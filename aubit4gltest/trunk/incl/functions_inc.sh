##############################################################################
#							Functions
##############################################################################


#Check for incompatible SQL dialect features (tests 234 256 etc...)
chech_sql_features () {


	#NOTE: All tests should at least compile, regardless of what 
	#SQL features are used in the code - so we will skip testing for SQL
	#features, otherwise it might appear that some tests that are compile-only
	#'work', but they 'work' because they are never executed, and if they where,
	#who knows what would happne
	if test "$DISABLE_SQL_FEATURES_CHECK" != "1" -a "$COMPILE_ONLY" != "1"; then
		if test "$SQL_FEATURES_USED" != ""; then 

		
		#List of non-ANSI compatible SQL or db features that is posible
		#to translate/emulate, but this is __NOT__ currently working
		#It is anticipated that support for them will be implemented in the 
		#near future
		SQL_FEATURES_NON_ANSI_POSIBLE="\
			ALTER_TABLE \
			ASC_INDEX \
			DESC_INDEX \
			CREATE_DATABASE \
			CREATE_DATABASE_WITH_LOG \
			CREATE_DATABASE_IN \
			CREATE_DATABASE_MODE_ANSI \
			CREATE_SYNONYM DDL_SYNONYM \
			CREATE_VIEW \
			DATABASE_EXCLUSIVE \
			DATETIME_EXTEND \
			DROP_INDEX \
			DROP_DATABASE \
			DROP_SYNONYM \
			DROP_TRIGGER \
			DDL_DEFAULT_VALUE \
			DDL_DEFAULT \
			DDL_PRIMARY_KEY \
			DDL_FOREIGN_KEY \
			DDL_MONEY_DATATYPE \
			DDL_MONEY \
			DDL_SERIAL \
			DDL_UNIQUE \
			DDL_DOUBLE_PRECISION \
			DDL_DATE \
			DDL_DATETIME \
			DDL_INTERVAL \
			DDL_NCHAR \
			DDL_NVARCHAR \
			DDL_TEXT \
			DDL_BYTE \
			FREE_CURSOR \
			FUNC_INTERVAL \
			FUNC_EXTEND \
			LOCK_TABLE \
			PUT_CURSOR \
			RENAME_COLUMN \
			RENAME_TABLE \
			ROWID \
			SELECT_RELATIVE FETCH_RELATIVE \
			SQL_FUNCTION_SUBSTR \
			SQL_SERIAL \
			SELECT_INTO_TEMP_WITH_NO_LOG \
			SELECT_FOR_UPDATE SELECT_FOR_UPDATE_CURSOR \
			TABLENAME_DB_SERVER_USER_TABLE \
			TABLENAME_DB_TABLE \
			TABLENAME_DB_USER_TABLE \
			UNLOCK_TABLE \
			UNLOAD_PATH_RELATIVE \
			UPDATE_WHERE_CURRENT_OF \
			UNLOAD_TO_SELECT_FROM \
			UNLOAD_TO_SELECT_FROM_WHERE \
			"
	
		#List of non-ANSI compatible SQL or db features that is posible
		#to translate/emulate, and is implemented in Aubit and fully working
		SQL_FEATURES_NON_ANSI_SUPORTED="\
			ANSI_INSERT \
			ANSI_DELETE \
			ANSI_SELECT \
			BEGIN_WORK ROLLBACK_WORK \
			CLOSE_DATABASE \
			CLOSE_CURSOR \
			CREATE_TABLE \
			CREATE_INDEX \
			CREATE_TEMP_TABLE \
			COMMIT_WORK \
			DROP_VIEW \
			CREATE_VIEW_SELECT \
			DROP_TABLE \
			EXECUTE_USING \
			EXECUTE_INTO_USING \
			GRANT \
			INSERT_COLUMNLIST_EQ_VALUELIST \
			INSERT_INTO_SELECT_FROM \
			REVOKE \
			SELECT_INTO_TEMP \
			SQL_END_SQL_BLOCK SQL_END_SQL\
			SQL_UNIQUE \
			SCROLL_CURSOR \
			SQLCA_SQLCODE \
			UPDATE_COLUMNLIST_EQ_VALUELIST \
			"
#SQL features used not expected by compatiblity check:
# 620=DELETE_WHERE_CURRENT_OF 621=DELETE_FROM_WHERE_WITH_SUBSELECT 622=DELETE_FROM_WHERE_EXISTS_SUBSELECT 623=DELETE_FROM_WHERE_ALL_SUBSELECT 623=DELETE_FROM_WHERE_ANY_SUBSELECT 623=DELETE_FROM_WHERE_SOME_SUBSELECT 624=DELETE_FROM_WHERE_NULL 625=DELETE_FROM_WHERE 626=LOAD_FROM_INSERT_INTO 627=LOAD_FROM_INSERT_INTO 628=LOAD_FROM_INSERT_INTO 629=LOAD_FROM_INSERT_INTO 630=LOAD_FROM_INSERT_INTO 631=LOAD_FROM_INSERT_INTO 632=UNLOAD_TO 632=LOAD_FROM_INSERT_INTO 633=UNLOAD_TO 633=LOAD_FROM_INSERT_INTO 634=UNLOAD_TO 634=LOAD_FROM_INSERT_INTO 635=UNLOAD_TO 635=LOAD_FROM_INSERT_INTO 636=UNLOAD_TO 636=LOAD_FROM_INSERT_INTO 637=ANSI_UPDATE 675=ANSI_UPDATE 675=CURSOR_SELECT 676=CURSOR_SELECT 676=META_UPDATE_VIEW 677=CURSOR_SELECT 677=META_UPDATE_MULTI_TABLE_VIEW 678=ANSI_UPDATE 678=CURSOR_SELECT 679=CURSOR_SELECT 681=CURSOR_SELECT 682=CURSOR_SELECT 685=CURSOR_SELECT 686=CURSOR_SELECT 687=CURSOR_SELECT 690=ANSI_UPDATE 690=CURSOR_SELECT
			
		#List of non-ANSI compatible SQL or db features that is NOT posible
		#to translate/emulate, and never will be since it depends on the
		#functionality of the back-end that CANNOT be emulated, translated
		#or subsitituted
		SQL_FEATURES_NON_ANSI_IMPOSIBLE="\
			ALTER_INDEX \
			ALTER_TABLE_ADD \
			ALTER_TABLE_DROP \
			ALTER_TABLE_LOCK_MODE \
			ALTER_TABLE_ADD_BEFORE \
			LOCK_TABLE_SHARED \
			LOCK_TABLE_EXCLUSIVE \
			CREATE_VIEW_SELECT_WITH_CHECK \
			CLUSTER_INDEX \
			CREATE_AUDIT \
			CREATE_TEMP_TABLE_NO_LOG \
			CREATE_TABLE_IN \
			CREATE_TABLE_EXTENT \
			CREATE_TABLE_NEXT_SIZE \
			CREATE_TABLE_LOCK_MODE \
			CREATE_INDEX_COMPOSITE \
			CREATE_INDEX_UNIQUE \
			CREATE_INDEX_UNIQUE_COMPOSITE \
			CREATE_INDEX_CLUSTER \
			CREATE_INDEX_ASC \
			CREATE_INDEX_DESC \
			CREATE_INDEX_ASC_DESC \
			CREATE_PROCEDURE \
			DROP_AUDIT \
			DLL_UNIQUE \
			DDL_CHECK \
			DDL_REFERENCES \
			DDL_SET_CONSTRAINT \
			DDL_CONSTRAINT ADD_CONSTRAINT DROP_CONSTRAINT \
			DDL_NEXT_SIZE \
			FREE_LOB \
			INDEX_FILLFACTOR \
			ORDER_BY_ASC \
			ORDER_BY_DESC \
			RECOVER_TABLE \
			ROLLFORWARD_DATABASE \
			SET_ISOLATION \
			SET_LOCK_MODE \
			SET_EXPLAIN \
			SET_LOG \
			SET_BUFFERED_LOG \
			START_DATABASE \
			START_DATABASE_WITH_LOG \
			START_DATABASE_WITH_LOG_MODE_ANSI \
			UPDATE_STATISTICS \
			UPDATE_VIEW \
			"

		#List of all non-ANSI compatible SQL or db features
		SQL_FEATURES_NON_ANSI="$SQL_FEATURES_NON_ANSI_POSIBLE \
								$SQL_FEATURES_NON_ANSI_SUPORTED \
								$SQL_FEATURES_NON_ANSI_IMPOSIBLE"
	
		#List of all non-ANSI compatible SQL or db features EXPECTED TO FAIL
		SQL_FEATURES_NON_ANSI_EXPECT_FAIL="$SQL_FEATURES_NON_ANSI_POSIBLE \
								$SQL_FEATURES_NON_ANSI_IMPOSIBLE"

#sql_features_used:
#	@echo "DROP_TABLE CREATE_TABLE INSERT_COLUMNLIST_EQ_VALUELIST \
#		ANSI_UPDATE CURSOR_SELECT"
								
#sql_features_used:
#	@echo ""
#TODO - check that all non-ANSI tests have sql_features_used target:
#691 692 693 694 695 696 697 698 699 700 701 703 704 705 710 711 712 713 714 715 
#716 717 718 719 720 721 722 723 724 725 726 727 728 729 730 731 732 733 734 735 
#736 737 740 741 742 743 744 745 746 747 748 749 750 751 752 753 754 755 756 757 
#758 759 760 761 762 763 764 765 768 769 770 771 772 773 774 775 776 778 779 780 
#781 782 783 784 785 786 787 788 789 790 791 792 795 798 901 904 905 906 907 908 
#909 910 911 912 914 915 916 917 1060 1300 1301 1302 1303 1304


			#Statments not supported by 4Js ODI on non-Informix databases
			SQL_INCOMPAT_4JS="$SQL_FEATURES_NON_ANSI_IMPOSIBLE"
				
			#Statements incompatible using Aubit in PG EC mode against 
			#Informix compatibility patched PG engine
			SQL_INCOMPAT_AUBIT_ECPG_PG_PATCHED="$SQL_FEATURES_NON_ANSI_EXPECT_FAIL"
	
			#Statements incompatible uisng Aubit in PG EC mode against 
			#vanilla (not patched) PG engine V 7.4
			SQL_INCOMPAT_AUBIT_ECPG_PG_VANILLA="$SQL_FEATURES_NON_ANSI_EXPECT_FAIL"
			
			#Statements incompatible uisng Aubit in C mode (ODBC) against 
			#vanilla (not patched) PG engine V 7.4
			SQL_INCOMPAT_AUBIT_C_PG_VANILLA="$SQL_FEATURES_NON_ANSI_EXPECT_FAIL"
	
			if test "1" = "1"; then
			#if test "$VERBOSE" = "1"; then
				#Check that the feature listed in makefile has a pair
				#in features definitions (spelling errors)
				for a in $SQL_FEATURES_USED; do
					TMP_OK=0
					for b in $SQL_FEATURES_NON_ANSI; do
						if test "$a" = "$b"; then
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
			
			case $DB_TYPE in
			
				IFX-SE) #Informix SE engine, all versions
					if test "$VERBOSE" = "1"; then 
						echo "FIXME: IFX-SE - not checking features:"
						echo "$SQL_FEATURES_USED"
					fi
					;;
					
				IFX-OL) #Informix On-line all versions (5.x, 7.x and 9.x)
					if test "$VERBOSE" = "1"; then 
						echo "FIXME: IFX-OL - not checking features:"
						echo "$SQL_FEATURES_USED"
					fi
					;;
					
				PG-IFX-74)  #PostgreSQL version 7.4 with Informix compatibility patch
					case "$USE_COMP" in
						aubit)
							INCOMPAT_FEATURE_LIST="$SQL_INCOMPAT_AUBIT_ECPG_PG_PATCHED"
						;;
						*)
							if test "$VERBOSE" = "1"; then 
								echo "FIXME: PG-IFX-74 and $USE_COMP - not checking features:"
								echo "$SQL_FEATURES_USED"
							fi
						;;
					esac
					;;
					
				PG-74) #PostgreSQL version 7.4x, not patched
					if test "$VERBOSE" = "1"; then 
						echo "FIXME: PG-74 - not checking features:"
						echo "$SQL_FEATURES_USED"
					fi
					;;
					
				PG-80) #PostgreSQL version 8.x, not patched
					if test "$VERBOSE" = "1"; then 
						echo "FIXME: PG-80 - not checking features:"
						echo "$SQL_FEATURES_USED"
					fi
					;;
				*)	#Any other database back-end
					if test "$VERBOSE" = "1"; then 
						echo "FIXME: other back-end ($DB_TYPE) - not checking features:"
						echo "$SQL_FEATURES_USED"
					fi
					;;
			esac
			
			#Perform the actuall check, by comparing the list of features used
			#with list of features expected to fail:
			INCOMPAT_SQL_LIST=
			if test "$INCOMPAT_FEATURE_LIST" != ""; then 
				for a in $SQL_FEATURES_USED; do
					for b in $INCOMPAT_FEATURE_LIST; do
						if test "$a" = "$b"; then
							if test "$INCOMPAT_SQL_LIST" = ""; then 
								INCOMPAT_SQL_LIST="$a"
							else
								INCOMPAT_SQL_LIST="$INCOMPAT_SQL_LIST $a"
							fi
							break
						fi
					done
					#If we allread have one incompatible, searching
					#for more wont change the outsome, so break and 
					#save some time
					if test "$INCOMPAT_SQL_LIST" != ""; then 
						break
					fi
				done
				if test "$INCOMPAT_SQL_LIST" != ""; then
					#temporary:
					DISABLE_SQL_FEATURES_SKIP=1
					SQL_FEATURES_COMPATIBLE=0					
					if test "$DISABLE_SQL_FEATURES_SKIP" != "1"; then		
						if test "$SKIP_INCOPAT_SQL_LIST" = ""; then 
							SKIP_INCOPAT_SQL_LIST="$TEST_NO"
						else
							SKIP_INCOPAT_SQL_LIST="$SKIP_INCOMPAT_SQL_LIST $TEST_NO"
						fi
						SKIP_REASON="incompatible SQL feature: $INCOMPAT_SQL_LIST"
						SKIP_REASON_CODES="$SKIP_REASON_CODES 28"
					else
						#SKIP_REASON_NOTSKIP="incompatible SQL feature: $INCOMPAT_SQL_LIST"
						SKIP_REASON_NOTSKIP="$INCOMPAT_SQL_LIST"
						#Just confuses things at the moment - turn it back on
						#when lists are clean:
						#IS_EXPECT_TO_FAIL_TEST=1
					fi
				else
					SQL_FEATURES_COMPATIBLE=1
				fi
			fi
		fi
	fi

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

dont_use_me () {

ALL_DIRS=[0-9]*
ALL_TESTS=`echo $ALL_DIRS | tr " " "\n" | $SORT -n |  tr "\n" " "`
LIST=""
LIST2=""
LIST3=""

for TEST_NO in $ALL_TESTS; do
	IS_DB_TEST=0
	for b in $DB_TESTS; do
		if test "$b" = "$TEST_NO"; then
			IS_DB_TEST=1
		fi
	done
	if test "$IS_DB_TEST" = "0"; then 
		TMP_IS_DB_TEST=`$MAKE -s -C $TEST_NO db_test 2>/dev/null`
		if test "$TMP_IS_DB_TEST" != ""; then 
			IS_DB_TEST=$TMP_IS_DB_TEST
		fi
	fi
	if test "$IS_DB_TEST" = "1"; then 
		IS_MAKE_ANSI_SQL_COMPAT=`$MAKE -s -C $TEST_NO ansi_sql_compat 2>/dev/null`
		if test "$IS_MAKE_ANSI_SQL_COMPAT" = "0"; then
			SQL_FEATURES_USED=`$MAKE -s -C $TEST_NO sql_features_used 2>/dev/null`
			if test "$SQL_FEATURES_USED" != ""; then
				LIST3="$LIST3 $TEST_NO"			
			else
				LIST="$LIST $TEST_NO"
			fi
		fi
	else
		IS_MAKE_ANSI_SQL_COMPAT=`$MAKE -s -C $TEST_NO ansi_sql_compat 2>/dev/null`
		if test "$IS_MAKE_ANSI_SQL_COMPAT" = "0"; then
			LIST2="$LIST2 $TEST_NO"
		fi
	fi

done

echo "List of datbase tests that are not ANSI compatible, " 
echo "and we need to find out why and list that in sql_features_used target:"
echo "$LIST"
# 1 36 68 73 76 80 94 95 98 101 107 108 109 206 207 255 269 286 287 289 290
#298 528 530 531 532 533 534 535 536 537 538 539 540 541 542 543 544 545 546
#547 548 550 551 552 553 554 555 556 557 558 559 560 561 562 563 564 565 566
#567 568 569 570 571 572 573 574 575 576 577 578 579 580 581 585 586 587 588
#590 591 592 593 594 595 596 597 598 599 600 602 603 605 606 607 609 610 611
#612 613 614 615 616 618 619 620 621 622 623 624 625 626 627 628 629 630 631 
#632 633 634 635 636 637 638 639 640 642 643 644 645 646 647 648 649 650 651 
#652 653 654 655 656 657 658 659 660 661 662 663 664 665 666 667 668 669 675 
#676 677 678 679 681 682 683 685 686 687 690 691 692 693 694 695 696 697 698 
#699 700 701 702 703 704 705 710 711 712 713 714 715 716 717 718 719 720 721 
#722 723 724 725 726 727 728 729 730 731 732 733 734 735 736 737 740 741 742 
#743 744 745 746 747 748 749 750 751 753 754 755 756 757 758 759 760 761 762 
#763 764 768 769 770 771 772 773 774 775 776 778 779 780 781 782 783 784 785 
#786 787 788 789 790 791 792 795 796 797 798 901 904 905 906 907 908 909 910 
#911 912 914 915 916 917 936 937 1060

echo ""
echo "Non-db tests, but marked not ANSI compatible (???)"
echo "$LIST2"
echo ""
echo "Allready have features described:"
echo "$LIST3"
# 91 100 106 234 738 793 794

exit



	
#Tests I plan to mark as ANSI compatible:
#datetime: 
A="28 47 49 51 60 215 224 265 271 280 947 970 982 993"

#Date : 
B="69 90 202 211 222 225 229 240 241 247 249 260 262 268 279 479 480 481 497 \
	946 961 981 992 1001"
#(Comment: I think it is safe to assume all databases we are interested in 
#support DATE and DATETIME?)

#Money: 
C="78 456 966 980 991 1000 24"
#(Comment: Money is just a decimal, so we can/should deal with this reasonably 
#easy in any database?) 

#Initialize like : 
D="372 373"
#(function of compiler, not database) 

#Create temp table: 
E="63 99"
#(We can/should emulate this one reasonably easy on any database) 

#Validate like : 
F="374 376 377 375"
#(function of compiler, not database) 

#UPDATE ... SET * = pr.* : 
G="680 689"
#(We can/should emulate this one reasonably easy on any database)

#Interval: 
H="706 707 948 971 983 994 670 671 672 673"
#(Comment: I think it is safe to assume all databases we are interested in 
#support INTERVALs this days?)


#Varchar: 
I="801 802 944 945 968 974 984 985 986 987 988 989 990 996 1003"
#(Comment: I think it is safe to assume all databases we are interested in 
#support VARCHARs this days?)

#Smallfloat: 
J="924 925 941 953 963 978 1006"
#(Comment: I think it is safe to assume all databases we are interested in 
#support SMALLFLOAT this days?)

#The only 'crime' of following tests is that they use DATABASE without full qualifier:
K="14 72 96 212 244 258 270  273 274 278 309 327 331 332 333 334 335 352 353 \
	354 357 358 359 360 361 362 363 364 365 366 367 370 371 476 477 478 513 \
	514 515 516 517 518 519 520 521 522 523 524 525 526 549 902 913 949 950 257" 
#Safe to ignore?

LIST="$A $B $C $D $E $F $G $H $I $J $K"

#for TEST_NO in $LIST; do
#	change_setting ansi_sql_compat 1 $TEST_NO
#	echo "Test $TEST_NO - set ansi_sql_compat to yes"
#done


#Tests I plan to mark as ANSI INCOMPATIBLE:

#Free cursor: 
A="587 589"

#Set explain : 
B="590 591"

#Database exclusive: 
C="550"

#Tests that use Alter table, Drop table, check, close database, primary key, 
#distinct, references, create synonym, foreign key, rename column, drop trigger, 
#set constraint, start database, set log, rollforward database, default, 
#create/drop database, cluster index, lock table: 
D="536 537 538 539 540 541 542 543 544 545 546 547 548 556 561 562 571 586 \
	597 599 607 683 702 796 936 937 531 554 555 558 560 569 572 585 600 797"

LIST="$A $B $C $D"
	
#for TEST_NO in $LIST; do
#	change_setting ansi_sql_compat 0 $TEST_NO
#	echo "Test $TEST_NO - set ansi_sql_compat to no"
#done




exit

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
            TMP=`cat /tmp/credbtmp.log | grep "Database created"`
            if test "$TMP" != ""; then
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
		echo "CR2"
		create_db $db
	else
		echo "Database $db exists"
		drop_db $db	
		echo "CR3"
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
#16-10-2004_12-49-24|aptiva|root|UNIX|i386-redhat-linux-gnu|
#Linux aptiva 2.4.7-10 #1 Thu Sep 6 17:21:28 EDT 2001 i586 unknown|
#-esqli -nospace -described -nolong -err-with-log -defaults -esqli -silent -log-unl -verbose-results|
#0.48|65||4689|2.96|9.51.UC1|9.21.UC4|3.79.1|2.05.8(1)-release||
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

	load_unl_tables
	
	echo "Done"
}

load_unl_tables () {
dl="|"
#ALL_RESULTS="aptiva_16-10-2004_12-49-24"
ALL_RESULTS=results_*.unl


	echo "Loading catalogue..."
	load_table "aubit_tests" "catalogue" "$CURR_DIR/docs/catalogue.unl" "42" "$dl"

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
		THIS_LOAD=`(expr $CNT - $BEFORE_LOAD) 2>/dev/null`
		echo "$THIS_LOAD rows loaded into $loadname"
	fi
	
	if test "$RET" != "0"; then 
		echo "dbload failed."
		if test -f /tmp/dbload.log; then 
			cat /tmp/dbload.log
		fi
		exit $RET
	fi
	
	if test "$VERBOSE" = "1"; then
		if test -f $loadname.err; then 
			cat $loadname.err
		fi
	fi

}


##
# Log test descriptiont into Informix-style .unl file
#
##
catalogue_unl() {
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
c_ver=`gcc --version | grep gcc `
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
		
	sqlite)
		cat $SCRIPT | sqlite $SQLITE_DB
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
show_test_info() {
			
			echo " ------------------- Info for test $TEST_NO -----------------------"		

			if test "$TEMPLATE_COMMENT" = "1"; then 
				echo "WARNING: test still contains template comment in makefile"
				TEMPLATE_COMMENT_CNT=`(expr $TEMPLATE_COMMENT_CNT + 1) 2>/dev/null`
				TEMPLATE_COMMENT_LIST="$TEMPLATE_COMMENT_LIST $TEST_NO"
			fi
			
			if test "$IS_OLD_MAKEFILE" = "1" \
				-a "$IS_DESCRIBED" = "1" \
				-a "$IS_UNKNOWN_TEST" != "1"; \
			then
				echo "Please migrate folowing test info from 'run_tests' script to makefile:"
				echo ""
				MIGRATE_DESC_CNT=`(expr $MIGRATE_DESC_CNT + 1) 2>/dev/null`
				MIGRATE_DESC_LIST="$MIGRATE_DESC_LIST $TEST_NO"			
			fi
			
			if test "$desc_txt" != "" ; then
				echo ""
				echo $desc_txt
				echo ""
				HAS_DESC_TXT_CNT=`(expr $HAS_DESC_TXT_CNT + 1) 2>/dev/null`
			fi
			
			if test "$IS_REPORT_TEST" = "1"; then
				echo "Test contains REPORT block"
				IS_REPORT_TEST_CNT=`(expr $IS_REPORT_TEST_CNT + 1) 2>/dev/null`
			fi
			if test "$EXPECT_CODE" != "0" ; then
				if test "$EXPECT_CODE" = "x" ; then
					echo "Test is expected to exit with non-zero code"			
				else
					echo "Test is expected to exit with code $EXPECT_CODE"
				fi
				NON_ZERO_EXIT_CNT=`(expr $NON_ZERO_EXIT_CNT + 1) 2>/dev/null`
			fi
			if test "$COMPILE_ONLY" = "1" ; then
				echo "Test is compile only, no execution will be attempted"
				COMPILE_ONLY_CNT=`(expr $COMPILE_ONLY_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_PCODE_ENABLED" = "1" ; then
				#All tests descxribed by makefiel are P-code enabled amyway
				echo "Test is P-CODE testing enabled"
				IS_PCODE_ENABLED_CNT=`(expr $IS_PCODE_ENABLED_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_DESCRIBED" != "1" ; then
				echo "*** Test not described ***"
				NOT_DESCRIBED_CNT=`(expr $NOT_DESCRIBED_CNT + 1) 2>/dev/null`
				NOT_DESCRIBED_LIST="$NOT_DESCRIBED_LIST $TEST_NO"
			fi
			if test "$IS_INVALID_TEST" = "1"; then 
				echo "**** TEST MARKED INVALID IN run_tests ******"
				IS_INVALID_CNT=`(expr $IS_INVALID_CNT + 1) 2>/dev/null`
				IS_INVALID_LIST="$IS_INVALID_LIST $TEST_NO"
			fi
			if test "$IS_EXPECT_TO_FAIL_TEST" = "1"; then 
				echo "**** TEST EXPECTED TO FAIL BECAUSE OF THE AUBIT4GL BUG ******"
				EXPECT_FAIL_CNT=`(expr $EXPECT_FAIL_CNT + 1) 2>/dev/null`
				EXPECT_FAIL_LIST="$EXPECT_FAIL_LIST $TEST_NO"
			fi
			if test "$IS_DB_TEST" = "1"; then
				echo "Test needs database"
				IS_DB_TEST_CNT=`(expr $IS_DB_TEST_CNT + 1) 2>/dev/null`
				if test "$SE_REQUIRED" = "1"; then
					echo "Test requires Informix SE RDBMS"
					IS_SE_REQUIRED_CNT=`(expr $IS_SE_REQUIRED_CNT + 1) 2>/dev/null`
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
				IS_EC_TEST_CNT=`(expr $IS_EC_TEST_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_NOSILENT_TEST" = "1"; then
				echo "Test will fail if not running on screen (curses)"
				IS_NOSILENT_CNT=`(expr $IS_NOSILENT_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_TUI_TEST" = "1"; then
				echo "Test uses curses and/or screeen dump and may fail when TERM!=xterm"
				echo "Anything that uses a screen dump may have specific attributes set which may"
				echo "fail if TERM!=xterm"
				echo "This core dumps on MinGW and messes up the terminal completely."
				echo "On Cygwin they don't core dump, but this tests fail"
				IS_TUI_TEST_CNT=`(expr $IS_TUI_TEST_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_FORM_TEST" = "1"; then
				echo "Test uses .per form files"
				IS_FORM_TEST_CNT=`(expr $IS_FORM_TEST_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_GRAPHIC_TEST" = "1"; then
				echo "Test that use graphic characters in forms that may be platform dependent"
				IS_GRAPHIC_TEST_CNT=`(expr $IS_GRAPHIC_TEST_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_CONSOLE_PROMPT_TEST" = "1"; then
				echo "Test waits for user's input in CONSOLE mode, because automated testing"
				echo "was not implemented there, so we must skip them untill this is implemented"
				IS_CONSOLE_PROMPT_CNT=`(expr $IS_CONSOLE_PROMPT_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_DUMP_SCREEN_TEST" = "1"; then
				echo "test uses aclfgl_aclfgl_dump_screen, A4GL_clr_window or aclfgl_fgl_drawbox, so"
				echo "it won't work in CONSOLE mode"
				IS_DUMP_SCREEN_CNT=`(expr $IS_DUMP_SCREEN_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_LONG_TEST" = "1"; then
				echo "Test takes more then 10 minutes to compile or run"
				IS_LONG_CNT=`(expr $IS_LONG_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_CERT_TEST" = "1"; then
				echo "Tests is certified to run (with -eci) If it fails, something was probably broken"
				echo "in current code."
				IS_CERT_CNT=`(expr $IS_CERT_CNT + 1) 2>/dev/null`
			fi
			if test "$IS_OBSOLETE_TEST" = "1"; then
				echo "test is superceeded or obsoleted and should be silently skipped"
				IS_OBSOLETE_CNT=`(expr $IS_OBSOLETE_CNT + 1) 2>/dev/null`
				IS_OBSOLETE_LIST="$IS_OBSOLETE_LIST $TEST_NO"
			fi
			if test "$compat_test" = "1"; then
				echo "Test can be run using any 4GL compatible compiler, not just Aubit"
				IS_COMPAT_CNT=`(expr $IS_COMPAT_CNT + 1) 2>/dev/null`
			fi
			if test "$need_compat" = "1"; then
				echo "Test requires Aubit to be in Informix compatibility mode"
			fi
			if test "$IS_UNKNOWN_TEST" = "1"; then 
				echo "Test is clasified as UNKNOWN - please corect this."
				UNKNOWN_TEST_CNT=`(expr $UNKNOWN_TEST_CNT + 1) 2>/dev/null`			
				echo ""
			fi
			echo ""
			if test "$INFO_TEST" = "1"; then
				if test "$CATALOGUE_UNL" = "1"; then 
					catalogue_unl
				fi
				continue
			fi
}


check_skip_non_db() {
	
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
check_skip() {
	
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
		SKIP_INVALID_CNT=`(expr $SKIP_INVALID_CNT + 1) 2>/dev/null`
		SKIP_INVALID_LIST="$SKIP_INVALID_LIST $TEST_NO"
		SKIP_REASON="invalid test"
		SKIP_REASON_CODES="$SKIP_REASON_CODES 1"
	else
	
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
		if test "$UI" = "CONSOLE" && (test "$IS_CONSOLE_PROMPT_TEST" = "1" -o "$IS_DUMP_SCREEN_TEST" = "1" -o test "$IS_FORM_TEST" = "1") ; then
			SKIP_REASON="in CONSOLE mode - uses forms or dump_screen()."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 8"
			SKIP_CONSOLE_LIST="$SKIP_CONSOLE_LIST $TEST_NO"
	    fi
		if test "$IS_DUMP_SCREEN_TEST" = "1" && (test "$UI" = "HL_TUIN" -o "$UI" = "HL_TUINs") ; then
			SKIP_REASON="screen_dump() not implemented in PDcurses."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 9"
			SKIP_NO_SCRDUMP_PDCURSES_LIST="$SKIP_NO_SCRDUMP_PDCURSES_LIST $TEST_NO"
	    fi
	    if test "$IS_DESCRIBED" != "1" -a "$DESCRIBED_ONLY" = "1"; then
			SKIP_REASON="not described"
			SKIP_REASON_CODES="$SKIP_REASON_CODES 10"
			SKIP_NODESC_LIST="$SKIP_NODESC_LIST $TEST_NO"
	    fi
		
		check_skip_non_db
		
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
		if test "$IS_DUMP_SCREEN_TEST" = "1" -a "$TERM" != "xterm"; then
			SKIP_DUMP_SCREEN_NOT_XTERM_LIST="$SKIP_DUMP_SCREEN_NOT_XTERM_LIST $TEST_NO"
			SKIP_REASON="cannot use dump_screen() with TERM=$TERM (need xterm)."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 15"
		fi
	    if test "$IS_GRAPHIC_TEST" = "1" -a "$NO_GRAPHIC" = "1"; then
			SKIP_REASON="uses platform specific characters."
			SKIP_REASON_CODES="$SKIP_REASON_CODES 16"
			SKIP_GRAPHIC_LIST="$SKIP_GRAPHIC_LIST $TEST_NO"
	    fi
	    if test "$IS_NO_CRON_TEST" = "1" -a "$CRON_JOB" = "1"; then
			IS_NO_CRON_CNT=`(expr $IS_NO_CRON_CNT + 1) 2>/dev/null`
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
				SKIP_NON_ANSI_CNT=`(expr $SKIP_NON_ANSI_CNT + 1) 2>/dev/null`
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

}	

#Check if makefile is old or new type; sets IS_OLD_MAKEFILE
check_makefile_type() {
	
	#We can no longer use description target itself to find out if test uses new or old 
	#makefiles, since Mike started adding desc target to old makefiles, so we 
	#now have OLD makefiles that DO have text description (desc target) but
	#little if anything else of other descriptions, and do not use any
	#functionality of new makefiles. So, to find out if this test has old
	#or new makefile, we will use form_test target... ATM, no makefile below
	#100 has it.
	
	IS_FORM_TEST=`$MAKE -s -C $TEST_NO form_test 2>/dev/null`
	if test "$IS_FORM_TEST" = ""; then
		#echo "old makefile"	
		IS_OLD_MAKEFILE=1
	else
		#echo "new makefile"	
		IS_OLD_MAKEFILE=0
	fi

}

#see if Makefile contains description. Both old and new makefiles
#may contain description now, but new ones may contain a template text
#instead of actuall description text
check_desc_txt() {
	
	desc_txt=`$MAKE -s -C $TEST_NO desc 2>/dev/null`

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
check_cached_skip_reasons() {

	for b in $IS_DB_TEST_CACHE; do
		if test "$b" = "$TEST_NO"; then
			IS_DB_TEST=1
		fi
	done

	check_skip_non_db

}


#decide if we WANT to skip test
do_skip() {
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
			SKIP_CNT=`(expr $SKIP_CNT + 1) 2>/dev/null`
			if test "$UNL_LOG" = "1"; then
				#test_no=$1 result=$2 skip_reason=$3 expect_fail=$4 test_version=$5 db_has_trans=$6
				result_unl $TEST_NO "" "$SKIP_REASON_CODES" $IS_EXPECT_TO_FAIL_TEST "" $DB_HAS_TRANSACTION
			fi
			DO_SKIP=1
		fi
    fi
}




