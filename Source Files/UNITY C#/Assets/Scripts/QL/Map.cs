using System.Collections.Generic;
using UnityEngine;

namespace Assets.Scripts.QL
{
    class Map
    {
        public char[,,] map;

        public List<int> initials;
        public GameObject finish;
        public List<GameObject> spaces, walls;

        public Map()
        {
            initials = new List<int>();
            walls = new List<GameObject>();
            spaces = new List<GameObject>();
        }

        public void Initialize(Vector3Int mapSize)
        {
            GameObject space = GameObject.Find("QL_Space"), wall = GameObject.Find("QL_Wall"), goal = GameObject.Find("QL_Goal");

            int k = 0;
            for (int z = mapSize.z - 1; z >= 0; z--)
                for (int y = mapSize.y - 1; y >= 0; y--)
                    for (int x = 0; x < mapSize.x; x++)
                    {
                        space.transform.position = new Vector3(x, y, z);

                        if (map[z, y, x] == 'B')
                        {
                            spaces.Add(Object.Instantiate(space));
                            initials.Add(k);
                            k++;
                        }
                        if (map[z, y, x] == 'W')
                        {
                            wall.transform.position = new Vector3(x, y, z);
                            spaces.Add(Object.Instantiate(space));
                            walls.Add(Object.Instantiate(wall));
                            k++;
                        }
                        if (map[z, y, x] == 'F')
                        {
                            goal.transform.position = new Vector3(x, y, z);
                            spaces.Add(Object.Instantiate(space));
                            finish = Object.Instantiate(goal);
                            k++;
                        }
                    }

            for (int i = 0; i < spaces.Count; i++)
                spaces[i].name = "Position " + i;

            Object.Destroy(space);
            Object.Destroy(wall);
            Object.Destroy(goal);
        }
    };
}
