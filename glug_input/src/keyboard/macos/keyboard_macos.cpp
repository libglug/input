#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <HIToolbox.framework/Headers/Events.h>

static int is_mod_key_pressed(enum keys key)
{
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    return (int)(modifiers & (unsigned long long)code_from_key(key));
}

int is_key_pressed(enum keys key)
{
    if (glug_key_shift_l <= key && key <= glug_key_super_r)
        return is_mod_key_pressed(key);

    return CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, (CGKeyCode)code_from_key(key));
}

void key_state(char *state)
{
    enum keys key;
    for (key = glug_key_none; key < glug_key_unknown; ++key)
        set_key_state(state, key, is_key_pressed(key));
}

int is_mod_pressed(enum mods mod)
{
    return !!(mod_state() & mod);
}

enum mods mod_state()
{
    enum mods mod, mod_state = glug_mod_none;
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

    for (mod = glug_mod_none + 1; mod < glug_mod_unknown; mod <<= 1)
        if (modifiers & (unsigned long long)code_from_mod(mod))
            mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum locks lock)
{
    return !!(lock_state() & lock);
}

enum locks lock_state()
{
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    return modifiers & (unsigned long long)code_from_lock(glug_lock_caps) ? glug_lock_caps : glug_lock_none;
}
