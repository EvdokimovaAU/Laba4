#include <windows.h>
#include "Win32Window.h"
#include "InputDevice.h"

int Run(Win32Window& window, InputDevice& input)
{
    MSG msg{};
    while (!window.IsExitRequested())
    {
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }

        // Проверка InputDevice
        if (input.IsKeyDown('W'))
        {
            OutputDebugStringW(L"W pressed\n");
        }

        Sleep(1);
    }

    return (int)msg.wParam;
}

int WINAPI wWinMain(HINSTANCE hInstance,
    HINSTANCE,
    PWSTR,
    int nCmdShow)
{
    InputDevice input;

    Win32Window window;
    window.SetInputDevice(&input);

    if (!window.Create(hInstance,
        nCmdShow,
        800,
        600,
        L"MyWindowClass",
        L"DX12 Part One"))
        return 0;

    return Run(window, input);
}
