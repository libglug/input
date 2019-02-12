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
