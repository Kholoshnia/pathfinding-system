using UnityEngine;

public class Information : MonoBehaviour
{
    public float GetDistance(GameObject obj) { return Vector3.Distance(obj.transform.position, transform.position); }
}