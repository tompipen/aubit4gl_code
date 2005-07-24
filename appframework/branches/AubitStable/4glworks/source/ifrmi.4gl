#	IFRMI.4gl - Form maintenance
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

    define frm_rec	record
			    code_frm	smallint,
			    desc_frm	char(40),
			    link_mdl	smallint,
			    form_length,
			    form_width,
			    left_margin	smallint,
			    top_of_form	char(50),
			    form_header,
			    form_footer	char(14)
			end record,
	   control	char(40),
	   desc_mdl	char(40),
	   header_blob,
	   footer_blob	text

#
#  locks record to modify/remove
#
function lock_frm(code_frm)
    define code_frm	smallint,
	   sr		integer

    whenever error call trap_err
    call wrk_begin()
    whenever error continue
    set lock mode to not wait
    declare frm_cl cursor for
      select frm.code_frm from frm
	where frm.code_frm=code_frm
    for update
    open frm_cl
    fetch frm_cl into frm_rec.code_frm
    whenever error call trap_err
    let sr=status
    if (wrk_check())
    then
	free frm_cl
    end if
    return sr
end function
#
#  form viewer
#
function frm_viewer()
    define im, ip,
	   om, op,
	   fd		smallint

    call menu_start()
    call stb_looks("", txt_fetch("ivwr.txt", viewing()), "")
    call set_stb_menu()
    call mnu_enable(MB_detailed, MB_detailed, 1, true)
    call stb_open("frm", "")
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
	    close form frm_form
	end case
	call stb_scroller(om, op) returning im, ip
	let om=MB_display
	let op=fd
	case
	  when (im=MB_display)
	    call display_frm(ip)
	  when (im=MB_detailed)
	    open form frm_form from "frmf"
	    let fd=MP_partdisplay
	    initialize frm_rec.* to null
	    call display_frm(MP_fulldisplay)
	    let op=MP_partdisplay
	  when (im=MB_brief)
	    let fd=MP_fulldisplay
	    let op=MP_fulldisplay
	  when (im=MB_exit)
	    exit while
	  when (im=MB_newrec)
	    initialize frm_rec.* to null
	    let desc_mdl=""
	    let om=MB_recinserted
	    call insert_frm(fd, "i")
	  when (im=MB_copyrec)
	    call load_frm(code_1)
	    let frm_rec.code_frm=""
	    let frm_rec.desc_frm=""
	    let om=MB_recinserted
	    call insert_frm(fd, "c")
	  when (im=MB_changerec)
	    case lock_frm(code_1)
	      when 0
		call load_frm(code_1)
		call update_frm(fd, "u")
		let om=MB_recchanged
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when (im=MB_deleterec)
	    case lock_frm(code_1)
	      when 0
		call delete_frm()
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
	    call select_frm(fd)
	    let om=MB_newset
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    if (fd=MP_partdisplay)
    then
	close form frm_form
    end if
    return ip
end function
#
#  form record display
#
function display_frm(rd)
    define rd	smallint

    if (rd=MP_fulldisplay)
    then
	display form frm_form
	call usr_area()
    end if
    if (rd!=MP_nodisplay)
    then
	call load_frm(code_1)
	display by name frm_rec.*, desc_mdl
    end if
end function
#
#  form record load
#
function load_frm(code_frm)
    define code_frm	smallint,
	   i		smallint

    select frm.code_frm, frm.desc_frm, frm.link_mdl, frm.form_length,
	   frm.form_width, frm.left_margin, frm.top_of_form
      into frm_rec.code_frm, frm_rec.desc_frm, frm_rec.link_mdl,
	   frm_rec.form_length, frm_rec.form_width, frm_rec.left_margin, control
      from frm
      where frm.code_frm=code_frm
    let desc_mdl=""
    select mdl.desc_mdl into desc_mdl from mdl
      where mdl.code_mdl=frm_rec.link_mdl
    let frm_rec.top_of_form=str_encode(control)
    let frm_rec.form_header=""
    let frm_rec.form_footer=""
    if frm_useblobs()
    then
        select true from frm
	  where frm.code_frm=code_frm
	    and frm.form_header is null
	if (status=0)
	then
	    let frm_rec.form_header="="
	end if
        select true from frm
	  where frm.code_frm=code_frm
	    and frm.form_footer is null
	if (status=0)
	then
	    let frm_rec.form_footer="="
	end if
    else
        select frm.form_header, frm.form_footer
	  into frm_rec.form_header, frm_rec.form_footer
	  from frm
	  where frm.code_frm=code_frm
    end if
end function
#
#  working set selection
#
function select_frm(df)
    define df	smallint,
	   cond	char(250)

    if (df=MP_fulldisplay)
    then
	open form frm_form from "frmf"
	display form frm_form
    else
	clear form
    end if
    call usr_input_area("q")
    let int_flag=false
    construct by name cond on code_frm, desc_frm,
			      link_mdl, form_length, form_width, left_margin,
			      form_header, form_footer
      help 2
      on key (control-b, F5)
	case
	  when infield(code_frm)
	    call multi_help("frm", "", 78, "|", "", get_fldbuf(code_frm))
	      returning cond
	    if cond is not null
	    then
		display cond to code_frm
	    end if
	  when infield(link_mdl)
	    call multi_help("mdl", "", 78, "|", "", get_fldbuf(link_mdl))
	      returning cond
	    if cond is not null
	    then
		display cond to link_mdl
	    end if
	end case

      after construct
	if frm_useblobs()
	then
	    call get_fldbuf(form_header, form_footer)
	      returning frm_rec.form_header, frm_rec.form_footer
	    case
	      when (length(frm_rec.form_header)>0) and
		   (frm_rec.form_header!="=") and
		   (frm_rec.form_header!="!=")
		call usr_warn("cptr.F5")
		next field form_header
	      when (length(frm_rec.form_footer)>0) and
		   (frm_rec.form_footer!="=") and
		   (frm_rec.form_footer!="!=")
		call usr_warn("cptr.F5")
		next field form_footer
	    end case
	end if
    end construct
    if not int_flag
    then
	call stb_open("frm", cond)
    end if
end function
#
#  new record insertion
#
function insert_frm(df, m)
    define df	smallint,
	   m	char(1),
	   sr	integer

    call wrk_begin()
    while true
	call input_frm(df, m)
	let df=MP_nodisplay
	case
	  when int_flag
	    exit while
	  when frm_useblobs()
	    if frm_rec.form_header is null or frm_rec.form_header="="
	    then
#
#  have to locate a blob before making it null, and have to make it
#  null, because otherwise it's undefined, which is anything, but 
#  surely not null (i.e. "if blob is null" yelds false!)
#
		locate header_blob in memory
		let header_blob=null
	    else
		locate header_blob in file frm_rec.form_header
	    end if
            if frm_rec.form_footer is null or frm_rec.form_footer="="
	    then
		locate footer_blob in memory
		let footer_blob=null
	    else
		locate header_blob in file frm_rec.form_header
	    end if
	    whenever error continue
	    insert into frm values
		  (frm_rec.code_frm, frm_rec.desc_frm, frm_rec.link_mdl,
		   frm_rec.form_length, frm_rec.form_width, frm_rec.left_margin,
		   control, header_blob, footer_blob)
	    whenever error call trap_err
	    let sr=status
#
#  this is the only way of detaching a named file from blob without
#  deleting the file! Detaching is necessary to avoid the risk of a
#  erroneous deletion in subsequent processing.
#
	    locate header_blob in memory
	    locate footer_blob in memory
	    free header_blob
	    free footer_blob
	  otherwise
	    insert into frm values
		  (frm_rec.code_frm, frm_rec.desc_frm, frm_rec.link_mdl,
		   frm_rec.form_length, frm_rec.form_width, frm_rec.left_margin,
		   control, frm_rec.form_header, frm_rec.form_footer)
	    let sr=status
	end case
	if (sr!=0)
	then
	    call check_writeop()
	else
	    exit while
	end if
    end while
    let sr=wrk_end()
end function
#
#  record update
#
function update_frm(df, m)
    define df	smallint,
	   m	char(1),
	   sr	integer
 
    while true
	call input_frm(df, m)
	let df=MP_nodisplay
	if int_flag
	then
	    exit while
	end if
	update frm
	  set (desc_frm, link_mdl,
	       form_length, form_width,
	       left_margin, top_of_form)=
	      (frm_rec.desc_frm, frm_rec.link_mdl,
	       frm_rec.form_length, frm_rec.form_width,
	       frm_rec.left_margin, control)
	  where current of frm_cl
#
#  plain files -- it is not clear whether form_header or form_footer should
#  behave like blobs, or an empty field should instead mean no header
#  or footer. For now this latter is the choosen behaviour
#
	case
	  when frm_useblobs() and frm_rec.form_header is not null
            if frm_rec.form_header="="
	    then
		locate header_blob in memory
		let header_blob=null
	    else
		locate header_blob in file frm_rec.form_header
	    end if
	    whenever error continue
	    update frm set form_header=header_blob
	      where current of frm_cl
	    whenever error call trap_err
	    let sr=status
	    locate header_blob in memory
	    free header_blob
	  when not frm_useblobs()
	    if frm_rec.form_header="="
	    then
		let frm_rec.form_header=""
	    end if
	    update frm set frm.form_header=frm_rec.form_header
	      where current of frm_cl
	    let sr=status
	end case
	case
	  when sr!=0
	  when frm_useblobs() and frm_rec.form_footer is not null
            if frm_rec.form_footer="="
	    then
		locate footer_blob in memory
		let footer_blob=null
	    else
		locate footer_blob in file frm_rec.form_footer
	    end if
	    whenever error continue
	    update frm set form_footer=footer_blob
	      where current of frm_cl
	    whenever error call trap_err
	    let sr=status
	    locate footer_blob in memory
	    free footer_blob
	  when not frm_useblobs()
	    if frm_rec.form_footer="="
	    then
		let frm_rec.form_footer=""
	    end if
	    update frm set frm.form_footer=frm_rec.form_footer
	      where current of frm_cl
	    let sr=status
	end case
	if (sr!=0)
	then
	    call check_writeop()
	else
	    exit while
	end if
    end while
    if wrk_end()
    then
	close frm_cl
    end if
    free frm_cl
end function
#
#  record deletion
#
function delete_frm()
    case
      when frm2ptr_delete(frm_rec.code_frm, "")
	delete from frm
	  where current of frm_cl
	if wrk_commit()
	then
	    close frm_cl
	end if
      when wrk_rollback()
	close frm_cl
    end case
    free frm_cl
end function
#
#  form record input
#
function input_frm(df, m)
    define df	smallint,
	   m	char(1),
	   dir, i, j 	smallint

    case
      when (df=MP_fulldisplay)
	open form frm_form from "frmf"
	display form frm_form
      when (df=MP_partdisplay)
	clear form
    end case
    if (df!=MP_nodisplay)
    then
	call usr_input_area(m)
	display by name desc_mdl
    end if
    let int_flag=false
    input by name frm_rec.*
      without defaults help 2

      before input
	if (m="u")
	then
	    next field next
	end if

      before field code_frm
        case
	  when (m!="u")
	  when (usr_action()<0)
	    next field previous
	  otherwise
	    next field next
	end case

      after field code_frm
	if code_check("frm", frm_rec.code_frm)
	then
	    next field code_frm
	end if

      after field desc_frm
	if desc_check("frm", frm_rec.desc_frm, frm_rec.code_frm)
	then
	    next field desc_frm
	end if

      after field link_mdl
	select mdl.desc_mdl into desc_mdl from mdl
	  where mdl.code_mdl=frm_rec.link_mdl
	if not_found(frm_rec.link_mdl)
	then
	    let frm_rec.link_mdl=""
	    next field link_mdl
	else
	    display by name desc_mdl
	end if

      on key (control-b, F5)
	case
	  when infield(link_mdl)
	    call uni_help("mdl", "", false, get_fldbuf(link_mdl))
	      returning frm_rec.link_mdl, desc_mdl
	    if frm_rec.link_mdl is not null
	    then
		display by name frm_rec.link_mdl, desc_mdl
	    end if
	  when infield(form_header)
	    let frm_rec.form_header=uni_file("", get_fldbuf(form_header))
	    if frm_rec.form_header is not null
	    then
		display by name frm_rec.form_header
	    end if
	  when infield(frm_rec.form_footer)
	    let frm_rec.form_footer=uni_file("", get_fldbuf(form_footer))
	    if frm_rec.form_footer is not null
	    then
		display by name frm_rec.form_footer
	    end if
	end case

      after input
	if not int_flag
	then
	    call str_decode(frm_rec.top_of_form)
	      returning control, j
	    if (j!=0)
	    then
		call usr_warn("cptr.bs")
		next field top_of_form
	    end if
	end if

    end input
end function
