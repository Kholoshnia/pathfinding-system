using UnityEngine;
using UnityEngine.UI;

public class DropdownStartPositions : MonoBehaviour
{
	public int value;
    public bool valueChanged;

	public void OnValueChanged()
	{
		if (GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().options[GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().value].text != "Choose start...")
		{
            valueChanged = true;
			value = GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().value;
			GameObject.FindWithTag("StartPositions").GetComponent<Dropdown>().SetValueWithoutNotify(0);
		}
	}
}
