#include "../button_util.h"
#include <glug_input/mouse/buttons.h>

#include <X11/extensions/XInput2.h>

// TODO: use built in button definitions(?)
#ifndef Button8
#define Button8 8
#endif

#ifndef Button9
#define Button9	9
#endif

int code_from_button(enum mouse_buttons button)
{
    switch(button)
    {
    case glug_mb_left:          return 1 << Button1;
    case glug_mb_mid:           return 1 << Button2;
    case glug_mb_right:         return 1 << Button3;
    case glug_mb_ex1:           return 1 << Button8;
    case glug_mb_ex2:           return 1 << Button9;
    case glug_mb_none:          // fall-through
    case glug_mb_unknown:       break;
    }

    return 0;
}

enum mouse_buttons button_from_code(int button)
{
    switch(button)
    {
    case 1 << Button1:          return glug_mb_left;
    case 1 << Button2:          return glug_mb_mid;
    case 1 << Button3:          return glug_mb_right;
    case 1 << Button8:          return glug_mb_ex1;
    case 1 << Button9:          return glug_mb_ex2;
    default:                    return glug_mb_none;
    }
}
