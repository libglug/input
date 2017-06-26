#ifndef GLUG_KEYBOARD_HPP
#define GLUG_KEYBOARD_HPP

#include <glug_input/export.hpp>

#include <vector>

namespace glug
{

enum class keys;
enum class mods;
enum class locks;

class INPUT_LIB_API keyboard
{
public:
  static bool is_key_pressed(keys key);
  static std::vector<bool> key_state();

  static bool is_mod_active(mods mod);
  static bool are_mods_active(mods mods);
  static mods mod_state();

  static bool is_lock_toggled(locks lock);
  static bool are_locks_toggled(locks locks);
  static locks lock_state();
};

} // namespace glug

#endif // GLUG_KEYBOARD_HPP
