#	IMILV.4gl  -  mail & news viewer
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
 
#include "idefl.4gh"
#include "imill.4gh"
globals "idpng.4gl"
globals "imilg.4gl"

define	inbox_stat	integer,
	inbox_size	integer,
	cur_stat	integer,
	refresh		integer,
	mbox		char(70)

#
#	module initialization
#
function mil_init()
    define i	smallint,
	   fd	smallint

    whenever error call trap_err
    call ntl_init()
    let inbox=""
    let folders=""
    let sent=""
    let sender=""
    let sendmail=""
    let signature=""
    let newsrc=""
    let nntphost=""
    let refresh=false
#
#  load systemwide defaults
#
    call mil_loadprefs(filepath(fgl_getenv("DBPATH"), "4gwmail.rc"))
#
#  load user defaults
#
    call mil_loadprefs(filepath(fgl_getenv("HOME"), ".4gwmailrc"))
#
#  fill in empty fields
#
    call mil_loadefaults()
#
#  see if folders directory needs to be created
#
    call diropen(folders)
    if (status=0)
    then
	call dirclose()
    else
	call dirmake(folders)
    end if
#
#  and while we're at it, create sent folder
#
    let fd=file_open(mil_getsent(), "r")
    if (status!=0)
    then
	let fd=file_open(mil_getsent(), "w")
    end if
    let i=fd_close(fd)
    let mbox=""
    call mil_getstat(inbox) returning inbox_stat, inbox_size
    call mil_setaddrbook("", "")
end function
#
#	interactively chooses/ forces folder or newsgroup to display upon
#	viewer entry
#
function mil_entry(mail, news, n)
    define mail,
	   news		integer,
	   n, f		char(70),
	   t, s		integer

    case
      when mbox is not null
	return false
      when n is not null
	let mbox=filepath(folders, n)
	call mil_getstat(mbox)
	  returning t, s
	if (t=get_time()) and (s=0)
	then
	    let mbox=n
	end if
      otherwise
	if (mail)
	then
	    let f=folders
	else
	    let f=""
	end if
	if (news)
	then
	    let n=newsrc
	else
	    let n=""
	end if
	call mil_choose(f, n, "", mail)
	  returning mbox, n
    end case
#
#  this is not an entirely acceptable practice -- In the future, MB_init or
#  dpn_looks could be made to wipe out the comment we're setting here
#
    call setcmt_mil(n)
    return (mbox is not null)
end function
#
#       mail viewer
#
function mil_viewer()
    define im, ip,
	   om, op	smallint,
	   viewing_news	integer,
	   new_mbox	char(70),
	   new_name	char(70),
	   str		char(78),
	   sort_1,
	   sort_2	char(7),
	   mil_ord	smallint,
	   header_lev	smallint,
	   dr		integer,
	   fd, i, j	smallint

#
#  configurable options start here
#
    let mil_ord=true
    let sort_1="63,81"
    let sort_2=""
    let header_lev=1
#
#  and end here
#
    call menu_start()
    let i=pan_add(1)
#
#  recipe for first pane header: substitute the next line with the next two,
#  and edit 4gwmods/mail/<language>/milfv.per accordingly
#
    call dpn_looks("milfv", 6, 10)
#    call dpn_looks("milfv", 5, 10)
#    call dpn_header(txt_retrieve("imil.heaf"), 1)
    call mnu_mask(MB_chooseset, MB_chooseset, K_allpanes)
    call mnu_mask(MB_reloadset, MB_reloadset, K_allpanes)
    call mnu_mask(MB_deleterec, MB_deleterec, K_allpanes)
    call mnu_mask(MB_copyrec, MB_copyrec, K_allpanes)
    call mnu_mask(MB_filewrite, MB_filewrite, K_allpanes)
    call mnu_mask(MB_print, MB_print, K_allpanes)
    call mnu_mask(MB_milsort, MB_nwscancel, K_allpanes)
    call mnu_mask(MB_mildesc, MB_mildesc, 0)
    call mnu_record(MB_deleterec, MB_deleterec, 1)
    call mnu_record(MB_copyrec, MB_copyrec, 1)
    call mnu_record(MB_filewrite, MB_filewrite, 1)
    call mnu_record(MB_milmove, MB_nwscancel, 1)
    call mnu_record(MB_print, MB_print, 1)
    if (mbox is null)
    then
	let mbox=inbox
	call setcmt_mil("Inbox")
    end if
    if (pos(mbox, folders)=1 or mbox=inbox)
    then
	let viewing_news=false
	let dr=construct_mil(mbox, "")
	let refresh=(mbox=inbox)
    else
	let viewing_news=true
	call hold_warning()
	call construct_nws(mbox, false)
	let refresh=true
    end if
    call setmenu_mil(viewing_news)
    call open_mil(sort_1, sort_2, mil_ord, header_lev)
    let om=MB_init
    let op=""
    while true
#
#  rats! nntp message loading forces us to use the filters directly
#
	call pan_enter()
	call dpn_upstream(om, op) returning im, ip
	call getbody_mil(im, ip, viewing_news)
	call dpn_upstream(im, ip) returning im, ip
	call menu_get(im, ip) returning im, ip
	call fpn_downstream(im, ip) returning im, ip
	call getbody_mil(im, ip, viewing_news)
	call spn_downstream(im, ip) returning im, ip
	let om=MB_display
	let op=MP_nodisplay
	case
	  when (im=MB_exit)
	    exit while
	  when (im=MB_reloadset)
	    if (viewing_news)
	    then
		call construct_nws(mbox, true)
	    else
		let dr=construct_mil(mbox, "")
	    end if
	    call fpn_sync(1)
	    let om=MB_declare
	    if (ip=MP_fulldisplay)
	    then
		let op=ip
	    else
		let op=MP_partdisplay
	    end if
	  when (im=MB_chooseset)
	    call mil_choose(folders, newsrc, "", true)
		returning new_mbox, new_name
	    if (new_mbox is not null)
	    then
		if (new_mbox=new_name)
		then
		    let viewing_news=true
		    call construct_nws(new_mbox, false)
		    let refresh=true
		else
		    let viewing_news=false
		    let dr=construct_mil(new_mbox, "")
		    let refresh=(new_mbox=inbox)
		end if
		let mbox=new_mbox
		call setcmt_mil(new_name)
		call setmenu_mil(viewing_news)
		call open_mil(sort_1, sort_2, mil_ord, header_lev)
		let om=MB_declare
		let op=MP_partdisplay
	    end if
	  when (im=MB_nwscancel)
	    if usr_askremove(1)
	    then
		call mil_cancel(link_dpn)
		  returning om, op
	    end if
	  when (im=MB_deleterec)
	    if usr_askremove(1)
	    then
		call erase_mil(link_dpn, mbox)
		  returning i, j
		if (j)
		then
		    let om=MB_open
		    let op=MP_partdisplay
		    call usr_warn("ee")
	        end if
		if (i)
		then
		    let om=MB_declare
		    let op=MP_partdisplay
		end if
	    end if
	  when (im=MB_milmove)
	    call mil_choose(folders, "", mbox, true)
		returning new_mbox, new_name
	    case
	      when (new_mbox is null)
	      when append_mil(link_dpn, new_mbox)
		call erase_mil(link_dpn, mbox)
		  returning i, j
		if (j)
		then
		    let om=MB_open
		    let op=MP_partdisplay
		    call usr_warn("imil.mv")
	        end if
		if (i)
		then
		    let om=MB_declare
		    let op=MP_partdisplay
		end if
	    end case
	  when (im=MB_copyrec)
	    call mil_choose(folders, "", mbox, true)
		returning new_mbox, new_name
	    case
	      when (new_mbox is null)
	      when append_mil(link_dpn, new_mbox)
		call usr_warn("imil.cp")
	    end case
	  when (im=MB_filewrite)
	    let new_mbox=file_input("", "")
	    if int_flag
	    then
		let int_flag=false
		continue while
	    end if
	    let fd=file_open(filepath(fgl_getenv("HOME"), new_mbox), "w")
	    if (status=0)
	    then
		call spn_start(link_dpn, ip)
		let str=spn_retrieve()
		while (SQLCA.SQLCODE=0)
		    call fd_writeln(fd, str)
		    let str=spn_retrieve()
		end while
		call spn_end()
		let i=fd_close(fd)
		call usr_warn("re")
	    else
		call usr_warn("ishl.fm")
	    end if
	  when (im=MB_print)
	    let str=cod2ptr(viewing())
	    if int_flag
	    then
		let int_flag=false
		call usr_warn("cptr.si")
	    else
		start report mlt_rep to pipe str
		call spn_start(link_dpn, 1)
		let str=spn_retrieve()
		while (SQLCA.SQLCODE=0)
		    output to report mlt_rep(str)
		    let str=spn_retrieve()
		end while
		call spn_end()
		finish report mlt_rep
		call ptr_check()
	    end if
	  when (im=MB_miledit) or (im=MB_milforward) or (im=MB_milreply)
	    call mil_send(im, ip, link_dpn)
	      returning om, op
	    if (om=MB_reloadset)
	    then
		let dr=construct_mil(mbox, "")
		call open_mil(sort_1, sort_2, mil_ord, header_lev)
		let om=MB_declare
	    end if
	  when (im=MB_milsort)
	    case ip
	      when MP_milsender
		let sort_1="1,20"
		let sort_2="63,81"
	      when MP_milsubject
		let sort_1="22,61"
		let sort_2="63,81"
	      when MP_milthread
		let sort_1="83,101"
		let sort_2="63,81"
	      otherwise
		let sort_1="63,81"
		let sort_2=""
	    end case
	    call open_mil(sort_1, sort_2, mil_ord, header_lev)
	    let om=MB_declare
	    let op=MP_partdisplay
	  when (im=MB_milasc) or (im=MB_mildesc)
	    call mnu_mask(im, im, 0)
	    call mnu_mask(MB_milasc+mil_ord, MB_milasc+mil_ord, K_allpanes)
	    let mil_ord=not mil_ord
	    call open_mil(sort_1, sort_2, mil_ord, header_lev)
	    let om=MB_declare
	    let op=MP_partdisplay
	  when (im=MB_milevel)
	    if (ip>=0) and (ip<=2)
	    then
		let header_lev=ip
		call spn_open(ip)
		let om=MB_open
		let op=2
	    end if
	  when (im<MB_display) or (im>MB_declare)
	    call invalid_message(im)
	    let om=MB_init
	    let op=""
	end case
    end while
    let mbox=""
    call nntp_closesocket(true)
    let refresh=false
    return ip
end function
#
#	turns on/off refresh messages from mil_check
#
function mil_refresh(r)
    define r	integer

    let refresh=(r!=0 and r is not null)
end function
#
#	checks for new mail
#
function mil_check()
    define om, op	smallint,
	   t		integer

    let t=inbox_stat
    call mil_getstat(inbox) returning inbox_stat, inbox_size
    case
#
# no change in inbox, not viewing inbox, but refresh requested
#
      when (inbox_size=0) or (inbox_stat=t)
	case
	  when (mbox=inbox)
	  when (refresh)
	    return MB_reloadset, MP_partdisplay
	end case
#
# change in inbox & refresh requested
#
      when (refresh)
	call hold_warning()
	call usr_warn("imil.nm")
	return MB_reloadset, MP_partdisplay
#
# change in inbox, refresh not requested
#
      otherwise
	call usr_warn("imil.nm")
    end case
    return "", ""
end function
#
#	returns current folder
#
function mil_getcurbox()
    return mbox
end function
#
#	displays hard error
#
function nws_sayerror(e)
    define e	integer,
	   t	char(10)

    let t="imil.se", e using "&&&"
    call usr_warn(t)
end function
#
#	displays server error message
#
function nws_saywarning(m)
    define m	char(78)

    call join_warning("imil.sr", m[4,78])
end function
#
#	enables/disables some record oriented messages
#
function setmenu_mil(ng)
    define ng, f	smallint

    if ng
    then
	let ng=0
	let f=K_allpanes
    else
	let ng=K_allpanes
	let f=0
    end if
    call mnu_mask(MB_deleterec, MB_deleterec, ng)
    call mnu_mask(MB_milmove, MB_milmove, ng)
    call mnu_mask(MB_miledit, MB_miledit, ng)
    call mnu_mask(MB_nwscancel, MB_nwscancel, f)
end function
#
#	sets folder name to be displayed in comment field
#
function setcmt_mil(n)
    define n	char(78)

    call dpn_comment(n, 1, 65)
end function
#
#	opens the dpn scroller
#
function open_mil(s1, s2, o, l)
    define s1, s2	char(7),
	   o, l		smallint

    call pan_enter()
    call fpn_open(s1, s2, o, o)
    call spn_open(l)
end function
#
#	erases a mail message from a folder
#
function erase_mil(lr, mb)
    define lr		integer,
	   mb		char(70),
	   fd, rl, dl	smallint,
	   nr		integer,
	   str,
	   msg_id	char(78),
	   i, j		integer

    let rl=false
    let dl=false
    if mil_createlock(mb)
    then
	call usr_warn("ctbl.tm")
	return rl, dl
    end if
#
#  rats! folder has changed, needs to be reloaded
#
    call mil_getstat(mb) returning i, j
    if (i!=cur_stat)
    then
#
#  save the message-id for later
#
	let msg_id=""
	call spn_start(lr, 0)
	let str=spn_retrieve()
	while (SQLCA.SQLCODE=0)
	    case
	      when (length(str)=0)
		exit while
	      when (upshift(str[1,10])="MESSAGE-ID")
		let msg_id=str
		exit while
	    end case
	    let str=spn_retrieve()
	end while
	call spn_end()
#
#  reload folder
#
	let nr=construct_mil(mb, msg_id)
	let rl=true
#
#  identify message, or quit if can't
#
	if (nr is not null)
	then
	    let lr=nr
	else
	    call usr_warn("imil.nf")
	    return rl, dl
	end if
    end if
    let i=pan_set_current(1)
    if (pan_max()=1) and (mb=inbox)
    then
	call dpn_delete(lr)
	call mil_dropfile(mb)
	let dl=true
    else
	let fd=file_open(mb, "w")
	call file_lock(fd, true)
	if (status=0)
	then
	    call usr_status("wa")
	    call dpn_delete(lr)
            call fpn_start("63,81", "", false, "")
	    let lr=fpn_retrieve()
	    let i=false
	    while (SQLCA.SQLCODE=0)
		let i=true
		call spn_start(lr, 0)
		let str=spn_retrieve()
		while (SQLCA.SQLCODE=0)
		    call fd_writeln(fd, str)
		    let str=spn_retrieve()
		end while
		let lr=fpn_retrieve()
	    end while
	    call fpn_end()
	    if (i)
	    then
		call spn_end()
	    end if
	    let dl=true
	else
	    call usr_warn("ctbl.tm")
	end if
	let i=fd_close(fd)
	call mil_getstat(mb) returning cur_stat, j
	if (mb=inbox)
	then
	    let inbox_stat=cur_stat
	    let inbox_size=j
	end if
    end if
    call mil_droplock(mb)
    return rl, dl
end function
#
#	append message to mailbox
#
function append_mil(lr, mb)
    define lr	integer,
	   mb	char(70),
	   str	char(78),
	   i, j	integer,
	   fd	smallint

    if mil_createlock(mb)
    then
	call usr_warn("ctbl.tm")
	return 0
    end if
    let fd=file_open(mb, "a")
    call file_lock(fd, true)
    let j=(status=0)
    if (j)
    then
        call spn_start(lr, 0)
	let str=spn_retrieve()
	while (SQLCA.SQLCODE=0)
	    call fd_writeln(fd, str)
	    let str=spn_retrieve()
	end while
	call spn_end()
    else
	call usr_warn("ctbl.tm")
    end if
    let i=fd_close(fd)
    call mil_droplock(mb)
    return j
end function
#
#	read mail into temp table
#
function construct_mil(mbox, mid)
    define mbox		char(78),
	   mid		char(78),
	   hea		char(78),
	   hidden	char(132),
	   str, tail	char(78),
	   tok		char(20),
	   lv		smallint,
	   fd		smallint,
	   mrec		integer,
	   i, l_t, eol	integer,
	   in_body	integer,
	   see_next	integer

    call usr_status("wa")
    call dpn_create()
    let mrec=""
    let fd=file_open(mbox, "r")
    if (status!=0)
    then
	return ""
    end if
    call file_lock(fd, false)
    let l_t=0
    let hea=""
    let hidden=""
    let in_body=false
    let see_next=false
    while not fd_eof(fd)
	let eol=fd_eol(fd)
	let str=fd_read(fd)
	let lv=1
	case
	  when (str[1,5]="From ")
#
#  Damned BSD folders!
#
	    case
#
#  True message start
#
	      when eol
#
#  this is a continuation from the previous line
#
	      when in_body 
		let str[1, 1]="f"
		call spn_newline(str, 2, "")
		continue while
#
#  well, most likely this isn't a BSD mail folder
#
	      when l_t=0
		continue while
#
#  this shouldn't be happening (field folding, you see), but just in case
#
	      otherwise
		let lv=0
		continue while
	    end case
	    if (l_t>0)
	    then
		call fpn_newrec(hea, hidden)
	    end if
	    let l_t=l_t+1
	    let in_body=false
	    let see_next=false
	    let hea=""
	    let hidden=""
	    call dpn_newrec(l_t, true)
	    let lv=0
	    call fd_postwordsep(fd, " ,")
	    call fd_2ndlineheader(fd, " ")
#
#  no good message spotted up to now
#
	  when (l_t=0)
	    continue while
#
#  don't want to fold spaces in excess of line width!
#
	  when (str is null) and not eol
	    continue while
	  when (in_body)
	    call spn_newline(str, 2, "")
	    continue while
#
#  go parse headers
#
	  when eol
	    case
#
#  body starts here
#
	      when (str is null) and (fd_eol(fd))
		call fd_postwordsep(fd, " ")
		call fd_2ndlineheader(fd, "")
		let in_body=true
#
#  more than a linefull of spaces? what kind of folded header is this?
#
	      when (str is null)
		continue while
#
#  message id we were looking for
#
	      when (str=mid)
		let mrec=l_t
		let lv=0
	      otherwise
		call get_token(str)
		  returning tok, tail
		let tok=upshift(tok)
		case
		  when (tok="DATE:")
		    call date_mil(tail)
		      returning hea[63, 78], hidden[63, 81]
		  when (tok="FROM:")
		    let hea[1, 20]=mil_author(tail)
		    let hidden[1, 20]=upshift(hea[1, 20])
		  when (tok="TO:") or (tok="CC:") or (tok="NEWSGROUPS:")
		  when (tok="SUBJECT:")
		    let hea[22, 61]=tail
		    let hidden[22, 61]=subject_mil(tail)
#
#  folded visible header
#
		  when (str[1,1]=" ") and (see_next)
#
#  [folded] invisible header
#
		  otherwise
		    let lv=0
		end case
	    end case
#
#  only headers that have been automagically folded by fd_read, here
#
	  when (str[1,1]=" ") and (see_next)
	  otherwise
	    let lv=0
	end case
	let see_next=(lv=1)
	call spn_newline(str, lv, "")
    end while
    let i=fd_close(fd)
    if (l_t>0)
    then
	call fpn_newrec(hea, hidden)
	call dpn_recdone()
	call mil_getstat(mbox) returning cur_stat, i
	if (mbox=inbox)
	then
	    let inbox_stat=cur_stat
	    let inbox_size=i
	end if
    end if
    call threadit_mil()
    return mrec
end function
#
#	read group into temp table
#
function construct_nws(ngroup, relative)
    define ngroup	char(78),
	   relative	integer,
	   hea		char(78),
	   hidden	char(132),
	   str, tail	char(78),
	   tok		char(20),
	   sock		smallint,
	   lv		smallint,
	   i, l_t, eol	integer,
	   last_msg	integer,
	   ask_next	integer,
	   see_next	integer

    call usr_status("wa")
#
#  open socket
#
    let sock=nntp_opensocket()
    if (sock is null)
    then
	return
    end if
#
#  select newsgroup
#
    let str="group ", ngroup clipped
    call fd_writeln(sock, str)
    let str=fd_read(sock)
    case
      when (status!=0)
	call nws_sayerror(status)
	call nntp_closesocket(true)
	return
#
#  non existent
#
      when (str[1,1]!="2")
	call nws_saywarning(str)
	call nntp_closesocket(true)
	return
    end case
    call fd_droptoeol(sock)
#
#  skip return code and article count
#
    call get_token(str) returning tok, tail
    call get_token(tail) returning tok, tail
#
#  get first article number
#
    call get_token(tail) returning tok, tail
#
#  save last article # for later
#
    call get_token(tail) returning str, tail
    let last_msg=str2int(str)
#
#  relative op, get next article number
#
    if (relative)
    then
	whenever error continue
	select 1+max(view_fpn.link_dpn) into str
	  from view_fpn
	whenever error call trap_err
#
#  not found, let's play it absolute
#
	case
	  when (length(str)=0)
	    call dpn_create()
	    let str="stat ", tok clipped
#
#  no new messages
#
	  when (str>last_msg)
	    call nntp_closesocket(false)
	    return
	  otherwise
	    let str="stat ", str clipped
	end case
    else
#
#  set article pointer to first
#
	call dpn_create()
	let str="stat ", tok clipped
    end if
    call fd_writeln(sock, str)
    let l_t=0
    let hea=""
    let hidden=""
    let ask_next=1
    let see_next=false
    while (true)
	if (ask_next<0)
	then
#
#  done with messages, exit
#
	    if (l_t=last_msg)
	    then
		call fpn_newrec(hea, hidden)
		call dpn_recdone()
		exit while
	    else
#
#  adj message pointer
#
		call fd_writeln(sock, "next")
		let ask_next=1
	    end if
	end if
	let eol=fd_eol(sock)
	let str=fd_read(sock)
	if (status!=0)
	then
	    call nws_sayerror(status)
	    if (l_t>0)
	    then
		call dpn_recdone()
	    end if
	    exit while
	end if
	let lv=1
	call get_token(str) returning tok, tail
	let tok=upshift(tok)
	case
#
#  request message header
#
	  when (ask_next=1)
#
#  bad msg!, need to quit to avoid a loop
#
	    if (str[1, 1]!="2")
	    then
		call nws_saywarning(str)
		let l_t=last_msg
		let ask_next=-1
		exit while
	    end if
	    call fd_droptoeol(sock)
	    call fd_writeln(sock, "head")
	    let ask_next=2
	    continue while
#
#  got message header preamble
#
	  when (ask_next=2)
	    if (l_t>0)
	    then
		call fpn_newrec(hea, hidden)
	    end if
#
#  bad message
#
	    if (tok[1,1]!="2")
	    then
		call nws_saywarning(str)
		exit while
	    else
		call get_token(tail) returning tok, tail
		let l_t=str2int(tok)
	    end if
	    call fd_droptoeol(sock)
	    let ask_next=0
	    let see_next=false
	    let hea=""
	    let hidden=""
	    call dpn_newrec(l_t, true)
#
#  this is needed in case we save the message in a BSD mail folder
#
	    let str="From ", ngroup clipped, " ", mil_unixtime(get_time())
	    let lv=0
	    call fd_2ndlineheader(sock, " ")
	    call fd_postwordsep(sock, " ,")
#
#  don't want empty header lines
#
	  when (str is null)
	    continue while
#
#  folded header, but not interesting
#
	  when (str[1,1]=" ") and (not see_next)
	    let lv=0
	  when not eol
#
#  end of message
#
	  when (str=".")
	    let ask_next=-1
#
#  save empty string to flag non existence of body
#
	    let str=""
	    let lv=0
	    call fd_2ndlineheader(sock, "")
	    call fd_postwordsep(sock, " ")
#
#  shouldn't find any, but just in case
#
	  when (str="..")
	    let str="."
	  when (tok="DATE:")
	    call date_mil(tail)
	      returning hea[63, 78], hidden[63, 81]
          when (tok="FROM:")
	    let hea[1, 20]=mil_author(tail)
	    let hidden[1, 20]=upshift(hea[1, 20])
          when (tok="TO:") or (tok="CC:") or (tok="NEWSGROUPS:")
          when (tok="SUBJECT:")
	    let hea[22, 61]=tail
	    let hidden[22, 61]=subject_mil(tail)
	  otherwise
	    let lv=0
	end case
	let see_next=(lv!=0)
	call spn_newline(str, lv, "")
    end while
    call nntp_closesocket(false)
    call threadit_mil()
end function
#
#	retrieves nntp article body
#
function getbody_mil(im, ip, ng)
    define im, ip	smallint,
	   ng		integer,
	   sock, r	smallint,
	   preamble	smallint,
	   n_o, eol	smallint,
	   str		char(78)

    case
      when (not ng)
     	return
      when (im is null)
	return
      when (im=MB_init)
      when (im<MB_display) or (im>MB_declare)
	return
      when (ip=1) or (ip=MP_nodisplay)
	return
    end case
    delete from view_spn
      where view_spn.link_dpn=link_dpn
	and txt is null
	and level=0
    if (SQLCA.SQLERRD[3]=0)
    then
	return
    end if
    call usr_status("wa")
    select max(ln) into n_o from view_spn
      where view_spn.link_dpn=link_dpn
#
#  open socket
#
    let sock=nntp_opensocket()
    if (sock is null)
    then
	return
    end if
#
#  select newsgroup
#
    let str="group ", mbox clipped
    call fd_writeln(sock, str)
    let str=fd_read(sock)
    case
      when (status!=0)
	call nws_sayerror(status)
	call nntp_closesocket(false)
	return
#
#  non existent
#
      when (str[1,1]!="2")
	call nws_saywarning(str)
	call nntp_closesocket(false)
	return
    end case
    call fd_droptoeol(sock)
#
#  request article body
#
    let str="body ", link_dpn using "<<<<<&"
    call fd_writeln(sock, str)
    let preamble=true
    while (true)
	let eol=fd_eol(sock)
	let str=fd_read(sock)
	if (status!=0)
	then
	    call nws_sayerror(status)
	    if (not preamble)
	    then
		call dpn_recdone()
	    end if
	    exit while
	end if
	case
#
#  skip body preamble
#
	  when (preamble)
#
#  bad message
#
	    if (str[1,1]!="2")
	    then
		exit while
	    end if
	    call fd_droptoeol(sock)
	    call dpn_newrec(link_dpn, false)
	    let n_o=n_o+1
	    call spn_newline("", 1, n_o)
	    let preamble=false
	    call fd_postwordsep(sock, " ")
	    continue while
#
#  just in case, if we're going to save the message in a BSD mail folder
#
	  when (str[1,5]="From ")
	    let str[1, 1]="f"
	  when not eol
	    if (str is null)
	    then
		continue while
	    end if
#
#  end of message
#
	  when (str=".")
	    call dpn_recdone()
	    exit while
#
#  just in case
#
	  when (str="..")
	    let str="."
	end case
	let n_o=n_o+1
	call spn_newline(str, 2, n_o)
    end while
    call nntp_closesocket(false)
    call usr_status("")
    return
end function
#
#	builds thread index
#
function threadit_mil()
    select hidden[22,61] s, min(hidden[63,81]) d
      from view_fpn
      group by 1
      into temp sort_fpn
    if (SQLCA.SQLERRD[3]>50)
    then
	create index sort_fpn_idx on sort_fpn(s)
    end if
    update view_fpn
      set hidden[83,101]=(select sort_fpn.d
			    from sort_fpn
			    where sort_fpn.s=view_fpn.hidden[22,61])
    drop table sort_fpn
end function
#
#	returns formatted date
#
function date_mil(s)
    define s	char(78),
	   tok	char(20),
	   i	integer,
	   dt	date,
	   v, h	char(16)

#
#  get_date doesn't like +/-DDDD (TZN) timezones, but luckily enough brackets
#  mark comments in RFC822, so to make get_date happy, all we have to do is
#  drop the comment!
#
    let h=get_str_date(mil_commentdrop(s))
    let dt=extend(h[1, 10], year to day)
    let i=today-dt
    case
      when (length(h)=0)
	let v=h
      when (i=0)
	let v=h[12, 16]
      when (i<8)
	let tok="wd", weekday(dt) using "&"
	let v=txt_fetch("imil.txt", tok) clipped , " ", h[12, 16]
      when (year(today)=h[1, 4])
	let tok="mo", h[6, 7]
	let v=txt_fetch("imil.txt", tok) clipped , " ",
		       h[9, 16]
      otherwise
	let v=h
    end case
    return v, h
end function
#
#	return formatted subject
#
function subject_mil(tail)
    define tail	char(78),
	   ot	char(78),
	   tok	char(40)

    let tail=upshift(tail)
    while (length(tail)>0)
	let ot=tail
	call get_token(tail) returning tok, tail
	if (tok!="RE:") and (tok!="FWD:")
	then
	    let tail=ot
	    exit while
	end if
    end while
    return tail[1, 40]
end function
