#	ISNDM.4gl  -  Sample vertical menu #2
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
#
#  sample vert menu #2
#
function menu_snd()
    define i, im, ip	smallint

    whenever error call trap_err
    call mnv_start()
    let i=mnv_opt("Configuration", "C", MB_configure, "")
    let i=mnv_opt("Full display", "F", MB_detailed, "")
    let i=mnv_opt("Short display", "S", MB_brief, "")
    let i=mnv_opt("Print", "P", MB_print, "")
    let i=mnv_opt("Enable printer", "E", "", 100)
    if db_islocked()
    then
	let i=mnv_opt("unlock Database", "D", "", 101)
    else
	let i=mnv_opt("lock Database", "D", "", 102)
    end if
    call mnv_get() returning im, ip
    case
      when (im is not null)
	return im, ip
      when (ip is null)
	return MB_display, MP_nodisplay
      when (ip=100)
	call ptr_enable()
	return MB_display, MP_nodisplay
      when (ip=102)
	case db_open("fgwdemo", true)
	  when true
	    call usr_warn("cdbm.AX")
	    return MB_declare, MP_nodisplay
	  when false
	    call usr_warn("cdbm.ax")
	    return MB_declare, MP_nodisplay
	  otherwise
	    call usr_warn("cdbm.nd")
	    return MB_exit, ""
	end case
      when (ip=101)
	if db_open("fgwdemo", false) is null
	then
	    call usr_warn("cdbm.nd")
	    return MB_exit, ""
	else
	    call usr_warn("cdbm.DX")
	    return MB_declare, MP_nodisplay
	end if
    end case
end function
