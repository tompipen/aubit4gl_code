/******************************************************************************\
 C functions to be included in runner.

 Copyright (C) 2001 John H. Frantz, Pétur K. Hilmarsson.

 This file is part of Power-4gl.

 Power-4gl is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 Power-4gl is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Power-4gl; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\******************************************************************************/
#include "fgicfunc.h"

int format();
int gettx();
int cpower();
int cputime();
int processid();
int userid();
int rnd_pass();
int fgl_clrmsg();
int fgl_prtscr();
int fgl_fopen();
int fgl_fgets();
int fgl_fputs();
int fgl_fputl();
int fgl_fclose();
int fgl_maxints();
int fgl_recdiff();
int fgl_recswap();
int fgl_strrep();
int fgl_strpos();
cfunc_t usrcfuncs[] = 
    {
    "format",format,-21,
    "gettx",gettx,2,
    "cpower",cpower,2,
    "cputime",cputime,0,
    "processid",processid,0,
    "userid",userid,0,
    "rnd_pass",rnd_pass,0,
    "fgl_clrmsg",fgl_clrmsg,0,
    "fgl_prtscr",fgl_prtscr,-3,
    "fgl_fopen",fgl_fopen,2,
    "fgl_fgets",fgl_fgets,1,
    "fgl_fputs",fgl_fputs,3,
    "fgl_fputl",fgl_fputl,2,
    "fgl_fclose",fgl_fclose,1,
    "fgl_maxints",fgl_maxints,-99,
    "fgl_recdiff",fgl_recdiff,-98,
    "fgl_recdiff1",fgl_recdiff,-98,
    "fgl_recdiff2",fgl_recdiff,-98,
    "fgl_recdiff3",fgl_recdiff,-98,
    "fgl_recdiff4",fgl_recdiff,-98,
    "fgl_recdiff5",fgl_recdiff,-98,
    "fgl_recdiff6",fgl_recdiff,-98,
    "fgl_recdiff7",fgl_recdiff,-98,
    "fgl_recdiff8",fgl_recdiff,-98,
    "fgl_recdiff9",fgl_recdiff,-98,
    "fgl_recswap",fgl_recswap,-98,
    "fgl_recswap1",fgl_recswap,-98,
    "fgl_recswap2",fgl_recswap,-98,
    "fgl_recswap3",fgl_recswap,-98,
    "fgl_recswap4",fgl_recswap,-98,
    "fgl_recswap5",fgl_recswap,-98,
    "fgl_recswap6",fgl_recswap,-98,
    "fgl_recswap7",fgl_recswap,-98,
    "fgl_recswap8",fgl_recswap,-98,
    "fgl_recswap9",fgl_recswap,-98,
    "fgl_strrep",fgl_strrep,-98,
    "fgl_strpos",fgl_strpos,-98,
    0, 0, 0
    };
