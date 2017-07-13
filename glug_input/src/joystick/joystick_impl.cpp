#include "joystick_impl.hpp"
#include <glug_input/joystick/joystick.hpp>

#if defined(GLUG_OS_WIN32)

#elif defined(GLUG_OS_LINUX)

#elif defined(GLUG_OS_MACOS)
#include "macos/joystick_macos.hpp"
#endif

namespace glug
{


template<class platform>
std::vector<platform> joystick_impl<platform>::joysticks;

template <class platform>
platform &joystick_impl<platform>::impl()
{
  return static_cast<platform &>(*this);
}

template <>
unsigned int joystick_impl<joystick_plat>::count()
{
  return joysticks.size();
}

size_t joystick_scanner::rescan()
{
  return joystick_plat::rescan();
}

} // namespace glug
