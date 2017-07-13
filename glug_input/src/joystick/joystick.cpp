#include <glug_input/joystick/joystick.hpp>
#include "joystick_impl.hpp"

#include <glug_input/joystick/scan_ops.hpp>

namespace glug
{

unsigned int joystick::buttons()
{

}

unsigned int joystick::axes()
{

}

unsigned int joystick::hats()
{

}

void joystick::value(button b)
{

}

void joystick::value(axis a)
{

}

void joystick::value(hat h)
{

}

joyid joystick::id()
{

}

size_t joystick::rescan(joy_scan_ops op)
{
  return joystick_scanner::rescan();
}

} // namespace glug
