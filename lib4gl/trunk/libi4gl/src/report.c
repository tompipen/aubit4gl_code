/*
@(#) File:           $RCSfile: report.c,v $
@(#) Version:        $Revision: 1.2 $
@(#) Last changed:   $Date: 2002-06-14 09:23:16 $
@(#) Purpose:        I4GL: Reset report output parameters (RDS & C4GL)
@(#) Author:         J Leffler / M Prowell
*/

/*TABSTOP=4*/

/*
** INFORMIX-4GL Dynamic Report Output Parameters Version 2
** C4GL code (and interface) by J Leffler.
** RDS interface by M Prowell.
**
** Compilation: 
** C4GL: cc -c $RCSfile: report.c,v $
** RDS:  cc -c -DI4GL_RDS $RCSfile: report.c,v $
*/

/*
** Addendum to Marlin's comments.
** -- tested on SUNOS 4.1.1 and I4GL-RDS 4.10.UC1 and it seems to work
**    correctly, but it is still unsupported code.
*/

/*
** From: uunet!nyssa.wa7ipx.ampr.org!mbp (Marlin Prowell)
** Subject: Changing report output params in RDS (code enclosed)
** Date: 29 Apr 92 04:30:46 GMT
** To: informix-list@rmy.emory.edu
** X-Informix-List-Id: <news.1132>
** 
** A few days ago, Jonathan Leffler posted some code for I4GL that would
** change report output parameters on the fly.  The code he posted works
** only for the C compiler version, and I only have the RDS version of
** Informix.  Since an Informix employee said he was unable to figure out
** a RDS version, I took that as a challenge.
** 
** Below is a modified version of his report.c that works when linked into
** a customized runner.  I leave the details to building the runner as an
** exercise for the reader.
** 
** I used Jonathan's code as a hint on how reports work in Informix.  I
** found the equivalent report pointer, and inferred the report structure
** that the interpreter uses.  Since this code diddles with internal
** interpreter variables, use this code at your own risk.  I use it now to
** reset the page length when output is going to the screen, and it
** *appears* to work correctly.  Your mileage may vary.
** 
** BTW, I am using Informix 4.00 on SCO Xenix.  I haven't tested this
** anywhere else.  Of course, the size of the junk variable in the repdesc
** structure may change on other machine architectures.  You could write
** another C function that gets called in the ON EVERY ROW section, and
** have it print out the values in the repdesc structure.  You can then
** verify that the structure definition is correct on your machine.
** 
** I've wanted to do this, but after I had previously poked around in the
** interpreter for awhile, I had also given up.  Thanks for the hints, Jonathan.
** 
**  -------------------------------------------------------------------------- 
** | Marlin Prowell            | There is a very thin line between ignorance  |
** | (206) 676-1554            | and arrogance and I have totally obliterated |
** | mbp@nyssa.wa7ipx.ampr.org | that line.             -- Dr. Science        |
**  -------------------------------------------------------------------------- 
*/

#include <stdio.h>

#ifndef lint
static  char    sccs[] = "@(#)$Id: report.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

#ifdef I4GL_RDS

/* Structure inferred from RDS */
typedef struct repdesc
{
	short junk[42];     /* unknown       */
	short ln;           /* Line number?  */
	short pagenumber;   /* Pge number    */
	short plength;      /* Page length */
	short tmargin;      /* Top margin    */
	short bmargin;      /* Bottom margin */
	short lmargin;      /* Left margin   */
	short rmargin;      /* Right margin  */
	short fphlines;     /* Lines in first page header */
	short phlines;      /* Lines in page header */
	short ptlines;      /* Lines in page trailer */
	short junktoo;      /* unknown       */
	short tot;
}  Report;

extern  Report *currep;   /* Parameters of current report */

#else

/* Structure copied from C code generated by I4GL */
typedef struct repdesc
{
	long rrecordnum;    /* Record number */
	short pagenumber;   /* Pge number    */
	short ln;           /* Line number?  */
	short tmargin;      /* Top margin    */
	short rmargin;      /* Right margin  */
	short lmargin;      /* Left margin   */
	short bmargin;      /* Bottom margin */
	short phlines;      /* Lines in page header */
	short fphlines;     /* Lines in first page header */
	short colcount;
	short tot;
	short oktoinc;
	FILE *outfp;        /* Output channel */
	short oftype;
	short plength;      /* Page length */
	short ptlines;      /* Lines in page trailer */
	struct aggdesc *_paggdesc;
	struct value *_paggvals;
	struct sortdesc *p_sortdesc;
	short gotoindx;
	short gotostk[5];
	short needlmarg;
}  Report;

extern  Report *c_rp;   /* Parameters of current report */

#endif	/* I4GL_RDS */

static  Report set;     /* Newly set report parameters  */
static  int newset = 0; /* Mask of newly set parameters */

#define TMARGIN 0x01
#define BMARGIN 0x02
#define LMARGIN 0x04
#define PLENGTH 0x08
#define RMARGIN 0x10

#define DEF_TMARGIN   3
#define DEF_BMARGIN   3
#define DEF_LMARGIN   5
#define DEF_PLENGTH  66
#define DEF_RMARGIN 132

/* Redefine page length */
int set_plength(i)
int i;
{
	if (i == 1)
	{
		popint(&i);
		if (i > 0)
		{
			set.plength = i;
			newset |= PLENGTH;
		}
	}
	return(0);
}

/* Reset top margin */
/* This will not reset the top margin on the first page */
int set_tmargin(i)
int i;
{
	if (i == 1)
	{
		popint(&i);
		if (i >= 0)
		{
			set.tmargin = i;
			newset |= TMARGIN;
		}
	}
	return(0);
}

/* Reset bottom margin */
int set_bmargin(i)
int i;
{
	if (i == 1)
	{
		popint(&i);
		if (i >= 0)
		{
			set.bmargin = i;
			newset |= BMARGIN;
		}
	}
	return(0);
}

/* Reset left margin */
int set_lmargin(i)
int i;
{
	if (i == 1)
	{
		popint(&i);
		if (i >= 0)
		{
			set.lmargin = i;
			newset |= LMARGIN;
		}
	}
	return(0);
}

/* Reset right margin */
int set_rmargin(i)
int i;
{
	if (i == 1)
	{
		popint(&i);
		if (i >= 0)
		{
			set.rmargin = i;
			newset |= RMARGIN;
		}
	}
	return(0);
}

/* Copy reset output list into report configuration */
/* Call in first page header block */
int set_output(i)
int i;
{
	int newlen;
	Report	*report;

#ifdef I4GL_RDS
	report = currep;
#else
	report = c_rp;
#endif	/* I4GL_RDS */

	if (i == 0 && newset && report != (Report *)0)
	{
		if (newset & PLENGTH)
		{
			report->plength = set.plength;
		}
		if (newset & TMARGIN)
		{
			newlen  = report->plength
					- report->ptlines
					- report->phlines
					- report->bmargin
					- report->tmargin
					- 1;
			if (set.tmargin < newlen)
			{
				report->tmargin = set.tmargin;
			}
		}
		if (newset & LMARGIN)
		{
			report->lmargin = set.lmargin;
		}
		if (newset & BMARGIN)
		{
			newlen  = report->plength
					- report->ptlines
					- report->phlines
					- report->tmargin
					- report->bmargin
					- 1;
			if (set.bmargin < newlen)
			{
				report->bmargin = set.bmargin;
			}
		}
		/* Adding report->phlines leaves the report     */
		/* title at the top of the terminal screen.  MP */
		report->tot = report->plength - (report->bmargin + report->ptlines
						+ report->phlines);
		newset = 0;
	}
	return(0);
}

/* Return page length */
int get_plength(i)
int i;
{
	if (newset & PLENGTH)
		i = set.plength;
	else
		i = DEF_PLENGTH;
	retint(i);
	return(1);
}

/* Return top margin */
int get_tmargin(i)
int i;
{
	if (newset & TMARGIN)
		i = set.tmargin;
	else
		i = DEF_TMARGIN;
	retint(i);
	return(1);
}

/* Return bottom margin */
int get_bmargin(i)
int i;
{
	if (newset & BMARGIN)
		i = set.bmargin;
	else
		i = DEF_BMARGIN;
	retint(i);
	return(1);
}

/* Return left margin */
int get_lmargin(i)
int i;
{
	if (newset & LMARGIN)
		i = set.lmargin;
	else
		i = DEF_LMARGIN;
	retint(i);
	return(1);
}

/* Return right margin */
int get_rmargin(i)
int i;
{
	if (newset & RMARGIN)
		i = set.rmargin;
	else
		i = DEF_RMARGIN;
	retint(i);
	return(1);
}
