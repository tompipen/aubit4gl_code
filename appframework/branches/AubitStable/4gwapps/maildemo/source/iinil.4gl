#	IINIL.4gl  -  4gwmail demo initialization
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

#
#  Application cold initialization
#
function main_init()
    whenever error call trap_err
    call usr_greet("4glWorks", "", "")
    call usr_status("wa")
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
    call dpn_init()
    call mil_init()			#mil before hor?
    call hor_init()
    call mil_setaddrbook("pipe", "awk -F: \'{print $1 \" \" $5}\' /etc/passwd")
    call usr_status("")
end function
