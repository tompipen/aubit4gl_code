{*
 * Functions used in 'configurator' program
 *
 *}

code
	#include <stdio.h>
	FILE *fout=0;
endcode

GLOBALS "globals.4gl"

{*
 * Set file format to be used when saving configuration to file
 *
 *}
function set_save_type()
	menu "Save Type"
        command "SH" "Save as ksh/sh/bash environment variables format"
                let mv_save_type="SH"
                exit menu

        command "CSH" "Save as csh environment variables format"
                let mv_save_type="CSH"
                exit menu

        command "RC" "Save as aubitrc file format"
                let mv_save_type="RC"
                exit menu

        command "XML" "Save as XML file fomat"
                let mv_save_type="XML"
                exit menu

        command "Cancel" "Do not save"
                initialize mv_save_type to null
                exit menu
	end menu
end function



function load_newvals()
define a integer
define v char(50)
	display "Please wait..." at 1,1
	for a=1 to 400
		let v=get_name(a)
		if v is null or v matches " " then
			exit for
		end if
		display "Loading : ",v,"" at 2,1		
		let lv_newvals[a]=fgl_getenv(v)
	end for
end function

{*
 * When Autoconf sets initial vaues in aubitrc, it also sores list
 * of valid iptions for several settings, acording to the libraries
 * and programs found installed on the system. This function retrived
 * this stored lists. See variables named *_DETECTED in aubitrc
 *}
function load_possible_values(id)
define
	id integer
	
	case mv_option[id].name
		when "A4GL_SQLTYPE"
			call load_option("A4GL_SQLTYPE_DETECTED",id)
		when "A4GL_LEXTYPE"
			call load_option("A4GL_LEXTYPE_DETECTED",id)
		when "A4GL_LEXDIALECT"
			call load_option("A4GL_LEXDIALECT_DETECTED",id)
		when "A4GL_PDFTYPE"
			call load_option("A4GL_PDFTYPE_DETECTED",id)
		when "A4GL_RPCTYPE"
			call load_option("A4GL_RPCTYPE_DETECTED",id)
		when "A4GL_UI"
			call load_option("A4GL_UI_DETECTED",id)
		when "A4GL_FORMTYPE"
			call load_option("A4GL_FORMTYPE_DETECTED",id)
		when "A4GL_MENUTYPE"
			call load_option("A4GL_MENUTYPE_DETECTED",id)
		when "A4GL_MSGTYPE"
			call load_option("A4GL_MSGTYPE_DETECTED",id)
		when "EXDTYPE"
			call load_option("EXDTYPE_DETECTED",id)
		when "A4GL_PACKER"
			call load_option("A4GL_PACKER_DETECTED",id)
	end case
	
end function	


{* 
 * Load named option to the global array
 *}
function load_option(opt_name,id)
define 
	opt_name char (30),
	id integer,
	tmp_str char(200),
	len, cnt, start_pos, end_pos smallint
	
	let tmp_str = fgl_getenv(opt_name)

	let len = length(tmp_str) 
	if len > 1 then 
		let mv_option_offscr[id].nvalues = 0
		let mv_option_offscr[id].id = id		
		let start_pos = 0
		let end_pos = 0
		for cnt = 1 to len
			if tmp_str[cnt] = '"' then
				continue for
			end if
		
			if tmp_str[cnt] = " " then
				if start_pos <> 0 then 
					#end of value
					let end_pos=cnt-1
				end if
			else
				if start_pos = 0 then 
					#first char of new value
					let start_pos = cnt
				end if
			end if
		
			if start_pos <> 0 and end_pos <> 0 then 
				let mv_option_offscr[id].nvalues = 
					mv_option_offscr[id].nvalues + 1				
				let mv_option_offscr[id].values[mv_option_offscr[id].nvalues]=			
					tmp_str[start_pos,end_pos]
				let start_pos = 0
				let end_pos = 0
			end if
			
		end for
	
		#get the last one
		if start_pos <> 0 and end_pos = 0 then 
			if tmp_str[cnt] ='"' then
				let end_pos = cnt - 1
			else
				let end_pos = cnt
			end if
			let mv_option_offscr[id].nvalues = 
				mv_option_offscr[id].nvalues + 1				
			let mv_option_offscr[id].values[mv_option_offscr[id].nvalues]=			
				tmp_str[start_pos,end_pos]
		end if
	
	end if
		

end function


{*
 * Load, show and allow user to select between possible values for 
 * named setting.
 * 
 * Note that aubitrc now includes xxx_DETECTED - use it to prevent - or at 
 * least warn - user from selecting values that very probably will not work
 * acording to the autoconf findings (./configure)
 *
 *}
function possible_values(id,v)
define id integer
define v char(30)
define a integer

	call load_possible_values(id)

	if mv_option_offscr[id].nvalues=0 then
		error "There are no predefined values available"
		return v
	end if
	
	open window wx at 10,10 with form "values" attribute(blue,reverse,border)
	call set_count(mv_option_offscr[id].nvalues)
	let int_flag=false
	display "   AVAILABLE VALUES" at 1,1
	display array mv_option_offscr[id].values to srec1.* 
		on key(return) exit display
	end display
	close window wx
	if int_flag then
		return v
	else
		let a=arr_curr()
		#error "a=",a," option=",mv_option_offscr[id].values[a] clipped
		#sleep 5
		return mv_option_offscr[id].values[a]
	end if
end function


{*
 * Validate new setting 
 * 
 * 
 *
 *}
function validate_setting(id,v)
define id, a, cnt integer
define v char(30)

	#if not allready_loaded 
		call load_possible_values(id)
	#end if

	if mv_option_offscr[id].nvalues=0 then
		return true
	end if
	
	for cnt = 1 to mv_option_offscr[id].nvalues
		if mv_option_offscr[id].values[cnt] = v then
			return true
		end if
	end for
	return false
end function


{*
 * Clear screen and display mlti-line message in the root window
 *
 *
 *
 *}
function display_txt()
define a integer
define b integer
	set pause mode on
	whenever error continue
	for a=8 to 24
		display "" at a,1
	end for
	for a=1 to 24
		let b=a+9
		if b<=24 then
			display lv_txt[a]  at b,1
		end if
	end for
	whenever error stop
	set pause mode off
end function


{* This is the first function called in MAIN block of 'configurator' program.
 *
 *
 *
 *
 *}
function initialize ()
	let mv_window_open=0
	
	if arg_val(1) = "-firstrun" then 
		call show_firstrun()
	end if
	
	
end function

{*
 * Show the short intro message to the user when program starts, if there was 
 * a flag '-firstrun' on the command line.
 * Used from aubit-rpm.spec.in after Aubit compiler is installed from RPM package.
 *
 *}
 function show_firstrun()

 	open window wmenu at 1,1 with 3 rows, 80 columns 
	open window wdisplay at 5,9 with 14 rows,62 columns attribute(border)
	
              # "--------------------------------------------------------------	
	display " ","" 								at 1,1 attribute(cyan,reverse)
	display "        Welcome to Aubit 4GL configuration utility,","" 	at 2,1 attribute(cyan,reverse)
	display " ","" 								at 3,1 attribute(cyan,reverse)
	display " " 								at 4,1
	display " When Aubit 4GL was compiled from source code, or installed  "	at 5,1
	display " from a 'tarball' package (followed by 'make install')" 	at 6,1
	display " or installed from RPM package, a script called 'configure' " 	at 7,1
	display " was automatically executed to detect your current system"	at 8,1
	display " configuration, and based on this Aubit global configuration"	at 9,1
#Note: location of system global cinfiguration file is determined by LSB standard.
#But wheather it will be created or not will depend on user lever privilages 
#of the user installing Aubit to write under /etc 
#DO NOT HARD-CODE - use @AUBITETC@ instead
	display "  file (/etc/opt/aubit4gl/aubitrc) was created. "		at 10,1
	display " " 								at 11,1
	display " This utility allows you to inspect and change settings that"	at 12,1
	display " apply to  Aubit compile-time and run-time programs."		at 13,1
	
	current window is wmenu
	menu "Introduction Window"
		command "Close" "Close introduction window"
			#close window...
			exit menu
	end menu
	close window wmenu
	close window wdisplay
 
 end function
  
{*
 * Show array of all options belonging to the group n, and let user
 * browse and edit them.
 *
 *
 *}
function show_options(n)
define n integer
define a integer
define str char(80)
define lv_name char(80)
define lv_x char(30)
	for a=1 to 24
		let lv_txt[a]= " "
	end for

	open window w1 at 4,1 with 20 rows, 80 columns attributes(form line 1)
	if not mv_window_open then
		open form f1 from "options"
		let mv_window_open=1
	end if

	display form f1


	call set_count(n)

	display array mv_option to srec1.*
		attribute (current row display="reverse,blue")

		on key(f1) #f1 should be help?
			exit display
		
		before row
			let a=arr_curr()

			let str=fgl_getenv(mv_option[a].name)
			if (str is null or str=" ") and mv_option[a].name[1,5]="A4GL_" then
        			let lv_x=mv_option[a].name[6,30]
        			let str=fgl_getenv(lv_x)
			end if
			if str is null then
				let str="(Not Set)"
			end if
			call do_display_txt(mv_option_offscr[a].id)
			display "CURRENT VALUE =",str clipped at 8,1
			let str=lv_newvals[get_id(mv_option[a].name)]
			display "NEW     VALUE =",str clipped at 9,1

		on key(left)
	        #error "left"
            #here we should exit the DISPLAY ARRAY, re-enter the ring menu and
            #enter the next ring menu option

		on key(right)
	        #error "right"
            #here we should exit the DISPLAY ARRAY, re-enter the ring menu and
            #enter the previous ring menu option


		on key(return)
			let a=arr_curr()
			call change(mv_option[a].name,a) returning str
			let lv_name=mv_option[a].name
			let lv_newvals[get_id(lv_name)]=str
			let str=lv_newvals[get_id(lv_name)]
			display "NEW     VALUE =",str clipped at 9,1
			let int_flag=false


	end display
	close window w1
end function


{*
 *
 *
 *
 *
 *}
function load_options_from_listing(a,s)
define a integer
define s char(80)
define c integer
define n integer
define buff char(30)
let mv_option_offscr[a].nvalues=0
let c=0
code
{
char **names;
int n=0;
names=scan_directory(s);
	for (n=0;names[n];n++) 
	{
		A4GL_debug("----> DIR RETURNS %s",names[n]);
		strcpy(buff,names[n]);
endcode
		let mv_option_offscr[a].values[n+1]=buff
code
		c=c+1;
	}
}
endcode
let mv_option_offscr[a].nvalues=c;

end function


{*
 * See if any settings changed
 *
 *
 *
 *}
function settings_changed()
define a integer
define v char(50)
define o,n char(255)

	for a=1 to 400
		let v=get_name(a)
		if v is null or v matches " " then
			exit for
		end if
		let o=fgl_getenv(v)
		let n=lv_newvals[a]
		if o is null then let o= " " end if
		if n is null then let n= " " end if
		if o!=n then return true end if
	end for
	return false
end function




{*
 * Save only settings that changed
 *
 *
 *
 *}
function save_changed()
define a integer
define v char(50)
define o,n char(255)

	call set_save_type()
	if mv_save_type is null then return 0 end if
	if not get_filename() then return 0 end if
	if not start_save(mv_filename) then return 0 end if
	
	for a=1 to 400
		let v=get_name(a)
		if v is null or v matches " " then
			exit for
		end if
		let o=fgl_getenv(v)
		let n=lv_newvals[a]
		if o is null then let o= " " end if
		if n is null then let n= " " end if
		if o!=n then call save_details(v,n) end if
	end for
	call finish_save()
	return 1
end function



{*
 * Save all settings
 *
 *
 *
 *}
function save_all()
define a integer
define v char(50)
define o,n char(255)

call set_save_type()
if mv_save_type is null then return 0 end if
if not get_filename() then return 0 end if
if not start_save(mv_filename) then return 0 end if


for a=1 to 400
	let v=get_name(a)
	if v is null or v matches " " then
		exit for
	end if
	let n=lv_newvals[a]
	if n is null then let n= " " end if
	call save_details(v,n)
end for
call finish_save()
return 1
end function



{*
 * Choose between saving all or only changed settings, and invoke
 * approptiate function to save.
 *
 *
 *}
function do_save()
define lv_ok integer

	let lv_ok=0
	MENU "Save "
		COMMAND "Only changed values"
			if save_changed() then
				let lv_ok=1
				exit menu
			else
				exit menu
			end if
	
		COMMAND "All values"
			if save_all() then
				let lv_ok=1
				exit menu
			else
				exit menu
			end if
	END MENU
	return lv_ok
end function




{*
 * Prompt to save changes, if any
 *
 *
 *
 *}
function ask_save()
	if settings_changed() then
		MENU "Do you want to save your changes ?"
			COMMAND "Yes"
				if do_save() then
					exit menu
				end if
			COMMAND "No" 
				exit menu
		END MENU
	end if
end function
	


{* Check if file 'f' allready exists
 *
 *
 *}
function file_exists(f)
define f char(255)
define ok integer
code
	A4GL_trim(f);
	fout=fopen(f,"r");
	if (fout) ok=1;
		else ok=0;
endcode
return ok
end function


{* Prompt user to enter file name to save settings to
 *
 *
 *}
function get_filename()
define f, homedir, default_filename, prompt_msg char(255)

	let homedir=fgl_getenv("HOME")

	case mv_save_type
	
	when "SH"
		let default_filename = homedir clipped,"/","aubitenv.sh"
	when "RC"
		let default_filename=fgl_getenv("A4GL_INIFILE")
		if default_filename = "" or default_filename is null then 
			let default_filename = homedir clipped,"/",".aubitrc"
		end if
	when "CSH"
		let default_filename = homedir clipped,"/","aubitenv.csh"
	when "XML"
		let default_filename = homedir clipped,"/","aubitrc.xml"
	end case

	let prompt_msg = "Please enter filename (ENTER=", default_filename clipped,") :"
	let int_flag=false
	prompt prompt_msg for f
	if int_flag=true then
		initialize mv_filename to null
		return 0
	end if
	
	if f = "" or f is null then 
		let f = default_filename clipped
	end if
	
	let mv_filename=f
	return 1
end function


{*
 * Start saving settings to file; prompt to overwrite if file exist
 * open file for writing.
 *}
function start_save(f)
define f char(255)
define lv_ok integer
	let lv_ok=1
	if file_exists(f) then
		MENU "File exists - Overwrite ?"
			COMMAND "No"
				let lv_ok=0
				exit menu
	
			COMMAND "Yes"
				let lv_ok=1
				exit menu
		end menu
	end if


if lv_ok then
code
	A4GL_trim(f);
	fout=fopen(f,"w");
	if (fout==0) lv_ok=-1;
endcode

	if lv_ok=-1 then
		error "It does not appear that you have the permissions to write that file"
		let lv_ok=0
	end if
end if


return  lv_ok
end function



{* Close file opened for writing after all is saved
 *
 *
 *}
function finish_save()
code
if (fout) fclose(fout);
endcode
end function



{* Save individual setting to file opened for writing, depending
 * on save file format.
 *
 *}
function save_details(v,value)
define v char(50)
define value char(255)
define lv_line char(300)

	case mv_save_type
	
	when "SH"
		let lv_line="export ",v clipped,"=\"",value clipped,"\""
	when "RC"
		let lv_line=v clipped,"=\"",value clipped,"\""
	when "CSH"
		let lv_line="setenv ",v clipped," ",value clipped,""
	when "XML"
		let lv_line="<VARIABLE NAME=",v clipped,">",value clipped,"</VARIABLE>"
	end case
	
code
A4GL_trim(lv_line);
fprintf(fout,"%s\n",lv_line);
endcode

end function

{*
 *
 *
 *
 *
 *}
function change(x,id)
define x char(30)
define id integer
define oldval char(255)
define newval char(255)

	open window shadow at 12,5 with 13 rows, 76 columns 
		attribute(black,reverse)
	open window w2 at 12,4 with form "change"  
		attribute(border,magenta,reverse,form line 1)
	
	display "Variable : ",x,"" at 1,1 attribute (reverse,cyan)
	
	let oldval=fgl_getenv(x)
	
	if (oldval is null or oldval=" ") and x[1,5]="A4GL_" then
		let x=x[6,30]
		let oldval=fgl_getenv(x)
	end if
	
	let newval=oldval
	let int_flag=false
	
	display by name oldval
	input newval without defaults from newval 
		on key(f1) 
			exit input
		on key(f2,control-b)
			call possible_values(id,newval) returning newval
			#FIXME: this should work BUT IT DOES NOT:
			#display 255 spaces
			display "                                                                  " 
				to newval
			display newval to newval
			#FIXME: this actually works like it was:
			#display newval clipped to newval
			#newval is char(255) but you can still see remains of old value 
			#if new one is shorter then old one. So if you have
			#abcdefgh
			#and then display 
			#12345
			#you will see
			#12345fgh
	end input 
	
	close window w2
	close window shadow
	
	if int_flag=false then
		if validate_setting(id,newval) then
			return newval
		else
			menu "Does not compute"
				command "OooPs - Sorry"
					return oldval
				command "Who cares"
					return newval
			end menu
		end if
	else
		return oldval
	end if

end function


# ------------------------ EOF ------------------------------


