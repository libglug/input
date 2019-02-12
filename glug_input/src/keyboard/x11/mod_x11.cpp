#include "../mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <X11/Xutil.h>

int code_from_mod(enum mods mod)
{
    switch (mod)
    {
    case glug_mod_shift:    return ShiftMask;
    case glug_mod_alt:      return Mod1Mask;
    case glug_mod_ctrl:     return ControlMask;
    case glug_mod_super:    return Mod4Mask;
    case glug_mod_none:     // fall-through
    case glug_mod_unknown:  break;
    }

    return 0;
}

enum mods mod_from_code(int mod)
{
    switch (mod)
    {
    case ShiftMask:         return glug_mod_shift;
    case Mod1Mask:          return glug_mod_alt;
    case ControlMask:       return glug_mod_ctrl;
    case Mod4Mask:          return glug_mod_super;
    default:                return glug_mod_none;
    }
}
