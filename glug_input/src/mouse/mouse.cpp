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
  buttons state = buttons::none;

  for (buttons b = buttons::left; b < buttons::unknown; b <<= 1)
      if (is_button_pressed(b))
          state |= b;

  return state;
}

} // namespace glug
