#ifndef GLUG_MOD_UTIL_HPP
#define GLUG_MOD_UTIL_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class mods;

class GLUG_LIB_LOCAL mod_util
{
public:
  static int  code_from_mod(mods mod);
  static mods mod_from_code(int mod);
};

} // namespace glug

#endif // GLUG_MOD_UTIL_HPP
