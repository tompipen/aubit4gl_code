################################################################################
# Maintenance program for 'irate' table.
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
  nirate,oirate record like irate.*,
  nrowid integer,
  ncrit,ocrit,scrit record
    grpnr like irate.grpnr,
    ord char(1),
    grpname char(32),
    datfr,datto char(10)
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
# Pick-list window handling (entry point).
################################################################################

function irates()

define
  rowid integer
initialize ncrit to null
let ncrit.datfr = "*"
let ncrit.datto = "*"
call iratecset()
let start = iratec()
if start then let start = listopen("irates","","","","") end if
if start then
  call listspitem("acctgrp")
  call listmsg(stx("keyother"))
  call irates_setup()
  while true
    call listman() returning action,rowid
    case action
    when "other" call mreport()
    when "filter"
      if iratec() then
        call irates_setup()
      end if
    when "enter"
      if irate(rowid) then call listinit("") end if
    when "insert"
      if irate("") then call listinit("") end if
    when "delete"
      if irated(rowid) then call listinit("") end if
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

function irates_setup()

call listhead(ncrit.grpname,2,"","")
call listsetup(tables,items,format,filter,order,"")

end function

################################################################################
# Pick-list criteria editing.
################################################################################

function iratec()

call winform("iratec",6,9)
call disptitle("iratec","f")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  input by name ncrit.grpname,ncrit.datfr,ncrit.datto without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("iratec","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    when "search"
      case
      when infield(grpname)
        call acctgrps(get_fldbuf(grpname)) returning i
        if i is not null then
          select grpnr,name into ncrit.grpnr,ncrit.grpname
            from acctgrp where rowid = i
          let ocrit.grpname = ncrit.grpname
          next field grpname
        end if
      end case
    end case
  before field grpname call msgtx("keysearch")
  after field grpname
    call msgtx("")
    if not same(ncrit.grpname,ocrit.grpname) then
      call acctgrp_chk_name(ncrit.grpnr,ncrit.grpname)
        returning ncrit.grpnr,ncrit.grpname,i
      if not i then next field grpname end if
      display by name ncrit.grpname attribute(reverse)
      let ocrit.grpname = ncrit.grpname
    end if
  before field datfr call msgtx("From date. '*'=Unrestricted.")
  after field datfr  
    call msgtx("")
    if ncrit.datfr is null then
      let ncrit.datfr = "*"
      display by name ncrit.datfr attribute(reverse)
    end if
    if ncrit.datfr <> "*" then
      if not checkdat(ncrit.datfr) then next field datfr end if
      let ncrit.datfr = convdat(ncrit.datfr)
      display by name ncrit.datfr attribute(reverse)
    end if
  before field datto call msgtx("To date. '*'=Unrestricted.")
  after field datto
    call msgtx("")
    if ncrit.datto is null then
      let ncrit.datto = ncrit.datfr
      display by name ncrit.datto attribute(reverse)
    end if
    if ncrit.datto <> "*" then
      if not checkdat(ncrit.datto) then next field datto end if
      let ncrit.datto = convdat(ncrit.datto)
      display by name ncrit.datto attribute(reverse)
    end if
  after input
    if ncrit.grpname is null then
      call errtx("fldemp")
      next field grpname
    end if
    let done = true
    let update = true
    call iratecset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function iratecset()

let items = "datch,rate,'%'"
let tables = "irate"
let format = " %-10s %10s%1s"
let filter = "grpnr=",ncrit.grpnr using "<<<<<<<<"
if ncrit.datfr <> "*" then
  let filter = filter clipped," and irate.datch>='",ncrit.datfr,"'"
end if
if ncrit.datto <> "*" then
  let filter = filter clipped," and irate.datch<='",ncrit.datto,"'"
end if

end function

################################################################################
# Single record editing.
################################################################################

function irate(xrowid)

define xrowid integer
call winform("irate",9,13)
call disptitle("irate","f")
display ncrit.grpname at 2,2 attribute(bold,blink)
let done = false
let update = false
while not done
  if xrowid is null then
    initialize nrowid,nirate to null
    let nirate.grpnr = ncrit.grpnr
    let start = false
  else
    select rowid,* into nrowid,nirate.* from irate where rowid = xrowid
    if status <> 0 then call progerrq("irate",status,"") end if
    let start = true
  end if
  let oirate.* = nirate.*
  input by name nirate.datch,nirate.rate
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
    when "help" call helpman("irate","")
    when "exit" let done = true exit input
    end case
  before input if start then next field rate end if
  before field datch call msgtx("Date of interest rate change.")
  after field datch call msgtx("")
  before field rate call msgtx("Interest rate.")
  after field rate call msgtx("")
  after input
    if nirate.datch is null then
      call errtx("fldemp")
      next field datch
    end if
    if nirate.rate is null then
      call errtx("fldemp")
      next field rate
    end if
    if nrowid is null then
      select count(*) into i from irate
        where grpnr = nirate.grpnr and datch = nirate.datch
    else
      select count(*) into i from irate
        where grpnr = nirate.grpnr and datch = nirate.datch
        and rowid <> nrowid
    end if
    if i <> 0 then
      call errtx("exists")
      next field datch
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      insert into irate values (nirate.*)
    else
      update irate set * = nirate.* where rowid = nrowid
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

function irated(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from irate where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
