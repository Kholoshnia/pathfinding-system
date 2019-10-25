#include "menu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(int argc, char* argv[])
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NNWay::menu form;
	Application::Run(% form);
	return 0;
}