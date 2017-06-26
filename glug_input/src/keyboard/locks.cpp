#include <glug_input/keyboard/locks.hpp>

namespace glug
{

bool operator! (locks b)
{
  return b == locks::none;
}

locks operator~ (locks b)
{
  return static_cast<locks>(~static_cast<int>(b));
}

locks operator| (locks lhs, locks rhs)
{
  return lhs |= rhs;
}

locks &operator|= (locks &lhs, locks rhs)
{
  return lhs = static_cast<locks>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

locks operator& (locks lhs, locks rhs)
{
  return lhs &= rhs;
}

locks &operator&= (locks &lhs, locks rhs)
{
  return lhs = static_cast<locks>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

} // namespace glug
