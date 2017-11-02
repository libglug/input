#include "mod_util.hpp"
#include <glug_input/keyboard/mods.hpp>

namespace glug
{

bool operator< (mods &lhs, mods &rhs)
{
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}

mods &operator<<= (mods &mod, int n)
{
  *reinterpret_cast<int *>(&mod) <<= n;
  return mod;
}

} // namespace glug
