{
This file shows sample code to read and write from flat ASCII files.

This code will open the source file 'filesample.4gl' and
copy it to 'filesample.out'

note:
fputs automatically appends a new line character to output.

}
main
define ret_code integer
define file_in integer
define file_out integer
define buffer char(256)
define notdone integer
define filenamein char(60)
define filenameout char(60)
define lv_foundit integer
let lv_foundit=0

let filenamein = "filesample.4gl"
let filenameout = "filesample.out"

let file_in = A4GL_file::fopen(filenamein,"r")
let file_out = A4GL_file::fopen(filenameout,"w")   

if file_in = 0 then
    display "error opening ", filenamein clipped
    exit program
end if

if file_out = 0 then
    display "error opening ", filenameout clipped
    exit program
end if

--read first record
call a4gl_file::fgets(file_in) returning buffer

let notdone = 1
while notdone = 1

    display buffer clipped
    if buffer matches "let lv_foundit=0" then
		let lv_foundit=1
    end if

    --write to output file
    call a4gl_file::fputs(buffer, file_out) returning ret_code
    if ret_code = 0 then
        display "error writing to ", filenamein
        exit program
    end if

    --read next line
    call a4gl_file::fgets(file_in) returning buffer

    --check for eof
    IF A4GL_file::feof(file_in) THEN
        let notdone = 0
    END IF

end while

call a4gl_file::fclose(file_in) returning ret_code
call a4gl_file::fclose(file_out) returning ret_code
if lv_foundit=1 then
	exit program 0
else 
	exit program 1
end if

end main
