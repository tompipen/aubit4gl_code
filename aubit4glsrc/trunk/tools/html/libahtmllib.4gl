# When running Aubit programs as CGI in web server, use A4GL_UI=CONSOLE

# $Id: libahtmllib.4gl,v 1.8 2007-06-05 18:06:20 fortiz Exp $

########################################################################
#ANSI C libraryes for CGI programing:
#
#own main()!!!!
#http://www.boutell.com/cgic/
#
#C, not free
#http://www.iexp.com/products/cgi-lib/
#
#cpp, free
#
#
#C, free
#http://www.newbreedsoftware.com/cgi-util/
#
#C, free
#http://www.eekim.com/software/cgihtml/
#
#c(?) simple, free
#http://www.csclub.uwaterloo.ca/~yhchan/download/qcgidoc.html
#
#W3C protocol library
#http://www.w3.org/Library/
#
#no main()
#http://www.geocities.com/SiliconValley/Bay/1927/yacgi.html
#
#http://kitsumi.xware.cx/xcgi/
#
#
#http://www.global-owl.de/ecgi/
#
#nice...
#http://catchen.org/gcgi/
########################################################################

###########
globals
###########
	define
		do_debug,
		showpage
			smallint,
        item,
        form_method
            char(20),

	HTTP_POST_VAR,
    HTTP_GET_VAR
		char(1000),

    www record
		GATEWAY_INTERFACE 	char (20),
		SERVER_NAME 		char (60),
		SERVER_SOFTWARE 	char (100),
		SERVER_PROTOCOL 	char (20),
		REQUEST_METHOD 		char (10),
		QUERY_STRING 		char (300),
		DOCUMENT_ROOT 		char (200),
		HTTP_ACCEPT 		char (200),
		HTTP_ACCEPT_CHARSET char (40),
		HTTP_ACCEPT_ENCODING char (20),
		HTTP_ACCEPT_LANGUAGE char (10),
		HTTP_CONNECTION    	char (20),
		HTTP_HOST           char (200),
		HTTP_REFERER        char (600),
		HTTP_USER_AGENT     char (300),
		REMOTE_ADDR         char (20),
		REMOTE_PORT         char (10),
		SCRIPT_FILENAME     char (300),
		SERVER_ADMIN        char (100),
		SERVER_PORT         char (10),
		SERVER_SIGNATURE    char (100),
		PATH_TRANSLATED     char (300),
		SCRIPT_NAME         char (300),
		REQUEST_URI         char (600)
    end record,

    HTTPvar array [100] of record
        vname char(20),
        value char(60)
    end record,

    g_css char (40)

end globals

#==================== HTML Library ==========================


#######################
function html_init(cssfilename)
#######################
define
    cssfilename char (40),
    lv_debug, lv_do_debug varchar(3)

	call html_headers()

	display "<html>"

    let form_method="POST"

	call get_webserver_vars()

	if www.REQUEST_METHOD = "POST"
	then
		call getstdin()
    end if


	if www.REQUEST_METHOD = "POST"
	then
		call html_params(HTTP_POST_VAR)
    else
		call html_params(HTTP_GET_VAR)
    end if

    let lv_do_debug = vread("do_debug") clipped
    if lv_do_debug = "on" then
        let do_debug = true
    end if
    if lv_do_debug = "off" then
        let do_debug = false
    end if

    let lv_debug = vread("debug") clipped
    if lv_debug = "on" then
        let do_debug = true
    end if
    if lv_debug = "off" then
        let do_debug = false
    end if

    if do_debug
    then
		display "HTTP_POST_VAR=[",HTTP_POST_VAR clipped, "]"
		display "<BR>HTTP_GET_VAR=[",HTTP_GET_VAR clipped,"]"
		display "<BR>"
    end if


    if vread("g_css") <> "0" then
        let g_css = vread("g_css")
        let cssfilename = g_css
    end if



    if do_debug
    then
		call vreadall()
    end if

	call html_css(cssfilename)

end function

################################
function html_css(cssfilename)
################################
define
    cssfilename, tmp_cssfilename char (40)

	let tmp_cssfilename = vread("css")
{
	display "xxx",tmp_cssfilename clipped,"xxx"

    if vread("css") <> false
    then
        display "not false"
    end if

    if vread("css") <> "0"
    then
        display "not '0'"
    end if

    if vread("css") <> 0
    then
        display "not 0"
    end if
}

	if tmp_cssfilename  <> '0'
#    if vread("css") <> '0'
    then
#		let tmp_cssfilename = vread("css")
#	    display "xxx",tmp_cssfilename clipped,"xxx"

		let cssfilename = tmp_cssfilename
        let g_css = tmp_cssfilename
    end if

    if cssfilename <> "none" then
		display "  <link rel='stylesheet' type='text/css' href='/",cssfilename clipped,".css'>"
    end if


end function

############################
function html_headers()
############################

#We cannot use DISPLAY for first line, because of bug (?) in Aubit that
#prints newline BEFORE it prints string, creating one empty line after program
#starts, so we heve to use this:
code



//printf("HTTP/1.1 200 OK");

//Pragma: no-cache
printf("Content-type: text/html\n\n");

endcode


    return



	{
	if [ "$REQUEST_METHOD" = "HEAD" ]; then
	  echo HTTP/1.1 200 OK
	  echo Date: `date`
	  echo Server: $SERVER_SOFTWARE
	  echo Connection: close
	  echo Content-type: multipart/x-mixed-replace
	  echo
	elif [ "$REQUEST_METHOD" = "GET" ]; then
	  echo HTTP/1.1 200 OK
	  echo Date: `date`
	  echo Server: $SERVER_SOFTWARE
	  echo Connection: close
	  exec $PATH_TO_WEBCAM $WEBCAM_OPTIONS
	else
	cat <<EOF
	HTTP/1.1 405 Method Not Allowed
	Date: `date`
	Server: $SERVER_SOFTWARE
	Allow: GET, HEAD
	Connection: close
	Content-type: text/html

	<HTML><HEAD>
	<TITLE>405 Method Not Allowed</TITLE>
	</HEAD><BODY>
	<H1>Method Not Allowed</H1>
	The requested method $REQUEST_METHOD is not allowed for the URL $REQUEST_URI.<P>
	</BODY></HTML>
	EOF
	fi


	print "Content-type: text/html\n\n";


	}

	{
	display "HTTP/1.1 200 OK"
	display "Date: Tue Oct 16 12:16:03 NZDT 2001"
	display "Server: ",www.SERVER_SOFTWARE clipped
	display "Connection: close"
	#display "Content-type: multipart/x-mixed-replace"
	}

	#echo Content-type: text/plain

	#HTTP/1.1 405 Method Not Allowed
	#Allow: GET, HEAD


end function


###################################
function html_start_body()
###################################

    #black falout.com scheme:
	#display "<body bgcolor='#000000' text='#FFFFFF' link='#00FFFF' vlink='#0000FF'>"

    #light blue scheme fro Maximise "add user"
	#display "<body text='#000000' bgcolor='#ededff' link='#000000' vlink='#000000' alink='#000000'>"


#  <body onLoad="A4gl_CheckError()">

	display "<body onLoad='A4gl_CheckError()' text='#000000' bgcolor='#ededff' link='#000000' vlink='#000000' alink='#000000'>"

end function

###################################
function html_end_body()
###################################
	display "</body>"
end function


###################################
function html_start_para()
###################################
	display "<p>"
end function

###################################
function html_end_para()
###################################
	display "</p>"
end function

###################################
function html_display_para(mytext)
###################################
#FIXME: why is "text" reserved word?
define mytext char (10000)

	call html_start_para()
    display mytext clipped
    call html_end_para()
end function

###################################
function html_meta()
###################################

	display "<meta http-equiv='Content-Language' content='en-us'>"
	display "<meta http-equiv='Content-Type' content='text/html; charset=windows-1252'>"
	display "<meta name='GENERATOR' content='Aubit 4gl'>"
	display "<meta name='ProgId' content='Aubit.Compiler.Document'>"

end function


###################################
function html_link(URL,target,mytext)
###################################
define
	URL,mytext char (300),
    target char(10)


	display "<a href='",URL clipped,"' target='",target clipped,"'>",mytext clipped,"</a>"


end function



###################################
function html_head(page_title)
###################################
define page_title char (300)

	display "<head>"
	display "    <meta http-equiv='Pragma' content='no-cache'>"

	call html_title(page_title)
    call html_meta()
	display "</head>"

	display "  <script language='JavaScript'>"
	display "  <!--"
	display "  function A4gl_CheckError() {"
#	display '    if ("$(gui.errorbar.object)" != "") {'
	display '    if ("$(gui.errorbar.object)" == "dissssabbbled") {'
	display '      alert ("$(gui.errorbar.object)")'
	display "    }"
	display "  }"
	display "  //-->"
	display "  </script>"


end function

###################################
function html_title(p_string)
###################################
define p_string char(512)

	display "<title>",p_string clipped,"</title>"

end function

###################################
function html_heading(p_string,p_level)
###################################
define p_string char(512)
define p_level integer

	display "<H",p_level using "<<<",">",p_string clipped,
		"</H",p_level using "<<<",">"

end function


###################################
function html_hline()
###################################

	display "<HR>"

end function

###################################
function html_image(URL,W,H)
###################################
define
	URL char (200),
    W,H integer

	display "<img border='0' src='",URL,"' width='",W,"' height='",H,"'>"

end function

###################################
function html_start_center()
###################################
	display "<center>"
end function

###################################
function html_end_center()
###################################
	display "</center>"
end function



###################################
function html_params(allparams)
###################################
define
    cnt,numparams,startpos,endpos,arglength, allparamslength,
    gotit, i, varlen
        smallint,
	ARGUMENT
			ARRAY[50] OF CHAR (60),
    prg_name
        char(20),

	allparams, resto, cutstring
        char (1000)

    #let prg_name = ARG_VAL(0)
    let prg_name = www.script_name


    #let allparams = ARG_VAL(1)
    #let allparams = www.query_string

	#if NUM_ARGS() = 0
	if length (allparams) = 0
    then
		if do_debug then
            display "No args<BR>"
        end if
		return
    end if


    let numparams = 0
    let startpos = 1
    let allparamslength = length(allparams)


    #from arg_val(1): something\&blah\&4444
    #from www.query_string: something&blah&4444
	################################
	FOR cnt = 1 TO length(allparams)
	################################

        if allparams[cnt] = "&"
        then
			let numparams = numparams + 1
			let endpos = cnt - 1
			let ARGUMENT[numparams] = allparams[startpos,endpos]
            let startpos = cnt + 1
        end if
    #######
	end for
    #######


	if startpos < allparamslength
    then
		let resto = allparams[startpos,allparamslength]

        if length (resto) > 0 then

			#last one don't have "&" on end
			let numparams = numparams + 1
			let endpos = length(allparams)
			let ARGUMENT[numparams] = allparams[startpos,endpos]
        end if
    end if

	############################
	#FOR cnt = 1 TO NUM_ARGS()
    FOR cnt = 1 TO numparams
	############################
        if do_debug then
			display "Param ",cnt," = [",ARGUMENT[cnt], "]<BR>"
        end if

#		IF
#			ARGUMENT[cnt] IS NOT NULL
#		THEN
#			LET ARGUMENT[cnt] = UPSHIFT(ARGUMENT[cnt])
#		END IF

        let varlen=length(ARGUMENT[cnt])
        let cutstring = ARGUMENT[cnt]
        let gotit = false
        ##################
        for i=1 to varlen
        ##################

            if cutstring[i] = "="
            then
				let HTTPvar[cnt].vname = cutstring[1,i-1]
				let HTTPvar[cnt].value = cutstring[i+1,varlen]
                let gotit = true
                exit for
            end if
        #######
		end for
        #######

        if not gotit
        then
			let HTTPvar[cnt].vname = ARGUMENT[cnt]
			let HTTPvar[cnt].value = ""
        end if


        let varlen=length(HTTPvar[cnt].value)
        let cutstring = HTTPvar[cnt].value
        ##################
        for i=1 to varlen
        ##################

	   	    #spaces are sent as "+"
            if cutstring[i] = "+"
            then
				#display "xxxx+<BR>"
				#let cutstring[i] = " " <---bug - this is not working
                let cutstring = cutstring[1,i-1]," ",cutstring[i+1,varlen]
            end if

			#Netscape sends "@" as "%40"
			if cutstring[i,i+2] = "%40"
            then
				#display "xxxx@<BR>"
				#let cutstring[i] = "@" <--- bug - not working
                let  cutstring =  cutstring[1,i-1],"@",cutstring[i+3,varlen]
            end if


        #######
		end for
        #######

        #display "eeee",cutstring,"<BR>"
		let HTTPvar[cnt].value = cutstring

	#######
	END FOR
	#######

        let item = vread("item")

end function #params()

################################
function vread(varname)
################################
define cnt smallint, tmpvarname, varname char(60)

    #all variable names in 4gl are case insensitive
    let varname = upshift(varname)

    ####################
	for cnt = 1 to 100
    ####################

        let tmpvarname = upshift(HTTPvar[cnt].vname)

        if tmpvarname = varname then
	        if length (HTTPvar[cnt].value) > 0 then
                return HTTPvar[cnt].value
        	else
                #varibale was defined, but no value was assigned
                return TRUE
			end if
        end if
    
	########
	end for
    ########

    
	#did not find this variable name:
	return false


end function


#####################
function vreadall()
#####################
define cnt smallint

    for cnt = 1 to 100

        if length (HTTPvar[cnt].vname) > 0 then
	    	display HTTPvar[cnt].vname clipped, " = ", HTTPvar[cnt].value clipped, "<BR>"
        else
            exit for
		end if

        if length (HTTPvar[cnt].value) = 0 then #bug in DISPLAY
	    	display "<BR>"
        end if
    end for

end function


##############################
function get_webserver_vars()
##############################
#http://hoohoo.ncsa.uiuc.edu/cgi/overview.html
#http://www.php.net/manual/en/language.variables.predefined.php
#http://httpd.apache.org/docs-2.0/howto/cgi.html

	#$HTTP_POST_VARS['username']


let www.GATEWAY_INTERFACE = FGL_GETENV("GATEWAY_INTERFACE")
#What revision of the CGI specification the server is using; i.e. 'CGI/1.1'.

let www.SERVER_NAME = FGL_GETENV("SERVER_NAME")
#The name of the server host under which the current script is executing.
#If the script is running on a virtual host, this will be the value defined
#for that virtual host.

let www.SERVER_SOFTWARE = FGL_GETENV("SERVER_SOFTWARE")
#Server identification string, given in the headers when responding to requests.

let www.SERVER_PROTOCOL = FGL_GETENV("SERVER_PROTOCOL")
#Name and revision of the information protocol via which the page was
#requested; i.e. 'HTTP/1.0';

let www.REQUEST_METHOD = FGL_GETENV("REQUEST_METHOD")
#Which request method was used to access the page; i.e. 'GET', 'HEAD',
#'POST', 'PUT'.

let www.QUERY_STRING = FGL_GETENV("QUERY_STRING")
let HTTP_GET_VAR = FGL_GETENV("QUERY_STRING")
#The query string, if any, via which the page was accessed.

let www.DOCUMENT_ROOT = FGL_GETENV("DOCUMENT_ROOT")
#The document root directory under which the current script is executing,
#as defined in the server's configuration file.

let www.HTTP_ACCEPT = FGL_GETENV("HTTP_ACCEPT")
#Contents of the Accept: header from the current request, if there is one.

let www.HTTP_ACCEPT_CHARSET = FGL_GETENV("HTTP_ACCEPT_CHARSET")
#Contents of the Accept-Charset: header from the current request, if
#there is one. Example: 'iso-8859-1,*,utf-8'.

let www.HTTP_ACCEPT_ENCODING = FGL_GETENV("HTTP_ACCEPT_ENCODING")
#Contents of the Accept-Encoding: header from the current request, if
#there is one. Example: 'gzip'.

let www.HTTP_ACCEPT_LANGUAGE = FGL_GETENV("HTTP_ACCEPT_LANGUAGE")
#Contents of the Accept-Language: header from the current request, if
#there is one. Example: 'en'.

let www.HTTP_CONNECTION = FGL_GETENV("HTTP_CONNECTION")
#Contents of the Connection: header from the current request, if
#there is one. Example: 'Keep-Alive'.

let www.HTTP_HOST = FGL_GETENV("HTTP_HOST")
#Contents of the Host: header from the current request, if there is one.

let www.HTTP_REFERER = FGL_GETENV("HTTP_REFERER")
#The address of the page (if any) which referred the browser to the
#current page. This is set by the user's browser; not all browsers will set this.

let www.HTTP_USER_AGENT = FGL_GETENV("HTTP_USER_AGENT")
#Contents of the User_Agent: header from the current request, if there
#is one. This is a string denoting the browser software being used to
#view the current page; i.e. Mozilla/4.5 [en] (X11; U; Linux 2.2.9 i586).
#Among other things, you can use this value with get_browser() to tailor
#your page's functionality to the capabilities of the user's browser.

let www.REMOTE_ADDR = FGL_GETENV("REMOTE_ADDR")
#The IP address from which the user is viewing the current page.

let www.REMOTE_PORT = FGL_GETENV("REMOTE_PORT")
#The port being used on the user's machine to communicate with the web
#server.

let www.SCRIPT_FILENAME = FGL_GETENV("SCRIPT_FILENAME")
#The absolute pathname of the currently executing script.

let www.SERVER_ADMIN = FGL_GETENV("SERVER_ADMIN")
#The value given to the SERVER_ADMIN (for Apache) directive in the web
#server configuration file. If the script is running on a virtual host,
#this will be the value defined for that virtual host.

let www.SERVER_PORT = FGL_GETENV("SERVER_PORT")
#The port on the server machine being used by the web server for
#communication. For default setups, this will be '80'; using SSL,
#for instance, will change this to whatever your defined secure HTTP port is.

let www.SERVER_SIGNATURE = FGL_GETENV("SERVER_SIGNATURE")
#String containing the server version and virtual host name which are
#added to server-generated pages, if enabled.

let www.PATH_TRANSLATED = FGL_GETENV("PATH_TRANSLATED")
#Filesystem- (not document root-) based path to the current script,
#after the server has done any virtual-to-real mapping.

let www.SCRIPT_NAME = FGL_GETENV("SCRIPT_NAME")
#Contains the current script's path. This is useful for pages which
#need to point to themselves.

let www.REQUEST_URI = FGL_GETENV("REQUEST_URI")
#The URI which was given in order to access this page; for instance,
#'/index.html'.


end function

##############################
function show_webserver_vars()
##############################

    	display "HTTP_POST_VAR=[",HTTP_POST_VAR clipped, "]"
	display "<BR>HTTP_GET_VAR=[",HTTP_GET_VAR clipped,"]"
	display "<BR>"
	display "<HR>"

	display "All www variables: <br>"
	display "GATEWAY_INTERFACE = ",www.GATEWAY_INTERFACE,"<BR>"
    display "SERVER_NAME = ",www.SERVER_NAME,"<BR>"
    display "SERVER_SOFTWARE = ",www.SERVER_SOFTWARE,"<BR>"
    display "SERVER_PROTOCOL = ",www.SERVER_PROTOCOL,"<BR>"
    display "REQUEST_METHOD = ",www.REQUEST_METHOD,"<BR>"
    display "QUERY_STRING = ",www.QUERY_STRING,"<BR>"
    display "DOCUMENT_ROOT = ",www.DOCUMENT_ROOT,"<BR>"
    display "HTTP_ACCEPT = ",www.HTTP_ACCEPT,"<BR>"
    display "HTTP_ACCEPT_CHARSET = ",www.HTTP_ACCEPT_CHARSET,"<BR>"

	display "xxx<BR>"
	display "HTTP_ACCEPT_ENCODING = ",www.HTTP_ACCEPT_ENCODING,"<BR>"
    display "HTTP_ACCEPT_LANGUAGE = ",www.HTTP_ACCEPT_LANGUAGE,"<BR>"
    display "HTTP_CONNECTION = ",www.HTTP_CONNECTION,"<BR>"
    display "HTTP_HOST = ",www.HTTP_HOST,"<BR>"
	display "xxx<BR>"
	display "HTTP_REFERER = ",www.HTTP_REFERER,"<BR>"
    display "HTTP_USER_AGENT = ",www.HTTP_USER_AGENT,"<BR>"
    display "REMOTE_ADDR = ",www.REMOTE_ADDR,"<BR>"
    display "REMOTE_PORT = ",www.REMOTE_PORT,"<BR>"
    display "SCRIPT_FILENAME = ",www.SCRIPT_FILENAME,"<BR>"
    display "SERVER_ADMIN = ",www.SERVER_ADMIN,"<BR>"
    display "SERVER_PORT = ",www.SERVER_PORT,"<BR>"
    display "SERVER_SIGNATURE = ",www.SERVER_SIGNATURE,"<BR>"
    display "PATH_TRANSLATED = ",www.PATH_TRANSLATED,"<BR>"

	display "xxx<BR>"
	display "SCRIPT_NAME = ",www.SCRIPT_NAME,"<BR>"
    display "REQUEST_URI = ",www.REQUEST_URI,"<BR>"
	display "<HR>"
end function

####################################
function show_webserver_vars_page()
####################################

	call html_start_body()

#	call page_menu()
#page_menu function is supposed to be defined in the ptogram itself - and on Windows this would
#cause undefined error. anyway, library should not depend on the functions defined in ptogram using it



	call show_webserver_vars()

#	call standard_footer()
#same comment sa for page_menu()

	call html_end_body()

end function


######################################################################
# This have a variable number of parameters
# so we'll have to pop them off in C
# NOTE: List is in reverse order - thats the order they will be pulled
# off the stack..
######################################################################
code
aclfgl_html_list(int a) {
	int c;
//	char s[256];
	char s[1000];
	for (c=0;c<a;c++) {
//		memset(s,0,255);
		memset(s,0,999);
//		A4GL_pop_char(s,80);
		A4GL_pop_char(s,1000);
		trim(s);
		printf("<li>%s</li>\n",s,c,a);
	}
return 0;
}
endcode
######################################################################

#####################
function xxxgetstdin()
#####################
define c char (256)

code
{

//    //char c;
//   while( (c = fgetc(stdin)) != EOF ) {
//           //fputc( c, stdout );
//           }
//
//	//return c;


//char *fgets( char *s, int n, FILE *stream );
/* stdin abbreviation */
char *gets( char *c );


//int fputs( char *s, FILE *stream );
/* stdout abbreviation */
//int puts( char *s );




}
endcode

return c

end function


#####################
function getstdin()
#####################
define
	charvar char (1000),
    len smallint

if www.REQUEST_METHOD <> "POST"
then
	initialize HTTP_POST_VAR to null
	return
end if


code
{
	fgets (charvar, sizeof (charvar), stdin);
	trim (charvar);

}
endcode
{
	let len = length (charvar)

	if len > 1
    then
        #strip CR
		let charvar = charvar[1,len-1]
	else
        initialize charvar to null
	end if
}
	let HTTP_POST_VAR = charvar clipped

end function

#############################
function html_redirect(URL)
#############################
define
    URL char (300)

			display '<head>'
            display '<meta http-equiv="refresh" content="0;URL=',URL clipped,'">'
            display '<meta http-equiv="Content-Type" content="text/html; charset=windows-1252">'
            display '<title>End program</title>'
            display '</head>'
            display '<body>'

			call html_end_body()
            display '</html>'

            exit program
end function


#====================================================================
#                       JavaScript functions
#====================================================================


###############################
function JS_windowname()
###############################
	display "<SCRIPT LANGUAGE='JavaScript'>"
	display "	window.name='ThisWindow';"
	display "</SCRIPT>"
end function


###############################
function JS_launchHelpWin()
###############################

	display "<SCRIPT LANGUAGE='JavaScript'>"
	display "function launchHelpWin(URL,hsize,vsize)"
	display "{"
	display "var HelpWin = null;"
	display "if (hsize == null)		{ hsize = 200; }"
	display "if (vsize == null)		{ vsize = 400; }"
	display "var winParams;"
	display "winParams = 'width=' + hsize + ',height=' + vsize + ',left=0,top=0,toolbar=no,menubar=no,location=no,scrollbars=no,resize=no';"
	display "HelpWin = window.open(URL, 'HelpWindow', winParams);"
	display "}"
	display "</SCRIPT>"

end function


###############################
function JS_launchNewWin()
###############################

	display "<SCRIPT LANGUAGE='JavaScript'>"
	display "function launchNewWin(URL,hsize,vsize,theform)"
	display "{	var NewWin = null;	alert('Page will now reload');		if (hsize == null)		{ hsize = 200; }"
	display "	if (vsize == null)		{ vsize = 400; }	 	var winParams;"
	display "	winParams = 'toolbar=yes,menubar=yes,location=yes,scrollbars=yes,resize=yes';"
	display "	   NewWin = open('http://www.cnn.com','ThisWindow','');	}"
	display "</SCRIPT>"
end function

########################
function JS_startcode()
########################

	display "<SCRIPT LANGUAGE='Javascript' TYPE='text/javascript' DEFER='1'>"
	display "<!--"
	display "form_submitted=false"
end function

#########################
function JS_endcode()
#########################
	display "//-->"
	display "</SCRIPT>"
	display "<NOSCRIPT>"
	display "<!-- dummy comment for user agents without Javascript support enabled -->"
	display "</NOSCRIPT>"
end function



###########################
function JS_ValidateEmail()
###########################

	display "function ValidateEmail(theinput)"
	display "{"
	display "	s=theinput.value"
	display "	if(s.search)"
	display "	{"
	display "		return (s.search(new RegExp('^([a-z0-9_]|\-|\\\.)+@(([a-z0-9_]|\-)+\\\.)+[a-z]{2,4}$','gi'))>=0)"
#|______________________________________________________________________________________________^
#| Error at line 213, character 96
#| parse error ()
	display "	}"
	display "	if(s.indexOf)"
	display "	{"
	display "		at_character=s.indexOf('@')"
	display "		if(at_character<=0 || at_character+4>s.length)"
	display "			return false"
	display "	}"
	display "	if(s.length<6)"
	display "		return false"
	display "	else"
	display "		return true"
	display "}"

end function

##########################
function JS_ValidateForm()
##########################

	display "function ValidateForm(theform)"
	display "{ if (window.SkipVerify==true) {return true }"
	display "	if(theform.email.value==''"
	display "	|| ValidateEmail(theform.email)==false)"
	display "	{"
	display "		alert('Valid e-mail address was not specified')"
	display "		theform.elements[1].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if(theform.confirm_email.value==''"
	display "	|| theform.confirm_email.value!=theform.email.value"
	display "	|| ValidateEmail(theform.confirm_email)==false)"
	display "	{"
	display "		alert('E-mail addres confirmation is not the same as e-mail specified')"
	display "		theform.elements[2].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if(theform.country.selectedIndex==-1 || theform.country.options[theform.country.selectedIndex].value=='')"
	display "	{ "
	display "		alert('Valid country name was not specified')"
	display "		theform.elements[3].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if(theform.first_name.value=='')"
	display "	{"
	display "		alert('Valid first name was not specified')"
	display "		theform.elements[4].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if(theform.last_name.value=='')"
	display "	{"
	display "		alert('Valid last name was not specified')"
	display "		theform.elements[5].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if((theform.alias.value.search"
#
#!!!!!!!!!!!!!!!!!!!!!!
#
	display "	&& theform.alias.value.search(new RegExp('^[a-zA-Z0-9\-_]+$','g'))<0)"
#
#!!!!!!!!!!!!!!!!!!!!!!
#
	display "	|| theform.alias.value=='')"
	display "	{"
	display "		alert('You did not specified a login name')"
	display "		theform.elements[6].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	if(theform.elements[9].checked==false && theform.elements[10].checked==false && theform.elements[11].checked==false)"
	display "	{"
	display "		alert('Subscription type was not specified')"
	display "		theform.elements[9].focus()"
	display "		form_submitted=false"
	display "		return false"
	display "	}"
	display "	return true"
	display "}"
	display ""
end function

#################################
function JS_PageLoad()
#################################
	display "function PageLoad()"
	display "{"
	display "		document.adduser.elements[1].focus()"
	display "}"

end function

#=====================================================================
#                       HTML Form fields
#=====================================================================

#################################
function HTMLF_email()
#################################

	display "	<TH ALIGN=right>E-mail address:"
	display "	</TH>"


	display "<TD>"
	display "	<INPUT TYPE='text' NAME='email' MAXLENGTH=100 ONCHANGE='if(value.toLowerCase) value=value.toLowerCase() ;if(value.toLowerCase) value=value.toLowerCase()'>"
	display "</TD>"
	display "<TD>"
	display "	<a href='javascript:launchHelpWin(",'"help/email.html"',",320,350)'>Help</a>"
	display "</TD>"

end function

#################################
function HTMLF_email_confirm()
#################################

	display "	<TH ALIGN=right>Confirm E-mail:"
	display "	</TH>"


	display "<TD>"
	display "	<INPUT TYPE='text' NAME='confirm_email' MAXLENGTH=100 ONCHANGE='if(value.toLowerCase) value=value.toLowerCase() ;if(value.toLowerCase) value=value.toLowerCase()'>"
	display "</TD>"
	display "<TD>"
	display "	<a href='javascript:launchHelpWin(",'"help/email_addr.html"',",320,350)'>Help</a>"
	display "</TD>"
end function




###############################
function HTMLF_form_header()
###############################

#	display "<FORM METHOD='GET' ACTION='/asp_pub/adduser/adduser.x' NAME='adduser' ONSUBMIT='return ValidateForm(this)'>"
	display "<FORM METHOD='",form_method clipped,"' ACTION='simple_html' NAME='adduser' ONSUBMIT='return ValidateForm(this)'>"
end function



###############################
function HTMLF_form_footer()
###############################

	display "</FORM>"

end function

###############################
function HTMLF_tableFrameStart()
###############################

	display "<CENTER>"
	display "	<TABLE BORDER>"
	display "		<TR>"
	display "			<TD>"
	display "				<CENTER>"
	display "					<TABLE BORDER>"
	display "						<TR>"

end function

###############################
function HTMLF_TableFrameEnd()
###############################
	display "						</TR>"
	display "					</TABLE>"
	display "				</CENTER>"
	display "			</TD>"
	display "		</TR>"
	display "	</TABLE>"
	display "</CENTER>"

end function

###################################
function HTMLF_countrylist()
###################################

	display "				<TH ALIGN=right>Country:"
	display "				</TH>"

	display "<TD>"
	display "<SELECT NAME='country'>"
	display "<OPTION VALUE='' SELECTED>Pick one...</OPTION>"
	display "<OPTION VALUE='AL'>Albania</OPTION>"
	display "<OPTION VALUE='DZ'>Algeria</OPTION>"
	display "<OPTION VALUE='AS'>American Samoa</OPTION>"
	display "<OPTION VALUE='AD'>Andorra</OPTION>"
	display "<OPTION VALUE='AI'>Anguilla</OPTION>"
	display "<OPTION VALUE='AQ'>Antartica</OPTION>"
	display "<OPTION VALUE='AG'>Antigua & Barbuda</OPTION>"
	display "<OPTION VALUE='AR'>Argentina</OPTION>"
	display "<OPTION VALUE='AM'>Armenia</OPTION>"
	display "<OPTION VALUE='AW'>Aruba</OPTION>"
	display "<OPTION VALUE='AU'>Australia</OPTION>"
	display "<OPTION VALUE='AT'>Austria</OPTION>"
	display "<OPTION VALUE='AZ'>Azerbaijan</OPTION>"
	display "<OPTION VALUE='BS'>Bahamas</OPTION>"
	display "<OPTION VALUE='BH'>Bahrain</OPTION>"
	display "<OPTION VALUE='BD'>Bangladesh</OPTION>"
	display "<OPTION VALUE='BB'>Barbados</OPTION>"
	display "<OPTION VALUE='BY'>Belarus</OPTION>"
	display "<OPTION VALUE='BE'>Belgium</OPTION>"
	display "<OPTION VALUE='BZ'>Belize</OPTION>"
	display "<OPTION VALUE='BJ'>Benin</OPTION>"
	display "<OPTION VALUE='BM'>Bermuda</OPTION>"
	display "<OPTION VALUE='BT'>Bhutan</OPTION>"
	display "<OPTION VALUE='BO'>Bolivia</OPTION>"
	display "<OPTION VALUE='BW'>Botswana</OPTION>"
	display "<OPTION VALUE='BV'>Bouvet Island</OPTION>"
	display "<OPTION VALUE='BR'>Brazil</OPTION>"
	display "<OPTION VALUE='IO'>British Indian Ocean Terr.</OPTION>"
	display "<OPTION VALUE='BN'>Brunei Darussalam</OPTION>"
	display "<OPTION VALUE='BG'>Bulgaria</OPTION>"
	display "<OPTION VALUE='BF'>Burkina Faso</OPTION>"
	display "<OPTION VALUE='BI'>Burundi</OPTION>"
	display "<OPTION VALUE='KH'>Cambodia</OPTION>"
	display "<OPTION VALUE='CM'>Cameroon</OPTION>"
	display "<OPTION VALUE='CA'>Canada</OPTION>"
	display "<OPTION VALUE='CV'>Cape Verde</OPTION>"
	display "<OPTION VALUE='KY'>Cayman Islands</OPTION>"
	display "<OPTION VALUE='CF'>Central African Republic</OPTION>"
	display "<OPTION VALUE='TD'>Chad</OPTION>"
	display "<OPTION VALUE='CL'>Chile</OPTION>"
	display "<OPTION VALUE='CN'>China</OPTION>"
	display "<OPTION VALUE='CX'>Christmas Island</OPTION>"
	display "<OPTION VALUE='CC'>Cocos (Keeling) Isl</OPTION>"
	display "<OPTION VALUE='CO'>Colombia</OPTION>"
	display "<OPTION VALUE='KM'>Comoros</OPTION>"
	display "<OPTION VALUE='CG'>Congo</OPTION>"
	display "<OPTION VALUE='CK'>Cook Isl</OPTION>"
	display "<OPTION VALUE='CR'>Costa Rica</OPTION>"
	display "<OPTION VALUE='CI'>Cote D'Ivoire</OPTION>"
	display "<OPTION VALUE='HR'>Croatia</OPTION>"
	display "<OPTION VALUE='CY'>Cyprus</OPTION>"
	display "<OPTION VALUE='CZ'>Czech Republic</OPTION>"
	display "<OPTION VALUE='DK'>Denmark</OPTION>"
	display "<OPTION VALUE='DJ'>Djibouti</OPTION>"
	display "<OPTION VALUE='DM'>Dominica</OPTION>"
	display "<OPTION VALUE='DO'>Dominican Republic</OPTION>"
	display "<OPTION VALUE='TP'>East Timor</OPTION>"
	display "<OPTION VALUE='EC'>Ecuador</OPTION>"
	display "<OPTION VALUE='EG'>Egypt</OPTION>"
	display "<OPTION VALUE='SV'>El Salvador</OPTION>"
	display "<OPTION VALUE='GQ'>Equatorial Guinea</OPTION>"
	display "<OPTION VALUE='EE'>Estonia</OPTION>"
	display "<OPTION VALUE='ET'>Ethiopia</OPTION>"
	display "<OPTION VALUE='FO'>Faroe Islands</OPTION>"
	display "<OPTION VALUE='FK'>Falkland Isl. (Malvinas)</OPTION>"
	display "<OPTION VALUE='FJ'>Fiji</OPTION>"
	display "<OPTION VALUE='FI'>Finland</OPTION>"
	display "<OPTION VALUE='FR'>France</OPTION>"
	display "<OPTION VALUE='GF'>French Guiana</OPTION>"
	display "<OPTION VALUE='PF'>French Polynesia</OPTION>"
	display "<OPTION VALUE='TF'>French Southern Terr.</OPTION>"
	display "<OPTION VALUE='GA'>Gabon</OPTION>"
	display "<OPTION VALUE='GM'>Gambia</OPTION>"
	display "<OPTION VALUE='GE'>Georgia</OPTION>"
	display "<OPTION VALUE='DE'>Germany</OPTION>"
	display "<OPTION VALUE='GH'>Ghana</OPTION>"
	display "<OPTION VALUE='GI'>Gibraltar</OPTION>"
	display "<OPTION VALUE='GR'>Greece</OPTION>"
	display "<OPTION VALUE='GL'>Greenland</OPTION>"
	display "<OPTION VALUE='GD'>Grenada</OPTION>"
	display "<OPTION VALUE='GP'>Guadeloupe</OPTION>"
	display "<OPTION VALUE='GU'>Guam</OPTION>"
	display "<OPTION VALUE='GT'>Guatemala</OPTION>"
	display "<OPTION VALUE='GG'>Guernsey, C.I.</OPTION>"
	display "<OPTION VALUE='GN'>Guinea</OPTION>"
	display "<OPTION VALUE='GW'>Guinea-Bissau</OPTION>"
	display "<OPTION VALUE='GY'>Guyana</OPTION>"
	display "<OPTION VALUE='HT'>Haiti</OPTION>"
	display "<OPTION VALUE='HM'>Heard and McDonald Isl</OPTION>"
	display "<OPTION VALUE='HN'>Honduras</OPTION>"
	display "<OPTION VALUE='HK'>Hong Kong</OPTION>"
	display "<OPTION VALUE='HU'>Hungary</OPTION>"
	display "<OPTION VALUE='IS'>Iceland</OPTION>"
	display "<OPTION VALUE='IN'>India</OPTION>"
	display "<OPTION VALUE='ID'>Indonesia</OPTION>"
	display "<OPTION VALUE='IE'>Ireland</OPTION>"
	display "<OPTION VALUE='IM'>Isle of Man</OPTION>"
	display "<OPTION VALUE='IL'>Israel</OPTION>"
	display "<OPTION VALUE='IT'>Italy</OPTION>"
	display "<OPTION VALUE='JM'>Jamaica</OPTION>"
	display "<OPTION VALUE='JP'>Japan</OPTION>"
	display "<OPTION VALUE='JE'>Jersey, C.I.</OPTION>"
	display "<OPTION VALUE='JO'>Jordan</OPTION>"
	display "<OPTION VALUE='KZ'>Kazakhstan</OPTION>"
	display "<OPTION VALUE='KE'>Kenya</OPTION>"
	display "<OPTION VALUE='KI'>Kiribati</OPTION>"
	display "<OPTION VALUE='KR'>Korea, Republic of</OPTION>"
	display "<OPTION VALUE='KW'>Kuwait</OPTION>"
	display "<OPTION VALUE='KG'>Kyrgyzstan</OPTION>"
	display "<OPTION VALUE='LA'>Laos</OPTION>"
	display "<OPTION VALUE='LV'>Latvia</OPTION>"
	display "<OPTION VALUE='LB'>Lebanon</OPTION>"
	display "<OPTION VALUE='LS'>Lesotho</OPTION>"
	display "<OPTION VALUE='LR'>Liberia</OPTION>"
	display "<OPTION VALUE='LI'>Liechtenstein</OPTION>"
	display "<OPTION VALUE='LT'>Lithuania</OPTION>"
	display "<OPTION VALUE='LU'>Luxemborg</OPTION>"
	display "<OPTION VALUE='MO'>Macau</OPTION>"
	display "<OPTION VALUE='MG'>Madagascar</OPTION>"
	display "<OPTION VALUE='MW'>Malawi</OPTION>"
	display "<OPTION VALUE='MY'>Malaysia</OPTION>"
	display "<OPTION VALUE='MV'>Maldives</OPTION>"
	display "<OPTION VALUE='ML'>Mali</OPTION>"
	display "<OPTION VALUE='MT'>Malta</OPTION>"
	display "<OPTION VALUE='MH'>Marshall Isl</OPTION>"
	display "<OPTION VALUE='MQ'>Martinique</OPTION>"
	display "<OPTION VALUE='MR'>Mauritania</OPTION>"
	display "<OPTION VALUE='MU'>Mauritius</OPTION>"
	display "<OPTION VALUE='MX'>Mexico</OPTION>"
	display "<OPTION VALUE='FM'>Micronesia</OPTION>"
	display "<OPTION VALUE='MD'>Moldova, Republic of</OPTION>"
	display "<OPTION VALUE='MC'>Monaco</OPTION>"
	display "<OPTION VALUE='MN'>Mongolia</OPTION>"
	display "<OPTION VALUE='MS'>Montserrat</OPTION>"
	display "<OPTION VALUE='MA'>Morocco</OPTION>"
	display "<OPTION VALUE='MZ'>Mozambique</OPTION>"
	display "<OPTION VALUE='MM'>Myanmar</OPTION>"
	display "<OPTION VALUE='NA'>Namibia</OPTION>"
	display "<OPTION VALUE='NR'>Nauru</OPTION>"
	display "<OPTION VALUE='NP'>Nepal</OPTION>"
	display "<OPTION VALUE='AN'>Netherland Antilles</OPTION>"
	display "<OPTION VALUE='NL'>Netherlands</OPTION>"
	display "<OPTION VALUE='NC'>New Caledonia</OPTION>"
	display "<OPTION VALUE='NZ'>New Zealand</OPTION>"
	display "<OPTION VALUE='NI'>Nicaragua</OPTION>"
	display "<OPTION VALUE='NE'>Niger</OPTION>"
	display "<OPTION VALUE='NG'>Nigeria</OPTION>"
	display "<OPTION VALUE='NU'>Niue</OPTION>"
	display "<OPTION VALUE='NF'>Norfolk Isl</OPTION>"
	display "<OPTION VALUE='MP'>Northern Mariana Isl</OPTION>"
	display "<OPTION VALUE='NO'>Norway</OPTION>"
	display "<OPTION VALUE='OM'>Oman</OPTION>"
	display "<OPTION VALUE='PK'>Pakistan</OPTION>"
	display "<OPTION VALUE='PW'>Palau</OPTION>"
	display "<OPTION VALUE='PA'>Panama</OPTION>"
	display "<OPTION VALUE='PZ'>Panama Canal Zone</OPTION>"
	display "<OPTION VALUE='PG'>Papua New Guinea</OPTION>"
	display "<OPTION VALUE='PY'>Paraguay</OPTION>"
	display "<OPTION VALUE='PE'>Peru</OPTION>"
	display "<OPTION VALUE='PH'>Philippines</OPTION>"
	display "<OPTION VALUE='PN'>Pitcairn</OPTION>"
	display "<OPTION VALUE='PL'>Poland</OPTION>"
	display "<OPTION VALUE='PT'>Portugal</OPTION>"
	display "<OPTION VALUE='PR'>Puerto Rico</OPTION>"
	display "<OPTION VALUE='QA'>Qatar</OPTION>"
	display "<OPTION VALUE='RE'>Reunion</OPTION>"
	display "<OPTION VALUE='RO'>Romania</OPTION>"
	display "<OPTION VALUE='RU'>Russian Federation</OPTION>"
	display "<OPTION VALUE='RW'>Rwanda</OPTION>"
	display "<OPTION VALUE='KN'>Saint Kitts & Nevis</OPTION>"
	display "<OPTION VALUE='LC'>Saint Lucia</OPTION>"
	display "<OPTION VALUE='WS'>Samoa</OPTION>"
	display "<OPTION VALUE='SM'>San Marino</OPTION>"
	display "<OPTION VALUE='ST'>Sao Tome & Principe</OPTION>"
	display "<OPTION VALUE='SA'>Saudi Arabia</OPTION>"
	display "<OPTION VALUE='SN'>Senegal</OPTION>"
	display "<OPTION VALUE='SC'>Seychelles</OPTION>"
	display "<OPTION VALUE='SL'>Sierra Leone</OPTION>"
	display "<OPTION VALUE='SG'>Singapore</OPTION>"
	display "<OPTION VALUE='SK'>Slovakia</OPTION>"
	display "<OPTION VALUE='SI'>Slovenia</OPTION>"
	display "<OPTION VALUE='SB'>Solomon Islands</OPTION>"
	display "<OPTION VALUE='SO'>Somalia</OPTION>"
	display "<OPTION VALUE='ZA'>South Africa</OPTION>"
	display "<OPTION VALUE='ES'>Spain</OPTION>"
	display "<OPTION VALUE='LK'>Sri Lanka</OPTION>"
	display "<OPTION VALUE='SH'>St. Helena</OPTION>"
	display "<OPTION VALUE='PM'>St. Pierre and Miquelon</OPTION>"
	display "<OPTION VALUE='VC'>St. Vincent & Grenadines</OPTION>"
	display "<OPTION VALUE='SR'>Suriname</OPTION>"
	display "<OPTION VALUE='SJ'>Svalbard & Jan Mayen Isl</OPTION>"
	display "<OPTION VALUE='SZ'>Swaziland</OPTION>"
	display "<OPTION VALUE='SE'>Sweden</OPTION>"
	display "<OPTION VALUE='CH'>Switzerland</OPTION>"
	display "<OPTION VALUE='TW'>Taiwan</OPTION>"
	display "<OPTION VALUE='TJ'>Tajikistan</OPTION>"
	display "<OPTION VALUE='TZ'>Tanzania, United Republic</OPTION>"
	display "<OPTION VALUE='TH'>Thailand</OPTION>"
	display "<OPTION VALUE='TG'>Togo</OPTION>"
	display "<OPTION VALUE='TK'>Tokelau</OPTION>"
	display "<OPTION VALUE='TO'>Tonga</OPTION>"
	display "<OPTION VALUE='TT'>Trinidad & Tobago</OPTION>"
	display "<OPTION VALUE='TN'>Tunisia</OPTION>"
	display "<OPTION VALUE='TR'>Turkey</OPTION>"
	display "<OPTION VALUE='TM'>Turkmenistan</OPTION>"
	display "<OPTION VALUE='TC'>Turks and Caicos Isl</OPTION>"
	display "<OPTION VALUE='TV'>Tuvalu</OPTION>"
	display "<OPTION VALUE='AE'>U.A.E.</OPTION>"
	display "<OPTION VALUE='UM'>U.S.Minor Outlying Isl</OPTION>"
	display "<OPTION VALUE='UG'>Uganda</OPTION>"
	display "<OPTION VALUE='UA'>Ukraine</OPTION>"
	display "<OPTION VALUE='GB'>United Kingdom</OPTION>"
	display "<OPTION VALUE='US'>United States</OPTION>"
	display "<OPTION VALUE='UY'>Uruguay</OPTION>"
	display "<OPTION VALUE='UZ'>Uzbekistan</OPTION>"
	display "<OPTION VALUE='VU'>Vanuatu</OPTION>"
	display "<OPTION VALUE='VA'>Vatican City State</OPTION>"
	display "<OPTION VALUE='VE'>Venezuela</OPTION>"
	display "<OPTION VALUE='VN'>Viet Nam</OPTION>"
	display "<OPTION VALUE='VG'>Virgin Isl (British)</OPTION>"
	display "<OPTION VALUE='VI'>Virgin Isl, (U.S.)</OPTION>"
	display "<OPTION VALUE='WF'>Wallis & Futuna Islands</OPTION>"
	display "<OPTION VALUE='EH'>Western Sahara</OPTION>"
	display "<OPTION VALUE='YE'>Yemen, Republic of</OPTION>"
	display "<OPTION VALUE='ZR'>Zaire</OPTION>"
	display "<OPTION VALUE='ZM'>Zambia</OPTION>"
	display "<OPTION VALUE='ZW'>Zimbabwe</OPTION>"
	display "</SELECT>"
	display "</TD>"

	display "<TD>"
	display "	<a href='javascript:launchHelpWin(",'"help/country.html"',",320,350)'>Help</a>"
	display "</TD>"



end function

#################################
function HTMLF_firstName()
#################################

	display "	<TH ALIGN=right>First name:"
	display "	</TH>"
	display "	<TD>"
	display "		<INPUT TYPE='text' NAME='first_name' MAXLENGTH=60>"
	display "	</TD>"
	display "	<TD>"
	display "		<a href='javascript:launchHelpWin(",'"help/first_name.html"',",320,350)'>Help</a>"
	display "	</TD>"

end function

#################################
function HTMLF_lastname()
#################################

	display "	<TH ALIGN=right>Last name:"
	display "	</TH>"
	display "	<TD>"
	display "		<INPUT TYPE='text' NAME='last_name' MAXLENGTH=60>"
	display "	</TD>"
	display "	<TD>"
	display "		<a href='javascript:launchHelpWin(",'"help/last_name.html"',",320,350)'>Help</a>"
	display "	</TD>"

end function

#################################
function HTMLF_loginname()
#################################

	display "	<TH ALIGN=right>Access name (login):"
	display "	</TH>"
	display "	<TD>"
	display "		<INPUT TYPE='text' NAME='alias' MAXLENGTH=8 ONCHANGE='if(value.toLowerCase) value=value.toLowerCase() ;'>"
	display "	</TD>"
	display "	<TD>"
	display "		<a href='javascript:launchHelpWin(",'"help/login_name.html"',",320,350)'>Help</a>"
	display "	</TD>"

end function

#################################
function HTMLF_checkASPnews()
#################################

	display "	<TD ALIGN=right>"
	display "		<INPUT TYPE='checkbox' NAME='ASPnews_notification' CHECKED>"
	display "	</TD>"
	display "	<TD VALIGN=top>Receive ASP system newsletter"
	display "	</TD>"
	display "	<TD>"
	display "		<a href='javascript:launchHelpWin(",'"help/aspNews.html"',",320,350)'>Help</a>"
	display "	</TD>"
end function

#################################
function HTMLF_checkSiteNews()
#################################

	display "	<TD ALIGN=right>"
	display "		<INPUT TYPE='checkbox' NAME='SiteNews_notification'>"
	display "	</TD>"
	display "	<TD VALIGN=top>Receive site newsletter"
	display "	</TD>"
	display "	<TD>"
	display "		<a href='javascript:launchHelpWin(",'"help/receiveNews.html"',",320,350)'>Help</a>"
	display "	</TD>"

end function

#################################
function HTMLF_radioItems()
#################################


	display "<TR>"
	display "	<TD ALIGN=right>"
	display "		<INPUT TYPE='radio' NAME='subscription_type' VALUE='administrator' Id='administrator_subscription'>"
	display "	</TD>"
	display "	<TD VALIGN=top>Administrator - create new database"
	display "	</TD>"
	display "</TR>"


	display "<TR>"
	display "	<TD ALIGN=right>"
	display "		<INPUT TYPE='radio' NAME='subscription_type' VALUE='user' Id='user_subscription'>"
	display "	</TD>"
	display "	<TD VALIGN=top>User - join your company database"
	display "	</TD>"
	display "</TR>"


	display "<TR>"
	display "	<TD ALIGN=right>"
	display "		<INPUT TYPE='radio' NAME='subscription_type' VALUE='guest' Id='guest_subscription'>"
	display "	</TD>"
	display "	<TD VALIGN=top>Guest - join public test database"
	display "	</TD>"
	display "</TR>"

end function

#################################
Function HTMLF_TitleLine()
#################################

	display "<TH COLSPAN=2>Subscription type:"
#	display "			</TD>"
	display "</TH>"

	display "<TD>"
	display "	<a href='javascript:launchHelpWin(",'"help/subsType.html"',",320,350)'>Help</a>"
	display "</TD>"

end function



#################################
function HTMLF_SubmitButton()
#################################
define
	s1,s2,s3,s4,s5,s6,s7,s8,s9 char (200)

#4glc dums core on this one:
#	display "<INPUT TYPE='submit' NAME='doit' VALUE='Submit subscription' ONCLICK='if(this.disabled || typeof(this.disabled)=='boolean') this.disabled=true ; form_submitted_test=form_submitted ; form_submitted=true ; form_submitted=(!form_submitted_test || confirm('Are you sure you want to submit this form again?')) ; if(this.disabled || typeof(this.disabled)=='boolean') this.disabled=false ; sub_form='' ; return true'></TD>"
#------------------------------------------------------------
#must be on one line?


	display "<TD COLSPAN=3 ALIGN=center>"


	let s1 = "<INPUT TYPE='submit' NAME='item' VALUE='Submit subscription' ONCLICK="


	let s2 = "	'if(this.disabled || typeof(this.disabled)==",'"boolean"',") this.disabled=true ;"
	let s3 = " 	form_submitted_test=form_submitted ;"
	let s4 = "	form_submitted=true ;"
	let s5 = " 	form_submitted=(!form_submitted_test || confirm(",'"Are you sure you want to submit this form again?"',")) ;"
	let s6 = " 	if(this.disabled || typeof(this.disabled)==",'"boolean"',") this.disabled=false ; "
	let s7 = " 	sub_form=",'""'," ;"
	let s8 = " 	return true'"


	let s9 = ">"


	display s1 clipped, s2 clipped, s3 clipped, s4 clipped, s5 clipped, s6 clipped, s7 clipped, s8 clipped, s9 clipped

	display "</TD>"


end function

function HTMLF_transferValue()

	display "<INPUT TYPE='hidden' NAME='frame' VALUE=''>"

end function



#--------------------------- EOF --------------------------------
