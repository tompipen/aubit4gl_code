################################################################################
# General report generating program (independent of system and database).
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
  modname char(18),
  mtform array[8] of char(32),
  mtitle array[8] of char(512),
  skiphead char,
  defprinter char(32),
  uname char(32),
  uid char(32),
  utime datetime year to minute,
  repsect char(10),
  rline record
    id integer,
    form char(32),
    text char(512),
    skip,need smallint
  end record,
  cline record
    id integer,
    form char(32),
    text char(512)
  end record,
  screenline array[64] of record
    id integer,
    form char(32),
    text char(512),
    skip,need smallint
  end record,
  screencovl array[64] of record
    id integer,
    form char(32),
    text char(512)
  end record,
  dopr char,
  ptxt char(1024),
  dummy char(32),
  setpaglen,paglen,curlin smallint,
  curpag integer,
  prsetup,prreset char(64),
  titlines,totlines,repwidth,scrlines smallint,
  linepos,curline,useline,covlpos,curcovl,usecovl smallint,
  totrows,pagerow,totcovr,pagecovr integer,
  find,i integer

################################################################################
# Opening of report window and title and other initializations (simple version).
################################################################################

function reportopen(mname,width)

define
  mname char(64),
  width smallint
if not reportfopen(mname,width) then
  call progerrq("reportopen",mname,"Unable to open report.")
end if

end function

################################################################################
# Opening of report window and title and other initializations (full version).
################################################################################

function reportfopen(mname,width)

define
  mname char(64),
  width smallint
if rec >= 1 then
  call pause("maxreport",6,30)
  return false
end if
if rec > 0 then let rec = rec + 1
else let rec = 1
end if
let modname = mname
let defprinter = null
let skiphead = true
let setpaglen = null
if width is null then let repwidth = 0
else let repwidth = width
end if
let scrlines = getlines()
let scrlines = scrlines - 2
if not same(jobtype(),"b") then
  call winopen(catstr("report-",mname),1,1,scrlines+1,80)
end if
let titlines = 0
for i = 1 to 8
  let mtform[i] = "Biu"
  let mtitle[i] = rawtitle(mname,"f",i)
  if mtitle[i] is not null then let titlines = i end if
  if length(mtitle[i]) > repwidth then let repwidth = length(mtitle[i]) end if
  let mtitle[i] = trim(mtitle[i],"|")
end for
if titlines > 0 then
  if repwidth < 64 then let repwidth = 64 end if
else
  if repwidth < 32 then let repwidth = 32 end if
end if
if repwidth > 512 then let repwidth = 512 end if
if mtitle[1] is null then let mtitle[1] = " " end if
let totlines = scrlines - titlines
if not same(jobtype(),"b") then
  call reportshowhead()
end if
return true

end function

################################################################################
# Additional title information.
################################################################################

function reporthead(frm,tit,lin)

define
  frm char(32),
  tit char(512),
  lin smallint
if lin > titlines then let lin = titlines end if
if frm is null then let frm = "Biu" end if
let mtform[lin] = frm
let mtitle[lin] = tit

end function

################################################################################
# Decision whether the second title line should skip a line or not.
################################################################################

function reportskiphead(skip)

define skip char
if skip is null then let skip = skiphead end if
let skiphead = skip

end function

################################################################################
# Setup of default printer to be used in the report.
################################################################################

function reportprinter(printer)

define printer char(32)
let defprinter = printer

end function

################################################################################
# Procurement of report tables and wait message.
################################################################################

function reportinit(msg)

define msg char(32)
whenever error continue
if not same(jobtype(),"b") then
  if msg is null then let msg = "reporting" end if
  call msgopen(msg)
end if
call reportcleanup()
create temp table repcover
  (nr serial, form char(32), text char(512)) with no log
if sqlca.sqlcode <> 0 then call progerrq("repinit: create",status,"cover") end if
create temp table replist
  (nr serial unique
  ,form char(32), text char(512), skip smallint, need smallint) with no log
if sqlca.sqlcode <> 0 then call progerrq("repinit: create",status,"list") end if
let totrows = 0
let totcovr = 0
declare repcovget scroll cursor with hold for select * from repcover
  order by nr
if sqlca.sqlcode <> 0 then call progerrq("repinit: declare",status,"cov") end if
declare replstget scroll cursor with hold for select * from replist
  where need >= 0 order by nr
if sqlca.sqlcode <> 0 then call progerrq("repinit: declare",status,"lst") end if
let uname = right(sysname(),32)
let uid = right(sysid(),32)
call timerset() returning utime,dummy
whenever error stop

end function

################################################################################
# Insertion of a full width line with a repeated string in the report table.
################################################################################

function reportline(xform,xtext,len,xskip,xneed)

define
  xform char(32),
  xtext char(10),
  len,xskip,xneed smallint
call reportfput(xform,repchar(xtext,len,repwidth),xskip,xneed)

end function

################################################################################
# Simple insertion of a report line in the report table.
################################################################################

function reportput(xtext)

define xtext char(512)
call reportputrow(xtext) returning dummy

end function

################################################################################
# Insertion of a report line in the report table.
################################################################################

function reportfput(xform,xtext,xskip,xneed)

define
  xform char(32),
  xtext char(512),
  xskip,xneed smallint
call reportfputrow(xform,xtext,xskip,xneed) returning dummy

end function

################################################################################
# Simple insertion of a report line in the report table, returning the row nr.
################################################################################

function reportputrow(xtext)

define xtext char(512)
return (reportfputrow("",xtext,0,0))

end function

################################################################################
# Insertion of a report line in the report table, returning the row nr.
################################################################################

function reportfputrow(xform,xtext,xskip,xneed)

define
  xform char(32),
  xtext char(512),
  xskip,xneed smallint
whenever error continue
if xtext is null then let xtext = " " end if
if xskip is null then let xskip = 0 end if
if xneed is null then let xneed = 0 end if
insert into replist values(0,xform,xtext,xskip,xneed)
if sqlca.sqlcode <> 0 then call progerrq("repfputrow: insert",status,xtext) end if
let totrows = totrows + 1
whenever error stop
return sqlca.sqlerrd[2]

end function

################################################################################
# Simple update of a report line in the report table.
################################################################################

function reportupd(xnr,xtext)

define
  xnr integer,
  xtext char(512)
whenever error continue
if xtext is null then let xtext = " " end if
update replist set text = xtext where nr = xnr
if sqlca.sqlcode <> 0 then call progerrq("repupd: update",status,xtext) end if
whenever error stop

end function

################################################################################
# Insertion of time information to report cover page table.
################################################################################

function reportcovtime()

define
  timenew datetime year to minute,
  timediff interval day(5) to fraction,
  diff1 interval day to minute,
  diff2 interval hour to second
call timerset() returning timenew,timediff
let ptxt = upper(word("worktime")),":"
case
when timediff < 1 units minute
  let ptxt = ptxt clipped," ",left(sectime(timediff))," ",word("sec")
when timediff < 1 units day
  let diff2 = timediff
  let ptxt = ptxt clipped," ",left(diff2)
otherwise
  let diff1 = timediff
  let ptxt = ptxt clipped," ",left(diff1)
end case
let ptxt = ptxt clipped,column 30,upfword("began"),":",column 39,utime
call reportcovput("",ptxt)
let ptxt = column 30,upfword("ended"),":",column 39,timenew
call reportcovput("",ptxt)

end function

################################################################################
# Insertion of text file to report cover page table.
################################################################################

function reportcovtext(fname,beg,end)

define
  fname char(64),
  beg,end,cur smallint,
  fp,ec integer
let fname = checkpath(fgl_getenv("SYSTEMDIR")) clipped,fname clipped
let fp = fgl_fopen(fname,"r")
if fp <> 0 then
  let cur = 0
  call fgl_fgets(fp) returning ec,ptxt
  while ec = 0
    if iswhitesp(ptxt) then let cur = cur + 1 end if
    call fgl_fgets(fp) returning ec,ptxt
  end while
  call fgl_fclose(fp)
  if beg is null then let beg = 0 end if
  if beg < 0 then let beg = cur + beg end if
  if beg < 0 then let beg = 0 end if
  if end is null then let end = cur end if
  if end < 0 then let end = cur + end end if
  if end < 0 then let end = 0 end if
  if end < beg then let end = beg end if
  let fp = fgl_fopen(fname,"r")
  let cur = 0
  call fgl_fgets(fp) returning ec,ptxt
  while ec = 0
    if iswhitesp(ptxt) then
      let cur = cur + 1
      let ptxt = null
    end if
    if cur >= beg and cur <= end then call reportcovput("",ptxt) end if
    call fgl_fgets(fp) returning ec,ptxt
  end while
  call fgl_fclose(fp)
end if

end function

################################################################################
# Insertion of a cover page line in the report cover page table.
################################################################################

function reportcovput(xform,xtext)

define
  xform char(32),
  xtext char(512)
whenever error continue
if xtext is null then let xtext = " " end if
insert into repcover values(0,xform,xtext)
if sqlca.sqlcode <> 0 then call progerrq("repcovput: insert",status,"cover") end if
let totcovr = totcovr + 1
whenever error stop

end function

################################################################################
# Closing of message window and display of first report screen.
################################################################################

function reportsetup(xdopr)

define xdopr char
if xdopr is null then let dopr = true
else let dopr = xdopr
end if
whenever error continue
open replstget
if sqlca.sqlcode <> 0 then call progerrq("repsetup: open",status,"lst") end if
open repcovget
if sqlca.sqlcode <> 0 then call progerrq("repsetup: open",status,"cov") end if
whenever error stop
if not same(jobtype(),"b") then
  let useline = null
  let curline = 1
  let pagerow = 1
  let linepos = 1
  let usecovl = null
  let curcovl = 1
  let pagecovr = 1
  let covlpos = 1
  call msgclose()
  if totrows > 0 or totcovr = 0 then
    let repsect = "report"
    call reportshowhead()
    call reportreadpage()
  else
    let repsect = "cover"
    call reportreadcovp()
  end if
end if

end function

################################################################################
# Force the use of a printer page length value. If the value is null, the
# page length contained in the printer setup is used.
################################################################################

function reportpaglen(xpaglen)

define xpaglen smallint
let setpaglen = xpaglen

end function

################################################################################
# Report window handling.
################################################################################

function reportman()

define
  c char(1),
  ptxt,ktxt char(80),
  action char(10),
  prname char(32),
  pfile char(32),
  maddr char(48),
  msubj char(48)
if same(jobtype(),"b") then
  call getjobval() returning dummy,dummy,dummy,prname,pfile,maddr,msubj,dummy
  if prname is not null then
    call reportprinter(prname)
    call reportprint() returning dummy
  end if
  if maddr is not null then
    call reportpmail(maddr,msubj)
  end if
  if pfile is not null then
    call reportpfile(pfile)
  end if
  return "exit",0
end if
let find = null
let action = null
while action is null
  if repsect = "report" then
    case
    when totrows = 0 let ptxt = stx("nolist")
    when pagerow = 1
      if totrows <= totlines then let ptxt = stx("onlypg")
      else let ptxt = stx("firstpg")
      end if
    when pagerow > totrows let ptxt = stx("beyond")
    when pagerow > totrows - totlines let ptxt = stx("lastpg")
    otherwise let ptxt = " "
    end case
    if totrows <> 0 then
      let ptxt = ptxt clipped," (",pagerow + curline - 1 using "<<<<<<<<"
        ,"/",totrows using "<<<<<<<<",")"
    end if
    if useline is not null then
      let useline = null
      call reportshowline(curline)
    end if
    if find is not null then
      let ptxt = "[",find using "<<<<<<<<","] ",ptxt
    end if
    if totcovr > 0 then
      let ktxt = stx("keyrepcov")
      let i = length(ktxt)
      if i + length(ptxt) < 80 then let ptxt[80-i,80] = ktxt end if
    end if
  else
    case
    when pagecovr = 1
      if totcovr <= scrlines then let ptxt = stx("onlypg")
      else let ptxt = stx("firstpg")
      end if
    when pagecovr > totcovr let ptxt = stx("beyond")
    when pagecovr > totcovr - scrlines let ptxt = stx("lastpg")
    otherwise let ptxt = " "
    end case
    let ptxt = ptxt clipped," (",pagecovr + curcovl - 1 using "<<<<<<<<"
      ,"/",totcovr using "<<<<<<<<",")"
    if usecovl is not null then
      let usecovl = null
      call reportshowcovl(curcovl)
    end if
    if find is not null then
      let ptxt = "[",find using "<<<<<<<<","] ",ptxt
    end if
    if totrows > 0 then
      let ktxt = stx("keyreport")
      let i = length(ktxt)
      if i + length(ptxt) < 80 then let ptxt[80-i,80] = ktxt end if
    end if
  end if
  call dispmsg(ptxt)
  case keytransl(getkey())
  when "left"
    if repsect = "report" then
      if linepos > 1 then
        let linepos = linepos - 16
        if linepos < 1 then let linepos = 1 end if
        call reportmovepage()
      end if
    else
      if covlpos > 1 then
        let covlpos = covlpos - 16
        if covlpos < 1 then let covlpos = 1 end if
        call reportmovecovp()
      end if
    end if
  when "right"
    if repsect = "report" then
      let i = repwidth - 80 + 1
      if linepos < i then
        let linepos = linepos + 16
        if linepos > i then let linepos = i end if
        call reportmovepage()
      end if
    else
      let i = repwidth - 80 + 1
      if covlpos < i then
        let covlpos = covlpos + 16
        if covlpos > i then let covlpos = i end if
        call reportmovecovp()
      end if
    end if
  when "tab"
    if repsect = "report" then
      let i = repwidth - 80 + 1
      if linepos < i then
        let linepos = i
        call reportmovepage()
      end if
    else
      let i = repwidth - 80 + 1
      if covlpos < i then
        let covlpos = i
        call reportmovecovp()
      end if
    end if
  when "sh-tab"
    if repsect = "report" then
      if linepos > 1 then
        let linepos = 1
        call reportmovepage()
      end if
    else
      if covlpos > 1 then
        let covlpos = 1
        call reportmovecovp()
      end if
    end if
  when "up"
    if repsect = "report" then
      if pagerow + curline - 1 > 1 then
        if curline > 1 then
          let curline = curline - 1
          call reportshowline(curline + 1)
          call reportshowline(curline)
        else
          for i = totlines to 1 + 1 step -1
            let screenline[i].* = screenline[i - 1].*
            call reportshowline(i)
          end for
          let pagerow = pagerow - 1
          fetch absolute pagerow replstget into screenline[1].*
          call reportshowline(1)
        end if
      end if
    else
      if pagecovr + curcovl - 1 > 1 then
        if curcovl > 1 then
          let curcovl = curcovl - 1
          call reportshowcovl(curcovl + 1)
          call reportshowcovl(curcovl)
        else
          for i = scrlines to 1 + 1 step -1
            let screencovl[i].* = screencovl[i - 1].*
            call reportshowcovl(i)
          end for
          let pagecovr = pagecovr - 1
          fetch absolute pagecovr repcovget into screencovl[1].*
          call reportshowcovl(1)
        end if
      end if
    end if
  when "down"
    if repsect = "report" then
      if pagerow + curline - 1 < totrows then
        if curline < totlines then
          let curline = curline + 1
          call reportshowline(curline - 1)
          call reportshowline(curline)
        else
          for i = 1 to totlines - 1 step 1
            let screenline[i].* = screenline[i + 1].*
            call reportshowline(i)
          end for
          let i = pagerow + totlines
          let pagerow = pagerow + 1
          fetch absolute i replstget into screenline[totlines].*
          call reportshowline(totlines)
        end if
      end if
    else
      if pagecovr + curcovl - 1 < totcovr then
        if curcovl < scrlines then
          let curcovl = curcovl + 1
          call reportshowcovl(curcovl - 1)
          call reportshowcovl(curcovl)
        else
          for i = 1 to scrlines - 1 step 1
            let screencovl[i].* = screencovl[i + 1].*
            call reportshowcovl(i)
          end for
          let i = pagecovr + scrlines
          let pagecovr = pagecovr + 1
          fetch absolute i repcovget into screencovl[scrlines].*
          call reportshowcovl(scrlines)
        end if
      end if
    end if
  when "prevpage"
    if repsect = "report" then
      if pagerow > 1 then
        let pagerow = pagerow - totlines
      else
        let curline = 1
        let pagerow = 1
      end if
      call reportreadpage()
    else
      if pagecovr > 1 then
        let pagecovr = pagecovr - scrlines
      else
        let curcovl = 1
        let pagecovr = 1
      end if
      call reportreadcovp()
    end if
  when "nextpage"
    if repsect = "report" then
      if pagerow + totlines - 1 < totrows then
        let pagerow = pagerow + totlines
      else
        let curline = totlines
        let pagerow = totrows - totlines + 1
      end if
      call reportreadpage()
    else
      if pagecovr + scrlines - 1 < totcovr then
        let pagecovr = pagecovr + scrlines
      else
        let curcovl = scrlines
        let pagecovr = totcovr - scrlines + 1
      end if
      call reportreadcovp()
    end if
  when "home"
    if repsect = "report" then
      let curline = 1
      let pagerow = 1
      call reportreadpage()
    else
      let curcovl = 1
      let pagecovr = 1
      call reportreadcovp()
    end if
  when "end"
    if repsect = "report" then
      let curline = totlines
      let pagerow = totrows - totlines + 1
      call reportreadpage()
    else
      let curcovl = scrlines
      let pagecovr = totcovr - scrlines + 1
      call reportreadcovp()
    end if
  when "print" if reportprint() then let dopr = false end if
  when "pfile" call reportpfile("")
  when "pmail" call reportpmail(defemail(),"")
  when "ppipe" call reportppipe()
  when "accept" if reportprint() then let action = "exit" end if
  when "help" call helpman(modname,"report")
  when "toggle"
    if repsect = "report" then
      if totcovr > 0 then
        let repsect = "cover"
        call winclear()
        call reportreadcovp()
      end if
    else
      if totrows > 0 then
        let repsect = "report"
        call winclear()
        call reportshowhead()
        call reportreadpage()
      end if
    end if
  when "refresh" let action = "refresh"
  when "prevset" let action = "prevset"
  when "nextset" let action = "nextset"
  when "filter" let action = "filter"
  when "other" let action = "other"
  when "enter" let action = "enter"
  when "exit"
    if dopr then if sure("noprint",8,8) then let action = "exit" end if
    else let action = "exit"
    end if
  end case
  let i = fgl_lastkey()
  if i < 512 then let c = ascii(i) else let c = null end if
  if c = "!" then
    let c = null
    call bang()
  end if
  if repsect = "report" and action is null and c matches "[0123456789]" then
    case
    when find is null let find = c
    when find <= 99999999 let find = find * 10 + c
    end case
    call reportfindpage()
  else let find = null
  end if
end while
let useline = curline
if repsect = "report" then call reportshowline(curline)
else call reportshowcovl(curcovl)
end if
return action, (pagerow + curline - 1)

end function

################################################################################
# Display of report head.
################################################################################

function reportshowhead()

define mtitle1 char(80)
let mtitle1 = center(mtitle[1],80)
for i = 1 to titlines step 1
  case i
  when 1 call disp(mtitle1,"titlefirst",1,1)
  when titlines call disp(mtitle[i],"titlelast",i,1)
  otherwise call disp(mtitle[i],"title",i,1)
  end case
end for

end function

################################################################################
# Horizontal repositioning of report page.
################################################################################

function reportmovepage()

define title char(512)
for i = 2 to titlines
  let title = mtitle[i][linepos,512]
  case i
  when titlines call disp(title,"titlelast",i,1)
  otherwise call disp(title,"title",i,1)
  end case
end for
for i = 1 to totlines call reportshowline(i) end for

end function

################################################################################
# Horizontal repositioning of report cover page.
################################################################################

function reportmovecovp()

for i = 1 to scrlines call reportshowcovl(i) end for

end function

################################################################################
# Retrieval of text line by row number.
################################################################################

function reportget(row)

define row integer
whenever error continue
fetch absolute row replstget into rline.*
if sqlca.sqlcode <> 0 then let rline.text = null end if
return rline.text
whenever error stop

end function

################################################################################
# Closing of report window and obliteration of report tables.
################################################################################

function reportclose()

call reportcleanup()
if not same(jobtype(),"b") then
  call winclose()
end if
let rec = rec - 1

end function

################################################################################
# Obliteration of report tables and associated cursors.
################################################################################

function reportcleanup()

whenever error continue
close repcovget free repcovget
drop table repcover
close replstget free replstget
drop table replist
whenever error stop

end function

################################################################################
# Handling of viewing window.
################################################################################

function reportview(module,nr,txt)

define
  module char(18),
  nr integer,
  txt char(80),
  action char(10),
  c char(1)
let action = null
while action is null
  case viewer(module,txt)
  when "prevpage"
    if nr > 1 then
      let nr = nr - 1
      let action = "refresh"
    else call errtx("noscroll")
    end if
  when "nextpage"
    if nr < totrows then
      let nr = nr + 1
      let action = "refresh"
    else call errtx("noscroll")
    end if
  when "other" let action = "other"
  when "exit" let action = "exit"
  when "enter" let action = "enter"
  end case
end while
return action,nr

end function

################################################################################
# Finding of report window position with respect to cursor and page display.
################################################################################

function reportfindpage()

if find is null then return end if
let curline = 3
if find > totrows then let pagerow = totrows - 3 + 1
else let pagerow = find - 3 + 1
end if
if pagerow < 1 then
  let curline = 3 + pagerow - 1
  let pagerow = 1
end if
call reportreadpage()

end function

################################################################################
# Display of a report page.
################################################################################

function reportreadpage()

whenever error continue
fetch absolute pagerow replstget into screenline[1].*
if sqlca.sqlcode <> 0 then
  let pagerow = 1
  fetch absolute pagerow replstget into screenline[1].*
end if
if sqlca.sqlcode <> 0 then
  let screenline[1].form = null
  let screenline[1].text = " "
  let curline = null
  let pagerow = null
end if
case
when curline is null let curline = 1
when curline > totrows - pagerow + 1 let curline = totrows - pagerow + 1
end case
call reportshowline(1)
for i = 1 + 1 to totlines
  fetch next replstget into screenline[i].*
  if sqlca.sqlcode <> 0 then
    let screenline[i].form = null
    let screenline[i].text = " "
  end if
  call reportshowline(i)
end for
whenever error stop

end function

################################################################################
# Display of one report line.
################################################################################

function reportshowline(i)

define
  i,pos smallint,
  sline char(512),
  attr char(16)
let pos = titlines + i
let sline = screenline[i].text[linepos,512]
case i
when useline let attr = "listmark"
when curline let attr = "listcurr"
otherwise let attr = "list"
end case
if i = totlines then let attr = attr clipped,"last" end if
case
when screenline[i].form[1,1] = "U" let attr = attr clipped,"U"
when screenline[i].form[2,2] = "U" let attr = attr clipped,"U"
when screenline[i].form[3,3] = "U" let attr = attr clipped,"U"
end case
call disp(sline,attr,pos,1)

end function

################################################################################
# Display of a report cover page.
################################################################################

function reportreadcovp()

whenever error continue
fetch absolute pagecovr repcovget into screencovl[1].*
if sqlca.sqlcode <> 0 then
  let pagecovr = 1
  fetch absolute pagecovr repcovget into screencovl[1].*
end if
if sqlca.sqlcode <> 0 then
  let screencovl[1].form = null
  let screencovl[1].text = " "
  let curcovl = null
  let pagecovr = null
end if
case
when curcovl is null let curcovl = 1
when curcovl > totcovr - pagecovr + 1 let curcovl = totcovr - pagecovr + 1
end case
call reportshowcovl(1)
for i = 1 + 1 to scrlines
  fetch next repcovget into screencovl[i].*
  if sqlca.sqlcode <> 0 then
    let screencovl[i].form = null
    let screencovl[i].text = " "
  end if
  call reportshowcovl(i)
end for
whenever error stop

end function

################################################################################
# Display of one report cover line.
################################################################################

function reportshowcovl(i)

define
  i smallint,
  sline char(512),
  attr char(16)
let sline = screencovl[i].text[covlpos,512]
case i
when usecovl let attr = "listmark"
when curcovl let attr = "listcurr"
otherwise let attr = "list"
end case
if i = scrlines then let attr = attr clipped,"last" end if
call disp(sline,attr,i,1)

end function

################################################################################
# Output of report to file.
################################################################################

function reportpfile(filename)

define
  filename char(32),
  withhead char,
  pos smallint
whenever error continue
call pfile(filename) returning filename,withhead
if filename is null then return end if
call msgopen("printing")
if withhead is null then let withhead = false end if
start report output to filename
if withhead then
  let cline.text = null
  fetch first repcovget into cline.*
  while sqlca.sqlcode = 0
    output to report output(cline.text,true)
    fetch next repcovget into cline.*
  end while
  if cline.text is not null then output to report output(" ",true) end if
end if
fetch first replstget into rline.*
if sqlca.sqlcode = 0 then
  if withhead and titlines > 0 then
    let pos = repwidth - 32
    let ptxt = mtitle[1][1,pos],uname
    output to report output(ptxt,true)
    for curlin = 2 to titlines step 1
      output to report output(mtitle[curlin],true)
    end for
    let ptxt = null
    for pos = 1 to repwidth let ptxt = ptxt clipped,"¯" end for
    output to report output(ptxt,true)
  end if
  while true
    output to report output(rline.text[1,repwidth],true)
    fetch next replstget into rline.*
    if sqlca.sqlcode <> 0 then exit while end if
  end while
end if
finish report output
call msgclose()
whenever error stop

end function

################################################################################
# Output of report to file.
################################################################################

function reportpmail(maddr,msubj)

define
  maddr,msubj char(48),
  filename char(64),
  dscrname char(64),
  withhead char,
  md1,md2,md3,md4,md5 char(64),
  pos,i smallint
whenever error continue
call pmail(maddr,msubj) returning withhead,maddr,msubj,md1,md2,md3,md4,md5
if maddr is null then return end if
let filename = newtempfile("_mtext")
let dscrname = newtempfile("_mdscr")
call msgopen("printing")
if withhead is null then let withhead = false end if
start report output to dscrname
output to report output(md1,true)
if md2 is not null then output to report output(md2,true) end if
if md3 is not null then output to report output(md3,true) end if
if md4 is not null then output to report output(md4,true) end if
if md5 is not null then output to report output(md5,true) end if
finish report output
start report output to filename
if withhead then
  let cline.text = null
  fetch first repcovget into cline.*
  while sqlca.sqlcode = 0
    output to report output(cline.text,true)
    fetch next repcovget into cline.*
  end while
  if cline.text is not null then output to report output(" ",true) end if
end if
fetch first replstget into rline.*
if sqlca.sqlcode = 0 then
  if withhead and titlines > 0 then
    let pos = repwidth - 32
    let ptxt = mtitle[1][1,pos],uname
    output to report output(ptxt,true)
    for curlin = 2 to titlines step 1
      output to report output(mtitle[curlin],true)
    end for
    let ptxt = null
    for pos = 1 to repwidth let ptxt = ptxt clipped,"¯" end for
    output to report output(ptxt,true)
  end if
  while true
    output to report output(rline.text[1,repwidth],true)
    fetch next replstget into rline.*
    if sqlca.sqlcode <> 0 then exit while end if
  end while
end if
finish report output
call sendmail(filename,msubj,dscrname,maddr)
call msgclose()
call remtempfile(filename)
call remtempfile(dscrname)
whenever error stop

end function

################################################################################
# Output of report to special pipe.
################################################################################

function reportppipe()

define
  ppipeid char(32),
  withhead char,
  pipestr char(128),
  pos smallint
whenever error continue
call ppipe("") returning ppipeid,pipestr,withhead
if ppipeid is null then return end if
call msgopen("printing")
if withhead is null then let withhead = false end if
fetch first replstget into rline.*
if sqlca.sqlcode = 0 then
  call ppipebeg(pipestr)
  if withhead and titlines > 0 then
    let pos = repwidth - 32
    let ptxt = mtitle[1][1,pos],uname
    call ppipeout(ptxt)
    for curlin = 2 to titlines step 1
      call ppipeout(mtitle[curlin])
    end for
    let ptxt = null
    for pos = 1 to repwidth let ptxt = ptxt clipped,"¯" end for
    call ppipeout(ptxt)
  end if
  while true
    call ppipeout(rline.text[1,repwidth])
    fetch next replstget into rline.*
    if sqlca.sqlcode <> 0 then exit while end if
  end while
  call ppipeend()
end if
call msgclose()
whenever error stop

end function

################################################################################
# Output of report to printer or pipe.
################################################################################

function reportprint()

define
  pipename char(128),
  whead char,
  copies smallint,
  xprsetup,xprreset char(64)
whenever error continue
call print(defprinter,"",repwidth)
  returning pipename,whead,copies,paglen,xprsetup,xprreset
if setpaglen is not null then let paglen = setpaglen end if
if paglen = 0 then let paglen = null end if
if copies is null then return false end if
call msgopen("printing")
if titlines > 0 then let paglen = paglen - titlines - 4 end if
declare replprget cursor for select * from replist order by nr
if sqlca.sqlcode <> 0 then call progerrq("repprint",status,"declare") end if
for copies = copies to 1 step -1
  let prsetup = xprsetup
  let prreset = xprreset
  start report output to pipe pipename
  let curpag = 0
  if whead then
    let i = false
    fetch first repcovget into cline.*
    while sqlca.sqlcode = 0
      if prsetup is not null then
        output to report output(prsetup,false)
        let prsetup = null
      end if
      output to report output(prenh(cline.form,cline.text),true)
      let i = true
      fetch next repcovget into cline.*
    end while
    if i then output to report output(prreset,false) end if
  end if
  open replprget
  if sqlca.sqlcode <> 0 then call progerrq("repprint",status,"open") end if
  fetch replprget into rline.*
  if sqlca.sqlcode = 0 then
    call report_header()
    while true
      for rline.skip = rline.skip to -1 step 1
        call report_output("","",true)
      end for
      if curlin > 0 and rline.need + curlin >= paglen then
        call report_trailer(true)
        call report_header()
      end if
      for rline.skip = rline.skip to 1 step -1
        call report_output("","",true)
      end for
      if rline.need < 0 then call report_output(rline.form,rline.text,false)
      else call report_output(rline.form,rline.text,true)
      end if
      fetch replprget into rline.*
      if sqlca.sqlcode <> 0 then exit while end if
    end while
    call report_trailer(false)
  end if
  finish report output
end for
close replprget free replprget
call msgclose()
return true
whenever error stop

end function

################################################################################
# Output of one line to printer or pipe.
################################################################################

function report_output(frm,txt,cr)

define
  frm char(32),
  txt char(512),
  cr char
if curlin >= paglen then
  call report_trailer(true)
  call report_header()
end if
let curlin = curlin + 1
output to report output(prenh(frm,txt[1,repwidth]),cr)

end function

################################################################################
# Output of page header to printer or pipe.
################################################################################

function report_header()

define pos smallint
let curpag = curpag + 1
if titlines > 0 then
  let pos = repwidth - 32
  let ptxt = mtitle[1][1,pos],uname
  let ptxt = prsetup clipped,prenh(mtform[1],ptxt)
  output to report output(ptxt,true)
  if skiphead then output to report output("",true) end if
  for curlin = 2 to titlines step 1
    output to report output(prenh(mtform[curlin],mtitle[curlin]),true)
  end for
  let ptxt = null
  for pos = 1 to repwidth let ptxt = ptxt clipped,"¯" end for
  output to report output(ptxt,true)
  output to report output(prenh("biu",""),false)
else
  if prsetup is not null then output to report output(prsetup,false) end if
end if
let prsetup = null
let curlin = 0

end function

################################################################################
# Output of page trailer to printer or pipe.
################################################################################

function report_trailer(ff)

define ff,pos,pp smallint
if titlines > 0 then
  while curlin < paglen 
    let curlin = curlin + 1
    output to report output("",true)
  end while
  let ptxt = null
  for pos = 1 to repwidth let ptxt = ptxt clipped,"_" end for
  output to report output(prenh("Biu",ptxt),true)
  let pos = repwidth / 2 - 8
  let pp = repwidth - 31
  let ptxt = utime,column pos,curpag using "##########",column pp,uid
else let ptxt = null
end if
if ff then let ptxt = ptxt clipped,prreset end if
if ptxt is not null then
  output to report output(ptxt,false)
end if

end function

################################################################################
# Return with of report
################################################################################

function reportgetwidth()

return repwidth 

end function 

################################################################################
# Return newpage limit (used in reportfput functions to force a new page)
################################################################################

function reportnewpage()

return 9999

end function
