#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

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
  static std::vector<bool> state(key_util::key_list.size());
  for (const keys key: key_util::key_list)
    state[static_cast<size_t>(key)] = is_key_pressed(key);

  return state;
}

bool keyboard_plat::is_mod_pressed(mods mod)
{
  return !!(mod_state() & mod);
}

mods keyboard_plat::mod_state()
{
  CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

  mods m = mods::none;
  for(const mods mod: mod_util::mod_list)
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
