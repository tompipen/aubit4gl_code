/*
	@(#)$Id: sqlfmt.h,v 1.1 2002-11-28 06:40:47 afalout Exp $

	Include file for sqlfmt
	J Leffler
*/

#ifndef SQLFMT_H
#define SQLFMT_H

#define PLAIN_CASE	0
#define UPPER_CASE	1
#define LOWER_CASE	2

extern char   **kw_table;	/* Keyword table */
extern int      kw_size;	/* Number of entries in keyword table */
extern int      wflag;		/* Case handling flag: Words (non-keywords) */
extern int      kflag;		/* Case handling flag: Keywords */

#include <stdio.h>

extern void install(char *file);
extern void fglxref(FILE *fp, char *fn);
extern void dokeyword(const char *s, int l);
extern int compare(const void *item, const void *entry);
extern void esqlfmt(FILE *fp, char *fn);
extern void sqlfmt(FILE *fp, char *fn);

#endif /* SQLFMT_H */
