/*
@(#)File:            $RCSfile: fglext.c,v $
@(#)Version:         $Revision: 1.1.1.1 $
@(#)Last changed:    $Date: 2001-08-20 02:37:08 $
@(#)Purpose:         Dynamic 4GL P-code extensions file for D4GL program
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1998
@(#)Product:         $Product: INFORMIX D4GL Programmer's Environment Version 2.00.UC2 (1998-07-31) $
*/

/*TABSTOP=4*/

#include <f2c/fglExt.h>

extern int file_access(int);

#ifndef lint
static const char rcs[] = "@(#)$Id: fglext.c,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $";
#endif

UsrData usrData[]={
  { 0, 0 }
};

UsrFunction usrFunctions[]={
  { "file_access", file_access, 2, 1 },
  { 0,0,0,0 }
};
