{
###########################################################################
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
###########################################################################

	 $Id: channel.4gl,v 1.26 2009-07-10 11:55:45 mikeaubury Exp $
}

{**
 * @file
 *
 * Four Js compatibility - "channel" functions 
 *
 * Collections of functions for file system files handling from 4GL, 
 * Functions defined in this library:
 * open_file open_pipe set_delimiter close read
 *
 * See also: libA4GL_file library (lib/extra_libs/file)
 *
 * @todo    : Add Doc4GL comments to functions and variables in this file
 *
 * @version : original
 *
 * @process : UNKNOWN
 *
 *}

code
	#include <stdio.h>
	#include <stdlib.h>
	#define CHANNEL_IN		'L'
	#define CHANNEL_OUT		'M'
	#define CHANNEL_DELIM		'N'
	#define CHANNEL_PIPE		'P'
 //void A4GL_exitwith (char *s);
void *A4GL_find_pointer (const char *pname, char t);
//int A4GL_has_pointer (const char *pname, char t);
long A4GL_has_pointer (const char *pname, char t);
void A4GL_del_pointer (char *pname, char t);
void A4GL_add_pointer (char *orig_name, char type, void *ptr);
int aclfgl_read(int nparam) ;
int aclfgl_write (int n) ;

endcode


{**
 * 
 *
 *
 *}
######################################## 
function open_file(handle,filename,flag)
########################################
define handle char(64)
define filename char(512)
define flag char(1)
define lv_file_o integer
define lv_file_i integer
define lv_err INTEGER

LET lv_err=0

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
			lv_file_i = (long)fopen(filename,"r");
		} else {
			lv_file_i=(long)stdin;
		}
		if (lv_file_i==0) lv_err++;
endcode
	when "w"
code
		lv_file_i=0;
		if (strlen(filename)) {
			lv_file_o=(long)fopen(filename,"w");
		} else {
			lv_file_o=(long)stdin;
		}
		if (lv_file_o==0) lv_err++;
endcode
	when "a"
code
		lv_file_i=0;
		if (strlen(filename)) {
			lv_file_o=(long)fopen(filename,"a");
		} else {
			lv_file_o=(long)stdin;
		}
		if (lv_file_o==0) lv_err++;
endcode
	end case
code

	if (lv_file_o==0 && lv_file_i==0 ) {
		A4GL_exitwith("Unable to open file");

		return(0);
	}
	if (lv_err) {
		A4GL_exitwith("Unable to open file");
		return(0);
	}
endcode


code
	{
	FILE *x;
		if (A4GL_has_pointer(handle,CHANNEL_IN)) {
			// Already open ?
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_IN);
			fclose(x);
			x=0;
			A4GL_del_pointer(handle,CHANNEL_IN);
		}
	
		if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
			// Already open ?
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_OUT);
			fclose(x);
			x=0;
			A4GL_del_pointer(handle,CHANNEL_OUT);
		}
	
		A4GL_add_pointer(handle,CHANNEL_IN, (void *)lv_file_i);
		A4GL_add_pointer(handle,CHANNEL_OUT,(void *)lv_file_o);
		A4GL_add_pointer(handle,CHANNEL_PIPE,(void *)0);
	}
endcode
end function

{**
 * 
 *
 *
 *}
######################################## 
function open_pipe(handle,cmd,flag)
########################################
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
		error "Don't know how to do 'u' in aubit4gl " sleep 4
code
 		lv_file_o=0;
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
		lv_file_i=0;
		lv_file_o=(long)popen(cmd,"r");
endcode
	end case

	if lv_file_o=0 and lv_file_i=0 then
code
A4GL_set_status(-101,0);
endcode
		return
	end if

code
	{
	FILE *x;
		if (A4GL_has_pointer(handle,CHANNEL_IN)) {
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_IN);
			// Already open ?
			fclose(x);
			x=0;
			A4GL_del_pointer(handle,CHANNEL_IN);
		}
	
		if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_OUT);
			// Already open ?
			fclose(x);
			x=0;
			A4GL_del_pointer(handle,CHANNEL_OUT);
		}
	
		A4GL_add_pointer(handle,CHANNEL_IN, (void *)lv_file_i);
		A4GL_add_pointer(handle,CHANNEL_OUT,(void *)lv_file_o);
		A4GL_add_pointer(handle,CHANNEL_PIPE,(void *)1);
	}
endcode
end function


{**
 * 
 *
 *
 *}
########################################
function set_delimiter(handle,delim)
########################################
define handle char(64)
define delim char(1)
code
	A4GL_trim(handle);
	if (A4GL_has_pointer(handle,CHANNEL_DELIM)) {
		A4GL_del_pointer(handle,CHANNEL_DELIM);
	}
	A4GL_add_pointer(handle,CHANNEL_DELIM, (void *)((int)delim[0]));
endcode
end function

{**
 * 
 *
 *
 *}
########################################
function close(handle) 
########################################
define handle char(64)
code
	{
	FILE *x;
	int ispipe=0;
	A4GL_trim(handle);
		if (A4GL_has_pointer(handle,CHANNEL_PIPE)) {
			ispipe=(int)A4GL_find_pointer(handle,CHANNEL_PIPE);
			A4GL_del_pointer(handle,CHANNEL_PIPE);
		}
		
		if (A4GL_has_pointer(handle,CHANNEL_IN)) {
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_IN);
            fflush(x);
			if (ispipe)  pclose(x);
			else fclose(x);
			A4GL_del_pointer(handle,CHANNEL_IN);
		}
		
		if (A4GL_has_pointer(handle,CHANNEL_OUT)) {
			x=(FILE *)A4GL_find_pointer(handle,CHANNEL_OUT);
            fflush(x);
			if (ispipe)  pclose(x);
			else fclose(x);
			A4GL_del_pointer(handle,CHANNEL_OUT);
		}
	}

endcode
end function

{**
 * 
 *
 *
 *}
######################################## 
function fgl_read(handle,nvars)
########################################
define handle char(64)
define nvars integer


end function


code
int aclfgl_read(int nparam) {
char *handle;
char buff[20000];
struct BINDING *obind=NULL;
FILE *f;
char delim_c;
int d;
int no;
char *ptr;
char *readBytes;

// We expect 2 parameters...

if (nparam!=2) {
		A4GL_push_int(0);
	return 1;
}

if (!A4GL_pop_binding_from_stack(&obind,&no,'o')) { // Its an output binding when reading...
	A4GL_push_int(0);
	return 1;
}

	handle=A4GL_char_pop();
	A4GL_trim(handle);

	if (A4GL_has_pointer(handle,CHANNEL_DELIM)) {
		delim_c=(char )((int)A4GL_find_pointer(handle,CHANNEL_DELIM));
	} else {
		delim_c=' ';
	}


	f=(FILE *)A4GL_find_pointer(handle,CHANNEL_IN);
	if (f==0) { A4GL_push_int(0); 
			A4GL_exitwith("File is not open");
		return 1;}
	strcpy(buff,"");
	readBytes=fgets(buff,sizeof(buff)-2,f);

	if (!readBytes) {
		int a;
		for (a=0;a<no;a++) {
				A4GL_setnull(obind[a].dtype,obind[a].ptr,obind[a].size);
			}
		A4GL_push_int(0);
		if (obind) free(obind);
		return 1;
	}
		
	buff[sizeof(buff)-1]=0;

	if (!A4GL_isno(acl_getenv("KEEPNLONREAD"))) {
		int x;
		
		x=strlen(buff);
		if (x>0) { if (buff[x-1]=='\n' || buff[x-1]=='\r') {buff[x-1]=0; x--;} }
			if (x>0) {if (buff[x-1]=='\n' || buff[x-1]=='\r') {buff[x-1]=0; x--;}}
		
	}

	if (no==1) {
		char *ptr;
		A4GL_push_char(buff);
		A4GL_pop_param(obind[0].ptr,obind[0].dtype, obind[0].size); // Its all into one variable - put the whole line there
	} else {
		int a;
		ptr=buff;

		for (a=0;a<no;a++) {
			A4GL_setnull(obind[a].dtype,obind[a].ptr,obind[a].size);
		}

		for (a=0;a<no;a++) {
			char *optr;
			optr=ptr;
			// Split on delim_c
			ptr=strchr(optr,delim_c);
			if (ptr==0) {
				A4GL_push_char(optr);
				A4GL_pop_param(obind[a].ptr,obind[a].dtype,obind[a].size);
				break;
			} else {
				*ptr=0;
				A4GL_push_char(optr);
				A4GL_pop_param(obind[a].ptr,obind[a].dtype,obind[a].size);
				ptr++;
			}
		}
		
	}


	A4GL_push_int(1);
		if (obind) free(obind);
	return 1;
}
endcode

code
int aclfgl_write (int n) {
char *ptr=0;
char *handle;
FILE *f;
struct BINDING *ibind=NULL;
int ni;
char *ptr2;
char **px=0;
int l=0;
int d;
char delim_c;
int a;
char ds[2];


if (!A4GL_pop_binding_from_stack(&ibind,&ni,'o')) { // Its an output binding when reading...
	A4GL_push_int(0);
	return 1;
}
handle=A4GL_char_pop();
A4GL_trim(handle);

if (A4GL_has_pointer(handle,CHANNEL_DELIM)) {
		delim_c=(char )((int)A4GL_find_pointer(handle,CHANNEL_DELIM));
} else {
	delim_c=' ';
}

	ds[1]=0;
	ds[0]=delim_c;




	f=(FILE *)A4GL_find_pointer(handle,CHANNEL_OUT);
	if (f==0) { 
			for (a=0;a<n;a++) free(px[a]);
			free(px);
			free(ptr);
			A4GL_exitwith("File is not open");
			if (ibind) free(ibind);
			return 0;
	}
	for (a=0;a<ni;a++) {
		if (a>=1) fprintf(f,"%s",ds);
      		A4GL_push_param(ibind[a].ptr,ibind[a].dtype+ENCODE_SIZE(ibind[a].size));
      		ptr=A4GL_char_pop();
			A4GL_trim(ptr);
		fprintf(f,"%s",ptr);
			free(ptr);
	}
	fprintf(f,"\n");
	if (ibind) free(ibind);

	return 0;
}
endcode



# ------------------------------- EOF ----------------------------

