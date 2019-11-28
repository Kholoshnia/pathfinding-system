using System.IO;
using UnityEngine;
using UnityEditor;
using UnityEngine.SceneManagement;
using System.Collections.Generic;

public class Main : MonoBehaviour
{
    [SerializeField] private Vector3 mapSize;
    private bool isPlaying;
    private string path;

    void Start()
    {
        isPlaying = true;
        
        List<Vector3> walls = new List<Vector3>();

        for (int i = 0; i < SceneManager.GetActiveScene().GetRootGameObjects().Length; i++)
        {
            if (SceneManager.GetActiveScene().GetRootGameObjects()[i].tag == "wall")
                walls.Add(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.position);
        }

        if (isPlaying)
        {
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

                int k = 0;
                for (int z = 0; z < mapSize.z; z++)
                {
                    for (int y = 0; y < mapSize.y; y++)
                    {
                        for (int x = 0; x < mapSize.x; x++)
                        {
                            bool wallThere = false;
                            for (int i = 0; i < walls.Count; i++)
                                if (walls[i] == GameObject.Find("space (" + k + ')').transform.position)
                                    wallThere = true;

                            if (GameObject.FindWithTag("goal").transform.position == GameObject.Find("space (" + k + ')').transform.position)
                                writer.Write('G');
                            else if (wallThere)
                                writer.Write('W');
                            else
                                writer.Write('S');
                            writer.Write(';');
                            k++;
                        }
                        writer.WriteLine();
                    }
                    writer.WriteLine();
                }
            }
            fout.Close();

            Application.Quit();
            isPlaying = false;
        }
    }
}
