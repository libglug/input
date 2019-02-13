#include <glug/input/mouse.h>
#include <glug/input/keyboard.h>

#include <stdio.h>

int main()
{
    enum mouse_buttons lr = (enum mouse_buttons)(glug_mb_left | glug_mb_right);

    printf("is left pressed? %d\n", glug_mouse_is_pressed(glug_mb_left));
    printf("are left and right pressed? %d\n", glug_mouse_are_pressed(lr));
    printf("are only left and right pressed? %d\n", glug_mouse_button_state() == lr);

    struct glug_point_t mouse_pos = glug_mouse_position();
    printf("mouse: %dx%d\n", mouse_pos.x, mouse_pos.y);

    printf("is right shift pressed? %d\n", glug_key_is_pressed(glug_vk_shift_r));
    printf("current active keyboard modifiers: %d\n", glug_key_mod_state());
    printf("is caps lock active? %d\n",glug_key_is_lock_toggled(glug_kl_caps));

    struct keystate k = glug_key_state();
    printf("is 'k' pressed? %d\n", !!(k.mask[glug_vk_k / 8] & (1 << glug_vk_k % 8)));

    return 0;
}
