{
    @(#)$Id: jobs.sql,v 1.1 2002-06-16 07:36:15 afalout Exp $
'\" @(#)FGLBLD Documentation
    @(#)Create Jobs Table
'\" @(#)Author: JL
}

CREATE TABLE Jobs
(
    Jobid              SERIAL         NOT NULL,
    Clientid           INTEGER        NOT NULL,
    Started            DATE           NOT NULL,
    Completed          DATE,
    Notesfile          CHAR(50),
    Notes              CHAR(50)
);
{
    PRIMARY KEY Jobs(Jobid)
    FOREIGN KEY Jobs(Clientid)
        REFERENCES Clients(Clientid)
}
CREATE UNIQUE INDEX jobs_1 ON jobs(jobid);
CREATE INDEX jobs_2 ON jobs(clientid);
