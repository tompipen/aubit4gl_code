/*
@(#)File:            $RCSfile: esqlmain.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Convert ESQL/C Keywords to upper case
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1987,1990-93,1996,1998
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/* -- Include Files -- */

#include <stdio.h>
#include "stderr.h"
#include "getopt.h"
#include "sqlfmt.h"
#include "filter.h"

/* -- Declarations -- */

char          **kw_table;
int             kw_size;
int             kflag = PLAIN_CASE;		/* Print keywords as supplied */
int             wflag = PLAIN_CASE;		/* Print words (non-keywords) ditto */

extern char *esql_tab[];
extern int   esql_size;

#ifndef lint
static const char sccs[] = "@(#)$Id: esqlmain.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

int main(int argc, char **argv)
{
	int             i;
	int             arg;
	char           *file = (char *)0;
	int             pflag = 0;

	setarg0(argv[0]);

	while ((arg = getopt(argc, argv, "LUVlpuf:")) != EOF)
	{
		switch (arg)
		{
		case 'L':		/* Print keywords in lower case */
			kflag = LOWER_CASE;
			break;
		case 'U':		/* Print keywords in upper case */
			kflag = UPPER_CASE;
			break;
		case 'l':		/* Print words (non-keywords) in lower case */
			wflag = LOWER_CASE;
			break;
		case 'u':		/* Print words (non-keywords) in upper case */
			wflag = UPPER_CASE;
			break;
		case 'p':
			pflag = 1;
			break;
		case 'f':
			file = optarg;
			break;
		case 'V':
			puts(&"@(#)SQLFMT Version 14 (1998-11-04)"[4]);
			version("", "$Revision: 1.1 $ ($Date: 2002-11-28 06:40:47 $)");
			exit(0);
			/* NOTREACHED */
		default:
			usage("[-LUVlpu] [-f keywordfile] [file ...]");
			break;
		}
	}

	/* Set up appropriate set of keywords */
	if (file)
		install(file);
	else
	{
		kw_table = esql_tab;
		kw_size = esql_size;
	}

	if (pflag)
	{
		for (i = 0; i < kw_size; i++)
			printf("%s\n", kw_table[i]);
	}
	else
	{
		filter(argc, argv, optind, esqlfmt);
	}

	return(0);
}
