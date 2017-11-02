#ifndef GLUG_LOCKS_HPP
#define GLUG_LOCKS_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class locks
{
  none,
  caps    = 1 << 0,
  num     = 1 << 1,
  scroll  = 1 << 2,
  unknown = 1 << 3,
};

bool  INPUT_LIB_API operator! (locks lock);
locks INPUT_LIB_API operator~ (locks lock);

locks INPUT_LIB_API  operator|  (locks  lhs, locks rhs);
locks INPUT_LIB_API &operator|= (locks &lhs, locks rhs);

locks INPUT_LIB_API  operator&  (locks  lhs, locks rhs);
locks INPUT_LIB_API &operator&= (locks &lhs, locks rhs);

} // namespace glug

#endif // GLUG_LOCKS_HPP
