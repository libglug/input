#ifndef GLUG_KEYBOARD_H
#define GLUG_KEYBOARD_H

#include <glug_input/export.h>
#include <glug_input/extern.h>

#include <glug_input/keyboard/keys.h>
#include <glug_input/keyboard/locks.h>
#include <glug_input/keyboard/mods.h>

GLUG_EXTERN_START

INPUT_LIB_API int             glug_key_is_pressed(enum keys key);
INPUT_LIB_API struct keystate glug_key_state();

INPUT_LIB_API int             glug_key_is_mod_active(enum mods mod);
INPUT_LIB_API int             glug_key_are_mods_active(enum mods mods);
INPUT_LIB_API enum mods       glug_key_mod_state();

INPUT_LIB_API int             glug_key_is_lock_toggled(enum locks lock);
INPUT_LIB_API int             glug_key_are_locks_toggled(enum locks locks);
INPUT_LIB_API enum locks      glug_key_lock_state();

GLUG_EXTERN_END

#endif // GLUG_KEYBOARD_H
