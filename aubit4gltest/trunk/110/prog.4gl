{**
 * @file
 * Test for core dump in LOAD FROM
 * @process TEST_GENERAL
 *}
 
database test1
main
define
    l_status,
    tmp_status,
	result,
    success,
	cnt
        smallint,
    path, cmd, filename
        char(800),
	mask
		char (50)
		
		let path = "."
		let mask = "*.4gl"
		let filename = "/tmp/match.tmp"
		let cmd = "ls ", path clipped,"/", mask clipped, " > ", 
			filename clipped," 2>/dev/null"
		run cmd
#display "A", filename clipped
		whenever error continue
		drop table tmp_tmp
		whenever error stop
#display "AA", filename clipped		
		create temp table tmp_tmp ( text_line char(180) )
#display "AB", filename clipped
		#Informix 4GL has a problem with this:
		#load from filename delimiter "\n" insert into tmp_tmp
		#Invalid delimiter. Do not use '\\' or hex digits (0-9, A-F, a-f).
		load from filename delimiter "" insert into tmp_tmp
#display "AC", filename clipped		
		select count(*) into cnt from tmp_tmp
		
		#must be 1 since there is only one 4gl file in this directory
		if cnt = 1 then 
			exit program (0)
		else
			display cnt, " rows found in file"
			exit program (1)
		end if

end main
