################################################################################
# Power-4gl demo program.
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
# Main function.
################################################################################

main

defer interrupt
call progbeg("POWER-4GL  DEMO PROGRAM")
while true
  call mmain()
  if sure("quitsys",6,2) then exit while end if
end while
call progend()

end main

################################################################################
# Main menu.
################################################################################

function mmain()

define rval char(10)
if not menuopen("mmain","","") then return end if
call menuline("acctrans","f")
call menuline("accounts","f")
call menuline("irates","f")
call menuline("munderl","m")
call menuline("mreport","m")
call menusetup()
while true
  case menuman()
  when 0 exit while
  when 1 call acctrans("") returning rval
  when 2 call accounts("","") returning rval
  when 3 call irates() returning rval
  when 4 call munderl()
  when 5 call mreport()
  end case
end while
call menuclose()

end function

################################################################################
# Underlying data menu.
################################################################################

function munderl()

define rval char(10)
if not menuopen("munderl","","") then return end if
call menuline("acctgrps","f")
call menuline("banks","f")
call menuline("states","f")
call menuline("msetup","m")
call menusetup()
while true
  case menuman()
  when 0 exit while
  when 1 call acctgrps("") returning rval
  when 2 call banks("") returning rval
  when 3 call states("","") returning rval
  when 4 call msetup()
  end case
end while
call menuclose()

end function

################################################################################
# System setup menu.
################################################################################

function msetup()

define rval char(10)
if not menuopen("msetup","","") then return end if
call menuline("printers","f")
call menuline("prntypes","f")
call menufline("System users","f",false)
call menufline("User access","f",false)
call menufline("Locations","f",false)
call menusetup()
while true
  case menuman()
  when 0 exit while
  when 1 call printers("","") returning rval
  when 2 call prntypes("") returning rval
  end case
end while
call menuclose()

end function

################################################################################
# Report menu.
################################################################################

function mreport()

define rval char(10)
if not menuopen("mreport","","") then return end if
call menuline("qatran","f")
call menuline("qirsum","f")
call menusetup()
while true
  case menuman()
  when 0 exit while
  when 1 call qatran()
  when 2 call qirsum("")
  end case
end while
call menuclose()

end function
