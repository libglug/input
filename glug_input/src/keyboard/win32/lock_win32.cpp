#include "../lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

#include <Windows.h>

namespace glug
{

int lock_util::code_from_lock(locks lock)
{
  switch (lock)
  {
  case locks::caps:    return VK_CAPITAL;
  case locks::num:     return VK_NUMLOCK;
  case locks::scroll:  return VK_SCROLL;
  case locks::none:    //fall-through
  case locks::unknown: break;
  }

  return 0;
}

locks lock_util::lock_from_code(int lock)
{
  switch (lock)
  {
  case VK_CAPITAL: return locks::caps;
  case VK_NUMLOCK: return locks::num;
  case VK_SCROLL:  return locks::scroll;
  default:         return locks::none;
  }
}

} // namespace glug
