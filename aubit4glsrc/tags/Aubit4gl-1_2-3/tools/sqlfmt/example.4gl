-- @(#)$Id: example.4gl,v 1.1 2002-11-28 06:40:47 afalout Exp $
-- @(#)Code to demonstrate I4GLXREF program

DATABASE Example

MAIN

    DEFINE
        r_table1    RECORD LIKE Table1.*,
        tab_id      LIKE Table1.Column01,
        duration    INTERVAL DAY(5) TO FRACTION(3), -- defined but not used
        counter     INTEGER                         -- defined but not used

    OPEN WINDOW w_demo AT 2, 2 WITH 21 ROWS, 78 COLUMNS ATTRIBUTE (BORDER)
    OPEN FORM f_demo FROM "demo"
    DISPLAY FORM f_demo
    LET tab_id = 1000       # Implausible
    START REPORT report_name
    DECLARE c_select CURSOR FOR
        SELECT * FROM Table1 WHERE Column01 = tab_id FOR UPDATE OF Column03

    { This sort of comment is understood as well as -- and # comments! }
    FOREACH c_select INTO r_table1.*
        LET r_table1.column03 = compute(r_table1.column02, r_table1.column03)
        DISPLAY r_table1.* TO s_table1.*
        UPDATE Table1 SET Column03 = r_table1.column03
            WHERE CURRENT OF c_select
        OUTPUT TO REPORT report_name(r_table1.*)
        SLEEP 3
    END FOREACH

    FINISH REPORT report_name
    CLOSE FORM f_demo
    CLOSE WINDOW w_demo
    FREE c_select

END MAIN
