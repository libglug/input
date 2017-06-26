#include <glug_input/keyboard/keyboard.hpp>
#include <glug_input/keyboard/mods.hpp>
#include <glug_input/keyboard/locks.hpp>

#include "keyboard_plat.hpp"

namespace glug
{

bool keyboard::is_key_pressed(keys key)
{
  return keyboard_plat::is_key_pressed(key);
}

std::vector<bool> keyboard::key_state()
{
  return keyboard_plat::key_state();
}

bool keyboard::is_mod_active(mods mod)
{
  return keyboard_plat::is_mod_pressed(mod);
}

bool keyboard::are_mods_active(mods mod)
{
  return (mod_state() & mod) == mod;
}

mods keyboard::mod_state()
{
  return keyboard_plat::mod_state();
}

bool keyboard::is_lock_toggled(locks lock)
{
  return keyboard_plat::is_lock_toggled(lock);
}

bool keyboard::are_locks_toggled(locks locks)
{
  return (lock_state() & locks) == locks;
}

locks keyboard::lock_state()
{
  return keyboard_plat::lock_state();
}

} // namespace glug
