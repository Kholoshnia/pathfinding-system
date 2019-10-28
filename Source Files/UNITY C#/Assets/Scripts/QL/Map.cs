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

            /*int x = 0, y = 0, z = 0;
            for (int i = 0; i < mapSize.x * mapSize.y * mapSize.z; i++)
            {
                x++;
                if (x > mapSize.x)
                {
                    x = 0;
                    y++;
                }
                if (y > mapSize.y)
                {
                    z++;
                    y = 0;
                }
            }

            Vector3Int tempMapSize = Vector3Int.zero;
            for (int i = 0; i < spaces.Length; i++)
                if (spaces[i].transform.position.x >= tempMapSize.x && spaces[i].transform.position.y >= tempMapSize.y && spaces[i].transform.position.z >= tempMapSize.z)
                    tempMapSize = new Vector3Int((int)spaces[i].transform.position.x , (int)spaces[i].transform.position.y, (int)spaces[i].transform.position.z);

            mapSize = tempMapSize;*/
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
                            walls.Add(Object.Instantiate(wall));
                            k++;
                        }
                        if (map[z, x, y] == 'F')
                        {
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
