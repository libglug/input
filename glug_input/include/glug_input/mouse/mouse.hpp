#ifndef GLUG_MOUSE_HPP
#define GLUG_MOUSE_HPP

#include <glug_input/export.hpp>
#include <glug_input/mouse/point.hpp>

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

  static point position();

  static void move(const point &delta);
  static void warp(const point &new_pos);
};

} // namespace glug

#endif // GLUG_MOUSE_HPP
