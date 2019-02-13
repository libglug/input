#include "../mod_util.h"
#include <glug_input/keyboard/mods.h>

#include <HIToolbox.framework/Headers/Events.h>

int code_from_mod(enum key_mods mod)
{
    switch (mod)
    {
    case glug_km_shift:                 return kCGEventFlagMaskShift;
    case glug_km_alt:                   return kCGEventFlagMaskAlternate;
    case glug_km_ctrl:                  return kCGEventFlagMaskControl;
    case glug_km_super:                 return kCGEventFlagMaskCommand;
    case glug_km_none:                  // fall-through
    case glug_km_unknown:               break;
    }

    return 0;
}

enum key_mods mod_from_code(int mod)
{
    switch (mod)
    {
    case kCGEventFlagMaskShift:         return glug_km_shift;
    case kCGEventFlagMaskAlternate:     return glug_km_alt;
    case kCGEventFlagMaskControl:       return glug_km_ctrl;
    case kCGEventFlagMaskCommand:       return glug_km_super;
    default:                            return glug_km_none;
    }
}
