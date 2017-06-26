#include "../mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <X11/Xutil.h>

namespace glug
{

int mod_util::code_from_mod(mods mod)
{
  switch (mod)
  {
  case mods::shift:   return ShiftMask;
  case mods::alt:     return Mod1Mask;
  case mods::ctrl:    return ControlMask;
  case mods::super:   return Mod4Mask;
  case mods::none:    // fall-through
  case mods::unknown: break;
  }

  return 0;
}

mods mod_util::mod_from_code(int mod)
{
  switch (mod)
  {
  case ShiftMask:     return mods::shift;
  case Mod1Mask:      return mods::alt;
  case ControlMask:   return mods::ctrl;
  case Mod4Mask:      return mods::super;
  default:            return mods::none;
  }
}

} // namespace glug
