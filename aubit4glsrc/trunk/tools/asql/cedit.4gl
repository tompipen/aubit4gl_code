# +----------------------------------------------------------------------+
# | Aubit SQL Acess Program ASQL                                         |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003 Aubit Computing Ltd                               |
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

## This is a simple 4GL editor
## it need curses for two routines
## and a couple of defines.
## Should be easy to port to GTK
## But its probably better to rewrite it to use a text area..
##
## It was done this way in order to be key compatible with Informix
## There are a couple of enhancements
## HOME/END take you to the beginning/End of the line








# maximum individual line length
define line_length constant 255

# Start editing line
define edit_top 	constant 6
define edit_lines 	integer

# Edit mode text (MODIFY or NEW)
define edit_mode char(6)


# Maximum number of buffer lines
define max_buff constant 2001


define lines array[max_buff] of char(line_length)
define cursor_x,cursor_y 		integer
define topline 		integer
define leftcol 		integer
define max_x integer
define max_y integer

define key_left 	integer
define key_right 	integer
define key_up 		integer
define key_down 	integer
define key_bs 		integer
define key_home		integer
define key_end		integer
define key_pgup		integer
define key_pgdn		integer
define key_cancel	integer
code
int not_blank(char *s) {
static int lastl=-1;
int a;
char buff[1024];
if (strlen(s)!=lastl) {
	lastl=strlen(s);
	memset(buff,' ',lastl);
	buff[lastl]=0;
	}
return memcmp(buff,s,lastl);
}
endcode

function display()
define a integer
define c integer
define l char(80)
define t integer
define rest char(line_length)
define cline char (255)


let c=edit_top
set pause mode on
let max_x=0
let max_y=0
let t=edit_top

for a=topline to topline+edit_lines-1
	if length(lines[a])>max_x then
		let max_x=length(lines[a])
	end if
	let l=lines[a][leftcol,line_length]
	if c==cursor_y+t-1 then
		let cline=l
	end if
	display l,"" at c,1 	# attribute(green,dim)  # for that olde green screen feeling...

	if leftcol>1 then display "+" at c,1 end if
	let rest=lines[a][leftcol,line_length]
	let rest=rest[80,line_length]
	if rest!=" " then display "+" at c,80 end if
	let c=c+1
end for
let max_y=0

code
for (a=0;a<201;a++) {
	if (not_blank(lines[a])) {
		max_y=a+1;
	}
}

//move(y+t-2,x-1);
endcode
if cline is null then
	let cline=" "
end if
display cline[cursor_x] at cursor_y+t-1,cursor_x attribute(reverse)
set pause mode off
end function












code

#define A4GLKEY_ENTER           0xff01
#define A4GLKEY_DOWN            0xff02
#define A4GLKEY_UP              0xff03
#define A4GLKEY_LEFT            0xff04
#define A4GLKEY_RIGHT           0xff05
#define A4GLKEY_PGUP            0xff06
#define A4GLKEY_PGDN            0xff07
#define A4GLKEY_INS             0xff08
#define A4GLKEY_DEL             0xff09
#define A4GLKEY_HOME            0xff0a
#define A4GLKEY_END             0xff0b

#define A4GLKEY_DC              0xff0c
#define A4GLKEY_DL              0xff0d
#define A4GLKEY_BACKSPACE       0xff0e
#define A4GLKEY_SHTAB           0xff0f

#define A4GLKEY_CANCEL          0xfffe

#define A4GLKEY_F(x)            (0xff10+x)

endcode



function edit_init()
code
key_left	=A4GLKEY_LEFT;
key_right	=A4GLKEY_RIGHT;
key_up		=A4GLKEY_UP;
key_down	=A4GLKEY_DOWN;
key_bs		=A4GLKEY_BACKSPACE;
key_pgup	=A4GLKEY_PGUP;
key_pgdn	=A4GLKEY_PGDN;
key_home	=A4GLKEY_HOME;
key_end		=A4GLKEY_END;
key_cancel	=A4GLKEY_CANCEL;
endcode
let edit_lines=18

end function







function edit(p_edt)
define c integer
define p_edt char(6)
define c_as_char char(1)
define lv_err integer
define tmp_line char(line_length)
define tmp_line2 char(line_length)
define tmp_x,tmp_y integer
define insmode integer
define insmode_txt char(1)
let edit_mode=p_edt
let insmode=0
let topline=1
let leftcol=1
let cursor_x=1
let cursor_y=1
call display_full()
let c_as_char=" "
let int_flag=false

while true
	
	call display()
	if insmode=0 then
		let insmode_txt="O"
	else
		let insmode_txt="I"
	end if
	display insmode_txt at 4,78
	display " Co:",cursor_x+leftcol-1,"/",max_x," Ln:",cursor_y+topline-1,"/",max_y," " at 4,2


code
//c=getch();
c=A4GL_get_key(-1);

if (c==A4GLKEY_DC) c=key_left;
if (c==A4GLKEY_ENTER)  c=13;
c_as_char[0]=c;
endcode
	if c>=32 and c<127 then
		let tmp_x=cursor_x+leftcol-1
		let tmp_y=cursor_y+topline-1
		let tmp_line=lines[tmp_y]

		if insmode=0 then
			let tmp_line[tmp_x]=c_as_char
			let lines[tmp_y]=tmp_line
			let c=key_right
		else
			let tmp_line2=lines[tmp_y]
			if tmp_x>1 then
			let tmp_line=tmp_line[1,tmp_x-1],c_as_char,tmp_line2[tmp_x,line_length]
			else
			let tmp_line=c_as_char,tmp_line2
			end if
			let lines[tmp_y]=tmp_line
			let c=key_right
		end if
		
	end if

	if c=13 then
		if insmode=1 then
			call ins_nl()
		end if
		let cursor_x=1
		let leftcol=1
		let c=key_down
	end if

	if c=key_bs or c=127 then
		let c=key_left
	end if
		
	if c=fgl_keyval("ACCEPT") then let c=27 end if
	if c=fgl_keyval("INTERRUPT") then let c=-100 end if

	case c
		when key_home
			let cursor_x=1 
			let leftcol=1

		when key_end
			let leftcol=1
			let cursor_x=length(lines[cursor_y+topline-1])
			while cursor_x>79
				let leftcol=leftcol+1
				let cursor_x=cursor_x-1
			end while

		when key_left
			if cursor_x>2 then 
				let cursor_x=cursor_x-1 
			else
				if cursor_x=2 and leftcol>1 then
					let leftcol=leftcol-1
				else
					let cursor_x=1
				end if
			end if
	
		when key_right
			if cursor_x<79 then 
				let cursor_x=cursor_x+1 
			else
				if leftcol<line_length then
					let leftcol=leftcol+1
				end if
			end if

		when key_up
			if cursor_y>1 then 
				let cursor_y=cursor_y-1 
			else
				if topline>1 then
					let topline=topline-1
				end if
			end if
			if cursor_x+leftcol>length(lines[topline+cursor_y-1]) then
				let cursor_x=length(lines[topline+cursor_y-1])+1
				while cursor_x>79
					let leftcol=leftcol+1
					let cursor_x=cursor_x-1
				end while
			end if


		when key_down
			if cursor_y<edit_lines then 
				let cursor_y=cursor_y+1 
			else
				if topline<max_buff then
					let topline=topline+1
				end if
			end if

			if cursor_x+leftcol>length(lines[topline+cursor_y-1]) then
				let cursor_x=length(lines[topline+cursor_y-1])+1
				while cursor_x>79
					let leftcol=leftcol+1
					let cursor_x=cursor_x-1
				end while
			end if

		when 1 let insmode=1-insmode
		when 4 call clr_eol()
		when 24 call clr_char()
		when 18 call display_full()
		when 27 exit while
		when -100 let int_flag=true exit while
		when key_cancel let int_flag=true exit while
	end case
end while
if int_flag=false then
let lv_err=edit_file_save() 
end if
end function

function display_full()
call display_header()
call display()
end function

function display_header()
display edit_mode,": ESC    = Done editing      CTRL-A = Typeover/Insert    CTRL-R = Redraw" at 1,1
display "        CTRL-X = Delete character  CTRL-D = Delete rest of line" at 2,1
call display_banner()
end function




function ins_nl()
define tmp_line char(line_length) # Our current line
define tmp_line2 char(line_length)  #Our inserted line
define tmp_x,tmp_y integer
define a integer
	let tmp_x=cursor_x+leftcol-1
	let tmp_y=cursor_y+topline-1
	let tmp_line=lines[tmp_y]

	if tmp_x>1 then
		let tmp_line2=tmp_line[tmp_x,line_length]
		let tmp_line=tmp_line[1,tmp_x-1]
	else
		let tmp_line2=tmp_line
		let tmp_line=" "
	end if
	for a=max_buff to tmp_y step  -1
		let lines[a]=lines[a-1]
	end for
	let lines[tmp_y]=tmp_line
	let lines[tmp_y+1]=tmp_line2

end function

function clr_eol()
define tmp_line char(line_length)
define tmp_line2 char(line_length)
define tmp_x,tmp_y integer
	let tmp_x=cursor_x+leftcol-1
	let tmp_y=cursor_y+topline-1
	let tmp_line=lines[tmp_y]
	if tmp_x>1 then
		let tmp_line=tmp_line[1,tmp_x-1]
	else
			let tmp_line=" "
	end if
	let lines[tmp_y]=tmp_line

end function

function clr_char()
define tmp_line char(line_length)
define tmp_line2 char(line_length)
define tmp_x,tmp_y integer
define a integer
		let tmp_x=cursor_x+leftcol-1
		let tmp_y=cursor_y+topline-1

		let tmp_line=lines[tmp_y]
		let tmp_line=tmp_line[tmp_x,line_length]

		if tmp_line =" " then
			let tmp_line=lines[tmp_y]
			if tmp_x>1 THEN
				let lines[tmp_y]=tmp_line[1,tmp_x-1], lines[tmp_y+1] clipped
			else
				let lines[tmp_y]=lines[tmp_y+1] clipped
			end if
			for a=tmp_y+1 to max_buff-1
				let lines[a]=lines[a+1]
			end for
			let lines[max_buff]=" "
		else

			let tmp_line=lines[tmp_y]
			let tmp_line2=lines[tmp_y]
			if tmp_x>1 then
				let tmp_line=tmp_line[1,tmp_x-1],tmp_line2[tmp_x+1,line_length]
			else
				let tmp_line=tmp_line2[2,line_length]
			end if
			let lines[tmp_y]=tmp_line
		end if

end function







#===============================================================================================

function edit_load_file()
define lv_fname char(255)
define lv_a integer
define err integer
define mb integer
define ll integer
let lv_fname=get_tmp_fname("SQL")
let mb=max_buff
let ll=line_length

let err=0

for lv_a=1 to max_buff 
	let lines[lv_a]=" "
end for

code
{
	FILE *f;
	int a;
	int lv_line;
	char little_buff[256];
	A4GL_trim(lv_fname);
	f=fopen(lv_fname,"r");

	if (!f) {
		err=1;
	} else {
		lv_a=0;
		while (1) {
			
			strcpy(little_buff," ");
			if (feof(f)) break;
			fgets(little_buff,255,f);
			little_buff[255]=0;
	
			while (1) {
				int c;
				int l;
				l=strlen(little_buff);
				c=little_buff[l-1];
				if (c=='\n'||c=='\r') {little_buff[l-1]=0;continue;}
				break;
			}
			memset(lines[lv_a],' ',ll);
			lines[lv_a][ll+1]=0;
			sprintf(lines[lv_a],"%-*s",ll,little_buff);
			lv_a++;
			if (lv_a>=mb) break;
		}
		fclose(f);
	}
}
endcode

return err
end function


function edit_file_save()
define lv_fname char(255)
define lv_a integer
define err integer
define mb integer
define ll integer
let lv_fname=get_tmp_fname("SQL")
let mb=max_buff
let ll=line_length
let err=0
let max_y=1
for lv_a=1 to max_buff
	if lines[lv_a] !=" " then
		let max_y=lv_a
	end if
end for

code
{
	FILE *f;
	int a;
	int lv_line;
	char little_buff[256];
	A4GL_trim(lv_fname);
	f=fopen(lv_fname,"w");

	if (!f) {
		err=1;
	} else {
		for (lv_a=0 ;lv_a<max_y;lv_a++) {
			A4GL_trim(lines[lv_a]);
			fprintf(f,"%s\n",lines[lv_a]);
		}
		fclose(f);
	}
}
endcode
if err then
	display "Error opening file.."
	sleep 2 # After an error
end if
return err
end function


