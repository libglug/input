#include "../mod_util.h"
#include <glug/input/keyboard/mods.h>

#include <Windows.h>

int code_from_mod(enum key_mods mod)
{
    switch (mod)
    {
    case glug_km_shift:         return VK_SHIFT;
    case glug_km_alt:           return VK_MENU;
    case glug_km_ctrl:          return VK_CONTROL;
    case glug_km_super:         // return ??;
    case glug_km_none:          // fall-through
    case glug_km_unknown:       break;
    }

    return 0;
}

enum key_mods mod_from_code(int mod)
{
    switch (mod)
    {
    case VK_SHIFT:              return glug_km_shift;
    case VK_MENU:               return glug_km_alt;
    case VK_CONTROL:            return glug_km_ctrl;
//    case ??:                    return mod_super:
    default:                    return glug_km_none;
    }
}
