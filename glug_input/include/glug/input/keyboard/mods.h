#ifndef GLUG_MODS_H
#define GLUG_MODS_H

enum key_mods
{
    glug_km_none,
    glug_km_shift   = 1 << 0,
    glug_km_alt     = 1 << 1,
    glug_km_ctrl    = 1 << 2,
    glug_km_super   = 1 << 3,
    glug_km_unknown = 1 << 4
};

#endif // GLUG_MODS_H
