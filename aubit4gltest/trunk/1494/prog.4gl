main
        define l_name char(8)
        define l_no integer

        open window w1 at 2,2 with form "required"


	initialize l_no to null 
        input l_name, l_no  from name, no
                before field name
                        message "Enter Name"
                after field name
                        message ""
        
                after input
			error "Testing" sleep 1
		{
                        if l_no is null then
                                error "You must enter a number"
                                next field no
                        end if
		}
        
        end input
        close window w1
	if l_no = 1 then
		exit program 0
	else
		exit program 1
	end if
		
end main
