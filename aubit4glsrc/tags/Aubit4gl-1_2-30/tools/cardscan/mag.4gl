
#define mv_pan1,mv_pan2 CHAR(19)
#Define mv_data1,mv_data2 char(11)
#define mv_name char(26)
DEFINE mv_card RECORD
       pan                CHAR(19),
       name               CHAR(26),
       expire             CHAR(4),
       service            CHAR(3),
       data1              CHAR(60),
       data2              CHAR(60)
END RECORD

DEFINE mv_cardscanned     CHAR(256)

DEFINE mv_firsttime INTEGER


FUNCTION get_lastcard_pan() 
	return mv_card.pan
END FUNCTION

FUNCTION get_lastcard_name() 
	return mv_card.name
END FUNCTION


FUNCTION get_lastcard_surname()
define lv_indexof integer
define a_name char(256)
let a_name=mv_card.name
                        if a_name matches "*/*" then
                                let lv_indexof=aclfgl_indexof(a_name,"/")
                                if lv_indexof>0 then
                                        let a_name=a_name[1,lv_indexof-1]
                                end if
                        end if

	return a_name
END FUNCTION

FUNCTION get_lastcard_details() 
	return mv_card.pan, mv_card.name,mv_card.expire
END FUNCTION


# enable/disable card scanning
#     call initialize_card_reader(false)
# from within main to disable card scanning
# and then use
#     scan_card()
# to enable it - and return the value you want...
FUNCTION initialize_card_reader (lv_set)
# Parameters
DEFINE lv_set             INTEGER

# Normal Variables
DEFINE lv_keycode         INTEGER

if mv_firsttime = false then
	# Reverse logic to catch the default value of NULL 
else
    	call form_is_compiled(a4gl_fcard,"MEMPACKED","GENERIC")
    	call form_is_compiled(a4gl_fcard2,"MEMPACKED","GENERIC")
	let mv_firsttime=false
end if
	

    # Assuming F36 isn;t used for anything else...
    LET lv_keycode=fgl_keyval("F36")

    # define %B to be recognised by ncurses at "F36"
    CALL ui.curses.define_key("%B",300)

    IF lv_set THEN

        # Set up a callback to the 4gl function 'get_scanned_code' whenever F36 is pressed
code
    aclfgl_key_callback(aclfgl_get_scanned_code,lv_keycode);

endcode

    ELSE

        # Add the inital callback for F36 so it will discard the data...

code
    aclfgl_key_callback(aclfgl_dump_scanned_code,lv_keycode);

endcode

    END IF

END FUNCTION



# open the window to allow a card scan to take place and then read the card
# and return the primary information...
FUNCTION scan_card ()
DEFINE lv_data            CHAR(80)
DEFINE lv_exp_month       INTEGER
DEFINE lv_exp_yr          INTEGER


initialize mv_card.* TO NULL
initialize mv_cardscanned TO NULL

    CALL initialize_card_reader(TRUE)

	let lv_data= " "

    OPEN WINDOW w_card AT 10,10
       WITH FORM "a4gl_fcard" ATTRIBUTES(BORDER, MESSAGE LINE LAST, form line 1,error line last,style="ds.")

	let int_flag=false
    INPUT lv_data  WITHOUT DEFAULTS
     FROM carddata

         ON KEY (F36)

	
            CALL get_card_details()
             RETURNING mv_card.*	

		if mv_card.pan is NULL THEN
			exit input
		end if

            IF mv_card.expire IS NULL THEN
                message "No card expiry date"
                CONTINUE INPUT
            END IF

            LET lv_exp_yr=mv_card.expire[1,2]

            # Anything after 1980...
            IF lv_exp_yr<80 THEN
                LET lv_exp_yr=lv_exp_yr+2000
            ELSE
                LET lv_exp_yr=lv_exp_yr+1900
            END IF

            LET lv_exp_month=mv_card.expire[3,4]

            IF YEAR(TODAY)>lv_exp_yr THEN
                message "Card has expired"
                CONTINUE INPUT
            ELSE

                # It runs out this year - so what about the month
                IF YEAR(TODAY)=lv_exp_yr AND lv_exp_month<MONTH(TODAY) THEN
                    message "Card has expired"
                    CONTINUE INPUT
                END IF

            END IF

            IF mv_card.pan IS NOT NULL THEN
                EXIT INPUT
            END IF

    END INPUT

    IF int_flag=TRUE THEN
        LET int_flag=FALSE

        INITIALIZE mv_card.* TO NULL
    END IF

    CLOSE WINDOW w_card

    CALL initialize_card_reader(FALSE)

    MESSAGE ""



    if mv_card.pan  is not null then
    	OPEN WINDOW w_card2 AT 2,2
       		WITH FORM "a4gl_fcard2" ATTRIBUTES(BORDER, MESSAGE LINE LAST)

	display by name mv_card.pan
	display by name mv_card.name
	display by name mv_card.expire
	display by name mv_card.service
	display by name mv_card.data1
	display by name mv_card.data2


	MENU "Accept ?"
			COMMAND "Yes"
				exit menu
			COMMAND "No"
				initialize mv_card.pan to NULL
				exit menu
	END MENU
        CLOSE WINDOW w_card2
    end if

    RETURN mv_card.pan
END FUNCTION



LOCAL FUNCTION get_card_details ()
DEFINE lv_blah            CHAR(60)

DEFINE lv_card RECORD
       pan                CHAR(19),
       name               CHAR(26),
       expire             CHAR(4),
       service            CHAR(3),
       data1              CHAR(60),
       data2              CHAR(60)
END RECORD

DEFINE lv_data1           CHAR(60)
DEFINE lv_data2           CHAR(60)
DEFINE lv_name            CHAR(60)
DEFINE lv_pan1            CHAR(60)
DEFINE lv_pan2            CHAR(60)

    IF mv_cardscanned IS NOT NULL THEN

        WHENEVER ERROR CONTINUE

        CALL aclfgl_split_on_delimiter("|",mv_cardscanned)
         RETURNING lv_pan1,lv_name,lv_data1,lv_pan2,lv_data2

        WHENEVER ERROR STOP

        IF status!=0 THEN
            INITIALIZE mv_cardscanned TO NULL

            RETURN NULL,NULL,NULL,NULL,NULL,NULL
        END IF

        IF lv_pan1 IS NULL THEN
            ERROR "Scan error : Invalid delimiter"

            INITIALIZE mv_cardscanned TO NULL
		INITIALIZE lv_card.* TO NULL 
                RETURN lv_card.*

        END IF

        IF length(lv_pan1) AND length(lv_pan2) THEN

            IF lv_pan1!=lv_pan2 THEN
                ERROR "Invalid PAN!"

                INITIALIZE mv_cardscanned TO NULL
		INITIALIZE lv_card.* TO NULL 
                RETURN lv_card.*
            END IF

        END IF

        LET lv_card.pan=lv_pan1
        LET lv_card.name=lv_name
        LET lv_card.expire=lv_data1[1,4]
        LET lv_card.service=lv_data1[5,7]
        LET lv_card.data1=lv_data1[8,60]
        LET lv_card.data2=lv_data2[8,60]

        INITIALIZE mv_cardscanned TO NULL

        RETURN lv_card.*
    END IF

    INITIALIZE lv_card.* TO NULL 
    RETURN lv_card.*

END FUNCTION



LOCAL FUNCTION dump_scanned_code ()
DEFINE lv_an              INTEGER

    # Eat up rougue card scanned and throw them away...
    WHILE TRUE
        LET lv_an=fgl_getkey_wait(1)

        IF lv_an=0 THEN
            RETURN
        END IF

        IF lv_an=13 OR lv_an=10 THEN
            RETURN
        END IF

    END WHILE

    ERROR "Card scanning is not allowed at this time"

END FUNCTION



FUNCTION get_scanned_code ()
DEFINE lv_a               CHAR(1)
DEFINE lv_an              INTEGER
DEFINE lv_retint          INTEGER
DEFINE lv_retval          CHAR(300)
DEFINE lv_state           INTEGER

    LET lv_retint=1
    LET lv_retval=" "

    MESSAGE "Waiting for scan..."

    {

    # http://en.wikipedia.org/wiki/Magnetic_stripe_card
    # Start sentinel . one character (generally '%')
    # Format code="B" . one character (alpha only)
    	These will be swallowed by the define_key

    # Primary account number (PAN) . up to 19 characters. Usually, but not always, matches the credit card number printed on the front of the card.
    # Field Separator . one character (generally '^')
    # Name . two to 26 characters
    # Field Separator . one character (generally '^')
    # Expiration date . four characters in the form YYMM.
    # Service code . three characters
    # Discretionary data . may include Pin Verification Key Indicator (PVKI, 1 character), PIN Verification Value (PVV, 4 characters), Card Verification Value or Card Verification Code (CVV or CVK, 3 characters)
    # End sentinel . one character (generally '?')
    }
    LET lv_state=1

    INITIALIZE mv_cardscanned TO NULL

    WHILE TRUE
        LET lv_an=fgl_getkey_wait(1)

        IF lv_an=0 THEN
            ERROR "Scan ended badly (",lv_state using "<<<<",")" sleep 1
            LET mv_cardscanned=NULL
            MESSAGE ""

            RETURN
        END IF

        IF lv_an=13 OR lv_an=10 THEN
            LET mv_cardscanned=lv_retval
            RETURN
        END IF

        LET lv_a=ASCII (lv_an)

        # PAN
        IF lv_state=1 AND lv_a="^" THEN
            LET lv_retval[lv_retint]="|"
            LET lv_retint=lv_retint+1
            LET lv_state=2

            CONTINUE WHILE
        END IF

        # NAME
        IF lv_state=2 AND lv_a="^" THEN
            LET lv_retval[lv_retint]="|"
            LET lv_retint=lv_retint+1
            LET lv_state=3

            CONTINUE WHILE
        END IF

        # END OF TRACK 1
        IF lv_state=3 AND lv_a="?" THEN

            #let lv_retval[lv_retint]="|" let lv_retint=lv_retint+1
            LET lv_state=4

            CONTINUE WHILE
        END IF

        IF lv_state=4 AND lv_a=";" THEN
            LET lv_retval[lv_retint]="|"
            LET lv_retint=lv_retint+1
            LET lv_state=5

            CONTINUE WHILE
        END IF

        IF lv_state=5 AND lv_a="=" THEN
            LET lv_retval[lv_retint]="|"
            LET lv_retint=lv_retint+1
            LET lv_state=6

            CONTINUE WHILE
        END IF

        IF lv_state=6 AND lv_a="?" THEN
            CONTINUE WHILE

            LET lv_state=7
        END IF

        LET lv_retval[lv_retint]=lv_a
        LET lv_retint=lv_retint+1
    END WHILE

END FUNCTION
