#Please do not remove or change this line - it is used in this test
{**
 * @file
 * Decribe the test here
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
	
	
{
	--# CALL channel::write(handle, write_string)
	--# CALL channel::set_delimiter("pipe",",")


}


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
	--#let ret = channel::read(handle, [buffer_record.Buff1, buffer_record.Buff2, buffer_record.Buff3])
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

