#include "key_util.hpp"
#include <glug_input/keyboard/keys.hpp>

namespace glug
{

bool operator< (keys &lhs, keys &rhs)
{
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}

keys operator++ (keys &key, int)
{
  return static_cast<keys>(*reinterpret_cast<int *>(&key) += 1);
}

void key_util::set_key_state(char *state, keys key, bool active)
{
  int index = static_cast<int>(key) / 8;
  int mask = 1 << static_cast<int>(key) % 8;
  if (active)
    state[index] |= mask;
  else
    state[index] &= ~mask;
}

} // namespace glug
