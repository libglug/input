#ifndef GLUG_KEYBOARD_H
#define GLUG_KEYBOARD_H

#include <glug/import.h>
#include <glug/extern.h>

#include <glug/input/keyboard/keys.h>
#include <glug/input/keyboard/locks.h>
#include <glug/input/keyboard/mods.h>

GLUG_EXTERN_START

GLUG_LIB_API int             glug_key_is_pressed(enum virtual_keys key);
GLUG_LIB_API struct keystate glug_key_state();

GLUG_LIB_API int             glug_key_is_mod_active(enum key_mods mod);
GLUG_LIB_API int             glug_key_are_mods_active(enum key_mods mods);
GLUG_LIB_API enum key_mods   glug_key_mod_state();

GLUG_LIB_API int             glug_key_is_lock_toggled(enum key_locks lock);
GLUG_LIB_API int             glug_key_are_locks_toggled(enum key_locks locks);
GLUG_LIB_API enum key_locks  glug_key_lock_state();

GLUG_EXTERN_END

#endif // GLUG_KEYBOARD_H
