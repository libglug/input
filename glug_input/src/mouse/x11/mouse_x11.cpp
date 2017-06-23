#include "../mouse_plat.hpp"
#include "glug_input/mouse/buttons.hpp"

#include <array>
#include <X11/extensions/XInput2.h>

namespace glug
{

static ::Display *xdisplay   = XOpenDisplay(NULL);
static ::Window xroot_window = XDefaultRootWindow(xdisplay);

bool mouse_plat::is_button_pressed(buttons button)
{
  return !!(button & button_state());
}

buttons mouse_plat::button_state()
{
  static double temp;
  static ::Window temp_win;
  static XIModifierState modifier_mask;
  static XIGroupState group;

  XIButtonState button_mask;

  buttons state = buttons::none;
  int count = 0;
  XIDeviceInfo *devs = XIQueryDevice(xdisplay, XIMasterPointer, &count);

  if (count)
  {
    XIQueryPointer(xdisplay, devs[0].deviceid, xroot_window,
                  &temp_win, &temp_win,
                  &temp, &temp,
                  &temp, &temp,
                  &button_mask, &modifier_mask, &group);

    int xbuttons = 0;
    for (int i = button_mask.mask_len; i--;)
      xbuttons |= button_mask.mask[i] << (i * 8);

    static const std::array<buttons, 5> button_list = {{
                                                        buttons::left,
                                                        buttons::mid,
                                                        buttons::right,
                                                        buttons::ex1,
                                                        buttons::ex2
                                                      }};

    for (const auto button: button_list)
      if (code_from_button(button) & xbuttons)
          state |= button;
  }

  return state;
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
