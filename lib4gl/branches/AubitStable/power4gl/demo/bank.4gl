################################################################################
# Maintenance program for the 'bank' table.
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
  nbank,obank record like bank.*,
  nform,oform record
    stname like state.name
  end record,
  nrowid integer,
  ncrit,ocrit,scrit record
    stcode char(8),
    stname char(32)
  end record,
  tables char(60),
  items char(200),
  format char(100),
  filter char(500),
  order char(60),
  i,j,k integer,
  action char(10),
  start,done,update char

################################################################################
# Record existence checking by name key (entry point).
################################################################################

function bank_chk_name(xbanknr,xname)

define
  xbanknr like bank.banknr,
  xname like bank.name,
  txt char(80)
if xname is null then return "","",true end if
let txt = xname clipped,"*"
whenever error continue
select banknr,name into xbanknr,xname from bank where name matches txt
whenever error stop
return xbanknr,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function banks(finder)

define
  finder char(60),
  rowid integer
if finder = " " then let finder = null end if
initialize ncrit to null
let ncrit.stcode = "*"
let ncrit.stname = "*"
call bankcset()
if listopen("banks","","","",57) then
  call listspitem("banknr")
  call listsetup(tables,items,format,filter,order,finder)
  while true
    call listman() returning action,rowid
    case action
    when "filter"
      if bankc() then
        call listsetup(tables,items,format,filter,order,finder)
      end if
    when "enter"
      if bank(rowid) then call listinit("") end if
    when "insert"
      if bank("") then call listinit("") end if
    when "delete"
      if bankd(rowid) then call listinit("") end if
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
# Pick-list criteria editing.
################################################################################

function bankc()

call winform("bankc",6,9)
call disptitle("criteria","s")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  let start = true
  input by name ncrit.* without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("bankc","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    when "search"
      case
      when infield(stcode)
        call states(get_fldbuf(stcode),"1") returning i
        if i is not null then
          select stcode,name into ncrit.stcode,ncrit.stname
            from state where rowid = i
          display by name ncrit.stname attribute(reverse)
          let ocrit.stcode = ncrit.stcode
          let ocrit.stname = ncrit.stname
          next field stcode
        end if
      when infield(stname)
        call states(get_fldbuf(stname),"2") returning i
        if i is not null then
          select code,name into ncrit.stcode,ncrit.stname
            from state where rowid = i
          display by name ncrit.stcode attribute(reverse)
          let ocrit.stcode = ncrit.stcode
          let ocrit.stname = ncrit.stname
          next field stname
        end if
      end case
    end case
  before field stcode call msgtx("keysearch")
  after field stcode
    call msgtx("")
    if not same(ncrit.stcode,ocrit.stcode) then
      if ncrit.stcode = "*" then let ncrit.stname = "*"
      else
        call state_chk_stcode(ncrit.stcode,ncrit.stname)
          returning ncrit.stcode,ncrit.stname,i
        if not i then next field stcode end if
      end if
      display by name ncrit.stcode,ncrit.stname attribute(reverse)
      let ocrit.stcode = ncrit.stcode
      let ocrit.stname = ncrit.stname
    end if
  before field stname call msgtx("keysearch")
  after field stname
    call msgtx("")
    if not same(ncrit.stname,ocrit.stname) then
      if ncrit.stname = "*" then let ncrit.stcode = "*"
      else
        call state_chk_name(ncrit.stcode,ncrit.stname)
          returning ncrit.stcode,ncrit.stname,i
        if not i then next field stname end if
      end if
      display by name ncrit.stcode,ncrit.stname attribute(reverse)
      let ocrit.stcode = ncrit.stcode
      let ocrit.stname = ncrit.stname
    end if
  after input
    let done = true
    let update = true
    call bankcset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function bankcset()

let items = "bank.name,bank.stcode,state.name"
let tables = "bank,outer state"
let format = " %-32s %-2s %-20s"
let filter = "state.stcode=bank.stcode"
case
when ncrit.stcode is null
  let filter = filter clipped," and bank.stcode is null"
when ncrit.stcode <> "*"
  let filter = filter clipped," and bank.stcode='",ncrit.stcode,"'"
end case
let order = "bank.name"

end function

################################################################################
# Single record editing.
################################################################################

function bank(xrowid)

define xrowid integer
call winform("bank",7,2)
call disptitle("bank","f")
let done = false
let update = false
while not done
  initialize nform to null
  if xrowid is null then
    initialize nrowid,nbank to null
    if ncrit.stcode <> "*" then let nbank.stcode = ncrit.stcode end if
    let start = false
  else
    select rowid,* into nrowid,nbank.* from bank where rowid = xrowid
    if status <> 0 then call progerrq("bank",status,"") end if
    let start = true
  end if
  if nbank.stcode is not null then
    select stcode,name into nbank.stcode,nform.stname from state
      where stcode = nbank.stcode
    let start = true
  end if
  let obank.* = nbank.*
  let oform.* = nform.*
  input by name nbank.name,nbank.address1 thru nbank.address2
    ,nbank.stcode,nform.stname
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
    when "help" call helpman("bank","")
    when "exit" let done = true exit input
    when "search"
      case
      when infield(stcode)
        call states(get_fldbuf(stcode),"1") returning i
        if i is not null then
          select stcode,name into nbank.stcode,nform.stname
            from state where rowid = i
          if not same(nbank.stcode,obank.stcode) then
            display by name nform.stname attribute(reverse)
            let obank.stcode = nbank.stcode
            let oform.stname = nform.stname
            end if
          next field stcode
        end if
      when infield(stname)
        call states(get_fldbuf(stname),"2") returning i
        if i is not null then
          select stcode,name into nbank.stcode,nform.stname
            from state where rowid = i
          if not same(nbank.stcode,obank.stcode) then
            display by name nbank.stcode attribute(reverse)
            let obank.stcode = nbank.stcode
            let oform.stname = nform.stname
          end if
          next field stname
        end if
      end case
    end case
  before input if start then next field address1 end if
  before field stcode call msgtx("keysearch")
  after field stcode
    call msgtx("")
    if not same(nbank.stcode,obank.stcode) then
      call state_chk_stcode(nbank.stcode,nform.stname)
        returning nbank.stcode,nform.stname,i
      if not i then next field stcode end if
      display by name nbank.stcode,nform.stname attribute(reverse)
      let obank.stcode = nbank.stcode
      let oform.stname = nform.stname
    end if
  before field stname call msgtx("keysearch")
  after field stname
    call msgtx("")
    if not same(nform.stname,oform.stname) then
      call state_chk_name(nbank.stcode,nform.stname)
        returning nbank.stcode,nform.stname,i
      if not i then next field stname end if
      display by name nbank.stcode,nform.stname attribute(reverse)
      let obank.stcode = nbank.stcode
      let oform.stname = nform.stname
    end if
  after input
    if nbank.name is null then
      call msgtx("fldemp")
      next field name
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      let nbank.banknr = 0
      insert into bank values (nbank.*)
    else
      update bank set * = nbank.* where rowid = nrowid
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

function bankd(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from bank where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
