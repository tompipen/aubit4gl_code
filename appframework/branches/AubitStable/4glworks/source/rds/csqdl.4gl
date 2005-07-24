#	CSQDL.4gl - SQL interpreter dynamic sql 4gl support functions
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Jun 98
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
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include "idefl.4gh"
#include "csqll.4gh"

#
#  execute immediate statement
#
function sql_immediate(i_query)
    define i_query	char(K_scriptbuf),
	   r		integer

    prepare sql_stat from i_query
    whenever error continue
    execute sql_stat
    whenever error call trap_err
    let r=sqlca.sqlcode
    free sql_stat
    return r
end function
