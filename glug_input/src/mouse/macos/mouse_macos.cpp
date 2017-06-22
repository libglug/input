#include "../mouse_plat.hpp"

#include <CoreGraphics/CGEventSource.h>
#include <CoreGraphics/CGEvent.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState,
                                  static_cast<CGMouseButton>(code_from_button(button)));
}

} // namespace glug
