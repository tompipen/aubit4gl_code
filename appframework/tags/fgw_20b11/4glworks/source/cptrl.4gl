#	CPTRL.4gl  -  phisical printer routines, common block
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
#include "idefl.4gh"

define	useblobs	integer,	
	rep_rec		record
			    width,
			    offset,
			    margin	smallint
			end record,
	ptr_rec		record 
			    code_ptr	smallint
			end record,
	frm_rec		record
			    code_frm	smallint,
			    form_length,
			    form_width,
			    left_margin	smallint,
			    top_of_form	char(40),
			    form_header,
			    form_footer	char(14)
			end record,
	mdl_rec		record
			    code_mdl	smallint,
			    pitch_size,
			    line_size	smallint,
 			    init,
			    deinit,
			    set_pitch,
			    set_line,
			    formfeed	char(40)
			end record,
			header_blob,
			footer_blob	text

#
#  module initailization
#
function cptr_init()
    whenever error call trap_err
    let useblobs=false
end function
#
#  load printer parameters & return "copies corrected" report destination
#
function ptr_open(code_ptr, code_frm, copies)
    define code_ptr	smallint,
	   code_frm,	smallint,
	   copies	smallint,
	   dest		char(78),
	   i, j, k	smallint

#
# this routine assumes that some data has been loaded by frm_open
# returns no dest if this is not the case
#
    if ptr_rec.code_ptr is null or ptr_rec.code_ptr!=code_ptr or
       frm_rec.code_frm is null or frm_rec.code_frm!=code_frm
    then
    	let int_flag=true
	return ""
    end if
    select ptr.dest into dest from ptr
      where ptr.code_ptr=code_ptr
    select mdl_rows.string into mdl_rec.deinit from mdl_rows
      where mdl_rows.link_mdl=mdl_rec.code_mdl
	and mdl_rows.str_name="deinit"
    select mdl_rows.string into mdl_rec.formfeed from mdl_rows
      where mdl_rows.link_mdl=mdl_rec.code_mdl
	and mdl_rows.str_name="formfeed"
    if length(mdl_rec.init)=0
    then
	select mdl_rows.string into mdl_rec.init from mdl_rows
	  where mdl_rows.link_mdl=mdl_rec.code_mdl
	    and mdl_rows.str_name="init"
    end if
    let frm_rec.form_length=frm_rec.form_length/mdl_rec.line_size
    let frm_rec.left_margin=(frm_rec.left_margin*10)/mdl_rec.pitch_size
    let frm_rec.form_width=(frm_rec.form_width*10)/mdl_rec.pitch_size
    let i=pos(dest, "#")
    if (i!=0)
    then
	let j=length(copies using "<<&")
        let j=i+j
	if (j>0)
	then
	    let k=i+1
	    let dest[j,78]=dest[k,78]
	end if
	let j=j-1
	let dest[i,j]=copies using "<<&"
    end if
    if useblobs
    then
        select true from frm
	  where frm.code_frm=frm_rec.code_frm
	    and frm.form_header is not null
	if (status=0)
	then
            let frm_rec.form_header=tmp_filename("hea")
            locate header_blob in file frm_rec.form_header
	    select frm.form_header into header_blob from frm
	      where frm.code_frm=code_frm
	end if
        select true from frm
	  where frm.code_frm=frm_rec.code_frm
	    and frm.form_footer is not null
	if (status=0)
	then
            let frm_rec.form_footer=tmp_filename("foo")
	    locate footer_blob in file frm_rec.form_footer
	    select frm.form_footer into footer_blob from frm
	      where frm.code_frm=code_frm
	end if
    else
	select frm.form_header, frm.form_footer
	  into frm_rec.form_header, frm_rec.form_footer
	  from frm
	  where frm.code_frm=code_frm
    end if
    return dest
end function
#
#  returns currently used printer
#
function ptr_get()
    return ptr_rec.code_ptr
end function
#
#  returns currently used form
#
function frm_get()
    return frm_rec.code_frm
end function
#
#  returns currently used model
#
function mdl_get()
    return mdl_rec.code_mdl
end function
#
#  checks if printer can be used with this print
#
function frm_open(code_ptr, code_frm, w ,l, cond)
    define code_ptr	smallint,
	   code_frm	smallint,
	   w, l		integer,
	   cond		char(100),
	   str		char(300),
	   i, r		integer

    initialize rep_rec.* to null
    initialize ptr_rec.* to null
    initialize frm_rec.* to null
    initialize mdl_rec.* to null
    if cond is not null
    then
	let cond=" and ", cond clipped
    end if
    let str=
	"select frm.form_length, frm.form_width, frm.left_margin,",
	"	frm.top_of_form",
	"  from frm",
	"  where frm.code_frm= ? ",
	cond clipped
    prepare frm_stat1 from str
    declare frm_comp cursor for frm_stat1
    open frm_comp using code_frm
    fetch frm_comp into frm_rec.form_length, frm_rec.form_width,
			frm_rec.left_margin, frm_rec.top_of_form
    let r=status
    close frm_comp
    SQ_freecurs frm_comp
    free frm_stat1
    if (r!=0)
    then
	call usr_warn("cptr.F1")
	return 1
    end if
    if code_ptr is not null
    then
	select frm2ptr.init, frm.link_mdl
	  into mdl_rec.init, mdl_rec.code_mdl
	  from frm, ptr, frm2ptr
	  where frm2ptr.link_frm=code_frm
	    and frm2ptr.link_ptr=code_ptr
	    and frm.code_frm=code_frm
	    and ptr.code_ptr=code_ptr
	    and ptr.link_mdl=frm.link_mdl
	if (status!=0)
	then
	    call usr_warn("cptr.F2")
	    return -1
	end if
    end if
    let i=frm_rec.form_length/l
    select max(str_attr) into mdl_rec.line_size from mdl_rows
      where mdl_rows.link_mdl=mdl_rec.code_mdl
	and mdl_rows.str_name="line"
	and mdl_rows.str_attr<=i
    if (status!=0) or mdl_rec.line_size is null or (i=0)
    then
	call usr_warn("cptr.F3")
	return 1
    else
	select string into mdl_rec.set_line from mdl_rows
	  where mdl_rows.link_mdl=mdl_rec.code_mdl
	    and mdl_rows.str_name="line"
	    and mdl_rows.str_attr=mdl_rec.line_size
    end if
    let i=(frm_rec.form_width*10)/w
    select max(str_attr) into mdl_rec.pitch_size from mdl_rows
      where mdl_rows.link_mdl=mdl_rec.code_mdl
	and mdl_rows.str_name="pitch"
	and mdl_rows.str_attr<=i
    if (status!=0) or mdl_rec.pitch_size is null or (i=0)
    then
	call usr_warn("cptr.F4")
	return 1
    else
	select string into mdl_rec.set_pitch from mdl_rows
	  where mdl_rows.link_mdl=mdl_rec.code_mdl
	    and mdl_rows.str_name="pitch"
	    and mdl_rows.str_attr=mdl_rec.pitch_size
    end if
    let rep_rec.width=w
    let frm_rec.code_frm=code_frm
    let ptr_rec.code_ptr=code_ptr
    return 0
end function
#
#  returns blob usage status
#
function frm_useblobs()
    return useblobs
end function
#
#  tests whether headers and footers are blobs
#
function frm_testblobs()
    define tbl, col	integer,
	   tbltype	char(1),
	   db, sv	char(64),
	   tb		char(18),
	   str		char(400)

   if db_isse()
   then
	let useblobs=false
	return
   end if
   select tabid, tabtype into tbl, tbltype from systables
     where tabname="frm"
   let col=0
   if tbltype="S"
   then
	select btabid, dbname, tabname, servername
	  into tbl, db, tb, sv from syssyntable
	  where tabid=tbl
	if (status!=0)
	then
	    let useblobs=false
	    return
	end if
	if db is not null
	then
	    if length(sv)!=0
	    then
		let db=db clipped, "@", sv clipped
	    end if
	    let str="select coltype from ", db clipped, ":syscolumns, ",
		db clipped, ":systables where ", db clipped, 
		":syscolumns.tabid=", db clipped, ":systables.tabid and ",
		db clipped, ":systables.tabname=\"", tb clipped, "\" and ",
		db clipped, ":syscolumns.colname=\"form_header\""
	    prepare ptr_stat2 from str
	    declare ptr_blob cursor for ptr_stat2
	    open ptr_blob
	    fetch ptr_blob into col
	    close ptr_blob
	    SQ_freecurs ptr_blob
	    free ptr_stat2
	end if
    else
	select coltype into col from syscolumns
	  where tabid=tbl
	    and colname="form_header"
    end if
    let useblobs=(col=11 or col=12 or col=267 or col=268)
end function
#
#  retrieves control string for model
#
function mdl_controlstring(str_name, str_attr)
    define str_name	char(8),
	   str_attr	smallint,
	   string	char(40),
	   stmt		char(500)

    let string=""
#
# Rats! 4gl 7.3 no longer allowd to test variables within statements!
#
#    select mdl_rows.string into string from mdl_rows
#      where mdl_rows.link_mdl=mdl_rec.code_mdl
#	and mdl_rows.str_name=str_name
#	and (mdl_rows.str_attr=str_attr or 
#	     (mdl_rows.str_attr is null and str_attr is null))
    let stmt="select mdl_rows.string into string from mdl_rows ", 
		"where mdl_rows.link_mdl=mdl_rec.code_mdl ",
		" and mdl_rows.str_name=str_name ",
		" and mdl_rows.str_attr"
    if (str_attr is null)
    then
	let stmt=stmt clipped, " is null"
    else
	let stmt=stmt clipped, "=", str_attr using "<<<<#"
    end if
    prepare mdl_rows_string_stmt from stmt
    declare mdl_rows_string_curs cursor for mdl_rows_string_stmt
    open mdl_rows_string_curs
    fetch mdl_rows_string_curs into string
    close mdl_rows_string_curs
    SQ_freecurs mdl_rows_string_curs
    free mdl_rows_string_stmt
    return string
end function
#
#  calculates offset for a centered print
#
function ptr_center(h)
    define h	char(96),
	   i	smallint

    let i=1+(rep_rec.width-length(h))/2
    return i
end function
#
#  calculates offset for a right justified print
#
function ptr_right(h)
    define h	char(96),
	   i	smallint

    let i=1+rep_rec.width-length(h)
    return i
end function
#
#  sets user defined x offset
#
function ptr_ofs_x(o)
    define o	smallint

    case
      when (o<0)
        let rep_rec.offset=0
      when (o>100)
        let rep_rec.offset=100
      otherwise
      	let rep_rec.offset=o
    end case
    let rep_rec.margin=((frm_rec.form_width-rep_rec.width)*rep_rec.offset)/100
    if (rep_rec.margin<frm_rec.left_margin)
    then
	let rep_rec.margin=frm_rec.left_margin
    end if
end function
#
#  returns user defined y offset
#
function ptr_ofs_y(o, h)
    define o, h smallint

    case
      when (o<0)
        let o=0
      when (o>100)
        let o=100
    end case
    return ((frm_rec.form_length-h)*o)/100
end function
#
#  sets up page header
#
function ptr_openpage(pn)
    define pn	smallint

    if (pn=1)
    then
	if rep_rec.offset is null
	then
	    call ptr_ofs_x(50)
	end if
	call page_len(frm_rec.form_length)
	call ptr_put(mdl_rec.init)
    end if
    if (frm_rec.form_header is not null)
    then
	call file_put(filepath(fgl_getenv("DBPATH"), frm_rec.form_header))
    end if
    call ptr_put(frm_rec.top_of_form)
    call ptr_put(mdl_rec.set_line)
    call ptr_put(mdl_rec.set_pitch)
    call page_adjmargins(rep_rec.margin, rep_rec.width)
end function
#
#  sets up page footer
#
function ptr_closepage(ef)
    define ef	smallint

    if (frm_rec.form_footer is not null)
    then
	call file_put(filepath(fgl_getenv("DBPATH"), frm_rec.form_footer))
    end if
    call ptr_put(mdl_rec.formfeed)
    call page_adjmargins(0, rep_rec.width)
    if ef
    then
	call ptr_put(mdl_rec.set_pitch)
	call ptr_put(mdl_rec.set_line)
	call ptr_put(mdl_rec.deinit)
	if useblobs
	then
	    if frm_rec.form_header is not null
	    then
		free header_blob
	    end if
	    if frm_rec.form_footer is not null
	    then
		free footer_blob
	    end if
	end if
	initialize mdl_rec.* to null
    end if
end function
#
#  returns page number complete with "continue" sign
#
function ptr_pagenumber(p, n)
    define p, n	integer,
	   s	char(10)

    let s="pag. ", p using "<<<"
    if not n
    then
	let s=s clipped, " %"
    end if
    return s
end function
#
#  executes printers' pipe
#
function ptr_shellop(cmd)
    define cmd char(78)

    if cmd clipped=""
    then
	return 0
    else
	return shell(cmd)
    end if
end function
