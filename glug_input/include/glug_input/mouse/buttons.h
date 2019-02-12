#ifndef GLUG_BUTTONS_H
#define GLUG_BUTTONS_H

enum buttons
{
    glug_btn_none,
    glug_btn_left    = 1 << 0,
    glug_btn_mid     = 1 << 1,
    glug_btn_right   = 1 << 2,
    glug_btn_ex1     = 1 << 3,
    glug_btn_ex2     = 1 << 4,
    glug_btn_unknown = 1 << 5
};

#endif // GLUG_BUTTONS_H
