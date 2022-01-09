#pragma once
#include <iostream>
#include <functional>
#include <vector>

struct Shortcut 
{
    int Id;
    std::function<void()> Callback;
};

class KeyHook
{
public:
    KeyHook();
    bool RegisterShortcut(unsigned modifiers, unsigned keyCode, std::function<void()> callback);
    void Listen();

private:
    int availableShortcutId;
    std::vector<Shortcut> shortcuts;

    int GetShortcutId();
    void OnShortcutPressed(int shortcutId);
};
