/*
@(#)File:            $RCSfile: filter.h,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2003-05-12 14:24:42 $
@(#)Purpose:         Header for filter functions
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1993,1996-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
  
#ifndef FILTER_H
#define FILTER_H
  
#ifdef MAIN_PROGRAM
#ifndef lint
static const char filter_h[] =
  "@(#)$Id: filter.h,v 1.2 2003-05-12 14:24:42 mikeaubury Exp $";

#endif	/* lint */
#endif	/* MAIN_PROGRAM */
  
#include <stdio.h>
typedef void (*Filter) (FILE * fp, char *fn);
extern void filter_setcontinue (void);
extern void filter (int argc, char **argv, int optnum, Filter function);

/* Backwards compatability */ 
#ifdef USE_FFILTER
extern void ffilter (int argc, char **argv, Filter function);

#else	/*  */
#define ffilter(argc, argv, function)	filter(argc, argv, 1, function)
#endif	/*  */
  
#endif	/* FILTER_H */
