################################################################################
# General pick-list program (independent of system and database).
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
  readytomark,maybemarked char,
  modname array[10] of char(80),
  ftype array[10] of char(1),
  fcnum array[10] of smallint,
  spitem array[10,4] of char(32),
  sptable array[10] of char(32),
  formstr array[10] of char(80),
  msgtxt array[10] of char(80),
  pgrow,frow1,totrows array[10] of integer,
  curline,useline,totlines,titlines,totcols,scrlines array[10] of smallint,
  lid array[10,64] of char(32),
  ldata array[10,64] of char(80),
  lmark array[10,64] of char,
  enarefr array[10] of char,
  aggryes array[10] of char,
  grpcl array[10] of char(200),
  idname array[10] of char(32),
  aggrcol array[10,5] of smallint,
  aggrcna array[10,5] of char(200),
  aggrtyp array[10,5] of char(16),
  aggrval array[10,5] of char(32),
  aggrdat array[10] of char(80),
  trancol array[10,7] of smallint,
  tranmth array[10,7] of char(32),
  mtform array[10,4] of char(32),
  mtitle array[10,4] of char(80),
  defprinter array[10] of char(32),
  defpipe array[10] of char(32),
  lastrow,currrow array[10] of integer,
  currid array[10] of char(32),
  paglen,curlin smallint,
  curpag integer,
  prsetup,prreset char(64),
  ptxt char(200),
  dummy char(10),
  uname char(32),
  uid char(32),
  lexstr char(400),
  lexpos,lexlen smallint,
  utime datetime year to minute,
  finder,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p char(80),
  findlen smallint

################################################################################
# Opening of list window with title.
################################################################################

function listopen(mname,r,c,nr,nc)

define
  mname char(18),
  i,r,c,nr,nc,len smallint,
  mtitle1 char(80)
if rec >= 10 then
  call pause("maxlist",6,30)
  return (false)
end if
if rec > 0 then let rec = rec + 1
else let rec = 1
end if
let modname[rec] = mname
let enarefr[rec] = false
let defprinter[rec] = null
let defpipe[rec] = null
let scrlines[rec] = getlines()
if r is null then let r = 9999 end if
if c is null then let c = 9999 end if
if nr is null then let nr = 9999 end if
if nc is null then let nc = 0 end if
let titlines[rec] = 0
for i = 1 to 4
  let mtitle[rec,i] = rawtitle(mname,"f",i)
  let mtform[rec,i] = "Biu"
  if mtitle[rec,i] is not null then
    let titlines[rec] = i
    let len = length(mtitle[rec,i])
    if len > nc then let nc = len end if
    let mtitle[rec,i] = trim(mtitle[rec,i],"|")
  end if
end for
if nr < titlines[rec] + 5 then let nr = titlines[rec] + 5 end if
if nc < 32 then let nc = 32 end if
if nr > scrlines[rec] - 3 then let nr = scrlines[rec] - 3 end if
if nc > 78 then
  let nc = 80
  let nr = scrlines[rec] - 1
  let r = 1
  let c = 1
else
  if r < 1 then let r = 1 end if
  if c < 1 then let c = 1 end if
  if r + nr > scrlines[rec] - 2 then let r = scrlines[rec] - 2 - nr end if
  if c + nc > 78 + 1 then let c = 78 - nc + 1 end if
  let r = r + 1
  let c = c + 1
end if
call winopen(catstr("list-",mname),r,c,nr,nc)
let totlines[rec] = nr - titlines[rec] - 1
let mtitle1 = center(mtitle[rec,1],nc)
for i = 1 to titlines[rec]
  case i
  when 1 call disp(mtitle1,"titlefirst",1,1)
  when titlines[rec] call disp(mtitle[rec,i],"titlelast",i,1)
  otherwise call disp(mtitle[rec,i],"title",i,1)
  end case
end for
let totcols[rec] = nc
for i = 1 to 7 let trancol[rec,i] = null end for
for i = 1 to 4 let spitem[rec,i] = null end for
let sptable[rec] = null
let msgtxt[rec] = null
let grpcl[rec] = null
let idname[rec] = "rowid"
let aggryes[rec] = false
call listaggrinit()
return (true)

end function

################################################################################
# Initialize aggregates.
################################################################################

function listaggrinit()

define i smallint
if aggryes[rec] then
  let totlines[rec] = totlines[rec] + 1
  let aggryes[rec] = false
end if
for i = 1 to 5 let aggrcol[rec,i] = null end for

end function

################################################################################
# Additional title information.
################################################################################

function listhead(tit,lin,col,attr)

define
  tit char(80),
  lin,col smallint,
  attr char(16)
if lin > titlines[rec] then let lin = titlines[rec] end if
let mtitle[rec,lin] = tit
if col is null then let col = 0 end if
if attr is null then let attr = "title" end if
case
when col = 0 or col is null let tit = center(tit,totcols[rec])
when col < 0 let tit = right(tit,totcols[rec])
end case
call disp(tit,attr,lin,1)

end function

################################################################################
# Setup of default printer to be used in the output list.
################################################################################

function listprinter(printer)
  
define printer char(32)
let defprinter[rec] = printer

end function

################################################################################
# Setup of default transfer pipe to be used in the output list.
################################################################################

function listpipe(pipe)
  
define pipe char(32)
let defpipe[rec] = pipe

end function

################################################################################
# Enable the refresh key in calling program.
################################################################################

function listenarefr()

let enarefr[rec] = true

end function

################################################################################
# List window message option.
################################################################################

function listmsg(msg)

define msg char(80)
let msgtxt[rec] = stx(msg)

end function

################################################################################
# Setup of summation calculations by column number.
################################################################################

function listsum(col)

define col smallint
call listaggr(col,"sum","")

end function

################################################################################
# Setup of average calculations by column number.
################################################################################

function listavg(col)

define col smallint
call listaggr(col,"avg","")

end function

################################################################################
# Setup of maximum calculations by column number.
################################################################################

function listmax(col)

define col smallint
call listaggr(col,"max","")

end function

################################################################################
# Setup of minimum calculations by column number.
################################################################################

function listmin(col)

define col smallint
call listaggr(col,"min","")

end function

################################################################################
# Setup of aggregate calculations by column number.
################################################################################

function listaggr(col,typ,cna)

define
  col smallint,
  typ char(16),
  cna char(200),
  i smallint
if not aggryes[rec] then
  let totlines[rec] = totlines[rec] - 1
  let aggryes[rec] = true
end if
for i = 1 to 5
  if aggrcol[rec,i] is null then let aggrcol[rec,i] = col end if
  if aggrcol[rec,i] = col then
    let aggrtyp[rec,i] = typ
    let aggrcna[rec,i] = cna
    exit for
  end if
end for

end function

################################################################################
# Setup of value translations by column number.
################################################################################

function listtransl(mth,col)

define
  i smallint,
  mth char(32),
  col smallint
for i = 1 to 7
  if trancol[rec,i] is null then let trancol[rec,i] = col end if
  if trancol[rec,i] = col then
    let tranmth[rec,i] = mth
    exit for
  end if
end for

end function

################################################################################
# Setup of group by clause.
################################################################################

function listgroup(gcl)

define gcl char(200)
if gcl = " " then let gcl = null end if
let grpcl[rec] = gcl
let idname[rec] = null

end function

################################################################################
# Setup of key name (other than the default rowid).
################################################################################

function listidname(idn)

define idn char(32)
if idn is null or idn = " " then let idn = "rowid" end if
let idname[rec] = idn

end function

################################################################################
# Setup of database cursor and initial page display (simple form).
################################################################################

function listsetup(tbl,items,fstr,wcl,ocl,fndr)

define
  tbl char(200),
  items char(1000),
  fstr char(200),
  wcl char(8000),
  ocl char(200),
  fndr char(80),
  i,j,k smallint,
  cname,creal,ctbl char(200),
  oname,otbl char(200),
  lval char(100),
  pstr char(8000)
let formstr[rec] = fstr
let pgrow[rec] = 0
let curline[rec] = 1
let useline[rec] = null
if items is null or items = " " then let items = "*" end if
if wcl = " " then let wcl = null end if
if ocl = " " then let ocl = null end if
------------------------------------------------------------------
-- Find first table in table list (to be used as default table).
------------------------------------------------------------------
call listlex_init(tbl)
let sptable[rec] = listlex()
if sptable[rec] = " " then let sptable[rec] = null end if
------------------------------------------------------------------
-- Find first order by table and column name (or aliases) from
-- the order string.
------------------------------------------------------------------
let otbl = null
let oname = null
call listlex_init(ocl)
while true
  let lval = listlex()
  case
  when lval is null or lval = "," exit while
  when lval = "." let otbl = oname
  otherwise let oname = lval
  end case
end while
if oname = " " then let oname = null end if
------------------------------------------------------------------
-- Determine the real first order by table and column name from
-- the items string, as well as the column position and type.
-- If the table name is not given, assume the default table.
------------------------------------------------------------------
let ftype[rec] = null
let cname = null
let creal = null
let ctbl = sptable[rec]
let fcnum[rec] = 1
if oname is not null and items <> "*" then
  call listlex_init(items)
  while true
    let lval = listlex()
    case
    when lval is null exit while
    when lval = ","		-- End of item. If column matches then exit.
      if cname = oname then
        if otbl is null then let otbl = ctbl end if
        if ctbl = otbl then exit while end if
      end if
      let fcnum[rec] = fcnum[rec] + 1
      let ctbl = sptable[rec]
      let cname = null
      let creal = null
    when lval = "."		-- Previous text was a table.
      let ctbl = cname
      let cname = null
      let creal = null
    when cname is not null	-- Previous text was the real name.
      let creal = cname
      let cname = lval
    otherwise
      let cname = lval
      let creal = lval
    end case
  end while
end if
if cname = oname and ctbl = otbl then
  select syscolumns.coltype into i from syscolumns,systables
    where syscolumns.colname = creal and systables.tabid = syscolumns.tabid
    and systables.tabname = ctbl
  if sqlca.sqlcode <> 0 then let i = null end if
  let i = i mod 256
  case
  when i = 0 or i = 13 or i = 15 or i = 16 let ftype[rec] = "c"
  when (i >= 1 and i <= 6) or i = 8 let ftype[rec] = "n"
  otherwise let ftype[rec] = "c"
  end case
end if
if grpcl[rec] is null then
  let pstr = "select count(*)"
  if aggryes[rec] then
    for i = 1 to 5
      case
      when aggrcol[rec,i] is null let cname = null
      when aggrcna[rec,i] is not null let cname = aggrcna[rec,i]
      otherwise
        let k = 0
        for j = 1 to length(items)
          case
          when items[j] = ","
            let k = k + 1
            if k = aggrcol[rec,i] then exit for end if
            let cname = null
          when k = aggrcol[rec,i] - 1
            let cname = cname clipped,items[j]
          end case
        end for
      end case
      if cname is null then
        let pstr = pstr clipped,",0"
      else
        let pstr = pstr clipped,",",aggrtyp[rec,i] clipped,"(",cname clipped,")"
      end if
    end for
  end if
  let pstr = pstr clipped," from ",tbl clipped
  if wcl is not null then let pstr = pstr clipped," where ",wcl clipped end if
  whenever error continue
  case rec
  when 1 prepare pcsc1 from pstr 
  when 2 prepare pcsc2 from pstr 
  when 3 prepare pcsc3 from pstr 
  when 4 prepare pcsc4 from pstr 
  when 5 prepare pcsc5 from pstr 
  when 6 prepare pcsc6 from pstr 
  when 7 prepare pcsc7 from pstr 
  when 8 prepare pcsc8 from pstr 
  when 9 prepare pcsc9 from pstr 
  otherwise prepare pcsc from pstr 
  end case
  if sqlca.sqlcode <> 0 then
    call progerrq("listsetup: prepare",sqlca.sqlcode,pstr)
  end if
  case rec
  when 1 declare csc1 cursor for pcsc1
  when 2 declare csc2 cursor for pcsc2
  when 3 declare csc3 cursor for pcsc3
  when 4 declare csc4 cursor for pcsc4
  when 5 declare csc5 cursor for pcsc5
  when 6 declare csc6 cursor for pcsc6
  when 7 declare csc7 cursor for pcsc7
  when 8 declare csc8 cursor for pcsc8
  when 9 declare csc9 cursor for pcsc9
  otherwise declare csc cursor for pcsc
  end case
  if sqlca.sqlcode <> 0 then
    call progerrq("listsetup: declare",sqlca.sqlcode,pstr)
  end if
end if
if idname[rec] is not null then
  let pstr = "select ",sptable[rec] clipped,".",idname[rec] clipped,",",items clipped
else
  let pstr = "select ",items clipped
end if
let pstr = pstr clipped," from ",tbl clipped
if wcl is not null then let pstr = pstr clipped," where ",wcl clipped end if
if grpcl[rec] is not null then let pstr = pstr clipped," group by ",grpcl[rec] end if
if ocl is not null then let pstr = pstr clipped," order by ",ocl clipped end if
case rec
when 1 prepare psc1 from pstr
when 2 prepare psc2 from pstr
when 3 prepare psc3 from pstr
when 4 prepare psc4 from pstr
when 5 prepare psc5 from pstr
when 6 prepare psc6 from pstr
when 7 prepare psc7 from pstr
when 8 prepare psc8 from pstr
when 9 prepare psc9 from pstr
otherwise prepare psc from pstr
end case
if sqlca.sqlcode <> 0 then
  call progerrq("listsetup: prepare",sqlca.sqlcode,pstr)
end if
case rec
when 1 declare sc1 scroll cursor with hold for psc1
when 2 declare sc2 scroll cursor with hold for psc2
when 3 declare sc3 scroll cursor with hold for psc3
when 4 declare sc4 scroll cursor with hold for psc4
when 5 declare sc5 scroll cursor with hold for psc5
when 6 declare sc6 scroll cursor with hold for psc6
when 7 declare sc7 scroll cursor with hold for psc7
when 8 declare sc8 scroll cursor with hold for psc8
when 9 declare sc9 scroll cursor with hold for psc9
otherwise declare sc scroll cursor with hold for psc
end case
if sqlca.sqlcode <> 0 then
  call progerrq("listsetup: declare",sqlca.sqlcode,pstr)
end if
whenever error stop
let lastrow[rec] = null
let currrow[rec] = null
let currid[rec] = null
call listinit(fndr)

end function

################################################################################
# Lex initialization.
################################################################################

function listlex_init(str)

define str char(400)
let lexstr = str clipped
let lexlen = length(lexstr)
let lexpos = 0

end function

################################################################################
# Next lex value.
################################################################################

function listlex()

define lexbeg smallint
  ,lexval char(100)
let lexval = null
let lexbeg = lexpos + 1
for lexpos = lexbeg to lexlen
  case
  when lexstr[lexpos] = "." or lexstr[lexpos] = ","
    if lexpos = lexbeg then return lexstr[lexpos]
    else
      let lexpos = lexpos - 1
      exit for
    end if
  when lexstr[lexpos] = "["
    for lexpos = lexpos + 1 to lexlen
      if lexstr[lexpos] = "]" then exit for end if
    end for
  when lexstr[lexpos] = " "
    exit for
  otherwise
    let lexval = lexval clipped,lexstr[lexpos]
  end case
end for
return lexval clipped

end function

################################################################################
# Definition of special items such as hidden keys to be displayed on request.
################################################################################

function listspitem(spit)

define
  spit char(32),
  i smallint
for i = 1 to 4
  if spitem[rec,i] is null then
    let spitem[rec,i] = spit
    exit for
  end if
end for

end function

################################################################################
# List window handling.
################################################################################

function listman()

define
  c char(1),
  mtxt,ptxt char(80),
  action char(10),
  arraypos smallint,
  i,j integer
let finder = null
let findlen = 0
if currid[rec] <> listfetchid(currrow[rec]) then
  for i = 1 to totrows[rec] step 1
    if listfetchid(i) = currid[rec] then
      let currrow[rec] = i
      exit for
    end if
  end for
end if
if currrow[rec] <> lastrow[rec] then
  let curline[rec] = curline[rec] + currrow[rec] - lastrow[rec]
  case
  when curline[rec] < 1
    let pgrow[rec] = pgrow[rec] + curline[rec] - 1
    let curline[rec] = 1
  when curline[rec] > totlines[rec]
    let pgrow[rec] = pgrow[rec] + curline[rec] - totlines[rec]
    let curline[rec] = totlines[rec]
  end case
  call listreadpage()
end if
let frow1[rec] = 0
let action = null
while action is null
  let arraypos = curline[rec] + 1
  case
  when totrows[rec] = 0 let ptxt = stx("nolist")
  when pgrow[rec] = 0
    if totrows[rec] <= totlines[rec] then let ptxt = stx("onlypg")
    else let ptxt = stx("firstpg")
    end if
  when totrows[rec] <= pgrow[rec] let ptxt = stx("beyond")
  when totrows[rec] <= totlines[rec] + pgrow[rec] let ptxt = stx("lastpg")
  otherwise let ptxt = " "
  end case
  if totrows[rec] <> 0 then
    let ptxt = ptxt clipped," (",pgrow[rec] + curline[rec] using "<<<<<<<<"
      ,"/",totrows[rec] using "<<<<<<<<",")"
  end if
  if finder is not null then let ptxt = "[",finder[1,findlen],"] ",ptxt end if
  if msgtxt[rec] is not null then
    let mtxt = msgtxt[rec]
    let j = totcols[rec] - length(mtxt) - 1
    if length(ptxt) < j - 2 then
      for i = j to totcols[rec] - 1 let ptxt[i] = mtxt[i - j + 1] end for
    end if
  end if
  if useline[rec] is not null then
    let useline[rec] = null
    call listshowline(arraypos)
  end if
  let i = totcols[rec] - 1
  if length(ptxt) > i then
    let mtxt = ptxt[1,i]
    let ptxt = mtxt
  end if
  call dispmsg(ptxt clipped)
  let i = getkey()
  if i < 256 and i > 32 then let c = ascii(i) else let c = null end if
  case keytransl(i)
  when "up"
    if curline[rec] > 1 then
      let curline[rec] = curline[rec] - 1
      call listshowline(arraypos)
      call listshowline(arraypos - 1)
    else
      if lid[rec,1] is not null then
        for i = listmaxlines() + 2 to 2 step -1
          let lid[rec,i] = lid[rec,i - 1]
          let ldata[rec,i] = ldata[rec,i - 1]
          let lmark[rec,i] = lmark[rec,i - 1]
          if i < totlines[rec] + 2 then call listshowline(i) end if
        end for
        let pgrow[rec] = pgrow[rec] - 1
        call listprocessrow(pgrow[rec],1)
      end if
    end if
  when "down"
    let j = listmaxlines()
    if curline[rec] < j then
      let curline[rec] = curline[rec] + 1
      call listshowline(arraypos)
      call listshowline(arraypos + 1)
    else
      if lid[rec,j + 2] is not null then
        for i = 1 to j + 1
          let lid[rec,i] = lid[rec,i + 1]
          let ldata[rec,i] = ldata[rec,i + 1]
          let lmark[rec,i] = lmark[rec,i + 1]
          if i > 1 then call listshowline(i) end if
        end for
        let pgrow[rec] = pgrow[rec] + 1
        call listprocessrow(pgrow[rec] + j + 1,j + 2)
      end if
    end if
  when "prevpage"
    if lid[rec,1] is null then
      let curline[rec] = 1
      call listfirstpage()
    else
      let pgrow[rec] = pgrow[rec] - totlines[rec]
      call listreadpage()
    end if
  when "nextpage"
    let j = totlines[rec]
    if lid[rec,j + 2] is null then
      let curline[rec] = totlines[rec]
      let pgrow[rec] = totrows[rec] - totlines[rec]
      call listreadpage()
    else
      let pgrow[rec] = pgrow[rec] + totlines[rec]
      let lid[rec,1] = lid[rec,j + 1]
      let ldata[rec,1] = ldata[rec,j + 1]
      let lmark[rec,1] = lmark[rec,j + 1]
      call listreadrest()
    end if
  when "home"
    let curline[rec] = 1
    call listfirstpage()
  when "end"
    let curline[rec] = totlines[rec]
    let pgrow[rec] = totrows[rec] - totlines[rec]
    call listreadpage()
  when "toggle"
    call listmarkline()
    let c = null
  when "pfile" call listpfile()
  when "pmail" call listpmail()
  when "print" call listprint()
  when "ppipe" call listppipe()
  when "refresh"
    if enarefr[rec] then let action = "refresh"
    else call listinit("")
    end if
  when "help" call helpman(modname[rec],"list")
  when "prevset" let action = "prevset"
  when "nextset" let action = "nextset"
  when "filter" let action = "filter"
  when "other" let action = "other"
  when "enter" let action = "enter"
  when "insert" let action = "insert"
  when "delete" let action = "delete"
  when "accept" let action = "accept"
  when "exit" let action = "exit"
  when "search" let c = null
  when "tab" let c = null
  when "left" let c = null
  when "right" let c = null
  otherwise if c is null then let c = " " end if
  end case
  if action is null then
    case c
    when "!" call bang()
    when "#" call listshowspitem(listfetchid(pgrow[rec] + curline[rec]))
    otherwise
      case ftype[rec]
      when "" let c = null
      when "n" if c not matches "[0123456789,]" then let c = null end if
      end case
      case
      when c is null
        let finder = null
        let findlen = 0
        let frow1[rec] = 0
      when length(finder) = 80
        let finder = null
        let findlen = 0
        let frow1[rec] = 0
      otherwise
        if finder is null then let finder = c
        else let finder = finder[1,findlen],c
        end if
        let findlen = findlen + 1
        if findlen > length(finder) + 1 or finder = " " then
          let finder = null
          let findlen = 0
          let frow1[rec] = 0
        end if
        call listfindpage()
      end case
    end case
  end if
end while
let useline[rec] = curline[rec]
call listshowline(arraypos)
let lastrow[rec] = pgrow[rec] + curline[rec]
let currrow[rec] = lastrow[rec]
let currid[rec] = listfetchid(currrow[rec])
return action,currid[rec]

end function

################################################################################
# Display of special item and rowid.
################################################################################

function listshowspitem(xid)

define
  xid char(32),
  xspval array[4] of char(32),
  ptxt char(200),
  c char,
  i integer,
  nr,nc,done smallint
if xid is null then return end if
initialize xspval to null
if spitem[rec,1] is not null then
  let ptxt = "select ",spitem[rec,1]
  for i = 2 to 4
    if spitem[rec,i] is null then exit for
    else let ptxt = ptxt clipped,",",spitem[rec,i]
    end if
  end for
  let nr = i + 4
  let nc = 32
  let ptxt = ptxt clipped," from ",sptable[rec] clipped
    ," where ",idname[rec] clipped,"=?"
  prepare pspit from ptxt declare spit cursor for pspit
else
  let nr = 4
  let nc = 20
end if
call winopen("listspitem",12,2,nr,nc)
let done = false
while not done
  call winclear()
  call disptitle("spitem","s")
  let ptxt = upfword("rowid"),"............"
  let ptxt = ptxt[1,10]," ",xid using "<<<<<<<<<<"
  display ptxt at 3,1 attribute(normal)
  if spitem[rec,1] is not null then
    open spit using xid
    fetch spit into xspval[1],xspval[2],xspval[3],xspval[4]
    if sqlca.sqlcode <> 0 then
      call progerr("listshowspitem: fetch",sqlca.sqlcode,rec)
      exit while
    end if
    let ptxt = upfword("key"),"............"
    let ptxt = ptxt[1,10]," ",xspval[1]
    display ptxt at 5,1 attribute(normal)
    for i = 2 to 4
      if xspval[i] is not null then
        let nr = i + 4
        display xspval[i] at nr,1 attribute(bold)
      end if
    end for
  end if
  case keytransl(getkey())
  when "prevpage"
    let i = listprevid(xid)
    if i is not null then let xid = i end if
  when "nextpage"
    let i = listnextid(xid)
    if i is not null then let xid = i end if
  when "help" call helpman("listspitem","")
  when "accept" let done = true
  when "exit" let done = true
  end case
end while
call winclose()
if spitem[rec,1] is not null then close spit free spit free pspit end if

end function

################################################################################
# Opening of database cursor and initial page display.
################################################################################

function listinit(fndr)

define
  fndr char(80),
  z smallint
call msgtx("seeking")
let finder = fndr
if finder = " " then let finder = null end if
let findlen = length(finder)
let uname = right(sysname(),32)
let uid = right(sysid(),32)
let utime = current
call listopencurs()
if readytomark then
  whenever error continue
  delete from listmark where 1=1;
  if sqlca.sqlcode <> 0 then call progerrq("listmark: delete",status,"") end if
  whenever error stop
  let maybemarked = false
else let readytomark = false
end if
if aggryes[rec] then
  let a = null let b = null let c = null let d = null let e = null let f = null
  let g = null let h = null let i = null let j = null let k = null let l = null
  let m = null let n = null let o = null let p = null
  for z = 1 to 5
    if aggrcol[rec,z] is not null then
      case aggrcol[rec,z]
      when 1 let a = aggrval[rec,z]
      when 2 let b = aggrval[rec,z]
      when 3 let c = aggrval[rec,z]
      when 4 let d = aggrval[rec,z]
      when 5 let e = aggrval[rec,z]
      when 6 let f = aggrval[rec,z]
      when 7 let g = aggrval[rec,z]
      when 8 let h = aggrval[rec,z]
      when 9 let i = aggrval[rec,z]
      when 10 let j = aggrval[rec,z]
      when 11 let k = aggrval[rec,z]
      when 12 let l = aggrval[rec,z]
      when 13 let m = aggrval[rec,z]
      when 14 let n = aggrval[rec,z]
      when 15 let o = aggrval[rec,z]
      when 16 let p = aggrval[rec,z]
      end case
    end if
  end for
  let aggrdat[rec] = listformat()
  let z = titlines[rec] + totlines[rec] + 1
  call disp(aggrdat[rec],"list",z,1)
end if
let frow1[rec] = 0
call listfindpage()

end function

################################################################################
# Handling of viewing window.
################################################################################

function listview(module,xid,txt)

define
  module char(18),
  i,xid char(32),
  txt char(80),
  action char(10),
  c char(1)
let action = null
while action is null
  case viewer(module,txt)
  when "prevpage"
    let i = listprevid(xid)
    if i is not null then
      let xid = i
      let action = "refresh"
    end if
  when "nextpage"
    let i = listnextid(xid)
    if i is not null then
      let xid = i
      let action = "refresh"
    end if
  when "refresh" let action = "refresh"
  when "other" let action = "other"
  when "exit" let action = "exit"
  end case
end while
return action,xid

end function

################################################################################
# Retrieval of previous page in editing and viewing windows.
################################################################################

function listprevid(xid)

define xid char(32)
if xid is not null then
  let xid = listprev()
  if xid is null then call errtx("firstpg")
  else
    let currrow[rec] = currrow[rec] - 1
    let currid[rec] = xid
  end if
end if
return xid

end function

################################################################################
# Retrieval of next page in editing and viewing windows.
################################################################################

function listnextid(xid)

define xid char(32)
if xid is not null then
  let xid = listnext()
  if xid is null then call errtx("lastpg")
  else
    let currrow[rec] = currrow[rec] + 1
    let currid[rec] = xid
  end if
end if
return xid

end function

################################################################################
# Retrieval of next page in editing and viewing windows.
################################################################################

function listsetid(xid)

define xid char(32)
let currid[rec] = xid

end function

################################################################################
# Retrieval of previous database cursor row.
################################################################################

function listprev()

define id char(32)
case rec
when 1 fetch previous sc1 into id
when 2 fetch previous sc2 into id
when 3 fetch previous sc3 into id
when 4 fetch previous sc4 into id
when 5 fetch previous sc5 into id
when 6 fetch previous sc6 into id
when 7 fetch previous sc7 into id
when 8 fetch previous sc8 into id
when 9 fetch previous sc9 into id
otherwise fetch previous sc into id
end case
if sqlca.sqlcode <> 0 then let id = null end if
return (id)

end function

################################################################################
# Retrieval of next database cursor row.
################################################################################

function listnext()

define id char(32)
case rec
when 1 fetch next sc1 into id
when 2 fetch next sc2 into id
when 3 fetch next sc3 into id
when 4 fetch next sc4 into id
when 5 fetch next sc5 into id
when 6 fetch next sc6 into id
when 7 fetch next sc7 into id
when 8 fetch next sc8 into id
when 9 fetch next sc9 into id
otherwise fetch next sc into id
end case
if sqlca.sqlcode <> 0 then let id = null end if
return (id)

end function

################################################################################
# Reopening of database cursor and retrieval of first row.
################################################################################

function listfirst()

define id char(32)
call listopencurs()
case rec
when 1 fetch first sc1 into id
when 2 fetch first sc2 into id
when 3 fetch first sc3 into id
when 4 fetch first sc4 into id
when 5 fetch first sc5 into id
when 6 fetch first sc6 into id
when 7 fetch first sc7 into id
when 8 fetch first sc8 into id
when 9 fetch first sc9 into id
otherwise fetch first sc into id
end case
if sqlca.sqlcode <> 0 then let id = null end if
return (id)

end function

################################################################################
# Opening of database cursor
################################################################################

function listopencurs()

define z smallint,id char(32)
if grpcl[rec] is null then
  case rec
  when 1 open csc1
  when 2 open csc2
  when 3 open csc3
  when 4 open csc4
  when 5 open csc5
  when 6 open csc6
  when 7 open csc7
  when 8 open csc8
  when 9 open csc9
  otherwise open csc
  end case
  if aggryes[rec] then
    case rec
    when 1 fetch csc1 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 2 fetch csc2 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 3 fetch csc3 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 4 fetch csc4 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 5 fetch csc5 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 6 fetch csc6 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 7 fetch csc7 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 8 fetch csc8 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    when 9 fetch csc9 into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    otherwise fetch csc into totrows[rec],aggrval[rec,1],aggrval[rec,2],aggrval[rec,3],aggrval[rec,4],aggrval[rec,5]
    end case
  else
    case rec
    when 1 fetch csc1 into totrows[rec]
    when 2 fetch csc2 into totrows[rec]
    when 3 fetch csc3 into totrows[rec]
    when 4 fetch csc4 into totrows[rec]
    when 5 fetch csc5 into totrows[rec]
    when 6 fetch csc6 into totrows[rec]
    when 7 fetch csc7 into totrows[rec]
    when 8 fetch csc8 into totrows[rec]
    when 9 fetch csc9 into totrows[rec]
    otherwise fetch csc into totrows[rec]
    end case
  end if
  if sqlca.sqlcode <> 0 then
    call progerrq("listopencurs: fetch csc",sqlca.sqlcode,rec)
  end if
  case rec
  when 1 close csc1
  when 2 close csc2
  when 3 close csc3
  when 4 close csc4
  when 5 close csc5
  when 6 close csc6
  when 7 close csc7
  when 8 close csc8
  when 9 close csc9
  otherwise close csc
  end case
end if
case rec
when 1 open sc1
when 2 open sc2
when 3 open sc3
when 4 open sc4
when 5 open sc5
when 6 open sc6
when 7 open sc7
when 8 open sc8
when 9 open sc9
otherwise open sc
end case
if grpcl[rec] is not null then
  let totrows[rec] = 0
  for z = 1 to 5 let aggrval[rec,z] = 0 end for
  while true
    if idname[rec] is null then
      case rec
      when 1 fetch sc1 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 2 fetch sc2 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 3 fetch sc3 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 4 fetch sc4 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 5 fetch sc5 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 6 fetch sc6 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 7 fetch sc7 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 8 fetch sc8 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 9 fetch sc9 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      otherwise fetch sc into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      end case
    else
      case rec
      when 1 fetch sc1 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 2 fetch sc2 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 3 fetch sc3 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 4 fetch sc4 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 5 fetch sc5 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 6 fetch sc6 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 7 fetch sc7 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 8 fetch sc8 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      when 9 fetch sc9 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      otherwise fetch sc into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
      end case
    end if
    if sqlca.sqlcode <> 0 then exit while end if
    let totrows[rec] = totrows[rec] + 1
    for z = 1 to 5
      if aggrcol[rec,z] is not null then
        case aggrcol[rec,z]
        when 1 let aggrval[rec,z] = aggrval[rec,z] + a
        when 2 let aggrval[rec,z] = aggrval[rec,z] + b
        when 3 let aggrval[rec,z] = aggrval[rec,z] + c
        when 4 let aggrval[rec,z] = aggrval[rec,z] + d
        when 5 let aggrval[rec,z] = aggrval[rec,z] + e
        when 6 let aggrval[rec,z] = aggrval[rec,z] + f
        when 7 let aggrval[rec,z] = aggrval[rec,z] + g
        when 8 let aggrval[rec,z] = aggrval[rec,z] + h
        when 9 let aggrval[rec,z] = aggrval[rec,z] + i
        when 10 let aggrval[rec,z] = aggrval[rec,z] + j
        when 11 let aggrval[rec,z] = aggrval[rec,z] + k
        when 12 let aggrval[rec,z] = aggrval[rec,z] + l
        when 13 let aggrval[rec,z] = aggrval[rec,z] + m
        when 14 let aggrval[rec,z] = aggrval[rec,z] + n
        when 15 let aggrval[rec,z] = aggrval[rec,z] + o
        when 16 let aggrval[rec,z] = aggrval[rec,z] + p
        end case
      end if
    end for
  end while
end if

end function

################################################################################
# Closing of list window and database cursor.
################################################################################

function listclose()

call listclosecurs()
call winclose()
let rec = rec - 1

end function

################################################################################
# Close database cursor.
################################################################################

function listclosecurs()

whenever error continue
case rec
when 1 close sc1 free sc1 free psc1 free csc1 free pcsc1
when 2 close sc2 free sc2 free psc2 free csc2 free pcsc2
when 3 close sc3 free sc3 free psc3 free csc3 free pcsc3
when 4 close sc4 free sc4 free psc4 free csc4 free pcsc4
when 5 close sc5 free sc5 free psc5 free csc5 free pcsc5
when 6 close sc6 free sc6 free psc6 free csc6 free pcsc6
when 7 close sc7 free sc7 free psc7 free csc7 free pcsc7
when 8 close sc8 free sc8 free psc8 free csc8 free pcsc8
when 9 close sc9 free sc9 free psc9 free csc9 free pcsc9
otherwise close sc free sc free psc free csc free pcsc
end case
whenever error stop

end function

################################################################################
# Finding of list window position with respect to cursor and display of page.
################################################################################

function listfindpage()

define
  xfinder,value char(80),
  ifinder,ivalue decimal,
  found,i smallint,
  frow2 integer
call msgtx("locating")
case
when ftype[rec] = "n"
  if length(finder) > 12 then let finder = null end if
  whenever error continue
  let ifinder = finder
  if status <> 0 then let ifinder = 0 end if
  whenever error stop
otherwise
  if ftype[rec] is null then let finder = null end if
  let xfinder = charsortval(finder)
end case
if finder is null then
  let findlen = 0
  let frow1[rec] = 0
else
  let frow2 = totrows[rec]
  let found = false
  while not found
    let pgrow[rec] = (frow1[rec] + frow2 + 1) / 2
    let found = true
    case
    when pgrow[rec] >= frow2 let pgrow[rec] = frow2
    when pgrow[rec] <= frow1[rec] let pgrow[rec] = frow1[rec]
    otherwise
      let found = false
      let value = listfindval()
      if value is null then let found = true
      else
        if ftype[rec] = "n" then
          let ivalue = value
          case
          when ivalue = ifinder let found = true
          when ivalue > ifinder let frow2 = pgrow[rec]
          otherwise let frow1[rec] = pgrow[rec]
          end case
        else
          let value = charsortval(value)
          case
          when value = xfinder let found = true
          when value > xfinder let frow2 = pgrow[rec]
          otherwise let frow1[rec] = pgrow[rec]
          end case
        end if
      end if
    end case
  end while
  let frow1[rec] = pgrow[rec] - 1
  if value is null then let pgrow[rec] = pgrow[rec] - 4
  else let pgrow[rec] = pgrow[rec] - 3
  end if
  let curline[rec] = 3
  let i = pgrow[rec] + totlines[rec] - totrows[rec]
  if i > 0 then
    let curline[rec] = curline[rec] + i
    let pgrow[rec] = pgrow[rec] - i
  end if
  if pgrow[rec] < 0 then
    let curline[rec] = curline[rec] + pgrow[rec]
    let pgrow[rec] = 0
  end if
end if
call listreadpage()

end function

################################################################################
# Determination of list window position with respect to cursor list.
################################################################################

function listfindval()

define
  id char(32),
  value char(80)
let id = listfetchid(pgrow[rec])
if id is null then return "" end if
case fcnum[rec] 
when 1 let value = a
when 2 let value = b
when 3 let value = c
when 4 let value = d
when 5 let value = e
when 6 let value = f
when 7 let value = g
when 8 let value = h
when 9 let value = i
when 10 let value = j
when 11 let value = k
when 12 let value = l
when 13 let value = m
when 14 let value = n
when 15 let value = o
when 16 let value = p
otherwise return ""
end case
if value is null then let value = " " end if
return (value)

end function

################################################################################
# Display of list window page.
################################################################################

function listreadpage()

if pgrow[rec] < 0 then let pgrow[rec] = 0 end if
call listprocessrow(pgrow[rec],1)
if sqlca.sqlcode = 0 then call listreadrest()
else call listfirstpage()

end if

end function

################################################################################
# Display of first list window page.
################################################################################

function listfirstpage()

let pgrow[rec] = 0
let lid[rec,1] = null
let ldata[rec,1] = " "
let lmark[rec,1] = null
call listreadrest()

end function

################################################################################
# Display of rest of list window page.
################################################################################

function listreadrest()

define i smallint
let i = listmaxlines()
let useline[rec] = null
if curline[rec] > i then let curline[rec] = i end if
if curline[rec] < 1 then let curline[rec] = 1 end if
for i = 2 to totlines[rec] + 2
  call listprocessrow(pgrow[rec] + i - 1,i)
  if i < totlines[rec] + 2 then call listshowline(i) end if
end for

end function

################################################################################
# Formating of list window line.
################################################################################

function listprocessrow(curs,anr)

define
  curs integer,
  anr,i smallint
let lid[rec,anr] = listfetchid(curs)
if lid[rec,anr] is null then let ldata[rec,anr] = " "
else let ldata[rec,anr] = listformat()
end if
if maybemarked then
  select count(*) into i from listmark where listmarkid = lid[rec,anr]
  if i = 0 then let lmark[rec,anr] = null
  else let lmark[rec,anr] = true
  end if
else let lmark[rec,anr] = null
end if

end function

################################################################################
# Formating of a line.
################################################################################

function listformat()

define
  z smallint,
  data char(80),
  val char(80)
for z = 1 to 7
  if trancol[rec,z] is null then exit for end if
  case trancol[rec,z]
  when 1 let a = transl(tranmth[rec,z],a)
  when 2 let b = transl(tranmth[rec,z],b)
  when 3 let c = transl(tranmth[rec,z],c)
  when 4 let d = transl(tranmth[rec,z],d)
  when 5 let e = transl(tranmth[rec,z],e)
  when 6 let f = transl(tranmth[rec,z],f)
  when 7 let g = transl(tranmth[rec,z],g)
  when 8 let h = transl(tranmth[rec,z],h)
  when 9 let i = transl(tranmth[rec,z],i)
  when 10 let j = transl(tranmth[rec,z],j)
  when 11 let k = transl(tranmth[rec,z],k)
  when 12 let l = transl(tranmth[rec,z],l)
  when 13 let m = transl(tranmth[rec,z],m)
  when 14 let n = transl(tranmth[rec,z],n)
  when 15 let o = transl(tranmth[rec,z],o)
  when 16 let p = transl(tranmth[rec,z],p)
  end case
end for
if formstr[rec] is not null then
  let data = format(formstr[rec],a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
else
  let data = a clipped,"  ",b clipped,"  ",c clipped,"  "
    ,d clipped,"  ",e clipped,"  ",f clipped,"  ",g clipped,"  "
    ,h clipped,"  ",i clipped,"  ",j clipped,"  ",k clipped,"  "
    ,l clipped,"  ",m clipped,"  ",n clipped,"  ",o clipped,"  ",p clipped
end if
return data

end function

################################################################################
# Mark/unmark the current screen line.
################################################################################

function listmarkline()

define anr,i integer
  ,id char(32),ptxt char(100)
whenever error continue
let anr = curline[rec] + 1
let id = lid[rec,anr]
if id is null then return end if
if maybemarked then
  select count(*) into i from listmark where listmarkid = id
else
  if not readytomark then
    create temp table listmark (listmarkid integer unique) with no log
    if sqlca.sqlcode <> 0 then call progerrq("listmark: create",status,"") end if
    let readytomark = true
  end if
  let maybemarked = true
  let i = 0
end if
if i = 0 then
  insert into listmark values (id)
  if sqlca.sqlcode <> 0 then call progerrq("listmark: insert",status,"") end if
  let lmark[rec,anr] = true
else
  delete from listmark where listmarkid = id
  if sqlca.sqlcode <> 0 then call progerrq("listmark: delete",status,"") end if
  let lmark[rec,anr] = null
end if
call listshowline(anr)
whenever error stop

end function

################################################################################
# Display of list window line.
################################################################################

function listshowline(anr)

define
  anr,pos smallint,
  attr char(16)
let pos = titlines[rec] + anr - 1
case anr
when useline[rec] + 1 let attr = "listmark"
when curline[rec] + 1
  if lmark[rec,anr] then let attr = "listcurrmark"
  else let attr = "listcurr"
  end if
otherwise
  if lmark[rec,anr] then let attr = "listmark"
  else let attr = "list"
  end if
end case
if anr = totlines[rec] + 1 then let attr = attr clipped,"last" end if
call disp(ldata[rec,anr],attr,pos,1)

end function

################################################################################
# Return a list of marked lines.
################################################################################

function listmarks()

define
  id char(32),
  str char(4000)
let str = null
if maybemarked then
  declare listmark cursor for select listmarkid from listmark where 1=1
  foreach listmark into id
    if str is not null then let str = str clipped,"," end if
    let str = str clipped,id clipped
  end foreach
  free listmark
end if
return str clipped

end function

################################################################################
# Retrieval of row in database cursor.
################################################################################

function listfetchid(curs)

define curs,id char(32)
whenever error continue
if idname[rec] is not null then
  case rec
  when 1 fetch absolute curs sc1 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 2 fetch absolute curs sc2 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 3 fetch absolute curs sc3 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 4 fetch absolute curs sc4 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 5 fetch absolute curs sc5 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 6 fetch absolute curs sc6 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 7 fetch absolute curs sc7 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 8 fetch absolute curs sc8 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 9 fetch absolute curs sc9 into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  otherwise fetch absolute curs sc into id,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  end case
else
  let id = 0
  case rec
  when 1 fetch absolute curs sc1 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 2 fetch absolute curs sc2 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 3 fetch absolute curs sc3 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 4 fetch absolute curs sc4 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 5 fetch absolute curs sc5 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 6 fetch absolute curs sc6 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 7 fetch absolute curs sc7 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 8 fetch absolute curs sc8 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  when 9 fetch absolute curs sc9 into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  otherwise fetch absolute curs sc into a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p
  end case
end if
if sqlca.sqlcode <> 0 then let id = null end if
whenever error stop
return (id)

end function

################################################################################
# Determination of the maximum number of screen lines.
################################################################################

function listmaxlines()

define i integer
let i = totrows[rec] - pgrow[rec]
if i > totlines[rec] then return totlines[rec]
else return i
end if

end function

################################################################################
# Output of list to file.
################################################################################

function listpfile()

define
  curs integer,
  filename char(32),
  withhead char,
  i,j smallint
call pfile("") returning filename,withhead
if filename is null then return end if
call msgopen("printing")
if withhead is null then let withhead = false end if
start report output to filename
let curs = 1
if listfetchid(curs) is not null then
  if withhead and titlines[rec] > 0 then
    if totcols[rec] < 66 then let j = 66
    else let j = totcols[rec]
    end if
    let i = j - 32
    let ptxt = mtitle[rec,1][1,i],uname
    output to report output(ptxt,true)
    for curlin = 2 to titlines[rec] step 1
      output to report output(mtitle[rec,curlin],true)
    end for
    let ptxt = null
    for i = 1 to j let ptxt = ptxt clipped,"¯" end for
    output to report output(ptxt,true)
  end if
  while true
    let ptxt = listformat()
    let i = totcols[rec]
    output to report output(ptxt[1,i],true)
    let curs = curs + 1
    if listfetchid(curs) is null then exit while end if
  end while
end if
finish report output
call msgclose()

end function

################################################################################
# Output of list to file.
################################################################################

function listpmail()

define
  curs integer,
  filename char(80),
  dscrname char(80),
  withhead char,
  maddr,msubj char(48),
  md1,md2,md3,md4,md5 char(80),
  i,j smallint
call pmail(defemail(),"") returning withhead,maddr,msubj,md1,md2,md3,md4,md5
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
let curs = 1
if listfetchid(curs) is not null then
  if withhead and titlines[rec] > 0 then
    if totcols[rec] < 66 then let j = 66
    else let j = totcols[rec]
    end if
    let i = j - 32
    let ptxt = mtitle[rec,1][1,i],uname
    output to report output(ptxt,true)
    for curlin = 2 to titlines[rec] step 1
      output to report output(mtitle[rec,curlin],true)
    end for
    let ptxt = null
    for i = 1 to j let ptxt = ptxt clipped,"¯" end for
    output to report output(ptxt,true)
  end if
  while true
    let ptxt = listformat()
    let i = totcols[rec]
    output to report output(ptxt[1,i],true)
    let curs = curs + 1
    if listfetchid(curs) is null then exit while end if
  end while
end if
finish report output
call sendmail(filename,msubj,dscrname,maddr)
call msgclose()
call remtempfile(filename)
call remtempfile(dscrname)

end function

################################################################################
# Output of list to printer.
################################################################################

function listprint()

define
  pipename char(128),
  copies smallint,
  xprsetup,xprreset char(64),
  curs integer,
  i smallint
call print(defprinter[rec],"",80)
  returning pipename,dummy,copies,paglen,xprsetup,xprreset
if copies is null then return end if
call msgopen("printing")
if titlines[rec] > 0 then let paglen = paglen - titlines[rec] - 4 end if
for copies = copies to 1 step -1
  let prsetup = xprsetup
  let prreset = xprreset
  start report output to pipe pipename
  let curpag = 0
  let curs = 1
  if listfetchid(curs) is not null then
    call list_header()
    while true
      if curlin >= paglen then
        call list_trailer(true)
        call list_header()
      end if
      let curlin = curlin + 1
      let ptxt = listformat()
      let i = totcols[rec]
      output to report output(ptxt[1,i],true)
      let curs = curs + 1
      if listfetchid(curs) is null then exit while end if
    end while
    if aggryes[rec] then
      if curlin >= paglen then
        call list_trailer(true)
        call list_header()
      end if
      let ptxt = aggrdat[rec]
      output to report output(prenh("B",ptxt[1,i]),true)
    end if
    call list_trailer(false)
  end if
  finish report output
end for
call msgclose()

end function

################################################################################
# Output of page header to printer or pipe.
################################################################################

function list_header()

define i,j smallint
let curpag = curpag + 1
if titlines[rec] > 0 then
  if totcols[rec] < 66 then let j = 66
  else let j = totcols[rec]
  end if
  let i = j - 32
  let ptxt = mtitle[rec,1][1,i],uname
  let ptxt = prsetup clipped,prenh(mtform[rec,1],ptxt clipped)
  output to report output(ptxt,true)
  output to report output("",true)
  for curlin = 2 to titlines[rec] step 1
    output to report output(prenh(mtform[rec,curlin],mtitle[rec,curlin]),true)
  end for
  let ptxt = null
  for i = 1 to j let ptxt = ptxt clipped,"¯" end for
  output to report output(ptxt,true)
  output to report output(prenh("bui",""),false)
else output to report output(prsetup,false)
end if
let prsetup = null
let curlin = 0

end function

################################################################################
# Output of page trailer to printer or pipe.
################################################################################

function list_trailer(ff)

define ff,i,j smallint
if titlines[rec] > 0 then
  while curlin < paglen
    let curlin = curlin + 1
    output to report output("",true)
  end while
  if totcols[rec] < 66 then let j = 66
  else let j = totcols[rec]
  end if
  let ptxt = null
  for i = 1 to j let ptxt = ptxt clipped,"_" end for
  output to report output(prenh("B",ptxt clipped),true)
  let i = j / 2 - 8
  let j = j - 31
  let ptxt = utime,column i,curpag using "##########",column j,uid
else let ptxt = null
end if
if ff then let ptxt = ptxt clipped,prreset end if
if ptxt is not null then
  output to report output(ptxt,false)
end if
 
end function

################################################################################
# Output of list to special pipe.
################################################################################

function listppipe()

define
  ppipeid char(32),
  withhead char,
  pipestr char(128),
  curs integer,
  i,j smallint
call ppipe(defpipe[rec]) returning ppipeid,pipestr,withhead
if ppipeid is null then return end if
call msgopen("printing")
if withhead is null then let withhead = false end if
let curs = 1
if listfetchid(curs) is not null then
  call ppipebeg(pipestr)
  if withhead and titlines[rec] > 0 then
    if totcols[rec] < 66 then let j = 66
    else let j = totcols[rec]
    end if
    let i = j - 32
    let ptxt = mtitle[rec,1][1,i],uname
    call ppipeout(ptxt clipped)
    for curlin = 2 to titlines[rec] step 1
      call ppipeout(mtitle[rec,curlin])
    end for
    let ptxt = null
    for i = 1 to j let ptxt = ptxt clipped,"¯" end for
    call ppipeout(ptxt clipped)
  end if
  while true
    let ptxt = listformat()
    let i = totcols[rec]
    call ppipeout(ptxt[1,i])
    let curs = curs + 1
    if listfetchid(curs) is null then exit while end if
  end while
  call ppipeend()
end if
call msgclose()

end function
