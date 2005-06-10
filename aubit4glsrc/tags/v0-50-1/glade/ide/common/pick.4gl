import package a4gl_glade
DEFINE pickwin integer
define mv_arr array[1000] of char(128)
define mv_cnt integer
define mv_curr_option integer
define mv_title char(80)

function set_pick(lv_sub,lv_value)
define lv_sub integer
define lv_value char(255)
let mv_arr[lv_sub]=lv_value
end function


function set_pick_cnt(lv_cnt)
define lv_cnt integer
let mv_cnt=lv_cnt
let mv_curr_option=1
end function


function prompt_pick(lv_txt,lv_value)
define lv_txt char(80)
define lv_value char(80)

let mv_title=lv_txt

open form pickwin disable program using pickwin_fh 

if mv_curr_option=-1 then
	return ""
else
	return mv_arr[mv_curr_option]
end if
end function


formhandler pickwin_fh
	before open form
		#call form_caption_set(pickwin,mv_title)
		call list_column_set_header(pickwin,id_to_int(picklist),mv_title)
		#message "Set caption to ",mv_title clipped
		call copy_data_to_list()
		let mv_curr_option=-1
input
	on b_ok
		let mv_curr_option=list_current_get(pickwin,id_to_int(picklist))
		if mv_curr_option=-1 then
			Message "Nothing selected!"
		else
			close form pickwin
		end if

	on b_cancel
		let mv_curr_option=-1
		close form pickwin

end input

end formhandler



function copy_data_to_list()
define a,lv_ok integer
# Clear our list down..
while true
	call list_count_get(pickwin,Id_To_Int(picklist)) returning lv_ok
	if lv_ok then
		call list_delete(pickwin,Id_To_Int(picklist),1)
	else
		exit while
	end if
end while

for a=1 to mv_cnt
	call list_append(pickwin,Id_To_Int(picklist),mv_arr[a])
end for
end function
