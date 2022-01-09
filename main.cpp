#include <iostream>
#include <Windows.h>

HWND GetFocusedWindow()
{
    return GetForegroundWindow();
}

bool TryGetWindowTopmostStatus(HWND windowHandle, bool& outIsTopmost)
{
    if (!windowHandle)
        return false;

    outIsTopmost = GetWindowLong(windowHandle, GWL_EXSTYLE) & WS_EX_TOPMOST;
    return true;
}

void ToggleFocusedWindowTopmost()
{
    HWND focusedWindow = GetFocusedWindow();
    bool isTopmost;

    if (TryGetWindowTopmostStatus(focusedWindow, isTopmost))
    {
        HWND zFlag = isTopmost ? HWND_NOTOPMOST : HWND_TOPMOST;
        SetWindowPos(focusedWindow, zFlag, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
}

void OnKeyDown(unsigned long keyCode)
{
    std::cout << keyCode << " keydown\n";
}

void OnKeyUp(unsigned long keyCode)
{
    std::cout << keyCode << " keyup\n";
}

LRESULT CALLBACK CheckShortcut(int iCode, WPARAM wParam, LPARAM lParam)
{
    PKBDLLHOOKSTRUCT pHook = (PKBDLLHOOKSTRUCT)lParam;
    DWORD keyCode = pHook->vkCode;

    if (wParam == WM_KEYDOWN)
        OnKeyDown(keyCode);
    else if (wParam == WM_KEYUP)
        OnKeyUp(keyCode);

    return CallNextHookEx(NULL, iCode, wParam, lParam);
}

void StartKeyHook()
{
    HHOOK keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, CheckShortcut, NULL, NULL);
    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(keyHook);
}

int main(int argc, char* argv[])
{
    // ToggleFocusedWindowTopmost();
    StartKeyHook();
    std::cout << "Starting keyboard hook\n";
}
