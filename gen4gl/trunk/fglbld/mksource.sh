:	"@(#)$Id: mksource.sh,v 1.1.1.1 2002-06-15 05:06:54 afalout Exp $"
#
#	Collect source files for FGLBLD from around system

: ${GET:=get}
: ${CO:=co}
: ${GFLAGS:='-s'}
: ${COFLAGS:='-q'}

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
		echo $srcfile
		${GET} ${GFLAGS} $FGLBLDDIR/SCCS/s.$srcfile
		srcfile=./$srcfile
	else
		echo "$0: $srcfile missing" >&2
		exit 1
	fi
fi

# Collect source files
sed -e 's/#.*//' -e '/^[ 	]*$/d' $srcfile |
while read file source
do
	if [ ! -f $file ]
	then
		echo $file
		rfile=$(rfile $source)
		if [ -f $rfile ]
		then ${CO} ${COFLAGS} -p $source | ./mkversion > $file
		else ${GET} ${GFLAGS} -p $source | ./mkversion >$file
		fi
		chmod 444 $file
	fi
done
