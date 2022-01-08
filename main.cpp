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

int main(int argc, char* argv[])
{
    ToggleFocusedWindowTopmost();
    std::cout << "Toggled topmost flag\n";
}
