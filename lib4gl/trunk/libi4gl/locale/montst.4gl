head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	91.11.17.16.35.19;	author jl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@-- @@(#)File:            $RCSfile: montst.4gl,v $
-- @@(#)Version:         $Revision: 1.1 $
-- @@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
-- @@(#)Purpose:         Test program for LOCALE table (Informix)
-- @@(#)Author:          J Leffler

DATABASE Test

MAIN

	DEFINE
		locale	ARRAY[2] OF CHAR(2),
		fmtcode	INTEGER,
		fmt		CHAR(40),
		val		DECIMAL(16),
		i		INTEGER,
		j		INTEGER,
		k		INTEGER

	LET locale[1] = "C"
	LET locale[2] = "UK"
	FOR i = 1 TO 2
		IF i4gl_set_locale(locale[i]) = 0 THEN
			LET fmt = i4gl_get_locale()
			DISPLAY "Locale: ", fmt CLIPPED
			LET val = 1.234567
			FOR j = 1 TO 10 STEP 2
				FOR fmtcode =  -3 TO 3
					FOR k = 1 TO 2
						LET fmt = i4gl_fmt_money(val, fmtcode)
						DISPLAY "code = ", fmtcode USING "-&",
								" val = ", val USING "--,---,---,---,--&.&&",
								" fmt = ", fmt CLIPPED
						LET val = -val
					END FOR
				END FOR
				LET val = val * 100.0
			END FOR
		ELSE
			ERROR "Could not set locale to ", locale[i]
		END IF
	END FOR

END MAIN
@
