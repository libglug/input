#include "key_util.hpp"
#include <glug_input/keyboard/keys.hpp>

void set_key_state(char *state, enum keys key, int active)
{
    int index = key / 8;
    int mask = 1 << key % 8;
    if (active)
        state[index] |= mask;
    else
        state[index] &= ~mask;
}
