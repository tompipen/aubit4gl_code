#	ISHLL.4gl - OS dependent routines
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

#
#  shell invocation
#
function exec_sh(pr)
    define pr	char(10),
	   c	char(90),
	   i	smallint

    whenever error call trap_err
    options prompt line last
    prompt pr clipped for c
    if not int_flag
    then
	case
	  when (c is null) or (c clipped=" ")
	    let c="exec sh"
	  when pos(c, ";")=0
	    let c="exec ", c clipped
	end case
	run c
	call shl_hitkey()
    end if
    let int_flag=false
    options prompt line last-1
end function
#
#  execute external app
#
function exec_appl(cmdline, ask_char)
    define cmdline	char(80),
	   ask_char	char(1),
	   cmd		char(90)

    options prompt line last
    if (pos(cmdline,";")=0)
    then
	let cmd="exec ", cmdline clipped
    else
	let cmd=cmdline
    end if
    if ask_char="B"
    then
	let cmd=cmd clipped, "&"
	if (shell(cmd)=0)
	then
	    call usr_warn("ishl.aa")
	else
	    call usr_warn("ishl.an")
	end if
    else
	run cmd
	if (ask_char="S")
	then
	    call shl_hitkey()
	end if
    end if
    let int_flag=false
    options prompt line last-1
end function
#
#  file name input for read/write ops
#
function file_input(fnam, path)
    define fnam,
	   path,
	   lnam	char(70)

    let lnam=fnam
    open window shl_filename_win at 4,3 with form "shlw"
      attribute(border, form line first, comment line last)
    let int_flag=false
    input by name fnam without defaults help 2
      after field fnam
	if nul(fnam)
	then
	    next field fnam
	else
	    exit input
	end if

      on key (control-b, F5)
	let fnam=uni_file(path, get_fldbuf(fnam))
	if fnam is not null
	then
	    display by name fnam
	end if
    end input
    close window shl_filename_win
    if int_flag
    then
	let fnam=lnam
	call usr_warn("oi")
    end if
    return fnam
end function
#
#  file names help
#
function uni_file(path, buf)
    define
	path	char(70),
	buf	char(40),
	ds	char(300)

    if path clipped!=" "
    then
	let ds="cd ", path clipped,";"
    else
	let ds=""
    end if
    let ds=ds clipped, "for i in *;do test -r $i -a ! -d $i && echo $i;done"
    return uni_desc("pipe", ds, buf)
end function
#
#  multiple file names help
#
function multi_file(path, ln, buf)
    define
	path	char(70),
	ln	smallint,
	buf	char(40),
	ds	char(300)

    if path clipped!=" "
    then
	let ds="cd ", path clipped,";"
    else
	let ds=""
    end if
    let ds=ds clipped, "for i in *;do test -r $i -a ! -d $i && echo $i;done"
    return multi_desc("pipe", ds, ln, " ", "", buf)
end function
