using System;
using System.IO;
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

        public Map(ref Vector3Int mapSize, ref string language, ref string pathIn)
        {
            FileStream fin = new FileStream(pathIn, FileMode.Open);

            using (StreamReader reader = new StreamReader(fin))
            {
                mapSize = new Vector3Int(Convert.ToInt32(reader.ReadLine()), Convert.ToInt32(reader.ReadLine()), Convert.ToInt32(reader.ReadLine()));
                map = new char[mapSize.z, mapSize.y, mapSize.x];

                for (int z = 0; z < mapSize.z; z++)
                    for (int y = 0; y < mapSize.y; y++)
                    {
                        for (int x = 0; x < mapSize.x; x++)
                            map[z, x, y] = (char)reader.Read();
                        reader.Read();
                    }

                language = reader.ReadLine();
            }
            fin.Close();

            spaces = new List<GameObject>();
            walls = new List<GameObject>();

            GameObject space = GameObject.Find("QL_Space"), wall = GameObject.Find("QL_Wall"), goal = GameObject.Find("QL_Goal");

            initials = new List<int>();

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
                            spaces.Add(UnityEngine.Object.Instantiate(space));
                            initials.Add(k);
                            k++;
                        }
                        if (map[z, x, y] == 'W')
                        {
                            walls.Add(UnityEngine.Object.Instantiate(wall));
                            k++;
                        }
                        if (map[z, x, y] == 'F')
                        {
                            finish = UnityEngine.Object.Instantiate(goal);
                            k++;
                        }
                    }

            UnityEngine.Object.Destroy(space);
            UnityEngine.Object.Destroy(wall);
            UnityEngine.Object.Destroy(goal);

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
    };
}
