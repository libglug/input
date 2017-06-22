#include "../mouse_plat.hpp"

#include <CoreGraphics/CGEventSource.h>
#include <CoreGraphics/CGEvent.h>

namespace glug
{

bool mouse_plat::is_button_pressed(buttons button)
{
  CGMouseButton b = static_cast<CGMouseButton>(code_from_button(button));
  if (b == -1) return false;

  return CGEventSourceButtonState(kCGEventSourceStateCombinedSessionState, b);
}

} // namespace glug