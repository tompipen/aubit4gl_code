
##############################################################################
#							Functions
##############################################################################


######################################
# Message functions 
#'verbose' is shown only if VERBOSE=1
function verbose () {
	message "$1" "V"
}
#'error' ais shown allways
function error () {
	message "$1" "E" "$2"
}
#'warning' is shown allways
function warning () {
	message "$1" "W"
}
#'debug' is shown if SH_DBG (-shdbg)
function debug () {
	message "$1" "D"
}
#'note' is shown if not SILENT=1
function note () {
	message "$1" "N"
}
#Do not call this function directly - use one of the above functions instead
function message () {
MSG_TEXT=$1
MSG_TYPE=$2
EXIT_CODE=$3
msg=""
	case $MSG_TYPE in 
	V) if test "$VERBOSE" = "1"; then msg="VERBOSE: $MSG_TEXT"; fi ;;
	D) if test "$SH_DBG" = "1"; then msg="DEBUG: $MSG_TEXT"; fi ;;	
	E) 	msg="ERROR: $MSG_TEXT"; 
		if test "$EXIT_CODE" != ""; then msg="$msg STOP." ; fi
		;;
	W) msg="WARNING: $MSG_TEXT" ;;
	N) if test "$SILENT" != "1"; then msg="NOTE: $MSG_TEXT"; fi ;;
	*) if test "$SILENT" != "1"; then msg="$MSG_TEXT"; fi ;;
	esac
	
	if test "$msg" != ""; then
		echo "run_tests: $msg"
		if test "$EXIT_CODE" != "" ; then
			exit $EXIT_CODE
		fi
	fi
}


########################
#calculate percentage
function calc_percent () {
VAR1="$1"
VAR2="$2"

	if test "$VAR2" != "0"; then
		RESULT=`perl -e '$X=shift @ARGV;$Y=shift @ARGV;;$Z=int($X*100/($Y));print "$Z";' $VAR1 $VAR2`
	else
		RESULT=0
	fi
}

######################################################
# Prepare catalogue of db features and there support status for one RDBMS
function db_features_doc () {
	
	echo "Preparing catalogue of db features, please wait..."
	TEST_WEBCVS_URL="http://cvs.sourceforge.net/viewcvs.py/aubit4gl/aubit4gltest"
	FEATURES_STATUS_TMP="/tmp/features_status.tmp"
	TEST_FEATURES_TMP="/tmp/tests_features.tmp"
	OUT_TMP=out.tmp
	EXPANDED_CONFIDENCE=1
	EXTRACT_FEATURE_COMMENTS=1
	HTML=1
	if test "$HTML" = "1"; then
		FINAL_OUT="./docs/support_status.html"
	else
		FINAL_OUT="./docs/support_status.txt"
	fi
	LAST_RESULTS=`ls -al --sort=t results_$HOSTNAME* 2> /dev/null | head -n 4 | grep ":" | head -n 1 | awk '{print $9}'`
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
		RESULTS_ESQL_VER=`cut --fields=13 --delimiter="|" $TEST_RUN_UNL`
#temp. override:
#RESULTS_ESQL_VER=`$POSTGRES_BIN/ecpg --version`				

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
	CNT=0; P_CNT=0;S_CNT=0;D_CNT=0;I_CNT=0;U_CNT=0;G_CNT=0;A_CNT=0;
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
				A) STATUS_NAME="PARTIAL"; let A_CNT=A_CNT+1;;
				*) echo "ERROR: STATUS=$STATUS"; exit 5;;
				esac
				;;
			2) TYPE="$col"
				case $TYPE in
				D) TYPE_NAME="DDL";; 
				S) TYPE_NAME="SQL";; 
				C) TYPE_NAME="Conectivity";; 
				P) TYPE_NAME="Procedure_&_trigger_(server_side)";; 
				F) TYPE_NAME="Functions_(server_side)";;
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
		#echo "Testing conditions:<br>" >> $FINAL_OUT
		
		echo "<div align="left">" >> $FINAL_OUT
		echo "  <table border="1" id="table2">" >> $FINAL_OUT
		echo "  <tr><td colspan='2' bgcolor='#C0C0C0'><p align='center'>Testing conditions:</td></tr>"  >> $FINAL_OUT				
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



		echo "<div align="left">" >> $FINAL_OUT
		echo "  <table border="1" id="table2">" >> $FINAL_OUT
		echo "  <tr><td colspan='2' bgcolor='#C0C0C0'><p align='center'>Legend:</td></tr>"  >> $FINAL_OUT				
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td>(n)</td>" >> $FINAL_OUT
		echo "      <td>for preceding test number, as follows:</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td><font color='#FF0000'>E</font></td>" >> $FINAL_OUT
		echo "      <td>Test does not perform any run-time Error checking</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td>S</td>" >> $FINAL_OUT
		echo "      <td>test was Skipped</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td><font color='#FF0000'>C</font></td>" >> $FINAL_OUT
		echo "      <td>test is Compile only - it was not executed</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT
		
		if test "$EXPANDED_CONFIDENCE" = "1"; then
			echo "    <tr>" >> $FINAL_OUT
			echo "      <td>x</td>" >> $FINAL_OUT
			echo "      <td>Confidence estimate for this test (1-5)</td>" >> $FINAL_OUT
			echo "    </tr>" >> $FINAL_OUT
		fi
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td>&nbsp;</td>" >> $FINAL_OUT
		echo "      <td>Other symbols:</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT
		if test "$EXPANDED_CONFIDENCE" = "1"; then
			echo "    <tr>" >> $FINAL_OUT
			echo "      <td>[<font color="#0000FF">C</font>/A/A/P]</td>" >> $FINAL_OUT
			echo "      <td>confidence that feature works (0-5) <font color="#0000FF">COMBINED</font>/AVERAGE/ABSOLUTE/PROPORTIONAL</td>" >> $FINAL_OUT
			echo "    </tr>" >> $FINAL_OUT
		else
			echo "    <tr>" >> $FINAL_OUT
			echo "      <td>[C]</td>" >> $FINAL_OUT
			echo "      <td>confidence that feature works (0-5) COMBINED</td>" >> $FINAL_OUT
			echo "    </tr>" >> $FINAL_OUT
		fi
		echo "    <tr>" >> $FINAL_OUT
		echo "      <td>...</td>" >> $FINAL_OUT
		echo "      <td>Indicates that not all test numbers belonging to that group are listed (max=5)</td>" >> $FINAL_OUT
		echo "    </tr>" >> $FINAL_OUT

		echo "  </table>" >> $FINAL_OUT
		echo "</div>" >> $FINAL_OUT
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
	
	STAT_LIST="SUPPORTED PARTIAL DEPENDS IGNORED POSSIBLE IMPOSSIBLE UNTESTED"
	#STAT_LIST="UNTESTED"
	for STAT in $STAT_LIST; do
		case $STAT in
			POSSIBLE) STAT_CNT="$P_CNT";;
			SUPPORTED) STAT_CNT="$S_CNT";;
			DEPENDS) STAT_CNT="$D_CNT";;
			IMPOSSIBLE) STAT_CNT="$I_CNT";;
			IGNORED) STAT_CNT="$G_CNT";;
			UNTESTED) STAT_CNT="$U_CNT";;
			PARTIAL)  STAT_CNT="$A_CNT";;
			*) echo "ERROR: STAT=$STAT"; exit 5;;
		esac
		echo "Creating status list for $STAT group ($STAT_CNT), please wait..."
		if test "$HTML" = "1"; then			
			echo "<div align='left'>"  >> $FINAL_OUT
			echo "  <table border='1' id='table$STAT'>"  >> $FINAL_OUT
			echo "  <tr><td colspan='8' bgcolor='#C0C0C0'><p align='center'>$STAT ($STAT_CNT)</td></tr>"  >> $FINAL_OUT
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
			echo "  <td>Feature comments</td>" >> $FINAL_OUT
			echo "  <td>Enter your comments here:</td>" >> $FINAL_OUT
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
				if test "$LABEL" = "NONE"; then
					continue
				fi
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
					#DBG_CONFID=1
					CNT2=0;
					LIST_0="";LIST_2="";LIST_3="";LIST_4="";LIST_5="";
					CNT_0=0;CNT_2=0;CNT_3=0;CNT_4=0;CNT_5=0;SUM_CONF=0
					for t in $TEST_WORKING_LIST; do
						let CNT2=CNT2+1
						make_test_attrib_label "$t" "$LAST_RESULTS" "$CATALOGUE_UNL_FILE"
						if test "$DBG_CONFID" = "1"; then
							echo "Test=$t Confidence=$THIS_TEST_CONFIDENCE"
						fi
						case $THIS_TEST_CONFIDENCE in
							0) LIST_0="$LIST_0 $t"; let CNT_0=CNT_0+1;;
							2) LIST_2="$LIST_2 $t"; let CNT_2=CNT_2+1;;
							3) LIST_3="$LIST_3 $t"; let CNT_3=CNT_3+1;;
							4) LIST_4="$LIST_4 $t"; let CNT_4=CNT_4+1;;
							5) LIST_5="$LIST_5 $t"; let CNT_5=CNT_5+1;;
							*) echo "ERROR: THIS_TEST_CONFIDENCE=$THIS_TEST_CONFIDENCE"; exit 3;;
						esac
						let SUM_CONF=SUM_CONF+THIS_TEST_CONFIDENCE
					done
					#After all tests for this feature are rated,
					#calculate confidence in this feature:
					#BS-this fives num of all tests - let SUM_CONF=CNT_0+CNT_2+CNT_3+CNT_4+CNT_5
					if test "$DBG_CONFID" = "1"; then
						echo "Feature conf. counters: 0=$CNT_0 2=$CNT_2 3=$CNT_3 4=$CNT_4 5=$CNT_5"
						echo "SUM=$SUM_CONF"
					fi
					#---------------------------------------------
					#Percentage:
					#nonsence - we want average, not percentage
					#percent of what?
					#PERC_CONF=`perl -e '$X=shift @ARGV;$Y=shift @ARGV;;$Z=int($X*100/($Y));print "$Z";' $SUM_CONF $TEST_WORKING_CNT`
					#Reduce to 1-5 range:
					#let FEATURE_CONFIDENCE_PERCENTAGE=($PERC_CONF/2)/10
					#if test "$DBG_CONFID" = "1"; then
					#	echo "PERC_CONF=(SUM_CONF*100/TEST_WORKING_CNT)"
					#	echo "$PERC_CONF=($SUM_CONF*100/$TEST_WORKING_CNT)"
					#	echo "Percent: PERC_CONF=$PERC_CONF FEATURE_CONFIDENCE_PERCENTAGE=$FEATURE_CONFIDENCE_PERCENTAGE"
					#fi
					
					#---------------------------------------------
					#Average score:
					AVG_CONF=`perl -e '$X=shift @ARGV;$Y=shift @ARGV;;$Z=int($X/$Y);print "$Z";' $SUM_CONF $TEST_WORKING_CNT`
					#AVG_CONF=SUM_CONF/TEST_WORKING_CNT
					FEATURE_CONFIDENCE_AVERAGE=$AVG_CONF
					if test "$DBG_CONFID" = "1"; then
						echo "AVG_CONF = SUM_CONF / TEST_WORKING_CNT ($AVG_CONF=$SUM_CONF/$TEST_WORKING_CNT)"
						echo "Average: AVG_CONF=$AVG_CONF FEATURE_CONFIDENCE_AVERAGE=$FEATURE_CONFIDENCE_AVERAGE"
					fi
					#---------------------------------------------
					#Absolute
					FEATURE_CONFIDENCE_ABSOLUTE=0
					if test "$CNT_2" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=2; fi
					if test "$CNT_3" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=3; fi
					if test "$CNT_4" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=4; fi
					if test "$CNT_5" -gt "0"; then FEATURE_CONFIDENCE_ABSOLUTE=5; fi
					if test "$DBG_CONFID" = "1"; then
						echo "FEATURE_CONFIDENCE_ABSOLUTE=$FEATURE_CONFIDENCE_ABSOLUTE"
					fi
					#---------------------------------------------
					#Proportional-assign value based on number of tests working
					if test "$TEST_WORKING_CNT" -gt "5"; then 
						FEATURE_CONFIDENCE_PROPORTIONAL="5"
					else
						FEATURE_CONFIDENCE_PROPORTIONAL="$TEST_WORKING_CNT"
					fi
					if test "$DBG_CONFID" = "1"; then
						echo "FEATURE_CONFIDENCE_PROPORTIONAL=$FEATURE_CONFIDENCE_PROPORTIONAL"
					fi
					#TODO: assign value to NUMBER of tests in each confidence group;
					#so that if we have 10 tests in group 2, and one in 5, 
					#we don't get too high score
					
					#---------------------------------------------
					#Combined - calculate median from average, absolute and proportional
					let FEATURE_CONFIDENCE_COMBINED=(FEATURE_CONFIDENCE_AVERAGE+FEATURE_CONFIDENCE_ABSOLUTE+FEATURE_CONFIDENCE_PROPORTIONAL)/3
					if test "$DBG_CONFID" = "1"; then
						echo "FEATURE_CONFIDENCE_COMBINED=(FEATURE_CONFIDENCE_AVERAGE+FEATURE_CONFIDENCE_ABSOLUTE+FEATURE_CONFIDENCE_PROPORTIONAL)/3"
						echo "$FEATURE_CONFIDENCE_COMBINED=($FEATURE_CONFIDENCE_AVERAGE+$FEATURE_CONFIDENCE_ABSOLUTE+$FEATURE_CONFIDENCE_PROPORTIONAL)/3"								
						echo "FEATURE_CONFIDENCE_COMBINED=$FEATURE_CONFIDENCE_COMBINED"
						exit
					fi
					#Reorder list, high confidence first
					TEST_WORKING_LIST="$LIST_5 $LIST_4 $LIST_3 $LIST_2 $LIST_0"
				else
					FEATURE_CONFIDENCE=0
					FEATURE_CONFIDENCE_COMBINED=0
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
				
				if test "$EXTRACT_FEATURE_COMMENTS" = "1"; then
					func_extract_feature_comments "$LABEL"
				fi
				
				TYPE_NAME=`echo $TYPE_NAME | tr "_" " "`
				
				if test "$HTML" = "1"; then
					TMPee=$TEST_LIST
					TEST_LIST=""
					for test_no in $TMPee; do
						if test "$test_no" != "..." -a "$test_no" != "NONE"; then
							make_test_attrib_label "$test_no" "$LAST_RESULTS" "$CATALOGUE_UNL_FILE"
							TEST_LIST="$TEST_LIST <a href='$TEST_WEBCVS_URL/$test_no'>$test_no$DESC</a>"
						else
							TEST_LIST="$TEST_LIST $test_no"
						fi
					done
					if test "$TEST_WORKING_LIST" != ""; then
						TMPee=$TEST_WORKING_LIST
						TEST_WORKING_LIST=""
						for test_no in $TMPee; do
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
				
					LABEL_LEN=`echo "$LABEL" | wc --chars`
					if test "$LABEL_LEN" -gt "20"; then
						LABEL_1=`echo "$LABEL" | cut --fields=1,2 --delimiter="_"`
						LABEL_2=`echo "$LABEL" | cut --fields=3,4,5,6,7,8,9 --delimiter="_"`
						LABEL="${LABEL_1}_...<br>..._${LABEL_2}"
					fi
					
					echo "<tr>" >> $FINAL_OUT
					echo "  <td>$LABEL</td>" >> $FINAL_OUT
					echo "  <td>$TYPE_NAME</td>" >> $FINAL_OUT
					echo "  <td>$TEST_CNT</td>" >> $FINAL_OUT
					echo "  <td>$TEST_LIST</td>" >> $FINAL_OUT
					if test "$EXPANDED_CONFIDENCE" = "1" -a "$TEST_WORKING_CNT" -gt "0" ; then
						echo "  <td>$TEST_WORKING_CNT [<font color="#0000FF">$FEATURE_CONFIDENCE_COMBINED</font>/$FEATURE_CONFIDENCE_AVERAGE/$FEATURE_CONFIDENCE_ABSOLUTE/$FEATURE_CONFIDENCE_PROPORTIONAL]</td>" >> $FINAL_OUT
					else
						if test "$TEST_WORKING_CNT" -gt "0"; then
							echo "  <td>$TEST_WORKING_CNT [<font color="#0000FF">$FEATURE_CONFIDENCE_COMBINED</font>]</td>" >> $FINAL_OUT
						else
							echo "  <td>$TEST_WORKING_CNT</td>" >> $FINAL_OUT
						fi
					fi
					echo "  <td>$TEST_WORKING_LIST</td>" >> $FINAL_OUT
					if test "$THE_COMMENT" = ""; then 
						THE_COMMENT="&nbsp;"
					fi
					echo "  <td>$THE_COMMENT</td>" >> $FINAL_OUT
					#Empty column to allow manual adding/editing of HTML table
					#to add comments
					echo "  <td>&nbsp;</td>" >> $FINAL_OUT
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
		#add newline because of featur names being echo'd without newline
		echo " "
	done
	#cat $FINAL_OUT
	if test "$HTML" = "1"; then
		echo "</body></html>"  >> $FINAL_OUT
	fi
	echo "Done: see $FINAL_OUT"
	
	rm -f "$FEATURES_STATUS_TMP" "$TEST_FEATURES_TMP"
	
}


######################################################
function func_extract_feature_comments () {
#WARNING - extracting comments from config file takes time
#Not recomended for anything but features support status
#catalog creation and similar - not while running
#ordinary tests

#Line must NOT start with a #, then it will have none or more 
#alpha and numbers, then feature name, followed by none or more 
#spaces before and of the line
#DBG_THIS=1
#FEATURE_NAME="CLUSTER_INDEX"
FEATURE_NAME="$1"
	if test "$DBG_THIS" = "1"; then	
		echo "Extracting comment for $FEATURE_NAME"
	fi

	REGEX="^[^#][[:alnum:][:space:]]*$FEATURE_NAME[[:space:]]*\$"
	#get 10 lines after the current feature identifier
	TMP1=`grep -E --word-regexp -A10 -e "$REGEX" etc/db_features.conf`
	if test "$DBG_THIS" = "1"; then 
		echo "1:--------------------"
		echo "$TMP1"
		#exit
	fi
	#Number ALL lines, and then take only lines that did NOT start with a comment
	#then isolate first two, then get the second line
	#NOTE: must be done on one line, so we dont loose newline
	TMP2=`echo "$TMP1" | grep -n "" | grep -v ":#"  | head -n 2 | tail -n 1`
	if test "$DBG_THIS" = "1"; then
		echo "2:--------------------"
		echo "$TMP2"
	fi
	#Get the line number of that line
	NEXT_FEATURE_LINE=`echo $TMP2 | awk '{print $1}' | tr ":" " "`
	if test "$DBG_THIS" = "1"; then
		echo "NEXT_FEATURE_LINE=$NEXT_FEATURE_LINE"
	fi
	let NEXT_FEATURE_LINE=NEXT_FEATURE_LINE-1
	if test "$DBG_THIS" = "1"; then	
		echo "NEXT_FEATURE_LINE=$NEXT_FEATURE_LINE"
	fi
	#Now get that number of lines - cant use data we allready have in the 
	#variable TMP1 because they lost newline
	#Take ony lines that begin with the comment
	#and get rid of comment symbol, filter out lines starting with 
	#3 hashes (###) because they contain line field numbers
	#NOTE: must be done on one line
	THE_COMMENT=`grep --word-regexp -A$NEXT_FEATURE_LINE "$REGEX" etc/db_features.conf | grep  "^#" | sed 's/^#//' | grep -v "^###"`
	if test "$DBG_THIS" = "1"; then
		if test "$THE_COMMENT" != ""; then 
			echo "$FEATURE_NAME comment: $THE_COMMENT"
		fi
		exit
	fi
}


function filter_out_white_listed () { 
#Add configuration specific expect-to-fail list tho the 
#reference point (-cert) expect-to fail list, filter out 
#white-listed tests:

EXPECT_TO_FAIL_TESTS_SPECIFIC="$1"
WHITELIST_TESTS_SPECIFIC="$2"

#dbg_this=1

	if test "$dbg_this" = "1"; then 
		echo "EXPECT_TO_FAIL_TESTS=$EXPECT_TO_FAIL_TESTS"
		echo "EXPECT_TO_FAIL_TESTS_SPECIFIC=$EXPECT_TO_FAIL_TESTS_SPECIFIC"
		echo "WHITELIST_TESTS_SPECIFIC=$WHITELIST_TESTS_SPECIFIC"
	fi
	NOT_ON_WHITE_LIST=""; ON_WHITE_LIST=""
	for t in $EXPECT_TO_FAIL_TESTS; do
		IS_ON_WHITE_LIST=0
		for w in $WHITELIST_TESTS_SPECIFIC; do
			if test "$t" = "$w"; then
				IS_ON_WHITE_LIST=1
				break
			fi
		done
		if test "$IS_ON_WHITE_LIST" = "0"; then
			NOT_ON_WHITE_LIST="$NOT_ON_WHITE_LIST $t"
		else
			ON_WHITE_LIST="$ON_WHITE_LIST $t"
		fi
	done
	EXPECT_TO_FAIL_TESTS="$NOT_ON_WHITE_LIST $EXPECT_TO_FAIL_TESTS_SPECIFIC"
	
	if test "$dbg_this" = "1"; then
		echo "-------------------------------------"
		echo "NOT_ON_WHITE_LIST=$NOT_ON_WHITE_LIST"
		echo "ON_WHITE_LIST=$ON_WHITE_LIST"
		echo "EXPECT_TO_FAIL_TESTS=$EXPECT_TO_FAIL_TESTS"
		exit
	fi

}

#################################################
#Check for compile-only, skip and tests with no run-time error checking
function make_test_attrib_label () {
test_no="$1"
LAST_RESULTS="$2"
CATALOGUE_UNL_FILE="$3"

	if test "$test_no" = ""; then
		echo "ERROR: test_no is empty"
		exit 5
	fi

	#Get data from tests results
	x=`grep "|$test_no|" $LAST_RESULTS`
	SKIP_REASON=`echo $x | cut --fields=4 --delimiter="|"`
	EXPECT_FAIL=`echo $x | cut --fields=5 --delimiter="|"`
	
	#Get data from tests catalogue (descriptions)
	y=`grep "|$test_no|" $CATALOGUE_UNL_FILE | cut --fields=22 --delimiter="|"`
#echo "test_no=$test_no"
#echo "y=$y"	
	COMPILE_ONLY=`echo $y | cut --field=1 --delimiter="|"`
#echo "COMPILE_ONLY=$COMPILE_ONLY"
#exit
	
	#TODO: dont have it in catalog.unl - should add it there
	RUNTIME_ERR_CHECK=`$MAKE -s -C $test_no runtime_err_check 2>/dev/null`

	#we start by assuming that this test passed - no point for calculating
	#confidence for anything else
	THIS_TEST_CONFIDENCE=5
	DESC=""
	
	if test "$RUNTIME_ERR_CHECK" = "0"; then
		THIS_TEST_CONFIDENCE=3
		DESC="<font color='#FF0000'>E</font>$DESC"
	fi
	#EXPECT_FAIL?
	if test "$COMPILE_ONLY" = "1"; then
		THIS_TEST_CONFIDENCE=2
		DESC="<font color='#FF0000'>C</font>$DESC"
	fi
	if test "$SKIP_REASON" != ""; then
		THIS_TEST_CONFIDENCE=0
		DESC="S$DESC"
	fi
	
	if test "$EXPANDED_CONFIDENCE" = "1"; then
		if test "$DESC" != ""; then
			DESC="($DESC$THIS_TEST_CONFIDENCE)"
		else
			DESC="($THIS_TEST_CONFIDENCE)"
		fi
	else
		if test "$DESC" != ""; then
			DESC="($DESC)"
		fi
	fi

}


function activate_use_cache () {
DB_TESTS_CACHE_FILE="$CURR_DIR/etc/cache_IS_DB_TEST.txt"

	if test -f $DB_TESTS_CACHE_FILE ; then
			count=`cat $DB_TESTS_CACHE_FILE | wc -w`
			if test "$count" -lt "100"; then
				warning "DB tests cache file ($DB_TESTS_CACHE_FILE) seems corrupt"
				warning "Cache file removed. Will not use cache."
				rm -f $DB_TESTS_CACHE_FILE
				USE_CACHE=0
			else
				USE_CACHE=1
				IS_DB_TEST_CACHE="`cat $DB_TESTS_CACHE_FILE`"
			fi
		else
			verbose "You need to create a cache file first to use -use-cache"
		fi
}

function activate_log_unl () {
		#unload rest result to .unl file
		date_stamp=`date +%d-%m-%Y_%H-%M-%S`
		U="_"
		if test "$VERBOSE" = "1"; then 
			echo "Logging results to file 'results_$HOSTNAME$U$date_stamp.unl'"
			echo "and 'test_run_$HOSTNAME$U$date_stamp.unl'"
		fi
		unl_file="$CURR_DIR/results_$HOSTNAME$U$date_stamp.unl"
		test_run_unl_file="$CURR_DIR/test_run_$HOSTNAME$U$date_stamp.unl"
		if test "1" = "2"; then 
			rm -f $unl_file $test_run_unl_file
			#rm -f results_*.unl test_run_*.unl
		fi
		UNL_LOG=1
		MEASURE_TIME=1
}


function cntpp () {
local num=$1
local numpp=0
echo "got $num"
	#C_CNT=`(expr $C_CNT + 1) 2>/dev/null`
	let numpp=$num+1
echo "returning $numpp"
	return $numpp
	
}

function test_cntpp () {
	
	X=4
	echo $X
	#let X=call cntpp $X
	#cntpp $X; X=$?
	#X=[cntpp $X]
	echo $X
	exit

}


##########################################
#Define (load from .conf file) list(s) of recognized SQL features
define_sql_features () {
LOAD_ONLY_USED_FEATURES=1
LOAD_ONLY_CURR_DB=1

	if test "$DISABLE_SQL_FEATURES_CHECK" = "1"; then
		debug "define_sql_features - DISABLED"
		return 
	fi
	
	if test "$DB_TYPE" = ""; then
		#We must know db type to work with db features
		DISABLE_SQL_FEATURES_CHECK=1
		if test "$INFO_TEST" != "1"; then
			#If we are just showing test info, it is OK not to have DB_TYPE
			warning "DB_TYPE is empty. Indicate which db to use - see -help-db."
			warning "Disabled SQL features checking."
		fi
		return
	fi
	 
	debug "Loading SQL features list...."
	
	#Determine which feature status applies to this db
	if test "$DB_TYPE" != "PG-IFX-74" -a "$DB_TYPE" != "PG-74" \
		-a "$DB_TYPE" != "IFX-OL" -a "$DB_TYPE" != "IFX-SE" \
		-a "$DB_TYPE" != "SQLITE" -a "$DB_TYPE" != "PG-80" ; then 
		#DB we have no info stored for, treat it as ANSI
		#TODO: determine if we have .cnv file for that db
		if test "1" = "1"; then 
			warning "treating DB features as ANSI db without conversion ($DB_TYPE)"
			FEATURE_DB_TYPE="ANSI"
		else
			warning "treating DB features as ANSI db with conversion ($DB_TYPE)"
			FEATURE_DB_TYPE="ANSI-CNV"
		fi
	else
		if test "$DB_TYPE" = "PG-80"; then 
			FEATURE_DB_TYPE="PG-74"
		else
			FEATURE_DB_TYPE="$DB_TYPE"
		fi
	fi
	
	#Determine which field of features array contains status for this db
	case $FEATURE_DB_TYPE in 
			ANSI-CNV) 	STAT_FIELD=1 ;;
			ANSI) 		STAT_FIELD=2 ;;
			IFX-OL) 	STAT_FIELD=3 ;;
			IFX-SE)		STAT_FIELD=4 ;;
			PG-IFX-74) 	STAT_FIELD=5 ;;
			PG-74) 		STAT_FIELD=6 ;;
			SQLITE) 	STAT_FIELD=7 ;;
			MySQL) 		STAT_FIELD=8 ;;
			MaxDB) 		STAT_FIELD=9 ;;
			Oracle) 	STAT_FIELD=10 ;;
			DB2) 		STAT_FIELD=11 ;;
			MSSQL) 		STAT_FIELD=12 ;;
			Sybase) 	STAT_FIELD=13 ;;
			Progress) 	STAT_FIELD=14 ;;
			Ingres) 	STAT_FIELD=15 ;;
			FireFox) 	STAT_FIELD=16 ;;
			xx1) 		STAT_FIELD=17 ;;
			xx2) 		STAT_FIELD=18 ;;
			xx3) 		STAT_FIELD=19 ;;
			*)	echo "ERROR: FEATURE_DB_TYPE=$FEATURE_DB_TYPE"; exit 5 ;;
	esac

	if test "$RUN_ONE" != "" -a "$LOAD_ONLY_USED_FEATURES" = "1"; then
		#load only features used by this test
		USED_FEATURES_GREP=""
		fcnt=0
		for used_f in $SQL_FEATURES_USED ; do
			let fcnt=fcnt+1
			if test "$fcnt" = "1"; then
				USED_FEATURES_GREP="$used_f"
			else
				USED_FEATURES_GREP="$USED_FEATURES_GREP\|$used_f"
			fi
		done
		if test "$LOAD_ONLY_CURR_DB" = "1"; then
			SQL_FEATURES_NON_ANSI=`grep -w "$USED_FEATURES_GREP" "$CURR_DIR/etc/db_features.conf" | grep -v "^#" | cut --fields=$STAT_FIELD,20,21 --delimiter=" "`
		else
			SQL_FEATURES_NON_ANSI=`grep -w "$USED_FEATURES_GREP" "$CURR_DIR/etc/db_features.conf" | grep -v "^#"`
		fi
	else
		#load all features
		if test "$LOAD_ONLY_CURR_DB" = "1"; then
			SQL_FEATURES_NON_ANSI=`cat $CURR_DIR/etc/db_features.conf | grep -v "^#" | cut --fields=$STAT_FIELD,20,21 --delimiter=' '`
		else
			SQL_FEATURES_NON_ANSI=`cat $CURR_DIR/etc/db_features.conf | grep -v "^#"`
		fi
	fi
#echo $SQL_FEATURES_NON_ANSI
#echo $RDBMS_FILTER
#exit
		
		#Initialise counters:
		CNT=0 ;	FIELD_CNT=0; ROW_CNT=0; DOTS_CNT=0
		D_CNT=0; S_CNT=0; C_CNT=0; P_CNT=0; F_CNT=0; X_CNT=0
		POSIBLE_CNT=0; SUPPORTED_CNT=0; IMPOSSIBLE_CNT=0; DEPEND_CNT=0; 
		IGNORED_CNT=0; PARTIAL_CNT=0
		D_P_CNT=0; D_S_CNT=0; D_I_CNT=0; D_D_CNT=0
		S_P_CNT=0; S_S_CNT=0; S_I_CNT=0; S_D_CNT=0
		C_P_CNT=0; C_S_CNT=0; C_I_CNT=0; C_D_CNT=0
		P_P_CNT=0; P_S_CNT=0; P_I_CNT=0; P_D_CNT=0
		F_P_CNT=0; F_S_CNT=0; F_I_CNT=0; F_D_CNT=0
		X_P_CNT=0; X_S_CNT=0; X_I_CNT=0; X_D_CNT=0

		#determine significant fields
		if test "$LOAD_ONLY_CURR_DB" = "1"; then
			#we loaded only relevant fields allready
			STAT_FIELD=1
			TYPE_FIELD=2
			LABEL_FIELD=3
		else
			#all fields are loaded
			#STAT_FIELD=$STAT_FIELD
			TYPE_FIELD=20
			LABEL_FIELD=21
		fi
		
		##############################################################
		#Chop up the big list into separate lists depending on status
		for field in $SQL_FEATURES_NON_ANSI ; do
			let CNT=CNT+1
			let FIELD_CNT=FIELD_CNT+1
			####################################
			if test "$FIELD_CNT" = "$STAT_FIELD"; then #Feature status
				FEATURE_STATUS="$field"
			####################################
			elif test "$FIELD_CNT" = "$TYPE_FIELD"; then #Feature type
				FEATURE_TYPE="$field"
				case $FEATURE_TYPE in
				D) #DDL 
					let D_CNT=D_CNT+1
					case $FEATURE_STATUS in 
						P) let D_P_CNT=D_P_CNT+1;;
						S) let D_S_CNT=D_S_CNT+1;;
						I) let D_I_CNT=D_I_CNT+1;;
						D) let D_D_CNT=D_D_CNT+1;;
					esac;;
				S) #SQL 
					let S_CNT=S_CNT+1
					case $FEATURE_STATUS in 
						P) let S_P_CNT=S_P_CNT+1;;
						S) let S_S_CNT=S_S_CNT+1;;
						I) let S_I_CNT=S_I_CNT+1;;
						D) let S_D_CNT=S_D_CNT+1;;
					esac;;
				C) #conectivity 
					let C_CNT=C_CNT+1
					case $FEATURE_STATUS in 
						P) let C_P_CNT=C_P_CNT+1;;
						S) let C_S_CNT=C_S_CNT+1;;
						I) let C_I_CNT=C_I_CNT+1;;
						D) let C_D_CNT=C_D_CNT+1;;
					esac;;
				P) #Procedure&trigger(serverSide) 
					let P_CNT=P_CNT+1
					case $FEATURE_STATUS in 
						P) let P_P_CNT=P_P_CNT+1;;
						S) let P_S_CNT=P_S_CNT+1;;
						I) let P_I_CNT=P_I_CNT+1;;
						D) let P_D_CNT=P_D_CNT+1;;
					esac;;
				F) #functions(serverSide)
					let F_CNT=F_CNT+1
					case $FEATURE_STATUS in 
						P) let F_P_CNT=F_P_CNT+1;;
						S) let F_S_CNT=F_S_CNT+1;;
						I) let F_I_CNT=F_I_CNT+1;;
						D) let F_D_CNT=F_D_CNT+1;;
					esac;;
				X) #miXed
					let X_CNT=X_CNT+1
					case $FEATURE_STATUS in 
						P) let X_P_CNT=X_P_CNT+1;;
						S) let X_S_CNT=X_S_CNT+1;;
						I) let X_I_CNT=X_I_CNT+1;;
						D) let X_D_CNT=X_D_CNT+1;;
					esac;;
				*) echo "ERROR: FEATURE_TYPE=$FEATURE_TYPE"
					exit 5
					;;
				esac
			######################################
			elif test "$FIELD_CNT" = "$LABEL_FIELD"; then #Feature name
				FEATURE_NAME="$field"
				case $FEATURE_STATUS in 
				P) SQL_FEATURES_NON_ANSI_POSIBLE="$SQL_FEATURES_NON_ANSI_POSIBLE $FEATURE_NAME"
					let POSIBLE_CNT=POSIBLE_CNT+1 ;;
				S) SQL_FEATURES_NON_ANSI_SUPORTED="$SQL_FEATURES_NON_ANSI_SUPORTED $FEATURE_NAME"
					let SUPPORTED_CNT=SUPPORTED_CNT+1 ;;
				I) SQL_FEATURES_NON_ANSI_IMPOSIBLE="$SQL_FEATURES_NON_ANSI_IMPOSIBLE $FEATURE_NAME"
					let IMPOSSIBLE_CNT=IMPOSSIBLE_CNT+1 ;;
				D) SQL_FEATURES_NON_ANSI_DEPEND="$SQL_FEATURES_NON_ANSI_DEPEND $FEATURE_NAME"
					let DEPEND_CNT=DEPEND_CNT+1 ;;
				G) SQL_FEATURES_NON_ANSI_IGNORED="$SQL_FEATURES_NON_ANSI_IGNORED $FEATURE_NAME"
					let IGNORED_CNT=IGNORED_CNT+1 ;;
				A) SQL_FEATURES_NON_ANSI_PARTIAL="$SQL_FEATURES_NON_ANSI_PARTIAL $FEATURE_NAME"
					let PARTIAL_CNT=PARTIAL_CNT+1 ;;
					
				*) echo "ERROR: FEATURE_STATUS=$FEATURE_STATUS"
					exit 5 ;;
				esac

				if test "$EXTRACT_FEATURE_COMMENTS" = "1"; then 
					func_extract_feature_comments "$FEATURE_NAME"
				fi
			
				let ROW_CNT=ROW_CNT+1
				if test "$VERBOSE" = "1"; then 
					let DOTS_CNT=DOTS_CNT+1
					if test "$DOTS_CNT" = "20"; then 
						DOTS_CNT=0
						DOTS=""
					fi
					DOTS="$DOTS."
					echo -e -n "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bLoading SQL features$DOTS                     "
				fi
				FIELD_CNT=0
			#######################################
			#else
			#	#This is OK - it must be a status field of another database
			#	if test "2" = "1"; then
			#		echo "ERROR: FIELD_CNT=$FIELD_CNT"
			#		exit 5
			#	fi
			fi
		done
		
		#Show features status report for this db
		if test "$SHOW_DB_FEATURES_REPORT" = "1"; then
			echo
			echo " SQL/DB features support status for $DB_TYPE (treated as $FEATURE_DB_TYPE)"
			echo "------------------------------------------------------------------"
			echo "Possible but not working ($POSIBLE_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_POSIBLE"
			echo "Possible by type: DDL=$D_P_CNT SQL=$S_P_CNT Con=$C_P_CNT Proc=$P_P_CNT Func=$F_P_CNT Mix=$X_P_CNT"
			echo 
			echo "Supported ($SUPPORTED_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_SUPORTED"
			echo "Supported by type: DDL=$D_S_CNT SQL=$S_S_CNT Con=$C_S_CNT Proc=$P_S_CNT Func=$F_S_CNT Mix=$X_S_CNT"
			echo 
			echo "Impossible ($IMPOSSIBLE_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_IMPOSIBLE"
			echo "Impossible by type: DDL=$D_I_CNT SQL=$S_I_CNT Con=$C_I_CNT Proc=$P_I_CNT Func=$F_I_CNT Mix=$X_I_CNT"
			echo 
			echo "Depend on back-end ($DEPEND_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_DEPEND"
			echo "Depend by type: DDL=$D_D_CNT SQL=$S_D_CNT Con=$C_D_CNT Proc=$P_D_CNT Func=$F_D_CNT Mix=$X_D_CNT"
			echo 
			echo "Ignored ($IGNORED_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_IGNORED"
			echo			
			echo "Partial ($PARTIAL_CNT):"
			echo "$SQL_FEATURES_NON_ANSI_PARTIAL"
			echo 
			echo "All described features totals:"
			echo "DDL=$D_CNT SQL=$S_CNT Con=$C_CNT Proc=$P_CNT Func=$F_CNT Mixed=$X_CNT Total=$ROW_CNT"
			exit
		fi
		
		if test "2" = "1"; then 
			#Dump sorted list to file - utility function
			SQL_FEATURES_NON_ANSI=`echo $SQL_FEATURES_NON_ANSI | tr " " "\n" | $SORT -n |  tr "\n" " "`
			rm -f all_sql_features.txt
			CNT=0
			for b in $SQL_FEATURES_NON_ANSI; do
			
				echo "			$b \\" >> all_sql_features.txt
			done
			echo "Total $CNT features described unloaded to all_sql_features.txt"
			exit
		fi
								 
		debug "Loaded SQL features list."

}

####################################################################
#Check for incompatible SQL dialect features (tests 234 256 etc...)
function chech_sql_features () {
	 
	debug "Checking SQL features..."

	#NOTE: All tests should at least compile, regardless of what 
	#SQL features are used in the code - so we will skip testing for SQL
	#features if test is compile only, otherwise it might appear that some 
	#tests that are compile-only 'work', but they 'work' because they are 
	#never executed, and if they where, who knows what would happen
	
	#TODO- we have simmilar problem with tests that do not perform any 
	#success checking at run-time, other then that program can run and
	#exits with 0 status - which does not mean that feature is really working
	#We will need to add new description to them, like no_runtime_check
	#and then skip them here too... most of them by now have text "no runtime
	#checking" in test description...
	
	if test "$DISABLE_SQL_FEATURES_CHECK" = "1"; then
		debug "DISABLE_SQL_FEATURES_CHECK=$DISABLE_SQL_FEATURES_CHECK"
		return
	fi

	if test "$COMPILE_ONLY" = "1"; then
		debug "COMPILE_ONLY=$COMPILE_ONLY"
		#We cant ignore checking of SQL features for compile only tests,
		#because even compile can fail when for instance -ecp is used
		#because the SQL is incompatible
		if test "$A4GL_LEXTYPE" = "C"; then 
			return
		fi
	fi

	
	if test "$SQL_FEATURES_USED" = ""; then
		#If test has no SQL/db features description, skip it - should never 
		#happen if this is a db test
		debug "SQL_FEATURES_USED ie empty"
		return
	fi

	if test "1" = "1"; then
	#if test "$VERBOSE" = "1"; then
		#Check that the feature listed in makefile has a pair
		#in features definitions (spelling errors, new features...)
		for a in $SQL_FEATURES_USED; do
			TMP_OK=0
			for b in $SQL_FEATURES_NON_ANSI; do
				if test "$a" = "$b"; then
					#Found it
					TMP_OK=1
					break
				fi
			done
			if test "$TMP_OK" = "0"; then 
				#echo "ERROR: test #$TEST_NO - feature $a not expected. Stop"
				FEATURE_NOT_EXPECTED="$FEATURE_NOT_EXPECTED $TEST_NO=$a"
				#exit 6
			fi
		done
	fi
	INCOMPAT_FEATURE_LIST=
	INCOMPAT_SQL_LIST=
	
	#Skip only db/SQL features known to be impossible on current db, but
	#NOT the ones that are possible but not working
	#use -skip-only-impossible flag instead
	#SKIP_ONLY_IMPOSSIBLE=1
	#temporary: even if you found a reason to skip test because it uses
	#incompatible db/SQL features, do not skip
	#use -disable-sql-features-skip flag instead
	#DISABLE_SQL_FEATURES_SKIP=1
	
	case "$USE_COMP" in
		aubit)
			if test "$SKIP_ONLY_IMPOSSIBLE" = "1" ; then
				#Skip only features known to be inpossible on this db
				INCOMPAT_FEATURE_LIST="$SQL_FEATURES_NON_ANSI_IMPOSIBLE"
			else
				#Skip all features expected to fail
				INCOMPAT_FEATURE_LIST="$SQL_FEATURES_NON_ANSI_POSIBLE \
								$SQL_FEATURES_NON_ANSI_IMPOSIBLE \
								$SQL_FEATURES_NON_ANSI_IGNORED"
							#should I add Depends here?
			fi
			;;
		*) #All other non-Aubit 4GL compilers
			if test "$VERBOSE" = "1"; then 
				echo "FIXME: $DB_TYPE and $USE_COMP - not checking features:"
				echo "$SQL_FEATURES_USED"
			fi
			;;
	esac

	#Perform the actuall check, by comparing the list of features used
	#with list of features expected to fail:
	INCOMPAT_SQL_LIST=
	if test "$INCOMPAT_FEATURE_LIST" != ""; then
		#If there are features we consider incompatible...
		for a in $SQL_FEATURES_USED; do
			#...for every feature test is using...
			for b in $INCOMPAT_FEATURE_LIST; do
				#...look for it on list of features we consider incompatible 
				if test "$a" = "$b"; then
					#If match is found, add it to the list incompatible
					#features this test is using
					if test "$INCOMPAT_SQL_LIST" = ""; then
						#Avoid leading space
						INCOMPAT_SQL_LIST="$a"
					else
						INCOMPAT_SQL_LIST="$INCOMPAT_SQL_LIST $a"
					fi
					#Found that one - check next feature used
					break
				fi
			done
			#If we allread have one incompatible, searching
			#for more wont change the outsome, so break and 
			#save some time IS THIS SMART? WILL IT CONFUSE RESULTS?
			if test "$INCOMPAT_SQL_LIST" != ""; then 
				break
			fi
		done
		
		#If we found reason to skip this test because it uses incompatible 
		#or non-working db/SQL feature...
		if test "$INCOMPAT_SQL_LIST" != ""; then
			#This test contains incompatible db/SQL features
			SQL_FEATURES_COMPATIBLE=0					
			if test "$DISABLE_SQL_FEATURES_SKIP" != "1"; then
				#Skip this test
				if test "$SKIP_INCOMPAT_SQL_LIST" = ""; then
					#Avoid leading space
					SKIP_INCOMPAT_SQL_LIST="$TEST_NO"
				else                        
					SKIP_INCOMPAT_SQL_LIST="$SKIP_INCOMPAT_SQL_LIST $TEST_NO"
				fi
				let SKIP_INCOMPAT_SQL_CNT=SKIP_INCOMPAT_SQL_CNT+1
				SKIP_INCOMPAT_SQL_LIST_WITH_FEATURES="$SKIP_INCOMPAT_SQL_LIST_WITH_FEATURES ($TEST_NO:$INCOMPAT_SQL_LIST)"
				SKIP_REASON="incompatible SQL feature: $INCOMPAT_SQL_LIST"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 28"
			else
				#db/SQL based skip is disabled - do not skip
				SKIP_REASON_NOTSKIP="$INCOMPAT_SQL_LIST"

				#Just confuses things at the moment - turn it back on
				#when lists are clean:
				#We will run it, but we expect it to fail:
				#IS_EXPECT_TO_FAIL_TEST=1
			fi
		else
			#This test DOES NOT contain incompatible db/SQL features
			SQL_FEATURES_COMPATIBLE=1
		fi
	fi

		debug "INCOMPAT_SQL_LIST=$INCOMPAT_SQL_LIST"
		debug "SQL_FEATURES_COMPATIBLE=$SQL_FEATURES_COMPATIBLE"
		debug "DISABLE_SQL_FEATURES_SKIP=$DISABLE_SQL_FEATURES_SKIP"
		debug "SQL_FEATURES_USED=$SQL_FEATURES_USED"

}

###############################################################
#Check if we need to switch transaction logging mode in RDBMS
###############################################################
check_trans_mode () {

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

count_rows () {
tablename=$1
dbname=$2

	SQL="select count(*) from $tablename"
	CNT=`echo "$SQL" | $DBACCESS $dbname 2>/dev/null | grep -v count`
	#Trim it:
	CNT=`echo $CNT`
}

drop_db () {
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

create_db () {
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

test_db_exist () {
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

check_informix () {
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


#####################################################################
check_postgresql () {
	if test "$VERBOSE" = "1"; then 
		echo "PostgreSQL specified (2=$PSQL)"
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
			PGDATA=`ps -auxw | grep postmaster | head -n 1 | awk '{print $14}'`
			#Sometimes retrns clipped path, so test it:
			if test ! -d "$PGDATA"; then
				unset PGDATA
			fi
			if test "$PGDATA" = ""; then
				#This is a backup - but it will probably fail to give us 
				#full command we need to determine PGDATA:
				if test "$VERBOSE" = "1"; then
					echo "WARNING: trying 'ps -efw' because 'ps -auxw' did not work"
				fi
				PGDATA=`ps -efw | grep postmaster | head -n 1 | awk '{print $11}'`
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
		echo "WARNING: specified PGDATA ($PGDATA) is not a directory"
		unset PGDATA
	fi
	
	#Find current PostgreSQL configuration file in use by currently running
	#instance of PG engine (PG_CONF)
	if test "$PG_CONF" = ""; then
		if test -f "$PGDATA/postgresql.conf"; then 
			PG_CONF="$PGDATA/postgresql.conf"
		else
			#This apparently works in PG8, but not in 7.4				
			PG_CONF=`$PSQL -U postgres -d template1 -c "show config_file;"  2>/dev/null | tail -n 3 | grep -v row`
			if ! test -f "$PG_CONF"; then		
				#seems like engine does not keep config file name (tried psql 'SHOW ALL;')
				#So only source of config file location is environment where postmaster
				#command was executed
				warning "failed to determine PG config file location (PG_CONF=$PG_CONF)"
				if test "$PGDATA" != ""; then
					ls -al $PGDATA/*.conf
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
		#	echo "$PGUSER_POSTGRES_PWD" | $POSTGRES_BIN/dropdb $TEST_DB > /tmp/dropdbtmp.log
		#else
			$POSTGRES_BIN/dropdb $TEST_DB > /tmp/dropdbtmp.log
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
		#	echo "$PGUSER_POSTGRES_PWD" | $POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
		#else
			$POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
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
		echo "INFO: DB_TYPE set to $DB_TYPE"
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
		export A4GL_TARGETDIALECT="POSTGRES"
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
		echo "WARNING: PG V7 >WITHOUT< IFX patch is not supported"
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

	note "Using conversion: ${A4GL_SQLDIALECT}-$A4GL_TARGETDIALECT.cnv"
	export A4GL_SQLDIALECT
	export A4GL_TARGETDIALECT
	#exit
#A4GL_SQLCONVERT COMPILE/RUNTIME/SQL Autoconvert SQL from sources files dialect to runtime dialect
	#Conversion of SQL statements in 4GL code, to the SQL dialect of target RDBMS
	#Conversion is only done if you set A4GL_SQLCONVERT=YES and only if
	#the dialect used by the program differs from that used by the DBMS
	#interface.
	export A4GL_SQLCONVERT=YES
	
	#See also settigs under -ecp flag in run_tests - AND MERGE THEM ALL IN ONE PLACE! 
	
}




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


create_unl_db_tables () {
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


#Load all .unl data
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

#Load single .unl file
load_table () {
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


##
# Log test descriptiont into Informix-style .unl file
#
##
function catalogue_unl() {
time=$date_stamp
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
#test 724 has asterix in description
test_desc_txt=`echo $desc_txt | tr "\n" " " | tr "|" " " | tr '*' '<astrerix>'  | tr '?' '<question>'`
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
old_makefile=$IS_OLD_MAKEFILE
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
logfile="$CATALOGUE_UNL_FILE"

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

#total 42 columns 

if test "$CATALOGUE_UNL_DBG" = "1"; then
	echo "1  $dl$time$dl"
	echo "2  $dl$test_no$dl"
	echo "3  $dl$invalid$dl"
	echo "4  $dl$is_db$dl"
	echo "5  $dl$is_ec$dl"
	echo "6  $dl$is_nosilent$dl"
	echo "7  $dl$is_tui$dl"
	echo "8  $dl$is_form$dl"
	echo "9  $dl$is_report$dl"
	echo "10 $dl$is_graphics$dl"
	echo "11 $dl$is_prompt$dl"
	echo "12 $dl$is_dump_screen$dl"
	echo "13 $dl$is_long$dl"
	echo "14 $dl$is_unknown$dl"
	echo "15 $dl$is_cert$dl"
	echo "16 $dl$is_obsolete$dl"
	echo "17 $dl$is_described$dl"
	echo "18 $dl$test_desc_txt$dl"
	echo "19 $dl$test_compat_test$dl"
	echo "20 $dl$expect_code$dl"
	echo "21 $dl$se_required$dl"
	echo "22 $dl$compile_only$dl"
	echo "23 $dl$need_ifx_ver$dl"
	echo "24 $dl$need_trans$dl"
	echo "25 $dl$no_prefix$dl"
	echo "26 $dl$need_compat$dl"
	echo "27 $dl$old_makefile$dl"
	echo "28 $dl$is_pcode_enabled$dl"
	echo "29 $dl$is_no_cron$dl"
	echo "30 $dl$scripted$dl"
	echo "31 $dl$is_window$dl"
	echo "32 $dl$test_ver$dl"
	echo "33 $dl$run_tests_ver$dl"
	echo "34 $dl$last_update$dl"
	echo "35 $dl$expect_fail_cert$dl"
	echo "36 $dl$expect_fail_esqli$dl"
	echo "37 $dl$expect_fail_ecp$dl"
	echo "38 $dl$expect_fail_ifx_p$dl"
	echo "39 $dl$expect_fail_4js$dl"
	echo "40 $dl$expect_fail_querix$dl"
	echo "41 $dl$sql_features_used$dl"
	echo "42 $dl$ansi_sql$dl"

	exit 
else

echo "$time$dl$test_no$dl$invalid$dl$is_db$dl$is_ec$dl$is_nosilent$dl$is_tui\
$dl$is_form$dl$is_report$dl$is_graphics$dl$is_prompt$dl$is_dump_screen\
$dl$is_long$dl$is_unknown$dl$is_cert$dl$is_obsolete$dl$is_described\
$dl$test_desc_txt$dl$test_compat_test$dl$expect_code$dl$se_required\
$dl$compile_only$dl$need_ifx_ver$dl$need_trans$dl$no_prefix$dl$need_compat\
$dl$old_makefile$dl$is_pcode_enabled$dl$is_no_cron$dl$scripted\
$dl$is_window$dl$test_ver$dl$run_tests_ver$dl$last_update$dl$expect_fail_cert\
$dl$expect_fail_esqli$dl$expect_fail_ecp$dl$expect_fail_ifx_p$dl$expect_fail_4js\
$dl$expect_fail_querix$dl$sql_features_used$dl$ansi_sql$dl" >> $logfile

fi

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
#Flags passed to run_tests:
flags="$FLAGS"
aubit_version=`aubit $FGLC -v | grep Version | awk '{print $2}'`
aubit_build=`aubit $FGLC -v | grep Build | awk '{print $3}'`
#Only when non-Aubit 4gl compiler is used
comp_version=""

#No spaces!
let total_time=FINISH_ALL_TIME-START_TIME
#echo "check this: total_time=FINISH_ALL_TIME - START_TIME"
#echo "($total_time = $FINISH_ALL_TIME - $START_TIME)"

c_ver=`gcc --version | grep gcc `
if test "$c_ver" = ""; then 
	c_ver=`gcc --version`
fi

if test "$A4GL_LEXTYPE" = "EC"; then
	#FIXME: adapt for SAP/Querix/Ingres :
	if test "$USE_ECP" = "1" -a "$A4GL_LEXDIALECT" = "POSTGRES"; then
		esql_ver=`$POSTGRES_BIN/ecpg --version`
	fi
	if test "$USE_ECI" = "1" -a "$A4GL_LEXDIALECT" = "INFORMIX"; then
		esql_ver=`esql -V | grep Version | awk '{print $3}'`
	fi
fi

#echo "A4GL_LEXTYPE=$A4GL_LEXTYPE"
#echo "USE_ECP=$USE_ECP"
#echo "A4GL_LEXDIALECT=$A4GL_LEXDIALECT"
#echo "esql_ver=$esql_ver"
#echo "USE_ECI=$USE_ECI"

#Fixme - addapt for non-Informix engines
case "$DB_TYPE" in 
	PG-IFX-74 | PG-74 | PG-80)  db_ver=`$POSTGRES_BIN/postmaster --version` ;;
	IFX-OL) db_ver=`dbaccess -V | grep Version | awk '{print $3}'` ;;
	IFX-SE) db_ver="$DB_TYPE";;
	SQLITE)  db_ver="$DB_TYPE";;
	*)  db_ver="Unknown type: $DB_TYPE";;
esac

set `$MAKE --version | head -n 1 | sed -e 's/^GNU Make version //' -e 's/^GNU Make //' -e 's/, by Richard Stallman and Roland McGrath.//' -e 's/\./ /g'`

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
					TMPgg=`echo $VALUES | sed -e 's/=/ /'`
					NAME=`echo $TMPgg |  awk '{print $1}'`
					VALUE=`echo $TMPgg |  awk '{print $2}'`
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
# Change setting in makefile. Add new one if it does not exist allready
#
##
function change_setting() {
look_for="$1:"
change_to=$2
test_no=$3
if test "$CHG_SETTING_MAKEFILE" = ""; then
	makefile=`ls $CURR_DIR/$test_no/?akefile`
else
	makefile="$CHG_SETTING_MAKEFILE"
fi
tmp_out="$makefile.tmp"

	if test "$makefile" = ""; then
		echo "ERROR: can't get makefile name"
		pwd
		echo "$CURR_DIR/$test_no/?akefile"
		exit 5
	fi
	TMP_TMP=`cat $makefile | grep $look_for`
	if test "$TMP_TMP" = ""; then 
		verbose "Adding new setting $look_for as $change_to in $makefile..."
		echo "" >> $makefile
		#echo "$look_for" >> $makefile
		#echo "	@echo \"$change_to\""  >> $makefile
		echo "$look_for			; @echo \"$change_to\"" >> $makefile
		echo "" >> $makefile
	else
		verbose "Changing value of $look_for to $change_to in $makefile..."

		#Determine if the existing setting is one-line or two-line type
		TMP2=`echo "$TMP_TMP" | grep ";"`
		if test "$TMP2" != ""; then
			IS_TWO_LINE=0
			#echo "One line"
		else
			IS_TWO_LINE=1
			#echo "two line"
		fi
		
		if test "$IS_TWO_LINE" = "1"; then
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
		else
			SUBST_STR="$look_for		; @echo \"$change_to\""
			cat $makefile | sed "s/$TMP_TMP/$SUBST_STR/" > $tmp_out
		fi
#echo $TMP_TMP
#grep "$look_for" "$tmp_out"
#exit
		if test "$VERBOSE" = "1" ; then
			diff $makefile $tmp_out
			RET=$?
		else
			diff $makefile $tmp_out > /dev/null
			RET=$?
		fi
		if test "$RET" = "0"; then 
			verbose "Nothing changed"
		else
			verbose "Changed."
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
	sqlite)
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
function run_sql_script() {
RDBMS=$1
DB=$2
SCRIPT=$3
LOGFILE=$4
LOGFILE_CMD="> $LOGFILE 2>&1"
AS_USER=$5

	if test -f $SCRIPT ; then
		if test "$COMSPEC" != ""; then
			#Native Windows executables know nothing about CygWin paths
			#so we need to translate
			SCRIPT=`cygpath -m "$SCRIPT"`
		fi
		if test "$VERBOSE" = "1"; then
			echo "Running script $SCRIPT"
		fi
	else
		echo "ERROR: named script $SCRIPT does not exist"
		exit 6
	fi

   case $RDBMS in
	informix)
		EXEC="dbaccess $DB -qcr $SCRIPT $LOGFILE_CMD"
		eval $EXEC
		RET=$?
		;;
	postgres)
	
		#if test "$COMSPEC" != ""; then 
		#	if test "$PGUSER_POSTGRES_PWD" = ""; then 
		#		echo "PGUSER_POSTGRES_PWD is empty. STOP."
		#		exit 6
		#	fi
		#	EXEC="echo "$PGUSER_POSTGRES_PWD" | \"$PSQL\" -d $DB -f $SCRIPT $LOGFILE_CMD"
		#else
			EXEC="$PSQL -d $DB -f $SCRIPT $LOGFILE_CMD"
			
		#fi
		if test "$AS_USER" != ""; then
			echo "As user: $AS_USER"
			if test "$COMSPEC" = ""; then #On UNIX
				EXEC="su -l $AS_USER -c '$EXEC'"
			else
				#On Windows, 'postgres' OS account is created WITHOUT 
				#login privilege, so we cant su it
				if test "$PGUSER_POSTGRES_PWD" = ""; then 
					echo "PGUSER_POSTGRES_PWD is empty. STOP."
					exit 6
				fi
				if test "$PGPASSWORD" = ""; then 
					#used by all PG tools to supply password
					echo "PGPASSWORD is empty. STOP."
					exit 6
				fi
				#EXEC="echo "$PGUSER_POSTGRES_PWD" | \"$PSQL\" -d $DB -f $SCRIPT $LOGFILE_CMD"
				#EXEC="$PSQL -h localhost -p 5432 postgres "template1" -f $SCRIPT $LOGFILE_CMD"
				#On Windows, default host is "local socket" whatever that is, so
				#we need to be explict and add -h localhost
				EXEC="$PSQL -h localhost -d $DB -U $AS_USER -f $SCRIPT $LOGFILE_CMD"
			fi
		fi
		if test "$VERBOSE" = "1"; then
			echo "Running: $EXEC"
		fi
		eval $EXEC
		RET=$?
		#psql sometimes does not exit with non-zero status on error
		TT=`grep "ERROR:" $LOGFILE`
		if test "$TT" = ""; then 
			TT=`grep "syntax error" $LOGFILE`
		fi
		if test "$TT" != ""; then
			echo "Error: see $LOGFILE"
			echo $TT
			exit 2
		fi
		
		;;
		
	sqlite)
		if test "$VERBOSE" = "1"; then 
			echo "cat $SCRIPT | $SQLITE_EXE $SQLITE_DB"
		fi
		cat $SCRIPT | $SQLITE_EXE $SQLITE_DB
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
		if test -f $LOGFILE ; then
			echo "returned code $RET. See $LOGFILE : (head only:...)"
			head $LOGFILE
		else
			echo "returned code $RET. Logfile $LOGFILE was not created."
		fi
		exit $RET
	else
		if test "$VERBOSE" = "1"; then
			echo "Command returned code $RET"
		fi
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
		echo "Converting DDL SQL..."	
		convert_sql ddl $RDBMS $SCRIPT
		echo "Creating tables..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		echo "Converting data SQL..."		
		convert_sql data $RDBMS $SCRIPT
		echo "Loading data..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		;;
	sqlite)
		convert_sql ddl $RDBMS $SCRIPT
		echo "Creating tables..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		convert_sql data $RDBMS $SCRIPT
		echo "Loading data..."
		run_sql_script $RDBMS $TEST_DB $SCRIPT $LOGFILE
		
		if ! test -f $SQLITE_DB ; then
			echo "Creation of SQLite db failed: file:"
			echo "$SQLITE_DB"
			echo "does not exist. Stop"
			exit 4
		fi
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


##
# Show human readable description of the test, and count totals
# Called from testing loop
#
# @param 
##
function show_test_info() {
			
			echo " ------------------- Info for test $TEST_NO -----------------------"		

			if test "$TEMPLATE_COMMENT" = "1"; then 
				echo "WARNING: test still contains template comment in makefile"
				let TEMPLATE_COMMENT_CNT=TEMPLATE_COMMENT_CNT+1
				TEMPLATE_COMMENT_LIST="$TEMPLATE_COMMENT_LIST $TEST_NO"
			fi
			
			if test "$IS_OLD_MAKEFILE" = "1" \
				-a "$IS_DESCRIBED" = "1" \
				-a "$IS_UNKNOWN_TEST" != "1"; \
			then
				echo "Please migrate folowing test info from 'run_tests' script to makefile:"
				echo ""
				let MIGRATE_DESC_CNT=MIGRATE_DESC_CNT+1
				MIGRATE_DESC_LIST="$MIGRATE_DESC_LIST $TEST_NO"			
			fi
			
			if test "$desc_txt" != "" ; then
				echo ""
				echo $desc_txt
				echo ""
				let HAS_DESC_TXT_CNT=HAS_DESC_TXT_CNT+1
			fi
			
			if test "$IS_REPORT_TEST" = "1"; then
				echo "Test contains REPORT block"
				let IS_REPORT_TEST_CNT=IS_REPORT_TEST_CNT+1
			fi
			if test "$EXPECT_CODE" != "0" ; then
				if test "$EXPECT_CODE" = "x" ; then
					echo "Test is expected to exit with non-zero code"			
				else
					echo "Test is expected to exit with code $EXPECT_CODE"
				fi
				let NON_ZERO_EXIT_CNT=NON_ZERO_EXIT_CNT+1
			fi
			if test "$COMPILE_ONLY" = "1" ; then
				echo "Test is compile only, no execution will be attempted"
				let COMPILE_ONLY_CNT=COMPILE_ONLY_CNT+1
			fi
			if test "$IS_PCODE_ENABLED" = "1" ; then
				#All tests descxribed by makefiel are P-code enabled amyway
				echo "Test is P-CODE testing enabled"
				let IS_PCODE_ENABLED_CNT=IS_PCODE_ENABLED_CNT+1
			fi
			if test "$IS_DESCRIBED" != "1" ; then
				echo "*** Test not described ***"
				let NOT_DESCRIBED_CNT=NOT_DESCRIBED_CNT+1
				NOT_DESCRIBED_LIST="$NOT_DESCRIBED_LIST $TEST_NO"
			fi
			if test "$IS_INVALID_TEST" = "1"; then 
				echo "**** TEST MARKED INVALID IN run_tests ******"
				let IS_INVALID_CNT=IS_INVALID_CNT+1
				IS_INVALID_LIST="$IS_INVALID_LIST $TEST_NO"
			fi
			if test "$IS_EXPECT_TO_FAIL_TEST" = "1"; then 
				echo "**** TEST EXPECTED TO FAIL BECAUSE OF THE AUBIT4GL BUG ******"
				let EXPECT_FAIL_CNT=EXPECT_FAIL_CNT+1
				EXPECT_FAIL_LIST="$EXPECT_FAIL_LIST $TEST_NO"
			fi
			if test "$IS_DB_TEST" = "1"; then
				echo "Test needs database"
				let IS_DB_TEST_CNT=IS_DB_TEST_CNT+1
				if test "$SE_REQUIRED" = "1"; then
					echo "Test requires Informix SE RDBMS"
					let IS_SE_REQUIRED_CNT=IS_SE_REQUIRED_CNT+1
				fi
				if test "$NEED_TRANSACTION" = "2" ; then
					echo "Database MUST NOT have transactions enabled for this test."
				fi
				if test "$NEED_TRANSACTION" = "1" ; then
					echo "Database MUST have transactions enabled for this test."
				fi
				if test "$IS_MAKE_ANSI_SQL_COMPAT" != ""; then
					if test "$IS_MAKE_ANSI_SQL_COMPAT" = "1"; then
						echo "Is ANSI SQL 92 compatible"
					else
						echo "Is __NOT__ ANSI SQL 92 compatible"
					fi
				fi
				if test "$NEED_IFX_VERSION" != "" -a "$NEED_IFX_VERSION" != "0"; then
					echo "Needs at least version $NEED_IFX_VERSION of Informix 4gl."
				fi
				if test "$SQL_FEATURES_USED" != ""; then 
					echo "Uses SQL statemets features: $SQL_FEATURES_USED"
				fi
				
			fi
			if test "$ec_test" = "1"; then
				echo "Uses/require ESQL compiler output, instead of C output"
				let IS_EC_TEST_CNT=IS_EC_TEST_CNT+1
			fi
			if test "$IS_NOSILENT_TEST" = "1"; then
				echo "Test will fail if not running on screen (curses)"
				let IS_NOSILENT_CNT=IS_NOSILENT_CNT+1
			fi
			if test "$IS_TUI_TEST" = "1"; then
				echo "Test uses curses and/or screeen dump and may fail when TERM!=xterm"
				echo "Anything that uses a screen dump may have specific attributes set which may"
				echo "fail if TERM!=xterm"
				echo "This core dumps on MinGW and messes up the terminal completely."
				echo "On Cygwin they don't core dump, but this tests fail"
				let IS_TUI_TEST_CNT=IS_TUI_TEST_CNT+1
			fi
			if test "$IS_FORM_TEST" = "1"; then
				echo "Test uses .per form files"
				let IS_FORM_TEST_CNT=IS_FORM_TEST_CNT+1
			fi
			if test "$IS_GRAPHIC_TEST" = "1"; then
				echo "Test that use graphic characters in forms that may be platform dependent"
				let IS_GRAPHIC_TEST_CNT=IS_GRAPHIC_TEST_CNT+1
			fi
			if test "$IS_CONSOLE_PROMPT_TEST" = "1"; then
				echo "Test waits for user's input in CONSOLE mode, because automated testing"
				echo "was not implemented there, so we must skip them untill this is implemented"
				let IS_CONSOLE_PROMPT_CNT=IS_CONSOLE_PROMPT_CNT+1
			fi
			if test "$IS_DUMP_SCREEN_TEST" = "1"; then
				echo "test uses aclfgl_aclfgl_dump_screen, A4GL_clr_window or aclfgl_fgl_drawbox, so"
				echo "it won't work in CONSOLE mode"
				let IS_DUMP_SCREEN_CNT=IS_DUMP_SCREEN_CNT+1
			fi
			if test "$IS_LONG_TEST" = "1"; then
				echo "Test takes more then 10 minutes to compile or run"
				let IS_LONG_CNT=IS_LONG_CNT+1
			fi
			if test "$IS_CERT_TEST" = "1"; then
				echo "Tests is certified to run (with -eci) If it fails, something was probably broken"
				echo "in current code."
				let IS_CERT_CNT=IS_CERT_CNT+1
			fi
			if test "$IS_OBSOLETE_TEST" = "1"; then
				echo "test is superceeded or obsoleted and should be silently skipped"
				let IS_OBSOLETE_CNT=IS_OBSOLETE_CNT+1
				IS_OBSOLETE_LIST="$IS_OBSOLETE_LIST $TEST_NO"
			fi
			if test "$compat_test" = "1"; then
				echo "Test can be run using any 4GL compatible compiler, not just Aubit"
				let IS_COMPAT_CNT=IS_COMPAT_CNT+1
			fi
			if test "$need_compat" = "1"; then
				echo "Test requires Aubit to be in Informix compatibility mode"
			fi
			if test "$IS_UNKNOWN_TEST" = "1"; then 
				echo "Test is clasified as UNKNOWN - please corect this."
				let UNKNOWN_TEST_CNT=UNKNOWN_TEST_CNT+1			
				echo ""
			fi
			echo ""
			#if test "$INFO_TEST" = "1"; then
				#now called from main loop, to enable creation of
				#unl catalogue at the same time when running tests (FULL_LOOP)
				#if test "$CATALOGUE_UNL" = "1"; then 
				#	catalogue_unl
				#fi
				#continue
			#fi
}

###############################
#
function check_skip_non_db() {
	
		if test "$IS_DB_TEST" != "1" -a "$ONLY_DB" = "1"; then
			SKIP_REASON="non-DB"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 11"
			SKIP_NONDB_LIST="$SKIP_NONDB_LIST $TEST_NO"
	    fi
}

##
# #See if we can/should run this test, or should we skip it
# Called from testing loop
#
# @param 
##
function check_skip() {

	debug "Determining if we can/should run test $TEST_NO"
	
	if test "$IS_OBSOLETE_TEST" = "1"; then
		if test "$VERBOSE" = "1"; then
			echo "Skipping obsolete test $TEST_NO (not counting or logging)"
		fi
        continue
    fi
	if [ ! -f $CURR_DIR/$TEST_NO/?akefile ]; then
		SKIP_REASON="no Makefile - mark it invalid"
		SKIP_REASON_CODES="$SKIP_REASON_CODES 18"
		SKIP_NOMAKEFILE_LIST="$SKIP_NOMAKEFILE_LIST $TEST_NO"
		IS_INVALID_TEST=1
	fi
	if test "$IS_INVALID_TEST" = "1"; then
		let SKIP_INVALID_CNT=SKIP_INVALID_CNT+1
		SKIP_INVALID_LIST="$SKIP_INVALID_LIST $TEST_NO"
		SKIP_REASON="invalid test"
		SKIP_REASON_CODES="$SKIP_REASON_CODES 1"
	else
		if test "$NEED_RDBMS" != ""; then
			IS_OK=0
			for RDBMS in $NEED_RDBMS ; do
				#echo "RDBMS=$RDBMS"
				MATCH_THIS="$RDBMS"
				case $RDBMS in
					*-ANY)
						#echo "sed-ing"
						MATCH_THIS=`echo "$RDBMS" | sed -e 's/-ANY/-\*/'`
						#echo "sed-ing done"
					;;
				esac
				#echo "Matching $DB_TYPE with $MATCH_THIS"
				case $DB_TYPE in 
					$MATCH_THIS) IS_OK=1 ;;
				esac
				if test "$IS_OK" = "1"; then
					break
				fi
			done
			if test "$IS_OK" != "1"; then
				SKIP_REASON="RDBMS $DB_TYPE incompatible with test (need $NEED_RDBMS)"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 67"
				SKIP_RDBMS_LIST="$SKIP_RDBMS_LIST $TEST_NO"
			fi
		fi
	
		if test "$NEED_PLUGIN" != ""; then
			for plugin in $NEED_PLUGIN ; do
				case $plugin in 
				*.prg)
					progbase=`basename $plugin .prg`
					if ! test -f "$BINS_DIR/$progbase"; then
						SKIP_REASON="Missing executable $plugin"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 68"
						SKIP_PLUGIN_LIST="$SKIP_PLUGIN_LIST ($TEST_NO=$plugin)"
						break
					fi
					;;
				*)
					if ! test -f "$LIBS_DIR/lib$plugin$SO_EXT"; then
						SKIP_REASON="Missing plug-in $plugin"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 68"
						SKIP_PLUGIN_LIST="$SKIP_PLUGIN_LIST ($TEST_NO=$plugin)"
						break
					fi
					;;
				esac
			done
		fi
		if test "$A4GL_FAKELEXTYPE" = "PCODE" -a "$IS_PCODE_ENABLED" = "0"; then
			SKIP_REASON="not p-code enabled"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 3"
			SKIP_PCODE_LIST="$SKIP_PCODE_LIST $TEST_NO"
        fi
		if test "$IS_BLACKLIST_TEST" = "1"; then
			SKIP_BLACKLIST_LIST="$SKIP_BLACKLIST_LIST $TEST_NO"
			SKIP_REASON="blacklisted"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 4"
	    fi
		
		if test "$IS_TUI_TEST" != "1" -a "$ONLY_TUI" = "1"; then
			SKIP_REASON="non-TUI"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 5"			
			SKIP_TUI_LIST="$SKIP_TUI_LIST $TEST_NO"
	    fi
		if test "$SKIP_EXPECT_FAIL" = "1" -a "$IS_EXPECT_TO_FAIL_TEST" = "1"; then
			SKIP_REASON="expected to fail"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 6"
			SKIP_EXPECT_FAIL_LIST="$SKIP_EXPECT_FAIL_LIST $TEST_NO"
		fi
	
		if test "$IS_LONG_TEST" = "1" -a "$SKIP_LONG" = "1"; then
			SKIP_REASON="long running"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 7"
			SKIP_LONG_LIST="$SKIP_LONG_LIST $TEST_NO"
	    fi
		if test "$UI" = "CONSOLE" && (test "$IS_CONSOLE_PROMPT_TEST" = "1" -o "$IS_DUMP_SCREEN_TEST" = "1" -o "$IS_FORM_TEST" = "1") ; then
			SKIP_REASON="in CONSOLE mode - uses forms or dump_screen()."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 8"
			SKIP_CONSOLE_LIST="$SKIP_CONSOLE_LIST $TEST_NO"
	    fi
#This now appears to be working
#DUMP_SCREEN_TESTS="10 102 103 104 105 11 15 220 223 229 230 231 236 247 \
#	252 254 263 29 4 6 67 74 8 276 277 278"

#		if test "$IS_DUMP_SCREEN_TEST" = "1" && (test "$UI" = "HL_TUIN" -o "$UI" = "HL_TUINs") ; then
#			SKIP_REASON="scr_dump() screen_dump() not implemented in PDcurses."
#			SKIP_REASON_CODES="$SKIP_REASON_CODES 9"
#			SKIP_NO_SCRDUMP_PDCURSES_LIST="$SKIP_NO_SCRDUMP_PDCURSES_LIST $TEST_NO"
#	    fi

	    if test "$IS_DESCRIBED" != "1" -a "$DESCRIBED_ONLY" = "1" \
			-a "$IS_OLD_MAKEFILE" != "1"; then
			SKIP_REASON="not described"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 10"
			SKIP_NODESC_LIST="$SKIP_NODESC_LIST $TEST_NO"
	    fi
		
		#check if we are to skip non-db tests
		check_skip_non_db
		
		#check if we are to skip db tests
		if test "$IS_DB_TEST" = "1" -a "$NO_DB" = "1"; then
			SKIP_REASON="DB dependent"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 12"
			SKIP_DB_LIST="$SKIP_DB_LIST $TEST_NO"
	    fi
	    if test "$IS_NOSILENT_TEST" = "1" -a "$SILENT" = "1"; then
			SKIP_REASON="cannot run in silent mode."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 13"
			SKIP_NOSILENT_LIST="$SKIP_NOSILENT_LIST $TEST_NO"
	    fi
		#Obsolete-using PDcurses now, not CygWin Ncurses:
	    #if test "$IS_TUI_TEST" = "1" -a "$TERM" != "xterm" -a "$PLATFORM" = "MINGW"; then
		#	SKIP_TUI_NOT_XTERM_LIST="$SKIP_TUI_NOT_XTERM_LIST $TEST_NO"
		#   SKIP_REASON_CODES="$SKIP_REASON_CODES 14"
		#	SKIP_REASON="cannot run with TERM=$TERM on MinGW using Cygwin Curses."
	    #fi
		
		#This seems to be working now too, since Mike rewrited the dump_screen() function
		#if test "$IS_DUMP_SCREEN_TEST" = "1" -a "$TERM" != "xterm"; then
		#	SKIP_DUMP_SCREEN_NOT_XTERM_LIST="$SKIP_DUMP_SCREEN_NOT_XTERM_LIST $TEST_NO"
		#	SKIP_REASON="cannot use dump_screen() with TERM=$TERM (need xterm)."
		#	SKIP_REASON_CODES="$SKIP_REASON_CODES 15"
		#fi
	    if test "$IS_GRAPHIC_TEST" = "1" -a "$NO_GRAPHIC" = "1"; then
			SKIP_REASON="uses platform specific characters."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 16"
			SKIP_GRAPHIC_LIST="$SKIP_GRAPHIC_LIST $TEST_NO"
	    fi
	    if test "$IS_NO_CRON_TEST" = "1" -a "$CRON_JOB" = "1"; then
			let IS_NO_CRON_CNT=IS_NO_CRON_CNT+1
			SKIP_REASON="fails when run as cron job"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 17"
			SKIP_NO_CRON_LIST="$SKIP_NO_CRON_LIST $TEST_NO"
	    fi
		
		if test "$USE_COMP" != "aubit"; then
			#tests that apply only to non-Aubit 4GL compilers
			if test "$NEED_IFX_VERSION" != "" -a "$NEED_IFX_VERSION" != "0"; then
				if test "$USE_COMP" = "ifx-p"; then
					set `echo $NEED_IFX_VERSION | sed -e 's/\./ /g'` #@echo "7.31"
					NO_GO=0
					if test "$1" -lt "$I4GL_PCOMPILER_VER_MAJOR"; then
						NO_GO=1
					else
						if test "$I4GL_PCOMPILER_VER_MINOR" -lt "$2" -a "$1" = "$I4GL_PCOMPILER_VER_MAJOR"; then 
							NO_GO=1
						fi
					fi
					if test "$NO_GO" = "1"; then
						SKIP_REASON="needs version $NEED_IFX_VERSION but have $I4GL_PCOMPILER_VER_MAJOR.$I4GL_PCOMPILER_VER_MINOR"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 2"					
						SKIP_NOVERSION_LIST="$SKIP_NOVERSION_LIST $TEST_NO"
					else
						if test "$VERBOSE" = "1"; then
							echo "Version check OK: $NEED_IFX_VERSION >= $I4GL_PCOMPILER_VER_MAJOR.$I4GL_PCOMPILER_VER_MINOR" >> $LOGFILE
						fi
					fi
				fi
			fi
			if test "$USE_COMP" = "4js-p"; then
				TMP1=""
				TMP1=`find $CURR_DIR/$TEST_NO -name "*.4gl" -exec grep -l aclfgl_dump_screen {} \;`
				if test "$TMP1" != ""; then 
					SKIP_REASON="can't dump_screen with 4js"
					SKIP_REASON_CODES="$SKIP_REASON_CODES 19"
					SKIP_DUMP_SCREEN="$SKIP_DUMP_SCREEN $TEST_NO"
				fi
			fi
			if test -f "$TEST_NO/keys.in"; then 
				SKIP_REASON="$USE_COMP specified but test uses keys.in"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 20"
				SKIP_KEYS_IN_LIST="$SKIP_KEYS_IN_LIST $TEST_NO"
			fi
			if test "$compat_test" != "1" -a "$IGNORE_COMPAT" != "1"; then
				SKIP_REASON="$USE_COMP specified on non-compat test"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 21"
				SKIP_NOCOMPAT_LIST="$SKIP_NOCOMPAT_LIST $TEST_NO"
			fi
			if test "$IS_OLD_MAKEFILE" = "1" \
				-a "$IS_DESCRIBED" = "1" \
				-a "$IS_UNKNOWN_TEST" != "1" || \
				test "$desc_txt" = "Old makefile"
			then 
				#Old makefiles don't know how to use non-Aubit compilers
				SKIP_OLD_MAKEFILE_LIST="$SKIP_OLD_MAKEFILE_LIST $TEST_NO"
				SKIP_REASON="$USE_COMP specified on test having old makefile"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 22"
			fi
		fi #"$USE_COMP" != "aubit"

		if test "$IS_DB_TEST" = "1"; then
			#Checks that make sense only if test uses database
			if test "$SKIP_NON_ANSI" = "1" -a "$IS_MAKE_ANSI_SQL_COMPAT" = "0"; then
				let SKIP_NON_ANSI_CNT=SKIP_NON_ANSI_CNT+1
				SKIP_NON_ANSI_LIST="$SKIP_NON_ANSI_LIST $TEST_NO"
				SKIP_REASON="not ANSI SQL compatible"
				SKIP_REASON_CODES="$SKIP_REASON_CODES 66"
			fi
		
			#Check if we need to switch transaction logging mode in RDBMS
			check_trans_mode
			
			#Check for incompatible SQL dialect features
			chech_sql_features
		fi
		
	fi #IS_INVALID_TEST

	debug "exiting function check_skip()"
	

}

#Check if makefile is old or new type; sets IS_OLD_MAKEFILE
function check_makefile_type() {
#DBG_check_makefile_type=1
	#We can no longer use description target itself to find out if test uses new or old 
	#makefiles, since Mike started adding desc target to old makefiles, so we 
	#now have OLD makefiles that DO have text description (desc target) but
	#little if anything else of other descriptions, and do not use any
	#functionality of new makefiles. So, to find out if this test has old
	#or new makefile, we will use form_test target... ATM, no makefile below
	#100 has it.
	
	#IS_FORM_TEST=`$MAKE -s -C $TEST_NO form_test 2>/dev/null`
	#if test "$IS_FORM_TEST" = ""; then
	#pwd
	#ls $TEST_NO/?akefile
	#Note: missing [m|M]akefile is treated as OLD makefile
	if grep "^include" $TEST_NO/?akefile > /dev/null 2>&1 ; then
		if test "$DBG_check_makefile_type" = "1"; then
			echo "new makefile"
		fi
		IS_OLD_MAKEFILE=0
	else
		if test "$DBG_check_makefile_type" = "1"; then
			echo "old makefile"
		fi
		IS_OLD_MAKEFILE=1
	fi
	if test "$DBG_check_makefile_type" = "1"; then
		exit
	fi
}

#see if Makefile contains description. Both old and new makefiles
#may contain description now, but new ones may contain a template text
#instead of actuall description text
function check_desc_txt() {
	
	if test "$desc_txt" = "" ; then
		desc_txt=`$MAKE -s -C $TEST_NO desc 2>/dev/null`
	fi

	if test "$desc_txt" != "" ; then
		#see if this description is unchanged from template, which 
		#means that developer who added the test forgot to descibe it
		TMP1=`echo $desc_txt | grep "This is not a test but a Testing template"`
	
		if test "$TMP1" != ""; then 
			if test "$INFO_TEST" = "1" -o "$RUN_AND_INFO" = "1"; then
				TEMPLATE_COMMENT=1
			fi
			desc_txt=""
			IS_DESCRIBED=0
		else
			ALL_DESCRIBED_TESTS="$ALL_DESCRIBED_TESTS $TEST_NO"
			IS_DESCRIBED=1
		fi
	else
		IS_DESCRIBED=0
	fi
}


#Instead of reading descriptions for each test before we can determine
#if this test should be skiped, use allready loaded cached descriptions
function check_cached_skip_reasons() {

	for b in $IS_DB_TEST_CACHE; do
		if test "$b" = "$TEST_NO"; then
			IS_DB_TEST=1
		fi
	done

	check_skip_non_db

}


#decide if we WANT to skip test
function do_skip() {
	DO_SKIP=0	
	if test "$NO_SKIP" != "1"; then
		#skip is allowed
		if test "$SKIP_REASON" != ""; then
			#have reason to skip - skip the test
			if test "$VERBOSE" = "1"; then
				#Message shows only LAST reason encountered
				#SKIP_REASON_CODES show ALL reasons codes
				echo "Skip #$TEST_NO: $SKIP_REASON ($SKIP_REASON_CODES)"  >> $LOGFILE
			fi
			let SKIP_CNT=SKIP_CNT+1
			if test "$UNL_LOG" = "1"; then
				#test_no=$1 result=$2 skip_reason=$3 expect_fail=$4 test_version=$5 db_has_trans=$6
				result_unl $TEST_NO "" "$SKIP_REASON_CODES" $IS_EXPECT_TO_FAIL_TEST "" $DB_HAS_TRANSACTION
			fi
			DO_SKIP=1
		fi
    fi
}


##############################################################################
#                           Finalise results & clean-up
##############################################################################

#####################
#Complete results log file(s), show to user
function show_results () {

	cd $CURR_DIR
	calc_percent "$PASS_CNT" "$RUN_CNT"
	close_all_log_files
	
	#####################
	#Show results to the user
	if test "$SHORT_SUMMARY" != "1"; then
		cat $LOGFILE
	else
		#SHORT_SUMMARY is 1 
		if test "$NO_ECHO" != "1"; then
			echo "Skipped: $SKIP_CNT Passed: $PASS_CNT Failed: $FAIL_CNT"
			echo "See $LOGFILE for details."
		fi
	fi
	echo ""
	cd $CURR_DIR

}

##################################
# create/complete/close all results log files
function close_all_log_files () {

	verbose_results
	log_sqlfeatures
	log_resources
	log_results
	if test "$ALL_DB" = "1"; then
		log_full_list
	fi
	if test "$UNL_LOG" = "1"; then
		#output summary result to .unl file
		FINISH_ALL_TIME=`date +%s`
		test_run_unl
	fi
}

#############################
# log current configuration as seen by Aubit (aubit-config)
function log_resources () {
	
	echo "----------------------------- aubit-config -a ------------------------------" > $RESLOGFILE
	$AUBITDIR_UNIX/bin/aubit-config$EXE_EXT -a  >> $RESLOGFILE 2>&1

}

#############################################################
# Is this used when running multiple tests configurations in one loop?
function log_full_list () {

	#TODO - is this file allready open?
	echo "Skipped: $SKIP_CNT Passed: $PASS_CNT Failed: $FAIL_CNT" >> $CURR_DIR/alldb.log
	echo "" >> $CURR_DIR/alldb.log
	
	#Load counter from file to variable
	FAIL_CNT_TOT=`cat $CURR_DIR/fail.cnt`
	PASS_CNT_TOT=`cat $CURR_DIR/pass.cnt`
	
	if test "$FAIL_CNT_TOT" = ""; then
		FAIL_CNT_TOT=0
	fi
	if test "$PASS_CNT_TOT" = ""; then
		PASS_CNT_TOT=0
	fi
	
	let FAIL_CNT_NEW=FAIL_CNT+FAIL_CNT_TOT
	let PASS_CNT_NEW=PASS_CNT+PASS_CNT_TOT
	
	#Store increased values to same files
	echo "$FAIL_CNT_NEW" > $CURR_DIR/fail.cnt
	echo "$PASS_CNT_NEW" > $CURR_DIR/pass.cnt

}

#############################
# Output verbose results info to verbose results log file 
function verbose_results () {

	VERBOSE_RESULTS_LOG="$CURR_DIR/verbose_results.log"
	rm -f $VERBOSE_RESULTS_LOG

	echo "Platform: $PLATFORM" >> $VERBOSE_RESULTS_LOG
	
	if test "$SKIP_DUMP_SCREEN_NOT_XTERM_LIST" != "" ; then 
		echo "Skipped DUMP_SCREEN - not xterm: $SKIP_DUMP_SCREEN_NOT_XTERM_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_NON_ANSI_LIST" != ""; then	
		echo "Skipped ANSI SQL incompatible: ($SKIP_NON_ANSI_CNT) $SKIP_NON_ANSI_LIST" >> $VERBOSE_RESULTS_LOG	
	fi

	if test "$SKIP_INVALID_LIST" != "" ; then 
		echo "Skipped $SKIP_INVALID_CNT tests as invalid (PLEASE FIX OR OBSOLETE): $SKIP_INVALID_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_INCOMPAT_SQL_LIST" != "" ; then 
		#echo "Skipped $SKIP_INCOMPAT_SQL_CNT tests with incompatible feature" >> $LOGFILE
		echo "Skipped incompatible feature: ($SKIP_INCOMPAT_SQL_CNT) $SKIP_INCOMPAT_SQL_LIST_WITH_FEATURES"  >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_PCODE_LIST" != "" ; then 
		echo "Skipped PCODE: $SKIP_PCODE_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_TUI_LIST" != "" ; then 
		echo "Skipped TUI: $SKIP_TUI_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_LONG_LIST" != "" ; then 
		echo "Skipped long: $SKIP_LONG_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_CONSOLE_LIST" != "" ; then 
		echo "Skipped console: $SKIP_CONSOLE_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_BLACKLIST_LIST" != "" ; then 
		echo "Skipped black-listed: $SKIP_BLACKLIST_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_NO_SCRDUMP_PDCURSES_LIST" != "" ; then 
		echo "Skipped screen_dump() with PDcurses: $SKIP_NO_SCRDUMP_PDCURSES_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$VERBOSE" = "1"; then
		#usually very long lists, and not terribly usefull
		if test "$SKIP_NONDB_LIST" != "" ; then 
			echo "Skipped NODB: $SKIP_NONDB_LIST" >> $VERBOSE_RESULTS_LOG
		fi 
		if test "$SKIP_DB_LIST" != "" ; then 
			echo "Skipped DB: $SKIP_DB_LIST" >> $VERBOSE_RESULTS_LOG
		fi
	fi
	if test "$SKIP_NOSILENT_LIST" != "" ; then 
		echo "Skipped NOSILENT: $SKIP_NOSILENT_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_NOVERSION_LIST" != "" ; then 
		echo "Skipped NOVERSION: $SKIP_NOVERSION_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_GRAPHIC_LIST" != "" ; then 
		echo "Skipped GRAPHIC: $SKIP_GRAPHIC_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_NOMAKEFILE_LIST" != "" ; then 
		echo "Skipped NOMEAKEFILE: $SKIP_NOMAKEFILE_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_NOCOMPAT_LIST" != "" ; then 
		echo "Skipped NOCOMPAT: $SKIP_NOCOMPAT_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_NO_CRON_LIST" != "" ; then 
		echo "Skipped NO_CRON: ($IS_NO_CRON_CNT) $SKIP_NO_CRON_LIST" >> $VERBOSE_RESULTS_LOG
	fi
	if test "$SKIP_TRANS_LIST" != "" ; then 
		echo "Skipped 'cant determine trans state' or 'cant swich trans mode': $SKIP_TRANS_LIST" >> $VERBOSE_RESULTS_LOG
	fi 
	if test "$SKIP_RDBMS_LIST" != ""; then 
		echo "Skipped tests incompatbile with used RDBMS: $SKIP_RDBMS_LIST" >> $VERBOSE_RESULTS_LOG	
	fi
	if test "$SKIP_PLUGIN_LIST" != "" ; then
		echo "Skipped tests that need missing plug-in: $SKIP_PLUGIN_LIST" >> $VERBOSE_RESULTS_LOG	
	fi
	if test "$PASS_FULL_LIST" = "1"; then 
		if test "$PASS_DB_TESTS" != "" ; then 
			echo "Pass db: ($PASS_DB_CNT) $PASS_DB_TESTS" >> $VERBOSE_RESULTS_LOG
		fi
		if test "$PASS_NONDB_TESTS" != "" ; then 
			echo "Pass non-db: ($PASS_NONDB_CNT) $PASS_NONDB_TESTS" >> $VERBOSE_RESULTS_LOG
		fi
	fi
	#if test "$VERBOSE_RESULTS" = "1"; then
		echo "Pass db: ($PASS_DB_CNT) Pass non-db: ($PASS_NONDB_CNT)" >> $VERBOSE_RESULTS_LOG
	#fi
	if test "$FAIL_FULL_LIST" = "1"; then	
		if test "$FAIL_DB_TESTS" != "" ; then 
			echo "Fail db: ($FAIL_DB_CNT) $FAIL_DB_TESTS" >> $VERBOSE_RESULTS_LOG
		fi
		if test "$FAIL_NONDB_TESTS" != "" ; then 
			echo "Fail non-db: ($FAIL_NONDB_CNT) $FAIL_NONDB_TESTS" >> $VERBOSE_RESULTS_LOG
		fi
	fi
	#if test "$VERBOSE_RESULTS" = "1"; then
		echo "Fail db: ($FAIL_DB_CNT) Fail non-db: ($FAIL_NONDB_CNT)" >> $VERBOSE_RESULTS_LOG
	#fi
	ALL_FAILED="$FAIL_DB_TESTS $FAIL_NONDB_TESTS"
	if test "$ALL_FAILED" != " " -a "$SHOW_FAIL_DESC" = "1"; then 
		echo "------------------------- Failed tests descriptions ---------------------------" >> $VERBOSE_RESULTS_LOG
		for TEST_NO in $ALL_FAILED; do
			desc_txt=`$MAKE -s -C $TEST_NO desc 2>/dev/null`
			echo "#$TEST_NO : $desc_txt" >> $VERBOSE_RESULTS_LOG
		done
		echo "-------------------------------------------------------------------------------" >> $VERBOSE_RESULTS_LOG
	fi

	if test "$NO_RUNTIME_ERR_CHECK_LIST" != ""; then
		echo "WARNING: PASS tests that perform no run-time error checking ($NO_RUNTIME_ERR_CHECK_CNT): $NO_RUNTIME_ERR_CHECK_LIST"  >> $VERBOSE_RESULTS_LOG
	fi

	if test "$UNL_LOG" = "1"; then 
		echo "" >> $VERBOSE_RESULTS_LOG
		echo "Logging files closed:" >> $VERBOSE_RESULTS_LOG
		echo "  results_$HOSTNAME$U$date_stamp.unl" >> $VERBOSE_RESULTS_LOG
		echo "  test_run_$HOSTNAME$U$date_stamp.unl" >> $VERBOSE_RESULTS_LOG
	fi
	
}

#####################################
# Output standard results to a log file 
function log_results () {
	
	if test "$LOGFILE" = ""; then
		LOGFILE=$CURR_DIR/build.log
	fi
	
	echo "" >> $LOGFILE
	echo "Skipped: $SKIP_CNT Run: $RUN_CNT Failed: $FAIL_CNT ${T_MD}Success: $RESULT %${T_ME}" >> $LOGFILE
	echo "Passed: (All/NoErrChk/CompOnly) $PASS_CNT/$NO_RUNTIME_ERR_CHECK_CNT/$COMPILE_ONLY_PASS_CNT" >> $LOGFILE
	if test "$KILL_CNT" != "0"; then 
		echo "Had to kill $KILL_CNT tests: $KILL_LIST" >> $LOGFILE
	fi
	if test "$EXPECTED_TO_FAIL_CNT" != "0"; then 
		echo "Expected to fail: $EXPECTED_TO_FAIL_LIST ($EXPECTED_TO_FAIL_CNT)"  >> $LOGFILE
	fi
	if test "$NOT_EXPECTED_TO_FAIL_CNT" != "0"; then 
		echo "NOT expected to fail: $NOT_EXPECTED_TO_FAIL_LIST ($NOT_EXPECTED_TO_FAIL_CNT)" >> $LOGFILE
	fi
	if test "$NOT_CERT_CNT" != "0"; then
		#if not -cert 1
		#	WHITELIST_TESTS_ECP
		#fi
		
		#No point in showing what pased and is not certified, unless we are 
		#testing under -cert conditions
		if test "$USE_ECI" = "1"; then
			echo "NOT certified: $NOT_CERT_LIST ($NOT_CERT_CNT)" >> $LOGFILE
		fi
	fi
	if test "$SKIP_NODESC_LIST" != ""; then 
		echo "Skipped as not descsribed: $SKIP_NODESC_LIST" >> $LOGFILE
	fi
	if test "$EXPECTED_TO_FAIL_PASSED_CNT" != "0"; then 
		echo "Expected to fail, but passed: $EXPECTED_TO_FAIL_PASSED_CNT ($EXPECTED_TO_FAIL_PASSED_LIST)" >> $LOGFILE
	fi
	
	if test "$SKIP_KEYS_IN_LIST" != ""; then
		echo "Skipped as use keys.in: $SKIP_KEYS_IN_LIST" >> $LOGFILE
	fi
	if test "$SKIP_OLD_MAKEFILE_LIST" != ""; then 
		echo "Skipped - has old makefile: $SKIP_OLD_MAKEFILE_LIST" >> $LOGFILE
	fi
	if test "$SKIP_DUMP_SCREEN" != ""; then 
		echo "Skipped dump_screen tests: $SKIP_DUMP_SCREEN" >> $LOGFILE
	fi
	
	#Prepare list of all tests we skipped, but will not list individually by default:
	SKIP_OTHER_LIST="\
	$SKIP_PCODE_LIST $SKIP_TUI_LIST $SKIP_LONG_LIST $SKIP_CONSOLE_LIST \
	$SKIP_NONDB_LIST $SKIP_DB_LIST $SKIP_NOSILENT_LIST $SKIP_NOVERSION_LIST\
	$SKIP_GRAPHIC_LIST $SKIP_NOMAKEFILE_LIST $SKIP_NOCOMPAT_LIST $SKIP_NO_CRON_LIST \
	$SKIP_TRANS_LIST $SKIP_NO_SCRDUMP_PDCURSES_LIST $SKIP_BLACKLIST_LIST \
	$SKIP_DUMP_SCREEN_NOT_XTERM_LIST $SKIP_INCOMPAT_SQL_LIST $SKIP_NON_ANSI_LIST"
	#clipp it:
	SKIP_OTHER_LIST=`echo $SKIP_OTHER_LIST`
	

	if test "$IS_DB_NO_SQL_FEATURES_DESC" != ""; then
		#This is bad; DB tests should have SQL/db features used described
		echo "ERROR: DB tests but have no features description : $IS_DB_NO_SQL_FEATURES_DESC" >> $LOGFILE
	fi
	if test "$NOT_ANSI_NO_SQL_FEATURES_DESC" != ""; then 
		#This is bad; DB tests should have SQL/db features used described	
		echo "ERROR: Not ANSI compatible but have no features description : $NOT_ANSI_NO_SQL_FEATURES_DESC" >> $LOGFILE
	fi
	if test "$PASS_INCOMPAT_SQL" != ""; then
		#This is certanly wrong; need to change feature status; test cannot\
		#possibly pass if feature is incompatible
		echo "" >> $LOGFILE
		echo "ERROR: Passed, but SQL features used are listed as incompatible:" >> $LOGFILE
		echo "$PASS_INCOMPAT_SQL" >> $LOGFILE
		echo "" >> $LOGFILE
	fi
	if test "$VERBOSE_RESULTS" = "1"; then
		echo ""	 >> $LOGFILE
		cat "$VERBOSE_RESULTS_LOG"  >> $LOGFILE
		echo ""	 >> $LOGFILE
	else
		#if test "$SKIP_OTHER_LIST" != "" ; then 
		#	echo "Other skipped tests: $SKIP_OTHER_LIST" >> $LOGFILE
		#fi
		echo ""	 >> $LOGFILE
		if test "$VERBOSE_RESULTS_LOG" != ""; then
			verbose "See `basename $VERBOSE_RESULTS_LOG` for details of skipped tests" >> $LOGFILE
		else
			warning "VERBOSE_RESULTS_LOG is null"
		fi
	fi 
	if test "$SQLFEATURES_LOGFILE" != ""; then
		verbose "See `basename $SQLFEATURES_LOGFILE` for detailed SQL features analisys" >> $LOGFILE
	else
		warning "SQLFEATURES_LOGFILE is null"
	fi
	echo ""	 >> $LOGFILE
		
	if test "$NOT_COMPAT_BUT_PASSED" != ""; then 
		#test is not described as compatible, but even using non-aubit compiler 
		#it passed, so it should be described as compatible
		echo "TODO-add non-Aubit compilers compatible descriptor to: $NOT_COMPAT_BUT_PASSED" >> $LOGFILE
	fi
	if test "$PASS_LIST" != "" -a "$SHOW_PASSED" = "1"; then 
		echo "Passed: $PASS_LIST" >> $LOGFILE
	fi
	if test "$FAIL_CNT" = "$EXPECTED_TO_FAIL_CNT" -o "$FAIL_CNT" -lt "$EXPECTED_TO_FAIL_CNT" ; then
		echo "RESULT: EXPECTED" >> $LOGFILE
		RESULT=0
	else
		#"$FAIL_CNT" is more then "$EXPECTED_TO_FAIL_CNT"
		echo "*********** RESULT: UNEXPECTED ******************" >> $LOGFILE
		RESULT=1
	fi
	if test "$VERBOSE" = "1"; then 
		echo "" >> $LOGFILE
		if test "$RESLOGFILE" != ""; then
			echo "see `basename $RESLOGFILE` and $TIME_FILE" >> $LOGFILE
		else
			echo "RESLOGFILE is null"
		fi
	fi
	
	if test "$FEATURE_NOT_EXPECTED" != ""; then
		#This is an error - correct the feature description in makefile or
		#in array of feature descriptions
		echo "" >> $LOGFILE
		echo "ERROR: SQL features used not expected by compatiblity check:" >> $LOGFILE
		echo "$FEATURE_NOT_EXPECTED" >> $LOGFILE
		echo "" >> $LOGFILE
	fi
	if test "$VERBOSE" = "1"; then
		echo "" >> $LOGFILE
		echo "Finished at:" >> $LOGFILE
		#we want exact time here - do not use $DATE
		date >> $LOGFILE
		echo "" >> $LOGFILE
	fi
	
}

######################################
# Log results related to SQL/DB features used
function log_sqlfeatures () {
	SQLFEATURES_LOGFILE="$CURR_DIR/sql_features.log"
	rm -f $SQLFEATURES_LOGFILE

	#Eliminate working features from failed features list, test that contains
	#them must have failed for some other reason, since feature is also
	#present in test(s) that passed
	if test "$SQL_FEATURES_PASS_LIST" != ""; then
		#If pass list is not empty...
		for failed_feature in $SQL_FEATURES_FAIL_LIST; do
			#...for every featre found in failed tests...
			HAS_MATCH=0
			for working_feature in $SQL_FEATURES_PASS_LIST; do	
			#...look for that feature in pass list...
				if test "$working_feature" = "$failed_feature"; then
					#Found feature from failed test in passed test, so ignore it
					#echo "feature $working_feature appears on both PASS nad FAIL lists"
					HAS_MATCH=1
					break
				fi
			done
			if test "$HAS_MATCH" = "0"; then 
				#Not found, store it in filteres list
				FILTERED_SQL_FEATURES_FAIL_LIST="$FILTERED_SQL_FEATURES_FAIL_LIST $failed_feature"
			else
				#found, store it in filtered-out list
				ELIMINATED_SQL_FEATURES_FAIL_LIST="$ELIMINATED_SQL_FEATURES_FAIL_LIST $failed_feature"
			fi
		done
	else
		#no pass list - nothing to filter out
		FILTERED_SQL_FEATURES_FAIL_LIST="$SQL_FEATURES_FAIL_LIST"
	fi
	 
		debug " "	
		debug "SQL_FEATURES_PASS_LIST=$SQL_FEATURES_PASS_LIST"
		debug " "
		debug "SQL_FEATURES_FAIL_LIST=$SQL_FEATURES_FAIL_LIST"
		debug "---------------------------------------------------------"
		debug "ELIMINATED_SQL_FEATURES_FAIL_LIST=$ELIMINATED_SQL_FEATURES_FAIL_LIST"
		debug " "
		debug "FILTERED_SQL_FEATURES_FAIL_LIST=$FILTERED_SQL_FEATURES_FAIL_LIST"
		echo " "
	
	
	if test "$FAIL_COMPAT_SQL" != ""; then
		#This is not nececeraly an error - test can fail for some other reason,
		#even when sql/db features are compatible
		echo "" >> $SQLFEATURES_LOGFILE
		echo "WARNING: Failed, but SQL features used are listed as compatible:" >> $SQLFEATURES_LOGFILE
		echo "$FAIL_COMPAT_SQL" >> $SQLFEATURES_LOGFILE
		echo "" >> $SQLFEATURES_LOGFILE
	fi	
	if test "$LIST_IN_4G_NOT_IN_MK" != ""; then
		echo "WARNING: features listed by 4glc but not in Makefile:" >> $SQLFEATURES_LOGFILE
		echo "$LIST_IN_4G_NOT_IN_MK" >> $SQLFEATURES_LOGFILE
		echo "" >> $SQLFEATURES_LOGFILE		
	fi
	if test "$LIST_IN_MK_NOT_IN_4GLC" != ""; then
		echo "WARNING: features listed in Makefile but not by 4glc:" >> $SQLFEATURES_LOGFILE
		echo "$LIST_IN_MK_NOT_IN_4GLC" >> $SQLFEATURES_LOGFILE
		echo "" >> $SQLFEATURES_LOGFILE		
	fi
	
	if test "$SQL_FEATURES_PASS_LIST" != ""; then
		#This is 100% correct
		echo "" >> $SQLFEATURES_LOGFILE
		echo "All working DB features:"  >> $SQLFEATURES_LOGFILE
		echo "$SQL_FEATURES_PASS_LIST"  >> $SQLFEATURES_LOGFILE		
		echo "" >> $SQLFEATURES_LOGFILE
	fi
	if test "$FILTERED_SQL_FEATURES_FAIL_LIST" != ""; then
		#This is potentially not 100% correct, since we can have here listed
		#an feature that did not fail, but the test in which it appeared did 
		#for some other reason, and the same feature did not appear in any
		#of the tests that passed, so we could not eliminate it from fail list
		echo "" >> $SQLFEATURES_LOGFILE
		echo "DB features used in failed tests (and possibly/probably not working):" >> $SQLFEATURES_LOGFILE
		echo "$FILTERED_SQL_FEATURES_FAIL_LIST" >> $SQLFEATURES_LOGFILE		
		echo "" >> $SQLFEATURES_LOGFILE		
	fi
	
}

##############
#get info about the test from makefile
function load_info_from_makefile () {
	
		IS_DB_TEST=`$MAKE -s -C $TEST_NO db_test 2>/dev/null`
		if test "$IS_DB_TEST" = "1"; then
			#We are intereste in this features only if test is a db test,
			SE_REQUIRED=`$MAKE -s -C $TEST_NO se_required 2>/dev/null`
			NEED_IFX_VERSION=`$MAKE -s -C $TEST_NO need_ifx_version 2>/dev/null`
			NEED_RDBMS=`$MAKE -s -C $TEST_NO need_rdbms 2>/dev/null`
		else
			SE_REQUIRED=
			NEED_IFX_VERSION=
		fi
		ec_test=`$MAKE -s -C $TEST_NO ec_test 2>/dev/null`
		IS_NOSILENT_TEST=`$MAKE -s -C $TEST_NO nosilent_test 2>/dev/null`
		IS_TUI_TEST=`$MAKE -s -C $TEST_NO tui_test 2>/dev/null`
		IS_FORM_TEST=`$MAKE -s -C $TEST_NO form_test 2>/dev/null`
		IS_REPORT_TEST=`$MAKE -s -C $TEST_NO report_test 2>/dev/null`
		IS_GRAPHIC_TEST=`$MAKE -s -C $TEST_NO graphic_test 2>/dev/null`
		IS_CONSOLE_PROMPT_TEST=`$MAKE -s -C $TEST_NO console_prompt_test 2>/dev/null`
		IS_DUMP_SCREEN_TEST=`$MAKE -s -C $TEST_NO dump_screen_test 2>/dev/null`
		IS_LONG_TEST=`$MAKE -s -C $TEST_NO long_test 2>/dev/null`
		IS_CERT_TEST=`$MAKE -s -C $TEST_NO cert_test 2>/dev/null`
		IS_OBSOLETE_TEST=`$MAKE -s -C $TEST_NO obsolete_test 2>/dev/null`
		compat_test=`$MAKE -s -C $TEST_NO compat_test 2>/dev/null`
		IS_UNKNOWN_TEST=`$MAKE -s -C $TEST_NO unknown_test 2>/dev/null`
		EXPECT_CODE=`$MAKE -s -C $TEST_NO expect_code 2>/dev/null`
		RUNTIME_ERR_CHECK=`$MAKE -s -C $TEST_NO runtime_err_check 2>/dev/null`
		if test "$EXPECT_CODE" = "" ; then
			EXPECT_CODE=0
		fi
		COMPILE_ONLY=`$MAKE -s -C $TEST_NO compile_only 2>/dev/null`
		NOPREFIX=`$MAKE -s -C $TEST_NO noprefix 2>/dev/null`
		if test "$NOPREFIX" = "1" ; then
			export A4GL_NAMESPACE=" "
		else
			unset A4GL_NAMESPACE
		fi

		NEED_COMPAT=`$MAKE -s -C $TEST_NO need_compat 2>/dev/null`

		if test "$NEED_COMPAT" = "1" ; then
			#test needs Aubit Informix compatibility support and headers
			export A4GL_COMPAT_MODE="Y"
			export CFLAGS="-I$AUBITDIR/incl -I$AUBITDIR/incl/compat "
		else
			unset A4GL_COMPAT_MODE
		fi
}

######################################
#get info from this scripts variables (set in incl/legacy_descriptions_inc.sh) 
#when test has old-style makefile
function load_info_from_strings () {
			
			#Do not have equivalent in script descriptions:
			#ec_test - DOES! EC_TESTS but it's not used 
			#compat_test

			for b in $REPORT_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_REPORT_TEST=1
				fi
			done

			for b in $UNKNOWN_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_UNKNOWN_TEST=1
				fi
			done
			for b in $DB_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_DB_TEST=1
				fi
			done
			
			for b in $NOSILENT_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_NOSILENT_TEST=1
				fi
			done
			
			for b in $TUI_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_TUI_TEST=1
				fi
			done
			
			for b in $GRAPHIC_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_GRAPHIC_TEST=1
				fi
			done
			
			for b in $ALL_DESCRIBED_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_DESCRIBED=1
				fi
			done
			for b in $CONSOLE_PROMPT_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_CONSOLE_PROMPT_TEST=1
				fi
			done
			for b in $DUMP_SCREEN_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_DUMP_SCREEN_TEST=1
				fi
			done
			for b in $FORM_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_FORM_TEST=1
				fi
			done
			for b in $LONG_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_LONG_TEST=1
				fi
			done
			for b in $CERT_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_CERT_TEST=1
				fi
			done
			for b in $OBSOLETE_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_OBSOLETE_TEST=1
				fi
			done
			for b in $PCODE_ENABLED; do
				if test "$b" = "$TEST_NO"; then
					IS_PCODE_ENABLED=1
				fi
			done
			for b in $NO_CRON_TESTS; do
				if test "$b" = "$TEST_NO"; then
					IS_NO_CRON_TEST=1
				fi
			done
}

###################
#Load info that is allways in makefile, and only in makefile
function load_info_makefile_only () {

	#Both old and new makefiles may contain this targets, but they are 
	#relevant only for db tests
	if test "$IS_DB_TEST" = "1"; then 
		IS_MAKE_ANSI_SQL_COMPAT=`$MAKE -s -C $TEST_NO ansi_sql_compat 2>/dev/null`
		NEED_TRANSACTION=`$MAKE -s -C $TEST_NO transaction 2>/dev/null`
		SQL_FEATURES_USED=`$MAKE -s -C $TEST_NO sql_features_used 2>/dev/null`

		if test "$IS_MAKE_ANSI_SQL_COMPAT" = "0" -a "$SQL_FEATURES_USED" = ""; then 
			#echo "WARNING: #$TEST_NO is not compatible with ANSI SQL, but has no SQL features used description"
			NOT_ANSI_NO_SQL_FEATURES_DESC="$NOT_ANSI_NO_SQL_FEATURES_DESC $TEST_NO"
		else
			if test "$SQL_FEATURES_USED" = ""; then
				#echo "WARNING: #$TEST_NO is db test, but has no SQL features used description"			
				IS_DB_NO_SQL_FEATURES_DESC="$IS_DB_NO_SQL_FEATURES_DESC $TEST_NO"
			fi
		fi
	else
		IS_MAKE_ANSI_SQL_COMPAT=""
		NEED_TRANSACTION=""
		SQL_FEATURES_USED=""
	fi
	
	#This targets can be present in both old and new makefiles:
	NEED_PLUGIN=`$MAKE -s -C $TEST_NO need_plugin 2>/dev/null`
	
}

###################
#Load info that is allways in script strings, and never in makefile
function load_info_script_only () {

	debug "Entering load_info_script_only"
	
		#################
		#Proces test information that is allways held only in this script, 
		#and NEVER in makefiles	
		for b in $EXPECT_TO_FAIL_TESTS; do
			if test "$b" = "$TEST_NO"; then
				IS_EXPECT_TO_FAIL_TEST=1
			fi
		done
		for b in $INVALID_TESTS; do
			if test "$b" = "$TEST_NO"; then
				IS_INVALID_TEST=1
			fi
		done
		for b in $BLACKLIST_TESTS; do
			if test "$b" = "$TEST_NO"; then
				IS_BLACKLIST_TEST=1
			fi
		done

	debug "Exiting load_info_script_only"
}

#################################
#Initialise counters and variables INSIDE testing loop, before running each test
function init_vars_in_loop () {
	
	desc_txt=""
	let COUNTER=COUNTER+1
	IS_DB_TEST=0
	ec_test=0
	IS_NOSILENT_TEST=0
    IS_TUI_TEST=0
    IS_GRAPHIC_TEST=0
    IS_DESCRIBED=0
	IS_CONSOLE_PROMPT_TEST=0
	IS_DUMP_SCREEN_TEST=0
	IS_FORM_TEST=0
	IS_BLACKLIST_TEST=0
    IS_LONG_TEST=0
	IS_MAKE_ANSI_SQL_COMPAT=""
    IS_CERT_TEST=0
    IS_OBSOLETE_TEST=0
    IS_INVALID_TEST=0
    IS_PCODE_ENABLED=0
	IS_UNKNOWN_TEST=0
	IS_NO_CRON_TEST=0	
	TEMPLATE_COMMENT=0
	NEED_TRANSACTION=0
	IS_REPORT_TEST=0
	EXPECT_CODE=0
	COMPILE_ONLY=0
	IS_EXPECT_TO_FAIL_TEST=0
	compat_test=0
	NEED_IFX_VERSION=""
	SE_REQUIRED=0
	SKIP_REASON=""
	SKIP_REASON_CODES=""
	IS_MAKE_ANSI_SQL_COMPAT=""
	NEED_TRANSACTION=""
	NEED_RDBMS=""
	SQL_FEATURES_USED=""
	SQL_FEATURES_COMPATIBLE=""
	NEED_PLUGIN=""
}

#################################
#Initialise counters and variables BEFORE entering testing loop
function init_vars_before_loop () {
	COUNTER=0
	FAIL_CNT=0
	PASS_CNT=0
	SKIP_CNT=0
	SKIP_INVALID_CNT=0
	SKIP_NON_ANSI_CNT=0
	RUN_CNT=0
	EXPECTED_TO_FAIL_CNT=0
	NOT_EXPECTED_TO_FAIL_CNT=0
	NOT_CERT_CNT=0
	TEMPLATE_COMMENT_CNT=0
	UNKNOWN_TEST_CNT=0			
	MIGRATE_DESC_CNT=0			
	HAS_DESC_TXT_CNT=0
	IS_REPORT_TEST_CNT=0
	NON_ZERO_EXIT_CNT=0
	COMPILE_ONLY_CNT=0
	IS_PCODE_ENABLED_CNT=0
	NOT_DESCRIBED_CNT=0
	IS_INVALID_CNT=0
	EXPECT_FAIL_CNT=0
	IS_DB_TEST_CNT=0
	IS_EC_TEST_CNT=0
	IS_NOSILENT_CNT=0
	IS_TUI_TEST_CNT=0
	IS_FORM_TEST_CNT=0
	IS_GRAPHIC_TEST_CNT=0
	IS_CONSOLE_PROMPT_CNT=0
	IS_DUMP_SCREEN_CNT=0
	IS_LONG_CNT=0
	NO_RUNTIME_ERR_CHECK_CNT=0
	COMPILE_ONLY_PASS_CNT=0
	IS_CERT_CNT=0
	IS_NO_CRON_CNT=0
	IS_OBSOLETE_CNT=0
	IS_COMPAT_CNT=0
	IS_UNKNOWN_CNT=0
	EXPECTED_TO_FAIL_PASSED_CNT=0
	IS_SE_REQUIRED_CNT=0
	FAIL_DB_CNT=0
	FAIL_NONDB_CNT=0
	PASS_DB_CNT=0
	PASS_NONDB_CNT=0
	KILL_CNT=0
	SKIP_INCOMPAT_SQL_CNT=0
}


######################
#define which tests are expected to fail based on database/Aubit options used
function define_expect_fail_list () {
	if test "$USE_COMP" = "aubit"; then 
		#Must be after flags processing to prevent cummulation when overriding switches
		case $DB_TYPE in
			#IFX-SE)
			IFX-OL)
				if test "$USE_ESQLI" = "1" -a "$USE_ECI" = "0"; then
					EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS $EXPECT_TO_FAIL_TESTS_ESQLI"
				fi
				if test "$USE_IFXODBC" = "1"; then		
					EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS $EXPECT_TO_FAIL_TESTS_IFXODBC"
				fi
				#EXPECT_TO_FAIL_TESTS are actually EXPECT_TO_FAIL_TESTS_ECI, since 
				#-eci is part of -cert
				;;
			PG-IFX-74)
				if test "$USE_ECP" = "1"; then
					filter_out_white_listed "$EXPECT_TO_FAIL_TESTS_ECP" "$WHITELIST_TESTS_ECP"
				#else
					#must be ODBC? (did that in ODBC section?)
				fi
				;;
			#PG-74)
			#PG-80)
			#*)	#Any other database back-end
		esac
	fi
	
	debug "Exiting define_expect_fail_list"
}



#######################
#Initialise results log files before entering test loop
function init_result_logs () {
	echo "" > $LOGFILE
	echo "============================== Test results ===============================" >> $LOGFILE
	echo "" >> $LOGFILE
	echo "Flags (expanded): $FLAGS" >> $LOGFILE
	
	if test "$ALL_DB" = "1"; then
		#remove irelevant flags, keep -sqlite -nospace -defaults -esqli
		#also remove ONE -sqlite, since it's a default added by -default switch
		#so we don't confuse the user:
		DISP_FLAGS=`echo $FLAGS | sed -e 's/-short//' -e 's/-silent//' -e 's/-alldbrun//' -e 's/-sqlite//' -e 's/-defaults//' -e 's/-cert//' -e 's/-described//' -e 's/-nospace//' -e 's/-noecho//'`
		echo "Flags: $DISP_FLAGS" >> $CURR_DIR/alldb.log
	fi
	if test "$VERBOSE" = "1"; then 
		echo "" >> $LOGFILE
		echo "Started at" >> $LOGFILE
		#we want exact time here - do not use $DATE
		date >> $LOGFILE
		echo "Aubit version/build:" >> $LOGFILE	
		aubit $FGLC -v | grep Version >> $LOGFILE
		aubit $FGLC -v | grep Build >> $LOGFILE
		debug "Finished collecting compiler version info"
		#TODO: show versions of 4Js/Informix/Querix compiler - if used
	fi
	
	if test "$RUN_ONE" != ""; then
		#echo "" >> $LOGFILE
		echo "Running test: $RUN_ONE" >> $LOGFILE
		ALL_TESTS=$RUN_ONE
		#echo "" >> $LOGFILE
	#else
	#	if test "$NO_ECHO" != "1"; then
	#		#echo "Running tests: $ALL_TESTS" >> $LOGFILE
	#		#To get $ALL_TESTS expanded on Windows, must not have quotes:
	#		echo "Running tests: $ALL_TESTS" >> $LOGFILE
	#   fi
	fi
	
	rm -f $CURR_DIR/$TIME_FILE
	rm -f $CURR_DIR/$OUTPUT_LOG
	rm -f $CURR_DIR/$ERROR_LOG
}

##########################
#
function show_config_in_loop () {
		echo "A4GL_INIFILE=$A4GL_INIFILE"
		$AUBITDIR_UNIX/bin/aubit-config$EXE_EXT -a
		
		echo "aubit-config A4GL_AUBITRC returns :`aubit-config A4GL_AUBITRC`"
		echo "aubit-config DBMONEY returns      :`aubit-config DBMONEY`"
		echo "in environment: DBMONEY=$DBMONEY"
		
		unset A4GL_INIFILE
		echo "A4GL_INIFILE=$A4GL_INIFILE"
		
		echo "aubit-config A4GL_AUBITRC returns :`aubit-config A4GL_AUBITRC`"
		echo "aubit-config DBMONEY returns      :`aubit-config DBMONEY`"
		echo "in environment: DBMONEY=$DBMONEYc"
		
		echo "A4GL_LEXTYPE:`aubit-config A4GL_LEXTYPE`"
		echo "A4GL_LEXDIALECT:`aubit-config A4GL_LEXDIALECT`"
		echo "A4GL_SQLTYPE:`aubit-config A4GL_SQLTYPE`"
		
		echo "A4GL_TARGETDIALECT:`aubit-config A4GL_TARGETDIALECT`"
		echo "A4GL_ESQL_UNLOAD:`aubit-config A4GL_ESQL_UNLOAD`"
		
		note "Above config is at point of makefile incovation in run_tests"
		note "and NOT in test makefile itself"
}

##################################
#Colect information about this test
function collect_test_info () {
#DBG_collect_test_info=1
#DISABLE_CAT_INFO=1
load_in_one_go=1
CAT_FILE="docs/catalogue.unl"
 
	debug "Loading test info..."
	
	if test "$DISABLE_CAT_INFO" != "1"; then
		if test "$CATALOGUE_UNL" != "1" -a "$INFO_TEST" != "1"; then
			#Cant get info from catalogue when Im creating new catalogue
			TRY_CAT=1
		fi
	fi
	
	if test "$TRY_CAT" = "1"; then
		THIS_MAKEFILE=`ls $CURR_DIR/$TEST_NO/?akefile`
		if test "$THIS_MAKEFILE" = ""; then
			warning "Cant get makefile name"
			TRY_CAT=0
		else
			if test "$CAT_FILE" -ot "$THIS_MAKEFILE"; then
				#True if file1 is older than file2.
				#Makefile was changed AFTER the catalogue was created, therefore
				#if we use catalogue, we may be getting out-of-date info
				warning "Makefile for test $TEST_NO changed since catalogue.unl was"
				warning "created. Disabled loading of test info from catalogue."
				TRY_CAT=0
			fi
		fi
	fi
	if test "$TRY_CAT" = "1"; then
		debug "Loading from catalogue..."
		load_info_from_catalogue
	fi
	
	if test "$GOT_INFO_FROM_CAT" != "1"; then
		if test "$TRY_CAT" = "1"; then	
			warning "Failed to get test info from catalogue, reading makefile and/or strings"
		fi
	
		#Check if makefile is old or new type; sets IS_OLD_MAKEFILE
		check_makefile_type
		
		if test "$IS_OLD_MAKEFILE" = "0" ; then
			if test "$load_in_one_go" = "1"; then 
				load_info_in_one_go
				if test "$DBG_collect_test_info" = "1"; then
					note "Got info from makefile (one go)"
				fi
			else
				load_info_from_makefile
				if test "$DBG_collect_test_info" = "1"; then
					note "Got info from makefile (one-by-one)"
				fi
			fi
			
		else #old makefile - no descriptions in makefile
			load_info_from_strings
			if test "$DBG_collect_test_info" = "1"; then
				note "Got info from strings (old makefile)"
			fi
		fi

		#see if Makefile contains description
		#sets desc_txt TEMPLATE_COMMENT IS_DESCRIBED ALL_DESCRIBED_TESTS
		check_desc_txt
		
		#can we skip this one when loading in one go?
		load_info_makefile_only
		

	else
		debug "Got info from catalogue"
		if test "$DBG_collect_test_info" = "1"; then
			note "Got info from catalogue"
		fi
	fi
	
	#This one has to be called even when loading in one go:
	load_info_script_only	
	
 	debug "Finished loading test info..."

	if test "$DBG_collect_test_info" = "1"; then
		show_test_info_vars
		exit
	fi

}

#################################
#Load test info from makefile using single make target instead of readin
#one-by-one setting, to save time. If any setting is missing, add it to 
#the makefile (one-by-one:6-7 sec one-go:3-4 sec, from catalogue:1 sec )
function load_info_in_one_go () {
#DBG_load_info_in_one_go=1
NEED_COLS=43

#$MAKE -C $TEST_NO all_desc
#$MAKE -C $TEST_NO obsolete_test
#exit
	ALL_DESC=`$MAKE -k -s -C $TEST_NO all_desc 2>/tmp/make.tmp | tr "\n" "|"`
	MISSING_TARGETS=`cat /tmp/make.tmp | grep "No rule to make target" | cut --field=8 --delimiter=" " | sed -e 's/\`//' | cut --field=1 --delimiter="'" | tr "\n" " "`
	
	if test "$MISSING_TARGETS" != ""; then
		for missing_target in $MISSING_TARGETS; do
			note "Adding missing setting $missing_target for test $TEST_NO ..."
			change_setting "$missing_target" "" "$TEST_NO"
		done
		#re-check
		ALL_DESC=`$MAKE -k -s -C $TEST_NO all_desc 2>/tmp/make.tmp | tr "\n" "|"`
		MISSING_TARGETS=`cat /tmp/make.tmp | grep "No rule to make target" | cut --field=8 --delimiter=" " | sed -e 's/\`//' | cut --field=1 --delimiter="'" | tr "\n" " "`
		if test "$MISSING_TARGETS" != ""; then
			error "Still missing targets:$MISSING_TARGETS" "3"
		fi
	fi
	
	#Check number of fields: (Note: LF is a char)
	delim_cnt=`echo $ALL_DESC | sed -e "s/[a-zA-Z0-9 _!~@#$%^&(()+*-=<,>.?{}\']//g" -e 's/\[//g' -e 's/\]//g' -e 's/\"//g' | wc -m`
	delim_cnt=`echo $delim_cnt`

	if test "$DBG_load_info_in_one_go" = "1" -o "$delim_cnt" != "$NEED_COLS"; then
		stripped=`echo $ALL_DESC | sed -e "s/[a-zA-Z0-9 _!~@#$%^&(()+*-=<,>.?{}\']//g" -e 's/\[//g' -e 's/\]//g' -e 's/\"//g'`
		echo ">$ALL_DESC<"
		echo ">$stripped<"
		echo "Expecting $NEED_COLS, got $delim_cnt"
		#if test "$delim_cnt" = "$NEED_COLS" ; then
		#	exit
		#fi
	fi
	if test "$delim_cnt" != "$NEED_COLS" ; then
		error "Loading descriptions from makefile in one go returned $delim_cnt"
		error "fields instead of expected $NEED_COLS for test $TEST_NO" "1"
	fi
	info_line_to_var "$ALL_DESC"
	
	if test "$DBG_load_info_in_one_go" = "1"; then
		echo "$ALL_DESC"
		echo "-----------------------------------------------------------------------"
		show_test_info_vars
		exit
	fi
	
}

###############################
#Load all test info from catalogue .unl file
function load_info_from_catalogue () {
CAT_FILE="docs/catalogue.unl"
GOT_INFO_FROM_CAT=0
#DBG_load_info_from_catalogue=1

	if test "$CATALOGUE_TIMESTAMP" = ""; then 
		CATALOGUE_TIMESTAMP=`head -n 1 $CAT_FILE | cut --field=1 --delimiter="|"`
	fi
	
	line=`grep "$CATALOGUE_TIMESTAMP|$TEST_NO|" docs/catalogue.unl`
	if test "$line" = ""; then
		verbose "Test not in $CAT_FILE"
		return
	fi
	info_line_to_var "$line"
	if test "$DBG_load_info_from_catalogue" = "1"; then 
		show_test_info_vars
		exit
	fi
	GOT_INFO_FROM_CAT=1
}

###################################
#break delimited test info line into variables
function info_line_to_var () {
line="$1"

	this_cnt=0
	while test "$this_cnt" -lt "43" ; do
		let this_cnt=this_cnt+1
		#while test did not work:
		if test "$this_cnt" = "43"; then
			break
		fi
		
		field=`echo $line | cut --field=$this_cnt --delimiter="|"`
		#echo "$this_cnt = |$field|"

		case $this_cnt in
			1) ;;
			2) ;;
			3)  #$invalid
				IS_INVALID_TEST="$field";;
			4)  #$is_db
				IS_DB_TEST="$field";;
			5)  #$is_ec
				ec_test="$field";;
			6)  #$is_nosilent
				IS_NOSILENT_TEST="$field";;
			7)  #$is_tui
				IS_TUI_TEST="$field";;
			8)  #$is_form
				IS_FORM_TEST="$field";;
			9)  #$is_report
				IS_REPORT_TEST="$field";;
			10) #$is_graphics
				IS_GRAPHIC_TEST="$field";;
			11) #$is_prompt
				IS_CONSOLE_PROMPT_TEST="$field";;
			12) #$is_dump_screen
				IS_DUMP_SCREEN_TEST="$field";;
			13) #$is_long
				IS_LONG_TEST="$field";;
			14) #$is_unknown
				IS_UNKNOWN_TEST="$field";;
			15) #$is_cert
				IS_CERT_TEST="$field";;
			16) #$is_obsolete
				IS_OBSOLETE_TEST="$field";;
			17) #$is_described
				IS_DESCRIBED="$field";;
			18) #$test_desc_txt
				desc_txt="$field";;
			19) #$test_compat_test
				compat_test="$field";;
			20) #$expect_code
				EXPECT_CODE="$field";;
			21) #$se_required
				SE_REQUIRED="$field";;
			22) #$compile_only
				COMPILE_ONLY="$field";;
			23) #$need_ifx_ver
				NEED_IFX_VERSION="$field";;
			24) #$need_trans
				NEED_TRANSACTION="$field";;
			25) #$no_prefix
				NOPREFIX="$field";;
			26) #$need_compat
				NEED_COMPAT="$field";;
			27) #$old_makefile
				IS_OLD_MAKEFILE="$field";;
			28) ;; #$dl$is_pcode_enabled$dl"	NO var
			29) ;; #$dl$is_no_cron$dl"			NO var
			30) ;; #$dl$scripted$dl"			NO var
			31) ;; #$dl$is_window$dl"			NO var
			32) ;; #$dl$test_ver$dl"			NO var
			33) ;; #$dl$run_tests_ver$dl"		NO var
			34) ;; #$dl$last_update$dl"			NO var
			35) ;; #$dl$expect_fail_cert$dl" 	NO var
			36) ;; #$dl$expect_fail_esqli$dl" 	NO var
			37) ;; #$dl$expect_fail_ecp$dl" 	NO var
			38) ;; #$dl$expect_fail_ifx_p$dl"	NO var
			39) ;; #$dl$expect_fail_4js$dl" 	NO var
			40) ;; #$dl$expect_fail_querix$dl" 	NO var
			41) #$sql_features_used
				SQL_FEATURES_USED="$field";;
			42) #$ansi_sql
				IS_MAKE_ANSI_SQL_COMPAT="$field";;
			*) error "this_cnt=$this_cnt" "2"
		esac
	done
}

##############################
# Show state of all variables that can be stored in catalogui.unl file
function show_test_info_vars () {
	
	echo "IS_INVALID_TEST=$IS_INVALID_TEST"
	echo "IS_DB_TEST=$IS_DB_TEST"
	echo "ec_test=$ec_test"
	echo "IS_NOSILENT_TEST=$IS_NOSILENT_TEST"
	echo "IS_TUI_TEST=$IS_TUI_TEST"
	echo "IS_FORM_TEST=$IS_FORM_TEST"
	echo "IS_REPORT_TEST=$IS_REPORT_TEST"
	echo "IS_GRAPHIC_TEST=$IS_GRAPHIC_TEST"
	echo "IS_CONSOLE_PROMPT_TEST=$IS_CONSOLE_PROMPT_TEST"
	echo "IS_DUMP_SCREEN_TEST=$IS_DUMP_SCREEN_TEST"
	echo "IS_LONG_TEST=$IS_LONG_TEST"
	echo "IS_UNKNOWN_TEST=$IS_UNKNOWN_TEST"
	echo "IS_CERT_TEST=$IS_CERT_TEST"
	echo "IS_OBSOLETE_TEST=$IS_OBSOLETE_TEST"
	echo "IS_DESCRIBED=$IS_DESCRIBED"
	echo "desc_txt=$desc_txt"
	echo "compat_test=$compat_test"
	echo "EXPECT_CODE=$EXPECT_CODE"
	echo "SE_REQUIRED=$SE_REQUIRED"
	echo "COMPILE_ONLY=$COMPILE_ONLY"
	echo "NEED_IFX_VERSION=$NEED_IFX_VERSION"
	echo "NEED_TRANSACTION=$NEED_TRANSACTION"
	echo "NOPREFIX=$NOPREFIX"
	echo "NEED_COMPAT=$NEED_COMPAT"
	echo "IS_OLD_MAKEFILE=$IS_OLD_MAKEFILE"
	echo "SQL_FEATURES_USED=$SQL_FEATURES_USED"
	echo "IS_MAKE_ANSI_SQL_COMPAT=$IS_MAKE_ANSI_SQL_COMPAT"
	
}

function migrate_old_makefiles () {
#DBG_migrate_old_makefiles=1

	ALL_OLD=`cat docs/catalogue.unl | cut --fields=2,27 --delimiter="|" | tr "|" " "`
	#echo $ALL_OLD
	#exit
	cnt=0
	for field in $ALL_OLD; do
		let cnt=cnt+1
		if test "$cnt" = "1"; then
			test_no="$field"
		else
			old_make="$field"
			cnt=0
			if test "$old_make" = "1"; then
				#echo "Test $test_no has OLD makefile"
				OLD_LIST="$OLD_LIST $test_no"
			#else
			#	echo "Test $test_no has new makefile"
			fi
		fi
	done

	#echo "OLD_LIST=$OLD_LIST"
	
	for TEST_NO in $OLD_LIST; do
		#load test settings into variables
		load_info_from_catalogue
		if test "$GOT_INFO_FROM_CAT" != "1" ; then
			error "Failed to get test info"
		fi
		if test "$DBG_migrate_old_makefiles" = "1"; then 
			show_test_info_vars
			exit
		fi

		#create new makefile from template using current state of test
		#info in varibles
		make_new_makefile
		
	done
	
}

function make_new_makefile () {
CHG_SETTING_MAKEFILE="$TEST_NO/makefile-new"
	
	
	echo "Creating new makefile for test $TEST_NO"
	cp template/makefile $CHG_SETTING_MAKEFILE
	CVS_ADD_FILES="$CVS_ADD_FILES $CHG_SETTING_MAKEFILE" 
	
	change_setting db_test "$IS_DB_TEST" $TEST_NO
	change_setting desc "$desc_txt" $TEST_NO
	change_setting ec_test "$ec_test" $TEST_NO
	change_setting nosilent_test "$IS_NOSILENT_TEST" $TEST_NO
	change_setting tui_test "$IS_TUI_TEST" $TEST_NO
	change_setting form_test "$IS_FORM_TEST" $TEST_NO
	change_setting report_test "$IS_REPORT_TEST" $TEST_NO
	change_setting graphic_test "$IS_GRAPHIC_TEST" $TEST_NO
	change_setting console_prompt_test "$IS_CONSOLE_PROMPT_TEST" $TEST_NO
	change_setting dump_screen_test "$IS_DUMP_SCREEN_TEST" $TEST_NO
	change_setting long_test "$IS_LONG_TEST" $TEST_NO
	change_setting cert_test "$IS_CERT_TEST" $TEST_NO
	change_setting obsolete_test "$IS_OBSOLETE_TEST" $TEST_NO
	change_setting compat_test "$compat_test" $TEST_NO
	change_setting expect_code "$EXPECT_CODE" $TEST_NO
	change_setting compile_only "$COMPILE_ONLY" $TEST_NO
	change_setting unknown_test "$IS_UNKNOWN_TEST" $TEST_NO
	change_setting need_ifx_version "$NEED_IFX_VERSION" $TEST_NO
	change_setting transaction "$NEED_TRANSACTION" $TEST_NO
	change_setting sql_features_used "$SQL_FEATURES_USED" $TEST_NO
	change_setting ansi_sql_compat "$IS_MAKE_ANSI_SQL_COMPAT" $TEST_NO
#	change_setting runtime_err_check "$XXX" $TEST_NO
#	change_setting need_rdbms "$XXX" $TEST_NO
#	change_setting need_plugin "$XXX" $TEST_NO

#	echo "IS_DESCRIBED=$IS_DESCRIBED"
#	echo "SE_REQUIRED=$SE_REQUIRED"
#	echo "NOPREFIX=$NOPREFIX"
#	echo "NEED_COMPAT=$NEED_COMPAT"
#	echo "IS_OLD_MAKEFILE=$IS_OLD_MAKEFILE"

	
	echo "Adding to CVS: $CVS_ADD_FILES"
	exit

}

#Create PG database user (and database)
function check_pg_user_create () {
#need to create user first - FATAL:  user "root" does not exist
				USERNAME=`whoami`
				echo "Need to create user '$USERNAME' first..."
				#Note: there is also a PG command line utility 'createuser'
				SCRIPT=/tmp/pg-create-user.sql
				echo "create user $USERNAME WITH PASSWORD '$PGPASSWORD' createdb createuser ;" > $SCRIPT
			 	run_sql_script postgres template1 $SCRIPT /tmp/pg-create-user.log postgres
				#we need this for future tests
				#if test "$COMSPEC" != ""; then 
				#	echo "$PGUSER_POSTGRES_PWD" | $POSTGRES_BIN/createdb $USERNAME > /tmp/credb$USERNAME.log 2>&1
				#else
					$POSTGRES_BIN/createdb $USERNAME > /tmp/credb$USERNAME.log 2>&1
				#fi
				#
				#su postgres
				#$PSQL -d template1
				#template1=# create user root createdb createuser ;

				echo "Again: Creating PostgreSQL database $TEST_DB"
				#if test "$COMSPEC" != ""; then 
				#	echo "$PGUSER_POSTGRES_PWD" | $POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
				#else
					$POSTGRES_BIN/createdb $TEST_DB > /tmp/credbtmp.log 2>&1
				#fi
				RET=$?
				if test "$RET" != "0"; then
					echo "Failed again (code $RET)."
					cat /tmp/credbtmp.log
					exit 29
				else
					TMPAA=`cat /tmp/credbtmp.log | grep "CREATE DATABASE"`
					if test "$TMPAA" != ""; then
						echo "Database Created"
					else
						echo "Database creation failed. See /tmp/credbtmp.log"
						exit 8
					fi
				fi
}				
