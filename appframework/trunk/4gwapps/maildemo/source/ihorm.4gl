#	IHORM.4gl - 4gwmail demo horizontal menu
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
#include "itiml.4gh"

#
#  module initialization
#
function hor_init()
    define i	smallint

    whenever error call trap_err
    call mnh_start("DEMO")
    let i=mnh_opt("Message",
		  "Message related ops", "M", "", -1, 1)
    let i=mnh_opt("Folder",
		  "Folder related ops", "F", "", -1, 2)
    let i=mnh_opt("View",
		  "Message viewing options", "V", "", -1, 3)
    let i=mnh_key(fgl_keyval("!"), "", 4)
#
#  now this is an example of something you'd better not do
#  control-x does not return 24 (control-x!) but 2010, which is the
#  logical key for deleteing a char.
#  If you are smart, drop this and use a plain option instead!
#
    let i=mnh_key(2010, MB_exit, "")
    call set_browse_keys()
#
#  set mail check timer
#
    let i=str2int(fgl_getenv("MAILCHECK"))
    case
      when (i>0)
      when (length(fgl_getenv("MAILCHECK"))=0)
	let i=300
    end case
    let i=tim_set(i, 0, true, A_mandatory, -2, "")
#
#  quit if 10 mins without hitting a key
#
    let i=tim_set(600, 0, true, A_keyboard, MB_exit, "")
end function
#
#  horizontal menu initialization
#
function menu_start()
    define i	smallint

    call mnu_clear()
    call pan_clear()
    call tim_clear()
#
#  hide or show viewer dependent pull-down menus, here
#
end function
#
#  menu display & option selection
#
function menu_get(im, ip)
    define im, ip,
	   om, op	smallint

    while true
	call mnh_get() returning om, op
	case
	  when (om>=0)
	    return om, op
	  when (om is null or om!=-1)
	  when (op is null)
	    continue while
	  when (op=1)
	    call menu_milmsg() returning om, op
	  when (op=2)
	    call menu_milfolder() returning om, op
	  when (op=3)
	    call menu_milview() returning om, op
	  when (op=4)
	    call exec_sh("!")
	    continue while
	end case
	if (om=-2)
	then
	    call mil_check() returning om, op
	end if
	return om, op
    end while
end function
