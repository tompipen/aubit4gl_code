import package a4gl_glade
define options integer
define lv_settings array[20] of char(80)


function open_settings() 
open form options  using f_options_fh
end function

function option_title(lv_option)
define lv_option char(80)
define lv_msg char(80)
if lv_option is null or lv_option = " " then
	let lv_msg="Option (none selected)"
else
	let lv_msg="Option: ",lv_option
end if

call form_caption_set(options,lv_msg)

end function



formhandler f_options_fh
define lv_selected integer
define lv_txt char(80)
before open form

	call list_column_set_header(options,id_to_int(opt_list),"Option")
	call list_append(options,id_to_int(opt_list),"SQL Editor")
	call list_append(options,id_to_int(opt_list),"Option 2")
	call list_append(options,id_to_int(opt_list),"Option 3")
	call list_append(options,id_to_int(opt_list),"Option 4")
	call list_append(options,id_to_int(opt_list),"Option 5")
	
input
	on bibble
		message "Bibble"

	on opt_list
		let lv_selected=list_current_get(options,id_to_int(opt_list))
		let lv_txt=list_text_get(options,id_to_int(opt_list),lv_selected)
		call option_title(lv_txt)
	call entry_text_set(options,id_to_int(value),lv_settings[lv_selected])


	on b_ok
		let lv_selected=list_current_get(options,id_to_int(opt_list))
		let lv_txt=entry_text_get(options,id_to_int(value))
		let lv_settings[lv_selected]=lv_txt


end input

end formhandler
