#	IDTBS.4gl - Many to many relation table maintenance scroller
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 92
#	Current release: Jan 02
#
#	This library is free software; you can redistribute it and/or
#	modify it under the terms of the GNU Lesser General Public
#	License as published by the Free Software Foundation; either
#	version 2.1 of the License, or (at your option) any later version.
#
#	This library is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#	Lesser General Public License for more details.
#
#	You should have received a copy of the GNU Lesser General Public
#	License along with this library; if not, write to the Free Software
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

#include "idefl.4gh"
globals "istbg.4gl"

define
    description	char(40)
#
#  form selection
#
function dtb_looks(frm, dsc, p)
    define frm	char(14),
	   dsc	char(40),
	   p	smallint

    whenever error call trap_err
    if (frm is null) or (p is null) or (p<1)
    then
	let frm="dtbf"
	let p=7
    end if
    open form dtb_form from frm
    call pan_set_length(p)
    let description=dsc
    call browse_start(MB_brief)
end function
#
#  cursor declaration
#
function prepare_dtb()
    prepare view_dtb from search
    declare dtb_curs scroll cursor with hold for view_dtb
end function
#
#  two table scroller
#
function dtb_scroller(im, ip)
    define im, ip,
	   om, op	smallint,
	   k		integer

    let om=MB_display
    let op=MP_nodisplay
    if browse_brief()
    then
	case
	  when (im=MB_init)
	    call pan_home()
	    call restore_dtb(MB_declare, MP_fulldisplay)
	  when (im>MB_init) and (im<=MB_maxupstream)
	    call end_modal(im, ip) returning im, ip
	    call restore_dtb(im, ip)
	  otherwise
	    let om=im
	    let op=ip
	end case
    else
	case
	  when (im=MB_init)
	    call retrieve_dtb(pan_row())
	    return MB_display, MP_fulldisplay
	  when (im>MB_init) and (im<=MB_maxupstream)
	    call end_modal(im, ip) returning im, ip
	    call restore_dtb(im, MP_nodisplay)
	    call retrieve_dtb(pan_row())
	    return MB_display, ip
	  when (im=MB_prevrec) or (im=MB_nextrec)
	    call browse_filter(im, ip)
	      returning im, ip
	    if (ip!=MP_nodisplay)
	    then
		call retrieve_dtb(pan_row())
	    end if
	    return im, ip
	  when (im=MB_display) and (ip=MP_partdisplay)
	    call pan_status()
	  otherwise
	    let om=im
	    let op=ip
	end case
    end if
    while true
	call menu_get(om, op) returning im, ip
	let k=pan_row()
	call browse_filter(im, ip) returning im, ip
	if (im=MB_reloadset)
	then
	    let im=MB_open
	    let ip=MP_partdisplay
	end if
	case
	  when (im=MB_exit)
#
#  Don't generate RT errors in case there isn't a current database
#
	    if db_islocked() is not null
	    then
		close dtb_curs
		SQ_freecurs dtb_curs
		free view_dtb
	    end if
	    close form dtb_form
	    return im, ip
	  when (im=MB_deleterec)
	    case
	      when usr_askremove(2)
		return MB_deleterec, ""
	      otherwise
		call pan_status()
		call usr_warn("ea")
	    end case
	  when (im=MB_brief)		#only nobrief!
	    call restore_dtb(MB_display, MP_fulldisplay)
	    return MB_brief, ""
	  when (im=MB_move)		#only brief!
	    case ip
	      when MP_scrollup
		scroll s_dtb.* up
	      when MP_scrolldown
		scroll s_dtb.* down
	    end case
	    call drow_dtb(k)
	    call drow_dtb(pan_row())
	  when (im<MB_display) or (im>MB_declare)
	    return im, ip
	  when browse_brief()
	    call restore_dtb(im, ip)
	  otherwise
	    call restore_dtb(im, MP_nodisplay)
	    call retrieve_dtb(pan_row())
	    return MB_display, ip
	end case
    end while
end function
#
#  page display
#
function display_dtb(clr)
    define clr		integer,
	   f, l, s, k	integer

    call pan_status()
    call browse_range() returning f, l, s
    for k=f to l
	call drow_dtb(k)
    end for
    if clr
    then
	for k=s to pan_length()
	    clear s_dtb[k].*
#
#  a small word of warning: if you put color/intensity attributes in your form
#  clear will use them. If you need to completely blank the fields, use
#
#	    display "", "", "", "" to s_dtb[k].* attribute (normal)
#
	end for
    end if
end function
#
#  "display" messages servicing function
#
function restore_dtb(rl, rd)
    define rl, rd	smallint

    case
      when (rl=MB_declare)
	call prepare_dtb()
	call check_dtb()
      when (rl=MB_open)
	call check_dtb()
      when (rl!=MB_display)
	call invalid_message(rl)
	let rd=true
    end case
    case
      when (rd=MP_fulldisplay)
	display form dtb_form
	if description is not null
	then
	    display by name description
	end if
	call usr_area()
	call display_dtb(false)
      when (rd=MP_partdisplay)
	call display_dtb(true)
      when browse_brief()
	call pan_status()
    end case
end function
#
#  row display
#
function drow_dtb(r)
    define r, l		integer,
	   loc_1tb 	char(8),
	   loc_2tb	char(8),
	   dum_1tb	char(40),
	   dum_2tb	char(40)

    fetch absolute r dtb_curs into loc_1tb, loc_2tb, dum_1tb, dum_2tb
    let l=r-browse_offset()
    if (r=pan_row())
    then
	let code_1=loc_1tb
	let code_2=loc_2tb
	let loc_1tb=str_right(loc_1tb)
	let loc_2tb=str_right(loc_2tb)
	display loc_1tb, loc_2tb, dum_1tb, dum_2tb
	  to s_dtb[l].* attribute (reverse)
    else
	let loc_1tb=str_right(loc_1tb)
	let loc_2tb=str_right(loc_2tb)
	display loc_1tb, loc_2tb, dum_1tb, dum_2tb
	  to s_dtb[l].* attribute (normal)
    end if
end function
#
#  row retrieval
#
function retrieve_dtb(r)
    define r		integer,
	   dum_1tb	char(40),
	   dum_2tb	char(40)

    fetch absolute r dtb_curs into code_1, code_2, dum_1tb, dum_2tb
end function
#
#  cursor (re)opening & row count retrieval
#
function check_dtb()
    define loc_1tb 	char(8),
	   loc_2tb	char(8),
	   dum_1tb	char(40),
	   dum_2tb	char(40),
	   s, m		integer

    call usr_status("wa")
    open dtb_curs
    let s=browse_search("")
    while (s!=0)
	let m=pan_max()
	fetch absolute m dtb_curs into loc_1tb, loc_2tb, dum_1tb, dum_2tb
	let s=browse_search(s)
    end while
end function
