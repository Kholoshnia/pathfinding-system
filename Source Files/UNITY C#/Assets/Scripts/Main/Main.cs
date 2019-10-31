using System.IO;
using UnityEngine;

public class Main : MonoBehaviour
{
    private Modes mode;
    private Languages language;
    private LearningAlgorithms learningAlgorithm;

    private string path, pathIn, pathOut;

    private Assets.Scripts.NEAT.Logic NEAT_logic;
    private Assets.Scripts.QL.Logic QL_logic;

    public void Awake()
    {
        switch (Application.platform)
        {
            case RuntimePlatform.WindowsEditor:
                path = Application.dataPath.Remove(Application.dataPath.Length - 28) + "Demo Files/3D/Data Files/data-ql.csv";
                break;
            case RuntimePlatform.WindowsPlayer:
                path = Application.dataPath.Remove(Application.dataPath.Length - 6) + "data/info.csv";
                break;
            case RuntimePlatform.OSXEditor:
<<<<<<< Updated upstream
                path = "/Users/vadim/Documents/GitHub/NEAT-QL/Demo Files/3D/Data Files/data.txt";
                break;
            case RuntimePlatform.OSXPlayer:
                path = "/Users/vadim/Documents/GitHub/NEAT-QL/Demo Files/3D/Data Files/data.txt";
=======
                path = Application.dataPath.Remove(Application.dataPath.Length - 28) + "Demo Files/3D/Data Files/data-ql.csv";
                break;
            case RuntimePlatform.OSXPlayer:
                path = Application.dataPath.Remove(Application.dataPath.Length - 6) + "data/info.csv";
>>>>>>> Stashed changes
                break;
        }

        FileStream fin = new FileStream(path, FileMode.Open);

        using (StreamReader reader = new StreamReader(fin))
        {
            switch (reader.ReadLine())
            {
                case "EN":
                    language = Languages.EN;
                    break;
                case "RU":
                    language = Languages.RU;
                    break;
                default:
                    Debug.Log("Incorrect language");
                    break;
            }

            switch (reader.ReadLine())
            {
                case "NEAT":
                    learningAlgorithm = LearningAlgorithms.NEAT;
                    break;
                case "QL":
                    learningAlgorithm = LearningAlgorithms.QL;
                    break;
                default:
                    Debug.Log("Incorrect learning algorithm");
                    break;
            }

            switch (reader.ReadLine())
            {
                case "LEARN":
                    mode = Modes.LEARN;
                    break;
                case "CHECK":
                    mode = Modes.CHECK;
                    break;
                default:
                    Debug.Log("Incorrect mode");
                    break;
            }

            pathIn = reader.ReadLine();
            pathOut = reader.ReadLine();
        }
        fin.Close();
    }

    public void Start()
    {
        switch (learningAlgorithm)
        {
            case LearningAlgorithms.NEAT:
                NEAT_logic = new Assets.Scripts.NEAT.Logic(mode, language, pathIn, pathOut);
                break;
            case LearningAlgorithms.QL:
                QL_logic = new Assets.Scripts.QL.Logic(mode, language, pathIn, pathOut);
                break;
        }
    }

    public void Update()
    {
        switch (learningAlgorithm)
        {
            case LearningAlgorithms.NEAT:
                switch (mode)
                {
                    case Modes.LEARN:
                        NEAT_logic.Learn();
                        break;
                    case Modes.CHECK:
                        NEAT_logic.Check();
                        break;
                }

                break;
            case LearningAlgorithms.QL:
                switch (mode)
                {
                    case Modes.LEARN:
                        QL_logic.Learn();
                        break;
                    case Modes.CHECK:
                        QL_logic.Check();
                        break;
                }
                break;
        }
    }
}