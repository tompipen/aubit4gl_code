/*
@(#)File:            $RCSfile: connect.h,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL Header for CONNECT, DISCONNECT and SET CONNECTION
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1995
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#ifndef CONNECT_H
#define CONNECT_H

#ifdef MAIN_PROGRAM
#ifndef lint
static char connect_h[] = "@(#)$Id: connect.h,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

/* -- Constant Definitions */

#define MAX_CONN_NAME	18
#define MAX_USER_NAME	18
#define MAX_AUTH_NAME	18
#define MAX_DBASE_NAME	80

/* -- Declarations */

/* CONNECT TO DEFAULT */
extern int connect_default(int n);
/* CONNECT TO "db" AS "conn_name" */
extern int connect_dbase_by_name(int n);
/* CONNECT TO "db" AS "conn_name" USER 'uname' USING 'auth' */
extern int connect_dbase_by_name_user(int n);

/* CONNECT TO DEFAULT WITH CONCURRENT TRANSACTION */
extern int connect_default_wct(int n);
/* CONNECT TO "db" AS "conn_name" WITH CONCURRENT TRANSACTION */
extern int connect_dbase_by_name_wct(int n);
/* CONNECT TO "db" AS "conn_name" USER 'uname' USING 'auth'
		WITH CONCURRENT TRANSACTION */
extern int connect_dbase_by_name_user_wct(int n);

/* DISCONNECT CURRENT */
extern int disconnect_current(int n);
/* DISCONNECT DEFAULT */
extern int disconnect_default(int n);
/* DISCONNECT "conn_name" */
extern int disconnect_by_name(int n);

/* SET CONNECTION DEFAULT */
extern int set_connection_default(int n);
/* SET CONNECTION "conn_name" */
extern int set_connection_by_name(int n);

#endif	/* CONNECT_H */
