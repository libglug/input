#ifndef GLUG_JOYSTICK_HPP
#define GLUG_JOYSTICK_HPP

#include <glug_input/export.hpp>

#include <vector>

namespace glug
{

enum class joy_scan_ops;
enum class joyid;
enum class button;
enum class axis;
enum class hat;

namespace priv
{

class joystick_plat;
template <class platform>
class joystick_impl;

} // namespace glug::priv

class INPUT_LIB_API joystick
{
public:
  unsigned int buttons();
  unsigned int axes();
  unsigned int hats();

  void value(button b);
  void value(axis a);
  void value(hat h);
  joyid id();

  bool connected();

  // TODO:
  static size_t rescan(joy_scan_ops op = static_cast<joy_scan_ops>(0));

private:
  priv::joystick_impl<priv::joystick_plat> *impl;
};

} // namespace glug

#endif // GLUG_JOYSTICK_HPP
