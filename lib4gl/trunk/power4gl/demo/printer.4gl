################################################################################
# Maintenance program for 'printer' table.
#
# Copyright (C) 2001 John H. Frantz, Pétur K. Hilmarsson.
# 
# This file is part of Power-4gl.
# 
# Power-4gl is free software; you can redistribute it and/or modify   
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# Power-4gl is distributed in the hope that it will be useful,  
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Power-4gl; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
################################################################################

database powdemo
define
  nprinter,oprinter record like printer.*,
  nform,oform record
    prntname like prntype.name
  end record,
  nrowid integer,
  ncrit,ocrit,scrit record
    prntnr like printer.prntnr,
    ord char(1),
    prntname char(32)
  end record,
  tables char(60),
  items char(200),
  format char(100),
  filter char(400),
  order char(60),
  i,j,k integer,
  action char(10),
  start,done,update char

################################################################################
# Record existence checking by code key (entry point).
################################################################################

function printer_chk_code(xcode,xname)

define
  xcode like printer.code,
  xname like printer.name,
  txt char(80)
if xcode is null then return "","","",true end if
let txt = xcode clipped,"*"
whenever error continue
select code,name into xcode,xname from printer
  where code matches txt
whenever error stop
return xcode,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function printers(finder,xord)

define
  finder char(60),
  xord char(1),
  rowid integer
if finder = " " then let finder = null end if
initialize ncrit to null
if xord is null then let ncrit.ord = "1"
else let ncrit.ord = xord
end if
let ncrit.prntname = "*"
call printercset()
if listopen("printers","","","",76) then
  call printers_setup(finder)
  while true
    call listman() returning action,rowid
    case action
    when "filter"
      if printerc() then
        call printers_setup("")
      end if
    when "enter"
      if printer(rowid) then call listinit("") end if
    when "insert"
      if printer("") then call listinit("") end if
    when "delete"
      if printerd(rowid) then call listinit("") end if
    when "accept" exit while
    when "exit" let rowid = null exit while
    end case
  end while
  call listclose()
else let rowid = null
end if
return (rowid)

end function

################################################################################
# Pick-list setup.
################################################################################

function printers_setup(finder)

define
  finder char(60),
  htxt char(48)
case
when ncrit.prntname = "*" let htxt = "** All printer types **"
otherwise let htxt = ncrit.prntname
end case
call listhead(htxt,2,"","")
call listsetup(tables,items,format,filter,order,finder)

end function

################################################################################
# Pick-list criteria editing.
################################################################################

function printerc()

call winform("printerc",6,9)
call disptitle("criteria","s")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  let start = true
  input by name ncrit.ord,ncrit.prntname without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("printerc","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    when "search"
      case
      when infield(prntname)
        call prntypes(get_fldbuf(prntname)) returning i
        if i is not null then
          select prntnr,name into ncrit.prntnr,ncrit.prntname
            from prntype where rowid = i
          let ocrit.prntname = ncrit.prntname
          next field prntname
        end if
      end case
    end case
  before input
    if start then next field prntname end if
  before field ord
    call msgtx("'1'=Code. '2'=Name.")
  after field ord
    call msgtx("")
    if ncrit.ord is null then
      let ncrit.ord = "1"
      display by name ncrit.ord attribute(reverse)
    end if
    if ncrit.ord not matches "[12]" then
      call errtx("badval")
      next field ord
    end if
  before field prntname call msgtx("keysearch")
  after field prntname
    call msgtx("")
    if not same(ncrit.prntname,ocrit.prntname) then
      if ncrit.prntname is null then let ncrit.prntname = "*" end if
      if ncrit.prntname <> "*" then
        call prntype_chk_name(ncrit.prntnr,ncrit.prntname)
          returning ncrit.prntnr,ncrit.prntname,i
        if not i then next field prntname end if
      end if
      display by name ncrit.prntname attribute(reverse)
      let ocrit.prntname = ncrit.prntname
    end if
  after input
    let done = true
    let update = true
    call printercset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function printercset()

let items = "printer.code,printer.name,prntype.name"
let tables = "printer,outer(prntype)"
let format = "%-10s %-32s %-32s"
let filter = "prntype.prntnr=printer.prntnr"
if ncrit.prntname <> "*" then
  let filter = filter clipped," and prntnr=",ncrit.prntnr using "<<<<<<<<"
end if
case ncrit.ord
when "2" let order = "printer.name"
otherwise let order = "printer.code"
end case

end function

################################################################################
# Single record editing.
################################################################################

function printer(xrowid)

define xrowid integer
call winform("printer",9,2)
call disptitle("printer","f")
let done = false
let update = false
while not done
  initialize nform to null
  if xrowid is null then
    initialize nrowid,nprinter to null
    if ncrit.prntname <> "*" then let nprinter.prntnr = ncrit.prntnr end if
    let start = false
  else
    select rowid,* into nrowid,nprinter.* from printer where rowid = xrowid
    if status <> 0 then call progerrq("printer",status,"") end if
    let start = true
  end if
  if nprinter.prntnr is not null then
    select name into nform.prntname from prntype where prntnr = nprinter.prntnr
  end if
  let oprinter.* = nprinter.*
  let oform.* = nform.*
  input by name nprinter.code,nprinter.name,nform.prntname,nprinter.pipe
    without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "prevpage"
      let i = listprevid(nrowid)
      if i is not null then let xrowid = i exit input end if
    when "nextpage"
      let i = listnextid(nrowid)
      if i is not null then let xrowid = i exit input end if
    when "refresh" exit input
    when "help" call helpman("printer","")
    when "exit" let done = true exit input
    when "search"
      case
      when infield(prntname)
        call prntypes(get_fldbuf(prntname)) returning i
        if i is not null then
          select prntnr,name into nprinter.prntnr,nform.prntname
            from prntype where rowid = i
          let oform.prntname = nform.prntname
          next field prntname
        end if
      end case
    end case
  before input if start then next field name end if
  before field code call msgtx("Printer code or id.")
  after field code call msgtx("")
  before field prntname call msgtx("keysearch")
  after field prntname
    call msgtx("")
    if not same(nform.prntname,oform.prntname) then
      call prntype_chk_name(nprinter.prntnr,nform.prntname)
        returning nprinter.prntnr,nform.prntname,i
      if not i then next field prntname end if
      display by name nform.prntname attribute(reverse)
      let oform.prntname = nform.prntname
    end if
  after input
    if nprinter.code is null then
      call errtx("fldemp")
      next field code
    end if
    if nprinter.name is null then
      call errtx("fldemp")
      next field name
    end if
    if nprinter.prntnr is null then
      call errtx("fldemp")
      next field prntname
    end if
    if nrowid is null then
      select count(*) into i from printer where code = nprinter.code
    else
      select count(*) into i from printer where code = nprinter.code
        and rowid <> nrowid
    end if
    if i <> 0 then
      call errtx("exists")
      next field code
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      insert into printer values (nprinter.*)
    else
      update printer set * = nprinter.* where rowid = nrowid
    end if
    whenever error stop
    let update = true
    if not assessw("") then continue input end if
    let done = true
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Single record deletion.
################################################################################

function printerd(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from printer where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
