-- @(#)$Id: report.4gl,v 1.1 2002-11-28 06:40:47 afalout Exp $
-- @(#)Code to demonstrate I4GLXREF program

DATABASE Example

REPORT report_name(r_table1)

    DEFINE
        r_table1    RECORD LIKE Table1.*

    FORMAT EVERY ROW

END REPORT {report_name}
