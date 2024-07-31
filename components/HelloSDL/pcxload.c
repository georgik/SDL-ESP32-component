/* 
 * OpenTyrian: A modern cross-platform port of Tyrian
 * Copyright (C) 2007-2009  The OpenTyrian Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "file.h"
#include "hello.h"
#include "palette.h"
#include "pcxload.h"
#include "video.h"

void JE_loadPCX(const char *file) // this is only meant to load tshp2.pcx
{
    Uint8 *s = (Uint8 *)VGAScreen->pixels; /* 8-bit specific */
    
    FILE *f = dir_fopen_die(data_dir(), file, "rb");
    
    efseek(f, -769, SEEK_END);

    if (efgetc(f) == 12)
    {
        for (int i = 0; i < 256; i++)
        {
            efread(&colors[i].r, 1, 1, f);
            efread(&colors[i].g, 1, 1, f);
            efread(&colors[i].b, 1, 1, f);
        }

        // Set the palette after loading it
        set_palette(colors, 0, 255);
    } 
    
    efseek(f, 128, SEEK_SET);
    
    for (int i = 0; i < 320 * 240; )
    {
        Uint8 p = efgetc(f);
        if ((p & 0xc0) == 0xc0)
        {
            int count = (p & 0x3f);
            i += count;
            memset(s, efgetc(f), count);
            s += count;
        } else {
            i++;
            *s = p;
            s++;
        }
        if (i && (i % 320 == 0))
        {
            s += VGAScreen->pitch - 320;
        }
    }
    
    efclose(f);
}
