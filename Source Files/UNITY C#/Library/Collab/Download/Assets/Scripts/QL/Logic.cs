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
        private Vector3 position;
        private List<Vector3> moves;

        private Map map;
        private Table table;
        private GameObject agent;
        private Vector3Int mapSize;

        private Modes mode;
        private Languages language;

        private bool pause;
        private long finishReward;
        private readonly string pathIn, pathOut;
        private int finishState, iterations, iterationsK, initialsK;

        public Logic(Modes mode, Languages language, string pathIn, string pathOut)
        {
            k = 0;

            UnityEngine.Object.Destroy(GameObject.Find("NEAT"));
            UnityEngine.Object.Destroy(GameObject.Find("NEAT_Canvas"));

            this.pathIn = pathIn;
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

                for (int z = 0; z < mapSize.z; z++)
                    for (int y = 0; y < mapSize.y; y++)
                    {
                        for (int x = 0; x < mapSize.x; x++)
                            map.map[z, y, x] = (char)reader.Read();
                        reader.Read();
                    }

                gamma = Convert.ToSingle(reader.ReadLine());
                iterations = Convert.ToInt32(reader.ReadLine());
            }
            fin.Close();

            map.Initialize(mapSize);

            agent = GameObject.Find("QL_Start");

            for (int j = 0; j < map.walls.Count; j++)
                GameObject.FindWithTag("Walls").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.walls[j].name });

            if (mode == Modes.LEARN)
            {
                initialsK = 0;
                iterationsK = 0;

                finishReward = (long)Math.Pow(mapSize.x * mapSize.y * mapSize.z, 3);

                table = new Table(finishReward, mapSize, map, gamma);
                
                UnityEngine.Object.Destroy(GameObject.FindWithTag("StartPositions"));
                
            }
            else if (mode == Modes.CHECK)
            {
                moves = new List<Vector3>();

                FileStream fresult = new FileStream(pathOut, FileMode.Open);

                table = new Table(finishReward, mapSize, map, gamma);

                using (StreamReader reader = new StreamReader(fresult))
                {
                    for (int action = 0; action < mapSize.x * mapSize.y * mapSize.z; action++)
                    {
                        string text = reader.ReadLine();
                        string[] bits = text.Split(' ');
                        for (int state = 0; state < mapSize.x * mapSize.y * mapSize.z; state++)
                            table.Q[action, state] = Convert.ToInt64(bits[state]);
                    }
                }
                fresult.Close();

                for (int j = 0; j < map.walls.Count; j++)
                    for (int i = 0; i < map.spaces.Count; i++)
                        if (map.spaces[i] != map.walls[j] || map.spaces[i] != map.finish)
                            GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.spaces[i].name });
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

                if (iterationsK > iterations)
                {
                    FileStream fout = new FileStream(pathOut, FileMode.Create);

                    using (StreamWriter writer = new StreamWriter(fout))
                    {
                        for (int action = 0; action < mapSize.x * mapSize.y * mapSize.z; action++)
                        {
                            for (int state = 0; state < mapSize.x * mapSize.y * mapSize.z; state++)
                            {
                                writer.Write(table.Q[action, state]);
                                writer.Write(' ');
                            }
                            writer.WriteLine();
                        }
                    }
                    fout.Close();
                    pause = true;
                    Application.Quit();
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
                    position = map.spaces[GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value - 1].transform.position;
                    int nowState = GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value - 1;
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
                        }
                    }
                    done = true;
                }
            }
            else
            {
                agent.transform.position = moves[k];

                if (Input.GetKeyUp(KeyCode.Space))
                {
                    k++;

                    if (k > moves.Count - 1)
                    {
                        k = 0;
                        done = false;
                        moves.Clear();
                        GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value = 0;
                    }
                }
            }
        }
    }
}
