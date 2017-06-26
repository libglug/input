#ifndef GLUG_KEY_UTIL_HPP
#define GLUG_KEY_UTIL_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class keys;

class GLUG_LIB_LOCAL key_util
{
public:
  static int  code_from_key(keys key);
  static keys key_from_code(int key);
};

} // namespace glug

#endif // GLUG_KEY_UTIL_HPP
