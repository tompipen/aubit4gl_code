################################################################################
# General menu program (independent of system and database).
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

define
  rec smallint,
  menuname array[10] of char(80),
  menutitle array[10,4] of char(80),
  menuwin array[10] of char,
  modlabel array[10,16] of char(80),
  modact array[10,16] of char,
  row,col,cur,use,tot,tit,scr array[10] of smallint,
  ptxt char(60)

################################################################################
# Initialization of menu window.
################################################################################

function menuopen(mname,r,c)

define
  mname char(80),
  r,c,i smallint
if rec > 9 then
  call pause("maxmenu",9,5)
  return (false)
end if
if rec > 0 then let rec = rec + 1
else let rec = 1
end if
let menuname[rec] = mname
let scr[rec] = getlines()
let tit[rec] = 1
for i = 1 to 4
  let menutitle[rec,i] = rawtitle(mname,"m",i)
  if menutitle[rec,i] is not null then
    let menutitle[rec,i] = " ",menutitle[rec,i]
    let tit[rec] = i
  end if
end for
let menuwin[rec] = false
let tot[rec] = 0
if r is null then
  if rec = 1 then let row[rec] = 2
  else let row[rec] = row[rec - 1] + tit[rec - 1] + 1
  end if
else let row[rec] = r + 1
end if
if c is null then
  if rec = 1 then let col[rec] = 2
  else let col[rec] = col[rec - 1] + 1
  end if
else let col[rec] = c + 1
end if
return (true)

end function

################################################################################
# Addition of normal menu item.
################################################################################

function menuline(mname,mtype)

define
  mname char(80),
  mtype char(1)
call menufline(mname,mtype,true)

end function

################################################################################
# Addition of menu item with full controls.
################################################################################

function menufline(mname,mtype,mact)

define
  mname char(80),
  mtype char(1),
  mact char(100),
  mc char(1),
  i smallint
let tot[rec] = tot[rec] + 1
let i = tot[rec]
if i < 10 then let mc = i
else
  case i
  when 10 let mc = "a"
  when 11 let mc = "b"
  when 12 let mc = "c"
  when 13 let mc = "d"
  when 14 let mc = "e"
  when 15 let mc = "f"
  when 16 let mc = "g"
  otherwise let mc = "?"
  end case
end if
let modlabel[rec,i] = label(mname,mtype)
let modlabel[rec,i] = " ",mc,". ",modlabel[rec,i]
if mtype = "m" then let modlabel[rec,i] = modlabel[rec,i] clipped,"..." end if
if mact is null then let modact[rec,i] = false
else let modact[rec,i] = mact
end if

end function

################################################################################
# Initial display of menu after having been setup.
################################################################################

function menusetup()

define
  r,c smallint,
  txt char(80),
  nc,nr,i,len smallint
for i = 1 to tot[rec] step 1
  if modact[rec,i] then exit for end if
end for
if i > tot[rec] then let cur[rec] = null
else let cur[rec] = i
end if
let use[rec] = null
let r = row[rec]
let c = col[rec]
let ptxt = " ",stx("menu")
let nc = length(ptxt) + 1
let nr = tit[rec] + tot[rec] + 3
for i = 1 to tit[rec]
  let len = length(menutitle[rec,i]) + 1
  if len > nc then let nc = len end if
  let menutitle[rec,i] = trim(menutitle[rec,i],"|")
end for
for i = 1 to tot[rec]
  let len = length(modlabel[rec,i]) + 1
  if len > nc then let nc = len end if
end for
if r < 2 then let r = 2 end if
if c < 2 then let c = 2 end if
if r + nr > scr[rec] - 1 then let r = scr[rec] - 1 - nr end if
if c + nc > 78 + 1 then let c = 78 - nc + 1 end if
call winopen(catstr("menu-",menuname[rec]),r,c,nr,nc)
let menuwin[rec] = true
for i = 1 to tit[rec]
  call disp(center(menutitle[rec,i],nc),"titlefirst",i,1)
end for
for i = 1 to tot[rec] call menushowline(i) end for
let i = i + tit[rec] + 2

end function

################################################################################
# menu handling function.
################################################################################

function menuman()

define
  mc char(1),
  i,j,val smallint
while true
  if use[rec] is not null then
    let use[rec] = null
    call menushowline(cur[rec])
  end if
  let mc = null
  let val = null
  call dispmsg(ptxt)
  let i = getkey()
  if i > 32 and i < 256 then let mc = ascii(i) else let mc = null end if
  case keytransl(i)
  when "up"
    if cur[rec] > 1 then
      for i = cur[rec] - 1 to 1 step -1
        if modact[rec,i] then exit for end if
      end for
      if i >= 1 then
        let j = cur[rec]
        let cur[rec] = i
        call menushowline(j)
        call menushowline(i)
      end if
    end if
  when "down"
    if cur[rec] < tot[rec] then
      for i = cur[rec] + 1 to tot[rec] step 1
        if modact[rec,i] then exit for end if
      end for
      if i <= tot[rec] then
        let j = cur[rec]
        let cur[rec] = i
        call menushowline(j)
        call menushowline(i)
      end if
    end if
  when "home"
    if cur[rec] <> 1 and tot[rec] > 0 then
      for i = 1 to tot[rec] step 1
        if modact[rec,i] then exit for end if
      end for
      if i >= 1 then
        let j = cur[rec]
        let cur[rec] = i
        call menushowline(j)
        call menushowline(i)
      end if
    end if
  when "end"
    if cur[rec] <> tot[rec] and tot[rec] > 0 then
      for i = tot[rec] to 1 step -1
        if modact[rec,i] then exit for end if
      end for
      if i <= tot[rec] then
        let j = cur[rec]
        let cur[rec] = i
        call menushowline(j)
        call menushowline(i)
      end if
    end if
  when "help" call helpman("","menu")
  when "enter" let val = cur[rec]
  when "accept" return 0
  when "exit" return 0
  end case
  if mc = "!" then
    call bang()
    let mc = null
  end if
  if mc is not null then
    if mc >= "1" and mc <= "9" then let val = mc
    else
      case lower(mc)
      when "a" let val = 10
      when "b" let val = 11
      when "c" let val = 12
      when "d" let val = 13
      when "e" let val = 14
      when "f" let val = 15
      when "g" let val = 16
      otherwise let val = 9999
      end case
    end if
  end if
  call dispmsg("")
  if val is not null then
    case
    when val > tot[rec] call errtx("nomenu")
    when not modact[rec,val] call errtx("nomenu")
    otherwise
      let i = cur[rec]
      let cur[rec] = val
      let use[rec] = val
      call menushowline(i)
      if i <> val then call menushowline(val) end if
      return (val)
    end case
  end if
end while

end function

################################################################################
# Display of item line.
################################################################################

function menushowline(i)

define i,j smallint

let j = i + tit[rec] + 1
if modact[rec,i] then
  case i
  when use[rec] call disp(modlabel[rec,i],"listmark",j,1)
  when cur[rec] call disp(modlabel[rec,i],"listcurr",j,1)
  otherwise call disp(modlabel[rec,i],"list",j,1)
  end case
else call disp(modlabel[rec,i],"listinact",j,1)
end if

end function

################################################################################
# Closing of menu window.
################################################################################

function menuclose()

if menuwin[rec] then call winclose() end if
let rec = rec - 1

end function
