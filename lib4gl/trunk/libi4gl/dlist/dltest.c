/*
	@@(#)$Id: dltest.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)Test code to check functionality of D-lists
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
static	char	sccs[] = "@@(#)$Id: dltest.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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

/*
@


3.4
log
@Do not try accessing non-existent D-Lists if compiled PARANOID
@
text
@d33 1
a33 1
		srand((unsigned)time((long *)0));
d35 1
a35 1
		fprintf(stderr,"Iteration no %d complete\n", i + 1);
d38 1
a38 1
	fprintf(stderr,"Test complete\n");
d44 1
a44 1
	fprintf(stderr,"Create lists\n");
d47 1
a47 1
	fprintf(stderr,"Populate lists\n");
d50 1
a50 1
	fprintf(stderr,"Dump lists\n");
d53 1
a53 1
	fprintf(stderr,"Depopulate lists\n");
d56 1
a56 1
	fprintf(stderr,"Dump lists\n");
d59 1
a59 1
	fprintf(stderr, "Systematically empty lists\n");
d62 1
a62 1
	fprintf(stderr,"Dump lists\n");
d65 1
a65 1
	fprintf(stderr,"Populate lists again\n");
d68 1
a68 1
	fprintf(stderr,"Dump lists\n");
d71 1
a71 1
	fprintf(stderr,"Destroy lists\n");
d75 1
a75 1
	fprintf(stderr,"Dump lists\n");
d79 4
d87 1
a87 1
	int	i,j,k,l,n;
d92 3
a94 3
		fprintf(stderr,"Dump of list number %d\n", list[i]);
		n = num_key(list[i]);
		fprintf(stderr,"Number of entries = %d\n", n);
d109 1
a109 1
				fprintf(stderr,"Entry %d = %d\n", j, l);
d131 1
a131 1
			fprintf(stderr,"destroyed list[%d] with index = %d\n", i, list[i]);
d152 1
a152 1
			fprintf(stderr,"created list[%d] with index = %d\n", i, list[i]);
d159 1
a159 1
	int	i,j,l,n;
d164 4
a167 3
		j = rand() % nlist;
		n = rand() % AVGLENGTH + 1;
		fprintf(stderr,"%3d: put row %3d into list index %d\n", i, n, j);
d169 3
a171 1
		if (sc_error < ENOLIST)
d183 3
d191 1
a191 1
	int	i,j,l,n;
d196 2
a197 2
		j = rand() % nlist;
		n = rand() % AVGLENGTH + 1;
d205 1
a205 1
		fprintf(stderr,"%3d: del row %3d from list index %d\n", i, n, j);
d217 1
a217 1
	int	i,j,k,l,n;
@


3.3
log
@Split into functions; make test marginally more stringent
@
text
@d74 1
d77 1
@


3.2
log
@Make test more stringent
Empty dlists and start inserting again
Taxes bug in dlist.c version 3.2; fixed in dlist.c 3.3
@
text
@d10 1
a10 1
#define NLIST	3
d14 1
a14 1
#define MAXNUM	100
d24 1
d28 53
d84 29
a112 1
	srand((unsigned)time((long *)0));
d114 22
a135 2
	fprintf(stderr,"Create lists\n");
	for (i = 0; i < NLIST; i++)
d149 6
a155 1
	fprintf(stderr,"Populate lists\n");
d158 1
a158 1
		j = rand() % NLIST;
d160 1
a160 1
		fprintf(stderr,"%d: get row %3d from list %d\n", i, n, j);
d168 1
a168 1
		if (ins_key(list[j], (char *)&i, sizeof(i)) < ENOERROR)
d175 1
d177 4
a180 2
	fprintf(stderr,"Dump lists\n");
	dump_lists();
a181 1
	fprintf(stderr,"Depopulate lists\n");
d184 1
a184 1
		j = rand() % NLIST;
d193 1
a193 2
		
		fprintf(stderr,"%d: get row %3d from list %d\n", i, n, j);
d201 1
d203 4
a206 2
	fprintf(stderr,"Dump lists\n");
	dump_lists();
d208 1
a208 2
	fprintf(stderr, "Systematically empty lists\n");
	for (i = 0; i < NLIST; i++)
d227 1
a227 60
	}

	fprintf(stderr,"Dump lists\n");
	dump_lists();

	fprintf(stderr,"Populate lists again\n");
	for (i = 1; i < MAXNUM; i++)
	{
		j = rand() % NLIST;
		n = rand() % AVGLENGTH + 1;
		fprintf(stderr,"%d: get row %3d from list %d\n", i, n, j);
		s = get_key(list[j], SC_ABSOLUTE, n);
		if (sc_error < ENOLIST)
		{
			fprintf(stderr, "Failed to get row %d from list %d: status %d\n",
					n, j, sc_error);
			exit(1);
		}
		if (ins_key(list[j], (char *)&i, sizeof(i)) < ENOERROR)
		{
			fprintf(stderr, "Failed to insert into list[%d]: status %d\n",
					j, l);
			exit(1);
		}
	}

	fprintf(stderr,"Dump lists\n");
	dump_lists();

	fprintf(stderr,"Test complete\n");

}

dump_lists()
{
	int	i,j,k,l,n;
	char *s;

	for (i = 0; i < NLIST; i++)
	{
		fprintf(stderr,"Dump of list number %d\n", list[i]);
		n = num_key(list[i]);
		fprintf(stderr,"Number of entries = %d\n", n);
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
				fprintf(stderr,"Entry %d = %d\n", j, l);
			}
		}


*/
