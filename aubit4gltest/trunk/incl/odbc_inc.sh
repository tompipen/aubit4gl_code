
##############################################################################
#                           Prepare ODBC settings
##############################################################################
function odbc_init () {
##########################
#Define the ODBCINI environment variable to point at your system wide odbc.ini.
#This will mess up the ability of users to define their own data sources, but
#it seems like ODBCINI is the only way to control where the Informix driver
#looks for it's configuration information. Needed for people that don't have
# $INFORMIXDIR/etc/odbc.ini linked to /etc/odbc.ini
#also see: http://www.unixodbc.org/doc/informix.html
#We also need to use private odbc.ini to avoid messing up the "real" ones
#when playing with DSN entries
#iODBC, for example, does the following:
# 1) Checks $ODBCINI
# 2) Checks $HOME/.odbc.ini
# 3) Checks ~/.odbc.ini (where ~ is obtained from struct passwd)
# 4) Checks system-wide odbc.ini (in /etc by default)
#Obay $ODBCINI: Informix, iODBC, UnixODBC, SqliteODBC, SAP
#WARNING: Ignore $ODBCINI: Postgresql

if ! test -f "$ODBCINI" ; then
	if test "$VERBOSE" = "1"; then
		echo "NOTE: ODBCINI in your environment is invalid:"
		echo "$ODBCINI"
	fi
	unset ODBCINI
fi

if ! test -f "$ODBCINSTINI"; then
	if test "$VERBOSE" = "1"; then
		echo "NOTE: ODBCINSTINI in your environment is invalid:"
		echo "$ODBCINSTINI"
	fi
	unset ODBCINSTINI
fi



#if [ "$NOKILLODBCINI" = "" -a "$ODBCINI" != "" ]; then
if test "$ODBCINI" = "" ; then
	export ODBCINI=$CURR_DIR/etc/odbc.ini
fi

if test "$ODBCINSTINI" = ""; then 
	export ODBCINSTINI=$CURR_DIR/etc/odbcinst.ini
fi


#Removed because it was bugging Mike - I dont remember why was it
#dome in the first place - remind myself to write more comments
#if [ "$ODBCINI" != "" ]; then
#	if ! test -f "$ODBCINI"; then
#		touch $ODBCINI
#	fi
#fi

#########################
#List of ODBC driver shared libraries
DRV_IFX=$INFORMIXDIR/lib/cli/libifcli$SO_EXT
DRV_PG=/usr/lib/libpsqlodbc$SO_EXT
DRV_SQLITE=/usr/local/lib/libsqliteodbc$SO_EXT
DRV_SAP=$SAPDBROOT/interfaces/odbc/lib/libsqlod$SO_EXT

#########################
#Create new odbcinst.ini
if ! test -f "$ODBCINSTINI"; then

	echo " " > $ODBCINSTINI
	echo "[ODBC Drivers]" >> $ODBCINSTINI
	echo "Informix=Installed" >> $ODBCINSTINI
	echo "PostgreSQL=Installed" >> $ODBCINSTINI
	echo "SQLite=installed" >> $ODBCINSTINI
	echo "SAP=installed" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

	echo "[Informix]" >> $ODBCINSTINI
	echo "Description=Informix ODBC driver" >> $ODBCINSTINI
	echo "Driver=$DRV_IFX" >> $ODBCINSTINI
	echo "APILevel=1" >> $ODBCINSTINI
	echo "ConnectFunctions=YYY" >> $ODBCINSTINI
	echo "DriverODBCVer=03.00" >> $ODBCINSTINI
	echo "FileUsage=0" >> $ODBCINSTINI
	echo "SQLLevel=1" >> $ODBCINSTINI
	echo "smProcessPerConnect=Y" >> $ODBCINSTINI
	#[INFORMIX 2.8 32-BIT]
	#Driver          = /opt/informix/lib/cli/iclis09a.so
	#Setup           = /opt/informix/lib/cli/iclis09a.so
	#DriverODBCVer           = 02.50
	#[INFORMIX 3.3 32-BIT]
	#Driver          = /opt/informix/lib/cli/iclis09b.so
	#Setup           = /opt/informix/lib/cli/iclis09b.so
	#DriverODBCVer           = 03.00
	echo " " >> $ODBCINSTINI

	echo "[PostgreSQL]" >> $ODBCINSTINI
	echo "Description=PostgreSQL ODBC driver" >> $ODBCINSTINI
	echo "Driver=$DRV_PG" >> $ODBCINSTINI
	echo "APILevel=1" >> $ODBCINSTINI
	echo "ConnectFunctions=YYY" >> $ODBCINSTINI
	echo "DriverODBCVer=03.00" >> $ODBCINSTINI
	echo "FileUsage=1" >> $ODBCINSTINI
	echo "SQLLevel=1" >> $ODBCINSTINI
	echo "smProcessPerConnect=Y" >> $ODBCINSTINI
#	echo "Setup=/usr/lib/libodbcpsqlS.so" >> $ODBCINSTINI
	echo "Debug=0" >> $ODBCINSTINI
	echo "CommLog=1" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

	echo "[SQLite]" >> $ODBCINSTINI
	echo "Description=SQLite ODBC driver" >> $ODBCINSTINI
	echo "Driver=$DRV_SQLITE" >> $ODBCINSTINI
	echo "APILevel=1" >> $ODBCINSTINI
	echo "ConnectFunctions=YYY" >> $ODBCINSTINI
	echo "DriverODBCVer=03.00" >> $ODBCINSTINI
	echo "FileUsage=0" >> $ODBCINSTINI
	echo "SQLLevel=1" >> $ODBCINSTINI
	echo "smProcessPerConnect=Y" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

	echo "[SAP]" >> $ODBCINSTINI
	echo "Description=SAP DB ODBC driver" >> $ODBCINSTINI
	echo "Driver=$DRV_SAP" >> $ODBCINSTINI
	echo "APILevel=1" >> $ODBCINSTINI
	echo "ConnectFunctions=YYY" >> $ODBCINSTINI
	echo "DriverODBCVer=03.00" >> $ODBCINSTINI
	echo "FileUsage=1" >> $ODBCINSTINI
	echo "SQLLevel=1" >> $ODBCINSTINI
	echo "smProcessPerConnect=Y" >> $ODBCINSTINI
#	echo "Setup=/usr/lib/libodbcdrvcfg1S.so" >> $ODBCINSTINI
	echo "CPTimeout=" >> $ODBCINSTINI
	echo "CPReuse=" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

	echo "[ODBC]" >> $ODBCINSTINI
	echo "Trace=No" >> $ODBCINSTINI
	echo "Trace File=/tmp/sql.log" >> $ODBCINSTINI
	echo "Pooling=No" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

	echo "[default]" >> $ODBCINSTINI
	echo "Description=Dummy driver to catch attemts to read default entry" >> $ODBCINSTINI
	echo "Driver=/opt/crap/libcrap.so" >> $ODBCINSTINI
	echo " " >> $ODBCINSTINI

fi

######################
#Tried, did not wor, reason unknown - ODBC managers would just go back to
#system odbc.ini [default] section to get driver setting
#USE_ODBCINSTINI=1
if test "$USE_ODBCINSTINI" = "1"; then
	#Use odbcinst.ini to hold driver details, instead of having to define
    #them with each DSN
	DRV_IFX=Informix
	DRV_PG=PostgreSQL
	DRV_SQLITE=SQLite
	DRV_SAP=SAP
fi


######################
#Check and create $ODBCINI DSN, see if we need to create database too

#directly linked plug-ins need DSN $ODBCINI entry despite ODBC driver 
#being linked to it directly - but Driver= setting is used only by ODBC managers.
#Informix one needs just Database and Servername parameters, SQLite needs just Database

if test "$IS_ODBC" = "1"; then

    #Some drivers need explicit UID/PWD to connect
	if test "$SQLPWD" = ""; then
		SQLPWD=`$AUBITDIR_UNIX/bin/aubit-config$EXE_EXT SQLPWD`
		if test "$SQLPWD" = ""; then
	        echo "ERROR: Aubit setting SQLPWD is empty. Stop."
	        exit 4
	    fi
    fi

	if test "$SQLUID" = ""; then
		SQLUID=`$AUBITDIR_UNIX/bin/aubit-config$EXE_EXT SQLUID`
		if test "$SQLUID" = ""; then
			echo "ERROR: Aubit setting SQLUID is empty. Stop."
	        exit 4
	    fi
    fi


	#This is probably redundant since we did not check if db exists ($TEST)
    #and we cannot do that before we have odbc.ini, and we cannot check access
    #anyway when using directly linked ODBC plug-ins. There is also a same
    #check few lines below:
	#see if we are to create new database too:
	if test "$NEW_ODBC" = "1" && test "$TEST" = ""; then
        echo "Re-creating ODBC database $TEST_DB"

		if test "$ODBC_USE_DB" = "IFX"; then
			NEW_IFMX=1
        elif test "$ODBC_USE_DB" = "PG"; then
			NEW_PG=1
		elif test "$ODBC_USE_DB" = "SQLITE"; then
			NEW_SQLITE=1
		elif test "$ODBC_USE_DB" = "SAP"; then
			NEW_SAP=1
		else
            echo "ERROR: Invalid ODBC_USE_DB=$ODBC_USE_DB Stop."
            exit 4
        fi
	fi

    #check $ODBCINI for DSN
    if test -f $ODBCINI; then
        ODBC_INI_PATH=$ODBCINI
        TMP=`grep "\[$TEST_DB\]" $ODBCINI`
        if test "$TMP" != ""; then
            HAS_ODBC_INI=1
        fi
    fi

    if test "$NEW_ODBC" = "1" || test "$HAS_ODBC_INI" != "1"; then

		if test "$HAS_ODBC_INI" = "1"; then
			if test "$VERBOSE" = "1"; then
				echo "Found DSN for $TEST_DB"
            fi
		else
            if test "$ODBC_INI_PATH" != ""; then
				echo "Creating DSN for $TEST_DB"

				#Common DSN entries:
				echo "" >> $ODBC_INI_PATH
				echo "[$TEST_DB]" >> $ODBC_INI_PATH
				echo "Description=Aubit automated build tests DSN"  >> $ODBC_INI_PATH
				echo "ReadOnly=0"  >> $ODBC_INI_PATH

                #this can all be changed later depending on driver, but it does
                #not hurt to set it right here anyway:
				if test "$ODBC_USE_DB" = "IFX"; then
					echo "Driver=$DRV_IFX" >> $ODBC_INI_PATH
					echo "Database=$TEST_DB"  >> $ODBC_INI_PATH
					echo "Servername=$INFORMIXSERVER"  >> $ODBC_INI_PATH
					#Optional stuff:
					#LogonID=xxx
					#pwd=xxx
					#TRANSLATIONDLL=/opt/informix/lib/esql/igo4a304.so
		        elif test "$ODBC_USE_DB" = "PG"; then
					echo "Driver=$DRV_PG"  >> $ODBC_INI_PATH
					echo "Database=$TEST_DB"  >> $ODBC_INI_PATH
					echo "Servername=localhost"  >> $ODBC_INI_PATH
					#Optional stuff:
					#echo "Port=5432"  >> $ODBC_INI_PATH
					#echo ";Debug=1"  >> $ODBC_INI_PATH
					#echo ";CommLog=1"  >> $ODBC_INI_PATH
					#echo ";Username=xxx"  >> $ODBC_INI_PATH
					#echo ";Password=xxx"  >> $ODBC_INI_PATH
				elif test "$ODBC_USE_DB" = "SQLITE"; then
					echo "Driver=$DRV_SQLITE"  >> $ODBC_INI_PATH
					echo "Database=/opt/aubit/aubit4glsrc/tools/$TEST_DB.db"  >> $ODBC_INI_PATH
					echo "Servername=localhost"  >> $ODBC_INI_PATH
					#Optional stuff:
					#echo "; optional lock timeout in milliseconds"  >> $ODBC_INI_PATH
					#echo "Timeout=2000"  >> $ODBC_INI_PATH
					#echo "; optional turn threading support on"  >> $ODBC_INI_PATH
					#echo "Threaded=1"  >> $ODBC_INI_PATH
				elif test "$ODBC_USE_DB" = "SAP"; then
					echo "Driver=$DRV_SAP"  >> $ODBC_INI_PATH
					echo "Database=$TEST_DB"  >> $ODBC_INI_PATH
					echo "Servername=localhost"  >> $ODBC_INI_PATH
					#Optional stuff:
					#ServerNode=localhost
					#ServerDB=TST
					#Port=
					#;This is ignored by SAP DB driver, but used by unixODBC:
					#Host		= localhost
					#Database	= TST
					#Trace 		= Yes
					#TraceFileName 	= /tmp/odbctrace2.log
				else
		            echo "ERROR: Invalid ODBC_USE_DB=$ODBC_USE_DB Stop."
		            exit 4
		        fi

                #must make sure we have CR.LF on the end of the file:
                echo ""  >> $ODBC_INI_PATH
            else
                echo "ERROR: canot find $ODBCINI. Stop."
                exit 5
            fi
        fi

		if test "$NEW_ODBC" = "1"; then
			#we still need to create actual database:
			if test "$ODBC_USE_DB" = "IFX"; then
				NEW_IFMX=1
	        elif test "$ODBC_USE_DB" = "PG"; then
				NEW_PG=1
			elif test "$ODBC_USE_DB" = "SQLITE"; then
				NEW_SQLITE=1
			elif test "$ODBC_USE_DB" = "SAP"; then
				NEW_SAP=1
	        else
	            echo "ERROR: Invalid ODBC_USE_DB=$ODBC_USE_DB Stop."
	            exit 4
	        fi
		fi
    fi
fi

######################
#Check ODBC DSN stuff in $ODBCINI:
if test "$IS_ODBC" = "1"; then

	######################
	#Check if we have DSN now:
	if test -f $ODBCINI; then
        ODBC_INI_PATH=$ODBCINI
        TMP=`grep "\[$TEST_DB\]" $ODBC_INI_PATH`
        if test "$TMP" != ""; then
            HAS_ODBC_INI=1
        fi
    fi

	if test "$HAS_ODBC_INI" = "1"; then
		if test "$VERBOSE" = "1"; then
			echo "Found DSN for $TEST_DB"
        fi
    else
        if test "$ODBC_INI_PATH" != ""; then
            echo "ERROR: DSN for $TEST_DB not found. Stop."
            exit 4
        else
            echo "ERROR: canot find $ODBCINI. Stop."
            exit 5
        fi
    fi

	######################
	#Check ODBC DSN for SQLite database file path "Database="
	LOOK_FOR="Database=/opt/aubit/aubit4glsrc/tools/$TEST_DB.db"
	if test "$USE_SQLITEODBC" = "1" || test "$ODBC_USE_DB" = "SQLITE"; then
		#check if Database setting is correct for SQLite
	    TMP=`grep "$LOOK_FOR" $ODBC_INI_PATH`
		if test "$TMP" = ""; then
            #Not correct-fix it
	        TMP=`grep "Database=$TEST_DB" $ODBC_INI_PATH`
	        if test "$TMP" != ""; then
	            #Found Database=$TEST_DB - replace it
				if test "$SILENT" != "1"; then
					echo "Replacing '$TMP' with '$LOOK_FOR' in $ODBC_INI_PATH"
                fi
	            REPLACE=$(echo $LOOK_FOR | sed -e "s/\//\\\\\//g")
	            sed -e "/^$TMP/s/$TMP/$REPLACE/" $ODBC_INI_PATH > /tmp/odbc.ini
	            mv /tmp/odbc.ini $ODBC_INI_PATH
	        else
				echo "ERROR: Cannot find 'Database=' setting. Stop."
	            exit 5
	        fi
	    else
			if test "$SILENT" != "1"; then
				echo "Database setting OK ($TMP)"
            fi
	    fi
	else
		#Not SQLiteODBC, DSN must not include path
	    #check if Database setting is correct for non-SQLite ODBC drivers
	    TMP=`grep "$LOOK_FOR" $ODBC_INI_PATH`
	    if test "$TMP" != ""; then
			TMP="Database=$TEST_DB"
		    REPLACE=$(echo $LOOK_FOR | sed -e "s/\//\\\\\//g")
			if test "$SILENT" != "1"; then
				echo "Replacing '$LOOK_FOR' with '$TMP' in $ODBC_INI_PATH"
            fi
            sed -e "/^$REPLACE/s/$REPLACE/$TMP/" $ODBC_INI_PATH > /tmp/odbc.ini
            mv /tmp/odbc.ini $ODBC_INI_PATH
	    else
			if test "$SILENT" != "1"; then
				echo "Database setting OK"
            fi
	    fi
	fi


	######################
	#Check ODBC DSN for Informix "Servername="
	LOOK_FOR="Servername=$INFORMIXSERVER"
	if test "$USE_IFXODBC" = "1" || test "$ODBC_USE_DB" = "IFX"; then
	    #check if Servername setting is correct for Informix
	    TMP=`grep "$LOOK_FOR" $ODBC_INI_PATH`
	    if test "$TMP" = ""; then
	        TMP=`grep "Servername=localhost" $ODBC_INI_PATH`
	        if test "$TMP" != ""; then
				if test "$SILENT" != "1"; then
					echo "Replacing '$TMP' with '$LOOK_FOR' in $ODBC_INI_PATH"
                fi
	            sed -e "/^$TMP/s/$TMP/$LOOK_FOR/" $ODBC_INI_PATH > /tmp/odbc.ini
	            mv /tmp/odbc.ini $ODBC_INI_PATH
	        else
	            echo "ERROR: Cannot find 'Servername=' setting. Stop."
	            exit 5
	        fi
	    else
			if test "$SILENT" != "1"; then
				echo "Servername setting OK ($TMP)"
            fi
	    fi
	else
		#Not InformixODBC, Servername must be "localhost"
	    #check if Servername setting is correct for non-Informix ODBC drivers
	    TMP=`grep "$LOOK_FOR" $ODBC_INI_PATH`
	    if test "$TMP" != ""; then
	        TMP="Servername=localhost"
			if test "$SILENT" != "1"; then
				echo "Replacing '$LOOK_FOR' with '$TMP' in $ODBC_INI_PATH"
            fi
	        sed -e "/^$LOOK_FOR/s/$LOOK_FOR/$TMP/" $ODBC_INI_PATH > /tmp/odbc.ini
	        mv /tmp/odbc.ini $ODBC_INI_PATH
	    else
			if test "$SILENT" != "1"; then
				echo "Servername setting OK"
            fi
	    fi
	fi

	######################
	#Check ODBC DSN/odbcinst.ini for correct "Driver="
    #Need to do this only for managers because ODBC drivers don't read
    #Driver= setting anyway
	if test "$IS_ODBC_MANAGER" = "1"; then
		LOOK_FOR="Servername=$INFORMIXSERVER"

		if test "$ODBC_USE_DB" = "IFX"; then
			LOOK_FOR="Driver=$DRV_IFX"
	    elif test "$ODBC_USE_DB" = "PG"; then
			LOOK_FOR="Driver=$DRV_PG"
		elif test "$ODBC_USE_DB" = "SQLITE"; then
			LOOK_FOR="Driver=$DRV_SQLITE"
		elif test "$ODBC_USE_DB" = "SAP"; then
			LOOK_FOR="Driver=$DRV_SAP"
		else
		    echo "ERROR: Invalid ODBC_USE_DB=$ODBC_USE_DB Stop."
			exit 4
		fi

	    TMP=`grep "$LOOK_FOR" $ODBC_INI_PATH`

	    if test "$TMP" = ""; then
			TMP=`grep "Driver=" $ODBC_INI_PATH`
			if test "$SILENT" != "1"; then
				echo "Replacing '$TMP' with '$LOOK_FOR' in $ODBC_INI_PATH"
            fi

			if test "$USE_ODBCINSTINI" = "1"; then
                #using plain names
                REPLACE_WITH=$LOOK_FOR
                REPLACE=$TMP
            else
                #using file paths
				REPLACE_WITH=$(echo $LOOK_FOR | sed -e "s/\//\\\\\//g")
                REPLACE=$(echo $TMP | sed -e "s/\//\\\\\//g")
			fi
			sed -e "/^$REPLACE/s/$REPLACE/$REPLACE_WITH/" $ODBC_INI_PATH > /tmp/odbc.ini
	        RET=$?
            if test "$RET" != "0"; then
                echo "ERROR in sed. Stop."
				echo "TMP=$TMP"
				echo "REPLACE_WITH=$REPLACE_WITH"
				echo sed -e "/^$REPLACE/s/$REPLACE/$REPLACE_WITH/"
                exit 55
            fi
			mv /tmp/odbc.ini $ODBC_INI_PATH
	    else
			if test "$SILENT" != "1"; then
				echo "Driver setting OK"
	        fi
	    fi
    fi
fi
} #function odbc_init ()

if test "$IS_ODBC" = "1" -o "$IS_ODBC_MANAGER" = "1"; then
	odbc_init
fi	


