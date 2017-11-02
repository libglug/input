#include <glug_input/keyboard/locks.hpp>

namespace glug
{

bool operator! (locks lock)
{
  return lock == locks::none;
}

locks operator~ (locks lock)
{
  return static_cast<locks>(~static_cast<int>(lock));
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
