using SFB;
using System;
using System.IO;
using UnityEngine;
using UnityEngine.UI;

public class Main : MonoBehaviour
{
    [SerializeField] private bool autoEnd;
    [SerializeField] private int autoExit = 20;
    [SerializeField] private Image image1, image2;
    [SerializeField] private Text reachedTheGoal, gen;
    [SerializeField] private Transform cameraTransform;
    [SerializeField] private GameObject startSphere, goalSphere, droneObject;

    private static GameObject start, goal;

    private Vector3[] acc;
    private Vector3 pos, vel;

    public bool checker;
    private string path;
    private bool isPlaying, isFlying;
    static private int directionArraySize, populationQuantity, k;

    private Population population;

    public class Brain
    {
        public Vector3[] directions;
        public int step;
        public float speed;

        public Brain()
        {
            speed = 0.1f;
            step = 0;
            directions = new Vector3[directionArraySize];
            for (int i = 0; i < directions.GetLength(0); i++)
                directions[i] = new Vector3();
            Randomize();
        }

        public void Randomize()
        {
            for (int i = 0; i < directions.GetLength(0); i++)
            {
                directions[i].x = UnityEngine.Random.Range(-speed, speed);
                directions[i].y = UnityEngine.Random.Range(-speed, speed);
                directions[i].z = UnityEngine.Random.Range(-speed, speed);
            }
        }

        public Brain Clone()
        {
            Brain clone = new Brain();
            for (int i = 0; i < directions.GetLength(0); i++)
                clone.directions[i] = directions[i];
            return clone;
        }

        public void Mutate()
        {
            float mutationRate = 0.01f;
            for (int i = 0; i < directions.GetLength(0); i++)
            {
                float randn = UnityEngine.Random.Range(0.0f, 1.0f);
                if (randn < mutationRate)
                {
                    directions[i].x = UnityEngine.Random.Range(-speed, speed);
                    directions[i].y = UnityEngine.Random.Range(-speed, speed);
                    directions[i].z = UnityEngine.Random.Range(-speed, speed);
                }
            }
        }
    };

    public class Dot
    {
        public GameObject sphere;
        public Vector3 pos, vel, acc;
        public Brain brain;
        public bool dead, reachedGoal, isBest;
        public float fitness;

        public Dot()
        {
            sphere = Instantiate(start);
            brain = new Brain();
            fitness = 0;
            dead = false;
            reachedGoal = false;
            isBest = false;
            pos = start.transform.position;
            vel = new Vector3(0, 0, 0);
            acc = new Vector3(0, 0, 0);
        }

        public void Move()
        {
            if (brain.directions.GetLength(0) > brain.step)
            {
                acc = brain.directions[brain.step];
                brain.step++;
            }
            else dead = true;
            if (Mathf.Abs(vel.x + acc.x) < 5) vel.x += acc.x;
            if (Mathf.Abs(vel.y + acc.y) < 5) vel.y += acc.y;
            if (Mathf.Abs(vel.z + acc.z) < 5) vel.z += acc.z;
            pos += vel;
            sphere.transform.position = pos;
        }

        public void Update()
        {
            if (!dead && !reachedGoal)
            {
                Move();
                if (sphere.GetComponent<OnCollision>().touchedGoal)
                    reachedGoal = true;
                else if (sphere.GetComponent<OnCollision>().touchedWall)
                    dead = true;
            }
        }

        public void CalculateFitness()
        {
            if (reachedGoal)
                fitness = 1.0f / 16.8f + 100000.0f / (brain.step * brain.step);
            else
                fitness = 1.0f / (goal.GetComponent<Information>().GetDistance(sphere) * goal.GetComponent<Information>().GetDistance(sphere));
        }

        public Dot GetCopy()
        {
            Dot baby = new Dot { brain = brain.Clone() };
            return baby;
        }
    };

    public class Population
    {
        public Dot[] dots;
        public int gen, minStep, bestDot;
        public float fitnessSum;
        public bool reachedTheGoal;

        public Population(int size)
        {
            reachedTheGoal = false;
            fitnessSum = 0;
            dots = new Dot[size];
            for (int i = 0; i < dots.GetLength(0); i++)
                dots[i] = new Dot();
            gen = 1;
            minStep = 4000;
            bestDot = 0;
        }

        public void Update()
        {
            for (int i = 0; i < dots.GetLength(0); i++)
            {
                if (dots[i].brain.step > minStep)
                    dots[i].dead = true;
                else
                    dots[i].Update();
                if (dots[i].reachedGoal)
                    reachedTheGoal = true;
            }
        }

        public void CalculateFitness()
        {
            for (int i = 0; i < dots.GetLength(0); i++)
                dots[i].CalculateFitness();
        }

        public bool AllDotsDead()
        {
            for (int i = 0; i < dots.GetLength(0); i++)
                if (!dots[i].dead && !dots[i].reachedGoal)
                    return false;
            return true;
        }

        public void NaturalSelection()
        {
            CalculateFitnessSum();
            Dot[] newDots = new Dot[dots.GetLength(0)];
            SetBestDot();
            newDots[0] = dots[bestDot].GetCopy();
            newDots[0].isBest = true;
            for (int i = 1; i < dots.GetLength(0); ++i)
            {
                Dot parent = SelectParent();
                newDots[i] = parent.GetCopy();
            }
            dots = newDots;
            gen++;
        }

        public void CalculateFitnessSum()
        {
            fitnessSum = 0;
            for (int i = 0; i < dots.GetLength(0); i++)
                fitnessSum += dots[i].fitness;
        }

        public Dot SelectParent()
        {
            float random = UnityEngine.Random.Range(0, fitnessSum);
            float runningSum = 0;
            for (int i = 0; i < dots.GetLength(0); i++)
            {
                runningSum += dots[i].fitness;
                if (runningSum > random)
                    return dots[i];
            }
            return null;
        }

        public void Mutate()
        {
            for (int i = 1; i < dots.GetLength(0); i++)
                dots[i].brain.Mutate();
        }

        public void SetBestDot()
        {
            float max = 0;
            int maxIndex = 0;
            for (int i = 0; i < dots.GetLength(0); i++)
            {
                if (dots[i].fitness > max)
                {
                    max = dots[i].fitness;
                    maxIndex = i;
                }
            }
            bestDot = maxIndex;
            if (dots[bestDot].reachedGoal)
                minStep = dots[bestDot].brain.step;
        }
    };

    public void Awake()
    {
        isFlying = true;
        isPlaying = true;
        k = 0;
        goal = goalSphere;
        directionArraySize = 350;
        populationQuantity = 2000;

        if (checker)
        {
            cameraTransform.rotation = new Quaternion(0, 0, 0, 1);
            start = droneObject;
            pos = startSphere.transform.position;
            vel = Vector3.zero;

            path = string.Join("", StandaloneFileBrowser.OpenFilePanel("Load result file", "", "txt", false));
            FileStream fin2 = new FileStream(path, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin2))
            {
                acc = new Vector3[Convert.ToInt32(reader.ReadLine())];
                for (int i = 0; i < acc.GetLength(0); i++)
                    acc[i] = new Vector3(Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()), Convert.ToSingle(reader.ReadLine()));
            }

            Destroy(reachedTheGoal);
            Destroy(image1);
            Destroy(gen);
            Destroy(image2);
            startSphere.SetActive(false);
        }
        else
        {
            Destroy(droneObject);
            start = startSphere;
            population = new Population(populationQuantity);
        }
    }

    public void Update()
    {
        if (isPlaying)
        {
            if (!checker)
            {
                if (population.AllDotsDead())
                {
                    reachedTheGoal.text = "Reached the goal: " + population.reachedTheGoal;
                    gen.text = "Gen: " + population.gen;

                    if (Input.GetKeyUp(KeyCode.Space) || (autoEnd && population.gen >= autoExit))
                    {
                        path = string.Join("", StandaloneFileBrowser.SaveFilePanel("Save information file", "", "result", "txt"));

                        FileStream fout = new FileStream(path, FileMode.Create);
                        using (StreamWriter writer = new StreamWriter(fout))
                        {
                            writer.WriteLine(population.dots[population.bestDot].brain.step);
                            for (int i = 0; i < population.dots[population.bestDot].brain.step; i++)
                            {
                                writer.WriteLine(population.dots[population.bestDot].brain.directions[i].x);
                                writer.WriteLine(population.dots[population.bestDot].brain.directions[i].y);
                                writer.WriteLine(population.dots[population.bestDot].brain.directions[i].z);
                            }
                        }
                        fout.Close();

                        Application.Quit();
                        isPlaying = false;
                    }

                    for (int i = 0; i < population.dots.GetLength(0); i++)
                        Destroy(population.dots[i].sphere);
                    population.CalculateFitness();
                    population.NaturalSelection();
                    population.Mutate();
                }
                else
                    population.Update();
            }
            else
            {
                if (isFlying)
                {
                    if (Mathf.Abs(vel.x + acc[k].x) < 5) vel.x += acc[k].x;
                    if (Mathf.Abs(vel.y + acc[k].y) < 5) vel.y += acc[k].y;
                    if (Mathf.Abs(vel.z + acc[k].z) < 5) vel.z += acc[k].z;
                    pos += vel;

                    start.transform.position = pos;

                    k++;

                    if (k >= acc.GetLength(0))
                        isFlying = false;
                }

                if (Input.GetKeyUp(KeyCode.Space))
                {
                    k = 0;
                    start = droneObject;
                    pos = startSphere.transform.position;
                    vel = Vector3.zero;
                    isFlying = true;
                }
            }
        }
    }
}