#	IMNUL.4gl - A few handy menu related routines
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: May 95
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
#  tipycal quick key browsing set up
#
function set_browse_keys()
    define i	smallint

    whenever error call trap_err
#
#  Note: no need to add control j, k and your next, prev page keys!
#
    let i=mnh_key(fgl_keyval("up"), MB_prevrow, "")
    let i=mnh_key(fgl_keyval("down"), MB_nextrow, "")
    let i=mnh_key(fgl_keyval("f2"), MB_prevrec, "")
    let i=mnh_key(fgl_keyval("f3"), MB_nextrec, "")
    let i=mnh_key(fgl_keyval("prevpage"), MB_prevpage, "")
    let i=mnh_key(fgl_keyval("nextpage"), MB_nextpage, "")
    let i=mnh_key(fgl_keyval("f1"), MB_home, "")
    let i=mnh_key(fgl_keyval("f4"), MB_end, "")
    let i=mnh_key(fgl_keyval("tab"), MB_nextpane, "")
end function
#
#  stb_viewer horizontal menu set_up
#
function set_stb_menu()
    call mnu_enable(MB_chooseset, MB_chooseset, 1, true)
    call mnu_enable(MB_newrec, MB_deleterec, 1, true)
    call mnu_record(MB_copyrec, MB_deleterec, K_focussedpane)
end function
#
#  app termination
#
function prog_done()
    define r	smallint,
	   q	char(10),
	   y, n	char(4),
	   l, s	smallint

    let q="   ", txt_retrieve("QUIT")
    let y=txt_retrieve("YES")
    let n=txt_retrieve("NO")
    let l=length(q)+length(y)+length(n)+10
    let s=(80-l)/2
    open window quit_win at 11, s
      with 2 rows, l columns
      attribute(border)
    menu q
      command n
	let r=false
	exit menu
      command y
	let r=true
	exit menu
    end menu
    close window quit_win
    return r
end function
#
#  insert item in vertical menu if parm != current viewer
#
function mnv_view(dm, qk, m, p)
    define dm	char(25),
	   qk	char(1),
	   m, p	smallint,
	   i	smallint

    if (p!=viewing())
    then
	return mnv_opt(dm, qk, m, p)
    else
	return ""
    end if
end function
#
#  find ShortCut key
#
function getfirstkey(dm)
    define dm	char(25),
	   i,j	smallint

    let i=1
    let j=length(dm)
    while i<j
	if ((dm[i]>="A") and (dm[i]<="Z")) or
	  ((dm[i]>="0") and (dm[i]<="9"))
	then
	    return dm[i]
	end if
	let i=i+1
    end while
    return ""
end function
