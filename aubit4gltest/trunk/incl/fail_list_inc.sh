#This file conatains lists of all tests expected to fail
#it is used as include from main testing execution script

# --------------------------------------------------------------------------
#							-cert (-eci)
# --------------------------------------------------------------------------

#####################
#Tests that currently fail because of the bug in Aubit compiler (with -cert)
#Note that this list will be included in all other EXPECT_TO_FAIL_
#lists that applu to Aubit compiler, since it anticipated that tests that fail 
#using -eci will not work with any other Aubit configuration
#NOTE: <*> = OK with -esqli
EXPECT_TO_FAIL_TESTS="240 766 767 962 976 987"
#240 (numeric formating) http://aubit.com/mantis/bug_view_page.php?bug_id=0000495
#766 (Key CONTROL-H was 49     and not 8) http://aubit.com/mantis/bug_view_page.php?bug_id=0000596
#767 (wrong codes returned) http://aubit.com/mantis/bug_view_page.php?bug_id=0000597
#962 (Error on near zero decimal comparison) http://aubit.com/mantis/bug_view_page.php?bug_id=0000601
#976 (Error in conversion.) http://aubit.com/mantis/bug_view_page.php?bug_id=0000603
#987 same ?
#233 failed once, but cant reproduce??

#not reported (please enter bug report at: http://aubit.com/mantis)
EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS "

#Tests that may fail for reasons other then Aubit bug (config issues)
#590 Cannot open EXPLAIN output file. (Works with -ecp because its ignored) 	
#218 RPC client server test

# --------------------------------------------------------------------------
#							-esql
# --------------------------------------------------------------------------

######################
#Tests that currently fail with -esqli (but work with -cert)
EXPECT_TO_FAIL_TESTS_ESQLI="80 685 694 703"
#80 (Decimal or money value exceeds maximum precision) http://aubit.com/mantis/bug_view_page.php?bug_id=0000605 # Can you double check - 80 works on mine
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
BLACKLIST_TESTS_IFXODBC="107 286 287"
#107: goes into loop:
#sql.c                2082   (     0,     0) After SQL Error -11067 S1010 [Informix][Informix ODBC Driver]Function sequence error.
#sql.c                2109   (     0,     0) 'S1010' '[Informix][Informix ODBC Driver]Function sequence error.' (-11067 56)


# --------------------------------------------------------------------------
#							Windows (native-MinGW)
# --------------------------------------------------------------------------

######################
#Tests that should not be run on MinGW, because they go into endless loop 
#and never exit
BLACKLIST_TESTS_MINGW="69 215 241 335 376"
#215 241 - error in field (seem like only sigle char read from keys.in?)
#335 - 4glc freezzes
#376 - core dump

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
#218 RPC client-server test
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
EXPECT_TO_FAIL_TESTS_ECP="1 76 98 110 376 530 535 584 587 670 739 900 \
	903 913 1208 1220 1228 "
#1 'xdt is null' BUT SHOULD BE 'xdt is 12:01:02' http://aubit.com/mantis/view.php?id=687 AND http://aubit.com/mantis/view.php?id=517
#76 (datetime-ecpg issue) http://aubit.com/mantis/bug_view_page.php?bug_id=0000479
#98 serial insert ignores non-zero value http://aubit.com/mantis/view.php?id=604
#110 COPY delimiter must be a single character http://aubit.com/mantis/view.php?id=693
#376 core in 4glc : http://aubit.com/mantis/view.php?id=688
#530 (TABLENAME_DB_USER_TABLE),535 (CREATE_TABLE_IN)  (syntax) http://aubit.com/mantis/bug_view_page.php?bug_id=0000485
#584 587 prepared DATABASE stmt fails with -220 http://aubit.com/mantis/view.php?id=694
#670 error in ecpg generated C code http://www.aubit.com/mantis/view.php?id=696
#739 A row was deleted from a temp table with no log http://aubit.com/mantis/view.php?id=692
#900 A wrong select give a zero sqlca http://aubit.com/mantis/view.php?id=690
#903 Wrong sqlca it as not assigned sqlcode http://aubit.com/mantis/view.php?id=691
#913 An warning was not issued with a DB with transactions http://aubit.com/mantis/view.php?id=689
#1208 1228 UNLOAD TO SELECT FROM cant open file http://www.aubit.com/mantis/view.php?id=697
#1220 select one more filed then it exsist in the table http://www.aubit.com/mantis/view.php?id=698


# --------------------------------------------------------------------------
#							-sqlite and -sqlite-odbc
# --------------------------------------------------------------------------
	
#####################################################
#Expected to fail using SQLite (without .cnv)  Success: 22 % (-onlydb)
EXPECT_TO_FAIL_SQLITE="\
	1 14 68 72 73 76 91 94 95 98 99 100 106 108 109 110 207 212 234 255 270 \
	286 358 359 367 528 530 531 532 536 537 538 539 540 541 542 543 544 551 \
	552 553 557 558 559 560 561 562 563 564 565 566 567 568 570 571 572 574 \
	576 578 580 584 585 586 587 588 592 595 596 598 602 605 606 609 610 611 \
	612 613 614 615 616 618 619 620 621 622 623 624 625 626 627 628 629 630 \
	631 632 633 634 635 636 637 638 639 640 642 643 644 645 646 647 648 649 \
	650 651 652 653 655 656 658 659 666 667 668 675 676 677 678 679 680 681 \
	682 683 685 686 687 689 690 691 692 693 694 695 696 697 698 699 700 701 \
	702 703 704 711 712 713 715 716 717 718 719 720 721 722 723 724 725 726 \
	727 728 729 730 731 732 733 734 735 736 737 738 739 740 741 742 743 744 \
	746 747 748 749 750 751 753 754 755 756 757 758 759 760 761 762 763 764 \
	765 768 769 770 771 772 773 774 775 776 778 779 780 781 782 783 784 785 \
	786 787 788 789 790 791 792 798 901 904 905 906 907 908 909 910 911 912 \
	913 914 915 936 1300 1301 1302 1303 1304"
	
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
	938 939 940 941 942 943 944 945 946 947 1206 \
	1234 1239 1233 1235 1236"
#752 - fails to run under informix 4gl
#707 - fails to run under informix 4gl
#375,377 -"informix".systables (assumes user "informix" created test database)
#684,255 259 - no test files
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
#498,499 no keys.in ** FIXED ??
#1202 - missing form file, and keys.in
#1200 out.expected missing ** FIXED ?
#287 never exits with -cert (seems to be fixed)
#empty MAIN block
#1234 1239 1233 1237 missing out.expected
#1235 1236 missing form file

################################### EOF #################################


