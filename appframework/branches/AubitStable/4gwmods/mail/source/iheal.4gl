#	IHEAL.4gl  -  4gwmail string conversion functions
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
#  here, it would have been nice to have sub, gsub, match & substr a la awk,
#  I was about to write my own, but libPW.a isn't available everywhere, so, for
#  now, I'm writing my RE's the hard way.
#  Note that as it is, these routines don't give a damn about folded comments,
#  folded quotes, nested comments, and comments delimiters within quotes!
#

#
#	returns formatted author
#
function mil_author(s)
    define s	char(78),
	   i, j	smallint

    whenever error call trap_err
    let i=pos(s, "(")+1
    if (i>1)
    then
	let j=pos(s, ")")-1
	if (j>i)
	then
	    let s=s[i, j]
	end if
    else
	let i=pos(s, "<")-1
	if (i>1)
	then
	    let s=s[1, i]
	end if
    end if
    return dropquote_mil(s)
end function
#
#	returns author's actual mailbox
#
function mil_getaddress(s)
    define s	char(78),
	   i, j	smallint

    let i=pos(s, "<")+1
    if (i>1)
    then
	let j=pos(s, ">")-1
	if (j>i)
	then
	    let s=s[i, j]
	end if
    else
	let i=pos(s, "(")-1
	if (i>1)
	then
	    let s=s[1, i]
	end if
    end if
    return dropquote_mil(downshift(s))
end function
#
#	returns the first angle bracketed string in the input string
#
function mil_anglebracket(s)
    define s	char(78),
	   i, j	smallint

    let i=pos(s, "<")
    if (i>0)
    then
	let j=pos(s, ">")
	if (j>i)
	then
	    let s=s[i, j]
	end if
    else
	let s=""
    end if
    return s
end function
#
#	finds & substitutes placeholder with real contents within string
#
function mil_changeparm(p, c, s)
    define p		char(2),
	   c, s		char(132),
	   i, j, k	smallint

    let i=pos(s, p)
    let j=i-1
    let k=i+length(p)
    case
      when (i=1)
	let s=c clipped, s[3, 132] clipped
      when (k=length(s)+1)
	let s=s[1, j], c clipped
      when (i!=0)
	let s=s[1, j], c clipped, s[k, 132] clipped
    end case
    return s
end function
#
#	drops comment from header
#
function mil_commentdrop(s)
    define s	char(78),
	   i, j	smallint

    let i=pos(s, "(")
    if (i>0)
    then
	let j=pos(s, ")")
	if (j>i)
	then
	    let s[i, j]=" "
	end if
    end if
    return s
end function
#
#	drops double quotes from string
#
function dropquote_mil(s)
    define s	char(70),
	   i, j	smallint

    let i=pos(s, "\"")
    while (i>0)
	let j=i+1
	let s[i, 70]=s[j, 70], " "
	let i=pos(s, "\"")
    end while
    return s
end function
