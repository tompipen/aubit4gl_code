#	IAPPL.4gl - Applications menu library
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
#include "csqll.4gh"
#define MB_executeapp	 32001
#define MB_openmnu	-32001
globals "istbg.4gl"

#
#  contrary to normal Informix wisdom, we do not even bother to close &
#  free the menu entries cursor for plain performance reasons
#
define mnu_top	smallint,
       mnu_cnt	smallint,
       mnu_max	smallint,
       mnh_cnt	smallint,
       app_vwr	smallint,
       app2mnh	array[25] of record
			    msg,
			    parm,
			    mnu		smallint
		end record

#
#  app library initialization
#
function app_init()
    whenever error call trap_err
    let mnu_cnt=0
    let mnu_max=""
    let mnh_cnt=0
    let app_vwr=0
end function
#
#  set viewer
#
function app_setviewer(v)
    define v	smallint

    let app_vwr=v
end function
#
#  declares cursors
#
function declare_mnu()
    prepare mnu_drill_stmt from "execute procedure mnu_expand(?)"
    declare mnu_drill_curs cursor for mnu_drill_stmt
    declare mnu_change_curs cursor for
      select * from mnu_changes
end function
#
#  mnh_get replacement
#
function app_mnhget()
    define im, ip	smallint,
	   code_mnu	smallint,
	   link_app	smallint,
	   desc_mnu	char(25),
	   comment	char(80),
	   i, c, m	smallint

    let mnu_top=""
    let code_mnu=""
    if (mnu_max is null)
    then
	call declare_mnu()
    end if
    whenever error continue
    open mnu_change_curs
#
#  somebody might have opened a new database here
#
    if (sqlca.sqlcode)
    then
	call declare_mnu()
	open mnu_change_curs
    end if
    whenever error call trap_err
    fetch mnu_change_curs into c, m
    if (c!=mnu_cnt) or (m!=mnu_max)
    then
	let mnh_cnt=0
	let mnu_cnt=c
	let mnu_max=m
	let i=mnh_drop(MB_executeapp, MP_allbodies)
	let i=mnh_drop(MB_openmnu, MP_allbodies)
	call open_mnu("")
	call fetch_mnu() returning code_mnu, link_app, desc_mnu, comment
    end if
    while code_mnu is not null
	if (link_app is not null)
	then
	    let i=mnh_opt(desc_mnu, comment, getfirstkey(desc_mnu), "",
			  MB_executeapp, link_app)
	else
	    let i=mnh_opt(desc_mnu, comment, getfirstkey(desc_mnu), "",
			  MB_openmnu, code_mnu)
	    if (i is null)
	    then
		call mnh_error()
		  returning desc_mnu, im, ip 
		if (mnh_cnt<25)
		then
		    let mnh_cnt=mnh_cnt+1
		    let app2mnh[mnh_cnt].msg=im
		    let app2mnh[mnh_cnt].parm=ip
		    let app2mnh[mnh_cnt].mnu=code_mnu
		end if
	    end if
	end if
	if (i=0)
	then
	    exit while
	end if
	call fetch_mnu() returning code_mnu, link_app, desc_mnu, comment
    end while
    call mnh_get() returning im, ip
    case
      when (im=MB_executeapp)
	call app_execute(ip)
	  returning im, ip
      when (im=MB_openmnu)
	call deploy_mnu(ip)
	  returning im, ip
      otherwise
	for i=1 to mnh_cnt
	    if (mnh_compare(im, ip, app2mnh[i].msg, app2mnh[i].parm))
	    then
		let mnu_top=app2mnh[i].mnu
		exit for
	    end if
	end for
    end case
    return im, ip
end function
#
#  mnv_get replacement
#
function app_mnvget()
    define im, ip	smallint,
	   code_mnu	smallint,
	   link_app	smallint,
	   desc_mnu	char(25),
	   dummy	char(80),
	   t, i		smallint,
	   app2mnv	array[25] of record
			    msg,
			    parm,
			    mnu		smallint
			end record

    if (mnu_top is null)
    then
	call mnv_get() returning im, ip
	return im, ip
    end if
    let t=0
    call open_mnu(mnu_top)
    call fetch_mnu() returning code_mnu, link_app, desc_mnu, dummy
    while code_mnu is not null
	if (link_app is not null)
	then
	    let i=mnv_opt(desc_mnu, getfirstkey(desc_mnu),
			  MB_executeapp, link_app)
	else
	    let i=mnv_opt(desc_mnu, getfirstkey(desc_mnu),
			  MB_openmnu, code_mnu)
	    if (i is null)
	    then
		call mnv_error()
		  returning desc_mnu, im, ip 
		if (t<25)
		then
		    let t=t+1
		    let app2mnv[t].msg=im
		    let app2mnv[t].parm=ip
		    let app2mnv[t].mnu=code_mnu
		end if
	    end if
	end if
	if (i=0)
	then
	    exit while
	end if
	call fetch_mnu() returning code_mnu, link_app, desc_mnu, dummy
    end while
    let mnu_top=""
    call mnv_get() returning im, ip
    case
      when (im=MB_executeapp)
	call app_execute(ip)
	  returning im, ip
      when (im=MB_openmnu)
	call deploy_mnu(ip)
	  returning im, ip
      otherwise
	for i=1 to t
	    if (mnh_compare(im, ip, app2mnv[i].msg, app2mnv[i].parm))
	    then
		let mnu_top=app2mnv[i].mnu
		exit for
	    end if
	end for
    end case
    return im, ip
end function
#
#  internal vertical menu display function
#
function deploy_mnu(lm)
    define lm		smallint,
	   im, ip	smallint,
	   code_mnu	smallint,
	   link_app	smallint,
	   desc_mnu	char(25),
	   dummy	char(80),
	   i		smallint

    while true
	call mnv_start()
	call open_mnu(lm)
	call fetch_mnu() returning code_mnu, link_app, desc_mnu, dummy
	while code_mnu is not null
	    if (link_app is not null)
	    then
		let i=mnv_opt(desc_mnu, getfirstkey(desc_mnu),
			      MB_executeapp, link_app)
	    else
		let i=mnv_opt(desc_mnu, getfirstkey(desc_mnu),
			      MB_openmnu, code_mnu)
	    end if
	    if (i=0)
	    then
		exit while
	    end if
	    call fetch_mnu() returning code_mnu, link_app, desc_mnu, dummy
	end while
	call mnv_get() returning im, ip
	case
	  when (im=MB_executeapp)
	    call app_execute(ip)
	      returning im, ip
	  when (im=MB_openmnu)
	   let lm=ip
	   continue while
	end case
	return im, ip
    end while
end function
#
#  executes an application
#
function app_execute(la)
    define la		smallint,
	   i_query	char(32000),
	   o_query	char(32000), 
	   app_type	char(2),
	   touch	integer,
	   textvar	text,
	   hash		byte,
	   i, ol, 
	   s, e, r	smallint,
	   fd		integer,
	   msg		smallint,
	   txt  	char(80)

    select app.app_type into app_type from app
      where app.code_app=la
    if (sqlca.sqlcode!=0)
    then
	return "", ""
    end if
    declare app_code_curs cursor for
      select row_txt, row_num from app_rows
	where app_rows.link_app=la
    order by row_num
    let i_query=""
    let s=0
    foreach app_code_curs into txt, i
	let s=s+length(txt)+1
	if (s>32000)
	then
	    exit foreach
	end if
	let i_query=i_query clipped, ascii 10, txt
    end foreach
    free app_code_curs
    if (app_type="M" or app_type="Q")
    then
	if (app_type="M")
	then
	    let touch=K_dml+K_noconf
	else
	    let touch=0
	end if
	if (sql_execute(i_query, 0, touch+K_verbose, 78, textvar)=0)
	then
	    call apv_settype(MB_chooseset, la)
	    call uni_settext(textvar)
	    call asc_free(textvar)
	    return MB_exit, app_vwr
	else
	    call asc_free(textvar)
	    return "", ""
	end if
    end if
    let msg=MB_reloadset
    let o_query=""
    let r=1
    let ol=0
    while (r is not null)
	call sql_explode(i_query, hash, false, true, r)
	  returning s, e, txt, r
	if (sqlca.sqlcode!=0)
	then
	    if (sqlca.sqlcode!=notfound)
	    then
		call usr_warn(sqlca.sqlcode)
	    end if
	    call hst_free(hash)
	    return MB_display, MP_nodisplay
	end if
	case
	  when (s is null)
	  when (ol)
	    let o_query=o_query[1, ol], i_query[s, e]
	    let ol=ol+e-s+1
	  otherwise
	    let o_query=i_query[s, e]
	    let ol=e-s+1
	end case
	case
	  when (txt is null)
	  when (ol)
	    let msg=MB_chooseset
	    let o_query=o_query[1, ol], txt clipped
	    let ol=ol+e-s+1
	  otherwise
	    let msg=MB_chooseset
	    let o_query=txt clipped
	    let ol=length(txt)
	end case
    end while
    call usr_status("wa")
    free hash
    case
      when (app_type="P")
	let fd=pipe_open(o_query, "r")
	case
	  when (sqlca.sqlcode=notfound)
	  when (sqlca.sqlcode!=0)
	    call usr_warn(r)
	  otherwise
	    call uni_create()
	    while (not fd_eof(fd))
		let txt=fd_read(fd)
		call uni_newline(txt)
	    end while
	    let i=fd_close(fd)
	    call apv_settype(msg, la)
	    return MB_exit, app_vwr
	end case
      otherwise
	if (app_type="EB")
	then
	    let o_query=o_query clipped, "&"
	end if
	let i=shell(o_query)
	if (app_type="EW")
	then
	    call shl_hitkey()
	end if
    end case
    call usr_status("")
    return "", ""
end function
#
#  open layer expansion cursor
#
function open_mnu(lm)
    define lm	smallint

    open mnu_drill_curs using lm
end function
#
#  fetch next menu entry
#
function fetch_mnu()
    define cm	smallint,
	   la	smallint,
	   dm	char(25),
	   cmt	char(80)

    let cm=""
    fetch mnu_drill_curs into cm, la, dm, cmt
    return cm, la, dm, cmt
end function
