
main

	display " " at 1,1
        show menu file using my_menuhandler from "m1"
        call a4gl_run_gui()

end main


menuhandler my_menuhandler

on mn_exit
        exit program
end menuhandler

