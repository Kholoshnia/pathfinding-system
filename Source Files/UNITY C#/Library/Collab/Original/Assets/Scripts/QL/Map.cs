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
            for (int z = 0; z < mapSize.z; z++)
                for (int y = 0; y < mapSize.y; y++)
                    for (int x = 0; x < mapSize.x; x++)
                    {
                        space.transform.position = new Vector3(x, y, z);
                        wall.transform.position = new Vector3(x, y, z);
                        goal.transform.position = new Vector3(x, y, z);

                        if (map[z, x, y] == 'B')
                        {
                            spaces.Add(Object.Instantiate(space));
                            initials.Add(k);
                            k++;
                        }
                        if (map[z, x, y] == 'W')
                        {
                            spaces.Add(Object.Instantiate(space));
                            walls.Add(Object.Instantiate(wall));
                            k++;
                        }
                        if (map[z, x, y] == 'F')
                        {
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
