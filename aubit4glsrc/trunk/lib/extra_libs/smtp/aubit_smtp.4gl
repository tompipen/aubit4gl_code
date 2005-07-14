
# SMTP integration

code
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include "libsmtp.h"
#include "libsmtp_mime.h"
endcode

define mv_counter integer
define mv_err_msg char(200)
define mv_server char(200)
define mv_has_err integer

################################################################################
function set_errmsg(lv_msg)
define lv_msg char(200)
let mv_err_msg=lv_msg
let mv_has_err=1
display "Error : ",lv_msg
exit program 1
end function


function clear_err()
let mv_has_err=0
let mv_err_msg=""
end function

function set_server(lv_server) 
define lv_server char(200)
	let mv_server=lv_server
end function

function get_server()
if mv_server is null or mv_server matches " " then
	let mv_server=fgl_getenv("SMTPSERVER")
end if
if mv_server is null or mv_server matches " " then
	let mv_server="mail"
end if

return mv_server

end function

################################################################################
function get_errmsg()
return mv_err_msg clipped
end function



################################################################################
function start_message(lv_sender,lv_subject)
define lv_sender,lv_subject char(512)
define lv_session integer
code
	A4GL_trim(lv_sender);
	A4GL_trim(lv_subject);
	lv_session=(long)libsmtp_session_initialize();
	libsmtp_set_environment (lv_sender, lv_subject, 0, (struct libsmtp_session_struct *)lv_session);
endcode
return lv_session
end function

################################################################################
function add_recipient(lv_message,lv_to)
define lv_message integer
define lv_to char(512)
call clear_err()
code
	A4GL_trim(lv_to);
	if (libsmtp_add_recipient (LIBSMTP_REC_TO, lv_to, lv_message)) {
		A4GL_push_char(libsmtp_strerr (lv_message));
		aclfgl_set_errmsg(1);
	}
endcode
end function

################################################################################
function send_to(lv_message,lv_to)
define lv_message integer
define lv_to char(512)
call clear_err()
code
	A4GL_trim(lv_to);
	if (libsmtp_add_recipient (LIBSMTP_REC_TO, lv_to, lv_message)) {
		A4GL_push_char(libsmtp_strerr (lv_message));
		aclfgl_set_errmsg(1);
	}
endcode
end function

function send_to_cc(lv_message,lv_to)
define lv_message integer
define lv_to char(512)
call clear_err()
code
	A4GL_trim(lv_to);
	if (libsmtp_add_recipient (LIBSMTP_REC_CC, lv_to, lv_message)) {
		A4GL_push_char(libsmtp_strerr (lv_message));
		aclfgl_set_errmsg(1);
	}
endcode
end function

################################################################################
function send_to_bcc(lv_message,lv_to)
define lv_message integer
define lv_to char(512)
call clear_err()
code
	A4GL_trim(lv_to);
	libsmtp_add_recipient (LIBSMTP_REC_BCC, lv_to, lv_message);
endcode
end function


function mime_type_new(lv_message,lv_part,lv_mimetype)
define lv_message integer
define lv_part integer
define lv_mimetype char(40)
define lv_desc char(256)
if mv_counter is null then
	let mv_counter=1
end if
let lv_desc= "MimeSection" ,mv_counter using "<<<<<"
return mime_type_new_with_description(lv_message,lv_part,lv_mimetype,lv_desc)
end function


################################################################################
function mime_type_new_with_description(lv_message,lv_part,lv_mimetype,lv_description)
define cset integer
define enc integer
define lv_part integer
define lv_newpart integer
define lv_type char(40)
define lv_description char(256)
define lv_rtype integer
define lv_rsubtype integer
define lv_message integer
define lv_mimetype char(40)
call clear_err()

let lv_type=downshift(lv_mimetype)
code
A4GL_trim(lv_type);
A4GL_trim(lv_description);

lv_rtype=LIBSMTP_MIME_TEXT;
lv_rsubtype=LIBSMTP_MIME_SUB_PLAIN;
cset=LIBSMTP_CHARSET_NOCHARSET;
enc=LIBSMTP_ENC_8BIT;

if (strcasecmp(lv_type,"text/plain")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_TEXT; lv_rsubtype=LIBSMTP_MIME_SUB_PLAIN;}
if (strcasecmp(lv_type,"text/html")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_TEXT; lv_rsubtype=LIBSMTP_MIME_SUB_HTML;}
if (strcasecmp(lv_type,"text/english")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_TEXT; lv_rsubtype=LIBSMTP_MIME_SUB_ENGLISH;}
if (strcasecmp(lv_type,"text/richtext")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_TEXT; lv_rsubtype=LIBSMTP_MIME_SUB_RICHTEXT;}

if (strcasecmp(lv_type,"message/rfc822")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_MESSAGE; lv_rsubtype=LIBSMTP_MIME_SUB_RFC822;}
if (strcasecmp(lv_type,"message/partial")==0) { 
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	enc=LIBSMTP_ENC_QUOTED;
	lv_rtype=LIBSMTP_MIME_MESSAGE; lv_rsubtype=LIBSMTP_MIME_SUB_PARTIAL;}


if (strcasecmp(lv_type,"image/gif")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_GIF;}
if (strcasecmp(lv_type,"image/jpg")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_JPG;}
if (strcasecmp(lv_type,"image/jpeg")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_JPG;}
if (strcasecmp(lv_type,"image/png")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_PNG;}
if (strcasecmp(lv_type,"image/tiff")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_TIFF;}

if (strcasecmp(lv_type,"image/tif")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_TIFF;}
if (strcasecmp(lv_type,"image/ms-bmp")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_IMAGE; lv_rsubtype=LIBSMTP_MIME_SUB_MS_BMP;
}


if (strcasecmp(lv_type,"application/rtf")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; lv_rsubtype=LIBSMTP_MIME_SUB_RTF;
}
if (strcasecmp(lv_type,"application/postscript")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; lv_rsubtype=LIBSMTP_MIME_SUB_POSTSCRIPT;
}
if (strcasecmp(lv_type,"application/pdf")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; 
	lv_rsubtype=LIBSMTP_MIME_SUB_PDF;
}
if (strcasecmp(lv_type,"application/exe")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; lv_rsubtype=LIBSMTP_MIME_SUB_EXECUTABLE;
}
if (strcasecmp(lv_type,"application/tar")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; lv_rsubtype=LIBSMTP_MIME_SUB_TAR;
}
if (strcasecmp(lv_type,"application/tgz")==0) { 
	enc=LIBSMTP_ENC_BASE64;
	lv_rtype=LIBSMTP_MIME_APPLICATION; lv_rsubtype=LIBSMTP_MIME_SUB_GTAR;
}

if (strcasecmp(lv_type,"multipart/mixed")==0) { 
	enc=LIBSMTP_ENC_7BIT;
	//cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	lv_rtype=LIBSMTP_MIME_MULTIPART; 
	lv_rsubtype=LIBSMTP_MIME_SUB_MIXED;
}

if (strcasecmp(lv_type,"multipart/parallel")==0) { 
	enc=LIBSMTP_ENC_8BIT;
	cset=LIBSMTP_CHARSET_ISO8859_1; // Assume for now...
	lv_rtype=LIBSMTP_MIME_MULTIPART; lv_rsubtype=LIBSMTP_MIME_SUB_PARALLEL;
}
if (strcasecmp(lv_type,"multipart/digest")==0) { 
	enc=LIBSMTP_ENC_8BIT;
	lv_rtype=LIBSMTP_MIME_MULTIPART; lv_rsubtype=LIBSMTP_MIME_SUB_DIGEST;
}
if (strcasecmp(lv_type,"multipart/alternative")==0) { 
	enc=LIBSMTP_ENC_8BIT;
	lv_rtype=LIBSMTP_MIME_MULTIPART; lv_rsubtype=LIBSMTP_MIME_SUB_ALTERNATIVE;
}


  lv_newpart = libsmtp_part_new (lv_part, lv_rtype, lv_rsubtype, enc, cset, lv_description, lv_message);
  if (lv_newpart==0) {
	printf("Couldn't do a part new : %s \n",libsmtp_strerr (lv_message));
	printf("%p %p %s %s\n",lv_message,lv_part,lv_type,lv_description);
	A4GL_push_char(libsmtp_strerr (lv_message));
	aclfgl_set_errmsg(1);
  }
endcode

return lv_newpart
end function


function connect(lv_message,lv_server,lv_port,lv_flags,lv_ismime)
define lv_server char(200)
define lv_port integer
define lv_flags integer
define lv_message integer
define lv_ismime integer

call clear_err()
if lv_server is null or lv_server matches " " then
	let lv_server=get_server()
	display "SERVER=",lv_server clipped
end if

code
	A4GL_trim(lv_server);
	if (libsmtp_connect (lv_server,lv_port,lv_flags,lv_message)) {
		A4GL_push_char(libsmtp_strerr (lv_message));
		aclfgl_set_errmsg(1);
	} else {
		if (libsmtp_dialogue (lv_message)) {
			A4GL_push_char(libsmtp_strerr (lv_message));
			aclfgl_set_errmsg(1);
		} else {
			if (libsmtp_headers (lv_message)) {
				A4GL_push_char(libsmtp_strerr (lv_message));
				aclfgl_set_errmsg(1);
			} else {
				if (lv_ismime) {
					if (libsmtp_mime_headers (lv_message)) {
						A4GL_push_char(libsmtp_strerr (lv_message));
						aclfgl_set_errmsg(1);
					}
				}
			}
		}
	}
endcode
end function


code

int aclfgl_data(int n) {
char *txt;
int msg;
txt=A4GL_char_pop();
msg=A4GL_pop_long();
aclfgl_clear_err(0);
if (libsmtp_body_send_raw (txt, strlen (txt), msg)) { 
	A4GL_push_char(libsmtp_strerr (msg)); aclfgl_set_errmsg(1); 
}
free(txt);
return 0;
}


int aclfgl_part_send_txt(int n) {
char *txt;
int msg;
int islast;

islast=A4GL_pop_long();
txt=A4GL_char_pop();
msg=A4GL_pop_long();

aclfgl_clear_err(0);
if (libsmtp_part_send (txt, strlen (txt), msg)) {
	A4GL_push_char(libsmtp_strerr (msg)); aclfgl_set_errmsg(1); 
}
if (!islast) libsmtp_part_next (msg);
	if (islast) libsmtp_part_end (msg);
return 0;
}
endcode

function part_send_file_html_listing(lv_message,lv_file,lv_last)
define lv_message integer
define lv_file char(256)
define lv_last integer
define lv_ok integer
code
{
  FILE *f;
  int l;
  static char *buffer = 0;
  int file_read;
  lv_ok = 1;
  A4GL_trim (lv_file);
  f = fopen (lv_file, "r");
  if (f)
    {
      if (!buffer)
	buffer = malloc (4098);

	sprintf(buffer,"<html><body><pre>");
  	libsmtp_part_send (buffer, strlen(buffer), lv_message);
      /* Read the file in 4k blocks */
      while ((file_read = fgets (buffer, 4096, f)))
	{
	  /* Then we send each chunk */
	  strcat(buffer,"\r\n");
	  if (libsmtp_part_send (buffer, strlen(buffer), lv_message))
	    {
	      lv_ok = 0;
	      A4GL_push_char (libsmtp_strerr (lv_message));
	      aclfgl_set_errmsg (1);
	      break;
	    }
	}
      fclose (f);
	sprintf(buffer,"</pre></body></html>");
  	libsmtp_part_send (buffer, strlen(buffer), lv_message);
        if (lv_ok && !lv_last) { libsmtp_part_next (lv_message); }
	if (lv_last) libsmtp_part_end (lv_message);
    }
}
endcode

end function


function part_send_file(lv_message,lv_file,lv_last)
define lv_message integer
define lv_file char(256)
define lv_last integer
define lv_ok integer
code
{
  FILE *f;
  int l;
  static char *buffer = 0;
  int file_read;
  lv_ok = 1;
  A4GL_trim (lv_file);
  f = fopen (lv_file, "r");
  if (f)
    {
	fseek(f,0,SEEK_END);
	l=ftell(f);
	rewind(f);
	buffer = realloc (buffer,l);

      /* Read the file in 4k blocks */
      file_read = fread (buffer, 1, l, f);
	printf("read %d bytes\n",file_read);
      if (libsmtp_part_send (buffer, file_read, lv_message))
	    {
	      lv_ok = 0;
	      A4GL_push_char (libsmtp_strerr (lv_message));
	      aclfgl_set_errmsg (1);
	    }
      fclose (f);
      if (lv_ok && !lv_last) { libsmtp_part_next (lv_message); }
      if (lv_last) libsmtp_part_end (lv_message);
    }
}
endcode

end function

function disconnect(lv_message)
define lv_message integer
call clear_err()
code


	if (libsmtp_body_end (lv_message)) {
		A4GL_push_char(libsmtp_strerr (lv_message)); aclfgl_set_errmsg(1); 
	} else {
		if (libsmtp_quit (lv_message)) {
			A4GL_push_char(libsmtp_strerr (lv_message)); aclfgl_set_errmsg(1); 
		}
	}
endcode
end function




function send_report(lv_hint,lv_rep_filename,lv_email_addr)
define lv_rep_filename char(255)
define lv_email_addr char(255)
define lv_message integer
define lv_mainpart integer
define lv_textpart integer
define lv_htmlpart integer
define lv_pdfpart integer
define lv_reppart integer
define lv_subject char(255)
define lv_hint char(10)
define lv_server char(200)

#display "HINT:",lv_hint clipped
#display "FILENAME:",lv_rep_filename clipped
#display "EMAIL:",lv_email_addr clipped

let lv_subject="Your report (",lv_rep_filename clipped,")"

if lv_email_addr is null or lv_email_addr matches " " then
	let lv_email_addr=aclfgl_get_user()
end if

#display "Start"
let lv_message=start_message("aubit4gl",lv_subject)
call fgl_smtp::send_to(lv_message,lv_email_addr)

let lv_mainpart = fgl_smtp::mime_type_new(lv_message,0,"multipart/mixed")

let lv_textpart = fgl_smtp::mime_type_new(lv_message,lv_mainpart,"text/plain")

if lv_rep_filename matches "*.pdf" or lv_hint="PDF" then
	let lv_pdfpart=fgl_smtp::mime_type_new_with_description(lv_message,lv_mainpart,"application/pdf",lv_rep_filename)
else
	let lv_reppart=fgl_smtp::mime_type_new_with_description(lv_message,lv_mainpart,"text/html",lv_rep_filename)
end if

let lv_server=get_server()
call fgl_smtp::connect(lv_message,lv_server clipped,0,0,1)
call fgl_smtp::part_send_txt(lv_message,"Your report output is attached",0)

if lv_rep_filename matches "*.pdf" or lv_hint="PDF" then
	call fgl_smtp::part_send_file(lv_message,lv_rep_filename,1)
else 
	call fgl_smtp::part_send_file_html_listing(lv_message,lv_rep_filename,1)
end if

call fgl_smtp::disconnect(lv_message)

end function



code
#ifdef libsmtp_part_end
int libsmtp_part_end (struct libsmtp_session_struct *libsmtp_session)
{
   GString * boundary = g_string_new("\r\n\r\n\r\n------_=_libsmtp_Nextpart__000_000007DA.3B95D19_1--\r\n");
   return libsmtp_int_send(boundary, libsmtp_session, 1);
 }
#endif
endcode
