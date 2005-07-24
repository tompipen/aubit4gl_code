#	CSTRL.4gl  -  string related functions
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
#  produces a centered string
#
function str_center(s, l)
    define s	char(78),
	   l, i	smallint

    whenever error call trap_err
    let i=(l+length(s))/2
    if (i>0) and (i<78)
    then
	let s=s[i, l], s clipped
    end if
    return s
end function
#
#  left justifies a code
#
function str_left(code)
    define code	char(8),
	   i	smallint

    let i=1
    if length(code)=0
    then
	return ""
    end if
    while code[i]=" "
	let i=i+1
    end while
    return code[i,8]
end function
#
#  right justifies a code
#
function str_right(code)
    define code	char(8),
	   i	smallint

    let i=length(code)+1
    if (i<9)
    then
	let code=code[i,8], code clipped
    end if
    return code
end function
#
#  encodes a string so to have unprintable chars as \ddd
#
function str_encode(istr)
    define istr,
	   ostr		char(80),
	   j, k		smallint,
	   c		char(1)

    let k=0
    let ostr=""
    for j=1 to length(istr)
    	let c=istr[j]
    	case
    	  when c="\\"
    	    let k=k+1
    	    let ostr[k]="\\"
    	    let k=k+1
    	    let ostr[k]="\\"
    	  when c>=(ascii 32) and (c<=ascii 126)
    	    let k=k+1
    	    let ostr[k]=c
	  otherwise
    	    let ostr=ostr clipped,
      		     "\\", char2int(c) using "&&&"
	    let k=k+4
	end case
    end for
    return ostr
end function
#
#  decodes a string so that any \ddd occurrence is mapped to
#  the corresponding char
#
function str_decode(istr)
    define istr,
	   ostr		char(80),
	   j, j1, k, l,
	   errc		smallint,
	   c		char(1)

    let ostr=""
    let k=length(istr)
    let errc=0
    let j=0
    let l=0
    while j<k
	let j=j+1
	let c=istr[j]
	let j1=j+1
	let errc=j
	case
	  when (c!="\\")
	  when (istr[j1]="\\")
	    let j=j1
	  otherwise
	    let j=j+3
	    if (j>k)
	    then
		exit while
	    end if
	    whenever any error continue
	    let j1=istr[j1,j]
	    whenever error call trap_err
	    if (status!=0) or (j1=0) or (j1>255)
	    then
		exit while
	    end if
	    let c=ascii j1
	end case
	let l=l+1
	let ostr[l]=c
	let errc=0
    end while
    if (errc>0)
    then
	return istr, errc
    else
	return ostr, 0
    end if
end function
