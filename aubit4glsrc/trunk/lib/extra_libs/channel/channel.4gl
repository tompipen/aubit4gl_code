
code
#include <stdio.h>
endcode


function open_file(handle,filename,flag)
define handle char(64)
define filename char(512)
define flag char(1)
define lv_file_o integer
define lv_file_i integer
code
A4GL_trim(filename);
A4GL_trim(handle);
endcode

let flag=downshift(flag)

case flag
	when "u"
code
 		lv_file_o=(long)stdout;
 		lv_file_i=(long)stdin;
endcode

	when "r"
code
		lv_file_o=0;
		if (strlen(filename)) {
			lv_file_i=(long)fopen(filename,"r");
		} else {
			lv_file_i=(long)stdin;
		}
endcode

	when "w"
code
		lv_file_i=0;
		if (strlen(filename)) {
			lv_file_o=(long)fopen(filename,"w");
		} else {
			lv_file_o=(long)stdin;
		}
endcode

	when "a"
code
		let lv_file_i=0;
		if (strlen(filename)) {
			lv_file_o=(long)fopen(filename,"r");
		} else {
			lv_file_o=(long)stdin;
		}
endcode
end case
if lv_file_o=0 and lv_file_i=0 then
	return
end if

code
{
FILE *x;
	x=A4GL_has_pointer(handle,CHANNEL_IN);
	if (x) {
		// Already open ?
		fclose(x);
		x=0;
		A4GL_del_pointer(handle,CHANNEL_IN);
	}

	x=A4GL_has_pointer(handle,CHANNEL_OUT);
	if (x) {
		// Already open ?
		fclose(x);
		x=0;
		A4GL_del_pointer(handle,CHANNEL_OUT);
	}

	A4GL_add_pointer(handle,CHANNEL_IN, lv_file_i);
	A4GL_add_pointer(handle,CHANNEL_OUT,lv_file_o);
	A4GL_add_pointer(handle,CHANNEL_PIPE,0);
}
endcode
end function





function open_pipe(handle,cmd,flag)
define handle char(64)
define cmd char(512)
define flag char(1)
define lv_file_o integer
define lv_file_i integer
code
A4GL_trim(cmd);
A4GL_trim(handle);
endcode

let flag=downshift(flag)

case flag
	when "u"
		error "Don't know how to do that in aubit4gl " sleep 4
code
 		lv_file_o=0
 		lv_file_i=0;
endcode

	when "r"
code
		lv_file_o=0;
		lv_file_i=(long)popen(cmd,"r");
endcode

	when "w"
code
		lv_file_i=0;
		lv_file_o=(long)popen(cmd,"w");
endcode

	when "a"
code
		let lv_file_i=0;
			lv_file_o=(long)popen(cmd,"r");
endcode
end case

if lv_file_o=0 and lv_file_i=0 then
	return
end if

code
{
FILE *x;
	if (A4GL_has_pointer(handle,CHANNEL_IN)) {
		x=A4GL_find_pointer(handle,CHANNEL_IN);
		// Already open ?
		fclose(x);
		x=0;
		A4GL_del_pointer(handle,CHANNEL_IN);
	}

	if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
		x=A4GL_find_pointer(handle,CHANNEL_OUT);
		// Already open ?
		fclose(x);
		x=0;
		A4GL_del_pointer(handle,CHANNEL_OUT);
	}

	A4GL_add_pointer(handle,CHANNEL_IN, lv_file_i);
	A4GL_add_pointer(handle,CHANNEL_OUT,lv_file_o);
	A4GL_add_pointer(handle,CHANNEL_PIPE,1);
}
endcode
end function




function set_delimiter(handle,delim) 
define handle char(64)
define delim char(1)
code
	if (A4GL_has_pointer(handle,CHANNEL_DELIM)) {
		A4GL_del_pointer(handle,CHANNEL_DELIM);
	}
	A4GL_add_pointer(handle,CHANNEL_DELIM, delim);
endcode
end function





function close(handle) 
define handle char(64)
code
{
FILE *x;
int ispipe=0;
if ( A4GL_has_pointer(handle,CHANNEL_PIPE)) {
	ispipe=(int)A4GL_find_pointer(handle,CHANNEL_PIPE);
}

if (A4GL_has_pointer(handle,CHANNEL_IN)) {
	x=A4GL_find_pointer(handle,CHANNEL_IN);
	if (ispipe)  pclose(x);
	else fclose(x);
	A4GL_del_pointer(handle,CHANNEL_IN);
}

if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
	x=A4GL_find_pointer(handle,CHANNEL_OUT);
	if (ispipe)  pclose(x);
	else fclose(x);
	A4GL_del_pointer(handle,CHANNEL_OUT);
}
}

endcode
end function


function read(handle,nvars)
define handle char(64)
define nvars integer


end function




code
aclfgl_write(int nargs) {
char *handle;
FILE *f;
char delim;
handle=A4GL_char_pop();
A4GL_trim(handle);
nargs--;

if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
}


}
endcode
