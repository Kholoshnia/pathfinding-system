using UnityEngine;

public class Main : MonoBehaviour
{
    enum LearningAlgorithm { NEAT, QL };

    [SerializeField] private bool checker;
    [SerializeField] private LearningAlgorithm learningAlgorithm;
    [SerializeField] private string pathForMap;
    [SerializeField] private string pathForResult;

    private Assets.Scripts.NEAT.Logic NEAT_logic;
    private Assets.Scripts.QL.Logic QL_logic;

    public void Awake()
    {
        if (learningAlgorithm == LearningAlgorithm.NEAT)
            NEAT_logic = new Assets.Scripts.NEAT.Logic(ref checker, ref pathForMap, ref pathForResult);
        else if (learningAlgorithm == LearningAlgorithm.QL)
            QL_logic = new Assets.Scripts.QL.Logic(ref pathForMap, ref pathForResult, ref checker);
    }

    public void Update()
    {
        if (learningAlgorithm == LearningAlgorithm.NEAT)
            NEAT_logic.Update();
        else if (learningAlgorithm == LearningAlgorithm.QL)
            QL_logic.Update();
    }
}