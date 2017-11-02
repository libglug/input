#include <glug_input/keyboard/mods.hpp>

namespace glug
{

bool operator! (mods mod)
{
  return mod == mods::none;
}

mods operator~ (mods mod)
{
  return static_cast<mods>(~static_cast<int>(mod));
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

