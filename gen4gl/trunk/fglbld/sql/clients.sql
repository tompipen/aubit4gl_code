{
    @(#)$Id: clients.sql,v 1.1 2002-06-16 07:36:15 afalout Exp $
'\" @(#)FGLBLD Documentation
    @(#)Create Clients Table
'\" @(#)Author: JL
}

CREATE TABLE Clients
(
    Clientid           SERIAL         NOT NULL,
    Client             CHAR(40)       NOT NULL,
    Contact            CHAR(40)       NOT NULL,
    Phone              CHAR(20)       NOT NULL,
    Telex              CHAR(15),
    Ansback            CHAR(6),
    Fax                CHAR(15),
    Notes              CHAR(50)
);
{
    PRIMARY KEY Clients(Clientid)
}
CREATE UNIQUE INDEX clients_1 ON clients(clientid);
