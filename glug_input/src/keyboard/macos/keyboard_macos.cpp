#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"
#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/mods.hpp>
#include <glug_input/keyboard/locks.hpp>

#include <array>
#include <HIToolbox.framework/Headers/Events.h>

namespace glug
{

static bool is_mod_key_pressed(keys key)
{
  CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
  return modifiers & key_util::code_from_key(key);
}

bool keyboard_plat::is_key_pressed(keys key)
{
  if (keys::shift_l <= key && key <= keys::super_r)
    return is_mod_key_pressed(key);

  return CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, key_util::code_from_key(key));
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

  for (const keys key: key_list)
    state[static_cast<size_t>(key)] = is_key_pressed(key);

  return state;
}

bool keyboard_plat::is_mod_pressed(mods mod)
{
  return !!(mod_state() & mod);
}

mods keyboard_plat::mod_state()
{
  static const std::array<mods, 4> mods_list = {{
                                                 mods::shift,
                                                 mods::alt,
                                                 mods::ctrl,
                                                 mods::super,
                                               }};
  CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

  mods m = mods::none;
  for(const mods mod: mods_list)
    if (modifiers & mod_util::code_from_mod(mod))
      m |= mod;

  return m;
}

bool keyboard_plat::is_lock_toggled(locks lock)
{
  return !!(lock_state() & lock);
}

locks keyboard_plat::lock_state()
{
  CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
  return modifiers & lock_util::code_from_lock(locks::caps) ? locks::caps : locks::none;
}

} // namespace glug
