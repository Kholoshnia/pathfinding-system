using System;
using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.QL
{
    class Logic
    {
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
        }

        public void Learn()
        {
            List<int> moves;

            int position, k = 0;
            bool done = false, playing = true;

            while (playing)
            {
                if (!done)
                {
                    /*if (Input.GetKeyUp(KeyCode.Mouse0))
                    {
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

            if (iterationsK > iterations)
            {

            }
        }
    }
}
