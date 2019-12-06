using System;
using System.IO;
using System.Collections.Generic;

using UnityEngine;
using UnityEngine.UI;

namespace Assets.Scripts.QL
{
    class Logic
    {
        private bool done;
        private Vector3 position;
        private List<GameObject> pos_agents;
        private readonly List<Vector3> moves;

        private Vector3Int mapSize;

        private readonly Map map;
        private readonly Table table;
        private readonly GameObject agent;

        private readonly Modes mode;
        private readonly VisualizationType visualization;

        private bool pause, showControls;
        private readonly long finishReward;
        private readonly string pathIn, pathOut;
        private readonly int iterations, repetitions;
        private int repetitionsK, initialsK, previousValue;

        public Logic(Modes mode, string pathIn, string pathOut, string pathInfo)
        {
            UnityEngine.Object.Destroy(GameObject.Find("NEAT"));
            UnityEngine.Object.Destroy(GameObject.Find("NEAT_Canvas"));

            showControls = false;
            this.pathIn = pathIn;
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

                for (int z = 0; z < mapSize.z; z++)
                {
                    for (int y = 0; y < mapSize.y; y++)
                    {
                        values = reader.ReadLine().Split(';');
                        for (int x = 0; x < mapSize.x; x++)
                            map.map[z, y, x] = Convert.ToChar(values[x]);
                    }
                    reader.ReadLine();
                }
            }
            fin.Close();

            FileStream finInfo = new FileStream(pathInfo, FileMode.Open);

            using (StreamReader reader = new StreamReader(finInfo))
            {
                reader.ReadLine();
                reader.ReadLine();
                reader.ReadLine();
                reader.ReadLine();

                values = reader.ReadLine().Replace('.', ',').Split(';');
                gamma = Convert.ToSingle(values[1]);

                values = reader.ReadLine().Split(';');
                switch (Convert.ToInt32(values[1]))
                {
                    case 0:
                        iterations = mapSize.x * mapSize.y * mapSize.z;
                        break;
                    default:
                        iterations = Convert.ToInt32(values[1]);
                        break;
                }

                values = reader.ReadLine().Split(';');
                repetitions = Convert.ToInt32(values[1]);

                values = reader.ReadLine().Split(';');
                switch (Convert.ToInt32(values[1]))
                {
                    case 0:
                        visualization = VisualizationType.NOVISUALIZATION;
                        break;
                    case 1:
                        visualization = VisualizationType.ITERATIONS;
                        break;
                    case 2:
                        visualization = VisualizationType.STATES;
                        break;
                }
            }
            finInfo.Close();

            map.Initialize(mapSize);

            agent = GameObject.Find("QL_Start");

            if (mode == Modes.LEARN)
            {
                initialsK = 0;
                repetitionsK = 0;

                finishReward = mapSize.x * mapSize.y * mapSize.z;

                table = new Table(finishReward, mapSize, map, gamma);

                UnityEngine.Object.Destroy(GameObject.FindWithTag("StartPositions"));

                if (visualization == VisualizationType.NOVISUALIZATION)
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
                pos_agents = new List<GameObject>();
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
                UnityEngine.Object.Destroy(GameObject.FindWithTag("TextRepetition"));
                GameObject.FindWithTag("TextControls").GetComponent<RectTransform>().transform.localPosition = new Vector3(-205.35f, 230.3f, 0.0f);
            }

            for (int j = 0; j < map.Walls.Count; j++)
                GameObject.FindWithTag("Walls").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = map.Walls[j].name });
        }

        public void Learn()
        {
            if (Input.GetKeyUp(KeyCode.Space))
                pause = !pause;

            if (Input.GetKeyUp(KeyCode.H))
            {
                showControls = !showControls;

                if (showControls) GameObject.FindWithTag("TextControls").GetComponent<Text>().text = "[WASDEQ] - Move camere\n[Mouse] - Rotate camera\n[P] - Change perspective\n[Space] - Pause\n[Esc] - exit\n[H] - Hide controls";
                else GameObject.FindWithTag("TextControls").GetComponent<Text>().text = "[H] - Show controls";
            }

            if (Input.GetKeyUp(KeyCode.Escape))
                Application.Quit();

            if (!pause)
            {
                table.Episode(map.Initials[initialsK], iterations, visualization);

                initialsK++;

                if (initialsK > map.Initials.Count - 1)
                {
                    initialsK = 0;
                    repetitionsK++;
                    GameObject.FindWithTag("TextRepetition").GetComponent<Text>().text = "Iteration: " + repetitionsK;
                }
                GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.Initials[initialsK];

                if (repetitionsK >= repetitions)
                {
                    GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.Initials[initialsK] + " (Loading)";

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

                    GameObject.FindWithTag("TextPosition").GetComponent<Text>().text = "Position: " + map.Initials[initialsK] + " (Done)";

                    Application.Quit();
                    pause = true;
                }
            }
        }

        public void Check()
        {
            if (Input.GetKeyUp(KeyCode.H))
            {
                showControls = !showControls;

                if (showControls) GameObject.FindWithTag("TextControls").GetComponent<Text>().text = "[WASDEQ] - Move camere\n[Mouse] - Rotate camera\n[P] - Change perspective\n[Esc] - exit\n[H] - Hide controls";
                else GameObject.FindWithTag("TextControls").GetComponent<Text>().text = "[H] - Show controls";
            }

            if (Input.GetKeyUp(KeyCode.Escape))
                Application.Quit();

            if (!done)
            {
                if (GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value != 0)
                {
                    previousValue = GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value;
                    int nowState = previousValue - 1;
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
                        while (true)
                        {
                            nowState = Convert.ToInt32(table.Maximum(nowState, true));
                            Vector3 bestAction = map.Spaces[nowState].transform.position;
                            moves.Add(bestAction);
                            if (bestAction == map.Finish.transform.position) break;
                            position = bestAction;
                            if (moves.Count > mapSize.z * mapSize.y * mapSize.x)
                                break;
                        }

                    done = true;
                    agent.SetActive(true);
                    for (int i = 0; i < moves.Count - 1; i++)
                    {
                        agent.transform.position = moves[i];
                        pos_agents.Add(UnityEngine.Object.Instantiate(agent));
                    }
                    agent.SetActive(false);
                }
            }
            else
            {
                if (GameObject.FindWithTag("StartPositions").GetComponent<DropdownStartPositions>().value != previousValue)
                {
                    done = false;
                    moves.Clear();
                    for (int i = 0; i < pos_agents.Count; i++)
                        UnityEngine.Object.Destroy(pos_agents[i]);
                    pos_agents.Clear();
                }
            }
        }
    }
}
