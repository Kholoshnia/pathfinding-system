using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.QL
{
    class Map
    {
        public char[,,] map;
        public List<int> Initials { get; }
        public List<GameObject> Walls { get; }
        public GameObject Finish { get; private set; }
        public List<GameObject> Spaces { get; private set; }

        public Map()
        {
            Initials = new List<int>();
            Walls = new List<GameObject>();
            Spaces = new List<GameObject>();
        }

        public void Initialize(Vector3Int mapSize)
        {
            GameObject space = GameObject.Find("QL_Space"), wall = GameObject.Find("QL_Wall"), goal = GameObject.Find("QL_Goal");

            int k = 0;
            for (int z = mapSize.z - 1; z >= 0; z--)
                for (int y = mapSize.y - 1; y >= 0; y--)
                    for (int x = 0; x < mapSize.x; x++)
                    {
                        space.transform.position = new Vector3(x, mapSize.y - 1 - y, mapSize.z - 1 - z);

                        if (map[z, y, x] == 'B')
                        {
                            Spaces.Add(Object.Instantiate(space));
                            Initials.Add(k);
                            k++;
                        }
                        if (map[z, y, x] == 'W')
                        {
                            wall.transform.position = new Vector3(x, y, z);
                            Spaces.Add(Object.Instantiate(space));
                            Walls.Add(Object.Instantiate(wall));
                            k++;
                        }
                        if (map[z, y, x] == 'F')
                        {
                            goal.transform.position = new Vector3(x, y, z);
                            Spaces.Add(Object.Instantiate(space));
                            Finish = Object.Instantiate(goal);
                            k++;
                        }
                    }

            for (int i = 0; i < Spaces.Count; i++)
                Spaces[i].name = "Position " + i;

            for (int i = 0; i < Walls.Count; i++)
                Walls[i].name = "Walls " + i;

            Object.Destroy(space);
            Object.Destroy(wall);
            Object.Destroy(goal);
        }
    };
}
