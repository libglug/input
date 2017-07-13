#include "joystick_macos.hpp"
#include <glug_input/joystick/joystick.hpp>

#include "scoped_cf.hpp"

#include <IOKit/IOTypes.h>
#include <IOKit/hid/IOHIDManager.h>
#include <IOKit/hid/IOHidKeys.h>

#include <iostream>

namespace glug
{

template<>
std::vector<joystick_plat> joystick_impl<joystick_plat>::joysticks;

joystick_plat::joystick_plat(IOHIDDeviceRef device):
  device(device)
{}

size_t joystick_plat::rescan()
{
  joystick_plat::enum_devices();
  return joysticks.size();
}

void joystick_plat::enum_devices()
{
  scoped_cf<IOHIDManagerRef> dev_man = IOHIDManagerCreate(kCFAllocatorDefault,
                                                          kIOHIDManagerOptionUsePersistentProperties);
  if (!dev_man) return;

  scoped_cf<CFMutableDictionaryRef> matchers = CFDictionaryCreateMutable(kCFAllocatorDefault,
                                                                         0,
                                                                         &kCFTypeDictionaryKeyCallBacks,
                                                                         &kCFTypeDictionaryValueCallBacks);
  if (!matchers) return;

  int usage_page_key = 1;
  scoped_cf<CFNumberRef> usage_page = CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage_page_key);

  int usage_key = kHIDPage_Game;
  scoped_cf<CFNumberRef> usage =CFNumberCreate(kCFAllocatorDefault, kCFNumberIntType, &usage_key);

  if (!usage_page || !usage) return;

  CFDictionaryAddValue(matchers, CFSTR(kIOHIDDeviceUsageKey), usage);
  CFDictionarySetValue(matchers, CFSTR(kIOHIDDeviceUsagePageKey), usage_page);

  IOHIDManagerSetDeviceMatching(dev_man, matchers);

  int res = IOHIDManagerOpen(dev_man, kIOHIDManagerOptionNone);
  if (res != kIOReturnSuccess) return;

  scoped_cf<CFSetRef> devs = IOHIDManagerCopyDevices(dev_man);
  if (!devs) return;

  CFSetApplyFunction(devs, reinterpret_cast<CFSetApplierFunction>(add_device), dev_man);
}

void joystick_plat::add_device(const IOHIDDeviceRef device, void *context)
{
  (void) context;

  joystick_plat j(device);
  // enum buttons
  // enum axis
  // enum ...
  j.enum_elements();

  joysticks.push_back(j);
}

void joystick_plat::enum_elements()
{
  scoped_cf<CFArrayRef> dev_eles = IOHIDDeviceCopyMatchingElements(device, nullptr, kIOHIDOptionsTypeNone);

  CFIndex ele_count = CFArrayGetCount(dev_eles);
  std::cerr << "elements read: " << ele_count << std::endl;

  IOHIDDeviceOpen(device, kIOHIDOptionsTypeNone);

//  CFArrayApplyFunction(dev_eles, {0, ele_count}, reinterpret_cast<CFArrayApplierFunction>(), device);
}

void joystick_plat::value(const IOHIDElementRef el)
{
  scoped_cf<IOHIDValueRef> value = IOHIDValueCreateWithIntegerValue(kCFAllocatorDefault, el, 0, 0);
  IOHIDDeviceGetValue(device, el, &value);

  IOHIDElementType type = IOHIDElementGetType(el);
  uint32_t usage = IOHIDElementGetUsage(el);

  std::cerr << usage << "\t" << type << ":\t" <<
               IOHIDValueGetIntegerValue(value) << std::endl;
}

} // namespace glug
