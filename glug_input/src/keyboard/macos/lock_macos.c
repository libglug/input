#include "../lock_util.h"
#include "lock_defs.h"
#include <glug_input/keyboard/locks.h>

int code_from_lock(enum key_locks lock)
{
    switch (lock)
    {
    case glug_kl_caps:          return gMask_Alpha;
    case glug_kl_num:           return gMask_Num;
    case glug_kl_scroll:        // return ??;
    case glug_kl_none:          // fall-through
    case glug_kl_unknown:       break;
    }

  return 0;
}

enum key_locks lock_from_code(int lock)
{
    switch(lock)
    {
    case gMask_Alpha:           return glug_kl_caps;
    case gMask_Num:             return glug_kl_num;
//    case ??:                    return glug_kl_scroll;
    default:                    return glug_kl_none;
    }
}
