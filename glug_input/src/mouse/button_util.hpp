#ifndef GLUG_BUTTON_UTIL_HPP
#define GLUG_BUTTON_UTIL_HPP

namespace glug
{

enum class buttons;

class button_util
{
public:
  static int code_from_button(buttons button);
  static buttons button_from_code(int button);
};

} // namespace glug

#endif // GLUG_BUTTON_UTIL_HPP
