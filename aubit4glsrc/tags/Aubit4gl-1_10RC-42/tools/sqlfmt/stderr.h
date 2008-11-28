/*
@(#)File:           $RCSfile: stderr.h,v $
@(#)Version:        $Revision: 1.3 $
@(#)Last changed:   $Date: 2003-05-15 07:10:51 $
@(#)Purpose:        Header file for standard error functions
@(#)Author:         J Leffler
@(#)Copyright:      (C) JLSS 1989-93,1996-98
@(#)Product:        SQLFMT Version 14 (1998-11-04)
*/  
  
#ifndef STDERR_H
#define STDERR_H
  
#ifdef MAIN_PROGRAM
#ifndef lint
static const char stderr_h[] =
  "@(#)$Id: stderr.h,v 1.3 2003-05-15 07:10:51 mikeaubury Exp $";

#endif	/* 
#endif	/* 
  
#include <stdio.h>
#include <stdarg.h>
  
/* -- Definitions for error handling */ 
  
#define ERR_STAT	(1)			/* Default exit status     */
  
#define ERR_COMM	(0x0001)		/* Print message on stderr  */
#define ERR_USAGE	(0x0002)		/* Print usage   on stderr  */
#define ERR_EXIT	(0x0004)		/* Exit  -- do not return   */
#define ERR_ABORT	(0x0008)		/* Abort -- do not return   */
#define ERR_FLUSH	(0x0010)		/* Flush stdout             */
#define ERR_STAMP	(0x0020)		/* Timestamp messages       */
#define ERR_NOARG0	(0x0040)		/* Do not print arg0 prefix */
#define ERR_PID		(0x0080)		/* Include pid=nnnnn info   */
#define ERR_ERRNO	(0x0100)		/* Include system error     */
  
/* -- Standard combinations of flags */ 
  
#define ERR_USE	(ERR_USAGE|ERR_EXIT|ERR_FLUSH)
#define ERR_REM	(ERR_COMM|ERR_FLUSH)
#define ERR_ERR	(ERR_COMM|ERR_EXIT|ERR_FLUSH)
#define ERR_ABT	(ERR_COMM|ERR_ABORT|ERR_FLUSH)
#define ERR_LOG	(ERR_STAMP|ERR_PID|ERR_COMM|ERR_FLUSH)
  
/* -- Global definitions */ 




				    size_t buflen);


			 va_list args);

			 ...);

			va_list args);










#endif	/* STDERR_H */