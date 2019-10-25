using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Agent
    {
        private Color color;
        private Vector3 pos, vel, acc;

        public bool Dead { get; set; }
        public bool IsBest { get; set; }
        public GameObject Sphere { get; }
        public Brain Brain { get; private set; }
        public float Fitness { get; private set; }
        public bool ReachedGoal { get; private set; }
        public Color Color { get => color; set => color = value; }

        public Agent(int directionArraySize)
        {
            Sphere = Object.Instantiate(GameObject.FindWithTag("Start"));
            Brain = new Brain(directionArraySize);
            Fitness = 0;
            Dead = false;
            ReachedGoal = false;
            IsBest = false;
            pos = GameObject.FindWithTag("Start").transform.position;
            vel = Vector3.zero;
            acc = Vector3.zero;
        }

        private void Move()
        {
            if (Brain.Directions.GetLength(0) > Brain.Step)
            {
                acc = Brain.Directions[Brain.Step];
                Brain.Step++;
            }
            else Dead = true;
            if (Mathf.Abs(vel.x + acc.x) < 5) vel.x += acc.x;
            if (Mathf.Abs(vel.y + acc.y) < 5) vel.y += acc.y;
            if (Mathf.Abs(vel.z + acc.z) < 5) vel.z += acc.z;
            pos += vel;
            Sphere.transform.position = pos;
        }

        public void Update()
        {
            if (!Dead && !ReachedGoal)
            {
                Move();
                if (Sphere.GetComponent<OnCollision>().touchedGoal)
                    ReachedGoal = true;
                else Dead |= Sphere.GetComponent<OnCollision>().touchedWall;
            }

            if (IsBest)
                Sphere.GetComponent<MeshRenderer>().material.color = new Color(0, 255, 0);
            else
                Sphere.GetComponent<MeshRenderer>().material.color = color;
        }

        public void CalculateFitness()
        {
            if (ReachedGoal)
                Fitness = 100000.0f / (Brain.Step * Brain.Step);
            else
                Fitness = 1.0f / (GameObject.FindWithTag("Goal").GetComponent<Information>().GetDistance(Sphere) * GameObject.FindWithTag("Goal").GetComponent<Information>().GetDistance(Sphere));
        }

        public Agent GetCopy() { return new Agent(Brain.Directions.Length) { Brain = Brain.Clone() }; }
    };
}