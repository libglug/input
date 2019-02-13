#include "../keyboard_plat.h"
#include "../key_util.h"
#include "../mod_util.h"
#include "../lock_util.h"

#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/locks.h>
#include <glug_input/keyboard/mods.h>

#include <Windows.h>

static int get_key_state(int vk_key)
{
    static unsigned short keydown_mask = 1 << 15;
    return (GetAsyncKeyState(vk_key) & keydown_mask) != 0;
}

int is_key_pressed(enum virtual_keys key)
{
    return get_key_state(code_from_key(key));
}

void key_state(char *state)
{
    enum virtual_keys key;
    for (key = glug_vk_none; key < glug_vk_unknown; key++)
        set_key_state(state, key, is_key_pressed(key));
}

int is_mod_pressed(enum key_mods mod)
{
    if (mod == glug_km_super)
        return is_key_pressed(glug_vk_super_l) || is_key_pressed(glug_vk_super_r);

    return get_key_state(code_from_mod(mod));
}

enum key_mods mod_state()
{
    enum key_mods mod, mod_state = glug_km_none;
    for (mod = glug_km_none + 1; mod < glug_km_unknown; mod <<= 1)
        if (is_mod_pressed(mod))
            mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum key_locks lock)
{
    static SHORT lock_mask = 1;
    return (GetKeyState(code_from_lock(lock)) & lock_mask) != 0;
}

enum key_locks lock_state()
{
    enum key_locks lock_state = glug_kl_none;
    for (enum key_locks lock = glug_kl_none + 1; lock < glug_kl_unknown; lock <<= 1)
        if (is_lock_toggled(lock))
            lock_state |= lock;

    return lock_state;
}
