#include "../mouse_plat.h"
#include "../button_util.h"

#include <glug_input/mouse/buttons.h>
#include <glug_input/mouse/point.h>

#include <CoreGraphics/CGEventSource.h>
#include <CoreGraphics/CGEvent.h>

int is_button_pressed(enum buttons button)
{
    return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState,
                                    (CGMouseButton)code_from_button(button));
}

enum buttons button_state()
{
    enum buttons btn, btn_state = glug_btn_none;

    for(btn = glug_btn_none + 1; btn < glug_btn_unknown; btn <<= 1)
        if (is_button_pressed(btn))
            btn_state |= btn;

    return btn_state;
}

struct point position()
{
    CGEventRef event = CGEventCreate(nil);
    CGPoint cursor = CGEventGetLocation(event);
    struct point p;
    CFRelease(event);

    p.x = (int)cursor.x;
    p.y = (int)cursor.y;

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
    CGPoint pos = {
                    (CGFloat)new_pos->x,
                    (CGFloat)new_pos->y,
                  };

    CGDisplayMoveCursorToPoint(CGMainDisplayID(), pos);
    CGAssociateMouseAndMouseCursorPosition(true);
}
