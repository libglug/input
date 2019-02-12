#include <glug_input/keyboard/keyboard.h>
#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/mods.h>
#include <glug_input/keyboard/locks.h>

#include "keyboard_plat.h"

int glug_is_key_pressed(enum keys key)
{
    return is_key_pressed(key);
}

struct keystate glug_key_state()
{
    struct keystate k;
    key_state(k.mask);
    return k;
}

int glug_is_mod_active(enum mods mod)
{
    return is_mod_pressed(mod);
}

int glug_are_mods_active(enum mods mod)
{
    return (mod_state() & mod) == mod;
}

enum mods glug_mod_state()
{
    return mod_state();
}

int glug_is_lock_toggled(enum locks lock)
{
    return is_lock_toggled(lock);
}

int glug_are_locks_toggled(enum locks locks)
{
    return (lock_state() & locks) == locks;
}

enum locks glug_lock_state()
{
    return lock_state();
}
