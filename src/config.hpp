#pragma once
#include "imm.h"

namespace Config
{
    // Used to prevent running multiple instances.
    // `Global` prefix for global event
    const char* WindowsEventName = "Global\\topmost";

    // Global shortcuts
    const Shortcut MakeTopmostShortcut   { MOD_ALT, 0x50 };
    const Shortcut MakeNotopmostShortcut { MOD_ALT | MOD_CONTROL, 0x50 };
    const Shortcut ToggleShortcut        { MOD_ALT | MOD_CONTROL, VK_SPACE };
    const Shortcut ExitShortcut          { MOD_ALT | MOD_CONTROL, VK_BACK };
}
