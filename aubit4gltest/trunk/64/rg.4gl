

MAIN

	DEFINE
		rec		RECORD
			a	INTEGER,
			b	INTEGER,
			c	INTEGER
		END RECORD

	START REPORT rg TO "rg.out"
	START REPORT rg_2 TO "rg_2.out"
	START REPORT rg_3 TO "rg_3.out"

	FOR rec.a = 1 TO 3
		FOR rec.b = 1 TO 4
			FOR rec.c = 1 TO 5
				OUTPUT TO REPORT rg (rec.a,rec.b,rec.c)
				OUTPUT TO REPORT rg_2 (rec.*)
				OUTPUT TO REPORT rg_3 (rec.*)
			END FOR
		END FOR
	END FOR
				
	FINISH REPORT rg
	FINISH REPORT rg_2
	FINISH REPORT rg_3


	START REPORT rg TO "rg_empty.out"
	FINISH REPORT rg

	START REPORT rg_header TO "rg_header.out"
		output to report rg_header(1)
	FINISH REPORT rg_header

	START REPORT rg_header_trailer TO "rg_header_trailer.out"
		output to report rg_header_trailer(1)
	FINISH REPORT rg_header_trailer

	START REPORT rg_header TO "rg_header_empty.out"
	FINISH REPORT rg_header

	START REPORT rg_header_trailer TO "rg_header_trailer_empty.out"
	FINISH REPORT rg_header_trailer

END MAIN

REPORT rg (rec)

	DEFINE
		rec		RECORD
			a	INTEGER,
			b	INTEGER,
			c	INTEGER
		END RECORD

	OUTPUT
		TOP MARGIN 0
		BOTTOM MARGIN 0
		PAGE LENGTH 20

	FORMAT

	PAGE HEADER
		PRINT "PAGE HEADER ", rec.a, rec.b

	BEFORE GROUP OF rec.a
		PRINT "BEFORE GROUP LEVEL a =", rec.a

	BEFORE GROUP OF rec.b
		PRINT "  BEFORE GROUP LEVEL b =", rec.b

	ON EVERY ROW
		PRINT "    ROW ", rec.a, rec.b, rec.c

	AFTER GROUP OF rec.b
		PRINT "  AFTER GROUP LEVEL b =", rec.b

	AFTER GROUP OF rec.a
		PRINT "AFTER GROUP LEVEL a =", rec.a

	PAGE TRAILER
		PRINT "PAGE TRAILER ",rec.a, rec.b

END REPORT

REPORT rg_2 (rec)

	DEFINE
		rec		RECORD
			a	INTEGER,
			b	INTEGER,
			c	INTEGER
		END RECORD

	OUTPUT
		TOP MARGIN 0
		BOTTOM MARGIN 0
		PAGE LENGTH 20

	FORMAT

	PAGE HEADER
		PRINT "PAGE HEADER ", rec.a, rec.b

	BEFORE GROUP OF rec.a
		PRINT "BEFORE GROUP LEVEL a =", rec.a

	BEFORE GROUP OF rec.b
		PRINT "  BEFORE GROUP LEVEL b =", rec.b

	ON EVERY ROW
		PRINT "    ROW ", rec.a, rec.b, rec.c

	AFTER GROUP OF rec.b
		PRINT "  AFTER GROUP LEVEL b =", rec.b

	AFTER GROUP OF rec.a
		PRINT "AFTER GROUP LEVEL a =", rec.a
		SKIP TO TOP OF PAGE

	PAGE TRAILER
		PRINT "PAGE TRAILER ",rec.a, rec.b

END REPORT

REPORT rg_3 (rec)

	DEFINE
		rec		RECORD
			a	INTEGER,
			b	INTEGER,
			c	INTEGER
		END RECORD

	OUTPUT
		TOP MARGIN 0
		BOTTOM MARGIN 0
		PAGE LENGTH 20

	FORMAT

	PAGE HEADER
		PRINT "PAGE HEADER ", rec.a, rec.b

	BEFORE GROUP OF rec.a
		SKIP TO TOP OF PAGE
		PRINT "BEFORE GROUP LEVEL a =", rec.a

	BEFORE GROUP OF rec.b
		PRINT "  BEFORE GROUP LEVEL b =", rec.b

	ON EVERY ROW
		PRINT "    ROW ", rec.a, rec.b, rec.c

	AFTER GROUP OF rec.b
		PRINT "  AFTER GROUP LEVEL b =", rec.b

	AFTER GROUP OF rec.a
		PRINT "AFTER GROUP LEVEL a =", rec.a

	PAGE TRAILER
		PRINT "PAGE TRAILER ",rec.a, rec.b

END REPORT


REPORT rg_header(a)
define a integer
format
page header
	print "Page Header"

END REPORT 

REPORT rg_header_trailer(a)
define a integer
format
page header
	print "Page Header"

page trailer
	print "Page Trailer"

END REPORT 

