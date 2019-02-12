#include <glug_input/mouse/mouse.hpp>
#include <glug_input/mouse/buttons.hpp>
#include <glug_input/mouse/point.hpp>

#include "mouse_plat.hpp"

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

struct point glug_position()
{
    return position();
}

void glug_move(const struct point *delta)
{
    move(delta);
}

void glug_warp(const struct point *new_pos)
{
    warp(new_pos);
}
