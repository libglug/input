#include "../button_util.h"
#include <glug_input/mouse/buttons.h>

#include <HIToolbox.framework/Headers/Events.h>

#define kCGMouseButtonEx1 (kCGMouseButtonCenter + 1)
#define kCGMouseButtonEx2 (kCGMouseButtonEx1 + 1)

int code_from_button(enum mouse_buttons button)
{
    switch(button)
    {
    case glug_mb_left:              return kCGMouseButtonLeft;
    case glug_mb_mid:               return kCGMouseButtonCenter;
    case glug_mb_right:             return kCGMouseButtonRight;
    case glug_mb_ex1:               return kCGMouseButtonEx1;
    case glug_mb_ex2:               return kCGMouseButtonEx2;
    case glug_mb_none:              // fall-through
    case glug_mb_unknown:           break;
    }

    return -1;
}

enum mouse_buttons button_from_code(int button)
{
    switch(button)
    {
    case kCGMouseButtonLeft:        return glug_mb_left;
    case kCGMouseButtonCenter:      return glug_mb_mid;
    case kCGMouseButtonRight:       return glug_mb_right;
    case kCGMouseButtonEx1:         return glug_mb_ex1;
    case kCGMouseButtonEx2:         return glug_mb_ex2;
    default:                        return glug_mb_none;
    }
}
