#this script will collect various information to help Aubit team developers
#identify the source of the bug

if test "$1" = "" || test "$1" = "--help" || test "$1" = "-help"; then
	echo ""
	echo "Aubit compiler bug report uttility. Usage:"
	echo "  abug.sh <progname>"
	echo "Attach created bug report file to yoru bug report."
	echo ""
fi

###############
#Set defaults
PROG=$1
BASEPROG=`basename $PROG`
SUMMARY=summary.out
OUTFILES="aubit-config.out set.out $SUMMARY"

###############
#Collect summary info
echo "Summary for bug report " > $SUMMARY
echo "Program name: $PROG " >> $SUMMARY
aubit 4glc -Vfull >> $SUMMARY

###############
#Collect current Aubit configuration
#what is -ae swithch?
aubit-config -a > aubit-config.out 2>&1

###############
#Collect info from environment
set > set.out 2>&1

###############
#Run the program:
rm -f debug.out
export DEBUG=ALL
$PROG 2> $BASEPROG.out


###############
#See which files are available:
if test -f debug.out; then
    OUTFILES="$OUTFILES debug.out"
else
	echo "debug.out file was not created" >> $SUMMARY
fi
if test -f $BASEPROG.out; then
    OUTFILES="$OUTFILES $BASEPROG.out"
else
	echo "$BASEPROG.out file was not created" >> $SUMMARY
fi
if test -f $BASEPROG.4gl; then
    OUTFILES="$OUTFILES $BASEPROG.4gl"
else
	echo "$BASEPROG.4gl file was not found" >> $SUMMARY
fi
if test -f $BASEPROG.c; then
    OUTFILES="$OUTFILES $BASEPROG.c"
else
	echo "$BASEPROG.c file was not found" >> $SUMMARY
fi
if test -f $BASEPROG.h; then
    OUTFILES="$OUTFILES $BASEPROG.h"
else
	echo "$BASEPROG.h file was not found" >> $SUMMARY
fi

###############
#Finish summary file
echo "Files included: $OUTFILES " >> $SUMMARY

###############
#Create bug report archive
tar -cvzf bugreport-$BASEPROG.tgz $OUTFILES

echo ""
echo "Bug report compiled - please log it with Aubit bug tracker at:"
echo "http://sourceforge.net/tracker/?group_id=32409&atid=405150"
echo "Attach created file (bugreport-$BASEPROG.tgz) to the report"
echo ""
echo "If you want your bug report to be processed promptly:"
echo "* Be detailed and complete in your report. 'It's not working' does not help."
echo "* If at all possible, include MINIMAL abstract of 4GL source code that can"
echo "  still be used to reproduce reported bug. Attempt to reduce example code ."
echo "  to less then 100 lines of 4GL source code."
echo "* If your code uses database to:
echo "    - compile, provide a SQL DDL for your db, FOR TABLES REFERENCED."
echo "    - run, provide a SQL DDL and data export FOR TABLES USED."
echo "    - if you are able to reproduce bug against SQLite, attach Sqlite db file."
echo "* If your code uses .per form files, add them to the bugreport-$BASEPROG.tgz"
echo "* Mailing lists are for discussion - DO NOT SEND BUG REPORTS THERE."
echo ""
echo " Thank you for reporting bugs - Aubit project development team."
echo ""
echo ""


