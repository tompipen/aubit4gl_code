#	IFOLV.4gl - Message center viewer
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
globals "imilg.4gl"

#
#  message center
#
function fol_viewer()
    define om, op,
	   im, ip	smallint

    whenever error call trap_err
    call menu_start()
    call uni_looks("folf", 17)
    call mnu_enable(MB_reloadset, MB_reloadset, 1, true)
    call hold_warning()
    call construct_fol()
    let om=MB_init
    let op=""
    call mil_refresh(true)
    while true
	call uni_upstream(om, op) returning im, ip
	call heafilter_fol(im, ip) returning im, ip
	call menu_get(im, ip) returning im, ip
	call uni_downstream(im, ip) returning im, ip
	call heafilter_fol(im, ip) returning im, ip
	let om=""
	let op=""
	case
	  when (im=MB_exit)
	    exit while
	  when (im=MB_reloadset)
	    call construct_fol()
	    let om=MB_declare
	    let op=MP_partdisplay
	  when (im is not null)
	    call invalid_message(im)
	    let om=MB_init
	end case
    end while
    call mil_refresh(false)
    return ip
end function
#
#  folder contents temp table construction
#
function heafilter_fol(im, ip)
    define im, ip	smallint,
	   h		char(78)

    if (im=MB_display) or (im=MB_open) or
       (im=MB_declare) or (im=MB_init)
    then
	let h=txt_fetch("imil.txt", "heam")
	if (dpn_usebold())
	then
	    display h to header attribute(bold)
	else
	    display h to header attribute(reverse)
	end if
	return "", ""
    end if
    return im, ip
end function
#
#  folder contents temp table construction
#
function construct_fol()
    define f	char(70)

    call usr_status("wa")
    call uni_create()
    call make_fol("Inbox", inbox)
    call diropen(folders)
    let f=dirin()
    while (f is not null)
	if (f[1, 1]!=".")
	then
	    call make_fol(f, filepath(folders, f))
	end if
	let f=dirin()
    end while
    call uni_newline("")
    call make_nws()
end function
#
#  count messages in folder
#
function make_fol(n, p)
    define n, p	char(70),
	   s, t	char(78),
	   r, c	integer,
	   fd	smallint

    let c=0
    let fd=file_open(p, "r")
    if (status=0)
    then
	while (not fd_eof(fd))
	    let s=fd_read(fd)
	    if (s[1, 5]="From ")
	    then
		let c=c+1
	    end if
	    call fd_droptoeol(fd)
	end while
	let r=fd_close(fd)
    end if
    let s=n
    let s[61,64]=c using "###&"
    call uni_newline(s)
end function
#
#	read group into temp table
#
function make_nws()
    define ngroup	char(78),
	   str, tail	char(78),
	   tok		char(20),
	   i, r, s	integer,
	   fd, sock	smallint

    call usr_status("wa")
    let fd=file_open(newsrc, "r")
    if (fd is null)
    then
	return
    end if
#
#  open socket
#
    let sock=nntp_opensocket()
    while (not fd_eof(fd))
	let ngroup=fd_read(fd)
	call get_token(ngroup)
	  returning ngroup, str
	let tok="????"
#
#  skip comments or unsubscribed to newsgroups
#
	let i=length(ngroup)
	case
	  when (i<=1) or (ngroup[1, 1]="#")
	    continue while
	  when (ngroup[i, i]!=":")
	    continue while
	  otherwise
	    let ngroup[i, i]=" "
	end case
#
#  select newsgroup
#
	if (sock)
	then
	    let str="group ", ngroup clipped
	    call fd_writeln(sock, str)
	    let str=fd_read(sock)
	    let s=status
	    case
	      when (s!=0)
		call nws_sayerror(s)
#
#  it's there
#
	      when (str[1,1]="2")
#
#  skip status
#
		call get_token(str) returning tok, tail
#
#  get count
#
		call get_token(tail) returning tok, tail
		let tok=4-length(tok) spaces, tok clipped
	    end case
	    call fd_droptoeol(sock)
	end if
	let str=ngroup
	let str[61,64]=tok[1,4]
	call uni_newline(str)
	call fd_droptoeol(fd)
    end while
    call nntp_closesocket(true)
    let r=fd_close(fd)
end function
