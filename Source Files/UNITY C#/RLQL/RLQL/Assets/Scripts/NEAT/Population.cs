using UnityEngine;

namespace Assets.Scripts.NEAT
{
    public class Population
    {
        private Color color;
        private int minStep;
        private float fitnessSum;
        private readonly int layersQuantity;

        public int Gen { get; private set; }
        public int BestAgent { get; private set; }
        public Agent[] Agents { get; private set; }
        public bool ReachedTheGoal { get; private set; }


        public Population(int directionArraySize,int populationQuantity, int layersQuantity)
        {
            if (layersQuantity != 1)
                color = Random.ColorHSV();
            ReachedTheGoal = false;
            fitnessSum = 0;
            Agents = new Agent[populationQuantity];
            if (layersQuantity != 1)
                for (int i = 0; i < Agents.Length; i++)
                    Agents[i] = new Agent(directionArraySize) { Color = color };
            else
                for (int i = 0; i < Agents.Length; i++)
                    Agents[i] = new Agent(directionArraySize);
            Gen = 1;
            minStep = 4000;
            BestAgent = 0;
            this.layersQuantity = layersQuantity;
        }

        public void Update()
        {
            for (int i = 0; i < Agents.Length; i++)
            {
                if (Agents[i].Brain.Step > minStep)
                    Agents[i].Dead = true;
                else
                    Agents[i].Update();
                ReachedTheGoal |= Agents[i].ReachedGoal;
            }
        }

        public void Mutate()
        {
            for (int i = 1; i < Agents.Length; i++)
                Agents[i].Brain.Mutate();
        }

        public void SetBestAgent()
        {
            float max = 0;
            int maxIndex = 0;
            for (int i = 0; i < Agents.Length; i++)
                if (Agents[i].Fitness > max)
                {
                    max = Agents[i].Fitness;
                    maxIndex = i;
                }
            BestAgent = maxIndex;
            if (Agents[BestAgent].ReachedGoal)
                minStep = Agents[BestAgent].Brain.Step;
        }

        public Agent SelectParent()
        {
            float random = Random.Range(0, fitnessSum);
            float runningSum = 0;
            for (int i = 0; i < Agents.Length; i++)
            {
                runningSum += Agents[i].Fitness;
                if (runningSum > random)
                    return Agents[i];
            }
            return null;
        }

        public bool AllAgentsDead()
        {
            for (int i = 0; i < Agents.Length; i++)
                if (!Agents[i].Dead && !Agents[i].ReachedGoal)
                    return false;
            return true;
        }

        public void CalculateFitness()
        {
            for (int i = 0; i < Agents.Length; i++)
                Agents[i].CalculateFitness();
        }

        public void NaturalSelection()
        {
            CalculateFitnessSum();
            Agent[] newAgents = new Agent[Agents.Length];
            SetBestAgent();
            newAgents[0] = Agents[BestAgent].GetCopy();
            newAgents[0].IsBest = true;
            for (int i = 1; i < Agents.Length; ++i)
            {
                Agent parent = SelectParent();
                newAgents[i] = parent.GetCopy();
            }
            Agents = newAgents;
            if (layersQuantity != 1)
                for (int i = 0; i < Agents.Length; i++)
                    Agents[i].Color = color;
            Gen++;
        }

        private void CalculateFitnessSum()
        {
            fitnessSum = 0;
            for (int i = 0; i < Agents.Length; i++)
                fitnessSum += Agents[i].Fitness;
        }
    };
}