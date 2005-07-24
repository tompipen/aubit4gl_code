/*
@(#)File:            $RCSfile: decsci.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 04:05:07 $
@(#)Purpose:         Functions to format DECIMAL values properly
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1996
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#ifndef DECSCI_H
#define DECSCI_H

#ifdef MAIN_PROGRAM
#ifndef lint
static const char decsci_h[] = "@(#)$Id: decsci.h,v 1.1 2002-06-20 04:05:07 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

#include "decimal.h"

/* NB: these routines are not thread-safe and share common return storage */
extern char *decfix(dec_t *d, int ndigit, int plus);
extern char *decsci(dec_t *d, int ndigit, int plus);
extern char *deceng(dec_t *d, int ndigit, int plus, int cw);

#endif	/* DECSCI_H */
