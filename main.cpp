#include <iostream>
#include <Windows.h>
#include <optional>

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

void OnShortcutPressed(int shortcutId)
{
    std::cout << shortcutId << " pressed\n";
    ToggleFocusedWindowTopmost();
}

bool RegisterShortcut(int shortcutId, unsigned modifiers, unsigned keyCode)
{
    return RegisterHotKey(NULL, shortcutId, modifiers | MOD_NOREPEAT, keyCode);
}

void ListenToWindowsEvents()
{
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (msg.message == WM_HOTKEY)
        {
            OnShortcutPressed((int)msg.wParam);
        }
    } 
}

int main(int argc, char* argv[])
{
    // ToggleFocusedWindowTopmost();
    RegisterShortcut(-123, MOD_ALT, 0x50);
    std::cout << "Starting keyboard hook\n";
    ListenToWindowsEvents();
}
