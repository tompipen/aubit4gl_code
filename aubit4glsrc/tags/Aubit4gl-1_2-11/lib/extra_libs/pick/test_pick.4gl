import package a4gl_pick

main
define lv_fname char(64)

	call set_pick(1,"Hello")
	call set_pick(2,"World")
	call set_pick_cnt(2)

	call prompt_pick_and_say("PICK >> ","","Choose a word") returning lv_fname
 
	call prompt_get("ENTER AN EXTENSION >> ","Please type in an extension and I'll look for it ") returning lv_fname

	call read_dir(".",lv_fname)

	call prompt_pick_and_say("PICK FILE >> ","","Choose a file") returning lv_fname

end main
