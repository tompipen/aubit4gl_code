/*
	@(#)$Id: dltest.c,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Test code to check functionality of D-lists
*/

#include <stdio.h>
#include "dlist.h"

#if !defined(NLIST)
#define NLIST	5
#endif

#if !defined(MAXNUM)
#define MAXNUM	200
#endif

#define AVGLENGTH	(MAXNUM/(2*NLIST))

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dltest.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

int	list[NLIST];
int	nlist;

main()
{
	int	i;

	for (i = 0; i < NLIST; i++)
	{
		nlist = i + 1;
		srand48(time((long *)0));
		one_iteration();
		fprintf(stderr, "Iteration no %d complete\n\n", i + 1);
	}

	fprintf(stderr, "Test complete\n");
	return(0);
}

one_iteration()
{
	fprintf(stderr, "Create lists\n");
	create_lists();

	fprintf(stderr, "\nPopulate lists\n");
	populate_lists();

	fprintf(stderr, "\nDump lists\n");
	dump_lists();

	fprintf(stderr, "\nDepopulate lists\n");
	part_empty();

	fprintf(stderr, "\nDump lists\n");
	dump_lists();

	fprintf(stderr, "\nSystematically empty lists\n");
	complete_empty();

	fprintf(stderr, "\nDump lists\n");
	dump_lists();

	fprintf(stderr, "\nPopulate lists again\n");
	populate_lists();

	fprintf(stderr, "\nDump lists\n");
	dump_lists();

	fprintf(stderr, "\nDestroy lists\n");
	destroy_lists();

#ifndef PARANOID
	fprintf(stderr, "\nDump lists\n");
	dump_lists();
#endif

#ifdef PARANOID_MALLOC
	dump_malloc();
#endif

}

dump_lists()
{
	int	i, j, k, l, n;
	char *s;

	for (i = 0; i < nlist; i++)
	{
		fprintf(stderr, "Dump of list number %d\n", list[i]);
		n = cnt_key(list[i]);
		fprintf(stderr, "Number of entries = %d\n", n);
		for (j = 1; j <= n; j++)
		{
			s = get_key(list[i], SC_ABSOLUTE, j);
			if (s == NIL(char *))
				fprintf(stderr, "NIL from get_key\n");
			if (sc_error < ENOLIST)
			{
				fprintf(stderr, "Failed to get row %d from list %d: status %d\n",
						j, i, sc_error);
				exit(1);
			}
			else
			{
				l = *(int *)s;
				fprintf(stderr, "Entry %d = %d\n", j, l);
			}
		}
	}
}

destroy_lists()
{
	int		i;
	int		s;

	for (i = 0; i < nlist; i++)
	{
		s = rm_key(list[i]);
		if (s < 0)
		{
			fprintf(stderr, "Failed to destroy list[%d] = %d: status %d\n",
					i, list[i], s);
			exit(1);
		}
		else
		{
			fprintf(stderr, "destroyed list[%d] with index = %d\n", i, list[i]);
		}
	}
}

create_lists()
{
	int	i;
	char *s;

	for (i = 0; i < nlist; i++)
	{
		list[i] = mk_key();
		if (list[i] <= 0)
		{
			fprintf(stderr, "Failed to create list[%d]: status %d\n",
					i, list[i]);
			exit(1);
		}
		else
		{
			fprintf(stderr, "created list[%d] with index = %d\n", i, list[i]);
		}
	}
}

populate_lists()
{
	int	i, j, k, l, n;
	char *s;

	for (i = 1; i < MAXNUM; i++)
	{
		j = lrand48() % nlist;
		k = cnt_key(list[j]);
		n = lrand48() % (k ? k : 1) + 1;
		fprintf(stderr, "%3d: put row %3d into list index %d\n", i, n, j);
		s = get_key(list[j], SC_ABSOLUTE, n);
		if (sc_error == ENOLIST)
			fprintf(stderr, "Empty list index %d: status %d\n", j, sc_error);
		else if (sc_error < ENOLIST)
		{
			fprintf(stderr, "Failed to get row %d from list %d: status %d\n",
					n, j, sc_error);
			exit(1);
		}
		if ((l = ins_key(list[j], (char *)&i, sizeof(i))) < ENOERROR)
		{
			fprintf(stderr, "Failed to insert into list[%d]: status %d\n",
					j, l);
			exit(1);
		}
		if (k != cnt_key(list[j]) - 1)
			fprintf(stderr, "List length mismatch? (count1 = %d) + 1 != (count2 = %d)\n",
					k + 1, cnt_key(list[j]));
	}
}

part_empty()
{
	int	i, j, l, n;
	char *s;

	for (i = 1; i < MAXNUM/5; i++)
	{
		j = lrand48() % nlist;
		n = lrand48() % AVGLENGTH + 1;
		s = get_key(list[j], SC_ABSOLUTE, n);
		if (sc_error < ENOLIST)
		{
			fprintf(stderr, "Failed to get row %d from list %d: status %d\n",
					n, list[j], sc_error);
			exit(1);
		}
		fprintf(stderr, "%3d: del row %3d from list index %d\n", i, n, j);
		if ((l = del_key(list[j])) < ENOLIST)
		{
			fprintf(stderr, "Failed to delete from list[%d]: status %d\n",
					j, l);
			exit(1);
		}
	}
}

complete_empty()
{
	int	i, j, k, l, n;
	char *s;

	for (i = 0; i < nlist; i++)
	{
		s = get_key(list[i], SC_ABSOLUTE, 1);
		while (sc_error != ENOLIST)
		{
			if (sc_error < ENOLIST)
			{
				fprintf(stderr, "Failed to get from list[%d]: status %d\n",
						i, sc_error);
				exit(1);
			}				
			if ((l = del_key(list[i])) < ENOLIST)
			{
				fprintf(stderr, "Failed to delete from list[%d]: status %d\n",
						i, l);
				exit(1);
			}
			s = get_key(list[i], SC_ABSOLUTE, 1);
		}
		fprintf(stderr, "completely emptied list index %d\n", i);
	}
}
