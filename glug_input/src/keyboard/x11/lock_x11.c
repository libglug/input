#include "../lock_util.h"
#include <glug/input/keyboard/locks.h>

#include <X11/Xutil.h>

int code_from_lock(enum key_locks lock)
{
    switch (lock)
    {
    case glug_kl_caps:          return XK_Caps_Lock;
    case glug_kl_num:           return XK_Num_Lock;
    case glug_kl_scroll:        return XK_Scroll_Lock;
    case glug_kl_none:          // fall-through
    case glug_kl_unknown:       break;
    }

    return 0;
}

enum key_locks lock_from_code(int lock)
{
    switch (lock)
    {
    case XK_Caps_Lock:          return glug_kl_caps;
    case XK_Num_Lock:           return glug_kl_num;
    case XK_Scroll_Lock:        return glug_kl_scroll;
    default:                    return glug_kl_none;
    }
}
