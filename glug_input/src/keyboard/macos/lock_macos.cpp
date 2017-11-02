#include "../lock_util.hpp"
#include "lock_defs.hpp"
#include <glug_input/keyboard/locks.hpp>

namespace glug
{

int lock_util::code_from_lock(locks lock)
{
  switch (lock)
  {
  case locks::caps:       return gMask_Alpha;
  case locks::num:        return gMask_Num;
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
  case gMask_Alpha:   return locks::caps;
  case gMask_Num:     return locks::num;
//  case ??:            return locks::scroll;
  default:            return locks::none;
  }
}

} // namespace glug
