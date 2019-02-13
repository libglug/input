#ifndef glug_kl_UTIL_H
#define glug_kl_UTIL_H

#include <glug/input/keyboard/locks.h>

int        code_from_lock(enum key_locks lock);
enum key_locks lock_from_code(int lock);

#endif // glug_kl_UTIL_H
