#	IHORM.4gl - Sample horizontal menu
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Mar 93
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

#
#  module initialization
#
function hor_init()
    define i	smallint

    whenever error call trap_err
    call mnh_start("DEMO")
    let i=mnh_opt("First",
		  "Sample vertical menu #1", "F", "", -1, 1)
    let i=mnh_opt("Second",
		  "Sample vertical menu #2", "S", "", -1, 2)
    let i=mnh_opt("New", "Insert a new record", "N", "", MB_newrec, "")
    let i=mnh_opt("Copy",
	"Insert a new record using the current record as a guideline",
	"C", "", MB_copyrec, "")
    let i=mnh_opt("Modify", "Modify the current record", "M", "",
	MB_changerec, "")
    let i=mnh_opt("Remove", "Remove the current record", "R", "",
	MB_deleterec, "")
    let i=mnh_opt("Edit", "Edit the query", "E", "", MB_sqledit, "")
    let i=mnh_opt("Do", "Execute the query", "D", "", MB_sqlexec, "")
    let i=mnh_opt("Read", "Read a query from disk", "R", "", MB_fileread, "")
    let i=mnh_opt("Write", "Save the query on disk", "W", "", MB_filewrite, "")
    let i=mnh_key(fgl_keyval("!"), "", 3)
#
#  now this is an example of something you'd better not do
#  control-x does not return 24 (control-x!) but 2010, which is the
#  logical key for deleteing a char.
#  If you are smart, drop this and use a plain option instead!
#
    let i=mnh_key(2010, MB_exit, "")
    call set_browse_keys()
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
	  when (om!=-1)
	    return om, op
	  when (op is null)
	    continue while
	  when (op=1)
	    call menu_fst() returning om, op
	  when (op=2)
	    call menu_snd() returning om, op
	  when (op=3)
	    call exec_sh("!")
	    continue while
	end case
	return om, op
    end while
end function
