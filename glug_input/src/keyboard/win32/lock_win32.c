#include "../lock_util.h"
#include <glug_input/keyboard/locks.h>

#include <Windows.h>

int code_from_lock(enum key_locks lock)
{
    switch (lock)
    {
    case glug_kl_caps:          return VK_CAPITAL;
    case glug_kl_num:           return VK_NUMLOCK;
    case glug_kl_scroll:        return VK_SCROLL;
    case glug_kl_none:          // fall-through
    case glug_kl_unknown:       break;
    }

    return 0;
}

enum key_locks lock_from_code(int lock)
{
    switch (lock)
    {
    case VK_CAPITAL:            return glug_kl_caps;
    case VK_NUMLOCK:            return glug_kl_num;
    case VK_SCROLL:             return glug_kl_scroll;
    default:                    return glug_kl_none;
    }
}
