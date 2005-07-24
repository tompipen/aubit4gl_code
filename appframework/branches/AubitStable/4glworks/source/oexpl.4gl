#	OEXPL.4gl - SQL interpreter: expansion add ons, batch applications
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Jun 98
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
#  remove/display "please wait" messages in between pick lists
#
function sql_givestatus(verbose, msg)
    define verbose	integer,
	   msg		char(2)

    whenever error call trap_err
end function
#
#  Multiple choice pick list
#
function multi_desc(tbl, cond, ln, sep, quotes, buf)
    define
	tbl	char(4),
	cond	char(300),
	ln	smallint,
	sep	char(1),
	quotes	char(2),
	buf	char(8)

    let sqlca.sqlcode=-201
    return ""
end function
#
#  multi_help - multiple selection help
#
function multi_help(tbl, cond, ln, sep, quotes, buf)
    define
	tbl	char(4),
	cond	char(300),
	ln	smallint,
	sep	char(1),
	quotes	char(2),
	buf	char(8)

    let sqlca.sqlcode=-201
    return ""
end function
#
#  field help display - description only
#
function uni_desc(tbl, cond, buf)
    define
	tbl	char(4),
	cond	char(300),
	buf	char(8)

    let sqlca.sqlcode=-201
    return ""
end function
#
#  single selection field help display
#
function uni_help(tbl, cond, insnew, buf)
    define
	tbl	char(4),
	cond	char(300),
	insnew	integer,
	buf	char(8)

    let sqlca.sqlcode=-201
    return "", ""
end function
