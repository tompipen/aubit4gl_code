#	IPRFT.4gl  -  4gwmail preference load & modification
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
globals "imilg.4gl"
globals "itedg.4gl"

#
#	edits preferences
#
function mil_setpreferences()
    define om, op	smallint,
	   s_inbox,
	   s_folders,
	   s_sendmail,
	   s_newsrc,
	   s_nntphost,
	   s_nntpport,
	   s_sender	char(70),
	   s_sent	char(14),
	   o_signature,
	   s_signature	char(70),
	   dummy	char(1),
	   str		char(80),
	   fd, i, r	smallint

    whenever error call trap_err
    let om=MB_display
    let op=MP_fulldisplay
    let s_inbox=inbox
    let s_folders=folders
    let s_sendmail=sendmail
    let s_signature=signature
    let s_newsrc=newsrc
    let s_nntphost=nntphost
    let s_nntpport=nntpport
    let s_sender=sender
    let s_sent=sent
    open form mil_prefs_form from "milfp"
    display form mil_prefs_form
    call usr_header(txt_retrieve("imil.prf"), true, true)
    call usr_area()
    let ted_count=0
    let i=ted_fileread(signature, 10, 1, 0)
    call ted_start(7, 10, false, false)
    call ted_features(false, false)
    call ted_show()
    let int_flag=false
    input s_sender, s_signature, s_inbox, s_folders, s_sent, s_sendmail,
	  s_nntphost, s_nntpport, s_newsrc, dummy
      without defaults
      from sender, signature, inbox, folders, sent, sendmail, nntphost,
	   nntpport, newsrc, dummy
      help 3

      before field signature
	let o_signature=s_signature

      after field signature
	case
	  when (o_signature=s_signature)
	  when (o_signature is null and s_signature is null)
	  when (s_signature is null)
	    call ted_clear()
	    let ted_count=0
	  when (ted_fileread(s_signature, 5, 1, 0)=0)
	    call ted_clear()
	    call ted_show()
	end case

      before field dummy
	let r=usr_action()
	let r=ted_input(r, true)
	case
	  when (r<0)
	    next field previous
	  when (r>0)
	    next field next
	  otherwise
	    goto after_input
	end case

      after input
label after_input:
	case
	  when (int_flag)
	    let int_flag=false
	    call hold_warning()
	    call usr_warn("oi")
	  when (ted_count>0 and length(s_signature)=0)
	    let s_signature=filepath(fgl_getenv("HOME"), ".signature")
	    display s_signature to signature
	    call usr_warn(-1311)
	    next field signature
	  otherwise
	    let fd=file_open(filepath(fgl_getenv("HOME"), ".4gwmailrc"), "w")
	    if (status!=0)
	    then
		call usr_warn("imil.ewp")
		continue input
	    end if
	    call file_lock(fd, true)
	    if (status!=0)
	    then
		call usr_warn("imil.ewp")
		continue input
	    end if
	    if (s_sender is not null)
	    then
		let str="sender ", s_sender
		call fd_writeln(fd, str)
	    end if
	    if (s_signature is not null)
	    then
		let str="signature ", s_signature
		call fd_writeln(fd, str)
		let i=ted_filewrite(s_signature, ted_count)
	    end if
	    if (s_inbox is not null)
	    then
		let str="inbox ", s_inbox
		call fd_writeln(fd, str)
	    end if
	    if (s_folders is not null)
	    then
		let str="folders ", s_folders
		call fd_writeln(fd, str)
	    end if
	    if (s_sent is not null)
	    then
		let str="sent ", s_sent
		call fd_writeln(fd, str)
	    end if
	    if (s_sendmail is not null)
	    then
		let str="sendmail ", s_sendmail
		call fd_writeln(fd, str)
	    end if
	    if (s_nntphost is not null)
	    then
		let str="nntphost ", s_nntphost
		call fd_writeln(fd, str)
	    end if
	    if (s_nntpport is not null)
	    then
		let str="nntpport ", s_nntpport
		call fd_writeln(fd, str)
	    end if
	    if (s_newsrc is not null)
	    then
		let str="newsrc ", s_newsrc
		call fd_writeln(fd, str)
	    end if
	    let r=fd_close(fd)
	    if (status!=0)
	    then
		call usr_warn("imil.ewp")
		continue input
	    end if
	    let inbox=s_inbox
	    let folders=s_folders
	    let sendmail=s_sendmail
	    let newsrc=s_newsrc
	    let nntphost=s_nntphost
	    let sender=s_sender
	    let sent=s_sent
	    call mil_loadefaults()
	    call hold_warning()
	    call usr_warn("re")
	end case
    end input
    close form mil_prefs_form
    return om, op
end function
#
#	loads preferences from file
#
function mil_loadprefs(fn)
    define fn	char(70),
	   tok	char(20),
	   str,
	   tail	char(80),
	   fd	smallint,
	   r	smallint

    let fd=file_open(fn, "r")
    if (fd is null)
    then
	return
    end if
    call file_lock(fd, false)
    while (not fd_eof(fd))
	let str=fd_read(fd)
	let str=txt_commentdrop(str)
	call get_token(str)
	  returning tok, tail
	let tok=downshift(tok)
	case
	  when (tok="inbox")
	    let inbox=tail
	  when (tok="folders")
	    let folders=tail
	  when (tok="sent")
	    let sent=tail
	  when (tok="nntphost")
	    let nntphost=tail
	  when (tok="nntpport")
	    let nntpport=tail
	  when (tok="newsrc")
	    let newsrc=tail
	  when (tok="sendmail")
	    let sendmail=tail
	  when (tok="sender")
	    let sender=tail
	  when (tok="signature")
	    let signature=tail
	end case
	call fd_droptoeol(fd)
    end while
    let r=fd_close(fd)
end function
#
#	load preferences with default values
#
function mil_loadefaults()
    if (inbox is null)
    then
	let inbox=fgl_getenv("MAIL")
#
#  just in case $MAIL is unset
#
	if (inbox is null)
	then
	    let inbox="/var/spool/mail/", get_login()
	end if
    end if
    if (folders is null)
    then
	let folders=filepath(fgl_getenv("HOME"), "mail")
    end if
    if (sent is null)
    then
	let sent="sent"
    end if
    if (sender is null)
    then
	let sender=mil_senderid()
    end if
    if (sendmail is null)
    then
	let sendmail="/usr/lib/sendmail -t"
    end if
    if (signature is null)
    then
	let signature=filepath(fgl_getenv("HOME"), ".signature")
    end if
    if (newsrc is null)
    then
	let newsrc=filepath(fgl_getenv("HOME"), ".newsrc")
    end if
    if (nntphost is null)
    then
	let nntphost="localhost"
    end if
    if (nntpport is null)
    then
	let nntpport="nntp"
    end if
end function
#
#	returns sent-mail folder
#
function mil_getsent()
    if (sent is null)
    then
	return ""
    else
	return filepath(folders, sent)
    end if
end function
