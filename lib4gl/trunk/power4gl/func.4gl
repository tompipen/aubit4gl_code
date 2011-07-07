################################################################################
# General functions (independent of system and database).
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
  systemname char(32),                          # System name.
  systemid char(32),                            # System id.
  systemver char(16),                           # System version.
  savecode char(80),				# Saved code.
  lines char(8),				# Number of terminal lines.
  paglen,curlin smallint,
  curpag integer,
  prsetup,prreset char(64),
  prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx char(64),
  uname char(32),
  uid char(32),
  jtype char(1),				# b=background. f=foreground.
  utime datetime year to minute,
  oldtime datetime year to fraction,		# Last set time.
  winnr smallint,                               # Current window number.
  winname array[32] of char(16),                # Window name array.
  winid array[32] of char(8),			# Window id.
  winstop char,					# Control endless recursive loops.
  formopen array[32] of char,                   # Whether separate form open.
  dblogstat char(1),                            # Database logging flag.
  logfile char(128),				# Error log file.
  msgnr smallint,                               # Message window number.
  msgwidth array[8] of smallint,                # Message window width.
  pstr char(1000),				# String for parsing
  ppos integer,					# current position in parsestring
  plen integer,					# length of parsestring
  ppgrpnr smallint,				# Lines in pipe output.
  job record                                    # Batch job settings.
    jobname char(32),
    atdt datetime year to minute,
    atrep char(1),
    prname char(32),
    pfile char(32),
    maddr char(48),
    msubj char(48),
    mailto char(32),
    cmd char(2000)
  end record

################################################################################
# Start error logging to file.
################################################################################

function start_log(filename)

define filename char(128)
let logfile = filename
call startlog(logfile)

end function

################################################################################
# Suspend error logging to file (if it is active).
################################################################################

function suspend_log()

if logfile is not null then
  call startlog("/dev/null")
end if

end function

################################################################################
# Resume error logging to file (if it has been suspended).
################################################################################

function resume_log()

if logfile is not null then
  call startlog(logfile)
end if

end function

################################################################################
# Write line to error log file (if it is active).
################################################################################

function write_log(txt)

define txt char(128)
if logfile is not null then
  call errorlog(txt clipped)
end if

end function

################################################################################
# Set code for later processing.
################################################################################

function setscode(code)

define code char(80)
let savecode = code

end function

################################################################################
# Retrieve saved code.
################################################################################

function getscode()

return savecode

end function

################################################################################
# Window title retrieval.
################################################################################

function title(name,type,line)

define
  name char(80),
  type char(1),
  line char(2)
return trim(rawtitle(name,type,line),"|")

end function

################################################################################
# Window title retrieval (raw).
################################################################################

function rawtitle(name,type,line)

define
  name char(80),
  type char(1),
  line char(2),
  table,key char(24),
  text char(512)
let text = null
if line is null then let line = "1" end if
if length(name) <= 16 then
  let table = "title.tbl"
  let key = type,"|",name[1,16],"|",line,"|"
  let text = gettx(table,key)
end if
if text is null and line = "1" then let text = name end if
return text clipped

end function

################################################################################
# Menu label retrieval.
################################################################################

function label(name,type)

define
  name char(80),
  type char(1),
  table,key char(24),
  text char(100)
let text = null
if length(name) <= 16 then
  let table = "label.tbl"
  let key = type,"|",name[1,16],"|"
  let text = gettx(table,key)
end if
if text is null then let text = name end if
return text clipped

end function

################################################################################
# Word retrieval.
################################################################################

function word(code)

define
  code char(80),
  table,key char(24),
  text char(100)
let text = null
if length(code) <= 16 then
  let table = "word.tbl"
  let key = code[1,16],"|"
  let text = gettx(table,key)
end if
if text is null then let text = code end if
return text clipped

end function

################################################################################
# Word retrieval with upshift of first character.
################################################################################

function upfword(code)

define code char(80)
return upf(word(code)) clipped

end function

################################################################################
# Word retrieval with upshift.
################################################################################

function upshword(code)

define code char(80)
return upper(word(code))

end function

################################################################################
# Single line message retrieval.
################################################################################

function stx(code)

define
  code char(80),
  table,key char(24),
  text char(512)
let text = null
if length(code) <= 16 then
  let table = "stx.tbl"
  let key = code[1,16],"|"
  let text = gettx(table,key)
end if
if text is null then let text = code end if
return text clipped

end function

################################################################################
# Multiple line message retrieval.
################################################################################

function mtx(code)

define
  code char(80),
  line char(2),
  table,key char(24),
  text array[8] of char(512),
  i,found smallint
let found = false
initialize text to null
if length(code) <= 16 then
  let table = "mtx.tbl"
  for i = 1 to 8
    let line = i
    let key = code[1,16],"|",line,"|"
    let text[i] = gettx(table,key)
    if text[i] is not null then let found = true end if
  end for
end if
if not found then let text[1] = code end if
return text[1] clipped,text[2] clipped,text[3] clipped,text[4] clipped
  ,text[5] clipped,text[6] clipped,text[7] clipped,text[8] clipped

end function

###############################################################################
# Cpu and real time timer reset.
###############################################################################

function timerset()

define
  newtime datetime year to fraction,
  newdiff interval day(5) to fraction
let newtime = current
if oldtime is null then let oldtime = newtime end if
let newdiff = newtime - oldtime
let oldtime = newtime
return newtime,newdiff

end function

###############################################################################
# Character repetition.
###############################################################################

function repchar(rtxt,rlen,tlen)

define
  rtxt char(32),
  rlen,tlen smallint,
  ttxt char(512),
  i smallint
if rtxt is null then return "" end if
if rlen is null then let rlen = length(rtxt) end if
if rlen < 1 then let rlen = 1 end if
if rlen > 32 then let rlen = 32 end if
if tlen is null then let tlen = rlen end if
if tlen < rlen then let tlen = rlen end if
if tlen > 512 then let tlen = 512 end if
let ttxt = rtxt[1,rlen]
for i = rlen to tlen + rlen step rlen
  let ttxt = ttxt[1,i],rtxt[1,rlen]
end for
return ttxt[1,tlen]

end function

###############################################################################
# Window opening with form, fail on error.
###############################################################################

function winform(fname,row,col)

define
  fname char(16),
  row,col smallint
call winopen(fname,row,col,0,0)

end function

###############################################################################
# Window opening with form, error handled.
###############################################################################

function winformx(fname,row,col)

define
  fname char(16),
  row,col smallint
if winopen2(fname,row,col,0,0) <> 0 then
  call pause("winnofit",8,8)
  return false
end if
return true

end function

###############################################################################
# Window opening, fail on error.
###############################################################################

function winopen(wname,row,col,nr,nc)

define
  wname char(32),
  row,col,nr,nc smallint,
  errcode integer
let errcode = winopen2(wname,row,col,nr,nc)
if errcode <> 0 then
  if winstop then let winstop = false
  else
    let winstop = true
    call pause("winnofit",8,8)
  end if
  let wname = "winopen-",wname
  call progerrq(wname,errcode,winnr)
end if

end function

###############################################################################
# Window opening, error handling option.
###############################################################################

function winopen2(wname,row,col,nr,nc)

define
  wname char(16),
  row,col,nr,nc smallint,
  isform char,
  withborder char,
  maxlines smallint,
  errcode integer,
  txt char(128)
if winnr is null then let winnr = 1
else let winnr = winnr + 1
end if
let maxlines = getlines()
let maxlines = maxlines - 1
let winname[winnr] = wname
let winid[winnr] = "win",winnr using "&&"
let formopen[winnr] = false
if nr is null then let nr = 0 end if
if nc is null then let nc = 0 end if
if nr = 0 and nc = 0 then let isform = true
else let isform = false
end if
if row = 0 or row is null then let row = 5 end if
if col = 0 or col is null then let col = 2 end if
if row = 1 then let col = 1 end if
if col = 1 then
  let nc = 80
  let row = 1
  let withborder = false
else let withborder = true
end if
let txt = "Open window: ",winname[winnr] clipped
  ," (id ",winid[winnr] clipped,", level ",winnr using "<<<<",")"
call write_log(txt)
let errcode = 0
whenever error continue
while true
  if isform then
    if withborder then
      case winnr
      when 01 open window win01 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 02 open window win02 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 03 open window win03 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 04 open window win04 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 05 open window win05 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 06 open window win06 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 07 open window win07 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 08 open window win08 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 09 open window win09 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 10 open window win10 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 11 open window win11 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 12 open window win12 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 13 open window win13 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 14 open window win14 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 15 open window win15 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 16 open window win16 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 17 open window win17 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 18 open window win18 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 19 open window win19 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 20 open window win20 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 21 open window win21 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 22 open window win22 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 23 open window win23 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 24 open window win24 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 25 open window win25 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 26 open window win26 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 27 open window win27 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 28 open window win28 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 29 open window win29 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 30 open window win30 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      when 31 open window win31 at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      otherwise open window win at row,col with form wname
        attribute(comment line off,prompt line last-1,border)
      end case
      let errcode = status
    else	-- without border
      let formopen[winnr] = true
      if maxlines < 24 then
        case winnr
        when 01 open window win01 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win01 from wname display form win01
        when 02 open window win02 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win02 from wname display form win02
        when 03 open window win03 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win03 from wname display form win03
        when 04 open window win04 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win04 from wname display form win04
        when 05 open window win05 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win05 from wname display form win05
        when 06 open window win06 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win06 from wname display form win06
        when 07 open window win07 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win07 from wname display form win07
        when 08 open window win08 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win08 from wname display form win08
        when 09 open window win09 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win09 from wname display form win09
        when 10 open window win10 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win10 from wname display form win10
        when 11 open window win11 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win11 from wname display form win11
        when 12 open window win12 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win12 from wname display form win12
        when 13 open window win13 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win13 from wname display form win13
        when 14 open window win14 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win14 from wname display form win14
        when 15 open window win15 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win15 from wname display form win15
        when 16 open window win16 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win16 from wname display form win16
        when 17 open window win17 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win17 from wname display form win17
        when 18 open window win18 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win18 from wname display form win18
        when 19 open window win19 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win19 from wname display form win19
        when 20 open window win20 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win20 from wname display form win20
        when 21 open window win21 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win21 from wname display form win21
        when 22 open window win22 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win22 from wname display form win22
        when 23 open window win23 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win23 from wname display form win23
        when 24 open window win24 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win24 from wname display form win24
        when 25 open window win25 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win25 from wname display form win25
        when 26 open window win26 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win26 from wname display form win26
        when 27 open window win27 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win27 from wname display form win27
        when 28 open window win28 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win28 from wname display form win28
        when 29 open window win29 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win29 from wname display form win29
        when 30 open window win30 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win30 from wname display form win30
        when 31 open window win31 at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win31 from wname display form win31
        otherwise open window win at 1,1 with 23 rows,80 columns
          attribute(comment line off,form line 2)
          open form win from wname display form win
        end case
        let errcode = status
      else	-- maxlines >= 24
        case winnr
        when 01 open window win01 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win01 from wname display form win01
        when 02 open window win02 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win02 from wname display form win02
        when 03 open window win03 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win03 from wname display form win03
        when 04 open window win04 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win04 from wname display form win04
        when 05 open window win05 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win05 from wname display form win05
        when 06 open window win06 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win06 from wname display form win06
        when 07 open window win07 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win07 from wname display form win07
        when 08 open window win08 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win08 from wname display form win08
        when 09 open window win09 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win09 from wname display form win09
        when 10 open window win10 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win10 from wname display form win10
        when 11 open window win11 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win11 from wname display form win11
        when 12 open window win12 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win12 from wname display form win12
        when 13 open window win13 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win13 from wname display form win13
        when 14 open window win14 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win14 from wname display form win14
        when 15 open window win15 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win15 from wname display form win15
        when 16 open window win16 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win16 from wname display form win16
        when 17 open window win17 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win17 from wname display form win17
        when 18 open window win18 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win18 from wname display form win18
        when 19 open window win19 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win19 from wname display form win19
        when 20 open window win20 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win20 from wname display form win20
        when 21 open window win21 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win21 from wname display form win21
        when 22 open window win22 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win22 from wname display form win22
        when 23 open window win23 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win23 from wname display form win23
        when 24 open window win24 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win24 from wname display form win24
        when 25 open window win25 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win25 from wname display form win25
        when 26 open window win26 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win26 from wname display form win26
        when 27 open window win27 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win27 from wname display form win27
        when 28 open window win28 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win28 from wname display form win28
        when 29 open window win29 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win29 from wname display form win29
        when 30 open window win30 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win30 from wname display form win30
        when 31 open window win31 at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win31 from wname display form win31
        otherwise open window win at 1,1 with maxlines rows,80 columns
          attribute(comment line off,prompt line last-1,message line last-1,form line 2)
          open form win from wname display form win
        end case
        let errcode = status
      end if
    end if
  else	-- is not form
    if nr = 0 then let nr = 20 end if
    if nc = 0 then let nc = 60 end if
    if nr > maxlines - 2 then let nr = maxlines end if
    if nc > 78 then let nc = 80 end if
    if nr = maxlines then let nc = 80 end if
    if withborder then
      case winnr
      when 01 open window win01 at row,col with nr rows, nc columns attribute(border)
      when 02 open window win02 at row,col with nr rows, nc columns attribute(border)
      when 03 open window win03 at row,col with nr rows, nc columns attribute(border)
      when 04 open window win04 at row,col with nr rows, nc columns attribute(border)
      when 05 open window win05 at row,col with nr rows, nc columns attribute(border)
      when 06 open window win06 at row,col with nr rows, nc columns attribute(border)
      when 07 open window win07 at row,col with nr rows, nc columns attribute(border)
      when 08 open window win08 at row,col with nr rows, nc columns attribute(border)
      when 09 open window win09 at row,col with nr rows, nc columns attribute(border)
      when 10 open window win10 at row,col with nr rows, nc columns attribute(border)
      when 11 open window win11 at row,col with nr rows, nc columns attribute(border)
      when 12 open window win12 at row,col with nr rows, nc columns attribute(border)
      when 13 open window win13 at row,col with nr rows, nc columns attribute(border)
      when 14 open window win14 at row,col with nr rows, nc columns attribute(border)
      when 15 open window win15 at row,col with nr rows, nc columns attribute(border)
      when 16 open window win16 at row,col with nr rows, nc columns attribute(border)
      when 17 open window win17 at row,col with nr rows, nc columns attribute(border)
      when 18 open window win18 at row,col with nr rows, nc columns attribute(border)
      when 19 open window win19 at row,col with nr rows, nc columns attribute(border)
      when 20 open window win20 at row,col with nr rows, nc columns attribute(border)
      when 21 open window win21 at row,col with nr rows, nc columns attribute(border)
      when 22 open window win22 at row,col with nr rows, nc columns attribute(border)
      when 23 open window win23 at row,col with nr rows, nc columns attribute(border)
      when 24 open window win24 at row,col with nr rows, nc columns attribute(border)
      when 25 open window win25 at row,col with nr rows, nc columns attribute(border)
      when 26 open window win26 at row,col with nr rows, nc columns attribute(border)
      when 27 open window win27 at row,col with nr rows, nc columns attribute(border)
      when 28 open window win28 at row,col with nr rows, nc columns attribute(border)
      when 29 open window win29 at row,col with nr rows, nc columns attribute(border)
      when 30 open window win30 at row,col with nr rows, nc columns attribute(border)
      when 31 open window win31 at row,col with nr rows, nc columns attribute(border)
      otherwise open window win at row,col with nr rows, nc columns attribute(border)
      end case
      let errcode = status
    else
      if nr < maxlines then
        let row = nr + 1
        case winnr
        when 01 open window win01 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 02 open window win02 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 03 open window win03 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 04 open window win04 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 05 open window win05 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 06 open window win06 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 07 open window win07 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 08 open window win08 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 09 open window win09 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 10 open window win10 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 11 open window win11 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 12 open window win12 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 13 open window win13 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 14 open window win14 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 15 open window win15 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 16 open window win16 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 17 open window win17 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 18 open window win18 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 19 open window win19 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 20 open window win20 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 21 open window win21 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 22 open window win22 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 23 open window win23 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 24 open window win24 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 25 open window win25 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 26 open window win26 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 27 open window win27 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 28 open window win28 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 29 open window win29 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 30 open window win30 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        when 31 open window win31 at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        otherwise open window win at 1,1 with row rows, 80 columns attribute(prompt line last-1,message line last-1)
        end case
        let errcode = status
        if errcode = 0 then
          display
            "                                                                                "
            at row,1 attribute(normal,underline)
          let errcode = status
          if errcode <> 0 then
            call winclose()
            return errcode
          end if
        end if
      else
        case winnr
        when 01 open window win01 at 1,1 with nr rows, 80 columns
        when 02 open window win02 at 1,1 with nr rows, 80 columns
        when 03 open window win03 at 1,1 with nr rows, 80 columns
        when 04 open window win04 at 1,1 with nr rows, 80 columns
        when 05 open window win05 at 1,1 with nr rows, 80 columns
        when 06 open window win06 at 1,1 with nr rows, 80 columns
        when 07 open window win07 at 1,1 with nr rows, 80 columns
        when 08 open window win08 at 1,1 with nr rows, 80 columns
        when 09 open window win09 at 1,1 with nr rows, 80 columns
        when 10 open window win10 at 1,1 with nr rows, 80 columns
        when 11 open window win11 at 1,1 with nr rows, 80 columns
        when 12 open window win12 at 1,1 with nr rows, 80 columns
        when 13 open window win13 at 1,1 with nr rows, 80 columns
        when 14 open window win14 at 1,1 with nr rows, 80 columns
        when 15 open window win15 at 1,1 with nr rows, 80 columns
        when 16 open window win16 at 1,1 with nr rows, 80 columns
        when 17 open window win17 at 1,1 with nr rows, 80 columns
        when 18 open window win18 at 1,1 with nr rows, 80 columns
        when 19 open window win19 at 1,1 with nr rows, 80 columns
        when 20 open window win20 at 1,1 with nr rows, 80 columns
        when 21 open window win21 at 1,1 with nr rows, 80 columns
        when 22 open window win22 at 1,1 with nr rows, 80 columns
        when 23 open window win23 at 1,1 with nr rows, 80 columns
        when 24 open window win24 at 1,1 with nr rows, 80 columns
        when 25 open window win25 at 1,1 with nr rows, 80 columns
        when 26 open window win26 at 1,1 with nr rows, 80 columns
        when 27 open window win27 at 1,1 with nr rows, 80 columns
        when 28 open window win28 at 1,1 with nr rows, 80 columns
        when 29 open window win29 at 1,1 with nr rows, 80 columns
        when 30 open window win30 at 1,1 with nr rows, 80 columns
        when 31 open window win31 at 1,1 with nr rows, 80 columns
        otherwise open window win at 1,1 with nr rows, 80 columns
        end case
        let errcode = status
      end if
    end if
  end if
  if errcode = 0 then exit while
  else
    if withborder then
      if row < 5 and col = 2 then
        let withborder = false
        let row = 1
        let col = 1
      else
        if row > 2 then let row = (row + 3) / 2 end if
        if col > 2 then let col = col - 1 end if
      end if
    else
      if row = 1 and col = 1 then
        let formopen[winnr] = false
        call winclose()
        return errcode
      else
        let row = 1
        let col = 1
      end if
    end if
  end if
end while
whenever error stop
return errcode

end function

###############################################################################
# Make a window current.
###############################################################################

function wincurrent(cwinname)

define
  cwinname char(16),
  cwinid char(8),
  cformopen char,
  i,j smallint,
  txt char(128)
for i = winnr to 1 step -1
  if winname[i] = cwinname then
    case winid[i]
    when "win01" current window is win01
    when "win02" current window is win02
    when "win03" current window is win03
    when "win04" current window is win04
    when "win05" current window is win05
    when "win06" current window is win06
    when "win07" current window is win07
    when "win08" current window is win08
    when "win09" current window is win09
    when "win10" current window is win10
    when "win11" current window is win11
    when "win12" current window is win12
    when "win13" current window is win13
    when "win14" current window is win14
    when "win15" current window is win15
    when "win16" current window is win16
    when "win17" current window is win17
    when "win18" current window is win18
    when "win19" current window is win19
    when "win20" current window is win20
    when "win21" current window is win21
    when "win22" current window is win22
    when "win23" current window is win23
    when "win24" current window is win24
    when "win25" current window is win25
    when "win26" current window is win26
    when "win27" current window is win27
    when "win28" current window is win28
    when "win29" current window is win29
    when "win30" current window is win30
    when "win31" current window is win31
    otherwise current window is win
    end case
    let cwinid = winid[i]
    let cformopen = formopen[i]
    for j = i to winnr - 1 step 1
      let winname[j] = winname[j+1]
      let winid[j] = winid[j+1]
      let formopen[j] = formopen[j+1]
    end for
    let winname[winnr] = cwinname
    let winid[winnr] = cwinid
    let formopen[winnr] = cformopen
    exit for
  end if
end for
let txt = "Current window: ",winname[winnr] clipped
  ," (id ",winid[winnr] clipped,", level ",winnr using "<<<<",")"
call write_log(txt)

end function

###############################################################################
# Window closing.
###############################################################################

function winclose()

define txt char(128)
if winnr > 0 then else return end if
let txt = "Close window: ",winname[winnr] clipped
  ," (id ",winid[winnr] clipped,", level ",winnr using "<<<<",")"
call write_log(txt)
if not formopen[winnr] then
  case winid[winnr]
  when "win01" close window win01
  when "win02" close window win02
  when "win03" close window win03
  when "win04" close window win04
  when "win05" close window win05
  when "win06" close window win06
  when "win07" close window win07
  when "win08" close window win08
  when "win09" close window win09
  when "win10" close window win10
  when "win11" close window win11
  when "win12" close window win12
  when "win13" close window win13
  when "win14" close window win14
  when "win15" close window win15
  when "win16" close window win16
  when "win17" close window win17
  when "win18" close window win18
  when "win19" close window win19
  when "win20" close window win20
  when "win21" close window win21
  when "win22" close window win22
  when "win23" close window win23
  when "win24" close window win24
  when "win25" close window win25
  when "win26" close window win26
  when "win27" close window win27
  when "win28" close window win28
  when "win29" close window win29
  when "win30" close window win30
  when "win31" close window win31
  otherwise close window win
  end case
else
  case winid[winnr]
  when "win01" close form win01 close window win01
  when "win02" close form win02 close window win02
  when "win03" close form win03 close window win03
  when "win04" close form win04 close window win04
  when "win05" close form win05 close window win05
  when "win06" close form win06 close window win06
  when "win07" close form win07 close window win07
  when "win08" close form win08 close window win08
  when "win09" close form win09 close window win09
  when "win10" close form win10 close window win10
  when "win11" close form win11 close window win11
  when "win12" close form win12 close window win12
  when "win13" close form win13 close window win13
  when "win14" close form win14 close window win14
  when "win15" close form win15 close window win15
  when "win16" close form win16 close window win16
  when "win17" close form win17 close window win17
  when "win18" close form win18 close window win18
  when "win19" close form win19 close window win19
  when "win20" close form win20 close window win20
  when "win21" close form win21 close window win21
  when "win22" close form win22 close window win22
  when "win23" close form win23 close window win23
  when "win24" close form win24 close window win24
  when "win25" close form win25 close window win25
  when "win26" close form win26 close window win26
  when "win27" close form win27 close window win27
  when "win28" close form win28 close window win28
  when "win29" close form win29 close window win29
  when "win30" close form win30 close window win30
  when "win31" close form win31 close window win31
  otherwise close form win close window win
  end case
end if
let winname[winnr] = null
let winnr = winnr - 1

end function

###############################################################################
# Window clearing.
###############################################################################

function winclear()

define txt char(128)
if winnr > 0 then else return end if
let txt = "Clear window: ",winname[winnr] clipped
  ," (id ",winid[winnr] clipped,", level ",winnr using "<<<<",")"
call write_log(txt)
case winid[winnr]
when "win01" clear window win01
when "win02" clear window win02
when "win03" clear window win03
when "win04" clear window win04
when "win05" clear window win05
when "win06" clear window win06
when "win07" clear window win07
when "win08" clear window win08
when "win09" clear window win09
when "win10" clear window win10
when "win11" clear window win11
when "win12" clear window win12
when "win13" clear window win13
when "win14" clear window win14
when "win15" clear window win15
when "win16" clear window win16
when "win17" clear window win17
when "win18" clear window win18
when "win19" clear window win19
when "win20" clear window win20
when "win21" clear window win21
when "win22" clear window win22
when "win23" clear window win23
when "win24" clear window win24
when "win25" clear window win25
when "win26" clear window win26
when "win27" clear window win27
when "win28" clear window win28
when "win29" clear window win29
when "win30" clear window win30
when "win31" clear window win31
otherwise clear window win
end case

end function

###############################################################################
# Report output line.
###############################################################################

report output(txt,cr)

define
  txt char(512),
  cr char
output left margin 0 top margin 0 bottom margin 0 page length 1
format on every row
  if cr then print txt clipped
  else print txt clipped;
  end if

end report

###############################################################################
# Upshift function including international letters.
###############################################################################

function upper(text)

define
  text char(200),
  i smallint
for i = length(text) to 1 step -1
  case text[i]
  when "á" let text[i] = "Á"
  when "é" let text[i] = "É"
  when "í" let text[i] = "Í"
  when "ó" let text[i] = "Ó"
  when "ú" let text[i] = "Ú"
  when "ý" let text[i] = "Ý"
  when "ö" let text[i] = "Ö"
  when "ð" let text[i] = "Ð"
  when "æ" let text[i] = "Æ"
  when "þ" let text[i] = "Þ"
  end case
end for
let text = upshift(text)
return text clipped

end function

function upsh(text)

define
  text char(200)
let text = upper(text)
return text clipped

end function

################################################################################
# Upshift of the first letter in a text string.
################################################################################

function upf(text)

define text char(200)
if text is not null then let text[1] = upper(text[1]) end if
return text clipped

end function

###############################################################################
# Downshift function including international letters.
###############################################################################

function lower(text)

define
  text char(200),
  i smallint
for i = length(text) to 1 step -1
  case text[i]
  when "Á" let text[i] = "á"
  when "É" let text[i] = "é"
  when "Í" let text[i] = "í"
  when "Ó" let text[i] = "ó"
  when "Ú" let text[i] = "ú"
  when "Ý" let text[i] = "ý"
  when "Ö" let text[i] = "ö"
  when "Ð" let text[i] = "ð"
  when "Æ" let text[i] = "æ"
  when "Þ" let text[i] = "þ"
  end case
end for
let text = downshift(text)
return text clipped

end function

function downsh(text)

define
  text char(200)
let text = lower(text)
return text clipped

end function

################################################################################
# Conversion of interval time period to decimal hour format.
################################################################################

function hourtime(i)

define
  i interval minute(9) to minute,
  x char(10),
  d decimal
let x = i
let d = x
let d = d / 60
return d

end function

################################################################################
# Conversion of interval time period to decimal second format.
################################################################################

function sectime(i)

define
  i interval second(9) to fraction,
  i2 interval second(9) to second,
  x char(32),
  d decimal(16,2)
let i2 = i * 1000
let x = i
let d = x / 1000
return d

end function

################################################################################
# Conversion of interval time period to integer month format.
################################################################################

function monthtime(iv)

define
  iv interval month(9) to month,
  x char(32),
  i integer
let x = iv
let i = x
return i

end function

################################################################################
# Conversion of decimal seconds to interval time period.
################################################################################

function secinterv(d)

define
  d decimal(12,2),
  x char(32),
  i interval second(9) to fraction
let d = d * 100
let x = d using "-----------&",".00"
let i = x
let i = i / 100
return i

end function

################################################################################
# Calculation of ratio between two minute intervals.
################################################################################

function minuteratio(i1,i2)

define
  i1,i2 interval minute(9) to minute,
  x1,x2 char(10),
  d decimal
let x1 = i1
let x2 = i2
let d = x1 / x2
return d

end function

################################################################################
# Calculation of ratio between two second intervals.
################################################################################

function secondratio(i1,i2)

define
  i1,i2 interval second(9) to second,
  x1,x2 char(10),
  d decimal
let x1 = i1
let x2 = i2
let d = x1 / x2
return d

end function

################################################################################
# Calculation of ratio between two second intervals.
################################################################################

function monthratio(i1,i2)

define
  i1,i2 interval month(9) to month,
  x1,x2 char(10),
  d decimal
let x1 = i1
let x2 = i2
let d = x1 / x2
return d

end function

################################################################################
# Change a blank string to null.
################################################################################

function bn(chr)

define chr char(2000)
if chr = " " or chr is null then return "" end if
return chr clipped

end function

################################################################################
# Completely trim a character value, changing a blank value to null.
################################################################################

function shave(chr)

define chr char(2000)
if chr = " " or chr is null then return "" end if
return left(chr) clipped

end function

################################################################################
# Turn a null value into a blank.
################################################################################

function blank(chr)

define chr char(2000)
if chr is null then return " " end if
return left(chr) clipped

end function

################################################################################
# Return first non null value.
################################################################################

function firstnn(txt1,txt2)

define txt1,txt2 char(255)
if txt1 = " " then let txt1 = null end if
if txt2 = " " then let txt2 = null end if
if txt1 is null then return txt2 clipped end if
return txt1 clipped

end function

################################################################################
# Comparison of two values with null handled as a special value.
################################################################################

function same(val1,val2)

define val1,val2 char(80)
case
when val1 = val2 return true
when val1 is null and val2 is null return true
otherwise return false
end case

end function

################################################################################
# Comparison of two values with null handled as a special value.
# True if first value is greater.
################################################################################

function greater(val1,val2)

define val1,val2 char(80)
case
when val1 > val2 return true
when val1 is not null and val2 is null return true
otherwise return false
end case

end function

################################################################################
# Comparison of two values with null handled as a special value.
# True if first value is lesser.
################################################################################

function lesser(val1,val2)

define val1,val2 char(80)
case
when val1 < val2 return true
when val1 is not null and val2 is null return true
otherwise return false
end case

end function

################################################################################
# Comparison of two decimal values for similarity by a factor.
################################################################################

function similar(v1,v2,d,f)
  
define
  v1,v2 decimal(32),
  d,f decimal
if same(v1,v2) then return true end if
if d is not null then
  case
  when v1 < v2
    if (v1+d) >= v2 then return true end if
  when v1 > v2
    if (v1-d) <= v2 then return true end if
  end case
end if
if f is not null then
  case
  when v1 < v2
    if v1 * (1 + f) >= v2 then return true end if
  when v1 > v2
    if v1 / (1 + f) <= v2 then return true end if
  end case
end if
return false

end function

################################################################################
# Incrementation of counter based on whether the host variable is null or not.
################################################################################

function cntincr(cnt,val)

define
  cnt integer,
  val char(32)
case
when val is null return cnt
when cnt is null return 1
otherwise return (cnt + 1)
end case

end function

################################################################################
# Absolute value
################################################################################

function absval(val)

define val decimal
if val < 0 and val is not null then return -val else return val end if

end function

################################################################################
# Format number.
################################################################################

function formatnum(num,formlen,decpl,useth)

define
  num decimal(32),
  formlen,decpl smallint,
  useth char,
  formstr char(32),
  i,decpos smallint
let num = round(num,decpl)
let formstr = num using "-------------------&.&&&&&&&&&&&"
let formstr = fgl_strrep(formstr,".",",")
let decpos = 21
if useth then
  for i = decpos-4 to 1 step - 4
    if formstr[i,i] > " " and formstr[i,i] <> "-" then
      if formstr[1,1] <> " " then
        let formstr = "################################" -- Overflow condition.
        exit for
      end if
      let formstr = formstr[2,i],".",formstr[i+1,32]
    end if
  end for
end if
if decpl <= 0 then let decpl = decpl - 1 end if
let i = decpos+decpl-formlen
if i > 0 then
  if formstr[i,i] <> " " then
    let formstr = "################################" -- Overflow condition.
  end if
end if
return formstr[i+1,decpos+decpl]

end function

################################################################################
# Rounding of a decimal number to a decimal place.
################################################################################

function round(dval,dpos)

define
  dval decimal,
  dpos smallint,
  ival decimal(16,0)
let ival = dval * (10 ** dpos)
let dval = ival / (10 ** dpos)
return dval

end function

################################################################################
# Truncating of a decimal number to a decimal place.
################################################################################

function trunc(dval,dpos)

define
  dval decimal,
  dpos smallint,
  ival decimal(16,0)
case
when dval > 0 let ival = dval * (10 ** dpos) - 0.5
when dval < 0 let ival = dval * (10 ** dpos) + 0.5
otherwise return dval
end case
let dval = ival / (10 ** dpos)
return dval

end function

################################################################################
# Decimal value raised to the power of another decimal value with null handling.
################################################################################

function power(val1,val2)

define
  val1,val2,val3 decimal(32)
if val1 is null or val2 is null then return "" end if
let val1 = val1 * 100000000 * 100000000
let val2 = val2 * 100000000 * 100000000
let val3 = cpower(val1,val2)
return val3

end function

################################################################################
# Addition of two numbers with null handled as a special value.
################################################################################

function add(val1,val2)

define val1,val2 decimal
case
when val1 is null return val2
when val2 is null return val1
otherwise return (val1 + val2)
end case

end function

################################################################################
# Addition of two numbers which lets null equal to zero	
################################################################################

function add0(val1,val2)

define val1,val2 decimal

if val1 is null then let val1 = 0 end if
if val2 is null then let val2 = 0 end if
return (val1 + val2)

end function

################################################################################
# Addition of two intervals with null handling.
################################################################################

function addiv(val1,val2)

define val1,val2 interval day(6) to fraction
case
when val1 is null and val2 is null return ""
when val1 is null return val2
when val2 is null return val1
otherwise return (val1 + val2)
end case

end function

################################################################################
# Divide two decimals with zero check (undefined result is null).
################################################################################

function div(d1,d2)

define d1,d2 decimal
whenever any error continue
call suspend_log()
let d1 = d1 / d2
if status <> 0 then let d1 = null end if
call resume_log()
whenever any error stop
return d1

end function

################################################################################
# Maximum of two integers with null handled as smaller.
################################################################################

function maxint(val1,val2)

define val1,val2 integer
case
when val1 is null return val2
when val2 is null return val1
when val1 > val2 return val1
otherwise return val2
end case

end function

################################################################################
# Minimum of two integers with null handled as larger.
################################################################################

function minint(val1,val2)

define val1,val2 integer
case
when val1 is null return val2
when val2 is null return val1
when val1 < val2 return val1
otherwise return val2
end case

end function

################################################################################
# Maximum of two decimals with null handled as smaller.
################################################################################

function maxdec(val1,val2)

define val1,val2 decimal
case
when val1 is null return val2
when val2 is null return val1
when val1 > val2 return val1
otherwise return val2
end case

end function

################################################################################
# Minimum of two decimals with null handled as larger.
################################################################################

function mindec(val1,val2)

define val1,val2 decimal
case
when val1 is null return val2
when val2 is null return val1
when val1 < val2 return val1
otherwise return val2
end case

end function

################################################################################
# Maximum of two intervals with null handled as smaller.
################################################################################

function maxiv(val1,val2)

define val1,val2 interval day(6) to fraction
case
when val1 is null return val2
when val2 is null return val1
when val1 > val2 return val1
otherwise return val2
end case

end function

################################################################################
# Minimum of two intervals with null handled as larger.
################################################################################

function miniv(val1,val2)

define val1,val2 interval day(6) to fraction
case
when val1 is null return val2
when val2 is null return val1
when val1 < val2 return val1
otherwise return val2
end case

end function

################################################################################
# Maximum of two dates with null handled as smaller.
################################################################################

function maxd(val1,val2)

define val1,val2 date
case
when val1 is null return val2
when val2 is null return val1
when val1 > val2 return val1
otherwise return val2
end case

end function

################################################################################
# Minimum of two dates with null handled as larger.
################################################################################

function mind(val1,val2)

define val1,val2 date
case
when val1 < val2 return val1
when val1 is null return val2
when val2 is null return val1
otherwise return val2
end case

end function

################################################################################
# Maximum of two datetimes with null handled as smaller.
################################################################################

function maxdt(val1,val2)

define val1,val2 datetime year to fraction
case
when val1 is null return val2
when val2 is null return val1
when val1 > val2 return val1
otherwise return val2
end case

end function

################################################################################
# Minimum of two datetimes with null handled as larger.
################################################################################

function mindt(val1,val2)

define val1,val2 datetime year to fraction
case
when val1 < val2 return val1
when val1 is null return val2
when val2 is null return val1
otherwise return val2
end case

end function

################################################################################
# Remove the wild character at end of a text field (if present).
################################################################################

function remwild(text)

define
  text char(80),
  i smallint
let text = text clipped
let i = length(text)
if i > 1 then
  if text[i,i] = "*" then let text = text[1,i-1] end if
else let text = null
end if
return text clipped

end function

################################################################################
# Concatenation of wild character to end of a text field (if not present).
################################################################################

function addwild(text)

define
  text char(80),
  i smallint
return addend(text,"*") clipped

end function

################################################################################
# Concatenation of a character to end of a string (if not already present).
################################################################################

function addend(text,ch)

define
  text char(80),
  ch char(1),
  i smallint
let text = text clipped
let i = length(text)
case
when text is null let text = ch
when text[i,i] <> ch let text = text clipped,ch
end case
return text clipped

end function

################################################################################
# Text left justification.
################################################################################

function left(text)

define
  text,ctxt char(2000),
  i,j,k smallint
let ctxt = ""
let k = length(text)
let j = null
for i = 1 to k
  if j is null then
    if text[i,i] <> " " then let j = 1
    else continue for
    end if
  end if
  let ctxt[j,j] = text[i,i]
  let j = j + 1
end for
return ctxt clipped

end function

################################################################################
# Text right justification.
################################################################################

function right(text,cols)

define
  text,ctxt char(80),
  cols,j,k smallint
let k = length(text)
if k >= cols then return text clipped
else
  let ctxt = " "
  let j = cols - k
  for cols = 1 to k let ctxt[cols + j] = text[cols] end for
  return ctxt clipped
end if

end function

################################################################################
# Text right justification with character filling.
################################################################################

function rightfill(text,cols,fchar)

define
  text,ctxt char(80),
  cols,i,j,k smallint,
  fchar char(1)
let k = length(text)
if k >= cols then return text clipped
else
  let j = cols - k
  for i =1 to j
    let ctxt[i] = fchar
  end for
  for i = 1 to k
    let ctxt[i + j] = text[i]
  end for
  return ctxt clipped
end if

end function

################################################################################
# Text centering.
################################################################################

function center(text,cols)

define
  text,ctxt char(100),
  cols,j,k smallint
let ctxt = " "
let k = length(text)
if k < 1 then return ctxt clipped end if
let j = (cols - k) / 2
if j < 1 then return text clipped end if
let ctxt[j+1,j+k] = text
return ctxt clipped

end function

################################################################################
# Superimposing of one text over another.
################################################################################

function superimpose(text1,text2)

define
  text1,text2 char(80),
  i,j smallint
for i = 1 to length(text2)
  if text2[i,i] <> " " then let text1[i,i] = text2[i,i] end if
end for
return text1

end function

################################################################################
# Title display to window with centering of first line.
################################################################################

function disptitle(mid,mtype)

define
  mid char(64),
  mtype char(1),
  mtit char(80),
  dtype char(16),
  i,j,k smallint
let j = 4
for i = j to 1 step -1
  let mtit = title(mid,mtype,i)
  if mtit is null then let j = i - 1
  else
    case i
    when 1 call dispcenter(mtit,"titlefirst",i)
    when j call disp(mtit,"titlelast",i,j)
    otherwise call disp(mtit,"title",i,j)
    end case
  end if
end for

end function

################################################################################
# Display to center of window.
################################################################################

function dispcenter(txt,type,row)

define
  txt char(80),
  type char(16),
  row smallint,
  i smallint
whenever any error continue
call suspend_log()
for i = 80 to 1 step -1
  display "_" at 1,i
  if status = 0 then exit for end if
end for
call resume_log()
whenever any error stop
let txt = center(txt,i)
call disp(txt,type,row,1)

end function

################################################################################
# Trim trailing character value from string.
################################################################################

function trim(txt,chr)

define txt char(1000)
  ,chr char(1)
  ,i smallint
for i = length(txt) to 1 step -1
  if txt[i] = chr then let txt[i] = " "
  else exit for
  end if
end for
return txt clipped

end function

################################################################################
# Trim leading character value from string.
################################################################################

function triml(txt,chr)

define txt char(1000)
  ,chr char(1)
  ,i smallint
for i = 1 to length(txt) step 1
  if txt[i] = chr then let txt[i] = " "
  else exit for
  end if
end for
return left(txt)

end function

################################################################################
# File directory path check.
################################################################################

function checkpath(path)

define
  path char(80),
  len smallint
let len = length(path)
if len <> 0 then
  if path[len,len] <> "/" then let path = path clipped,"/" end if
end if
return path

end function

################################################################################
# Determine whether string is white space.
################################################################################

function iswhitesp(str)

define str char(512)
case
when str is null return true
when str = " " return true
when str = ascii 9 return true
end case
return false

end function

################################################################################
# Check for not null value.
################################################################################

function checknn(val)

define val char(64)
if val is not null then return true end if
call errtx("fldemp")
return false

end function

################################################################################
# Check for null value.
################################################################################

function checknull(val)

define val char(64)
if val is null then return true end if
call errtx("fldnotemp")
return false

end function

################################################################################
# Number validity check.
################################################################################

function checknum(val)

define
  val char(32),
  num decimal,
  ret char
whenever any error continue
call suspend_log()
let num = val
if status = 0 then let ret = true
else
  let ret = false
  call errtx("notnum")
end if
call resume_log()
whenever any error stop
return ret

end function

################################################################################
# Date-time validity check.
################################################################################

function checkdt(val)

define
  val char(32),
  dt datetime year to fraction(5),
  ret char
whenever any error continue
call suspend_log()
case length(val)
when 2
  let val = val clipped,"-01-01 00:00:00.00000"
when 4
  if val > "2200" or val < "1800" then
    let val = val[1,2],"-",val[3,4],"-01 00:00:00.00000"
  else
    let val = val clipped,"-01-01 00:00:00.00000"
  end if
when 6 let val = val[1,4],"-",val[5,6],"-01 00:00:00.00000"
when 7 let val = val clipped,"-01 00:00:00.00000"
when 8 let val = val[1,4],"-",val[5,6],"-",val[7,8]," 00:00:00.00000"
when 10 let val = val clipped," 00:00:00.00000"
when 13 let val = val clipped,":00:00.00000"
when 16 let val = val clipped,":00.00000"
when 19 let val = val clipped,".00000"
end case
let dt = val
if status = 0 then let ret = true
else
  let ret = false
  call errtx("notdt")
end if
call resume_log()
whenever any error stop
return ret

end function

################################################################################
# Convert date-time text to full date-time value.
################################################################################

function convdt(val)

define
  val char(32),
  dt datetime year to fraction(5)
whenever any error continue
call suspend_log()
case length(val)
when 2
  let val = val clipped,"-01-01 00:00:00.00000"
when 4
  if val > "2200" or val < "1800" then
    let val = val[1,2],"-",val[3,4],"-01 00:00:00.00000"
  else
    let val = val clipped,"-01-01 00:00:00.00000"
  end if
when 6 let val = val[1,4],"-",val[5,6],"-01 00:00:00.00000"
when 7 let val = val clipped,"-01 00:00:00.00000"
when 8 let val = val[1,4],"-",val[5,6],"-",val[7,8]," 00:00:00.00000"
when 10 let val = val clipped," 00:00:00.00000"
when 13 let val = val clipped,":00:00.00000"
when 16 let val = val clipped,":00.00000"
when 19 let val = val clipped,".00000"
end case
let dt = val
let val = dt
call resume_log()
whenever any error stop
return val clipped

end function

################################################################################
# Hour:minute validity check.
################################################################################

function checkhm(val)

define
  val char(32),
  dt datetime hour to minute,
  i smallint,
  ret char
whenever any error continue
call suspend_log()
for i = 1 to length(val)
  if val[i,i] = ":" then let i = 0 exit for end if
end for
case i
when 2 let val = val clipped,":00"
when 3 let val = val clipped,":00"
when 4 let val = "0",val[1,1],":",val[2,3]
when 5 let val = val[1,2],":",val[3,4]
end case
let dt = val clipped
if status = 0 then let ret = true
else
  let ret = false
  call errtx("notdt")
end if
call resume_log()
whenever any error stop
return ret

end function

################################################################################
# Convert an hour:minute text value into a datetime value.
################################################################################

function convhm(val)

define val char(5),
  i smallint
whenever any error continue
call suspend_log()
for i = 1 to length(val)
  if val[i,i] = ":" then let i = 0 exit for end if
end for
case i
when 2 let val = val clipped,":00"
when 3 let val = val clipped,":00"
when 4 let val = "0",val[1,1],":",val[2,3]
when 5 let val = val[1,2],":",val[3,4]
end case
let val = extend(val,hour to minute)
call resume_log()
whenever any error stop
return val

end function

################################################################################
# Date validity check.
################################################################################

function checkdat(val)

define
  val char(32),
  dat date,
  ret char
whenever any error continue
call suspend_log()
let dat = val
if status = 0 then let ret = true
else
  let ret = false
  call errtx("notdate")
end if
call resume_log()
whenever any error stop
return ret

end function

################################################################################
# Convert a date text value into a normal date format.
################################################################################

function convdat(val)

define
  val char(10),
  dat date
whenever any error continue
call suspend_log()
let dat = val
call resume_log()
whenever any error stop
return dat

end function

################################################################################
# interval year-month validity check.
################################################################################

function checkage(val)

define
  val char(7),
  iv interval year to month,
  i smallint,
  ret char
whenever any error continue
call suspend_log()
for i = 1 to length(val)
  if val[i,i] = "-" then let i = 0 exit for end if
end for
case i
when 2 let val = val clipped,"-00"
when 3 let val = val clipped,"-00"
when 4 let val = val clipped,"-00"
when 5 let val = val[1,2],"-",val[3,4]
when 6 let val = val[1,3],"-",val[4,5]
end case
let iv = val
if status = 0 then let ret = true
else
  let ret = false
  call errtx("notage")
end if
call resume_log()
whenever any error stop
return ret

end function

################################################################################
# Convert an year-month text value into a interval value.
################################################################################

function convage(val)

define
  val char(7),
  iv interval year to month,
  i smallint
whenever any error continue
call suspend_log()
for i = 1 to length(val)
  if val[i,i] = "-" then let i = 0 exit for end if
end for
case i
when 2 let val = val clipped,"-00"
when 3 let val = val clipped,"-00"
when 4 let val = val clipped,"-00"
when 5 let val = val[1,2],"-",val[3,4]
when 6 let val = val[1,3],"-",val[4,5]
end case
let iv = val
call resume_log()
whenever any error stop
return iv
end function

################################################################################
# Convert a unformatted time text value into a normal time format.
################################################################################

function ctotime(val)

define
  val char(4),
  dat datetime hour to minute
whenever any error continue
call suspend_log()
let dat = val using "##:##"
call resume_log()
whenever any error stop
return dat

end function

################################################################################
# Convert a unformatted date text value into a normal datetime format.
################################################################################

function ctod(val)

define
  val char(10),
  dat datetime year to day
whenever any error continue
call suspend_log()
initialize dat to null
let val = val clipped
if length(val) = 6 then
  let val = val[5,6],"-",val[3,4],"-",val[1,2]
  let dat = val
else
  let val = val[5,8],"-",val[3,4],"-",val[1,2]
  let dat = val
end if
call resume_log()
whenever any error stop
return dat

end function

################################################################################
# Convert a formatted numeric text value into a normal number format.
################################################################################

function convnum(val)

define
  val char(16),
  len,j,i smallint
let val = left(formatnum(val clipped,16,0,false))
return val clipped

end function

################################################################################
# swapping of decimal values
################################################################################

function swapd(val1,val2)

define val1,val2 decimal
return val2,val1

end function

################################################################################
# Convert Yes/no character from language dependent value to english.
################################################################################

function convyn(val)

define val char(1)
case val
when word("y") return "y"
when word("n") return "n"
otherwise return val
end case

end function

################################################################################
# Yes/no check (language dependent).
################################################################################

function checkyn(val)

define val char(1)
if convyn(val) matches "[yn]" then return true end if
call errtx("notyn")
return false

end function

################################################################################
# "x"/blank check.
################################################################################

function checkx(val)

define val char(1)
if val is null or val = "x" then return true end if
call errtx("notx")
return false

end function

################################################################################
# Determination if last key pressed represents a movement to the previous field.
################################################################################

function keyprev()

define keyval char(18)
let keyval = keymap(fgl_lastkey())
case keyval
when "up" return true
when "left" return true
otherwise return false
end case

end function

################################################################################
# Determination if last key pressed represents a movement to the next field.
################################################################################

function keynext()

define keyval char(18)
let keyval = keymap(fgl_lastkey())
case keyval
when "up" return false
when "left" return false
when "accept" return false
otherwise return true
end case

end function

################################################################################
# Message box display.
################################################################################

function msgopen(text)

define
  text char(48),
  i smallint
if jobtype() = "b" then return end if
if msgnr is null then let msgnr = 1
else let msgnr = msgnr + 1
end if
let text = stx(text)
let i = length(text)
let msgwidth[msgnr] = i + 16
let i = 40 - i / 2 - 8
call winopen("msg",16,i,3,msgwidth[msgnr])
call disp(text,"text",2,9)

end function

################################################################################
# Message box additional message.
################################################################################

function msgadd(text)

define text char(64)
if jobtype() = "b" then return end if
let text = center(text,msgwidth[msgnr])
call disp(text,"data",3,1)

end function

################################################################################
# Message box closing.
################################################################################

function msgclose()

if jobtype() = "b" then return end if
if msgnr > 0 then else return end if
call winclose()
let msgnr = msgnr - 1

end function

################################################################################
# Error message to error line.
################################################################################

function errtx(t)

define t char(80)
if length(t) <= 16 then let t = stx(t) end if
call disperr(t)

end function

################################################################################
# Error message to error line with additional passed information.
################################################################################

function errtxa(t,t2)

define t,t2 char(80)
if length(t) <= 16 then let t = stx(t) end if
if length(t2) <= 16 then let t2 = stx(t2) end if
let t = t clipped," ",t2 clipped
call disperr(t)

end function

################################################################################
# Message to message line.
################################################################################

function msgtx(t)

define t char(80)
if length(t) <= 16 then let t = stx(t) end if
call dispmsg(t)

end function

################################################################################
# Message to message line with additional passed information.
################################################################################

function msgtxa(t,t2)

define t,t2 char(80)
if length(t) <= 16 then let t = stx(t) end if
if length(t2) <= 16 then let t2 = stx(t2) end if
whenever any error continue
call suspend_log()
let t = t clipped," ",t2 clipped
call resume_log()
whenever any error stop
call dispmsg(t)

end function

################################################################################
# Temporary message to message line (returning null).
################################################################################

function msgtmp(t)

define t char(80)
if t is not null then call msgtx(t) end if
return ""

end function

################################################################################
# Message to window position.
################################################################################

function dsptx(t,r,c)

define
  t char(80),
  r,c smallint
if length(t) <= 16 then let t = stx(t) end if
call disp(t,"message",r,c)

end function

################################################################################
# Prompt window for printer criteria.
################################################################################

function print(prname,copies,repwid)

define
  prname,xprname,oprname,sprname char(32),
  whead,swhead char(1),
  copies,scopies char(4),
  repwid smallint,
  prnametxt,wheadtxt,copiestxt char(32),
  pipestr char(128),
  pagwid,paglen smallint,
  prsetup,prreset char(64),
  i integer,
  lv_done smallint
if copies is null then let copies = "1" end if
let whead = getwithhead("x")
if jobtype() = "b" then
  call getprinter(prname,repwid)
    returning xprname,pipestr,paglen,pagwid,prsetup,prreset
    ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
  let lv_done = true
else
  if prname is null then let prname = getdefprinter() end if
  call winform("print",6,16)
  call disptitle("print","s")
  let prnametxt = upfword("printer") clipped,"................"
  let wheadtxt = upfword("withcover") clipped,"................"
  let copiestxt = upfword("copies") clipped,"................"
  display by name prnametxt,wheadtxt,copiestxt attribute(normal)
  let sprname = prname
  let swhead = whead
  let scopies = copies
  let lv_done = false
end if
while not lv_done
  let prname = sprname
  let whead = swhead
  let copies = scopies
  let oprname = prname
  input by name prname,whead,copies without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("print","")
    when "exit" let copies = null let lv_done = true exit input
    when "search"
      case
      when infield(prname)
        call getprinter(get_fldbuf(prname),repwid)
          returning xprname,pipestr,paglen,pagwid,prsetup,prreset
          ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
        if xprname is not null then
          let prname = xprname
          let oprname = prname
          next field prname
        end if
      end case
    end case
  before field prname call msgtx(stx("prnamemsg"))
  after field prname
    call msgtx("")
    call checkprinter(prname,repwid)
      returning prname,pipestr,paglen,pagwid,prsetup,prreset
      ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx,i
    if not i then next field prname end if
    if not same(prname,oprname) then
      display by name prname attribute(reverse)
      let oprname = prname
    end if
  before field whead call msgtx("xyesno")
  after field whead
    call msgtx("")
    if not checkx(whead) then next field whead end if
  after field copies
    if copies is null then let copies = "1" end if
    if not checknum(copies) then next field copies end if
    if copies < 1 then
      call errtx("badval")
      next field copies
    end if
  after input
    if repwid > pagwid then
      if not goahead("repwide",12,12) then next field prname end if
    end if
    let lv_done = true
  end input
end while
call winclose()
if whead = "x" then let whead = true
else let whead = false
end if
return pipestr,whead,copies,paglen,prsetup,prreset

end function

################################################################################
# Prompt window for printscreen criteria.
################################################################################

function pscreen()

define
  prname,xprname,oprname,sprname char(32),
  prnametxt char(64),
  pipestr char(128),
  pagwid,paglen smallint,
  prsetup,prreset char(64),
  i integer,
  lv_done,doit smallint
let prname = getdefprinter()
call winform("pscreen",6,16)
call disptitle("pscreen","s")
let prnametxt = upfword("printer") clipped,"................"
display by name prnametxt attribute(normal)
let sprname = prname
let doit = false
let lv_done = false
while not lv_done
  let prname = sprname
  let oprname = prname
  input by name prname without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("pscreen","")
    when "exit" let lv_done = true exit input
    when "search"
      case
      when infield(prname)
        call getprinter(get_fldbuf(prname),80)
          returning xprname,pipestr,paglen,pagwid,prsetup,prreset
          ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
        if xprname is not null then
          let prname = xprname
          let oprname = prname
          next field prname
        end if
      end case
    end case
  before field prname call msgtx(stx("prnamemsg"))
  after field prname
    call msgtx("")
    call checkprinter(prname,80)
      returning prname,pipestr,paglen,pagwid,prsetup,prreset
      ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx,i
    if not i then next field prname end if
    if not same(prname,oprname) then
      display by name prname attribute(reverse)
      let oprname = prname
    end if
  after input
    let lv_done = true
    let doit = true
  end input
end while
call winclose()
if doit then call fgl_prtscr(prsetup,pipestr,length(pipestr)) end if

end function

################################################################################
# Enhancement string conversion for print outputs.
################################################################################

function prenh(form,text)

define
  form char(32),
  text char(512),
  text2 char(1024),
  enh char(32),
  i,j,k,l,m smallint
let text2 = null
let j = 0
let k = 0
let l = 0
let m = 0
for i = 1 to length(form) step 1
  if form[i,i] matches "[0123456789]" then let j = j * 10 + form[i,i]
  else
    let k = k + j
    let j = 0
    case form[i,i]
    when "B" let enh = prbold
    when "b" let enh = prboldx
    when "U" let enh = prunderl
    when "u" let enh = prunderlx
    when "I" let enh = pritalic
    when "i" let enh = pritalicx
    otherwise let enh = null
    end case
    if k <= 512 then
      if m = 0 then
        if k = l then let text2 = enh
        else let text2 = text[l+1,k],enh
        end if
      else
        if k = l then let text2 = text2[1,m],enh
        else let text2 = text2[1,m],text[l+1,k],enh
        end if
      end if
    end if
    let m = m + k - l + length(enh)
    let l = k
  end if
end for
if m < 1 then let text2 = text
else let text2 = text2[1,m],text[l+1,512]
end if
return text2 clipped

end function

################################################################################
# Create a new temporary file.
################################################################################

function newtempfile(ending)

define ending char(16)
  ,rootname char(64)
  ,filename char(64)
  ,nr,fp integer
let rootname = fgl_getenv("TEMPDIR")
if rootname is null then let rootname = "/tmp" end if
let rootname = rootname clipped,"/t",left(processid()),"_"
for nr = 1 to 9999
  let filename = rootname clipped,nr using "&&&&",ending
  let fp = fgl_fopen(filename,"r")
  if fp = 0 then
    let fp = fgl_fopen(filename,"w")
    if fp <> 0 then
      call fgl_fclose(fp)
      return filename clipped
    end if
  else call fgl_fclose(fp)
  end if
end for
call progerrq("newtempfile",nr,fp)

end function

################################################################################
# Remove a previously created temporary file.
################################################################################

function remtempfile(filename)

define filename char(128)
let filename = "rm -f ",filename clipped," 2>/dev/null"
run filename clipped

end function

################################################################################
# Prompt window for printer criteria.
################################################################################

function ppipe(ppipe)

define
  ppipe,oppipe,sppipe char(32),
  pipestr char(128),
  whead,swhead char(1),
  ppipetxt,wheadtxt char(32),
  i integer,
  lv_done smallint
let pipestr = null
let whead = getwithhead("x")
if ppipe is null then let ppipe = getdefppipe() end if
call winform("ppipe",6,16)
call disptitle("ppipe","s")
let ppipetxt = upfword("ppipe") clipped,"................"
let wheadtxt = upfword("withhead") clipped,"................"
display by name ppipetxt,wheadtxt attribute(normal)
let sppipe = ppipe
let swhead = whead
let lv_done = false
while not lv_done
  let ppipe = sppipe
  let whead = swhead
  let oppipe = ppipe
  input by name ppipe,whead without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("ppipe","")
    when "exit" let ppipe = null let lv_done = true exit input
    when "search"
      case
      when infield(ppipe)
        call getppipe(get_fldbuf(ppipe)) returning oppipe,pipestr
        if oppipe is null then let oppipe = ppipe
        else
          let ppipe = oppipe
          next field ppipe
        end if
      end case
    end case
  before field ppipe call msgtx(stx("ppipemsg"))
  after field ppipe
    call msgtx("")
    call checkppipe(ppipe) returning ppipe,pipestr,i
    if not i then next field ppipe end if
    if not same(ppipe,oppipe) then
      display by name ppipe attribute(reverse)
      let oppipe = ppipe
    end if
  before field whead call msgtx("xyesno")
  after field whead
    call msgtx("")
    if not checkx(whead) then next field whead end if
  after input
    if not checknn(ppipe) then next field ppipe end if
    let lv_done = true
  end input
end while
call winclose()
if whead = "x" then let whead = true
else let whead = false
end if
return ppipe,pipestr,whead

end function

################################################################################
# Start report to special pipe.
################################################################################

function ppipebeg(pipestr)

define pipestr char(128)
start report output to pipe pipestr
let ppgrpnr = 0

end function

################################################################################
# Finish report to special pipe.
################################################################################

function ppipeend()

if ppgrpnr > 0 then call ppipegrpend() end if
finish report output

end function

################################################################################
# Output one line to special pipe.
################################################################################

function ppipeout(ptxt)

define
  ppipeid char(32),
  ptxt char(512),
  plin char(512),
  i smallint
if ppgrpnr = 0 then
  call ppipegrpbeg()
end if
let ppgrpnr = ppgrpnr + 1
let plin = getppipebeglin()
output to report output(plin,true)
let plin = getppipebegtxt(),ppipeconv(ptxt clipped),getppipeendtxt()
output to report output(plin,true)
let plin = getppipeendlin()
output to report output(plin,true)
if ppgrpnr = getppipegrpnr() then
  call ppipegrpend()
  let ppgrpnr = 0
end if

end function

################################################################################
# Output head of group.
################################################################################

function ppipegrpbeg()

define
  i smallint,
  plin char(400)
let i = 1
while true
  let plin = getppipebeggrp(i)
  if plin is null then exit while end if
  output to report output(plin,true)
  let i = i + 1
end while

end function

################################################################################
# Output tail of group.
################################################################################

function ppipegrpend()

define
  i smallint,
  plin,olin char(400)
let i = 1
let olin = null
while true
  let plin = getppipeendgrp(i)
  if plin is null then exit while end if
  output to report output(olin,true)
  let olin = plin
  let i = i + 1
end while
if olin is not null then output to report output(olin,false) end if

end function
 
################################################################################
# Prompt window for print file criteria.
################################################################################

function pfile(pfile)

define
  pfile,spfile char(32),
  whead,swhead char(1),
  pfiletxt,wheadtxt char(32),
  fp integer,
  lv_done smallint
let whead = getwithhead("x")
if jobtype() = "b" then
  let lv_done = true
else
  call winform("pfile",6,16)
  call disptitle("pfile","s")
  let pfiletxt = upfword("filename") clipped,"................"
  let wheadtxt = upfword("withhead") clipped,"................"
  display by name pfiletxt,wheadtxt attribute(normal)
  let spfile = pfile
  let swhead = whead
  let lv_done = false
end if
while not lv_done
  let pfile = spfile
  let whead = swhead
  input by name pfile,whead without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("pfile","")
    when "exit" let pfile = null let lv_done = true exit input
    end case
  before field whead call msgtx("xyesno")
  after field whead
    call msgtx("")
    if not checkx(whead) then next field whead end if
  after input
    if not checknn(pfile) then next field pfile end if
    let fp = fgl_fopen(pfile,"r")
    if fp <> 0 then
      call fgl_fclose(fp)
      if not goahead("filereplace",8,8) then next field pfile end if
    end if
    let fp = fgl_fopen(pfile,"w")
    if fp = 0 then
      call errtx("filenowrite")
      next field pfile
    else call fgl_fclose(fp)
    end if
    let lv_done = true
  end input
end while
call winclose()
if whead is null then return pfile,false
else return pfile,true
end if

end function

################################################################################
# Prompt window for mail criteria.
################################################################################

function pmail(maddr,msubj)

define
  maddr,smaddr,smsubj,msubj char(48),
  whead,swhead char(1),
  mdescr1,mdescr2,mdescr3,mdescr4,mdescr5 char(64),
  maddrtxt,msubjtxt,wheadtxt,mdescrtxt char(32),
  fp integer,
  lv_done smallint
let whead = getwithhead("x")
if jobtype() = "b" then
  let mdescr1 = null
  let mdescr2 = null
  let mdescr3 = null
  let mdescr4 = null
  let mdescr5 = null
  let lv_done = true
else
  call winform("pmail",4,8)
  call disptitle("pmail","s")
  let maddrtxt = upfword("mailaddr") clipped,"................"
  let msubjtxt = upfword("mailsubj") clipped,"................"
  let wheadtxt = upfword("withhead") clipped,"................"
  let mdescrtxt = upfword("maildescr") clipped,":"
  display by name maddrtxt,msubjtxt,wheadtxt,mdescrtxt attribute(normal)
  let smaddr = maddr
  let smsubj = msubj
  let swhead = whead
  let lv_done = false
end if
while not lv_done
  let maddr = smaddr
  let msubj = smsubj
  let whead = swhead
  let mdescr1 = null
  let mdescr2 = null
  let mdescr3 = null
  let mdescr4 = null
  let mdescr5 = null
  input by name maddr,msubj,whead
    ,mdescr1,mdescr2,mdescr3,mdescr4,mdescr5 without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("pmail","")
    when "exit" let maddr = null let lv_done = true exit input
    end case
  after field maddr
    let maddr = strip(maddr)
    display by name maddr attribute(reverse)
  after field msubj
--    let msubj = chrrep(msubj," ","_")
    display by name msubj attribute(reverse)
  before field whead call msgtx("xyesno")
  after field whead
    call msgtx("")
    if not checkx(whead) then next field whead end if
  after input
    if not checknn(maddr) then next field maddr end if
    if not checknn(msubj) then next field msubj end if
    let lv_done = true
  end input
end while
call winclose()
if whead is null then let whead = false
else let whead = true
end if
return whead,maddr,msubj,mdescr1,mdescr2,mdescr3,mdescr4,mdescr5

end function

################################################################################
# Prompt window for background job scheduling.
################################################################################

function schedjob_form(jobname,atdt,norep,prname,pfile,maddr,msubj,mailto)

define
  jobname char(32),
  atdt datetime year to minute,
  norep char,
  prname,xprname,oprname,sprname char(32),
  pfile,spfile char(32),
  maddr,msubj char(48),
  mailto char(32),
  attitle char(32),
  attimetxt char(32),
  atdatetxt char(32),
  atreptxt char(32),
  attime char(5),
  atdate char(10),
  atrep char(1),
  prtitle char(32),
  prnametxt char(32),
  pftitle char(32),
  pfiletxt char(32),
  pmtitle char(32),
  maddrtxt char(32),
  msubjtxt char(32),
  xdt datetime year to minute,
  xiv interval hour to minute,
  dum char(128),
  i integer,
  fp integer,
  lv_done,doit smallint
call winform("schedjob",8,16)
call disptitle("schedjob","s")
if norep is null then let norep = false end if
let attitle = title("schedule","s",1) clipped,":"
let attimetxt = upfword("time") clipped,"................"
let atdatetxt = upfword("date") clipped,"................"
let atreptxt = upfword("repeat") clipped,"................"
let prtitle = title("print","s",1) clipped,":"
let prnametxt = upfword("printer") clipped,"................"
let pftitle = title("pfile","s",1) clipped,":"
let pfiletxt = upfword("filename") clipped,"................"
let pmtitle = title("pmail","s",1) clipped,":"
let maddrtxt = upfword("mailaddr") clipped,"................"
let msubjtxt = upfword("mailsubj") clipped,"................"
display by name attitle,attimetxt,atdatetxt,atreptxt
  ,prtitle,prnametxt,pftitle,pfiletxt
  ,pmtitle,maddrtxt,msubjtxt attribute(normal)
if prname is null then let prname = getdefprinter() end if
let sprname = prname
let spfile = pfile
let doit = false
let lv_done = false
while not lv_done
  let attime = extend(atdt,hour to minute)
  let atdate = date(atdt)
  let atrep = null
  let prname = sprname
  let pfile = spfile
  let maddr = null
  let msubj = null
  input by name attime,atdate,atrep,prname,pfile,maddr,msubj without defaults
  on key (prevpage,nextpage,help,escape,insert,delete,interrupt,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12,f13,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31,f32,f33,f34,f35,f36,f37,f38,f39,f40,f41,f42,f43,f44,f45,f46,f47,f48,f49,f50,f51,f52,f53,f54,f55,f56,control-b,control-c,control-e,control-f,control-g,control-k,control-n,control-o,control-p,control-q,control-t,control-u,control-v,control-y,control-z)
    case keytransl(fgl_lastkey())
    when "refresh" exit input
    when "help" call helpman("schedjob","")
    when "exit" let lv_done = true exit input
    when "search"
      case
      when infield(prname)
        call getprinter(get_fldbuf(prname),"")
          returning xprname,dum,dum,dum,dum,dum,dum,dum,dum,dum,dum,dum
        if xprname is not null then
          let prname = xprname
          let oprname = prname
          next field prname
        end if
      end case
    end case
  before input
    if norep then display by name atrep end if
  before field attime call msgtx(stx("attimemsg"))
  after field attime
    call msgtx("")
    if not checkhm(attime) then next field attime end if
    let attime = convhm(attime)
    display by name attime attribute(reverse)
  before field atdate call msgtx(stx("atdatemsg"))
  after field atdate
    call msgtx("")
    if atdate is null and attime is not null then
      let xdt = today
      let xiv = attime
      let xdt = xdt + xiv
      if xdt <= current year to minute + 1 units minute then
        let xdt = xdt + 1 units day
      end if
      let atdate = date(xdt)
      display by name atdate attribute(reverse)
    end if
    if not checkdat(atdate) then next field atdate end if
    let atdate = convdat(atdate)
    display by name atdate attribute(reverse)
  before field atrep
    if norep then
      if keyprev() then next field previous
      else next field next
      end if
    end if
    call msgtx(stx("atrepmsg"))
  after field atrep
    call msgtx("")
    if atrep is not null then
      if transl("timeunit",atrep) not matches "[dwm]" then
        call errtx("badval")
        next field atrep
      end if
    end if
  before field prname call msgtx(stx("prnamemsg"))
  after field prname
    call msgtx("")
    call checkprinter(prname,"")
      returning prname,dum,dum,dum,dum,dum,dum,dum,dum,dum,dum,dum,i
    if not i then next field prname end if
    if not same(prname,oprname) then
      display by name prname attribute(reverse)
      let oprname = prname
    end if
  after field maddr
    let maddr = strip(maddr)
    display by name maddr attribute(reverse)
  after field msubj
--    let msubj = chrrep(msubj," ","_")
    display by name msubj attribute(reverse)
  after input
    if norep then display by name atrep end if
    if atdate is not null then
      if not checknn(attime) then next field attime end if
    end if
    if attime is not null then
      if not checknn(atdate) then next field atdate end if
    end if
    if attime is null then let xdt = null
    else
      let xdt = date(atdate)
      let xiv = attime
      let xdt = xdt + xiv
      if xdt <= current year to minute + 1 units minute then
        call errtx("notfuture")
        next field attime
      end if
    end if
    if maddr is not null then
      if not checknn(msubj) then next field msubj end if
    end if
    if pfile is not null then
      let fp = fgl_fopen(pfile,"r")
      if fp <> 0 then
        call fgl_fclose(fp)
        if not goahead("filereplace",8,8) then next field pfile end if
      end if
      let fp = fgl_fopen(pfile,"w")
      if fp = 0 then
        call errtx("filenowrite")
        next field pfile
      else call fgl_fclose(fp)
      end if
    end if
    let job.jobname = jobname
    let job.atdt = xdt
    let job.atrep = atrep
    let job.prname = prname
    let job.pfile = pfile
    let job.maddr = maddr
    let job.msubj = msubj
    let job.mailto = mailto
    let job.cmd = null
    let lv_done = true
    let doit = true
  end input
end while
call winclose()
return doit

end function

################################################################################
# Setup a job schedule without a form.
################################################################################

function schedjob_set(jobname,atdt,atrep,prname,pfile,maddr,msubj,mailto)

define
  jobname char(32),
  atdt datetime year to minute,
  atrep char(1),
  prname char(32),
  pfile char(32),
  maddr char(48),
  msubj char(48),
  mailto char(32)
let job.jobname = jobname
let job.atdt = atdt
let job.atrep = atrep
let job.prname = prname
let job.pfile = pfile
let job.maddr = maddr
let job.msubj = msubj
let job.mailto = mailto
let job.cmd = null

end function

################################################################################
# Add to the job scheduling command line.
################################################################################

function schedjob_cmd(cmd)

define cmd char(128)
let job.cmd = job.cmd clipped,cmd clipped

end function

################################################################################
# Schedule background job that was previously set up.
################################################################################

function schedjob_perf()

define
  atcmd char(2000),
  attime,attx char(16),
  i integer
let atcmd = "echo """,job.cmd clipped
if job.mailto is not null and job.mailto <> " " then
  if job.jobname is null then let job.jobname = "at" end if
  let atcmd = atcmd clipped
    ," 2>&1|mailx -s '",job.jobname clipped,"' ",job.mailto
end if
if job.atdt is null then let attime = "now+1 minute"
else
  let attx = job.atdt
  let attime = "-t",attx[1,4],attx[6,7],attx[9,10],attx[12,13],attx[15,16]
end if
let atcmd = atcmd clipped,"""|at ",attime clipped," 2>/dev/null"
run atcmd returning i
if i <> 0 then return false end if
return true

end function

################################################################################
# Set batch job values.
################################################################################

function setjobval(jobname,prname,pfile,maddr,msubj)

define jobname char(32),
  prname char(32),
  pfile char(32),
  maddr char(48),
  msubj char(48)
let job.jobname = jobname
let job.prname = prname
let job.pfile = pfile
let job.maddr = maddr
let job.msubj = msubj

end function

################################################################################
# Return batch job values.
################################################################################

function getjobval()

return job.jobname,job.atdt,job.atrep,job.prname,job.pfile,job.maddr,job.msubj
  ,job.mailto

end function

################################################################################
# Message box with wait for user response.
################################################################################

function pause(tcode,r,c)

define
  tcode char(72),
  ptext char(80),
  r,c,len smallint
let ptext = " ", stx("prany")
let len = length(ptext)
call promptbox(tcode,r,c,len)
call dispmsg(ptext)
call getkey() returning ptext
call winclose()

end function

################################################################################
# Small message box with wait for user response.
################################################################################

function spause(tcode,r,c)

define
  tcode char(80),
  ptext char(80),
  r,c,len smallint
let ptext = " ", stx("prany")
let len = length(ptext)
call spromptbox(tcode,r,c,len)
call dispmsg(ptext)
call getkey() returning ptext
call winclose()

end function

################################################################################
# Retrieve keystroke and clear messages.
################################################################################

function getkey()

define i integer
let i = fgl_getkey()
call fgl_clrmsg()
return i

end function

################################################################################
# Prompt for yes/no from user with text.
################################################################################

function getyn(tcode,pcode,r,c)

define
  tcode char(72),
  pcode char(72),
  ptext char(80),
  answer char(1),
  r,c smallint
if pcode is null then let ptext = " ",stx("yesno")
else let ptext = " ",stx(pcode)
end if
call promptbox(tcode,r,c,length(ptext))
while true
  call dispmsg(ptext)
  let c = getkey()
  if c < 256 then let answer = ascii(c) else let answer = null end if
  case keytransl(c)
  when "accept" let answer = word("y")
  when "help" call helpman("getyn","")
  when "exit" let answer = word("n")
  when "enter" let answer = word("y")
  end case
  if answer is not null then
    let answer = lower(answer)
    let answer = convyn(answer)
    case answer
      when " " let r = true exit while
      when "y" let r = true exit while
      when "n" let r = false exit while
      otherwise call errtx("notyn")
    end case
  end if
end while
call winclose()
return r

end function

################################################################################
# Prompt for yes/no from user with text, small box
################################################################################

function sgetyn(tcode,pcode,r,c)

define
  tcode char(80),
  pcode char(80),
  ptext char(80),
  answer char(1),
  r,c smallint
if pcode is null then let ptext = " ",stx("yesno")
else let ptext = " ",stx(pcode)
end if
call spromptbox(tcode,r,c,length(ptext))
while true
  call dispmsg(ptext)
  let c = getkey()
  if c < 256 then let answer = ascii(c) else let answer = null end if
  case keytransl(c)
  when "accept" let answer = word("y")
  when "help" call helpman("sgetyn","")
  when "exit" let answer = word("n")
  when "enter" let answer = word("y")
  end case
  if answer is not null then
    let answer = lower(answer)
    let answer = convyn(answer)
    case answer
      when " " let r = true exit while
      when "y" let r = true exit while
      when "n" let r = false exit while
      otherwise call errtx("notyn")
    end case
  end if
end while
call winclose()
return r

end function

################################################################################
# Prompt user for affirmation.
################################################################################

function agree(tcode,r,c)

define
  tcode char(72),
  r,c smallint
return (getyn(tcode,"agree",r,c))

end function

################################################################################
# Prompt user for affirmation.
################################################################################

function sagree(tcode,r,c)

define
  tcode char(80),
  r,c smallint
return (sgetyn(tcode,"agree",r,c))

end function

################################################################################
# Prompt user if user wants to continue.
################################################################################

function goahead(tcode,r,c)

define
  tcode char(72),
  r,c smallint
return (getyn(tcode,"goahead",r,c))

end function

################################################################################
# Prompt user if user wants to continue.
################################################################################

function sgoahead(tcode,r,c)

define
  tcode char(80),
  r,c smallint
return (sgetyn(tcode,"goahead",r,c))

end function

################################################################################
# Prompt user if user is sure.
################################################################################

function sure(tcode,r,c)

define
  tcode char(72),
  r,c smallint
return (getyn(tcode,"sure",r,c))

end function

################################################################################
# Prompt user if user is sure.
################################################################################

function ssure(tcode,r,c)

define
  tcode char(80),
  r,c smallint
return (sgetyn(tcode,"sure",r,c))

end function

################################################################################
# Prompt box window opening (used internally).
################################################################################

function promptbox(tcode,r,c,minlen)

define
  tcode char(72),
  mtxt array[8] of char(72),
  r,c,minlen,nr,nc,i,j,scr smallint
let nr = 0
let nc = 20
let scr = getlines()
if tcode is not null then
  call mtx(tcode)
    returning mtxt[1],mtxt[2],mtxt[3],mtxt[4],mtxt[5],mtxt[6],mtxt[7],mtxt[8]
end if
for i = 1 to 8
  if mtxt[i] is not null then
    let nr = i
    let j = length(mtxt[i])
    if j > nc then let nc = j end if
  end if
end for
if nc < minlen then
  let nc = minlen
end if
if nr = 0 then let i = 1
else let i = nr + 3
end if
let j = nc + 2
if r is null then let r = 4 end if
if c is null then let c = 12 end if
if r < 3 then let r = 3 end if
if c < 1 then let c = 1 end if
if r + i > scr - 2 then let r = scr - 2 - i end if
if c + j > 80 then let c = 80 - j end if
let r = r + 1
let c = c + 1
call winopen("promptbox",r,c,i,j)
for i = 1 to nr
  let r = i + 1
  call disp(mtxt[i],"text",r,2)
end for

end function

################################################################################
# Small prompt box window opening (used internally).
################################################################################

function spromptbox(tcode,r,c,minlen)

define
  tcode char(80),
  txt char(80),
  r,c,nr,nc,minlen,scr smallint
let scr = getlines()
if tcode is not null then let txt =  stx(tcode) end if
let nr  = 4
let nc = length(txt)
if nc < minlen then
  let nc = minlen
end if
let nc = nc + 2
if r is null then let r = 4 end if
if c is null then let c = 12 end if
if r < 3 then let r = 3 end if
if c < 1 then let c = 1 end if
if r + nr > scr - 2 then let r = scr - 2 - nr end if
if c + nc > 80 then let c = 80 - nc end if
let r = r + 1
let c = c + 1
call winopen("spromptbox",r,c,nr,nc)
call disp(txt,"text",2,2)

end function

################################################################################
# Handling of standard viewing window.
################################################################################

function viewer(module,txt)

define
  module char(18),
  txt char(80),
  action char(16),
  c char(1)
let action = null
call msgtx(txt)
while action is null
  case keytransl(getkey())
  when "prevpage" let action = "prevpage"
  when "nextpage" let action = "nextpage"
  when "refresh" let action = "refresh"
  when "help" call helpman(module,"viewer")
  when "other" let action = "other"
  when "enter" let action = "enter"
  when "accept" let action = "exit"
  when "exit" let action = "exit"
  end case
end while
return action

end function

################################################################################
# Operating system shell.
################################################################################

function bang()

define
  cmd char (100),
  scr smallint
let scr = getlines()
call winopen("bang",1,1,scr,80)
let cmd = "echo '",stx("opsys")
let cmd[99,99] = "'"
run cmd
run "echo ' '"
call opsys()
call winclose()

end function

################################################################################
# Help function.
################################################################################

function helpman(tcode1,tcode2)

define
  tcode1,tcode2 char(16),
  sysdir,fname char(64),
  helptxt array[500] of char(100),
  helpfrm array[500] of char(32),
  ptxt char(80),
  answer char(1),
  blank char(76),
  filename char(64),
  dscrname char(64),
  withhead char,
  maddr,msubj char(48),
  md1,md2,md3,md4,md5 char(64),
  ppipeid char(32),
  pipestr char(128),
  copies smallint,
  xprsetup,xprreset char(64),
  lv_done,rtot,rscr,curs,r,c,i,j,ec smallint,
  fp integer
let i = 1
let c = 42
let sysdir = checkpath(fgl_getenv("SYSTEMDIR"))
if tcode1 is not null then
  let fname = sysdir clipped,tcode1 clipped,".hlp"
  let fp = fgl_fopen(fname,"r")
  if fp = 0 then
    let fname = sysdir clipped,"help/",tcode1 clipped,".hlp"
    let fp = fgl_fopen(fname,"r")
  end if
  if fp <> 0 then
    call fgl_fgets(fp) returning ec,helptxt[i]
    while ec = 0
      if helptxt[i] is null then let helptxt[i] = " " end if
      call helpformat(helptxt[i]) returning helptxt[i],helpfrm[i]
      let j = length(helptxt[i])
      if j > c then let c = j end if
      let i = i + 1
      call fgl_fgets(fp) returning ec,helptxt[i]
    end while
    call fgl_fclose(fp)
  end if
end if
if tcode2 is not null then
  let fname = sysdir clipped,tcode2 clipped,".hlp"
  let fp = fgl_fopen(fname,"r")
  if fp = 0 then
    let fname = sysdir clipped,"help/",tcode2 clipped,".hlp"
    let fp = fgl_fopen(fname,"r")
  end if
  if fp <> 0 then
    if i > 1 then
      let helptxt[i] = "_____________________________________________________________________________"
      let helpfrm[i] = null
      let i = i + 1
    end if
    call fgl_fgets(fp) returning ec,helptxt[i]
    while ec = 0
      if helptxt[i] is null then let helptxt[i] = " " end if
      call helpformat(helptxt[i]) returning helptxt[i],helpfrm[i]
      let j = length(helptxt[i])
      if j > c then let c = j end if
      let i = i + 1
      call fgl_fgets(fp) returning ec,helptxt[i]
    end while
    call fgl_fclose(fp)
  end if
end if      
let fname = sysdir clipped,"help.hlp"
let fp = fgl_fopen(fname,"r")
if fp = 0 then
  let fname = sysdir clipped,"help/help.hlp"
  let fp = fgl_fopen(fname,"r")
end if
if fp <> 0 then
  if i > 1 then
    let helptxt[i] = "_____________________________________________________________________________"
      let helpfrm[i] = null
    let i = i + 1
  end if
  call fgl_fgets(fp) returning ec,helptxt[i]
  while ec = 0
    if helptxt[i] is null then let helptxt[i] = " " end if
      call helpformat(helptxt[i]) returning helptxt[i],helpfrm[i]
    let j = length(helptxt[i])
    if j > c then let c = j end if
    let i = i + 1
    call fgl_fgets(fp) returning ec,helptxt[i]
  end while
  call fgl_fclose(fp)
end if
let rscr = getlines()
let rtot = i - 1
if rtot = 0 then
  let helptxt[1] = " "
  let rtot = 1
end if
let blank = " "
let j = c - length(tcode1) - 2
let helptxt[1] = helptxt[1][1,j],"[",tcode1 clipped,"]"
let helpfrm[1] = "B",j using "<<<<","b"
if rtot > rscr - 4 then let r = rscr - 4
else let r = rtot
end if
let r = r + 1
call winopen(catstr("help-",tcode1),2,2,r,c)
let curs = 1
let lv_done = false
call disp(helptxt[1],"titlefirst",1,1)
let uname = right(sysname(),32)
let uid = right(sysid(),32)
let utime = current
let ptxt = stx("prany")
call dispmsg(ptxt)
while not lv_done
  let lv_done = true
  for i = 2 to r - 1
    case
    when i + curs - 1 > rtot call disp(blank,"text",i,1)
    when helptxt[i + curs - 1] is null call disp(blank,"text",i,1)
    otherwise call helpdisp(helptxt[i+curs-1],helpfrm[i+curs-1],i)
    end case
  end for
  case keytransl(getkey())
  when "nothing" let lv_done = false
  when "up"
    let lv_done = false
    if curs > 1 then let curs = curs - 1 end if
  when "down"
    let lv_done = false
    if curs + (r - 2) < rtot then let curs = curs + 1 end if
  when "prevpage"
    let lv_done = false
    let curs = curs - (r - 2)
    if curs < 1 then let curs = 1 end if
  when "nextpage"
    let lv_done = false
    if curs + (r - 2) < rtot then let curs = curs + (r - 2) end if
  when "home"
    let lv_done = false
    let curs = 1
  when "end"
    let lv_done = false
    let curs = rtot - (r - 2)
  when "pfile"
    let lv_done = false
    call pfile("") returning filename,withhead
    if filename is null then exit case end if
    call msgopen("printing")
    start report output to filename
    if rtot > 0 then
      if withhead then
        let ptxt = stx("helptxt")
        if c < 66 then let j = 66 else let j = c end if
        let i = j - 32
        let ptxt = ptxt[1,i],uname
        output to report output(ptxt,true)
        let ptxt = null
        for i = 1 to j let ptxt = ptxt clipped,"¯" end for
        output to report output(ptxt,true)
      end if
      for i = 1 to rtot step 1
        output to report output(helptxt[i][1,c],true)
      end for
    end if
    finish report output
    call msgclose()
  when "ppipe"
    let lv_done = false
    call ppipe("") returning ppipeid,pipestr,withhead
    if ppipeid is null then exit case end if
    call msgopen("printing")
    if rtot > 0 then
      call ppipebeg(pipestr)
      if withhead then
        let ptxt = stx("helptxt")
        if c < 66 then let j = 66 else let j = c end if
        let i = j - 32
        let ptxt = ptxt[1,i],uname
        call ppipeout(ptxt)
        let ptxt = null
        for i = 1 to j let ptxt = ptxt clipped,"¯" end for
        call ppipeout(ptxt)
      end if
      for i = 1 to rtot step 1
        call ppipeout(helptxt[i][1,c])
      end for
      call ppipeend()
    end if
    call msgclose()
  when "pmail"
    let lv_done = false
    call pmail(defemail(),"") returning withhead,maddr,msubj,md1,md2,md3,md4,md5
    if maddr is null then exit case end if
    let filename = newtempfile("_mtext")
    let dscrname = newtempfile("_mdscr")
    call msgopen("printing")
    start report output to dscrname
    output to report output(md1,true)
    if md2 is not null then output to report output(md2,true) end if
    if md3 is not null then output to report output(md3,true) end if
    if md4 is not null then output to report output(md4,true) end if
    if md5 is not null then output to report output(md5,true) end if
    finish report output
    start report output to filename
    if rtot > 0 then
      if withhead then
        let ptxt = stx("helptxt")
        if c < 66 then let j = 66 else let j = c end if
        let i = j - 32
        let ptxt = ptxt[1,i],uname
        output to report output(ptxt,true)
        let ptxt = null
        for i = 1 to j let ptxt = ptxt clipped,"¯" end for
        output to report output(ptxt,true)
      end if
      for i = 1 to rtot step 1
        output to report output(helptxt[i][1,c],true)
      end for
    end if
    finish report output
    call sendmail(filename,msubj,dscrname,maddr)
    call msgclose()
    call remtempfile(filename)
    call remtempfile(dscrname)
  when "print"
    let lv_done = false
    call print("","",c)
      returning pipestr,withhead,copies,paglen,xprsetup,xprreset
    if copies is null then exit case end if
    let paglen = paglen - 4
    call msgopen("printing")
    for copies = copies to 1 step -1
      let prsetup = xprsetup
      let prreset = xprreset
      start report output to pipe pipestr
      let curpag = 0
      if rtot > 0 then
        call help_header(c)
        for i = 1 to rtot step 1
          if curlin >= paglen then
            call help_trailer(c,true)
            call help_header(c)
          end if
          let curlin = curlin + 1
          output to report output(prenh(helpfrm[i],helptxt[i][1,c]),true)
        end for
        call help_trailer(c,false)
      end if
      finish report output
    end for
    call msgclose()
  end case
end while
call winclose()

end function

################################################################################
# Set up the format of a help text line.
################################################################################

function helpformat(text)

define
  text char(100),
  form char(32),
  text2 char(78),
  i,j,k,l smallint
let form = null
let text2 = null
let k = false
let j = 0
let l = 0
for i = 1 to length(text)
  if text[i] = "\\" then let k = true
  else
    if k then
      case text[i]
      when "B"
        let form = form clipped,j using "<<<<",text[i]
        let j = 0
      when "b"
        let form = form clipped,j using "<<<<",text[i]
        let j = 0
      otherwise
        if l = 0 then let text2 = text[i]
        else let text2 = text2[1,l],text[i]
        end if
        let l = l + 1
        let j = j + 1
      end case
      let k = false
    else
      if l = 0 then let text2 = text[i]
      else let text2 = text2[1,l],text[i]
      end if
      let l = l + 1
      let j = j + 1
    end if
  end if
end for
return text2,form

end function

################################################################################
# Display of a help text line.
################################################################################

function helpdisp(text,form,pos)

define
  text char(78),
  form char(32),
  pos,i,j,k smallint,
  dispform char(18)
if text is null or text = " " then
  call disp(text,"text",pos,1)
  return
end if
let dispform = "text"
let j = 0
let k = 0
for i = 1 to length(form)
  case form[i]
  when "B"
    if k > 0 then call disp(text[j+1,j+k],dispform,pos,j+1) end if
    let dispform = "textbold"
    let j = j + k
    let k = 0
  when "b"
    if k > 0 then call disp(text[j+1,j+k],dispform,pos,j+1) end if
    let dispform = "text"
    let j = j + k
    let k = 0
  otherwise
    if form[i] matches "[0123456789]" then let k = k * 10 + form[i] end if
  end case
end for
let k = length(text)
if k > j then call disp(text[j+1,k],dispform,pos,j+1) end if

end function

################################################################################
# Output of help header to printer or pipe.
################################################################################

function help_header(c)

define
  c,i,j smallint,
  htxt char(200)
let curpag = curpag + 1
let htxt = stx("helptxt")
if c < 66 then let j = 66 else let j = c end if
let i = j - 32
let htxt = htxt[1,i],uname
let htxt = prsetup clipped,prenh("B",htxt)
output to report output(htxt,true)
let htxt = null
for i = 1 to j let htxt = htxt clipped,"¯" end for
let htxt = htxt clipped,prboldx clipped
output to report output(htxt,true)
let prsetup = null
let curlin = 0

end function

################################################################################
# Output of help trailer to printer or pipe.
################################################################################

function help_trailer(c,ff)

define
  c,ff,i,j smallint,
  htxt char(200)
while curlin < paglen
  let curlin = curlin + 1
  output to report output("",true)
end while
if c < 66 then let j = 66 else let j = c end if
let i = j - 32
let htxt = prbold clipped
for i = 1 to j let htxt = htxt clipped,"_" end for
output to report output(htxt,true)
let i = j / 2 - 8
let j = j - 31
let htxt = utime,column i,curpag using "##########",column j,uid
if ff then let htxt = htxt clipped,prreset end if
output to report output(htxt,false)

end function

################################################################################
# Assignment of database logging flag (to be called after a database open).
################################################################################

function setdblog()

if sqlca.sqlawarn[2] = "W" then let dblogstat = true
else let dblogstat = false
end if

end function

################################################################################
# Retrieval of database logging flag.
################################################################################

function dblog()

return dblogstat

end function

################################################################################
# Transaction logging beginning.
################################################################################

function beginw()

if dblogstat then begin work end if

end function

################################################################################
# Online Transaction error assessment and reaction.
################################################################################

function assessw(sqlcode,txt)

define
  sqlcode integer,
  txt char(64),
  lv_done char
let txt = "assessw-",txt clipped
let lv_done = false
if sqlcode is null then let sqlcode = sqlca.sqlcode end if
if sqlcode = 0 then
  call commitw()
  let lv_done = true
else
  call rollbackw()
  case
  when sqlcode = 1
    call pause("changed",12,8)
  when sqlcode = 2
    call pause("nochange",12,8)
  when sqlcode = -250 or sqlcode = -263 or sqlcode = -271 or sqlcode = -289
    call pause("locked",12,8)
  when sqlcode = -691 or sqlcode = -692
    call pause("referenced",12,8)
  otherwise
    call progerr(txt,sqlcode,"")
    call pause("noupdate",6,8)
  end case
end if
return lv_done

end function

################################################################################
# Transaction logging commitment.
################################################################################

function commitw()

if dblogstat then commit work end if

end function

################################################################################
# Transaction logging rollback.
################################################################################

function rollbackw()

if dblogstat then rollback work end if

end function

################################################################################
# Execute simple sql statement (e.g. that can't be done directly in I4gl)
################################################################################

function execsql(txt)

define txt char(400)
  ,errcode integer
whenever error continue
prepare pexecsql from txt
if sqlca.sqlcode = 0 then
  execute pexecsql
  let errcode = sqlca.sqlcode
  free pexecsql
  if sqlca.sqlcode = 0 then let sqlca.sqlcode = errcode end if
end if
whenever error stop

end function

################################################################################
# Table locking (only if transaction logging enabled).
################################################################################

function tlock(tname)

define
  i smallint,
  xlock char(80),
  tname char(16)
if dblogstat then
  let xlock = "lock table ",tname," in share mode"
  prepare tlock from xlock
  whenever any error continue
  call suspend_log()
  let i = 1
  while i <= 10
    execute tlock
    if status = 0 then exit while end if
    sleep 1
    let i = i + 1
  end while
  call resume_log()
  whenever any error stop
  if i > 10 then return false end if
end if
return true

end function

################################################################################
# Read status check and reaction.
################################################################################

function readcheck(code)

define
  code integer,
  action char(16)
if code is null then let code = sqlca.sqlcode end if
case code
when 0 return(true)
when 100 call errtx("notfound")
when -284 call errtx("needinfo")
when 999 call errtx("changeinfo")
otherwise call errtxa("error",code)
end case
return (false)

end function

################################################################################
# Catastrophic system error handling.
################################################################################

function syserr(msg,stat)

define
  msg char(80),
  stat char(16),
  tx array[8] of char(64),
  i,j smallint
call mtx("syserr") returning tx[1],tx[2],tx[3],tx[4],tx[5],tx[6],tx[7],tx[8]
for i = 8 to 1 step -1 if tx[i] is not null then exit for end if end for
for j = 1 to i step 1 display tx[j] end for
display ""
let msg = stx("progloc")," ",msg clipped
display msg
sleep 1
call err_quit(stat)

end function

################################################################################
# Set system name for subsequent retrieval.
################################################################################

function setsysname(name)

define name char(32)
let systemname = name

end function

################################################################################
# Retrieval of system name.
################################################################################

function sysname()

return systemname

end function

################################################################################
# Set job type for subsequent retrieval.
################################################################################

function setjobtype(jt)

define jt char(1)
let jtype = jt

end function

################################################################################
# Retrieval of job type.
################################################################################

function jobtype()

return jtype

end function

################################################################################
# Set system id for subsequent retrieval.
################################################################################

function setsysid(id)

define id char(32)
let systemid = id

end function

################################################################################
# Retrieval of system id.
################################################################################

function sysid()

return systemid

end function

################################################################################
# Set system version for subsequent retrieval.
################################################################################

function setsysver(ver)

define ver char(16)
let systemver = ver

end function

################################################################################
# Retrieval of system version.
################################################################################

function sysver()

return systemver

end function

################################################################################
# Set number of terminal lines.
################################################################################

function setlines(l)

define l smallint
if l is null then let lines = 24
else let lines = l
end if

end function

################################################################################
# Retrieval of terminal lines.
################################################################################

function getlines()

if lines is null then let lines = 24 end if
return lines

end function

################################################################################
# Extraction of first word of a text.
################################################################################

function firstword(text)

define
  text char(64),
  i,len smallint
let text = left(text)
let len = length(text)
for i = 1 to len step +1
  if text[i,i] = " " then return text[1,i - 1] end if
end for
return text clipped

end function

################################################################################
# Extraction of the last word of a text.
################################################################################

function lastword(text)

define
  text char(64),
  i,len smallint
let text = left(text)
let len = length(text)
for i = len to 1 step -1
  if text[i,i] = " " then return text[i + 1,len] end if
end for
return text

end function


##############################################################################
# Start string parsing
##############################################################################

function parsestring(str)

define str char(1000)
let pstr = str
let ppos = 1
let plen = length(pstr)

end function

##############################################################################
# Returns the next word in the sting
##############################################################################

function parseword()

define
  i,j integer,
  str char(1000)
let str = null  
for i = ppos to plen
  if pstr[i,i] <> " " and pstr[i,i] not matches '[.,]' then exit for end if
end for
for j = i to plen
  if pstr[j,j] = " " or pstr[j,j] matches '[.,]' then exit for end if
  let str = str clipped, pstr[j,j]
end for
let ppos = j+1
return str clipped

end function

##############################################################################
# Modulus 11 check.
##############################################################################

function modulus11(numstr,len)

define
  numstr char(100),
  len,total,i,j integer
let total = 0
if len is null then let len = length(numstr) end if
let j = 1
for i = len to 1 step -1
  if j > 7 then let j = 2 end if
  let total = total + numstr[i,i] * j
  let j = j + 1
end for
let total = total mod 11
if total = 0 then return true end if
return false

end function

##############################################################################
# Swapping of control markers in a string with actual control characters.
##############################################################################

function strctrlrep(string)

define
  string char(200),
  i,j smallint,
  found char
let j = length(string)
for i = 1 to j - 1 step 1
  let found = true
  case string[i,i+1]
  when "^A" let string[i,i] = ascii 1
  when "^B" let string[i,i] = ascii 2
  when "^C" let string[i,i] = ascii 3
  when "^D" let string[i,i] = ascii 4
  when "^E" let string[i,i] = ascii 5
  when "^F" let string[i,i] = ascii 6
  when "^G" let string[i,i] = ascii 7
  when "^H" let string[i,i] = ascii 8
  when "^I" let string[i,i] = ascii 9
  when "^J" let string[i,i] = ascii 10
  when "^K" let string[i,i] = ascii 11
  when "^L" let string[i,i] = ascii 12
  when "^M" let string[i,i] = ascii 13
  when "^N" let string[i,i] = ascii 14
  when "^O" let string[i,i] = ascii 15
  when "^P" let string[i,i] = ascii 16
  when "^Q" let string[i,i] = ascii 17
  when "^R" let string[i,i] = ascii 18
  when "^S" let string[i,i] = ascii 19
  when "^T" let string[i,i] = ascii 20
  when "^U" let string[i,i] = ascii 21
  when "^V" let string[i,i] = ascii 22
  when "^W" let string[i,i] = ascii 23
  when "^X" let string[i,i] = ascii 24
  when "^Y" let string[i,i] = ascii 25
  when "^Z" let string[i,i] = ascii 26
  when "^[" let string[i,i] = ascii 27
  when "^\\" let string[i,i] = ascii 28
  when "^]" let string[i,i] = ascii 29
  when "^^" let string[i,i] = ascii 30
  when "^_" let string[i,i] = ascii 31
  when "^Ð" let string[i,i] = ascii 144
  when "^Ü" let string[i,i] = ascii 156
  otherwise let found = false
  end case
  if found then
    if i < j - 1 then let string[i+1,j-1] = string[i+2,j] end if
    let string[j,j] = ""
    let j = j - 1
  end if
end for
return string clipped

end function

##############################################################################
# Determination of number of days in a given month and year.
##############################################################################

function monthdays(mo,yr) 

define mo,yr,dy smallint
case
when mo = 4 or mo = 6 or mo = 9 or mo = 11 let dy = 30
when mo = 2
  if yr mod 4 = 0 and (yr mod 100<>0 or yr mod 400=0) then let dy = 29
  else let dy = 28
  end if
otherwise let dy = 31
end case
return dy

end function

##############################################################################
# Replacement of character within a string with another character.
##############################################################################

function chrrep(string,chr1,chr2)

define
  string char(1000),
  chr1,chr2 char(1),
  pos smallint
for pos = 1 to length(string) step 1
  if string[pos,pos] = chr1 then let string[pos,pos] = chr2 end if
end for
return string clipped

end function

##############################################################################
# Clip string and return null if just spaces
##############################################################################

function clipstr(str)

define str char(200)
if length(str)>0 then return (str clipped)
else return ""
end if

end function

##############################################################################
# Remove all spaces from string
##############################################################################

function strip(str)

define
  str char(200),
  len,i smallint
let len = length(str)
let i = 1
while i < len
  if str[i,i] = " " then
    if i > 1 then let str = str[1,i-1],str[i+1,len]
    else let str = str[2,len]
    end if
    let len = len - 1
  else let i = i + 1
  end if
end while
return str clipped

end function

##############################################################################
# Concatenation of two strings.
##############################################################################

function catstr(str1,str2)

define str1,str2 char(1000)
let str1 = str1 clipped,str2 clipped
return str1 clipped

end function

##############################################################################
# Retrieval of substring from within a string.
##############################################################################

function substr(str,pos,num)

define
  str char(1000),
  pos,num,len smallint
if pos <= 0 or num <= 0 then return "" end if
let len = length(str)
if pos > len then return("") end if
if (pos+num-1) > len then let num = len - pos +1 end if
return(str[pos,pos+num-1])

end function

##############################################################################
# Retrieves sets of column values from a table using rowids.
##############################################################################

function rowid2colval(andmark,p_rowids,p_table,p_columns)

define
  andmark char(32),                  -- retrive columns if set to "&".
  p_rowids char(1000),
  p_table,p_columns char(100),
  ptxt,retval char(1000),
  colval char(100)
initialize retval to null
if andmark = "&" then
  let ptxt = "select ",p_columns clipped,
                " from ", p_table clipped,
                " where rowid in (",p_rowids clipped,
                 ") order by ", p_columns clipped
  whenever any error continue  
  prepare prowids2col from ptxt
  declare rowids2col cursor for prowids2col
  foreach rowids2col into colval
    if retval is null then
      let retval = colval
    else
      let retval = retval clipped,",",colval
    end if
    if status <> 0 then exit foreach end if
  end foreach
  whenever error stop
else
  let retval = andmark  
end if
return retval clipped

end function

##############################################################################
# Returns a criteria sting for preparing cursors 
##############################################################################

function critstr(colname,operator,paropen,critvalue,parclose)

define
  colname char(200),
  operator char(200),
  paropen char(200),
  critvalue char(200),
  parclose char(200)
return critstr3(colname,operator,paropen,critvalue,critvalue,parclose,"")

end function

##############################################################################
# Returns a criteria sting for preparing cursors 
##############################################################################

function critstr2(colname,operator,paropen,testvalue,critvalue,parclose)

define
  colname char(200),
  operator char(200),
  paropen char(200),
  testvalue char(200),
  critvalue char(200),
  parclose char(200),
  filter char(800)
return critstr3(colname,operator,paropen,testvalue,critvalue,parclose,"")

end function

##############################################################################
# Returns a criteria sting for preparing cursors 
##############################################################################

function critstr3(colname,operator,paropen,testvalue,critvalue,parclose,rowidlist)

define
  colname char(200),
  operator char(200),
  paropen char(200),
  testvalue char(200),
  critvalue char(200),
  parclose char(200),
  rowidlist char(1000),
  filter char(800),
  i integer
let filter = null
case
when testvalue is null
  let filter = " and ",colname clipped," is null"
when testvalue = "?"
  let filter = " and ",colname clipped," is not null"
when testvalue = "&"
  if rowidlist is not null then
    let i = fgl_strpos(colname,".")
    if i <= 1 then let filter = " and rowid in (",rowidlist,")"
    else let filter = " and ",colname[1,i-1] clipped,".rowid in (",rowidlist,")"
    end if
  end if  
when testvalue <> "*"
  case paropen[1,1]
  when "'" let critvalue = fgl_strrep(critvalue clipped,"'","''")
  when '"' let critvalue = fgl_strrep(critvalue clipped,'"','""')
  end case
  let filter = " and ",colname clipped," ",operator clipped," "
    ,paropen clipped,critvalue clipped,parclose clipped
end case
return filter clipped

end function
