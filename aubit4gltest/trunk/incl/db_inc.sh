
##############################################################################
#                           Check if we have the database required
##############################################################################

######################
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

}


if test "$USE_SQLITE" = "1" -o "$ODBC_USE_DB" = "SQLITE"; then
	check_sqlite
fi

######################
#Check and create Informix database
if test "$USE_ESQLI" = "1" -o "$NEW_IFMX" = "1" -o "$ODBC_USE_DB" = "IFX"; then
	check_informix
fi

######################
#Check and create PostgreSQL database
if test "$USE_PG" = "1" -o "$ODBC_USE_DB" = "PG"; then
	check_postgresql
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
if test "$USE_ECG" = "1" -o "$ODBC_USE_DB" = "INGRES"; then
	DB_TYPE=INGRES
fi

#Now exit if we where just asked to create new ODBC database
if test "$NEW_ODBC" = "1"; then
	exit
fi


