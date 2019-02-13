#ifndef GLUG_MOUSE_PLAT_H
#define GLUG_MOUSE_PLAT_H

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

int is_button_pressed(enum mouse_buttons buttons);
enum mouse_buttons button_state();

struct glug_point_t position();

void move(const struct glug_point_t *delta);
void warp(const struct glug_point_t *new_pos);

#endif // GLUG_MOUSE_PLAT_H
