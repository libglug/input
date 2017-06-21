#ifndef GLUG_MOUSE_HPP
#define GLUG_MOUSE_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class buttons;

class INPUT_LIB_API mouse
{
public:
  static bool is_button_pressed(buttons buttons);
  static bool are_buttons_pressed(buttons buttons);
  static bool only_buttons_pressed(buttons buttons);

  static buttons button_state();
};

} // namespace glug

#endif // GLUG_MOUSE_HPP