#include <iostream>
#include <Windows.h>
#include <optional>
#include "keyhook.hpp"

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

void Callback()
{
    std::cout << "shortcut pressed\n";
    ToggleFocusedWindowTopmost();
}

int main(int argc, char* argv[])
{
    KeyHook keyHook;
    keyHook.RegisterShortcut(MOD_ALT, 0x50, Callback);
    std::cout << "Starting keyboard hook\n";
    keyHook.Listen();
}
