################################################################################
# Interface functions for list, report, menu and func modules for
# database and system dependent variations.
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

################################################################################
# Translation methods.
################################################################################

function transl(method,value)

define
  method char(30),
  value char(60),
  i smallint,
  dat date,
  mon datetime month to month
case method
when "money14" return value using "---,---,--&.&&"
when "money18" return value using "---,---,---,--&.&&"
when "datetime/date"
  let value = value[9,10],".",value[6,7],".",value[3,4],value[11,30]
when "wkdtxt3"
  let dat = value
  let i = weekday(dat)
  case i
  when 0 return upfword("sun")
  when 1 return upfword("mon")
  when 2 return upfword("tue")
  when 3 return upfword("wed")
  when 4 return upfword("thu")
  when 5 return upfword("fri")
  when 6 return upfword("sat")
  otherwise return "???"
  end case
when "montxt"
  let mon = value
  case mon
  when "1" return upfword("january")
  when "2" return upfword("february")
  when "3" return upfword("march")
  when "4" return upfword("april")
  when "5" return upfword("may")
  when "6" return upfword("june")
  when "7" return upfword("july")
  when "8" return upfword("august")
  when "9" return upfword("september")
  when "10" return upfword("oktober")
  when "11" return upfword("november")
  when "12" return upfword("desember")
  otherwise return "????"
  end case
when "yes/no"
  case value
  when "0" return upfword("no")
  when "1" return upfword("yes")
  otherwise return("???")
  end case
end case
return value clipped

end function

################################################################################
# Retrieval of default value of w/head.
################################################################################

function getwithhead(whead)

define whead char(1)
return whead

end function

################################################################################
# Retrieval of default printer name.
################################################################################

function getdefprinter()

return fgl_getenv("DEFPRINTER")

end function

################################################################################
# Retrieval of valid printer name.
################################################################################

function getprinter(prname,repwid)

define
  prname char(32),
  repwid smallint,
  prt like printer.prntnr,
  pipestr char(128),
  paglen,pagwid smallint,
  prsetup,prreset,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
    like prnadj.adjstr,
  i integer
let i = printers(prname,"")
if i is null then
  let prname = null
  call printernull()
    returning pipestr,paglen,pagwid,prsetup,prreset
    ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
else
  select code,prtnr,pipe into prname,prt,pipestr from printer where rowid = i
  call printerctrl(prt,pipestr,repwid)
    returning pipestr,paglen,pagwid,prsetup,prreset
    ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
end if
return prname,pipestr,paglen,pagwid,prsetup,prreset
  ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx

end function

################################################################################
# Check for valid printer name.
################################################################################

function checkprinter(prname,repwid)

define
  prname char(32),
  repwid smallint,
  dummy char(32),
  prt like printer.prntnr,
  pipestr char(128),
  paglen,pagwid smallint,
  prsetup,prreset,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
    like prnadj.adjstr,
  i integer
call printer_chk_code(prname,"") returning prname,dummy,i
if i then
  if prname is null then
    call printernull()
      returning pipestr,paglen,pagwid,prsetup,prreset
      ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
  else
    select prntnr,pipe into prt,pipestr from printer where code = prname
    call printerctrl(prt,pipestr,repwid)
      returning pipestr,paglen,pagwid,prsetup,prreset
      ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
  end if
end if
return prname,pipestr,paglen,pagwid,prsetup,prreset
  ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx,i

end function

################################################################################
# Setup the printer control parameters (used internally).
################################################################################

function printerctrl(prt,pipestr,repwid)

define
  prt like prntype.prntnr,
  pipestr char(128),
  repwid smallint,
  xadjcode like prnadj.adjcode,
  xadjstr like prnadj.adjstr,
  prepipe like prntype.pipe,
  paglen,pagwid,xrows,xcols smallint,
  prsetup,prreset,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx
    like prnadj.adjstr,
  update char,
  i,j smallint
select pipe into prepipe from prntype where prntnr = prt
case
when pipestr is null let pipestr = prepipe
when prepipe is not null let pipestr = prepipe clipped,"|",pipestr
end case
declare prnadj cursor for select adjcode,adjstr
  from prnadj where prntnr = prt
let paglen = null
let pagwid = null
let prsetup = null
let prreset = null
let prbold = null
let prboldx = null
let prunderl = null
let prunderlx = null
let pritalic = null
let pritalicx = null
foreach prnadj into xadjcode,xadjstr
  case
  when xadjcode = "zbold" let prbold = xadjstr
  when xadjcode = "zboldx" let prboldx = xadjstr
  when xadjcode = "zunderl" let prunderl = xadjstr
  when xadjcode = "zunderlx" let prunderlx = xadjstr
  when xadjcode = "zitalic" let pritalic = xadjstr
  when xadjcode = "zitalicx" let pritalicx = xadjstr
  when xadjcode = "xreset" let prreset = xadjstr
  when xadjcode[1,1] = "x"
    let xrows = null
    let xcols = null
    for i = 2 to length(xadjcode) - 1 step 1
      if xadjcode[i] matches "[rc]" then
        for j = i + 1 to length(xadjcode) step 1
          if xadjcode[j] not matches "[0123456789]" then exit for end if
          if xadjcode[i] = "r" then let xrows = add((xrows * 10),xadjcode[j])
          else let xcols = add((xcols * 10),xadjcode[j])
          end if
        end for
      end if
    end for
    if xrows is not null and xcols is not null then
      let update = false
      case
      when pagwid is null let update = true
      when pagwid = xcols if xrows > paglen then let update = true end if
      when pagwid < repwid if xcols > pagwid then let update = true end if
      when pagwid > repwid
        if xcols < pagwid and xcols >= repwid then let update = true end if
      end case
      if update then
        let paglen = xrows
        let pagwid = xcols
        let prsetup = xadjstr
      end if
    end if
  end case
end foreach
if paglen is null then let paglen = 66 end if
let prsetup = strctrlrep(prsetup)
let prreset = strctrlrep(prreset)
let prbold = strctrlrep(prbold)
let prboldx = strctrlrep(prboldx)
let prunderl = strctrlrep(prunderl)
let prunderlx = strctrlrep(prunderlx)
let pritalic = strctrlrep(pritalic)
let pritalicx = strctrlrep(pritalicx)
free prnadj
return pipestr,paglen,pagwid,prsetup,prreset
  ,prbold,prboldx,prunderl,prunderlx,pritalic,pritalicx

end function

################################################################################
# Setup the "null" printer (used internally).
################################################################################

function printernull()

define
  pipestr char(128),
  paglen smallint,
  prsetup,prreset like prnadj.adjstr
let pipestr = "more -cd"
let paglen = fgl_getenv("LINES")
if paglen is null then let paglen = "24" end if
let paglen = paglen - 1
let prsetup = null
let prreset = ascii 10
return pipestr,paglen,"",prsetup,prreset,"","","","","",""

end function

################################################################################
# Program error handling without termination.
################################################################################

function progerr(locat,stat,msg)

define
  locat char(32),
  stat char(16),
  msg char(1000)
call pause("progerr",6,9)
call progmail(locat,stat,msg)

end function

################################################################################
# Program error handling with termination.
################################################################################

function progerrq(locat,stat,msg)

define
  locat char(32),
  stat char(16),
  msg char(1000)
call pause("progerrq",6,9)
call progmail(locat,stat,msg)
call syserr(locat,stat)

end function

################################################################################
# Program error mailing.
################################################################################

function progmail(locat,stat,msg)

define
  locat char(32),
  stat char(16),
  msg char(1000),
  txt char(80)
call msgopen("mailing")
let txt = fgl_getenv("SYSUSER")
if txt is null then let txt = "root" end if
let txt = "elm -s'Error (",sysid() clipped,")' ",txt clipped," 2>&1 1>/dev/null"
start report progmailout to pipe txt
let txt = "ERROR! (",sysname() clipped,")"
output to report progmailout(txt)
output to report progmailout(locat)
output to report progmailout(stat)
output to report progmailout(msg)
finish report progmailout
call msgclose()

end function

################################################################################
# Program mailing output.
################################################################################

report progmailout(txt)

define txt char(1000)
output left margin 0 top margin 0 bottom margin 0 page length 1
format on every row print txt clipped

end report

###############################################################################
# Email.
################################################################################

function sendmail(filename,msubj,descrname,maddr)

define filename char(128)
  ,msubj char(48)
  ,descrname char(128)
  ,maddr char(48)
  ,mcmd char(400)
  ,i integer
{
let mcmd = "/opt/mm/bin/metasend -b -e 'quoted-printable'"
  ," -s '",msubj clipped,"' -F '",defemail() clipped,"' -t '",maddr clipped,"'"
  ," -m 'text/plain' -f '",descrname clipped,"'"
  ," -n -m 'text/plain;name=""mail.txt""' -f '",filename clipped,"'"
run mcmd returning i
if i <> 0 then
  display "Command: ",mcmd clipped
  display "Error:",i
  call errtx("Error while sending email.")
end if
sleep 1
}
  
end function

################################################################################
# Default email address.
################################################################################

function defemail()

return "xxx@xxx.xxx"

end function

################################################################################
# Translate key code to logical identifier and handle standard keys.
################################################################################

function keytransl(keycode)

define
  keycode integer,
  action char(10)
let action = keymap(keycode)
case action
when "prtscr" call pscreen()
when "opsys" call bang()
otherwise return action
end case
return "nothing"

end function

################################################################################
# Translation of key code to logical identifier.
################################################################################

function keymap(keycode)

define keycode integer
case keycode
when fgl_keyval("accept") return "accept"
when fgl_keyval("return") return "enter"
when fgl_keyval("escape") return "exit"
when fgl_keyval("help") return "help"
when fgl_keyval("insert") return "insert"
when fgl_keyval("delete") return "delete"
when fgl_keyval("up") return "up"
when fgl_keyval("down") return "down"
when fgl_keyval("left") return "left"
when fgl_keyval("right") return "right"
when fgl_keyval("prevpage") return "prevpage"
when fgl_keyval("nextpage") return "nextpage"
when fgl_keyval("tab") return "tab"
when fgl_keyval("f1") return "help"
when fgl_keyval("f2") return "accept"
when fgl_keyval("f3") return "refresh"
when fgl_keyval("f4") return "filter"
when fgl_keyval("f5") return "other"
when fgl_keyval("f6") return "toggle"
when fgl_keyval("f7") return "search"
when fgl_keyval("f8") return "exit"
when fgl_keyval("f9") return "prevset"
when fgl_keyval("f10") return "nextset"
when fgl_keyval("f20") return "home"
when fgl_keyval("f21") return "end"
when fgl_keyval("f22") return "prtscr"
when fgl_keyval("f23") return "sh-tab"
when fgl_keyval("control-z") return "opsys"
when fgl_keyval("control-p") return "print"
when fgl_keyval("control-f") return "pfile"
when fgl_keyval("interrupt") return "interrupt"
otherwise return ""
end case

end function

################################################################################
# Display text with defined attribute.
################################################################################

function disp(txt,def,r,c)

define
  txt char(79),
  def char(16),
  r,c smallint
case def
when "list" display txt at r,c attribute(normal)
when "listcurr" display txt at r,c attribute(reverse)
when "listmark" display txt at r,c attribute(reverse)
when "listcurrmark" display txt at r,c attribute(reverse,bold)
when "listlast" display txt at r,c attribute(normal,underline)
when "listcurrlast" display txt at r,c attribute(reverse,underline)
when "listmarklast" display txt at r,c attribute(reverse,underline)
when "listcurrmarklast" display txt at r,c attribute(reverse,bold,underline)
when "listinact" display txt at r,c attribute(bold)
when "titlefirst" display txt at r,c attribute(reverse,bold)
when "title" display txt at r,c attribute(bold)
when "titlelast" display txt at r,c attribute(bold,underline)
when "data" display txt at r,c attribute(bold)
when "text" display txt at r,c attribute(normal)
when "textbold" display txt at r,c attribute(bold)
when "message" display txt at r,c attribute(bold)
when "error" display txt at r,c attribute(reverse,bold)
otherwise display txt at r,c
end case

end function

################################################################################
# Display error text with defined attribute.
################################################################################

function disperr(txt)

define txt char(80)
error txt attribute(reverse,bold)

end function

################################################################################
# Display message text with defined attribute.
################################################################################

function dispmsg(txt)

define txt char(80)
message txt attribute(bold)

end function

################################################################################
# Operating system shell.
################################################################################

function opsys()

define shell char(64)
let shell = "sh"
run shell

end function

################################################################################
# Local language character sort value.
################################################################################

function charsortval(txt)

define txt char(1000)
return upper(txt)

end function

################################################################################
# Retrieval of default pipe.
################################################################################

function getdefppipe()

return ""

end function

################################################################################
# Retrieval of valid pipe name.
################################################################################

function getppipe(ppipe)

define ppipe char(32)
return ppipe,""

end function

################################################################################
# Check for valid pipe name.
################################################################################

function checkppipe(ppipe)

define ppipe char(32)
return ppipe,"",""

end function

################################################################################
# Pipe parameter storage.
################################################################################

function ppipeparam()

end function

################################################################################
# Pipe parameter retrieval.
################################################################################

function getppipegrpnr()

return ""

end function

################################################################################

function getppipebeggrp(i)

define i integer
return ""

end function

################################################################################

function getppipeendgrp(i)

define i integer
return ""

end function

################################################################################

function getppipebeglin()

return ""

end function

################################################################################

function getppipeendlin()

return ""

end function

################################################################################

function getppipebegtxt()

return ""

end function

################################################################################

function getppipeendtxt()

return ""

end function

################################################################################
# Pipe text conversion.
################################################################################

function ppipeconv(txt)

define txt char(400)
return txt clipped

end function
