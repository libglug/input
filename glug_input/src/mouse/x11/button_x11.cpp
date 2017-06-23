#include "../button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <X11/extensions/XInput2.h>

// TODO: use built in button definitions(?)
#ifndef Button8
#define Button8 8
#endif

#ifndef Button9
#define Button9	9
#endif

namespace glug
{

int button_util::code_from_button(buttons button)
{
  switch(button)
  {
  case buttons::left:     return 1 << Button1;
  case buttons::mid:      return 1 << Button2;
  case buttons::right:    return 1 << Button3;
  case buttons::ex1:      return 1 << Button8;
  case buttons::ex2:      return 1 << Button9;
  case buttons::none:     // fall-through
  case buttons::unknown:  break;
  }

  return 0;
}

buttons button_util::button_from_code(int button)
{
  switch(button)
  {
  case 1 << Button1:    return buttons::left;
  case 1 << Button2:    return buttons::mid;
  case 1 << Button3:    return buttons::right;
  case 1 << Button8:    return buttons::ex1;
  case 1 << Button9:    return buttons::ex2;
  default:              return buttons::none;
  }
}

} // namespace glug
