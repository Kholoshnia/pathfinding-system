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

        private bool pause;
        private readonly string pathOut;
        private readonly int iterations;
        private readonly long finishReward;
        private int iterationsK, initialsK;
        private readonly bool visualization;

        public Logic(Modes mode, string pathIn, string pathOut, string pathInfo)
        {
            k = 0;

            UnityEngine.Object.Destroy(GameObject.Find("NEAT"));
            UnityEngine.Object.Destroy(GameObject.Find("NEAT_Canvas"));

            this.pathOut = pathOut;

            this.mode = mode;

            map = new Map();

            float gamma;
            string[] values;

            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                values = reader.ReadLine().Split(';');
                reader.ReadLine();
                mapSize = new Vector3Int(Convert.ToInt32(values[1]), Convert.ToInt32(values[2]), Convert.ToInt32(values[3]));
                map.map = new char[mapSize.z, mapSize.y, mapSize.x];

                for (int z = mapSize.z - 1; z >= 0; z--)
                {
                    for (int y = mapSize.y - 1; y >= 0; y--)
                    {
                        values = reader.ReadLine().Split(';');
                        for (int x = 0; x < mapSize.x; x++)
                            map.map[z, y, x] = Convert.ToChar(values[x]);
                    }
                    reader.ReadLine();
                }

                values = reader.ReadLine().Split(';');
                gamma = Convert.ToSingle(values[1]);

                values = reader.ReadLine().Split(';');
                iterations = Convert.ToInt32(values[1]);

                values = reader.ReadLine().Split(';');
                visualization |= Convert.ToInt32(values[1]) == 1;
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

                for (int j = 0; j < map.Walls.Count; j++)
                    GameObject.FindWithTag("Walls").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.Walls[j].name });

                if (!visualization)
                {
                    UnityEngine.Object.Destroy(agent);
                    for (int i = 0; i < map.Spaces.Count; i++)
                        UnityEngine.Object.Destroy(map.Spaces[i]);
                    for (int i = 0; i < map.Walls.Count; i++)
                        UnityEngine.Object.Destroy(map.Walls[i]);
                    UnityEngine.Object.Destroy(map.Finish);
                    UnityEngine.Object.Destroy(GameObject.FindWithTag("Walls"));
                    UnityEngine.Object.Destroy(GameObject.FindWithTag("StartPositions"));
                    GameObject.FindWithTag("MainCamera").GetComponent<CameraMovement>().enabled = false;
                }
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

                for (int i = 0; i < map.Spaces.Count; i++)
                {
                    bool notThere = true;
                    for (int j = 0; j < map.Walls.Count; j++)
                        notThere &= map.Spaces[i] != map.Walls[j];

                    if (notThere && map.Spaces[i] != map.Finish)
                        GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.Spaces[i].name });
                }

                UnityEngine.Object.Destroy(GameObject.FindWithTag("TextPosition"));
                UnityEngine.Object.Destroy(GameObject.FindWithTag("TextIteration"));
            }
        }

        public void Learn()
        {
            if (!pause)
            {
                table.Episode(map.Initials[initialsK]);

                if (visualization)
                    agent.transform.position = GameObject.Find("Position " + map.Initials[initialsK]).transform.position;

                initialsK++;

                if (initialsK > map.Initials.Count - 1)
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

                GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.Initials[initialsK];
                GameObject.FindWithTag("TextIteration").GetComponent<Text>().text = "Iteration: " + iterationsK;
            }
        }

        public void Check()
        {
            if (!done)
            {
                if (GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value != 0)
                {
                    int nowState = GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value - 1;
                    position = map.Spaces[nowState].transform.position;
                    moves.Add(position);

                    bool found = false;
                    for (int i = 0; i < map.Initials.Count; i++)
                        if (map.Spaces[map.Initials[i]].transform.position == position)
                        {
                            found = true;
                            break;
                        }

                    if (found)
                    {
                        while (true)
                        {
                            nowState = table.InferenceBestAction(nowState);
                            Vector3 bestAction = map.Spaces[nowState].transform.position;
                            moves.Add(bestAction);
                            if (bestAction == map.Finish.transform.position) break;
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
