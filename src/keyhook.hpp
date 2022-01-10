#pragma once
#include <iostream>
#include <functional>
#include <vector>

struct Shortcut
{
    unsigned modifiers;
    unsigned keyCode;
};

class KeyHook
{
public:
    KeyHook();
    bool RegisterShortcut(Shortcut shortcut, std::function<void()> callback);
    void Listen();

private:
    struct RegisteredShortcut 
    {
        int Id;
        std::function<void()> Callback;
    };

    int availableShortcutId;
    std::vector<RegisteredShortcut> shortcuts;

    int GetShortcutId();
    void OnShortcutPressed(int shortcutId);
};
