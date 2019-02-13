#include "../mouse_plat.h"
#include "../button_util.h"

#include <glug/input/mouse/buttons.h>
#include <glug/input/mouse/point_t.h>

#include <CoreGraphics/CGEventSource.h>
#include <CoreGraphics/CGEvent.h>

int is_button_pressed(enum mouse_buttons button)
{
    return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState,
                                    (CGMouseButton)code_from_button(button));
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
    CGEventRef event = CGEventCreate(nil);
    CGPoint cursor = CGEventGetLocation(event);
    struct glug_point_t p;
    CFRelease(event);

    p.x = (int)cursor.x;
    p.y = (int)cursor.y;

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
    CGPoint pos = {
                    (CGFloat)new_pos->x,
                    (CGFloat)new_pos->y,
                  };

    CGDisplayMoveCursorToPoint(CGMainDisplayID(), pos);
    CGAssociateMouseAndMouseCursorPosition(true);
}
