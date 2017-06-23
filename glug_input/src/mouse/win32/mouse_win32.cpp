#include "../mouse_plat.hpp"

#include <Windows.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  static unsigned short mask = 1 << 15;

  return (GetAsyncKeyState(code_from_button(button)) & mask) != 0;
}

} // namespace glug
