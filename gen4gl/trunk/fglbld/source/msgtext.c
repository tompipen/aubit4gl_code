/*
@(#)File:            $RCSfile: msgtext.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         Open, Read, Close Informix Error Message Files
@(#)Author:          J Leffler
*/

/* -- Include Files */

#include <stdio.h>
#include <errno.h>

/* -- Constant Definitions */

#define I4GL_C	int				/* C callable from I4GL */
#define MAGIC1	((ushort)0xFE68)
#define MAXBUFF	4096
#define NIL(x)	((x)0)

/* -- Type Definitions */

typedef unsigned short ushort;
typedef unsigned long ulong;

typedef struct
{
	ushort          magic;
	short           n_entries;
}               Header;

typedef struct
{
	short           err_number;
	short           err_length;
	long            err_seek;
}               Entry;

/* -- Declarations */

static char     buff[MAXBUFF];
static char     header[sizeof(Header)];
static char     entry[sizeof(Entry)];
static Header   hdr;
static FILE    *fp;
static Entry   *elist;

extern char    *malloc();
extern void     free();

#if !defined(lint)
static char     sccs[] = "@(#)$Id: msgtext.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

/* Close an already open error message file */
/* Does not fail if no file open */
void            iem_close()
{
	if (fp != NIL(FILE *))
	{
		fclose(fp);
		if (elist != NIL(Entry *))
			free(elist);
		elist = NIL(Entry *);
		fp = NIL(FILE *);
	}
}

int             iem_open(fname)
char           *fname;
{
	iem_close();
	if ((fp = fopen(fname, "r")) == NIL(FILE *))
		return (-1);
	if (fread(header, sizeof(header), 1, fp) == EOF)
		return (-1);
	hdr.magic = ldint(&header[0]);
	hdr.n_entries = ldint(&header[2]);
#ifdef DEBUG
	fprintf(stderr, "Magic: %04X; entries = %d\n", hdr.magic, hdr.n_entries);
#endif	/* DEBUG */
	if (hdr.magic != MAGIC1)
		return (-1);
	return (0);
}

/* Compare two error message entries */
static int      iem_comp(cp1, cp2)
char           *cp1;
char           *cp2;
{
	register Entry *ep1 = (Entry *) cp1;
	register Entry *ep2 = (Entry *) cp2;

	return (ep1->err_number - ep2->err_number);
}

/* missing - this is dummy */
int
ldint(char *entry)
{
    return 1;
}

char           *iem_read(msg)
int             msg;
{
	Entry           hunt;
	Entry          *ent;
	char           *entry;
	long            org_seek;
	int             i;
	int             n;

	if (elist == NIL(Entry *))
	{
		/* Read array of message headers into memory */
		n = hdr.n_entries;
		if ((elist = (Entry *) malloc(n * sizeof(Entry))) == NIL(Entry *))
			return(NIL(char *));
		if (fread((char *) elist, sizeof(Entry), n, fp) != n)
		{
			/* Failed to read header records */
			free(elist);
			elist = NIL(Entry *);
			return (NIL(char *));
		}
		/* Convert numbers from canonical form to host form */
		for (i = 0; i < n; i++)
		{
			ent = &elist[i];
			entry = (char *) ent;
			ent->err_number = ldint(&entry[0]);
			ent->err_length = ldint(&entry[2]);
			ent->err_seek = ldlong(&entry[4]);
		}
	}

	hunt.err_number = msg;
	ent = (Entry *) bsearch((char *) &hunt, (char *) elist, hdr.n_entries,
							sizeof(Entry), iem_comp);

	if (ent == NIL(Entry *))
		return (NIL(char *));
	else
	{
#ifdef DEBUG
		fprintf(stderr, "%4d: %6d: %4d @ 0x%08X\n", msg, ent->err_number,
				ent->err_length, ent->err_seek);
#endif	/* DEBUG */
		fseek(fp, ent->err_seek, 0);
		if (ent->err_length > MAXBUFF)
			ent->err_length = MAXBUFF - 1;
		if (fread(buff, ent->err_length, 1, fp) != 1)
			return (NIL(char *));
		buff[ent->err_length] = '\0';
		if (buff[ent->err_length - 1] == '\n')
			buff[ent->err_length - 1] = '\0';
	}
	return (buff);
}

/* I4GL calling sequence: LET i = fgl_msgopen(msgfile) */
/*                       (i = 0 => OK; i = -1 => fail) */
/* I4GL calling sequence: LET s = fgl_msgread(msgnum) */
/* I4GL calling sequence: CALL fgl_msgclose() */

I4GL_C          fgl_msgopen(n)
int             n;
{
	char            msgfile[512];
	int				r;

	if (n != 1)
		r = -1;
	else
	{
		popstring(msgfile, sizeof(msgfile));
		r = iem_open(msgfile);
	}
	retint(r);
	return (1);
}

I4GL_C          fgl_msgread(n)
int             n;
{
	char           *s;
	int             msgnum;
	char			buffer[50];

	if (n != 1)
		s = "";
	else
	{
		popint(&msgnum);
		if ((s = iem_read(msgnum)) == NIL(char *))
		{
			sprintf(buffer, "<<unknown message number %d>>", msgnum);
			s = buffer;
		}
	}
	retquote(s);
	return (1);
}

/* ARGSUSED */
I4GL_C          fgl_msgclose(n)
int             n;
{
	iem_close();
	return (0);
}

#ifdef TEST

main(argc, argv)
int             argc;
char          **argv;
{
	int             i;
	int             n;
	char           *s;

	if (argc <= 2)
	{
		fprintf(stderr, "Usage: %s iemfile msg [...]\n", argv[0]);
		exit(1);
	}

	if (iem_open(argv[1]) != 0)
	{
		fprintf(stderr, "%s: failed to open message file %s\n", argv[0], argv[1]);
		exit(1);
	}

	for (i = 2; i < argc; i++)
	{
		n = atoi(argv[i]);
		s = iem_read(n);
		if (s != NIL(char *))
			printf("%d: %s\n", n, s);
		else
			printf("%d: <no such message>\n", n);
	}

	iem_close();
	return (0);
}

#endif	/* TEST */
