
##############################################################################
#                           Check if we have the database required
##############################################################################

######################
#Check and create SQLite db
SQLITE_DB="$AUBITDIR_UNIX/$TEST_DB.db"

if test "$USE_SQLITE" = "1" -o "$ODBC_USE_DB" = "SQLITE"; then
	if ! test -f $SQLITE_DB -o "$NEW_SQLITE" = "1"; then
		rm -f $SQLITE_DB > /dev/null 2>&1
		echo "creating SQLite testing database..."
		cat testdb.sql | sqlite $SQLITE_DB
        RET=$?
		if test -f $SQLITE_DB || test "$RET" != "0" ; then
			echo "created SQLite testing database:"
			echo "$SQLITE_DB"
        else
			echo "ERROR creating SQLite testing database ($RET):"
			echo "$SQLITE_DB"
            exit 5
        fi
    fi
	if test "$NEW_SQLITE" = "1"; then
        exit 0
    fi

	#remember to account for this scritp cd-ing into test directory
	#when setting relative DBPATH to database file
	if test "$PLATFORM" = "MINGW"; then
		DBPATH="d:/cygwin$AUBITDIR_UNIX/tools"
	else
		DBPATH="$AUBITDIR_UNIX/tools"
    fi
	export DBPATH
fi

######################
#Check and create Informix database

if test "$USE_ESQLI" = "1" -o "$NEW_IFMX" = "1" -o "$ODBC_USE_DB" = "IFX"; then
	if test "`dbaccess -V 2>/dev/null`" = ""; then
		if test "$VERBOSE" = "1" ; then	
	    	echo "WARNING: dbaccess not found - Informix engine missing or remote?"
		fi
		#CSDK on Windows does not include ANY command line tools :-(
		if test "`$SH aubit asql_i.4ae -V 2>/dev/null`" = ""; then
			make -C $AUBITDIR_UNIX/tools/asql asql_i.4ae
			make -C $AUBITDIR_UNIX/tools/asql install
			if test "`$SH aubit asql_i.4ae -V 2>/dev/null`" = ""; then
				echo "Attempt to make asql_i failed. Stop"
				exit 56
			else
				IFX_ENG_REMOTE=1
				DBACCESS="$SH aubit asql_i.4ae"
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
	$DBACCESS $TEST_DB -e > /tmp/tmp.dbaccess 2>&1
   	TEST=`cat /tmp/tmp.dbaccess | sed -e 's/OOPS//g' | grep Databasenotfoundornosystempermission`

	if test "$NEW_IFMX" = "1" -a "$TEST" = ""; then
        echo "Droping Informix database $TEST_DB"
        $DBACCESS - - > /tmp/dropdbtmp.log 2>&1 <<!
        drop database '$TEST_DB'
!
        RET=$?
        if test "$RET" != "0"; then
			echo "Failed (code $RET). See /tmp/dropdbtmp.log"
            exit 2
        else
    	    echo "Droped Informix database $TEST_DB"
        fi
    fi

    if test "$TEST" != "" || test "$NEW_IFMX" = "1"; then
        echo "Creating Informix database $TEST_DB"
        $DBACCESS - - > /tmp/credbtmp.log 2>&1 <<!
        create database '$TEST_DB' with log
!
        RET=$?
        if test "$RET" != "0"; then
            echo "Failed (code $RET). See /tmp/credbtmp.log"
            exit 19
        else
            TMP=`cat /tmp/credbtmp.log | grep "Database created"`
            if test "$TMP" != ""; then
                echo "Database Created"
            else
                echo "Database creation failed. See /tmp/credbtmp.log"
                exit 8
            fi
        fi
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
fi




######################
#Check and create PostgreSQL database

if test "$USE_PG" = "1" -o "$ODBC_USE_DB" = "PG"; then
	if test "$VERBOSE" = "1"; then 
		echo "PostgreSQL specified (PSQL=$PSQL)"
	fi
	if test "`$PSQL -V 2>/dev/null`" = ""; then
        echo "ERROR: $PSQL not found - no PostgreSQL engine?"
        exit 67
    fi

	#Find PostgreSQL data directory of currently running PG engine (PGDATA)
	if test "$PGDATA" = ""; then
		#su -l postgres -s /bin/sh -c "$POSTGRES_BIN/pg_ctl -D $PG_DATA status"
		#We need wide output to get full command line:
		PGDATA=`ps -auxw | grep postmaster | head -1 | awk '{print $14}'`
		if test "$PGDATA" = ""; then
			#This is a backup - but it will probably fail to give us 
			#full command we need to determine PGDATA:
			PGDATA=`ps -ef | grep postmaster | head -1 | awk '{print $11}'`
			echo "WARNING: using 'ps -ef' - 'ps -auxw' returned nothing"
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
				
			else
				if test "$VERBOSE" = "1"; then 
					echo "PGDATA set to $PGDATA"
				fi
			fi
		fi
	else
		if test ! -d "$PGDATA"; then
			echo "WARNING: specified PGDATA ($PGDATA) is not a directory"
			unset PGDATA
		fi
	fi
	
	#Find current PostgreSQL configuration file in sue by currently rinning
	#instance of PG engine (PG_CONF)
	if test -f "$PGDATA/postgresql.conf"; then 
		PG_CONF="$PGDATA/postgresql.conf"
	else
		echo "WARNING: failed to determine PG config file location"
		PG_CONF="unknown"
	fi
	
	echo "\q" | $PSQL -d $TEST_DB > /tmp/tmp.dbaccess 2>&1
	RET=$?
	if test "$RET" != "0"; then 
		echo "$PSQL returned code $RET."
		cat /tmp/tmp.dbaccess
		TEST=`cat /tmp/tmp.dbaccess | grep "could not connect to server"`
		if test "$TEST" != ""; then
			#Try starting local PG engine
			#FIXME - only on SuSE
			rcpostgresql start
		#else
		#	echo "ERROR: unknown fault (1)"		
		#	exit $RET
		fi
		#Try connecting again
		echo "\q" | $PSQL -d $TEST_DB > /tmp/tmp.dbaccess 2>&1
		RET=$?
		if test "$RET" != "0"; then 
			echo "$PSQL returned code $RET."
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
		$POSTGRES_BIN/dropdb $TEST_DB > /tmp/dropdbtmp.log
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
		$POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
        RET=$?
        if test "$RET" != "0"; then
			TMP4=`cat /tmp/credbtmp.log | grep "FATAL:  user"`
			if test "$TMP4" != ""; then 
				#need to create user first - FATAL:  user "root" does not exist
				USERNAME=`whoami`
				echo "Need to create user '$USERNAME' first..."
				SCRIPT=/tmp/pg-create-user.sql
				echo "create user $USERNAME createdb createuser ;" > $SCRIPT
			 	run_sql_script postgres template1 $SCRIPT /tmp/pg-create-user.log postgres
				#we need this for future tests
				$POSTGRES_BIN/createdb $USERNAME > /tmp/credb$USERNAME.log 2>&1
				#xxxxx
				#su postgres
				#$PSQL -d template1
				#template1=# create user root createdb createuser ;

				echo "Again: Creating PostgreSQL database $TEST_DB"
				$POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
				RET=$?
				if test "$RET" != "0"; then
					echo "Failed again (code $RET)."
					cat /tmp/credbtmp.log
					exit 29
				else
					TMP=`cat /tmp/credbtmp.log | grep "CREATE DATABASE"`
					if test "$TMP" != ""; then
						echo "Database Created"
					else
						echo "Database creation failed. See /tmp/credbtmp.log"
						exit 8
					fi
				fi
			else
	            echo "Failed (code $RET)."
				cat /tmp/credbtmp.log
				exit 29
			fi
        else
            TMP=`cat /tmp/credbtmp.log | grep "CREATE DATABASE"`
            if test "$TMP" != ""; then
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

	#################
	#Tests to verify PG is configured as we need it for Informix
	#compatibility
	TMP=`echo 'show datestyle;' | $PSQL -d $TEST_DB | grep -i "informix"`
	if test "$TMP" = ""; then 
		echo "WARNING: PostgreSQL config file ($PG_CONF)"
		echo "does not contain needed setting:"
		echo "datestyle = 'informix, mdy'"
		#should we do that automatically??
		#echo "datestyle = 'informix, mdy'" >> $PG_CONF
		#...and restart pg...?
		if test "$IGNORE_CONF_ERR" != "1"; then 
			echo "STOP. (correct or use -ignore-conf-error to ignore)"
			exit 8
		fi
	fi
	TMP=`echo 'show default_delim;' | $PSQL -d $TEST_DB | grep "\|"`
	if test "$TMP" = ""; then 
		echo "WARNING: PostgreSQL config file ($PG_CONF)"
		echo "does not contain needed setting:"
		echo "default_delim = '|'"
		echo "This must be set *after* you do the initdb"
		#should we do that automatically??
		#echo "datestyle = 'informix, mdy'" >> $PG_CONF
		#...and restart pg...?
		if test "$IGNORE_CONF_ERR" != "1"; then 
			echo "STOP. (correct or use -ignore-conf-error to ignore)"
			exit 8
		fi
	fi
	PG_VERSION=`echo 'show server_version;' | $PSQL -d $TEST_DB | grep "."`
	if test "$VERBOSE" = "1"; then 
		echo "INFO: PG server reported version $PG_VERSION"
	fi
	
	#TODO: determine DB_TYPE from actual version number
	DB_TYPE="PG-IFX-74"
	#DB_TYPE="PG-74"
	#DB_TYPE="PG-80"

	#> You should also initdb with --locale='C' if you want index's to be used
	#> when comparing an indexed column with a string.
	#eg. "initdb --locale='C' -D /usr/local/pgsql/data" ?
	#Is there a way to verify that this was done on currently running PG instance?


	#> One more little gotcha, postgres has a "problem" with using indexes with
	#> bigint's. This has been fixed in 8.0, but in previous versions you
	#> should use where bigintcol='1' , or where bigintcol=int8::1
	
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
	export A4GL_USE_INDICATOR=N

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

fi

######################
#Check and create SAP DB database

if test "$USE_SAP" = "1" || test "$ODBC_USE_DB" = "SAP"; then
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
fi

#######################
#Check if we can use ODBC as defined in $ODBCINI for ODBC managers
if test "$IS_ODBC_MANAGER" = "1"; then

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

fi

#Now exit if we where just asked to create new ODBC database
if test "$NEW_ODBC" = "1"; then
	exit
fi


