/*
 * fgldoc, an Informix-4GL program documenter
 * Copyright (c) 1995-1998 Ivan Nejgebauer <ian@uns.ns.ac.yu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * REVISION HISTORY:
 *
 * 2.00 Jun 1999 ian
 *
 * Major revamp (but without disturbing the internals too much).  New
 * and improved:
 *
 * o Source configuration with Autoconf;
 *
 * o Reading of the program database is back, using ESQL/C instead of
 *   raw C/ISAM (punted in 1.15).  The PROGRAM_DESIGN_DBS environment
 *   variable is honored.  Programmer's environments from 4.x to 7.20
 *   are supported;
 *
 * o 4GL modules outside the current directory are supported;
 *
 * o The parser has been updated to recognize the use of character
 *   variables in OPEN FORM and OPEN WINDOW.  Internal functions added
 *   since 4.00 are also there;
 *
 * o The program is now named "fgldoc".
 *
 * 1.16 Nov 1998 ian
 *
 * More portability tweaks in parser.y and lexer.l.
 *
 * 1.15 Apr 1998 ian
 *
 * Threw out C-ISAM calls and got rid of ugly #defines.
 *
 * 1.13 Mar 1995 ian
 *
 * Now using bison instead of yacc.
 *
 * 1.12 Jan 1995 ian
 *
 * Integrated database search, recompiled for Xenix 386. Hopefully,
 * improved portability.
 *
 * Eliminated the '!' printing glitch from the form summary.
 *
 * 1.10 Jan 1995 ian
 *
 * If no modulelist is given on stdin, forks a process which attempts to
 * access the program database and read module names from it.
 *
 * Recursive functions are properly handled in the hierarchy report.
 *
 * 1.00 Jan 1995 ian
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fgldoc.h"

#define MODNAME_LEN_MAX	10
#define IDENT_LEN_MAX	18

/* externs */
extern FILE *yyin;
int yyparse();

enum { MOD, FUN, RPT, FRM };			/* node types */
enum { TADD, TSCAN };				/* tree scan modes */
enum { CALLS, CALLEDBY };			/* call list identifiers */

/* list and tree node structs */
struct TAG_flist;

typedef struct TAG_fnode {
    char name[20];
    char *path;
    int type;
    struct TAG_fnode *module;
    struct TAG_flist *cllist;
    struct TAG_flist *cblist;
    int passed;
    struct TAG_fnode *left;
    struct TAG_fnode *right;
} Fnode;

typedef struct TAG_flist {
    Fnode *nptr;
    struct TAG_flist *next;
} Flist;

/* globals */
int verbose;					/* verbose mode */

/* global functions */
void yyerror(char *s);
int regmod(char *name, char *path);

/* local functions */
static Fnode *treescan(Fnode *root, char *name, int scanonly);
static void upd_flist(Fnode *of, Fnode *by, int which);
static int get_modules(char *progarg, char *extmod);
static void read_stdin(void);
static void modwalk(Fnode *mp);
static void mods_process(void);
static void heading(char *title);
static int ps_mwalk(Fnode *mp);
static void ps_owalk(Fnode *op);
static void prog_summ(void);
static void func_summ(void);
static void rept_summ(void);
static void os_owalk(Fnode *op);
static void fs_fwalk(Fnode *fp);
static void fs_hier(Fnode *fp, int lev);
static void eprint(char *out, Flist *le);
static char *rtrim(char *s);
static void form_summ(void);
static void usage(void);

/* local data */
static Fnode *cmod, *cfun;			/* current module, func */
static Fnode *modr, *funr, *rptr, *frmr;	/* root nodes */
static char prog[11];				/* program name */
static int nmods, nfuns, nreps, nfrms;		/* counts */

#ifdef HAVE_ESQLC
static int readstdin = 0;			/* module list from standard */
#else						/* input: force if we don't */
static int readstdin = 1;			/* have ESQL/C */
#endif

/* scan symbol tree, add node if requested */
static Fnode *
treescan(Fnode *root, char *name, int scanonly)
{
    Fnode *p = root, *q = NULL;
    int cond = 0;

    while (p) {
	q = p;
	if ((cond = strcmp(name, p->name)) == 0)
	    break;
	else if (cond < 0)
	    p = p->left;
	else
	    p = p->right;
    }
    if (scanonly)
	return p;
    if (!p)
	if ((p = (Fnode *) calloc(1, sizeof(Fnode))) == NULL) {
	    fprintf(stderr, "fgldoc: FATAL: malloc failed\n");
	    exit(1);
	} else {
	    p->module = p->left = p->right = NULL;
	    p->cllist = p->cblist = NULL;
	}
    if (cond < 0)
	q->left = p;
    else if (cond > 0)
	q->right = p;
    return p;
}

/* update calling and called-by lists of a node */
static void
upd_flist(Fnode *of, Fnode *by, int which)
{
    Flist *head, *curr, *prev;

    head = (which == CALLS) ? of->cllist : of->cblist;
    for (prev = curr = head; curr; prev = curr, curr = curr->next)
	if (by == curr->nptr)
	    break;
    if (curr)
	return;
    if ((curr = (Flist *) malloc(sizeof(Flist))) == NULL) {
	fprintf(stderr, "fgldoc: FATAL: malloc failed\n");
	exit(1);
    }
    curr->nptr = by;
    curr->next = NULL;
    if (head)
	prev->next = curr;
    else if (which == CALLS)
	of->cllist = curr;
    else
	of->cblist = curr;
}

/* register a function, called from the parser */
void
regfun(char *name)
{
    Fnode *temp = treescan(funr, name, TADD);

    if (!funr)
	funr = temp;
    if (!(temp->name)[0])
	strncpy(temp->name, name, IDENT_LEN_MAX);
    nfuns++;
    temp->type = FUN;
    temp->module = cmod;
    cfun = temp;
}

/* register a function call, called from the parser */
void
regfcall(char *name)
{
    Fnode *temp = treescan(funr, name, TADD);

    if (!(temp->name)[0])
	strncpy(temp->name, name, IDENT_LEN_MAX);
    temp->type = FUN;
    upd_flist(temp, cfun, CALLEDBY);
    upd_flist(cfun, temp, CALLS);
}

/* register a report, called from the parser */
void
regrep(char *name)
{
    Fnode *temp = treescan(rptr, name, TADD);

    if (!rptr)
	rptr = temp;
    if (!(temp->name)[0])
	strncpy(temp->name, name, IDENT_LEN_MAX);
    nreps++;
    temp->type = RPT;
    temp->module = cmod;
    cfun = temp;
}

/* register a report call, called from the parser */
void
regrcall(char *name)
{
    Fnode *temp = treescan(rptr, name, TADD);

    if (!rptr)
	rptr = temp;
    if (!(temp->name)[0])
	strncpy(temp->name, name, IDENT_LEN_MAX);
    temp->type = RPT;
    upd_flist(temp, cfun, CALLEDBY);
    upd_flist(cfun, temp, CALLS);
}

/* register a form opening, called from the parser */
void
regfrm(char *name)
{
    Fnode *temp = treescan(frmr, name, TADD);

    if (!frmr)
	frmr = temp;
    if (!(temp->name)[0]) {
	strncpy(temp->name, name, IDENT_LEN_MAX);
	nfrms++;
    }
    temp->module = (Fnode *) 1;	/* fake module */
    temp->type = FRM;
    upd_flist(temp, cfun, CALLEDBY);
    upd_flist(cfun, temp, CALLS);
}

/*
 * get the module list: from stdin if -s was specified or the program
 * lacks ESQL/C support, otherwise try to read the program database.
 * Process the modules named in extmod first.
 */
static int
get_modules(char *progarg, char *extmod)
{
    prog[sizeof prog - 1] = '\0';
    strncpy(prog, progarg, sizeof prog - 1);

    if (extmod) {
	char *s = extmod;
	char *t;

	do {
	    t = strchr(s, ',');
	    if (t)
		*t++ = '\0';
	    if (*s)
		regmod(s, ".");
	    if (t)
		s = t;
	} while (t);
    }

    if (readstdin)
	read_stdin();
#ifdef HAVE_ESQLC
    else
	read_progdbs(prog, regmod);
#endif

    return (modr != NULL);
}

/* read stdin, separate name and path elements and register them */
static void
read_stdin(void)
{
    char modline[256];
    char *mpath, *mname;
    char *t;

    while (fgets(modline, sizeof modline, stdin) == modline) {
	t = rtrim(modline);
	*t = '\0';
	t = strrchr(modline, '/');
	if (t) {
	    *t++ = '\0';
	    if (!*t || !modline[0])	/* junks modules in / -- BFD */
		continue;
	    regmod(t, modline);
	} else if (modline[0])
	    regmod(modline, ".");
    }
}

/* register modules as they are read */
int
regmod(char *name, char *path)
{
    Fnode *temp;

    nmods++;
    temp = treescan(modr, name, TADD);
    if (!modr)
	modr = temp;
    strncpy(temp->name, name, MODNAME_LEN_MAX);
    temp->path = (char *) malloc(strlen(path) + MODNAME_LEN_MAX + 6);
    if (temp->path == NULL) {
	fprintf(stderr, "fgldoc: FATAL: malloc failed\n");
	exit(1);
    }
    strcpy(temp->path, path);

    return 0;	/* bogus */
}

/* process all modules recursively */
static void
modwalk(Fnode *mp)
{
    static FILE *modfp;

    if (mp) {
	modwalk(mp->left);
	strcat(mp->path, "/");
	strcat(mp->path, mp->name);
	strcat(mp->path, ".4gl");
	if ((modfp = fopen(mp->path, "r")) == NULL) {
	    fprintf(stderr, "fgldoc: cannot open '%s'\n", mp->path);
	    exit(1);
	}
	if (verbose) {
	    fprintf(stderr, "    %-10s   %6d", mp->name, 0);
	    fflush(stderr);
	}
	cmod = mp;
	yyin = modfp;
	lineno = 1;
	if (yyparse())
	    exit(1);
	mp->passed = --lineno;
	if (verbose)
	    fprintf(stderr, "\b\b\b\b\b\b%6d\n", mp->passed);
	fclose(modfp);
	modwalk(mp->right);
    }
}

/* parser error printing routine */
void
yyerror(char *s)
{
    if (verbose)
	fprintf(stderr, "\n");
    fprintf(stderr, "fgldoc: %s, module '%s', line %d\n",
	    s, cmod->name, lineno);
}

/* start module processing */
static void
mods_process(void)
{
    Fnode *temp;

    modwalk(modr);
    temp = treescan(funr, "!main", TSCAN);
    if (!temp) {
	fprintf(stderr, "fgldoc: no main symbol\n");
	exit(1);
    }
    printf("\
FGLDOC: Informix-4GL Program Documenter v2.00\n\
Copyright (c) 1995-1999 Ivan Nejgebauer\n\n");
    printf("PROGRAM: %s\n", prog);
}

/* print summary heading */
static void
heading(char *title)
{
    int i, len = strlen(title) + 12;
    char sep[30];

    for (i = 0; i < len; i++)
	sep[i] = '*';
    sep[i] = '\0';
    printf("\n%s\n* %s SUMMARY *\n%s\n\n", sep, title, sep);
}

/* print all module names */
static int
ps_mwalk(Fnode *mp)
{
    static int lsum = 0;

    if (mp) {
	lsum += mp->passed;
	ps_mwalk(mp->left);
	printf("    %-10s  %6d\n", mp->name, mp->passed);
	ps_mwalk(mp->right);
    }
    return lsum;
}

/* print all form names */
static void
ps_owalk(Fnode *op)
{
    if (op) {
	ps_owalk(op->left);
	printf("    %s\n", op->name);
	ps_owalk(op->right);
    }
}

/* print program summary */
static void
prog_summ(void)
{
    if (verbose)
	fprintf(stderr, "Writing program summary...\n");
    heading("PROGRAM");
    printf("Modules: %d\n", nmods);
    printf("               -------\n    Lines:     %7d\n", ps_mwalk(modr));
    printf("\nFunctions: %d\n", nfuns - 1);
    printf("\nReports: %d\n", nreps);
    printf("\nForms: %d\n", nfrms);
    ps_owalk(frmr);
}

/* print an entry from the cl or cb list */
static void
eprint(char *out, Flist *le)
{
    int type = le->nptr->type;
    int ismain = *le->nptr->name == '!';
    char t[30];

    if (type == RPT || type == FRM)
	sprintf(t, "%s %-18s ", (type == RPT) ? "(r)" : "(f)", le->nptr->name);
    else
	sprintf(t, "%-22s ", le->nptr->name + ismain);
    strcat(out, t);
}

/* clip a string */
static char
*rtrim(char *s)
{
    int c;
    char *t = s + strlen(s);

    while (t > s && ((c = *--t) == ' ' || c == '\n'))
	;
    return t + (*t && !isspace(*t));
}

/* function hierarchy */
static void
fs_hier(Fnode *fp, int lev)
{
    Flist *cl;
    static int ismain, fline, c;
    static char out[80];
    static char *outtr;

    ismain = *fp->name == '!';
    fline = 1;
    sprintf(out, "%3d %-18s %-10s ", lev, fp->name + ismain, fp->module->name);
    for (cl = fp->cllist; cl; cl = cl->next) {
	if (!fline)
	    strcpy(out, "                                  ");
	if (cl->nptr->module) {
	    eprint(out, cl);
	    if (cl->nptr->module != (Fnode *) 1)
		strcat(out, cl->nptr->module->name);
	} else
	    continue;
	if ((outtr = rtrim(out)) != out) {
	    *outtr = '\0';
	    printf("%s\n", out);
	}
	fline = 0;
    }
    for (cl = fp->cllist; cl; cl = cl->next)
	if (cl->nptr->module && !cl->nptr->passed && fp != cl->nptr
		&& (c = cl->nptr->type) != RPT && c != FRM) {
	    fs_hier(cl->nptr, lev + 1);
	    cl->nptr->passed = 1;
	}
}

/* functions by name */
static void
fs_fwalk(Fnode *fp)
{
    static int fline;
    static Flist *cl, *cb;
    static char out[80];
    static char *outtr;

    if (fp) {
	fs_fwalk(fp->left);
	fline = 1;
	cl = fp->cllist;
	cb = fp->cblist;
	do {
	    if (!fp->module)
		break;
	    if (fline) {
		int ismain = *fp->name == '!';

		sprintf(out, "%c%-18s %-10s ", (cb || ismain) ? ' ' : '#',
			fp->name + ismain, fp->module->name);
		fline = 0;
	    } else
		strcpy(out, "                               ");
	    while (cl && !cl->nptr->module)
		cl = cl->next;
	    if (cl)
		eprint(out, cl);
	    else
		strcat(out, "                       ");
	    if (cb) {
		eprint(out, cb);
		cb = cb->next;
	    }
	    if (cl)
		cl = cl->next;
	    if ((outtr = rtrim(out)) != out) {
		*outtr = '\0';
		printf("%s\n", out);
	    }
	} while (cb || cl);
	fs_fwalk(fp->right);
    }
}

/* print function summary */
static void
func_summ(void)
{
    if (!funr)
	return;
    if (verbose)
	fprintf(stderr, "Writing function summary...\n");
    heading("FUNCTION");
    printf("\
a) Function Hierarchy\n\
-------------------------------------------------------------------\n\
Lev Name               Module     Calls                  In-Module\n\
-------------------------------------------------------------------\n");
    fs_hier(treescan(funr, "!main", TSCAN), 0);
    printf("\n\
b) Functions by Name\n\
------------------------------------------------------------------------\n\
 Name               Module     Calls                  Called-by\n\
------------------------------------------------------------------------\n");
    fs_fwalk(funr);
}

/* print report summary */
static void
rept_summ(void)
{
    if (!rptr)
	return;
    if (verbose)
	fprintf(stderr, "Writing report summary...\n");
    heading("REPORT");
    printf("\
------------------------------------------------------------------------\n\
 Name               Module     Calls                  Called-by\n\
------------------------------------------------------------------------\n");
    fs_fwalk(rptr);
}

/* forms by name */
static void
os_owalk(Fnode *op)
{
    static int fline, ismain;
    static Flist *temp;

    if (op) {
	os_owalk(op->left);
	printf(" %-18s ", op->name);
	fline = 1;
	for (temp = op->cblist; temp; temp = temp->next) {
	    ismain = *temp->nptr->name == '!';
	    if (!fline)
		printf("            ");
	    printf("%-18s %-10s\n", temp->nptr->name + ismain,
		   temp->nptr->module->name);
	    fline = 0;
	}
	os_owalk(op->right);
    }
}

/* print form summary */
static void
form_summ(void)
{
    if (!frmr)
	return;
    if (verbose)
	fprintf(stderr, "Writing form summary...\n");
    heading("FORM");
    printf("\
-------------------------------------------------\n\
 Name               Called-by          In-Module\n\
-------------------------------------------------\n");
    os_owalk(frmr);
}

/* usage */
static void
usage(void)
{
    fprintf(stderr, "\
FGLDOC: Informix-4GL Program Documenter v2.00\n\
Copyright (c) 1995-1999 Ivan Nejgebauer\n\n");
    fprintf(stderr, "\
USAGE:\n\n\
fgldoc [-v] [-s] [-x modname[,modname...]] [-apfro] progname\n\n\
  -v   verbose option, diagnostics to stderr\n\
  -s   read module list from standard input\n\n\
  -x   add named modules to module list\n\n\
  -a   output all summaries (default)\n\
  -p   output program summary\n\
  -f   output function summary\n\
  -r   output report summary\n\
  -o   output form summary\n\n\
       Options p, f, r and o may be combined as needed.\n");
    exit(1);
}

int
main(int argc, char *argv[])
{
    char *extmod = NULL;
    int c;
    extern int optind, opterr;
    extern char *optarg;
    int dopsum, dofsum, dorsum, doosum;

    dopsum = dofsum = dorsum = doosum = 0;
    opterr = 0;
    while ((c = getopt(argc, argv, "vsx:apfro")) != -1)
	switch (c) {
	case 'a':
	    dopsum = dofsum = dorsum = doosum = 1;
	    break;
	case 'p':
	    dopsum = 1;
	    break;
	case 'f':
	    dofsum = 1;
	    break;
	case 'r':
	    dorsum = 1;
	    break;
	case 'o':
	    doosum = 1;
	    break;
	case 'v':
	    verbose = 1;
	    break;
	case 's':
	    readstdin = 1;
	    break;
	case 'x':
	    extmod = optarg;
	    break;
	default:
	    usage();
	}
    if (optind >= argc)
	usage();
    if (!get_modules(argv[optind], extmod))
	return 1;
    if (verbose)
	fprintf(stderr, "Program: %s\n", prog);
    if (!(dopsum || dofsum || dorsum || doosum))
	dopsum = dofsum = dorsum = doosum = 1;
    mods_process();
    if (dopsum)
	prog_summ();
    if (dofsum)
	func_summ();
    if (dorsum)
	rept_summ();
    if (doosum)
	form_summ();
    if (verbose)
	fprintf(stderr, "Done.\n");
    return 0;
}
