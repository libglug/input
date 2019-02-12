#ifndef GLUG_MOUSE_PLAT_H
#define GLUG_MOUSE_PLAT_H

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point.h>

int is_button_pressed(enum buttons buttons);
enum buttons button_state();

struct point position();

void move(const struct point *delta);
void warp(const struct point *new_pos);

#endif // GLUG_MOUSE_PLAT_H
