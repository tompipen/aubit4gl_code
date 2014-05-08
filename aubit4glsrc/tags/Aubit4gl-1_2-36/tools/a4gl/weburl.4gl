
DATABASE syspgma4gl
{----------------------------------------------------------------------+
| GLOBAL variable definition                                           |
+----------------------------------------------------------------------}

{ $Id: weburl.4gl,v 1.1 2010-01-14 08:15:57 mikeaubury Exp $ }

  DEFINE
	ga_rec_found SMALLINT,
	ga_rec_no SMALLINT,
	ga_table_name ARRAY[2] OF CHAR(32),
	ga_screen_name ARRAY[3] OF CHAR(32),
	gv_attribute CHAR(32),
	end_flag INTEGER,
	abort_flag INTEGER,
	answer CHAR(1)


    DEFINE gr_web_serverurl        RECORD LIKE        web_serverurl.*
    DEFINE ga_oid INTEGER
    DEFINE gv_rec_found, gv_mode, gv_idx INTEGER
    DEFINE gv_cursor, gv_statement CHAR(32)
    DEFINE where_part, query_text VARCHAR(1000)
    DEFINE mv_module CHAR(20)

function web_urls()
    LET mv_module = "webserver"

   # n,1 tablename n,2 tabledesc
    LET ga_table_name[1] = "web_serverurl"
    LET ga_table_name[2] = "web_serverurl"


   # n,1 formname n,2 formdesc n,3 formcolor
    LET ga_screen_name[1] = "f_webserver"
    LET ga_screen_name[2] = "webserver"
    LET ga_screen_name[3] = "GREEN"

    # define first screen for each table

    CALL prog_init()

    CALL open_window(mv_module)
    LET gv_attribute = set_delimiter(0,0)
    LET gv_attribute = set_delimiter(0,1)

        CALL display_menu(mv_module)

    CALL close_window(mv_module)
END function

##################################################
LOCAL FUNCTION display_record()
##################################################

    IF ga_rec_found <= 0 THEN
        RETURN
    END IF

         # display screen 1 table 1
        LET gv_attribute = set_delimiter(1,0)
        DISPLAY
          gr_web_serverurl.url_id,
          gr_web_serverurl.relativeurl,
		gr_web_serverurl.htaccessfile, 
		gr_web_serverurl.htpasswdfile, 
		gr_web_serverurl.xmlfile,
          gr_web_serverurl.authmode
		 TO           web_serverurl.url_id,
          web_serverurl.relativeurl,
               web_serverurl.htaccessfile,
                web_serverurl.htpasswdfile,
                web_serverurl.xmlfile,
          web_serverurl.authmode

          ATTRIBUTE(gv_attribute)

	call display_fk("authmode",gr_web_serverurl.authmode)
	call web_perms(gr_web_serverurl.url_id,"N")

        LET gv_attribute = set_delimiter(1,1)

        LET gv_attribute = set_delimiter(0,0)
        LET gv_attribute = set_delimiter(0,1)


    CALL recpos_msg()
END FUNCTION

##################################################
LOCAL FUNCTION query_by_example()
##################################################

clear form

  LET int_flag = FALSE
          CONSTRUCT BY NAME where_part ON
            web_serverurl.url_id,
            web_serverurl.relativeurl,
               web_serverurl.htaccessfile,
                web_serverurl.htpasswdfile,
                web_serverurl.xmlfile,
            web_serverurl.authmode
                  ON KEY(f1,control-b)
                   IF infield(authmode) then
                     CALL zoom("authmode", get_fldbuf(authmode)) RETURNING gr_web_serverurl.authmode
                     DISPLAY BY NAME gr_web_serverurl.authmode
                   END IF

          END CONSTRUCT
        IF int_flag THEN
          LET int_flag = FALSE
          RETURN
        END IF

          LET ga_rec_found = -1

      LET query_text = "SELECT ROWID,* from web_serverurl",
          " WHERE ", where_part CLIPPED
         #" ORDER BY aaa, bbb"

  PREPARE p_web_serverurl FROM query_text
  DECLARE c_web_serverurl SCROLL CURSOR FOR p_web_serverurl
  LET gv_rec_found = 0
  FOREACH c_web_serverurl
    LET gv_rec_found = gv_rec_found + 1
  END FOREACH
  IF gv_rec_found = 0 THEN
    CALL notfound_msg()
    RETURN
  END IF
  CLOSE c_web_serverurl
  LET ga_rec_found = gv_rec_found
  LET ga_rec_no = 1
  MESSAGE ga_rec_found using "<<<<<<", " record"
  CALL get_record()
  
END FUNCTION

##################################################
LOCAL FUNCTION get_record()
##################################################

   if ga_rec_found<=0 THEN INITIALIZE gr_web_serverurl.* TO NULL RETURN END IF
      OPEN c_web_serverurl
      FETCH ABSOLUTE ga_rec_no  c_web_serverurl
        INTO ga_oid, gr_web_serverurl.*
      IF STATUS <> 0 THEN
        CLOSE c_web_serverurl
        CALL notfound_msg()
        RETURN
      END IF
        CLOSE c_web_serverurl
      { get the derived tables row }
  CALL display_record()
END FUNCTION

##################################################
LOCAL FUNCTION add_record()
##################################################

      INITIALIZE gr_web_serverurl.* TO NULL
      CALL display_record()
      CALL add_msg("web_serverurl")
      LET gv_mode = 1
      CALL input_record()
      IF abort_flag THEN
        CALL abort_msg("web_serverurl")
        CALL get_record()
        CALL display_record()
        RETURN
      END IF
      INSERT INTO web_serverurl VALUES (gr_web_serverurl.*)
      IF status <> 0 THEN
        CALL err_msg("Error adding web_serverurl record")
        CALL display_record()
        RETURN
      END IF
      CALL err_msg("web_serverurl record added")

  CALL display_record()
END FUNCTION

##################################################
LOCAL FUNCTION update_record()
##################################################

      CALL update_msg("web_serverurl")
      LET gv_mode = 2
      CALL input_record()
      IF abort_flag THEN
        CALL abort_msg("web_serverurl")
        CALL get_record()
        CALL display_record()
        RETURN
      END IF
      UPDATE web_serverurl SET * = gr_web_serverurl.*
        WHERE rowid = ga_oid
      IF status <> 0 THEN
        CALL err_msg("Error updating web_serverurl record")
        CALL display_record()
        RETURN
      END IF
      CALL err_msg("web_serverurl updated")

  CALL display_record()
END FUNCTION

##################################################
LOCAL FUNCTION remove_record()
##################################################

      IF NOT ok_to_delete() THEN
    		CALL get_record()
    		CALL display_record()
    		RETURN
      END IF

      SELECT * into gr_web_serverurl.* from  web_serverurl WHERE rowid=ga_oid
	IF status=0 THEN
		DELETE FROM web_perms WHERE url_id=gr_web_serverurl.url_id
	END IF


      DELETE FROM web_serverurl
        WHERE rowid = ga_oid
	
      IF status <> 0 THEN
        CALL err_msg("Error removing web_serverurl record")
    CALL get_record()
    CALL display_record()
    RETURN
      END IF
      CALL err_msg("web_serverurl removed")

  IF abort_flag THEN
    CALL get_record()
  END IF
  CALL display_record()
END FUNCTION

##################################################
LOCAL FUNCTION input_record()
##################################################

  DEFINE gr_formonly RECORD
	authmode_desc	VARCHAR(100)
	END RECORD

  LET int_flag = FALSE
  LET abort_flag = FALSE
  LET gv_attribute = get_color(0)


	if gv_mode=1 then
		clear form
	end if
          INPUT 
            gr_web_serverurl.url_id,
            gr_web_serverurl.relativeurl,
               gr_web_serverurl.htaccessfile,
                gr_web_serverurl.htpasswdfile,
                gr_web_serverurl.xmlfile,
            gr_web_serverurl.authmode 
			WITHOUT DEFAULTS FROM 
               web_serverurl.url_id,
               web_serverurl.relativeurl,
               web_serverurl.htaccessfile,
               web_serverurl.htpasswdfile,
               web_serverurl.xmlfile,
               web_serverurl.authmode
# before field validation
# after field validation
                  ON KEY(f1,control-b)
                   IF infield(authmode) then
                     CALL zoom("authmode", get_fldbuf(authmode)) RETURNING gr_web_serverurl.authmode
                     DISPLAY BY NAME gr_web_serverurl.authmode
                     CALL display_fk("authmode", gr_web_serverurl.authmode)
                   END IF

		AFTER FIELD url_id
			if gr_web_serverurl.htaccessfile is null or gr_web_serverurl.htaccessfile matches " " then
				let gr_web_serverurl.htaccessfile="htaccess_"||gr_web_serverurl.url_id
				display by name gr_web_serverurl.htaccessfile
			end if

			if gr_web_serverurl.htpasswdfile is null or gr_web_serverurl.htpasswdfile matches " "then
				let gr_web_serverurl.htpasswdfile="htpasswd_"||gr_web_serverurl.url_id
				display by name gr_web_serverurl.htpasswdfile
			end if

			if gr_web_serverurl.xmlfile is null or gr_web_serverurl.xmlfile matches " " then
				let gr_web_serverurl.xmlfile="fglaccess_"||gr_web_serverurl.url_id clipped,".xml"
				display by name gr_web_serverurl.xmlfile
			end if

                  AFTER FIELD authmode
                    IF NOT validate_column("authmode",gr_web_serverurl.authmode,gv_mode) THEN
                       NEXT FIELD authmode
                    ELSE
                       CALL display_fk("authmode", gr_web_serverurl.authmode)
                    END IF

		#before field url_id
			#if gv_mode=2 then
				#next field relativeurl
			#end if

                  AFTER INPUT
                    IF int_flag THEN
                       EXIT INPUT
                    END IF
                    IF NOT validate_column("authmode",gr_web_serverurl.authmode,gv_mode) THEN
                       NEXT FIELD authmode
                    END IF

          END INPUT

          IF int_flag = TRUE THEN
             LET int_flag=FALSE
             LET abort_flag = TRUE
          END IF

          IF abort_flag THEN
            RETURN
          END IF

END FUNCTION

{----------------------------------------------------------------------+
| Common Modules                                                       |
+----------------------------------------------------------------------}

# $Id: weburl.4gl,v 1.1 2010-01-14 08:15:57 mikeaubury Exp $



LOCAL FUNCTION prog_init()
DEFINE	i smallint

    OPTIONS
	    INPUT WRAP,
	    INSERT KEY F21,
	    DELETE KEY F22,
	    PREVIOUS KEY F23,
	    NEXT KEY F24,
		MESSAGE LINE LAST


	LET ga_rec_found = -1
	LET ga_rec_no = 0

END FUNCTION

###############################
# FUNCTION NAME : open_window()
###############################

LOCAL FUNCTION open_window(lv_module)
define lv_module char(20)
DEFINE lv_window, lv_form CHAR(32)
    SET PAUSE MODE ON
	LET lv_window = "w_", lv_module CLIPPED
	LET lv_form   = "f_", lv_module CLIPPED
	OPEN WINDOW _variable(lv_window) AT 1,1 WITH 24 ROWS, 80 COLUMNS
	OPEN FORM _variable(lv_form) FROM ga_screen_name[1]
	IF STATUS <> 0 THEN
	    EXIT PROGRAM
	END IF
	DISPLAY FORM _variable(lv_form) #ATTRIBUTE (BLACK) #ga_screen_name[i,3])
    LET lv_window = "w_", lv_module CLIPPED
    CURRENT WINDOW IS _variable(lv_window)
    SET PAUSE MODE OFF
END FUNCTION

###############################
# FUNCTION NAME : close_window()
###############################

LOCAL FUNCTION close_window(lv_module)
define lv_module char(20)
DEFINE lv_window CHAR(32)
    SET PAUSE MODE ON
    LET lv_window = "w_", lv_module CLIPPED
    CLOSE WINDOW _variable(lv_window)
    SET PAUSE MODE OFF
END FUNCTION

###############################
# FUNCTION NAME : display_menu()
###############################

LOCAL FUNCTION display_menu(lv_module)
define lv_module char(20)
DEFINE lv_query, lv_next, lv_prev, lv_add, lv_update, lv_remove,
	lv_master, lv_detail, lv_screen CHAR(72),
	lv_window, lv_table CHAR(32),
	i, lv_has_master SMALLINT

    LET lv_window = "w_", lv_module CLIPPED
    CURRENT WINDOW IS _variable(lv_window)

    LET lv_query  = "Search the current table                    "
    LET lv_next   = "Shows the next row in the current table     "
    LET lv_prev   = "Shows the previous row in the current table "
    LET lv_add    = "Adds a row to the current table             "
    LET lv_update = "Changes a row in the current table          "
    LET lv_remove = "Deletes a row from the current table        "
    LET lv_screen = "Shows the next screen of the current table  "

    MENU ga_screen_name[2]
	BEFORE MENU
	    CALL display_record()

	COMMAND "Query" lv_query
	    CALL query_by_example()

	COMMAND "Next" lv_next
	    CALL display_next()

	COMMAND "Previous" lv_prev
	    CALL display_previous()

	COMMAND "Add" lv_add
	    CALL add_record()

	COMMAND "Update" lv_update
	    CALL update_record()

	COMMAND "Remove" lv_remove
	    CALL remove_record()

	COMMAND KEY ("M") "perMissions" "Edit permissions for this URL"
		if ga_rec_found and gr_web_serverurl.url_id is not null then
		 call web_perms(gr_web_serverurl.url_id,"Y")
		else
			ERROR "Nothing to find!"
	        end if

	command "Dump"  "Generate the access files"
		if ga_rec_found and gr_web_serverurl.url_id is not null then
			call dump_web_users(gr_web_serverurl.url_id)
		else
			ERROR "Nothing to find!"
		end if
	COMMAND "Exit" "Exit Program"
	    EXIT MENU
    END MENU
END FUNCTION

###############################
# FUNCTION NAME : display_next()
###############################

LOCAL FUNCTION display_next()

    IF ga_rec_found = 0 THEN
	CALL next_err_msg()
	RETURN
    END IF
    IF ga_rec_no >= ga_rec_found THEN
	CALL next_err_msg()
	RETURN
    END IF
    LET ga_rec_no = ga_rec_no + 1
    CALL get_record()

END FUNCTION

###############################
# FUNCTION NAME : display_previous()
###############################

LOCAL FUNCTION display_previous()

    IF ga_rec_found = 0 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    IF ga_rec_no <= 1 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    LET ga_rec_no = ga_rec_no - 1
    CALL get_record()

END FUNCTION	

###############################
# FUNCTION NAME : get_color()
###############################

LOCAL FUNCTION get_color(lv_idx)
DEFINE lv_idx INTEGER
	return "GREEN"
END FUNCTION

###############################
# FUNCTION NAME : set_delimiter()
###############################

LOCAL FUNCTION set_delimiter(lv_table, lv_state)
DEFINE lv_table, lv_state INTEGER

	return "BLACK"
END FUNCTION

LOCAL FUNCTION err_msg(str)
    DEFINE str CHAR(79)
    ERROR str ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION show_comments(str,hasbell,isreverse)
    DEFINE str CHAR(79),
	hasbell, isreverse SMALLINT
    IF hasbell THEN
	LET str = str, ASCII 7
    END IF
    IF isreverse THEN
	ERROR str ATTRIBUTE (RED, REVERSE)
    ELSE
	ERROR str ATTRIBUTE (RED)
    END IF
END FUNCTION


LOCAL FUNCTION abort_msg(lv_table)
DEFINE lv_table CHAR(32)
    ERROR "Input aborted for table ", lv_table CLIPPED
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION notfound_msg()
    ERROR "There are no rows satisfying the conditions."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION next_err_msg()
    ERROR "There are no more rows going forward."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION prev_err_msg()
    ERROR "There are no more rows going backward."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION recpos_msg()
    MESSAGE 
        "Record ", ga_rec_no USING "<<<<<",
        " of ", ga_rec_found USING "<<<<<", " in ", ga_table_name[1] CLIPPED
	--ATTRIBUTE (RED, REVERSE)
END FUNCTION

LOCAL FUNCTION ok_to_delete()
    PROMPT "OK TO DELETE ? " ATTRIBUTE(RED,BLINK) FOR CHAR answer
    IF answer MATCHES "[yY]" THEN
	RETURN TRUE
    ELSE
	RETURN FALSE
    END IF
END FUNCTION

LOCAL FUNCTION add_msg(lv_table)
DEFINE lv_table char(32)
    DISPLAY "ADD:  ESCAPE adds new data.  INTERRUPT discards it.  ARROW keys move cursor.  ","" at 1,1
    DISPLAY "Adds new data to the active database table.  ** ",
	lv_table CLIPPED, " table **" AT 2,1
END FUNCTION

LOCAL FUNCTION update_msg(lv_table)
DEFINE lv_table char(32)
    DISPLAY "UPDATE:  ESCAPE changes data.  INTERRUPT discards changes.                    ","" at 1,1
    DISPLAY "Changes this row in the active database table.  ** ",
	lv_table CLIPPED, " table **" AT 2,1
END FUNCTION

LOCAL FUNCTION are_you_sure(prompt_msg)
    DEFINE prompt_msg CHAR(70)
    PROMPT prompt_msg CLIPPED ATTRIBUTE(MAGENTA) FOR CHAR answer
    IF answer MATCHES "[yY]" THEN
	RETURN TRUE
    ELSE
	RETURN FALSE
    END IF
END FUNCTION

