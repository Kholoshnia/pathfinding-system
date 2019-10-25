using UnityEngine;

namespace Assets.Scripts.QL
{
    class Agent
    {
        private GameObject Sphere;

        public Agent()
        {
            Sphere = GameObject.FindWithTag("Start");
        }
    };
}