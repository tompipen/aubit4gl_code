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
	cnt,
	done_load
        smallint,
    path, cmd, filename
        char(800),
	mask
		char (50)
		let done_load = 0
		let path = "."
		let mask = "*.4gl"
		let filename = "/tmp/match.tmp"
		let cmd = "ls ", path clipped,"/", mask clipped, " > ", 
			filename clipped," 2>/dev/null"
		run cmd

		whenever error continue
		drop table tmp_tmp
		whenever error stop
		
		create temp table tmp_tmp ( text_line char(180) )

	if db_dialect() = 4 then #POSTGRES
		display "Performing PostgreSQL compatible load"
		#Informix 4GL has a problem with this:
		load from filename delimiter "\n" insert into tmp_tmp
		#Invalid delimiter. Do not use '\\' or hex digits (0-9, A-F, a-f).
		let done_load = 1
	end if	
		
	if db_dialect() = 5 then # SQLITE
		display "Performing PostgreSQL compatible load"
		#Informix 4GL has a problem with this:
		load from filename delimiter "\n" insert into tmp_tmp
		#Invalid delimiter. Do not use '\\' or hex digits (0-9, A-F, a-f).
		let done_load = 1
	end if	
	if db_dialect() = 1 then #INFORMIX
		display "Performing Informix compatible load"
		#This works fine on Informix, but fails on PostgreSQL with:
		#Database error ('COPY delimiter must be a single character' in line 166.).
		load from filename delimiter "" insert into tmp_tmp
		let done_load = 1
	end if
	
	if done_load = 0 then
		display "Load was not performed because database type could not be determined" 
		exit program (1)
	
	end if
	
	
		select count(*) into cnt from tmp_tmp
		
		#must be 1 since there is only one 4gl file in this directory
		if cnt = 1 then 
			exit program (0)
		else
			display cnt, " rows found in file"
			exit program (1)
		end if

end main

function db_dialect()
define DIALECT char (20)

	initialize DIALECT to null
	
	#A4GLSQL_dbms_name() Returns name/description of the currently connected DBMS
	#A4GLSQL_dbms_dialect() return  a char string, eg. "INFORMIX", "ORACLE", "SAPDB"
	
	#need forward function in libaubit4gl, aclfgl_dbms_dialect()
	--! let DIALECT = dbms_dialect() 
	
	if DIALECT is not null then
	
		case DIALECT
			when "INFORMIX"
				return 1 #Informix
			
			when "ORACLE"
				return 2
			
			when "SAPDB"
				return 3
			
			when "POSTGRESQL"
				return 4
			
			when "SQLITE"
				return 5
			otherwise
				error "Cannot determine SQL DIALECT based on ",DIALECT clipped
				return 0 #unknown
		end case
	else
	{! 
		display "Call to aclfgl_dbms_dialect returned null."
		return 0
	!}
		#For all compiler other then Aubit, return 1 (Informix)
		return 1
	
	end if


end function


