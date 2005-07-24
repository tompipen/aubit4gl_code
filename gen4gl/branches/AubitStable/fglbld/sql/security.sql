{
    @(#)$Id: security.sql,v 1.1 2002-06-16 07:36:15 afalout Exp $
'\" @(#)KPGB Sales Analysis System: Security
    @(#)Create Security Table
'\" @(#)Author: JL
}

{
Users are authorised to do an action if there is an entry in the
Security table with their login and the specified action.
}

{ Authorised actions }
CREATE TABLE Security
(
    User_id     CHAR(8)  NOT NULL,   { Name of user }
    Action      CHAR(12) NOT NULL    { Authorised action }
);
{
    PRIMARY KEY Security(User_id)
    FOREIGN KEY Security(Action)
        IDENTIFIES Action(Code)
}
CREATE UNIQUE INDEX ix_sec1 ON Security(User_id, Action);
CREATE INDEX ix_sec2 ON Security(Action);
REVOKE ALL ON Security FROM PUBLIC;
GRANT SELECT ON Security TO PUBLIC;
