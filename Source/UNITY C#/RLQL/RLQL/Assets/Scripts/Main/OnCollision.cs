using UnityEngine;

public class OnCollision : MonoBehaviour
{
    public bool touchedWall, touchedGoal;

    public void Awake()
    {
        touchedWall = false;
        touchedGoal = false;
    }

    public void OnCollisionEnter(Collision collisionInfo)
    {
        if (collisionInfo.collider.tag == "Goal")
            touchedGoal = true;
        else
            touchedWall = true;
    }
}
