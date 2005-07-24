:	"@(#)$Id: mksource.sh,v 1.2 2002-06-16 07:36:07 afalout Exp $"
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
srcfile=./etc/fglbld-SRC.lst
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
#FIXME: we probably don't need this functionality any more:
#sed -e 's/#.*//' -e '/^[ 	]*$/d' $srcfile |
#while read file source
#do
	#if [ ! -f $file ]
	#then
		#echo "Cannot find $file - retriving it ..."

		#FIXME: what is rfile command supposed to do?
		#rfile=$(rfile $source)
		#if [ -f $rfile ]
		#then
		#	${CO} ${COFLAGS} -p $source | ./mkversion > $file
		#else
		#   no "get" command on my planet...
		#	${GET} ${GFLAGS} -p $source | ./mkversion >$file
		#fi
		#chmod 444 $file
	#fi
#done
