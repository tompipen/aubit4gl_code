:	"@(#)$Id: mkshar.sh,v 1.1.1.1 2002-06-15 05:06:54 afalout Exp $"
#
#	Create shell archive (on stdout) from fglbld.src

: ${GET:=get}
: ${GFLAGS:='-s'}

:	${FGLBLDDIR:=.}

if [ ! -d $FGLBLDDIR ]
then
	echo "Creating $FGLBLDDIR"
	mkdir         $FGLBLDDIR
	chmod 755     $FGLBLDDIR
fi

# Check existence of source definition file
srcfile=fglbld.src
if [ ! -f $srcfile ]
then
	if [ -f $FGLBLDDIR/etc/$file ]
	then
		srcfile=$FGLBLDDIR/etc/$srcfile
	elif [ -f $FGLBLDDIR/SCCS/s.$srcfile ]
	then
		${GET} ${GFLAGS} $FGLBLDDIR/SCCS/s.$srcfile
		srcfile=./$srcfile
	else
		echo "$0: $srcfile missing" >&2
		exit 1
	fi
fi

tmp=${TMPDIR:-/tmp}/mkshar.$$
trap "rm -f $tmp ; exit 1" 1 2 3 13 15

# Collect source files
cat $srcfile |
while read file source
do
	case "$file" in
	\#*)	: Comment
			continue;;
	"")		: Blank
			continue;;
	*)		echo $file;;
	esac
done >$tmp

shar `cat $tmp`
rm -f $tmp
exit 0
