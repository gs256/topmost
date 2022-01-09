#include <Windows.h>
#include "iostream"
#include "keyhook.hpp"

KeyHook::KeyHook()
    : availableShortcutId(1),
      shortcuts() { }

bool KeyHook::RegisterShortcut(unsigned modifiers, unsigned keyCode, std::function<void()> callback)
{
    int shortcutId = GetShortcutId();
    bool registered = RegisterHotKey(NULL, shortcutId, modifiers | MOD_NOREPEAT, keyCode);

    if (!registered)
        return false;

    shortcuts.push_back({ shortcutId, callback });
    return true;
}

void KeyHook::Listen()
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

int KeyHook::GetShortcutId()
{
    return availableShortcutId++;
}

void KeyHook::OnShortcutPressed(int shortcutId)
{
    for (auto& shortcut : shortcuts)
    {
        if (shortcut.Id == shortcutId)
        {
            if (shortcut.Callback)
            {
                shortcut.Callback();
            }
        }
    }
}
