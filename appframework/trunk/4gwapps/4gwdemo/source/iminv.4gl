#	IMINV.4gl  -  sample main program, application framework
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

#include "ivwrl.4gh"

define
  cv,nv	smallint

main
    whenever error call trap_err
    defer interrupt
    defer quit
    call afw_init()
    call main_init()
    let cv=V_nul
    while true 
	case
	  when (cv is null)
	    clear screen
	    exit program
	  when (cv=V_nul)
	    call main_reset()
	    let nv=null_viewer()
	  when (cv=V_sql)
	    let nv=sql_viewer()
	  when (cv=V_log)
	    let nv=log_viewer()
	  when (cv=V_ptr)
	    let nv=ptr_viewer()
	  when (cv=V_frm)
	    let nv=frm_viewer()
	  when (cv=V_mdl)
	    let nv=mdl_viewer()
	  when (cv=V_f2p)
	    let nv=frm2ptr_viewer()
	  otherwise
	    call invalid_viewer(cv)
	    let cv=V_nul
	    let nv=null_viewer()
	end case
	let cv=nv
    end while
end main
#
#  returns current viewer
#
function viewing()
    return cv
end function
