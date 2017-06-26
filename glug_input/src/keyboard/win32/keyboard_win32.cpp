#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"
#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/mods.hpp>
#include <glug_input/keyboard/locks.hpp>

#include <array>
#include <Windows.h>

namespace glug
{

bool get_key_state(int vk_key)
{
  static SHORT keydown_mask = static_cast<SHORT>(1 << 15);
  return (GetAsyncKeyState(vk_key) & keydown_mask) != 0;
}

bool keyboard_plat::is_key_pressed(keys key)
{
  return get_key_state(key_util::code_from_key(key));
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
  if (mod == mods::super)
    return is_key_pressed(keys::super_l) || is_key_pressed(keys::super_r);

  return get_key_state(mod_util::code_from_mod(mod));
}

mods keyboard_plat::mod_state()
{
  static const std::array<mods, 4> mod_list = {{
                                                mods::shift,
                                                mods::alt,
                                                mods::ctrl,
                                                mods::super,
                                              }};
  mods mod_state = mods::none;
  for (const mods mod: mod_list)
    if (is_mod_pressed(mod))
      mod_state |= mod;

  return mod_state;
}

bool keyboard_plat::is_lock_toggled(locks lock)
{
  static SHORT lock_mask = 1;
  return (GetKeyState(lock_util::code_from_lock(lock)) & lock_mask) != 0;
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
