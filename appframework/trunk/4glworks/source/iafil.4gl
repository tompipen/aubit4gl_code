#	IAFIL.4gl  -  4glWorks one time initialization
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: May 95
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

#
#  this is to be called upon application entry
#
function afw_init()
    define modname	char(64),
	   b		integer
    
    whenever error call trap_err
    call startlog(filepath(fgl_getenv("DBPATH"), "error.log"))
    let b=usr_isbatch()
    call cptr_init()
    call tbl_init()
    call txt_init()
    call usr_init()
#
#  this is a bit of a hack, and requires that 4gl initializes modular variables
#
    if (b)
    then
	let b=usr_setbatch(true)
	return
    end if
    let modname=filesplit(arg_val(0), false, true, false) clipped, ".hlp"
    call mlt_init()	--
    call mnh_init()
    call mnv_init()
    call iptr_init()
    call ted_init()
    call tim_init()
    call uni_init()	--
    options
	menu		line first,
	prompt		line last-1,
	form		line first+3,
	comment		line first+1,
	message		line last-1,
	error		line last,
	help key	control-w,
	insert key	control-n,
	delete key	control-e,
	next key	control-f,
	previous key	control-g,
	accept key	esc,
	help file	modname
    call mnh_help(10, true)
    call mnv_help(11, true)
    call usr_help(12, true)
end function
