#include "../mouse_plat.hpp"

#include <X11/extensions/XInput2.h>

namespace glug
{

static ::Display *xdisplay   = XOpenDisplay(NULL);
static ::Window xroot_window = XDefaultRootWindow(xdisplay);

bool mouse_plat::is_button_pressed(buttons button)
{
  static double temp;
  static ::Window temp_win;

  XIButtonState button_mask;
  XIModifierState modifier_mask;
  XIGroupState group;

  int count = 0;
  XIDeviceInfo *devs = XIQueryDevice(xdisplay, XIMasterPointer, &count);
  if (!count) return false;

  XIQueryPointer(xdisplay, devs[0].deviceid, xroot_window,
                &temp_win, &temp_win,
                &temp, &temp,
                &temp, &temp,
                &button_mask, &modifier_mask, &group);

  int mask = 0;
  for (int i = button_mask.mask_len; i--;)
    mask |= button_mask.mask[i] << (i * 8);


  return (code_from_button(button) & mask) != 0;
}

struct mouse_initializer {
  mouse_initializer() {
    static int xinput_op;
    static int event, error;

    // TODO: error reporting/handling
    XQueryExtension(xdisplay, "XInputExtension", &xinput_op, &event, &error);

    int major = 2, minor = 2;
    XIQueryVersion(xdisplay, &major, &minor);
  }
};

static mouse_initializer m;

} // namespace glug
