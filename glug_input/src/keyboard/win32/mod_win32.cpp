#include "../mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <Windows.h>

int code_from_mod(enum mods mod)
{
    switch (mod)
    {
    case glug_mod_shift:        return VK_SHIFT;
    case glug_mod_alt:          return VK_MENU;
    case glug_mod_ctrl:         return VK_CONTROL;
    case glug_mod_super:        // return ??;
    case glug_mod_none:         // fall-through
    case glug_mod_unknown:      break;
    }

    return 0;
}

enum mods mod_from_code(int mod)
{
    switch (mod)
    {
    case VK_SHIFT:              return glug_mod_shift;
    case VK_MENU:               return glug_mod_alt;
    case VK_CONTROL:            return glug_mod_ctrl;
//    case ??:                    return mod_super:
    default:                    return glug_mod_none;
    }
}
