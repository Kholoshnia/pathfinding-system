#include "menu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NNWay::menu form;
	Application::Run(% form);
	return 0;
}