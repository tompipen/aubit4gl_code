#	IAPPI.4gl - Applications maintenance
#
#	4gwMenus, an isql menus like 4glWorks module
#	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Sep 93
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
globals "istbg.4gl"
globals "itedg.4gl"

define
    app_rec	record
		    code_app	smallint,
		    desc_app	char(40),
		    app_type	char(2)
		end record,
    comment	char(80),
    p_a2u	array[20] of record
		    link_usr	char(8),
		    dummy_u	char(1)
		end record,
    p_mnu	array[4] of record
		    desc_mnu	char(25),
		    dummy_m	char(1)
		end record,
    h_mnu	array[4] of smallint,
    otc,
    uc, mc, omc	smallint

#
#  locks record to modify/remove
#
function lock_app(code_app)
    define code_app     smallint,
           sr           integer

    whenever error call trap_err
    call wrk_begin()
    whenever error continue
    set lock mode to not wait
    declare app_cl cursor for
      select * from applications
        where applications.code_app=code_app
    for update
    open app_cl
    fetch app_cl into app_rec.*
    whenever error call trap_err
    let sr=status
    if (wrk_check())
    then
        free app_cl
    end if
    return sr
end function
#
#  applications viewer
#
function app_viewer()
    define im, ip,
	   om, op,
	   fd		smallint

    whenever error call trap_err
    call menu_start()
    call stb_looks("", txt_fetch("ivwr.txt", viewing()), "")
    call set_stb_menu()
    call mnu_enable(MB_detailed, MB_detailed, 1, true)
    call open_app("")
    let om=MB_init
    let op=""
    let fd=MP_fulldisplay
    while true
	case
	  when (fd=MP_partdisplay)
	  when (op=MP_fulldisplay)
	    close form app_form
	end case
	call stb_scroller(om, op)
	  returning im, ip
	let op=fd
	case im
	  when MB_display
	    call display_app(fd)
	    let om=MB_display
	  when MB_detailed
	    open form app_form from "appf"
	    let fd=MP_partdisplay
	    call display_app(MP_fulldisplay)
	    let om=MB_display
	    let op=MP_partdisplay
	  when MB_brief
	    let fd=MP_fulldisplay
	    let om=MB_display
	    let op=MP_nodisplay
	  when MB_exit
	    exit while
	  when MB_newrec
	    initialize app_rec.* to null
	    let comment=""
	    let ted_count=0
	    let uc=0
	    let mc=0
	    let om=MB_recinserted
	    call insert_app(fd, "i")
	  when MB_copyrec
	    call load_app(code_1)
	    let om=MB_recinserted
	    call insert_app(fd, "c")
	  when MB_changerec
	    case lock_app(code_1)
	      when 0
		call load_app(code_1)
		call update_app(fd, "u")
		let om=MB_recchanged
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when MB_deleterec
	    case lock_app(code_1)
	      when 0
		call delete_app()
		let om=MB_recdeleted
		if int_flag
		then
		    let op=MP_nodisplay
		else
		    let op=MP_partdisplay
		end if
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when MB_chooseset
	    call select_app(fd)
	    let om=MB_newset
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    if (fd=MP_partdisplay)
    then
	close form app_form
    end if
    return ip
end function
#
#  search string initialization
#
function open_app(cond)
    define cond         char(250)

    case
      when (cond=" 1=1")
        let cond=""
      when cond clipped!=" "
        let cond=" where ", cond clipped
    end case
    let search="select code_app, desc_app, \"\" ",
               "from applications", cond clipped, " order by 1"
    call pan_home()
end function
#
#  application record display
#
function display_app(rd)
    define rd	smallint,
	   i	smallint

    if (rd=MP_fulldisplay)
    then
	display form app_form
	call usr_area()
    end if
    if (rd!=MP_nodisplay)
    then
	call load_app(code_1)
	display by name app_rec.code_app thru app_rec.app_type, comment
#
#  somebody might have screwed the ted screen rows
#
	call ted_start(10, K_maxtedrows, true, true)
	call ted_show()
	for i=1 to mc
	    display p_mnu[i].* to s_mnu[i].*
	end for
	for i=1 to minint(uc, 8)
	    display p_a2u[i].* to s_a2u[i].*
	end for
    end if
end function
#
#  application record load
#
function load_app(s_app)
    define s_app	smallint,
	   code_mnu	smallint,
	   desc_mnu	char(25),
	   link_mnu	smallint,
	   dummy_app	smallint,
	   i, j		smallint

    select applications.code_app, applications.desc_app, applications.app_type
      into app_rec.*
      from applications
      where applications.code_app=s_app
    let ted_count=1
    let uc=1
    let mc=0
    declare app_txt_curs cursor for
      select application_rows.row_num, application_rows.row_txt
	from application_rows
        where application_rows.link_app=s_app
        order by row_num
    foreach app_txt_curs into dummy_app, p_ted[ted_count].txt
        let ted_count=ted_count+1
        if (ted_count>K_maxtedrows)
        then
            exit foreach
        end if
    end foreach
    free app_txt_curs
    let ted_count=ted_count-1
    let otc=ted_count
    declare app2usr_curs cursor for
      select app2usr.link_usr from app2usr
        where app2usr.link_app=s_app
    foreach app2usr_curs into p_a2u[uc].link_usr
        let uc=uc+1
        if (uc>20)
        then
            exit foreach
        end if
    end foreach
    free app2usr_curs
    let uc=uc-1
    select mnu.code_mnu, mnu.desc_mnu, mnu.link_mnu
      into code_mnu, desc_mnu, link_mnu
      from mnu
      where mnu.link_app=app_rec.code_app
    while true
	if (SQLCA.SQLCODE!=0)
	then
	    exit while
	end if
	for i=mc to 1 step -1
	    let j=i+1
	    let p_mnu[j].desc_mnu=p_mnu[i].desc_mnu
	    let h_mnu[j]=h_mnu[i]
	end for
	let mc=mc+1
	let p_mnu[1].desc_mnu=desc_mnu
	let h_mnu[1]=code_mnu
	if (link_mnu is null)
	then
	    exit while
	end if
	select mnu.code_mnu, mnu.desc_mnu, mnu.link_mnu
	  into code_mnu, desc_mnu, link_mnu
	  from mnu
	  where mnu.code_mnu=link_mnu
    end while
    let omc=mc
    let comment=""
    if (mc>0)
    then
	select mnu_comment.comment into comment from mnu_comment, mnu
	  where mnu_comment.link_mnu=mnu.code_mnu
	    and mnu.desc_mnu=p_mnu[1].desc_mnu
    end if
end function
#
#  working set selection
#
function select_app(df)
    define df	smallint,
	   cond	char(250)

    if (df=MP_fulldisplay)
    then
	open form app_form from "appf"
	display form app_form
    else
	clear form
    end if
    call usr_input_area("q")
    let int_flag=false
    construct by name cond on applications.code_app, applications.desc_app,
			      applications.app_type
      help 2
      on key(control-b, F5)
	if infield(code_app)
	then
	    call multi_help("app", "", 78, "|", "", get_fldbuf(code_app))
	      returning cond
	    if cond is not null
	    then
		display cond to code_app
	    end if
	end if
    end construct
    if not int_flag
    then
	call open_app(cond)
    end if
end function
#
#  new record insertion
#
function insert_app(df, m)
    define df   smallint,
           m    char(1),
	   i	smallint

    while true
        call input_app(df, m)
	if int_flag
	then
            return
	end if
        let df=MP_nodisplay
	call wrk_begin()
        case
	  when insert_mnu(false, true)
          when tbl_lockwait("mnu", 5)
	    whenever error continue
	    insert into applications values (app_rec.*)
	    whenever error call trap_err
	    if (sqlca.sqlcode=0)
	    then
		exit while
	    end if
	    call check_writeop()
	    if wrk_rollback()
	    then
		call tbl_unlock("mnu")
	    end if
	    continue while
	end case
	let i=not wrk_rollback()
    end while
    let i=insert_mnu(false, false)
    call insert_app_rows(1)
    if wrk_end()
    then
	call tbl_unlock("mnu")
    end if
end function
#
#  record update
#
function update_app(df, m)
    define df           smallint,
           m            char(1),
	   i, j		smallint
 
    while true
	call input_app(df, m)
	let df=MP_nodisplay
	case
	  when int_flag
	    let i=wrk_rollback()
	    return
	  when insert_mnu(true, true)
	  when tbl_lockwait("mnu", 5)
	    exit while
	end case
    end while
    update applications
      set (code_app, desc_app, app_type)=
          (app_rec.code_app, app_rec.desc_app, app_rec.app_type)
      where current of app_cl
    let i=insert_mnu(true, false)
    let i=minint(ted_count, otc)
    for j=1 to i
	update application_rows set row_txt=p_ted[j].txt
	  where application_rows.link_app=app_rec.code_app
	    and application_rows.row_num=j
    end for
    call delete_app_rows(i+1)
    call insert_app_rows(otc+1)
    if wrk_commit()
    then
	call tbl_unlock("mnu")
	close app_cl
    end if
    free app_cl
end function
#
#  record deletion
#
function delete_app()
    case
      when tbl_lockwait("mnu", 5)
	call delete_mnu("")
	call delete_app_rows(1)
	delete from applications
	  where current of app_cl
	if wrk_commit()
	then
	    call tbl_unlock("mnu")
	    close app_cl
	end if
      when wrk_rollback()
	close app_cl
    end case
    free app_cl
end function
#
#  insert user & app info in detail tables
#
function insert_app_rows(idx)
    define idx	smallint,
	   i	smallint

    for i=1 to uc
	insert into app2usr
	  values(app_rec.code_app, p_a2u[i].link_usr)
    end for
    for i=idx to ted_count
	insert into application_rows
	  values(app_rec.code_app, i, p_ted[i].txt)
    end for
end function
#
#  delete user & app info from detail tables
#
function delete_app_rows(idx)
    define idx	smallint

    delete from app2usr
      where app2usr.link_app=app_rec.code_app
    delete from application_rows
      where application_rows.link_app=app_rec.code_app
	and application_rows.row_num>=idx
end function
#
#  SNAFU: a serial field would have been great as primary key in the menu
#  table, but, alas, it is also damn well nice to have menu pkeys as message
#  parameters (so as to have simple things like MB_mnuopen, <menu_entry>).
#  Sadly enough, back when everything started, I decided that since there was
#  no guarantee that primary keys would always have been integers, and 4gl does
#  not offer variable records, table references would be better left outside
#  messages. Smallint message parameters were appropriate for everything else,
#  so I stuck to smallints.
#  Now, a simple way to retain simplicity from both sides would be to change
#  the horz & vert menu routines to hold integer message parms, since most
#  likely, those will be the only places where we will be using menu
#  entries related messages, but it very looks like a dirty solution. For
#  starters it altogether precludes us from using viewer generated menu
#  related messages (very unlikely to be used, as of this writing, but, who
#  knows?). Instead, we're going to simulate serials, and compact the menu
#  table when needed.
#

#
#  insert/update menu tree entry
#
function insert_mnu(upd, check)
    define upd		smallint,
	   check	smallint,
	   i, lev	smallint,
	   insert_new	smallint,
	   new_key	smallint,
	   mnu_rec	record
			    code_mnu	smallint,
			    desc_mnu	char(25),
			    link_mnu	smallint,
			    link_app	smallint
			end record,
	   link_app	smallint

    let lev=1
    let insert_new=false
    let link_app=""
#
#  this is just to make sure we do not end up not refreshing the menu
#  (could still, happen, if we have to use cleanup_mnu, though)
#
    let new_key=fakeserial_mnu()
    initialize mnu_rec.* to null
    select mnu.* into mnu_rec.* from mnu
      where mnu.desc_mnu=p_mnu[1].desc_mnu
	and mnu.link_mnu is null
    while (lev<=mc)
	if (lev=mc)
	then
	    let link_app=app_rec.code_app
	end if
	case
#
#  new branch in menu chain
#
	  when insert_new
	    insert into mnu
	      values(new_key, p_mnu[lev].desc_mnu, mnu_rec.code_mnu, link_app)
	    if (lev=1)
	    then
		insert into mnu_comment
		  values(new_key, comment)
	    end if
	    let lev=lev+1
	    let mnu_rec.code_mnu=new_key
	    let new_key=new_key+1
#
#  menu chain on table differs from that in array, from here onwards
#
	  when sqlca.sqlcode=notfound
	    case
#
#  check only, no need to insert - for now
#
	      when check
		return false
#
#  delete differing bit of chain
#
	      when (upd and lev<=omc)
		call delete_mnu(h_mnu[lev-1])
	    end case
	    let insert_new=true
#
#  end of chain in array, and records on table. either link_app equals our own
#  or the menu chain in array is invalid
#
	  when (lev=mc)
	    case
	      when not upd
#
#  shortening chain, here
#
	      when mnu_rec.link_app is null
		exit while
	      when mnu_rec.link_app=app_rec.code_app
		return false
	    end case
	    call usr_warn("iapp.mnused")
	    return true
#
#  menu chain on table continues
#
	  when (mnu_rec.link_app is null)
	    let lev=lev+1
	    select mnu.* into mnu_rec.* from mnu
	      where mnu.desc_mnu=p_mnu[lev].desc_mnu
		and mnu.link_mnu=mnu_rec.code_mnu
#
#  user trying to prolong menu chain
#
	  when check
	    return false
	  otherwise
	    update mnu set link_app=""
	      where mnu.desc_mnu=p_mnu[lev].desc_mnu
		and mnu.code_mnu=mnu_rec.code_mnu
	    let lev=lev+1
	    let insert_new=true
	end case
    end while
#
#  trying to shorten a chain, or inserting to short a chain?
#
    if (omc>mc)
    then
#
#  we rely on 1) foreach evaluating the select and 2)
#  the engine leaving mnu_rec as it is after the last record...
#
	declare mnu_explore_curs cursor for
	  select mnu.* into mnu_rec.* from mnu
	    where mnu.link_mnu=mnu_rec.code_mnu
	let i=1
#
#  any menu entry out there pointing to other apps?
#
	while (i>0)
	    let i=0
	    foreach mnu_explore_curs
		let i=i+1
		if (mnu_rec.link_app is not null and
		    mnu_rec.link_app!=app_rec.code_app)
		then
#
#  yes! menu cannot be added/updated
#
		    close mnu_explore_curs
		    free mnu_explore_curs
		    call usr_warn("iapp.mninv")
		    return true
		end if
	    end foreach
	end while
	free mnu_explore_curs
	if (upd and not check)
	then
	    call delete_mnu(h_mnu[mc])
	    update mnu set link_app=app_rec.code_app
	      where mnu.code_mnu=h_mnu[mc]
	end if
    end if
    if (not check)
    then
	call cleanup_mnu()
    end if
    return false
end function
#
#  remove menu tree entry
#
function delete_mnu(code_mnu)
    define code_mnu	smallint,
	   mnu_rec	record
			    code_mnu	smallint,
			    desc_mnu	char(25),
			    link_mnu	smallint,
			    link_app	smallint
			end record,
	   i		integer

    initialize mnu_rec.* to null
    select mnu.* into mnu_rec.* from mnu
      where mnu.link_app=app_rec.code_app
    delete from mnu_comment
      where mnu_comment.link_mnu=mnu_rec.code_mnu
    delete from mnu
      where mnu.code_mnu=mnu_rec.code_mnu
#
#  the following assumes that the top level has a null link_mnu
#  if not, poor table!
#
    while (mnu_rec.link_mnu is not null and
	   (mnu_rec.link_mnu!=code_mnu or code_mnu is null))
	select count(*) into i from mnu
	  where mnu.link_mnu=mnu_rec.link_mnu
	if (i>0)
	then
	    exit while
	end if
	select mnu.* into mnu_rec.* from mnu
	  where mnu.code_mnu=mnu_rec.link_mnu
	delete from mnu_comment
	  where mnu_comment.link_mnu=mnu_rec.code_mnu
	delete from mnu
	  where mnu.code_mnu=mnu_rec.code_mnu
    end while
    call cleanup_mnu()
end function
#
#  compact menu structure
#
function cleanup_mnu()
    define mx, cnt	smallint,
	   c_mnu,
	   o_mnu	smallint

    select max(code_mnu), count(*) into mx, cnt from mnu
    case
      when (mx=cnt)		#already compacted
      when (mx<16000)		#not necessary
      when (mx*2>cnt+48000)	#compulsory above 48000, might do if 16000+ &
				#large enough gap wrt largest key
	declare mnu_cleanup_curs cursor for
	  select code_mnu from mnu
	    order by code_mnu
	let o_mnu=0
	foreach mnu_cleanup_curs into c_mnu
	    if (c_mnu!=o_mnu+1)
	    then
		update mnu set code_mnu=o_mnu+1
		  where mnu.code_mnu=c_mnu
		update mnu set link_mnu=o_mnu+1
		  where mnu.link_mnu=c_mnu
	    end if
	    let o_mnu=o_mnu+1
	end foreach
    end case
end function
#
#  returns max menu key
#
function fakeserial_mnu()
    define mx	smallint

    select max(code_mnu)+1 into mx from mnu
    if (mx is null)
    then
	return 1
    else
	return mx
    end if
end function
#
#  applications record input
#
function input_app(df, m)
    define df		smallint,
	   m		char(1),
	   dummy	char(40),
	   old_mnu1	char(25),
	   cr, sr, ld	smallint,
	   i, d, f	smallint

    call ted_start(10, K_maxtedrows, true, true)
    call ted_features(false, true)
    case
      when (df=MP_fulldisplay)
	open form app_form from "appf"
	display form app_form
      when (df=MP_partdisplay)
	clear form
    end case
    if (df!=MP_nodisplay)
    then
	call usr_input_area(m)
	for i=1 to mc
	    display p_mnu[i].* to s_mnu[i].*
	end for
	display by name comment
	for i=1 to minint(uc, 8)
	    display p_a2u[i].* to s_a2u[i].*
	end for
	call ted_show()
    end if
    let old_mnu1=p_mnu[1].desc_mnu
    let f=1
    let d=1
    let int_flag=false
    options input no wrap
    while true
	case f
	  when 1
	    input by name app_rec.*
	      without defaults help 2

	      before input
		case
		  when (d<0)
		    next field app_type
		  when (m="u")
		    next field desc_app
		end case

	      before field code_app
#
#  very simplified test if input nowrap is in effect
#
		if (m="u")
		then
		    exit input
		end if

	      after field code_app
		if code_check("app", app_rec.code_app)
		then
		    next field code_app
		end if

	      after field desc_app
		if desc_check("app", app_rec.desc_app, app_rec.code_app)
		then
		    next field desc_app
		end if

	      on key(control-b, F3)
		if infield(app_type)
		then
		    call uni_help("file", "iapp.lst", false, get_fldbuf(app_type))
		      returning app_rec.app_type, dummy
		    if (app_rec.app_type is not null)
		    then
			display by name app_rec.app_type
			next field app_type
		    end if
		end if

	    end input
	    let d=usr_action()
	  when 2
	    let ld=false
	    call set_count(mc)
	    input array p_mnu without defaults from s_mnu.* help 3
	      before row
                let cr=arr_curr()
                let sr=scr_line()
                if (cr<mc) and (d=-1)
                then
                    next field dummy_m
                else
                    let d=0
                end if

	      before insert
		let ld=(cr>=arr_count())

	      after field desc_mnu
		case
		  when ld
		  when (length(p_mnu[cr].desc_mnu)=0)
		    call usr_warn(-1305)
		    next field desc_mnu
		end case
		if (fgl_lastkey()=fgl_keyval("autonext"))
		then
		    let d=cr+1
		    let mc=arr_count()
		    next field next
		end if

	      after insert, delete
		let ld=false

	      after row
		let ld=false
                if (d=0)
                then
                    let d=usr_direction(4, 4, p_mnu[cr].desc_mnu is null)
                    if (d!=0)
                    then
                        exit input
                    end if
                end if
	    end input
	    let mc=arr_count()
	    while (mc>0)
		if (p_mnu[mc].desc_mnu is null)
		then
		    let mc=mc-1
		else
		    exit while
		end if
	    end while
	  when 3
	    case
	      when (old_mnu1=p_mnu[1].desc_mnu)
	      otherwise
		let comment=""
		select mnu_comment.comment into comment
		  from mnu_comment, mnu
		  where mnu.desc_mnu=p_mnu[1].desc_mnu
		    and mnu.code_mnu=mnu_comment.link_mnu
		display by name comment
		let old_mnu1=p_mnu[1].desc_mnu
	    end case
	    input by name comment without defaults
	      after field comment
		exit input
	    end input
	    let d=usr_action()
	  when 4
	    let ld=false
	    call set_count(uc)
	    input array p_a2u without defaults from s_a2u.* help 3
	      before row
                let cr=arr_curr()
                let sr=scr_line()
                if (cr<uc) and (d=-1)
                then
                    next field dummy_u
                else
                    let d=0
                end if

	      before insert
		let ld=(cr>=arr_count())

	      after field link_usr
		case
		  when ld
		  when (length(p_a2u[cr].link_usr)=0)
		    call usr_warn(-1305)
		    next field link_usr
		end case
		if (fgl_lastkey()=fgl_keyval("autonext"))
		then
		    let d=cr+1
		    let uc=arr_count()
		    next field next
		end if

	      after insert, delete
		let ld=false

	      after row
		let ld=false
                if (d=0)
                then
                    let d=usr_direction(5, 20, p_a2u[cr].link_usr is null)
                    if (d!=0)
                    then
                        exit input
                    end if
                end if
	    end input
	    let uc=arr_count()
	    while (uc>0)
		if (p_a2u[uc].link_usr is null)
		then
		    let uc=uc-1
		else
		    exit while
		end if
	    end while
	  when 5
	    let d=ted_input(d, true)
	end case
	let f=f+d
	case
	  when (d=0)
	    exit while
	  when (f<1)
	    let f=5
	  when (f>5)
	    let f=1
	end case
    end while
    options input wrap
end function
