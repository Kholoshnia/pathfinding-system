using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Brain
    {
        public int Step { get; private set; }
        public Vector3[] Directions { get; private set; }
        public float MutationRate { get; }
        public float Speed { get; }

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

        public void IncStep() { Step++; }

        public Brain Clone() { return new Brain(Directions.Length, MutationRate, Speed) { Directions = Directions }; }

        private void SetDirection(int i) { Directions[i] = new Vector3(Random.Range(-Speed, Speed), Random.Range(-Speed, Speed), Random.Range(-Speed, Speed)); }
    };
}
