#	ILOGV.4gl - Error Log Viewer
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
#  error log viewer
#
function log_viewer()
    define om, op,
	   im, ip	smallint

    whenever error call trap_err
    call menu_start()
    call uni_looks("", "")
    call mnu_enable(MB_print, MB_print, 1, true)
    call mnu_enable(MB_reloadset, MB_reloadset, 1, true)
    call mnu_enable(MB_newrec, MB_newrec, 1, true)
    call construct_log()
    let om=MB_init
    let op=""
    while true
	call uni_scroller(om, op) returning im, ip
	let om=""
	let op=""
	case
	  when (im=MB_exit)
	    exit while
	  when (im=MB_print)
	    call mlt_head_tail(txt_fetch("ivwr.txt", viewing()), get_login())
	    let om=im
	  when (im=MB_reloadset)
	    call construct_log()
	    let om=MB_declare
	    let op=MP_partdisplay
	  when (im=MB_newrec)
	    call new_log()
	    call construct_log()
	    let om=MB_recinserted
	    let op=MP_partdisplay
	  when (im is not null)
	    call invalid_message(im)
	    let om=MB_init
	end case
    end while
    return ip
end function
#
#  error log temp table construction
#
function construct_log()
    define i	smallint,
	   fd	smallint,
	   str	char(78)

    call usr_status("wa")
    call uni_create()
    let fd=file_open(filepath(fgl_getenv("DBPATH"), "error.log"),"r")
    if (status=0)
    then
	while (not fd_eof(fd))
	    let str=fd_read(fd)
	    call uni_newline(str)
	end while
	let i=fd_close(fd)
    end if
end function
