/*
@(#)File:            $RCSfile: jlss.h,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2003-05-12 14:24:42 $
@(#)Purpose:         JLSS Library Functions
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1997-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
  
#ifndef JLSS_H
#define JLSS_H
  
#ifdef MAIN_PROGRAM
#ifndef lint
static const char jlss_h[] =
  "@(#)$Id: jlss.h,v 1.2 2003-05-12 14:24:42 mikeaubury Exp $";

#endif	/* lint */
#endif	/* MAIN_PROGRAM */
  
#include <stdio.h>
extern FILE *efopen (const char *name, const char *mode);
extern char *vstrcpy (char *s1, int n, ...);
extern const char *cistrstr (const char *s1, const char *s2);
extern int cistrcmp (const char *s1, const char *s2);
extern int tokenise (char *str, char *sep, char **token, int maxtok,
		      int nulls);
extern void fcopy (FILE * f1, FILE * f2);
extern void image_print (FILE * fp, long offset, const char *buffer,
			  long nbytes);

/* strncpy() except for argument order and guaranteed null terminated */ 
extern void nstrcpy (char *dst, size_t sz, const char *src);

/* Case-convert strings in situ.  Return pointer to terminal null character */ 
extern char *strupper (char *s);
extern char *strlower (char *s);

#endif	/* JLSS_H */
