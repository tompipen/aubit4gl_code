/*
@(#)File:            $RCSfile: filter.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Standard File Filter
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1987-89,1991,1993,1996-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stderr.h"
#include "filter.h"

static int continue_mode = 0;

#ifndef lint
static const char rcs[] = "@(#)$Id: filter.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

/* Set program to continue with next file after a file-open error */
void filter_setcontinue(void)
{
	continue_mode = 1;
}

/*
    Purpose:    Standard File Filter

    Maintenance Log
    ---------------
    09/03/87  JL    Original version stabilised
    18/04/88  JL    Now pass fp and file name to function
    15/12/91  JL    Upgrade for ANSI C
    29/06/93  JL    Rename to filter and accept optind argument
    15/10/96  JL    Remove non-ANSI support and ffilter(); rename file
	31/03/98  JL    Add support for continuing on error opening a file

    Arguments
    ---------
    argc            In: Number of arguments
    argv            In: Argument list of program
    optind          In: Offset in list to start at
    function        In: Function to process file

    Comments
    --------
    1.  For every non-flag option in the argument list, or standard input
        if there are no non-flag arguments, run 'function' on file.
    2.  If a file name is '-', use standard input.
    3.  The optnum argument should normally be the value of optind as
        supplied by getopt(3).  But it should be the index of the first
        non-flag argument.

*/

void            filter(int argc, char **argv, int optnum, Filter function)
{
	int             i;
	FILE           *fp;
	char           *file;

	if (argc <= optnum)
	{
		/* Assumes argv[argc] == NIL(char *) and can be assigned to */
		argv[argc] = "-";
		argc++;
	}

	for (i = optnum; i < argc; i++)
	{
		if (strcmp(argv[i], "-") == 0)
		{
			file = "(standard input)";
			(*function)(stdin, file);
		}
		else if ((fp = fopen(argv[i], "r")) != NULL)
		{
			file = argv[i];
			(*function)(fp, file);
			fclose(fp);
		}
		else if (continue_mode)
			err_remark("failed to open file %s (%s)\n", argv[i], strerror(errno));
		else
			error2("failed to open file", argv[i]);
	}
}

#ifdef TEST

/*
** Test program -- equivalent to: cat [-v] [file ...]
*/

#include <ctype.h>
#define GETOPT gnu_getopt
#include "getopt.h"

static void fcopy(FILE *f1, FILE *f2)
{
	char            buffer[BUFSIZ];
	int             n;

	while ((n = fread(buffer, sizeof(char), sizeof(buffer), f1)) > 0)
	{
		if (fwrite(buffer, sizeof(char), n, f2) != n)
			error("write failed");
	}
}

static void vis(FILE *fp, char *fn)
{
	int             c;

	fprintf(stdout, "%s:\n", fn);
	while ((c = getc(fp)) != EOF)
	{
		if (c == '\n' || c == '\t')
			putchar(c);
		else if (c > 127 || !isprint(c))
			printf("\\%03o", c);
		else
			putchar(c);
	}
}

static void cat(FILE *fp, char *fn)
{
	fprintf(stdout, "%s:\n", fn);
	fcopy(fp, stdout);
}

int             main(int argc, char **argv)
{
	int             opt;
	Filter          f = cat;

	setarg0(argv[0]);
	opterr = 0;
	while ((opt = GETOPT(argc, argv, "cv")) != EOF)
	{
		if (opt == 'c')
			filter_setcontinue();
		else if (opt == 'v')
			f = vis;
		else
			usage("[-v] [file ...]");
	}
	filter(argc, argv, optind, f);
	return(0);
}

#endif	/* TEST */
