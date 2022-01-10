#include <iostream>
#include <windows.h>
#include "keyhook.hpp"
#include "core.hpp"
#include "config.hpp"

void ToggleTopmost()
{
    Core::ToggleFocusedWindowTopmost();
}

void Exit()
{
    std::exit(0);
}

bool AnotherInstanceRunning()
{
    HANDLE globalEvent = CreateEvent(NULL, false, false, Config::WindowsEventName);

    if (globalEvent == NULL)
        return false;

    if (GetLastError() == ERROR_ALREADY_EXISTS) 
        return true;

    return false;
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    if (AnotherInstanceRunning())
        return 1;

    KeyHook keyHook;
    keyHook.RegisterShortcut(MOD_ALT, 0x50, ToggleTopmost);
    keyHook.RegisterShortcut(MOD_ALT | MOD_CONTROL, 0x50, Exit);
    keyHook.Listen();

    return 0;
}
