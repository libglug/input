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

void keyboard_plat::key_state(char *state)
{
  for (keys key = keys::none; key < keys::unknown; key++)
    key_util::set_key_state(state, key, is_key_pressed(key));
}

bool keyboard_plat::is_mod_pressed(mods mod)
{
  return !!(mod_state() & mod);
}

mods keyboard_plat::mod_state()
{
  CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

  mods mod_state = mods::none;
  for (mods mod = static_cast<mods>(static_cast<int>(mods::none) + 1); mod < mods::unknown; mod <<= 1)
    if (modifiers & mod_util::code_from_mod(mod))
      mod_state |= mod;

  return mod_state;
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
