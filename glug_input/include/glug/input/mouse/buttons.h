#ifndef GLUG_BUTTONS_H
#define GLUG_BUTTONS_H

enum mouse_buttons
{
    glug_mb_none,
    glug_mb_left    = 1 << 0,
    glug_mb_mid     = 1 << 1,
    glug_mb_right   = 1 << 2,
    glug_mb_ex1     = 1 << 3,
    glug_mb_ex2     = 1 << 4,
    glug_mb_unknown = 1 << 5
};

#endif // GLUG_BUTTONS_H
