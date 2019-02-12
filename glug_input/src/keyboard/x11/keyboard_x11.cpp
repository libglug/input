#include "../keyboard_plat.hpp"
#include "../key_util.hpp"
#include "../mod_util.hpp"
#include "../lock_util.hpp"

#include <glug_input/keyboard/keys.hpp>
#include <glug_input/keyboard/locks.hpp>
#include <glug_input/keyboard/mods.hpp>

#include <X11/Xutil.h>

#define KEYBOARDMAPSIZE 32

static Display *get_display()
{
    static Display *xdisplay = NULL;

    if (xdisplay) return xdisplay;

    xdisplay = XOpenDisplay(NULL);
    return xdisplay;
}

static Window root_window()
{
    static Window xroot_window = 0;
    if (!get_display() || xroot_window) return xroot_window;

    return XDefaultRootWindow(get_display());
}

static int check_key(char *xglug_key_map, enum keys key)
{
    unsigned int glug_key_code = XKeysymToKeycode(get_display(), code_from_key(key));
    return xglug_key_map[glug_key_code / 8] & (1 << glug_key_code % 8);
}

int is_key_pressed(enum keys key)
{
    char xglug_key_map[KEYBOARDMAPSIZE];

    XQueryKeymap(get_display(), xglug_key_map);
    return check_key(xglug_key_map, key);
}

void key_state(char *state)
{
    char xglug_key_map[KEYBOARDMAPSIZE];
    enum keys key;

    XQueryKeymap(get_display(), xglug_key_map);
    for (key = glug_key_none; key < glug_key_unknown; key++)
        set_key_state(state, key, check_key(xglug_key_map, key));
}

int is_mod_pressed(enum mods mod)
{
    return !!(mod_state() & mod);
}

enum mods mod_state()
{
    static Window temp_win;
    static int temp;
    unsigned int modifiers;
    enum mods mod, mod_state = glug_mod_none;

    XQueryPointer(get_display(), root_window(),
                  &temp_win, &temp_win,
                  &temp, &temp, &temp, &temp,
                  &modifiers);

    for (mod = glug_mod_none + 1; mod < glug_mod_unknown; mod <<= 1)
    if (modifiers & code_from_mod(mod))
        mod_state |= mod;

    return mod_state;
}

int is_lock_toggled(enum locks lock)
{
    XKeyboardState lock_state;
    XGetKeyboardControl(get_display(), &lock_state);

    return lock_state.led_mask & lock;
}

enum locks lock_state()
{
    enum locks lock, lock_state = glug_lock_none;

    for (lock = glug_lock_none + 1; lock < glug_lock_unknown; lock <<= 1)
        if (is_lock_toggled(lock))
            lock_state |= lock;

    return lock_state;
}
