using System;
using System.IO;
using UnityEngine;
using UnityEditor;
using System.Collections.Generic;

public class Main : MonoBehaviour
{
    [SerializeField] private GameObject space;
    [SerializeField] private Transform spaceTransform;

    private string path;
    private Vector3Int mapSize;

    void Start()
    {
        mapSize.x = Convert.ToInt32(spaceTransform.localScale.x);
        mapSize.y = Convert.ToInt32(spaceTransform.localScale.y);
        mapSize.z = Convert.ToInt32(spaceTransform.localScale.z);

        List<GameObject> grid = new List<GameObject>();

        for (int z = 0; z < mapSize.z; z++)
            for (int y = 0; y < mapSize.y; y++)
                for (int x = 0; x < mapSize.x; x++)
                {
                    GameObject newSpace = Instantiate(space);
                    newSpace.transform.position = new Vector3(x, y, z);// - spaceTransform.localScale / 2;
                    grid.Add(newSpace);
                }

        Destroy(space);

        for (int i = 0; i < grid.Count; i++)
            if (grid[i].GetComponent<OnCollision>().goal)
                Debug.Log("true");

        path = EditorUtility.SaveFilePanel("Save new map", "", "Map", "csv");

        FileStream fout = new FileStream(path, FileMode.Create);
        using (StreamWriter writer = new StreamWriter(fout))
        {
            writer.Write("map-size:;");
            writer.Write(mapSize.x);
            writer.Write(';');
            writer.Write(mapSize.y);
            writer.Write(';');
            writer.WriteLine(mapSize.z);
            writer.WriteLine();

            for (int z = 0; z < mapSize.z; z++)
            {
                for (int y = 0; y < mapSize.y; y++)
                {
                    for (int x = 0; x < mapSize.x; x++)
                    {
                        int k = mapSize.y * mapSize.x * z + mapSize.y * y + x;

                        if (grid[k].GetComponent<OnCollision>().goal)
                            writer.Write('G');
                        else if (grid[k].GetComponent<OnCollision>().wall)
                            writer.Write('W');
                        else
                            writer.Write('S');

                        writer.Write(';');
                    }
                    writer.WriteLine();
                }
                writer.WriteLine();
            }
        }
        fout.Close();

        for (int i = 0; i < grid.Count; i++)
            Destroy(grid[i]);
        Application.Quit();
    }
}
