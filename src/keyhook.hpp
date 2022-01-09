#pragma once
#include <iostream>
#include <functional>
#include <vector>

class KeyHook
{
public:
    KeyHook();
    bool RegisterShortcut(unsigned modifiers, unsigned keyCode, std::function<void()> callback);
    void Listen();

private:
    struct Shortcut 
    {
        int Id;
        std::function<void()> Callback;
    };

    int availableShortcutId;
    std::vector<Shortcut> shortcuts;

    int GetShortcutId();
    void OnShortcutPressed(int shortcutId);
};
