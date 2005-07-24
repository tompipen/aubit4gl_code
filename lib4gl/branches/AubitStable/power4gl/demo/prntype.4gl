################################################################################
# Maintenance program for the 'prntype' table.
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
  nprntype,oprntype record like prntype.*,
  nprnadj array[100] of record
    adjcode like prnadj.adjcode,
    adjstr like prnadj.adjstr
  end record,
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

function prntype_chk_name(xprntnr,xname)

define
  xprntnr like prntype.prntnr,
  xname like prntype.name,
  txt char(80)
if xname is null then return "","",true end if
let txt = xname clipped,"*"
whenever error continue
select prntnr,name into xprntnr,xname from prntype where name matches txt
whenever error stop
return xprntnr,xname,readcheck("")

end function

################################################################################
# Pick-list window handling (entry point).
################################################################################

function prntypes(finder)

define
  finder char(60),
  rowid integer
if finder = " " then let finder = null end if
call prntypecset()
if listopen("prntypes","","","","") then
  call listspitem("prntnr")
  call listsetup(tables,items,format,filter,order,finder)
  while true
    call listman() returning action,rowid
    case action
    when "enter"
      if prntype(rowid) then call listinit("") end if
    when "insert"
      if prntype("") then call listinit("") end if
    when "delete"
      if prntyped(rowid) then call listinit("") end if
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

function prntypecset()

let items = "name"
let tables = "prntype"
let format = "%-32s"
let filter = ""
let order = "name"

end function

################################################################################
# Single record editing.
################################################################################

function prntype(xrowid)

define
  xrowid integer,
  fsect char(16)
call winform("prntype",13,2)
call disptitle("prntype","f")
declare prnadj cursor for select adjcode,adjstr from prnadj
  where prntnr = nprntype.prntnr order by adjcode
let fsect = null
let done = false
let update = false
while not done
  if fsect is null then
    initialize nprnadj to null
    if xrowid is null then
      initialize nprntype,nrowid to null
      let start = false
    else
      select rowid,* into nrowid,nprntype.* from prntype where rowid = xrowid
      if status <> 0 then call progerrq("prntype",status,"") end if
      let i = 1
      foreach prnadj into nprnadj[i].* let i = i + 1 end foreach
      let start = true
    end if
    let fsect = "prntype"
    let oprntype.* = nprntype.*
    for i = 1 to 14
      if nprnadj[i].adjcode is null and i > 1 then
        display nprnadj[i].* to prnadj[i].*
      else display nprnadj[i].* to prnadj[i].* attribute(reverse)
      end if
    end for
  end if
  case fsect
  when "prntype"
    input by name nprntype.name,nprntype.pipe without defaults
    on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
      case keytransl(fgl_lastkey())
      when "prevpage"
        let i = listprevid(nrowid)
        if i is not null then let xrowid = i let fsect = null exit input end if
      when "nextpage"
        let i = listnextid(nrowid)
        if i is not null then let xrowid = i let fsect = null exit input end if
      when "refresh" let fsect = null exit input
      when "toggle" let fsect = "prnadj" exit input
      when "help" call helpman("prntype","")
      when "other" call mreport()
      when "exit" let done = true exit input
      end case
    before input if start then next field pipe end if
    after field name
      if not same(nprntype.name,oprntype.name) then
        if nrowid is null then
          select count(*) into i from prntype
            where name = nprntype.name
        else
          select count(*) into i from prntype
            where name = nprntype.name and rowid <> nrowid
        end if
        if i <> 0 then
          call errtx("exists")
          next field name
        end if
        let oprntype.name = nprntype.name
      end if
    after field pipe
      if keynext() then
        let fsect = "prnadj"
        exit input
      end if
    after input let fsect = "*"
    end input
  when "prnadj"
    for i = 99 to 1 step -1
      if nprnadj[i].adjcode is not null then exit for end if
    end for
    call set_count(i)
    input array nprnadj without defaults from prnadj.*
    on key (help,escape,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
      case keytransl(fgl_lastkey())
      when "refresh" let fsect = null exit input
      when "toggle" let fsect = "prntype" exit input
      when "help" call helpman("prntype","")
      when "other" call mreport()
      when "exit" let done = true exit input
      end case
    before row
      let j = arr_curr()
    after row
      if j = 1 then
        if keyprev() then
          let fsect = "prntype"
          let start = true
          exit input
        end if
      end if
      let k = arr_count()
    before field adjcode
      case keymap(fgl_lastkey())
      when "insert"
        initialize nprnadj[j] to null
        display nprnadj[j].* to prnadj[j].* attribute(reverse)
      when "delete"
        initialize nprnadj[k+1] to null
      end case
    after field adjcode
      for i = 1 to k
        if i <> j then
          if nprnadj[i].adjcode = nprnadj[j].adjcode then
            call errtx("exists")
            next field adjcode
          end if
        end if
      end for
    before field adjstr
      call msgtx("Use '^' for control characters, e.g. '^[' for 'esc'.")
    after field adjstr call msgtx("")
    after input let fsect = "*"
    end input
  otherwise exit while
  end case
  if fsect = "*" then
    call beginw()
    whenever error continue
    if nrowid is null then
      let nprntype.prntnr = 0
      insert into prntype values (nprntype.*)
      let nprntype.prntnr = sqlca.sqlerrd[2]
    else
      delete from prnadj where prntnr = nprntype.prntnr
      if sqlca.sqlcode = 0 then
        update prntype set * = nprntype.* where rowid = nrowid
      end if
    end if
    for i = 1 to 99
      if sqlca.sqlcode <> 0 then exit for end if
      if nprnadj[i].adjcode is not null then
        insert into prnadj values (nprntype.prntnr,nprnadj[i].*)
      end if
    end for
    whenever error stop
    let update = true
    if assessw("") then let done = true
    else let fsect = "prntype"
    end if
  end if
end while
call winclose()
return (update)

end function

################################################################################
# Single record deletion.
################################################################################

function prntyped(xrowid)

define xrowid integer
if xrowid is null then return false end if
let update = false
while goahead("delete",8,15)
  call beginw()
  whenever error continue
  select * into nprntype.* from prntype where rowid = xrowid
  if sqlca.sqlcode = 0 then
    delete from prnadj where prntnr = nprntype.prntnr
  end if
  if sqlca.sqlcode = 0 then
    delete from prntype where rowid = xrowid
  end if
  whenever error stop
  let update = true
  if assessw("") then exit while end if
end while
return (update)

end function
