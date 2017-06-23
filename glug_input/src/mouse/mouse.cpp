#include <glug_input/mouse/mouse.hpp>
#include <glug_input/mouse/buttons.hpp>

#include "mouse_plat.hpp"

namespace glug
{

bool mouse::is_button_pressed(buttons button)
{
  return mouse_plat::is_button_pressed(button);
}

bool mouse::are_buttons_pressed(buttons buttons)
{
  return (button_state() & buttons) == buttons;
}

bool mouse::only_buttons_pressed(buttons buttons)
{
  return button_state() == buttons;
}

buttons mouse::button_state()
{
  return mouse_plat::button_state();
}

point mouse::position()
{
  return mouse_plat::position();
}

void mouse::move(const point &delta)
{
  return mouse_plat::move(delta);
}

void mouse::warp(const point &new_pos)
{
  return mouse_plat::warp(new_pos);
}


} // namespace glug
