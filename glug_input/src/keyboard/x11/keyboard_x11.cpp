#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <X11/Xutil.h>

#define KEYBOARDMAPSIZE 32

static ::Display *xdisplay = XOpenDisplay(NULL);
static ::Window xroot_window = XDefaultRootWindow(xdisplay);

namespace glug
{

static bool check_key(char *xkey_map, keys key)
{
  unsigned int key_code = XKeysymToKeycode(xdisplay, key_util::code_from_key(key));
  return xkey_map[key_code / 8] & (1 << key_code % 8);
}

bool keyboard_plat::is_key_pressed(keys key)
{
  char xkey_map[KEYBOARDMAPSIZE];
  XQueryKeymap(xdisplay, xkey_map);
  return check_key(xkey_map, key);
}

void keyboard_plat::key_state(char *state)
{
  char xkey_map[KEYBOARDMAPSIZE];
  XQueryKeymap(xdisplay, xkey_map);
  for (keys key = keys::none; key < keys::unknown; key++)
    key_util::set_key_state(state, key, check_key(xkey_map, key));
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
  for (mods mod = static_cast<mods>(static_cast<int>(mods::none) + 1); mod < mods::unknown; mod <<= 1)
    if (modifiers & mod_util::code_from_mod(mod))
      mod_state |= mod;

  return mod_state;
}

bool keyboard_plat::is_lock_toggled(locks lock)
{
  XKeyboardState lock_state;
  XGetKeyboardControl(xdisplay, &lock_state);

  return lock_state.led_mask & static_cast<unsigned long>(lock);
}

locks keyboard_plat::lock_state()
{
  locks lock_state = locks::none;
  for (locks lock = static_cast<locks>(static_cast<int>(locks::none) + 1); lock < locks::unknown; lock <<= 1)
    if (is_lock_toggled(lock))
      lock_state |= lock;

  return lock_state;
}

} // namespace glug
