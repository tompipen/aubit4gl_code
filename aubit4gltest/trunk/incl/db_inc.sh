
##############################################################################
#                Functions related to database support
##############################################################################

###############################################################
#Check if we need to switch transaction logging mode in RDBMS
###############################################################
function check_trans_mode () {

		if test "$DB_HAS_TRANSACTION" != "NULL" ; then 
			if test "$NEED_TRANSACTION" = "1" -a "$DB_HAS_TRANSACTION" != "1" ; then
				#need to switch logging mode
				if test "$IFX_ENG_REMOTE" != "1"; then
					if test "$USE_ESQLI" = "1" -o "$ODBC_USE_DB" = "IFX"; then		
						if test "$VERBOSE" = "1"; then
							ontape -s -B $TEST_DB
							RET=$?
							echo "NOTE: turned ON buffered logging"
						else
							ontape -s -B $TEST_DB > /dev/null
							RET=$?
						fi
						if test "$RET" != "0"; then 
							echo "ERROR: swithching logging mode ON failed"
							exit $RET
						fi
						DB_HAS_TRANSACTION="1"
					else
						#Don't know how to turn on transactions for this RDBMS			
						SKIP_REASON="needs transaction support, but current database don't have it and I don't know how to turn them on"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 23"
					fi
				else
					if test "$IGNORE_CANT_SWITCH_TRANS" = "1" ; then
						if test "$VERBOSE" = "1"; then
							echo "WARNING: $TEST_NO explicit preference for transactions, but DB" >> $LOGFILE
							echo "WARNING: engine is remote so cant swithch logging mode" >> $LOGFILE		
						fi
					else
						SKIP_TRANS_LIST="$SKIP_TRANS_LIST $TEST_NO"
						SKIP_REASON="explicit preference for transactions, but DB engine is remote"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 24"
					fi
				fi
			fi

			if test "$NEED_TRANSACTION" = "2" -a "$DB_HAS_TRANSACTION" = "1"; then
				#need to switch logging mode
				if test "$IFX_ENG_REMOTE" != "1"; then				
					if test "$USE_ESQLI" = "1" -o "$ODBC_USE_DB" = "IFX"; then		
						if test "$VERBOSE" = "1"; then
							ontape -s -N $TEST_DB
							RET=$?
							echo "NOTE: turned OFF logging"
						else
							ontape -s -N $TEST_DB > /dev/null
							RET=$?
						fi
						if test "$RET" != "0"; then 
							echo "ERROR: swithching logging mode OFF failed"
							exit $RET
						fi
						DB_HAS_TRANSACTION="0"				
					else
						#Don't know how to turn off transactions for this RDBMS
						SKIP_REASON="MUST NOT have transaction support, but current database have it and I don't know how to turn them off"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 25"
					fi
				else
					if test "$IGNORE_CANT_SWITCH_TRANS" = "1" ; then
						if test "$VERBOSE" = "1"; then
							echo "WARNING: $TEST_NO explicit preference for transactions, but DB" >> $LOGFILE
							echo "WARNING: engine is remote so cant swithch logging mode" >> $LOGFILE
						fi
					else
						SKIP_TRANS_LIST="$SKIP_TRANS_LIST $TEST_NO"					
						SKIP_REASON="explicit preference for transactions, but DB engine is remote"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 26"
					fi
				fi
			fi
		else
			if test "$NEED_TRANSACTION" = "1" -o "$NEED_TRANSACTION" = "2" ; then
				if test "$SKIP_UNKNOWN_TRANS" != "1" ; then
					if test "$VERBOSE" = "1"; then
						echo "WARNING: $TEST_NO explicit preference for transactions, but unable to determine state" >> $LOGFILE
					fi
				else
					SKIP_TRANS_LIST="$SKIP_TRANS_LIST $TEST_NO"
					SKIP_REASON="explicit preference for transactions, but unable to determine state"
					SKIP_REASON_CODES="$SKIP_REASON_CODES 27"
				fi
			fi
		fi
}


###############################################################
#
###############################################################
function count_rows () {
tablename=$1
dbname=$2

	SQL="select count(*) from $tablename"
	CNT=`echo "$SQL" | $DBACCESS $dbname 2>/dev/null | grep -v count`
	#Trim it:
	CNT=`echo $CNT`
}

###############################################################
#
###############################################################
function drop_db () {
db_name=$1

        echo "Droping Informix database $db_name"
        $DBACCESS - - > /tmp/dropdbtmp.log 2>&1 <<!
        drop database '$db_name'
!
        RET=$?
        if test "$RET" != "0"; then
			echo "Failed (code $RET). See /tmp/dropdbtmp.log"
            exit 2
        else
    	    echo "Droped Informix database $db_name"
        fi
}

###############################################################
#
###############################################################
function create_db () {
new_db=$1	
	
		echo "Creating Informix database $new_db"
        $DBACCESS - - > /tmp/credbtmp.log 2>&1 <<!
        create database '$new_db' with log
!
        RET=$?
        if test "$RET" != "0"; then
            echo "Failed (code $RET). See /tmp/credbtmp.log"
            exit 19
        else
            TMPrr=`cat /tmp/credbtmp.log | grep "Database created"`
            if test "$TMPrr" != ""; then
                echo "Database $new_db Created"
            else
                echo "Database creation failed. See /tmp/credbtmp.log"
                exit 8
            fi
        fi
}

###############################################################
#
###############################################################
function test_db_exist () {
test_db=$1

	if test "$DBACCESS" = ""; then 
		echo "ERROR: DBACCESS not defined. Stop."
		exit 5
	fi

	$DBACCESS $test_db -e > /tmp/tmp.dbaccess 2>&1
	RET=$?
   	TEST=`cat /tmp/tmp.dbaccess | sed -e 's/OOPS//g' | grep Databasenotfoundornosystempermission`
	
	#echo $RET
	#echo $TEST

}	

###############################################################
#
###############################################################
function check_informix () {
	if test "`dbaccess -V 2>/dev/null`" = ""; then
		if test "$VERBOSE" = "1" ; then	
	    	echo "WARNING: dbaccess not found - Informix engine missing or remote?"
		fi
		#CSDK on Windows does not include ANY command line tools :-(
		if test "`$SH aubit asql_i.4ae -V 2>/dev/null`" = ""; then
			if test -d "$AUBITDIR_SRC/tools/asql"; then 
				USE_SRC=$AUBITDIR_SRC
			else
				if test -d "$AUBITDIR_UNIX/tools/asql"; then 
					USE_SRC=$AUBITDIR_UNIX
				fi
			fi
			if test "$USE_SRC" != ""; then
				make -C $USE_SRC/tools/asql asql_i.4ae
				make -C $USE_SRC/tools/asql install
				if test "`$SH aubit asql_i.4ae -V 2>/dev/null`" = ""; then
					echo "Attempt to make asql_i failed. Stop"
					exit 56
				else
					IFX_ENG_REMOTE=1
					DBACCESS="$SH aubit asql_i.4ae"
				fi
			else
				echo "ERROR: missing asql_i.4ae and can't determine SRC dir. STOP"
				exit 1
			fi
		else
			IFX_ENG_REMOTE=1
			DBACCESS="$SH aubit asql_i.4ae"
		fi
	else
		IFX_ENG_REMOTE="unknown"
		DBACCESS=dbaccess	
    fi

	if test "$DBACCESS" = "$SH aubit asql_i.4ae"; then
		if test "$A4GL_UI" = "HL_TUIN"; then 
			echo "WARNING: Cant use asql with HL_TUIN: Function Not found : UILIB_A4GL_current_window"
			#we are uisng it in command line mode anyway...
			#exit 3
		fi
	fi
	
	test_db_exist $TEST_DB

	if test "$NEW_IFMX" = "1" -a "$TEST" = ""; then
		drop_db $TEST_DB
    fi

    if test "$TEST" != "" || test "$NEW_IFMX" = "1"; then
		create_db $TEST_DB
		new_testdb informix
    else
		#if test "$NO_ECHO" != "1"; then
		if test "$VERBOSE" = "1"; then
			echo "Found Informix database $TEST_DB"
        fi
		SQL="select is_logging from sysdatabases where name = '$TEST_DB'"
        DB_HAS_TRANSACTION=`echo "$SQL" | $DBACCESS sysmaster 2>/dev/null | grep -v is_logging`
		#Trim it:
		DB_HAS_TRANSACTION=`echo $DB_HAS_TRANSACTION`
		if test "$VERBOSE" = "1" ; then
			echo "DB_HAS_TRANSACTION=$DB_HAS_TRANSACTION"		
			if test "$DB_HAS_TRANSACTION" != "1" -a "$DB_HAS_TRANSACTION" != "0"; then 
				echo "WARNING: failed to determine Informix database transaction support state"
			fi
		fi
    fi
	if test "$USEERNAME" != "informix" -a "$VERBOSE" = "1"; then
		echo "WARNING: you are not logged in as Informix super user (informix) but"
		echo "WARNING: as $USERNAME - make sure you have sufficient permisions"
		echo "WARNING: to execute 'ontape' utility program (for switching logging mode)"
	fi
	if test "$INFORMIXDIR" != "" -a "$ONCONFIG" != ""; then 
		if test -f "$INFORMIXDIR/etc/$ONCONFIG"; then 
			LTAPEDEV_LINE=`grep LTAPEDEV "$INFORMIXDIR/etc/$ONCONFIG"`
			if test "$LTAPEDEV_LINE" != ""; then 
				LTAPEDEV_VALUE=`echo $LTAPEDEV_LINE | grep null`
				if test "$LTAPEDEV_VALUE" = ""; then
					echo "WARNING: in Informix config file $INFORMIXDIR/etc/$ONCONFIG"			
					echo "WARNING: $LTAPEDEV_LINE"
					echo "WARNING: should be 'LTAPEDEV=/dev/null')"
					echo "WARNING: switching transaction logging mode will probably fail"
				fi
			else
				echo "WARNING: Informix config file $INFORMIXDIR/etc/$ONCONFIG"
				echo "WARNING: does not contain LTAPEDEV setting"
				echo "WARNING: should be 'LTAPEDEV=/dev/null')"
				echo "WARNING: switching transaction logging mode will probably fail"
			fi
		else
			echo "WARNING: cannot find file $INFORMIXDIR/etc/$ONCONFIG"
			echo "WARNING: cannot check value of LTAPEDEV (should be '/dev/null')"			
		fi
	else
		echo "WARNING: INFORMIXDIR and/or ONCONFIG are empty"
		echo "WARNING: cannot check value of LTAPEDEV (should be '/dev/null')"
	fi
	
	#TODO: determine actual DB_TYPE
	#DB_TYPE="IFX-SE"
	DB_TYPE="IFX-OL"
	
	
    if test "$NEW_IFMX" = "1"; then
        exit
    fi
}


###############################################################
#
###############################################################
function check_postgresql () {
	if test "$VERBOSE" = "1"; then 
		echo "PostgreSQL specified (2: PLSQL=$PSQL)"
	fi
	if test "`$PSQL -V 2>/dev/null`" = ""; then
        echo "ERROR: $PSQL not found - no PostgreSQL engine?"
        exit 67
    fi

	#Find PostgreSQL data directory of currently running PG engine (PGDATA)
	if test "$PGDATA" = ""; then
		if test "$COMSPEC" = ""; then #On UNIX 
			#su -l postgres -s /bin/sh -c "$POSTGRES_BIN/pg_ctl -D $PGDATA status"
			#We need wide output to get full command line:
			PG_LINE=`ps -auxw 2>/dev/null| grep postmaster | head -n 1`
			if test "$PG_LINE" = ""; then			
				verbose "trying 'ps -efw' because 'ps -auxw' did not work"
				PG_LINE=`ps -efw | grep postmaster | head -n 1 `
			fi
			if test "$PG_LINE" != ""; then
				for x in $PG_LINE; do
					#echo $x
					case $x in
						*postmaster)
							POSTMASTER_EXE=$x
						;;
						port=*)
							PG_PORT=`echo $x | sed 's/=/ /' | awk '{print $2}'`
						;;
						*)
							if test -d "$x" ; then
								PGDATA=$x
							else
								HH=`ls $x 2>&1 | grep "Permission denied"`
								if test "$HH" != ""; then 
									verbose "$x exists, but user dont have sufficient rights to access it"
									PGDATA=$x
									PGDATA_NOACCESS=1
								fi
							fi
						;;
					esac
				done
				if test "$POSTMASTER_EXE" = ""; then
					verbose "cant get postmaster name out of ps line"
				fi
				if test "$PGDATA" = ""; then
					verbose "cant get PG data dir name out of ps line"
				fi
				verbose "$POSTMASTER_EXE $PGDATA $PG_PORT $PGDATA_NOACCESS"
				PG_CREATEDB="$POSTGRES_BIN/createdb"
				PG_DROPDB="$POSTGRES_BIN/dropdb"
				if test "$PG_PORT" != ""; then
					#PG_PORT is sed by SQL_pg plug-in too:
					export PG_PORT
					
					
					#Note: for same purpose ecpg uses this too:
					#export PG_DBPATH=dbname[@server][:port]
					#This will override any DATABASE statements in the .cpc (This is part of ecpg
					#- not aubit4gl)
					#see the sourcecode - I found some :
					#http://jonathangardner.net/PostgreSQL/doxygen/7.4/connect_8c-source.html
					PG_DBPATH="$TEST_DB@localhost:$PG_PORT"
					export PG_DBPATH
					
					PSQL="$PSQL -p $PG_PORT"
					PG_CREATEDB="$POSTGRES_BIN/createdb --port=$PG_PORT"
					PG_DROPDB="$PG_DROPDB --port=$PG_PORT"
				fi

				if test "$POSTMASTER_EXE" != ""; then 
					if test "$PG_LOCATION" != ""; then 
						if test "$POSTMASTER_EXE" != "$PG_LOCATION/bin/postmaster"; then
							echo "ERROR: $POSTMASTER_EXE != $PG_LOCATION/bin/postmaster"
							echo "It seems you are running a different postmaster from the"
							echo "one you specified with -pg-inst !!"
							exit 5
						fi
					fi
				fi
			else 
				verbose "Cant get anything out of ps -auxw or ps -efw"
				verbose "postmaster probably not running?"
			fi
			
			if test "$PGDATA" = ""; then
				#This apparently works in PG8, but not in 7.4			
				PGDATA=`$PSQL -U postgres -d template1 -c "show data_directory;"  2>/dev/null | tail -n 3 | grep -v row`
			fi
			
			if test "$PGDATA" = ""; then 
				echo "WARNING: PostgreSQL not running or started without -D flag"
				echo "(using PGDATA, but no PGDATA present in environment)"
				echo "ps -ef | grep postmaster"
				ps -ef | grep postmaster
				echo "ps -auxw | grep postmaster"
				ps -auxw | grep postmaster
			else
				if test ! -d "$PGDATA"; then
					#see if it exists, but we dont have rights to stat it:
					HH=`ls $PGDATA 2>&1 | grep "Permission denied"`
					if test "$HH" != ""; then 
						verbose "$PGDATA exists, but user dont have sufficient rights to access it"
						PGDATA_NOACCESS=1
					else
						#One dir up:
						GG=`dirname $PGDATA`
						HH=`ls $GG 2>&1 | grep "Permission denied"`
						if test "$HH" != ""; then 
							verbose "$PGDATA seems to exists, but user dont have sufficient rights to access it"
							PGDATA_NOACCESS=1
						fi
					fi
					if test "$PGDATA_NOACCESS" != "1"; then
						echo "WARNING: PGDATA obtained from postmaster flags is not a directory ($PGDATA)"
						unset PGDATA
						#try guessing
						if test -d "/var/lib/pgsql/data"; then
							#RedHat RPM's
							PGDATA="/var/lib/pgsql/data"
						fi
						if test -d "/usr/local/pgsql/data"; then
							#PG default
							PGDATA="/usr/local/pgsql/data"
						fi
						if test -d "/usr/local/pgsql/data-7.4"; then
							#Andrej
							PGDATA="/usr/local/pgsql/data-7.4"
						fi
						if test ! -d "$PGDATA"; then
							echo "WARNING: unable to set PGDATA"
							echo "Please set PGDATA manually."				
						else
							if test "$VERBOSE" = "1"; then 
								echo "PGDATA set to $PGDATA"
							fi
						fi
					fi
				else
					if test "$VERBOSE" = "1"; then 
						echo "PGDATA set to $PGDATA"
					fi
				fi
			fi
		else #On Windows
			POSTGRESDIR_LIB="`cygpath -u "$POSTGRESDIR"`/lib"
			#echo $POSTGRESDIR_LIB
			export PATH="$POSTGRESDIR_LIB:$PATH"

			#On Windows, CygWin 'ps' has -W flag that is supposed to show 
			#Windows proceses including services, but it does not show
			#posmaster even when visible in Windows Services tool
			if test "$PGUSER_POSTGRES_PWD" = ""; then
				PGUSER_POSTGRES_PWD=`aubit-config PGUSER_POSTGRES_PWD`
			fi
			if test "$PGPASSWORD" = ""; then
				PGPASSWORD="`aubit-config PGPASSWORD`"
			fi
			if test "$PGPASSWORD" != ""; then
				PGUSER_POSTGRES_PWD="$PGPASSWORD"
			fi
			if test "$PGUSER_POSTGRES_PWD" != ""; then
				PGPASSWORD="$PGUSER_POSTGRES_PWD"
			fi
			if test "$PGUSER_POSTGRES_PWD" = ""; then
				echo "On Windows environment variable PGUSER_POSTGRES_PWD must be"
				echo "set to password for user 'postgres'. STOP."
				exit 4
			else
				#See http://www.redhat.com/docs/manuals/database/RHDB-2.1-Manual/prog/libpq-envars.html
				#For more info on variables accpted by libpq
				#
				#PGHOST sets the default server name. If this begins with a 
				#slash, it specifies Unix-domain communication rather than 
				#TCP/IP communication; the value is the name of the directory 
				#in which the socket file is stored (default "/tmp").
				#
				#PGPORT sets the default TCP port number or Unix-domain socket 
				#file extension for communicating with the Red Hat Database backend.
				#
				#PGDATABASE sets the default Red Hat Database database name.
				#
				#PGUSER sets the username used to connect to the database and for 
				#authentication.
				#
				#PGPASSWORD sets the password used if the backend demands password 
				#authentication.
				#
				#PGREALM sets the Kerberos realm to use with Red Hat Database, if it is 
				#different from the local realm. If PGREALM is set, Red Hat Database 
				#applications will attempt authentication with servers for this realm and use 
				#separate ticket files to avoid conflicts with local ticket files. This 
				#environment variable is used only if Kerberos authentication is selected by 
				#the backend.
				#
				#PGOPTIONS sets additional runtime options for the Red Hat Database backend.
				#
				#PGTTY sets the file or tty on which debugging messages from the backend server 
				export PGPASSWORD="$PGUSER_POSTGRES_PWD"
			
				#TODO: maybe we can use PGPASSWORD instead of 'echo $PGUSER_POSTGRES_PWD' ???
				
				#This apparently works in PG8, but not in 7.4				
				#WIN_PG_CONF=`echo $PGUSER_POSTGRES_PWD | $PSQL -U postgres -d template1 -c "show config_file;"  2>/dev/null | tail -n 3 | grep -v row`	
				#WIN_PGDATA=`echo $PGUSER_POSTGRES_PWD | $PSQL -U postgres -d template1 -c "show data_directory;"  2>/dev/null | tail -n 3 | grep -v row`
				WIN_PG_CONF=`$PSQL -U postgres -d template1 -c "show config_file;"  2>/dev/null | tail -n 3 | grep -v row`	
				WIN_PGDATA=`$PSQL -U postgres -d template1 -c "show data_directory;"  2>/dev/null | tail -n 3 | grep -v row`
				
				WIN_PGDATA=`echo $WIN_PGDATA`
				WIN_PG_CONF=`echo $WIN_PG_CONF`
				PG_CONF=`cygpath -u "$WIN_PG_CONF"`
				PGDATA=`cygpath -u "$WIN_PGDATA"`
				if test ! -d "$PGDATA"; then
					echo "ERROR: specified PGDATA ($PGDATA) is not a directory"
					exit 4
				fi
				if test ! -f "$PG_CONF"; then
					echo "ERROR: specified PG_CONF ($PG_CONF) is not a file"
					exit 4
				fi
				verbose "PGDATA set to '$PGDATA'"
				verbose "PG_CONF set to '$PG_CONF'"
			fi
		fi
	fi
	if test ! -d "$PGDATA"; then
		if test "$PGDATA_NOACCESS" != "1"; then	
			echo "WARNING: specified PGDATA ($PGDATA) is not a directory"
			unset PGDATA
		fi
	fi

	#Find current PostgreSQL configuration file in use by currently running
	#instance of PG engine (PG_CONF)
	if test "$PG_CONF" = ""; then
		if test "$PGDATA_NOACCESS" != "1"; then	
			if test -f "$PGDATA/postgresql.conf"; then 
				PG_CONF="$PGDATA/postgresql.conf"
			fi
		fi
		if test "$PG_CONF" = ""; then
			#This apparently works in PG8, but not in 7.4	
			#gives ERROR:  unrecognized configuration parameter "config_file"
			verbose "Running: $PSQL -U postgres -d template1 -c \"show config_file;\""
			PG_CONF=`$PSQL -U postgres -d template1 -c "show config_file;"  2>/dev/null | tail -n 3 | grep -v row`
			if ! test -f "$PG_CONF"; then		
				#seems like engine does not keep config file name (tried psql 'SHOW ALL;')
				#So only source of config file location is environment where postmaster
				#command was executed
				verbose "failed to determine PG config file location (PG_CONF=$PG_CONF)"
				if test "$PGDATA" != ""; then
					if test "$PGDATA_NOACCESS" != "1"; then
						if test "$VERBOSE" = "1"; then
							ls -al $PGDATA/*.conf
						fi
					fi
				fi
				PG_CONF="unknown"
			fi
		fi
	fi

	#if test "$COMSPEC" != ""; then 
	#	echo "$PGUSER_POSTGRES_PWD" | $PSQL -d $TEST_DB -c "\q;" > /tmp/tmp.dbaccess 2>&1
	#else
		$PSQL -d $TEST_DB -c "\q;" > /tmp/tmp.dbaccess 2>&1	
	#fi
	RET=$?
	if test "$RET" != "0"; then 
		echo "(37) $PSQL returned code $RET trying to connect to db $TEST_DB ."
		cat /tmp/tmp.dbaccess
		TEST=`cat /tmp/tmp.dbaccess | grep "could not connect to server"`
		if test "$TEST" != ""; then
			if test "$COMSPEC" = ""; then		
				#Try starting local PG engine
				#FIXME - only on SuSE
				rcpostgresql start
			fi
		else
			TMP4=`cat /tmp/tmp.dbaccess | grep "FATAL:  user"`
			if test "$TMP4" != ""; then
				check_pg_user_create
			fi
			TMP4=`cat /tmp/tmp.dbaccess | grep "FATAL:  password authentication failed for user"`
			if test "$TMP4" != ""; then
				check_pg_user_create
			fi
		#	echo "ERROR: unknown fault (1)"		
		#	exit $RET
		fi
		#Try connecting again
		#if test "$COMSPEC" != ""; then 
		#	echo "$PGUSER_POSTGRES_PWD" | $PSQL -d $TEST_DB -c "\q;" > /tmp/tmp.dbaccess 2>&1
		#else
			$PSQL -d $TEST_DB -c "\q;" > /tmp/tmp.dbaccess 2>&1	
		#fi
		RET=$?
		if test "$RET" != "0"; then 
			echo "(38) $PSQL returned code $RET trying to connect to db $TEST_DB ."
			cat /tmp/tmp.dbaccess
			TEST=`cat /tmp/tmp.dbaccess | grep "does not exist"`
			if test "$TEST" != ""; then
				echo "Will create database"
				NEW_PG=1
			else
				echo "ERROR: unknown fault (2)"
				exit $RET
			fi
		fi
	fi
   	TEST=`cat /tmp/tmp.dbaccess | grep "psql: FATAL"`
	if test "$NEW_PG" = "1" -a "$TEST" = ""; then
	    echo "Droping PostgreSQL database $TEST_DB"
		#if test "$COMSPEC" != ""; then 
		#	echo "$PGUSER_POSTGRES_PWD" | $PG_DROPDB $TEST_DB > /tmp/dropdbtmp.log
		#else
			$PG_DROPDB $TEST_DB > /tmp/dropdbtmp.log
		#fi
        #returns "DROP DATABASE" string on success
		RET=$?
        if test "$RET" != "0"; then
			echo "Failed (code $RET). See /tmp/dropdbtmp.log"
            exit 2
        else
    	    echo "Droped PostgreSQL database $TEST_DB"
        fi
    fi

    if test "$TEST" != "" -o "$NEW_PG" = "1"; then
        echo "Creating PostgreSQL database $TEST_DB"
		#createdb is a shell script wrapper around the SQL command
		#CREATE DATABASE via the PostgreSQL interactive terminal psql.
		#if test "$COMSPEC" != ""; then 
		#	echo "$PGUSER_POSTGRES_PWD" | $PG_CREATEDB $TEST_DB > /tmp/credbtmp.log 2>&1
		#else
			$PG_CREATEDB $TEST_DB > /tmp/credbtmp.log 2>&1
		#fi
        RET=$?
        if test "$RET" != "0"; then
			TMP4=`cat /tmp/credbtmp.log | grep "FATAL:  user"`
			if test "$TMP4" != ""; then
				check_pg_user_create
			else
	            echo "Failed (code $RET)."
				cat /tmp/credbtmp.log
				exit 29
			fi
        else
            TMPzz=`cat /tmp/credbtmp.log | grep "CREATE DATABASE"`
            if test "$TMPzz" != ""; then
                echo "Database Created"
            else
                echo "Database creation failed. See /tmp/credbtmp.log"
                exit 8
            fi
        fi

		echo "Creating tables and loading data..."
		new_testdb postgres
    else
		if test "$VERBOSE" = "1"; then
			echo "Found PostgreSQL database $TEST_DB"
        fi
    fi

    if test "$NEW_PG" = "1"; then
        exit
    fi

	#Get PG server version
	#if test "$COMSPEC" != ""; then
	#	PG_VERSION=`echo "$PGUSER_POSTGRES_PWD" | $PSQL -d $TEST_DB -c "show server_version;" 2>/dev/null | grep "\."`
	#else
		PG_VERSION=`$PSQL -d $TEST_DB -c "show server_version;" | grep "\."`
	#fi
	if test "$VERBOSE" = "1"; then 
		echo "INFO: PG server reported version $PG_VERSION"
	fi
	#Clip it:
	PG_VERSION=`echo $PG_VERSION`
	case $PG_VERSION in 
		7.4informix*) 	DB_TYPE="PG-IFX-74";;
		7.4*)			DB_TYPE="PG-74";;
		8*)				DB_TYPE="PG-80";;
		*)				DB_TYPE="PG-UNKNOWN";;
	esac
	if test "$VERBOSE" = "1"; then 
		info "DB_TYPE set to $DB_TYPE"
	fi
	
	#################
	#Tests to verify PG is configured as we need it for Informix
	#compatibility
	
	#if test "$COMSPEC" != ""; then 
	#	TMP=`echo "$PGUSER_POSTGRES_PWD" | $PSQL -d $TEST_DB -c "show datestyle;" 2>/dev/null | grep -i "informix"`
	#else
		TMPff=`$PSQL -d $TEST_DB -c "show datestyle;" | grep -i "informix"`
	#fi
	if test "$COMSPEC" != ""; then
		echo "WARNING: Windows versions of PG engine are currently not"
		echo "WARNING: fully compatible with Aubit in ecpg mode, since they"
		echo "WARNING: do not contain Informix compatibility patch"
	fi
	if test "$TMPff" = "" -a "$COMSPEC" = ""; then 
		echo "WARNING: PostgreSQL config file ($PG_CONF)"
		echo "does not contain needed setting:"
		echo "datestyle = 'informix, mdy'"
		#should we do that automatically??
		#echo "datestyle = 'informix, mdy'" >> $PG_CONF
		#...and restart pg...?
		if test "$IGNORE_CONF_ERR" != "1" -a "$DB_TYPE" = "PG-IFX-74"; then 
			error "(correct or use -ignore-conf-error to ignore)" "8"
		fi
	fi
	#if test "$COMSPEC" != ""; then
	#	TMP=`echo "$PGUSER_POSTGRES_PWD" | $PSQL -d $TEST_DB -c "show default_delim;" 2>/dev/null | grep "\|"`
	#else
		if test "$COMSPEC" = ""; then
			TMPhh=`$PSQL -d $TEST_DB -c "show default_delim;"| grep "\|"`
			#On Windows, we would get:
			#ERROR:  unrecognized configuration parameter "default_delim"
		fi
	#fi
	if test "$TMPhh" = "" -a "$COMSPEC" = ""; then 
		echo "WARNING: PostgreSQL config file ($PG_CONF)"
		echo "does not contain needed setting:"
		echo "default_delim = '|'"
		echo "This must be set *after* you do the initdb"
		#should we do that automatically??
		#echo "datestyle = 'informix, mdy'" >> $PG_CONF
		#...and restart pg...?
		if test "$IGNORE_CONF_ERR" != "1" -a "$DB_TYPE" = "PG-IFX-74"; then 
			error "(correct or use -ignore-conf-error to ignore)" "8"
		fi
	fi
	
	#You should also initdb with --locale='C' if you want index's to be used
	#when comparing an indexed column with a string.
	#eg. "initdb --locale='C' -D /usr/local/pgsql/data" 
	#Is there a way to verify that this was done on currently running PG instance?
	TMPhh=`$PSQL -d $TEST_DB -c "show locale;"| grep "\|"`
	verbose "CHECK: 'show locale' returned $TMPhh"

	#postgres has a "problem" with using indexes with
	#bigint's. This has been fixed in 8.0, but in previous versions you
	#should use where bigintcol='1' , or where bigintcol=int8::1
	TMPhh=`$PSQL -d $TEST_DB -c "show bigintcol;"| grep "\|"`
	verbose "CHECK: 'show bigintcol' returned $TMPhh"
	
	####################
	#Set Aubit configuration options to perform correctly
	#in PostgreSQL Informix compatibility mode
	
	# All updates will be transformed to Ansi syntax
	#Rewrites the Update (col1,col2,col3)=(val1,val2,val3) -> update 
	#col1=val1,col2=val2,col3=val3
	export A4GL_FIXUPDATE=Y

	# The keyword 'AS' is included when using an alias on a select column
	#eg. select tabid tid from systables -> select tabid AS 'tid' from systables
	export A4GL_USE_ALIAS_AS=Y

	# Any CREATE TEMP TABLE .. WITH NO LOG will have the 'WITH NO LOG' silently removed
	#This does not include the ' WITH NO LOG' at the end of a create temp table 
	#when the original SQL does.
	#create temp table a(a integer) WITH NO LOG ->
	#create temp table a(a integer)
	export A4GL_OMIT_NO_LOG=Y

	# No indicator variables (=YES Adds indicators to SQL statements to check for nulls)
	#export A4GL_USE_INDICATOR=N

	# When needed use the ecpg UNLOAD statement rather than the aubit code
	export A4GL_ESQL_UNLOAD=Y
	
	#When SQL encounters CURRENT  - it calls this function instead with two string 
	#parameters ('START' to 'END')
	#select current year to minute from systables where tabid=1 ->
	#select somename('year','minute') from systables where tabid=1
	#export A4GL_SQL_CURRENT_FUNCTION=somename

	#Treat MONEY type as DECIMAL when compiling to POSTGRES EC LEXTYPE
	#Because PG EC compiler (ecpg) does not know about MONEY type. Without it,
	#you will get (ERROR: Only numeric/decimal have precision/scale argument)
	export A4GL_MONEY_AS_DECIMAL=YES
	
	#Treat MONEY type as MONEY when compiling to POSTGRES EC LEXTYPE
	#This will probably fail, since PG EC compiler curently does not know about 
	#MONEY datatype (ERROR: invalid datatype 'money').
	export A4GL_MONEY_AS_MONEY=NO

	#Enable sqlca.sqlerrd[6] (ROWID/OID of last inserted record) translation 
	#This is apparently needed only with PostgreSQL (with IFX compatibility patches)
	export SWAP_SQLCA62=Y 

#A4GL_SQLDIALECT COMPILE/RUNTIME/SQL SQL Dialect used for the source file
	#Declares the SQL dialect of SQL code in 4GL source code.
	#an 4GL directive to change the default SQL dialect at runtime is:
	#       SET SQL DIALECT TO ORACLE
	#by default the system assumes the 4GL application is using Informix SQL
	#syntax, but this can be changed by setting, for example:
	export A4GL_SQLDIALECT="INFORMIX"

#A4GL_SQLCNVPATH RUNTIME/SQL Specifies the location of the conversion details for SQL grammers
	#CONFIG FILE BASED CONVERSIONS
	#convert_sql() now uses configuration files.  These are by default
	#located in /opt/aubit4gl/etc/convertsql/, but that can be changed
	#with A4GL_SQLCNVPATH.

#A4GL_TARGETDIALECT COMPILE Specify target part of .cnv file
	#at runtime - it would be A4GL_SQLDIALECT
	#you need to be careful with that that you dont process statements twice 
	#(dont use TARGETDIALECT and SQLDIALECT unless you are using ESQL/C generation)
	#By default, value of this setting is decided based on type of database
	#plug-in (A4GL_SQLTYPE) or based on connected database in case of ODBC
	#connection.
	
# INFORMIX-POSTGRES8.cnv   - for PostgreSQL V8 using ecpg 
# INFORMIX-POSTGRES.cnv    - for PostgreSQL V7.4 (with IFX patch) using ecpg
# INFORMIX-POSTGRESSQL.cnv - for PostgreSQL V7.4 or 8 over ODBC
	
	if test "$DB_TYPE" = "PG-IFX-74"; then
		if test "$A4GL_LEXTYPE" = "EC"; then
			PG_TYPE="7_ECPG_IFX"
		else
			PG_TYPE="7_ODBC_IFX"
		fi
	elif test "$DB_TYPE" = "PG-74"; then
		if test "$A4GL_LEXTYPE" = "EC"; then
			PG_TYPE="7_ECPG"
		else
			PG_TYPE="7_ODBC"
		fi
	elif test "$DB_TYPE" = "PG-80" ; then 
		if test "$A4GL_LEXTYPE" = "EC"; then
			PG_TYPE="8_ECPG"
		else
			PG_TYPE="8_ODBC"
		fi
	else
		echo "Unknown PG DB_TYPE=$DB_TYPE"
		exit 5
	fi
	
	if test "$PG_TYPE" = "8_ECPG"; then
		#Success % (May 2006)
		#--- Postgres engine:				WinPG8+ECPG
		#A4GL_TARGETDIALECT="POSTGRES8"			74 %
		#A4GL_TARGETDIALECT="POSTGRESSQL"		37 %
		#A4GL_TARGETDIALECT="POSTGRES"	 		76 %	
		export A4GL_TARGETDIALECT="POSTGRES8"
		export A4GL_ESQL_UNLOAD=NO
	elif test "$PG_TYPE" = "8_ODBC"; then
		export A4GL_TARGETDIALECT="POSTGRESSQL"
		export A4GL_ESQL_UNLOAD=NO
	elif test "$PG_TYPE" = "7_ODBC"; then
		export A4GL_TARGETDIALECT="POSTGRESSQL"
		export A4GL_ESQL_UNLOAD=NO
	elif test "$PG_TYPE" = "7_ECPG_IFX"; then
		export A4GL_TARGETDIALECT="POSTGRES"
		export A4GL_ESQL_UNLOAD=YES
	elif test "$PG_TYPE" = "7_ECPG"; then
		warning "PG V7 >WITHOUT< IFX patch is not supported"
		export A4GL_TARGETDIALECT="POSTGRES"
		export A4GL_ESQL_UNLOAD=NO		
	else
		echo "WARNING: PG_TYPE not set or unknown ($PG_TYPE)"
		echo "Using default target SQL dialect for PostgreSQL 8 using ecpg"
		export A4GL_TARGETDIALECT="POSTGRES8"
	fi
	#echo "DB_TYPE=$DB_TYPE FEATURE_DB_TYPE=$FEATURE_DB_TYPE PG_TYPE=$PG_TYPE A4GL_LEXTYPE=$A4GL_LEXTYPE"
	#exit
	
	#Note: using POSTGRES8 is more or less pointless because of:
	#Warning: Can't fix insert statement - Table testunlo is not in the database(1)
	
	#Manual overrides:
		#A4GL_TARGETDIALECT="POSTGRES8"
		#A4GL_TARGETDIALECT="POSTGRESSQL"
		#A4GL_TARGETDIALECT="POSTGRES"

#A4GL_SQLCONVERT COMPILE/RUNTIME/SQL Autoconvert SQL from sources files dialect to runtime dialect
	#Conversion of SQL statements in 4GL code, to the SQL dialect of target RDBMS
	#Conversion is only done if you set A4GL_SQLCONVERT=YES and only if
	#the dialect used by the program differs from that used by the DBMS
	#interface.
	export A4GL_SQLCONVERT=YES
	
	#See also settigs under -ecp flag in run_tests - AND MERGE THEM ALL IN ONE PLACE! 
	
}



###############################################################
#Loop trough all tests and check them for ANSI SQL 92 compatibility
###############################################################
function check_ansi_all () {
ALL_DIRS=[0-9]*
ALL_TESTS=`echo $ALL_DIRS | tr " " "\n" | $SORT -n |  tr "\n" " "`
FAIL_NOERRFILE_CNT=0
FAIL_ANSI_CNT=0
FAIL_NOT_SIX=0
DIFF_RESULTS=0
TEST_CNT=0
ALLREADY_SET_CNT=0
TOTAL_FGL_CNT=0
ANSI_OK_CNT=0
FAIL_ANSI_COMMENT_ONLY_CNT=0

		for TEST_NO in $ALL_TESTS
		do
			check_ansi_single $TEST_NO

			#Show results for each test:
			case $RESULT in
				unknown-failed-but-no-ANSI-in-err | yes-only-comment-warnings |	no | unknown-failed-to-compile)
					if test "$VERBOSE" = "1"; then
						echo $MSG1
						if test "$MSG2" != ""; then 
							echo "MSG2"
						fi
						MSG1=""; MSG2=""
						echo ""
						echo "--------------------------------------------------------------------------"
						echo ""
					fi
				;;
			esac
			if test "2" = "1"; then 
				#if test "$TEST_CNT" = "100"; then
				if test "$TEST_CNT" = "20"; then
					echo "Exiting after reaching the set limit"
					break
				fi
			fi
		done
		
		
		#Show summary results
		echo ""
		echo "Procesed $TEST_CNT tests, $TOTAL_FGL_CNT 4gl source files"
		echo ""
		echo "Failed on ANSI, but no ANSI in err file ($FAIL_NOERRFILE_CNT) $FAIL_NOERRFILE_LST"
		echo "Failed on ANSI, but only comment warnings ($FAIL_ANSI_COMMENT_ONLY_CNT) $FAIL_ANSI_COMMENT_ONLY_LST"		
		echo "Failed, not on ANSI ($FAIL_NOT_SIX) $FAIL_NOT_SIX_LST"
		echo "Conflicting results from compilers ($DIFF_RESULTS) $DIFF_RESULTS_LST"
		echo "Allready set in makefile ($ALLREADY_SET_CNT) $ALLREADY_SET_LST"
		echo "--------------------------------------------------------------------------"
		echo "ANSI compatible: ($ANSI_OK_CNT + $FAIL_ANSI_COMMENT_ONLY_CNT) $ANSI_OK_LST $FAIL_ANSI_COMMENT_ONLY_LST"
		echo ""		
		echo "Not ANSI compatible: ($FAIL_ANSI_CNT) $FAIL_ANSI_LST"
		echo ""
		echo "Unknown: ($FAIL_NOERRFILE_CNT + $FAIL_NOT_SIX + $DIFF_RESULTS) $FAIL_NOERRFILE_LST $FAIL_NOT_SIX_LST $DIFF_RESULTS_LST"
		echo ""
		
}


###############################################################
#Check one test for ANSI SQL compliance and interpret results
###############################################################
function check_ansi_single () {
CHECK_TEST=$1
COMPARE_REAL_WITH_STORED=1

	IS_MAKE_ANSI_SQL_COMPAT=`$MAKE -s -C $CHECK_TEST ansi_sql_compat 2>/dev/null`
	if test "$IS_MAKE_ANSI_SQL_COMPAT" != ""; then
		#we allready have this set in makefile. Since testing using compilers
		#tests only static SQL, we must honor what is set in makefile, since
		#it may be set because of dynamic SQL
		IS_ANSI_COMPATIBLE=$IS_MAKE_ANSI_SQL_COMPAT
		let ALLREADY_SET_CNT=ALLREADY_SET_CNT+1
		ALLREADY_SET_LST="$ALLREADY_SET_LST $CHECK_TEST"
		if test "$IS_ANSI_COMPATIBLE" = "0"; then 
			MSG1="$CHECK_TEST: Result 0 from makefile"
			let FAIL_ANSI_CNT=FAIL_ANSI_CNT+1
			FAIL_ANSI_LST="$FAIL_ANSI_LST $CHECK_TEST"
		else
			MSG1="$CHECK_TEST: Result 1 from makefile"
			let ANSI_OK_CNT=ANSI_OK_CNT+1
			ANSI_OK_LST="$ANSI_OK_LST $CHECK_TEST"
		fi
	fi
	
	if test "$IS_MAKE_ANSI_SQL_COMPAT" = "" -o "$COMPARE_REAL_WITH_STORED" = "1"; then 
		#do the ANSI check
		RESULT=""
		IS_ANSI_COMPATIBLE=""
		let TEST_CNT=TEST_CNT+1
		check_ansi $CHECK_TEST
		let TOTAL_FGL_CNT=TOTAL_FGL_CNT+FGL_CNT

		#Interpret and count results
		
			case $RESULT in
				unknown-failed-but-no-ANSI-in-err)
					MSG1="$CHECK_TEST: $FGL failed with code $RET, but no ANSI in err file"
					let FAIL_NOERRFILE_CNT=FAIL_NOERRFILE_CNT+1
					FAIL_NOERRFILE_LST="$FAIL_NOERRFILE_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				yes-only-comment-warnings)	
					MSG1="$CHECK_TEST: $FGL generated ANSI warnings, but all about comments"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then
						let FAIL_ANSI_COMMENT_ONLY_CNT=FAIL_ANSI_COMMENT_ONLY_CNT+1
						FAIL_ANSI_COMMENT_ONLY_LST="$FAIL_ANSI_COMMENT_ONLY_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="1"
					;;
				no)
					MSG1="$CHECK_TEST: $FGL generated ANSI warnings:"
					MSG2="$WARN_TXT_NO_COMMENT"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then
						let FAIL_ANSI_CNT=FAIL_ANSI_CNT+1
						FAIL_ANSI_LST="$FAIL_ANSI_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="0"
					;;
				unknown-failed-to-compile)
					MSG1="$CHECK_TEST: $FGL faied with exit code $RET (not 6)"
					let FAIL_NOT_SIX=FAIL_NOT_SIX+1
					FAIL_NOT_SIX_LST="$FAIL_NOT_SIX_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				unknown-different-results)
					MSG1="$CHECK_TEST: $FGL conflicting results from compilers"
					let DIFF_RESULTS=DIFF_RESULTS+1
					DIFF_RESULTS_LST="$DIFF_RESULTS_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				yes)
					MSG1="$CHECK_TEST: $FGL is ANSI compatible"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then					
						let ANSI_OK_CNT=ANSI_OK_CNT+1
						ANSI_OK_LST="$ANSI_OK_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="1"
					;;
				no-fgl)
					MSG1="$CHECK_TEST: No 4gl files"
					let FAIL_NOT_SIX=FAIL_NOT_SIX+1
					FAIL_NOT_SIX_LST="$FAIL_NOT_SIX_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				*)
					echo "WARNING: unhandled result: $RESULT"
					IS_ANSI_COMPATIBLE="unknown"
					;;
			esac
			if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then
				#makefile does NOT contain the value
				if test "$IS_ANSI_COMPATIBLE" = "1" -o "$IS_ANSI_COMPATIBLE" = "0"; then
					#We determined state, so record it to makefile
					if test "1" = "1"; then
						makefile=`ls $CURR_DIR/$CHECK_TEST/?akefile 2> /dev/null`
						if test "$makefile" != ""; then
							change_setting ansi_sql_compat $IS_ANSI_COMPATIBLE $CHECK_TEST
							#echo "changed test $CHECK_TEST"
							#exit
						fi
					fi
				fi
			fi
	fi
	
	if test "$IS_MAKE_ANSI_SQL_COMPAT" != "" -a "$COMPARE_REAL_WITH_STORED" = "1"; then
		#Compare value stored in makefile with result of the actual test 
		if test "$IS_ANSI_COMPATIBLE" != "$IS_MAKE_ANSI_SQL_COMPAT"; then
			if test "$VERBOSE" = "1"; then
				echo "WARNING: test $CHECK_TEST - different results from the actuall test and makefile" 
				echo "Test: $IS_ANSI_COMPATIBLE but in Makefile: $IS_MAKE_ANSI_SQL_COMPAT"
			fi
			#exit 5
			#setting in makefile has priority, because of dynamic SQL
			IS_ANSI_COMPATIBLE="$IS_MAKE_ANSI_SQL_COMPAT"
		else
			if test "$VERBOSE" = "1"; then
				echo "Result of actual test and value stored in makefile are same"
			fi
		fi
	fi
			
			
	if test "$VERBOSE" = "1"; then
		echo $MSG1
		if test "$MSG2" != ""; then 
			echo "$MSG2"
		fi
	fi
	
}

###############################################################
#check all 4gl files in test directory for ANSI SQL compliance
###############################################################
function check_ansi() {
this_test_no=$1
FGL_CNT=0
if test "$ANSI_USE_COMP" = ""; then 
	#ANSI_USE_COMP=ifx
	#ANSI_USE_COMP=querix
	#ANSI_USE_COMP=aubit
	ANSI_USE_COMP=all
fi
#4Js apparently does not have option for ANSI schecking
#what is DBANSIWARN env. var doing?
#ANSI SQL info: http://www.tdan.com/i016hy01.htm
#http://www.knosof.co.uk/sqlport.html
#http://thor.informatik.uni-halle.de/~brass/sqllint/


	OLD_DIR=`pwd`
	cd $CURR_DIR/$this_test_no
	ALL_4GL=*.4gl
	RESULT=""

	for FGL in $ALL_4GL
	do
		if ! test -f $FGL; then
			RESULT="no-fgl"
			continue
		fi
		#If we allready got no or unknown on one 4gl file, we can't be
		#sure if test is compatible even if another 4gl file is OK, so abort
		case $a in
		no*)
	   		break
			;;
		unknown*)
			break
			;;
		esac
		let FGL_CNT=FGL_CNT+1
		case $ANSI_USE_COMP in
			ifx)
				check_ansi_ifx $FGL
				;;
			querix)
				check_ansi_querix $FGL
				;;
			aubit)
				check_ansi_aubit $FGL
				;;
			all)
				check_ansi_querix $FGL
				RESULT_QUERIX=$RESULT
				check_ansi_aubit $FGL
				RESULT_AUBIT=$RESULT
				check_ansi_ifx $FGL
				RESULT_IFX=$RESULT
				
				if test "$RESULT_QUERIX" != "$RESULT_IFX"; then
					if test "$RESULT_QUERIX" = "yes" -a "$RESULT_IFX" = "yes-only-comment-warnings"; then
						#Only Informix can return yes-only-comment-warnings so it is yes
						RESULT="yes"
					else
						RESULT="unknown-different-results"
					fi
				else
					#Make sure we ignore Aubit result - not reliable
					#since Querix and Informix returned same result, it is
					#irelevant which one we will assign
					RESULT=$RESULT_QUERIX
				fi
			
		esac
	done
	cd $OLD_DIR
}


###############################################################
#Check one 4gl file for ANSI SQL compliance using Informix 4GL compiler
###############################################################
function check_ansi_ifx() {
FGL=$1
FGLCOMP_CMD="fglpc -ansi"

		TMP_TMP=`$FGLCOMP_CMD $FGL 2>&1` 
		RET=$?
		if test "$RET" != "0"; then
			FGL_BASENAME=`basename $FGL .4gl`
		 	if test "$RET" = "6"; then
				WARN_TXT=`cat $FGL_BASENAME.err | grep "^|" | grep ANSI`
				if test "$WARN_TXT" = ""; then
					RESULT="unknown-failed-but-no-ANSI-in-err"
				else
					WARN_TXT_NO_COMMENT=`echo "$WARN_TXT" | grep -v "non-ANSI comment indicator"`
					if test "$WARN_TXT_NO_COMMENT" = ""; then 
						RESULT="yes-only-comment-warnings"
					else
						RESULT="no"
					fi
				fi
			else
				RESULT="unknown-failed-to-compile"
			fi
		else
			RESULT="yes"
		fi
		
		
	if test "$VERBOSE" = "1"; then
		echo "----------- Testing ANSI SQL compatibility using Informix 4GL compiler --------"
		echo "$FGL : $RESULT"
		if test "$WARN_TXT_NO_COMMENT" != ""; then
			#echo $WARN_TXT_NO_COMMENT
			grep -B 5 "$WARN_TXT_NO_COMMENT" $FGL_BASENAME.err
		fi
		if test "$RESULT" = "unknown-failed-to-compile"; then 
			grep -B 1 "^|" $FGL_BASENAME.err
		
		fi
		echo ""
	fi
}

###############################################################
#Check one 4gl file for ANSI SQL compliance using Querix 4GL compiler
###############################################################
function check_ansi_querix() {
FGL=$1

#Querix will exit with 0, but print "Warnings found" to stderr
#.err file will contain "Warning: Non ANSI standard SQL statement"
#It does not warn about comments
FGLCOMP_CMD="fglc -ansi"

		TMP_TMP=`$FGLCOMP_CMD $FGL 2>&1`
		RET=$?
		TMP_TMP=`echo $TMP_TMP | grep "Warnings found"`
		FGL_BASENAME=`basename $FGL .4gl`
		if test "$RET" = "0"; then
		 	if test "$TMP_TMP" != ""; then
				#Warnings found
				WARN_TXT=`cat $FGL_BASENAME.err | grep "^|" | grep "Warning: Non ANSI standard SQL statement"`
				if test "$WARN_TXT" = ""; then
					RESULT="unknown-failed-but-no-ANSI-in-err"
				else
					RESULT="no"
				fi
			else
				RESULT="yes"
			fi
		else
			RESULT="unknown-failed-to-compile"
		fi
		
	if test "$VERBOSE" = "1"; then
		echo "------------Testing ANSI SQL compatibility using Querix 4GL compiler ----------"
		echo "$FGL : $RESULT"
		if test "$RESULT" = "unknown-failed-to-compile"; then 
			grep -B 1 "^|" $FGL_BASENAME.err
		
		fi
		echo ""
	fi
		
}

###############################################################
#Check one 4gl file for ANSI SQL compliance using Aubit 4GL compiler
###############################################################
function check_ansi_aubit() {
FGL=$1

# Try test 538 
#TODO: use '-ansi' flag on the ESQL/C compiler.

if test "$A4GL_LEXTYPE" = "" -o "$A4GL_SQLTYPE" = ""; then 
	#We are called before run_test script set this 
	AUBIT_DB="export A4GL_LEXTYPE=C; export A4GL_SQLTYPE=esql;"
fi
FGLCOMP_CMD="export A4GL_ANSI_WARN=Yes; $AUBIT_DB aubit $FGLC --verbose"

		TMP_TMP=`eval $FGLCOMP_CMD $FGL 2>&1`
		RET=$?
		#echo $TMP_TMP
		TMP_TMP=`echo $TMP_TMP | grep "ANSI violation"`
		if test "$RET" = "0"; then
			#compiled OK
		 	if test "$TMP_TMP" != ""; then
				#Warnings found - Aubit does not create .err file in that case
				RESULT="no"
			else
				RESULT="yes"
			fi
		else
			RESULT="unknown-failed-to-compile"
		fi
		
	if test "$VERBOSE" = "1"; then
		echo "------------Testing ANSI SQL compatibility using Aubit 4GL compiler ----------"
		echo "$FGL : $RESULT"
		echo ""
	fi
		
}


###############################################################
#Create database tables for ....
###############################################################
function create_unl_db_tables () {
db="aubit_tests"
tablename="catalogue"
script="$tablename.sql"
logfile="$tablename.log"
if test "$RDBMS" = ""; then 
	RDBMS="informix"
	check_informix
fi
	test_db_exist $db
	if test "$TEST" != ""; then 
		#echo "CR2"
		create_db $db
	else
		echo "Database $db exists"
		drop_db $db	
		#echo "CR3"
		create_db $db
	fi

cat > $script <<X
	create table catalogue (
		timestamp char (19),   -- 22-10-2004_01-34-24
		test_no smallint,
		invalid smallint,
		is_db smallint,
		is_ec smallint,
		is_nosilent smallint,
		is_tui smallint,
		is_form smallint,
		is_report smallint,
		is_graphics smallint,
		is_prompt smallint,
		is_dump_screen smallint,
		is_long smallint,
		is_unknown smallint,
		is_cert smallint,
		is_obsolete smallint,
		is_described smallint,
		test_desc_txt varchar(255),
		test_compat_test smallint,
		expect_code char(3),
		se_required smallint,
		compile_only smallint,
		need_ifx_ver char(10),
		need_trans smallint,
		no_prefix smallint,
		need_compat smallint,
		old_makefile smallint,
		is_pcode_enabled smallint,
		is_no_cron smallint,
		scripted smallint,
		is_window smallint,
		test_ver decimal,
		run_tests_ver decimal,
		last_update date,
		expect_fail_cert  smallint,
		expect_fail_esqli smallint,
		expect_fail_ecp smallint,
		expect_fail_ifx_p smallint,
		expect_fail_4js smallint,
		expect_fail_querix smallint,
		sql_features_used varchar(255),
		ansi_sql smallint
	);
X

	#echo "Converting script..."
	#convert_sql ddl $RDBMS $script
	echo "Creating table $tablename..."
	run_sql_script $RDBMS $db $script $logfile
	TMP_TMP=`cat $logfile | grep "TableOOPScreated"`
	if test "$TMP_TMP" = ""; then 
		echo "Failed - see $logfile"
		exit 5
	fi
	

tablename="results"
script="$tablename.sql"
logfile="$tablename.log"
#15-10-2004_18-23-02|34|1||0||NULL|1.49|0.30|0:01.85|96%|0|0|0|0|3773|0|
cat > $script <<X
	create table results (
		timestamp char (19),   -- 22-10-2004_01-34-24
		test_no smallint,
		result smallint,
		skip_reason char (20),
		expect_fail smallint,
		test_version decimal,
		db_has_trans char(4),
		t_user decimal,
		t_system decimal,
		t_elapsed char(8),
		t_CPU char(4),
		t_text decimal,
		t_data decimal,
		t_inputs decimal,
		t_outputs decimal,
		t_major integer,
		t_swaps integer
		);
X


	#echo "Converting script..."
	#convert_sql ddl $RDBMS $script
	echo "Creating table $tablename..."
	run_sql_script $RDBMS $db $script $logfile
	TMP_TMP=`cat $logfile | grep "TableOOPScreated"`
	if test "$TMP_TMP" = ""; then 
		echo "Failed - see $logfile"
		exit 5
	fi

tablename="test_run"
script="$tablename.sql"
logfile="$tablename.log"

cat > $script <<X
	create table test_run (
		timestamp char (19),   -- 22-10-2004_01-34-24
		host char(30),
		user char (14),
		platform char (10),
		os_name char (20),
		os_version char(80),
		flags char (200),
		aubit_version decimal,
		aubit_build smallint,
		comp_version char(40),
		total_time integer,
		c_ver char(40),
		esql_ver char(40),
		db_ver char(40),
		make_ver char(40),
		sh_ver char(40),
		log_text varchar(255)
		);
X

	#echo "Converting script..."
	#convert_sql ddl $RDBMS $script
	echo "Creating table $tablename..."
	run_sql_script $RDBMS $db $script $logfile
	TMP_TMP=`cat $logfile | grep "TableOOPScreated"`
	if test "$TMP_TMP" = ""; then 
		echo "Failed - see $logfile"
		exit 5
	fi

	echo "Done creating tables"
}


###############################################################
#Load all .unl data
###############################################################
function load_unl_tables () {
dl="|"
#ALL_RESULTS="aptiva_16-10-2004_12-49-24"
ALL_RESULTS=results_*.unl


	echo "Loading catalogue..."
	load_table "aubit_tests" "catalogue" "$CATALOGUE_UNL_FILE" "42" "$dl"

	for FILE in $ALL_RESULTS; do 
		STAMP=`echo $FILE | sed -e 's/results_//' -e 's/.unl//'`
		results_unl_file="results_$STAMP.unl"
		test_run_unl_file="test_run_$STAMP.unl"
		
		if ! test -f $results_unl_file || ! test -f $test_run_unl_file; then
			#This happens when run_tests is interupted before reaching the 
			#end, and creating test_run_ unl file
			if test "$VERBOSE" = "1"; then
				echo "Skipping $STAMP - missing pair"
			fi
		else
			echo "Loading results from $results_unl_file..."
			load_table "aubit_tests" "results" "$CURR_DIR/$results_unl_file" "17" "$dl"
			
			echo "Loading test_run from $test_run_unl_file..."	
			load_table "aubit_tests" "test_run" "$CURR_DIR/$test_run_unl_file" "17" "$dl"
		fi
	done

	count_rows catalogue aubit_tests
	echo "Total $CNT rows loaded into catalogue"
	count_rows test_run aubit_tests
	echo "Total $CNT rows loaded into test_run"
	count_rows results aubit_tests
	echo "Total $CNT rows loaded into results"

	
}

###############################################################
#Load single .unl file
###############################################################
function load_table () {
db=$1
loadname=$2
logfile=$3
col_no=$4
dl=$5

	echo "file \"$logfile\" delimiter \"$dl\" $col_no;" > $loadname.dbl
	echo "insert into $loadname;" >> $loadname.dbl
	
	if test "$VERBOSE" = "1"; then
		count_rows $loadname $db
		BEFORE_LOAD=$CNT
	fi
	
	dbload -d $db -c $loadname.dbl -l $loadname.err > /tmp/dbload.log 2>&1
	RET=$?

	if test "$VERBOSE" = "1"; then 
		count_rows $loadname $db
		let THIS_LOAD=CNT-BEFORE_LOAD
		echo "$THIS_LOAD rows loaded into $loadname"
	fi
	
	if test "$RET" != "0"; then 
		echo "dbload failed."
		if test -f /tmp/dbload.log; then 
			cat /tmp/dbload.log
		fi
		exit $RET
	fi
	
	if test -f $loadname.err; then
		error "Load rejected some rows. See $loadname.err" "1"
		if test "$VERBOSE" = "1"; then
			cat $loadname.err
		fi
	fi

}

###############################################################
#Check and create MySQL db
###############################################################
function check_mysql () {

	RC_MYSQL=`ls /etc/init.d/mysql`
	if test $"RC_MYSQL" = ""; then 
		RC_MYSQL=`which rcmysql`
	fi
	if test $"RC_MYSQL" = ""; then
		RC_SERVICE=`which service`
		if test $"RC_SERVICE" != ""; then
			RC_MYSQL="$RC_SERVICE mysql"
		fi
	fi
		
	if test $"RC_MYSQL" = ""; then
		warning "Cannot locate MySQL RC script - please make sure MySQL instance is running"
	else
		TMP_STAT=`$RC_MYSQL status | grep running`
		if test "$TMP_STAT" = ""; then
			$RC_MYSQL start
			TMP_STAT=`$RC_MYSQL status | grep running`
			if test "$TMP_STAT" = ""; then
				warning "Cannot verify that MySQL is running using RC script $RC_MYSQL"
				warning "please make sure MySQL instance is running"
			fi
		else
			verbose "MySQL is running"
		fi
	fi

 	DB_TYPE="MYSQL"
	MYSQL_EXE=`which mysql`
	if test "$MYSQL_EXE" = ""; then
		error "Cannot locate MySQL executable. STOP" "1"
	fi

	MYSQL_VERSION=`$MYSQL_EXE --version  | awk '{ print $5 }' | sed 's/,//'g`
	verbose "MySQL version $MYSQL_VERSION"

	TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="\q"`
	TMP_STAT=$?
	if test "$TMP_STAT" != "0"; then
		#ERROR 1049 (42000): Unknown database 'test1'
		verbose "MySQL databse $TEST_DB does not exist"
		HAVE_MYSQL_DB=0
	else
		verbose "Found MySQL databse $TEST_DB"
		HAVE_MYSQL_DB=1
		if test "$NEW_MYSQL" = "1"; then
			echo  "Deleting MySQL db $TEST_DB"
			TMP_OUT=`mysqladmin --user=root --password=aubit --force drop $TEST_DB`
			TMP_STAT=$?
			if test "$TMP_STAT" != "0"; then
				warning "Attempt to delete MySQL database $TEST_DB failed; message returned:"
				echo "$TMP_OUT"
			else
				HAVE_MYSQL_DB=0
			fi
		fi
	fi
	
	if test "$HAVE_MYSQL_DB" = "0"; then
		message "Creating MySQL testing database..."
		TMP_OUT=`mysqladmin --user=root --password=aubit create $TEST_DB`
		TMP_STAT=$?
		if test "$TMP_STAT" != "0"; then
			echo "$TMP_OUT"
			error "Failed trying to create MySQL DB $TEST_DB" "1"
		else
			TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="\q"`
			TMP_STAT=$?
			if test "$TMP_STAT" != "0"; then
				echo $TMP_OUT
				#ERROR 1049 (42000): Unknown database 'test1'
				error "ERROR: failed to create MySQL database $TEST_DB" "1"
			else
				new_testdb mysql
				#Does the $USER exist in MySQL? 
				TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="select user from mysql.user;"`
				TMP_STAT=$?
				if test "$TMP_STAT" != "0"; then
					error "Attempt to list users failed" "4"
				else
					TMP_TEST=`echo $TMP_OUT | grep $USER`
				fi
				if test "$TMP_TEST" = ""; then
					#Create user $USER
					#This wont work - password allready have to be hashed:
					#TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="CREATE USER $USER IDENTIFIED BY PASSWORD 'aubit';"`
					TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="CREATE USER $USER;"`
					#This works:
					#mysql> CREATE USER aubit@localhost;
					TMP_STAT=$?				
					if test "$TMP_STAT" != "0"; then
						error "Attempt to create user failed" "4"
					fi
				else
					verbose "User $USER exists in MySQL"
					#User exist - make sure we know the password:
					#Did not work - dont know why:
					#TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="SET PASSWORD FOR '$USER'@'%' = PASSWORD('aubit');"`
					TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="SET PASSWORD FOR '$USER' = PASSWORD('aubit');"`
					#mysql> SET PASSWORD FOR 'aubit'@'localhost' = PASSWORD('aubit');					
					TMP_STAT=$?				
					if test "$TMP_STAT" != "0"; then
						error "Attempt to change password failed" "9"
					else
						verbose "Changed password for $USER to 'aubit'"
					fi
				fi
				#Grant $USER all privileges in $TEST_DB database:
				TMP_OUT=`mysql --user=root --password=aubit --database=$TEST_DB --execute="GRANT ALL PRIVILEGES ON $TEST_DB.* TO '$USER';"`
				TMP_STAT=$?				
				if test "$TMP_STAT" != "0"; then
					echo "$TMP_OUT"
					error "Failed to grant privileges on $TEST_DB to $USER" "1"
				else
					verbose "Granted all privileges on $TEST_DB to $USER"
					#Finally, can we connect as current user?
					TMP_OUT=`mysql --user=$USER --password=aubit --database=$TEST_DB --execute="\q" 2>&1`
					#ERROR 1045 (28000): Access denied for user 'aubit'@'localhost' (using password: YES)
					TMP_STAT=$?
					if test "$TMP_STAT" != "0"; then
						error "CMD: mysql --user=$USER --password=aubit --database=$TEST_DB --execute='\q'"
						echo "$TMP_OUT"
						error "Cannot connect as $USER with password 'aubit'" "8"
					else
						verbose "Succesfully conected to MySQL db $TEST_DB as $USER"
					fi
				fi
			fi
		fi
    fi
	
	#If MySQL server is not on localhost: 
	#export MYSQL_SERVER=MySQLServerName

	#Make sure 4GL compiler knows username & password:
	#We can do that with SQLUID/SQLPWD too
	#The .aubit4gl.acl file should also work as as alternative for the
	#SQLUID/SQLPWD for ODBC connections to any data source
	A4GL_ACL=$HOME/.aubit4gl.acl

if test "disabled" = "xxx"; then
#Broken ATM
	if test -f $A4GL_ACL; then
		grep $TEST_DB $A4GL_ACL
		TMP_STAT=$?
		if test "$TMP_STAT" != "0"; then
			echo "$TEST_DB:$USER:aubit" >> $A4GL_ACL
		fi
	else
		#dbname:username:password
		#NOTE: 4glpc will automatically encrypt the password, on first access
		echo "$TEST_DB:$USER:aubit" >> $A4GL_ACL
	fi
else
	export SQLUID=$USER
	export SQLPWD=aubit
fi
	
	if test "$NEW_MYSQL" = "1"; then
        exit 0
    fi
	
	EXPECT_TO_FAIL="$EXPECT_TO_FAIL $EXPECT_TO_FAIL_MYSQL"
	
	A4GL_TARGETDIALECT="MYSQLDIRECT"

}

###############################################################
#
###############################################################
#Check and create SQLite db
function check_sqlite () {

	SQLITE_DB="$AUBITDIR_UNIX/tools/$TEST_DB.db"
	
	if test "$COMSPEC" != ""; then 
		#SQLite is a native Windows executable - so it needs native Windows path for db
		SQLITE_DB="`cygpath -m $SQLITE_DB`"
	fi

	
 	DB_TYPE="SQLITE"
	
	TMPTMP=`type sqlite3 2>/dev/null`
	if test "$TMPTMP" != ""; then 
		SQLITE_EXE="sqlite3"
	else
		TMPTMP=`type sqlite 2>/dev/null`
		if test "$TMPTMP" != ""; then 
			SQLITE_EXE="sqlite"
		else
			echo "ERROR: cannot find SQLite executable. STOP."
			exit 5
		fi
	fi
	SQLITE_VERSION=`$SQLITE_EXE -version`
	if test "$VERBOSE" = "1"; then
		echo "SQLite version $SQLITE_VERSION"
	fi
	
	if test "$NEW_SQLITE" = "1"; then
		echo  "Deleting SQLite db in $SQLITE_DB"
		rm -f $SQLITE_DB > /dev/null 2>&1	
	fi
	
	if ! test -f $SQLITE_DB ; then
		echo "creating SQLite testing database..."
		new_testdb sqlite
		if ! test -f $SQLITE_DB ; then
			echo "ERROR: failed to create SQLite database:"
			echo "$SQLITE_DB"
			exit 4
		fi
	else
		if test "$VERBOSE" = "1"; then
			echo "Found SQLite db in $SQLITE_DB"
		fi
    fi
	if test "$NEW_SQLITE" = "1"; then
        exit 0
    fi
	
	#remember to account for this scrit cd-ing into test directory
	#when setting relative DBPATH to database file
	if test "$PLATFORM" = "MINGW"; then
		DBPATH="`cygpath -m $AUBITDIR_UNIX`"
	else
		DBPATH="$AUBITDIR_UNIX"
    fi
	export DBPATH
	
	EXPECT_TO_FAIL="$EXPECT_TO_FAIL $EXPECT_TO_FAIL_SQLITE"
	
	
	A4GL_TARGETDIALECT="SQLITE"

}

###############################################################
#
###############################################################
#Check and create SAP DB database
function check_sap() {

	if test "`echo quit | dbmcli -V 2>/dev/null`" = ""; then
        echo "ERROR: dbmcli not found - no SAP DB engine?"
        exit 67
    fi


	#TEST_DB=TST

	if test "$SILENT" != "1"; then
		echo "testing SAP connection..."
    fi
	_o=`cat <<EOF | dbmcli -d $TEST_DB -u dba,dba
	sql_connect dba,dba
EOF`
	#sql_execute CREATE USER test PASSWORD test DBA NOT EXCLUSIVE

	_test=`echo $_o | grep "x_server not running"`
	if [ "$_test" != "" ]; then
		echo "Trying to start x_server..."

		/etc/rc.d/init.d/sapdb start

		$SAPDBROOT/indep_prog/bin/dbmcli -d $TEST_DB -u dbm,dbm db_cold
		$SAPDBROOT/indep_prog/bin/dbmcli -d $TEST_DB -u dbm,dbm db_warm

	    #try again:
		_o=`cat <<EOF | dbmcli -d $TEST_DB -u dba,dba
		sql_connect dba,dba
EOF`
		_test=`echo $_o | grep "Error"`
		if [ "$_test" != "" ]; then
            echo "Failed to start x_server. Stop."
            exit 3
        fi
	fi

	TEST=`echo $_o | grep "Error"`
	if [ "$TEST" = "" ]; then
		TEST=`echo $_o | grep ERR`
    fi
	if [ "$TEST" != "" ]; then
        echo "access to SAP DB $TEST_DB failed: $_o"
	else
		if test "$SILENT" != "1"; then
			echo "access to SAP DB $TEST_DB OK"
        fi
	fi

	if test "$NEW_SAP" = "1" && test "$TEST" = ""; then
	    echo "Droping SAP DB database $TEST_DB"
		# stop and drop probably existing demo database
		dbmcli -d $TEST_DB -u dbm,dbm db_offline >/dev/null 2>&1
		dbmcli -s -d $TEST_DB -u dbm,dbm db_drop >/dev/null 2>&1
		RET=$?
        if test "$RET" != "0"; then
			echo "Failed (code $RET). See /tmp/dropdbtmp.log"
            exit 2
        else
			rmdir $HOME/$TEST_DB  >/dev/null 2>&1
			echo "Droped SAP DB database $TEST_DB"
        fi
    fi

    if test "$TEST" != "" || test "$NEW_SAP" = "1"; then
        echo "Creating SAP DB database $TEST_DB"

        if ! test -d /root/$TEST_DB; then
			mkdir /root/$TEST_DB
        fi
        chmod a+xrw /root/$TEST_DB
        chmod a+rw /tmp/credbtmp.log
		COMMAND="sh $SAPDBROOT/testdb/create_demo_db.sh $TEST_DB  > /tmp/credbtmp.log"
		su --preserve-environment -c "$COMMAND" sapdb

        RET=$?
        if test "$RET" != "0"; then
            echo "Failed (code $RET). See /tmp/credbtmp.log"
            exit 39
        else
            TMP=`cat /tmp/credbtmp.log | grep "set backup parameters"`
            if test "$TMP" != ""; then
                echo "Database Created"
            else
                echo "Database creation failed. See /tmp/credbtmp.log"
                exit 8
            fi
        fi

		echo "Trying to start database..."
		#/etc/rc.d/init.d/sapdb start
		$SAPDBROOT/indep_prog/bin/dbmcli -d $TEST_DB -u dbm,dbm db_cold
		$SAPDBROOT/indep_prog/bin/dbmcli -d $TEST_DB -u dbm,dbm db_warm

		if test "$SILENT" != "1"; then
			echo "testing SAP connection..."
        fi
		_o=`cat <<EOF | dbmcli -d $TEST_DB -u dba,dba
		sql_connect dba,dba
EOF`

		TEST=`echo $_o | grep "Error"`
		if [ "$TEST" = "" ]; then
			TEST=`echo $_o | grep ERR`
	    fi
		if [ "$TEST" != "" ]; then
			echo "access to SAP DB $TEST_DB failed: $_o"
            exit 33
		else
			if test "$SILENT" != "1"; then
				echo "access to SAP DB $TEST_DB OK"
            fi
		fi

		echo "Creating tables and loading data..."
		cat ./testdb.sql | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" | sed -e 's/128,0/128/g' | tr "\"" "'" | tr "\;" " " > testdb-tmp.sql

		#Note: database name here must be in uppercase!
		/opt/sapdb/depend/bin/xsql -u dba,dba -d TEST1 < ./testdb-tmp.sql > /tmp/testdb.log 2>&1

		RET=$?
		if test "$RET" != "0"; then
			echo "Statement returned code $RET. See /tmp/testdb.log"
            exit 3
        else
			TMP=`cat /tmp/testdb.log | grep "ERROR"`
			if test "$TMP" = ""; then
				TMP=`cat /tmp/testdb.log | grep "database not running"`
            fi
			if test "$TMP" = ""; then
				TMP=`cat /tmp/testdb.log | grep "Unknown user name"`
			fi
			if test "$TMP" = ""; then
				TMP=`cat /tmp/testdb.log | grep "Invalid SQL statement"`
			fi
			if test "$TMP" = ""; then
				TMP=`cat /tmp/testdb.log | grep "Missing delimiter"`
			fi
			if test "$TMP" = ""; then
				TMP=`cat /tmp/testdb.log | grep "Missing keyword"`
			fi
			if test "$TMP" = ""; then
                echo "Tables created and populated"
	            rm ./testdb-tmp.sql
			else
                echo "Tables creation failed. See /tmp/testdb.log"
                exit 8
            fi
		fi
    else
		if test "$VERBOSE" = "1"; then
			echo "Found SAP DB database $TEST_DB"
        fi
    fi

    if test "$NEW_SAP" = "1"; then
        exit
    fi
	
	A4GL_TARGETDIALECT="SAPDB"

}

###############################################################
#Check if we can use ODBC as defined in $ODBCINI for ODBC managers
###############################################################
function check_odbc() {

    TEST=""
	if test "$USE_UNIXODBC" = "1"; then
        echo "quit" | isql $TEST_DB $SQLUID $SQLPWD -v > /tmp/tmp.dbaccess 2>&1
        #[ISQL]ERROR: Could not SQLConnect
		TEST=`cat /tmp/tmp.dbaccess |  grep "Could not SQLConnect"`
    elif test "$USE_IODBC" = "1"; then
        if ! test -f $AUBITDIR_UNIX/bin/odbctest-iodbc3; then
            $MAKE -C $AUBITDIR_UNIX/tools/odbctest > /dev/null 2>&1
            if ! test -f $AUBITDIR_UNIX/bin/odbctest-iodbc3; then
                echo "ERROR: building odbctest failed. Stop."
                exit 84
            fi
        fi
        echo quit | $AUBITDIR_UNIX/bin/odbctest-iodbc3 "DSN=$TEST_DB;UID=$SQLUID;PWD=$SQLPWD;"  > /tmp/tmp.dbaccess 2>&1
		#DSN=maindb;UID=informix;PWD=ifmx;HOST=localhost;DATABASE=maindb;OPTIONS='aptiva_on'\r"
		#[SAP AG][LIBSQLOD SO]Dialog failed., SQLSTATE=IM008
        TEST=`cat /tmp/tmp.dbaccess |  grep "failed"`
    elif test "$USE_ODBC_32" = "1"; then
        echo "FIXME: how to do this on Windows? Same as iODBC?"
	else
        echo "ERROR: invalid USE_ setting for ODBC. Stop."
        exit 3
    fi

    if test "$TEST" != ""; then
		echo "ERROR: cannot connect to ODBC database $TEST_DB Stop."
		echo "ODBCINI=$ODBCINI"
		echo "ODBCINSTINI=$ODBCINSTINI"
        echo "SQLUID=$SQLUID SQLPWD=$SQLPWD TEST_DB=$TEST_DB"
		echo "UNIXODBC=$USE_UNIXODBC IODBC=$USE_IODBC ODBC21=$USE_ODBC_32"
		cat /tmp/tmp.dbaccess
        exit 21
    else
		if test "$VERBOSE" = "1"; then
			echo "Found ODBC database $TEST_DB"
        fi
    fi
	
	#Set conversion file - override what check_yyyy functions had set
	#if we have a separate conversion file better suited for use with ODBC
	case $DB_TYPE in
		MYSQL)
			#For native plug-in A4GL_TARGETDIALECT="MYSQLDIRECT"
			A4GL_TARGETDIALECT="MYSQL"
			;;
		
		PG-IFX-74 | PG-74 ) 
			# INFORMIX-POSTGRES8.cnv   - for PostgreSQL V8 using ecpg 
			# INFORMIX-POSTGRES.cnv    - for PostgreSQL V7.4 (with IFX patch) using ecpg
			# INFORMIX-POSTGRESSQL.cnv - for PostgreSQL V7.4 or 8 over ODBC
			A4GL_TARGETDIALECT="POSTGRESSQL"
			;;
		PG-80) 
			A4GL_TARGETDIALECT="POSTGRESSQL8"
			;;
		DB2)
			A4GL_TARGETDIALECT="DB2"
			#There is also INFORMIX-DB2VM.cnv, not sure which one to use here
			;;
	esac
	
	#When using non-Informix SQL syntax in 4GL code, runnign agains Informix db:
	#ORACLE-INFORMIX.cnv
	#POSTGRESQL-INFORMIX.cnv
	
	#Not sure what this is for:
	#INFORMIX-INFORMIX.cnv
	
	
}

###############################################################
#Check presense of Ingres database, create, set options
###############################################################
function check_ingres() {
	DB_TYPE="INGRES"
	A4GL_TARGETDIALECT="INGRES"
}

###############################################################
#Check presense of MS SQL Server database, create, set options
###############################################################
function check_sqlserver() {
	DB_TYPE="SQLSERVER"
	A4GL_TARGETDIALECT="SQLSERVER"
}

###############################################################
#Check presense of ORACLE database, create, set options
###############################################################
function check_oracle() {
	DB_TYPE="ORACLE"
	A4GL_TARGETDIALECT="ORACLE"
}

###############################################################
#Check presense of IBM DB/2 database, create, set options
###############################################################
function check_db2() {
	DB_TYPE="DB2"
	A4GL_TARGETDIALECT="DB2"
	#There is also INFORMIX-DB2VM.cnv
}

###############################################################
#Stub function for postgresql 8.x native driver            
###############################################################
function check_pg8() {
	DB_TYPE="PG8"
	A4GL_TARGETDIALECT="POSTGRES8"
	if test "$NEW_PG8" = "1"; then
		echo "Creating tables and loading data..."
		new_testdb postgres
        exit 
    fi

}

###############################################################
#Check if we have .cnv file as per configuration
###############################################################
function check_cnv_file () {

	if test "$A4GL_SQLDIALECT" = ""; then
		#At least for our tests, this will be true almost allways
		export A4GL_SQLDIALECT="INFORMIX"
	fi
	
	if test "$A4GL_TARGETDIALECT" = ""; then 
		warning "A4GL_TARGETDIALECT not specified"
	else
		#Check if we have specified .cnv file
		A4GL_SQLCNVPATH="`aubit-config A4GL_SQLCNVPATH`" 
		if test "$A4GL_SQLCNVPATH" = ""; then
			A4GL_SQLCNVPATH="$AUBITDIR/etc/convertsql"
		fi
		CNV_FILENAME=$A4GL_SQLCNVPATH/${A4GL_SQLDIALECT}-$A4GL_TARGETDIALECT.cnv
		if test -d $A4GL_SQLCNVPATH; then
			if test -f $CNV_FILENAME; then
				debug "Found conversion file $CNV_FILENAME"
				note "Using conversion: ${A4GL_SQLDIALECT}-$A4GL_TARGETDIALECT.cnv"
				export A4GL_SQLDIALECT
				export A4GL_TARGETDIALECT			
			else
				warning "Conversion file $CNV_FILENAME does not exist"
			fi
		else
			warning "Convertsion files directory ($A4GL_SQLCNVPATH) not found"
		fi
	fi
}

###############################################################
#Call db checking functions depending on db to be used
###############################################################
function check_database() {
	
	if test "$USE_SQLITE" = "1" -o "$NEW_SQLITE" = "1" -o "$ODBC_USE_DB" = "SQLITE"; then
		check_sqlite
	elif test "$USE_ESQLI" = "1" -o "$NEW_IFMX" = "1" -o "$ODBC_USE_DB" = "IFX"; then
		check_informix
	elif test "$USE_MYSQL" = "1" -o "$NEW_MYSQL" = "1" -o "$ODBC_USE_DB" = "MYSQL"; then
		check_mysql
	elif test "$USE_PG" = "1" -o "$NEW_PG" = "1" -o "$ODBC_USE_DB" = "PG"; then
		check_postgresql
	elif test "$USE_SAP" = "1" -o "$NEW_SAP" = "1" -o "$ODBC_USE_DB" = "SAP"; then
		check_sap
	elif test "$USE_ECG" = "1" -o "$NEW_INGRES" = "1" -o "$ODBC_USE_DB" = "INGRES"; then
		check_ingres
	elif test "$USE_SQLSERVER" = "1" -o "$NEW_SQLSERVER" = "1" -o "$ODBC_USE_DB" = "SQLSERVER"; then
		check_sqlserver
	elif test "$USE_ORACLE" = "1" -o "$NEW_ORACLE" = "1" -o "$ODBC_USE_DB" = "ORACLE"; then
		check_oracle
	elif test "$USE_DB2" = "1" -o "$NEW_DB2" = "1" -o "$ODBC_USE_DB" = "DB2"; then
		check_db2
	elif test "$USE_PG8" = "1" -o "$NEW_PG8" = "1"; then
		check_pg8
	else
		warning "Database type not checked or set"
	fi
	
	if test "$IS_ODBC_MANAGER" = "1"; then
		check_odbc
	fi
	
	check_cnv_file

}

check_database

#Now exit if we where just asked to create new ODBC database
#Has to be here, because ODBC db can be any of above types
if test "$NEW_ODBC" = "1"; then
	exit
fi


# --------------------------------- EOF -----------------------------------
