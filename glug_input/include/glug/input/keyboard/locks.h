#ifndef GLUG_LOCKS_H
#define GLUG_LOCKS_H

enum key_locks
{
    glug_kl_none,
    glug_kl_caps    = 1 << 0,
    glug_kl_num     = 1 << 1,
    glug_kl_scroll  = 1 << 2,
    glug_kl_unknown = 1 << 3
};

#endif // GLUG_LOCKS_H
