#ifndef GLUG_MODS_HPP
#define GLUG_MODS_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class mods
{
  none,
  shift   = 1 << 0,
  alt     = 1 << 1,
  ctrl    = 1 << 2,
  super   = 1 << 3,
  unknown = 1 << 4,
};

bool INPUT_LIB_API operator! (mods mod);
mods INPUT_LIB_API operator~ (mods mod);

mods INPUT_LIB_API  operator|  (mods  lhs, mods rhs);
mods INPUT_LIB_API &operator|= (mods &lhs, mods rhs);

mods INPUT_LIB_API  operator&  (mods  lhs, mods rhs);
mods INPUT_LIB_API &operator&= (mods &lhs, mods rhs);

} // namespace glug

#endif // GLUG_MODS_HPP
