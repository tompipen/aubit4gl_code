#	IMLTS.4gl  -  multi-type record scroller
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
globals "imltg.4gl"

#
#  last_ord needed to reopen the cursor in case of
#  MB_declare message
#
define
  last_ord	smallint,
#
#  "need to hilite record", "hilited record" flags
#
  hilite,
  hilited	integer,
#
#  current row & max no. of rows in current record
#
  rn, mr	smallint,
#
#  mlt_deny is used to inhibit certain messages depending
#  on the current record type
#
  mlt_deny	array[4] of record
			        type_rec	char(10),
				msg		smallint
			    end record,
  cnt_deny	smallint,
#
# temp table state - 0 not there, 1 newly created, 2 & 3 there
#
  mlt_tmpstate	smallint,
#
# the following contain the state of the record insertion routines
#
  autoinc,
  maxtxt	smallint,
  type_ins	char(1),
  link_ins	integer

#
#  module initialization
#
function mlt_init()
    whenever error call trap_err
    let cnt_deny=0
    let type_ins=""
    let mlt_tmpstate=0
end function
#
#  form selection
#
function mlt_looks(frm, p)
    define frm	char(14),
	   p	smallint

    call pan_next()
    if (frm is null) or (p is null) or (p<1)
    then
	let frm="txtf"
	let p=18
    end if
    if (pan_current()=1)
    then
	open form mlt_form from frm
    end if
    call pan_set_length(p)
    call mnu_enable(MB_prevrow, MB_end, pan_current(), true)
    call mnu_record(MB_print, MB_print, K_focussedpane)
    let cnt_deny=0
end function
#
#  multi type record scroller
#
function mlt_scroller(im, ip)
    define im, ip,
	   om, op	smallint

    call mlt_upstream(im, ip)
      returning om, op
    while true
	call menu_get(om, op)
	  returning im, ip
	call mlt_downstream(im, ip)
	  returning om, op
	if (om>=MB_exit)
	then
	    return om, op
	end if
    end while
end function
#
#  upstream filter
#
function mlt_upstream(im, ip)
    define im, ip,
	   om, op,
	   i, j		smallint

    call pan_next()
    let om=MB_display
    let op=MP_nodisplay
    case
      when (im=MB_init)
	let om=im
	let op=ip
	let im=MB_declare
	let ip=MP_fulldisplay
      when not pan_focussed()
      when (im=MB_print)
	call stp_mlt()
      when (im=MB_notfound)		#record not found, adj temp table
	call mlt_delete(type_rec, link_rec)
	call end_modal(im, ip) returning im, ip
    end case
    if (im>MB_init) and (im<=MB_maxupstream)
    then
	call end_modal(im, ip) returning im, ip
    end if
    call pan_filter(im, ip) returning im, ip
    case
      when (hilited) and (im=MB_display) and
	   (ip=MP_nodisplay) and pan_focussed()
	call display_mlt(false)
      when (im<MB_display) or (im>MB_declare)
	call pan_status()
      when im is not null
	call restore_mlt(im, ip)
	if (om!=MB_init)
	then
	    let om=im
	    let op=ip
	end if
    end case
    let hilited=false
    for i=1 to cnt_deny
	let j=mlt_deny[i].msg
	call mnu_enable(j, j, pan_current(),
		pos(mlt_deny[i].type_rec, type_rec)=0)
    end for
    return om, op
end function
#
#  downstream filter
#
function mlt_downstream(im, ip)
    define im, ip,
	   om, op	smallint,
	   ol, ln,
	   mln, pl	integer

    call pan_next()
    let om=im
    let op=ip
    let ol=pan_row()
    call scroll_filter(im, ip) returning im, ip
    call pan_filter(im, ip) returning im, ip
    let pl=pan_length()
    let ln=pan_row()
    let mln=pan_max()
    case
      when (im=MB_display) or (im=MB_open) or (im=MB_declare)
	let om=im
	let op=ip
	call restore_mlt(im, ip)
      when (im=MB_exit)
	if (pan_current()=1)
	then
	    close form mlt_form
	end if
	let cnt_deny=0
	call drop_mlt(false)
      when not pan_focussed()
      when (im=MB_scroll)
	while scroll_findtext(length(mlt_retrieve(pan_row()))>0, ip, ol)
	end while
	let ln=pan_row()
#
#  It's my firm convincement that scrolling a line is faster than
#  redisplaying the entire array. If you think it isn't, then just
#  skip to the otherwise code
#
	case ln-ol
	  when 0
	  when 1
	    scroll s_mlt.* up
	    if (ln+pl-1)<=mln
	    then
		call drow_mlt(ln+pl-1)
	    end if
	    call reload_mlt(ln)
	    call pan_status()
	  when -1
	    scroll s_mlt.* down
	    call drow_mlt(ln)
	    call pan_status()
	  otherwise
	    call display_mlt(true)
	end case
	let om=MB_display
	let op=MP_nodisplay
      when (im=MB_changerec)
	if (rn>1)
	then
	    call hilite_mlt()
	    if not usr_ask(txt_retrieve("mr"), false)
	    then
		call display_mlt(false)
		call usr_warn("ma")
		let om=MB_display
		let op=MP_nodisplay
	    else
		let hilited=true
	    end if
	end if
      when (im=MB_deleterec)
	call hilite_mlt()
	if not usr_askremove(2)
	then
	    call display_mlt(false)
	    let om=MB_display
	    let op=MP_nodisplay
	else
	    let hilited=true
	end if
      when (im=MB_prevrec)
	if (ln>1)
	then
	    if (rn=1)
	    then
		let ln=ln-1
		call reload_mlt(ln)
	    end if
	    let ln=ln-rn+1
	    call pan_set_row(ln)
	    call display_mlt(true)
	end if
	let om=MB_display
	let op=MP_nodisplay
      when (im=MB_nextrec)
	let ln=ln+mr-rn+1
	if (ln<=mln)
	then
	    call pan_set_row(ln)
	    call display_mlt(true)
	end if
	let om=MB_display
	let op=MP_nodisplay
    end case
    return om, op
end function
#
#  message disable setup
#
function mlt_op_filter(m, t)
    define m	smallint,
	   t	char(10)

    if cnt_deny=4
    then
	return
    end if
    let cnt_deny=cnt_deny+1
    let mlt_deny[cnt_deny].msg=m
    let mlt_deny[cnt_deny].type_rec=t
end function
#
#  statemant prepare
#
function prepare_mlt()
    define s	char(300)

    let s="select date_rec, type_rec, link_rec, num_ord, maxl, txt ",
	  "from view_mlt ",
	  "order by "
    case last_ord
      when -1
	let s=s clipped, " date_rec desc, link_rec desc"
      when 0
	let s=s clipped, " link_rec"
      when 1
	let s=s clipped, " date_rec, type_rec, link_rec"
      when 2
	let s=s clipped, " date_rec desc, type_rec desc, link_rec"
      when 3
	let s=s clipped, " type_rec, date_rec, link_rec"
      when 4
	let s=s clipped, " type_rec desc, date_rec desc, link_rec"
      when 11
	let s=s clipped, " date_rec, link_rec, type_rec"
      when 12
	let s=s clipped, " date_rec, type_rec, link_rec"	#=1, but needed
      when 13
	let s=s clipped, " link_rec, type_rec, date_rec"
      when 14
	let s=s clipped, " type_rec, link_rec, date_rec"
    end case
    let s=s clipped, ", num_ord"
    prepare mlt_sel from s
    declare mlt_curs scroll cursor with hold for mlt_sel
end function
#
#  search order initialization
#
function mlt_open(new_ord, cpos)
    define new_ord,
	   cpos		smallint

    let last_ord=new_ord
    case
      when (cpos=1)
	call pan_end()
      when (cpos=2) and (mlt_tmpstate=2)
	let mlt_tmpstate=3
      when cpos!=3
	call pan_home()
    end case
end function
#
#  create temporary table (needs correct pane being current)
#
function mlt_create()
    call drop_mlt(true)
    create temp table view_mlt
      (date_rec	date,
       type_rec	char(1),
       link_rec	integer,
       num_ord 	smallint,
       maxl	smallint,
       txt  	char(78)
      ) with no log
    let mlt_tmpstate=1
    call pan_set_max(0)
end function
#
#  temp table removal
#
function drop_mlt(c)
    define c	smallint

    case
#
#  Don't generate RT errors in case there isn't a current DB
#
      when db_islocked() is null
	let mlt_tmpstate=0
      when (mlt_tmpstate>1)
	close mlt_curs
	SQ_freecurs mlt_curs
	free mlt_sel
	drop table view_mlt
	let mlt_tmpstate=0
      when (mlt_tmpstate and c)
	drop table view_mlt
	let mlt_tmpstate=0
    end case
end function
#
#  record removal (needs correct pane being current)
#
function mlt_delete(type_rec, link_rec)
    define type_rec	char(1),
	   link_rec	integer

    delete from view_mlt
      where view_mlt.type_rec=type_rec
	and view_mlt.link_rec=link_rec
    call pan_set_max(pan_max()-SQLCA.SQLERRD[3])
end function
#
#  sets up new record insertion
#
function mlt_newrec(tr, lr, dr, ai, maxl)
    define tr	char(1),
	   lr	integer,
	   dr	date,
	   ai,
	   maxl	smallint,
	   str	char(200)

    if type_ins is not null
    then
	call mlt_recdone()
    end if
    if db_uselogs()
    then
#
#  I know this sound unreasonable (the temp table is not logged)
#  but have to begin work, or you get a fat -255!
#
	begin work
#
#  this is even more reasonable: a not logged temp table consumes locks anyway
#
	lock table view_mlt in exclusive mode
    end if
    let str="insert into view_mlt values (\"", dr, "\",\"", tr,
		"\",", lr, ",?,", maxl, ",?)"
    prepare mlt_insstat from str
    declare mlt_inscurs cursor for mlt_insstat
    open mlt_inscurs
    if (ai!=0 or maxl<=0)
    then
	let maxl=""		#needed to force recalculation no matter what
    end if
    let type_ins=tr
    let link_ins=lr
    let maxtxt=maxl
    let autoinc=ai
end function
#
#  inserts new text line
#
function mlt_newline(txt, num_ord)
    define txt		char(78),
	   num_ord	smallint

    if autoinc>0
    then
	let num_ord=autoinc
	let autoinc=autoinc+1
    end if
    put mlt_inscurs from num_ord, txt
end function
#
#  closes record insertion (needs correct pane being current)
#
function mlt_recdone()
    if db_uselogs()
    then
	commit work
    else
	close mlt_inscurs
    end if
    SQ_freecurs mlt_inscurs
    free mlt_insstat
    if (maxtxt is null)
    then
	if (autoinc!=0)
	then
	    let maxtxt=autoinc-1
        else
	    select max(num_ord) into maxtxt from view_mlt
	      where view_mlt.link_rec=link_ins
		and view_mlt.type_rec=type_ins
	end if
	update view_mlt set maxl=maxtxt
	  where view_mlt.link_rec=link_ins
	    and view_mlt.type_rec=type_ins
    end if
    call pan_set_max(pan_max()+maxtxt)
    let type_ins=""
end function
#
#  returns a row - used for prints
#
function mlt_retrieve(r)
    define r	integer,
	   mrec	record
		    date_rec	date,
		    type_rec 	char(1),
		    link_rec	integer,
		    num_ord  	smallint,
	            maxl	smallint,
	   	    txt		char(78)
		end record

    fetch absolute r mlt_curs into mrec.*
    return mrec.txt
end function
#
#  retrieves a row relative position
#
function reload_mlt(r)
    define r	integer,
	   mrec	record
		    date_rec	date,
		    type_rec 	char(1),
		    link_rec	integer,
		    num_ord  	smallint,
	            maxl	smallint,
	   	    txt		char(78)
		end record

    fetch absolute r mlt_curs into mrec.*
    let rn=mrec.num_ord
    let mr=mrec.maxl
    let type_rec=mrec.type_rec
    let link_rec=mrec.link_rec
end function
#
#  cursor (re)opening & row count retrieval
#
function check_mlt()
    define ln, mln, pl	integer

    let pl=pan_length()
    let ln=pan_row()
    let mln=pan_max()
    open mlt_curs
    case
      when (mln<=0) or (status!=0)
	let mln=0
      when (ln>mln)
	let ln=mln-pl+1
	if (ln<1)
	then
	    let ln=1
	end if
    end case
    call pan_set_row(ln)
    call pan_set_max(mln)
end function
#
#  system messages servicing function
#
function restore_mlt(rl, rd)
    define rl, rd	smallint,
	   i		integer,
	   mrec		record
			    date_rec	date,
			    type_rec 	char(1),
			    link_rec	integer,
			    num_ord  	smallint,
		            maxl	smallint,
		   	    txt		char(78)
			end record

    case
      when (rl=MB_declare)
	if (mlt_tmpstate=1)
        then
	    let mlt_tmpstate=2
	    call pan_home()
	end if
	call prepare_mlt()
	call check_mlt()
	if (mlt_tmpstate=3)
	then
	    let i=1
	    while i<pan_max()
		fetch absolute i mlt_curs into mrec.*
		if (mrec.type_rec=type_rec) and
		   (mrec.link_rec=link_rec)
		then
		    call pan_set_row(i)
		    exit while
		else
		    let i=i+mrec.maxl
		end if
	    end while
	    let mlt_tmpstate=2
	    call browse_test_row()
	end if
      when (rl=MB_open)
	call check_mlt()
    end case
    if (mlt_tmpstate>2)
    then
	let mlt_tmpstate=2
    end if
    case
      when (rd=MP_fulldisplay)
	display form mlt_form
	call usr_area()
	call display_mlt(false)
      when (rd=MP_partdisplay) or (rd=pan_current())
	call display_mlt(true)
      otherwise
	call pan_status()
    end case
end function
#
#  "print" message servicing function
#
function stp_mlt()
    define i	integer,
	   dest	char(80)

    let dest=cod2ptr(viewing())
    if int_flag
    then
	call usr_warn("cptr.si")
	let int_flag=false
    else
	start report mlt_rep to pipe dest
	for i=1 to pan_max()
	    output to report mlt_rep(mlt_retrieve(i))
	end for
	finish report mlt_rep
	call ptr_check()
    end if
end function
#
#  hilites record for modification, removal
#
function hilite_mlt()
    let hilite=true
    call pan_set_row(pan_row()-rn+1)
    call display_mlt(false)
    let hilite=false
end function
#
#  page display
#
function display_mlt(clr)
    define clr		integer,
	   f, l, s, k	integer

    call pan_status()
    let f=pan_row()
    call scroll_last() returning l, s
    for k=f to l
	call drow_mlt(k)
    end for
    if clr
    then
	for k=s to pan_length()
	    clear s_mlt[k].*
#
#  a small word of warning: if you put color/intensity attributes in your form
#  clear will use them. If you need to completely blank the fields, use
#
#	    display " " to s_mlt[k].* attribute(normal)
#
	end for
    end if
end function
#
#  row display
#
function drow_mlt(r)
    define r, l	integer,
	   mrec	record
		    date_rec	date,
		    type_rec  	char(1),
		    link_rec	integer,
		    num_ord  	smallint,
	            maxl	smallint,
		    txt		char(78)
		end record

    let l=r-pan_row()+1
    fetch absolute r mlt_curs into mrec.*
    if (l=1)
    then
	let rn=mrec.num_ord
	let mr=mrec.maxl
	let type_rec=mrec.type_rec
	let link_rec=mrec.link_rec
    end if
    if (mrec.num_ord=1) or (hilite and (mrec.num_ord!=mrec.maxl))
    then
	display mrec.txt to s_mlt[l].* attribute(reverse)
    else
	display mrec.txt to s_mlt[l].*
	let hilite=false
    end if
end function
