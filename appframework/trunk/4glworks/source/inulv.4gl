#	INULV.4gl  -  Null (empty) viewer
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
#  null viewer
#
function null_viewer()
    define im, ip	smallint

    whenever error call trap_err
    clear screen
    call usr_area()
    call menu_start()
    while true
	call menu_get("", "") returning im, ip
	case
	  when (im=MB_exit)
	    return ip
	  when (im<MB_display) or (im>MB_declare)
	    call invalid_message(im)
	  when ip!=MP_nodisplay
	  otherwise
	    call usr_status("")
	    continue while
	end case
	clear screen
	call usr_area()
    end while
end function
