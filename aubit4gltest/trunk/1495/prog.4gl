{
        Example program to demonstrate Aubit4GL bug
        Problem: varchar(60) gets truncated to 40 chars when
                 used in UPDATE command.

        A4GL_LEXDIALECT=INFORMIX
        A4GL_LEXTYPE=C
        A4GL_SQLCONVERT=YES
        A4GL_SQLTYPE=pg8
        This bug disappears if you define l_comment char(60)
}
database test1
globals
        define gr_fred record
                col varchar(60)
        end record
end globals
main
        define l_comment varchar(60)
        #define l_comment char(60)
        define l_count integer
        define l_msg char(76)

        let l_comment = "123456789012345678901234567890123456789012345678901234567890"
        # Above is 60 chars      10        20        30        40        50        60"
        call createtab()
        UPDATE fred
                SET col = l_comment
        if sqlca.sqlcode <> 0 then
                error "UPDATE failed"
		exit program 1
        else
                let l_count = sqlca.sqlerrd[3]
                let l_msg = l_count using "<<<&"," row(s) UPDATEd"
                display l_msg
        end if
        select * into gr_fred.* from fred
        display "UPDATEd col should be:\n"|| l_comment
        display "UPDATEd col is:\n"|| gr_fred.col
	unload to "x.1" select * from fred
        call droptab()
	if l_comment!=gr_fred.col then
		exit program 1
	else
		exit program 0
	end if
end main

function createtab()
        create temp table fred ( col varchar(60))
        insert into fred values('12345678901234567890')
end function

function droptab()
        drop table fred
end function
