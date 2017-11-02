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

  static void set_key_state(char *state, keys key, bool active);
};

bool GLUG_LIB_LOCAL operator< (keys &lhs, keys &rhs);
keys GLUG_LIB_LOCAL operator++ (keys &key, int);

} // namespace glug

#endif // GLUG_KEY_UTIL_HPP
