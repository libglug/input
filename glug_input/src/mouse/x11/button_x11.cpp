#include "../button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <X11/extensions/XInput2.hpp>

// TODO: use built in button definitions(?)
#ifndef Button8
#define Button8 8
#endif

#ifndef Button9
#define Button9	9
#endif

int code_from_button(enum buttons button)
{
    switch(button)
    {
    case glug_btn_left:     return 1 << Button1;
    case glug_btn_mid:      return 1 << Button2;
    case glug_btn_right:    return 1 << Button3;
    case glug_btn_ex1:      return 1 << Button8;
    case glug_btn_ex2:      return 1 << Button9;
    case glug_btn_none:     // fall-through
    case glug_btn_unknown:  break;
    }

    return 0;
}

enum buttons button_from_code(int button)
{
    switch(button)
    {
    case 1 << Button1:      return glug_btn_left;
    case 1 << Button2:      return glug_btn_mid;
    case 1 << Button3:      return glug_btn_right;
    case 1 << Button8:      return glug_btn_ex1;
    case 1 << Button9:      return glug_btn_ex2;
    default:                return glug_btn_none;
    }
}
