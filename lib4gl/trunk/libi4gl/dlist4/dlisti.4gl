head	4.1;
access;
symbols;
locks; strict;
comment	@# @;


4.1
date	91.11.17.22.11.17;	author jl;	state Exp;
branches;
next	3.3;

3.3
date	88.11.15.11.48.49;	author john;	state Exp;
branches;
next	3.2;

3.2
date	88.11.15.11.33.25;	author john;	state Exp;
branches;
next	3.1;

3.1
date	88.11.14.13.04.24;	author john;	state Exp;
branches;
next	;


desc
@@


4.1
log
@Extend diagnostic printing -- not very neatly
@
text
@{
	@@(#)$Id: dlisti.4gl,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)Test code to check functionality of D-lists -- INTEGERS
}

DEFINE
	list		ARRAY[4] OF INTEGER,
	n_list		INTEGER,
	seed		INTEGER

MAIN

	DEFINE
		sccs		CHAR(32),
		i,j,k,l,m,n	INTEGER

	LET sccs = "@@(#)$Id: dlisti.4gl,v 1.1 2002-06-14 05:03:45 afalout Exp $"
	LET n_list = 4

	FOR i = 1 TO n_list
		LET list[i] = sc_create()
		IF list[i] <= 0 THEN
			ERROR "Failed to create list[", i USING "&",
				  "] with status", list[i] USING "---&"
			SLEEP 3
			EXIT PROGRAM
		ELSE
			DISPLAY "created list[", i USING "&", "] with index = ",
					list[i] USING "&" AT i, 1
		END IF
		CALL slow_me_up()
	END FOR

	DISPLAY "Inserting rows" AT 5, 1
	FOR i = 1 TO 100
		DISPLAY "Inserting row ", i AT 5, 1
		LET j = i4gl_random() MOD n_list + 1
		LET n = i4gl_random() MOD (i / n_list + 1) + 1
		DISPLAY "get row ", n USING "--&", " from list ",
				j USING "-&&" AT 6, 1
		CALL sc_select(list[j], 'A', n)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "--&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		ELSE
			DISPLAY "Select return: l = ", l USING "---&",
					" k = ", k USING "---&" AT 7, 30
		END IF
		IF sc_insert(list[j], i) < 0 THEN
			ERROR "Failed to insert into list[", j USING "&",
				  "] with status", list[j] USING "---&"
			SLEEP 3
			ERROR "Continuing"
		END IF
		LET l = sc_count(list[j])
		DISPLAY "List count ", l USING "--&" AT 7, 1
		CALL slow_me_up()
	END FOR
	DISPLAY "Insert finished" AT 7, 1
	SLEEP 1

	CALL dump_lists()
	SLEEP 1

	DISPLAY "Delete some rows" AT 8, 1
	FOR i = 1 TO 20
		LET j = i4gl_random() MOD n_list + 1
		LET n = i4gl_random() MOD ((100 - i) / n_list) + 1
		DISPLAY "get row ", n USING "--&", " from list ",
				j USING "--&" AT 9, 1
		CALL sc_select(list[j], 'A', n)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "--&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		ELSE
			DISPLAY "Select return: l = ", l USING "---&",
					" k = ", k USING "---&" AT 10, 30
		END IF
		DISPLAY "Delete row ", l USING "--&" AT 11, 1
		LET k = sc_delete(list[j])
		IF k < 0 THEN
			ERROR "Failed to delete from list[", j USING "&",
				  "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		END IF
		CALL slow_me_up()
	END FOR
	DISPLAY "Delete finished" AT 10, 1
	SLEEP 1

	CALL dump_lists()
	SLEEP 1

END MAIN

FUNCTION dump_lists()

	DEFINE
		i,j,k,l,m,n	INTEGER

	DISPLAY "Dump lists" AT 12, 1
	FOR i = 1 TO n_list
		LET m = (i - 1) * 20 + 1
		DISPLAY "Dump list ", i USING "&" AT 13, m
		LET n = sc_count(list[i])
		DISPLAY "Entries = ", n USING "--&" AT 14, m
		FOR j = 1 TO n
			CALL sc_select(list[i], 'A', j) RETURNING k, l
			IF k < -1 THEN
				ERROR "Failed to get row ", j USING "--&",
					  "from list[", i USING "&", "] with status", k USING "---&"
				SLEEP 3
				ERROR "Continuing"
			END IF
			DISPLAY "Entry[", j USING "#&", "] = ", l USING "--&" AT 15, m
			CALL slow_me_up()
		END FOR
	END FOR
	DISPLAY "Dump complete" AT 16, 1

END FUNCTION {dump_lists}

FUNCTION slow_me_up()

	DEFINE
		i	INTEGER

	FOR i = 1 TO 2000
		LET i = i
	END FOR

END FUNCTION {slow_me_up}
@


3.3
log
@Tidy up screen layout
@
text
@d6 5
a13 1
		list		ARRAY[4] OF INTEGER,
d15 2
a16 2
		i,j,k,l,n	INTEGER
	
d18 1
d20 2
a21 2
	FOR i = 1 TO 4
		LET list[i] = sc_mkint()
d31 1
d34 1
d36 6
a41 5
		LET j = hash(i)
		LET n = hash(j+3)*4
		DISPLAY "get row ", n USING "##&", " from list ",
				j USING "&" AT 5, 1
		CALL sc_getint(list[j], 'A', hash(j+3)*4)
d44 1
a44 1
			ERROR "Failed to get row ", j USING "##&",
d47 4
d52 1
a52 1
		IF sc_insint(list[j], i) < 0 THEN
d56 1
d58 3
d62 5
d68 1
d70 5
a74 2
		LET j = hash(i+37)
		CALL sc_getint(list[j], 'A', hash(j+6)*4)
d77 1
a77 1
			ERROR "Failed to get row ", j USING "##&",
d80 4
d85 2
a86 1
		LET k = sc_delint(list[j])
d91 1
d93 1
d95 5
d101 13
a113 4
	FOR i = 1 TO 4
		DISPLAY "Dump of list number ", i USING "&" AT 6, 1
		LET n = sc_numint(list[i])
		DISPLAY "Number of entries = ", n USING "##&" AT 7, 1
d115 1
a115 1
			CALL sc_getint(list[i], 'A', j) RETURNING k, l
d117 1
a117 1
				ERROR "Failed to get row ", j USING "##&",
d120 1
d122 2
a123 1
			DISPLAY "Entry[", j USING "#&", "] = ", l USING "##&" AT 8, 1
d126 1
d128 1
a128 1
END MAIN
d130 1
a130 1
FUNCTION hash(i)
d133 1
a133 1
		i, j	INTEGER
d135 3
a137 1
	RETURN ((i * 41) / 7) MOD 4 + 1
d139 1
a139 1
END FUNCTION
@


3.2
log
@Tighten up a little
@
text
@d31 1
a31 1
		DISPLAY "get row ", n USING "<<<", " from list ",
d36 1
a36 1
			ERROR "Failed to get row ", j USING "<<<",
d52 1
a52 1
			ERROR "Failed to get row ", j USING "<<<",
d71 1
a71 1
				ERROR "Failed to get row ", j USING "<<<",
@


3.1
log
@Initial revision
@
text
@d10 1
d13 2
d35 1
a35 1
		IF k < 0 THEN
d51 1
a51 1
		IF k < 0 THEN
d70 1
a70 1
			IF k < 0 THEN
@
