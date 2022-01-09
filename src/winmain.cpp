#include <iostream>
#include <windows.h>
#include "keyhook.hpp"
#include "core.hpp"

void ToggleTopmost()
{
    Core::ToggleFocusedWindowTopmost();
}

void Exit()
{
    std::exit(0);
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    KeyHook keyHook;
    keyHook.RegisterShortcut(MOD_ALT, 0x50, ToggleTopmost);
    keyHook.RegisterShortcut(MOD_ALT | MOD_CONTROL, 0x50, Exit);
    keyHook.Listen();
    return 0;
}
