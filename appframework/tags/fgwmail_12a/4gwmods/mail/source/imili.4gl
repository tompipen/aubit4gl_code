#	IMILI.4gl  -  4gwmail message composer
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
globals "imilg.4gl"
globals "itedg.4gl"

define	adb_table	char(18),
	adb_search	char(100),
	fd, sock	integer

#
#	set address book search query
#
function mil_setaddrbook(t, s)
    define t	char(18),
	   s	char(100)

    whenever error call trap_err
    let adb_table=t
    let adb_search=s
end function
#
#  mail/news message creation
#
function mil_send(im, ip, link_msg)
    define im, ip	smallint,
	   link_msg	integer,
	   p_dst	array[20] of record
			    dtype	char(12),
			    dcont	char(65),
			    d2ndtype	char(1)
			end record,
	   dst_count	smallint,
	   cmd		char(132),
	   tok		char(20),
	   str, tail	char(78),
	   help_list	char(78),
	   expires,
	   followupto,
	   newsgroups	smallint,
	   subject	char(70),
	   references	smallint,
	   message_id,
	   in_reply_to,
	   wrote	char(132),
	   tm		integer,
	   cr, sr	smallint,
	   d, f		smallint,
	   i, j, k, n	smallint,
	   sm, sn	smallint

    let dst_count=0
    let ted_count=0
    let message_id=""
    let in_reply_to=""
    let references=""
    let subject=""
    if (im is not null)
    then
	let wrote=txt_retrieve("imil.qstart")
	let f=false
	let n=false
	call spn_start(link_msg, 0)
	let d=1
	let str=spn_retrieve()
	while (SQLCA.SQLCODE=0)
#
#  this entire loops works under the assumption (as it should be) that a
#  message which is being replied to contains either reply-to:'s or
#  followup-to:'s. If it isn't, "followup-to: poster" might not work
#
#  still to be looked into: *folded headers*
#
	    call get_token(str)
	      returning tok, tail
	    let tok=downshift(tok)
	    case
	      when (tok is null)
		exit while
	      when (str[1,1]=" ")
	      when (tok="date:") and (im!=MB_miledit)
		let wrote=mil_changeparm("%d", tail, wrote)
	      when (tok="subject:")
		let subject=tail
		call get_token(upshift(tail))
		  returning tok, tail
		case
		  when (im=MB_milreply) and (tok!="RE:")
		    let subject="Re: ", subject clipped
		  when (im=MB_milforward) and (tok!="FWD:")
		    let subject="Fwd: ", subject clipped
		end case
	      when (tok="from:")
		if (im=MB_miledit)
		then
		    let tail=mil_getaddress(tail)
		    if (tail=mil_getaddress(sender))
		    then
			exit case
		    else
			call usr_warn("imil.ena")
			call spn_end()
			return MB_display, MP_nodisplay
		    end if
		end if
		if (im=MB_milreply) and (dst_count<20) and (n or not f)
		then
		    let dst_count=dst_count+1
		    let p_dst[dst_count].dtype="to:"
		    let p_dst[dst_count].d2ndtype="a"
		    let p_dst[dst_count].dcont=tail
		end if
		let wrote=mil_changeparm("%f", tail, wrote)
		let wrote=mil_changeparm("%a", mil_author(tail), wrote)
	      when (im=MB_milforward)
	      when (tok="message-id:") and (im!=MB_miledit)
		let message_id=mil_anglebracket(tail)
	      when (tok="references:")
		let references=d
	      when (tok="in-reply-to:")
		let in_reply_to=mil_anglebracket(tail)
	      when (im=MB_miledit)
	        case
		  when (dst_count=20)
		  when (tok="to:") or (tok="reply-to:") or (tok="cc:")
		    let dst_count=dst_count+1
		    let p_dst[dst_count].dtype=tok
		    let p_dst[dst_count].d2ndtype="a"
		    let p_dst[dst_count].dcont=tail
		  when (tok="newsgroups:") or (tok="followup-to:")
		    let dst_count=dst_count+1
		    let p_dst[dst_count].dtype=tok
		    let p_dst[dst_count].d2ndtype="n"
		    let p_dst[dst_count].dcont=tail
		end case
	      when (tok="reply-to:")
		if (not f)
		then
		    let i=1
		    while (i<=dst_count)
			if (p_dst[i].dtype="to:")
			then
			    for j=i+1 to dst_count
				let k=j-1
				let p_dst[k].*=p_dst[j].*
			    end for
			    let dst_count=dst_count-1
			end if
			let i=i+1
		    end while
		    let f=true
		end if
		if (dst_count<20)
		then
		    let dst_count=dst_count+1
		    let p_dst[dst_count].dtype="to:"
		    let p_dst[dst_count].d2ndtype="a"
		    let p_dst[dst_count].dcont=tail
		end if
	      when (tok="followup-to:")
		if (not n)
		then
		    let i=1
		    while (i<=dst_count)
			if (p_dst[i].dtype="newsgroups:")
			then
			    for j=i+1 to dst_count
				let k=j-1
				let p_dst[k].*=p_dst[j].*
			    end for
			    let dst_count=dst_count-1
			end if
			let i=i+1
		    end while
		    let n=true
		end if
		if (dst_count<20 and tail!="poster")
		then
		    let dst_count=dst_count+1
		    let p_dst[dst_count].dtype="newsgroups:"
		    let p_dst[dst_count].d2ndtype="n"
		    let p_dst[dst_count].dcont=tail
		end if
	      when (tok="newsgroups:") and (dst_count<20) and not n
		let dst_count=dst_count+1
		let p_dst[dst_count].dtype="newsgroups:"
		let p_dst[dst_count].d2ndtype="n"
		let p_dst[dst_count].dcont=tail
	    end case
	    let str=spn_retrieve()
	    let d=d+1
	end while
	call spn_end()
	case
	  when (im=MB_miledit)
	    call loadbody_mil(link_msg, "", "", "")
	  when (ip=MP_milquoted)
	    call loadbody_mil(link_msg, wrote, ">", "")
	  when (ip=MP_milbracketed)
	    call loadbody_mil(link_msg, wrote, "", txt_retrieve("imil.qend"))
	end case
    end if
    let i=ted_fileread(signature, 10, ted_count+1, ted_count)
    open form mil_send_form from "milfi"
    display form mil_send_form
    call usr_header(txt_retrieve("imil.cmp"), true, true)
    call usr_area()
    display by name subject
    call ted_start(12, K_maxtedrows, false, false)
    call ted_features(true, true)
    call ted_show()
    let d=1
    let f=1
    let expires=""
    let int_flag=false
    while (true)
	call usr_status("")
	case f
	  when 1
	    call set_count(dst_count)
	    input array p_dst without defaults from s_dst.* help 3
	      before row
		let cr=arr_curr()
		let sr=scr_line()
		if (cr<dst_count) and (d=-1)
		then
		    next field dummy
		else
		    let d=0
		end if

	      before delete
		case
		  when (cr=expires)
		    let expires=""
		  when (cr<expires)
		    let expires=expires-1
		end case

	      after field dtype
		let tok=p_dst[cr].d2ndtype
		case
		  when (p_dst[cr].dtype="newsgroups:" or
			p_dst[cr].dtype="followup-to:")
		    let p_dst[cr].d2ndtype="n"
		  when (p_dst[cr].dtype="expires:")
		    if (expires!=cr)
		    then
			call usr_warn("imil.dex")
			let p_dst[cr].dcont=""
			display p_dst[cr].dcont to s_dst[sr].dcont
			next field dtype
		    end if
		    let p_dst[cr].d2ndtype="d"
		    let expires=cr
		  otherwise
		    let p_dst[cr].d2ndtype="a"
		end case
		if (tok!=p_dst[cr].d2ndtype)
		then
		    let p_dst[cr].dcont=""
		    display p_dst[cr].dcont to s_dst[sr].dcont
		end if

	      after field dcont
		if (length(p_dst[cr].dcont)=0)
		then
		    call usr_warn(-1305)
		    next field dcont
		end if
		if (p_dst[cr].d2ndtype="d")
		then
		    let tm=(date(p_dst[cr].dcont)-date("01/01/1970"))*86400
		    if (tm is null)
		    then
			let tm=get_timet_date(p_dst[cr].dcont)
		    end if
		    case
		      when (tm is null)
			call usr_warn(-1304)
			next field dcont
		      when (tm-get_time()<172800)
			call usr_warn("imil.ex2")
			next field dcont
		      otherwise
			let p_dst[cr].dcont=mil_rfctime(tm)
			display p_dst[cr].dcont to s_dst[cr].dcont
		    end case
		end if

	      after row
		if (d=0)
		then
		    let d=usr_direction(4, 20, p_dst[cr].dcont is null)
		    if (d>0) or (d<0 and arr_count()>0)
		    then
			exit input
		    end if
		end if

	      on key(control-B, F5)
		case
		  when infield(dtype)
		    call uni_desc("file", "ihea.txt", get_fldbuf(dtype))
		      returning p_dst[cr].dtype
		    if (p_dst[cr].dtype is not null)
		    then
			display p_dst[cr].dtype to s_dst[cr].dtype
		    end if
		  when (p_dst[cr].d2ndtype="n")
		    call mil_choose("", newsrc, "", false)
		      returning help_list, str
		    if help_list is not null
		    then
			let p_dst[cr].dcont=help_list
			display p_dst[cr].dcont to s_dst[sr].dcont
		    end if
		  when (adb_table is not null or adb_search is not null)
		    call multi_help(adb_table, adb_search, 65, ", ", "",
				    get_fldbuf(dcont))
		      returning help_list
		    if help_list is not null
		    then
			let p_dst[cr].dcont=help_list
			display p_dst[cr].dcont to s_dst[sr].dcont
		    end if
		end case
	    end input
	    let dst_count=arr_count()
	    while (dst_count>0)
		if (length(p_dst[dst_count].dcont)>0)
		then
		    exit while
		else
		    let dst_count=dst_count-1
		end if
	    end while
	  when 2
	    input by name subject without defaults help 4
	      after field subject
		exit input
	    end input
	    let d=usr_action()
	  when 3
	    let d=ted_input(d, true)
	end case
	let f=f+d
	case
	  when (d=0)
	    case
	      when (int_flag)
		exit while
	      when (dst_count=0)
		call usr_warn(-1305)
		let f=1
		let d=1
		continue while
	      when (length(subject)=0)
		call usr_warn(-1305)
		let f=2
		let d=1
		continue while
	      otherwise
		for i=1 to dst_count
		    case
		      when (p_dst[i].d2ndtype="a" and
			    p_dst[i].dtype!="reply-to:") or
			   (p_dst[i].d2ndtype="n" and
			    p_dst[i].dtype="newsgroups:")
			exit for
		      when (i=dst_count)
			let f=1
			let d=1
			call usr_warn("imil.nrs")
			continue while
		    end case
		end for
	    end case
	  when (f=0)
	    let f=3
	    continue while
	  when (f=4)
	    let f=1
	    continue while
	  otherwise
	    continue while
	end case
	let sm=false
	let sn=false
	let followupto=0
	let newsgroups=0
	for i=1 to dst_count
	    case
	      when (p_dst[i].d2ndtype="a" and p_dst[i].dtype!="reply-to:")
		let sm=true
	      when (p_dst[i].dtype="newsgroups:" and newsgroups=0)
		let newsgroups=i
		let sn=true
	      when (p_dst[i].dtype="followup-to:" and followupto=0)
		let followupto=i
	    end case
	end for
	call usr_status("wa")
	if (sm)
	then
	    let cmd=sendmail, " 1>/dev/null 2>&1"
	    let fd=pipe_open(cmd, "w")
	    if (status!=0)
	    then
		call usr_warn("imil.nsp")
		continue while
	    end if
	end if
	if (sn)
	then
#
#	contact NNTP server
#
	    let sock=nntp_opensocket()
	    if (sock is null)
	    then
		call endsend_mil(false, sm)
		continue while
	    end if
#
#	see if first ng existing, otherwise posting fails
#
	    case
	      when (testgroup_mil(p_dst[newsgroups].dcont))
		continue while
	      when not followupto
	      when (p_dst[followupto].dcont="poster")
	      when (testgroup_mil(p_dst[followupto].dcont))
		continue while
	    end case
#
#	see if we can actually post
#
	    call fd_writeln(sock, "post")
	    let str=fd_read(sock)
	    case
	      when (status!=0)
		call nws_sayerror(status)
		call endsend_mil(sn, sm)
		continue while
	      when (str[1, 3]!="340")
		call nws_saywarning(str)
		call endsend_mil(sn, sm)
		continue while
	    end case
	    call fd_droptoeol(sock)
	else
	    let sock=""
	end if
#
#  some inn implementations require a (possibly well formed!) from: header
#
	if (sender is not null)
	then
	    let str="From: ", sender
	    call sendtxt_mil(str, sm, sn)
	end if
	for i=1 to dst_count
	    let str=p_dst[i].dtype clipped, " ", p_dst[i].dcont clipped
	    let str[1, 1]=upshift(str[1, 1])
	    call sendtxt_mil(str, sm and (p_dst[cr].d2ndtype="a"),
				  sn and (p_dst[cr].d2ndtype="d"))
	end for
	if (sn)
	then
	    let str="Newsgroups: ", dropspaces_mil(p_dst[newsgroups].dcont) 
	    call fd_write(sock, str)
	    for i=newsgroups+1 to dst_count
		if (p_dst[i].dtype="newsgroups:")
		then
		    let str=",", dropspaces_mil(p_dst[i].dcont)
		    call fd_write(sock, str)
		end if
	    end for
	    call fd_writeln(sock, "")
	    if (followupto)
	    then
		let str="Followup-To: ", dropspaces_mil(p_dst[followupto].dcont) 
		call fd_write(sock, str)
		for i=followupto+1 to dst_count
		    if (p_dst[i].dtype="followup-to:")
		    then
			let str=",", dropspaces_mil(p_dst[i].dcont)
			call fd_write(sock, str)
		    end if
		end for
		call fd_writeln(sock, "")
	    end if
	end if
	if (length(subject)>0)
	then
	    let str="Subject: ", subject clipped
	    call sendtxt_mil(str, sm, sn)
	end if
	call getreferences_mil(link_msg, references)
	  returning references, str
	while (str is not null)
	    call sendtxt_mil(str, sm, sn)
	    call getreferences_mil(link_msg, references)
		returning references, str
	end while
	case
	  when (in_reply_to is null)
	  when (im=MB_miledit)
	    let str="In-Reply-To: ", in_reply_to clipped
	    call sendtxt_mil(str, sm, sn)
	  when (references is null)
	    let str="References: ", in_reply_to clipped
	    call sendtxt_mil(str, sm, sn)
	  otherwise
	    let str=" ", in_reply_to clipped
	    call sendtxt_mil(str, sm, sn)
	end case
#
#  Here things are a bit complex: 822 allows both In-Reply-To and References,
#  but prefers the first; 1036 only wants the second, so: use the second if
#  posting is involved, otherwise the first
#
	case
	  when (message_id is null)
	  when (not sn)
	    let str="In-Reply-To: ", message_id clipped
	    call sendtxt_mil(str, sm, sn)
	  when (references or in_reply_to is not null)
	    let str=" ", message_id clipped
	    call sendtxt_mil(str, sm, sn)
	  otherwise
	    let str="References: ", message_id clipped
	    call sendtxt_mil(str, sm, sn)
	end case
	call sendtxt_mil("", sm, sn)
	for i=1 to ted_count
	    call sendtxt_mil(p_ted[i].txt, sm, sn)
	end for
	if (sm)
	then
	    let sm=fd_close(fd)
	end if
	if (sn)
	then
	    call fd_writeln(sock, ".")
	    let str=fd_read(sock)
	    case
	      when (status!=0)
	      when (str[1, 1]!="2")
		call nws_saywarning(str)
		call endsend_mil(sn, false)
		continue while
	    end case
	    call endsend_mil(sn, false)
	end if
	case
	  when (mil_getsent() is null)
	  when (mil_createlock(mil_getsent()))
	    call usr_warn("imil.ews")
	  otherwise
	    let fd=file_open(mil_getsent(), "a")
	    if (status!=0)
	    then
		call usr_warn("imil.ews")
		goto end_savesent
	    end if
	    call file_lock(fd, true)
	    if (status!=0)
	    then
		call usr_warn("imil.ews")
		goto end_savesent
	    end if
	    let str="From ", get_login(), " ", mil_unixtime(get_time())
	    call fd_writeln(fd, str)
	    if (sender is not null)
	    then
		let str="From: ", sender
		call fd_writeln(fd, str)
	    end if
	    for i=1 to dst_count
		let str=p_dst[i].dtype clipped, " ", p_dst[i].dcont clipped
		let str[1, 1]=upshift(str[1, 1])
		call fd_writeln(fd, str)
	    end for
	    let str="Date: ", mil_rfctime(get_time())
	    call fd_writeln(fd, str)
	    if length(subject)>0
	    then
		let str="Subject: ", subject clipped
		call fd_writeln(fd, str)
	    end if
	    call getreferences_mil(link_msg, references)
	      returning references, str
	    while (str is not null)
		call fd_writeln(fd, str)
		call getreferences_mil(link_msg, references)
		  returning references, str
	    end while
	    case
	      when (in_reply_to is null)
	      when (im=MB_miledit)
		let str="In-Reply-To: ", in_reply_to clipped
		call fd_writeln(fd, str)
	      when (references is null)
		let str="References: ", in_reply_to clipped
		call fd_writeln(fd, str)
	      otherwise
		let str=" ", in_reply_to clipped
		call fd_writeln(fd, str)
	    end case
	    case
	      when (message_id is null)
	      when (not sn)
		let str="In-Reply-To: ", message_id clipped
		call fd_writeln(fd, str)
	      when (references or in_reply_to is not null)
		let str=" ", message_id clipped
		call fd_writeln(fd, str)
	      otherwise
		let str="References: ", message_id clipped
		call fd_writeln(fd, str)
	    end case
	    call fd_writeln(fd, "")
	    for i=1 to ted_count
		call fd_writeln(fd, p_ted[i].txt)
	    end for
#
#  maybe there should be two empty lines?
#
	    call fd_writeln(fd, "")
label end_savesent:
	    let i=fd_close(fd)
	    call mil_droplock(mil_getsent())
	end case
	exit while
    end while
    close form mil_send_form
    call hold_warning()
    case
      when int_flag
	let int_flag=false
	call usr_warn("oi")
	return MB_display, MP_fulldisplay
      when sm
	call usr_warn("imil.dm")
      otherwise
	call usr_warn("imil.mi")
    end case
    case
      when (inbox=mil_getcurbox())
#
#	before giving up control, give sendmail the time to dispatch
#	mail back to us, if there is any
#
	sleep 2
	call mil_check()
	  returning k, f
	if (k is null)
	then
	    let k=MB_display
	end if
	return k, MP_fulldisplay
      when (mil_getsent()=mil_getcurbox())
	return MB_reloadset, MP_fulldisplay
      otherwise
	return MB_display, MP_fulldisplay
    end case
end function
#
#	loads ted buffer with formatted message body 
#
function loadbody_mil(l, w, q, e)
    define l	integer,
	   w	char(78),
	   q	char(2),
	   e	char(78),
	   s	char(80),
	   t	smallint

    if (w is not null)
    then
	call loadted_mil(w)
	call loadted_mil("")
    end if
    let t=(q is not null)
    call spn_start(l, 2)
    let s=spn_retrieve()
    while (SQLCA.SQLCODE=0)
	if (t)
	then
	    let s=q, s clipped
	end if
	call loadted_mil(s)
	let s=spn_retrieve()
    end while
    call spn_end()
    if (e is not null)
    then
	call loadted_mil(e)
    end if
end function
#
#	does the actual job of storing the string
#
function loadted_mil(s)
    define s	char(80),
	   i, j	smallint

    if (ted_count=K_maxtedrows)
    then
	return
    end if
    let i=length(s)
    if (i>78)
    then
#
#  don't seize words, here
#
	while (i>67) and (s[i, i]!=" ")
	   let i=i-1
	end while
	let j=i-1
	let ted_count=ted_count+1
	let p_ted[ted_count].txt=s[1, i]
	if (ted_count=K_maxtedrows)
	then
	    return
	end if
	let ted_count=ted_count+1
	let p_ted[ted_count].txt=s[j, 80]
    else
	let ted_count=ted_count+1
	let p_ted[ted_count].txt=s
    end if
end function
#
#	test newsgroup existence
#
function testgroup_mil(g)
    define g	char(78),
	   i	smallint

    let i=pos(g, ",")
    if (i>0)
    then
	let g="group ", g[1, i]
    else
	let g="group ", g clipped
    end if
    call fd_writeln(sock, g)
    let g=fd_read(sock)
    case
      when (status!=0)
	call nws_sayerror(status)
	call endsend_mil(true, (fd is not null))
	return true
      when (g[1, 1]!="2")
	call nws_saywarning(g)
	call endsend_mil(true, (fd is not null))
	return true
    end case
    call fd_droptoeol(sock)
    return false
end function
#
#	removes spaces from ng list (inn doesn't like spaces in newsgroups: hea)
#
function dropspaces_mil(g)
    define g	char(78),
	   h	char(78),
	   t	char(78),
	   i	smallint

    call postoken(g, " \t,")
      returning t, i
    while (i is not null)
	let g=g[i, 78]
	call postoken(g, " \t,")
	  returning h, i
	if (length(h)>0)
	then
	    let t=t, ",", h clipped
	end if
    end while
    return t
end function
#
#	closes pipes & sockets in case of errors
#
function endsend_mil(n, m)
    define n, m	smallint

    if (m)
    then
	let m=fd_close(fd)
    end if
    let n=nntp_closesocket(false)
end function
#
#	send string to pipe & socket
#
function sendtxt_mil(s, m, n)
    define s	char(78),
	   m, n	smallint

    if (m)
    then
	call fd_writeln(fd, s)
    end if
    if (n)
    then
	if (s[1, 1]=".")
	then
	    let s=".", s clipped
	end if
	call fd_writeln(sock, s)
    end if
end function
#
#	gets next references line
#
function getreferences_mil(l, r)
    define l	integer,
	   r	smallint,
	   s, t	char(78)

    let s=""
    if (r is not null)
    then
	select txt into s from view_spn
	  where link_dpn=l
	    and ln=r
	if (length(s))
	then
	    let t=downshift(s)
	    if (t[1, 12]!="references: " and s[1, 1]!=" ")
	    then
		let s=""
	    else
		let r=r+1
	    end if
	end if
    end if
    return r, s
end function
