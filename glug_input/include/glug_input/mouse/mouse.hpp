#ifndef GLUG_MOUSE_H
#define GLUG_MOUSE_H

#include <glug_input/export.hpp>
#include <glug_input/extern.hpp>

#include <glug_input/mouse/buttons.hpp>
#include <glug_input/mouse/point.hpp>

GLUG_EXTERN_START

int          INPUT_LIB_API glug_is_button_pressed(enum buttons buttons);
int          INPUT_LIB_API glug_are_buttons_pressed(enum buttons buttons);
int          INPUT_LIB_API glug_only_buttons_pressed(enum buttons buttons);

enum buttons INPUT_LIB_API glug_button_state();

struct point INPUT_LIB_API glug_position();

void         INPUT_LIB_API glug_move(const struct point *delta);
void         INPUT_LIB_API glug_warp(const struct point *new_pos);

GLUG_EXTERN_END

#endif // GLUG_MOUSE_H
