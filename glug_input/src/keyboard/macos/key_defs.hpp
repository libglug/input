#ifndef GLUG_MACOS_KEY_DEFS_HPP
#define GLUG_MACOS_KEY_DEFS_HPP

#include <HIToolbox.framework/Headers/Events.h>

#define gVK_LeftShift    NX_DEVICELSHIFTKEYMASK
#define gVK_RightShift   NX_DEVICERSHIFTKEYMASK
#define gVK_LeftOption   NX_DEVICELALTKEYMASK
#define gVK_RightOption  NX_DEVICERALTKEYMASK
#define gVK_LeftControl  NX_DEVICELCTLKEYMASK
#define gVK_RightControl NX_DEVICERCTLKEYMASK
#define gVK_LeftCommand  NX_DEVICELCMDKEYMASK
#define gVK_RightCommand NX_DEVICERCMDKEYMASK

#define gMask_LeftShift    (gVK_LeftShift    | kCGEventFlagMaskShift)
#define gMask_RightShift   (gVK_RightShift   | kCGEventFlagMaskShift)
#define gMask_LeftOption   (gVK_LeftOption   | kCGEventFlagMaskAlternate)
#define gMask_RightOption  (gVK_RightOption  | kCGEventFlagMaskAlternate)
#define gMask_LeftControl  (gVK_LeftControl  | kCGEventFlagMaskControl)
#define gMask_RightControl (gVK_RightControl | kCGEventFlagMaskControl)
#define gMask_LeftCommand  (gVK_LeftCommand  | kCGEventFlagMaskCommand)
#define gMask_RightCommand (gVK_RightCommand | kCGEventFlagMaskCommand)

#endif // GLUG_MACOS_KEY_DEFS_HPP
