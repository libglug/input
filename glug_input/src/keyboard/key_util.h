#ifndef glug_vk_UTIL_H
#define glug_vk_UTIL_H

#include <glug/input/keyboard/keys.h>

int       code_from_key(enum virtual_keys key);
enum virtual_keys key_from_code(int key);

void set_key_state(char *state, enum virtual_keys key, int active);

#endif // glug_vk_UTIL_H
