##############################################################################
#                           Initialise
##############################################################################

#######################
#Set defaults
CURR_DIR=`pwd`
export A4GL_PRG=".4ae"
export FGLC=4glc
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
else
	FIND=find
fi

IFX_RUNNER="$CURR_DIR/bin/testfglgo"
FJSRUNNER="$CURR_DIR/bin/testfglrun"

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
if test -f "$AUBITDIR/bin/4glpc" ; then 
	chmod a+x $AUBITDIR/bin/4glpc
else
	echo "ERROR: invalid AUBITDIR ($AUBITDIR)"
	exit 4
fi

#Even on Windows we have to use UNIX style path in this script. Since when using 
#MinGW AUBITDIR must be Windows-stile, we must distinguish between them and use
#only AUBITDIR_UNIX in this script
AUBITDIR_UNIX="$AUBITDIR"

if test "$AUBITDIR_SRC" = ""; then
	#maybe current aubitdir is aubit source dir?
	if test -f "$AUBITDIR/lib/libaubit4gl/io.c"; then 
		AUBITDIR_SRC="$AUBITDIR"
	else
		#Just guessing
		AUBITDIR_SRC=/opt/aubit/aubit4glsrc
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

#Determine POSTGRESDIR and PSQL for PostgreSQL database engine
#Must be here because PSQL is used before we reach dedicated PG section,
#in running scripts function and to set default database when not specified
PSQL=psql
if test "$POSTGRESDIR" = ""; then
	POSTGRESDIR=`aubit-config POSTGRESDIR`
fi
if test "$POSTGRESDIR" != ""; then
	if test ! -d "$POSTGRESDIR"; then
		echo "WARNING: POSTGRESDIR is invalid ($POSTGRESDIR)" 
	else
		export POSTGRESDIR
		if test -f "$POSTGRESDIR/bin/postgres" ; then
			#It can be only ecpg installation there, so check if actuall
			#engine and tools are also there
			POSTGRES_BIN=$POSTGRESDIR/bin
			PSQL="$POSTGRES_BIN/psql"
		fi
	fi
fi

#remove this:
if test "$HOSTNAME" = "xxxaptiva.falout.org"; then
	#is actually a ecpg installation dir:
	export POSTGRESDIR=/opt/ecpg-cvs

	#libpq-fe.h :
	export CFLAGS="-I/usr/include/pgsql $CFLAGS"
    #FIXME: store @PGSQL_INCLUDE@ (@ECPG_IFLAGS@ ?) in aubitrc and retrive \
	#with aubit-config
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
	export AUBITDIR="D:/cygwin$AUBITDIR"
    EXE_EXT=.exe
else
    if test "$COMSPEC" != ""; then
        PLATFORM=CYGWIN
        EXE_EXT=.exe
		#getopt_long() not working on Cygwin:
		export FGLC=4glpc
    else
        PLATFORM=UNIX
    fi
fi

#######################
#Check if we have TUI lib, set AUBITDIR:
#fixme - we now have UI_TUIN on MinGW (PDcurses)
if test "$PLATFORM" = "MINGW"; then
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

#######################
#Define platform defaults
if test "$PLATFORM" = "MINGW"; then
	DEFAULT_FLAGS="-xml -nodb -nospace -nographic"
	CERT_DEFAULT_FLAGS="$DEFAULT_FLAGS"
	SO_EXT=.dll
fi
if test "$PLATFORM" = "CYGWIN"; then
	DEFAULT_FLAGS="-nographic -nodb "
	CERT_DEFAULT_FLAGS="$DEFAULT_FLAGS"
	SO_EXT=.dll
fi
if test "$PLATFORM" = "UNIX"; then

	#it is a bit optimistic to hope we can curently use SQLite to run
    #this tests. It would be nice, since it can be easily provided an all
    #platfoms, but it just does not work in many cases.
	DEFAULT_FLAGS="-sqlite -nospace"
	CERT_DEFAULT_FLAGS="-eci -nospace"

	#Not true for Darwin and HP-UX
	SO_EXT=.so
fi

DEFAULT_FLAGS="$DEFAULT_FLAGS -described -nolong -err-with-log"
#DEFAULT_FLAGS="$DEFAULT_FLAGS -stop"
CERT_DEFAULT_FLAGS="$CERT_DEFAULT_FLAGS -described -nolong -err-with-log -aubitrc-test"

#######################
#Apply platform defaults, see if we are to run multiple tests
FLAGS="$@"
for a in $FLAGS; do

	if test "$INFO_TEST" = "1"; then 
		if test -d $a; then
			RUN_ONE=$a
    		#echo "------ Info for test $RUN_ONE ------------"
			#exit FOR loop
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
	 $FIND . -name "*.4gl" -exec grep -H "$a" {} \;
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
		-defaults)
            #If there is a conflict, USER flags will win
			FLAGS="$DEFAULT_FLAGS $FLAGS"
            #exit 'for' loop since this flag means we will not be running -alltests
			break
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
			#flage the test as certified in the makefile
			CERT_TEST=1
			continue
			;;
			
		-new-nocvs)
			#create new test
			NEW_TEST="1"
			NO_CVS="1"
			continue
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
			
        -info)
			#Show information about the test
			INFO_TEST="1"
            continue
            ;;
		-catalogue) 
			#create catalogue.txt file using -info flag
			echo "Creating tests catalogue file ... this will take a while, please wait..."			
			bash run_tests -info > ./catalogue.txt
			echo "Tests catalogue created (./catalogue.txt)"
			exit 0
			;;
			
		-catatogue-unl-test) 
			#unload all test info to .unl file
			exit
			;;
		-log-unl-test)
			#unload rest result to .unl file
			result_unl "123" "ifx" "7.3" "eci" "pass"
			exit
			;;
		-catatogue-unl) 
			#unload all test info to .unl file
			exit
			;;
		-log-unl)
			#unload rest result to .unl file
			UNL_LOG=1
			exit
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
				if ! test -f $a/.cvsignore; then
                    cp template/.cvsignore $a
                    ADDED="$ADDED $a/.cvsignore"
                else
					CVSIGNORE="$a/.cvsignore"
					#CVSIGNORE_OUT=">> $CVSIGNORE"
					ADDEXT_LIST=".42m .42r .42f"
					for ADDEXT in $ADDEXT_LIST; do
						if ! grep "$ADDEXT" "$CVSIGNORE" > /dev/null ; then 
							#echo "*$ADDEXT" $CVSIGNORE_OUT
							echo "*$ADDEXT" >> $CVSIGNORE
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
			if test "$ALL_TESTS_NONDB" || test "$ALL_TESTS_DB"; then
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

if test "$NEW_TEST" = "1"; then
    echo "ERROR: new test number missing"
    exit 4
fi

if test "$INFO_TEST" = "1"; then 
	if test "$RUN_ONE" = ""; then 
		INFO_ALL=1
		echo "This output was created using command 'run_tests -info'"
		$DATE 
		echo " "
	fi
fi

