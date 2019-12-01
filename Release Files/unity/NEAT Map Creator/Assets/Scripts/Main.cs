using System.IO;
using UnityEngine;
using UnityEditor;
using UnityEngine.SceneManagement;

public class Main : MonoBehaviour
{
    private bool isPlaying;
    private string path;

    void Start()
    {
        isPlaying = true;

        if (isPlaying)
        {
            path = EditorUtility.SaveFilePanel("Load information file", "", "Map", "txt");

            FileStream fout = new FileStream(path, FileMode.Create);
            using (StreamWriter writer = new StreamWriter(fout))
            {
                writer.WriteLine("number-of-objects:;" + SceneManager.GetActiveScene().GetRootGameObjects().GetLength(0));
                for (int i = 0; i < SceneManager.GetActiveScene().GetRootGameObjects().GetLength(0); i++)
                {
                    writer.WriteLine();
                    writer.WriteLine(SceneManager.GetActiveScene().GetRootGameObjects()[i].name);

                    writer.Write("position:;");
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.position.x);
                    writer.Write(';');
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.position.y);
                    writer.Write(';');
                    writer.WriteLine(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.position.z);

                    writer.Write("rotation:;");
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.rotation.w);
                    writer.Write(';');
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.rotation.x);
                    writer.Write(';');
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.rotation.y);
                    writer.Write(';');
                    writer.WriteLine(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.rotation.z);

                    writer.Write("localScale:;");
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.localScale.x);
                    writer.Write(';');
                    writer.Write(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.localScale.y);
                    writer.Write(';');
                    writer.WriteLine(SceneManager.GetActiveScene().GetRootGameObjects()[i].transform.localScale.z);
                }
            }
            fout.Close();

            Application.Quit();
            isPlaying = false;
        }
    }
}
