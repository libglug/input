#include <glug_input/mouse.hpp>

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

  return 0;
}
