
#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

DATABASE test1

MAIN

DEFINE l_f2 CHAR(10)
    CREATE TEMP TABLE testfirst (campo1 int, campo2 char(10))
    INSERT INTO testfirst VALUES (1, "a")
    INSERT INTO testfirst VALUES (1, "b")
{
    SQL
    SELECT campo2 INTO $l_f2 FROM testfirst WHERE campo1 = 1
    END SQL
    DISPLAY "f2=", l_f2
}

    SQL
    SELECT FIRST 1 campo2 INTO $l_f2 FROM testfirst WHERE campo1 = 1
    END SQL
    DISPLAY "f2=", l_f2
	
END MAIN

