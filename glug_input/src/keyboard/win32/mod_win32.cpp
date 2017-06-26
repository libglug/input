#include "../mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

#include <Windows.h>

namespace glug
{

int mod_util::code_from_mod(mods mod)
{
  switch (mod)
  {
  case mods::shift:   return VK_SHIFT;
  case mods::alt:     return VK_MENU;
  case mods::ctrl:    return VK_CONTROL;
  case mods::super:   // return ??;
  case mods::none:    //fall-through
  case mods::unknown: break;
  }

  return 0;
}

mods mod_util::mod_from_code(int mod)
{
  switch (mod)
  {
  case VK_SHIFT:    return mods::shift;
  case VK_MENU:     return mods::alt;
  case VK_CONTROL:  return mods::ctrl;
//  case ??:          return mods::super:
  default:          return mods::none;
  }
}

} // namespace glug
