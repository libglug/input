#include <glug_input/mouse.hpp>
#include <glug_input/keyboard.hpp>
#include <glug_input/event/event_queue.hpp>
#include <glug_input/event/key_event.hpp>

#include <iostream>

using namespace std;
using namespace glug;

int main(int, char *[])
{
  buttons lr = buttons::left | buttons::right;

  key_event event;
  int ev;
  event_queue::wait_for_event(event);

  cout << boolalpha;
  cout << "is left pressed? " << mouse::is_button_pressed(buttons::left) << endl;
  cout << "are left and right pressed? " << mouse::are_buttons_pressed(lr) << endl;
  cout << "are only left and right pressed? " << mouse::only_buttons_pressed(lr) << endl;

  point mouse_pos = mouse::position();
  cout << "mouse: " << mouse_pos.x << "x" << mouse_pos.y << endl;

  cout << "is right shift pressed? " << keyboard::is_key_pressed(keys::shift_r) << endl;
  cout << "current active keyboard modifiers: " << static_cast<int>(keyboard::mod_state()) << endl;
  cout << "is caps lock active? " << keyboard::is_lock_toggled(locks::caps) << endl;

  return 0;
}
