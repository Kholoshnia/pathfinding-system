using UnityEngine;

public class OnCollision : MonoBehaviour
{
    public bool wall, goal;

    void Awake()
    {
        wall = false;
        goal = false;
    }

    void OnCollisionStay(Collision collision)
    {
        switch (collision.collider.tag)
        {
            case "goal":
                goal = true;
                break;
            case "wall":
                wall = true;
                break;
        }
    }

}
