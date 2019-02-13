#include <glug/input/mouse/mouse.h>
#include <glug/input/mouse/buttons.h>
#include <glug/input/mouse/point_t.h>

#include "mouse_plat.h"

int glug_mouse_is_pressed(enum mouse_buttons button)
{
    return is_button_pressed(button);
}

int glug_mouse_are_pressed(enum mouse_buttons buttons)
{
    return (button_state() & buttons) == buttons;
}

enum mouse_buttons glug_mouse_button_state()
{
    return button_state();
}

struct glug_point_t glug_mouse_position()
{
    return position();
}

void glug_mouse_move(const struct glug_point_t *delta)
{
    move(delta);
}

void glug_mouse_warp(const struct glug_point_t *new_pos)
{
    warp(new_pos);
}
