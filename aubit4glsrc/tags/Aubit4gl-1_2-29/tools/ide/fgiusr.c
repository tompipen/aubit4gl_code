/*
@(#)File:            $RCSfile: fgiusr.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2003-05-12 14:24:34 $
@(#)Purpose:         I4GL-RDS Function Definitions for D4GL Program
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1998
@(#)Product:         $Product: INFORMIX D4GL Programmer's Environment Version 2.00.UC2 (1998-07-31) $
*/

/*TABSTOP=4*/

#include "fgicfunc.h"

#ifndef lint
static const char rcs[] =
  "@(#)$Id: fgiusr.c,v 1.2 2003-05-12 14:24:34 mikeaubury Exp $";
#endif

extern int file_access (int);

cfunc_t usrcfuncs[] = {
  {"file_access", file_access, 2},
  {0, 0, 0}
};
