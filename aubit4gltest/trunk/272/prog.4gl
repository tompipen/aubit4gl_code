
DATABASE test1

MAIN
	DEFINE	queryStr	CHAR(200),
			exitint		SMALLINT,
			selstmt		CHAR(200)
	define lv_i integer
	define x char(20)
	
	
 	let lv_i=1
 	OPEN window w1 at 2,2 with form "constru"
		CONSTRUCT queryStr ON temp_tbl.account_number
			FROM formonly.account_number
			
		after construct 
			let x= get_fldbuf(account_number)
			error "x='",x,"'" sleep 1
			if get_fldbuf(account_number) = " "  or  get_fldbuf(account_number) is null then
				error "Insufficient" sleep 2
				let lv_i=lv_i-1
				#	 f*ck windows - the test stays as it is..
				# fix the bug - not the test...
				continue construct
			else
				error "---> " # ,get_fldbuf(account_number) sleep 2
				exit program lv_i
			end if

		END CONSTRUCT



END MAIN
