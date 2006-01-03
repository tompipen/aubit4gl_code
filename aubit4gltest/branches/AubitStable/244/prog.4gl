DATABASE test1

MAIN
	DEFINE	query_string    CHAR(240)      # SPR-4418
	define lv_ok INTEGER

	OPEN FORM cons_fild FROM "cons_fild"
	DISPLAY FORM cons_fild
	LET lv_ok=0
	CONSTRUCT query_string ON hca_list.cacct_no
             FROM account

    AFTER  FIELD account
		let lv_ok=1
    		OPTIONS DISPLAY ATTRIBUTE(WHITE,BOLD)

	END CONSTRUCT
	if lv_ok!=1 or query_string!= "hca_list.cacct_no='222'" then
   		display "lv_ok= >",lv_ok,"< query_string= >",query_string clipped, "<"
		#lv_ok=          1query_string= >hca_list.cacct_no='2'<
		sleep 5
		EXIT PROGRAM 1
	end if
	
END MAIN
