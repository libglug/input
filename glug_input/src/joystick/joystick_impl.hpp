#ifndef GLUG_JOYSTICK_IMPL_HPP
#define GLUG_JOYSTICK_IMPL_HPP

#include <vector>
#include <unordered_map>

namespace glug
{

class joystick;

class joystick_scanner
{
public:
  static size_t rescan();
};

template <class platform>
class joystick_impl
{
public:
  static unsigned int count();
  platform &impl();

protected:
  static std::vector<platform> joysticks;

  std::unordered_map<int, int> buttons;
  std::unordered_map<int, int> axes;
  std::unordered_map<int, int> hats;
};

} // namespace glug

#endif // GLUG_JOYSTICK_IMPL_HPP
