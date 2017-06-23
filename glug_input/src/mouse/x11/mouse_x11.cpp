#include "../mouse_plat.hpp"
#include "../button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <array>
#include <X11/extensions/XInput2.h>

namespace glug
{

static ::Display *xdisplay   = XOpenDisplay(NULL);
static ::Window xroot_window = XDefaultRootWindow(xdisplay);

static bool xmouse_state(buttons * = nullptr, point * = nullptr);
static buttons xmouse_buttons(XIButtonState *button_mask);

bool mouse_plat::is_button_pressed(buttons button)
{
  return !!(button & button_state());
}

buttons mouse_plat::button_state()
{
  buttons state = buttons::none;
  xmouse_state(&state);
  return state;
}

point mouse_plat::position()
{
  point mouse_pt = {0, 0};
  xmouse_state(nullptr, &mouse_pt);
  return mouse_pt;
}


void mouse_plat::move(const point &delta)
{
  XWarpPointer(xdisplay, None, None, 0, 0, 0, 0, delta.x, delta.y);
  XFlush(xdisplay);
}

void mouse_plat::warp(const point &new_pos)
{
  XWarpPointer(xdisplay, None, xroot_window, 0, 0, 0, 0, new_pos.x, new_pos.y);
  XFlush(xdisplay);
}

static bool xmouse_state(buttons *button_state, point *pos)
{
  static double temp;
  static ::Window temp_win;
  static XIModifierState temp_modifiers;
  static XIGroupState temp_group;

  int count = 0;
  XIDeviceInfo *devs = XIQueryDevice(xdisplay, XIMasterPointer, &count);

  if (count)
  {
    double x, y;
    XIButtonState button_mask;
    XIQueryPointer(xdisplay, devs[0].deviceid, xroot_window,
                   &temp_win, &temp_win,
                   &x, &y,
                   &temp, &temp,
                   &button_mask,
                   &temp_modifiers,
                   &temp_group);

    if (pos)
    {
      pos->x = static_cast<long long>(x);
      pos->y = static_cast<long long>(y);
    }

    if (button_state)
      *button_state = xmouse_buttons(&button_mask);
  }

  return count == 0;
}

buttons xmouse_buttons(XIButtonState *button_mask)
{
  int xbuttons = 0;
  for (int i = button_mask->mask_len; i--;)
    xbuttons |= button_mask->mask[i] << (i * 8);

  static const std::array<buttons, 5> button_list = {{
                                                      buttons::left,
                                                      buttons::mid,
                                                      buttons::right,
                                                      buttons::ex1,
                                                      buttons::ex2,
                                                    }};

  buttons state = buttons::none;
  for (const buttons button: button_list)
    if (button_util::code_from_button(button) & xbuttons)
        state |= button;

  return state;
}

struct mouse_initializer
{
  mouse_initializer()
  {
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
