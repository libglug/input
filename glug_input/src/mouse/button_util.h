#ifndef GLUG_BUTTON_UTIL_H
#define GLUG_BUTTON_UTIL_H

#include <glug_input/mouse/buttons.h>

int          code_from_button(enum mouse_buttons button);
enum mouse_buttons button_from_code(int button);

#endif // GLUG_BUTTON_UTIL_H
