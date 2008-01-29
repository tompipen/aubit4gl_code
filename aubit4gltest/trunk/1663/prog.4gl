{**
 * @file
 * NESTED report with agragates scrambles data in first report
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN

DEFINE mr RECORD
	   foli INT,
	   nubo INT,
	   cade CHAR(8),
	   npec CHAR(16),
	   sucu INT,
	   line INT,
	   fami INT,
	   orde INT,
	   prod INT,
	   cant INT,
	   cant2 INT,
           prog INT
        END RECORD,
        w_file CHAR(30)


create temp table fomrpedi (
	   foli INT,
	   nubo INT,
	   cade CHAR(8),
	   npec CHAR(16),
	   sucu INT,
	   line INT,
	   fami INT,
	   orde INT,
	   prod INT,
	   cant INT,
	   cant2 INT,
           prog INT )
LOAD FROM "rpedi.unl" INSERT INTO fomrpedi
DECLARE c_edi CURSOR FOR SELECT *  FROM fomrpedi
LET w_file = "out.expected"
{! LET w_file = "out" !}
START REPORT edirpedi_pedi TO w_file
FOREACH c_edi INTO mr.*
    OUTPUT TO REPORT edirpedi_pedi(mr.*)
END FOREACH
FREE c_edi
FINISH REPORT edirpedi_pedi
END MAIN

REPORT edirpedi_pedi(r)
DEFINE r RECORD
	   foli INT,
	   nubo INT,
	   cade CHAR(8),
	   npec CHAR(16),
	   sucu INT,
	   line INT,
	   fami INT,
	   orde INT,
	   prod INT,
	   cant INT,
	   cant2 INT,
           prog INT
	END RECORD,
	w_file CHAR(80)

OUTPUT
    TOP MARGIN 0
    LEFT MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 1

ORDER BY r.nubo, r.prog, r.cade, r.npec, r.sucu, 
         r.foli, r.line, r.fami, r.orde, r.prod

FORMAT
    BEFORE GROUP OF r.nubo
	IF r.nubo > 0 THEN
            LET w_file = "out0", r.nubo USING "<<<<"
            START REPORT edirpedi_bode TO w_file
	END IF

    ON EVERY ROW
        PRINT "r.foli = ", r.foli, " r.prod=", r.prod, ",r.nubo=", r.nubo

    AFTER GROUP OF r.prod
	IF r.nubo > 0 THEN
            OUTPUT TO REPORT edirpedi_bode(r.*)
	END IF

    AFTER GROUP OF r.nubo
	IF r.nubo > 0 THEN
            FINISH REPORT edirpedi_bode 
	END IF

END REPORT

REPORT edirpedi_bode(r)
DEFINE r RECORD
	   foli INT,
	   nubo INT,
	   cade CHAR(8),
	   npec CHAR(16),
	   sucu INT,
	   line INT,
	   fami INT,
	   orde INT,
	   prod INT,
	   cant INT,
	   cant2 INT,
           prog INT
	END RECORD 

OUTPUT
    TOP MARGIN 0
    LEFT MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 1

ORDER EXTERNAL BY r.cade, r.npec, r.sucu, r.foli 

FORMAT
    AFTER GROUP OF r.foli
	PRINT COLUMN 20, "Total",
	      COLUMN 40, group sum(r.cant) USING "###,##&"  ,
	      COLUMN 50, group sum(r.cant2) USING "###,##&"  ,
	      COLUMN 60, group sum(r.cant - r.cant2) USING "###,##&"

END REPORT
