using System;
using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.QL
{
    class Logic
    {
<<<<<<< Updated upstream
        private Map map;
        private Table table;
        private GameObject agent;
        private Vector3Int mapSize;
        private readonly string pathIn;
        private readonly string pathOut;
        private int finishState, iterations;
        int iterationsK, initialsK;
        bool playing;
        private long finishReward;

        public Logic(Modes mode, Languages language, string pathIn, string pathOut)
        {
            playing = true;
            initialsK = 0;
            iterationsK = 0;
            map = new Map(mapSize, pathIn);
            this.pathIn = pathIn;
            this.pathOut = pathOut;
            table = new Table(finishReward, mapSize, map);
            agent = GameObject.FindWithTag("Start");
            UnityEngine.Object.Destroy(GameObject.Find("NEAT"));
            finishReward = (long)Math.Pow(mapSize.x * mapSize.y * mapSize.z, 3);
=======
        private int k;
        private bool done;
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
                    for (int action = 0; action < mapSize.z * mapSize.y * mapSize.x; action++)
                    {
                        string[] bits = reader.ReadLine().Split(' ');
                        for (int state = 0; state < mapSize.z * mapSize.y * mapSize.x; state++)
                            table.Q[action, state] = Convert.ToInt64(bits[state]);
                    }
                }
                fresult.Close();

                for (int j = 0; j < map.walls.Count; j++)
                    for (int i = 0; i < map.spaces.Count; i++)
                        if (map.spaces[i] != map.walls[j] || map.spaces[i] != map.finish)
                            GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.spaces[i].name });
            }
>>>>>>> Stashed changes
        }

        public void Learn()
        {
            List<int> moves;

            int position, k = 0;
            bool done = false, playing = true;

<<<<<<< Updated upstream
            while (playing)
            {
                if (!done)
=======
                if (iterationsK >= iterations)
>>>>>>> Stashed changes
                {
                    /*if (Input.GetKeyUp(KeyCode.Mouse0))
                    {
<<<<<<< Updated upstream
                    position = map_size_y * (event.mouseMove.y / (width / map_size_y)) + event.mouseMove.x / (width / map_size_x);
				                    moves.emplace_back(position);
				                    if (std::find(initials.begin(), initials.end(), position) != initials.end())
				                    {
					                    moves.Add(position);
					                    while (true)
					                    {
						                    int best_action = table->inference_best_action(position);
                                            moves.emplace_back(best_action);
						                    if (best_action == finish_state) break;
						                    else position = best_action;
					                    }
                                        done = true;
				                    }
			                    }
		                    }*/
=======
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
                    Application.Quit();
                    pause = true;
                }

                if (language == Languages.EN)
                {
                    GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.initials[initialsK];
                    GameObject.FindWithTag("TextIteration").GetComponent<Text>().text = "Iteration: " + iterationsK;
>>>>>>> Stashed changes
                }
                else
                {
                    /*agent->show(window);
                    agent->update(moves[k]);
                    k++;

			        if (k > moves.size() - 1)
                    {
				        moves.clear();
				        k = 0;
				        done = false;
			        }*/
                }
            }
        }

        public void Check()
        {
<<<<<<< Updated upstream
            table.Episode(map.initials[initialsK]);

            /*std::ostringstream initials_str;
            initials_str << initials[initials_k];
            text[1].setString(initials_str.str());

            std::ostringstream iterations_str;
            iterations_str << iterations_k;
            text[3].setString(iterations_str.str());*/

            initialsK++;

            if (initialsK > map.initials.Count - 1)
            {
                initialsK = 0;
                iterationsK++;
            }
=======
            if (!done)
            {
                if (GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value != 0)
                {
                    int nowValue = GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value - 1;
                    position = map.spaces[nowValue].transform.position;
                    int nowState = nowValue;
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
                            if (moves.Count > mapSize.z * mapSize.y * mapSize.z)
                                break;
                        }
                    }
                    done = true;
                }
            }
            else
            {
                agent.transform.position = moves[k];
>>>>>>> Stashed changes

            if (iterationsK > iterations)
            {

<<<<<<< Updated upstream
=======
                    if (k > moves.Count - 1)
                    {
                        k = 0;
                        done = false;
                        moves.Clear();
                        GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value = 0;
                    }
                }
>>>>>>> Stashed changes
            }
        }
    }
}
