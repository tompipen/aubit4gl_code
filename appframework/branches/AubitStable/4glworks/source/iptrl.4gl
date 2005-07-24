#	IPTRL.4gl  -  phisical printer routines, interactive framework
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

define	ptr_count	integer,
	p_ptr		array[3] of record
			    desc_ptr	char(40),
			    disabled,
			    enable	char(78)
			end record

#
#  module initialization
#
function iptr_init()
    whenever error call trap_err
    let ptr_count=0
end function
#
#  printer (re)enable routine
#
function ptr_enable()
    define cnt		smallint,
	   code_ptr	smallint,
	   desc_ptr	char(40),
	   reject,
	   disabled,
 	   enable	char(78),
	   i,j		integer

    select count(*) into cnt from ptr
    if cnt=0
    then
	call usr_warn("av")
	return
    end if
    open window ptr_enable_win at 10, 6 with form "ptrwe"
      attribute(border, form line first, comment line last,
		message line last, prompt line last)
    let int_flag=false
    input by name code_ptr
	help 31

      after field code_ptr
	select ptr.desc_ptr, ptr.reject, ptr.disabled, ptr.enable
	  into desc_ptr, reject, disabled, enable
	  from ptr
	  where ptr.code_ptr=code_ptr
	if not_found(code_ptr)
	then
	    clear desc_ptr
	    let code_ptr=null
	    next field code_ptr
	else
	    display by name desc_ptr
	    if (ptr_shellop(reject)!=0)
	    then
		call usr_warn("cptr.P3")
	    else
		let i=ptr_shellop(disabled)
		while (i!=0)
		    let int_flag=false
		    call usr_help(31, false)
		    let j=usr_ask(txt_retrieve("cptr.in"), true)
		    case
		      when j
		      when int_flag
			exit input
		      otherwise
			call usr_warn("cptr.SI")
			exit while
		    end case
		    let i=ptr_shellop(enable)
		    let i=ptr_shellop(disabled)
		end while
		if (i=0)
		then
		    call usr_warn("cptr.SA")
		end if
	    end if
	end if

      after input
        if not int_flag
	then
	    next field code_ptr
	end if

      on key (control-b, F5)
	call uni_help("ptr", "", false, get_fldbuf(code_ptr))
	  returning code_ptr, desc_ptr
	if code_ptr is not null
	then
	    display by name code_ptr, desc_ptr
	end if

    end input
    close window ptr_enable_win
    let int_flag=false
end function
#
#  printer selection routine
#
function ptr_choose(code_ptr, code_frm, copies, confirm, mw, ml, cond)
    define code_ptr	smallint,
	   code_frm	smallint,
	   copies	smallint,
	   confirm	integer,
	   mw, ml	smallint,
	   cond		char(100),
	   code_ptr2	smallint,
	   desc_ptr,
	   desc_ptr2	char(40),
	   desc_frm	char(40),
	   dest		char(80),
	   reject,
	   disabled,
 	   enable	char(78),
	   i, j, k, r	integer

    let desc_ptr=""
    let desc_frm=""
    let r=true
    call hold_warning()		#hold actual message display until
				#window is displayed
    case
      when copies is null
	let copies=1
	call usr_warn("cptr.P1")
      when confirm
      when code_ptr is null or code_frm is null
	call usr_warn("cptr.P1")
      otherwise
	let r=false
    end case
    if (code_frm is not null)
    then
	call frm_test(code_ptr, code_frm, mw, ml, cond)
	  returning i, desc_frm, code_ptr, desc_ptr
	let r=r or i
    end if
    if (code_ptr is not null)
    then
	select ptr.desc_ptr, ptr.reject, ptr.disabled, ptr.enable 
	  into desc_ptr, reject, disabled, enable from ptr
	  where ptr.code_ptr=code_ptr
	case
	  when queue_full(disabled, enable)
	    call usr_warn("cptr.P4")
	    let r=true
	  when (status=notfound)
	    call usr_warn("cptr.P2")
	    let r=true
	  when r
	  when (ptr_shellop(reject)!=0)
	    call usr_warn("cptr.P3")
	    let r=true
        end case
    end if
    if (r)
    then
	open window ptr_set_win at 8, 6
	  with form "ptrws" attribute (border, form line first,
				       comment line first)
	call pop_warning()
	display by name desc_ptr, desc_frm
	let int_flag=false
	input by name code_ptr, code_frm, copies without defaults
          help 32

	  after field code_ptr
	    call ptr_test(code_ptr, code_frm)
	      returning r, desc_ptr
	    display by name desc_ptr
	    case
	      when desc_ptr is null
		let code_ptr=""
		next field code_ptr
	      when r
		let code_frm=""
		let desc_frm=""
		display by name code_frm, desc_frm
	    end case

	  after field code_frm
	    call frm_test(code_ptr, code_frm, mw, ml, cond)
	      returning r, desc_frm, code_ptr2, desc_ptr2
	    display by name desc_frm
	    case
	      when desc_frm is null
		let code_frm=""
		next field code_frm
	      when (code_ptr!=code_ptr2)
		let code_ptr=code_ptr2
		let desc_ptr=desc_ptr2
		display by name code_ptr, desc_ptr
	    end case
	    if (r)
	    then
		next field code_frm
	    end if

	  on key (control-b, F5)
	    case
	      when infield(code_ptr)
		call uni_help("ptr", "", false, get_fldbuf(code_ptr))
		  returning code_ptr, desc_ptr
		if code_ptr is not null
		then
		    display by name code_ptr, desc_ptr
		end if
	      when infield(code_frm)
		call uni_help("frm", cond, false, get_fldbuf(code_frm))
		  returning code_frm, desc_frm
		if code_frm is not null
		then
		    display by name code_frm, desc_frm
		end if
	    end case

	  after input
	    case
	      when int_flag
		exit input
	      when frm_open(code_ptr, code_frm, mw, ml, cond)!=0
		next field code_frm
	    end case
	    select ptr.reject, ptr.disabled, ptr.enable
	      into reject, disabled, enable
	      from ptr
	      where ptr.code_ptr=code_ptr
	    case
	      when queue_full(disabled, enable)
		call usr_warn("cptr.P4")
		continue input
	      when (ptr_shellop(reject)!=0)
		call usr_warn("cptr.P3")
		next field code_ptr
            end case
	end input
	close window ptr_set_win 
    else
	call drop_warning()
    end if
    if int_flag
    then
	return ""
    else
	call usr_status("wa")
        call ptr_push(desc_ptr, disabled, enable)
	return ptr_open(code_ptr, code_frm, copies)
    end if
end function
#
#  check printer status
#
function ptr_check()
    define i,j	integer

    if ptr_count=0
    then
	return
    end if
    call usr_status("wa")
    call usr_warn("cptr.sa")
    while (ptr_count>0)
	let i=ptr_shellop(p_ptr[ptr_count].disabled)
	let j=false
	while (i!=0)
	    let int_flag=false
	    call hold_warning()
	    call join_warning("cptr.ck", p_ptr[ptr_count].desc_ptr)
	    call usr_help(33, false)
	    if not usr_confirm("")
	    then
		let int_flag=false
		let j=false
		call usr_warn("cptr.SI")
		exit while
	    end if
	    let i=ptr_shellop(p_ptr[ptr_count].enable)
	    let i=ptr_shellop(p_ptr[ptr_count].disabled)
	    let j=true
	end while
	let ptr_count=ptr_count-1
	if j
	then
	    call usr_warn("cptr.SA")
	end if
	if (ptr_count>0)
	then
	    call usr_status("wa")
	end if
    end while
    call usr_status("")
end function
#
#  insert a printer in queue
#
function ptr_push(desc_ptr, disabled, enable)
    define desc_ptr	char(40),
	   disabled,
	   enable	char(78),
	   i		smallint

    let i=1
    while (i<=ptr_count)
	if (p_ptr[i].disabled=disabled) and
	   (p_ptr[i].enable=enable)
	then
	    return
	end if
	let i=i+1
    end while
    if (i>ptr_count) and (i<4)
    then
	let ptr_count=i
	let p_ptr[ptr_count].desc_ptr=desc_ptr
	let p_ptr[ptr_count].disabled=disabled
	let p_ptr[ptr_count].enable=enable
    end if
end function
#
#  check for a free slot in printer queue
#
function queue_full(disabled, enable)
   define disabled,
	  enable	char(78),
	  i		smallint

   let i=1
   while (i<=ptr_count)
	if (p_ptr[i].disabled=disabled) and
	   (p_ptr[i].enable=enable)
	then
	    exit while
	end if
	let i=i+1
   end while
   return i>3
end function
#
#  tests ptr & frm for correctness, after field code_ptr case
#
function ptr_test(code_ptr, code_frm)
    define code_ptr	smallint,
	   code_frm	smallint,
	   desc_ptr	char(40),
	   r		integer

    select ptr.desc_ptr into desc_ptr from ptr
      where ptr.code_ptr=code_ptr
    if not_found(code_ptr)
    then
	return false, ""
    end if
    if code_frm is not null
    then
	select true into r from frm2ptr, ptr, frm
	  where frm2ptr.link_frm=code_frm
	    and frm2ptr.link_ptr=code_ptr
	    and frm.code_frm=code_frm
	    and ptr.code_ptr=code_ptr
	    and ptr.link_mdl=frm.link_mdl
	if status!=0
	then
	    call usr_warn("cptr.F2")
	    return true, desc_ptr
	end if
    end if
    return false, desc_ptr
end function
#
#  tests ptr & frm for correctness - after field code_frm case
#
function frm_test(code_ptr, code_frm, w, l, cond)
    define code_ptr	smallint,
	   code_frm	smallint,
	   w, l		smallint,
	   cond		char(100),
	   desc_ptr	char(40),
	   desc_frm	char(40),
	   r		smallint

    select frm.desc_frm into desc_frm from frm
      where frm.code_frm=code_frm
    if not_found(code_frm)
    then
	return false, "", code_ptr, ""
    end if
    let r=frm_open(code_ptr, code_frm, w, l, cond)
    let desc_ptr=""
    if (r<0)
    then
	let code_ptr=""
	declare frm2ptr_curs cursor for
	  select ptr.code_ptr, ptr.desc_ptr from frm2ptr, ptr, frm
	    where frm2ptr.link_frm=code_frm
	      and frm2ptr.link_ptr=ptr.code_ptr
	      and frm.code_frm=code_frm
	      and ptr.link_mdl=frm.link_mdl
	open frm2ptr_curs
	fetch frm2ptr_curs into code_ptr, desc_ptr
	close frm2ptr_curs
	free frm2ptr_curs
	if code_ptr is not null
	then
	    let r=frm_open(code_ptr, code_frm, w, l, cond)
	else
	    let desc_ptr=""
	end if
    end if
    return r, desc_frm, code_ptr, desc_ptr
end function
