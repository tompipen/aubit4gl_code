#	OPTRL.4gl - printer related functions, offline framework
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

#
#  printer selection routine
#
function ptr_choose(code_ptr, code_frm, copies, mw, ml, cond, desc_rep)
    define code_ptr	smallint,
	   code_frm	smallint,
	   copies	smallint,
	   mw, ml	smallint,
	   cond		char(100),
	   desc_rep	char(40),
	   reject	char(78),
	   r		smallint

    whenever error call trap_err
    let r=true
    case
      when copies is null
	let copies=1
	let r=false
      when code_ptr is null or code_frm is null
	call usr_warn("cptr.P1")
      otherwise
	select ptr.reject into reject from ptr
	  where ptr.code_ptr=code_ptr
	case
	  when (status=notfound)
	    call usr_warn("cptr.P2")
	  when (ptr_shellop(reject)!=0)
	    call usr_warn("cptr.P3")
	  otherwise
	    select false into r from frm
	      where frm.code_frm=code_frm
	    if (status!=0)
	    then
		call usr_warn("cptr.F2")
	    else
		let r=(frm_open(code_ptr, code_frm, mw, ml, cond)!=0)
	    end if
        end case
    end case
    if (r)
    then
	call join_warning("cptr.ns", desc_rep)
	return ""
    else
	return ptr_open(code_ptr, code_frm, copies)
    end if
end function
