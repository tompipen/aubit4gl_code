code
int init_filename=1;


endcode

define mv_tmpinfile char(255) # Filename
define mv_fin integer         # fopen file handle
define mv_filename char(255)


function remove_tmpfile()
code
if (init_filename==0) {
	unlink(mv_tmpinfile);
}
endcode

end function



################################################################################
function get_tmp_fname() 
	return mv_tmpinfile
end function


function open_tmpfile_as_stdin() 
code
mv_fin=stdin;
endcode
end function


################################################################################
function open_tmpfile(p_mode)
define p_mode char(1)
code
mv_fin=(long)fopen(mv_tmpinfile,p_mode);
A4GL_assertion(mv_fin==0,"Tried to open tmpfile failed");
endcode
end function

################################################################################
function close_tmpfile()
if mv_fin then
code
	fclose((FILE *)mv_fin);
	mv_fin=0;
endcode
end if
end function




################################################################################
function init_filename()
define do_init integer
define fin integer

code
{
do_init=init_filename;
mv_fin=0;
init_filename=0;
sprintf(mv_tmpinfile,"/tmp/a4gl_%d",getpid());
endcode

call open_tmpfile("w")

if mv_fin=0 then
	error "Unable to write temporary file",mv_tmpinfile
	exit program
end if

call close_tmpfile()


if do_init then
	initialize mv_filename to null
			#let mv_qry=""
end if
code
}
endcode

end function




################################################################################

function display_tmp_file() 
define l integer
define buff char(255)
call clear_screen_portion()
let l=6
call open_tmpfile("r")
code
while (1) {
	strcpy(buff,"");
	fgets(buff,255,(FILE *)mv_fin);
	if (feof((FILE *)mv_fin)) break;
	buff[80]=0;
endcode
	display buff,"" at l,1
code
	l++;
	if (l>23) break;
}
endcode

call close_tmpfile()
end function


function copy_file(src,dest)
define src char(255)
define dest char(255)
define lv_str char(600)
define f integer
code
A4GL_trim(src);
f=(long)fopen(src,"r");
if (!f)  {
	strcat(src,".sql");
	f=(long)fopen(src,"r");
}
endcode
if f then
	let lv_str="cp ",src clipped," ",dest
	run lv_str
else
	error "Unable to open file ",src
end if
end function


code
long get_curr_mvfin() {
	return mv_fin;
}
endcode
