#	IF2PI.4gl - Form to printer mtm maintenance
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Feb 97
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
globals "istbg.4gl"

    define frm2ptr_rec	record
			    link_frm	smallint,
			    link_ptr	smallint,
			    init	char(50)
			end record,
	   control	char(40),
	   desc_frm	char(40),
	   desc_ptr	char(40)

#
#  locks record to modify/remove
#
function lock_frm2ptr(link_frm, link_ptr)
    define link_frm,
	   link_ptr	smallint,
	   sr		integer

    whenever error call trap_err
    call wrk_begin()
    whenever error continue
    set lock mode to not wait
    declare frm2ptr_cl cursor for
      select * from frm2ptr
	where frm2ptr.link_frm=link_frm
	  and frm2ptr.link_ptr=link_ptr
    for update
    open frm2ptr_cl
    fetch frm2ptr_cl into frm2ptr_rec.*
    whenever error call trap_err
    let sr=status
    if (wrk_check())
    then
	free frm2ptr_cl
    end if
    return sr
end function
#
#  form viewer
#
function frm2ptr_viewer()
    define im, ip,
	   om, op,
	   fd, i	smallint

    call menu_start()
    call dtb_looks("", txt_fetch("ivwr.txt", viewing()), "")
    call set_stb_menu()
    call mnu_enable(MB_detailed, MB_detailed, 1, true)
    call open_frm2ptr("")
    let om=MB_init
    let op=""
    let fd=MP_fulldisplay
    while true
#
#  close the form left open by services (brief display only)
#
	case
	  when (fd=MP_partdisplay)
	  when (op=MP_fulldisplay)
	    close form frm2ptr_form
	end case
	call dtb_scroller(om, op) returning im, ip
	let om=MB_display
	let op=fd
	case
	  when (im=MB_display)
	    call display_frm2ptr(ip)
	  when (im=MB_detailed)
	    open form frm2ptr_form from "f2pf"
	    let fd=MP_partdisplay
	    initialize frm2ptr_rec.* to null
	    call display_frm2ptr(MP_fulldisplay)
	    let op=MP_partdisplay
	  when (im=MB_brief)
	    let fd=MP_fulldisplay
	    let op=MP_fulldisplay
	  when (im=MB_exit)
	    exit while
	  when (im=MB_newrec)
	    initialize frm2ptr_rec.* to null
	    let desc_frm=""
	    let desc_ptr=""
	    let om=MB_recinserted
	    call insert_frm2ptr(fd, "i")
	  when (im=MB_copyrec)
	    if testmodel_frm2ptr(code_1, code_2)
	    then
		let op=MP_nodisplay
		continue while
	    end if
	    call load_frm2ptr(code_1, code_2)
	    let om=MB_recinserted
	    call insert_frm2ptr(fd, "c")
	  when (im=MB_changerec)
	    if testmodel_frm2ptr(code_1, code_2)
	    then
		let op=MP_nodisplay
		continue while
	    end if
	    case lock_frm2ptr(code_1, code_2)
	      when 0
		call load_frm2ptr(code_1, code_2)
		call update_frm2ptr(fd, "u")
		let om=MB_recchanged
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when (im=MB_deleterec)
	    case lock_frm2ptr(code_1, code_2)
	      when 0
		call delete_frm2ptr()
		let om=MB_recdeleted
		let op=MP_partdisplay
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when (im=MB_chooseset)
	    call select_frm2ptr(fd)
	    let om=MB_newset
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    if (fd=MP_partdisplay)
    then
	close form frm2ptr_form
    end if
    return ip
end function
#
#  form record display
#
function display_frm2ptr(rd)
    define rd	smallint

    if (rd=MP_fulldisplay)
    then
	display form frm2ptr_form
	call usr_area()
    end if
    if (rd!=MP_nodisplay)
    then
	call load_frm2ptr(code_1, code_2)
	display by name frm2ptr_rec.*, desc_frm, desc_ptr
    end if
end function
#
#  form record load
#
function load_frm2ptr(link_frm, link_ptr)
    define link_frm,
	   link_ptr	smallint

    select frm2ptr.link_frm, frm2ptr.link_ptr, frm2ptr.init
      into frm2ptr_rec.link_frm, frm2ptr_rec.link_ptr, control
      from frm2ptr
      where frm2ptr.link_frm=link_frm
	and frm2ptr.link_ptr=link_ptr
    let desc_frm=""
    let desc_ptr=""
    select frm.desc_frm into desc_frm from frm
      where frm.code_frm=frm2ptr_rec.link_frm
    select ptr.desc_ptr into desc_ptr from ptr
      where ptr.code_ptr=frm2ptr_rec.link_ptr
    let frm2ptr_rec.init=str_encode(control)
end function
#
#  working set selection
#
function select_frm2ptr(df)
    define df	smallint,
	   cond	char(250)

    if (df=MP_fulldisplay)
    then
	open form frm2ptr_form from "f2pf"
	display form frm2ptr_form
    else
	clear form
    end if
    call usr_input_area("q")
    let int_flag=false
    construct by name cond on link_frm, link_ptr
      help 2
      on key (control-b, F5)
	case
	  when infield(link_frm)
	    call multi_help("frm", "", 78, "|", "", get_fldbuf(link_frm))
	      returning cond
	    if cond is not null
	    then
		display cond to link_frm
	    end if
	  when infield(link_ptr)
	    call multi_help("ptr", "", 78, "|", "", get_fldbuf(link_ptr))
	      returning cond
	    if cond is not null
	    then
		display cond to link_ptr
	    end if
	end case

    end construct
    if not int_flag
    then
	call open_frm2ptr(cond)
    end if
end function
#
#  sets search condition
#
function open_frm2ptr(cond)
    define cond	char(300)

    let search=
	"select link_frm, link_ptr, desc_frm, desc_ptr",
	" from frm2ptr, outer frm, outer ptr",
	" where frm2ptr.link_frm=frm.code_frm and frm2ptr.link_ptr=ptr.code_ptr"
    if cond is not null and (cond!=" 1=1")
    then
	let search=search clipped, " and (", cond clipped, ")"
    end if
    let search=search clipped, " order by link_frm, link_ptr"
    call pan_home()
end function
#
#  tests for model compatibility
#
function testmodel_frm2ptr(link_frm, link_ptr)
    define link_frm,
	   link_ptr	smallint,
	   r		smallint

    select true into r from frm, ptr
      where frm.code_frm=link_frm
	and ptr.code_ptr=link_ptr
	and frm.link_mdl=ptr.link_mdl
    if (status!=0)
    then
	call usr_warn("cptr.dm")
	return true
    end if
    return false
end function
#
#  new record insertion
#
function insert_frm2ptr(df, m)
    define df	smallint,
	   m	char(1),
	   sr	integer

    while true
	call input_frm2ptr(df, m)
	let df=MP_nodisplay
	if int_flag
	then
	    exit while
	else
	    whenever error continue
	    insert into frm2ptr values
	      (frm2ptr_rec.link_frm, frm2ptr_rec.link_ptr, control)
	    whenever error call trap_err
	    if (status!=0)
	    then
		call check_writeop()
	    else
		exit while
	    end if
	end if
    end while
end function
#
#  record update
#
function update_frm2ptr(df, m)
    define df	smallint,
	   m	char(1),
	   sr	integer
 
    call input_frm2ptr(df, m)
    case
      when not int_flag
	update frm2ptr
	  set init=control
	  where current of frm2ptr_cl
	if wrk_commit()
	then
	    close frm2ptr_cl
	end if
      when wrk_rollback()
	close frm2ptr_cl
    end case
    free frm2ptr_cl
end function
#
#  record deletion
#
function delete_frm2ptr()
    delete from frm2ptr
      where current of frm2ptr_cl
    if wrk_commit()
    then
	close frm2ptr_cl
    end if
    free frm2ptr_cl
end function
#
#  frm2ptr record input
#
function input_frm2ptr(df, m)
    define df	smallint,
	   m	char(1),
	   dir, i, j 	smallint

    case
      when (df=MP_fulldisplay)
	open form frm2ptr_form from "f2pf"
	display form frm2ptr_form
      when (df=MP_partdisplay)
	clear form
    end case
    if (df!=MP_nodisplay)
    then
	call usr_input_area(m)
	display by name desc_frm, desc_ptr
    end if
    let int_flag=false
    input by name frm2ptr_rec.*
      without defaults help 2

      before input
	if (m="u")
	then
	    next field init
	end if

      after field link_frm
	select frm.desc_frm into desc_frm from frm
	  where frm.code_frm=frm2ptr_rec.link_frm
	if not_found(frm2ptr_rec.link_frm)
	then
	    let frm2ptr_rec.link_frm=""
	    next field link_frm
	else
	    display by name desc_frm
	end if

      after field link_ptr
	select ptr.desc_ptr into desc_ptr from ptr
	  where ptr.code_ptr=frm2ptr_rec.link_ptr
	if not_found(frm2ptr_rec.link_ptr)
	then
	    let frm2ptr_rec.link_ptr=""
	    next field link_ptr
	else
	    display by name desc_ptr
	end if

      on key (control-b, F5)
	case
	  when infield(link_frm)
	    call uni_help("frm", "", false, get_fldbuf(link_frm))
	      returning frm2ptr_rec.link_frm, desc_frm
	    if frm2ptr_rec.link_frm is not null
	    then
		display by name frm2ptr_rec.link_frm, desc_frm
	    end if
	  when infield(link_ptr)
	    call uni_help("ptr", "", false, get_fldbuf(link_ptr))
	      returning frm2ptr_rec.link_ptr, desc_ptr
	    if frm2ptr_rec.link_ptr is not null
	    then
		display by name frm2ptr_rec.link_ptr, desc_ptr
	    end if
	end case

      after field init
	call str_decode(frm2ptr_rec.init)
	  returning control, j
	case
	  when (j!=0)
	    call usr_warn("cptr.bs")
	    next field init
	  when usr_action()=0
	  when (m="u")
	    next field init
	end case

      after input
	case
	  when int_flag
	  when testmodel_frm2ptr(frm2ptr_rec.link_frm, frm2ptr_rec.link_ptr)
	    continue input
	end case

    end input
end function
