
##############################################################################
#                Runing multiple configuration of tests (-alltests)
##############################################################################

if test "$ALL_TESTS_NONDB" = "1" || test "$ALL_TESTS_DB" = "1"; then
#Running all tests - initialise results file,defaults and counters:
	echo "0" > ./fail.cnt
    echo "0" > ./pass.cnt

    echo "" > ./alldb.log
    echo "===================== Test results ========================" >> ./alldb.log
    echo "" >> ./alldb.log
	#echo "Platform: $PLATFORM" >> ./alldb.log
	echo "Flags: $FLAGS  Platform: $PLATFORM Date:$DATE" >> ./alldb.log
	echo "  PWD=$CURR_DIR" >> ./alldb.log

    echo "" >> ./alldb.log

    #set the common flags we will use to run tests - we will add test
	#configuration specific ones later, as needed
	#-alldbrun = is to indicate to called script that it was called from 'alltests' loop
    #-defaults = apply platform specific defaults
    #-short = show only short summary
    #-noecho = Don't show any non-critical messages while running tests
	#-silent = don't show output of programs execution
	COMMON_FLAGS="-defaults -short -alldbrun -silent -noecho"
fi

if test "$ALL_TESTS_NONDB" = "1"; then
#Running all tests - run non-db tests
    ######################
    #First non-db tests with different packers (cant test PACKER_PERL -
	#output only) and UI's plus pcode:
    #This is not 100% what we want, since at leaset some db tests will use
    #packers (forms) too, and pcode/EC should be tested on everything, but
    #this would force us to run EVERYTHING in the loop, taking too much
    #ime - maybe one day...
    NODB_LIST="-xml -packed -xdr -console -pcode"
    for a in $NODB_LIST; do
        sh run_tests -nodb $a $COMMON_FLAGS $RUN_ONE
        RET=$?
        if test "$RET" != "0"; then
            echo "EXIT with error $RET on $a (non-db)"  >> ./alldb.log
            if test "$STOP_ON_EXIT"; then
                echo "Stop after EXIT"
                exit 44
            fi
        fi
    done
fi

if test "$ALL_TESTS_DB" = "1"; then
#Running all tests - run all db tests
	#for debugging - you can turn on/off particular class of db tests here:
	ODBC_U=1
	ODBC_I=1
	DB_NATIVE=1
	ODBC_DIRECT=1
	DB_EC=1

    ######################
    #native plug-ins and directly linked ODBC plug-ins
	if test "$DB_NATIVE" = "1"; then
        DB_PLUGIN="-sqlite -esqli -pg"
    fi
    if test "$PLATFORM" = "UNIX" && test "$ODBC_DIRECT" = "1"; then
        DB_PLUGIN="$DB_PLUGIN -ifxodbc -sqliteodbc -pgodbc -sapodbc"
    fi
    for a in $DB_PLUGIN; do
        sh run_tests -onlydb $a $COMMON_FLAGS $RUN_ONE
        RET=$?
        if test "$RET" != "0"; then
            echo "EXIT with error $RET on $a (db native)"  >> ./alldb.log
            if test "$STOP_ON_EXIT"; then
                echo "Stop after EXIT"
                exit 44
            fi
        fi
    done

    #######################
    #ODBC managers, for each available backend:
    DB_LIST="-odbcdb-ifx -odbcdb-pg -odbcdb-sqlite -odbcdb-sap"
    if test "$PLATFORM" != "UNIX"; then
        #we are on Windows - only ODBC manager is native Windows odbc32
        for a in $DB_LIST; do
            sh run_tests -onlydb -winodbc $a $COMMON_FLAGS $RUN_ONE
            RET=$?
            if test "$RET" != "0"; then
                echo "EXIT with error $RET on $a (ODBC manager-Windows)"  >> ./alldb.log
                if test "$STOP_ON_EXIT"; then
                    echo "Stop after EXIT"
                    exit 44
                fi
            fi
        done
    else
        #we are on UNIX
        for a in $DB_LIST; do
            #UnixODBC
            if test "$ODBC_U" = "1"; then
				#echo "---------------------------------------"
                sh run_tests -onlydb -unixodbc $a $COMMON_FLAGS $RUN_ONE
                RET=$?
                if test "$RET" != "0"; then
                    echo "EXIT with error $RET on $a (unixODBC)"  >> ./alldb.log
                    if test "$STOP_ON_EXIT"; then
                        echo "Stop after EXIT"
                        exit 44
                    fi
                fi
            fi

            #iODBC
            if test "$ODBC_I" = "1"; then
                sh run_tests -onlydb -iodbc $a $COMMON_FLAGS $RUN_ONE
                RET=$?
                if test "$RET" != "0"; then
                    echo "EXIT with error $RET on $a (iODBC)"  >> ./alldb.log
                    if test "$STOP_ON_EXIT"; then
                        echo "Stop after EXIT"
                        exit 44
                    fi
                fi
            fi
        done
    fi

    #######################
    #now EC output:
	if test "$DB_EC" = "1"; then
	    EC_LIST="-eci -ecs -ecp -ecq"
        for a in $EC_LIST; do
			sh run_tests -onlydb $a $COMMON_FLAGS $RUN_ONE
	        RET=$?
	        if test "$RET" != "0"; then
	            echo "EXIT with error $RET on $a (EC)"  >> ./alldb.log
	            if test "$STOP_ON_EXIT"; then
	                echo "Stop after EXIT"
	                exit 44
	            fi
	        fi
        done
    fi
fi

if test "$ALL_TESTS_NONDB" = "1" || test "$ALL_TESTS_DB" = "1"; then
#Running all tests - finish results file and exit
    FAIL_CNT_TOT=`cat ./fail.cnt`
    PASS_CNT_TOT=`cat ./pass.cnt`

    echo "Total passed=$PASS_CNT_TOT Total failed=$FAIL_CNT_TOT" >> ./alldb.log
    echo "" >> ./alldb.log
    echo "===================== End of Test results ===================" >> ./alldb.log
    echo "" >> ./alldb.log

    rm -f ./fail.cnt
    rm -f ./pass.cnt

    cat ./alldb.log
    
    #exit this script - we are done
	exit
fi
