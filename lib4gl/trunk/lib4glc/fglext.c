/**********************************************************************
 * Copyright (C) 1992-1998 Sanderson Australia Pty. Limited           *
 * All rights reserved.                                               *
 * Use, modification, duplication, and/or distribution of this        *
 * software is limited by the software license agreement.             *
 * Sccsid: %Z% %M%%Y% %Q%%I% %E%                                      *
 **********************************************************************/

# include	<f2c/fglExt.h>
# include	"fdecls.h"

char *cfgl_interpreter = "wacrun";

/* keep this array as the first, so that `make functions' works */
/* comments in this array must be single-liners, so the scripts work */

UsrFunction usrFunctions[] =
{
# include	"fglext.inc"

    { 0, 0, 0, 0 }
};


UsrData usrData[] =
{
  { 0, 0 }
};


/*
void popstring(char *buf, int len)
{
    popquote(buf, len);
    cfgl_trim(buf);
}
*/
