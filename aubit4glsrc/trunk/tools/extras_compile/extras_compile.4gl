code
#include <stdio.h>
FILE *p_file;
endcode

define lv_width integer
define lv_height integer
define lv_fileline integer
define lc_max_display_lines constant 60
define lv_arr array[lc_max_display_lines] of char(255)
define mv_cnt integer


# Total number of programs to compile...
define lc_num_compiles constant 102

define lv_fail array[200] of char(80)
define lv_ok array[200] of  char(80)
define lv_fail_cnt integer
define lv_ok_cnt integer


function middle(s,w)
define s char(255)
define s1 char(255)
define i integer
define w integer
define a integer
let a=w-length(s)
let a=a/2
let s1[a,255]=s
return s1
end function




main
define lv_cnt integer
define lv_make chaR(200)
call startlog("blah")
let lv_ok_cnt=1
let lv_fail_cnt=1
let mv_cnt=0
start report compile_status to "compile_extras.out"
start report lines to "makerest.log"

for lv_cnt=1 to lc_max_display_lines
	let lv_arr[lv_cnt]=" "
end for

let lv_make=fgl_getenv("A4GL_MAKE")

if lv_make is null or lv_make matches " " then
	let lv_make="make"
end if

# Make sure its set in the environment
# we might have picked it up from an aubitrc file...
call aclfgl_setenv("A4GL_MAKE", lv_make clipped)

let lv_fileline=0

if console_mode() then
	display "Aubit4GL Extras Compilation"
	let lv_width=253
	let lv_height=24
else
	display " " at 1,1 # go to screen mode..
	let lv_width=aclfgl_get_curr_width()
	if lv_width>255 then
		let lv_width=255
	end if
	let lv_width=lv_width-2

	let lv_height=aclfgl_get_curr_height()-7 
	if lv_height>lc_max_display_lines then
		let lv_height=lc_max_display_lines
	end if

	display middle("Aubit4GL Extras Compilation",lv_width)  at 1,1 attributes(reverse,cyan)
	open  window w_title at 3,2 with 3 rows, lv_width columns attribute(border)
	open  window w_compile at 8,2 with lv_height rows, lv_width columns attribute(border)
end if

call compile_optionals()

let lv_fail_cnt=lv_fail_cnt-1
let lv_ok_cnt=lv_ok_cnt-1

if console_mode() then
	display lv_fail_cnt, " components failed to compile" 
	display lv_ok_cnt, " components compiled successfully" 
	display "(see compile_extras.out for details)"
	display "A make log is stored in makerest.log" 
else
	current window is w_compile
	clear window  w_compile
	display lv_fail_cnt, " components failed to compile" at  2,1
	display lv_ok_cnt, " components compiled successfully" at 3,1
	display "Please see compile_extras.out for details" at 5,1
	display "A make log is stored in makerest.log" at 6,1
end if

finish report compile_status
finish report lines
#display "mv_cnt=",mv_cnt
end main


report lines(lv_str)
define lV_str char(255)
output left margin 0
top margin 0
bottom margin 0
format
on every  row
print lv_str clipped
end report



function add_line(lv_str)
define lv_str char(255)
define a integer

output to report lines (lv_str)

if console_mode() then
	display lv_str clipped
	return
end if

current window is w_compile
if lv_str is null then
	let lv_str = " "
end if
let lv_fileline=lv_fileline+1

if lv_fileline<=lv_height then
	let lv_arr[lv_fileline]=lv_str
else
	for a=1 to (lv_height-1)
		let lv_arr[a]=lv_arr[a+1]
	end for
	let lv_arr[lv_height]=lv_str
end if

set pause mode on

for a=1 to lv_height
	display " " , "" at a,1
	if a>lv_fileline then
		exit for
	end if
	display lv_arr[a] clipped at a,1
end for

set pause mode off


end function


report compile_status(lv_title,lv_ok)
define lv_title char(80) 
define lv_ok integer
format

on every row
	if lv_ok then 
		print "    ", lv_title clipped,"(OK)"
	else
		print "****", lv_title clipped, " FAILED TO COMPILE"
	end if
end report


function show_progress(lv_cnt,lv_tot)
define lv_cnt,lv_tot integer
define lv_str char(255)
define lv_x integer

if console_mode() then
	return
else
	# current window should be w_title already...
	let lv_x=(lv_cnt*lv_width)/lv_tot
	let lv_x=lv_x+1
	if lv_x> lv_width then
		let lv_x=lv_width
	end if

	let lv_str="###############################################################################################################################################################################################################################################################";
	display lv_str[1,lv_x] at 3,1 attribute(reverse,green)
end if

end function
	

function run(lv_title, lv_str,lv_importance)
define lv_str char(512)
define lv_title char(80)
define lv_line char(255)
define lv_importance integer
define a integer


call show_progress(mv_cnt,lc_num_compiles)
let mv_cnt=mv_cnt+1

if console_mode() then
	display "Compiling : ",lv_title  clipped
else
	current window is w_title
	display "Compiling : ",lv_title  at 1,1
end if

let lv_str=aclfgl_expand_env_vars_in_cmdline(lv_str) clipped," 2>&1"
if console_mode() then
	display lv_str
end if
code
{
  A4GL_trim (lv_str);
//printf("%s\n",lv_str);
  p_file = popen (lv_str, "r");
  if (p_file != 0)
    {
      while (1)
	{
	  memset (lv_line, 0, lv_width + 1);
	  if (!fgets (lv_line, lv_width + 1, p_file))
	    break;
	  lv_line[lv_width + 1] = 0;
	  A4GL_trim_nl (lv_line);
		while (1) {
			char *ptr;
			ptr=strchr(lv_line,'\t');
			if (!ptr) break;
			*ptr=' ';
		}
	  A4GL_push_char (lv_line);
	  aclfgl_add_line (1);
	}
      a = pclose (p_file) >> 8;
      sprintf (lv_line, "Exit status : %x", a);
      A4GL_push_char (lv_line);
      aclfgl_add_line (1);
    }
  else
    {
      A4GL_push_char ("Unable to run command");
      aclfgl_add_line (1);
    }
}

endcode

if console_mode() then
	if a=0 then
		display "Compiled  : ",lv_title clipped," OK"
		display " "
	else
		if lv_importance>=3 then
			display "Compiled  : ",lv_title clipped," FAIL"
		else
			display "Compiled  : ",lv_title clipped," FAIL (can probably be ignored)"
		end if
	end if
else
	current window is w_title
	display "Compiled  : ",lv_title at 2,1
	if a=0 then
		display "OK  " at 2,70
	else
		if lv_importance>=3 then
			display "FAIL" at 2,70 attribute(red,reverse)
		else
			display "FAIL" at 2,70
		end if
		
	end if
end if

if a=0 then
	let lv_ok[lv_ok_cnt]=lv_title
	let lv_ok_cnt=lv_ok_cnt+1
	output to report compile_status(lv_title,1)
else
	let lv_fail[lv_fail_cnt]=lv_title
	output to report compile_status(lv_title,0)
	let lv_fail_cnt=lv_fail_cnt+1
end if

if not console_mode() then
	display " ", "" at 1,1
end if

end function





function compile_optionals()

	call run("ESQL/C SQL DRIVER", "$A4GL_MAKE -C lib/libsql/esqlc ",5)
	call run("Resources", "$A4GL_MAKE -C lib/resource",5)
	call run("MYSQL Connector", "$A4GL_MAKE -C lib/libsql/mysql",5)
	call run("Dummy SQL Connector", "$A4GL_MAKE -C lib/libsql/nosql",5)
	call run("IFXODBC Connector", "$A4GL_MAKE -C lib/libsql/odbc ifxodbc",3)
	call run("PGODBC Connector", "$A4GL_MAKE -C lib/libsql/odbc pgodbc",3)
	call run("SQLITE Connector", "$A4GL_MAKE -C lib/libsql/odbc sqlite3",3)
	call run("UNIXODBC Connector", "$A4GL_MAKE -C lib/libsql/odbc unixodbc",3)
	call run("Postgresql Connector", "$A4GL_MAKE -C lib/libsql/postgresql",5)
	call run("FILESCHEMA Connector", "$A4GL_MAKE -C lib/libsql/schema_in_file",5)
	call run("4GL LEXTYPE", "$A4GL_MAKE -C lib/liblex/lex_4gl",1)
	call run("SPL LEXTYPE", "$A4GL_MAKE -C lib/liblex/lex_spl",1)
	call run("Dummy SQLPARSEr", "$A4GL_MAKE -C lib/libsqlparse/none",5)
	call run("AACE Compiler", "$A4GL_MAKE -C compilers/ace",4)
	call run("Form Compiler", "$A4GL_MAKE -C compilers/fcompile",5)
	call run("Help Compiler", "$A4GL_MAKE -C compilers/helpcompile",5)
	call run("Menu Compiler", "$A4GL_MAKE -C compilers/menus",0)
	call run("PCODE compiler", "$A4GL_MAKE -C compilers/pcode",0)
	call run("SQL Translator", "$A4GL_MAKE -C compilers/sql",5)
	call run("MEMCACHED interface", "$A4GL_MAKE -C lib/extra_libs/memcached ",1)
	call run("PCRE interface", "$A4GL_MAKE -C lib/extra_libs/pcre",1)
	call run("POP interface", "$A4GL_MAKE -C lib/extra_libs/pop",1)
	call run("SMTP interface", "$A4GL_MAKE -C lib/extra_libs/smtp",1)
	call run("Channel compatibility interface", "$A4GL_MAKE -C lib/extra_libs/channel",5)
	call run("FILE interface", "$A4GL_MAKE -C lib/extra_libs/file",5)
	call run("string interface", "$A4GL_MAKE -C lib/extra_libs/string",3)
	call run("barcode lookup interface", "$A4GL_MAKE -C lib/extra_libs/barcode",1)
	call run("roman numbers", "$A4GL_MAKE -C lib/extra_libs/roman",1)
	call run("sample errhook", "$A4GL_MAKE -C lib/extra_libs/errhook",1)
	call run("mantis connect", "$A4GL_MAKE -C lib/extra_libs/mantisconnect",1)
	call run("Help files", "$A4GL_MAKE -C help",5)
	call run("Documentation tool data loader", "$A4GL_MAKE -C lib loadmap",5)
	call run("LIBLOGICAL layout engine", "$A4GL_MAKE -C lib/liblogical/layout_engine",3)
	call run("LIBLOGICAL processor", "$A4GL_MAKE -C lib/liblogical/processor",5)
	call run("LIBLOGICAL viewer", "$A4GL_MAKE -C lib/liblogical/report_viewer",3)
	call run("ESQL/C Helper functions", "$A4GL_MAKE -C lib/libesql ",5)
	call run("Extra datatype", "$A4GL_MAKE -C lib/libexdata ",5)
	call run("GENERIC form driver", "$A4GL_MAKE -C lib/libform/form_generic",5)
	call run("XDR Form Driver", "$A4GL_MAKE -C lib/libform/form_xdr",2)
	call run("Dummy form driver", "$A4GL_MAKE -C lib/libform/noform",5)
	call run("PERL generation", "$A4GL_MAKE -C lib/liblex/lex_perl",1)
	call run("LIBLOGICAL CSV layout module", "$A4GL_MAKE -C lib/liblogical/csv/layout",5)
	call run("LIBLOGICAL CSV process module", "$A4GL_MAKE -C lib/liblogical/csv/process",5)
	call run("LIBLOGICAL HTML layout module", "$A4GL_MAKE -C lib/liblogical/html/layout",5)
	call run("LIBLOGICAL HTML process module", "$A4GL_MAKE -C lib/liblogical/html/process",5)
	call run("LIBLOGICAL Layout engine", "$A4GL_MAKE -C lib/liblogical/layout_engine ",3)
	call run("LIBLOGICAL PDF layout module", "$A4GL_MAKE -C lib/liblogical/pdf/layout",3)
	call run("LIBLOGICAL PDF process module", "$A4GL_MAKE -C lib/liblogical/pdf/process",3)
	call run("LIBLOGICAL TXT layout module", "$A4GL_MAKE -C lib/liblogical/txt/layout",5)
	call run("LIBLOGICAL TXT process module", "$A4GL_MAKE -C lib/liblogical/txt/process",5)
	call run("Read/Write message files", "$A4GL_MAKE -C lib/libmsg/msg_native",5)
	call run("GZ Packer", "$A4GL_MAKE -C lib/libpacker/gzpacked",3)
	call run("In-memory Packer", "$A4GL_MAKE -C lib/libpacker/mempacked",5)
	call run("Packed Packer", "$A4GL_MAKE -C lib/libpacker/packed",5)
	call run("Perl Packer", "$A4GL_MAKE -C lib/libpacker/perl",1)
	call run("XDR Packer", "$A4GL_MAKE -C lib/libpacker/xdr",5)
	call run("XML Packer", "$A4GL_MAKE -C lib/libpacker/xml",5)
	call run("PDF Report generation", "$A4GL_MAKE -C lib/libpdf",3)
	call run("DUMMY RPC functions", "$A4GL_MAKE -C lib/librpc/no_rpc",4)
	call run("SUN ONC/RPC functions", "$A4GL_MAKE -C lib/librpc/sun_rpc",1)
	call run("XML RPC functions", "$A4GL_MAKE -C lib/librpc/xml_rpc",1)
	call run("CURSES UI", "$A4GL_MAKE -C lib/libui/ui_curses",5)
	call run("GLADE UI", "$A4GL_MAKE -C lib/libui/ui_glade",1)
	call run("GLADE UI helper library", "$A4GL_MAKE -C lib/libui/ui_glade/glade_lib",1)
	call run("Highlevel UI", "$A4GL_MAKE -C lib/libui/ui_highlevel ",5)
	call run("adbload tool", "$A4GL_MAKE -C tools/adbload2",3)
	call run("adbschema tool", "$A4GL_MAKE -C tools/adbschema",5)
	call run("afinderr tool", "$A4GL_MAKE -C tools/afinderr",5)
	call run("asql tool", "$A4GL_MAKE -C tools/asql",5)
	call run("A4GL IDE tool", "$A4GL_MAKE -C tools/a4gl",5)
	call run("aupscol tool", "$A4GL_MAKE -C tools/aupscol",5)
	call run("configuration tool", "$A4GL_MAKE -C tools/configuration",1)
	call run("convertsql tool", "$A4GL_MAKE -C tools/convertsql",2)
	call run("loadmap tool", "$A4GL_MAKE -C tools/loadmap",1)
	call run("Glade demo IDE", "$A4GL_MAKE -C glade/ide",0)
	call run("Glade demo Sqleditor", "$A4GL_MAKE -C glade/ide/sqleditor",0)
	call run("IDE","$A4GL_MAKE -C tools/ide",1)
	call run("ODBC Test","$A4GL_MAKE -C tools/odbctest",1)
	call run("HTML helper library","$A4GL_MAKE -C tools/html dll",1)
	call run("misql","$A4GL_MAKE -C tools/misql misql.4ae",1)
	call run("ADBLOAD","$A4GL_MAKE -C tools/adbload",1)
	call run("SOLITAIRE","$A4GL_MAKE -C tools/test solitaire.4ae",1)
	call run("Test Applications","$A4GL_MAKE -C tools/test",1)
	call run("showhelp display", "$A4GL_MAKE -C lib/libhelp",1)
	call run("fgllint", "$A4GL_MAKE -C compilers/4glc fgllint",0)
	call run("fglcalltree", "$A4GL_MAKE -C compilers/4glc fglcalltree",0)
	call run("C#", "$A4GL_MAKE -C lib/liblex/lex_cs",0)
	call run("XMLBEST", "$A4GL_MAKE -C lib/libpacker/xml_best",0)
	call run("XML UI", "$A4GL_MAKE -C lib/libui/ui_xml",0)
	call run("HARU PDF", "$A4GL_MAKE -C lib/libpdf haru.dummy",0)
	call run("WRITE LEXTYPE", "$A4GL_MAKE -C lib/liblex/lex_write",0)
	call run("Quick setup guide", "$A4GL_MAKE -C tools/quickguide",0)
	call run("Postgresql static libs", "$A4GL_MAKE -C lib/libsql/postgresql libSQL_pg8l.so libSQL_pg8ls.so",0)
	call run("ASQL_I", "$A4GL_MAKE -C tools/asql asql_i.4ae",0)
	call run("ASQL_P", "$A4GL_MAKE -C tools/asql asql_p.4ae",0)
	call run("Logical reports", "cd lib/liblogical && sh makeit",0)
	call run("ESQL helper Simple","cd lib/libesql && sh make_simple",0)
	call run("Static TUI", "cd lib/libui/ui_curses; sh make_static",0)
	call run("Static TUI (5.7) ", "cd lib/libui/ui_curses; make -f Makefile.static",0)
	call run("SQLMetrics", "cd tools/sqlmetrics; make",0)
	call run("FORMXML Packer", "cd lib/libpacker/formxml; make",0)
	call run("Optimised 4glc", "cd compilers/4glc; make opt",0)


end function


function console_mode()
if fgl_getenv("A4GL_UI")="TUI" then
	return false
else
	return true
end if
end function
