#ifndef GLUG_KEYBOARD_H
#define GLUG_KEYBOARD_H

#include <glug_input/export.h>
#include <glug_input/extern.h>

#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/locks.h>
#include <glug_input/keyboard/mods.h>

GLUG_EXTERN_START

int             INPUT_LIB_API glug_is_key_pressed(enum keys key);
struct keystate INPUT_LIB_API glug_key_state();

int             INPUT_LIB_API glug_is_mod_active(enum mods mod);
int             INPUT_LIB_API glug_are_mods_active(enum mods mods);
enum mods       INPUT_LIB_API glug_mod_state();

int             INPUT_LIB_API glug_is_lock_toggled(enum locks lock);
int             INPUT_LIB_API glug_are_locks_toggled(enum locks locks);
enum locks      INPUT_LIB_API glug_lock_state();

GLUG_EXTERN_END

#endif // GLUG_KEYBOARD_H
