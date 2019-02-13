#include "../mouse_plat.h"
#include "../button_util.h"

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

#include <X11/extensions/XInput2.h>

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
        xroot_window = XDefaultRootWindow(get_display());

    return xroot_window;
}

static int xmouse_state(enum buttons *, struct glug_point_t *);
static enum buttons xmouse_buttons(XIButtonState *button_mask);

int is_button_pressed(enum buttons button)
{
    return !!(button & button_state());
}

enum buttons button_state()
{
    enum buttons state = glug_btn_none;
    xmouse_state(&state, NULL);
    return state;
}

struct glug_point_t position()
{
    struct glug_point_t mouse_pt = {0, 0};
    xmouse_state(NULL, &mouse_pt);
    return mouse_pt;
}

void move(const struct glug_point_t *delta)
{
    XWarpPointer(get_display(), None, None, 0, 0, 0, 0, delta->x, delta->y);
    XFlush(get_display());
}

void warp(const struct glug_point_t *new_pos)
{
    XWarpPointer(get_display(), None, root_window(), 0, 0, 0, 0, new_pos->x, new_pos->y);
    XFlush(get_display());
}

static int xmouse_state(enum buttons *button_state, struct glug_point_t *pos)
{
    static double temp;
    static Window temp_win;
    static XIModifierState temp_modifiers;
    static XIGroupState temp_group;

    int count = 0;
    XIDeviceInfo *devs = XIQueryDevice(get_display(), XIMasterPointer, &count);

    if (count)
    {
        double x, y;
        XIButtonState button_mask;
        XIQueryPointer(get_display(), devs[0].deviceid, root_window(),
                       &temp_win, &temp_win,
                       &x, &y,
                       &temp, &temp,
                       &button_mask,
                       &temp_modifiers,
                       &temp_group);

        if (pos)
        {
            pos->x = (int)x;
            pos->y = (int)y;
        }

        if (button_state)
            *button_state = xmouse_buttons(&button_mask);
    }

    return count == 0;
}

enum buttons xmouse_buttons(XIButtonState *button_mask)
{
    int xbuttons = 0;
    enum buttons btn, btn_state = glug_btn_none;

    for (int i = button_mask->mask_len; i--;)
        xbuttons |= button_mask->mask[i] << (i * 8);

    for (btn = glug_btn_none + 1; btn < glug_btn_unknown; btn <<= 1)
        if (code_from_button(btn) & xbuttons)
            btn_state |= btn;

    return btn_state;
}
