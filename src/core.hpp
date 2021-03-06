#pragma once
#include "Windows.h"

namespace Core 
{
    bool IsFocusedWindowTopmost();
    void ToggleFocusedWindowTopmost();
    void MakeFocusedWindowTopmost();
    void MakeFocusedWindowNotopmost();
}