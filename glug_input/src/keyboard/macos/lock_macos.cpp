#include "../lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

#include <HIToolbox.framework/Headers/Events.h>

namespace glug
{

int lock_util::code_from_lock(locks lock)
{
  switch (lock)
  {
  case locks::caps:       return NX_ALPHASHIFTMASK;
  case locks::num:        // return ??;
  case locks::scroll:     // return ??;
  case locks::none:       // fall-through
  case locks::unknown:    break;
  }

  return 0;
}

locks lock_util::lock_from_code(int lock)
{
  switch(lock)
  {
  case NX_ALPHASHIFTMASK:   return locks::caps;
//  case ??:                   return locks::num;
//  case ??:                   return locks::scroll;
  default:                  return locks::none;
  }
}

} // namespace glug
