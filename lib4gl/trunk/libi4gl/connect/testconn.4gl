-- @(#)$Id: testconn.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
--
-- Basic tests for CONNECT, DISCONNECT and SET CONNECTION routines
-- callable from I4GL 6.00 or later.

MAIN

    DEFINE
        dbase   CHAR(80),
        ucon1   CHAR(18),
        ucon2   CHAR(18),
        uname   CHAR(18),
        uauth   CHAR(18)
    DEFINE
        retval  INTEGER

    LET dbase = "stores"
    LET ucon1 = "conn_1"
    LET ucon2 = "conn_2"
    LET uname = "ghenghis"
    LET uauth = "The Kahn"

	DISPLAY " No current connections "

	DATABASE dbase
	DISPLAY sqlca.sqlcode, " DATABASE"

    LET retval = connect_dbase_by_name_wct(dbase, ucon1)
	DISPLAY retval, " CONNECT BY NAME WCT"
    LET retval = connect_dbase_by_name_user_wct(dbase, ucon2, uname, uauth)
	DISPLAY retval, " CONNECT BY NAME AND USER WCT"

    LET retval = set_connection_default()
	DISPLAY retval, " SET CONNECT DEFAULT"
    LET retval = set_connection_by_name(ucon1)
	DISPLAY retval, " SET CONNECT BY NAME"

    LET retval = set_connection_default()
	DISPLAY retval, " SET CONNECT DEFAULT"
    LET retval = disconnect_current()
	DISPLAY retval, " DISCONNECT CURRENT"

    LET retval = disconnect_by_name(ucon1)
	DISPLAY retval, " DISCONNECT BY NAME"
    LET retval = disconnect_by_name(ucon2)
	DISPLAY retval, " DISCONNECT BY NAME"

	DISPLAY " No current connections "

    LET retval = connect_default_wct()
	DISPLAY retval, " CONNECT DEFAULT WCT"
    LET retval = disconnect_default()
	DISPLAY retval, " DISCONNECT DEFAULT"

	DISPLAY " No current connections "

    LET retval = connect_default()
	DISPLAY retval, " CONNECT DEFAULT"
    LET retval = connect_dbase_by_name(dbase, ucon1)
	DISPLAY retval, " CONNECT BY NAME"
    LET retval = connect_dbase_by_name_user(dbase, ucon2, uname, uauth)
	DISPLAY retval, " CONNECT BY NAME AND USER"

    LET retval = disconnect_current()
	DISPLAY retval, " DISCONNECT CURRENT"
    LET retval = disconnect_default()
	DISPLAY retval, " DISCONNECT DEFAULT"
    LET retval = disconnect_by_name(ucon1)
	DISPLAY retval, " DISCONNECT BY NAME"

	DISPLAY " No current connections "

END MAIN
