
DATABASE test1

MAIN
	DEFINE	queryStr	CHAR(200),
			exitint		SMALLINT,
			selstmt		CHAR(200)
	define lv_i integer
	
 	let lv_i=1
 	OPEN window w1 at 2,2 with form "constru"
		CONSTRUCT queryStr ON temp_tbl.account_number
			FROM formonly.account_number
			
		after construct 
			if get_fldbuf(account_number) = " "  or  get_fldbuf(account_number) is null then
				error "Insufficient" sleep 2
				let lv_i=lv_i-1
				continue construct
			else
				error "---> ",get_fldbuf(account_number) sleep 2
				exit program lv_i
			end if

		END CONSTRUCT



END MAIN
