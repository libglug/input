#include <glug_input/mouse/buttons.hpp>

namespace glug
{

bool operator! (buttons b)
{
  return b != buttons::none;
}

buttons operator~ (buttons b)
{
  return static_cast<buttons>(~static_cast<int>(b));
}

buttons operator| (buttons lhs, buttons rhs)
{
  return lhs |= rhs;
}

buttons &operator|= (buttons &lhs, buttons rhs)
{
  return lhs = static_cast<buttons>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

buttons operator& (buttons lhs, buttons rhs)
{
  return lhs &= rhs;
}

buttons &operator&= (buttons &lhs, buttons rhs)
{
  return lhs = static_cast<buttons>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

buttons operator<< (buttons buttons, int n)
{
  return buttons <<= n;
}

buttons &operator<<= (buttons &buttons, int n)
{
  return buttons = static_cast<glug::buttons>(static_cast<int>(buttons) << n);
}

buttons operator>> (buttons buttons, int n)
{
  return buttons >>= n;
}

buttons &operator>>= (buttons &buttons, int n)
{
  return buttons = static_cast<glug::buttons>(static_cast<int>(buttons) >> n);
}

} // namespace glug
