#	ITBLL.4gl  -  DB & table oriented functions
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
#  provides a (suggested) code value - char fields
#
function code_guess(desc, tbl)
    define desc		char(40),
	   tbl		char(3),
	   code		char(8),
	   src		char(120),
	   i, j, k	smallint

    whenever error call trap_err
    let i=0
    let j=0
    let k=length(desc)
    let code=" "
    while (i<8) and (j<k)
	let j=j+1
	if (desc[j,j]!=" ")
	then
	     let i=i+1
	     let code[i,i]=upshift(desc[j,j])
	end if
    end while
    let src="select true from ", tbl clipped, " where code_",
		tbl clipped, "=\"?\""
    prepare cg_stat from src
    declare cg_curs cursor for cg_stat
    open cg_curs using code
    fetch cg_curs
    let k=(status=0)
    let j=0
    while k and (j<99)
	let j=j+1
	let src=j using "<<&"
	let k=i-length(src)+1
	let code[k,i]=src clipped
	open cg_curs using code
	fetch cg_curs
	let k=(status=0)
    end while
    close cg_curs
    SQ_freecurs cg_curs
    free cg_stat
    return code clipped
end function
#
#  provides a (suggested) code value - smallint fields
#
function ser_guess(tbl)
    define tbl	char(3),
	   src	char(120),
	   i	integer

    let i=""
    let src="select max(code_", tbl clipped, ") from ", tbl clipped
    prepare sg_stat from src
    declare sg_curs cursor for sg_stat
    open sg_curs
    fetch sg_curs into i
    close sg_curs
    SQ_freecurs sg_curs
    free sg_stat
    case
      when (i<0) or (i is null) or (status=100)
	return 1
      when (status!=0)
	return ""
      otherwise
	return i+1
    end case
end function
#
#  code field validation
#
function code_check(tbl, val)
    define tbl	char(3),
	   val	char(8),
	   src	char(120),
	   i	integer

    if char_check(false, false, true, true, "", val)
    then
	return true
    end if
    let src="select count(*) from ", tbl clipped, 
	    " where code_", tbl clipped, "=\"", val, "\""
    prepare cc_stat from src
    declare cc_curs cursor for cc_stat
    open cc_curs
    fetch cc_curs into i
    close cc_curs
    SQ_freecurs cc_curs
    free cc_stat
    if (i=0)
    then
	return false
    else
	call usr_warn("cu")
	return true
    end if
end function
#
#  description field validation
#
function desc_check(tbl, val, code)
    define tbl	char(3),
	   val	char(40),
	   code	char(8),
	   src	char(120),
	   i	integer

    if nul(val)
    then
	return true
    end if
    let src="select count(*) from ", tbl clipped, 
	    " where desc_", tbl clipped, "=\"", val clipped, "\""
    if code is not null
    then
	let src=src clipped, " and code_", tbl clipped,
		"!=\"", code clipped, "\""
    end if
    prepare dc_stat from src
    declare dc_curs cursor for dc_stat
    open dc_curs
    fetch dc_curs into i
    close dc_curs
    SQ_freecurs dc_curs
    free dc_stat
    if (i=0)
    then
	return false
    else
	call usr_warn("du")
	return true
    end if
end function
#
#  "value already in table" generic check
#
function field_check(val, em)
    define val	char(40),
	   em	char(8)

    case
      when nul(val)
	return true
      when (sqlca.sqlcode=0)
	call usr_warn(em)
	return true
    end case
    return false
end function
