using UnityEngine;

namespace Assets.Scripts.QL
{
    class Table
    {
        Vector3Int mapSize;
        private readonly float gamma;
        private int state, finishState;

        public long[,] R;
        public long[,] Q;

        public Table(long finishReward, Vector3Int mapSize, Map map, float gamma)
        {
            this.gamma = gamma;
            this.mapSize = mapSize;

            R = new long[mapSize.x * mapSize.y * mapSize.z, mapSize.x * mapSize.y * mapSize.z];
            Q = new long[mapSize.x * mapSize.y * mapSize.z, mapSize.x * mapSize.y * mapSize.z];

            for (int y = 0; y < mapSize.x * mapSize.y * mapSize.z; y++)
                for (int x = 0; x < mapSize.x * mapSize.y * mapSize.z; x++)
                {
                    R[y, x] = -1;
                    Q[y, x] = 0;
                }

            for (int z = 0; z < mapSize.z; z++)
                for (int y = 0; y < mapSize.y; y++)
                    for (int x = 0; x < mapSize.x; x++)
                    {
                        if (x - 1 >= 0)
                            if (map.map[z, y, x - 1] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + (x - 1)] = 0;
                            else if (map.map[z, y, x - 1] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + (x - 1)] = finishReward;

                        if (x + 1 < mapSize.x)
                            if (map.map[z, y, x + 1] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x + 1] = 0;
                            else if (map.map[z, y, x + 1] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x + 1] = finishReward;

                        if (y - 1 >= 0)
                            if (map.map[z, y - 1, x] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * (y - 1) + x] = 0;
                            else if (map.map[z, y - 1, x] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * (y - 1) + x] = finishReward;

                        if (y + 1 < mapSize.y)
                            if (map.map[z, y + 1, x] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * (y + 1) + x] = 0;
                            else if (map.map[z, y + 1, x] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * (y + 1) + x] = finishReward;

                        if (z - 1 >= 0)
                            if (map.map[z - 1, y, x] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x] = 0;
                            else if (map.map[z - 1, y, x] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x] = finishReward;

                        if (z + 1 < mapSize.z)
                            if (map.map[z + 1, y, x] == 'B')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x] = 0;
                            else if (map.map[z + 1, y, x] == 'F')
                                R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x] = finishReward;

                        if (map.map[z, y, x] == 'F')
                        {
                            R[mapSize.z * z + mapSize.y * y + x, mapSize.z * z + mapSize.y * y + x] = finishReward;
                            for (int i = 0; i < map.spaces.Count; i++)
                                if (map.spaces[i].transform.position == map.finish.transform.position)
                                    finishState = i;
                        }
                    }

            if (finishState == 0)
                Debug.Log("Finish not found");
        }

        void ChooseAnAction()
        {
            int possibleAction = GetRandomAction(0, mapSize.x * mapSize.y * mapSize.z - 1);
            if (R[state, possibleAction] >= 0)
            {
                Q[state, possibleAction] = (long)(R[state, possibleAction] + gamma * Maximum(possibleAction, false));
                state = possibleAction;
            }
        }

        public void Episode(int initState)
        {
            state = initState;
            if (state != finishState)
                do
                {
                    ChooseAnAction();
                } while (state == finishState);
            for (int i = 0; i < mapSize.x * mapSize.y * mapSize.z; i++)
                ChooseAnAction();
        }

        public int InferenceBestAction(int nowState)
        {
            double tempMaxQ = 0;
            int bestAction = 0;
            for (int i = 0; i < mapSize.x * mapSize.y * mapSize.z; ++i)
                if (Q[nowState, i] > tempMaxQ)
                {
                    tempMaxQ = Q[nowState, i];
                    bestAction = i;
                }
            return bestAction;
        }

        public long Maximum(int st, bool returnIndexOnly)
        {
            int winner;
            bool done = false;
            bool foundNewWinner;

            winner = 0;

            do
            {
                foundNewWinner = false;
                for (int i = 0; i < mapSize.x * mapSize.y * mapSize.z; i++)
                    if ((i < winner) || (i > winner))
                        if (Q[st, i] > Q[st, winner])
                        {
                            winner = i;
                            foundNewWinner = true;
                        }
                done |= foundNewWinner == false;
            } while (done == false);

            if (returnIndexOnly == true)
                return winner;
            return Q[st, winner];
        }

        int GetRandomAction(int lowerBound, int upperBound)
        {
            int act;
            bool choiceIsValid = false;
            do
            {
                act = Random.Range(lowerBound, upperBound);
                choiceIsValid |= R[state, act] > -1;
            } while (!choiceIsValid);
            return act;
        }
    };
}
