#include "../mouse_plat.h"
#include "../button_util.h"

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point_t.h>

#include <Windows.h>

int is_button_pressed(enum mouse_buttons button)
{
    static unsigned short mask = 1 << 15;

    return (GetAsyncKeyState(code_from_button(button)) & mask) != 0;
}

enum mouse_buttons button_state()
{
    enum mouse_buttons btn, btn_state = glug_mb_none;

    for (btn = glug_mb_none + 1; btn < glug_mb_unknown; btn <<= 1)
        if (is_button_pressed(btn))
            btn_state |= btn;

    return btn_state;
}

struct glug_point_t position()
{
    POINT mp;
    struct glug_point_t p;

    GetCursorPos(&mp);
    p.x = mp.x;
    p.y = mp.y;

    return p;
}

void move(const struct glug_point_t *delta)
{
    struct glug_point_t curr = position();
    curr.x += delta->x;
    curr.y += delta->y;

    warp(&curr);
}

void warp(const struct glug_point_t *new_pos)
{
    SetCursorPos(new_pos->x, new_pos->y);
}
