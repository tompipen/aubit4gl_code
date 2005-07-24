#	IINIL.4gl  -  Application initialization sample
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
#  Application cold initialization
#
function main_init()
    define i integer

    whenever error call trap_err
    call usr_greet("4glWorks", "", "")
    options
	input		wrap,
	sql interrupt	off,
	field order	constrained
#
#  Here's a good place to open a DB 
#
    if db_open("fgwdemo", false) is null
    then
	call usr_hitkey(txt_retrieve(sqlca.sqlcode))
	clear screen
	exit program
    end if
#
#  & init modular variables
#
    call hor_init()
    call usr_status("")
end function
#
#  null viewer (re)inizialization
#
function main_reset()
    call usr_status("wa")
#
#  reset application modules
#
    call usr_status("")
end function
