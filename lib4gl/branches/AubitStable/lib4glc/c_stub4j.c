/********************************************************************
 * Copyright (C) 1992-1998 Sanderson Australia Pty. Limited         *
 * All rights reserved.                                             *
 * Use, modification, duplication, and/or distribution of this      *
 * software is limited by the software license agreement.           *
 * Sccsid: %Z% %M%%Y% %Q%%I% %E%                                    *
 ********************************************************************/

/* Stubs for FourJays functions - link ONLY to informix runners */

# include	"cfun4gl.h"


function(fgl_init4js,0,0,1,0)
    RUNNER(fgiusr)
{
    return 0;

}   /* fgl_init4js */
/*JFACE*/ int fgl_init4js_0(int nargs) { return fgl_init4js(nargs); }


function(fgl_fglgui,0,0,1,1)
    RUNNER(fgiusr)
{
    retint(0);
    return 1;

}   /* fgl_fglgui */
/*JFACE*/ int fgl_fglgui_0(int nargs) { return fgl_fglgui(nargs); }


function(fgl_keysetlabel,2,2,1,0)
    RUNNER(fgiusr)
{
    char buf[1];

    popstring(buf, sizeof(buf));
    popstring(buf, sizeof(buf));
    return 0;

}   /* fgl_keysetlabel */
/*JFACE*/ int fgl_keysetlabel_2(int nargs) { return fgl_keysetlabel(nargs); }


function(fgl_settitle,1,1,1,0)
    RUNNER(fgiusr)
{
    char buf[1];

    popstring(buf, sizeof(buf));
    return 0;

}   /* fgl_settitle */
/*JFACE*/ int fgl_settitle_1(int nargs) { return fgl_settitle(nargs); }
