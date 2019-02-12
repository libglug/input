#ifndef GLUG_LOCK_UTIL_H
#define GLUG_LOCK_UTIL_H

#include <glug_input/keyboard/locks.h>

int        code_from_lock(enum locks lock);
enum locks lock_from_code(int lock);

#endif // GLUG_LOCK_UTIL_H
