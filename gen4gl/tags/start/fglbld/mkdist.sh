:	"@(#)mkdist.sh	6.5 89/11/14"
#
#	@(#)FGLBLD Version 6.12 (04/04/1990)
#	Make binary distribution

: ${FGLBLDDIR:=.}

DISTRIBUTION=$FGLBLDDIR/Distribution

case "$1" in
-c)	check=yes
	mkchk=-n;;
"")	check=no;;
*)	echo "Usage: $0 [-c]" >&2
	exit 1;;
esac

# Remove the existing distribution directory
if [ $check = no ]
then
	rm -fr $DISTRIBUTION >/dev/null 2>&1

	# Check that there is a distribution directory (it may still exist)
	if [ ! -d $DISTRIBUTION ]
	then
		mkdir $DISTRIBUTION
		chmod 755 $DISTRIBUTION
	fi
fi

# Check existence of file list
:	${FGLTYPE:=RDS}

case $FGLTYPE in
RDS)	ext=RDS;;
C4GL)	ext=4GL;;
*)		echo "$arg0: unknown type $FGLTYPE -- should be RDS or C4GL" >&2
		exit 1
esac

objfile=fglbld.$ext
if [ ! -f $objfile ]
then
	if [ -f ./etc/$objfile ]
	then
		objfile=./etc/$objfile
	elif [ -f $FGLBLDDIR/$objfile ]
	then
		objfile=$FGLBLDDIR/$objfile
	elif [ -f $FGLBLDDIR/etc/$objfile ]
	then
		objfile=$FGLBLDDIR/etc/$objfile
	else
		echo "$0: $objfile missing" >&2
		exit 1
	fi
fi

cat $objfile |
while read file type link owner group perms
do
	case "$file" in
	\#*)	: Comment
		continue;;
	"")	: Blank
		continue;;
	esac

	if [ $type = directory ]
	then
		if [ $check = yes ]
		then
			continue
		fi
		if [ ! -d $DISTRIBUTION/$file ]
		then
			mkdir $DISTRIBUTION/$file
			chmod 755 $DISTRIBUTION/$file
		fi
		continue
	fi

	if [ $type = deleted ]
	then
		continue
	fi

	if [ $type = link ]
	then
		continue
	fi

	source=$file
	if [ ! -r $source ]
	then
		source=`basename $file`
		if [ ! -r $source ]
		then
			echo "$0: $file not found" >&2
			if [ $check = no ]
			then
				exit 1
			else
				continue
			fi
		fi
	fi

	echo $DISTRIBUTION/$file
	if [ $check = no ]
	then
		cp $source $DISTRIBUTION/$file
		chmod $perms $DISTRIBUTION/$file
	fi

done
