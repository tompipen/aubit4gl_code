database test1

main
define a smallint


	create temp table abc(x char(10), y char(10))

	#test for statemetn re-use without closing 
	call q ()
	call q () # on second call - ECPG_WARNING_PORTAL_EXISTS         -605
	

	
	
	#now the status=100=notfound test:
	
    select * from abc

	let a=status

	if a=notfound then
		if a=100 then
			exit program 0
        else
			display "NOTFOUND OK, but status<>100; status=",a
			exit program 1
        end if
	else
		display "status=",a
		exit program 1
	end if

end main

function q ()
define 	query_text char (100)

	let query_text = " select * from abc where 1=1"
	
   prepare s_customer from query_text
   declare c_customer scroll cursor for s_customer
   open c_customer

end function 



#Compile - onoly test for declaring insert cursor with static (not variable)
#value in insert cursor declaration
#This was causing Aubit to print EC code (INFORMIX dialect) with
#missing opening left curly bracket. Works with -ifx-p :
function yyy ()
define a char(100)

     declare ins_j_curs cursor for 
		insert into orderdetl values(1)
	
end function 




