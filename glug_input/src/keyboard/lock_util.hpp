#ifndef GLUG_LOCK_UTIL_HPP
#define GLUG_LOCK_UTIL_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class locks;

class GLUG_LIB_LOCAL lock_util
{
public:
  static int   code_from_lock(locks lock);
  static locks lock_from_code(int lock);
};

} // namespace glug

#endif // GLUG_LOCK_UTIL_HPP
