/*
@(#)File:            $RCSfile: sqltypes.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-16 07:36:15 $
@(#)Purpose:         Substitute sqltypes.h
@(#)Author:          J Leffler
*/

#ifndef SQLTYPES_H
#define SQLTYPES_H

/*
**  If a client has not got ESQL/C, this file gives sufficient information
**  for the code which uses SQL types to compile correctly.  It is, however,
**  subject to change if Informix ever change their version of the file.
*/

#define SQLCHAR		0
#define SQLSMINT	1
#define SQLINT		2
#define SQLFLOAT	3
#define SQLSMFLOAT	4
#define SQLDECIMAL	5
#define SQLSERIAL	6
#define SQLDATE		7
#define SQLMONEY	8

#endif	/* SQLTYPES_H */
