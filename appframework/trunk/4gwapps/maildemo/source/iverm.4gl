#	IVERM.4gl  -  4gwmail demo vertical menus
#
#	4gwMail, a news and mail client 4glWorks module
#	Copyright (C) 1997-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 97
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
#
#include "idefl.4gh"
#include "imill.4gh"
#include "ivwrl.4gh"

#
#  messagges menu
#
function menu_milmsg()
    define i,j	smallint

    whenever error call trap_err
    call mnv_start()
    let i=mnv_opt("Drop", "D", MB_deleterec, "")
    let i=mnv_opt("Cancel", "C", MB_nwscancel, "")
    let i=mnv_opt("cOpy", "O", MB_copyrec, "")
    let i=mnv_opt("Move", "M", MB_milmove, "")
    let i=mnv_opt("Save", "S", MB_filewrite, 0)
    let i=mnv_opt("eXport", "X", MB_filewrite, 1)
    let i=mnv_opt("Forward", "F", MB_milforward, MP_milbracketed)
    let i=mnv_opt("Reply", "R", MB_milreply, MP_milbracketed)
    let i=mnv_opt("Edit", "E", MB_miledit, "")
    let i=mnv_opt("New", "N", "", 1)
    call mnv_get() returning i, j
    if (i is null) and (j=1)
    then
	call mil_send("", "", "") returning i, j
    end if
    return i, j
end function
#
#  folder menu
#
function menu_milfolder()
    define i,j	smallint

    call mnv_start()
    let i=mnv_opt("Create", "C", "", 1)
    let i=mnv_opt("Drop", "D", "", 2)
    let i=mnv_opt("Join", "J", "", 3)
    let i=mnv_opt("Unsubscribe", "U", "", 4)
    let i=mnv_opt("Reload", "R", MB_reloadset, "")
    let i=mnv_opt("Select", "S", MB_chooseset, "")
    call mnv_get() returning i, j
    case
      when (i is not null) or (j is null)
	return i, j
      when (j=1)
	call mil_create()
      when (j=2)
	call mil_erase()
      when (j=3)
	call mil_subscribe(true)
      when (j=4)
	call mil_subscribe(false)
    end case
    if (viewing()=V_fol)
    then
	return MB_reloadset, ""
    else
	return "", ""
    end if
end function
#
#  view menu
#
function menu_milview()
    define i,j	smallint

    call mnv_start()
    let i=mnv_view("Folders", "F", "", V_mil)
    if (mnv_view("message Center", "C", MB_exit, V_fol) is not null)
    then
	let i=mnv_opt("Sort", "S", "", -1)
	let i=mnv_opt("Headers", "H", "", -2)
    end if
    let i=mnv_opt("Preferences", "P", "", -3)
    call mnv_get() returning i, j
    case
      when (i is not null)
      when (j=V_mil)
	if (mil_entry(true, true, ""))
	then
	    let i=MB_exit
	else
	    let j=""
	end if
      when (j=-1)
	call menu_milsort()
	  returning i, j
      when (j=-2)
	call menu_milheaders()
	  returning i, j
      when (j=-3)
	call mil_setpreferences()
	  returning i, j
    end case
    return i, j
end function
#
#  sort menu
#
function menu_milsort()
    define i,j	smallint

    call mnv_start()
    let i=mnv_opt("Sender", "S", MB_milsort, MP_milsender)
    let i=mnv_opt("sUbject", "U", MB_milsort, MP_milsubject)
    let i=mnv_opt("Date", "D", MB_milsort, MP_mildate)
    let i=mnv_opt("Thread", "T", MB_milsort, MP_milthread)
    let i=mnv_opt("Ascending", "A", MB_milasc, "")
    let i=mnv_opt("dEscending", "E", MB_mildesc, "")
    call mnv_get() returning i, j
    return i, j
end function
#
#  headers menu
#
function menu_milheaders()
    define i,j	smallint

    call mnv_start()
    let i=mnv_opt("Brief", "B", MB_milevel, MP_milnone)
    let i=mnv_opt("Normal", "N", MB_milevel, MP_milnormal)
    let i=mnv_opt("All", "A", MB_milevel, MP_milall)
    call mnv_get() returning i, j
    return i, j
end function
