#ifndef GLUG_KEY_UTIL_HPP
#define GLUG_KEY_UTIL_HPP

#include <glug_input/export.hpp>

#include <array>

namespace glug
{

enum class keys;

class GLUG_LIB_LOCAL key_util
{
public:
  static int  code_from_key(keys key);
  static keys key_from_code(int key);

  static const std::array<keys, 101> key_list;
};

} // namespace glug

#endif // GLUG_KEY_UTIL_HPP
