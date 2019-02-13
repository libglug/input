#include "../mod_util.h"
#include <glug_input/keyboard/mods.h>

#include <X11/Xutil.h>

int code_from_mod(enum key_mods mod)
{
    switch (mod)
    {
    case glug_km_shift:         return ShiftMask;
    case glug_km_alt:           return Mod1Mask;
    case glug_km_ctrl:          return ControlMask;
    case glug_km_super:         return Mod4Mask;
    case glug_km_none:          // fall-through
    case glug_km_unknown:       break;
    }

    return 0;
}

enum key_mods mod_from_code(int mod)
{
    switch (mod)
    {
    case ShiftMask:             return glug_km_shift;
    case Mod1Mask:              return glug_km_alt;
    case ControlMask:           return glug_km_ctrl;
    case Mod4Mask:              return glug_km_super;
    default:                    return glug_km_none;
    }
}
