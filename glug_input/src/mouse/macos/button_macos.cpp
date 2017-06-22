#include "../mouse_plat.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <HIToolbox.framework/Headers/Events.h>

#define kCGMouseButtonEx1 (kCGMouseButtonCenter + 1)
#define kCGMouseButtonEx2 (kCGMouseButtonEx1 + 1)

namespace glug
{

int mouse_plat::code_from_button(buttons button)
{
    switch(button)
    {
    case buttons::left:     return kCGMouseButtonLeft;
    case buttons::mid:      return kCGMouseButtonCenter;
    case buttons::right:    return kCGMouseButtonRight;
    case buttons::ex1:      return kCGMouseButtonEx1;
    case buttons::ex2:      return kCGMouseButtonEx2;
    case buttons::none:     // fall-through
    case buttons::unknown:  break;
    }

    return -1;
}

buttons mouse_plat::button_from_code(int button)
{
    switch(button)
    {
    case kCGMouseButtonLeft:    return buttons::left;
    case kCGMouseButtonCenter:  return buttons::mid;
    case kCGMouseButtonRight:   return buttons::right;
    case kCGMouseButtonEx1:     return buttons::ex1;
    case kCGMouseButtonEx2:     return buttons::ex2;
    default:                    return buttons::none;
    }
}

} // namespace glug
