#include "../mod_util.h"
#include <glug_input/keyboard/mods.h>

#include <HIToolbox.framework/Headers/Events.h>

int code_from_mod(enum mods mod)
{
    switch (mod)
    {
    case glug_mod_shift:                return kCGEventFlagMaskShift;
    case glug_mod_alt:                  return kCGEventFlagMaskAlternate;
    case glug_mod_ctrl:                 return kCGEventFlagMaskControl;
    case glug_mod_super:                return kCGEventFlagMaskCommand;
    case glug_mod_none:                 // fall-through
    case glug_mod_unknown:              break;
    }

    return 0;
}

enum mods mod_from_code(int mod)
{
    switch (mod)
    {
    case kCGEventFlagMaskShift:         return glug_mod_shift;
    case kCGEventFlagMaskAlternate:     return glug_mod_alt;
    case kCGEventFlagMaskControl:       return glug_mod_ctrl;
    case kCGEventFlagMaskCommand:       return glug_mod_super;
    default:                            return glug_mod_none;
    }
}
