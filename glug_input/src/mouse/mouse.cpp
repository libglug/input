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

point mouse::get_position()
{
  return mouse_plat::get_position();
}

} // namespace glug
