#	IMDLI.4gl - Printer model maintenance
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

    define mdl_rec	record
			    code_mdl	smallint,
			    desc_mdl	char(40)
			end record,
	   controls	array[20] of char(40),
	   p_mdl	array[20] of record
			    str_name	char(8),
			    desc_str	char(40),
			    str_attr	smallint,
			    string	char(50),
			    d		char(1)
			end record,
	   mdl_count	smallint

#
#  locks record to modify/remove
#
function lock_mdl(code_mdl)
    define code_mdl	smallint,
	   sr		integer

    whenever error call trap_err
    call wrk_begin()
    whenever error continue
    set lock mode to not wait
    declare mdl_cl cursor for
      select * from mdl
	where mdl.code_mdl=code_mdl
    for update
    open mdl_cl
    fetch mdl_cl into mdl_rec.*
    whenever error call trap_err
    let sr=status
    if (wrk_check())
    then
	free mdl_cl
    end if
    return sr
end function
#
#  printer model viewer
#
function mdl_viewer()
    define im, ip,
	   om, op,
	   fd, cr, i	smallint

    call menu_start()
    call stb_looks("", txt_fetch("ivwr.txt", viewing()), "")
    call set_stb_menu()
    call mnu_enable(MB_detailed, MB_detailed, 1, true)
    call stb_open("mdl", "")
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
	    close form mdl_form
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
#
#  changed record so start displaying from the top
#
	    case
	      when mdl_rec.code_mdl=code_1
	      otherwise
		let cr=1
	    end case
	    call display_mdl(ip, cr)
	  when (im=MB_prevrow)
	    if (cr>1)
	    then
		let cr=cr-1
		scroll s_mdl.* down
		display p_mdl[cr].* to s_mdl[1].*
	    end if
	    let op=MP_nodisplay
	  when (im=MB_nextrow)
	    if (cr<mdl_count)
	    then
		let cr=cr+1
		scroll s_mdl.* up
		let i=cr+6
		if (i<=7)
		then
		    display p_mdl[i].* to s_mdl[7].*
		end if
	    end if
	    let op=MP_nodisplay
	  when (im=MB_detailed)
	    open form mdl_form from "mdlf"
	    let fd=MP_partdisplay
	    let cr=1
	    initialize mdl_rec.* to null
	    for i=1 to 20
		initialize p_mdl[i].* to null
	    end for
	    let mdl_count=0
	    call mnu_enable(MB_prevrow, MB_nextrow, 1, true)
	    call display_mdl(MP_fulldisplay, 1)
	    let op=MP_partdisplay
	  when (im=MB_brief)
	    let fd=MP_fulldisplay
	    let op=MP_fulldisplay
	  when (im=MB_exit)
	    exit while
	  when (im=MB_newrec)
	    initialize mdl_rec.* to null
	    for i=1 to 20
		initialize p_mdl[i].* to null
	    end for
	    let mdl_count=0
	    let om=MB_recinserted
	    call insert_mdl(fd, "i")
	  when (im=MB_copyrec)
	    call load_mdl(code_1)
	    let mdl_rec.code_mdl=""
	    let mdl_rec.desc_mdl=""
	    let om=MB_recinserted
	    call insert_mdl(fd, "c")
	  when (im=MB_changerec)
	    case lock_mdl(code_1)
	      when 0
		call load_mdl(code_1)
		call update_mdl(fd, "u")
		let om=MB_recchanged
	      when notfound
		let om=MB_notfound
		let op=MP_partdisplay
	      otherwise
		let om=MB_display
		let op=MP_nodisplay
	    end case
	  when (im=MB_deleterec)
	    case lock_mdl(code_1)
	      when 0
		call delete_mdl()
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
	    call select_mdl(fd)
	    let om=MB_newset
	  otherwise
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    if (fd=MP_partdisplay)
    then
	close form mdl_form
    end if
    return ip
end function
#
#  printer model record display
#
function display_mdl(rd, cr)
    define rd, cr,
	   i, j, l	smallint

    if (rd=MP_fulldisplay)
    then
	display form mdl_form
	call usr_area()
    end if
    if (rd!=MP_nodisplay)
    then
	case
	  when mdl_rec.code_mdl=code_1
	  otherwise
	    call load_mdl(code_1)
	end case
	display by name mdl_rec.*
	let j=minint(cr+6, mdl_count)
	let l=1
	for i=cr to j
	    display p_mdl[i].* to s_mdl[l].*
	    let l=l+1
	end for
	if (rd!=MP_fulldisplay)
	then
	    for i=l to 7
		display "", "", "", "", "" to s_mdl[i].*
		  attribute (normal)
	    end for
	end if
    end if
end function
#
#  printer model record load
#
function load_mdl(code_mdl)
    define code_mdl	smallint,
	   dummy_mdl	smallint,
	   i		smallint

    select mdl.* into mdl_rec.* from mdl
      where mdl.code_mdl=code_mdl
    let mdl_count=1
    declare mdl_curs cursor for
      select mdl_rows.*  from mdl_rows
	where mdl_rows.link_mdl=code_mdl
	order by link_mdl, str_name, str_attr
    foreach mdl_curs into dummy_mdl, p_mdl[mdl_count].str_name,
			  p_mdl[mdl_count].str_attr, controls[mdl_count]
	let p_mdl[mdl_count].desc_str=txt_fetch("imdl.lst",
						p_mdl[mdl_count].str_name)
	let p_mdl[mdl_count].string=str_encode(controls[mdl_count])
	let mdl_count=mdl_count+1
	if (mdl_count>20)
	then
	    exit foreach
	end if
    end foreach
    free mdl_curs
    let mdl_count=mdl_count-1
end function
#
#  working set selection
#
function select_mdl(df)
    define df	smallint,
	   cond	char(250)

    if (df=MP_fulldisplay)
    then
	open form mdl_form from "mdlf"
	display form mdl_form
    else
	clear form
    end if
    call usr_input_area("q")
    let int_flag=false
    construct by name cond on code_mdl, desc_mdl
      help 2
      on key (control-b, F5)
	if infield(code_mdl)
	then
	    call multi_help("mdl", "", 78, "|", "", get_fldbuf(code_mdl))
	      returning cond
	    if cond is not null
	    then
		display cond to code_mdl
	    end if
	end if
    end construct
    if not int_flag
    then
	call stb_open("mdl", cond)
    end if
end function
#
#  new record insertion
#
function insert_mdl(df, m)
    define df	smallint,
	   m	char(1),
	   i	smallint

    call wrk_begin()
    while true
	call input_mdl(df, m)
	let df=MP_nodisplay
	if int_flag
	then
	    exit while
	end if
	whenever error continue
	insert into mdl values (mdl_rec.*)
	whenever error call trap_err
	if (sqlca.sqlcode=0)
	then
	    call insert_mdl_rows()
	    exit while
	end if
	call check_writeop()
    end while
    let i=wrk_end()
end function
#
#  record update
#
function update_mdl(df, m)
    define df	smallint,
	   m	char(1),
	   i	smallint

    call input_mdl(df, m)
    let df=MP_nodisplay
    if not int_flag
    then
	update mdl set desc_mdl=mdl_rec.desc_mdl
	  where current of mdl_cl
	delete from mdl_rows
	  where mdl_rows.link_mdl=mdl_rec.code_mdl
	call insert_mdl_rows()
    end if
    if wrk_end()
    then
	close mdl_cl
    end if
    free mdl_cl
end function
#
#  record deletion
#
function delete_mdl()
    delete from mdl_rows
      where mdl_rows.link_mdl=mdl_rec.code_mdl
    delete from mdl
      where current of mdl_cl
    if wrk_commit()
    then
	call tbl_unlock("mdl_rows")
	close mdl_cl
    end if
    free mdl_cl
end function
#
#  insert model capabilities
#
function insert_mdl_rows()
    define i smallint

    for i=1 to mdl_count
	insert into mdl_rows
	  values (mdl_rec.code_mdl, p_mdl[i].str_name,
		  p_mdl[i].str_attr, controls[i])
    end for
end function
#
#  printer model record input
#
function input_mdl(df, m)
    define df		smallint,
	   m, dummy	char(1),
	   dir, nrw	smallint,
	   needed_cap	char(20),
	   i, j, k 	smallint

    case
      when (df=MP_fulldisplay)
	open form mdl_form from "mdlf"
	display form mdl_form
      when (df=MP_partdisplay)
	clear form
    end case
    call usr_input_area(m)
    let j=minint(mdl_count, 7)
    for i=1 to j
	display p_mdl[i].* to s_mdl[i].*
    end for
    let nrw=""
    let int_flag=false
    input by name mdl_rec.code_mdl, mdl_rec.desc_mdl, dummy
      without defaults help 2

      before input
	if (m="u")
	then
	    next field desc_mdl
	end if

      before field code_mdl
        case
	  when (m!="u")
	  when (usr_action()>0)
	    next field desc_mdl
	  otherwise
	    next field dummy
	end case

      after field code_mdl
	if code_check("mdl", mdl_rec.code_mdl)
	then
	    next field code_mdl
	end if

      after field desc_mdl
	if desc_check("mdl", mdl_rec.desc_mdl, mdl_rec.code_mdl)
	then
	    next field desc_mdl
	end if

      before field dummy
	case
	  when nrw is not null
	    let dir=inputcontrols_mdl(nrw)
	  when (usr_action()<0)
	    let dir=inputcontrols_mdl(mdl_count)
	  otherwise
	    let dir=inputcontrols_mdl(1)
	end case
	let nrw=""
        case
	  when (dir>0)
	    next field next
	  when (dir<0)
	    next field previous
	  otherwise
	    goto exit_input
	end case

      after input
label exit_input:
	case
	  when int_flag
	    exit input
	  when (mdl_count=0)
	    call usr_warn(-1305)
	    let nrw=1
	    next field dummy
	end case
	let needed_cap="- pitch line"
	for i=1 to mdl_count
	    call str_decode(p_mdl[i].string)
	      returning controls[i], j
	    if (j>0)
	    then
		let nrw=i
		call usr_warn(-1304)
		next field dummy
	    end if
	    let j=pos(needed_cap, p_mdl[i].str_name)
	    if (j>0)
	    then
		let k=j+length(p_mdl[i].str_name)
		let j=j-1
		let needed_cap=needed_cap[1, j], needed_cap[k, 20]
	    end if
	end for
	if (length(needed_cap)>1)
	then
	    call join_warning(-1305, needed_cap)
	    let nrw=1
	    next field dummy
	end if

    end input
end function
#
#  printer model strings input
#
function inputcontrols_mdl(nrw)
    define nrw, p, s,
	   k, cr, d	smallint

    call set_count(mdl_count)
    let cr=true
    input array p_mdl without defaults from s_mdl.* help 3

      before row
	let p=arr_curr()
	if (p<nrw)
	then
	    next field d
	else
	    let nrw=""
	end if
	if infield(str_attr) and p_mdl[p].str_attr is null
	then
	    next field str_name
	end if

      before insert
	let cr=false

      after field str_name
	case
	  when (length(p_mdl[p].str_name)>0)
	  when cr
	    call usr_warn(-1305)
	    next field str_name
	  otherwise
	    continue input
	end case
	let p_mdl[p].desc_str=txt_fetch("imdl.lst", p_mdl[p].str_name)
	let k=length(p_mdl[p].str_name)
	if (p_mdl[p].desc_str[1,k]=p_mdl[p].str_name)
	then
	    call usr_warn("co")
	    clear s_mdl[p].str_name
	    next field str_name
	end if
	case
	  when p_mdl[p].str_attr is not null and
	       name2attr_mdl(p_mdl[p].str_name) is null
	    let p_mdl[p].str_attr=""
	    display p_mdl[p].str_attr to s_mdl[p].str_attr
	end case
	display p_mdl[p].desc_str to s_mdl[p].desc_str
	for k=1 to arr_count()
	    case
	      when (p_mdl[k].str_name!=p_mdl[p].str_name)
	      when (p_mdl[k].str_attr!=p_mdl[p].str_attr)
	      when (p_mdl[k].str_attr is not null) and
		   (p_mdl[p].str_attr is null)
	      when (p!=k)
		call usr_warn("du")
		next field str_name
	    end case
	end for
	if name2attr_mdl(p_mdl[p].str_name) is not null and
	   p_mdl[p].str_attr is null
	then
	    next field str_attr
	end if

      before field str_attr
	if name2attr_mdl(p_mdl[p].str_name) is null
	then
	    next field next
	end if

      after field str_attr
	case
	  when nul(p_mdl[p].str_attr)
	    next field str_attr
	  when name2attr_mdl(p_mdl[p].str_name)
	  when (p_mdl[p].str_attr<0) or
	       (p_mdl[p].str_attr>1)
	    call usr_warn(-1301)
	    next field str_attr
	end case
	for k=1 to arr_count()
	    case
	      when (p_mdl[k].str_name!=p_mdl[p].str_name)
	      when (p_mdl[k].str_attr!=p_mdl[p].str_attr)
	      when (p!=k)
		call usr_warn("du")
		next field str_name
	    end case
	end for

      before field string
	if cr
	then
	    let k=length(p_mdl[p].string)
	else
	    let k=""
	end if

      after field string
	case
	  when length(p_mdl[p].string)>0
	  when k=0
	  when not usr_confirm("EF")
	    next field string
	end case

      after row
	let d=usr_direction(7, 20, p_mdl[p].str_name is null)
	if (nrw is null) and (d!=0)
	then
	    exit input
	end if
	let cr=true

      on key(control-b, F5)
	if infield(str_name)
	then
	    call uni_help("file", "imdl.lst", false, get_fldbuf(str_name))
	      returning p_mdl[p].str_name, p_mdl[p].desc_str
	    if (p_mdl[p].str_name is not null)
	    then
		display p_mdl[p].str_name, p_mdl[p].desc_str
		  to s_mdl[p].str_name, s_mdl[p].desc_str
	    else
		let p_mdl[p].str_name=get_fldbuf(str_name)
	    end if
	end if

    end input
    let mdl_count=arr_count()
    return d
end function
#
#  returns attribute type needed for capability
#
function name2attr_mdl(str_name)
    define str_name	char(8)

    case str_name
      when "pitch"
	return true
      when "line"
	return true
      when "init"
	return ""
      when "deinit"
	return ""
      when "formfeed"
	return ""
    end case
    return false
end function
