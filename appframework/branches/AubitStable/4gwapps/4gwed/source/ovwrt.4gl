#	OVWRT.4gl - batch scripting operation
#
#	4gwEd, a dbaccess like 4glWorks based application
#	Copyright (C) 1999-2002 Marco Greco (marco@4glworks.com)
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

#include "csqll.4gh"

function parse_options()
    define query	text,
	   opt, inf 	char(100),
	   fdi, fdo,
	   i		smallint,
	   flags, w	integer,
	   txtvar	text

    whenever error call trap_err
    let w=""
    let inf=""
    let flags=K_dml+K_noconf
    for i=1 to num_args()
	let opt=arg_val(i)
	case
	  when (inf is null) and (opt="-w") and (w is null)
	    let i=i+1
	    let w=str2int(arg_val(i))
	    if (w is null)
	    then
		exit program(1)
	    end if
	  when (inf is null) and (opt="-h") and not (bwand(flags, K_html))
	    let flags=flags+K_html
	  when (inf is null) and (opt="-")
	    let inf="-"
	  when (inf is null) and (opt[1]!="-")
	    let inf=opt
	  otherwise
	    exit program(1)
	end case
    end for
    if (inf is null) and (w or bwand(flags, K_html))
    then
	let inf="-"
    end if 
    case
      when (inf is null)
	return
      when (inf="-")
	let fdi=stdfd_open(0)
      otherwise
	let fdi=file_open(inf, "r")
	if status
	then
	    exit program (status)
	end if
    end case
    let i=usr_setbatch(true)
    call afw_init()
    let fdo=stdfd_open(1)
    if (w is null)
    then
	let w=78
    end if
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
    exit program(0)
end function
