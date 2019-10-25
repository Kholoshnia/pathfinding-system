using Unity.Jobs;
using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Layers
    {
        private readonly UpdateThreads updateThreads;

        public static Population[] Populations { get; set; }

        private struct UpdateThreads : IJobParallelFor
        {
            public void Execute(int i)
            {
                if (Populations[i].AllAgentsDead())
                {
                    Populations[i].CalculateFitness();
                    for (int j = 0; j < Populations[i].Agents.Length; j++)
                        Object.Destroy(Populations[i].Agents[j].Sphere);
                    Populations[i].NaturalSelection();
                    Populations[i].Mutate();
                }
                else
                    Populations[i].Update();
            }
        }

        public Layers(ref int directionArraySize, ref int populationQuantity, ref int layersQuantity)
        {
            updateThreads = new UpdateThreads();
            Populations = new Population[layersQuantity];
            for (int i = 0; i < Populations.Length; i++)
                Populations[i] = new Population(directionArraySize, populationQuantity, layersQuantity);
        }

        public void Update()
        {
            for (int i = 0; i < Populations.Length; i++)
                updateThreads.Execute(i);
        }

        public bool AllPopulationsDead()
        {
            for (int i = 0; i < Populations.Length; i++)
                if (!Populations[i].AllAgentsDead())
                    return false;
            return true;
        }

        public Population GetBestPopulation()
        {
            float max = 0;
            int maxIndex = 0;
            for (int i = 0; i < Populations.Length; i++)
                if (Populations[i].Agents[Populations[i].BestAgent].Fitness > max)
                {
                    max = Populations[i].Agents[Populations[i].BestAgent].Fitness;
                    maxIndex = i;
                }
            return Populations[maxIndex];
        }
    };
}
