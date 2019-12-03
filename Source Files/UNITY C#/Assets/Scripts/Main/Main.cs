using System.IO;
using UnityEngine;

public class Main : MonoBehaviour
{
    private Modes mode;
    private LearningAlgorithms learningAlgorithm;

    private string pathInfoIn, pathInfoOut, pathInfo;

    private Assets.Scripts.NEAT.Logic NEAT_logic;
    private Assets.Scripts.QL.Logic QL_logic;

    public void Awake()
    {

        switch (Application.platform)
        {
            case RuntimePlatform.WindowsPlayer:
                pathInfo = Application.dataPath.Remove(Application.dataPath.Length - 29) + "data/info.csv";
                break;
            case RuntimePlatform.OSXEditor:
                pathInfo = Application.dataPath.Remove(Application.dataPath.Length - 14) + "Release Files/data/info.csv";
                break;
        }

        FileStream fin = new FileStream(pathInfo, FileMode.Open);

        using (StreamReader reader = new StreamReader(fin))
        {
            pathInfoIn = reader.ReadLine();
            pathInfoOut = reader.ReadLine();

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
        }
        fin.Close();
    }

    public void Start()
    {
        switch (learningAlgorithm)
        {
            case LearningAlgorithms.NEAT:
                NEAT_logic = new Assets.Scripts.NEAT.Logic(mode, pathInfoIn, pathInfoOut, pathInfo);
                break;
            case LearningAlgorithms.QL:
                QL_logic = new Assets.Scripts.QL.Logic(mode, pathInfoIn, pathInfoOut, pathInfo);
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
