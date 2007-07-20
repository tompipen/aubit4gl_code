DEFINE  # global to this module
    medarr      ARRAY[4] OF RECORD
                        description     CHAR(10),
                        bal_amount      INTEGER,
                        item            CHAR(49),
                        bal_units       INTEGER,
                        price           DECIMAL(8,0),
                        loan            INTEGER
                        END RECORD,
               arr_idx             SMALLINT,
               scr_idx             SMALLINT,
				pant_arr_merc       ARRAY [3] OF RECORD
				   descite          CHAR(50)
				END RECORD, 
               wk_arr_descite ARRAY[3000,50] OF RECORD
                    descite         CHAR(50)
               END RECORD 

MAIN
        DEFINE
                x       INTEGER,
                y       INTEGER

#define confirm char

        OPTIONS
                INPUT WRAP,
        MESSAGE LINE 1,
        PROMPT LINE 23,
                COMMENT LINE 23,
                ERROR LINE 24,
        ACCEPT KEY CONTROL -N 

        OPEN FORM arr4 FROM "test3p1"

        DISPLAY FORM arr4 ATTRIBUTE (CYAN)

        CALL fgl_drawbox(21,80,2,1,0)

        LET medarr[1].description = NULL
        LET medarr[1].bal_amount = NULL
        LET medarr[1].item = NULL
        LET medarr[1].price = NULL
        LET medarr[1].loan = NULL
        LET medarr[1].bal_units = NULL

        LET medarr[2].description = "2"
        LET medarr[2].bal_amount = 0
        LET medarr[2].item = NULL
        LET medarr[2].price = 123456
        LET medarr[2].loan = 123456
        LET medarr[2].bal_units = NULL

        LET medarr[3].description = "3"
        LET medarr[3].bal_amount = 0
        LET medarr[3].item = NULL
        LET medarr[3].price = 0
        LET medarr[3].loan = 0
        LET medarr[3].bal_units = NULL

        LET medarr[4].description = "4"
        LET medarr[4].bal_amount = 0
        LET medarr[4].item = NULL
        LET medarr[4].price = 0
        LET medarr[4].loan = 0
        LET medarr[4].bal_units = NULL

    CALL SET_COUNT(4)

    input array medarr without defaults from ftlbal.*

        on key(control-b)
            IF INFIELD(item) THEN
		let arr_idx=1
                 LET arr_idx = arr_curr()
                 LET scr_idx = SCR_LINE()

                 CALL descripcion_adicional_items(arr_idx) 
            END IF
               # LET medarr[x].description = "XXXX"

#        on key(control-b)
#                let x=arr_Curr()
#                LET medarr[x].description = "YYYY"

        end input

        CLOSE FORM arr4
	if medarr[1].description !="ABC" then
        exit program 1
	else
        exit program 0
	end if
END MAIN

FUNCTION descripcion_adicional_items(l_pos)
        DEFINE l_pos,
               l_x, 
               l_y,
               l_filas,
               arr_idx   SMALLINT
        OPEN WINDOW pant_descite AT 3,3 WITH FORM "test3p2"

        INPUT ARRAY pant_arr_merc WITHOUT DEFAULTS FROM sc.*
        #END INPUT 
        CLOSE WINDOW pant_descite
END FUNCTION
