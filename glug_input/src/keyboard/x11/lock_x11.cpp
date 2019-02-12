#include "../lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

#include <X11/Xutil.h>

int code_from_lock(enum locks lock)
{
    switch (lock)
    {
    case glug_lock_caps:        return XK_Caps_Lock;
    case glug_lock_num:         return XK_Num_Lock;
    case glug_lock_scroll:      return XK_Scroll_Lock;
    case glug_lock_none:        // fall-through
    case glug_lock_unknown:     break;
    }

    return 0;
}

enum locks lock_from_code(int lock)
{
    switch (lock)
    {
    case XK_Caps_Lock:          return glug_lock_caps;
    case XK_Num_Lock:           return glug_lock_num;
    case XK_Scroll_Lock:        return glug_lock_scroll;
    default:                    return glug_lock_none;
    }
}
