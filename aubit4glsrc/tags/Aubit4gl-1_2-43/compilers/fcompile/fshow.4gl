code

#ifdef GTK
#define fgl_start(x,y) A4GL_setenv("A4GL_UI","gtk",1);fgl_start(x,y)
#endif


endcode



MAIN
DEFINE lv_formname CHAR(256)
	IF num_args()=0 THEN
		DISPLAY "You didn't supply a file name!"
		EXIT PROGRAM
	END IF

	LET lv_formname=arg_val(1)
	OPEN FORM f1 FROM lv_formname
	DISPLAY FORM f1
        OPTIONS PROMPT LINE LAST
	if fgl_getenv("NOFSHOWPROMPT")="Y" Then
		# ....
	else
        	PROMPT "PRESS ANY KEY " FOR CHAR lv_formname
	end if
END MAIN
