#	INLSL.4gl  -  network library
#
#	4gwMail, a news and mail client 4glWorks module
#	Copyright (C) 1997-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 99
#	Current release: Oct 99
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
 
globals "imilg.4gl"

define	nntp_sock,
	old_sock	integer

#
#	module initialization
#
function ntl_init()
    whenever error call trap_err
    let nntp_sock=0
end function
#
#	open socket to news server
#
function nntp_opensocket()
    define str	char(128),
	   s	integer

    let old_sock=nntp_sock
    if (nntp_sock>0)
    then
	call fd_writeln(nntp_sock, " ");
	if (status=0)
	then
	    return nntp_sock
	end if
    end if
    let nntp_sock=socket_open(nntphost, nntpport, "tcp")
    let s=status
    if (s)
    then
	goto bad_exit
    end if
    call fd_crnl(nntp_sock, true)
    let str=fd_read(nntp_sock)
    let s=status
    case
      when (s!=0)
	call fd_close(nntp_sock)
	goto bad_exit
	
#
#  whatever it said, we're not welcome
#
      when (str[1,1]!="2")
	call nws_saywarning(str)
	call fd_close(nntp_sock)
	goto bad_exit1
    end case
    call fd_droptoeol(nntp_sock)
    return nntp_sock
label bad_exit:
    call nws_sayerror(s)
label bad_exit1:
    let nntp_sock=0
    let old_sock=0
    return ""
end function
#
#       close socket to news server
#
function nntp_closesocket(permanent)
    define permanent	integer

    case
      when (nntp_sock<=0)
      when (permanent or old_sock<=0)
	call fd_writeln(nntp_sock, "quit")
	let permanent=fd_close(nntp_sock)
	let nntp_sock=0
    end case
end function
