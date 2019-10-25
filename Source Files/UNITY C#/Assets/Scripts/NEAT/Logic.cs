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

        private GameObject[] way;
        private readonly GameObject[] cubes;

        private string pathIn, pathOut;
        private readonly string language;

        private bool isPlaying, isCheking;
        private readonly bool autoEnd, checker;

        private readonly int autoExit;
        private int directionArraySize, populationQuantity, layersQuantity, steps, k;

        public Logic(ref bool checker, ref string pathIn, ref string pathOut)
        {
            this.checker = checker;
            k = 0;
            isPlaying = true;
            isCheking = checker;

            this.pathIn = pathIn;
            this.pathOut = pathOut;
            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                GameObject goal = GameObject.FindWithTag("Goal");
                GameObject start = GameObject.FindWithTag("Start");

                int numberOfObjects = Convert.ToInt32(reader.ReadLine());
                cubes = new GameObject[numberOfObjects - 2];
                reader.ReadLine();
                goal.transform.position = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                goal.transform.rotation = new Quaternion(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                goal.transform.localScale = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                reader.ReadLine();
                start.transform.position = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                start.transform.rotation = new Quaternion(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                start.transform.localScale = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                for (int i = 0; i < numberOfObjects - 2; i++)
                {
                    reader.ReadLine();
                    cubes[i] = UnityEngine.Object.Instantiate(GameObject.FindWithTag("Wall"));
                    cubes[i].transform.position = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                    cubes[i].transform.rotation = new Quaternion(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                    cubes[i].transform.localScale = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                }

                if (Convert.ToInt32(reader.ReadLine()) == 0)
                    for (int i = 1; i < SceneManager.GetActiveScene().GetRootGameObjects().Length; i++)
                        SceneManager.GetActiveScene().GetRootGameObjects()[i].SetActive(false);

                directionArraySize = Convert.ToInt32(reader.ReadLine());
                populationQuantity = Convert.ToInt32(reader.ReadLine());
                layersQuantity = Convert.ToInt32(reader.ReadLine());

                if (Convert.ToInt32(reader.ReadLine()) == 1) autoEnd = true;
                else autoEnd = false;

                autoExit = Convert.ToInt32(reader.ReadLine());

                language = reader.ReadLine();
            }
            fin.Close();
            UnityEngine.Object.Destroy(GameObject.FindWithTag("Wall"));

            if (checker)
                InitializeChecker();
            else
                Initialize();
        }

        public void Update()
        {
            if (isPlaying)
            {
                if (!checker)
                {
                    SetText();

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
                                writer.WriteLine(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].x);
                                writer.WriteLine(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].y);
                                writer.WriteLine(layers.GetBestPopulation().Agents[layers.GetBestPopulation().BestAgent].Brain.Directions[i].z);
                            }
                        }
                        fout.Close();

                        Application.Quit();
                        isPlaying = false;
                    }
                }
                else
                {
                    if (isCheking)
                    {
                        if (Mathf.Abs(vel.x + acc[k].x) < 5) vel.x += acc[k].x;
                        if (Mathf.Abs(vel.y + acc[k].y) < 5) vel.y += acc[k].y;
                        if (Mathf.Abs(vel.z + acc[k].z) < 5) vel.z += acc[k].z;
                        pos += vel;

                        way[k].transform.position = pos;

                        Debug.Log(vel.x);

                        k++;

                        isCheking &= k < acc.Length;
                    }

                    if (Input.GetKeyUp(KeyCode.Space))
                    {
                        for (int i = 0; i < way.Length; i++)
                            way[i].transform.position = Vector3.zero;
                        k = 0;
                        pos = GameObject.FindWithTag("Start").transform.position;
                        vel = Vector3.zero;
                        isCheking = true;
                    }
                }
            }
        }

        private void SetText()
        {
            if (language == "EN")
            {
                if (layers.GetBestPopulation().ReachedTheGoal) GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: Yes";
                else GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Reached the goal: No";
                GameObject.FindWithTag("TextGen").GetComponent<Text>().text = "Gen: " + layers.GetBestPopulation().Gen;
            }
            else if (language == "RU")
            {
                if (layers.GetBestPopulation().ReachedTheGoal) GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Достиг цели: Да";
                else GameObject.FindWithTag("TextReachedTheGoal").GetComponent<Text>().text = "Достиг цели: Нет";
                GameObject.FindWithTag("TextGen").GetComponent<Text>().text = "Поколение: " + layers.GetBestPopulation().Gen;
            }
        }

        private void Initialize()
        {
            layers = new Layers(ref directionArraySize, ref populationQuantity, ref layersQuantity);
            SetText();
        }

        private void InitializeChecker()
        {
            pos = GameObject.FindWithTag("Start").transform.position;
            vel = Vector3.zero;

            FileStream fin2 = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin2))
            {
                way = new GameObject[Convert.ToInt32(reader.ReadLine())];
                acc = new Vector3[way.Length];
                for (int i = 0; i < way.Length; i++)
                {
                    way[i] = UnityEngine.Object.Instantiate(GameObject.FindWithTag("Start"));
                    acc[i] = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
                }
            }

            populationQuantity = 1;
            layers = new Layers(ref directionArraySize, ref populationQuantity, ref layersQuantity);
            UnityEngine.Object.Destroy(GameObject.FindWithTag("TextReachedTheGoal"));
            UnityEngine.Object.Destroy(GameObject.FindWithTag("ImageReachedTheGoal"));
            UnityEngine.Object.Destroy(GameObject.FindWithTag("TextGen"));
            UnityEngine.Object.Destroy(GameObject.FindWithTag("ImageGen"));
        }
    };
}