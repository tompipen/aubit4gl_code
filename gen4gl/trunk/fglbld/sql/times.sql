{
    @(#)$Id: times.sql,v 1.1 2002-06-16 07:36:15 afalout Exp $
'\" @(#)FGLBLD Documentation
    @(#)Create Timesheet Table
'\" @(#)Author: JL
}

CREATE TABLE Timesheet
(
    Ts_date            DATE           NOT NULL,
    Ts_from            CHAR(5)        NOT NULL,
    Ts_upto            CHAR(5)        NOT NULL,
    Jobid              INTEGER        NOT NULL,
    Notes              CHAR(60)
);
{
    PRIMARY KEY Timesheet(Ts_date, Ts_from)
    FOREIGN KEY Timesheet(Jobid)
        REFERENCES Jobs(Jobid)
}
CREATE UNIQUE INDEX timesheet_1 ON timesheet(ts_date, jobid, ts_from);
CREATE INDEX timesheet_2 ON timesheet(jobid);
