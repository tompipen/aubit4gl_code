
MAIN
define a record
	name char(50),
	card_details char(19),
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
		if lv_carddata is not null then
			let a.card_details=lv_carddata
		end if
		if lv_dir="P" then
			next field previous
		else
			next field next
		end if
    end input
	
end main


