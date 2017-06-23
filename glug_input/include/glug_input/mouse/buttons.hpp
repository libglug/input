#ifndef GLUG_BUTTONS_HPP
#define GLUG_BUTTONS_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class buttons
{
  none,
  left  = 1 << 0,
  mid   = 1 << 1,
  right = 1 << 2,
  ex1   = 1 << 3,
  ex2   = 1 << 4,
  unknown,
};

bool INPUT_LIB_API operator! (buttons b);
buttons INPUT_LIB_API operator~ (buttons b);


buttons INPUT_LIB_API  operator|  (buttons  lhs, buttons rhs);
buttons INPUT_LIB_API &operator|= (buttons &lhs, buttons rhs);

buttons INPUT_LIB_API  operator&  (buttons  lhs, buttons rhs);
buttons INPUT_LIB_API &operator&= (buttons &lhs, buttons rhs);

} // namespace glug

#endif // GLUG_BUTTONS_HPP
