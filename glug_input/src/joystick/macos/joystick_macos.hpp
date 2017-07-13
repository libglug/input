#ifndef GLUG_JOYSTICK_PLAT_HPP
#define GLUG_JOYSTICK_PLAT_HPP

#include <glug_input/export.hpp>
#include "../joystick_impl.hpp"
#include "scoped_cf.hpp"

#include <IOKit/hid/IOHIDManager.h>

namespace glug
{

class GLUG_LIB_LOCAL joystick_plat: protected joystick_impl<joystick_plat>
{
public:
  static size_t rescan();

  void value(const IOHIDElementRef el);

protected:
  joystick_plat(IOHIDDeviceRef);

  static void enum_devices();
  static void add_device(const IOHIDDeviceRef device, void *);
  void enum_elements();

  IOHIDDeviceRef device;
  std::unordered_map<uint32_t, scoped_cf<IOHIDElementRef>> buttons;
  std::unordered_map<uint32_t, scoped_cf<IOHIDElementRef>> axes;
  std::unordered_map<uint32_t, scoped_cf<IOHIDElementRef>> hats;
};

} // namespace glug

#endif // GLUG_JOYSTICK_PLAT_HPP
