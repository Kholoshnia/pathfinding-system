using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Brain
    {
        private readonly float speed;

        public int Step { get; set; }
        public Vector3[] Directions { get; }

        public Brain(int directionArraySize)
        {
            speed = 0.1f;
            Step = 0;
            Directions = new Vector3[directionArraySize];
            for (int i = 0; i < Directions.Length; i++)
                Directions[i] = new Vector3();
            Randomize();
        }

        public Brain Clone()
        {
            Brain clone = new Brain(Directions.Length);
            for (int i = 0; i < Directions.Length; i++)
                clone.Directions[i] = Directions[i];
            return clone;
        }

        public void Mutate()
        {
            float mutationRate = 0.01f;
            for (int i = 0; i < Directions.Length; i++)
            {
                float randn = UnityEngine.Random.Range(0.0f, 1.0f);
                if (randn < mutationRate)
                {
                    Directions[i].x = UnityEngine.Random.Range(-speed, speed);
                    Directions[i].y = UnityEngine.Random.Range(-speed, speed);
                    Directions[i].z = UnityEngine.Random.Range(-speed, speed);
                }
            }
        }

        public void Randomize()
        {
            for (int i = 0; i < Directions.Length; i++)
            {
                Directions[i].x = UnityEngine.Random.Range(-speed, speed);
                Directions[i].y = UnityEngine.Random.Range(-speed, speed);
                Directions[i].z = UnityEngine.Random.Range(-speed, speed);
            }
        }
    };
}
