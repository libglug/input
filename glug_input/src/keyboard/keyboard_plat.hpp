#ifndef GLUG_KEYBOARD_PLAT_HPP
#define GLUG_KEYBOARD_PLAT_HPP

#include <glug_input/export.hpp>

namespace glug
{

enum class keys;
enum class mods;
enum class locks;

class GLUG_LIB_LOCAL keyboard_plat
{
public:
  static bool is_key_pressed(keys key);
  static void key_state(char *state);

  static bool is_mod_pressed(mods mod);
  static mods mod_state();

  static bool is_lock_toggled(locks lock);
  static locks lock_state();
};

} // namespace glug

#endif // GLUG_KEYBOARD_PLAT_HPP
