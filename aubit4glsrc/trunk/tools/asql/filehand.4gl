# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-7 Aubit Computing Ltd                             |
# +----------------------------------------------------------------------+
# | Production of this software was sponsored by                         |
# |                 Cassens Transport Company                            |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
code
int do_init_filename=1;
char *get_tmp_dir();

void add_temp_file (char *s);

long get_curr_mvfin (char *lv_type);
endcode


define mv_tmpinfile array[11] of char(255) # Filename
define mv_fin array[11] of integer         # fopen file handle




################################################################################
function get_tmp_fname(lv_type) 
define lv_type CHAR(3)
define lv_a integer
let lv_a=get_type_id(lv_type)
return mv_tmpinfile[lv_a]
end function


function open_tmpfile_as_stdin(lv_type) 
define lv_type char(3)
code
mv_fin[get_type_id(lv_type)]=(long)stdin;
endcode
end function


################################################################################
function open_tmpfile(lv_type,p_mode)
define lv_type CHAR(3)
define p_mode char(1)
code
A4GL_debug("OPENING TMP : %s ",mv_tmpinfile[get_type_id(lv_type)]);
mv_fin[get_type_id(lv_type)]=(long)fopen(mv_tmpinfile[get_type_id(lv_type)],p_mode);
	add_temp_file(mv_tmpinfile[get_type_id(lv_type)]);
A4GL_assertion(mv_fin[get_type_id(lv_type)]==0,"Tried to open tmpfile failed");
endcode
end function

################################################################################
function close_tmpfile(lv_type)
define lv_type CHAR(3)
if mv_fin[get_type_id(lv_type)] then
code
	fclose((FILE *)mv_fin[get_type_id(lv_type)]);
	mv_fin[get_type_id(lv_type)]=0;
endcode
end if
end function



function get_type_id(lv_s)
define lv_s char(3)
define a integer
code
a=get_type_id(lv_s);
endcode
return a+1
end function


code
int get_type_id(char *s) {
	if (strcmp(s,"SQL")==0) return 0;
	if (strcmp(s,"PER")==0) return 1;
	if (strcmp(s,"4GL")==0) return 2;
	if (strcmp(s,"ACE")==0) return 3;
	if (strcmp(s,"MSG")==0) return 4;

	if (strcmp(s,"FRM")==0) return 5;
	if (strcmp(s,"C")==0) return 6;
	if (strcmp(s,"EC")==0) return 7;
	if (strcmp(s,"IEM")==0) return 8;
	if (strcmp(s,"ARC")==0) return 9;

	if (strcmp(s,"ERR")==0) return 10;

	return 9;
}
endcode


################################################################################
function remove_tmp_files(lv_type) 
define lv_type char(3)
define lv_fname char(256)
define a integer
for a=1 to 11 
if lv_type="ALL" or get_type_id(lv_type)==a then
	let lv_fname=mv_tmpinfile[a]
code
	A4GL_trim(lv_fname);
	unlink(lv_fname);
endcode
end if
end for
end function



function remove_err_file()
call remove_tmp_files("ERR")
end function

function has_err_file() 
define lv_fname char(256)
define fl integer

let fl=0
let lv_fname=mv_tmpinfile[get_type_id("ERR")]
code
{
	FILE *f;
        A4GL_trim(lv_fname);
	f=fopen(lv_fname,"r");
	if (f) {
		fseek(f,0,SEEK_END);
		fl=ftell(f);
		fclose(f);
	}
}
endcode

if fl>0 then
	return TRUE
else
	return FALSE
end if


end function

function copy_err_file_back() 
define lv_in,lv_out integer
define buff char(256)

call open_tmpfile("SQL","w")
let lv_out=fget_curr_mvfin("SQL");
code
	if (lv_out==stdin) lv_in=0;
endcode

call open_tmpfile("ERR","r")
let lv_in=fget_curr_mvfin("ERR");
if lv_out=0 then
	return
end if

if lv_in=0 then
	return
end if

code
{
	FILE *r_f;
	FILE *r_fo;
	int iscontinue=0;
	r_f=(FILE *)lv_in;
	r_fo=(FILE *)lv_out;
	rewind(r_f);
	while (1) {
		strcpy(buff,"");
		fgets(buff,255,r_f);

		if (strchr(buff,'\n')) {
			iscontinue=0;
		}  else {
			iscontinue=1;
		}


		if (feof(r_f)) { break; }
		buff[255]=0;

		if (buff[0]=='#' && !iscontinue) ; //  do nothing - its our error...
		else {
			fprintf(r_fo,"%s",buff);
		}
	}
}
endcode

call close_tmpfile("ERR")
call close_tmpfile("SQL")

end function

function create_err_file(lv_ln, lv_col, msg) 
define lv_ln,lv_col integer
define msg char(512)
define cline integer
define lv_in,lv_out integer
define buff char(256)

let lv_in=fget_curr_mvfin("SQL");
let cline=0

code
	if (lv_in==stdin) lv_in=0;
endcode

if lv_in=0 then
	return FALSE
end if
	
call open_tmpfile("ERR","w")
let lv_out=fget_curr_mvfin("ERR");
if lv_out=0 then
	return FALSE
end if

code
A4GL_trim(msg);
{
	FILE *r_f;
	FILE *r_fo;
	r_f=(FILE *)lv_in;
	r_fo=(FILE *)lv_out;
	rewind(r_f);
	while (1) {
		strcpy(buff,"");
		fgets(buff,255,r_f);

		if (strchr(buff,'\n')) {
			cline++;
		}

		if (cline>lv_ln && lv_ln>=0) {
			//fprintf(r_fo,"# Line %d col %d\n", lv_ln, lv_col);
			fprintf(r_fo,"#");
			lv_col--;
			while(lv_col>0) {fprintf(r_fo," "); lv_col--;}
			fprintf(r_fo,"^\n");
			fprintf(r_fo,"# %s (%d %d)\n",msg, cline,lv_ln);
			lv_ln=-1;
		}

		if (feof(r_f)) { break; }
		buff[255]=0;
		fprintf(r_fo,"%s",buff);
	}
	if (lv_ln>=0) { // Not printed - just just it at the end...
			//fprintf(r_fo,"# Line %d col %d\n", lv_ln, lv_col);
			lv_ln=-1;
			lv_col--;
			fprintf(r_fo,"#");
			lv_col--;
			while(lv_col>0) {fprintf(r_fo," "); lv_col--;}
			fprintf(r_fo,"^\n");
			fprintf(r_fo,"# %s\n",msg);

	}
}
endcode
call close_tmpfile("ERR")
call close_tmpfile("SQL")

RETURN TRUE
end function


################################################################################
function init_filename()
define do_init integer
define fin integer

code
{
int a;
do_init=do_init_filename;
if (do_init_filename) {
for (a=0;a<11;a++) { mv_fin[a]=0;}
do_init_filename=0;
sprintf(mv_tmpinfile[get_type_id("SQL")],"%s/a4gl_sql_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("PER")],"%s/a4gl_per_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("4GL")],"%s/a4gl_4gl_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("ACE")],"%s/a4gl_ace_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("MSG")],"%s/a4gl_msg_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("FRM")],"%s/a4gl_frm_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("C")],  "%s/a4gl_c_%d",get_tmp_dir(),getpid());
sprintf(mv_tmpinfile[get_type_id("ERR")],  "%s/a4gl_err_%d",get_tmp_dir(),getpid());
endcode



call open_tmpfile("SQL","w")

if mv_fin[get_type_id("SQL")]=0 then
	error "Unable to write temporary file",mv_tmpinfile[get_type_id("SQL")]
	exit program
end if

call close_tmpfile("SQL")

code
}
}
endcode

end function




################################################################################

function display_tmp_file() 
define l integer
define buff char(256)
call clear_screen_portion()
let l=6
call open_tmpfile("SQL","r")
code
while (1) {
	strcpy(buff,"");
	fgets(buff,255,(FILE *)mv_fin[get_type_id("SQL")]);
	A4GL_debug("Temp file : %s",buff);
	if (feof((FILE *)mv_fin[get_type_id("SQL")])) break;
	buff[255]=0;
endcode
	display buff,"" at l,1
code
	l++;
	if (l>23) break;
}
endcode

call close_tmpfile("SQL")
end function

function fget_curr_mvfin(lv_s)
define lv_s char(3)
define lv_a integer

code
A4GL_trim(lv_s);
lv_a=get_curr_mvfin(lv_s);

endcode

return lv_a
end function

function copy_file(src,dest,type,removeatexit)
define src char(255)
define dest char(255)
define type char(255)
define removeatexit integer
define lv_str char(600)
define buff char(255);
define f integer
define fo integer
define ok integer
let ok=0
code

A4GL_trim(src);
A4GL_trim(dest);
A4GL_trim(type);
f=(long)fopen(src,"r");

if (!f)  {
	strcat(src,type);
	f=(long)fopen(src,"r");
} 

if (f) {
	fo=(long)fopen(dest,"w");
	if (removeatexit) {
		add_temp_file(dest);
	}
}

if (fo&&f) {
	FILE *r_f;
	FILE *r_fo;
	r_f=(FILE *)f;
	r_fo=(FILE *)fo;
	rewind(r_f);
	while (1) {
		strcpy(buff,"");
		fgets(buff,255,r_f);
		if (feof(r_f)) { break; }
		buff[255]=0;
		fprintf(r_fo,"%s",buff);
	}
	fclose(r_f);
	fclose(r_fo);
	ok=1;
}
endcode

if not ok then
	error "Unable to open file src=",src, " dest=", dest," type=",type
	sleep 3 # After an error opening a file
end if
end function


code



long get_curr_mvfin (char *lv_type)
{
  return mv_fin[get_type_id (lv_type)];
}


char *used_files[1000];
int nused_files = 0;


void clean_up_temp_files(void) {
int a;
for (a=0;a<1000;a++) {
	if (used_files[a]) {
		//printf("DELETE %s\n",used_files[a]);
		unlink(used_files[a]);
	}
}
}


void add_temp_file (char *s)
{
  char buff[1000];
  int a;
  int found = 0;
  static int inited = 0;
  if (inited == 0)
    {
      for (a = 0; a < 1000; a++)
	used_files[a] = 0;
      inited = 1;
      nused_files = 0;
    }
  strcpy (buff, s);
  A4GL_trim (buff);
  found = -1;
  for (a = 0; a < 1000; a++)
    {
      if (used_files[a] == 0)
	break;
      if (strcmp (used_files[a], buff) == 0)
	{
	  found = a;
	  break;
	}
    }

  if (found == -1)
    {
      for (a = 0; a < 1000; a++)
	{
	  if (used_files[a])
	    continue;
	  used_files[a] = strdup (buff);
	  break;
	}
    }
}
endcode
