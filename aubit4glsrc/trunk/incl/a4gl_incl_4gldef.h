/* *****************************************************************************
 * (c) 1997-2002 Aubit Computing Ltd.
 *
 * $Id: a4gl_incl_4gldef.h,v 1.2 2002-05-18 14:57:29 mikeaubury Exp $
 *
 * Change History :
 *	$Log: not supported by cvs2svn $
 *	Revision 1.1  2002/04/25 06:32:46  afalout
 *	Adding a4gl_xxx_ prefix to remaining header files
 *	
 *	Revision 1.1  2002/04/13 11:09:49  saferreira
 *	Informix connector
 *	
 *
 *****************************************************************************/

/**
 * @file 
 *
 * Definition of structures and typedefs necessary in both lib and generated 
 * C code.
 *
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 */

#ifndef FGLDEF_INCL
#define FGLDEF_INCL

#include <stdio.h>

/**
 * Decimal 4gl data type variable definition
 */
typedef struct  {
	char data[64]; /**< The value stored in decimal variable */
} fgldecimal;

/** This type name is just to have some pattern in type names */
typedef fgldecimal FglDecimal;

typedef fgldecimal FglMoney;

/**
 * Money 4gl data type variable definition 
 */
typedef struct  {
	char data[64]; /**< The value stored in money variable */
} fglmoney;


/** SQLCA structure definition */
typedef struct {
	int sqlcode;
	char sqlerrm[73];
	char sqlerrp[9];
	int sqlerrd[6];
	char sqlawarn[9];
	char sqlstate[10];
} sqlca_struct;


/**
 * Binding information structure definition.
 * Used to bind values to and from SQL.
 */
struct BINDING {
	void *ptr; /**< A pointer to the variable bounded */
	int dtype; /**< The data type of the variable bounded */
	long size; /**< The size in bytes of the variable bounded */
};

/**
 * Location definition structure for blobs.
 */
struct fgl_int_loc {
  char where;
  FILE *f;
  long memsize;
  char filename[256];
  void *ptr;
};

#define fglbyte struct fgl_int_loc

/** 4gl Byte data type */
typedef struct fgl_int_loc FglByte;

#define fgltext struct fgl_int_loc

/** 4gl Text data type */
typedef struct fgl_int_loc FglText;

/** Date data type */
typedef long FglDate;

/**
 * Datetime value variable type.
 *
 * The name was chaged due to imcompatibility with esql/c
 * 
 * The values in qualifiers are :
 *   - 1 : YEAR
 *   - 2 : MONTH
 *   - 3 : DAY
 *   - 4 : HOUR
 *   - 5 : MINUTE
 *   - 6 : SECOND
 *   - > 6 FRACTION + precision of fraction (2 by default)
 */
struct A4GLSQL_dtime {
    int stime;     /**< The start qualifier */
    int ltime;     /**< The end qualifier */
    char data[32]; /**< The information in the var */
};

/** Date time defined without typedef. To be deprecated */
#define struct_dtime struct A4GLSQL_dtime

/** 4gl Interval data type definition */
typedef struct A4GLSQL_dtime FglDatetime;

/**
 * Interval variable data type.
 */
#define IVAL_STRUCT
struct ival {
    int stime;     /**< The start qualifier */
    int ltime;     /**< The end qualifier */
    char data[32]; /**< The value of the interval variable */
};

#define struct_ival struct ival

/** 4gl Datetime data type definition */
typedef struct ival FglInterval;


#endif
