################################################################################
# Interest rate summary report.
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
    grpnr like acctgrp.grpnr,
    grpname char(32)
  end record,
  nwinid,owinid char(16),
  nacctgrp record like acctgrp.*,
  nirate record like irate.*,
  oyr,nyr datetime year to year,
  drat array[360] of decimal,
  ptxt char(1000),
  rep char(220),
  i,j,k integer,
  action char(10),
  dummy char(10),
  start,done,update char

################################################################################
# Main function (entry point).
################################################################################

function qirsum(xgrpnr)

define xgrpnr integer
initialize ncrit to null
if xgrpnr is not null then
  select grpnr,name into ncrit.grpnr,ncrit.grpname
    from acctgrp where grpnr = xgrpnr
end if
let owinid = null
if ncrit.grpnr is null then let start = qirsumc()
else let start = true
end if
if start then
  call qirsum_open()
  call qirsum_out()
  while true
    call reportman() returning action,i
    case action
    when "refresh" call qirsum_out()
    when "filter"
      if qirsumc() then
        call qirsum_open()
        call qirsum_out()
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

function qirsumc()

call winform("qirsumc",4,6)
call disptitle("qirsumc","f")
let scrit.* = ncrit.*
let done = false
let update = false
while not done
  call msgtx("")
  let ocrit.* = ncrit.*
  let start = true
  input by name ncrit.grpname without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" let ncrit.* = scrit.* exit input
    when "help" call helpman("qirsumc","")
    when "exit" let ncrit.* = scrit.* let done = true exit input
    when "search"
      case
      when infield(grpname)
        call acctgrps(get_fldbuf(grpname)) returning i
        if i is not null then
          select grpnr,name into ncrit.grpnr,ncrit.grpname from acctgrp
            where rowid = i
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
  after input
    if ncrit.grpnr is null then
      call errtx("fldemp")
      next field grpname
    end if
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

function qirsum_open()

let nwinid = "qirsum"
if not same(nwinid,owinid) then
  if owinid is not null then call reportclose() end if
  call reportopen(nwinid,"")
  call reporthead("",ncrit.grpname,2)
  let owinid = nwinid
end if

end function

################################################################################
# Assemble report.
################################################################################

function qirsum_out()

define
  dat datetime day to day,
  mon datetime month to month,
  x char(8),
  curd smallint
call reportinit("")
select * into nacctgrp.* from acctgrp where grpnr = ncrit.grpnr
if status <> 0 then call progerrq("acctgrp",status,"") end if
let nirate.datch = today + 40
let oyr = nirate.datch + 1 units year
let nirate.datch = oyr
declare irate cursor for select * from irate
  where grpnr = ncrit.grpnr and datch < nirate.datch order by datch desc
let curd = null
foreach irate into nirate.*
  let nyr = nirate.datch
  while not same(nyr,oyr)
    if curd is not null then
      for curd = curd to 1 step -1 let drat[curd] = nirate.rate end for
      call qirsum_outyr()
    end if
    let oyr = oyr - 1 units year
    let curd = 360
    initialize drat to null
  end while
  let mon = nirate.datch
  let dat = nirate.datch
  let x = mon let i = x
  let x = dat let j = x
  if j > 30 then let j = 30 end if
  let i = (i - 1) * 30 + j
  for curd = curd to i step -1 let drat[curd] = nirate.rate end for
end foreach
if curd is not null then call qirsum_outyr() end if
call reportsetup(false)
free irate

end function

################################################################################
# Output a year.
################################################################################

function qirsum_outyr()

define
  arat decimal,
  mrat array[12] of decimal,
  mbrt array[12] of char(1),
  mnrd,anrd smallint
let arat = 0
let anrd = 0
for i = 1 to 12
  let mrat[i] = null
  let mbrt[i] = null
  let mnrd = 0
  for j = 1 to 30
    let k = (i - 1) * 30 + j
    if drat[k] is not null then
      if mrat[i] is null then let mrat[i] = drat[k]
      else let mrat[i] = mrat[i] + drat[k]
      end if
      if j > 1 then
        if drat[k] <> drat[k-1] then let mbrt[i] = "*" end if
      end if
      let mnrd = mnrd + 1
    end if
  end for
  if mrat[i] is not null then let arat = arat + mrat[i] end if
  let anrd = anrd + mnrd
  let mrat[i] = mrat[i] / mnrd
end for
let arat = arat / anrd
let rep = oyr,column 8
  ,formatnum(mrat[1],9,2,""),mbrt[1]
  ,column 18,formatnum(mrat[2],9,2,""),mbrt[2]
  ,column 28,formatnum(mrat[3],9,2,""),mbrt[3]
  ,column 38,formatnum(mrat[4],9,2,""),mbrt[4]
  ,column 48,formatnum(mrat[5],9,2,""),mbrt[5]
  ,column 58,formatnum(mrat[6],9,2,""),mbrt[6]
  ,column 68,formatnum(mrat[7],9,2,""),mbrt[7]
  ,column 78,formatnum(mrat[8],9,2,""),mbrt[8]
  ,column 88,formatnum(mrat[9],9,2,""),mbrt[9]
  ,column 98,formatnum(mrat[10],9,2,""),mbrt[10]
  ,column 108,formatnum(mrat[11],9,2,""),mbrt[11]
  ,column 118,formatnum(mrat[12],9,2,""),mbrt[12]
  ,column 133,oyr,column 140,formatnum(arat,9,2,"")
call reportfput("B4b128B4b",rep,0,0)

end function
