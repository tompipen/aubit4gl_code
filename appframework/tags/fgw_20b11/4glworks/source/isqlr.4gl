#	ISQLR.4gl - Query language report
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
#   query language reports
#
report sql_rep(code_ope, txt, q)
    define code_ope	char(8),		#OS dependent!
	   txt		char(78),
	   q,i		smallint,
	   pno		char(10),
	   ef		integer

    output
      left margin 0
      top margin 0
      bottom margin 0

    order external by q

    format
      page header
        whenever error call trap_err
	let ef=false
        call ptr_openpage(pageno)
	print code_ope clipped, "  ", today, " ", time;
	let pno="pag. ", pageno using "&&&&"
	print column ptr_right(pno), pno clipped
	for i=2 to ptr_right("")
	    print "-";
	end for
	skip 1 line

      before group of q
	if (q=0)
	then
	    skip to top of page
	    print "Query:"
	else
	    for i=2 to ptr_right("")
		print "-";
	    end for
	    skip 1 line
	end if
	
      on every row
	print txt clipped

      on last row
	let ef=true

      page trailer
	call ptr_closepage(ef)
end report
