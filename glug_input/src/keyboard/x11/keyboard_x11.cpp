#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <X11/Xutil.h>

#define KEYBOARDMAPSIZE 32
static char key_map[KEYBOARDMAPSIZE];

static ::Display *xdisplay = XOpenDisplay(NULL);
static ::Window xroot_window = XDefaultRootWindow(xdisplay);

namespace glug
{

bool check_key(keys key)
{
  unsigned int key_code = XKeysymToKeycode(xdisplay, key_util::code_from_key(key));
  return key_map[key_code / 8] & (1 << key_code % 8);
}

bool keyboard_plat::is_key_pressed(keys key)
{
  XQueryKeymap(xdisplay, key_map);
  return check_key(key);
}

std::vector<bool> &keyboard_plat::key_state()
{
  static std::vector<bool> state(key_util::key_list.size());
  XQueryKeymap(xdisplay, key_map);
  for (const keys key: key_util::key_list)
    state[static_cast<size_t>(key)] = check_key(key);

  return state;
}

bool keyboard_plat::is_mod_pressed(mods mod)
{
  return !!(mod_state() & mod);
}

mods keyboard_plat::mod_state()
{
  static ::Window temp_win;
  static int temp;
  unsigned int modifiers;
  XQueryPointer(xdisplay, xroot_window,
                &temp_win, &temp_win,
                &temp, &temp, &temp, &temp,
                &modifiers);

  mods mod_state = mods::none;
  for (const mods mod: mod_util::mod_list)
    if (modifiers & mod_util::code_from_mod(mod))
      mod_state |= mod;

  return mod_state;
}

bool keyboard_plat::is_lock_toggled(locks lock)
{
  XKeyboardState lock_state;
  XGetKeyboardControl(xdisplay, &lock_state);

  return lock_state.led_mask & static_cast<long unsigned int>(lock);
}

locks keyboard_plat::lock_state()
{
  locks lock_state = locks::none;
  for (const locks lock: lock_util::lock_list)
    if (is_lock_toggled(lock))
      lock_state |= lock;

  return lock_state;
}

} // namespace glug
