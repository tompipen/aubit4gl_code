########################################################################
#
# This is Aubit 4gl demo for CGI/HTML functionality
#
# $Id: html_report.4gl,v 1.1 2007-06-07 20:34:15 fortiz Exp $
#
########################################################################

database test1 

globals "ahtmllib.4gl"

###################################
main
###################################

    call html_init()
	call select_page()
end main


###################################
function select_page()
###################################
define dummy smallint
	case upshift(item)
		when "REPORT"
			call process_report()
		when "DEBUG"
            call html_headers("text/html")
            display "<html>"
			call html_head("Debug")
			call show_webserver_vars_page()
            display "</html>"
        when "EXIT"
            call html_redirect("http://aubit4gl.sourceforge.net")
		otherwise #"INTRO"
            call html_headers("text/html")
            display "<html>"
			call html_head("Intro")
			call show_intropage()
            display "</html>"
    end case
end function

############################
function page_menu()
############################
define
    tmp_char char(40)

	call html_start_center()

	display "<table border='0' width='100%' bgcolor='#3366FF'>"
	display "	<tr>"
	display "		<td width='100%'>"	#&nbsp;"
	display '			<form method="',form_method clipped,'" action="html_report">'

	display "				<label for='fp1'>Menu: </label>"


	display "				<input value='Intro' title='Show intro screen' 	type='Submit' name='item' id='fp1'>"
    display "               <select name='type'>"
    display "                  <option value='def' selected>plain</option>"
    display "                  <option value='txt'>txt</option>"
    display "                  <option value='pdf'>pdf</option>"
    display "                  <option value='csv'>csv</option>"
    display "                  <option value='html'>html</option>"
    display "               </select>"
	display "				<input value='Report' title='Execute report'	type='Submit' name='item'>"
	display "				<input value='Debug' title='Show debug screen'	type='Submit' name='item'>"
	display "				<input value='Exit'	title='Exit this demo'		type='Submit' name='item'>"

	display "			</form>"
	display "		</td>"
	display "	</tr>"
	display "</table>"

	call html_end_center()

end function

###################################
function show_intropage()
###################################
define s1, s2, s3, s4, s5
    char (300)

	call html_start_body()
	call page_menu()
	call html_heading("Overview",1)
    call html_display_para("Another demonstration of 4gl program compiled with Aubit 4gl compiler running as CGI program.")

	let s1 = "This generate a report in several formats using the facility 'logical reports'"
	let s2 = "Chose a type of report and the click on 'report' buttom"
	let s3 = "Option 'plain' is the normal 'START REPORT ... TO SCREEN"
	let s4 = "All other options use 'START REPORT ... TO CONVERTIBLE, and then convert with 'FINISH REPORT .. CONVERTING TO ... AS ..'."

	call html_list(s4,s3,s2,s1)
    call html_display_para("Enjoy!")

	call standard_footer()
	call html_end_body()
end function

###############################
function process_report()
###############################
define w record
        tabid like systables.tabid,
        tabname like systables.tabname
    end record,
    lv_type varchar(4),
    lv_file char(30)

    let lv_type = upshift(vread("type")) clipped

    declare c_tab cursor for 
         select tabid, tabname from systables

    if lv_type = "DEF" then
        start report repo1 
    else
        start report repo1 to convertible
        let lv_file = "repo"
        let lv_file = cgi_mktemp(lv_file)
    end if
    foreach c_tab into w.*
        output to report repo1(w.*, lv_type, lv_file)
    end foreach
    case lv_type 
        when "TXT"
            call html_headers("text/plain")
            finish report repo1 converting to lv_file as "TXT"
        when "HTML"
            call html_headers("text/html")
            finish report repo1 converting to lv_file as "HTML"
        when "PDF"
            call html_headers("application/pdf")
            finish report repo1 converting to lv_file as "PDF"
        when "CSV"
            call html_headers("text/plain")
            finish report repo1 converting to lv_file as "CSV"
        otherwise
            call html_headers("text/plain")
            finish report repo1 
    end case
    if lv_type <> "DEF" THEN
        CALL cgi_dumpfile(lv_file)
        CALL cgi_unlink(lv_file)
    end if
end function

function cgi_mktemp(p_file)
define p_file char(30),
       a_file varchar(50)

let a_file = "/tmp/", p_file clipped, "XXXXXX"
code
mkstemp(a_file);
endcode
return a_file
end function

function cgi_dumpfile(p_file)
define p_file, a_file varchar(50)

let a_file = p_file clipped
code
int fp;
int c;
fp = fopen(a_file,"r");
if (fp != 0) {
    while ((c = fgetc(fp)) != EOF) { 
        putchar(c);
    }
    fclose(fp);
}
endcode
end function

function cgi_unlink(p_file)
define p_file char(30),
       a_file varchar(30)

let a_file = p_file clipped
code
unlink(a_file);
endcode
end function


##############################
report repo1(r, lv_type, lv_file)
##############################
define r record
        tabid like systables.tabid,
        tabname like systables.tabname
    end record,
    lv_type varchar(4),
    lv_file char(30)

format
    page header
        print "Systen catalog. List of tables"
        print lv_type, " ", lv_file
        print
        print column 10, "id", 
              column 20, "Name"

    on every row
        print column 10, r.tabid using "####", 
              column 20, r.tabname

    page trailer
        skip 1 line
        print column 40, "-", pageno using "<<<", "-"
end report

##############################
function standard_footer()
##############################
	display "      <table width='100%'>"
	display "        <tr>"
	display "			<td>"
	display "				<center>"
	display "					<span class='fjs-none'>"
	call html_link("http://aubit4gl.sourceforge.net","_blank","Aubit home page")
	display "					</span>"
	display "				</center>"
	display "			</td>"
	display "		 </tr>"
	display "      </table>"

end function

#############################
function maximise_logo()
#############################

	call html_start_center()
    call html_image("http://aubit4gl.sourceforge.net/images/AubitLogoTPLight.gif",186,100)
	call html_end_center()

end function
#-------------------------------- EOF ---------------------------
