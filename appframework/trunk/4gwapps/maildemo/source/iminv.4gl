#	IMINV.4gl  -  4gwmail demo main program
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
#include "ivwrl.4gh"

define
  cv,nv	smallint

main
    whenever error call trap_err
    defer interrupt
    defer quit
    call afw_init()
    call main_init()
    let cv=V_mil
    while (cv is not null)
	case
	  when (cv=V_mil)
	    let nv=mil_viewer()
	  when (cv=V_fol)
	    let nv=fol_viewer()
	end case
	let cv=nv
    end while
    clear screen
end main
#
#  returns current viewer
#
function viewing()
    return cv
end function
