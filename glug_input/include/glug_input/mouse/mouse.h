#ifndef GLUG_MOUSE_H
#define GLUG_MOUSE_H

#include <glug_input/export.h>
#include <glug_input/extern.h>

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

GLUG_EXTERN_START

INPUT_LIB_API int                 glug_mouse_is_pressed(enum buttons buttons);
INPUT_LIB_API int                 glug_mouse_are_pressed(enum buttons buttons);
INPUT_LIB_API enum buttons        glug_mouse_button_state();

INPUT_LIB_API struct glug_point_t glug_mouse_position();
INPUT_LIB_API void                glug_mouse_move(const struct glug_point_t *delta);
INPUT_LIB_API void                glug_mouse_warp(const struct glug_point_t *new_pos);

GLUG_EXTERN_END

#endif // GLUG_MOUSE_H
