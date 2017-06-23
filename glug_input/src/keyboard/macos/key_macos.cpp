#include "../key_util.hpp"
#include "key_defs.hpp"
#include <glug_input/keyboard/keys.hpp>

namespace glug
{

int key_util::code_from_key(keys key)
{
  switch (key)
  {
  case keys::shift_l:     return gVK_LeftShift;
  case keys::shift_r:     return gVK_RightShift;
  case keys::alt_l:       return gVK_LeftOption;
  case keys::alt_r:       return gVK_RightOption;
  case keys::ctrl_l:      return gVK_LeftControl;
  case keys::ctrl_r:      return gVK_RightControl;
  case keys::super_l:     return gVK_LeftCommand;
  case keys::super_r:     return gVK_RightCommand;
  case keys::escape:      return kVK_Escape;
  case keys::insert:      return kVK_Help;
  case keys::home:        return kVK_Home;
  case keys::end:         return kVK_End;
  case keys::pageup:      return kVK_PageUp;
  case keys::pagedown:    return kVK_PageDown;
//  case keys::print:       return ??;
//  case keys::pause:       return ??;
  case keys::backspace:   return kVK_Delete;
  case keys::del:         return kVK_ForwardDelete;
  case keys::tab:         return kVK_Tab;
  case keys::enter:       return kVK_Return;
//  case keys::menu:        return ??;
  case keys::space:       return kVK_Space;
  case keys::up:          return kVK_UpArrow;
  case keys::down:        return kVK_DownArrow;
  case keys::left:        return kVK_LeftArrow;
  case keys::right:       return kVK_RightArrow;
  case keys::f1:          return kVK_F1;
  case keys::f2:          return kVK_F2;
  case keys::f3:          return kVK_F3;
  case keys::f4:          return kVK_F4;
  case keys::f5:          return kVK_F5;
  case keys::f6:          return kVK_F6;
  case keys::f7:          return kVK_F7;
  case keys::f8:          return kVK_F8;
  case keys::f9:          return kVK_F9;
  case keys::f10:         return kVK_F10;
  case keys::f11:         return kVK_F11;
  case keys::f12:         return kVK_F12;
  case keys::tilde:       return kVK_ANSI_Grave;
  case keys::one:         return kVK_ANSI_1;
  case keys::two:         return kVK_ANSI_2;
  case keys::three:       return kVK_ANSI_3;
  case keys::four:        return kVK_ANSI_4;
  case keys::five:        return kVK_ANSI_5;
  case keys::six:         return kVK_ANSI_6;
  case keys::seven:       return kVK_ANSI_7;
  case keys::eight:       return kVK_ANSI_8;
  case keys::nine:        return kVK_ANSI_9;
  case keys::zero:        return kVK_ANSI_0;
  case keys::minus:       return kVK_ANSI_Minus;
  case keys::equal:       return kVK_ANSI_Equal;
  case keys::a:           return kVK_ANSI_A;
  case keys::b:           return kVK_ANSI_B;
  case keys::c:           return kVK_ANSI_C;
  case keys::d:           return kVK_ANSI_D;
  case keys::e:           return kVK_ANSI_E;
  case keys::f:           return kVK_ANSI_F;
  case keys::g:           return kVK_ANSI_G;
  case keys::h:           return kVK_ANSI_H;
  case keys::i:           return kVK_ANSI_I;
  case keys::j:           return kVK_ANSI_J;
  case keys::k:           return kVK_ANSI_K;
  case keys::l:           return kVK_ANSI_L;
  case keys::m:           return kVK_ANSI_M;
  case keys::n:           return kVK_ANSI_N;
  case keys::o:           return kVK_ANSI_O;
  case keys::p:           return kVK_ANSI_P;
  case keys::q:           return kVK_ANSI_Q;
  case keys::r:           return kVK_ANSI_R;
  case keys::s:           return kVK_ANSI_S;
  case keys::t:           return kVK_ANSI_T;
  case keys::u:           return kVK_ANSI_U;
  case keys::v:           return kVK_ANSI_V;
  case keys::w:           return kVK_ANSI_W;
  case keys::x:           return kVK_ANSI_X;
  case keys::y:           return kVK_ANSI_Y;
  case keys::z:           return kVK_ANSI_Z;
  case keys::bracket_l:   return kVK_ANSI_LeftBracket;
  case keys::bracket_r:   return kVK_ANSI_RightBracket;
  case keys::backslash:   return kVK_ANSI_Backslash;
  case keys::semicolon:   return kVK_ANSI_Semicolon;
  case keys::quote:       return kVK_ANSI_Quote;
  case keys::comma:       return kVK_ANSI_Comma;
  case keys::period:      return kVK_ANSI_Period;
  case keys::slash:       return kVK_ANSI_Slash;
  case keys::num_zero:    return kVK_ANSI_Keypad0;
  case keys::num_one:     return kVK_ANSI_Keypad1;
  case keys::num_two:     return kVK_ANSI_Keypad2;
  case keys::num_three:   return kVK_ANSI_Keypad3;
  case keys::num_four:    return kVK_ANSI_Keypad4;
  case keys::num_five:    return kVK_ANSI_Keypad5;
  case keys::num_six:     return kVK_ANSI_Keypad6;
  case keys::num_seven:   return kVK_ANSI_Keypad7;
  case keys::num_eight:   return kVK_ANSI_Keypad8;
  case keys::num_nine:    return kVK_ANSI_Keypad9;
  case keys::num_add:     return kVK_ANSI_KeypadPlus;
  case keys::num_minus:   return kVK_ANSI_KeypadMinus;
  case keys::num_mult:    return kVK_ANSI_KeypadMultiply;
  case keys::num_div:     return kVK_ANSI_KeypadDivide;
  case keys::num_dec:     return kVK_ANSI_KeypadDecimal;
  case keys::none:        // fall-through
  case keys::unknown:     break;
  }

  return 0;
}

keys key_util::key_from_code(int key)
{
  switch (key)
  {
  case gMask_LeftShift:           return keys::shift_l;
  case gMask_RightShift:          return keys::shift_r;
  case gMask_LeftOption:          return keys::alt_l;
  case gMask_RightOption:         return keys::alt_r;
  case gMask_LeftControl:         return keys::ctrl_l;
  case gMask_RightControl:        return keys::ctrl_r;
  case gMask_LeftCommand:         return keys::super_l;
  case gMask_RightCommand:        return keys::super_r;
  case kVK_Escape:                return keys::escape;
  case kVK_Help:                  return keys::insert;
  case kVK_Home:                  return keys::home;
  case kVK_End:                   return keys::end;
  case kVK_PageUp:                return keys::pageup;
  case kVK_PageDown:              return keys::pagedown;
//  case kVK_PrintScreen:           return keys::print;
//  case VK_PAUSE:                  return keys::pause;
  case kVK_Delete:                return keys::backspace;
  case kVK_ForwardDelete:         return keys::del;
  case kVK_Tab:                   return keys::tab;
  case kVK_Return:                return keys::enter;
//  case kVK_Menu:                  return keys::menu;
  case kVK_Space:                 return keys::space;
  case kVK_UpArrow:               return keys::up;
  case kVK_DownArrow:             return keys::down;
  case kVK_LeftArrow:             return keys::left;
  case kVK_RightArrow:            return keys::right;
  case kVK_F1:                    return keys::f1;
  case kVK_F2:                    return keys::f2;
  case kVK_F3:                    return keys::f3;
  case kVK_F4:                    return keys::f4;
  case kVK_F5:                    return keys::f5;
  case kVK_F6:                    return keys::f6;
  case kVK_F7:                    return keys::f7;
  case kVK_F8:                    return keys::f8;
  case kVK_F9:                    return keys::f9;
  case kVK_F10:                   return keys::f10;
  case kVK_F11:                   return keys::f11;
  case kVK_F12:                   return keys::f12;
  case kVK_ANSI_Grave:            return keys::tilde;
  case kVK_ANSI_1:                return keys::one;
  case kVK_ANSI_2:                return keys::two;
  case kVK_ANSI_3:                return keys::three;
  case kVK_ANSI_4:                return keys::four;
  case kVK_ANSI_5:                return keys::five;
  case kVK_ANSI_6:                return keys::six;
  case kVK_ANSI_7:                return keys::seven;
  case kVK_ANSI_8:                return keys::eight;
  case kVK_ANSI_9:                return keys::nine;
  case kVK_ANSI_0:                return keys::zero;
  case kVK_ANSI_Minus:            return keys::minus;
  case kVK_ANSI_Equal:            return keys::equal;
  case kVK_ANSI_A:                return keys::a;
  case kVK_ANSI_B:                return keys::b;
  case kVK_ANSI_C:                return keys::c;
  case kVK_ANSI_D:                return keys::d;
  case kVK_ANSI_E:                return keys::e;
  case kVK_ANSI_F:                return keys::f;
  case kVK_ANSI_G:                return keys::g;
  case kVK_ANSI_H:                return keys::h;
  case kVK_ANSI_I:                return keys::i;
  case kVK_ANSI_J:                return keys::j;
  case kVK_ANSI_K:                return keys::k;
  case kVK_ANSI_L:                return keys::l;
  case kVK_ANSI_M:                return keys::m;
  case kVK_ANSI_N:                return keys::n;
  case kVK_ANSI_O:                return keys::o;
  case kVK_ANSI_P:                return keys::p;
  case kVK_ANSI_Q:                return keys::q;
  case kVK_ANSI_R:                return keys::r;
  case kVK_ANSI_S:                return keys::s;
  case kVK_ANSI_T:                return keys::t;
  case kVK_ANSI_U:                return keys::u;
  case kVK_ANSI_V:                return keys::v;
  case kVK_ANSI_W:                return keys::w;
  case kVK_ANSI_X:                return keys::x;
  case kVK_ANSI_Y:                return keys::y;
  case kVK_ANSI_Z:                return keys::z;
  case kVK_ANSI_LeftBracket:      return keys::bracket_l;
  case kVK_ANSI_RightBracket:     return keys::bracket_r;
  case kVK_ANSI_Backslash:        return keys::backslash;
  case kVK_ANSI_Semicolon:        return keys::semicolon;
  case kVK_ANSI_Quote:            return keys::quote;
  case kVK_ANSI_Comma:            return keys::comma;
  case kVK_ANSI_Period:           return keys::period;
  case kVK_ANSI_Slash:            return keys::slash;
  case kVK_ANSI_Keypad0:          return keys::num_zero;
  case kVK_ANSI_Keypad1:          return keys::num_one;
  case kVK_ANSI_Keypad2:          return keys::num_two;
  case kVK_ANSI_Keypad3:          return keys::num_three;
  case kVK_ANSI_Keypad4:          return keys::num_four;
  case kVK_ANSI_Keypad5:          return keys::num_five;
  case kVK_ANSI_Keypad6:          return keys::num_six;
  case kVK_ANSI_Keypad7:          return keys::num_seven;
  case kVK_ANSI_Keypad8:          return keys::num_eight;
  case kVK_ANSI_Keypad9:          return keys::num_nine;
  case kVK_ANSI_KeypadPlus:       return keys::num_add;
  case kVK_ANSI_KeypadMinus:      return keys::num_minus;
  case kVK_ANSI_KeypadMultiply:   return keys::num_mult;
  case kVK_ANSI_KeypadDivide:     return keys::num_div;
  case kVK_ANSI_KeypadDecimal:    return keys::num_dec;
  default:                        return keys::none;
  }
}

} // namespace glug
