#This file conatains lists of all tests expected to fail
#it is used as include from main testing execution script


# --------------------------------------------------------------------------
#							-cert (-eci)
# --------------------------------------------------------------------------

######################
#Tests that currently fail because of the bug in Aubit compiler (with -cert)
#Note that this list will be included in all other EXPECT_TO_FAIL_
#lists that applu to Aubit compiler, since it anticipated that tests that fail 
#using -eci will not work with any other Aubit configuration
#NOTE: <*> = OK with -esqli
EXPECT_TO_FAIL_TESTS="240 670 706 278 766 767 962 976 987"
#240 (numeric formating) http://aubit.com/mantis/bug_view_page.php?bug_id=0000495
#670 (syntax errors in generated EC code) http://aubit.com/mantis/bug_view_page.php?bug_id=0000477
#706 (expression in SQL syntax error) http://aubit.com/mantis/bug_view_page.php?bug_id=0000515
#278 (Too few variables for the number of fields) http://aubit.com/mantis/bug_view_page.php?bug_id=0000593
#766 (Key CONTROL-H was 49     and not 8) http://aubit.com/mantis/bug_view_page.php?bug_id=0000596
#767 (wrong codes returned) http://aubit.com/mantis/bug_view_page.php?bug_id=0000597
#962 (Error on near zero decimal comparison) http://aubit.com/mantis/bug_view_page.php?bug_id=0000601
#976 (Error in conversion.) http://aubit.com/mantis/bug_view_page.php?bug_id=0000603
#987 same ?
#233 failed once, but cant reproduce??

#SEEM TO BE FIXED NOW: 348 349 350 351 fail at random ?!! (seem they work with -esqli ?)

#not reported (please enter bug report at: http://aubit.com/mantis)
EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS 296 590 111 112"
#296 Unable to read form.
#590 Cannot open EXPLAIN output file. (Works with -ecp HOW? is it ignored?)
#111 channel function not implemented
#112 opening form in DBPATH broken

# --------------------------------------------------------------------------
#							-esql
# --------------------------------------------------------------------------

######################
#Tests that currently fail with -esqli (but work with -cert)
EXPECT_TO_FAIL_TESTS_ESQLI="80 685 694 703"
#80 (Decimal or money value exceeds maximum precision) http://aubit.com/mantis/bug_view_page.php?bug_id=0000605
#685 same
#694 same
#703 same

# --------------------------------------------------------------------------
#							-ifxodbc
# --------------------------------------------------------------------------

######################
#Tests expected to fail with -ifxodbc (in addition to EXPECT_TO_FAIL_TESTS)
EXPECT_TO_FAIL_TESTS_IFXODBC="1 68 108 212 234 270 582 583 584 585 587 706 904 \
	905 906 907 908 909 910 911 912 913 914 915 91 95 100 586 739 1200 \
	76 98 207 900 903"
#1 conv.c               2751   (     0,     0) Start Time invalid on datetime(dttoc)


######################
#Tests that should not be run with -ifxodbc, because they go into endless loop 
#and never exit
BLACKLIST_TESTS_IFXODBC="107 286 287 681 682 686 687 701 702 703 704"
#107: goes into loop:
#sql.c                2082   (     0,     0) After SQL Error -11067 S1010 [Informix][Informix ODBC Driver]Function sequence error.
#sql.c                2109   (     0,     0) 'S1010' '[Informix][Informix ODBC Driver]Function sequence error.' (-11067 56)


# --------------------------------------------------------------------------
#							Windows (native-MinGW)
# --------------------------------------------------------------------------

######################
#Tests that should not be run on MinGW, because they go into endless loop 
#and never exit
BLACKLIST_TESTS_MINGW="69 215 241 335"
#215 241 - error in field (seem like only sigle char read from keys.in?)
#335 - 4glc freezzes

EXPECT_TO_FAIL_TESTS_MINGW="242 244 246 252 254 272 273 274 276 277 288 535 1060 \
	22 24 26 27 31 33 34 38 40 42 57 59 63 70 77 79 86 104 203 \
	205 211 213 217 218 220 222 223 229 230 231 236 239 283"


#242 
#244 
#246 initscr(): LINES=1 COLS=1: too small
#252 
#254 
#272 
#273 
#274 
#276 
#277 
#288 
#535
#1060 - Native Windows executable knows nothing about bash and CygWin paths,
#so RUN-ining a shell script fails with error mesage from Microsoft cmd.exe

# --------------------------------------------------------------------------
#							-unixodbc
# --------------------------------------------------------------------------

#-unixodbc with -odbcdb-ifx
EXPECT_TO_FAIL_TESTS_UNIXODBC_IFX=""

# --------------------------------------------------------------------------
#							-ecp
# --------------------------------------------------------------------------

######################
#Tests that currently fail with -ecp (but work with -cert)
EXPECT_TO_FAIL_TESTS_ECP="76 98 530 535"
#76 (datetime-ecpg issue) http://aubit.com/mantis/bug_view_page.php?bug_id=0000479
#98 (serial) http://aubit.com/mantis/bug_view_page.php?bug_id=0000604
#530,535 (syntax) http://aubit.com/mantis/bug_view_page.php?bug_id=0000485

#TODO: Close bugs in Mantis:
#FIXED: 36 (close cursor) http://aubit.com/mantis/bug_view_page.php?bug_id=0000478
#SEEM TO BE WORKING NOW BUT HOW? 227 (syntax error) http://aubit.com/mantis/bug_view_page.php?bug_id=0000483

#############
#Not reported, but diagnosed:
EXPECT_TO_FAIL_TESTS_ECP="$EXPECT_TO_FAIL_TESTS_ECP \
	1 73 91 100 106 234 256 376 109 286 287 793 794 913 914 915 207 900 903 739"
#1 afinderr -213 /opt/aubit/aubit4glsrc/help/help_ecpg.iem: ECPG_MISSING_INDICATOR          -213   	
#73 core dump in libecpg.so
#91,100,234 put.cpc:155: ERROR: invalid datatype 'PUT' - now SKIP (PUT_CURSOR)
#106 prog.cpc:138: ERROR: syntax error at or near "1" - SQL...END SQL block & SELECT FIRST (relative)
#256 prog.cpc:133: ERROR: syntax error at or near "INTO" - now SKIP (SELECT_INTO_TEMP)
#376 core in 4glc :
#aubit 4glc list_validate_like_star.4gl -c -o list_validate_like_star.ao
#row number 1 is out of range 0..-1
#286 287 A4GLSQL_set_sqlerrm(''relative path not allowed for COPY to file' in line 147.','NOT SET ') 
#109 core dump when opening lock cursor
#793 794 syntax error at or near "AUDIT" - now SKIP
#914 A warning was not issued after an agregate with null values
#913 An warning was not issued with a DB with transactions 
#207 Performing extend(year to day)
#900 A wrong select give a zero sqlca
#903 Wrong sqlca it as not assigned sqlcode
#739 A row was deleted from a temp table with no log

#############
#Not reported, not diagnosed:
EXPECT_TO_FAIL_TESTS_ECP="$EXPECT_TO_FAIL_TESTS_ECP \
	110 541 551 552 553 554 555 556 557 558 559 560 561 562 569 570 571 572 \
	573 575 576 577 579 581 584 587 593 597 599 600 603 607 611 612 620 628 \
	632 633 634 635 636 639 643 645 646 648 649 650 651 652 653 654 655 656 \
	657 658 659 660 661 662 663 664 665 666 667 668 669 675 676 683 686 687 \
	689 698 700 701 702 704 710 711 713 714 721 724 725 728 729 730 750 751 \
	754 760 761 762 764 771 773 775 776 795 796 902 904 905 906 908 909 936 \
	937 1201 1301 1302 1303 1304"

# --------------------------------------------------------------------------
#							-ifx-p
# --------------------------------------------------------------------------
	
#####################################################
#Expected to fail using Informix/4Js/Querix compiler
EXPECT_TO_FAIL_IFX="102 227 251 254 319 487 706"
#102,254 - dump_screen empty
#227 - all 3 compilers give different ouptput
#251 - Ifx & Q same, but Aubit different
#319 - NULL in function call not accepted by i4gl
#487 - ON KEY ("home") supported only by 4js and Aubit
#706 - (Diferent value 32) http://aubit.com/mantis/bug_view_page.php?bug_id=0000515

# --------------------------------------------------------------------------
#							-4js-p
# --------------------------------------------------------------------------

EXPECT_TO_FAIL_4JS="216 225 240 348 349 364 372 373 380 381 531 536 565 566 \
	573 577 626 627 628 629 630 631 632 633 634 635 636 670 675 706"

# --------------------------------------------------------------------------
#							-querix
# --------------------------------------------------------------------------
	
EXPECT_TO_FAIL_QUERIX="234 240 351 359 362 363 364 365 366 372 373 374 376 380 \
	381 383 385 402 404 408 421 422 461 470 471 473 475 487 516 531 538 539 544 \
	556 582 583 584 586 587 597 599 607 629 670 683 702 706"
#487 - ON KEY ("home") supported only by 4js and Aubit

# --------------------------------------------------------------------------
#						Invalid/incomplete tests
# --------------------------------------------------------------------------

######################
#Tests that currently fail because of the errors in the test itself
INVALID_TESTS="375 377 684 105 705 707 752 797 916 917 919 920 921 \
	922 923 924 925 926 927 928 929 930 931 932 933 934 935 948 949 950 951 952 \
	953 954 955 956 957 958 959 964	966  918 \
	938 939 940 941 942 943 944 945 946 947  498 499 1202 1200 1201"
#752 - fails to run under informix 4gl
#707 - fails to run under informix 4gl
#375,377 -"informix".systables (assumes user "informix" created test database)
#684,255 256 259 - no test files
#105 - missing database schemma
#705 - "It is not possible to convert between the specified types." with -ifx-p
#920 - no makefile
#797  SET CONSTRAINTS ALL IMMEDIATE - fails even with -ifx-p
#916,917,919,921,922,923,924,>>925<<,927,928,929,930,931,932,933,935,948...
#...949 950 951 952 953 954 955 957 958 959 964 966 918 938 939 940 941 
#...942 943 944 945 946 947 - fails even with -ifx-p (.c files with informix headers)
#926 missing function
#934 no test files
#956 missing 4gl file
#498,499 no keys.in
#1202 - missing form file, and keys.in
#1200 1201  out.expected missing

################################### EOF #################################


