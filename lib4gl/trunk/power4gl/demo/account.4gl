################################################################################
# Maintenance program for 'account' table.
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
  naccount,oaccount record like account.*,
  nform,oform record
    grpname like acctgrp.name
  end record,
  nrowid integer,
  ncrit,ocrit,scrit record
    grpnr like account.grpnr,
    ord char(1),
    grpname char(32)
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

function account_chk_code(xacctnr,xcode,xname)

define
  xacctnr like account.acctnr,
  xcode like account.code,
  xname like account.name,
  txt char(80)
if xcode is null then return "","","",true end if
let txt = xcode clipped,"*"
whenever error continue
select acctnr,code,name into xacctnr,xcode,xname from account
  where code matches txt
whenever error stop
return xacctnr,xcode,xname,readcheck("")

end function

################################################################################
# Record existence checking by name key (entry point).
################################################################################

function account_chk_name(xacctnr,xcode,xname)

define
  xacctnr like account.acctnr,
  xcode like account.code,
  xname like account.name,
  txt char(80)
if xname is null then return "","","",true end if
let txt = xname clipped,"*"
whenever error continue
select acctnr,code,name into xacctnr,xcode,xname from account
  where name matches txt
whenever error stop
return xacctnr,xcode,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function accounts(finder,xord)

define
  finder char(60),
  xord char(1),
  rowid integer
if finder = " " then let finder = null end if
initialize ncrit to null
if xord is null then let ncrit.ord = "1"
else let ncrit.ord = xord
end if
let ncrit.grpname = "*"
call accountcset()
if listopen("accounts","","","",66) then
  call listspitem("acctnr")
  call listmsg(stx("keyother"))
  call accounts_setup(finder)
  while true
    call listman() returning action,rowid
    case action
    when "other" call mreport()
    when "filter"
      if accountc() then
        call accounts_setup("")
      end if
    when "enter"
      if account(rowid) then call listinit("") end if
    when "insert"
      if account("") then call listinit("") end if
    when "delete"
      if accountd(rowid) then call listinit("") end if
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

function accounts_setup(finder)

define
  finder char(60),
  htxt char(48)
case
when ncrit.grpname = "*" let htxt = "** All account groups **"
when ncrit.grpname is null let htxt = "** Ungrouped accounts **"
otherwise let htxt = ncrit.grpname
end case
call listhead(htxt,2,"","")
call listsetup(tables,items,format,filter,order,finder)

end function

################################################################################
# Pick-list criteria editing.
################################################################################

function accountc()

call winform("accountc",6,9)
call disptitle("criteria","s")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  let start = true
  input by name ncrit.ord,ncrit.grpname without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("accountc","")
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
  before input
    if start then next field grpname end if
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
  before field grpname call msgtx("keysearch")
  after field grpname
    call msgtx("")
    if not same(ncrit.grpname,ocrit.grpname) then
      if ncrit.grpname <> "*" then
        call acctgrp_chk_name(ncrit.grpnr,ncrit.grpname)
          returning ncrit.grpnr,ncrit.grpname,i
        if not i then next field grpname end if
      end if
      display by name ncrit.grpname attribute(reverse)
      let ocrit.grpname = ncrit.grpname
    end if
  after input
    let done = true
    let update = true
    call accountcset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function accountcset()

let items = "code,name,datopen,datclose"
let tables = "account"
let format = "%-8s  %-32s  %-10s  %-10s"
let filter = "1=1"
case
when ncrit.grpname is null let filter = filter clipped," and grpnr is null"
when ncrit.grpname <> "*"
  let filter = filter clipped," and grpnr=",ncrit.grpnr using "<<<<<<<<"
end case
case ncrit.ord
when "2" let order = "name"
otherwise let order = "code"
end case

end function

################################################################################
# Single record editing.
################################################################################

function account(xrowid)

define xrowid integer
call winform("account",9,2)
call disptitle("account","f")
let done = false
let update = false
while not done
  initialize nform to null
  if xrowid is null then
    initialize nrowid,naccount to null
    if ncrit.grpname <> "*" then let naccount.grpnr = ncrit.grpnr end if
    let start = false
  else
    select rowid,* into nrowid,naccount.* from account where rowid = xrowid
    if status <> 0 then call progerrq("account",status,"") end if
    let start = true
  end if
  if naccount.grpnr is not null then
    select name into nform.grpname from acctgrp where grpnr = naccount.grpnr
  end if
  let oaccount.* = naccount.*
  let oform.* = nform.*
  input by name naccount.code,naccount.name,nform.grpname
    ,naccount.datopen,naccount.datclose
    without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "prevpage"
      let i = listprevid(nrowid)
      if i is not null then let nrowid = i exit input end if
    when "nextpage"
      let i = listnextid(nrowid)
      if i is not null then let nrowid = i exit input end if
    when "refresh" exit input
    when "help" call helpman("account","")
    when "exit" let done = true exit input
    when "search"
      case
      when infield(grpname)
        call acctgrps(get_fldbuf(grpname)) returning i
        if i is not null then
          select grpnr,name into naccount.grpnr,nform.grpname
            from acctgrp where rowid = i
          let oform.grpname = nform.grpname
          next field grpname
        end if
      end case
    end case
  before input if start then next field name end if
  before field code call msgtx("Account code or id.")
  after field code call msgtx("")
  before field grpname call msgtx("keysearch")
  after field grpname
    call msgtx("")
    if not same(nform.grpname,oform.grpname) then
      call acctgrp_chk_name(naccount.grpnr,nform.grpname)
        returning naccount.grpnr,nform.grpname,i
      if not i then next field grpname end if
      display by name nform.grpname attribute(reverse)
      let oform.grpname = nform.grpname
    end if
  after input
    if naccount.code is null then
      call errtx("fldemp")
      next field code
    end if
    if naccount.name is null then
      call errtx("fldemp")
      next field name
    end if
    if nrowid is null then
      select count(*) into i from account where code = naccount.code
    else
      select count(*) into i from account where code = naccount.code
        and rowid <> nrowid
    end if
    if i <> 0 then
      call errtx("exists")
      next field code
    end if
    call beginw()
    whenever error continue
    if nrowid is null then
      let naccount.acctnr = 0
      insert into account values (naccount.*)
    else
      update account set * = naccount.* where rowid = nrowid
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

function accountd(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from account where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
