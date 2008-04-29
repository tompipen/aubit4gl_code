{**
 * @file
 * INPUT with several THRU, only first is taken
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE lr record
         a1 int,
         a2 char(1),
         a3 date,
         a4 int,
         a5 date,
         a6 char(10)
       end record,
       av_b char(10)

OPEN WINDOW v1 AT 1,1 WITH FORM "t1677" ATTRIBUTE(DIM)
LET av_b = "X"
LET lr.a6 = "X"
INPUT BY NAME lr.a1 thru lr.a3, 
              av_b,
              lr.a4 thru lr.a6 WITHOUT DEFAULTS 
           ATTRIBUTE(UNDERLINE,BOLD)
     ON KEY (ESC)
        EXIT INPUT
END INPUT
CLOSE WINDOW v1
IF av_b <> "4" THEN display "bad ", av_b EXIT PROGRAM 1 END IF
IF lr.a6 <> "7" THEN display "bad ", lr.a6 EXIT PROGRAM 2 END IF
DISPLAY "ok" EXIT PROGRAM 0
END MAIN
