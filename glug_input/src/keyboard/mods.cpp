#include <glug_input/keyboard/mods.hpp>

namespace glug
{

bool operator! (mods b)
{
  return b == mods::none;
}

mods operator~ (mods b)
{
  return static_cast<mods>(~static_cast<int>(b));
}

mods operator| (mods lhs, mods rhs)
{
  return lhs |= rhs;
}

mods &operator|= (mods &lhs, mods rhs)
{
  return lhs = static_cast<mods>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

mods operator& (mods lhs, mods rhs)
{
  return lhs &= rhs;
}

mods &operator&= (mods &lhs, mods rhs)
{
  return lhs = static_cast<mods>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

} // namespace glug

