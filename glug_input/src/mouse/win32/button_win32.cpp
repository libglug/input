#include "../mouse_plat.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <Windows.h>

namespace glug
{

int mouse_plat::code_from_button(buttons button)
{
    switch(button)
    {
    case buttons::left:     return VK_LBUTTON;
    case buttons::mid:      return VK_MBUTTON;
    case buttons::right:    return VK_RBUTTON;
    case buttons::ex1:      return VK_XBUTTON1;
    case buttons::ex2:      return VK_XBUTTON2;
    case buttons::none:     // fall-through
    case buttons::unknown:  break;
    }

    return 0;
}

buttons mouse_plat::button_from_code(int button)
{
    switch(button)
    {
    case VK_LBUTTON:    return buttons::left;
    case VK_MBUTTON:    return buttons::mid;
    case VK_RBUTTON:    return buttons::right;
    case VK_XBUTTON1:   return buttons::ex1;
    case VK_XBUTTON2:   return buttons::ex2;
    default:            return buttons::none;
    }
}

} // namespace glug
