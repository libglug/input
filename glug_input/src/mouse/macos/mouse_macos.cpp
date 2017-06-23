#include "../mouse_plat.hpp"
#include "../button_util.hpp"
#include <glug_input/mouse/buttons.hpp>

#include <array>
#include <CoreGraphics/CGEventSource.h>
#include <CoreGraphics/CGEvent.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState,
                                  static_cast<CGMouseButton>(button_util::code_from_button(button)));
}

buttons mouse_plat::button_state()
{
  static const std::array<buttons, 5> button_list = {{
                                                       buttons::left,
                                                       buttons::mid,
                                                       buttons::right,
                                                       buttons::ex1,
                                                       buttons::ex2
                                                     }};

  buttons state = buttons::none;

  for (const auto button: button_list)
    if (is_button_pressed(button))
      state |= button;

  return state;
}

point mouse_plat::get_position()
{
  CGEventRef event = CGEventCreate(nil);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  return {
          static_cast<long long>(cursor.x),
          static_cast<long long>(cursor.y),
         };
}



} // namespace glug
