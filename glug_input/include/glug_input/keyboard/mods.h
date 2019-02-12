#ifndef GLUG_MODS_H
#define GLUG_MODS_H

enum mods
{
    glug_mod_none,
    glug_mod_shift   = 1 << 0,
    glug_mod_alt     = 1 << 1,
    glug_mod_ctrl    = 1 << 2,
    glug_mod_super   = 1 << 3,
    glug_mod_unknown = 1 << 4
};

#endif // GLUG_MODS_H
