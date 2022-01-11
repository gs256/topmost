#include "core.hpp"

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

void Core::ToggleFocusedWindowTopmost()
{
    if (IsFocusedWindowTopmost())
    {
        MakeFocusedWindowNotopmost();
    }
    else
    {
        MakeFocusedWindowTopmost();
    }
}

bool Core::IsFocusedWindowTopmost()
{
    HWND focusedWindow = GetFocusedWindow();
    bool isTopmost;

    if (!TryGetWindowTopmostStatus(focusedWindow, isTopmost))
        return false;
    
    return isTopmost;
}

void Core::MakeFocusedWindowTopmost()
{
    SetWindowPos(GetFocusedWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void Core::MakeFocusedWindowNotopmost()
{
    SetWindowPos(GetFocusedWindow(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
