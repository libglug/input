#ifndef GLUG_KEY_UTIL_H
#define GLUG_KEY_UTIL_H

#include <glug_input/keyboard/keys.h>

int       code_from_key(enum keys key);
enum keys key_from_code(int key);

void set_key_state(char *state, enum keys key, int active);

#endif // GLUG_KEY_UTIL_H
