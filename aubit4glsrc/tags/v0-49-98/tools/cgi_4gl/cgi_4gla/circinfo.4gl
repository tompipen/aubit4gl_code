DATABASE library

MAIN
	DEFINE
		formrc INT,
		retc INT,
		p_pin LIKE security.pin,
		p_id_number LIKE patron.id_number,
		err_msg CHAR(128),
		err_cnt INT,
		p_valid RECORD
			id_number LIKE patron.id_number,
			pin LIKE security.pin,
			name LIKE patron.name,
			id_status LIKE patron.id_status,
			status LIKE status_code.description
		END RECORD
	
	CALL load_form() RETURNING formrc

	IF formrc = 0 THEN
		CALL output_form("", 0, "")
	ELSE
		CALL get_entry("ssn") RETURNING p_id_number
		CALL get_entry("pin") RETURNING	p_pin
		CALL get_entry("retry") RETURNING err_cnt
		
		IF err_cnt = 3 THEN
			CALL show_error("Too many incorrect tries!")
		ELSE
			SELECT 	patron.id_number, security.pin, patron.name,
				patron.id_status, status_code.description
			INTO	p_valid.*
			FROM 	patron, security, status_code, standing_code
			WHERE 	patron.id_number = security.id_number AND
				patron.id_status = status_code.id_status AND
				patron.standing = standing_code.standing AND
				patron.id_number = p_id_number

			IF status = 0 THEN
				IF p_valid.id_status = "G" THEN
					IF p_pin = p_valid.pin THEN
						CALL has (p_valid.id_number, p_valid.name) RETURNING retc
						IF retc = FALSE THEN
							LET err_msg = "No circulation information was found for ", p_valid.name CLIPPED, "."
							CALL show_error(err_msg)
						END IF
					ELSE
						LET err_msg = "Invalid PIN ", p_pin, ", please try again."
						LET err_cnt = err_cnt + 1
						CALL output_form(err_msg, err_cnt, p_id_number)
					END IF
				ELSE
					LET err_msg = "ID NOT VALID because it is ", p_valid.status CLIPPED, "."
					CALL show_error(err_msg)
				END IF
			ELSE
				LET err_msg = "The BYU ID ", p_id_number, " was not found in our patron database."
				LET err_cnt = err_cnt + 1
				CALL has (p_id_number, "SPECIAL ACCOUNT") RETURNING retc
				IF retc = FALSE THEN
					CALL output_form(err_msg, err_cnt, "")
				END IF
			END IF
		END IF
	END IF
	CALL free_form()
END MAIN

FUNCTION output_form(special_msg, retry, ssn_str)
	DEFINE
		special_msg CHAR(128),
		retry INT,
		ssn_str CHAR(9)

	DISPLAY "Content-type: text/html"
	DISPLAY ""
	DISPLAY "<TITLE>Brigham Young University Libraries Patron Circulation Records</TITLE>"
	DISPLAY "<CENTER>"
	DISPLAY "<H1>Patron Circulation Records</H1>"
	DISPLAY "<FORM METHOD=\"POST\" ACTION=\"http:/cgi-bin/circinfo\">"
	DISPLAY "Enter your BYU ID number: <INPUT SIZE=9 MAXLENGTH=9 NAME=\"ssn\" VALUE=\"", ssn_str CLIPPED,"\"> <P>"
	DISPLAY "Enter your personal identification number: <INPUT SIZE=4 MAXLENGTH=4"
	DISPLAY "TYPE=\"password\" NAME=\"pin\"> <P>"
	DISPLAY "<INPUT TYPE=\"submit\" VALUE=\"Lookup\">"
	DISPLAY "<INPUT TYPE=\"reset\" VALUE=\"Clear Form\">"
	DISPLAY "<INPUT TYPE=\"hidden\" NAME=\"retry\" VALUE=", retry CLIPPED, ">"
	DISPLAY "<BR>"
	DISPLAY "</FORM>"
	DISPLAY "<BLINK><B>", special_msg CLIPPED, "</B></BLINK>"
	DISPLAY "</CENTER>"
	DISPLAY "<HR SIZE=4>"
	DISPLAY "<UL>"
	DISPLAY "<LI><I>You may obtain your pin by presenting your current ID at the general"
	DISPLAY "reference desk.</I>"
	DISPLAY "<LI><I>Circulation records are only updated at the end of the day.</I>"
	DISPLAY "<LI><I>Items checked out on the current day will not be listed.</I>"
	DISPLAY "</UL>"
	DISPLAY "<HR SIZE=4>"
END FUNCTION

FUNCTION show_error(error_msg)
	DEFINE
		error_msg CHAR(128)

	DISPLAY "Content-type: text/html"
	DISPLAY ""
	DISPLAY "<TITLE>Brigham Young University Libraries Patron Circulation Records</TITLE>"
	DISPLAY "<CENTER>"
	DISPLAY "<BLINK><B>", error_msg CLIPPED, "</B></BLINK>"
	DISPLAY "</CENTER>"
END FUNCTION
