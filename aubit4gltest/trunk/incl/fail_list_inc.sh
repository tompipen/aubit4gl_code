#This file conatains lists of all tests expected to fail
#it is used as include from main testing execution script

#fails at random? #NOT expected to fail:  349 (1)


#-esqli NOT expected to fail:  109 296 351 (3)
#-eci NOT expected to fail:  109 296 (2)

######################
#Teats expected to fail with -ifxodbc (in addition to EXPECT_TO_FAIL_TESTS)
EXPECT_TO_FAIL_TESTS_IFXODBC="1 \
	753 758 759 760 783 791 792 798 901 902 904 905 906 907 \
	908 909 910 911 912 913 914 915 936 1060"
#1 conv.c               2751   (     0,     0) Start Time invalid on datetime(dttoc)

######################
#Tests that should not be run with -ifxodbc, because they go into endless loop 
#and never exit
BLACKLIST_TESTS_IFXODBC="107 286 287 681 682 686 687 701 702 703 704"
#107: goes into loop:
#sql.c                2082   (     0,     0) After SQL Error -11067 S1010 [Informix][Informix ODBC Driver]Function sequence error.
#sql.c                2109   (     0,     0) 'S1010' '[Informix][Informix ODBC Driver]Function sequence error.' (-11067 56)


#-unixodbc with -odbcdb-ifx
EXPECT_TO_FAIL_TESTS_UNIXODBC_IFX=""


######################
#Tests that currently fail because of the bug in Aubit compiler (with -cert)
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

#not reported (please enter bug report at: http://aubit.com/mantis)
EXPECT_TO_FAIL_TESTS="$EXPECT_TO_FAIL_TESTS "


######################
#Tests that currently fail with -esqli (but work with -cert)
EXPECT_TO_FAIL_TESTS_ESQLI="80 685 694 703"
#80 (Decimal or money value exceeds maximum precision) http://aubit.com/mantis/bug_view_page.php?bug_id=0000605
#685 same
#694 same
#703 same


######################
#Tests that currently fail with -ecp (but work with -cert)
EXPECT_TO_FAIL_TESTS_ECP="36 76 98 227 530 531 535"
#36 (close cursor) http://aubit.com/mantis/bug_view_page.php?bug_id=0000478
#76 (datetime-ecpg issue) http://aubit.com/mantis/bug_view_page.php?bug_id=0000479
#98 (serial) http://aubit.com/mantis/bug_view_page.php?bug_id=0000604
#227 (syntax error) http://aubit.com/mantis/bug_view_page.php?bug_id=0000483
#530 (syntax+531,535) http://aubit.com/mantis/bug_view_page.php?bug_id=0000485

#############
#Not reported
EXPECT_TO_FAIL_TESTS_ECP="$EXPECT_TO_FAIL_TESTS_ECP \
	536 537 538 539 540 541 543 544 551 552 553 554 555 556 557 558 \
	559 560 561 562 565 566 567 568 569 570 571 572 573 575 576 577 579 581 \
	584 587 592 593 597 599 600 602 603 605 606 607 609 610 611 612 613 614 \
	615 618 619 621 622 623 624 625 626 627 628 629 630 631 632 633 634 635 \
	636 637 638 639 645 646 647 648 649 650 651 652 653 654 655 656 657 \
	658 659 660 664 665 666 667 668 669 675 676 677 678 679 681 682 683 \
	685 686 687 689 690 691 693 694 697 698 699 700 701 702 703 704 710 711 \
	712 713 714 715 716 717 718 \
	1 73 91 100 106 234 256 270 376 542 563 564 574 578 580 585 586 588 \
	595 596 598 620 642 643 644 661 662 663 692 695 696 719 720 721 722 723 \
	724 725 726 727 728 729 730 731 732 733 734 735 736 737 738 739 740 741 \
	742 743 744 745 746 747 748 749 750 751 753 754 755 756 757 758 759 760 \
	761 762 763 764 768 769 770 771 772 773 774 775 776 778 779 780 781 782 \
	783 784 785 786 787 788 789 790 791 792 795 796 798 900 901 902 903 904 \
	905 906 907 908 909 910 936 937"

#1 afinderr -213 /opt/aubit/aubit4glsrc/help/help_ecpg.iem: ECPG_MISSING_INDICATOR          -213   	
#73 core dump in libecpg.so: 
#91,100,234 put.cpc:155: ERROR: invalid datatype 'PUT'
#106 prog.cpc:138: ERROR: syntax error at or near "1"
#256 prog.cpc:133: ERROR: syntax error at or near "INTO"
#270 define a record like test1:systables.*
#|__________________________________^
#| Error at line 4, character 36
#376 core in 4glc 
#aubit 4glc list_validate_like_star.4gl -c -o list_validate_like_star.ao
#row number 1 is out of range 0..-1
#/opt/aubit/aubit4glsrc/bin/aubit: line 1: 23312 Segmentation fault      4glc list_validate_like_star.4gl -c -o list_validate_like_star.ao



#####################################################
#Expected to fail using Informix/4Js/Querix compiler
EXPECT_TO_FAIL_IFX="102 227 251 254 319 487 706"
#102,254 - dump_screen empty
#227 - all 3 compilers give different ouptput
#251 - Ifx & Q same, but Aubit different
#319 - NULL in function call not accepted by i4gl
#487 - ON KEY ("home") supported only by 4js and Aubit
#706 - (Diferent value 32) http://aubit.com/mantis/bug_view_page.php?bug_id=0000515

EXPECT_TO_FAIL_4JS="216 225 240 348 349 364 372 373 380 381 531 536 565 566 \
	573 577 626 627 628 629 630 631 632 633 634 635 636 670 675 706"

EXPECT_TO_FAIL_QUERIX="234 240 351 359 362 363 364 365 366 372 373 374 376 380 \
	381 383 385 402 404 408 421 422 461 470 471 473 475 487 516 531 538 539 544 \
	556 582 583 584 586 587 597 599 607 629 670 683 702 706"
#487 - ON KEY ("home") supported only by 4js and Aubit

######################
#Tests that currently fail because of the errors in the test itself
INVALID_TESTS="375 377 684 105 705 707 752 797 916 917 919 920 921 \
	922 923 924 925 926 927 928 929 930 931 932 933 934 935 948 949 950 951 952 \
	953 954 955 956 957 958 959 964	966 284 918 \
	938 939 940 941 942 943 944 945 946 947 282 498 499 288 291"
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
#934 284 no test files
#956 missing 4gl file
#282 testtable does not exist in the database
#498,499 no keys.in
#288 291 no files

#testing function invocation:
test_func() {
x=$1
	echo "Inside test_func"
	echo "received param 1 = $x"
	echo "CONSOLE_PROMPT_TESTS=$CONSOLE_PROMPT_TESTS"
	XXX="testing"
	echo "XXX=$XXX"
	echo "exiting test_finc"
	
}


