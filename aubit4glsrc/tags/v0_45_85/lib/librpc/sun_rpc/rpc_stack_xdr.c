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
# $Id: rpc_stack_xdr.c,v 1.8 2003-05-15 07:10:44 mikeaubury Exp $
#*/

/**
 * @file
 *
 * This file was generated using rpcgen and then modified (IIRC) which
 * allows it to act as both a client and a server, in the same C code
 * (which isn't normally possible).
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL

#include <rpc/types.h>
#include <rpc/xdr.h>

#include "a4gl_xdr_rpc_stack.h"

#else

#include "a4gl_lib_rpc_xdr_int.h"

#endif

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define main server_run

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

unsigned int serviceport = 0x2000000;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @return
 */
bool_t
xdr_single_dtype (XDR * xdrs, single_dtype * objp)
{

/*	 register long *buf; */

  if (!xdr_int (xdrs, &objp->dtype))
    {
      return (FALSE);
    }
  switch (objp->dtype)
    {
    case 1:
      if (!xdr_short (xdrs, &objp->single_dtype_u.shortval))
	{
	  return (FALSE);
	}
      break;
    case 2:
    case 6:
    case 7:
    case 8:
      if (!xdr_long (xdrs, &objp->single_dtype_u.longval))
	{
	  return (FALSE);
	}
      break;
    case 4:
      if (!xdr_float (xdrs, &objp->single_dtype_u.smfltval))
	{
	  return (FALSE);
	}
      break;
    case 3:
      if (!xdr_double (xdrs, &objp->single_dtype_u.floatval))
	{
	  return (FALSE);
	}
      break;
    case 0:
      if (!xdr_string (xdrs, &objp->single_dtype_u.chardata, ~0))
	{
	  return (FALSE);
	}
      break;
    case 11:
    case 12:
      if (!xdr_bytes
	  (xdrs, (char **) &objp->single_dtype_u.blobdata.blobdata_val,
	   (u_int *) & objp->single_dtype_u.blobdata.blobdata_len, ~0))
	{
	  return (FALSE);
	}
      break;
    default:
      return (FALSE);
    }
  return (TRUE);
}

/**
 *
 *
 * @return
 */
bool_t
xdr_object_data (XDR * xdrs, object_data * objp)
{

/*	 register long *buf; */

  if (!xdr_single_dtype (xdrs, objp))
    {
      return (FALSE);
    }
  return (TRUE);
}

/**
 *
 *
 * @return
 */
bool_t
xdr_return_values (XDR * xdrs, return_values * objp)
{

/*	 register long *buf; */

  if (!xdr_array
      (xdrs, (char **) &objp->return_values_val,
       (u_int *) & objp->return_values_len, ~0, sizeof (object_data),
       (xdrproc_t) xdr_object_data))
    {
      return (FALSE);
    }
  return (TRUE);
}

/**
 *
 *
 * @return
 */
bool_t
xdr_call (XDR * xdrs, call * objp)
{

/*	 register long *buf; */

  if (!xdr_string (xdrs, &objp->function_name, ~0))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->parameters.parameters_val,
       (u_int *) & objp->parameters.parameters_len, ~0, sizeof (object_data),
       (xdrproc_t) xdr_object_data))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->sizedata.sizedata_val,
       (u_int *) & objp->sizedata.sizedata_len, ~0, sizeof (long),
       (xdrproc_t) xdr_long))
    {
      return (FALSE);
    }
  return (TRUE);
}



/* ============================== EOF ================================ */
