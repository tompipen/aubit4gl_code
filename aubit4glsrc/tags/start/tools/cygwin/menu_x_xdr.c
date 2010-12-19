#include <rpc/rpc.h>
#include "menu_x.h"


bool_t
xdr_menu_option_item(xdrs, objp)
	XDR *xdrs;
	menu_option_item *objp;
{
	if (!xdr_string(xdrs, &objp->id, ~0)) {
		return (FALSE);
	}
	if (!xdr_string(xdrs, &objp->caption, ~0)) {
		return (FALSE);
	}
	if (!xdr_string(xdrs, &objp->key_list, ~0)) {
		return (FALSE);
	}
	if (!xdr_string(xdrs, &objp->image, ~0)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->checked)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->align)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->color)) {
		return (FALSE);
	}
	if (!xdr_string(xdrs, &objp->submenu_id, ~0)) {
		return (FALSE);
	}
	return (TRUE);
}




bool_t
xdr_menu(xdrs, objp)
	XDR *xdrs;
	menu *objp;
{
	if (!xdr_string(xdrs, &objp->id, ~0)) {
		return (FALSE);
	}
	if (!xdr_array(xdrs, (char **)&objp->options.options_val, (u_int *)&objp->options.options_len, ~0, sizeof(menu_option_item), xdr_menu_option_item)) {
		return (FALSE);
	}
	return (TRUE);
}




bool_t
xdr_menu_list(xdrs, objp)
	XDR *xdrs;
	menu_list *objp;
{
	if (!xdr_array(xdrs, (char **)&objp->menus.menus_val, (u_int *)&objp->menus.menus_len, ~0, sizeof(menu), xdr_menu)) {
		return (FALSE);
	}
	return (TRUE);
}



