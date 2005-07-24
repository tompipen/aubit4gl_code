#	OVWRT.4gl - sql interpreter
#
#	4gwMenus, an isql menus like 4glWorks module
#	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Apr 98
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

#include "csqll.4gh"

main
    define query	text,
	   fdi, fdo, i	smallint,
	   flags, w	integer,
	   txtvar	text

    whenever error call trap_err
    call afw_init()
    let w=""
    let flags=K_dml+K_noconf
    for i=1 to num_args()
	case
	  when (arg_val(i)="-w") and (w is null)
	    let i=i+1
	    let w=str2int(arg_val(i))
	    if (w is null)
	    then
		exit program(1)
	    end if
	  when (arg_val(i)="-h") and not (bwand(flags, K_html))
	    let flags=flags+K_html
	  otherwise
	    exit program(1)
	end case
    end for
    if (w is null)
    then
	let w=78
    end if
    let fdi=stdfd_open(0)
    let fdo=stdfd_open(1)
    locate query in memory
    call fd_blobread(fdi, query)
    let i=fd_close(fdi)
    call asc_initialize(query)
    let i=sql_execute2(query, fdo, flags, w, txtvar)
    call asc_free(query)
    if (i!=0)
    then
	call usr_warn(i)
    end if
    call asc_free(txtvar)
end main
