#ifndef GLUG_KEYBOARD_PLAT_H
#define GLUG_KEYBOARD_PLAT_H

#include <glug/input/keyboard/keys.h>
#include <glug/input/keyboard/locks.h>
#include <glug/input/keyboard/mods.h>

int is_key_pressed(enum virtual_keys key);
void key_state(char *state);

int is_mod_pressed(enum key_mods mod);
enum key_mods mod_state();

int is_lock_toggled(enum key_locks lock);
enum key_locks lock_state();

#endif // GLUG_KEYBOARD_PLAT_H
