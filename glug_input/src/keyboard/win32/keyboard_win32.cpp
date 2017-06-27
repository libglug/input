#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"
#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <Windows.h>

namespace glug
{

bool get_key_state(int vk_key)
{
  static unsigned short keydown_mask = static_cast<unsigned short>(1 << 15);
  return (GetAsyncKeyState(vk_key) & keydown_mask) != 0;
}

bool keyboard_plat::is_key_pressed(keys key)
{
  return get_key_state(key_util::code_from_key(key));
}

std::vector<bool> &keyboard_plat::key_state()
{
  static std::vector<bool> state(key_util::key_list.size());
  for (const keys key: key_util::key_list)
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
  mods mod_state = mods::none;
  for (const mods mod: mod_util::mod_list)
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
  locks lock_state = locks::none;
  for (const locks lock: lock_util::lock_list)
    if (is_lock_toggled(lock))
      lock_state |= lock;

  return lock_state;
}

} // namespace glug
