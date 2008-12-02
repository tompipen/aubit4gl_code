# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-7 Aubit Computing Ltd                             |
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
define mv_arr array[2000] of char(128)
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

define mv_printat array[2003] of record
		page_no integer,
		x integer,
		y integer
end record

define mv_max_option_width integer
define mv_npages integer
define mv_use_form integer
define mv_fields_per_screen integer

define mv_current_form char(32)
code
static int compare_str (const void *vs1, const void *vs2);
char **m_names = 0;

static int
compare_str (const void *vs1, const void *vs2)
{
  char *s1;
  char *s2;
  s1 = (char *) vs1;
  s2 = (char *) vs2;
  return strcmp (s1, s2);
}

endcode


################################################################################
function size_picklist() 
define a,x,y integer
define yinc integer
define this_page integer
code
mv_maxy=A4GL_get_curr_height();
mv_maxx=A4GL_get_curr_width()+1;
endcode
let mv_max_option_width=0
if mv_cnt>2000 then
code
	A4GL_assertion(1,"Internal error - out of bounds");
endcode
end if

for a=1 to mv_cnt
if a>2000 then
code
	A4GL_assertion(1,"Internal error - out of bounds");
endcode
end if
	if length(mv_arr[a])>mv_max_option_width then
		let mv_max_option_width=length(mv_arr[a])
	end if
end for

let this_page=1


if mv_cnt<4*9 then
	let yinc=1
else 
	let yinc=1
end if
	
let x=1
let y=6
let mv_rows=mv_maxy-5
let y=y-yinc
let mv_nextx=0
let mv_nexty=0

if mv_use_form then
	call size_picklist_form()
	return
end if

for a=1 to mv_cnt+1
	if a>1000 then
		continue for
	end if
	let y=y+yinc

	if y>mv_maxy then
		# Wrap around...
		let y=6
		let x=x+mv_max_option_width+2
	end if

	if x+2+mv_max_option_width>mv_maxx then
		# Wrap around to next page...
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


################################################################################
function open_formwin(lv_form)
define lv_form char(32)

call close_formwin() # Ensure window is closed....

let mv_current_form=lv_form
clear screen
open window w_pickform at 1,1 with form lv_form attributes(form line 1)

end function


################################################################################
function close_formwin()

if mv_current_form is not null then
	close window w_pickform
	initialize mv_current_form to null
end if

end function


function size_picklist_form()
define a integer
define this_page integer
define lv_form char(20)
define lv_fieldno integer
define lv_fields_across integer
define lv_fields_down integer
define lv_x integer
define lv_y integer

define lv_field_matrix array[7,15] of integer

let lv_fields_down=15


# mv_max_option_width should already be set up - so first - pick the best matching size
case 
	when mv_max_option_width<=10 					let lv_form="pick10"  let lv_fields_across=7
	when mv_max_option_width>10 and mv_max_option_width<=20 	let lv_form="pick20"  let lv_fields_across=3
	when mv_max_option_width>20 and mv_max_option_width<=38 	let lv_form="pick38"  let lv_fields_across=2
	when mv_max_option_width>38 					let lv_form="pick78"  let lv_fields_across=1
end case

call open_formwin(lv_form)
let mv_fields_per_screen=lv_fields_across*lv_fields_down
let mv_rows=lv_fields_down
let lv_fieldno=1


# Aubit4gl counts fields going across - and then down..
let lv_x=1
let lv_y=1

# Fill an array with our field numbers...
for a=1 to mv_fields_per_screen
	let lv_field_matrix[lv_x,lv_y]=a

	#display a to val[a]

	let lv_x=lv_x+1
	if lv_x>lv_fields_across then
		let lv_x=1
		let lv_y=lv_y+1
		if lv_y>lv_fields_down then
			exit for
		end if
	end if
end for

let this_page=1
let lv_fieldno=1

let lv_x=1
let lv_y=1
for a=1 to mv_cnt
	let mv_printat[a].x=lv_field_matrix[lv_x,lv_y]
	let mv_printat[a].y=lv_field_matrix[lv_x,lv_y]
	let mv_printat[a].page_no=this_page
	let lv_y=lv_y+1

	if lv_y>lv_fields_down then
		let lv_y=1
		let lv_x=lv_x+1
		if lv_x>lv_fields_across then # next page
			if a=mv_cnt then
			else
				let this_page=this_page+1

				let lv_y=2 # Skip first field - its for '...'
				let lv_x=1 
				let mv_printat[a].x=lv_field_matrix[lv_x,lv_y]
				let mv_printat[a].y=lv_field_matrix[lv_x,lv_y]
				let mv_printat[a].page_no=this_page
				let lv_y=lv_y+1
			end if
		end if
	end if

end for


let mv_npages=this_page
end function



function set_use_form()
	let mv_use_form=1
end function


function clr_use_form()
	let mv_use_form=0
end function

function get_use_form()
	return mv_use_form
end function

################################################################################
function show_pick() 
define a,x,y integer

#message "USING FORM..."

if mv_cpage<=0 then
	call size_picklist()
end if

if mv_cpage!=mv_printat[mv_curr_option].page_no then
	let mv_cpage=mv_printat[mv_curr_option].page_no
	if mv_use_form then
		clear form
	else
		call clear_screen_portion()
	end if
end if

set pause mode on
call display_banner()

if mv_cpage>1 then
	if mv_use_form then
		display "..." to val[1]
	else
		display "..." at 6,1
	end if
end if

if mv_cpage<mv_npages then
	if mv_use_form then
		display "..." to val[mv_fields_per_screen]
	else
		display "..." at mv_nexty,mv_nextx
	end if
end if

for a=1 to mv_cnt
	if mv_printat[a].page_no=mv_cpage then
		let x=mv_printat[a].x
		let y=mv_printat[a].y

		if mv_use_form then
			if a=mv_curr_option then
         			display mv_arr[a][1,mv_max_option_width]  to val[y] attribute(reverse)
			else
                		display mv_arr[a][1,mv_max_option_width]  to val[y]
        		end if
		else
			if a=mv_curr_option then
         			display mv_arr[a][1,mv_max_option_width]  at y,x attribute(reverse)
			else
                		display mv_arr[a][1,mv_max_option_width]  at y,x
        		end if
		end if
	end if
end for
set pause mode off
end function


################################################################################
function set_pick(lv_sub,lv_value)
define lv_sub integer
define lv_value char(255)
let mv_arr[lv_sub]=lv_value
end function

################################################################################
function set_pick_dup(lv_sub,lv_value)
define lv_sub integer
define lv_value char(255)
define lv_i integer

# check for a duplicate value before adding...
if lv_sub>1 then
	for lv_i=1 to lv_sub-1
		if mv_arr[lv_i]=lv_value then
			return false
		end if
	end for
end if
# Its not there
let mv_arr[lv_sub]=lv_value
return true
end function


################################################################################
function set_pick_cnt(lv_cnt)
define lv_cnt integer
let mv_cpage=-1
let mv_cnt=lv_cnt
let mv_curr_option=1
end function

function sort_pick()
code
qsort (&mv_arr[0], mv_cnt, sizeof (mv_arr[0]), compare_str);
endcode
end function

################################################################################
function set_picked_option_cnt(lv_cnt)
define lv_cnt integer
let mv_curr_option=lv_cnt
end function


################################################################################
function set_picked_option(lv_value)
define lv_value char(255)
define lv_cnt integer
for lv_cnt=1 to mv_cnt
	if lv_value=mv_arr[lv_cnt] then
		let mv_curr_option=lv_cnt
		exit for
	end if
end for
end function

################################################################################
function prompt_pick_and_say(lv_txt,lv_value,lv_description)
define lv_txt char(80)
define lv_txt2 char(80)
define lv_value char(80)
define lv_cnt integer
define lv_found integer
define lv_description char(80)
define lv_doneit integer
define lv_counter integer

if mv_use_form then
	call clear_screen_portion()
end if

if has_prompt_action() then
	return get_prompt_action()
end if

if mv_cnt >=1 then
	let int_flag=false

	let lv_counter=0
	let lv_txt2=lv_txt
	while true
		let lv_counter=lv_counter+1
		call show_pick()
		let int_flag=false

		if mv_use_form then
			display lv_description to desc
			display lv_txt2 to prompt_str
			options input no wrap
			input lv_value from value attribute(underline)
	
				on key(down)
					if mv_curr_option+1<=mv_cnt then
						let mv_curr_option=mv_curr_option+1
					else
						let mv_curr_option=1
					end if
					call show_pick()
					display lv_description to desc
					display lv_txt2 to prompt_str
				
				on key(right)
					let lv_doneit=0
					if mv_curr_option+mv_rows<=mv_cnt then
						if mv_cpage=mv_printat[mv_curr_option+mv_rows].page_no then
							let mv_curr_option=mv_curr_option+mv_rows
							let lv_doneit=1
						end if
					end if
					call show_pick()
					display lv_description to desc
					display lv_txt2 to prompt_str
		
				
				
				on key(up)
					if mv_curr_option-1>=1 then
						let mv_curr_option=mv_curr_option-1
					else
						let mv_curr_option=mv_cnt
					end if
					call show_pick()
					display lv_description to desc
					display lv_txt2 to prompt_str
				
				on key(left)
					let lv_doneit=0
					if mv_curr_option-mv_rows>=1 then
						if mv_cpage=mv_printat[mv_curr_option-mv_rows].page_no then
							let mv_curr_option=mv_curr_option-mv_rows
							let lv_doneit=1
						end if
					end if
					call show_pick()
					display lv_description to desc
					display lv_txt2 to prompt_str
				
			end input
		else
			display lv_description clipped, "" at 2,1
			prompt lv_txt2 clipped for lv_value #attribute(normal)
	
				on key(down)
					if mv_curr_option+1<=mv_cnt then
						let mv_curr_option=mv_curr_option+1
					else
						let mv_curr_option=1
					end if
				
				on key(right)
					let lv_doneit=0
					if mv_curr_option+mv_rows<=mv_cnt then
						if mv_cpage=mv_printat[mv_curr_option+mv_rows].page_no then
							let mv_curr_option=mv_curr_option+mv_rows
							let lv_doneit=1
						end if
					end if
		
				
				
				on key(up)
					if mv_curr_option-1>=1 then
						let mv_curr_option=mv_curr_option-1
					else
						let mv_curr_option=mv_cnt
					end if
				
				on key(left)
					let lv_doneit=0
					if mv_curr_option-mv_rows>=1 then
						if mv_cpage=mv_printat[mv_curr_option-mv_rows].page_no then
							let mv_curr_option=mv_curr_option-mv_rows
							let lv_doneit=1
						end if
					end if
				
			end prompt
		end if



		if fgl_lastkey()!=fgl_keyval("ENTER") and  fgl_lastkey()!=fgl_keyval("ACCEPT") and fgl_lastkey()!=fgl_keyval(".") and fgl_lastkey()!=fgl_keyval(",") and int_flag=false then
			continue while
		end if
	
		if (lv_value !="," and lv_value!=".") or int_flag=true or lv_value is null then
			exit while
		end if
	
		if lv_value="." then
			if mv_cpage=mv_npages and mv_cpage=1 then
				# Theres only a single page
			else 
				let lv_found=0
				for lv_cnt=mv_curr_option to mv_cnt
					if mv_cpage!=mv_printat[lv_cnt].page_no then
						let mv_curr_option=lv_cnt
						let lv_found=1
						exit for
					end if
				end for
				if lv_found=0 then
					let mv_curr_option=1
				end if
			end if
		end if



		if lv_value="," then
			if mv_cpage=mv_npages and mv_cpage=1 then
				# Theres only a single page
			else 
				let lv_found=0
				for lv_cnt=mv_curr_option to 1 step -1
					if mv_cpage!=mv_printat[lv_cnt].page_no then
						let mv_curr_option=lv_cnt
						let lv_found=1
						exit for
					end if
				end for

				if lv_found=0 then
					let mv_curr_option=mv_cnt
				end if
			end if
		end if


	end while
	
	
	
	if int_flag=true then
		if mv_use_form then 
			call close_formwin() # Ensure window is closed....
		else
			call clear_screen_portion()
		end if
		return ""
	end if
else
	let int_flag=false
	prompt lv_txt clipped for lv_value
	if int_flag=true then
		if mv_use_form then 
			call close_formwin() # Ensure window is closed....
		else
			call clear_screen_portion()
		end if
		return ""
	end if
end if


if lv_value is null or lv_value matches " " then
	let lv_value=mv_arr[mv_curr_option]
end if
	
if mv_use_form then 
	call close_formwin() # Ensure window is closed....
else
	call clear_screen_portion()
end if

return lv_value
end function



function prompt_get(lv_prompt,lv_desc)
define lv_prompt char(80)
define lv_desc char(80)
define lv_response char(30)
display lv_desc at 2,1

call display_banner()
let int_flag=false

if has_prompt_action() then
      return get_prompt_action()
end if


if lv_prompt matches "*PASSWORD*" then
	prompt lv_prompt clipped for lv_response attribute(invisible)
else
	prompt lv_prompt clipped for lv_response
end if


if int_flag=true then
	initialize lv_response to null
end if

return lv_response

end function
