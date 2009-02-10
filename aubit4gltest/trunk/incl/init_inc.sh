##############################################################################
#                           Initialise
##############################################################################

#######################
#Set defaults

if test "$SH" = ""; then 
	if test "$SHELL" = ""; then
		SH="bash"
		SHELL="$SH"
	else
		SH="$SHELL"
	fi
else
	if test "$SHELL" = ""; then
		SHELL="$SH"
	fi
fi

CURR_DIR=`pwd`
export A4GL_PRG=".4ae"

#Note that for some utillity functions, like getting the list of features used 
#In 4GL code, we need to ALLWAYS use 4glc directly
A4GL_FGLC=4glc
A4GL_FGLPC=4glpc

if test "$FGLC" = ""; then 
	export FGLC=$A4GL_FGLC
	#We can't make 4glpc default ATM as it messes up debug.out file by 
	#writing to the same file 4glc is writing - which makes it very hard 
	#to debug things
	export FGLC=$A4GL_FGLPC
fi
#Let Amake rules know:
if test "$FGLC" = "$A4GL_FGLPC"; then
	export USE_4GLPC="1"
elif test "$FGLC" = "$A4GL_FGLC"; then
	export USE_4GLPC=""
else
	echo "Eh?"
	exit 5
fi


#This tests failed when using 4glpc, but worked with 4glc:
#95 107 108 110 207 598 626 627 628 630 631 632 633 634 635 636 695 1060 1208 1223 1228 1245

#This tests failed with 4glc, but worked with 4glpc
#14 72 585 586 588 1210 1227 1250 1416 1417

USE_COMP=aubit
MAKE_TARGET=run
MAKE=gmake
DATE=`date`
DB_HAS_TRANSACTION=NULL
TEST_DB="test1"
#decimals work ok with 'LC_NUMERIC' set to C
#apparently they fail with anything else, like when LANG is set to 'de_DE@euro'
export LC_NUMERIC="C"
FGIUSR_4JS_C="./bin/fgiusr-4js.c"
FGIUSR_IFX_C="./bin/fgiusr-ifx.c"
OUTPUT_LOG="output.log"
ERROR_LOG="error.log"
export MAKEFILE_COMMON="$CURR_DIR/incl/Makefile-common"
if test "$COMSPEC" != ""; then
	FIND=/bin/find
	SORT=/bin/sort
else
	FIND=find
	SORT=sort
fi

IFX_RUNNER="$CURR_DIR/bin/testfglgo"
FJSRUNNER="$CURR_DIR/bin/testfglrun"

CATALOGUE_UNL_FILE="$CURR_DIR/docs/catalogue.unl"

#######################
#Set and check AUBITDIR
if test "$AUBITDIR" = ""; then
	AUBITDIR=`aubit-config AUBITDIR 2>/dev/null`
	if test "$AUBITDIR" = ""; then
		echo "ERROR: AUBITDIR not set and aubit-config not installed"
		exit 3
	else
		export AUBITDIR
	fi
fi
if test -f "$AUBITDIR/bin/aubit" ; then 
	if [ ! -x "$AUBITDIR/bin/aubit" ]; then
    	chmod a+x $AUBITDIR/bin/aubit
	fi
else
	echo "ERROR: invalid AUBITDIR ($AUBITDIR)"
	exit 4
fi

#Even on Windows we have to use UNIX style path in this script. Since when using 
#MinGW AUBITDIR must be Windows-stile, we must distinguish between them and use
#only AUBITDIR_UNIX in this script
if test "$COMSPEC" != ""; then 
	A4GL_PATH_SEP=":"
	#convert AUBITDIR to cygwin path so shell can find executables
	AUBITDIR_UNIX=`cygpath -u "$AUBITDIR"`
else
	AUBITDIR_UNIX="$AUBITDIR"
fi

if test "$AUBITDIR_SRC" = ""; then
	#maybe current aubitdir is aubit source dir?
	if test -f "$AUBITDIR/lib/libaubit4gl/io.c"; then 
		AUBITDIR_SRC="$AUBITDIR"
	else
		AUBITDIR_SRC="`aubit-config AUBITDIR_SRC`"
		if test "$AUBITDIR_SRC" = ""; then
			#Just guessing
			AUBITDIR_SRC=/opt/aubit/aubit4glsrc
		fi
	fi
fi
if test -d "$AUBITDIR_SRC"; then  
	CUSTOM="$AUBITDIR_SRC/lib/extra_libs/infx_dump_screen/infx"
	SRC_CUSTOM="$CUSTOM.c"
	OBJ_CUSTOM="$CUSTOM.o"
	#Used when linking Querix
	export SRC_CUSTOM
else
	echo "**"
	echo "** WARNING: Aubit source code directory setting (AUBITDIR_SRC)"
	echo "** is invalid: $AUBITDIR_SRC"
	echo "**"
	AUBITDIR_SRC=""	
fi

HOSTNAME=`hostname`
USERNAME=`whoami`

#Determine POSTGRESDIR and PSQL for PostgreSQL database engine
#Must be here because PSQL is used before we reach dedicated PG section,
#in running scripts function and to set default database when not specified

FLAGS="$@"
for a in $FLAGS; do
   case $a in
	-pg-inst=*) #Use Postgres installed at particular location, and not
				#the one potentially available at system locations lile
				#/ust/bin /usr/lib etc
		PG_LOCATION=`echo $a | sed 's/=/ /' | awk '{print $2}'`
		if ! test -d $PG_LOCATION/bin; then
			echo "ERROR: $PG_LOCATION/bin does not exist. STOP"
			exit 1
		fi
		#if ! test "$NO_ECHO"; then
		if test "$VERBOSE" = "1"; then
			echo "** "
			echo "** WARNING:"
			echo "** Using PG tools installed at $PG_LOCATION."
			echo "** PLEASE MAKE SURE YOUR RUNNING postmaster is the"
			echo "** one installed there - othewise I'll be mixing "
			echo "** one database engine with another set ot tools and libraries!"
			echo "** "
        fi
		#Make sure this location takes priority when looking for programs
		#and libraries. NOTE THAT IF WE ARE INVOKING ANY PROGRAMS POR LIBRARIES
		#THAT DO NOT EXIST AT -pg-ins, WE WILL STILL BE SERVED WHATEVER IS INSTALLED
		#IN SYSTEM TRUSTED PATHS!
		PATH="$PG_LOCATION/bin:$PATH" 
		LD_LIBRARY_PATH="$PG_LOCATION/lib:$LD_:IBRARY_PATH"
		POSTGRESDIR="$PG_LOCATION"
		export PATH
		export LD_LIBRARY_PATH
		export POSTGRESDIR
	esac
done

PSQL=psql
if test "$POSTGRESDIR" = ""; then
	POSTGRESDIR=`aubit-config POSTGRESDIR`
	if test ! -d "$POSTGRESDIR"; then
		if test "$VERBOSE" = "1"; then
			echo "WARNING: POSTGRESDIR reported by aubit-config is invalid ($POSTGRESDIR)"
		fi
		
		POSTGRESDIR=`ps -efw | grep postmaster | head -n 1 | awk '{print $8}'`
		POSTGRESDIR=`dirname $POSTGRESDIR`
		POSTGRESDIR=`dirname $POSTGRESDIR`
	fi
fi
if test "$POSTGRESDIR" != ""; then
	if test -d "$POSTGRESDIR"; then
		export POSTGRESDIR
		export LD_LIBRARY_PATH="$POSTGRESDIR/lib:$LD_LIBRARY_PATH"
		if test "$VERBOSE" = "1"; then
			echo "Note: POSTGRESDIR set to ($POSTGRESDIR)"
		fi
		if test -f "$POSTGRESDIR/bin/postgres" ; then
			#It can be only ecpg installation there, so check if actuall
			#engine and tools are also there
			POSTGRES_BIN=$POSTGRESDIR/bin
			PSQL="$POSTGRES_BIN/psql"
		fi
	else
		echo "WARNING: POSTGRESDIR is invalid ($POSTGRESDIR)"
	fi
else
	echo "WARNING: POSTGRESDIR is empty"
fi

if test "$COMSPEC" != ""; then
	PSQL=`cygpath -u "$PSQL"`
	POSTGRES_BIN_CYG=`cygpath -a "$POSTGRES_BIN"`
	export PATH="$POSTGRES_BIN_CYG:$PATH"
	#echo $PATH
	#exit
fi


#define emphasis characters for terminal display
a4gl_shtool=$AUBITDIR_SRC/tools/project/shtool
if test -f $a4gl_shtool; then
	T_MD=`$a4gl_shtool echo -n -e %B 2>/dev/null`
	T_ME=`$a4gl_shtool echo -n -e %b 2>/dev/null`
fi

#######################
#See what platform are we on:
#FIXME: Why is this causing "mingw32-gcc: not found" on CygWin ?????
TMP=`mingw32-gcc --version 2>/dev/null`
if test "$TMP" != ""; then
    PLATFORM=MINGW
	#Aubit programs compiled with MinGW GCC understand only Windows-style paths
	#we allready checked AUBITDIR - no longer needed
	#export AUBITDIR="D:/cygwin$AUBITDIR"
    EXE_EXT=.exe
	MAKE=make
	#echo $AUBITDIR_UNIX
	#echo $AUBITDIR
	#NOTE: this will get converted back to Windows native paths 
	#by CygWin shell when incoking native Windows executables
	export PATH="$PATH:$AUBITDIR_UNIX/lib:$AUBITDIR_UNIX/bin"
	#echo $PATH
	#exit
	
	BLACKLIST_TESTS="$BLACKLIST_TESTS $BLACKLIST_TESTS_MINGW"
	EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS $EXPECT_TO_FAIL_TESTS_MINGW"	
else
    if test "$COMSPEC" != ""; then
        PLATFORM=CYGWIN
        EXE_EXT=.exe
		#getopt_long() not working on Cygwin:
		export FGLC=4glpc
		MAKE=make
    else
        PLATFORM=UNIX
    fi
fi
#echo $BLACKLIST_TESTS
#exit
#######################
#Check if we have TUI lib, set AUBITDIR:
#fixme - we now have UI_TUIN on MinGW (PDcurses)
if test "$PLATFORM" = "MINGW"; then
#Not needed any more - use TUIN
if test "1" = "disabled"; then
	#MinGw don't have Curses, but we can try using CygWin one:
	if ! test -f $AUBITDIR_UNIX/lib/libUI_TUI.dll; then
        #this file is placed in /tmp by aubitbuild.sh ONLY, so if you want to update it
        #you will need to do it manually
		if test -f /tmp/libUI_TUI.dll; then
			cp /tmp/libUI_TUI.dll $AUBITDIR_UNIX/lib
	    else
	        echo "Can't find /tmp/libUI_TUI.dll - Stop."
	        exit 5
	    fi
    fi
fi
fi

#######################
#Define platform defaults
if test "$PLATFORM" = "MINGW"; then
	#DEFAULT_FLAGS="-xml -nodb -nographic"
	#DEFAULT_FLAGS="-esqli -tuins -nodosdiff"
	#CERT_DEFAULT_FLAGS="-eci -tuins -nodosdiff"
	#DEFAULT_FLAGS="-ecp -tuins -nodosdiff"
	#NOTE: Mike say there are KNOWN pronlems in all HL_ code. Should try 
	#to compile old TUI, uisng PDcurses plus our forms.c code
	DEFAULT_FLAGS="-ecp -tuinw -nodosdiff"
	CERT_DEFAULT_FLAGS="$DEFAULT_FLAGS"
	SO_EXT=.dll
fi
#Obsolete; Cygwin unsupported
#if test "$PLATFORM" = "CYGWIN"; then
#	DEFAULT_FLAGS="-nographic -nodb -nodosdiff"
#	CERT_DEFAULT_FLAGS="$DEFAULT_FLAGS"
#	SO_EXT=.dll
#fi
if test "$PLATFORM" = "UNIX"; then
	#it is a bit optimistic to hope we can curently use SQLite to run
    #this tests. It would be nice, since it can be easily provided an all
    #platfoms, but it just does not work in many cases.
	#DEFAULT_FLAGS="-sqlite"
	DEFAULT_FLAGS="-esqli"
	CERT_DEFAULT_FLAGS="-eci"
	#Not true for Darwin and HP-UX
	SO_EXT=.so
fi

DEFAULTS_COMMON="-described -nolong -err-with-log -aubitrc-test -nospace"
DEFAULT_FLAGS="$DEFAULT_FLAGS $DEFAULTS_COMMON"
CERT_DEFAULT_FLAGS="$CERT_DEFAULT_FLAGS $DEFAULTS_COMMON"
#echo DEFAULT_FLAGS $DEFAULT_FLAGS 
#echo CERT_DEFAULT_FLAGS $CERT_DEFAULT_FLAGS
#exit
#######################
#Apply platform defaults, see if we are to run multiple tests
for a in $FLAGS; do
#echo "FLAGS=$FLAGS"
#echo "a=$a"
	if test "$INFO_TEST" = "1"; then 
		if test -d $a; then
			RUN_ONE=$a
    		#echo "------ Info for test $RUN_ONE ------------"
			#exit FOR loop
			if test "$VERBOSE" = "1"; then 
				echo "Exit after info"
			fi
			break
		else
            echo ""
			echo "ERROR: unknown switch with -info or test"
			echo "does not exist: $a"
            echo "Try -help. Stop."
			echo ""
			exit 4
       fi
	fi

   if test "$NEW_TEST" = "1"; then
     new_test $a
	 exit 0
   fi
   if test "$FIND_WORD" = "1"; then
   	#-w = whole word -i = ignore case
	 $FIND . -name "*.4gl" -exec grep -w -i -H "$a" {} \;
	 $FIND . -name "?akefile" -exec grep -w -i -H "$a" {} \;
	 exit 0
   fi
   if test "$LIST_CODE" = "1"; then
	 less $a/*.4gl
	 exit 0
   fi
   
	if test "$CERT_TEST" = "1"; then
		change_setting "cert_test" "1" "$a"
		echo "Test $a marked as certified."
		exit
	fi
	
	if test "$CHECK_ANSI" = "1"; then
		check_ansi_single $a
		echo "Test $a ANSI compatibility: $IS_ANSI_COMPATIBLE"
		exit 0
	fi
	
	if test "$SET_ANSI_TO" != ""; then  
		change_setting ansi_sql_compat $SET_ANSI_TO $a
		echo "Test $a - set ansi_sql_compat to $SET_ANSI_TO"
		exit 0
	fi
	
   case $a in
   
   		-xxx)
			#example how to run 4Js programs scripted (replacement for
			#aubit keys.in functionality)
			VERBOSE=1

			#a dumbed down expect script that just sends commands and does not
			#expect anything.

			(
			echo "q\c";
			sleep 2;
			echo "SMITH*";
			sleep 2;
			echo "<ESC>";
			sleep 1;
			echo "b";
			sleep 1;
			
			) | fglrun progam.42r
			exit
			;;

		-verbose)
			VERBOSE=1
			;;
		-check-ansi)
			if [ $# -gt 1 ]; then
				#Check SINGLE test for ANSI SQL compatibility
				CHECK_ANSI=1
			else
				#Check ALL tests for ANSI SQL compatibility
				check_ansi_all
				exit
			fi
			;;
			
		-do-not-use-me)
			dont_use_me
			;;
			
		-set-ansi-yes)
			SET_ANSI_TO="1"
			;;
		-set-ansi-no)
			SET_ANSI_TO="0"
			;;
			
		-defaults)
            #If there is a conflict, USER flags will win
			FLAGS="$DEFAULT_FLAGS $FLAGS"
            #exit 'for' loop since this flag means we will not be running -alltests
			#nnooooooot!
			#break
            ;;
		-cert) #Use flags expected to verify certified tests
			FLAGS="$CERT_DEFAULT_FLAGS $FLAGS"
			break
			;;
        -new)
			#create new test
			NEW_TEST="1"
            continue
            ;;


		-db-features-doc)
			db_features_doc
			exit
			;;

		-no-run) #establish no-runtime erro checking base on comments in makefile
			ALL_DIRS=[0-9]*
			#ALL_DIRS=1004
			#ALL_DIRS=250
            for a in $ALL_DIRS; do
				#echo $a
				MK=`ls $a/?akefile 2> /dev/null`
				if test "$MK" = ""; then
					continue
				fi
				if test -f $MK; then
					FOUND=0; MAYBE=0;
					LOOK_FOR="no run-time error check"
					TMP=`grep -i "$LOOK_FOR" $MK`
					RET=$?
					if test "$RET" = "0"; then
						FOUND=1
						FOUND_LIST="$FOUND_LIST $a"
						echo "FOUND ($a): $TMP"
					fi
					if test "$FOUND" = "0"; then
						LOOK_FOR="no run-time check"
						TMP=`grep -i "$LOOK_FOR" $MK`
						RET=$?
						if test "$RET" = "0"; then
							FOUND=1
							FOUND_LIST="$FOUND_LIST $a"
							echo "FOUND ($a): $TMP"
						fi
					fi
					
					if test "$FOUND" = "0"; then
						LOOK_FOR="run-time"
						TMP=`grep -i "$LOOK_FOR" $MK`
						RET=$?
						if test "$RET" = "0"; then
							MAYBE=1
							MAYBE_LIST="$MAYBE_LIST $a"
							echo "MAYBE ($a): $TMP"
						fi
					fi
					if test "$FOUND" = "0" -a "$MAYBE" = 0; then
						LOOK_FOR="error check"
						TMP=`grep -i "$LOOK_FOR" $MK`
						RET=$?
						if test "$RET" = "0"; then
							MAYBE=1
							MAYBE_LIST="$MAYBE_LIST $a"
							echo "MAYBE ($a): $TMP"
						fi
					fi
					if test "$FOUND" = "0" -a "$MAYBE" = 0; then
						LOOK_FOR="time error"
						TMP=`grep -i "$LOOK_FOR" $MK`
						RET=$?
						if test "$RET" = "0"; then
							MAYBE=1
							MAYBE_LIST="$MAYBE_LIST $a"
							echo "MAYBE ($a): $TMP"
						fi
					fi
					
				#else
					#echo "no makefile in $a" 
				fi
	 		done
			
			echo "MAYBE_LIST=$MAYBE_LIST"
			echo "FOUND_LIST=$FOUND_LIST"
			
			LIST="$MAYBE_LIST $FOUND_LIST"
			
			for b in $LIST; do
				IS_SET=`$MAKE -s -C $b runtime_err_check 2>/dev/null`
				if test "$IS_SET" != ""; then
					echo "Allready set ($b)"
				else
					echo "Adding $b"
					change_setting runtime_err_check "0" $b
					#exit
				fi
			
			done
			
			exit
			;;
		

			
        -find) #find word in 4gl code
			FIND_WORD="1"
            continue
            ;;

        -list) #list 4gl code
			LIST_CODE="1"
            continue
            ;;

		-fff)
			echo "before call"
			echo "CONSOLE_PROMPT_TESTS=$CONSOLE_PROMPT_TESTS"
			echo "XXX=$XXX"
			echo "calling test_func with param1='blah'"
			test_func "blah"
			echo "after function call XXX=$XXX"
			exit
		;;
		-certify)
			#flag the test as certified in the makefile
			CERT_TEST=1
			continue
			;;
			
		-new-nocvs)
			#create new test
			NEW_TEST="1"
			NO_CVS="1"
			continue
			;;

		-migrate-old-makefiles)
			migrate_old_makefiles
			exit
			;;
			
		-se)
			#test if current running Informix db is SE or not
			DB=test1
			SCRIPT=try.sql
			LOGFILE=try.log
			LOGFILE_CMD="> $LOGFILE 2>&1"
			echo "select rowid from syscolumns where colname = 'dirpath' and tabid = 1" > $SCRIPT
			EXEC="dbaccess $DB -qcr $SCRIPT $LOGFILE_CMD"
			eval $EXEC
			RET=$?
			echo "RET=$RET"
			TEST=`cat $LOGFILE | sed -e 's/OOPS//g' | grep  Norowsfound`
			if test "$TEST" != ""; then
				echo "This is NOT SE engine"
			fi
			rm -f try.sql try.log
			exit $RET
			;;
			
		-update)
			LOGFILE=/tmp/cvsupdate-aubit4gltest.log
			echo "+--------------------------------------------------------------------+"
			echo "| CVS update started at $DATE"
			echo "| Logging to $LOGFILE"
			echo "+--------------------------------------------------------------------+"	
			echo " "
			cvs update -d -P > $LOGFILE 2>&1
			RET=$?
			if test "$RET" != "0"; then echo "ERROR: cvs updated failed"; fi
			grep -v "cvs update: Updating" $LOGFILE
			grep "cvs update: conflict" $LOGFILE  > /dev/null
			RET=$?;
			if test "$RET" = "0" ; then 
				grep "cvs update: conflict" $LOGFILE
				echo "WARNING: conflict(s) detected - see $LOGFILE"; 
			fi
			grep "configure" $LOGFILE  > /dev/null ; 
			RET=$?; 
			if test "$RET" = "0" ; then 
				echo "WARNING: configure changed - re-run ./configure"; 
			fi
			#TODO - check id SQL files where updated to re-run db creation
			echo " "
			echo "+--------------------------------------------------------------------+"
			echo "| CVS update finished at `date`"
			echo "| See /tmp/cvsupdate-aubit4gl.log for details                        |"
			echo "+--------------------------------------------------------------------+"
			echo " "
			exit 0
			;;

		-commit)
			#Note: cvs commit command cannot be redirected to file because of the need
			#to edit commit message
			cvs -q commit
			exit 0
			;;
			
        -info) #Show information about the one or all tests
			date_stamp=`date +%d-%m-%Y_%H-%M-%S`
			if [ $# -gt 2 ]; then
				#More then 2 flags on cmd line, process everything/run test, but
				#also show info
				RUN_AND_INFO=1
			else
				#2 or less flags on command line, one of which is -info, so
				#just show the info for test (if specified) or output info 
				#for all tests if test not specified
				INFO_TEST=1
				continue
			fi
            ;;

		-catalogue) 
			#create catalogue.txt and .unl file using -info flag
			rm -f $CATALOGUE_UNL_FILE
			export CATALOGUE_UNL=1
			echo "Creating tests catalogue file ... this will take a while, please wait..."			
			$SH run_tests -info  > $CURR_DIR/docs/catalogue.txt
			echo "Tests catalogue created (./docs/catalogue.txt and .unl)"
			exit 0
			;;
		-xyz)
			#replace a string in all makefiles
			ALL_DIRS=[0-9]*
			#ALL_DIRS=1004
			#ALL_DIRS=250
            for a in $ALL_DIRS; do
				echo $a
				MK=`ls $a/?akefile`
				if test "$MK" = ""; then
					continue
				fi
				if test -f $MK; then 
					TO_REPLACE="include ..\/Makefile-common"
					REPLACE_WITH='include ${MAKEFILE_COMMON}'
					TMP=`grep "$TO_REPLACE" $MK`
					RET=$?
					if test "$RET" = "0"; then
						echo "$MK"
						#echo $TMP
						TT=`echo $TMP | sed -e "s/$TO_REPLACE/$REPLACE_WITH/"`
						echo "$TMP ==> $TT"
						cat $MK  | sed -e "s/$TO_REPLACE/$REPLACE_WITH/" > /tmp/mk.tmp
						mv /tmp/mk.tmp $MK
					else
						echo "no $TO_REPLACE string in $MK"
					fi
				else
					echo "no makefile in $a" 
				fi
	 		done
			exit
			;;
        -add-makefile)
			#Do not add makefile to 58 and 65 - they are obsolete
			ALL_DIRS=[0-9]*
            for a in $ALL_DIRS; do
				if ! test -f $a/?akefile; then
					echo "Adding in $a"
					cp template/makefile template/.cvsignore $a
                    ADDED="$ADDED $a/.cvsignore $a/makefile"
				fi
	 		done
            if test "$ADDED" != ""; then
				echo "cvs add $ADDED"
				cvs add $ADDED
            fi
            #exit script - we are done
			exit 0
            ;;
        -add-cvsignore)
			ALL_DIRS=[0-9]*
            for a in $ALL_DIRS; do
				CVSIGNORE="$a/.cvsignore"
				if ! test -f $CVSIGNORE ; then
                    cp template/.cvsignore $a
                    ADDED="$ADDED $CVSIGNORE"
                else
					#ADDEXT_LIST=".c_"
					ADDEXT_LIST="sql_features"
					for ADDEXT in $ADDEXT_LIST; do
						if ! grep "$ADDEXT" "$CVSIGNORE" > /dev/null ; then 
							#echo "*$ADDEXT" >> $CVSIGNORE
							echo "$ADDEXT" >> $CVSIGNORE
						fi
					done
				fi
	 		done

            if test "$ADDED" != ""; then
				cvs add $ADDED
            fi

            #exit script - we are done
			exit 0
            ;;

        -alltests)
            echo "Running all available combinations of tests..."
			ALL_TESTS_NONDB=1
			ALL_TESTS_DB=1
			;;
		-alltests-db)
            echo "Running all available combinations of DATABASE tests..."
			ALL_TESTS_DB=1
			;;
        -alltests-nodb)
            echo "Running all available combinations of NON_DATABASE tests..."
			ALL_TESTS_NONDB=1
			;;
        -stop)
            #This applies only to -alltests loop:
			#script can also exit for a valid reason, like when there is no plug-in
		    #for particular test, so use this only for debugging:
			STOP_ON_EXIT=1
            ;;
        *)
			#This works only if -alltests is before test number:
			if test "$ALL_TESTS_NONDB" -o "$ALL_TESTS_DB"; then
				if test -d $a; then
					RUN_ONE=$a
		    		echo "Running all tests on test $RUN_ONE only."
				else
		            echo ""
					echo "ERROR: unknown switch with -alltests or test"
					echo "does not exist: $a"
		            echo "Try -help. Stop."
					echo ""
					exit 4
		        fi
            fi
            ;;

   esac
done

#echo "FLAGS=$FLAGS"
#exit

if test "$NEW_TEST" = "1"; then
    echo "ERROR: new test number missing"
    exit 4
fi

if test "$INFO_TEST" = "1"; then 
	if test "$RUN_ONE" = ""; then 
		INFO_ALL=1
		echo "This output was created using command 'run_tests -info'"
		echo "on $DATE"
		echo " "
	fi
fi




