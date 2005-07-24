/*
@(#)File:            $RCSfile: tabcol.ec,v $
@(#)Version:         $Revision: 1.1.1.1 $
@(#)Last changed:    $Date: 2002-06-15 05:07:14 $
@(#)Purpose:         Validate table name and fill in column details
@(#)Author:          J Leffler
*/

/* -- Include Files */

$include sqlca;
#include <stdio.h>
#include <assert.h>
#include "fglgen.h"
#include "fglgene.h"

/* -- Declarations */

$	static	char	colname[20];
$	static	int		coltype;
$	static	int		collen;
$	static	int		colno;

#ifndef lint
static	char	sccs[] = "@(#)$Id: tabcol.ec,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $";
#endif

static	Table	*get_table(name)
char	*name;
{
$	int		 ncols;
$	char	 tabname[20];
	Column	*col;
	Table	*tp;
	char	*s;
	char	*t;

	s = name;
	t = tabname;
	while (*t++ = tolower(*s++))
		;	

$	SELECT Systables.Ncols
		INTO $ncols
		FROM Systables
		WHERE Systables.Tabname = $tabname;
	if (sqlca.sqlcode != 0)
	{
		semantic_error(E_TABLENOTFOUND, name);
		tp = mk_table(name);
		tp->t_flag |= T_MIRAGE;
		TRACE((5, "Mirage table %s\n", tp->t_tabname));
		return(tp);
	}

	tp = mk_table(name);

$	DECLARE c_column CURSOR FOR
		SELECT	Syscolumns.Colname,
				Syscolumns.Colno,
				Syscolumns.Coltype,
				Syscolumns.Collength
			FROM Systables, Syscolumns
			WHERE Systables.Tabid = Syscolumns.Tabid
			AND Systables.Tabname = $tabname
			ORDER BY Colno;

	if (sqlca.sqlcode != 0)
		internal_error("Can't declare cursor");

$	OPEN c_column;
	if (sqlca.sqlcode != 0)
	{
		sqlerror();
		internal_error("Can't open cursor");
	}

	while (fetch() == 0)
	{
		col = mk_column(tp, stralloc(colname));
		col->c_coltype = coltype;
		col->c_collen  = collen;
		add_item((char *)col, &tp->t_cols);
		tp->t_ncols++;
	}
	if (sqlca.sqlcode != SQLNOTFOUND)
		internal_error("Can't fetch cursor");

$	CLOSE c_column;
	if (sqlca.sqlcode != 0)
		internal_error("Can't close cursor");

	return(tp);
}

Table	*chk_table(name)
char	*name;
{
	Table	*tp;

	if (program.p_database == NIL(char *) || (program.p_flag & P_NODBASE))
	{
		/* No database -- table deemed to be a mirage */
		program.p_flag |= P_NODBASE;
		if (program.p_database == NIL(char *))
			semantic_error(E_NODATABASE, name);
		tp = mk_table(name);
		tp->t_flag |= T_MIRAGE;
		TRACE((5, "Mirage table %s\n", tp->t_tabname));
	}
	else
		tp = get_table(name);

	return(tp);
}

static	int	fetch()
{
$	FETCH c_column INTO $colname, $colno, $coltype, $collen;
	strip_blanks(colname, sizeof(colname));
	return(sqlca.sqlcode);
}

Column	*mk_column(tp, col)
Table	*tp;
char	*col;
{
	Column	*cp;

	cp            = (Column *)MALLOC(sizeof(Column));
	cp->c_colname = col;
	cp->c_table   = tp;
	cp->c_flag    = C_DEFAULT;
	cp->c_sqstart = 0;
	cp->c_sqincr  = 0;
	cp->c_screen  = 0;
	cp->c_row     = 0;
	cp->c_block   = 0;
	cp->c_coltype = -1;
	cp->c_collen  = -1;
	cp->c_xref    = NIL(Table *);
	cp->c_popup   = NIL(Function *);
	cp->c_fetch   = NIL(Function *);
	cp->c_default = NIL(char *);
	cp->c_label   = NIL(char *);

	return(cp);
}

Table	*mk_table(name)
char	*name;
{
	Table	*tp;

	tp            = (Table *)MALLOC(sizeof(Table));
	tp->t_tabname = name;
	tp->t_flag    = T_DEFAULT;
	tp->t_option  = NIL(char *);
	tp->t_prows   = 0;
	tp->t_srows   = 0;
	tp->t_ncols   = 0;
	tp->t_njoins  = 0;
	newlist(&tp->t_cols);
	newlist(&tp->t_join);
	tp->t_pkey    = NIL(Key *);
	tp->t_order   = NIL(Key *);

	return(tp);
}
