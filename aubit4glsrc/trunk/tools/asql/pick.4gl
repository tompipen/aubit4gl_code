# +----------------------------------------------------------------------+
# | Aubit SQL Acess Program ASQL                                         |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003 Aubit Computing Ltd                               |
# +----------------------------------------------------------------------+
# | Production of this software was sponsored by                         |
# |                 Cassens Transport Company                            |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
define mv_arr array[1000] of char(128)
define mv_cnt integer
define mv_curr_option integer
define mv_rows integer
define mv_cpage integer
define mv_maxy integer
define mv_maxx integer

define mv_nextx integer
define mv_nexty integer

define mv_nextx_last integer
define mv_nexty_last integer

define mv_printat array[1000] of record
		page_no integer,
		x integer,
		y integer
end record

define mv_max_option_width integer
define mv_npages integer

function size_picklist() 
define a,x,y integer
define yinc integer
define this_page integer
code
mv_maxy=A4GL_get_curr_height();
mv_maxx=A4GL_get_curr_width();
endcode
let mv_max_option_width=0

for a=1 to mv_cnt
	if length(mv_arr[a])>mv_max_option_width then
		let mv_max_option_width=length(mv_arr[a])
	end if
end for

let this_page=1


if mv_cnt<4*9 then
	let yinc=2
else 
	let yinc=1
end if
	
let x=1
let y=6
let mv_rows=mv_maxy-5
let y=y-yinc
let mv_nextx=0
let mv_nexty=0

for a=1 to mv_cnt+1
	let y=y+yinc

	if y>mv_maxy then
		let y=6
		let x=x+mv_max_option_width+2
	end if

	if x+2+mv_max_option_width>mv_maxx then
		let y=7
		let x=1
		let this_page=this_page+1
		if mv_nextx=0 then
			let mv_nextx=mv_printat[a-1].x
			let mv_nexty=mv_printat[a-1].y
		else
			let mv_nextx_last=mv_printat[a-1].x
			let mv_nexty_last=mv_printat[a-1].y
		end if
		let mv_printat[a-1].page_no=this_page
		let mv_printat[a-1].x=1
		let mv_printat[a-1].y=y
		let y=y+yinc
	end if

	let mv_printat[a].x=x
	let mv_printat[a].y=y
	let mv_printat[a].page_no=this_page
code
	A4GL_debug("---XX11--- %d %d %d\n",x,y,this_page);
endcode
end for
let mv_npages=this_page
end function



function show_pick() 
define a,x,y integer

if mv_cpage<=0 then
	call size_picklist()
end if

if mv_cpage!=mv_printat[mv_curr_option].page_no then
	let mv_cpage=mv_printat[mv_curr_option].page_no
	call clear_screen_portion()
end if

set pause mode on
if mv_cpage>1 then
	display "..." at 6,1
end if

if mv_cpage<mv_npages then
	display "..." at mv_nexty,mv_nextx
end if
for a=1 to mv_cnt
	if mv_printat[a].page_no=mv_cpage then
		let x=mv_printat[a].x
		let y=mv_printat[a].y
		if a=mv_curr_option then
         		display mv_arr[a][1,mv_max_option_width]  at y,x attribute(reverse)
		else
                	display mv_arr[a][1,mv_max_option_width]  at y,x
        	end if
	end if
end for
set pause mode off
end function


function set_pick(lv_sub,lv_value)
define lv_sub integer
define lv_value char(255)
let mv_arr[lv_sub]=lv_value
end function


function set_pick_cnt(lv_cnt)
define lv_cnt integer
let mv_cpage=-1
let mv_cnt=lv_cnt
let mv_curr_option=1
end function



function prompt_pick(lv_txt,lv_value)
define lv_txt char(80)
define lv_value char(80)
call clear_screen_portion()

if mv_cnt >=1 then
	let int_flag=false
	call show_pick()
	prompt lv_txt clipped for lv_value #attribute(normal)

	on key(down)
		if mv_curr_option+1<=mv_cnt then
			let mv_curr_option=mv_curr_option+1
		else
			let mv_curr_option=1
		end if
		call show_pick()
		continue prompt
	
	on key(right)
		if mv_curr_option+mv_rows<=mv_cnt then
			let mv_curr_option=mv_curr_option+mv_rows
			call show_pick()
		end if
		continue prompt
	
	
	on key(up)
		if mv_curr_option-1>=1 then
			let mv_curr_option=mv_curr_option-1
		else
			let mv_curr_option=mv_cnt
		end if
			call show_pick()
		continue prompt
	
	on key(left)
		if mv_curr_option-mv_rows>=1 then
			let mv_curr_option=mv_curr_option-mv_rows
			call show_pick()
		end if
		continue prompt
	
	end prompt

	if int_flag=true then
		call clear_screen_portion()
		return ""
	end if
else
	let int_flag=false
	prompt lv_txt clipped for lv_value
	if int_flag=true then
		call clear_screen_portion()
		return ""
	end if
end if

if lv_value is null or lv_value matches " " then
	let lv_value=mv_arr[mv_curr_option]
end if
	
call clear_screen_portion()
return lv_value
end function

