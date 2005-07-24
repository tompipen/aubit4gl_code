#	CSHLL.4gl - OS dependent routines, common bit
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
#  returns complete path name
#
function filepath(path, file)
    define path	char(64),
	   file	char(64),
	   s_1	char(128)

    whenever error call trap_err
    if path clipped!=" " and file[1]!="/"
    then
	let s_1=path clipped, "/", file clipped
    else
	let s_1=file clipped
    end if
    return s_1
end function
#
#  splits file name
#
function filesplit(path, d, n, e)
    define path		char(128),
    	   d, n ,e	smallint,
    	   il, id	smallint,
    	   i, j		smallint,
    	   r		char(128)
    	   
    let i=length(path)
    let il=""
    let id=""
    while (i>0)
	case
	  when path[i]="/"
	    if il is null
	    then
		let il=i
	    end if
	    exit while
	  when path[i]="."
	    if id is null
	    then
	        let id=i
	    end if
	end case
	let i=i-1
    end while
    let r=""
    if d and il>0
    then
        let r=path[1, il]
    end if
    if n
    then
    	if il>0
    	then
	    let i=il+1
	else
	    let i=1
	end if
	if id>0
	then
	    let j=id-1
	else
	    let j=length(path)
	end if
	let r=r clipped, path[i, j]
    end if
    if e and id>0
    then
        let j=length(path)
        let r=r clipped, path[id, j]
    end if
    return r
end function
#
#  returns a temporary file name
#
function tmp_filename(p)
    define p	char(3),
	   f	char(9)

    if length(p)=0
    then
	let p="tmp"
    end if
    let f=p clipped, get_process() using "&&&&&&"
    return filepath(fgl_getenv("INFORMIXTEMP"), f)
end function
