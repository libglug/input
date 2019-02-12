#include "../lock_util.h"
#include <glug_input/keyboard/locks.h>

#include <Windows.h>

int code_from_lock(enum locks lock)
{
    switch (lock)
    {
    case glug_lock_caps:        return VK_CAPITAL;
    case glug_lock_num:         return VK_NUMLOCK;
    case glug_lock_scroll:      return VK_SCROLL;
    case glug_lock_none:        // fall-through
    case glug_lock_unknown:     break;
    }

    return 0;
}

enum locks lock_from_code(int lock)
{
    switch (lock)
    {
    case VK_CAPITAL:            return glug_lock_caps;
    case VK_NUMLOCK:            return glug_lock_num;
    case VK_SCROLL:             return glug_lock_scroll;
    default:                    return glug_lock_none;
    }
}
