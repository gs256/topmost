#include <iostream>
#include <windows.h>
#include "keyhook.hpp"
#include "core.hpp"
#include "config.hpp"

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
    keyHook.RegisterShortcut(Config::ToggleShortcut, Core::ToggleFocusedWindowTopmost);
    keyHook.RegisterShortcut(Config::MakeTopmostShortcut, Core::MakeFocusedWindowTopmost);
    keyHook.RegisterShortcut(Config::MakeNotopmostShortcut, Core::MakeFocusedWindowNotopmost);
    keyHook.RegisterShortcut(Config::ExitShortcut, Exit);
    keyHook.Listen();

    return 0;
}
