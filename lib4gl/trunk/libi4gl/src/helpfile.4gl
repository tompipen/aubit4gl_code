head	1.5;
access;
symbols;
locks; strict;
comment	@# @;


1.5
date	91.08.19.22.29.34;	author jl;	state Exp;
branches;
next	1.4;

1.4
date	91.08.19.22.26.04;	author jl;	state Exp;
branches;
next	1.3;

1.3
date	91.05.22.12.10.48;	author johnl;	state Exp;
branches;
next	1.2;

1.2
date	91.05.09.15.16.46;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.08.06.16.18.06;	author john;	state Exp;
branches;
next	;


desc
@@


1.5
log
@Remove stray line and stray comma
@
text
@-- @@(#)$Id: helpfile.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Maintain stack of helpfile names
-- @@(#)Author: JL

{
This code maintains a stack of help file names.  Whenever a new file
is pushed onto the stack, the stack pointer is incremented.  If there
is still space on the stack, the name is put onto the stack; in any
case, it is made into the current help file.  The pop function
recogises whether it has a record of the correct help file name, and
if it has, the current help file is changed; in any case, the stack
pointer is decremented unless it would then go negative.
}

DEFINE
	stack		ARRAY[10] OF CHAR(64),
	sp			INTEGER

{ Push helpfile on to stack and make it the current help file }
FUNCTION psh_helpfile(filename)

	DEFINE
		filename	CHAR(64),
		junk		INTEGER

	LET sp = sp + 1
	IF sp <= 10 THEN
		LET stack[sp] = filename
	END IF

	OPTIONS HELP FILE filename
	LET junk = fgl_msgopen(filename)

END FUNCTION {psh_helpfile}

{ Pop helpfile off stack and make it the current help file }
FUNCTION pop_helpfile()

	DEFINE
		filename	CHAR(64),
		junk		INTEGER

	IF sp > 0 AND sp <= 10 THEN
		LET filename = stack[sp]
		OPTIONS HELP FILE filename
		LET junk = fgl_msgopen(filename)
	END IF

	IF sp > 0 THEN
		LET sp = sp - 1
	END IF

END FUNCTION {pop_helpfile}

{ Return name of current help file }
FUNCTION cur_helpfile()

	DEFINE
		filename	CHAR(64),
		sccs		CHAR(1)

	IF sp > 0 AND sp <= 10 THEN
		LET filename = stack[sp]
	ELSE
		LET filename = NULL
		LET sccs = "@@(#)$Id: helpfile.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	END IF

	RETURN filename

END FUNCTION {cur_helpfile}

{ Return text of message number from help file }
FUNCTION help_message(msgnum)

	DEFINE
		msgnum	INTEGER,
		s		CHAR(512)

	IF sp > 0 AND sp <= 10 THEN
		LET s = fgl_msgread(msgnum)
	ELSE
		LET s = NULL
	END IF

	RETURN s

END FUNCTION {help_message}
@


1.4
log
@Use fgl_msgopen and fgl_msgread
@
text
@a5 1

d25 1
a25 1
		junk		INTEGER,
@


1.3
log
@Add help_message function
@
text
@d25 2
a26 1
		filename	CHAR(64)
d34 1
d42 2
a43 1
		filename	CHAR(64)
d48 1
d83 1
a83 1
		LET s = fgl_msgtext(stack[sp], msgnum)
@


1.2
log
@Upgrade
@
text
@d70 17
@


1.1
log
@Initial revision
@
text
@d1 4
a4 6
{
	@@(#)$Id: helpfile.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Maintain stack of helpfile names
	@@(#)Author: JL
}
d57 2
a58 1
		filename	CHAR(64)
d64 1
@
