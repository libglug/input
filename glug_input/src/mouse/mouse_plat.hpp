#ifndef GLUG_MOUSE_PLAT_HPP
#define GLUG_MOUSE_PLAT_HPP

#include <glug_input/export.hpp>
#include <glug_input/mouse/point.hpp>

namespace glug
{

enum class buttons;

class GLUG_LIB_LOCAL mouse_plat
{
public:
  static bool is_button_pressed(buttons buttons);
  static buttons button_state();

  static point get_position();

protected:
  static int code_from_button(buttons buttons);
  static buttons button_from_code(int buttons);
};

} // namespace glug

#endif // GLUG_MOUSE_PLAT_HPP
