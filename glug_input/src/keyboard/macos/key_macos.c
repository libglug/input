#include "../key_util.h"
#include "key_defs.h"
#include <glug/input/keyboard/keys.h>

int code_from_key(enum virtual_keys key)
{
    switch (key)
    {
    case glug_vk_shift_l:           return gVK_LeftShift;
    case glug_vk_shift_r:           return gVK_RightShift;
    case glug_vk_alt_l:             return gVK_LeftOption;
    case glug_vk_alt_r:             return gVK_RightOption;
    case glug_vk_ctrl_l:            return gVK_LeftControl;
    case glug_vk_ctrl_r:            return gVK_RightControl;
    case glug_vk_super_l:           return gVK_LeftCommand;
    case glug_vk_super_r:           return gVK_RightCommand;
    case glug_vk_escape:            return kVK_Escape;
    case glug_vk_insert:            return kVK_Help;
    case glug_vk_home:              return kVK_Home;
    case glug_vk_end:               return kVK_End;
    case glug_vk_pageup:            return kVK_PageUp;
    case glug_vk_pagedown:          return kVK_PageDown;
//    case glug_vk_print:             return ??;
//    case glug_vk_pause:             return ??;
    case glug_vk_backspace:         return kVK_Delete;
    case glug_vk_del:               return kVK_ForwardDelete;
    case glug_vk_tab:               return kVK_Tab;
    case glug_vk_enter:             return kVK_Return;
//    case glug_vk_menu:              return ??;
    case glug_vk_space:             return kVK_Space;
    case glug_vk_up:                return kVK_UpArrow;
    case glug_vk_down:              return kVK_DownArrow;
    case glug_vk_left:              return kVK_LeftArrow;
    case glug_vk_right:             return kVK_RightArrow;
    case glug_vk_f1:                return kVK_F1;
    case glug_vk_f2:                return kVK_F2;
    case glug_vk_f3:                return kVK_F3;
    case glug_vk_f4:                return kVK_F4;
    case glug_vk_f5:                return kVK_F5;
    case glug_vk_f6:                return kVK_F6;
    case glug_vk_f7:                return kVK_F7;
    case glug_vk_f8:                return kVK_F8;
    case glug_vk_f9:                return kVK_F9;
    case glug_vk_f10:               return kVK_F10;
    case glug_vk_f11:               return kVK_F11;
    case glug_vk_f12:               return kVK_F12;
    case glug_vk_tilde:             return kVK_ANSI_Grave;
    case glug_vk_one:               return kVK_ANSI_1;
    case glug_vk_two:               return kVK_ANSI_2;
    case glug_vk_three:             return kVK_ANSI_3;
    case glug_vk_four:              return kVK_ANSI_4;
    case glug_vk_five:              return kVK_ANSI_5;
    case glug_vk_six:               return kVK_ANSI_6;
    case glug_vk_seven:             return kVK_ANSI_7;
    case glug_vk_eight:             return kVK_ANSI_8;
    case glug_vk_nine:              return kVK_ANSI_9;
    case glug_vk_zero:              return kVK_ANSI_0;
    case glug_vk_minus:             return kVK_ANSI_Minus;
    case glug_vk_equal:             return kVK_ANSI_Equal;
    case glug_vk_a:                 return kVK_ANSI_A;
    case glug_vk_b:                 return kVK_ANSI_B;
    case glug_vk_c:                 return kVK_ANSI_C;
    case glug_vk_d:                 return kVK_ANSI_D;
    case glug_vk_e:                 return kVK_ANSI_E;
    case glug_vk_f:                 return kVK_ANSI_F;
    case glug_vk_g:                 return kVK_ANSI_G;
    case glug_vk_h:                 return kVK_ANSI_H;
    case glug_vk_i:                 return kVK_ANSI_I;
    case glug_vk_j:                 return kVK_ANSI_J;
    case glug_vk_k:                 return kVK_ANSI_K;
    case glug_vk_l:                 return kVK_ANSI_L;
    case glug_vk_m:                 return kVK_ANSI_M;
    case glug_vk_n:                 return kVK_ANSI_N;
    case glug_vk_o:                 return kVK_ANSI_O;
    case glug_vk_p:                 return kVK_ANSI_P;
    case glug_vk_q:                 return kVK_ANSI_Q;
    case glug_vk_r:                 return kVK_ANSI_R;
    case glug_vk_s:                 return kVK_ANSI_S;
    case glug_vk_t:                 return kVK_ANSI_T;
    case glug_vk_u:                 return kVK_ANSI_U;
    case glug_vk_v:                 return kVK_ANSI_V;
    case glug_vk_w:                 return kVK_ANSI_W;
    case glug_vk_x:                 return kVK_ANSI_X;
    case glug_vk_y:                 return kVK_ANSI_Y;
    case glug_vk_z:                 return kVK_ANSI_Z;
    case glug_vk_bracket_l:         return kVK_ANSI_LeftBracket;
    case glug_vk_bracket_r:         return kVK_ANSI_RightBracket;
    case glug_vk_backslash:         return kVK_ANSI_Backslash;
    case glug_vk_semicolon:         return kVK_ANSI_Semicolon;
    case glug_vk_quote:             return kVK_ANSI_Quote;
    case glug_vk_comma:             return kVK_ANSI_Comma;
    case glug_vk_period:            return kVK_ANSI_Period;
    case glug_vk_slash:             return kVK_ANSI_Slash;
    case glug_vk_num_zero:          return kVK_ANSI_Keypad0;
    case glug_vk_num_one:           return kVK_ANSI_Keypad1;
    case glug_vk_num_two:           return kVK_ANSI_Keypad2;
    case glug_vk_num_three:         return kVK_ANSI_Keypad3;
    case glug_vk_num_four:          return kVK_ANSI_Keypad4;
    case glug_vk_num_five:          return kVK_ANSI_Keypad5;
    case glug_vk_num_six:           return kVK_ANSI_Keypad6;
    case glug_vk_num_seven:         return kVK_ANSI_Keypad7;
    case glug_vk_num_eight:         return kVK_ANSI_Keypad8;
    case glug_vk_num_nine:          return kVK_ANSI_Keypad9;
    case glug_vk_num_add:           return kVK_ANSI_KeypadPlus;
    case glug_vk_num_minus:         return kVK_ANSI_KeypadMinus;
    case glug_vk_num_mult:          return kVK_ANSI_KeypadMultiply;
    case glug_vk_num_div:           return kVK_ANSI_KeypadDivide;
    case glug_vk_num_dec:           return kVK_ANSI_KeypadDecimal;
    case glug_vk_none:              // fall-through
    case glug_vk_unknown:           break;
    }

    return 0;
}

enum virtual_keys glug_vk_from_code(int key)
{
    switch (key)
    {
    case gMask_LeftShift:           return glug_vk_shift_l;
    case gMask_RightShift:          return glug_vk_shift_r;
    case gMask_LeftOption:          return glug_vk_alt_l;
    case gMask_RightOption:         return glug_vk_alt_r;
    case gMask_LeftControl:         return glug_vk_ctrl_l;
    case gMask_RightControl:        return glug_vk_ctrl_r;
    case gMask_LeftCommand:         return glug_vk_super_l;
    case gMask_RightCommand:        return glug_vk_super_r;
    case kVK_Escape:                return glug_vk_escape;
    case kVK_Help:                  return glug_vk_insert;
    case kVK_Home:                  return glug_vk_home;
    case kVK_End:                   return glug_vk_end;
    case kVK_PageUp:                return glug_vk_pageup;
    case kVK_PageDown:              return glug_vk_pagedown;
//    case kVK_PrintScreen:           return glug_vk_print;
//    case VK_PAUSE:                  return glug_vk_pause;
    case kVK_Delete:                return glug_vk_backspace;
    case kVK_ForwardDelete:         return glug_vk_del;
    case kVK_Tab:                   return glug_vk_tab;
    case kVK_Return:                return glug_vk_enter;
//    case kVK_Menu:                  return glug_vk_menu;
    case kVK_Space:                 return glug_vk_space;
    case kVK_UpArrow:               return glug_vk_up;
    case kVK_DownArrow:             return glug_vk_down;
    case kVK_LeftArrow:             return glug_vk_left;
    case kVK_RightArrow:            return glug_vk_right;
    case kVK_F1:                    return glug_vk_f1;
    case kVK_F2:                    return glug_vk_f2;
    case kVK_F3:                    return glug_vk_f3;
    case kVK_F4:                    return glug_vk_f4;
    case kVK_F5:                    return glug_vk_f5;
    case kVK_F6:                    return glug_vk_f6;
    case kVK_F7:                    return glug_vk_f7;
    case kVK_F8:                    return glug_vk_f8;
    case kVK_F9:                    return glug_vk_f9;
    case kVK_F10:                   return glug_vk_f10;
    case kVK_F11:                   return glug_vk_f11;
    case kVK_F12:                   return glug_vk_f12;
    case kVK_ANSI_Grave:            return glug_vk_tilde;
    case kVK_ANSI_1:                return glug_vk_one;
    case kVK_ANSI_2:                return glug_vk_two;
    case kVK_ANSI_3:                return glug_vk_three;
    case kVK_ANSI_4:                return glug_vk_four;
    case kVK_ANSI_5:                return glug_vk_five;
    case kVK_ANSI_6:                return glug_vk_six;
    case kVK_ANSI_7:                return glug_vk_seven;
    case kVK_ANSI_8:                return glug_vk_eight;
    case kVK_ANSI_9:                return glug_vk_nine;
    case kVK_ANSI_0:                return glug_vk_zero;
    case kVK_ANSI_Minus:            return glug_vk_minus;
    case kVK_ANSI_Equal:            return glug_vk_equal;
    case kVK_ANSI_A:                return glug_vk_a;
    case kVK_ANSI_B:                return glug_vk_b;
    case kVK_ANSI_C:                return glug_vk_c;
    case kVK_ANSI_D:                return glug_vk_d;
    case kVK_ANSI_E:                return glug_vk_e;
    case kVK_ANSI_F:                return glug_vk_f;
    case kVK_ANSI_G:                return glug_vk_g;
    case kVK_ANSI_H:                return glug_vk_h;
    case kVK_ANSI_I:                return glug_vk_i;
    case kVK_ANSI_J:                return glug_vk_j;
    case kVK_ANSI_K:                return glug_vk_k;
    case kVK_ANSI_L:                return glug_vk_l;
    case kVK_ANSI_M:                return glug_vk_m;
    case kVK_ANSI_N:                return glug_vk_n;
    case kVK_ANSI_O:                return glug_vk_o;
    case kVK_ANSI_P:                return glug_vk_p;
    case kVK_ANSI_Q:                return glug_vk_q;
    case kVK_ANSI_R:                return glug_vk_r;
    case kVK_ANSI_S:                return glug_vk_s;
    case kVK_ANSI_T:                return glug_vk_t;
    case kVK_ANSI_U:                return glug_vk_u;
    case kVK_ANSI_V:                return glug_vk_v;
    case kVK_ANSI_W:                return glug_vk_w;
    case kVK_ANSI_X:                return glug_vk_x;
    case kVK_ANSI_Y:                return glug_vk_y;
    case kVK_ANSI_Z:                return glug_vk_z;
    case kVK_ANSI_LeftBracket:      return glug_vk_bracket_l;
    case kVK_ANSI_RightBracket:     return glug_vk_bracket_r;
    case kVK_ANSI_Backslash:        return glug_vk_backslash;
    case kVK_ANSI_Semicolon:        return glug_vk_semicolon;
    case kVK_ANSI_Quote:            return glug_vk_quote;
    case kVK_ANSI_Comma:            return glug_vk_comma;
    case kVK_ANSI_Period:           return glug_vk_period;
    case kVK_ANSI_Slash:            return glug_vk_slash;
    case kVK_ANSI_Keypad0:          return glug_vk_num_zero;
    case kVK_ANSI_Keypad1:          return glug_vk_num_one;
    case kVK_ANSI_Keypad2:          return glug_vk_num_two;
    case kVK_ANSI_Keypad3:          return glug_vk_num_three;
    case kVK_ANSI_Keypad4:          return glug_vk_num_four;
    case kVK_ANSI_Keypad5:          return glug_vk_num_five;
    case kVK_ANSI_Keypad6:          return glug_vk_num_six;
    case kVK_ANSI_Keypad7:          return glug_vk_num_seven;
    case kVK_ANSI_Keypad8:          return glug_vk_num_eight;
    case kVK_ANSI_Keypad9:          return glug_vk_num_nine;
    case kVK_ANSI_KeypadPlus:       return glug_vk_num_add;
    case kVK_ANSI_KeypadMinus:      return glug_vk_num_minus;
    case kVK_ANSI_KeypadMultiply:   return glug_vk_num_mult;
    case kVK_ANSI_KeypadDivide:     return glug_vk_num_div;
    case kVK_ANSI_KeypadDecimal:    return glug_vk_num_dec;
    default:                        return glug_vk_none;
    }
}
