#	IMLTR.4gl  -  mlt_viewer report
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

define hdr	char(78),
       tl	char(60)
#
#  report head & tail selection
#
function mlt_head_tail(h, t)
    define h	char(78),
	   t	char(40)

    whenever error call trap_err
    let hdr=h
    let tl=time
    let tl=t clipped, "  ", today, " - ", tl[1,5]
end function
#
#  mlt_viewer report
#
report mlt_rep(txt)
    define txt		char(78),
	   pno		char(12),
	   ef		integer,
	   d		date

    output
      left margin 0
      top margin 0
      bottom margin 0

    format
      first page header
	call ptr_openpage(1)
	let ef=false
	print column ptr_center(hdr), hdr clipped
	skip 1 line

      page header
	call ptr_openpage(pageno)
	print column ptr_center(hdr), hdr clipped
	skip 1 line

      on every row
	print txt clipped

      on last row
	let ef=true

      page trailer
	skip 1 line
	let pno=ptr_pagenumber(pageno, ef)
	print tl clipped, column ptr_right(pno), pno clipped
	call ptr_closepage(ef)
end report
