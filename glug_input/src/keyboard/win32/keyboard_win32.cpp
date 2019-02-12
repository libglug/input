#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <Windows.h>

static int get_key_state(int vk_key)
{
    static unsigned short keydown_mask = 1 << 15;
    return (GetAsyncKeyState(vk_key) & keydown_mask) != 0;
}

int is_key_pressed(enum keys key)
{
    return get_key_state(code_from_key(key));
}

void key_state(char *state)
{
    enum keys key;
    for (key = glug_key_none; key < glug_key_unknown; key++)
        set_key_state(state, key, is_key_pressed(key));
}

int is_mod_pressed(enum mods mod)
{
    if (mod == glug_mod_super)
        return is_key_pressed(glug_key_super_l) || is_key_pressed(glug_key_super_r);

    return get_key_state(code_from_mod(mod));
}

enum mods mod_state()
{
    enum mods mod, mod_state = glug_mod_none;
    for (mod = glug_mod_none + 1; mod < glug_mod_unknown; mod <<= 1)
        if (is_mod_pressed(mod))
            mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum locks lock)
{
    static SHORT lock_mask = 1;
    return (GetKeyState(code_from_lock(lock)) & lock_mask) != 0;
}

enum locks lock_state()
{
    enum locks lock_state = glug_lock_none;
    for (enum locks lock = glug_lock_none + 1; lock < glug_lock_unknown; lock <<= 1)
        if (is_lock_toggled(lock))
            lock_state |= lock;

    return lock_state;
}
