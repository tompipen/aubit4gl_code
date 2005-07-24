/*
@(#)File:            $RCSfile: connect.ec,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL interface to CONNECT, DISCONNECT, SET CONNECTION
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1995
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

/* -- Include Files */

#include <sqlca.h>
#include "connect.h"

#ifndef lint
static char     sccs[] = "@(#)$Id: connect.ec,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

static char module_name[] = "$RCSfile: connect.ec,v $";

/* CONNECT TO DEFAULT */
int connect_default(int n)
{
	if (n != 0)
		fgl_fatal(module_name, __LINE__, -1318);
	EXEC SQL CONNECT TO DEFAULT;
	retint(sqlca.sqlcode);
	return(1);
}

/* CONNECT TO "db" AS "conn_name" */
int connect_dbase_by_name(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	dbase[MAX_DBASE_NAME + 1];
	char	uconn[MAX_CONN_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 2)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uconn, sizeof(uconn));
	popstring(dbase, sizeof(dbase));
	EXEC SQL CONNECT TO :dbase AS :uconn;
	retint(sqlca.sqlcode);
	return(1);
}

/* CONNECT TO "db" AS "conn_name" USER 'uname' USING 'auth' */
int connect_dbase_by_name_user(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	dbase[MAX_DBASE_NAME + 1];
	char	uconn[MAX_CONN_NAME + 1];
	char	uname[MAX_USER_NAME + 1];
	char	uauth[MAX_AUTH_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 4)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uauth, sizeof(uauth));
	popstring(uname, sizeof(uname));
	popstring(uconn, sizeof(uconn));
	popstring(dbase, sizeof(dbase));
	EXEC SQL CONNECT TO :dbase AS :uconn USER :uname USING :uauth;
	retint(sqlca.sqlcode);
	return(1);
}


/* CONNECT TO DEFAULT WITH CONCURRENT TRANSACTION */
int connect_default_wct(int n)
{
	if (n != 0)
		fgl_fatal(module_name, __LINE__, -1318);
	EXEC SQL CONNECT TO DEFAULT
				WITH CONCURRENT TRANSACTION;
	retint(sqlca.sqlcode);
	return(1);
}

/* CONNECT TO "db" AS "conn_name" WITH CONCURRENT TRANSACTION */
int connect_dbase_by_name_wct(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	dbase[MAX_DBASE_NAME + 1];
	char	uconn[MAX_CONN_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 2)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uconn, sizeof(uconn));
	popstring(dbase, sizeof(dbase));
	EXEC SQL CONNECT TO :dbase AS :uconn
				WITH CONCURRENT TRANSACTION;
	retint(sqlca.sqlcode);
	return(1);
}

/* CONNECT TO "db" AS "conn_name" USER 'uname' USING 'auth'
		WITH CONCURRENT TRANSACTION */
int connect_dbase_by_name_user_wct(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	dbase[MAX_DBASE_NAME + 1];
	char	uconn[MAX_CONN_NAME + 1];
	char	uname[MAX_USER_NAME + 1];
	char	uauth[MAX_AUTH_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 4)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uauth, sizeof(uauth));
	popstring(uname, sizeof(uname));
	popstring(uconn, sizeof(uconn));
	popstring(dbase, sizeof(dbase));
	EXEC SQL CONNECT TO :dbase AS :uconn USER :uname USING :uauth
				WITH CONCURRENT TRANSACTION;
	retint(sqlca.sqlcode);
	return(1);
}


/* DISCONNECT CURRENT */
int disconnect_current(int n)
{
	if (n != 0)
		fgl_fatal(module_name, __LINE__, -1318);
	EXEC SQL DISCONNECT CURRENT;
	retint(sqlca.sqlcode);
	return(1);
}

/* DISCONNECT DEFAULT */
int disconnect_default(int n)
{
	if (n != 0)
		fgl_fatal(module_name, __LINE__, -1318);
	EXEC SQL DISCONNECT DEFAULT;
	retint(sqlca.sqlcode);
	return(1);
}

/* DISCONNECT "conn_name" */
int disconnect_by_name(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	uconn[MAX_CONN_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 1)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uconn, sizeof(uconn));
	EXEC SQL DISCONNECT :uconn;
	retint(sqlca.sqlcode);
	return(1);
}

/* SET CONNECTION DEFAULT */
int set_connection_default(int n)
{
	if (n != 0)
		fgl_fatal(module_name, __LINE__, -1318);
	EXEC SQL SET CONNECTION DEFAULT;
	retint(sqlca.sqlcode);
	return(1);
}

/* SET CONNECTION "conn_name" */
int set_connection_by_name(int n)
{
	EXEC SQL BEGIN DECLARE SECTION;
	char	uconn[MAX_CONN_NAME + 1];
	EXEC SQL END DECLARE SECTION;

	if (n != 1)
		fgl_fatal(module_name, __LINE__, -1318);
	popstring(uconn, sizeof(uconn));
	EXEC SQL SET CONNECTION :uconn;
	retint(sqlca.sqlcode);
	return(1);
}
