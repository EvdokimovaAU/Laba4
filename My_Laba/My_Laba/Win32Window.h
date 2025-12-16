#pragma once
#include <windows.h>
#include <string>

class InputDevice;

class Win32Window {
public:
    bool Create(HINSTANCE hInstance,
        int nCmdShow,
        int clientWidth,
        int clientHeight,
        const wchar_t* className,
        const wchar_t* title);

    void SetInputDevice(InputDevice* input);
    bool IsExitRequested() const;

    LRESULT HandleMessage(UINT msg, WPARAM wParam, LPARAM lParam);

    static LRESULT CALLBACK WndProc(HWND hWnd,
        UINT msg,
        WPARAM wParam,
        LPARAM lParam);

private:
    HWND m_hWnd = nullptr;
    bool m_exitRequested = false;
    InputDevice* m_input = nullptr;
};



