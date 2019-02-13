#include "../keyboard_plat.h"
#include "../key_util.h"
#include "../mod_util.h"
#include "../lock_util.h"

#include <glug/input/keyboard/keys.h>
#include <glug/input/keyboard/locks.h>
#include <glug/input/keyboard/mods.h>

#include <HIToolbox.framework/Headers/Events.h>

static int is_mod_key_pressed(enum virtual_keys key)
{
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    return (int)(modifiers & (unsigned long long)code_from_key(key));
}

int is_key_pressed(enum virtual_keys key)
{
    if (glug_vk_shift_l <= key && key <= glug_vk_super_r)
        return is_mod_key_pressed(key);

    return CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, (CGKeyCode)code_from_key(key));
}

void key_state(char *state)
{
    enum virtual_keys key;
    for (key = glug_vk_none; key < glug_vk_unknown; ++key)
        set_key_state(state, key, is_key_pressed(key));
}

int is_mod_pressed(enum key_mods mod)
{
    return !!(mod_state() & mod);
}

enum key_mods mod_state()
{
    enum key_mods mod, mod_state = glug_km_none;
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);

    for (mod = glug_km_none + 1; mod < glug_km_unknown; mod <<= 1)
        if (modifiers & (unsigned long long)code_from_mod(mod))
            mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum key_locks lock)
{
    return !!(lock_state() & lock);
}

enum key_locks lock_state()
{
    CGEventFlags modifiers = CGEventSourceFlagsState(kCGEventSourceStateCombinedSessionState);
    return modifiers & (unsigned long long)code_from_lock(glug_kl_caps) ? glug_kl_caps : glug_kl_none;
}
