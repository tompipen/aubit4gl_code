################################################################################
# Assorted underlying functions.
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
# Beginning of a user interface program.
################################################################################

function progbeg(text)

define
  text char(32),
  sys char(32),
  i,j smallint
options
  form line first,
  message line last,
  comment line last-1,
  prompt line last,
  error line last,
  field order unconstrained,
  input attribute (reverse),
  display attribute (bold),
  help key f1,
  insert key insert,
  delete key delete,
  next key nextpage,
  previous key prevpage,
  accept key f2
call setdblog()
call pause("welcome",2,8)
call setlines(fgl_getenv("LINES"))
call setsysname(upf(downsh(text)))
call setsysid("**")
call setsysver("1.0")
call proglogo(text)

end function

################################################################################
# End of a user interface program.
################################################################################

function progend()

clear screen

end function

################################################################################
# Program logo and background display.
################################################################################

function proglogo(text)

define
  text char(32),
  i,j smallint
call fgl_drawbox(10,38,1,42)
call fgl_drawbox(3,36,2,43)
call fgl_drawbox(5,36,5,43)
let i = (34 - length(text)) / 2 + 44
display text clipped at 3,i attribute(bold)
let text = "Developed by John H. Frantz"
let i = (34 - length(text)) / 2 + 44
display text clipped at 6,i attribute(normal)
let text = "Version ",sysver()
let i = (34 - length(text)) / 2 + 44
display text clipped at 8,i attribute(normal)
let j = getlines()
if j is null then let j = 24 end if
display "1" at j,1 attribute(normal)
display "  Help  " at j,2 attribute(reverse,bold)
display "2" at j,11 attribute(normal)
display " Accept " at j,12 attribute(reverse,bold)
display "3" at j,21 attribute(normal)
display "Refresh " at j,22 attribute(reverse,bold)
display "4" at j,31 attribute(normal)
display "Criteria" at j,32 attribute(reverse,bold)
display "5" at j,41 attribute(normal)
display " Other  " at j,42 attribute(reverse,bold)
display "6" at j,51 attribute(normal)
display " Toggle " at j,52 attribute(reverse,bold)
display "7" at j,61 attribute(normal)
display " Search " at j,62 attribute(reverse,bold)
display "8" at j,71 attribute(normal)
display "  Exit  " at j,72 attribute(reverse,bold)

end function
