database syspgma4gl

define lc_maxfiles constant 2000
define lc_strlen constant 256

define lv_names array[lc_maxfiles] of char(lc_strlen)
define lv_types array[lc_maxfiles] of char(1)
define lv_dirs array[lc_maxfiles] of char(lc_strlen)

main
define lv_str char(lc_strlen)
define c integer
define lv_deffile char(lc_strlen)

# Get the name of the program from the last portion of the current directory
let lv_str=aclfgl_getcwd()
for c=length(lv_str) to 1 step -1
	if lv_str[c]="/" then
		let lv_str=lv_str[c+1,lc_strlen]
		exit for
	end if
end for

if aclfgl_file_exists("l_"||lv_str) then
	let lv_deffile="l_"||lv_str
else
	let lv_deffile=" "
end if
#generate a program - with the 
	if generate_makefile(lv_str,lv_deffile) then
		displaY "created program definition for ",lv_str clipped
		display "generating makefile"
		run "a4gl -p "||lv_str
	
	else
		display "Failed to generate program",lv_str clipped
	end if
	
end main

function generate_makefile(lv_progname, lv_deffile)
define lv_progname char(64)
define lv_vrun, lv_deffile  char(lc_strlen)
define a,c integer
define lv_handle integer
define lv_stat integer
define lv_builddir, lv_outpath char(lc_strlen)
define lv_val char(100)
for c=1 to lc_maxfiles
	let lv_names[c]= " "
	let lv_dirs[c]= " "
	let lv_types[c]= " "
end for


if lv_deffile is null or lv_deffile matches " " then
display "Using files in directory"
# Get the current list of 4gls and pers and use them instead...
code
{
char **names;
	names=A4GL_read_directory(".",".4gl");
	if (names!=0) {
		for (c=0;names[c];c++) {
			strcpy(lv_names[a++],names[c]);
		}
		free(names);
	}
	names=A4GL_read_directory(".",".per");
	if (names!=0) {
		for (c=0;names[c];c++) {
			strcpy(lv_names[a++],names[c]);
		}
		free(names);
	}
}
endcode
else
display "Using supplied file list"
	# read the list of the files instead
	let lv_handle=A4GL_file::fopen(lv_deffile,"r");
	let a=1

	if lv_handle then
		while not A4GL_file::feof(lv_handle)
			let lv_names[a]=A4GL_file::fgets(lv_handle)
			# We wont count blank lines..
			if lv_names[a] is not null and lv_names[a] not matches " " then
				let a=a+1
			end if
		end while
	end if
	let a=a-1
end if

if a=0 then
	display "No 4gls or pers found"
	return false
end if


if aclfgl_getcwd()!=fgl_getenv("VMAKE")||"/"||lv_progname then
	display "Warning : $VMAKE is not set to point to this directory"
end if

# Go through and set the file types
for c=1 to a
	
	if lv_names[c] matches "*.4gl" then
		let lv_types[c]="M"
		let lv_names[c]=lv_names[c][1,length(lv_names[c])-4]
		continue for
	end if

	if lv_names[c] matches "*.per" then
		let lv_types[c]="F"
		let lv_names[c]=lv_names[c][1,length(lv_names[c])-4]
		continue for
	end if


	# We'll need to guess - lets see if files exist with these names..
	if aclfgl_file_exists(lv_names[c] clipped||".4gl") then
		let lv_types[c]="M"
		continue for
	end if
	if aclfgl_file_exists(lv_names[c] clipped||".per") then
		let lv_types[c]="F"
		continue for
	end if

	display "Unable to get the file type for : ",lv_names[c]
	return false
	
end for



display "inserting"
	let lv_outpath="make_"||lv_progname clipped

	let lv_vrun="$VMAKE/"||lv_progname


	# theres no specific one for this user...
	# get rid of any old program definition
	delete from program where progname=lv_progname 
	delete from entity where progname=lv_progname
	delete from afglsettings where progname=lv_progname
	let lv_val=fgl_getenv("A4GL_C_COMP")
	if lv_val != " " then
		insert into afglsettings values(lv_progname, " ","A4GL_C_COMP",lv_val)
	else
		insert into afglsettings values(lv_progname, " ","A4GL_C_COMP","ccache gcc")
	end if

	insert into afglsettings values(lv_progname, " ","A4GL_USE_FORMXML","Y")

	# create a new program definition
	insert into program (
		progname    ,
		justuser   ,
		progoutdir ,
		progmakefile,
		linkflags  ,
		compflags ,
		lastupd  ,
		genmakefile) values (lv_progname, " ", lv_vrun, lv_outpath, " "," ",0,0)

for c=1 to a
	if lv_types[a]="M" then
		# Is it really a globals file ? 
	 	run "grep -y 'end globals' "||lv_names[c] clipped||".4gl > /dev/null" returning lv_stat
		if lv_stat=0 then
			let lv_types[a]="G"
		end if

	end if
	let lv_outpath="$VMAKE/"||lv_progname
	insert into entity values(0,lv_types[c],lv_progname, " ",lv_names[c],lv_outpath)
	display "Adding ",  lv_types[c], " ", lv_names[c] clipped, " " ,lv_outpath clipped
end for
return true
end function
