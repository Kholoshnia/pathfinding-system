using System;
using System.IO;
using System.Collections.Generic;

using UnityEngine;
using UnityEngine.UI;

namespace Assets.Scripts.QL
{
    class Logic
    {
        private int k;
        private bool done;
        private float timer;
        private Vector3 position;
        private readonly List<Vector3> moves;

        private Vector3Int mapSize;

        private readonly Map map;
        private readonly Table table;
        private readonly GameObject agent;

        private readonly Modes mode;
        private readonly Languages language;

        private bool pause;
        private readonly string pathOut;
        private readonly int iterations;
        private readonly long finishReward;
        private int iterationsK, initialsK;

        public Logic(Modes mode, Languages language, string pathIn, string pathOut)
        {
            k = 0;

            UnityEngine.Object.Destroy(GameObject.Find("NEAT"));
            UnityEngine.Object.Destroy(GameObject.Find("NEAT_Canvas"));

            this.pathOut = pathOut;

            this.mode = mode;
            this.language = language;

            map = new Map();

            float gamma;

            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                mapSize = new Vector3Int(Convert.ToInt32(reader.ReadLine()), Convert.ToInt32(reader.ReadLine()), Convert.ToInt32(reader.ReadLine()));
                map.map = new char[mapSize.z, mapSize.y, mapSize.x];

                for (int z = mapSize.z - 1; z >= 0; z--)
                    for (int y = mapSize.y - 1; y >= 0; y--)
                    {
                        var values = reader.ReadLine().Split(';');
                        for (int x = 0; x < mapSize.x; x++)
                            map.map[z, y, x] = Convert.ToChar(values[x]);
                    }

                gamma = Convert.ToSingle(reader.ReadLine());
                iterations = Convert.ToInt32(reader.ReadLine());
            }
            fin.Close();

            map.Initialize(mapSize);

            agent = GameObject.Find("QL_Start");

            if (mode == Modes.LEARN)
            {
                initialsK = 0;
                iterationsK = 0;

                finishReward = (long)Math.Pow(mapSize.x * mapSize.y * mapSize.z, 3);

                table = new Table(finishReward, mapSize, map, gamma);
                
                UnityEngine.Object.Destroy(GameObject.FindWithTag("StartPositions"));

                for (int j = 0; j < map.walls.Count; j++)
                    GameObject.FindWithTag("Walls").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.walls[j].name });
            }
            else if (mode == Modes.CHECK)
            {
                agent.SetActive(false);
                moves = new List<Vector3>();
                table = new Table(finishReward, mapSize, map, gamma);

                FileStream fresult = new FileStream(pathOut, FileMode.Open);

                using (StreamReader reader = new StreamReader(fresult))
                {
                    for (int action = 0; action < mapSize.x * mapSize.y * mapSize.z; action++)
                    {
                        string[] bits = reader.ReadLine().Split(';');
                        for (int state = 0; state < mapSize.x * mapSize.y * mapSize.z; state++)
                            table.Q[action, state] = Convert.ToInt64(bits[state]);
                    }
                }
                fresult.Close();

                for (int i = 0; i < map.spaces.Count; i++)
                {
                    bool notThere = true;
                    for (int j = 0; j < map.walls.Count; j++)
                        notThere &= map.spaces[i] != map.walls[j];

                    if (notThere && map.spaces[i] != map.finish)
                        GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.spaces[i].name });
                }
            }
        }

        public void Learn()
        {
            if (!pause)
            {
                table.Episode(map.initials[initialsK]);

                initialsK++;

                if (initialsK > map.initials.Count - 1)
                {
                    initialsK = 0;
                    iterationsK++;
                }

                if (iterationsK >= iterations)
                {
                    FileStream fout = new FileStream(pathOut, FileMode.Create);

                    using (StreamWriter writer = new StreamWriter(fout))
                    {
                        for (int action = 0; action < mapSize.x * mapSize.y * mapSize.z; action++)
                        {
                            for (int state = 0; state < mapSize.x * mapSize.y * mapSize.z; state++)
                            {
                                writer.Write(table.Q[action, state]);
                                writer.Write(';');
                            }
                            writer.WriteLine();
                        }
                    }
                    fout.Close();

                    Application.Quit();
                    pause = true;
                }

                if (language == Languages.EN)
                {
                    GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.initials[initialsK];
                    GameObject.FindWithTag("TextIteration").GetComponent<Text>().text = "Iteration: " + iterationsK;
                }
                else if (language == Languages.RU)
                {
                    GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Позиция: " + map.initials[initialsK];
                    GameObject.FindWithTag("TextIteration").GetComponent<Text>().text = "Итерация: " + iterationsK;
                }
            }
        }

        public void Check()
        {
            if (!done)
            {
                if (GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value != 0)
                {
                    int nowState = GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value - 1;
                    position = map.spaces[nowState].transform.position;
                    moves.Add(position);

                    bool found = false;
                    for (int i = 0; i < map.initials.Count; i++)
                        if (map.spaces[map.initials[i]].transform.position == position)
                        {
                            found = true;
                            break;
                        }

                    if (found)
                    {
                        while (true)
                        {
                            nowState = table.InferenceBestAction(nowState);
                            Vector3 bestAction = map.spaces[nowState].transform.position;
                            moves.Add(bestAction);
                            if (bestAction == map.finish.transform.position) break;
                            position = bestAction;
                            if (moves.Count > mapSize.z * mapSize.y * mapSize.x)
                                break;
                        }
                    }
                    done = true;
                    agent.SetActive(true);
                }
            }
            else
            {
                agent.transform.position = moves[k];

                timer += Time.deltaTime;

                if (timer >= 0.25f)
                {
                    k++;
                    timer = 0;
                }

                if (k > moves.Count - 1)
                {
                    k = 0;
                    done = false;
                    moves.Clear();
                    agent.SetActive(false);
                    GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value = 0;
                }
            }
        }
    }
}