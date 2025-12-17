#include <windows.h>
#include "Appllication.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    Application app(hInstance);

    if (!app.Initialize(nCmdShow))
        return 0;

    return app.Run();
}

