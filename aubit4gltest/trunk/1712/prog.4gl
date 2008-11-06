main
    DEFINE exitStatus SMALLINT
    DEFINE start_date DATE

    LET exitStatus = 0

    open form sel_screen from "t1"
    display form sel_screen

    # The field format is dd/mm/yy so 10/01/08 is: Jan 10 2008
    input start_date from s.*

    close form sel_screen

    display "day:", day(start_date)
    display "month:", month(start_date)
    display "year:", year(start_date)
    if day(start_date) <> 10 or month(start_date) <> 1 or
       year(start_date) <> 2008
    then
        display "Error date not Jan 10 2008: ", start_date
        LET exitStatus = 1
    end if

    EXIT PROGRAM exitStatus
end main
