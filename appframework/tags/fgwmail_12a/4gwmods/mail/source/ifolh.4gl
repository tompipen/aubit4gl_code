#	IFOLH.4gl  -  4gwmail folder picklist
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
 
globals "imilg.4gl"

#
#	choose new or output folder
#
function mil_choose(folders, newsrc, cur, ib)
    define folders,
	   newsrc,
	   cur		char(70),
	   ib, ng	smallint,
	   newbox	char(70),
	   newname	char(70),
	   t, s		integer,
	   ds		char(300)

    whenever error call trap_err
    let ng=(newsrc is not null)
    if (ib)
    then
	let ds="echo \"Inbox\"; "
    else
	let ds=""
    end if
    if (folders is not null)
    then
	let ds=ds clipped, "(cd ", folders clipped,
	       "; for i in *; do test -r $i -a ! -d $i && echo $i; done); "
    end if
    if (ng)
    then
	let ds=ds clipped,
	       "${AWK:-awk} -F: ' ($1 !~ /[!#]/) { print $1 }' ", newsrc, " 2>&-"
    end if
    if (ds is null)
    then
	return "", ""
    end if
    let newname=uni_desc("pipe", ds, "")
    if (newname="Inbox")
    then
	let newbox=inbox
	let ng=false
    else
	let newbox=filepath(folders, newname)
    end if
    case
      when newname is null
	return "", ""
      when (cur=newbox)
	call usr_warn("imil.sf")
	return "", ""
      when (folders is null)
	let newbox=newname
      when (newname is not null) and (ng)
#
#  this fails if somebody else has created a folder named like a the choosen
#  newsgroup in *this* exact moment - highly unlikely
#
	call mil_getstat(newbox)
	  returning t, s
	if (t=get_time()) and (s=0)
	then
	    let newbox=newname
	end if
    end case
    return newbox, newname
end function
