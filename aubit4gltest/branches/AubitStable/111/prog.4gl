#Please do not remove or change this line - it is used in this test
{**
 * @file
 * Testing 4js-style chane; functions for readin and writing files and pipe
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main
DEFINE 
	buffer_record RECORD
		Buff1 CHAR(128),
		Buff2 CHAR(128),
		Buff3 INTEGER
	END RECORD,
	buffer_line, handle CHAR(128),
	buffer_array ARRAY[1024] of CHAR(128),
	I,success, result, tmp_status INTEGER

	let success = 0
	
	#4Js
	--# let success = 1
	
	#Aubit
	--! let success = 1
	
	#Works only with Querix V 4 and higher
	--* let success = 1
	
	if success = 0 then
		display "This test is compatible only with 4Js, Aubit and Querix compilers"
		exit program 
	end if

	call mike()
	
	#Test reading from pipe channel
	let handle = "pipe_ls"
	let result = test_reading(handle,"pipe")
	if result <> 0 then
		exit program (1)
	end if
	

	#Test reading from file channel
	let handle = "file"
	let result = test_reading(handle,"file")
	if result <> 0 then
		exit program (1)
	end if

#Aubit has open_file open_pipe set_delimiter close read	
	

	 # CALL channel::write(handle, write_string)
	 #CALL channel::set_delimiter("pipe",",")





	exit program (0)

end main


##################################
function ChannelStatus(tmp_status)
##################################
define
    success,
    tmp_status
        smallint

	case tmp_status
		when (-2000)	# Cannot open file.
            let success = False
		when (-2001)	# Unsupported mode for 'open file'.
            let success = False
		when (-2002)	# Cannot open pipe.
            let success = False
		when (-2003)	# Unsupported mode for 'open pipe'.
            let success = False
		when (-2004)	# Cannot write to unopened file or pipe.
            let success = False
		when (-2005)	# Channel write error.
            let success = False
		when (-2006)	# Cannot read from unopened file or pipe.
            let success = False
		when 0			# No error
            let success = True
		otherwise       # Some other error !!
            let success = False
	end case

    return success

end function


function test_reading(handle,read_from)
define
	success, tmp_status, ret, result smallint,
	buffer_record RECORD
		Buff1 CHAR(128),
		Buff2 CHAR(128),
		Buff3 INTEGER
	END RECORD,
	buffer_line, handle, read_from, compare_with CHAR(128),
	buffer_array ARRAY[1024] of CHAR(128),
	I INTEGER
	
	let compare_with = "#Please do not remove or change this line - it is used in this test"
	
	
	if read_from = "pipe" then
		call open_pipe(handle)
	else
		call open_file(handle)
	end if
	
	let result = 0
	display "--------------------------------------------------------------"
	
#To single var:
	let ret = channel::read(handle, buffer_line)
	let tmp_status=status
	display "ret=",ret
	let success = ChannelStatus(tmp_status)
	display "success=", success
	display "buffer_line=", buffer_line clipped
	
	if read_from = "pipe" then 
		if buffer_line <> "prog.4gl" then 
			let result = 1		
		end if
	else
		if buffer_line <> compare_with then 
			let result = 1
		end if
	end if
	
	if not success then 
		let result = 1
	end if
	display "--------------------------------------------------------------"
	
	call close_channel(handle)
	if read_from = "pipe" then
		call open_pipe(handle)
	else
		call open_file(handle)
	end if
	
#To array:

	
	LET I = 1
	WHILE channel::read(handle, buffer_array[I])
		display "buffer_array[",I,"]=", buffer_array[I] clipped
		LET I = I + 1
	END WHILE
    if I > 1 then let success = true else let success = false end if
	display success

	if read_from = "pipe" then 
		if buffer_array[1] <> "prog.4gl" then 
			let result = 1		
		end if
	else
		if buffer_line <> compare_with then 
			let result = 1
		end if		
	end if
	
	if not success then
		let result = 1
	end if
	display "--------------------------------------------------------------"
	
	call close_channel(handle)
	if read_from = "pipe" then
		call open_pipe(handle)
	else
		call open_file(handle)
	end if
	
#To record:

#Commented out because it failes to compile with Aubit ATM:
	let ret = channel::read(handle, [buffer_record.Buff1, buffer_record.Buff2, buffer_record.Buff3])
	let tmp_status = status
	display "ret=",ret
	let success = ChannelStatus(tmp_status)
	display "success=", success
	
	display "buffer_record.Buff1=", buffer_record.Buff1 clipped
	display "buffer_record.Buff2=", buffer_record.Buff2 clipped
	display "buffer_record.Buff3=", buffer_record.Buff3	clipped
	if read_from = "pipe" then 
		if buffer_record.Buff1 <> "prog.4gl" then 
			let result = 1		
		end if
	else
		if buffer_line <> compare_with then 
			let result = 1
		end if		
	end if
	if not success then
		let result = 1
	end if
	display "--------------------------------------------------------------"
	display "resul=", result 	
	return result
	
	
	call close_channel(handle)
	
end function

function open_pipe(handle)
define
	handle char (30),
	tmp_status, success smallint
	
	CALL channel::open_pipe(handle, "ls *.4gl", "r") 
	let tmp_status = status
	display "open pipe status=",tmp_status
	let success = ChannelStatus(tmp_status)
	display "success=", success
	if not success then
		exit program (1)
	end if

end function


function open_file(handle)
define
	handle char (30),
	tmp_status, success smallint
	
	CALL channel::open_file(handle, "prog.4gl", "r")
	##Aubit has open_file open_pipe set_delimiter close read
	#CALL A4GL_channel::open_file(handle,"r")

	let tmp_status = status
	display "open file status=",tmp_status
	let success = ChannelStatus(tmp_status)
	display "success=", success
	if not success then
		exit program (1)
	end if

end function



function close_channel(handle)
define
	handle char (30),
	tmp_status, success smallint


	CALL channel::close(handle)
	let tmp_status = status
	display "Close channel status=",tmp_status
	let success = ChannelStatus(tmp_status)
	display "success=", success
	if not success then 
		exit program (1)
	end if

end function



function mike()
define lv_rec record
        uname char(8),
        passwd char(20),
        uid integer,
        gid integer,
        udesc char(50),
        uhome char(50),
        ushell char(50)
	end record
define lv_a char(10)
define b integer
define tmp_string char (180)

	let lv_a="fin"
	call channel::open_file("fin","/etc/passwd","r")
	call channel::set_delimiter("fin",":")
	
	call channel::open_file("fout","./tmp.out","w")
{	
	while channel::read(lv_a,[lv_Rec.*])
			display "Uname=",lv_rec.uname," uid=",lv_rec.uid 
	end while
}	

	while channel::read(lv_a,[lv_Rec.*])
		let tmp_string=
			lv_rec.uname clipped,":",
			lv_rec.passwd clipped,":",
			lv_rec.uid  ,":",
			lv_rec.gid ,":",
			lv_rec.udesc clipped,":",
			lv_rec.uhome clipped,":",
			lv_rec.ushell clipped,":"
		
			{
			channel::write ( handle, buffer-list )
			Handle CHAR(n) - Channel identifier
			buffer-list - Variable List of variables. Use [ ] square braces when
						more than one variable is used.
			Returns  - None
			}
{
	This works in Aubit, but not in 4Js which does not return anything:
		if not channel::write("fout", tmp_string) then
        #if not channel::write("fout",[lv_Rec.*]) then
                display "Error writing"
        end if
}
		#call channel::write("fout", tmp_string)
		call channel::write("fout",[lv_Rec.*])

        display "Uname=",lv_rec.uname," uid=",lv_rec.uid
	end while

	CALL channel::CLOSE(lv_a)    	
	CALL channel::CLOSE("fout")
	
#Do I get something like :
#root    :x                   :0          :0          :root                                              :/root                                             :/bin/bash
	
#exit program
	
end function




{
If you've got A4GL_LEXTYPE=EC and A4GL:_LEXDIALECT=POSTGRES you should get the 
first couple of SQL's translated in the .cpc - something like :

   EXEC SQL SELECT tabname INTO
        :_vo_0 INDICATOR :_voi_0
    FROM  systables  WHERE substr(tabname,1,3) = 'sys' AND tabid = 1  ;

For the remaining ones - if you run the program as soon as it hits test 3 - it 
should fire up the translation module at runtime as still work :

}
function sqlconvert()

define lv_s char(20)
define lv_str char(200)


        display "Test 1 - plain SQL"
        select tabname into lv_s from systables where tabname[1,3]="sys" and tabid=1

        display " "
        display "Test 2 - declare for plain SQL"
        declare c0 cursor for select tabname From systables b where tabname[1,3]="sys"

        foreach c0 into lv_s
                display lv_s
        END FOREACH

        display " "
        display "Test 3 - declare for prepared SQL"
        prepare p1 from "select tabname From systables b where tabname[1,3]=\"sys\" "
        declare c1 cursor for p1

        foreach c1 into lv_s
                display lv_s
        END FOREACH


        display " "
        display "Test 4 - another declare for prepared SQL"
        let lv_str="select tabname From systables b where tabname[1,3]!=\"sys\" "
        prepare p2 from lv_str
        declare c2 cursor for p2

        foreach c2 into lv_s
                display lv_s
        END FOREACH

        display " "
        display "Test 5 - another declare for prepared SQL with matches"
        let lv_str="select tabname From systables b where tabname matches \"syst*\" "
        prepare p3 from lv_str
        declare c3 cursor for p3

        foreach c3 into lv_s
                display lv_s
        END FOREACH


end function


