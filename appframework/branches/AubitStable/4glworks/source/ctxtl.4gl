#	CTXTL.4gl  -  language dependent text retrieval
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
 
define
    fcnt	smallint,
    acc		integer,
    modname	char(14),
    file_hash	byte,
    files	array[20] of record
		    p_txt	byte,
		    cnt, lr	integer,
		    fname	char(14)
            	end record
#
#  module initialization
#
function txt_init()
    whenever error call trap_err
    let fcnt=0
    let acc=0
    let modname=filesplit(arg_val(0), false, true, false) clipped, ".txt"
    call hst_start(file_hash, 20)
end function
#
#  "implicit file name" & informix messages text retrieval
#
function txt_retrieve(code)
    define code		char(14),
	   fname	char(14),
	   t		char(78),
	   i,j		integer

    let i=pos(code, ".")
    if (i>0)
    then
	let fname=code[1,i], "txt"
	let i=i+1
	let j=length(code)
	let code=code[i,j]
	let t=txt_fetch(fname, code)
    else
	let i=str2int(code)
	if (i is not null)
	then
	    let t=err_get(i)
#
#  drop trailing LF left by err_get
#
	    let i=length(t)
	    while (i>0) and t[i, i]<" "
		let i=i-1
	    end while
	    if (i>0)
	    then
		let t=t[1, i]
	    else
		let t=""
	    end if
	else
	    let t=txt_fetch(modname, code)
	end if
    end if
    return t
end function
#
#  "esplicit file name" text retrieval
#
function txt_fetch(fname, code)
    define fname	char(14),
	   code		char(8),
	   desc		char(80),
	   i,j		smallint

    let i=load_txt(fname)
    let acc=acc+1
    if (i is not null)
    then
	let desc=hst_retrieve(files[i].p_txt, code)
	if (desc is not null)
	then
	    let files[i].cnt=files[i].cnt+1
	    let files[i].lr=acc
	    return desc
	end if
    end if
    let code=code clipped,"?!"
    return code
end function
#
#  checks that file fname defines all the texts in codes
#
function txt_validate(fname, codes)
    define fname	char(14),
	   codes	char(80),
	   code		char(8),
	   desc		char(80),
	   f, nf	smallint

    let f=load_txt(fname)
    if (f is null)
    then
	return ""
    end if
    let nf=0
    call get_token(codes) returning code, codes
    while (code is not null)
	if (length(hst_retrieve(files[f].p_txt, code))=0)
	then
	    let nf=nf+1
	end if
	call get_token(codes) returning code, codes
    end while
    return nf
end function
#
#  loads txt file
#
function load_txt(fname)
    define fname	char(14),
	   code		char(40),
	   l_buf	char(80),
	   fd		smallint,
	   i, j		smallint

    let i=hst_retrieve(file_hash, fname)
    case
      when (i>0)
	return i
      when (i<0)
	return ""
    end case
    if (fcnt=20)
    then
	let i=dropfile_txt()
    else
	let i=fcnt+1
    end if
#
#  just in case we are trying to recover from something else!
#
    let status=0
    let fd=file_open(filepath(fgl_getenv("DBPATH"), fname), "r")
    if (status!=0)
    then
	call invalid_file(fname)
	call hst_enterint(file_hash, fname, -1)
	return ""
    end if
    let fcnt=fcnt+1
    let files[i].lr=0
    let files[i].cnt=0
    call hst_enterint(file_hash, fname, i)
    call hst_start(files[i].p_txt, 32)
    let files[i].fname=fname
    while (not fd_eof(fd))
	let l_buf=fd_read(fd)
	call fd_droptoeol(fd)
	let l_buf=txt_commentdrop(l_buf)
	call get_token(l_buf)
	  returning code, l_buf
	if (l_buf is not null)
	then
	    call hst_enter(files[i].p_txt, code, l_buf)
	end if
    end while
    let j=fd_close(fd)
    return i
end function
#
#  removes comments from lines of text
#
function txt_commentdrop(desc)
    define desc	char(78),
	   i	smallint
	   
    let i=pos(desc, "#")-1
    if (i>0)
    then
        let desc=desc[1, i]
    end if
    return desc clipped
end function
#
#  discard least frequently/recently used file
#
function dropfile_txt()
    define i,j,k,l,m	integer

    let k=1000000000		#anything big will do
    let l=1000000000
    for i=1 to fcnt-1
	case
	  when files[i].cnt>k
	     continue for
	  when files[i].cnt<k
	  when files[i].lr>l
	     continue for
	end case
	let j=i
	let k=files[i].cnt
	let l=files[i].lr
    end for
    call hst_free(files[j].p_txt)
    call hst_drop(file_hash, files[j].fname)
    let fcnt=fcnt-1
    return j
end function
