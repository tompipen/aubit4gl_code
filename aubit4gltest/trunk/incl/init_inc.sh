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
if [ "$FGLC" = "" ]
then
	export FGLC=4glc
fi
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
USERNAME=`whoami`

#Determine POSTGRESDIR and PSQL for PostgreSQL database engine
#Must be here because PSQL is used before we reach dedicated PG section,
#in running scripts function and to set default database when not specified
PSQL=psql
if test "$POSTGRESDIR" = ""; then
	POSTGRESDIR=`aubit-config POSTGRESDIR`
	if test ! -d "$POSTGRESDIR"; then
		if test "$VERBOSE" = "1"; then
			echo "WARNING: POSTGRESDIR reported by aubit-config is invalid ($POSTGRESDIR)"
		fi
		
		POSTGRESDIR=`ps -efw | grep postmaster | head -1 | awk '{print $8}'`
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
	DEFAULT_FLAGS="-esqli -tuins -nodosdiff"
	CERT_DEFAULT_FLAGS="-eci -tuins -nodosdiff"
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

#######################
#Apply platform defaults, see if we are to run multiple tests
FLAGS="$@"
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
			echo "Preparing catalogue of db features, please wait..."
			TEST_WEBCVS_URL="http://cvs.sourceforge.net/viewcvs.py/aubit4gl/aubit4gltest"
			FEATURES_STATUS_TMP="/tmp/features_status.tmp"
			TEST_FEATURES_TMP="/tmp/tests_features.tmp"
			OUT_TMP=out.tmp
			EXPANDED_CONFIDENCE=1
			HTML=1
			if test "$HTML" = "1"; then
				FINAL_OUT="./docs/support_status.html"
			else
				FINAL_OUT="./docs/support_status.txt"
			fi
			LAST_RESULTS=`ls -al --sort=t results_$HOSTNAME* 2> /dev/null | head -4 | grep ":" | head -1 | awk '{print $9}'`
			if test "$LAST_RESULTS" = ""; then 
				echo "ERROR: no results files (results_HOSTNAME_DATE.unl) found"
				exit 1
			else
				if test ! -f $LAST_RESULTS ; then
					echo "ERROR: results file ($LAST_RESULTS) missing"
					exit 2
				fi
			fi
			
			if test ! -f $CATALOGUE_UNL_FILE ; then
				echo "ERROR: catalogue file ($CATALOGUE_UNL_FILE) missing"
				exit 2
			fi
			U="_"
			TEST_DATE=`echo "$LAST_RESULTS" | sed -e "s/results_$HOSTNAME$U//" | sed -e 's/_/ /' | awk '{print $1}'`
			TEST_TIME=`echo "$LAST_RESULTS" | sed -e "s/results_$HOSTNAME$U//" | sed -e 's/_/ /' | awk '{print $2}' | sed -e 's/.unl//'`
			U="_"
			TEST_RUN_UNL="test_run_$HOSTNAME$U$TEST_DATE$U$TEST_TIME.unl"
			if test ! -f $TEST_RUN_UNL ; then
				echo "ERROR: $TEST_RUN_UNL missing"
				exit 5
			else
				RESULTS_HOST=`cut --fields=2 --delimiter="|" $TEST_RUN_UNL`
				#RESULTS_USER=`cut --fields=3 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_PLATFORM=`cut --fields=4 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_OSNAME=`cut --fields=5 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_OS_VER=`cut --fields=6 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_FLAGS=`cut --fields=7 --delimiter="|" $TEST_RUN_UNL`
				
				RESULTS_AUBIT_VER=`cut --fields=8 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_AUBIT_BUILD=`cut --fields=9 --delimiter="|" $TEST_RUN_UNL`
				#Only when non-Aubit 4gl compiler is used:
				RESULTS_COMP_VER=`cut --fields=10 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_TOTAL_TIME=`cut --fields=11 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_C_COMP_VER=`cut --fields=12 --delimiter="|" $TEST_RUN_UNL`
#temp:				
#if test "$RESULTS_C_COMP_VER" = ""; then
#	RESULTS_C_COMP_VER=`gcc --version`
#fi
				RESULTS_ESQL_VER=`cut --fields=13 --delimiter="|" $TEST_RUN_UNL`
#temp. override:
RESULTS_ESQL_VER=`$POSTGRES_BIN/ecpg --version`				
				RESULTS_DB_VER=`cut --fields=14 --delimiter="|" $TEST_RUN_UNL`
#TEmp overide:
#RESULTS_DB_VER=`$POSTGRES_BIN/postmaster --version`
				#RESULTS_MAKE_VER=`cut --fields=15 --delimiter="|" $TEST_RUN_UNL`
				#RESULTS_SH_VER=`cut --fields=16 --delimiter="|" $TEST_RUN_UNL`
				RESULTS_LOG_TEXT=`cut --fields=17 --delimiter="|" $TEST_RUN_UNL`				
			fi
			#Create list of features
			cat etc/db_features.conf | grep -v "^#" | cut --fields=5,20,21 --delimiter=" " > $FEATURES_STATUS_TMP
			#create list of tests using features
			cat $CATALOGUE_UNL_FILE | cut --fields=2,41 --delimiter="|" > $TEST_FEATURES_TMP
			rm -f $OUT_TMP $FINAL_OUT
			
			FEATURES_STATUS=`cat $FEATURES_STATUS_TMP`
			CNT=0; P_CNT=0;S_CNT=0;D_CNT=0;I_CNT=0;U_CNT=0;G_CNT=0;
			for col in $FEATURES_STATUS ; do
				let CNT=CNT+1
				#echo "$CNT = $col"
				case $CNT in
					1) STATUS="$col"
						case $STATUS in
						P) STATUS_NAME="POSSIBLE"; let P_CNT=P_CNT+1;;
						S) STATUS_NAME="SUPPORTED"; let S_CNT=S_CNT+1;;
						D) STATUS_NAME="DEPENDS"; let D_CNT=D_CNT+1;;
						I) STATUS_NAME="IMPOSSIBLE"; let I_CNT=I_CNT+1;;
						G) STATUS_NAME="IGNORED"; let G_CNT=G_CNT+1;;
						*) echo "ERROR: STATUS=$STATUS"; exit 5;;
						esac
						;;
					2) TYPE="$col"
						case $TYPE in
						D) TYPE_NAME="DDL";; 
						S) TYPE_NAME="SQL";; 
						C) TYPE_NAME="Conectivity";; 
						P) TYPE_NAME="Procedure&trigger(serverSide)";; 
						F) TYPE_NAME="Functions(serverSide)";;
						X) TYPE_NAME="Mixed";;
						*) echo "ERROR: TYPE=$TYPE"; exit 5;;
						esac
						;;
					3) LABEL="$col"; CNT=0; 
						TEST_CNT=`grep --count --word-regexp $LABEL $TEST_FEATURES_TMP`
						TEST_LIST=`grep --word-regexp $LABEL $TEST_FEATURES_TMP | cut --fields=1 --delimiter="|" | tr "\n" "_"`
						if test "$TEST_CNT" = "0"; then 
							STATUS_NAME="UNTESTED"
							TEST_LIST="NONE"
							let U_CNT=U_CNT+1
							#Fixme; reduce current stat counter by one
						fi
						echo "$LABEL|$TYPE_NAME|$STATUS_NAME|$TEST_CNT|$TEST_LIST" >> $OUT_TMP
						;;
				esac
			done
			if test "$HTML" = "1"; then 
				echo "<html><head>"  >> $FINAL_OUT
				echo "<meta http-equiv='Content-Language' content='en-us'>"  >> $FINAL_OUT
				echo "<meta http-equiv='Content-Type' content='text/html; charset=windows-1252'>"  >> $FINAL_OUT
				TITLE="Aubit 4GL: SQL & database features support and usage status"
				echo "<title>$TITLE</title></head><body>"  >> $FINAL_OUT
				echo "<h1 align='center'>$TITLE</h1><BR>"  >> $FINAL_OUT
				echo "Links: <br>" >> $FINAL_OUT
				echo "<a href="http://cvs.sourceforge.net/viewcvs.py/aubit4gl/aubit4gltest/etc/db_features.conf?view=markup">SQL and database features status configuration file (also contains status descriptions)</a><br>"  >> $FINAL_OUT
				echo "<a href="http://cvs.sourceforge.net/viewcvs.py/aubit4gl/aubit4gltest/docs/catalogue.unl?view=markup">Tests catalogue (.unl)</a><br>"  >> $FINAL_OUT
				echo "<a href="http://cvs.sourceforge.net/viewcvs.py/aubit4gl/aubit4gltest/docs/catalogue.txt?view=markup">Tests catalogue (.txt)</a><br>"  >> $FINAL_OUT				
				echo "<a href="http://developer.mimer.se/validator/">Mimer SQL Validator</a><br>"  >> $FINAL_OUT
				echo "<a href="http://dev.mysql.com/tech-resources/crash-me.php">Database Server Feature Comparisons</a><br>"  >> $FINAL_OUT
				echo "<a href="http://dev.mysql.com/tech-resources/crash-me.php?res_id=450">Database Server Feature Comparison: PostgreSQL-7.3.3, Informix-7.24UC5</a><br>"  >> $FINAL_OUT				
				echo "<br><br>" >> $FINAL_OUT
				echo "Testing conditions:<br>" >> $FINAL_OUT
				echo "<div align="left">" >> $FINAL_OUT
				echo "  <table border="1" id="table2">" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Host name</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_HOST</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Platform</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_PLATFORM</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>OS name</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_OSNAME</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>OS version</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_OS_VER</td>" >> $FINAL_OUT
				#RESULTS_USER
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Test flags (expanded)</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_FLAGS</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Aubit 4GL compiler version (major.minor)</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_AUBIT_VER</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Aubit 4GL compiler build</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_AUBIT_BUILD</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				#Only when non-Aubit 4gl compiler is used
				if test "$RESULTS_COMP_VER" != ""; then
					echo "    <tr>" >> $FINAL_OUT
					echo "      <td>Non-Aubit 4GL compiler version</td>" >> $FINAL_OUT
					echo "      <td>$RESULTS_COMP_VER</td>" >> $FINAL_OUT
					echo "    </tr>" >> $FINAL_OUT
				fi
				#Disabled - huge number!
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Tests total run time (seconds)</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_TOTAL_TIME</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>C compiler version (GCC)</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_C_COMP_VER</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Used ESQL/C compiler version</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_ESQL_VER</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>Used database version</td>" >> $FINAL_OUT
				echo "      <td>$RESULTS_DB_VER</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				#RESULTS_MAKE_VER
				#RESULTS_SH_VER
				if test "$RESULTS_LOG_TEXT" != ""; then
					echo "    <tr>" >> $FINAL_OUT
					echo "      <td>Teest custom log text</td>" >> $FINAL_OUT
					echo "      <td>$RESULTS_LOG_TEXT</td>" >> $FINAL_OUT
					echo "    </tr>" >> $FINAL_OUT
				fi
				echo "    <tr>" >> $FINAL_OUT
				echo "      <td>This report created on</td>" >> $FINAL_OUT
				echo "      <td>`date`</td>" >> $FINAL_OUT
				echo "    </tr>" >> $FINAL_OUT
				
				echo "  </table>" >> $FINAL_OUT
				echo "</div>" >> $FINAL_OUT
				echo "<br><br>" >> $FINAL_OUT
				
				echo "Legend:<br>" >> $FINAL_OUT
				echo "<br>" >> $FINAL_OUT
				echo "(n): for preceding test number, as follows:<br>" >> $FINAL_OUT
				echo "E=test does not perform any run-time Error checking<br>" >> $FINAL_OUT
				echo "S=test was Skipped<br>" >> $FINAL_OUT
				echo "C=test is Compile only - it was not executed<br>" >> $FINAL_OUT
				if test "$EXPANDED_CONFIDENCE" = "1"; then 
					echo "x=Confidence estimate for this test (1-5)<br>" >> $FINAL_OUT
				fi
				echo "<br>" >> $FINAL_OUT
				echo "Other symbols:<br>" >> $FINAL_OUT
				if test "$EXPANDED_CONFIDENCE" = "1"; then
					echo "[C/A/A/P]: confidence that feature works (0-5) COMBINED/AVERAGE/ABSOLUTE/PROPORTIONAL<br>" >> $FINAL_OUT
				else
					echo "[C]: confidence that feature works (0-5) COMBINED<br>" >> $FINAL_OUT
				fi
				echo "...=Indicates that not all test numbers belonging to that group are listed (max=5)<br>" >> $FINAL_OUT
				echo "<br><br>" >> $FINAL_OUT				
			else
				echo "RESULTS_HOST $RESULTS_HOST" >> $FINAL_OUT
				echo "RESULTS_PLATFORM $RESULTS_PLATFORM" >> $FINAL_OUT
				echo "RESULTS_OSNAME $RESULTS_OSNAME" >> $FINAL_OUT
				echo "RESULTS_OS_VER $RESULTS_OS_VER" >> $FINAL_OUT				
				#RESULTS_USER				
				echo "RESULTS_FLAGS $RESULTS_FLAGS" >> $FINAL_OUT
				echo "RESULTS_AUBIT_VER $RESULTS_AUBIT_VER" >> $FINAL_OUT
				echo "RESULTS_AUBIT_BUILD $RESULTS_AUBIT_BUILD" >> $FINAL_OUT
				#Only when non-Aubit 4gl compiler is used
				if test "$RESULTS_COMP_VER" != ""; then
					echo "RESULTS_COMP_VER $RESULTS_COMP_VER" >> $FINAL_OUT
				fi
				#Disabled - huge number!
				#echo "RESULTS_TOTAL_TIME $RESULTS_TOTAL_TIME" >> $FINAL_OUT
				echo "RESULTS_C_COMP_VER $RESULTS_C_COMP_VER" >> $FINAL_OUT
				echo "RESULTS_ESQL_VER $RESULTS_ESQL_VER" >> $FINAL_OUT
				echo "RESULTS_DB_VER $RESULTS_DB_VER" >> $FINAL_OUT				
				#RESULTS_MAKE_VER
				#RESULTS_SH_VER
				if test "$RESULTS_LOG_TEXT" != ""; then 
					echo "RESULTS_LOG_TEXT $RESULTS_LOG_TEXT" >> $FINAL_OUT
				fi
			
			fi
			
			STAT_LIST="SUPPORTED DEPENDS IGNORED POSSIBLE IMPOSSIBLE UNTESTED"
			#STAT_LIST="UNTESTED"
			for STAT in $STAT_LIST; do
				case $STAT in
					POSSIBLE) STAT_CNT="$P_CNT";;
					SUPPORTED) STAT_CNT="$S_CNT";;
					DEPENDS) STAT_CNT="$D_CNT";;
					IMPOSSIBLE) STAT_CNT="$I_CNT";;
					IGNORED) STAT_CNT="$G_CNT";;
					UNTESTED) STAT_CNT="$U_CNT";;
					*) echo "ERROR: STAT=$STAT"; exit 5;;
				esac
				echo "Creating status list for $STAT group ($STAT_CNT), please wait..."
				if test "$HTML" = "1"; then			
					echo "<div align='left'>"  >> $FINAL_OUT
					echo "  <table border='1' id='table$STAT'>"  >> $FINAL_OUT
					echo "  <tr><td colspan='6' bgcolor='#C0C0C0'><p align='center'>$STAT ($STAT_CNT)</td></tr>"  >> $FINAL_OUT
					echo "<tr>" >> $FINAL_OUT
					echo "  <td>Feature</td>" >> $FINAL_OUT
					echo "  <td>Type</td>" >> $FINAL_OUT
					#if test "$LAST_RESULTS" = ""; then
						echo "  <td>Used in<br>tests</td>" >> $FINAL_OUT
						echo "  <td>Tests USING feature</td>" >> $FINAL_OUT
					#else
						echo "  <td>Working<br>tests</td>" >> $FINAL_OUT
						echo "  <td>WORKING tests using feature</td>" >> $FINAL_OUT
					#fi
					echo "</tr>" >> $FINAL_OUT
					
				else
					echo "-------------- $STAT ($STAT_CNT) ------------------" >> $FINAL_OUT				
				fi 
				
				THIS_STAT_LIST=`grep "|$STAT|" $OUT_TMP | tr "|" " "`
				CNT=0
				for col in $THIS_STAT_LIST; do
					let CNT=CNT+1
					case $CNT in
					1) LABEL="$col";;
					2) TYPE_NAME="$col";;
					3);;#STATUS_NAME
					4) TEST_CNT="$col";;
					5) TEST_LIST="$col"; CNT=0
					 	echo -n "$LABEL "
						TEST_LIST=`echo $TEST_LIST | tr "_" " "`
						#here we have the list of tests that use that feature
						#now we have to check if this tests really worked 
						#for this database:
						TEST_WORKING_CNT=0
						TEST_FAILED_CNT=0
						TEST_WORKING_LIST=""
						TEST_FAILED_LIST=""
						if test "$LAST_RESULTS" = ""; then 
							TEST_WORKING_CNT="0"
							TEST_WORKING_LIST="?"
						else
							for AN_TEST in $TEST_LIST; do
								x=`grep "|$AN_TEST|" $LAST_RESULTS`
									#1: timestamp char (19),   -- 22-10-2004_01-34-24
									#2: test_no smallint,
									#3: result smallint,
									#4: skip_reason char (20),
									#5: expect_fail smallint,
									#6: test_version decimal,

								RESULT=`echo $x | cut --fields=3 --delimiter="|"`
								if test "$RESULT" = "1"; then
									let TEST_WORKING_CNT=TEST_WORKING_CNT+1
									TEST_WORKING_LIST="$TEST_WORKING_LIST $AN_TEST"
								else
									let TEST_FAILED_CNT=TEST_FAILED_CNT+1
									TEST_FAILED_LIST="$TEST_FAILED_LIST $AN_TEST"
								fi
							done
						fi
						if test "$TEST_WORKING_CNT" -gt "0"; then
							#get confidence for each (working) test,
							#reorder list to show tests with high confidence first (tests
							#that are not compile-only, and tests that do
							#perform run-time error checking
							CNT2=0;
							LIST_0="";LIST_2="";LIST_3="";LIST_4="";LIST_5="";
							CNT_0=0;CNT_2=0;CNT_3=0;CNT_4=0;CNT_5=0;
							for t in $TEST_WORKING_LIST; do
								let CNT2=CNT2+1
								make_test_attrib_label "$t" "$LAST_RESULTS" "$CATALOGUE_UNL_FILE"
								case $THIS_TEST_CONFIDENCE in
									0) LIST_0="$LIST_0 $t"; let CNT_0=CNT_0+1;;
									2) LIST_2="$LIST_2 $t"; let CNT_2=CNT_2+1;;
									3) LIST_3="$LIST_3 $t"; let CNT_3=CNT_3+1;;
									xx4) LIST_4="$LIST_4 $t"; let CNT_4=CNT_4+1;;
									5) LIST_5="$LIST_5 $t"; let CNT_5=CNT_5+1;;
									*) echo "ERROR: THIS_TEST_CONFIDENCE=$THIS_TEST_CONFIDENCE"; exit 3;;
								esac
							done
							#After all tests for this feature are rated,
							#calculate confidence in this feature:
							let SUM_CONF=CNT_0+CNT_2+CNT_3+CNT_4+CNT_5
							#Percentage:
							AVG_CONF=`perl -e '$X=shift @ARGV;$Y=shift @ARGV;;$Z=int($X*100/($Y));print "$Z";' $SUM_CONF $TEST_WORKING_CNT`
							#Reduce to 1-5 range:
							let FEATURE_CONFIDENCE_AVERAGE=($AVG_CONF/2)/10
							FEATURE_CONFIDENCE_ABSOLUTE=0
							if test "$CNT_2" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=2; fi
							if test "$CNT_3" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=3; fi
							if test "$CNT_4" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=4; fi
							if test "$CNT_5" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=5; fi
							
							#Proportional-assign value based on number of tests working
							if test "$TEST_WORKING_CNT" -gt "5"; then 
								FEATURE_CONFIDENCE_PROPORTIONAL="5"
							else
								FEATURE_CONFIDENCE_PROPORTIONAL="$TEST_WORKING_CNT"
							fi
							
							#TODO: assign value to NUMBER of tests in each confidence group;
							#so that if we have 10 tests in group 2, and one in 5, 
							#we don't get too high score
							
							
							#Combined - calculate median from average, absolute and proportional
							let FEATURE_CONFIDENCE_COMBINED=(FEATURE_CONFIDENCE_AVERAGE+FEATURE_CONFIDENCE_ABSOLUTE+FEATURE_CONFIDENCE_PROPORTIONAL)/3
							
							#Reorder list, high confidence first
							TEST_WORKING_LIST="$LIST_5 $LIST_4 $LIST_3 $LIST_2 $LIST_0"
						else
							FEATURE_CONFIDENCE=0
						fi
						
						if test "$TEST_WORKING_CNT" -gt "5"; then
							CNT2=0; REDUCED_WORKING_TEST_LIST=""
							for t in $TEST_WORKING_LIST; do
								let CNT2=CNT2+1
								REDUCED_WORKING_TEST_LIST="$REDUCED_WORKING_TEST_LIST $t"
								if test "$CNT2" = "5"; then
									break
								fi
							done
							TEST_WORKING_LIST="$REDUCED_WORKING_TEST_LIST ..."
						fi
						if test "$TEST_CNT" -gt "5"; then 
							CNT2=0; REDUCED_TEST_LIST=""
							for t in $TEST_LIST; do
								let CNT2=CNT2+1
								REDUCED_TEST_LIST="$REDUCED_TEST_LIST $t"
								if test "$CNT2" = "5"; then
									break
								fi
							done
							TEST_LIST="$REDUCED_TEST_LIST ..."
						fi
						
						if test "$HTML" = "1"; then
							TMP=$TEST_LIST
							TEST_LIST=""
							for test_no in $TMP; do
								if test "$test_no" != "..." -a "$test_no" != "NONE"; then
									make_test_attrib_label "$test_no" "$LAST_RESULTS" "$CATALOGUE_UNL_FILE"
									TEST_LIST="$TEST_LIST <a href='$TEST_WEBCVS_URL/$test_no'>$test_no$DESC</a>"
								else
									TEST_LIST="$TEST_LIST $test_no"
								fi
							done
							if test "$TEST_WORKING_LIST" != ""; then
								TMP=$TEST_WORKING_LIST
								TEST_WORKING_LIST=""
								for test_no in $TMP; do
									if test "$test_no" != "..." -a "$test_no" != "NONE"; then
										make_test_attrib_label "$test_no" "$LAST_RESULTS" "$CATALOGUE_UNL_FILE"
										TEST_WORKING_LIST="$TEST_WORKING_LIST <a href='$TEST_WEBCVS_URL/$test_no'>$test_no$DESC</a>"
									else
										TEST_WORKING_LIST="$TEST_WORKING_LIST $test_no"										
									fi
								done
							else
								if test "$STAT" = "SUPPORTED"; then
									TEST_WORKING_LIST="<font color='#FF0000'>NONE</font>"
								else
									TEST_WORKING_LIST="NONE"
								fi
							fi
						
							echo "<tr>" >> $FINAL_OUT
							echo "  <td>$LABEL</td>" >> $FINAL_OUT
							echo "  <td>$TYPE_NAME</td>" >> $FINAL_OUT
							echo "  <td>$TEST_CNT</td>" >> $FINAL_OUT
							echo "  <td>$TEST_LIST</td>" >> $FINAL_OUT
							if test "$EXPANDED_CONFIDENCE" = "1"; then
								echo "  <td>$TEST_WORKING_CNT [<font color="#0000FF">$FEATURE_CONFIDENCE_COMBINED</font>/$FEATURE_CONFIDENCE_AVERAGE/$FEATURE_CONFIDENCE_ABSOLUTE/$FEATURE_CONFIDENCE_PROPORTIONAL]</td>" >> $FINAL_OUT
							else
								echo "  <td>$TEST_WORKING_CNT [<font color="#0000FF">$FEATURE_CONFIDENCE_COMBINED</font>]</td>" >> $FINAL_OUT
							fi
							echo "  <td>$TEST_WORKING_LIST</td>" >> $FINAL_OUT
							echo "</tr>" >> $FINAL_OUT
						else
							#echo "$LABEL	($TYPE_NAME) $TEST_CNT: $TEST_LIST"  >> $FINAL_OUT
							#x=`echo -n "$LABEL";echo -e "\t\t\t($TYPE_NAME) $TEST_CNT: $TEST_LIST"`
							#echo -n "$LABEL";echo -e "\t\t\t($TYPE_NAME) $TEST_CNT: $TEST_LIST"
							#printf "%s" "$LABEL"; printf "\t\t\t(%s) %s: %s\n" "$TYPE_NAME" "$TEST_CNT" "$TEST_LIST"
							#echo $x >> $FINAL_OUT
							#echo -n "$LABEL" >> $FINAL_OUT
							#echo -e "\t\t\t($TYPE_NAME) $TEST_CNT: $TEST_LIST" >> $FINAL_OUT
							printf "%s\n" "$LABEL" >> $FINAL_OUT
							printf "\t(%s) %s: %s\n" "$TYPE_NAME" "$TEST_WORKING_CNT" "$TEST_WORKING_LIST" >> $FINAL_OUT
						fi
						;;
					*) echo "ERROR: CNT=$CNT"; exit 5
						;;
					esac
				done
				if test "$HTML" = "1"; then		
					echo "  </table>"  >> $FINAL_OUT
					echo "</div><br><br>"  >> $FINAL_OUT
				else
					echo ""	 >> $FINAL_OUT
					echo ""	 >> $FINAL_OUT
				fi
			done
			#cat $FINAL_OUT
			if test "$HTML" = "1"; then
				echo "</body></html>"  >> $FINAL_OUT
			fi
			echo "Done: see $FINAL_OUT"
			
			rm -f "$FEATURES_STATUS_TMP" "$TEST_FEATURES_TMP"
			
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
			
        -info) #Show information about the test
			date_stamp=`date +%d-%m-%Y_%H-%M-%S`
			if [ $# -gt 2 ]; then
				#More flags on cmd line, process everything, but 
				#also show info
				RUN_AND_INFO=1
			else
				#Only 2 flags on command line, one of which is -info, so
				#just show the info
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
				if ! test -f $a/.cvsignore; then
                    cp template/.cvsignore $a
                    ADDED="$ADDED $a/.cvsignore"
                else
					CVSIGNORE="$a/.cvsignore"
					#CVSIGNORE_OUT=">> $CVSIGNORE"
					ADDEXT_LIST=".c_"
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




