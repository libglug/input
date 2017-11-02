#include "lock_util.hpp"
#include <glug_input/keyboard/locks.hpp>

namespace glug
{

bool operator< (locks &lhs, locks &rhs)
{
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}

locks &operator<<= (locks &lock, int n)
{
  *reinterpret_cast<int *>(&lock) <<= n;
  return lock;
}

} // namespace glug
