#ifndef GLUG_KEYBOARD_PLAT_H
#define GLUG_KEYBOARD_PLAT_H

#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/locks.h>
#include <glug_input/keyboard/mods.h>

int is_key_pressed(enum keys key);
void key_state(char *state);

int is_mod_pressed(enum mods mod);
enum mods mod_state();

int is_lock_toggled(enum locks lock);
enum locks lock_state();

#endif // GLUG_KEYBOARD_PLAT_H
