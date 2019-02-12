#include "../button_util.h"
#include <glug_input/mouse/buttons.h>

#include <HIToolbox.framework/Headers/Events.h>

#define kCGMouseButtonEx1 (kCGMouseButtonCenter + 1)
#define kCGMouseButtonEx2 (kCGMouseButtonEx1 + 1)

int code_from_button(enum buttons button)
{
    switch(button)
    {
    case glug_btn_left:         return kCGMouseButtonLeft;
    case glug_btn_mid:          return kCGMouseButtonCenter;
    case glug_btn_right:        return kCGMouseButtonRight;
    case glug_btn_ex1:          return kCGMouseButtonEx1;
    case glug_btn_ex2:          return kCGMouseButtonEx2;
    case glug_btn_none:         // fall-through
    case glug_btn_unknown:      break;
    }

    return -1;
}

enum buttons button_from_code(int button)
{
    switch(button)
    {
    case kCGMouseButtonLeft:    return glug_btn_left;
    case kCGMouseButtonCenter:  return glug_btn_mid;
    case kCGMouseButtonRight:   return glug_btn_right;
    case kCGMouseButtonEx1:     return glug_btn_ex1;
    case kCGMouseButtonEx2:     return glug_btn_ex2;
    default:                    return glug_btn_none;
    }
}
