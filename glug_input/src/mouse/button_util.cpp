#include "button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

namespace glug
{

buttons &operator<<= (buttons &button, int n)
{
  *reinterpret_cast<int *>(&button) <<= n;
  return button;
}

} // namespace glug
