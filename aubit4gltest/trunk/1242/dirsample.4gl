{
Example showing use of library functions to read directory entries.

This sample will read the current directory and display all entries.
Note - directory entries are not sorted.  They are displayed in the order
they are stored.  Typical ls output is sorted by ls command.

opendir accepts directory to open and returns either a valid handle or zero
on error

readdir accepts a valid directory handle and returns the next directory
entry and status code, status of zero indicates end of directory

closedir closes the open connection
}
main
define dir_name    char(60)
define dir_handle  integer
define ret_code    integer
define i           integer
define lv_foundme integer
let lv_foundme=0

let dir_handle = a4gl_file::opendir(".")

if dir_handle = 0 then
    display "error opening directory"
else
    let ret_code = 1
    while ret_code = 1

        call a4gl_file::readdir(dir_handle) returning dir_name, ret_code

        if ret_code is not null then --else end of list
            display a4gl_file::fsize_fname(dir_name)," ",dir_name clipped
		if dir_name="dirsample.4gl" then
			let lv_foundme=1
		end if
        end if

    end while
    let ret_code = a4gl_file::closedir(dir_handle)
end if
if lv_foundme then
display "OK"
	exit program 0
else
display "Not ok"
	exit program 1
end if
end main
