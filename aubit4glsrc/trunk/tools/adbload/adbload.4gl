#
#   adbload.4gl
#
# Load SQL schemma generated with dbschemma/dbexport and create database
# Load data exported with dbexport and insert it in database
#
#This is a4gl specific code; it will not compile with other 4gl compilers

#Fuctions list:
#   file2array
#   process_array
#   create_table
#   fopen
#	readoneline(p_fileid)
#   params()
#   myshowhelp()
#

#include needed for c functions:
code
#include <stdio.h>
endcode

#######
globals
#######
    define
        a_load array [1000] of record
			oneline char (200)
		end record,
        a_load_size,
        a_load_full,
		do_debug,
        loadonly,
        testfortable,
        verbose,
        dropalltables
			smallint,
		target_db
            char (3),
        load_db_name,
        uname,
        passwd,
        dbexportname
            char (30)

###########
end globals
###########


####
main
####
define
    sqlfile
        char (300)
        #prepare cmd from "create database dbname"
        #display status
        #execute cmd #core dump here


    let a_load_size = 1000
	let do_debug = false
    let verbose = true
    let loadonly = false
    let testfortable = false
    let dropalltables = true

	call params()

    #ERROR command is causing "press any key..." in Aubit 4gl
#    display "testing"

	let sqlfile = dbexportname clipped,
					".exp/",
					dbexportname clipped,
					".sql"

    display "SQL schemma file in ",sqlfile clipped


	if file2array(sqlfile) then
		if process_array() then
			display "Process success"
        else
			display "Error processing"
    	    exit program
        end if
    else
		display "Error opening File"
    end if


end main



###############################
function file2array(p_filename)
###############################
	DEFINE
		p_filename CHAR(128),
		p_mode CHAR(5),
		p_fileid,
		lv_file,
		cnt
			INTEGER,
        dummy
            char(200),
        lineskip,
        tmplen
            smallint



	let p_mode = "r"

	let p_fileid = fopen(p_filename,p_mode)

	if p_fileid = 0 then
        return false
	end if

    let a_load_full = 0
    let lineskip = false
    ##########################
    for cnt = 1 to a_load_size
    ##########################
        if not lineskip then
			let dummy = readoneline(p_fileid)
            if dummy is null then
                exit for
            end if
			let tmplen = length(dummy)
            let dummy = dummy [1,tmplen-1]
            if  tmplen > 1 then
	            #display "LEN=",tmplen,"=", ">", dummy clipped, "<"
                #display ">", dummy clipped, "<"
				let a_load_full = a_load_full + 1
				let a_load[a_load_full].oneline = dummy clipped
			    if
                    do_debug
                then
					display a_load[a_load_full].oneline
                end if
			end if
            #let lineskip = true
        else
			#let dummy = readoneline(p_fileid)
            #let lineskip = false
        end if



	#######
	end for
    #######

    if
        loadonly
    then
        exit program
    end if

    if a_load_full > 0 then
	    display "loaded ",a_load_full, " lines...."
		return true
    else
        return false
    end if


end function #file2array()


########################
function process_array()
########################
define
    cnt,
    first_line
        smallint,
    p_systables record
		tabname              char(18),
		owner                char(8) ,
		partnum              integer,
		tabid                integer,	#serial,
		rowsize              smallint,
		ncols                smallint,
		nindexes             smallint,
		nrows                integer,
		created              date,
		version              integer,
		tabtype              char(1),
		locklevel            char(1),
		npused               integer,
		fextsize             integer,
		nextsize             integer,
		flags                smallint,
		site                 char(18),
		dbname               char(18)
    end record,
    SQLcmd
        char (300)


    ##############
    case target_db
    ##############


        when "IFX"
		    #database Informix7 #bad stores7
		    #database maindb #OK maindb in Informix

			#database aubittestifmx #OK, empty
			#I need to use load_db_name variable here:
			display "Connecting to Informix database DNS", load_db_name clipped

			database load_db_name

#            database _variable(load_db_name)
#|___________________^
#| Error at line 223, character 21
#| parse error ()


			display "Connected Informix database DNS", load_db_name clipped

		when "PG"
		    #database ptest #bad - we cannot
		    #use DABASE command for both because username/password
		    #in $SQLPASS and $SQLUSER

			display "Connecting to PostgreSQL database DNS ", load_db_name clipped
			display "using username ", uname clipped, " password ", passwd clipped

code
	trim(uname);
	trim(passwd);
endcode

open session s_id1 to database load_db_name AS USER uname PASSWORD passwd


			#OPEN SESSION s_id1 TO DATABASE ptest as user "postgres" password "pg"
			#OPEN SESSION s_id1 TO DATABASE load_db_name as user uname password passwd
            #OPEN SESSION s_id1 TO DATABASE load_db_name as user "postgres" password "pg"
            #OPEN SESSION s_id1 TO DATABASE ptest  as user uname password passwd

            #cause "error compiling":
#			OPEN SESSION s_id1 TO DATABASE _variable(load_db_name) as user _variable(uname) password _variable(passwd)

#            OPEN SESSION s_id1 TO DATABASE _variable(load_db_name) as user _variable(uname) password _variable(passwd)
#|_________________________________________^
#| Error at line 248, character 43
#| parse error ()

			SET SESSION TO s_id1

			display "Connected to PostgreSQL database ", load_db_name clipped
        otherwise
            error "no target db specified"
            exit program
    ########
	end case
    ########



    if
        dropalltables
    then
        if
            target_db = "IFX"
        then
            prepare S1 from "select * from systables"
            declare C1 cursor for S1

            let cnt = 0
			foreach C1 into p_systables.*
                if
                    p_systables.tabname[1,3] <> "sys"
                    and
                    p_systables.tabname[1] <> " "
                then
                    let cnt = cnt + 1
                    #drop table p_systables.tabname
                    let SQLcmd = "drop table ", p_systables.tabname clipped
					display SQLcmd clipped
					prepare S2 from SQLcmd
        		    declare C2 cursor for S2
#                    execute C2 #core dump here

                end if
            end foreach
            if cnt = 0 then
                display "no tables to drop"
            else
                display cnt, " tables dropped"
				exit program
            end if
        end if
	end if



    ##########################
	for cnt = 1 to a_load_full
    ##########################
		#display a_load[cnt].oneline clipped
        #display cnt, length(a_load[cnt].oneline), a_load[cnt].oneline clipped

#        continue for

        if length(a_load[cnt].oneline) = 0 then
            continue for
        end if

        if a_load[cnt].oneline[1,5] = "grant" then
		#grant dba to "informix";
            #display "grant line"
			continue for
		end if

        if a_load[cnt].oneline[1] = "{" then
		# TABLE "informix".cc_type row size = 24 number of columns = 2 index size = 12
		# unload file name = cc_ty00100.unl number of rows = 4
			#display "Load instructions line"

			if a_load[cnt].oneline not matches "*}*" then
				while true
					let cnt = cnt + 1
					if a_load[cnt].oneline matches "*}*" then
	                    #display "Load instruction section ends."
	                    exit while
	                end if
	            end while
            end if
			continue for
        end if

        if a_load[cnt].oneline[1,12] = "create table" then
		#create table "informix".cc_type
		#  (
		#    cc_type_code serial not null ,
		#    cc_type_name char(20) not null
		#  );
			#display "Create table section starts..."

            let first_line = cnt
            while true
				let cnt = cnt + 1
				if a_load[cnt].oneline matches "*);*" then
                    #display "Create table section ends."
                    exit while
                end if
            end while

            call create_table(first_line,cnt)

            continue for
        end if



        if a_load[cnt].oneline[1,6] = "revoke" then
		#revoke all on "informix".cc_type from "public";
			#display "Revoke line"
            continue for
        end if

        if a_load[cnt].oneline[1,13] = "create unique" then
		#create unique cluster index "informix".xpkcc_type on "informix"
			#display "Create unique index line"

            while true
				let cnt = cnt + 1
				if a_load[cnt].oneline matches "*);*" then
                    #display "Create unique index ends."
                    exit while
                end if
            end while
			continue for
        end if

        if a_load[cnt].oneline[1,12] = "create index" then
		#create unique cluster index "informix".xpkcc_type on "informix"
			#display "Create index line"

            while true
				let cnt = cnt + 1
				if a_load[cnt].oneline matches "*);*" then
                    #display "Create index ends."
                    exit while
                end if
            end while
			continue for
        end if


        display "What? "
		display cnt, length(a_load[cnt].oneline), a_load[cnt].oneline clipped


    #######
    end for
    #######


    return true

end function #process_aray()


########################################
function create_table(first_line,last_line)
########################################


define
    last_line,
    cnt,
    first_line,
    tmplen,
    startchar,
    endchar,
    tmpstat
        smallint,
    SQLcmd,
    testSQL
        char (10000),
    tablename
        char (60)




	initialize SQLcmd to null

    #################################
	for cnt = first_line to last_line
    #################################

        let SQLcmd = SQLcmd clipped, a_load[cnt].oneline clipped

    #######
    end for
    #######

    #display SQLcmd clipped

    #get table name
    let tmplen = length (SQLcmd)
    let startchar = 0

    #####################
	for cnt = 1 to tmplen
    #####################

        if SQLcmd[cnt] = "." then
            let startchar = cnt
        end if

        if startchar > 0 then
	        if SQLcmd[cnt] = " " then
	            let endchar = cnt
                let tablename = SQLcmd[startchar+1, endchar]
                exit for
	        end if
        end if

    #######
    end for
    #######

    display "Creating table ", tablename clipped

#    exit program

    if
        testfortable
    then


		#I'm investigating the whenever error problem -
		#for now - if you use :
		#	whenever any error continue
		#	whenever sqlerror continue
		#	whenever error continue
		#######################
		whenever any error continue
		whenever sqlerror continue
		whenever error continue
	    #######################
			let testSQL = "select * from ",tablename clipped
	        display "before prepare"
	        prepare cmd from testSQL
	        let status = 0
			display "status = ", status
	        execute cmd
	        let tmpstat = status
	        display "tmpstat=", tmpstat
	        let status = 0
	    ###################
	#	whenever error stop
	#	whenever error continue
	    ###################

	    display tmpstat

	    if tmpstat = 0
		then
			#display "table exists..."
	        return
	    end if

	#    exit program

    end if

    if
        do_debug
        or
        verbose
    then
        display SQLcmd clipped
    end if

    prepare cmd from SQLcmd

	execute cmd

    free cmd

#    exit program

end function #create_table()

##################
function params()
##################
define
    cnt,
    arglen
        smallint,
	ARGUMENT
			ARRAY[8] OF CHAR (80),
    ArgumentString,
    ARGUMENTstringUP
        char (80),
	prg_name
        char(20),
    g_msg
        char (100)

    #let prg_name = ARG_VAL(0)

    if
		NUM_ARGS() = 0
    then
        #return
        call myshowhelp()
        exit program
    end if

    initialize
		load_db_name,uname,passwd,target_db,dbexportname
        	to null

    initialize load_db_name to null
	initialize uname to null
	initialize passwd to null
	initialize target_db to null



	############################
	FOR cnt = 1 TO NUM_ARGS()
	############################

		LET ARGUMENT[cnt] = ARG_VAL(cnt)

		#IF
		#	ARGUMENT[cnt] IS NOT NULL
		#THEN
		#	LET ARGUMENTstring = UPSHIFT(ARGUMENT[cnt])
		#END IF

		LET ARGUMENTstring = ARGUMENT[cnt]
		LET ARGUMENTstringUP = UPSHIFT(ARGUMENT[cnt])

		let arglen = length(ARGUMENTstring)

        ####
        case
        ####
			when ARGUMENTstringUP = "-H" or ARGUMENTstringUP = "--H"
	            or ARGUMENTstringUP = "-HELP" or ARGUMENTstringUP = "--HELP"

				call myshowhelp()
		        exit program

			when ARGUMENTstringUP = "-examples"
				call show_examples()
		        exit program


#not working!!!!!
#			when UPSHIFT(ARGUMENTstring) = "PG"
			when ARGUMENTstringUP = "PG"
				let target_db="PG"

			when ARGUMENTstringUP = "IFX"
				let target_db="IFX"

			when ARGUMENTstringUP = "LOADONLY"
				let loadonly=true

			when ARGUMENTstringUP = "DEBUG"
                let do_debug = true
                    error "DEBUG MODE ON"
                    sleep 2

			when ARGUMENTstring[1,2] = "-D" or ARGUMENTstring[1,2] = "-d"
                let load_db_name = ARGUMENTstring[3,arglen]

			when ARGUMENTstring[1,2] = "-U" or ARGUMENTstring[1,2] = "-u"
				let uname = ARGUMENTstring[3,arglen]

			when ARGUMENTstring[1,2] = "-P" or ARGUMENTstring[1,2] = "-p"
				let passwd  = ARGUMENTstring[3,arglen]

			when ARGUMENTstring[1,2] = "-E" or ARGUMENTstring[1,2] = "-e"
				let dbexportname  = ARGUMENTstring[3,arglen]


            #########
			otherwise
            #########
                let g_msg = "Argument #", cnt using "&", " not recognised: ",
                    ARGUMENTstring clipped

                #error g_msg clipped
                display g_msg clipped

		########
		end case
        ########

	#######
	END FOR
	#######

#    display "all",
#		load_db_name,uname,passwd,target_db

{is null test is ignored: bug!!
    case
        when load_db_name is null
            display "Load database name not specified"
            display " "
            call myshowhelp()
            exit program

		when uname is null
            display "User name not specified"
            display " "
            call myshowhelp()
            exit program

		when passwd is null
            display "Password not specified"
            display " "
            call myshowhelp()
            exit program

		when target_db is null
            display "Target database type  not specified"
            display " "
            call myshowhelp()
            exit program

	end case
}

#if load_db_name = null then
#if load_db_name is null then
if length(load_db_name) < 1 then
            display "Load database name not specified"
            display " "
            call myshowhelp()
            exit program
end if

if length(uname) < 1 then
            display "User name not specified"
            display " "
            call myshowhelp()
            exit program
end if

if length(passwd) < 1 then
            display "Password not specified"
            display " "
            call myshowhelp()
            exit program
end if
if length (target_db) < 1 then
            display "Target database type  not specified"
            display " "
            call myshowhelp()
            exit program
end if

if length (dbexportname) < 1 then
            display "dbexport directory name not specified"
            display " "
            call myshowhelp()
            exit program
end if

end function #params()


####################
function myshowhelp()
####################

    display " "
    display "adbload - Aubit 4gl database schemma and data load/unload utillity"
    display " "
    display "Options:"
    display " "
	display "PG 		- target database is PostgreSQL"
	display "IFX		- targer database is Informix"
	display "LOADONLY 	- load SQL schemma only, no actions performed"
	display "SCHEMMAONLY- just create schemma"
	display "VERBOSE 	- dipslay all operations as performed"
	display "DEBUG 		- display additional debugging messages"
    display " "
    display "Parameters:"
    display " "
    display "	-d<dbname>	- database name/ODBC DNS name to load to"
    display " 	-u<username>- username used to connect to database/DNS"
    display " 	-p<password>- pasword used to connect to database/DNS"
    display " 	-e<dbexport>- directory created by IFX dbexport utility"
    display " 	-f<filename>- .unl file to load"
    display " 	-t<tablename>- table to load .unl file to"
    display " 	-s<filename>- .sql file containing schemma"
    display " 	-l<delimiter>- character used as delimiter in -f file"
	display " "
	display " Use 'adbload -examples' to see command parameter and options examples"
	display " "

end function #showwhelp()

#########################
function show_examples()
#########################

	display " "
    display "adbload - Aubit 4gl database schemma and data load/unload utillity"
    display " "
    display "Examples:"
    display " "
    display "   adbload PG -dptest -upostgres -ppg -ecm"
	display " "
	display " will load dbexport result of database 'cm' into Postgres"
	display " database 'ptest' (that you previously created) using username 'postgres'"
	display " and pasword 'pg' to connect."
	display " "
    display "   adbload PG -dptest -upostgres -ppg -scm.sql SCHEMMAONLY"
	display " "
	display " will create database structure from file 'cm.sql' in Postgres"
	display " database 'ptest' (that you previously created) using username 'postgres'"
	display " and pasword 'pg' to connect."
	display " "
    display "   adbload PG -dptest -upostgres -ppg -ftest.unl -tmytab "
	display " "
	display " will load data from file 'test.unl' in table 'mytab' in Postgres"
	display " database 'ptest' (that you previously created) using username 'postgres'"
	display " and pasword 'pg' to connect."
	display " "
	display " "
	display " Use 'adbload -help' to see all command parameter and options help"
	display " "

end function #show_examples()


#####################################################################
#
# WARNING: keep functions with embedded c code at the end of souce code!
#
#####################################################################

#################################
FUNCTION fopen(p_filename,p_mode)
#################################
    DEFINE
		p_filename CHAR(128),
		p_mode CHAR(5),
		p_fileid,
		lv_file
			INTEGER

    initialize p_fileid, lv_file to null

code
        trim(p_filename); // library function to remove trailing spaces
        trim(p_mode);
        p_fileid=fopen(p_filename,p_mode);
//		lv_file=(long)fopen(p_filename,p_mode);

endcode

    RETURN p_fileid

END FUNCTION #fopen()


###############################
function readoneline(p_field)
###############################
define
	p_field,
	EOF
		integer,
    tmpbuf char(200)

	initialize tmpbuf to null

code
        while (1)
                {
/*
On CygWin, feof is a macro:
# 162 "/usr/include/stdio.h" 3
int __attribute__((__cdecl__)) feof (FILE *);

So this will become:
        r=(((handle)->_flags & 0x0020) != 0);
line 1631

and cause:
libfile.c: In function `aclfgl_feof':
libfile.c:703: invalid type argument of `->'
*/

				#ifdef __CYGWIN__
			        printf("FIXME: don't know what to do with feof() on CygWin\n");
                    break;
				#else
					if (feof(p_field)) break;
                	fgets(tmpbuf,200,p_field); break;
                #endif
                }

endcode

#	display "xx",tmpbuf

	return tmpbuf

end function


############################# EOF ############################

