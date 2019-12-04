#include <menu.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int CALLBACK WinMain(__in  HINSTANCE hInstance, __in  HINSTANCE hPrevInstance, __in  LPSTR lpCmdLine, __in  int nCmdShow)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NNWay::menu form;
	Application::Run(% form);
	return 0;
}