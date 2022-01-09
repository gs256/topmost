#include <iostream>
#include <Windows.h>
#include <optional>
#include "keyhook.hpp"
#include "core.hpp"

void ToggleTopmost()
{
    Core::ToggleFocusedWindowTopmost();

    if (Core::IsFocusedWindowTopmost())
        std::cout << "topmost\n";
    else
        std::cout << "notopmost\n";
}

void Exit()
{
    std::exit(0);
}

int main(int argc, char* argv[])
{
    KeyHook keyHook;
    keyHook.RegisterShortcut(MOD_ALT, 0x50, ToggleTopmost);
    keyHook.RegisterShortcut(MOD_ALT | MOD_CONTROL, 0x50, Exit);
    std::cout << "Starting keyboard hook\n";
    keyHook.Listen();
}
