#	OUSRL.4gl  -  User interface, offline framework
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

    define fd	smallint

#
#  module initialization
#
function usr_init()
    whenever error call trap_err
    let fd=stdfd_open(2)
end function
#
#  returns user interaction mode
#
function usr_isbatch()
    return true
end function
#
#  sets user interaction mode
#
function usr_setbatch(mode)
    define mode 	smallint

    return true
end function
#
#  main message dispatcher
#
function usr_status(code)
    define code	char(14),
	   txt	char(78)

    if (length(code))
    then
	let txt=txt_retrieve(code)
	display txt clipped
    end if
end function
#
#  just a synonym for display
#
function usr_inform(txt)
    define txt	char(78)

    let status=0
    if (length(txt))
    then
	display txt clipped
    end if
end function
#
#  joins two messages (useful to complete a message with data
#  taken from the DB)
#
function join_warning(em, dt)
    define em   char(14),
	   dt   char(40),
	   str  char(80)

    let str=txt_retrieve(em) clipped, " ", dt
    call fd_writeln(fd, str)
end function
#
#  main error dispatcher
#
function usr_warn(code)
    define code	char(14)

    if (length(code))
    then
	call fd_writeln(fd, txt_retrieve(code))
    end if
end function
#
#  displayes error text
#
function usr_notify(txt)
    define txt	char(78),
	   c	smallint

    if (length(txt))
    then
	call fd_writeln(fd, txt)
    end if
end function
#
#  waits for a generic confirmation
#
function usr_ask(s, i)
    define s	char(60),
	   i, h	integer,
	   y, n	char(1),
	   cnf	char(18),
	   ans	char(1)

    let int_flag=false
    let cnf=txt_retrieve("YES")
    let y=upshift(cnf[1])
    let cnf=txt_retrieve("NO")
    let n=upshift(cnf[1])
    let cnf="(", y, "/", n, ")"
    while  true
	let ans=" "
	display " ", s clipped, " ", cnf clipped
	let ans=readchar()
	case
	  when int_flag and i
	    let i=false
	  when int_flag or upshift(ans)=n
	    let int_flag=false
	    let i=false
	  when upshift(ans)=y
	    let i=true
	  otherwise
	    let cnf="(", txt_retrieve("hit") clipped, " ", y, "/", n, ")"
	    continue while
	end case
	return i
    end while
end function
#
#  waits for a key before continuing execution
#
function usr_hitkey(parm)
    define parm	char(50),
	   p    char(78),
	   i, l	smallint,
	   sep	char(3),
	   c	char(1)

    let p=txt_retrieve("hitkey")
    let l=length(parm)
    case
      when (l=0)
	let p[1]=upshift(p[1])
	let p=" ", p clipped
      when (parm[1]!=" ")
	let p=" ", parm clipped, " - ", p clipped
      otherwise
	let sep=" ", ascii 8, ascii 10
	let i=posnbrk(parm, sep)
	let p=" ", parm[i, l], " - ", p clipped
    end case
    let int_flag=false
    display p clipped
    let c=readchar()
end function
#
#  issues error message and checks whether to continue
#
function usr_confirm(em)
    define em	char(14),
	   s	char(60)

    if length(em)>0
    then
	let s=txt_retrieve(em) clipped, " ", txt_retrieve("proceed")
    else
	let s=txt_retrieve("proceed")
    end if
    return usr_ask(s, false)
end function
