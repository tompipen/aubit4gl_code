#	IAPVV.4gl - generic (pipe/select stmt) data browser
#
#	4gwMenus, an isql menus like 4glWorks module
#	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Aug 96
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
globals "istbg.4gl"

define view_msg		smallint,
       link_app		smallint

#
#  application viewer
#
function apv_viewer()
    define om, op,
	   im, ip, i	smallint

    whenever error call trap_err
    call menu_start()
    call uni_looks("", "")
    call mnu_enable(view_msg, view_msg, 1, true)
    call mnu_enable(MB_print, MB_print, 1, true)
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
	  when (im=MB_chooseset) or (im=MB_reloadset)
	    call app_execute(link_app)
	      returning om, op
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	end case
    end while
    return ip
end function
#
#  sets type & link to app (sql only)
#
function apv_settype(msg, link)
    define msg	smallint,
	   link	smallint

    let view_msg=msg
    let link_app=link
end function
