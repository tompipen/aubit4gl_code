#	IFSTM.4gl  -  Sample menu #1
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
#include "idefl.4gh"
#include "ivwrl.4gh"

function menu_fst()
    define i, im, ip	smallint

    whenever error call trap_err
    call mnv_start()
    let i=mnv_view("null Viewer", "V", MB_exit, V_nul)
    let i=mnv_opt("Choose", "C", MB_chooseset, "")
    let i=mnv_opt("Reread", "R", MB_reloadset, MP_partdisplay)
    let i=mnv_view("Error log", "E", MB_exit, V_log)
    let i=mnv_view("sql Interpreter", "I", MB_exit, V_sql)
    let i=mnv_view("Application maintenance", "A", MB_exit, V_app)
    let i=mnv_view("Printer maintenance", "P", MB_exit, V_ptr)
    let i=mnv_view("Form maintenance", "F", MB_exit, V_frm)
    let i=mnv_view("Model maintenance", "M", MB_exit, V_mdl)
    let i=mnv_view("form to printer Table", "T", MB_exit, V_f2p)
    call app_mnvget() returning im, ip
    case
      when im is not null
	return im, ip
      when ip is null
	return MB_display, MP_nodisplay
    end case
end function
