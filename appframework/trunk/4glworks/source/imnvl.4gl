#	IMNVL.4gl - Vertical menu routines
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

define
    errid,
    hor_interact,
    mnh_move,
    lastcol,
    maxwidth,
    maxlines,
    hiddenentries,
    cur_help,
    def_help	smallint,
    p_mnv	array[50] of record
		    desc_mnv	char(25),
		    quickkey	char(1),
		    msg		smallint,
		    parm	smallint,
		    ambigue	integer
		end record

#
#  module initialization
#
function mnv_init()
    whenever error call trap_err
    let cur_help=""
    let def_help=""
    let mnh_move=true
    let hor_interact=false
end function
#
#  vertical menu initialization
#
function mnv_start()
    let hiddenentries=51
    let maxlines=0
    let maxwidth=0
    let cur_help=def_help
end function
#
#  sets help message
#
function mnv_help(hn, def)
    define hn, def	smallint

    let cur_help=hn
    if def
    then
	let def_help=hn
    end if
end function
#
#  select menu display column #
#
function mnv_pos(col)
    define col	smallint

    let lastcol=col
end function
#
#  flags menu is being opened via horizontal menu library
#
function mnv_ismenu()
    let hor_interact=true
end function
#
#  flags menu is not part of a menu hierarchy
#
function mnv_standalone()
    let mnh_move=false
end function
#
#  insert item in vertical menu
#
function mnv_opt(dm, qk, m, p)
    define dm	char(25),
	   qk	char(1),
	   m, p	smallint,
	   udm	char(25),
	   i	smallint

    let errid=""
    let udm=upshift(dm)
    case
      when hiddenentries-maxlines=1
	return false
      when not pan_test(m)
	for i=hiddenentries to 50
	    if (p_mnv[i].desc_mnv=udm)
	    then
		let errid=i
		return ""
	    end if
	end for
	let hiddenentries=hiddenentries-1
	let p_mnv[hiddenentries].desc_mnv=udm
	return ""
      otherwise
	for i=1 to maxlines
	    if (upshift(p_mnv[i].desc_mnv)=udm)
	    then
		let errid=i
		return ""
	    end if
	end for
	for i=hiddenentries to 50
	    if (p_mnv[i].desc_mnv=udm)
	    then
		let errid=i
		return ""
	    end if
	end for
    end case
    let maxlines=maxlines+1
    let p_mnv[maxlines].desc_mnv=dm
    let p_mnv[maxlines].quickkey=qk
    let p_mnv[maxlines].msg=m
    let p_mnv[maxlines].parm=p
    let p_mnv[maxlines].ambigue=false
    if length(dm)>maxwidth
    then
	let maxwidth=length(dm)
    end if
    for i=1 to maxlines-1
	if (p_mnv[i].quickkey=qk)
	then
	    let p_mnv[i].ambigue=true
	    let p_mnv[maxlines].ambigue=true
	end if
    end for
    return maxlines
end function
#
#  returns existing conflicting entry
#
function mnv_error()
    if (errid is null)
    then
	return "", "", ""
    else
	return p_mnv[errid].desc_mnv, p_mnv[errid].msg, p_mnv[errid].parm
    end if
end function
#
#  menu display & option selection
#
function mnv_get()
    define i, j, k, l	smallint,
	   tm, tp	smallint,
	   linenum,
	   oldline,
	   firstline,
	   pglen,
	   rdwop	smallint,
	   getit	integer,
	   keyhit	char(1)

    let int_flag=false
    let linenum=1
    let firstline=0
    case
      when (maxlines=0)
	call usr_warn("cn")
	let hor_interact=false
	let mnh_move=true
	return "", ""
      when (maxlines=1 and not hor_interact)
	call opt_put(p_mnv[1].msg, p_mnv[1].parm)
	let mnh_move=true
	return p_mnv[1].msg, p_mnv[1].parm
    end case
    for i=1 to maxlines
	let j=length(p_mnv[i].desc_mnv)
	if (p_mnv[i].desc_mnv[j,j]=">" and j<maxwidth)
	then
	    let p_mnv[i].desc_mnv[j,j]=" "
	    let p_mnv[i].desc_mnv[maxwidth, maxwidth]=">"
	end if
    end for
    let maxwidth=maxwidth+2
    case
      when lastcol<3
	let lastcol=3
      when lastcol>80-maxwidth
	let lastcol=80-maxwidth
    end case
    if (maxlines>19)
    then
	let pglen=19
    else
	let pglen=maxlines
    end if
    open window mnv_win at 4, lastcol with pglen rows, maxwidth columns
      attribute (border, form line first, comment line last,
		 prompt line last, message line last)
    let rdwop=1
    let getit=true
    while getit
	case
	  when rdwop!=0
	    let l=1
	    let j=minint(firstline+pglen, maxlines)
	    for k=firstline+1 to j
		if (k!=linenum)
		then
		    display " ", p_mnv[k].desc_mnv
		       at l, 1 attribute (normal)
		else
		    display " ", p_mnv[k].desc_mnv at l, 1
		      attribute (reverse)
		end if
		let l=l+1
	    end for
	    if (rdwop<0)
	    then
		for k=l to pglen
		    display ""  at k, 1 attribute (normal)
		end for
	    end if
	  when (oldline!=linenum)
	    if (oldline>0)
	    then
		let l=oldline-firstline
		display " ", p_mnv[oldline].desc_mnv
		  at l, 1 attribute (normal)
	    end if
	    let l=linenum-firstline
	    display " ", p_mnv[linenum].desc_mnv at l, 1
	      attribute (reverse)
	end case
	let rdwop=0
	let oldline=linenum
	let l=linenum-firstline
	display "" at l, maxwidth
	call tim_event()
	  returning keyhit, tm, tp
	let i=fgl_lastkey()
	case
	  when int_flag or tm is not null or tp is not null
	    let getit=false
	  when i=fgl_keyval("help")
	    call help_show(cur_help)
	    let int_flag=false
	  when i=13
	    let getit=false
	  when i=fgl_keyval("left") and mnh_move
	    call mnh_back()
	    let tm=MB_display
	    let tp=MP_nodisplay
	    let getit=false
	  when i=fgl_keyval("right") and mnh_move
	    call mnh_forth()
	    let tm=MB_display
	    let tp=MP_nodisplay
	    let getit=false
	  when i=fgl_keyval("nextpage")
	    case
	      when (linenum+pglen-1<maxlines)
		let linenum=linenum+pglen-1
		let firstline=firstline+pglen-1
		let rdwop=-1
	      when (firstline+pglen-1<maxlines)
		let linenum=maxlines
		let firstline=firstline+pglen-1
		let rdwop=-1
	      when (linenum<maxlines)
		let linenum=maxlines
	    end case
	  when i=fgl_keyval("prevpage")
	    case
	      when (firstline>=pglen-1)
		let linenum=linenum-pglen+1
		let firstline=firstline-pglen+1
		let rdwop=1
	      when (firstline>0) and (linenum>pglen-1)
		let firstline=0
		let linenum=linenum-pglen+1
		let rdwop=-1
	      when (firstline>0)
		let firstline=0
		let linenum=1
		let rdwop=-1
	      when (linenum>1)
		let linenum=1
	    end case
	  when i=fgl_keyval("F1")
	    case
	      when (linenum=1)
	      when (firstline=0)
		let linenum=1
	      otherwise
		let linenum=1
		let firstline=0
		let rdwop=-1
	    end case
	  when i=fgl_keyval("up")
	    case
	      when (linenum-firstline>1)
		let linenum=linenum-1
	      when (linenum>1)
		let rdwop=-1
		let linenum=linenum-1
		let firstline=firstline-1
	      otherwise
		case
		  when (linenum>=maxlines)
		  when (linenum-firstline<pglen) and
		       (maxlines-firstline<=pglen)
		    let linenum=maxlines
		  otherwise
		    let linenum=maxlines
		    let firstline=linenum-pglen
		    let rdwop=-1
		end case
	    end case
	  when i=fgl_keyval("down") or (i=32)
	    case
	      when (linenum>=maxlines)
		case
		  when (linenum=1)
		  when (firstline=0)
		    let linenum=1
		  otherwise
		    let linenum=1
		    let firstline=0
		    let rdwop=-1
		end case
	      when (linenum-firstline<pglen)
		let linenum=linenum+1
	      otherwise
		let rdwop=-1
		let linenum=linenum+1
		let firstline=firstline+1
	    end case
	  when i=fgl_keyval("F4")
	    case
	      when (linenum>=maxlines)
	      when (linenum-firstline<pglen) and (maxlines-firstline<=pglen)
		let linenum=maxlines
	      otherwise
		let linenum=maxlines
		let firstline=linenum-pglen
		let rdwop=-1
	    end case
	  when i=fgl_keyval("~")
	    call mnh_easter()
	      returning tm, tp
	    if (tm is not null or tp is not null)
	    then
		let getit=false
	    end if
	  when keyhit is null
	  otherwise
	    let keyhit=upshift(keyhit)
	    let j=maxlines
	    let i=linenum
	    while (j!=0)
		if (i=maxlines)
		then
		    let i=1
		else
		    let i=i+1
		end if
		case
		  when (p_mnv[i].quickkey is null)
		  when (p_mnv[i].quickkey!=keyhit)
		  when (p_mnv[i].ambigue)
		    let linenum=i
		    if (i<firstline) or (i>firstline+pglen)
		    then
			let firstline=linenum-1
			let rdwop=-1
		    end if
		    call usr_warn("dc")
		    exit while
		  otherwise
		    let linenum=i
		    let getit=false
		    exit while
		end case
		let j=j-1
	    end while
	end case
    end while
    close window mnv_win
    let mnh_move=true
    let hor_interact=false
    case
      when int_flag
	call usr_warn("oi")
	return "", ""
      when (tm is not null or tp is not null)
	return tm, tp
      otherwise
	call opt_put(p_mnv[linenum].msg, p_mnv[linenum].parm)
	return p_mnv[linenum].msg, p_mnv[linenum].parm
    end case
end function
