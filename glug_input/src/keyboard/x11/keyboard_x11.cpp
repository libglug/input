#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"
#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/mods.hpp>
#include <glug_input/keyboard/locks.hpp>

#include <array>
#include <X11/extensions/XInput2.h>

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
  static const size_t key_count = static_cast<size_t>(keys::unknown);
  static std::vector<bool> state(key_count);
  static std::array<keys, key_count> key_list = {{
                                                  keys::none,
                                                  keys::shift_l,
                                                  keys::shift_r,
                                                  keys::alt_l,
                                                  keys::alt_r,
                                                  keys::ctrl_l,
                                                  keys::ctrl_r,
                                                  keys::super_l,
                                                  keys::super_r,
                                                  keys::escape,
                                                  keys::insert,
                                                  keys::home,
                                                  keys::end,
                                                  keys::pageup,
                                                  keys::pagedown,
                                                  keys::print,
                                                  keys::pause,
                                                  keys::backspace,
                                                  keys::del,
                                                  keys::tab,
                                                  keys::enter,
                                                  keys::menu,
                                                  keys::space,
                                                  keys::up,
                                                  keys::down,
                                                  keys::left,
                                                  keys::right,
                                                  keys::f1,
                                                  keys::f2,
                                                  keys::f3,
                                                  keys::f4,
                                                  keys::f5,
                                                  keys::f6,
                                                  keys::f7,
                                                  keys::f8,
                                                  keys::f9,
                                                  keys::f10,
                                                  keys::f11,
                                                  keys::f12,
                                                  keys::tilde,
                                                  keys::one,
                                                  keys::two,
                                                  keys::three,
                                                  keys::four,
                                                  keys::five,
                                                  keys::six,
                                                  keys::seven,
                                                  keys::eight,
                                                  keys::nine,
                                                  keys::zero,
                                                  keys::minus,
                                                  keys::equal,
                                                  keys::a,
                                                  keys::b,
                                                  keys::c,
                                                  keys::d,
                                                  keys::e,
                                                  keys::f,
                                                  keys::g,
                                                  keys::h,
                                                  keys::i,
                                                  keys::j,
                                                  keys::k,
                                                  keys::l,
                                                  keys::m,
                                                  keys::n,
                                                  keys::o,
                                                  keys::p,
                                                  keys::q,
                                                  keys::r,
                                                  keys::s,
                                                  keys::t,
                                                  keys::u,
                                                  keys::v,
                                                  keys::w,
                                                  keys::x,
                                                  keys::y,
                                                  keys::z,
                                                  keys::bracket_l,
                                                  keys::bracket_r,
                                                  keys::backslash,
                                                  keys::semicolon,
                                                  keys::quote,
                                                  keys::comma,
                                                  keys::period,
                                                  keys::slash,
                                                  keys::num_zero,
                                                  keys::num_one,
                                                  keys::num_two,
                                                  keys::num_three,
                                                  keys::num_four,
                                                  keys::num_five,
                                                  keys::num_six,
                                                  keys::num_seven,
                                                  keys::num_eight,
                                                  keys::num_nine,
                                                  keys::num_add,
                                                  keys::num_minus,
                                                  keys::num_mult,
                                                  keys::num_div,
                                                  keys::num_dec,
                                                }};
  XQueryKeymap(xdisplay, key_map);
  for (const keys key: key_list)
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

  static const std::array<mods, 4> mods_list = {{
                                                 mods::shift,
                                                 mods::alt,
                                                 mods::ctrl,
                                                 mods::super,
                                               }};
  mods mod_state = mods::none;
  for (const mods mod: mods_list)
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
  static const std::array<locks, 3> lock_list = {{
                                                  locks::caps,
                                                  locks::num,
                                                  locks::scroll,
                                                }};
  locks lock_state = locks::none;
  for (const locks lock: lock_list)
    if (is_lock_toggled(lock))
      lock_state |= lock;

  return lock_state;
}

} // namespace glug
