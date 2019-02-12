#ifndef GLUG_LOCKS_H
#define GLUG_LOCKS_H

enum locks
{
    glug_lock_none,
    glug_lock_caps    = 1 << 0,
    glug_lock_num     = 1 << 1,
    glug_lock_scroll  = 1 << 2,
    glug_lock_unknown = 1 << 3
};

#endif // GLUG_LOCKS_H
