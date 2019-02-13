#include <glug_input/mouse/mouse.h>
#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

#include "mouse_plat.h"

int glug_is_button_pressed(enum buttons button)
{
    return is_button_pressed(button);
}

int glug_are_buttons_pressed(enum buttons buttons)
{
    return (button_state() & buttons) == buttons;
}

int glug_only_buttons_pressed(enum buttons buttons)
{
    return button_state() == buttons;
}

enum buttons glug_button_state()
{
    return button_state();
}

struct glug_point_t glug_position()
{
    return position();
}

void glug_move(const struct glug_point_t *delta)
{
    move(delta);
}

void glug_warp(const struct glug_point_t *new_pos)
{
    warp(new_pos);
}
