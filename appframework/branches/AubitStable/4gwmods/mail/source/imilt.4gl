#	IMILT.4gl  -  message, folder & newgroups related services
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

#
#	create a folder
#
function mil_create()
    define mb	char(78),
	   fd	smallint,
	   i	integer

    let mb=file_input("", folders)
    if int_flag
    then
	let int_flag=false
	return
    end if
    let mb=filepath(folders, mb)
    if (mil_createlock(mb))
    then
	call usr_warn("ctbl.tm")
	return
    end if
    let fd=file_open(mb, "r")
    if (fd is not null)
    then
	call usr_warn("imil.ef")
    else
	let fd=file_open(mb, "w")
	call usr_warn("re")
    end if
    let i=fd_close(fd)
    call mil_droplock(mb)
end function
#
#	drop a folder
#
function mil_erase()
    define mb, n	char(78)

    call mil_choose(folders, "", mil_getcurbox(), false)
      returning mb, n
    case
      when (mb is null)
      when (not usr_askremove(2))
      when (mil_createlock(mb))
	call usr_warn("ctbl.tm")
      otherwise
	call mil_dropfile(mb)
	call mil_droplock(mb)
    end case
end function
#
#	cancel a usenet message
#
function mil_cancel(link_msg)
    define link_msg	integer,
	   from		char(78),
	   subject	char(150),
	   str		char(78),
	   tok		char(20),
	   tail		char(78),
	   sock, r	smallint,
	   om, op	smallint

    whenever error call trap_err
    let om=MB_display
    let op=MP_nodisplay
    call spn_start(link_msg, 0)
    let str=spn_retrieve()
    while (SQLCA.SQLCODE=0)
	call get_token(str)
	  returning tok, tail
	let tok=upshift(tok)
	case
	  when (str is null)
	    exit while
	  when (tok="FROM:")
	    let tail=mil_getaddress(tail)
	    if (tail=mil_getaddress(sender))
	    then
		let from=str
	    else
		call usr_warn("imil.cna")
		call spn_end()
		return om, op
	    end if
	  when (tok="MESSAGE-ID:")
	    let subject="Subject: cmsg cancel ", tail clipped
	end case
	let str=spn_retrieve()
    end while
    call spn_end()
    if (from is null or subject is null)
    then
	call usr_warn("imil.nf")
	return om, op
    end if
#
#	contact NNTP server
#
    let sock=nntp_opensocket()
    if (sock is null)
    then
	call nws_sayerror(status)
	goto connection_closed
    end if
    call fd_crnl(sock, true)
#
#	see if we can actually post
#
    call fd_writeln(sock, "post")
    let str=fd_read(sock)
    case
      when (status!=0)
	call nws_sayerror(status)
	goto close_connection
      when (str[1, 3]!="340")
	call nws_saywarning(str)
	goto say_goodbye
    end case
    call fd_droptoeol(sock)
    call fd_writeln(sock, from)
    call fd_writeln(sock, subject)
    call fd_writeln(sock, "Newsgroups: control")
    call fd_writeln(sock, "")
    call fd_writeln(sock, "4glworks rulez!")
    call fd_writeln(sock, ".")
    let str=fd_read(sock)
    case
      when (status!=0)
	call nws_sayerror(status)
	goto close_connection
      when (str[1, 1]!="2")
	call nws_saywarning(str)
	goto say_goodbye
    end case
    call dpn_delete(link_msg)
    let om=MB_recdeleted
    let op=MP_partdisplay
label say_goodbye:
label close_connection:
    call nntp_closesocket(false)
label connection_closed:
    return om, op
end function
#
#	subscribe/unsubscribe to a newsgroup
#
function mil_subscribe(op)
    define op		smallint,
	   newsgroup,
	   dummy	char(70)

    open window mil_newsgroups_win at 4,3 with form "nwsw"
      attribute(border, form line first, comment line last,
	        prompt line last, message line last)
    let int_flag=false
    input by name newsgroup help 2
      after field newsgroup
	case
	  when int_flag
	    exit input 
	  when nul(newsgroup)
	    next field newsgroup
	  when op
	  when not usr_askremove(1)
	    next field newsgroup
	end case
	case adjnewsrc_mil(newsgroup, op)
	  when 0
	    exit input
	  when -1
	    call usr_warn("imil.nsg")
	    next field newsgroup
	  when -2
	    call usr_warn("imil.asn")
	    next field newsgroup
	  otherwise
	    call usr_warn("imil.ewn")
	    next field newsgroup
	end case

      on key (control-b, F5)
	if (op)
	then
	    call usr_warn("imil.nha")
	else
	    call mil_choose("", newsrc, "", false)
	      returning newsgroup, dummy
	    if (newsgroup is not null)
	    then
		display by name newsgroup
	    end if
	end if
    end input
    close window mil_newsgroups_win
    if int_flag
    then
	call usr_warn("oi")
	let int_flag=false
    else
	call usr_warn("re")
    end if
end function
#
#	performs the actual newsrc modification
#
function adjnewsrc_mil(ngroup, op)
    define ngroup	char(70),
	   fname	char(80),
	   op		smallint,
	   seek		char(70),
	   str, tok	char(132),
	   fd		smallint,
	   r		smallint,
	   offset	integer

    if (op)
    then
	let seek=ngroup clipped, "!"
	let ngroup=ngroup clipped, ":"
	let op=1
    else
	let seek=ngroup clipped, ":"
	let ngroup=ngroup clipped, "!"
	let op=0
    end if
    let fname=newsrc clipped, ".old"
#
#   a+ (+ fseek(0, SET_CUR)) reads in the correct place, but writes at the end
#
    let fd=file_open(newsrc, "r+")
    case
      when (status=0)
      when (not op)
	return -1
      otherwise
	let fd=file_open(newsrc, "a+")
	if (status!=0)
	then
	    return 1
	end if
    end case
    call file_lock(fd, true)
    if (status!=0)
    then
	let r=fd_close(fd)
	return 1
    end if
    let offset=0
    while (not fd_eof(fd))
	let str=fd_read(fd)
	call get_token(str)
	  returning tok, str
	case
	  when (tok=seek)
	    call file_seek(fd, offset)
	    call fd_write(fd, ngroup)
	    let r=fd_close(fd)
	    return 0
	  when (tok=ngroup) and op
	    let r=fd_close(fd)
	    return -2
	end case
	call fd_droptoeol(fd)
	let offset=file_tell(fd)
    end while
    if (op)
    then
	call file_seek(fd, offset)
	call fd_writeln(fd, ngroup)
    end if
    let r=fd_close(fd)
    return op-1
end function
