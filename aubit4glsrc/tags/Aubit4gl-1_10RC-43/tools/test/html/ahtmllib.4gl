########################################################################
# Utility functions for CGI programs
#
# Set www.* record with the environment
#
# Parse GET/POST variables in HTTPvar array
#
# vread() function to read HTTPvar
#                                                                      
# $Id: ahtmllib.4gl,v 1.1 2007-06-07 20:34:15 fortiz Exp $
#
########################################################################

###########
globals
###########
	define
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
    end record


end globals

#==================== HTML Library ==========================


#######################
function html_init()
#######################
    let form_method="POST"

	call get_webserver_vars()

	if www.REQUEST_METHOD = "POST"
	then
		call getstdin()
		call html_params(HTTP_POST_VAR)
    else
		call html_params(HTTP_GET_VAR)
    end if
end function

############################
function html_headers(what)
############################
define what varchar(100)

let what = what clipped
code

printf("Content-type: %s\n\n",what);

endcode

return
end function

###################################
function html_start_body()
###################################
	display "<body text='#000000' bgcolor='#ededff' link='#000000' vlink='#000000' alink='#000000'>"
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

    let prg_name = www.script_name


	if length (allparams) = 0
    then
		return
    end if

    let numparams = 0
    let startpos = 1
    let allparamslength = length(allparams)

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
    FOR cnt = 1 TO numparams
	############################

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
                let cutstring = cutstring[1,i-1]," ",cutstring[i+1,varlen]
            end if

			#Netscape sends "@" as "%40"
			if cutstring[i,i+2] = "%40"
            then
                let  cutstring =  cutstring[1,i-1],"@",cutstring[i+3,varlen]
            end if


        #######
		end for
        #######

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
 	call page_menu()
	call show_webserver_vars()
	call standard_footer()
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
	char s[1000];
	for (c=0;c<a;c++) {
		memset(s,0,999);
		A4GL_pop_char(s,1000);
		trim(s);
		printf("<li>%s</li>\n",s,c,a);
	}
return 0;
}
endcode
######################################################################

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


#--------------------------- EOF --------------------------------
