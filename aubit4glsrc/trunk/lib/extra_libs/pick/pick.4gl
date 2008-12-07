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

## #######################################################################
##
## PLEASE DONT ADD ANY EXTRA 4GLS OR C MODULES TO THIS DIRECTORY
## WITHOUT UPDATING THE OBJS_PICK in tools/asql and tools/a4gl and tools/aupscol
##
## #######################################################################
define mv_arr array[2000] of char(128)
define mv_usesep char(1) 	# use the 'display_separator' to display  the ---- Ctrl-W for help ---  line
define mv_curr_db char(80)
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
define lv_actions  array[100] of record
                type char(1),
                details char(80)
end record
define lv_actions_cnt integer
define lv_actions_used integer


define mv_inited integer

define mv_max_option_width integer
define mv_npages integer
define mv_use_form CHAR(1)
define mv_fields_per_screen integer
define mv_form_values array[200] of integer
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
local function size_picklist() 
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

if get_use_form() then
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
local function open_formwin(lv_form)
define lv_form char(32)

call close_formwin() # Ensure window is closed....

let mv_current_form=lv_form
clear screen
open window w_pickform at 1,1 with form lv_form attributes(form line 1)

end function


###############################################################################
local function close_formwin()

if mv_current_form is not null then
	close window w_pickform
	initialize mv_current_form to null
end if

end function


local function size_picklist_form()
define a integer
define this_page integer
define lv_form char(20)
define lv_fieldno integer
define lv_num_fields integer


# mv_max_option_width should already be set up - so first - pick the best matching size
case 
	when mv_max_option_width<=10 					let lv_form="pick10"  let lv_num_fields=42
	when mv_max_option_width>10 and mv_max_option_width<=20 	let lv_form="pick20"  let lv_num_fields=21
	when mv_max_option_width>20 and mv_max_option_width<=38 	let lv_form="pick38"  let lv_num_fields=14
	when mv_max_option_width>38 					let lv_form="pick78"  let lv_num_fields=7
end case

call open_formwin(lv_form)
clear form
let mv_fields_per_screen=lv_num_fields
let mv_rows=7

let this_page=1
let lv_fieldno=1

for a=1 to mv_cnt
	let mv_printat[a].x=lv_fieldno
	let mv_printat[a].page_no=this_page

	let lv_fieldno=lv_fieldno+1

	if lv_fieldno>lv_num_fields then
		let lv_fieldno=1
		if a=mv_cnt then
		else
			let this_page=this_page+1
			let lv_fieldno=2 # Skip first field - its for '...'
			#display "Putting option ", a, " on page ",this_page
			let mv_printat[a].page_no=this_page
			let mv_printat[a].x=lv_fieldno
			let lv_fieldno=lv_fieldno+1
		end if
	end if
end for

let mv_npages=this_page
end function

################################################################################
# Set the 'use_form'  flags based on the current UI
################################################################################
local function set_form()
	if fgl_getenv("A4GL_UI")="HL_GTK" or fgl_getenv("A4GL_UI")="XML" or fgl_getenv("A4GL_USE_FORMS")="Y" then
        	call aclfgl_setenv("HIDEEMPTYBUTTONS","Y");
        	call set_use_form()
	else
        	call clr_use_form()
	end if
end function


################################################################################
# GET/SET functions for mv_use_form...
################################################################################

local function set_use_form()
	if fgl_getenv("DBEDIT")="vi" then
		call aclfgl_setenv("DBEDIT","kwrite")
	end if

	let mv_use_form="Y"
	call ensure_forms_are_loaded()
end function


local function clr_use_form()
	let mv_use_form="N"
end function

function get_use_form()
	# Lets check to see if we have a value set..
	# if not - lets try to detect what we need 
	# it set to based on the current UI
	if mv_use_form is null or mv_use_form matches " " then
		call set_form()
	end if

	if mv_use_form="Y" then
		return TRUE
	else
		return FALSE
	end if
end function

################################################################################
function show_pick() 
define a,x,y integer
define lv_cnt integer
define lv_fldname char(60)
#message "USING FORM..."

if mv_cpage<=0 then
	call size_picklist()
end if

if mv_cpage!=mv_printat[mv_curr_option].page_no then
	let mv_cpage=mv_printat[mv_curr_option].page_no
	if get_use_form() then
		#display "Clearing form"
		clear form
	else
		
		call clear_screen_portion()
	end if
end if

#display "mv_cpage=",mv_cpage," mv_curr_option=", mv_curr_option, " mv_printat[mv_curr_option].page_no=",mv_printat[mv_curr_option].page_no
set pause mode on
call display_banner()

if mv_cpage>1 then
	#display "Need starting ..."
	if get_use_form() then
		let mv_form_values[1]=-1
		display "..." to val01
	else
		display "..." at 6,1
	end if
end if

if mv_cpage<mv_npages then
	if get_use_form() then
		let lv_fldname="val"||mv_fields_per_screen using "&&"
		let mv_form_values[mv_fields_per_screen]=-2

		display "..." to _variable(lv_fldname)
	else
		display "..." at mv_nexty,mv_nextx
	end if
end if


if mv_cpage>1 then
	let lv_cnt=1 # Allow space for the ... at the beginning
else
	let lv_cnt=0
end if

for a=1 to mv_cnt
	if mv_printat[a].page_no=mv_cpage then
		let lv_cnt=lv_cnt+1
		let x=mv_printat[a].x
		let y=mv_printat[a].y

		if get_use_form() then
			let lv_fldname="val"|| lv_cnt using "&&"
			let mv_form_values[lv_cnt]=a

			if a=mv_curr_option then
         			display mv_arr[a][1,mv_max_option_width]  to _variable(lv_fldname)  attribute(bold)
			else
                		display mv_arr[a][1,mv_max_option_width]  to  _variable(lv_fldname)
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
define lv_curr_option_next integer


if get_use_form() then
	#clear form
else
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

		if get_use_form() then
			display lv_description to desc
			display lv_txt2 to prompt_str
			options input no wrap

			let lv_curr_option_next=0
			input lv_value from value attribute(underline)

				on action fld1 let lv_curr_option_next=mv_form_values[1] exit input
				on action fld2 let lv_curr_option_next=mv_form_values[2] exit input
				on action fld3 let lv_curr_option_next=mv_form_values[3] exit input
				on action fld4 let lv_curr_option_next=mv_form_values[4] exit input
				on action fld5 let lv_curr_option_next=mv_form_values[5] exit input
				on action fld6 let lv_curr_option_next=mv_form_values[6] exit input
				on action fld7 let lv_curr_option_next=mv_form_values[7] exit input
				on action fld8 let lv_curr_option_next=mv_form_values[8] exit input
				on action fld9 let lv_curr_option_next=mv_form_values[9] exit input
				on action fld10 let lv_curr_option_next=mv_form_values[10] exit input
				on action fld11 let lv_curr_option_next=mv_form_values[11] exit input
				on action fld12 let lv_curr_option_next=mv_form_values[12] exit input
				on action fld13 let lv_curr_option_next=mv_form_values[13] exit input
				on action fld14 let lv_curr_option_next=mv_form_values[14] exit input
				on action fld15 let lv_curr_option_next=mv_form_values[15] exit input
				on action fld16 let lv_curr_option_next=mv_form_values[16] exit input
				on action fld17 let lv_curr_option_next=mv_form_values[17] exit input
				on action fld18 let lv_curr_option_next=mv_form_values[18] exit input
				on action fld19 let lv_curr_option_next=mv_form_values[19] exit input
				on action fld20 let lv_curr_option_next=mv_form_values[20] exit input
				on action fld21 let lv_curr_option_next=mv_form_values[21] exit input
				on action fld22 let lv_curr_option_next=mv_form_values[22] exit input
				on action fld23 let lv_curr_option_next=mv_form_values[23] exit input
				on action fld24 let lv_curr_option_next=mv_form_values[24] exit input
				on action fld25 let lv_curr_option_next=mv_form_values[25] exit input
				on action fld26 let lv_curr_option_next=mv_form_values[26] exit input
				on action fld27 let lv_curr_option_next=mv_form_values[27] exit input
				on action fld28 let lv_curr_option_next=mv_form_values[28] exit input
				on action fld29 let lv_curr_option_next=mv_form_values[29] exit input
				on action fld30 let lv_curr_option_next=mv_form_values[30] exit input
				on action fld31 let lv_curr_option_next=mv_form_values[31] exit input
				on action fld32 let lv_curr_option_next=mv_form_values[32] exit input
				on action fld33 let lv_curr_option_next=mv_form_values[33] exit input
				on action fld34 let lv_curr_option_next=mv_form_values[34] exit input
				on action fld35 let lv_curr_option_next=mv_form_values[35] exit input
				on action fld36 let lv_curr_option_next=mv_form_values[36] exit input
				

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

			if lv_curr_option_next!=0 then # Action was used
			
				if lv_curr_option_next<0 then # ACTION was used and it was a '...'

					# Previous page...
					if lv_curr_option_next=-1 and mv_cpage>1 then
						let mv_cpage=mv_printat[mv_curr_option].page_no
						while mv_cpage=mv_printat[mv_curr_option].page_no
							let mv_curr_option=mv_curr_option-1
							if mv_curr_option<1 then
								let mv_curr_option=mv_cnt
								exit while
							end if
						end while
						continue while
					end if
	
					if lv_curr_option_next=-2 then
						let mv_cpage=mv_printat[mv_curr_option].page_no
						while mv_cpage=mv_printat[mv_curr_option].page_no
							let mv_curr_option=mv_curr_option+1
							if mv_curr_option>mv_cnt then
								let mv_curr_option=1
								exit while
							end if
		
						end while
						continue while
					end if
				else 
					let mv_curr_option=lv_curr_option_next
					exit while
					# Option is > 0
				end if
			end if
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
		if get_use_form() then 
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
		if get_use_form() then 
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
	
if get_use_form() then 
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

local function ensure_forms_are_loaded()
if mv_inited=1 then
	return
end if
call init_pick_library()
end function

local function init_pick_library()
        call form_is_compiled(pick10,"MEMPACKED","GENERIC")
        call form_is_compiled(pick20,"MEMPACKED","GENERIC")
        call form_is_compiled(pick38,"MEMPACKED","GENERIC")
        call form_is_compiled(pick78,"MEMPACKED","GENERIC")
end function


################################################################################
function display_banner()

	call display_to_separator("------------------------------------------------ Press CTRL-W for Help --------")

end function


################################################################################
function clear_screen_portion()
define lv_y integer
define lv_maxy integer
code
lv_maxy=A4GL_get_curr_height();

endcode
set pause mode on
for lv_y=6 to lv_maxy
        display " ","" at lv_y,1
end for
set pause mode off
end function



function get_prompt_action()
if has_prompt_action() then
        let lv_actions_used=lv_actions_used+1
        return lv_actions[lv_actions_used].details
else
        if lv_actions_used<lv_actions_cnt then

                error "No prompt actions.." sleep 1
                call show_actions()
                sleep 2
        end if
        call clr_all_actions()
end if
return ""
end function




### These 'action' functions are used by asql etc to handle command
### line menu options
### there are just here so the linking works (Win32 complains if we call back to the executables)...
local function init_actions()
let lv_actions_cnt=0
let lv_actions_used=0

end function


function add_menu_actions(lv_s)
define lv_s char(80)
define a integer

for a=2 to length(lv_s)
        let lv_actions_cnt=lv_actions_cnt+1
        let lv_actions[lv_actions_cnt].type="M"
        let lv_actions[lv_actions_cnt].details=downshift(lv_s[a])
end for
end function


function show_actions()
define a integer
for a=1 to lv_actions_cnt
        if lv_actions[a].type="M" then
                display a," - mENU   : ", lv_actions[a].details
        elif lv_actions[a].type="P" then
                display a," - PROMPT : ", lv_actions[a].details
        else
                display a," - OTHER : ", lv_actions[a].details
        end if
end for
sleep 10
end function


function add_pick_actions(lv_s)
define lv_s char(80)
define a integer
let lv_actions_cnt=lv_actions_cnt+1
let lv_actions[lv_actions_cnt].type="P"
let lv_actions[lv_actions_cnt].details=lv_s
end function
function has_menu_action()
if lv_actions[lv_actions_used+1].type="M" then
        return true
else
        return false
end if
end function



function has_prompt_action()
if lv_actions[lv_actions_used+1].type="P" then
        return true
else
        return false
end if
end function


function arg_need_next(lv_start)
define lv_a integer
define lv_start integer

for lv_a=lv_start to num_args()
        if arg_val(lv_a) matches "-*" then
                call add_menu_actions(arg_val(lv_a))
        else
                call add_pick_actions(arg_val(lv_a))
        end if
end for

let lv_actions_used=0

return 1

end function
function get_menu_action()
if has_menu_action() then
        let lv_actions_used=lv_actions_used+1
        return lv_actions[lv_actions_used].details
else
        call clr_all_actions()
end if
return ""
end function



function has_any_action()
if has_prompt_action() or has_menu_action() then
        return true
else
        return false
end if
end function

function clr_all_actions()

        error "Invalid command line option"
        sleep 1
end function



# Set the separator flag explicitly...
function pick_set_separator(lv_yesno)
define lv_yesno char(1)
if lv_yesno="N" or lv_yesno="0" or lv_yesno="n" then
	let mv_usesep="N"
else
	let mv_usesep="Y"
end if
end function


function display_to_separator(lv_str)
define lv_str char(80)
define lv_db char(80)

if mv_usesep is null or mv_usesep = " " then
	let mv_usesep="Y"
end if


if mv_usesep="Y" then

	if mv_curr_db is not null then
        	let lv_db="_",mv_curr_db clipped,"_" # A string we can measure the length of
        	let lv_str[25,25+length(lv_db)]= " ",mv_curr_db clipped," "
	end if
	
	display lv_str at 4,1
end if
end function




function set_pick_db(lv_db)
define lv_db char(80)
	let mv_curr_db=lv_db
end function
