########################################################################
#
#This is Aubit 4gl demo for CGI/HTML functionality
#
# $Id: simple_html.4gl,v 1.1 2001-11-19 06:28:19 afalout Exp $
#
########################################################################

globals "libahtmllib.4gl"

###################################
main
###################################

	let do_debug = false
#	let do_debug = true

    call html_init()
	call select_page()

end main


###################################
function select_page()
###################################
define dummy smallint

	case upshift(item)

		when "FORM"
			call html_head("Form Test")
			call show_formpage()

		when "SUBMIT SUBSCRIPTION"
			call html_head("Form Results")
			call process_form()

		when "DEBUG"
			call html_head("Debug")
			call show_webserver_vars_page()

        when "EXIT"
            call html_redirect("http://aubit4gl.sourceforge.net")

		otherwise #"INTRO"
			call html_head("Intro")
			call show_intropage()
    end case

	display "</html>"

end function


######################
function page_menu()
######################

	call html_start_center()

	display "<table border='0' width='100%' bgcolor='#3366FF'>"
	display "	<tr>"
	display "		<td width='100%'>"	#&nbsp;"
	display '			<form method="',form_method clipped,'" action="simple_html">'
	display "				<label for='fp1'>Menu: </label>"
	display "				<input type='Submit' value='Intro' name='item' id='fp1'>"
	display "				<input type='Submit' value='Form' name='item'>"
	display "				<input type='Submit' value='Debug' name='item'>"
	display "				<input type='Submit' value='Exit' name='item'>"
	display "			</form>"
	display "		</td>"
	display "	</tr>"
	display "</table>"

	call html_end_center()
#	call html_hline()

end function


function ccs_demo()

	display "<html>
	display "  <link rel="stylesheet" type="text/css" href="css2.css">
	display "  <head><title>CSS Example</title></head>
	display "  <body>
	display "    <form action="fglcl.exe?libebizdemo" method="post">
	display "      <input type="hidden" name="taskId" value="libebizdemo.73078023.1"><br>
	display "      <input name="m1" tabindex=1 title="Change the infofield's class to fjs-none" type=submit value="None">
	display "      <input name="m2" tabindex=2 title="Change the infofield's class to fjs-red"  type=submit value="Red">
	display "      <input name="m3" tabindex=3 title="Change the infofield's class to fjs-blue" type=submit value="Blue">
	display "      <input name="m4" tabindex=4 title="Remove the infofield's class attribute"   type=submit value="Remove">
	display "      <input name="m5" tabindex=5 type=submit value="Exit"><br>
	display "      <font color="#FF0000"></font><font color="#00FF00"></font><br>
	display "      <table width='100%'>
	display "        <tr><td><center><span class="fjs-none">Hello, world !</span></center></td></tr>
	display "      </table>
	display "    </form>
	display "  </body>
	display "</html>

end function


###################################
function show_intropage()
###################################
define s1, s2, s3, s4, s5
    char (300)


	call html_start_body()
	call page_menu()
	call html_heading("Overview",1)
    call html_display_para("This is demonstration of 4gl program compiled with Aubit 4gl compiler running as CGI program.")
#	call html_list("This is output of 4gl program compiled with Item3","Item2","Item1")

	let s1 = "This is output of 4gl program compiled with Aubit compiler, running as CGI under Apache web server"
	let s2 = "You can input data in the form, watch client-side validation in action, and see results"
	let s3 = "This program will not perform any actions, and data you enter will not be recorded"
    let s4 = "All Aubit 4GL functionality is available: ODBC database connection, PDF generation, RPC, IM, etc..."

#if i call this, program will core dump on return from THIS function (show_intropage)
#	call html_list(s4,s3,s2,s1)
    call html_display_para("Click on 'Form' button to start...")

	call standard_footer()
	call html_end_body()


end function

###############################
function show_formpage()
###############################
define page_title char (300)

    call JS_windowname()
	call JS_launchHelpWin()
	call JS_launchNewWin()
	call JS_startcode()
	call JS_ValidateEmail()
	call JS_ValidateForm()
	call JS_PageLoad()
	call JS_endcode()

	call html_start_body()
	call page_menu()
	call maximise_logo()

	call HTMLF_form_header()
    call HTMLF_transferValue()
    call HTMLF_tableFrameStart()

	display "						<TR>"
	call HTMLF_email()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
	call HTMLF_email_confirm()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
    call HTMLF_countrylist()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
	call HTMLF_firstName()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
    call HTMLF_lastname()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
    call HTMLF_loginname()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
    call HTMLF_checkASPnews()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
	call HTMLF_checkSiteNews()
#	display "			</TD>"
	display "						</TR>"
	display "						<TR>"
    call HTMLF_TitleLine()
	display "						</TR>"
	call HTMLF_radioItems()
	display "						<TR>"
    call HTMLF_SubmitButton()
	display "						</TR>"
    call HTMLF_TableFrameEnd()
	call HTMLF_form_footer()
	call standard_footer()
	call html_end_body()

end function


###############################
function process_form()
###############################

	call html_start_body()
	call page_menu()
	call html_heading("Form entry results",1)
    display "You entered:<p>"
	display " Email address :", vread("email"), " (confirmed)<BR>"
    display " Country :", vread("country"), "<BR>"
    display " Your name is :", vread("first_name"), vread("last_name"), "<BR>"
    display " Login name to be created :", vread("alias"), "<BR>"

    if vread("ASPnews_notification") = "on" then
	    display " You want to receive ASP newsletter<BR>"
    else
	    display " You don't want to receive ASP newsletter<BR>"
    end if

    display " Subscription type will be :", vread("subscription_type"), "<BR>"


    display "</P> Thank you for tesitng Aubit 4gl HTML functionality.<BR>"
	call standard_footer()
	call html_end_body()


end function

##############################
function standard_footer()
##############################
	call html_hline()
	call html_start_center()
    call html_link("http://aubit4gl.sourceforge.net","_blank","Aubit home page")
	call html_end_center()

end function

#############################
function maximise_logo()
#############################

#	call html_image("/images/maximiseorb.gif",54,51)
#    call html_image("/images/maximiselogo.gif",186,50)

	call html_start_center()
#    call html_image("http://aubit4gl.sourceforge.net/images/AubitLogoOnWhite.jpg",186,100)
    call html_image("http://aubit4gl.sourceforge.net/images/AubitLogoTPLight.gif",186,100)
	call html_end_center()

end function


#-------------------------------- EOF ---------------------------