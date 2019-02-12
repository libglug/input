#include "../lock_util.hpp"
#include "lock_defs.hpp"
#include <glug_input/keyboard/locks.hpp>

int code_from_lock(enum locks lock)
{
    switch (lock)
    {
    case glug_lock_caps:        return gMask_Alpha;
    case glug_lock_num:         return gMask_Num;
    case glug_lock_scroll:      // return ??;
    case glug_lock_none:        // fall-through
    case glug_lock_unknown:     break;
    }

  return 0;
}

enum locks lock_from_code(int lock)
{
    switch(lock)
    {
    case gMask_Alpha:           return glug_lock_caps;
    case gMask_Num:             return glug_lock_num;
//    case ??:                    return glug_lock_scroll;
    default:                    return glug_lock_none;
    }
}
