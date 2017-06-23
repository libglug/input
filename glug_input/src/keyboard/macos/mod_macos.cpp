#include "../mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <HIToolbox.framework/Headers/Events.h>

namespace glug
{

int mod_util::code_from_mod(mods mod)
{
  switch (mod)
  {
  case mods::shift:     return kCGEventFlagMaskShift;
  case mods::alt:       return kCGEventFlagMaskAlternate;
  case mods::ctrl:      return kCGEventFlagMaskControl;
  case mods::super:     return kCGEventFlagMaskCommand;
  case mods::none:      // fall-through
  case mods::unknown:   break;
  }

  return 0;
}

mods mod_util::mod_from_code(int mod)
{
  switch (mod)
  {
  case kCGEventFlagMaskShift:     return mods::shift;
  case kCGEventFlagMaskAlternate: return mods::alt;
  case kCGEventFlagMaskControl:   return mods::ctrl;
  case kCGEventFlagMaskCommand:   return mods::super;
  default:                        return mods::none;
  }
}

} // namespace glug
