################################################################################
# Maintenance program for the 'acctgrp' table.
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
  nacctgrp,oacctgrp record like acctgrp.*,
  nrowid integer,
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

function acctgrp_chk_name(xgrpnr,xname)

define
  xgrpnr like acctgrp.grpnr,
  xname like acctgrp.name,
  txt char(80)
if xname is null then return "","",true end if
let txt = xname clipped,"*"
whenever error continue
select grpnr,name into xgrpnr,xname from acctgrp where name matches txt
whenever error stop
return xgrpnr,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function acctgrps(finder)

define
  finder char(60),
  rowid integer
if finder = " " then let finder = null end if
call acctgrpcset()
if listopen("acctgrps",4,32,8,32) then
  call listspitem("grpnr")
  call listsetup(tables,items,format,filter,order,finder)
  while true
    call listman() returning action,rowid
    case action
    when "enter"
      if acctgrp(rowid) then call listinit("") end if
    when "insert"
      if acctgrp("") then call listinit("") end if
    when "delete"
      if acctgrpd(rowid) then call listinit("") end if
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
# Setup of filter and order-by variables.
################################################################################

function acctgrpcset()

let items = "name"
let tables = "acctgrp"
let format = "%-32s"
let filter = "1=1"
let order = "name"

end function

################################################################################
# Single record editing.
################################################################################

function acctgrp(xrowid)

define xrowid integer
call winform("acctgrp",13,2)
call disptitle("acctgrp","f")
let done = false
let update = false
while not done
  if xrowid is null then
    initialize nrowid,nacctgrp to null
    let start = false
  else
    select rowid,* into nrowid,nacctgrp.* from acctgrp where rowid = xrowid
    if status <> 0 then call progerrq("acctgrp",status,"") end if
    let start = true
  end if
  let oacctgrp.* = nacctgrp.*
  input by name nacctgrp.name,nacctgrp.descr
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
    when "help" call helpman("acctgrp","")
    when "exit" let done = true exit input
    end case
  before input if start then next field descr end if
  after input
    if nacctgrp.name is null then
      call msgtx("fldemp")
      next field name
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      let nacctgrp.grpnr = 0
      insert into acctgrp values (nacctgrp.*)
    else
      update acctgrp set * = nacctgrp.* where rowid = nrowid
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

function acctgrpd(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from acctgrp where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
