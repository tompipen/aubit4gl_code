#	IPTRI.4gl - Printer data maintenance
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

#include "idefl.4gh"
globals "istbg.4gl"

    define ptr_rec	record
			    code_ptr	smallint,
			    desc_ptr	char(40),
			    link_mdl	smallint,
			    dest,
			    reject,
			    disabled,
			    enable	char(78)
			end record,
	   desc_mdl	char(40)

#
#  locks record to modify/remove
#
function lock_ptr(code_ptr)
    define code_ptr	smallint,
	   sr		integer

    whenever error call trap_err
    call wrk_begin()
    whenever error continue
    set lock mode to not wait
    declare ptr_cl cursor for
      select * from ptr
	where ptr.code_ptr=code_ptr
    for update
    open ptr_cl
    fetch ptr_cl into ptr_rec.*
    whenever error call trap_err
    let sr=status
    if (wrk_check())
    then
	free ptr_cl
    end if
    return sr
end function
#
#  printer viewer
#
function ptr_viewer()
    define im, ip,
	   om, op,
	   fd, cr, i	smallint

    call menu_start()
    call stb_looks("", txt_fetch("ivwr.txt", viewing()), "")
    call set_stb_menu()
    call mnu_enable(MB_detailed, MB_detailed, 1, true)
    call stb_open("ptr", "")
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
	    close form ptr_form
	end case
#
#  changed record so start displaying from the top
#
	case
	  when (fd=MP_fulldisplay)
	  when (op=MP_partdisplay)
	    let cr=1
	end case
	call stb_scroller(om, op) returning im, ip
	let om=MB_display
	let op=fd
	case
	  when (im=MB_display)
	    call display_ptr(ip)
	  when (im=MB_detailed)
	    open form ptr_form from "ptrf"
	    let fd=MP_partdisplay
	    initialize ptr_rec.* to null
	    call display_ptr(MP_fulldisplay)
	    let op=MP_partdisplay
	  when (im=MB_brief)
	    let fd=MP_fulldisplay
	    let op=MP_fulldisplay
	  when (im=MB_exit)
	    exit while
	  when (im=MB_newrec)
	    initialize ptr_rec.* to null
	    let desc_mdl=""
	    let om=MB_recinserted
	    call insert_ptr(fd, "i")
	  when (im=MB_copyrec)
	    call load_ptr(code_1)
	    let ptr_rec.code_ptr=""
	    let ptr_rec.desc_ptr=""
	    let om=MB_recinserted
	    call insert_ptr(fd, "c")
	  when (im=MB_changerec)
	    case lock_ptr(code_1)
	      when 0
		call load_ptr(code_1)
		call update_ptr(fd, "u")
		let om=MB_recchanged
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when (im=MB_deleterec)
	    case lock_ptr(code_1)
	      when 0
		call delete_ptr()
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
	  when (im=MB_chooseset)
	    call select_ptr(fd)
	    let om=MB_newset
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    if (fd=MP_partdisplay)
    then
	close form ptr_form
    end if
    return ip
end function
#
#  printer record display
#
function display_ptr(rd)
    define rd	smallint

    if (rd=MP_fulldisplay)
    then
	display form ptr_form
	call usr_area()
    end if
    if (rd!=MP_nodisplay)
    then
	call load_ptr(code_1)
	display by name ptr_rec.*, desc_mdl
    end if
end function
#
#  printer record load
#
function load_ptr(code_ptr)
    define code_ptr	smallint,
	   i		smallint

    let desc_mdl=""
    select ptr.code_ptr, ptr.desc_ptr, ptr.link_mdl, ptr.dest,
	   ptr.reject, ptr.disabled, ptr.enable
      into ptr_rec.code_ptr, ptr_rec.desc_ptr, ptr_rec.link_mdl, ptr_rec.dest,
	   ptr_rec.reject, ptr_rec.disabled, ptr_rec.enable
      from ptr
      where ptr.code_ptr=code_ptr
    select mdl.desc_mdl into desc_mdl from mdl
      where mdl.code_mdl=ptr_rec.link_mdl
end function
#
#  working set selection
#
function select_ptr(df)
    define df	smallint,
	   cond	char(250)

    if (df=MP_fulldisplay)
    then
	open form ptr_form from "ptrf"
	display form ptr_form
    else
	clear form
    end if
    call usr_input_area("q")
    let int_flag=false
    construct by name cond on code_ptr, desc_ptr, link_mdl,
			      dest, reject, disabled, enable
      help 2
      on key (control-b, F5)
	case
	  when infield(code_ptr)
	    call multi_help("ptr", "", 78, "|", "", get_fldbuf(code_ptr))
	      returning cond
	    if cond is not null
	    then
		display cond to code_ptr
	    end if
	  when infield(link_mdl)
	    call multi_help("mdl", "", 78, "|", "", get_fldbuf(link_mdl))
	      returning cond
	    if cond is not null
	    then
		display cond to link_mdl
	    end if
	end case
    end construct
    if not int_flag
    then
	call stb_open("ptr", cond)
    end if
end function
#
#  new record insertion
#
function insert_ptr(df, m)
    define df	smallint,
	   m	char(1),
	   sr	integer

    while true
	call input_ptr(df, m)
	let df=MP_nodisplay
	if int_flag
	then
	    exit while
	else
	    whenever error continue
	    insert into ptr values (ptr_rec.*)
	    whenever error call trap_err
	    if (status=0)
	    then
		exit while
	    else
		call check_writeop()
	    end if
	end if
    end while
end function
#
#  record update
#
function update_ptr(df, m)
    define df		smallint,
	   m		char(1),
	   loc_mdl	smallint
 
    call input_ptr(df, m)
    case
      when not int_flag
	update ptr
	  set (desc_ptr, link_mdl,
	       dest, reject, disabled, enable)=
	      (ptr_rec.desc_ptr, ptr_rec.link_mdl,
 	       ptr_rec.dest, ptr_rec.reject, ptr_rec.disabled, ptr_rec.enable)
	  where current of ptr_cl
	if wrk_commit()
	then
	    close ptr_cl
	end if
      when wrk_rollback()
	close ptr_cl
    end case
    free ptr_cl
end function
#
#  record deletion
#
function delete_ptr()
    case
      when frm2ptr_delete("", ptr_rec.code_ptr)
	delete from ptr
	  where current of ptr_cl
	if wrk_commit()
	then
	    close ptr_cl
	end if
      when wrk_rollback()
	close ptr_cl
    end case
    free ptr_cl
end function
#
#  delete frm2ptr mtm entries
#
function frm2ptr_delete(link_frm, link_ptr)
    define link_frm,
	   link_ptr	smallint

    if tbl_lock("frm2ptr")
    then
	delete from frm2ptr
	  where frm2ptr.link_frm=link_frm
	     or frm2ptr.link_ptr=link_ptr
	if not db_uselogs()
	then
	    call tbl_unlock("frm2ptr")
	end if
	return true
    end if
    return false
end function
#
#  printer record input
#
function input_ptr(df, m)
    define df		smallint,
	   m 		char(1)

    case
      when (df=MP_fulldisplay)
	open form ptr_form from "ptrf"
	display form ptr_form
      when (df=MP_partdisplay)
	clear form
    end case
    if (df!=MP_nodisplay)
    then
	call usr_input_area(m)
	display by name desc_mdl
    end if
    let int_flag=false
    input by name ptr_rec.*
      without defaults help 2

      before input
	if (m="u")
	then
	    next field next
	end if

      before field code_ptr
        case
	  when (m!="u")
	  when (usr_action()>0)
	    next field next
	  otherwise
	    next field previous
	end case

      after field code_ptr
	if code_check("ptr", ptr_rec.code_ptr)
	then
	    next field code_ptr
	end if

      after field desc_ptr
	if desc_check("ptr", ptr_rec.desc_ptr, ptr_rec.code_ptr)
	then
	    next field desc_ptr
	end if

      after field link_mdl
	select mdl.desc_mdl into desc_mdl from mdl
	  where mdl.code_mdl=ptr_rec.link_mdl
	if not_found(ptr_rec.link_mdl)
	then
	    let ptr_rec.link_mdl=""
	    next field link_mdl
	else
	    display by name desc_mdl
	end if

      on key (control-b, F5)
	if infield(link_mdl)
	then
	    call uni_help("mdl", "", false, get_fldbuf(link_mdl))
	      returning ptr_rec.link_mdl, desc_mdl
	    if ptr_rec.link_mdl is not null
	    then
		display by name ptr_rec.link_mdl, desc_mdl
	    end if
	end if

    end input
end function
