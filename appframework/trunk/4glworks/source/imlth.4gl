#	IMLTH.4gl  -  multiple selection help
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
#  multi_help - multiple selection help
#
function multi_help(tbl, cond, ln, sep, quotes, buf)
    define
	tbl	char(4),
	cond	char(300),
	ln	smallint,
	sep	char(1),
	quotes	char(2),
	buf	char(8),
	fname	char(64),
	sel	char(1),
	code	char(8),
	str	char(80),
	p_hlp	text,
        i,j,k,
	l,m	integer,
	fd,
	dsrc,
	rdwop,
	linenum,
	oldline,
	firstline,
	maxlines,
	pglen	smallint,
	ds	char(80),
	sn	smallint,
	getit	integer,
	keyhit	char(1)

    whenever error call trap_err
    call asc_locate(p_hlp)
    case
      when (tbl="file")
	call get_token(cond)
	   returning fname, cond
	while (length(fname)>0)
	    let fd=file_open(filepath(fgl_getenv("DBPATH"), fname), "r")
	    while (not fd_eof(fd))
		let str=txt_commentdrop(fd_read(fd))
		call fd_droptoeol(fd)
		call get_token(str)
		  returning code, str
		if length(str)>0
		then
		    let str="  ", code clipped, " ", str clipped
		    call asc_addline(p_hlp, str, "")
		end if
	    end while
	    let j=fd_close(fd)
	    call get_token(cond)
	      returning fname, cond
	end while
      when (tbl="pipe")
	let fd=pipe_open(cond, "r")
	while (not fd_eof(fd))
	    let str=txt_commentdrop(fd_read(fd))
	    call fd_droptoeol(fd)
	    call get_token(str)
	      returning code, str
	    if length(str)
	    then
		let str="  ", code clipped, " ", str clipped
		call asc_addline(p_hlp, str, "")
	    end if
	end while
	let j=fd_close(fd)
      otherwise
	if (tbl is not null)
	then
	    if cond clipped!=" "
	    then
		let cond="where ", cond clipped
	    end if
	    let cond="select code_", tbl,", desc_", tbl," from ", tbl,
		     " ", cond clipped, " order by code_", tbl
	end if
	whenever error continue
	prepare mlt_search from cond
	whenever error call trap_err
	if (sqlca.sqlcode=0)
	then
	    declare mlt_hlp cursor for mlt_search
	    foreach mlt_hlp into code, str
		let str="  ", code clipped, " ", str clipped
		call asc_addline(p_hlp, str, "")
	    end foreach
	    SQ_freecurs mlt_hlp
	    free mlt_search
	end if
    end case
    let int_flag=false
    let linenum=1
    let maxlines=asc_lines(p_hlp)
    let sn=0
    case
      when (maxlines=0)
	call usr_warn("nv")
      when (maxlines>1)
	let pglen=14
	let j=0
	let buf=str_left(upshift(buf))
	if (sep clipped!=" ")
	then
	    let i=pos(buf, sep)-1
	    if (i>0)
	    then
		let buf=buf[1, i]
	    end if
	end if
	let l=length(buf)
	for i=1 to maxlines
            call get_token(asc_retrieveline(p_hlp, i))
                returning code, str 
	    let k=str_compare(upshift(code), buf)
	    let m=str_compare(upshift(str), buf)
	    case
	      when (k=l) or (m=l)
		let linenum=i
		exit for
	      when (k>j)
		let linenum=i
		let j=k
	      when (m>j)
		let linenum=i
		let j=m
	    end case
	end for
	if (linenum>pglen)
	then
	    let firstline=linenum-1
	else
	    let firstline=0
	end if
	open window mlt_help_win at 4,26
	  with form "hl2w"
	  attribute (border, form line first, comment line last,
		     prompt line last, message line last)
	let rdwop=1
	let dsrc=false
	let getit=true
	while getit
	    case
	      when rdwop!=0
		let l=1
		let j=minint(firstline+pglen, maxlines)
		for k=firstline+1 to j
                    let str=asc_retrieveline(p_hlp, k)
		    let sel=str[1]
                    call get_token(str[3, 80])
                      returning code, str
		    let code=str_right(code)
		    case
		      when (k!=linenum)
			display sel, code, str
			  to s_hlp[l].* attribute (normal)
		      when dsrc
			display sel, code to s_hlp[l].sel, s_hlp[l].code
			  attribute (normal)
			display str to s_hlp[l].description
			  attribute (reverse)
		      otherwise
			display code to s_hlp[l].code
			  attribute (reverse)
			display sel, str
			  to s_hlp[l].sel, s_hlp[l].description
			  attribute (normal)
		    end case
		    let l=l+1
		end for
		if (rdwop<0)
		then
		    for k=l to pglen
			display "", "", "" to s_hlp[k].* attribute (normal)
		    end for
		end if
	      when (oldline!=linenum)
		if (oldline>0)
		then
                    let str=asc_retrieveline(p_hlp, oldline)
		    let sel=str[1]
                    call get_token(str[3, 80])
                      returning code, str
		    let code=str_right(code)
		    let l=oldline-firstline
		    display sel, code, str
		      to s_hlp[l].* attribute (normal)
		end if
		let l=linenum-firstline
                let str=asc_retrieveline(p_hlp, linenum)
		let sel=str[1]
                call get_token(str[3, 80])
                  returning code, str
		let code=str_right(code)
		if dsrc
		then
		    display sel, code
		      to s_hlp[l].sel, s_hlp[l].code
		      attribute (normal)
		    display str to s_hlp[l].description
		      attribute (reverse)
		else
		    display code to s_hlp[l].code
		      attribute (reverse)
		    display sel, str
		      to s_hlp[l].sel, s_hlp[l].description
		      attribute (normal)
		end if
	    end case
	    let rdwop=0
	    let oldline=linenum
	    let keyhit=readkey()
	    let i=fgl_lastkey()
	    case
	      when int_flag
		let getit=false
	      when i=fgl_keyval("help")
		call showhelp(22)
		let int_flag=false
	      when i=fgl_keyval("accept")
		let getit=false
	      when i=9
		let dsrc=not dsrc
		let oldline=-1
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
		    scroll s_hlp.* down
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
	      when (i=13)
		call codesel_mlt(p_hlp, linenum, ln ,sn)
		  returning sn
		goto fake_nobreak
	      when i=fgl_keyval("down")
label fake_nobreak:
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
		    scroll s_hlp.* up
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
	      when (i=32)
		call codesel_mlt(p_hlp, linenum, ln, sn)
		  returning sn
		let oldline=-1
	      when keyhit is null
	      otherwise
		let keyhit=upshift(keyhit)
		let j=maxlines
		let k=linenum
		while (j!=0)
		    if (k=maxlines)
		    then
			let k=1
		    else
			let k=k+1
		    end if
		    call get_token(asc_retrieveline(p_hlp, k))
		      returning code, str
		    if dsrc
		    then
			let l=(keyhit=upshift(str[1]))
		    else
			let l=(keyhit=upshift(code[1]))
		    end if
		    if (l)
		    then
		        let linenum=k
			if (k<=firstline) or (k>firstline+pglen)
			then
			    let firstline=linenum-1
			    let rdwop=-1
			end if
			exit while
		    end if
		    let j=j-1
		end while
	    end case
	end while
	close window mlt_help_win
    end case
    let ds=""
    case
      when int_flag or (maxlines=0)
      when sn=0
	let str=asc_retrieveline(p_hlp, linenum)
	call get_token(str[3, 80])
	  returning code, str
	let ds=quotes[1, 1] clipped, code clipped,
	       quotes[2, 2] clipped
      otherwise
	let k=true
	for j=1 to maxlines
	    let str=asc_retrieveline(p_hlp, j)
	    let sel=str[1, 1]
	    call get_token(str[3, 80])
	      returning code, str
	    case
	      when (sel="*") and k
		let ds=quotes[1, 1] clipped, code clipped,
		       quotes[2, 2] clipped
		let k=false
	      when (sel="*")
		let ds=ds clipped, sep, quotes[1, 1] clipped,
		       code clipped, quotes[2, 2] clipped
	    end case
	end for
    end case
    let int_flag=false
    return ds
end function
#
#  selection flag adj
#
function codesel_mlt(p_hlp, linenum, ln, sn)
    define p_hlp	text,
	   linenum	smallint,
	   ln, sn	smallint,
	   str		char(80),
	   sel		char(3),
	   code		char(8),
	   l		smallint

    let str=asc_retrieveline(p_hlp, linenum)
    let sel=str[1, 3]
    call get_token(str[3, 80])
      returning code, str
    let l=length(code)
    case
      when sel[1]="*"
	let sel[1]=" "
	let sn=sn-l-1
	if (sn<0)
	then
	    let sn=0
	end if
      when (sn=0)
	let sel[1]="*"
	let sn=l
      when (sn+l<ln)
	let sel[1]="*"
	let sn=sn+1+l
      otherwise
	call usr_warn("ns")
    end case
    let l=asc_linepos(p_hlp, linenum)
    call asc_changestring(p_hlp, sel, l, l+2)
    return sn 
end function
