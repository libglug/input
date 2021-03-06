#include "key_util.h"
#include <glug/input/keyboard/keys.h>

void set_key_state(char *state, enum virtual_keys key, int active)
{
    int index = key / 8;
    int mask = 1 << key % 8;
    if (active)
        state[index] |= mask;
    else
        state[index] &= ~mask;
}
