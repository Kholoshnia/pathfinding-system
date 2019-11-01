using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Brain
    {
        public float Speed { get; }
        public float MutationRate { get; }
        public int Step { get; private set; }
        public Vector3[] Directions { get; private set; }

        public Brain(int directionArraySize, float mutationRate, float speed)
        {
            Step = 0;
            Speed = speed;
            MutationRate = mutationRate;
            Directions = new Vector3[directionArraySize];

            Randomize();
        }

        public void Mutate()
        {
            for (int i = 0; i < Directions.Length; i++)
            {
                float rand = Random.Range(0.0f, 1.0f);
                if (rand < MutationRate)
                    SetDirection(i);
            }
        }

        public void Randomize()
        {
            for (int i = 0; i < Directions.Length; i++)
                SetDirection(i);
        }

        public Brain Clone()
        {
            Brain clone = new Brain(Directions.Length, MutationRate, Speed);
            for (int i = 0; i < Directions.Length; i++)
                clone.Directions[i] = Directions[i];
            return clone;
        }

        public void IncStep() { Step++; }

        private void SetDirection(int i) { Directions[i] = new Vector3(Random.Range(-Speed, Speed), Random.Range(-Speed, Speed), Random.Range(-Speed, Speed)); }
    };
}