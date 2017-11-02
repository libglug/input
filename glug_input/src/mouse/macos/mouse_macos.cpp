#include "../mouse_plat.hpp"
#include "../button_util.hpp"

#include <glug_input/mouse/buttons.hpp>
#include <glug_input/mouse/point.hpp>

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
  buttons state = buttons::none;

  buttons button = static_cast<buttons>(static_cast<int>(buttons::none) + 1);
  for(; button < buttons::unknown; button <<= 1)
    if (is_button_pressed(button))
      state |= button;

  return state;
}

point mouse_plat::position()
{
  CGEventRef event = CGEventCreate(nil);
  CGPoint cursor = CGEventGetLocation(event);
  CFRelease(event);

  return {
          static_cast<long long>(cursor.x),
          static_cast<long long>(cursor.y),
         };
}

void mouse_plat::move(const point &delta)
{
  point curr = position();
  curr.x += delta.x;
  curr.y += delta.y;

  warp(curr);
}

void mouse_plat::warp(const point &new_pos)
{
  CGPoint pos = {
                 static_cast<CGFloat>(new_pos.x),
                 static_cast<CGFloat>(new_pos.y),
                };

  CGDisplayMoveCursorToPoint(CGMainDisplayID(), pos);
  CGAssociateMouseAndMouseCursorPosition(true);
}

} // namespace glug
