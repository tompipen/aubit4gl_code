##############################################################################
#							Functions
##############################################################################

#Loop trough all tests and check them for ANSI SQL 92 compatibility
check_ansi_all () {
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


#Check one test for ANSI SQL compliance and interpret results
check_ansi_single () {
CHECK_TEST=$1
COMPARE_REAL_WITH_STORED=1

	IS_MAKE_ANSI_SQL_COMPAT=`$MAKE -s -C $CHECK_TEST ansi_sql_compat 2>/dev/null`
	if test "$IS_MAKE_ANSI_SQL_COMPAT" != ""; then
		#we allready have this set in makefile. Since testing using compilers
		#tests only static SQL, we must honor what is set in makefile, since
		#it may be set because of dynamic SQL
		IS_ANSI_COMPATIBLE=$IS_MAKE_ANSI_SQL_COMPAT
		ALLREADY_SET_CNT=`(expr $ALLREADY_SET_CNT + 1) 2>/dev/null`
		ALLREADY_SET_LST="$ALLREADY_SET_LST $CHECK_TEST"
		if test "$IS_ANSI_COMPATIBLE" = "0"; then 
			MSG1="$CHECK_TEST: Result 0 from makefile"
			FAIL_ANSI_CNT=`(expr $FAIL_ANSI_CNT + 1) 2>/dev/null`
			FAIL_ANSI_LST="$FAIL_ANSI_LST $CHECK_TEST"
		else
			MSG1="$CHECK_TEST: Result 1 from makefile"
			ANSI_OK_CNT=`(expr $ANSI_OK_CNT + 1) 2>/dev/null`
			ANSI_OK_LST="$ANSI_OK_LST $CHECK_TEST"
		fi
	fi
	
	if test "$IS_MAKE_ANSI_SQL_COMPAT" = "" -o "$COMPARE_REAL_WITH_STORED" = "1"; then 
		#do the ANSI check
		RESULT=""
		IS_ANSI_COMPATIBLE=""
		TEST_CNT=`(expr $TEST_CNT + 1) 2>/dev/null`
		check_ansi $CHECK_TEST
		TOTAL_FGL_CNT=`(expr $TOTAL_FGL_CNT + $FGL_CNT) 2>/dev/null`

		#Interpret and count results
		
			case $RESULT in
				unknown-failed-but-no-ANSI-in-err)
					MSG1="$CHECK_TEST: $FGL failed with code $RET, but no ANSI in err file"
					FAIL_NOERRFILE_CNT=`(expr $FAIL_NOERRFILE_CNT + 1) 2>/dev/null`
					FAIL_NOERRFILE_LST="$FAIL_NOERRFILE_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				yes-only-comment-warnings)	
					MSG1="$CHECK_TEST: $FGL generated ANSI warnings, but all about comments"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then
						FAIL_ANSI_COMMENT_ONLY_CNT=`(expr $FAIL_ANSI_COMMENT_ONLY_CNT + 1) 2>/dev/null`
						FAIL_ANSI_COMMENT_ONLY_LST="$FAIL_ANSI_COMMENT_ONLY_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="1"
					;;
				no)
					MSG1="$CHECK_TEST: $FGL generated ANSI warnings:"
					MSG2="$WARN_TXT_NO_COMMENT"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then
						FAIL_ANSI_CNT=`(expr $FAIL_ANSI_CNT + 1) 2>/dev/null`
						FAIL_ANSI_LST="$FAIL_ANSI_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="0"
					;;
				unknown-failed-to-compile)
					MSG1="$CHECK_TEST: $FGL faied with exit code $RET (not 6)"
					FAIL_NOT_SIX=`(expr $FAIL_NOT_SIX + 1) 2>/dev/null`
					FAIL_NOT_SIX_LST="$FAIL_NOT_SIX_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				unknown-different-results)
					MSG1="$CHECK_TEST: $FGL conflicting results from compilers"
					DIFF_RESULTS=`(expr $DIFF_RESULTS + 1) 2>/dev/null`
					DIFF_RESULTS_LST="$DIFF_RESULTS_LST $CHECK_TEST"
					IS_ANSI_COMPATIBLE="unknown"
					;;
				yes)
					MSG1="$CHECK_TEST: $FGL is ANSI compatible"
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = ""; then					
						ANSI_OK_CNT=`(expr $ANSI_OK_CNT + 1) 2>/dev/null`
						ANSI_OK_LST="$ANSI_OK_LST $CHECK_TEST"
					fi
					IS_ANSI_COMPATIBLE="1"
					;;
				no-fgl)
					MSG1="$CHECK_TEST: No 4gl files"
					FAIL_NOT_SIX=`(expr $FAIL_NOT_SIX + 1) 2>/dev/null`
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

#check all 4gl files in test directory for ANSI SQL compliance
check_ansi() {
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
		FGL_CNT=`(expr $FGL_CNT + 1) 2>/dev/null`
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


#Check one 4gl file for ANSI SQL compliance using Informix 4GL compiler
check_ansi_ifx() {
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

#Check one 4gl file for ANSI SQL compliance using Querix 4GL compiler
check_ansi_querix() {
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

#Check one 4gl file for ANSI SQL compliance using Aubit 4GL compiler
check_ansi_aubit() {
FGL=$1

# Try test 538 
#TODO: use '-ansi' flag on the ESQL/C compiler.

if test "$A4GL_LEXTYPE" = "" -o "$A4GL_SQLTYPE" = ""; then 
	#We are called before run_test script set this 
	AUBIT_DB="export A4GL_LEXTYPE=C; export A4GL_SQLTYPE=esql;"
fi
FGLCOMP_CMD="export A4GL_ANSI_WARN=Yes; $AUBIT_DB aubit 4glc --verbose"

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


##
# Log test descriptiont into Informix-style .unl file
#
##
catalogue_unl() {
#time=$date_stamp
time=`date +%d-%m-%Y_%H-%M-%S`
test_no=$TEST_NO
invalid=$IS_INVALID_TEST
is_db=$IS_DB_TEST
is_ec=$ec_test
is_nosilent=$IS_NOSILENT_TEST
is_tui=$IS_TUI_TEST
is_form=$IS_FORM_TEST
is_report=$IS_REPORT_TEST
is_graphics=$IS_GRAPHIC_TEST
is_prompt=$IS_CONSOLE_PROMPT_TEST
is_dump_screen=$IS_DUMP_SCREEN_TEST
is_long=$IS_LONG_TEST
is_unknown=$IS_UNKNOWN_TEST
is_cert=$IS_CERT_TEST
is_obsolete=$IS_OBSOLETE_TEST
is_described=$IS_DESCRIBED
#echo ">$desc_txt<"
test_desc_txt=`echo $desc_txt | tr "\n" " " | tr "|" " "`
#echo ">$test_desc_txt<"
#exit
test_compat_test=$compat_test
expect_code=$EXPECT_CODE
se_required=$SE_REQUIRED
compile_only=$COMPILE_ONLY
need_ifx_ver=$NEED_IFX_VERSION
need_trans=$NEED_TRANSACTION
#???? t:noprefix
no_prefix=$NOPREFIX
need_compat=$NEED_COMPAT
old_makefile=$OLD_DESC
sql_features_used="$SQL_FEATURES_USED"
ansi_sql=$IS_MAKE_ANSI_SQL_COMPAT

#################################
#Variables still to populate:

#Test makefile is aubit P-code Old makefiles:PCODE_ENABLED
is_pcode_enabled=""
#Test will fail when running under cron. Old makefiles:NO_CRON_TESTS
is_no_cron=""
#Uses scripted execution (keys.in)
scripted=""
#Opens windows Old makefiles: WINDOW_TESTS
is_window=""
#CVS version of that test
test_ver=""
#Version of run_tests script used to collect values
run_tests_ver=""
#Time of last update of this test (test files changed)
last_update=""
#Need to scan this again, since IS_EXPECT_FAIL is composed at run-time
#depending on run_tests flags:
expect_fail_cert=""
expect_fail_esqli=""
expect_fail_ecp=""
expect_fail_ifx_p=""
expect_fail_4js=""
expect_fail_querix=""

dl="|"
logfile="$CURR_DIR/docs/catalogue.unl"

if ! test -f $logfile; then
if test "$UNL_LEGEND" = "1"; then 
	#on first row print legend

echo "'time'$dl'test_no'$dl'invalid'$dl'is_db'$dl'is_ec'$dl'is_nosilent'$dl'is_tui'\
$dl'is_form'$dl'is_report'$dl'is_graphics'$dl'is_prompt'$dl'is_dump_screen'\
$dl'is_long'$dl'is_unknown'$dl'is_cert'$dl'is_obsolete'$dl'is_described'\
$dl'test_desc_txt'$dl'test_compat_test'$dl'expect_code'$dl'se_required'\
$dl'compile_only'$dl'need_ifx_ver'$dl'need_trans'$dl'no_prefix'$dl'need_compat'\
$dl'old_makefile'$dl'is_pcode_enabled'$dl'is_no_cron'$dl'scripted'\
$dl'is_window'$dl'test_ver'$dl'run_tests_ver'$dl'last_update'$dl'expect_fail_cert'\
$dl'expect_fail_esqli'$dl'expect_fail_ecp'$dl'expect_fail_ifx_p'$dl'expect_fail_4js'\
$dl'expect_fail_querix'$dl'sql_features_used'$dl'ansi_sql'$dl" > $logfile
fi
fi

echo "$time$dl$test_no$dl$invalid$dl$is_db$dl$is_ec$dl$is_nosilent$dl$is_tui\
$dl$is_form$dl$is_report$dl$is_graphics$dl$is_prompt$dl$is_dump_screen\
$dl$is_long$dl$is_unknown$dl$is_cert$dl$is_obsolete$dl$is_described\
$dl$test_desc_txt$dl$test_compat_test$dl$expect_code$dl$se_required\
$dl$compile_only$dl$need_ifx_ver$dl$need_trans$dl$no_prefix$dl$need_compat\
$dl$old_makefile$dl$is_pcode_enabled$dl$is_no_cron$dl$scripted\
$dl$is_window$dl$test_ver$dl$run_tests_ver$dl$last_update$dl$expect_fail_cert\
$dl$expect_fail_esqli$dl$expect_fail_ecp$dl$expect_fail_ifx_p$dl$expect_fail_4js\
$dl$expect_fail_querix$dl$sql_features_used$dl$ansi_sql$dl" >> $logfile

}


##
# Log test run settings and summary results into Informix-style .unl file
#
##
test_run_unl() {

time=$date_stamp
host=$HOSTNAME
user=$USERNAME
platform="$PLATFORM"
os_name="$MACHTYPE"
#os_version="`uname -r`"
os_version="`uname -a`"
flags="$FLAGS"
aubit_version=`aubit 4glc -v | grep Version | awk '{print $2}'`
aubit_build=`aubit 4glc -v | grep Build | awk '{print $3}'`
#Only when non-Aubit 4gl compiler is used
comp_version=""
total_time=`(expr $FINISH_ALL_TIME - $START_TIME) 2>/dev/null`
c_ver=`gcc --version`
#FIXME: adapt for PG/SAP/Querix :
esql_ver=`esql -V | grep Version | awk '{print $3}'`
#Fixme - addapt for non-Informix engines
db_ver=`dbaccess -V | grep Version | awk '{print $3}'`
set `$MAKE --version | head -1 | sed -e 's/^GNU Make version //' -e 's/^GNU Make //' -e 's/, by Richard Stallman and Roland McGrath.//' -e 's/\./ /g'`
make_ver="$1.$2.$3"
sh_ver=`$SH --version | grep version | awk '{print $4}'`


dl="|"

if ! test -f $test_run_unl_file; then
if test "$UNL_LEGEND" = "1"; then
	#on first row print legend
echo "'time'$dl'host'$dl'user'$dl'platform'$dl'os_name'$dl'os_version'\
$dl'flags'$dl'aubit_version'$dl'aubit_build'$dl'comp_version'$dl'total_time'\
$dl'c_ver'$dl'esql_ver'$dl'db_ver'$dl'make_ver'$dl'sh_ver'$dl'LOG_TEXT'$dl" \
	> $test_run_unl_file
fi
fi

echo "$time$dl$host$dl$user$dl$platform$dl$os_name$dl$os_version\
$dl$flags$dl$aubit_version$dl$aubit_build$dl$comp_version$dl$total_time\
$dl$c_ver$dl$esql_ver$dl$db_ver$dl$make_ver$dl$sh_ver$dl$LOG_TEXT$dl" \
	>> $test_run_unl_file

}


##
# Log results of each test into Informix-style .unl file
#
##
result_unl() {
time=$date_stamp
test_no=$1
result=$2
skip_reason=$3
expect_fail=$4
test_version=$5
db_has_trans=$6

if test "$skip_reason" = ""; then 
	if test -f $CURR_DIR/$test_no/$TIME_TMPFILE; then 
		TMP_TMP=`cat $CURR_DIR/$test_no/$TIME_TMPFILE | grep -v non-zero`
		set `echo $TMP_TMP` 
		t_user=$1
		t_system=$2 
		t_elapsed=$3 
		t_CPU=$4 
		t_text=$5 
		t_data=$6 
		t_inputs=$7 
		t_outputs=$8
		t_major=$9
		#t_swaps=$10
		#can't get more then 9 from set - how to use 'shift'?
		#t_swaps="fixme"
		shift
		t_swaps=$9
	fi
fi

dl="|"

if ! test -f $unl_file; then 
if test "$UNL_LEGEND" = "1"; then
#On first row, print legend
echo "'date_stamp'$dl'test_no'$dl'result'$dl'skip_reason'$dl'expect_fail'\
$dl'test_version'$dl'db_has_trans'$dl't_user'$dl't_system'$dl't_elapsed'\
$dl't_CPU'$dl't_text'$dl't_data'$dl't_inputs'$dl't_outputs'$dl't_major'\
$dl't_swaps'$dl" > $unl_file
fi
fi

echo "$time$dl$test_no$dl$result$dl$skip_reason$dl$expect_fail\
$dl$test_version$dl$db_has_trans\
$dl$t_user$dl$t_system$dl$t_elapsed$dl$t_CPU$dl$t_text$dl$t_data$dl$t_inputs\
$dl$t_outputs$dl$t_major$dl$t_swaps$dl\
" >> $unl_file


}


##
# Compare Aubit settings comming from aubit-config and environment
#
##
compare_settings() {

			if test "$A4GL_INIFILE" != ""; then 
				echo "Note: using Aubit rc file $A4GL_INIFILE"
			fi
			aubit-config -a > aubit-config.log
			cat -n aubit-config.log > aubit-config-num.log
			LINES=`grep -c "" aubit-config.log`
			SETTINGS=`grep -c = aubit-config.log`
			echo "aubit-config output has $LINES lines, $SETTINGS settings"

			a=0
			cnt=0
			SKIP_BLOCK=1
			echo " "
			echo "name			env		aubitrc		aubit-config"
			echo "------------------------------------------------------------------"
			while test "1" = "1" ; do
				let a=a+1
				LINE=`grep -e "^ \+$a	" aubit-config-num.log`
				VALUES=`echo "$LINE" | awk '{print $2}'`
				
				if test "$VALUES" = "User"; then
					#User resources block begins
					SKIP_BLOCK=0
				fi
				if test "$SKIP_BLOCK" = "1"; then
					#Skip everything before User Resources block
					continue
				fi
				if test "$VALUES" != "Built-in"; then
					let cnt=cnt+1
					#echo $VALUES
					TMP=`echo $VALUES | sed -e 's/=/ /'`
					NAME=`echo $TMP |  awk '{print $1}'`
					VALUE=`echo $TMP |  awk '{print $2}'`
					#echo "$cnt: Name=$NAME Value=$VALUE"
					dollar="$"
					EXEC="if test \"$dollar$NAME\" != \"\"; then echo \"$dollar$NAME\"; fi"
					#we are running this as external script to see only what
					#is exported to environment, since only that will affect
					#makefiles we will run from run_test script
					echo $EXEC > run.sh					
					ENV_VALUE=`bash ./run.sh`
					if test "$ENV_VALUE" != ""; then
						if test "$ENV_VALUE" != "$VALUE"; then
							x=`aubit-config $NAME`
							#echo "$NAME : env: '$ENV_VALUE' aubitrc: '$VALUE'"
							#echo "aubit-config returns $NAME=`aubit-config $NAME` x=$x"
							echo "$NAME		'$ENV_VALUE'		'$VALUE'		'$x'"
						#else
						#	echo "$NAME IS in environment as '$ENV_VALUE' and in Aubit as "$VALUE""
						fi
					#else
					#	echo "$NAME not in environment"					
					fi
					
					#if test "$cnt" = "10"; then
					#	break
					#fi
				fi
				
				if test "$a" = "$LINES"; then
					break
				fi
			done
	echo "------------------------------------------------------------------"
	echo " "

	set | grep "^A4GL_" > set.log
	LINES=`grep -c "" set.log`
	echo "$LINES Aubit settings in environment"
	if test "$LINES" != "0"; then 
		cat set.log
	fi

	#rm -f aubit-config-num.log aubit-config.log run.sh set.log
	
	
	
	
}

##
# Change setting in makefile
#
##
change_setting() {
look_for="$1:"
change_to=$2
test_no=$3
makefile=`ls $CURR_DIR/$test_no/?akefile`
if test "$makefile" = ""; then
	echo "ERROR: can't get makefile name"
	pwd
	echo "$CURR_DIR/$test_no/?akefile"
	exit 5
fi
tmp_out="$makefile.tmp"

	TMP_TMP=`cat $makefile | grep $look_for`
	if test "$TMP_TMP" = ""; then 
		if test "$VERBOSE" = "1" ; then
			echo "Adding new setting $look_for as $change_to in $makefile..."
		fi
		echo "" >> $makefile
		echo "$look_for" >> $makefile
		echo "	@echo \"$change_to\""  >> $makefile
		echo "" >> $makefile		
	else

		if test "$VERBOSE" = "1" ; then
			echo "Changing value of $look_for to $change_to in $makefile..."
		fi
	
		awk -v look_for="$look_for" -v change_to="$change_to" '
		BEGIN {
		}
		{
			if (skip_next==1) {
				skip_next=0
				next
			} else {
				if (look_for==$1) {
					print
					print "	@echo \"" change_to "\""
					skip_next=1
				} else {
					print
				}
			}
		}
		' < $makefile > $tmp_out
		
		if test "$VERBOSE" = "1" ; then
			diff $makefile $tmp_out
			RET=$?
		else
			diff $makefile $tmp_out > /dev/null
			RET=$?
		fi
		if test "$RET" = "0"; then 
			if test "$VERBOSE" = "1" ; then
				echo "Nothing changed"
			fi
		else
			if test "$VERBOSE" = "1" ; then
				echo "Changed."
			fi
			mv $tmp_out $makefile
		fi
	fi
}

##
# Create API code for Four J's custom runner
#
##
create_4js_api() {
rm -f $FGIUSR_4JS_C

#ERROR(-6200):Module 'prog': The function <extern C>.aclfgl_dump_screen(2,1) 
#will be called as aclfgl_dump_screen(1,0).

cat<<EOF > $FGIUSR_4JS_C
#include <f2c/fglExt.h>
int aclfgl_dump_screen (int n);
	UsrData usrData[] = {
	  {0, 0}
	};
	
	UsrFunction usrFunctions[] = {
	  {"aclfgl_dump_screen", aclfgl_dump_screen, 1, 0},
	  {0, 0, 0, 0}
	};

EOF
}

##
# Create API code for Informix custom runner
#
##
create_ifx_api() {
rm -f $FGIUSR_IFX_C
cat<<EOF > $FGIUSR_IFX_C
#include "fgicfunc.h"
int aclfgl_dump_screen (int n);
cfunc_t usrcfuncs[] =
{
	"aclfgl_dump_screen", aclfgl_dump_screen, 1,
	0, 0, 0
};

EOF
}

##
# Create runner with C function for dumping screen to file.
#
# Test 252 is nice to try screen dumps :
# 	bash run_tests -cert [-querix|-ifx-p|-4js-p] 252
#
# NOTE: Aubit has built-in dump_screen function
# Querix and Informix C-compiled do not need a runner - they will get
# dump_screen function linked in when compiling 4GL programs (in Makefile-common)
#
# @param COMPILER Type of 4GL compiler to create runner for
##
create_runner() {
COMPILER=$1

SRC_CUSTOM="$CUSTOM.c"
OBJ_CUSTOM="$CUSTOM.o"
		
	case $COMPILER in
	informix)
		if test "$INFORMIXDIR" = ""; then 
			echo "ERROR: INFORMIXDIR not set"
			exit 3
		fi
		if test "$AUBITDIR_SRC" = ""; then 
			echo "ERROR: AUBITDIR_SRC not set"
			exit 3
		fi		
		create_ifx_api
		rm -f $IFX_RUNNER 
		SOURCES="$SRC_CUSTOM $FGIUSR_IFX_C"
		#CFGLGO_FLAGS="-dumpspecs"
		#CFGLGO_FLAGS="-v"
		#CFGLGO_FLAGS="-DDEBUG"
		EXEC="cfglgo -DI4GL_RDS $CFGLGO_FLAGS $LIBS $SOURCES -o $IFX_RUNNER "
		echo $EXEC
		rm -f tmp.log
		eval $EXEC > tmp.log 2>&1
		RET=$?
		if test "$RET" != "0"; then
			less tmp.log
			echo "ERROR: creation of Informix custom runner failed"
			exit $RET
		else
			echo "Informix custom runner ($IFX_RUNNER) created" 
			rm -f tmp.log
		fi
		;;
	4js)
		#assuming we will be uiing Informix RDBMS
		if test "$INFORMIXDIR" = ""; then 
			echo "ERROR: INFORMIXDIR not set"
			exit 3
		fi
		if test "$FGLDIR" = ""; then 
			echo "ERROR: FGLDIR (Four J's) not set"
			exit 3
		fi
		if test "$AUBITDIR_SRC" = ""; then 
			echo "ERROR: AUBITDIR_SRC not set"
			exit 3
		fi		
		create_4js_api
		
		#decap program strips away the termcap escape sequences
		EXEC="gcc $AUBITDIR_SRC/lib/extra_libs/infx_dump_screen/decap.c -o ./bin/decap"
		echo $EXEC
		eval $EXEC
		RET=$?
		if test "$RET" != "0"; then
			echo "ERROR: compiling C code failed"
			exit 3
		fi
		
		#Specify version of database on your system; see 'fglmkrun -dl'
		#DB=ifx9** #ERROR(-6197):'Open Database Interface' extension is not allowed with this license type.
		#DB=ix711
		DB=ix720
		#4Js apprently DOES NOT use curses
		#LFLAGS="-lkf \"-lncurses\""
		
		#/opt/aubit/gen4gl/fglbld/include/decimal.h
		#/opt/informix/incl/tools/decimal.h
		#/opt/querix/incl/decimal.h
		FJS_CFLAGS="-cpf \"-DC4GL=1 -DDEBUG -DFOURJS \
			-I$FGLDIR/include -I$INFORMIXDIR/incl/tools \
			-I$INFORMIXDIR/incl\""
		
		rm -f $FJSRUNNER
		LINKER="esql"	#assumes there is Informix ESQL/C installed
		SRC_CUSTOM="$AUBITDIR_SRC/lib/extra_libs/infx_dump_screen/fgl_prtscr.c"
		EXEC="fglmkrun -d $DB -o $FJSRUNNER -l $LINKER \
			$FJS_CFLAGS \
			-acs \"$SRC_CUSTOM\" \
			$LFLAGS \
			-ext $FGIUSR_4JS_C"
		echo $EXEC
		rm -f tmp.log
		eval $EXEC > tmp.log 2>&1
		RET=$?
		if test "$RET" != "0"; then
			less tmp.log
			echo "ERROR: creation of Four J's custom runner failed"
			exit $RET
		else
			echo "Four J's custom runner ($FJSRUNNER) created"
			rm -f tmp.log
		fi
		;;
	*)
		echo "ERROR: unknown compiler type: $COMPILER"
		;;
	esac

}

##
# Convert SQL script for particular RDBMS dialect
#
# @param TYPE Type of conversion (ddl or data)
# @param RDBMS Type of RDBMS to convert SQL dialect to
# @param RESULT Filename of resulting converted SQL script
##
convert_sql() {
TYPE=$1
RDBMS=$2
RESULT=$3
SQL_DDL=etc/testdb-ddl.sql
SQL_DATA=etc/testdb-data.sql
TMP1=tmp1
TMP2=tmp2

	echo "Translating $TYPE script for $RDBMS ..."
	case $RDBMS in
	informix)
		case $TYPE in
		ddl)
			cat $SQL_DDL | sed -e "s/systables/dummy_systables/g" | sed -e "s/sysusers/dummy_sysusers/g" > $TMP1
			cat $TMP1 | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" > $TMP2
			mv $TMP2 $RESULT
			;;
		data)
			cat $SQL_DATA | sed -e "s/systables/dummy_systables/g" | sed -e "s/sysusers/dummy_sysusers/g" > $TMP1
			cat $TMP1 | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" > $TMP2
			mv $TMP2 $RESULT
			;;
		*)
			echo "ERROR: unknown translation type: $TYPE"
			exit 3
			;;
		esac
		;;
	postgres)
		case $TYPE in
		ddl)
			cat $SQL_DDL | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" | sed -e 's/128,0/128/g' | tr "\"" "'" > $TMP1			
			mv $TMP1 $RESULT
			;;
		data)
			cat $SQL_DATA | grep -v "^/\*" | grep -v "^\*/" | grep -v "^//" | sed -e 's/128,0/128/g' | tr "\"" "'" > $TMP1			
			mv $TMP1 $RESULT
			;;
		*)
			echo "ERROR: unknown translation type: $TYPE"
			exit 3
			;;
		esac
		;;
	*)
		echo "ERROR: don't know how to translate SQL for $RDBMS"
		exit 4
		;;
	esac
	
	rm -f $TMP1 $TMP2
	
}


##
# Run SQL script 
#
# @param RDBMS Type of RDBMS to create test database in
# @param DB Database name
# @param SCRIPT SQL script to run
# @param File to log execution into
##
run_sql_script() {
RDBMS=$1
DB=$2
SCRIPT=$3
LOGFILE=$4
LOGFILE_CMD="> $LOGFILE 2>&1"
AS_USER=$5

   case $RDBMS in
	informix)
		EXEC="dbaccess $DB -qcr $SCRIPT $LOGFILE_CMD"
		eval $EXEC
		RET=$?
		;;
	postgres)
		EXEC="$PSQL -d $DB -f $SCRIPT $LOGFILE_CMD"
		if test "$AS_USER" != ""; then 
			EXEC="su -l $AS_USER -c '$EXEC'"
		fi
		eval $EXEC
		RET=$?
		;;
	*)
		echo "ERROR: don't know how to run script for $RDBMS"
		exit 4
		;;
	esac
	
	if test "$RET" != "0"; then
		echo "Statement:"
		echo $EXEC
		echo "returned code $RET. See $LOGFILE"
		exit $RET
	fi
}


##
# Create a new test database.
# Populte test data
#
# @param RDBMS Type of RDBMS to create test database in
##
new_testdb() {
RDBMS=$1
SCRIPT=converted.sql
LOGFILE=/tmp/testdb.log
	
   case $RDBMS in
	informix | postgres)
		convert_sql ddl $RDBMS $SCRIPT
		echo "Creating tables..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		convert_sql data $RDBMS $SCRIPT
		echo "Loading data..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		;;
	*)
		echo "ERROR: don't know how to create test data for $RDBMS"
		exit 4
		;;
	esac
	
	rm -f $SCRIPT
}

##
# Create a new test.
# Copy the template of the makefile into the directory and the .cvsignore also
# Try to copy the files if they not exist but the directory yes.
# Exit the program after doing it.
#
# @param dir The name of the test.
##
new_test() {
dir=$1
nothing_done="1"
  echo "Adding new test $dir"
if ! test -d $dir; then
    mkdir $dir
	cp template/makefile template/prog.4gl template/.cvsignore $dir
	
    if ! test "$NO_CVS" = "1"; then
      cvs add $dir
      cvs add $dir/makefile $dir/prog.4gl $dir/.cvsignore
    fi
    echo "Template for test $dir created. Steps to complete:"
    echo " 1) edit test files to create test code"
    echo " 2) describe test in makefile"
    echo " 3) perform 'cvs add' on additional files test needs, if any"
    echo " 4) perform 'cvs commit'"
    nothing_done=0
else
	#add mandatory files to allready existing directory if they are missing
	CVS_ADD=""
	if ! test -f $dir/makefile && ! test -f $dir/Makefile ; then
		cp template/makefile $dir
		CVS_ADD="$dir/makefile"
		echo "makefile added from template"
		nothing_done="0"
	fi
	if ! test -f $dir/.cvsignore; then
		cp template/.cvsignore $dir
		CVS_ADD="$CVS_ADD $dir/.cvsignore"
		echo ".cvsignore added from template"
		nothing_done="0"
	fi
    if ! test "$NO_CVS" = "1" && test "$CVS_ADD" != ""; then
      cvs add $CVS_ADD
    fi
fi
  if test $nothing_done = "1"; then
    echo "ERROR: test $a already exists with makefile and .cvsignore"
  fi
  exit
}

