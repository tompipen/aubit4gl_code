:	"@(#)$Id: mkfest.sh,v 1.1.1.1 2002-06-15 05:06:54 afalout Exp $"
#
#	@(#):FGLBLDVER:
#	@(#)Create current Manifest

: ${GET:=get}
: ${GFLAGS:='-s'}

:	${FGLBLDDIR:=.}

# Check existence of source definition file
srcfile=fglbld.src
if [ ! -f $srcfile ]
then
	if [ -f $FGLBLDDIR/etc/$file ]
	then
		srcfile=$FGLBLDDIR/etc/$srcfile
	elif [ -f $FGLBLDDIR/SCCS/s.$srcfile ]
	then
		echo $srcfile
		${GET} ${GFLAGS} $FGLBLDDIR/SCCS/s.$srcfile
		srcfile=./$srcfile
	else
		echo "$0: $srcfile missing" >&2
		exit 1
	fi
fi

sed -e 's/#.*//' -e '/^[ 	]*$/d' $srcfile |
{
echo "#############################################################"
echo "# @(#)Manifest for :FGLBLDVER:"
echo "# @(#)This file is not complete unless the last line reads:"
echo "# @(#)Manifest complete."
echo "# @(#)The line above must appear twice."
echo "#############################################################"
echo "# This file contains the result of running what(1) on all"
echo "# the source used to make :FGLBLDVER:"
echo "# Use it to check that you have received the correct material"
echo "#############################################################"
echo "# If you have received a binary-only distribution, you can"
echo "# still use this file to check that your distribution was"
echo "# built from the correct source.  You can run what on all"
echo "# the files in your distribution, and they should all have"
echo "# the same version as in this Manifest.  (Exception: form"
echo "# files cannot be given a version stamp reliably)."
echo "#############################################################"
echo
while read file source
do
	if [ ! -f $file ]
	then
		echo "$0: $file absent" >&2
		exit 1
	else
		what $file
		echo
	fi
done
echo "#############################################################"
echo "# @(#)Manifest complete."
echo "#############################################################"
} >$FGLBLDDIR/Manifest

exit 0
