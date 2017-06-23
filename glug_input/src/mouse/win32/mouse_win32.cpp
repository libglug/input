#include "../mouse_plat.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <array>
#include <Windows.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  static unsigned short mask = 1 << 15;

  return (GetAsyncKeyState(code_from_button(button)) & mask) != 0;
}

buttons mouse_plat::button_state()
{
  static const std::array<buttons, 5> button_list = {{
                                                      buttons::left,
                                                      buttons::mid,
                                                      buttons::right,
                                                      buttons::ex1,
                                                      buttons::ex2
                                                    }};
  buttons state = buttons::none;

  for (const auto button: button_list)
    if (is_button_pressed(button))
        state |= button;

  return state;
}

} // namespace glug
