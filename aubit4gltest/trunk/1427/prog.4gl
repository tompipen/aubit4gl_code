database test1
main
define w_cons CHAR(80)
create temp table constdate (d1 date)
insert into constdate values ('01/01/01')
insert into constdate values ('02/02/02')
insert into constdate values ('03/03/03')
insert into constdate values ('04/04/04')
OPEN WINDOW v_cons AT 12,13 WITH FORM "constdate"
                   ATTRIBUTE(BORDER, FORM LINE 1)
CONSTRUCT BY NAME w_cons ON d1 ATTRIBUTE(UNDERLINE,BOLD)
    BEFORE CONSTRUCT
        DISPLAY "" TO d1 ATTRIBUTE(UNDERLINE,BOLD)
END CONSTRUCT
CLOSE WINDOW v_cons

display w_cons

if w_cons="d1='020202..030303'" then
	display "Bad"
	exit program 2
else
	display "Good", w_cons
end if

end main

