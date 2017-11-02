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

static bool get_key_state(int vk_key)
{
  static unsigned short keydown_mask = static_cast<unsigned short>(1 << 15);
  return (GetAsyncKeyState(vk_key) & keydown_mask) != 0;
}

bool keyboard_plat::is_key_pressed(keys key)
{
  return get_key_state(key_util::code_from_key(key));
}

void keyboard_plat::key_state(char *state)
{
  for (keys key = keys::none; key < keys::unknown; key++)
    key_util::set_key_state(state, key, is_key_pressed(key));
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
  for (mods mod = static_cast<mods>(static_cast<int>(mods::none) + 1); mod < mods::unknown; mod <<= 1)
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
  for (locks lock = static_cast<locks>(static_cast<int>(locks::none) + 1); lock < locks::unknown; lock <<= 1)
    if (is_lock_toggled(lock))
      lock_state |= lock;

  return lock_state;
}

} // namespace glug
