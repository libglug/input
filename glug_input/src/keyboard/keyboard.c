#include <glug/input/keyboard/keyboard.h>
#include <glug/input/keyboard/keys.h>
#include <glug/input/keyboard/mods.h>
#include <glug/input/keyboard/locks.h>

#include "keyboard_plat.h"

int glug_key_is_pressed(enum virtual_keys key)
{
    return is_key_pressed(key);
}

struct keystate glug_key_state()
{
    struct keystate k;
    key_state(k.mask);
    return k;
}

int glug_key_is_mod_active(enum key_mods mod)
{
    return is_mod_pressed(mod);
}

int glug_key_are_mods_active(enum key_mods mods)
{
    return (mod_state() & mods) == mods;
}

enum key_mods glug_key_mod_state()
{
    return mod_state();
}

int glug_key_is_lock_toggled(enum key_locks lock)
{
    return is_lock_toggled(lock);
}

int glug_key_are_locks_toggled(enum key_locks locks)
{
    return (lock_state() & locks) == locks;
}

enum key_locks glug_key_lock_state()
{
    return lock_state();
}
