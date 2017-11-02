#include <glug_input/mouse.hpp>
#include <glug_input/keyboard.hpp>

#include <iostream>

using namespace std;
using namespace glug;

int main(int, char *[])
{
  buttons lr = buttons::left | buttons::right;

  cout << boolalpha;
  cout << "is left pressed? " << mouse::is_button_pressed(buttons::left) << endl;
  cout << "are left and right pressed? " << mouse::are_buttons_pressed(lr) << endl;
  cout << "are only left and right pressed? " << mouse::only_buttons_pressed(lr) << endl;

  point mouse_pos = mouse::position();
  cout << "mouse: " << mouse_pos.x << "x" << mouse_pos.y << endl;

  cout << "is right shift pressed? " << keyboard::is_key_pressed(keys::shift_r) << endl;
  cout << "current active keyboard modifiers: " << static_cast<int>(keyboard::mod_state()) << endl;
  cout << "is caps lock active? " << keyboard::is_lock_toggled(locks::caps) << endl;

  keystate k = keyboard::key_state();
  cout << "is 'k' pressed? " << !!(k.mask[(int)keys::k / 8] & (1 << (int)keys::k % 8)) << endl;

 return 0;
}

