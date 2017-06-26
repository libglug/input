#include "../key_util.hpp"
#include "key_defs.hpp"
#include <glug_input/keyboard/keys.hpp>

namespace glug
{

int key_util::code_from_key(keys key)
{
  switch (key)
  {
  case keys::shift_l:      return VK_LSHIFT;
  case keys::shift_r:      return VK_RSHIFT;
  case keys::alt_l:        return VK_LMENU;
  case keys::alt_r:        return VK_RMENU;
  case keys::ctrl_l:       return VK_LCONTROL;
  case keys::ctrl_r:       return VK_RCONTROL;
  case keys::super_l:      return VK_LWIN;
  case keys::super_r:      return VK_RWIN;
  case keys::escape:       return VK_ESCAPE;
  case keys::insert:       return VK_INSERT;
  case keys::home:         return VK_HOME;
  case keys::end:          return VK_END;
  case keys::pageup:       return VK_PRIOR;
  case keys::pagedown:     return VK_NEXT;
  case keys::print:        return VK_SNAPSHOT;
  case keys::pause:        return VK_PAUSE;
  case keys::backspace:    return VK_BACK;
  case keys::del:          return VK_DELETE;
  case keys::tab:          return VK_TAB;
  case keys::enter:        return VK_RETURN;
  case keys::menu:         return VK_APPS;
  case keys::space:        return VK_SPACE;
  case keys::up:           return VK_UP;
  case keys::down:         return VK_DOWN;
  case keys::left:         return VK_LEFT;
  case keys::right:        return VK_RIGHT;
  case keys::f1:           return VK_F1;
  case keys::f2:           return VK_F2;
  case keys::f3:           return VK_F3;
  case keys::f4:           return VK_F4;
  case keys::f5:           return VK_F5;
  case keys::f6:           return VK_F6;
  case keys::f7:           return VK_F7;
  case keys::f8:           return VK_F8;
  case keys::f9:           return VK_F9;
  case keys::f10:          return VK_F10;
  case keys::f11:          return VK_F11;
  case keys::f12:          return VK_F12;
  case keys::tilde:        return gVK_TILDE;
  case keys::one:          return gVK_ONE;
  case keys::two:          return gVK_TWO;
  case keys::three:        return gVK_THREE;
  case keys::four:         return gVK_FOUR;
  case keys::five:         return gVK_FIVE;
  case keys::six:          return gVK_SIX;
  case keys::seven:        return gVK_SEVEN;
  case keys::eight:        return gVK_EIGHT;
  case keys::nine:         return gVK_NINE;
  case keys::zero:         return gVK_ZERO;
  case keys::minus:        return VK_OEM_MINUS;
  case keys::equal:        return VK_OEM_PLUS;
  case keys::a:            return gVK_A;
  case keys::b:            return gVK_B;
  case keys::c:            return gVK_C;
  case keys::d:            return gVK_D;
  case keys::e:            return gVK_E;
  case keys::f:            return gVK_F;
  case keys::g:            return gVK_G;
  case keys::h:            return gVK_H;
  case keys::i:            return gVK_I;
  case keys::j:            return gVK_J;
  case keys::k:            return gVK_K;
  case keys::l:            return gVK_L;
  case keys::m:            return gVK_M;
  case keys::n:            return gVK_N;
  case keys::o:            return gVK_O;
  case keys::p:            return gVK_P;
  case keys::q:            return gVK_Q;
  case keys::r:            return gVK_R;
  case keys::s:            return gVK_S;
  case keys::t:            return gVK_T;
  case keys::u:            return gVK_U;
  case keys::v:            return gVK_V;
  case keys::w:            return gVK_W;
  case keys::x:            return gVK_X;
  case keys::y:            return gVK_Y;
  case keys::z:            return gVK_Z;
  case keys::bracket_l:    return gVK_LBRACKET;
  case keys::bracket_r:    return gVK_RBRACKET;
  case keys::backslash:    return gVK_BACKSLASH;
  case keys::semicolon:    return gVK_SEMICOLON;
  case keys::quote:        return gVK_QUOTE;
  case keys::comma:        return VK_OEM_COMMA;
  case keys::period:       return VK_OEM_PERIOD;
  case keys::slash:        return gVK_SLASH;
  case keys::num_zero:     return VK_NUMPAD0;
  case keys::num_one:      return VK_NUMPAD1;
  case keys::num_two:      return VK_NUMPAD2;
  case keys::num_three:    return VK_NUMPAD3;
  case keys::num_four:     return VK_NUMPAD4;
  case keys::num_five:     return VK_NUMPAD5;
  case keys::num_six:      return VK_NUMPAD6;
  case keys::num_seven:    return VK_NUMPAD7;
  case keys::num_eight:    return VK_NUMPAD8;
  case keys::num_nine:     return VK_NUMPAD9;
  case keys::num_add:      return VK_ADD;
  case keys::num_minus:    return VK_SUBTRACT;
  case keys::num_mult:     return VK_MULTIPLY;
  case keys::num_div:      return VK_DIVIDE;
  case keys::num_dec:      return VK_DECIMAL;
  case keys::none:         //fall-through
  case keys::unknown:      break;
  }

  return 0;
}

keys key_util::key_from_code(int key_code)
{
  switch (key_code)
  {
  case VK_LSHIFT:       return keys::shift_l;
  case VK_RSHIFT:       return keys::shift_r;
  case VK_LMENU:        return keys::alt_l;
  case VK_RMENU:        return keys::alt_r;
  case VK_LCONTROL:     return keys::ctrl_l;
  case VK_RCONTROL:     return keys::ctrl_r;
  case VK_LWIN:         return keys::super_l;
  case VK_RWIN:         return keys::super_r;
  case VK_ESCAPE:       return keys::escape;
  case VK_INSERT:       return keys::insert;
  case VK_HOME:         return keys::home;
  case VK_END:          return keys::end;
  case VK_PRIOR:        return keys::pageup;
  case VK_NEXT:         return keys::pagedown;
  case VK_SNAPSHOT:     return keys::print;
  case VK_PAUSE:        return keys::pause;
  case VK_BACK:         return keys::backspace;
  case VK_DELETE:       return keys::del;
  case VK_TAB:          return keys::tab;
  case VK_RETURN:       return keys::enter;
  case VK_APPS:         return keys::menu;
  case VK_SPACE:        return keys::space;
  case VK_UP:           return keys::up;
  case VK_DOWN:         return keys::down;
  case VK_LEFT:         return keys::left;
  case VK_RIGHT:        return keys::right;
  case VK_F1:           return keys::f1;
  case VK_F2:           return keys::f2;
  case VK_F3:           return keys::f3;
  case VK_F4:           return keys::f4;
  case VK_F5:           return keys::f5;
  case VK_F6:           return keys::f6;
  case VK_F7:           return keys::f7;
  case VK_F8:           return keys::f8;
  case VK_F9:           return keys::f9;
  case VK_F10:          return keys::f10;
  case VK_F11:          return keys::f11;
  case VK_F12:          return keys::f12;
  case gVK_TILDE:       return keys::tilde;
  case gVK_ONE:         return keys::one;
  case gVK_TWO:         return keys::two;
  case gVK_THREE:       return keys::three;
  case gVK_FOUR:        return keys::four;
  case gVK_FIVE:        return keys::five;
  case gVK_SIX:         return keys::six;
  case gVK_SEVEN:       return keys::seven;
  case gVK_EIGHT:       return keys::eight;
  case gVK_NINE:        return keys::nine;
  case gVK_ZERO:        return keys::zero;
  case VK_OEM_MINUS:    return keys::minus;
  case VK_OEM_PLUS:     return keys::equal;
  case gVK_A:           return keys::a;
  case gVK_B:           return keys::b;
  case gVK_C:           return keys::c;
  case gVK_D:           return keys::d;
  case gVK_E:           return keys::e;
  case gVK_F:           return keys::f;
  case gVK_G:           return keys::g;
  case gVK_H:           return keys::h;
  case gVK_I:           return keys::i;
  case gVK_J:           return keys::j;
  case gVK_K:           return keys::k;
  case gVK_L:           return keys::l;
  case gVK_M:           return keys::m;
  case gVK_N:           return keys::n;
  case gVK_O:           return keys::o;
  case gVK_P:           return keys::p;
  case gVK_Q:           return keys::q;
  case gVK_R:           return keys::r;
  case gVK_S:           return keys::s;
  case gVK_T:           return keys::t;
  case gVK_U:           return keys::u;
  case gVK_V:           return keys::v;
  case gVK_W:           return keys::w;
  case gVK_X:           return keys::x;
  case gVK_Y:           return keys::y;
  case gVK_Z:           return keys::z;
  case gVK_LBRACKET:    return keys::bracket_l;
  case gVK_RBRACKET:    return keys::bracket_r;
  case gVK_BACKSLASH:   return keys::backslash;
  case gVK_SEMICOLON:   return keys::semicolon;
  case gVK_QUOTE:       return keys::quote;
  case VK_OEM_COMMA:    return keys::comma;
  case VK_OEM_PERIOD:   return keys::period;
  case gVK_SLASH:       return keys::slash;
  case VK_NUMPAD0:      return keys::num_zero;
  case VK_NUMPAD1:      return keys::num_one;
  case VK_NUMPAD2:      return keys::num_two;
  case VK_NUMPAD3:      return keys::num_three;
  case VK_NUMPAD4:      return keys::num_four;
  case VK_NUMPAD5:      return keys::num_five;
  case VK_NUMPAD6:      return keys::num_six;
  case VK_NUMPAD7:      return keys::num_seven;
  case VK_NUMPAD8:      return keys::num_eight;
  case VK_NUMPAD9:      return keys::num_nine;
  case VK_ADD:          return keys::num_add;
  case VK_SUBTRACT:     return keys::num_minus;
  case VK_MULTIPLY:     return keys::num_mult;
  case VK_DIVIDE:       return keys::num_div;
  case VK_DECIMAL:      return keys::num_dec;
  default:              return keys::none;
  }
}


} // namespace glug
