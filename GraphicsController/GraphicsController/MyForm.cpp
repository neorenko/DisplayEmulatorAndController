#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[System::STAThread]
void main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    GraphicsController::MyForm form;
    Application::Run(% form);
}