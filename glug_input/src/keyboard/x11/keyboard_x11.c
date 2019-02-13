#include "../keyboard_plat.h"
#include "../key_util.h"
#include "../mod_util.h"
#include "../lock_util.h"

#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/locks.h>
#include <glug_input/keyboard/mods.h>

#include <X11/extensions/XInput2.h>

#define KEYBOARDMAPSIZE 32

static Display *get_display()
{
    static Display *xdisplay = NULL;
    static int xinput_op;
    static int event, error;

    if (!xdisplay)
    {
        xdisplay = XOpenDisplay(NULL);

        // TODO: error reporting/handling
        XQueryExtension(get_display(), "XInputExtension", &xinput_op, &event, &error);

        int major = 2, minor = 2;
        XIQueryVersion(get_display(), &major, &minor);
    }

    return xdisplay;
}

static Window root_window()
{
    static Window xroot_window = 0;

    if (!xroot_window && get_display())
        return xroot_window = XDefaultRootWindow(get_display());

    return xroot_window;
}

static int check_key(char *xglug_vk_map, enum virtual_keys key)
{
    unsigned int glug_vk_code = XKeysymToKeycode(get_display(), code_from_key(key));
    return xglug_vk_map[glug_vk_code / 8] & (1 << glug_vk_code % 8);
}

int is_key_pressed(enum virtual_keys key)
{
    char xglug_vk_map[KEYBOARDMAPSIZE];

    XQueryKeymap(get_display(), xglug_vk_map);
    return check_key(xglug_vk_map, key);
}

void key_state(char *state)
{
    char xglug_vk_map[KEYBOARDMAPSIZE];
    enum virtual_keys key;

    XQueryKeymap(get_display(), xglug_vk_map);
    for (key = glug_vk_none; key < glug_vk_unknown; key++)
        set_key_state(state, key, check_key(xglug_vk_map, key));
}

int is_mod_pressed(enum key_mods mod)
{
    return !!(mod_state() & mod);
}

enum key_mods mod_state()
{
    static Window temp_win;
    static int temp;
    unsigned int modifiers;
    enum key_mods mod, mod_state = glug_km_none;

    XQueryPointer(get_display(), root_window(),
                  &temp_win, &temp_win,
                  &temp, &temp, &temp, &temp,
                  &modifiers);

    for (mod = glug_km_none + 1; mod < glug_km_unknown; mod <<= 1)
        if (modifiers & code_from_mod(mod))
            mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum key_locks lock)
{
    XKeyboardState lock_state;
    XGetKeyboardControl(get_display(), &lock_state);

    return lock_state.led_mask & lock;
}

enum key_locks lock_state()
{
    enum key_locks lock, lock_state = glug_kl_none;

    for (lock = glug_kl_none + 1; lock < glug_kl_unknown; lock <<= 1)
        if (is_lock_toggled(lock))
            lock_state |= lock;

    return lock_state;
}
