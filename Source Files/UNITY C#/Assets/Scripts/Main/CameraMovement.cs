using UnityEngine;

public class CameraMovement : MonoBehaviour
{
    private int yMaxLimit = 80;
    private int yMinLimit = -80;
    private float xSpeed = 200.0f;
    private float ySpeed = 200.0f;
    private float zoomDampening = 5.0f;

    private float xDeg;
    private float yDeg;
    private Quaternion rotation;
    private Quaternion currentRotation;
    private Quaternion desiredRotation;

    public void Start() { Init(); }
    public void OnEnable() { Init(); }

    public void Init()
    {
        rotation = transform.rotation;
        currentRotation = transform.rotation;
        desiredRotation = transform.rotation;

        xDeg = Vector3.Angle(Vector3.right, transform.right);
        yDeg = Vector3.Angle(Vector3.up, transform.up);
    }

    public void LateUpdate()
    {
        if (Input.GetMouseButton(0))
        {
            xDeg += Input.GetAxis("Mouse X") * xSpeed * 0.02f;
            yDeg -= Input.GetAxis("Mouse Y") * ySpeed * 0.02f;
            yDeg = ClampAngle(yDeg, yMinLimit, yMaxLimit);
            desiredRotation = Quaternion.Euler(yDeg, xDeg, 0);
            currentRotation = transform.rotation;
            rotation = Quaternion.Lerp(currentRotation, desiredRotation, Time.deltaTime * zoomDampening);
            transform.rotation = rotation;
        }

        if (Input.GetKey(KeyCode.W))
            transform.Translate(Vector3.forward * xSpeed * Time.deltaTime / 10.0f);
        if (Input.GetKey(KeyCode.A))
            transform.Translate(Vector3.left * ySpeed * Time.deltaTime / 10.0f);
        if (Input.GetKey(KeyCode.S))
            transform.Translate(-Vector3.forward * xSpeed * Time.deltaTime / 10.0f);
        if (Input.GetKey(KeyCode.D))
            transform.Translate(Vector3.right * ySpeed * Time.deltaTime / 10.0f);
    }

    private static float ClampAngle(float angle, float min, float max)
    {
        if (angle < -360)
            angle += 360;
        if (angle > 360)
            angle -= 360;
        return Mathf.Clamp(angle, min, max);
    }
}