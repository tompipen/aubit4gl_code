/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: pack_xdr.c,v 1.2 2002-07-21 09:56:42 afalout Exp $
#*/

/**
 * @file
 *
 * We don't actually do much in here
 * we just use the name of the datatype specified
 * to identify the xdr routine to call
 * and then - call it...
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL
	#include <stdio.h>
	#include "rpc/rpc.h"
#else
	#include "rpc/rpc.h"
	#define _NO_FORM_X_H_
	/* FIXME: this should be a4gl_lib_packer_xdr_int.h */
	#include "a4gl_libaubit4gl.h"
#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int unpack_all(char *name,void *s,char *filename);
int pack_all(char *name,void *s,char *filename);
int A4GLPACKER_initlib (void);
int can_pack_all(char* name);
int open_packer(char *fname,int dir) ;
int close_packer(int dir);


static int (*func)(); /*  warning: function declaration isn't a prototype */
static int process_xdr(char dir,char *name,void *s,char *filename) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
A4GLPACKER_initlib (void)
{
	return 1;
}

/**
 *
 * @todo Describe function
 */
int 
can_pack_all(char* name) 
{
	void *libptr;
  	libptr=(void *)dl_openlibrary("XDRPACKER",name);
	if (libptr) return 1;
	return -1;
}



/*
   We don't need to worry about these two functions
   as we're doing the whole thing in one go using xdr
*/
int open_packer(char *fname,int dir)  { return 0; }
int close_packer(int dir) { return 0; }


/**
 *
 * @todo Describe function
 */
int
pack_all(char *name,void *s,char *filename)
{
	return process_xdr('O',name,s,filename);
}


/**
 *
 * @todo Describe function
 */
int
unpack_all(char *name,void *s,char *filename)
{
	return process_xdr('I',name,s,filename);
}


/**
 *
 * @todo Describe function
 */
static int
process_xdr(char dir,char *name,void *s,char *filename)
{
FILE *fxx;
void *libptr;
char buff[256];
XDR xdrp;

  sprintf(buff,"xdr_%s",name);

  libptr=(void *)dl_openlibrary("XDRPACKER",name);
  if (libptr==0) return 0;

  /*
   We can only write to the current directory - but we
   can open files from anywhere on the dbpath
  */
	if (dir=='O')
	  fxx = fopen(filename,"wb");
	else
	  fxx = (FILE *) open_file_dbpath (filename);


  if (fxx==0) return 0;


	if (dir=='O')
	  xdrstdio_create(&xdrp, fxx, XDR_ENCODE);
	else
	  xdrstdio_create(&xdrp, fxx, XDR_DECODE);

  func=(void *)find_func(libptr,buff);
  if (func==0) return 0;

  func(&xdrp,s);

  xdr_destroy(&xdrp);
  fclose(fxx);
  return 1;
}



/* =================================== EOF =========================== */
