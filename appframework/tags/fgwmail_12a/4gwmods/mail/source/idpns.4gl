#	IDPNS.4gl - a dual pane text scroller
#
#	4gwMail, a news and mail client 4glWorks module
#	Copyright (C) 1997-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 97
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
#include "itiml.4gh"
globals "idpng.4gl"

define
#
# reflects the state of the temp table: 0 - none
#					1 - created & not indexed
#					-1 - created & indexed
  dpn_tmpstate	smallint,
#
#  first pane resyncronization flag
#
  fpn_syncdir	integer,
#
# holds the id of the slave pane
#
  spn_id	smallint,
#
# first pane sort keys index
#
  key_1, key_2	char(7),
  desc1, desc2	smallint,
#
# second pane search condition
#
  level		smallint,
#
# pane header & comments
#
  hea		array[2] of char(78),
  cmt		array[2] of char(78),
#
# form header attribute - depends on whether we use termcap or terminfo
#
  usebold	smallint,
#
# the state of second pane delayed display
#
  pending_disp	integer,
#
# the state of the text insertion routines
#
  link_ins	integer,
  autoinc	smallint

#
#
#  module initialization
#
function dpn_init()
    whenever error call trap_err
    let dpn_tmpstate=0
    let spn_id=""
    let pending_disp=""
    let usebold=(upshift(fgl_getenv("INFORMIXTERM"))="TERMCAP" or
		 length(fgl_getenv("INFORMIXTERM"))=0)
    let link_ins=""
    let hea[1]=""
    let hea[2]=""
    let cmt[1]=""
    let cmt[2]=""
end function
#
#  form selection
#
function dpn_looks(frm, f, s)
    define frm	char(14),
	   f, s	smallint

    if (frm is null) or (f is null) or (f<1)
    then
	let frm="dpnf"
	let f=5
	let s=9
    end if
    call pan_next()
    if (pan_current()=1)
    then
	open form dpn_form from frm
    end if
    call pan_set_length(f)
    call browse_start(MB_brief)
    call pan_next()
    let spn_id=pan_current()
    call mnu_enable(MB_prevrow, MB_end, pan_current(), true)
    call mnu_enable(MB_prevrec, MB_nextrec, pan_current(), false)
    call pan_set_length(s)
end function
#
#  set pane header
#
function dpn_header(h, p)
    define h	char(78),
	   p	smallint

    if (p=1) or (p=2)
    then
	let hea[p]=h
    end if
end function
#
#  set pane comment
#
function dpn_comment(c, p, l)
    define c	char(78),
	   p, l	smallint

    if (p=1) or (p=2)
    then
	if (l>0) and (l<=78)
	then
	    let l=l-length(c)
	    if (l>0)
	    then
		let c=l spaces, c clipped
	    end if
	end if
	let cmt[p]=c
    end if
end function
#
#  dual pane text scroller
#
function dpn_scroller(im, ip)
    define im, ip	smallint

    while true
	call pan_enter()
#
# no, it's not wrong - same code for both panes
#
	call dpn_upstream(im, ip) returning im, ip
	call dpn_upstream(im, ip) returning im, ip
	call menu_get(im, ip) returning im, ip
	call fpn_downstream(im, ip) returning im, ip
	call spn_downstream(im, ip) returning im, ip
	if (im>=MB_exit)
	then
	    return im, ip
	end if
	let im=""
	let ip=""
    end while
end function
#
#  upstream filter
#
function dpn_upstream(im, ip)
    define im, ip,
	   om, op	smallint

    call pan_next()
    let om=MB_display
    let op=MP_nodisplay
    case
      when (im=MB_init)
	let om=im
	let op=ip
	let im=MB_declare
	let ip=MP_fulldisplay
      when (im>MB_init) and (im<=MB_maxupstream)
	call end_modal(im, ip) returning im, ip
    end case
    call pan_filter(im, ip) returning im, ip
    case
      when (im<MB_display) or (im>MB_declare)
	call pan_status()
      when (im is not null)
	call restore_dpn(im, ip)
	if (om!=MB_init)
	then
	    let om=im
	    let op=ip
	end if
    end case
    return om, op
end function
#
#  master pane: downstream filter
#
function fpn_downstream(im, ip)
    define im, ip, k, r	smallint

    call pan_next()
    let k=pan_row()
    let r=(im>=MB_prevrow and im<=MB_end)
    call browse_filter(im, ip) returning im, ip
    call pan_filter(im, ip) returning im, ip
    case
      when (im=MB_move)
	case ip
	  when MP_scrollup
	    scroll s_fpn.* up
	  when MP_scrolldown
	    scroll s_fpn.* down
	end case
	call drow_fpn(k)
	call drow_fpn(pan_row())
      when (im=MB_exit)
	call clean_dpn()
      when (im=MB_display) or (im=MB_open) or (im=MB_declare)
	call restore_dpn(im, ip)
    end case
    if (r and k!=pan_row())
    then
#
#  if cursor movement, force slave pane redisplay
#  forcing pane cursor to go home
#
	let r=pan_set_current(spn_id)
	call pan_home()
	let r=pan_set_current(spn_id-1)
	if (pending_disp)
	then
	    call tim_drop(pending_disp)
	end if
	let pending_disp=tim_set(1, 1, false, A_mandatory, MB_open, spn_id)
	return "", ""
    else
	return im, ip
    end if
end function
#
#  slave pane: downstream filter
#
function spn_downstream(im, ip)
    define im, ip,
	   ol, ln,
	   pl, mln	smallint

    call pan_next()
    let ol=pan_row()
    call scroll_filter(im, ip) returning im, ip
    call pan_filter(im, ip) returning im, ip
    let ln=pan_row()
    let mln=pan_max()
    let pl=pan_length()
    case
      when (im=MB_display) or (im=MB_open) or (im=MB_declare)
	call restore_dpn(im, ip)
      when (im=MB_exit)
	call clean_dpn()
      when (im=MB_scroll) and pan_focussed()
	while scroll_findtext(length(retrieve_spn(pan_row()))>0, ip, ol)
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
	    scroll s_spn.* up
	    if (ln+pl-1<=mln)
	    then
		call drow_spn(ln+pl-1)
	    end if
	    call pan_status()
	  when -1
	    scroll s_spn.* down
	    call drow_spn(ln)
	    call pan_status()
	  otherwise
	    call display_dpn(true)
	end case
	let im=""
	let ip=""
#
# if there's a message going to the viewer, and still a pending display
# redisplay, just in case
#
      when (pending_disp) and (im is not null)
	call check_dpn()
	call display_dpn(false)
    end case
    return im, ip
end function
#
#  true if bold usable
#
function dpn_usebold()
    return usebold
end function
#
#  clean up dpn scroller status upon exit
#
function clean_dpn()
    if (pan_current()=1)
    then
	close form dpn_form
    end if
#
#  don't generate RT errors in case there's no current DB
#
    if db_islocked() is not null
    then
	call dpn_drop()
    end if
    let hea[1]=""
    let hea[2]=""
    let cmt[1]=""
    let cmt[2]=""
end function
#
#  scroller cursor declaration
#
function prepare_dpn()
   define str	char(200),
	  o	char(30)

    if (pan_current()!=spn_id)
    then
	let o=""
	if (key_1 is not null)
	then
	    let str="select hidden[", key_1, "],"
	    if (desc1)
	    then
	        let o="1 desc"
	    else
	        let o="1"
	    end if
	else
	    let str="select \"\","
	end if
	if (key_2 is not null)
	then
	    if (key_1 is not null)
	    then
		let o=o clipped, ","
	    end if
	    let str=str clipped, " hidden[", key_2, "],"
	    if (desc2)
	    then
	        let o=o clipped, " 2 desc"
	    else
	        let o=o clipped, " 2"
	    end if
	else
	    let str=str clipped, " \"\","
	end if
	let str=str clipped, " link_dpn, txt",
	    " from view_fpn",
	    " order by ", o clipped
	prepare fpn_sel from str
	declare fpn_curs scroll cursor with hold for fpn_sel
    else
	if (dpn_tmpstate>0)
	then
	    create index spn_idx on view_spn (link_dpn, ln)
	    let dpn_tmpstate=-1
	end if
	declare spn_curs scroll cursor with hold for
	  select view_spn.ln, view_spn.txt from view_spn
	    where view_spn.link_dpn=link_dpn
	    and view_spn.level>=level
	    order by 1
    end if
end function
#
#  temp table creation
#
function dpn_create()
    if dpn_tmpstate!=0
    then
	call dpn_drop()
    end if
    create temp table view_fpn
	(
	link_dpn	integer,
	hidden		char(132),		
	txt		char(78)
	) with no log
    create temp table view_spn
	(
	link_dpn	integer,
	level		smallint,
	ln		smallint,		
	txt		char(78)
	) with no log
    let dpn_tmpstate=1
end function
#
#  temp table drop
#
function dpn_drop()
    if dpn_tmpstate!=0
    then
	close fpn_curs
	SQ_freecurs fpn_curs
	free fpn_sel
	close spn_curs
	SQ_freecurs spn_curs
	drop table view_fpn
	drop table view_spn
	let dpn_tmpstate=0
    end if
end function
#
#  record deletion
#
function dpn_delete(link_dpn)
    define link_dpn	integer

    delete from view_fpn
      where view_fpn.link_dpn=link_dpn
    delete from view_spn
      where view_spn.link_dpn=link_dpn
end function
#
#  gets ready for new text insertion
#
function dpn_newrec(l_r, ai)
    define l_r	integer,
	   ai	smallint,
	   str	char(100)

    if (link_ins is null)
    then
	if db_uselogs()
	then
#
#  I know this sound unreasonable (the temp table is not logged)
#  but have to begin work, or you get a fat -255!
#
	    begin work
#
#  this is even more unreasonable - a not logged temp table uses locks anyway,
#
	    lock table view_spn in exclusive mode
	end if
	prepare spn_insstat from "insert into view_spn values(?,?,?,?)"
	declare spn_inscurs cursor for spn_insstat
    end if
    open spn_inscurs
    let link_ins=l_r
    let autoinc=ai
end function
#
#  inserts new text line
#
function spn_newline(txt, l, n)
    define txt	char(78),
	   l, n	smallint

    if (autoinc>0)
    then
	let n=autoinc
	let autoinc=autoinc+1
    end if
    put spn_inscurs from link_ins, l, n, txt
end function
#
#  closes record insertion
#
function fpn_newrec(t, h)
    define t	char(78),
	   h	char(132)

    insert into view_fpn values(link_ins, h, t)
end function
#
#  closes record insertion
#
function dpn_recdone()
    if db_uselogs()
    then
	commit work
    else
	close spn_inscurs
    end if
    SQ_freecurs spn_inscurs
    free spn_insstat
    let link_ins=""
end function
#
#  printout cursor declaration, first pane
#
function fpn_start(k1, k2, d1, d2)
   define k1,
	  k2	char(7),
	  d1,
	  d2	smallint,
	  str	char(200),
	  o	char(30)

    if k1 is not null
    then
	let str="select hidden[", k1, "],"
	if (d1)
	then
	    let o="1 desc"
	else
	    let o="1"
	end if
    else
	let str="select \"\","
    end if
    if k2 is not null
    then
	let str=str clipped, " hidden[", k2, "],"
	if (d1)
	then
	    let o=o clipped, ","
	end if
	if (d2)
	then
	    let o=o clipped, " 2 desc"
	else
	    let o=o clipped, " 2"
	end if
    else
	let str=str clipped, " \"\","
    end if
    let str=str clipped, " view_fpn.link_dpn",
	    " from view_fpn",
	    " order by ", o clipped
    prepare fpn_rep_stat from str
    declare fpn_rep_curs cursor for fpn_rep_stat
    open fpn_rep_curs
end function
#
#  printout cursor declaration, second pane
#
function spn_start(lr, lv)
   define lr	integer,
	  lv	smallint

    declare spn_rep_curs scroll cursor for
      select view_spn.ln, view_spn.txt from view_spn
	where view_spn.link_dpn=lr
	  and view_spn.level>=lv
	order by 1
    open spn_rep_curs
end function
#
#  printout row fetch, first pane
#
function fpn_retrieve()
    define k1,
	   k2	char(78),
	   lr	integer

    whenever error continue
    fetch fpn_rep_curs into k1, k2, lr
    whenever error call trap_err
    return lr
end function
#
#  printout row fetch, second pane
#
function spn_retrieve()
    define txt	char(78),
	   n	smallint

    whenever error continue
    fetch spn_rep_curs into n, txt
    whenever error call trap_err
    return txt
end function
#
#  close printout cursor, first pane
#
function fpn_end()
    close fpn_rep_curs
    SQ_freecurs fpn_rep_curs
    free fpn_rep_stat
end function
#
#  close printout cursor, second pane
#
function spn_end()
    close spn_rep_curs
    SQ_freecurs spn_rep_curs
end function
#
#  set search order 
#
function fpn_open(k1, k2, d1, d2)
   define k1,
	  k2	char(7),
	  d1,
	  d2	smallint

    call pan_next()
    let key_1=k1
    let key_2=k2
    let desc1=d1
    let desc2=d2
    call pan_home()
end function
#
#  flags first pane scroller to reposition onto current record
#
function fpn_sync(d)
    define d integer

    case
      when (not dpn_tmpstate)
      when (d>0)
	let fpn_syncdir=1
      when (d<0)
	let fpn_syncdir=-1
      otherwise
	let fpn_syncdir=0
    end case
end function
#
#  set display level
#
function spn_open(l)
    define l	smallint

    call pan_next()
    let level=l
    call pan_home()
end function
#
#  open cursor and check # of rows
#
function check_dpn()
    define s, m		smallint,
	   k1,
	   k2,
	   txt		char(78),
	   n		smallint,
	   l_r		integer

    if (pan_current()!=spn_id)
    then
	open fpn_curs
	let s=browse_search("")
	while (s!=0)
	    let m=pan_max()
	    fetch absolute m fpn_curs into k1, k2, l_r, txt
	    let s=browse_search(s)
	end while
    else
	if (dpn_tmpstate>0)
	then
	    create index spn_idx on view_spn (link_dpn, ln)
	    let dpn_tmpstate=-1
	end if
	open spn_curs
	let s=browse_search("")
	while (s!=0)
	    let m=pan_max()
	    fetch absolute m spn_curs into n, txt
	    let s=browse_search(s)
	end while
    end if
    call usr_status("")
end function
#
#  "display" messages servicing function
#
function restore_dpn(rl, rd)
    define rl, rd	smallint,
	   fpn_rec	record
			    k1, k2	char(78),
			    link_dpn	integer,
			    txt		char(78)
		        end record,
	   i		smallint

    case
      when rl=MB_declare
	call usr_status("wa")
	call prepare_dpn()
	call check_dpn()
	if (fpn_syncdir and pan_current()!=spn_id)
	then
	    let i=pan_row()
	    while (i>1 and 1<pan_max())
		fetch absolute i fpn_curs into fpn_rec.*
		if (fpn_rec.link_dpn=link_dpn)
		then
		    call pan_set_row(i)
		    exit while
		else
		    let i=i+fpn_syncdir
		end if
	    end while
	    let fpn_syncdir=0
	    call browse_test_row()
        end if
      when rl=MB_open
	call usr_status("wa")
	call check_dpn()
    end case
    case
      when (rd=MP_fulldisplay)
	display form dpn_form
	call usr_area()
	call display_dpn(false)
      when (rd=MP_partdisplay) or (rd=pan_current())
	call display_dpn(true)
      otherwise
	call pan_status()
    end case
end function
#
#  page display
#
function display_dpn(clr)
    define clr		integer,
	   f, l, s, k	integer

    call pan_status()
    if (pan_current()!=spn_id)
    then
	call browse_range() returning f, l, s
	for k=f to l
	    call drow_fpn(k)
	end for
	call sayheaders_dpn(1)
    else
	let f=pan_row()
	call scroll_last() returning l, s
	for k=f to l
	    call drow_spn(k)
	end for
	call sayheaders_dpn(2)
	if (pending_disp is not null)
	then
	    call tim_drop(pending_disp)
	    let pending_disp=""
	end if
    end if
    case
      when not clr
      when (pan_current()!=spn_id)
	for k=s to pan_length()
	    clear s_fpn[k].*
#
#  a small word of warning: if you put color/intensity attributes in your form
#  clear will use them. If you need to completely blank the fields, use
#
#	    display " " to s_fpn[k].* attribute(normal)
#
	end for
     otherwise
	for k=s to pan_length()
	    clear s_spn[k].*
#
#  a small word of warning: if you put color/intensity attributes in your form
#  clear will use them. If you need to completely blank the fields, use
#
#	    display " " to s_spn[k].* attribute(normal)
#
	end for
    end case
end function
#
#	display
#
function sayheaders_dpn(p)
    define p	smallint

    case
      when cmt[p] is null
      when usebold
	display cmt[p] to s_cmt[p].cmt attribute(bold)
      otherwise
	display cmt[p] to s_cmt[p].cmt attribute(reverse)
    end case
    case
      when hea[p] is null
      when usebold
	display hea[p] to s_hea[p].hea attribute(bold)
      otherwise
	display hea[p] to s_hea[p].hea attribute(reverse)
    end case
end function
#
# master pane: row display
#
function drow_fpn(r)
    define r, l		integer,
	   k1,
	   k2,
	   txt		char(78),
	   l_r		integer

    let l=r-browse_offset()
    fetch absolute r fpn_curs into k1, k2, l_r, txt
    if (r=pan_row())
    then
	let link_dpn=l_r
	display txt to s_fpn[l].* attribute(reverse)
    else
	display txt to s_fpn[l].* attribute(normal)
    end if
end function
#
#  slave pane: row display
#
function drow_spn(r)
    define r, l	integer,
	   txt 	char(78),
	   n	smallint

    let l=r-pan_row()+1
    fetch absolute r spn_curs into n, txt
    display txt to s_spn[l].*
end function
#
#  slave pane: row retrieval
#
function retrieve_spn(r)
    define r	integer,
	   txt 	char(78),
	   n	smallint

    fetch absolute r spn_curs into n, txt
    return txt
end function
