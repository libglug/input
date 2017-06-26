#include "../mouse_plat.hpp"
#include "../button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <Windows.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  static unsigned short mask = 1 << 15;

  return (GetAsyncKeyState(button_util::code_from_button(button)) & mask) != 0;
}

buttons mouse_plat::button_state()
{
  buttons state = buttons::none;

  for (const auto button: button_util::button_list)
    if (is_button_pressed(button))
        state |= button;

  return state;
}

point mouse_plat::position()
{
  POINT mp;
  GetCursorPos(&mp);
  return {
          mp.x,
          mp.y,
         };
}

void mouse_plat::move(const point &delta)
{
  point curr = position();
  curr.x += delta.x;
  curr.y += delta.y;

  warp(curr);
}

void mouse_plat::warp(const point &new_pos)
{
  SetCursorPos(static_cast<LONG>(new_pos.x), static_cast<LONG>(new_pos.y));
}

} // namespace glug
