using System;
using System.IO;

using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

namespace Assets.Scripts.NEAT
{
    class Logic
    {
        private Layers layers;

        private Vector3[] acc;
        private Vector3 vel, pos;

        private readonly GameObject[] way;
        public readonly GameObject[] walls;

        private Languages language;
        private readonly string pathOut;

        private readonly bool autoEnd;

        private readonly float mutationRate, speed, maxSpeed;

        private readonly int autoExit;
        private int directionArraySize, populationQuantity, layersQuantity, steps, k;

        public Logic(Modes mode, Languages language, string pathIn, string pathOut)
        {
            UnityEngine.Object.Destroy(GameObject.Find("QL"));
            UnityEngine.Object.Destroy(GameObject.Find("QL_Canvas"));

            this.pathOut = pathOut;
            this.language = language;

            GameObject goal = GameObject.FindWithTag("Goal");
            GameObject start = GameObject.FindWithTag("Start");

            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                var values = reader.ReadLine().Split(';');
                int numberOfObjects = Convert.ToInt32(values[1]);
                walls = new GameObject[numberOfObjects - 2];

                reader.ReadLine();
                reader.ReadLine();
                values = reader.ReadLine().Split(';');
                goal.transform.position = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                values = reader.ReadLine().Split(';');
                goal.transform.rotation = new Quaternion(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]), Convert.ToSingle(values[4]));
                values = reader.ReadLine().Split(';');
                goal.transform.localScale = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                reader.ReadLine();
                reader.ReadLine();
                values = reader.ReadLine().Split(';');
                start.transform.position = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));
                values = reader.ReadLine().Split(';');
                start.transform.rotation = new Quaternion(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]), Convert.ToSingle(values[4]));
                values = reader.ReadLine().Split(';');
                start.transform.localScale = new Vector3(Convert.ToSingle(values[1]), Convert.ToSingle(values[2]), Convert.ToSingle(values[3]));

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

                reader.ReadLine();
                reader.ReadLine();
                values = reader.ReadLine().Split(';');
                if (Convert.ToInt32(values[1]) == 0)
                    for (int i = 1; i < SceneManager.GetActiveScene().GetRootGameObjects().Length; i++)
                        SceneManager.GetActiveScene().GetRootGameObjects()[i].SetActive(false);

                values = reader.ReadLine().Split(';');
                directionArraySize = Convert.ToInt32(values[1]);
                populationQuantity = Convert.ToInt32(values[2]);
                layersQuantity = Convert.ToInt32(values[3]);

                values = reader.ReadLine().Split(';');
                if (Convert.ToInt32(values[1]) == 1) autoEnd = true;
                else autoEnd = false;
                autoExit = Convert.ToInt32(values[2]);

                values = reader.ReadLine().Split(';');
                speed = Convert.ToSingle(values[1]);
                maxSpeed = Convert.ToSingle(values[2]);

                values = reader.ReadLine().Split(';');
                mutationRate = Convert.ToSingle(values[1]);
            }
            fin.Close();

            UnityEngine.Object.Destroy(GameObject.FindWithTag("Wall"));

            if (mode == Modes.LEARN)
                layers = new Layers(directionArraySize, populationQuantity, layersQuantity, mutationRate, speed, maxSpeed);
            else if (mode == Modes.CHECK)
            {
                pos = GameObject.FindWithTag("Start").transform.position;
                vel = Vector3.zero;

                FileStream fin2 = new FileStream(pathOut, FileMode.Open);

                using (StreamReader reader = new StreamReader(fin2))
                {
                    way = new GameObject[Convert.ToInt32(reader.ReadLine())];
                    acc = new Vector3[way.Length];
                    for (int i = 0; i < way.Length; i++)
                    {
                        way[i] = UnityEngine.Object.Instantiate(GameObject.FindWithTag("Start"));

                        var values = reader.ReadLine().Split(';');
                        acc[i] = new Vector3(Convert.ToSingle(values[0]), Convert.ToSingle(values[1]), Convert.ToSingle(values[2]));
                    }
                }

                populationQuantity = 1;
                layers = new Layers(directionArraySize, populationQuantity, layersQuantity, mutationRate, speed, maxSpeed);
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

            if (layers.AllPopulationsDead())
                steps = layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Step;

            if (Input.GetKeyUp(KeyCode.Space) || (autoEnd && layers.GetBestPopulation().Gen >= autoExit))
            {
                FileStream fout = new FileStream(pathOut, FileMode.Create);
                using (StreamWriter writer = new StreamWriter(fout))
                {
                    writer.WriteLine(steps);
                    for (int i = 0; i < steps; i++)
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

            if (language == Languages.EN)
            {
                if (layers.GetBestPopulation().ReachedTheGoal) GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: Yes";
                else GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: No";
                GameObject.FindWithTag("TextGen").GetComponent<Text>().text = "Gen: " + layers.GetBestPopulation().Gen;
            }
            else if (language == Languages.RU)
            {
                if (layers.GetBestPopulation().ReachedTheGoal) GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Достиг цели: Да";
                else GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Достиг цели: Нет";
                GameObject.FindWithTag("TextGen").GetComponent<Text>().text = "Поколение: " + layers.GetBestPopulation().Gen;
            }
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