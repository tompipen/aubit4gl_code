################################################################################
# Maintenance program for the 'acctran' table.
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
  nacctran,oacctran record like acctran.*,
  nform,oform record
    acctcode like account.code,
    acctname like account.name
  end record,
  nrowid integer,
  ncrit,ocrit,scrit record
    acctnr like acctran.acctnr,
    ord char(1),
    acctcode char(8),
    acctname char(32),
    datfr,datto char(10)
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
# Pick-list window handling (entry point).
################################################################################

function acctrans(xord)

define
  xord char(1),
  rowid integer
initialize ncrit to null
if xord is null then let ncrit.ord = "1"
else let ncrit.ord = xord
end if
let ncrit.acctcode = "*"
let ncrit.acctname = "*"
let ncrit.datfr = "*"
let ncrit.datto = "*"
let start = acctranc()
if start then let start = listopen("acctrans","","","",59) end if
if start then
  call listspitem("atrnr")
  call listspitem("dat")
  call listspitem("acctnr")
  call listmsg(stx("keyother"))
  call listsum(2)
  call listtransl("money14",2)
  call acctrans_setup()
  while true
    call listman() returning action,rowid
    case action
    when "other" call mreport()
    when "filter"
      if acctranc() then
        call acctrans_setup()
      end if
    when "enter"
      if acctran(rowid) then call listinit("") end if
    when "insert"
      if acctran("") then call listinit("") end if
    when "delete"
      if acctrand(rowid) then call listinit("") end if
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

function acctrans_setup()

define
  htxt char(48)
case ncrit.acctcode
when "*" let htxt = "** All accounts **"
otherwise let htxt = ncrit.acctcode clipped,"  ",ncrit.acctname
end case
call listhead(htxt,2,"","")
call listsetup(tables,items,format,filter,order,"")

end function

################################################################################
# Pick-list criteria editing.
################################################################################

function acctranc()

call winform("acctranc",6,9)
call disptitle("acctranc","f")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  let start = true
  input by name ncrit.ord thru ncrit.datto without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("acctranc","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    when "search"
      case
      when infield(acctcode)
        call accounts(get_fldbuf(acctcode),"1") returning i
        if i is not null then
          select acctnr,code,name
            into ncrit.acctnr,ncrit.acctcode,ncrit.acctname
            from account where rowid = i
          display by name ncrit.acctname attribute(reverse)
          let ocrit.acctcode = ncrit.acctcode
          let ocrit.acctname = ncrit.acctname
          next field acctcode
        end if
      when infield(acctname)
        call accounts(get_fldbuf(acctname),"2") returning i
        if i is not null then
          select acctnr,code,name
            into ncrit.acctnr,ncrit.acctcode,ncrit.acctname
            from account where rowid = i
          display by name ncrit.acctcode attribute(reverse)
          let ocrit.acctcode = ncrit.acctcode
          let ocrit.acctname = ncrit.acctname
          next field acctname
        end if
      end case
    end case
  before input
    if start then next field acctcode end if
  before field ord
    call msgtx("'1'=Account code. '2'=Date.")
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
  before field acctcode call msgtx("keysearch")
  after field acctcode
    call msgtx("")
    if not same(ncrit.acctcode,ocrit.acctcode) then
      if ncrit.acctcode is null then let ncrit.acctcode = "*" end if
      if ncrit.acctcode = "*" then let ncrit.acctname = "*"
      else
        call account_chk_code(ncrit.acctnr,ncrit.acctcode,ncrit.acctname)
          returning ncrit.acctnr,ncrit.acctcode,ncrit.acctname,i
        if not i then next field acctcode end if
      end if
      display by name ncrit.acctcode,ncrit.acctname attribute(reverse)
      let ocrit.acctcode = ncrit.acctcode
      let ocrit.acctname = ncrit.acctname
    end if
  before field acctname call msgtx("keysearch")
  after field acctname
    call msgtx("")
    if not same(ncrit.acctname,ocrit.acctname) then
      if ncrit.acctname is null then let ncrit.acctname = "*" end if
      if ncrit.acctname = "*" then let ncrit.acctcode = "*"
      else
        call account_chk_name(ncrit.acctnr,ncrit.acctcode,ncrit.acctname)
          returning ncrit.acctnr,ncrit.acctcode,ncrit.acctname,i
        if not i then next field acctname end if
      end if
      display by name ncrit.acctcode,ncrit.acctname attribute(reverse)
      let ocrit.acctcode = ncrit.acctcode
      let ocrit.acctname = ncrit.acctname
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
    let done = true
    let update = true
    call acctrancset()
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Setup of filter and order-by variables.
################################################################################

function acctrancset()

let items = "acctran.dat,acctran.amount,acctran.comment"
let tables = "acctran"
let format = " %-10s%14s  %-32s"
let filter = "1=1"
if ncrit.acctcode <> "*" then
  let filter = filter clipped," and acctran.acctnr='",ncrit.acctnr,"'"
end if
if ncrit.datfr <> "*" then
  let filter = filter clipped," and acctran.dat>='",ncrit.datfr,"'"
end if
if ncrit.datto <> "*" then
  let filter = filter clipped," and acctran.dat<='",ncrit.datto,"'"
end if
case ncrit.ord
when "2" let order = "acctran.acctnr,acctran.dat desc"
otherwise let order = "acctran.dat desc"
end case

end function

################################################################################
# Single record editing.
################################################################################

function acctran(xrowid)

define xrowid integer
call winform("acctran",7,2)
call disptitle("acctran","f")
let done = false
let update = false
while not done
  initialize nform to null
  if xrowid is null then
    initialize nrowid,nacctran to null
    if ncrit.acctcode <> "*" then let nacctran.acctnr = ncrit.acctnr end if
    if ncrit.datfr = ncrit.datto and ncrit.datfr <> "*" then
      let nacctran.dat = ncrit.datfr
    else let nacctran.dat = today
    end if
  else
    select rowid,* into nrowid,nacctran.* from acctran where rowid = xrowid
    if status <> 0 then call progerrq("acctran",status,"") end if
  end if
  if nacctran.acctnr is null then let start = false
  else
    select code,name into nform.acctcode,nform.acctname from account
      where acctnr = nacctran.acctnr
    let start = true
  end if
  let oacctran.* = nacctran.*
  let oform.* = nform.*
  input by name nform.acctcode,nform.acctname
    ,nacctran.dat,nacctran.amount,nacctran.comment
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
    when "help" call helpman("acctran","")
    when "exit" let done = true exit input
    when "search"
      case
      when infield(acctcode)
        call accounts(get_fldbuf(acctcode),"1") returning i
        if i is not null then
          select acctnr,code,name
            into nacctran.acctnr,nform.acctcode,nform.acctname
            from account where rowid = i
          if not same(nform.acctcode,oform.acctcode) then
            display by name nform.acctname attribute(reverse)
            let oform.acctcode = nform.acctcode
            let oform.acctname = nform.acctname
            end if
          next field acctcode
        end if
      when infield(acctname)
        call accounts(get_fldbuf(acctname),"2") returning i
        if i is not null then
          select acctnr,code,name
            into nacctran.acctnr,nform.acctcode,nform.acctname
            from account where rowid = i
          if not same(nform.acctcode,oform.acctcode) then
            display by name nform.acctcode attribute(reverse)
            let oform.acctcode = nform.acctcode
            let oform.acctname = nform.acctname
          end if
          next field acctname
        end if
      end case
    end case
  before input if start then next field dat end if
  before field acctcode call msgtx("keysearch")
  after field acctcode
    call msgtx("")
    if not same(nform.acctcode,oform.acctcode) then
      call account_chk_code(nacctran.acctnr,nform.acctcode,nform.acctname)
        returning nacctran.acctnr,nform.acctcode,nform.acctname,i
      if not i then next field acctcode end if
      display by name nform.acctcode,nform.acctname attribute(reverse)
      if not same(nform.acctcode,oform.acctcode) then
        let oform.acctcode = nform.acctcode
        let oform.acctname = nform.acctname
      end if
    end if
  before field acctname call msgtx("keysearch")
  after field acctname
    call msgtx("")
    if not same(nform.acctname,oform.acctname) then
      call account_chk_name(nacctran.acctnr,nform.acctcode,nform.acctname)
        returning nacctran.acctnr,nform.acctcode,nform.acctname,i
      if not i then next field acctname end if
      display by name nform.acctcode,nform.acctname attribute(reverse)
      if not same(nform.acctcode,oform.acctcode) then
        let oform.acctcode = nform.acctcode
        let oform.acctname = nform.acctname
      end if
    end if
  before field dat call msgtx("Date of the transaction.")
  after field dat
    call msgtx("")
    if nacctran.dat is null then
      let nacctran.dat = today
      display by name nacctran.dat attribute(reverse)
    end if
  after input
    call beginw()
    whenever error continue
    if nrowid is null then
      let nacctran.atrnr = 0
      insert into acctran values (nacctran.*)
    else
      update acctran set * = nacctran.* where rowid = nrowid
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

function acctrand(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  delete from acctran where rowid = xrowid
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
