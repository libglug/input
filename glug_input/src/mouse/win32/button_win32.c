#include "../button_util.h"
#include <glug/input/mouse/buttons.h>

#include <Windows.h>

int code_from_button(enum mouse_buttons button)
{
    switch(button)
    {
    case glug_mb_left:          return VK_LBUTTON;
    case glug_mb_mid:           return VK_MBUTTON;
    case glug_mb_right:         return VK_RBUTTON;
    case glug_mb_ex1:           return VK_XBUTTON1;
    case glug_mb_ex2:           return VK_XBUTTON2;
    case glug_mb_none:          // fall-through
    case glug_mb_unknown:       break;
    }

    return 0;
}

enum mouse_buttons button_from_code(int button)
{
    switch(button)
    {
    case VK_LBUTTON:            return glug_mb_left;
    case VK_MBUTTON:            return glug_mb_mid;
    case VK_RBUTTON:            return glug_mb_right;
    case VK_XBUTTON1:           return glug_mb_ex1;
    case VK_XBUTTON2:           return glug_mb_ex2;
    default:                    return glug_mb_none;
    }
}
