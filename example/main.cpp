#include <glug_input/mouse.h>
#include <glug_input/keyboard.h>

#include <iostream>

using namespace std;

int main(int, char *[])
{
    enum mouse_buttons lr = static_cast<mouse_buttons>(glug_mb_left | glug_mb_right);

    cout << "is left pressed? " << glug_mouse_is_pressed(glug_mb_left) << endl;
    cout << "are left and right pressed? " << glug_mouse_are_pressed(lr) << endl;
    cout << "are only left and right pressed? " << (glug_mouse_button_state() == lr) << endl;

    glug_point_t mouse_pos = glug_mouse_position();
    cout << "mouse: " << mouse_pos.x << "x" << mouse_pos.y << endl;

    cout << "is right shift pressed? " << glug_key_is_pressed(glug_vk_shift_r) << endl;
    cout << "current active keyboard modifiers: " << static_cast<int>(glug_key_mod_state()) << endl;
    cout << "is caps lock active? " << glug_key_is_lock_toggled(glug_kl_caps) << endl;

    keystate k = glug_key_state();
    cout << "is 'k' pressed? " << !!(k.mask[glug_vk_k / 8] & (1 << glug_vk_k % 8)) << endl;

    return 0;
}
