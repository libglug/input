#include "../mouse_plat.hpp"

#include <Windows.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
    static unsigned short mask = 1 << 15;

    int b = code_from_button(button);
    return (GetAsyncKeyState(b) & mask) != 0;
}

} // namespace glug
