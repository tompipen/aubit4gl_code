################################################################################
# Maintenance program for 'state' table.
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
  nstate,ostate record like state.*,
  nrowid integer,
  ncrit,ocrit,scrit record
    ord char(1)
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

function state_chk_stcode(xstcode,xname)

define
  xstcode like state.stcode,
  xname like state.name,
  txt char(80)
if xstcode is null then return "","",true end if
let txt = xstcode clipped,"*"
whenever error continue
select stcode,name into xstcode,xname from state where stcode matches txt
whenever error stop
return xstcode,xname,readcheck("")

end function

################################################################################
# Record existence checking by name key (entry point).
################################################################################

function state_chk_name(xstcode,xname)

define
  xstcode like state.stcode,
  xname like state.name,
  txt char(80)
if xname is null then return "","","",true end if
let txt = xname clipped,"*"
whenever error continue
select stcode,name into xstcode,xname from state where name matches txt
whenever error stop
return xstcode,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function states(finder,xord)

define
  finder char(60),
  xord char(1),
  rowid integer
if finder = " " then let finder = null end if
initialize ncrit to null
if xord is null then let ncrit.ord = "1"
else let ncrit.ord = xord
end if
call statecset()
if listopen("states","","","","") then
  call listsetup(tables,items,format,filter,order,finder)
  while true
    call listman() returning action,rowid
    case action
    when "filter"
      if statec() then
        call listsetup(tables,items,format,filter,order,finder)
      end if
    when "enter"
      if state(rowid) then call listinit("") end if
    when "insert"
      if state("") then call listinit("") end if
    when "delete"
      if stated(rowid) then call listinit("") end if
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

function statec()

call winform("statec",6,9)
call disptitle("criteria","s")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  input by name ncrit.* without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("statec","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    end case
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
  after input
    let done = true
    let update = true
    call statecset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function statecset()

let items = "stcode,name"
let tables = "state"
let format = "  %-2s   %-20s"
let filter = "1=1"
case ncrit.ord
when "2" let order = "name"
otherwise let order = "stcode"
end case

end function

################################################################################
# Single record editing.
################################################################################

function state(xrowid)

define xrowid integer
call winform("state",9,9)
call disptitle("state","f")
let done = false
let update = false
while not done
  if xrowid is null then
    initialize nrowid,nstate to null
    let start = false
  else
    select rowid,* into nrowid,nstate.* from state where rowid = xrowid
    if status <> 0 then call progerrq("state",status,"") end if
    let start = true
  end if
  let ostate.* = nstate.*
  input by name nstate.stcode,nstate.name
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
    when "help" call helpman("state","")
    when "exit" let done = true exit input
    end case
  before input if start then next field name end if
  before field stcode call msgtx("State postal code.")
  after field stcode call msgtx("")
  after input
    if nstate.stcode is null then
      call errtx("fldemp")
      next field stcode
    end if
    if nstate.name is null then
      call errtx("fldemp")
      next field name
    end if
    if nrowid is null then
      select count(*) into i from state where stcode = nstate.stcode
    else
      select count(*) into i from state where stcode = nstate.stcode
        and rowid <> nrowid
    end if
    if i <> 0 then
      call errtx("exists")
      next field stcode
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      insert into state values (nstate.*)
    else
      update state set * = nstate.* where rowid = nrowid
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

function stated(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from state where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
