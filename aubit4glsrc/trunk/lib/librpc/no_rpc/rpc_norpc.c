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
# $Id: rpc_norpc.c,v 1.7 2003-05-12 14:24:24 mikeaubury Exp $
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

#include "a4gl_libaubit4gl.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* All following definitions where copied from RPC header files, whith sole
purpose to mainatian consistent API prototypes - since function calls use,
for example, variable "XDR" we have to define it somehow, even in absence of
actuall RPC functionallity on the system. Since this is jsut a dummy plug-in
that just returns "can't do it" messages, this really don't matter much, but yes
we know it's ugly...
*/

#define bool_t int

#ifdef __MINGW32__
typedef char *caddr_t;
#endif


enum xdr_op
{
  XDR_ENCODE = 0,
  XDR_DECODE = 1,
  XDR_FREE = 2
};

typedef struct
{
  enum xdr_op x_op;		/* operation; fast additional param */
  struct xdr_ops
  {
    bool_t (*x_getlong) (void);	/* get a long from underlying stream */
    bool_t (*x_putlong) (void);	/* put a long to " */
    bool_t (*x_getbytes) (void);	/* get some bytes from " */
    bool_t (*x_putbytes) (void);	/* put some bytes to " */
    u_int (*x_getpostn) (void);	/* returns bytes off from beginning */
    bool_t (*x_setpostn) (void);	/* lets you reposition the stream */
    long *(*x_inline) (void);	/* buf quick ptr to buffered data */
    void (*x_destroy) (void);	/* free privates of this xdr_stream */
  }
   *x_ops;
  caddr_t x_public;		/* users' data */
  caddr_t x_private;		/* pointer to private data */
  caddr_t x_base;		/* private used for position info */
  int x_handy;			/* extra private word */
}
XDR;


struct menu_option_item
{
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

struct menu
{
  char *id;
  struct
  {
    u_int options_len;
    menu_option_item *options_val;
  }
  options;
};
typedef struct menu menu;


struct menu_list
{
  struct
  {
    u_int menus_len;
    menu *menus_val;
  }
  menus;
};
typedef struct menu_list menu_list;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void xdrmem_create (XDR * xdrs, caddr_t addr, u_int size, enum xdr_op op);
static void local_exitwith (char *s);
bool_t xdr_menu_list (XDR * xdrs, menu_list * objp);
bool_t xdr_struct_form (XDR * xdrs, struct_form * objp);
bool_t xdr_int (XDR * xdrs, int *ip);
void xdrstdio_create (XDR * xdrs, FILE * file, enum xdr_op op);

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
xdrmem_create (XDR * xdrs, caddr_t addr, u_int size, enum xdr_op op)
/*
	XDR *xdrs;
	caddr_t addr;
	u_int size;
	enum xdr_op op;
*/
{
  local_exitwith ("Could not xdrmem_create - noRPC build");
}


/**
 *
 * @todo Describe function
 */
bool_t
xdr_int (XDR * xdrs, int *ip)
{
  local_exitwith ("Could not xdr_int - noRPC build");
  return 0;
}


/**
 *
 * @todo Describe function
 */
void
xdrstdio_create (XDR * xdrs, FILE * file, enum xdr_op op)
{
  local_exitwith ("Could not xdrstdio_create - noRPC build");
}


/**
 *
 * @todo Describe function
 */
bool_t
/*
xdr_struct_form(xdrs, objp)
	XDR *xdrs;
	struct_form *objp;
*/
xdr_struct_form (XDR * xdrs, struct_form * objp)
{
  local_exitwith ("Could not xdr_struct_form - noRPC build");
  return 0;
}


/**
 *
 * @todo Describe function
 */
bool_t
xdr_menu_list (XDR * xdrs, menu_list * objp)
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
  {
    debug ("ending because : %s", s);
  }
#endif
  printf ("\n\n\n");
  exit (1);
}

/* ============================= EOF ============================= */
