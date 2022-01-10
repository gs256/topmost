#pragma once
#include "imm.h"

namespace Config
{
    // Used to prevent running multiple instances.
    // `Global` prefix for global event
    const char* WindowsEventName = "Global\\topmost";

    const Shortcut ToggleShortcut { MOD_ALT, 0x50 };
    const Shortcut ExitShortcut { MOD_ALT | MOD_CONTROL, 0x50 };
}
