/*
@(#)File:            $RCSfile: getopt.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Declarations for GETOPT(3) and GETSUBOPT(3)
@(#)Author:          J Leffler
@(#)Copyright:       JLSS (C) 1992-93,1996-97
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

#ifndef GETOPT_H
#define GETOPT_H

#ifdef MAIN_PROGRAM
#ifndef lint
static const char getopt_h[] = "@(#)$Id: getopt.h,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

/*
** GNU getopt provides facilities not available in standard getopt.
** Specifically, it will reorder all option arguments before all non-option
** arguments unless the environment variable _POSIX_OPTION_ORDER is
** defined.  It can also handle optional arguments, which must be attached
** to option letter on the command line, indicated by two colons after the
** option letter.  It can be told to return all arguments in order, with a
** value of '\0' indicating a file option by starting the options string
** with a '-'.  It also has a different interface from standard getopt
** because the second (argv) argument is not const.
*/

#ifdef USE_GNU_GETOPT
#define GETOPT(argc, argv, opts)	gnu_getopt(argc, argv, opts)
#define opterr	gnu_opterr
#define optind	gnu_optind
#define optarg	gnu_optarg
#define optopt	gnu_optopt
#else
#define GETOPT(argc, argv, opts)	getopt(argc, argv, opts)
#endif /* USE_GNU_GETOPT */

extern int      optopt;
extern int      opterr;
extern int      optind;
extern char    *optarg;

extern int      getopt(int argc, char *const*argv, const char *opts);
extern int      getsubopt(char **opt, char *const*names, char **value);
extern int      gnu_getopt(int argc, char **argv, const char *opts);

#endif	/* GETOPT_H */
