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
# $Id: rpc_norpc.c,v 1.1 2002-06-29 13:12:02 afalout Exp $
#
*/

/**
 * @file
 * RPC Implementation functions used in absence of RPC libraries on system.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */
/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include <stdio.h>

	/* FIXME: how come this two where not needed on ISTATION, but are on ARMADA : */
	#include <rpc/types.h>  	/* needed for xdr.h */
	#include <rpc/xdr.h> 		/* defines XDR, etc... */

	#include "a4gl_formxw.h"
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_rpc_xdr_int.h"

#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

struct menu_option_item {
	char *id;
	char *caption;
	char *key_list;
	char *image;
	int checked;
	int align;
	int color;
	char *submenu_id;
};
typedef struct menu_option_item menu_option_item;

struct menu {
	char *id;
	struct {
		u_int options_len;
		menu_option_item *options_val;
	} options;
};
typedef struct menu menu;


struct menu_list {
	struct {
		u_int menus_len;
		menu *menus_val;
	} menus;
};
typedef struct menu_list menu_list;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void local_exitwith (char *s);
bool_t xdr_menu_list(XDR * xdrs,menu_list * objp);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
void
xdrmem_create(xdrs, addr, size, op)
	register XDR *xdrs;
	caddr_t addr;
	u_int size;
	enum xdr_op op;
{
	local_exitwith ("Could not xdrmem_create - noRPC build");
}


/**
 *
 * @todo Describe function
 */
bool_t
xdr_int(xdrs, ip)
	XDR *xdrs;
	int *ip;
{
	local_exitwith ("Could not xdr_int - noRPC build");
	return 0;
}


/**
 *
 * @todo Describe function
 */
void
xdrstdio_create(xdrs, file, op)
	register XDR *xdrs;
	FILE *file;
	enum xdr_op op;
{
	local_exitwith ("Could not xdrstdio_create - noRPC build");
}


/**
 *
 * @todo Describe function
 */
bool_t
xdr_struct_form(xdrs, objp)
	XDR *xdrs;
	struct_form *objp;
{
	local_exitwith ("Could not xdr_struct_form - noRPC build");
	return 0;
}


/**
 *
 * @todo Describe function
 */
bool_t
xdr_menu_list(XDR * xdrs,menu_list * objp)
{
   	local_exitwith ("Could not xdr_menu_list - noRPC build");
	return 0;
}

/**
 *
 * @todo Describe function
 */
static void
local_exitwith (char *s)
{
	#ifdef DEBUG
		{debug ("ending because : %s", s);}
	#endif
  printf ("\n\n\n");
  exit (1);
}

/* ============================= EOF ============================= */

