main
    define
        p record
            start_date date,
            end_date   date
        end record

    open form sel_screen from "date_range"
    display form sel_screen

    input p.* from s.*

    close form sel_screen
    #call aclfgl_dump_screen("out")
    if p.start_date!=today or p.end_date!=today then
		exit program 1
	end if
    display p.start_date, " ", p.end_date
end main
