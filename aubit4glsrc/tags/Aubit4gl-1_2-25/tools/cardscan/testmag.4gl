


MAIN

DEFINE a RECORD
       card_details       CHAR(19),
       name               CHAR(50),
       some_other_details CHAR(50)
END RECORD

DEFINE lv_carddata        CHAR(19)
DEFINE lv_dir             CHAR(1)
DEFINE lv_indexof         INTEGER

    CALL initialize_card_reader(FALSE)

    OPEN FORM details FROM "something"

    DISPLAY FORM details

    DEFER INTERRUPT

    OPTIONS INPUT WRAP

    INPUT BY NAME a.*

        BEFORE FIELD card_details

            IF fgl_lastkey()=fgl_keyval("UP") OR fgl_lastkey()=fgl_keyval("LEFT") THEN
                LET lv_dir="P"
            ELSE
                LET lv_dir="N"
            END IF

            CALL scan_card() RETURNING lv_carddata

            IF lv_carddata IS NOT NULL THEN
                LET a.card_details=lv_carddata

                IF a.name IS NULL THEN
                    CALL get_lastcard_surname() RETURNING a.name
                END IF

                DISPLAY BY NAME a.name,a.card_details
            END IF

            IF lv_dir="P" THEN
                NEXT FIELD PREVIOUS
            ELSE
                NEXT FIELD NEXT
            END IF

    END INPUT

END MAIN
