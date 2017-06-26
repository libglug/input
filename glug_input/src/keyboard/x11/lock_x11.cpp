#include "../lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

#include <X11/Xutil.h>

namespace glug
{

int lock_util::code_from_lock(locks lock)
{
  switch (lock)
  {
  case locks::caps:    return XK_Caps_Lock;
  case locks::num:     return XK_Num_Lock;
  case locks::scroll:  return XK_Scroll_Lock;
  case locks::none:    //fall-through
  case locks::unknown: break;
  }

  return 0;
}

locks lock_util::lock_from_code(int lock)
{
  switch (lock)
  {
  case XK_Caps_Lock:      return locks::caps;
  case XK_Num_Lock:       return locks::num;
  case XK_Scroll_Lock:    return locks::scroll;
  default:                return locks::none;
  }
}

} // namespace glug
