#include "../mouse_plat.h"
#include "../button_util.h"

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point.h>

#include <Windows.h>

int is_button_pressed(enum buttons button)
{
    static unsigned short mask = 1 << 15;

    return (GetAsyncKeyState(code_from_button(button)) & mask) != 0;
}

enum buttons button_state()
{
    enum buttons btn, btn_state = glug_btn_none;

    for (btn = glug_btn_none + 1; btn < glug_btn_unknown; btn <<= 1)
        if (is_button_pressed(btn))
            btn_state |= btn;

    return btn_state;
}

struct point position()
{
    POINT mp;
    struct point p;

    GetCursorPos(&mp);
    p.x = mp.x;
    p.y = mp.y;

    return p;
}

void move(const struct point *delta)
{
    struct point curr = position();
    curr.x += delta->x;
    curr.y += delta->y;

    warp(&curr);
}

void warp(const struct point *new_pos)
{
    SetCursorPos(new_pos->x, new_pos->y);
}
