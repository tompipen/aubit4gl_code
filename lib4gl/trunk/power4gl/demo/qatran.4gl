################################################################################
# Account transaction report.
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
  ncrit,ocrit,scrit record
    datfr,datto char(10)
  end record,
  nwinid,owinid char(16),
  nacctran record like acctran.*,
  nacctgrp record like acctgrp.*,
  naccount,oaccount record like account.*,
  ptxt char(1000),
  rep char(220),
  icnt,jcnt,scnt integer,
  iamnt,jamnt,samnt decimal,
  irow,jrow,srow integer,
  itxt,jtxt,stxt char(200),
  i,j,k integer,
  action char(10),
  dummy char(10),
  start,done,update char

################################################################################
# Main program (entry point).
################################################################################

function qatran()

initialize ncrit to null
let ncrit.datfr = "*"
let ncrit.datto = "*"
let owinid = null
if qatranc() then
  call qatran_open()
  call qatran_out()
  while true
    call reportman() returning action,i
    case action
    when "refresh" call qatran_out()
    when "filter"
      if qatranc() then
        call qatran_open()
        call qatran_out()
      end if
    when "exit" exit while
    end case
  end while 
  call reportclose()
end if

end function

################################################################################
# Criteria editing.
################################################################################

function qatranc()

call winform("qatranc",4,6)
call disptitle("qatranc","f")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  input by name ncrit.datfr,ncrit.datto without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("qatranc","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    end case
  before field datfr call msgtx("Date from. '*'=Unrestricted.")
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
  before field datto call msgtx("Date to. '*'=Unrestricted.")
  after field datto
    call msgtx("")
    if ncrit.datto is null then
      let ncrit.datto = "*"
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
  end input
end while
call winclose()
return (update)

end function

################################################################################
# Open report window.
################################################################################

function qatran_open()

let nwinid = "qatran"
if not same(nwinid,owinid) then
  if owinid is not null then call reportclose() end if
  call reportopen(nwinid,"")
  let owinid = nwinid
end if

end function

################################################################################
# Assemble report.
################################################################################

function qatran_out()

call reportinit("")
call reportcovput("BU",title("qatran","f",1))
call reportcovput("bu","")
call reportcovput("","CRITERIA:")
let rep = "Dates.......... ",ncrit.datfr clipped," - ",ncrit.datto
call reportcovput("",rep)
call reportcovput("","")
let ptxt = "select acctran.*,account.*,acctgrp.*"
  ," from acctran,outer (account,outer acctgrp)"
  ," where account.acctnr=acctran.acctnr and acctgrp.grpnr=account.grpnr"
if ncrit.datfr <> "*" then
  let ptxt = ptxt clipped," and acctran.dat>='",ncrit.datfr,"'"
end if
if ncrit.datto <> "*" then
  let ptxt = ptxt clipped," and acctran.dat<='",ncrit.datto,"'"
end if
let ptxt = ptxt clipped," order by acctgrp.name,acctgrp.grpnr"
  ,",account.code,account.acctnr,acctran.dat"
prepare pacctran from ptxt declare acctran cursor for pacctran
let scnt = null
let samnt = null
let srow = null
foreach acctran into nacctran.*,naccount.*,nacctgrp.*
  if scnt is null then
    let stxt = "REPORT TOTAL"
    let srow = reportfputrow("BU124bu",stxt,1,0)
    call reportline("B80b","¯",1,0,0)
  end if
  case
  when not same(naccount.grpnr,oaccount.grpnr)
    if scnt is not null then call qatrantotj() end if
    call qatrannewj()
  when not same(naccount.acctnr,oaccount.acctnr)
    if jcnt is not null then call qatrantoti() end if
    call qatrannewi()
  end case
  call qatranline()
  let oaccount.* = naccount.*
end foreach
if scnt is not null then
  call qatrantotj()
  let stxt = stxt clipped,column 61,samnt using "-----,---,--&.&&"
  call reportupd(srow,stxt)
end if
free pacctran
call reportsetup(true)

end function

################################################################################
# Start of primary group.
################################################################################

function qatrannewj()

if nacctgrp.name is null then let jtxt = "Ungrouped accounts"
else let jtxt = "Account group: ",nacctgrp.name
end if
if scnt is null then let i = 0
else let i = 1
end if
let jrow = reportfputrow("BU80bu",jtxt,i,5)
let scnt = add(scnt,1)
let jcnt = null
let jamnt = null
call qatrannewi()

end function

################################################################################
# Start of secondary group.
################################################################################

function qatrannewi()

let itxt = "  Account: ",naccount.name
let irow = reportfputrow("B80b",itxt,0,3)
let jcnt = add(jcnt,1)
let icnt = null
let iamnt = null

end function

################################################################################
# End of primary group.
################################################################################

function qatrantotj()

call qatrantoti()
let jtxt = jtxt[1,60],column 61,jamnt using "-----,---,--&.&&"
call reportupd(jrow,jtxt)
let samnt = add(samnt,jamnt)

end function

################################################################################
# End of secondary group.
################################################################################

function qatrantoti()

let itxt = itxt[1,60],column 61,iamnt using "-----,---,--&.&&"
call reportupd(irow,itxt)
let jamnt = add(jamnt,iamnt)

end function

################################################################################
# Transaction line.
################################################################################

function qatranline()

let rep = column 5,nacctran.dat,column 18,nacctran.comment
  ,column 61,nacctran.amount using "-----,---,--&.&&"
call reportput(rep)
let icnt = add(icnt,1)
let iamnt = add(iamnt,nacctran.amount)

end function

