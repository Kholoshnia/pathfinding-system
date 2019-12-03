using System;
using System.IO;

using UnityEngine;
using UnityEngine.UI;

namespace Assets.Scripts.NEAT
{
    class Logic
    {
        private readonly Layers layers;

        private Vector3 vel, pos;
        private readonly Vector3[] acc;
        private readonly GameObject[] way;
        private readonly GameObject[] walls;

        private readonly string pathOut;

        private int steps, k;
        private readonly bool visualization;
        private readonly float mutationRate, maxSpeed;
        private readonly int directionArraySize, populationQuantity, layersQuantity, autoCompletion;

        public Logic(Modes mode, string pathIn, string pathOut, string pathInfo)
        {
            UnityEngine.Object.Destroy(GameObject.Find("QL"));
            UnityEngine.Object.Destroy(GameObject.Find("QL_Canvas"));


            this.pathOut = pathOut;

            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                var values = reader.ReadLine().Split(';');
                int numberOfObjects = Convert.ToInt32(values[1]);
                walls = new GameObject[numberOfObjects - 2];

                reader.ReadLine();
                reader.ReadLine();
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Goal").transform.position = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Goal").transform.rotation = new Quaternion(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]), Convert.ToSingle(values[4]));
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Goal").transform.localScale = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                reader.ReadLine();
                reader.ReadLine();
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Start").transform.position = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Start").transform.rotation = new Quaternion(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]), Convert.ToSingle(values[4]));
                values = reader.ReadLine().Split(';');
                GameObject.FindWithTag("Start").transform.localScale = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));

                for (int i = 0; i < numberOfObjects - 2; i++)
                {
                    reader.ReadLine();
                    reader.ReadLine();
                    walls[i] = UnityEngine.Object.Instantiate(GameObject.FindWithTag("Wall"));
                    walls[i].name = "Wall " + i;
                    values = reader.ReadLine().Split(';');
                    walls[i].transform.position = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                    values = reader.ReadLine().Split(';');
                    walls[i].transform.rotation = new Quaternion(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]), Convert.ToSingle(values[4]));
                    values = reader.ReadLine().Split(';');
                    walls[i].transform.localScale = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                }
            }
            fin.Close();

            UnityEngine.Object.Destroy(GameObject.FindWithTag("Wall"));

            if (mode == Modes.LEARN)
            {
                FileStream finInfo = new FileStream(pathInfo, FileMode.Open);

                using (StreamReader reader = new StreamReader(finInfo))
                {
                    reader.ReadLine();
                    reader.ReadLine();
                    reader.ReadLine();
                    reader.ReadLine();

                    var values = reader.ReadLine().Split(';');
                    visualization |= Convert.ToInt32(values[1]) == 1;

                    values = reader.ReadLine().Split(';');
                    directionArraySize = Convert.ToInt32(values[1]);

                    values = reader.ReadLine().Split(';');
                    populationQuantity = Convert.ToInt32(values[1]);

                    values = reader.ReadLine().Split(';');
                    layersQuantity = Convert.ToInt32(values[1]);

                    values = reader.ReadLine().Split(';');
                    autoCompletion = Convert.ToInt32(values[1]);

                    values = reader.ReadLine().Split(';');
                    maxSpeed = Convert.ToSingle(values[1]);

                    values = reader.ReadLine().Split(';');
                    mutationRate = Convert.ToSingle(values[1]);
                }
                finInfo.Close();

                layers = new Layers(directionArraySize, populationQuantity, layersQuantity, mutationRate, maxSpeed);

                if (!visualization)
                {
                    UnityEngine.Object.Destroy(GameObject.FindWithTag("Walls"));
                    GameObject.FindWithTag("MainCamera").GetComponent<CameraMovement>().enabled = false;

                    for (int i = 0; i < walls.Length; i++)
                        walls[i].GetComponent<MeshRenderer>().enabled = false;

                    for (int i = 0; i < Layers.Populations.Length; i++)
                        for (int j = 0; j < Layers.Populations[i].Agents.Length; j++)
                            Layers.Populations[i].Agents[j].Sphere.GetComponent<MeshRenderer>().enabled = false;

                    GameObject.FindWithTag("Goal").GetComponent<MeshRenderer>().enabled = false;
                    GameObject.FindWithTag("Start").GetComponent<MeshRenderer>().enabled = false;
                }
            }
            else if (mode == Modes.CHECK)
            {
                pos = GameObject.FindWithTag("Start").transform.position;
                vel = Vector3.zero;

                FileStream fin2 = new FileStream(pathOut, FileMode.Open);

                using (StreamReader reader = new StreamReader(fin2))
                {
                    var values = reader.ReadLine().Split(';');
                    maxSpeed = Convert.ToInt32(values[1]);
                    values = reader.ReadLine().Split(';');
                    way = new GameObject[Convert.ToInt32(values[1])];
                    acc = new Vector3[way.Length];
                    for (int i = 0; i < way.Length; i++)
                    {
                        way[i] = UnityEngine.Object.Instantiate(GameObject.FindWithTag("Start"));

                        values = reader.ReadLine().Split(';');
                        acc[i] = new Vector3(Convert.ToSingle(values[0]), Convert.ToSingle(values[1]), Convert.ToSingle(values[2]));
                    }
                }

                populationQuantity = 1;
                layers = new Layers(directionArraySize, populationQuantity, layersQuantity, mutationRate, maxSpeed);
                UnityEngine.Object.Destroy(GameObject.FindWithTag("TextReachedTheGoal"));
                UnityEngine.Object.Destroy(GameObject.FindWithTag("ImageReachedTheGoal"));
                UnityEngine.Object.Destroy(GameObject.FindWithTag("TextGen"));
                UnityEngine.Object.Destroy(GameObject.FindWithTag("ImageGen"));
            }

            for (int i = 0; i < walls.Length; i++)
                GameObject.FindWithTag("Walls").GetComponent<Dropdown>().options.Add(new Dropdown.OptionData { text = walls[i].name });
        }

        public void Learn()
        {
            layers.Update();

            if (Input.GetKeyUp(KeyCode.Space) || (layers.GetBestPopulation().AfterReach >= autoCompletion))
            {
                FileStream fout = new FileStream(pathOut, FileMode.Create);
                using (StreamWriter writer = new StreamWriter(fout))
                {
                    writer.Write("max-speed:;");
                    writer.WriteLine(maxSpeed);
                    writer.Write("directions-array-size:;");
                    writer.WriteLine(layers.GetBestPopulation().MinStep);
                    for (int i = 0; i < layers.GetBestPopulation().MinStep; i++)
                    {
                        writer.Write(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].x);
                        writer.Write(';');
                        writer.Write(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].y);
                        writer.Write(';');
                        writer.Write(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].z);
                        writer.WriteLine();
                    }
                }
                fout.Close();

                Application.Quit();
            }

            if (layers.GetBestPopulation().ReachedTheGoal) GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: Yes";
            else GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: No";
            GameObject.FindWithTag("TextGen").GetComponent<Text>().text = "Gen: " + layers.GetBestPopulation().Gen;
        }

        public void Check()
        {
            if (k < acc.Length)
            {
                if (Mathf.Abs(vel.x + acc[k].x) < maxSpeed) vel.x += acc[k].x;
                if (Mathf.Abs(vel.y + acc[k].y) < maxSpeed) vel.y += acc[k].y;
                if (Mathf.Abs(vel.z + acc[k].z) < maxSpeed) vel.z += acc[k].z;
                pos += vel;

                way[k].transform.position = pos;

                k++;
            }
        }
    };
}
