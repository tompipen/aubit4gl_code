
MAIN
define a record
	card_details char(19),
	name char(50),
	some_other_details char(50)
end record
define lv_carddata char(19)
define lv_dir char(1)
	
    call magreader::initialize_card_reader(false)

    OPEN FORM details FROM "something"
    DISPLAY FORM details
    defer interrupt
    options input wrap
    INPUT BY NAME a.* 
   	BEFORE FIELD card_details
		if fgl_lastkey()=fgl_keyval("UP") or fgl_lastkey()=fgl_keyval("LEFT") then
			let lv_dir="P"
		else
			let lv_dir="N"
		end if
	
		call magreader::scan_card() returning lv_carddata


            IF lv_carddata IS NOT NULL THEN
                LET a.card_details=lv_carddata

                IF a.name IS NULL THEN
                    CALL magreader::get_lastcard_surname() RETURNING a.name
                END IF

                DISPLAY BY NAME a.name,a.card_details
            END IF

		if lv_dir="P" then
			next field previous
		else
			next field next
		end if
    end input
	
end main


