#	ISTBS.4gl - Table maintenance scroller
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
function stb_looks(frm, dsc, p)
    define frm	char(14),
	   dsc	char(40),
	   p	smallint

    whenever error call trap_err
    if (frm is null) or (p is null) or (p<1)
    then
	let frm="stbf"
	let p=15
    end if
    open form stb_form from frm
    call pan_set_length(p)
    let description=dsc
    call browse_start(MB_brief)
end function
#
#  search string initialization
#
function stb_open(fname, cond)
    define fname	char(3),
	   cond		char(250)

    case
      when (cond=" 1=1")
	let cond=""
      when cond clipped!=" "
	let cond=" where ", cond clipped
    end case
    let search="select code_", fname, ", desc_", fname, ", \"\" ",
	       "from ", fname, cond clipped, " order by 1"
    call pan_home()
end function
#
#  cursor declaration
#
function prepare_stb()
    prepare view_stb from search
    declare stb_curs scroll cursor with hold for view_stb
end function
#
#  scroller routine
#
function stb_scroller(im, ip)
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
	    call restore_stb(MB_declare, MP_fulldisplay)
	  when (im>MB_init) and (im<=MB_maxupstream)
	    call end_modal(im, ip) returning im, ip
	    call restore_stb(im, ip)
	  otherwise
	    let om=im
	    let op=ip
	end case
    else
	case
	  when (im=MB_init)
	    call restore_stb(MB_declare, MP_nodisplay)
	    call retrieve_stb(pan_row())
	    return MB_display, MP_fulldisplay
	  when (im>MB_init) and (im<=MB_maxupstream)
	    call end_modal(im, ip) returning im, ip
	    call restore_stb(im, MP_nodisplay)
	    call retrieve_stb(pan_row())
	    return MB_display, ip
	  when (im=MB_prevrec) or (im=MB_nextrec)
	    call browse_filter(im, ip)
	      returning im, ip
	    if (ip!=MP_nodisplay)
	    then
		call retrieve_stb(pan_row())
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
#  don't generate RT errors in case there's no longer a current DB
#
	    if db_islocked() is not null
	    then
		close stb_curs
		SQ_freecurs stb_curs
		free view_stb
	    end if
	    close form stb_form
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
	    call restore_stb(MB_display, MP_fulldisplay)
	    return MB_brief, ""
	  when (im=MB_move)		#only brief!
	    case ip
	      when MP_scrollup
		scroll s_stb.* up
	      when MP_scrolldown
		scroll s_stb.* down
	    end case
	    call drow_stb(k)
	    call drow_stb(pan_row())
	  when (im<MB_display) or (im>MB_declare)
	    return im, ip
	  when browse_brief()
	    call restore_stb(im, ip)
	  otherwise
	    call restore_stb(im, MP_nodisplay)
	    call retrieve_stb(pan_row())
	    return MB_display, ip
	end case
    end while
end function
#
#  "display" messages servicing function
#
function restore_stb(rl, rd)
    define rl, rd	smallint

    case
      when (rl=MB_declare)
	call prepare_stb()
	call check_stb()
      when (rl=MB_open)
	call check_stb()
    end case
    case
      when (rd=MP_fulldisplay)
	display form stb_form
	call usr_area()
	if description is not null
	then
	    display by name description
	end if
	call display_stb(false)
      when (rd=MP_partdisplay)
	call display_stb(true)
      when browse_brief()
	call pan_status()
    end case
end function
#
#  page display
#
function display_stb(clr)
    define clr		integer,
	   f, l, s, k	integer

    call pan_status()
    call browse_range() returning f, l, s
    for k=f to l
	call drow_stb(k)
    end for
    if clr
    then
	for k=s to pan_length()
	    clear s_stb[k].*
#
#  a small word of warning: if you put color/intensity attributes in your form
#  clear will use them. If you need to completely blank the fields, use
#
#	    display "", "" to s_stb[k].* attribute (normal)
#
	end for
    end if
end function
#
#  single row display
#
function drow_stb(r)
    define r, l		integer,
	   loc_stb,
	   loc_data	char(8),
	   dum_stb	char(40)

    let l=r-browse_offset()
    fetch absolute r stb_curs into loc_stb, dum_stb, loc_data
    if (r=pan_row())
    then
	if length(loc_data)=0
	then
	    let code_1=loc_stb
	else
	    let code_1=loc_data
	end if
	let loc_stb=str_right(loc_stb)
	display loc_stb, dum_stb to s_stb[l].* attribute (reverse)
    else
	let loc_stb=str_right(loc_stb)
	display loc_stb, dum_stb to s_stb[l].* attribute (normal)
    end if
end function
#
#  single row retrieval
#
function retrieve_stb(r)
    define r		integer,
	   loc_stb,
	   loc_data	char(8),
	   dum_stb	char(40)

    fetch absolute r stb_curs into loc_stb, dum_stb, loc_data
    if length(loc_data)=0
    then
	let code_1=loc_stb
    else
	let code_1=loc_data
    end if
end function
#
#  cursor (re)opening & row count retrieval
#
function check_stb()
    define loc_stb	char(8),
	   dum_stb	char(40),
	   s, m		integer

    call usr_status("wa")
    open stb_curs
    let s=browse_search("")
    while (s!=0)
	let m=pan_max()
	fetch absolute m stb_curs into loc_stb, dum_stb
	let s=browse_search(s)
    end while
end function
