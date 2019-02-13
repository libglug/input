#ifndef GLUG_MOUSE_H
#define GLUG_MOUSE_H

#include <glug_input/export.h>
#include <glug_input/extern.h>

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

GLUG_EXTERN_START

INPUT_LIB_API int                 glug_is_button_pressed(enum buttons buttons);
INPUT_LIB_API int                 glug_are_buttons_pressed(enum buttons buttons);
INPUT_LIB_API int                 glug_only_buttons_pressed(enum buttons buttons);
INPUT_LIB_API enum buttons        glug_button_state();

INPUT_LIB_API struct glug_point_t glug_position();
INPUT_LIB_API void                glug_move(const struct glug_point_t *delta);
INPUT_LIB_API void                glug_warp(const struct glug_point_t *new_pos);

GLUG_EXTERN_END

#endif // GLUG_MOUSE_H
