#
# You'll need to compile testmenu.menu  before running this
# mcompile testmenu.menu
#
main
	
	show menu mymenu using my_menuhandler from "testmenu"

# if you don't have this - your program will exit here!
	call run_gui()

end main


menuhandler my_menuhandler

on mn_exit
	exit program
end menuhandler
