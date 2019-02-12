#include "../button_util.h"
#include <glug_input/mouse/buttons.h>

#include <Windows.h>

int code_from_button(enum buttons button)
{
    switch(button)
    {
    case glug_btn_left:     return VK_LBUTTON;
    case glug_btn_mid:      return VK_MBUTTON;
    case glug_btn_right:    return VK_RBUTTON;
    case glug_btn_ex1:      return VK_XBUTTON1;
    case glug_btn_ex2:      return VK_XBUTTON2;
    case glug_btn_none:     // fall-through
    case glug_btn_unknown:  break;
    }

    return 0;
}

enum buttons button_from_code(int button)
{
    switch(button)
    {
    case VK_LBUTTON:        return glug_btn_left;
    case VK_MBUTTON:        return glug_btn_mid;
    case VK_RBUTTON:        return glug_btn_right;
    case VK_XBUTTON1:       return glug_btn_ex1;
    case VK_XBUTTON2:       return glug_btn_ex2;
    default:                return glug_btn_none;
    }
}
