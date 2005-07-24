:	"@(#)install.sh	6.14 89/11/14"
#
#	@(#)FGLBLD Version 6.12 (04/04/1990)
#	@(#)Installation script

uid=`id | sed 's/uid=\([0-9][0-9]*\)[^0-9].*/\1/'`
case $uid in
0)	: OK;;
*)	echo "You must be root to install this software" >&2
	exit 1;;
esac

:	${FGLBLDDIR:=/opt/fglbld}
#:	${FGLBLDBIN:=${INFORMIXDIR:-/opt/informix}/bin}
:	${FGLBLDBIN:=${FGLBLDBIN:-/usr}/bin}
:	${FGLUSR:=informix}
:	${FGLGRP:=informix}
:	${FGLTYPE:=RDS}

export FGLBLDDIR FGLBLDBIN FGLUSR FGLGRP FGLTYPE

echo "

Installing FGLBLD Informix-4GL Code Generator Software

Version: FGLBLD Version 6.12 (04/04/1990)

The software will be installed as follows:

    Public Directory:     $FGLBLDBIN
    Private Directory:    $FGLBLDDIR
    Owner:                $FGLUSR
    Group:                $FGLGRP
    Type:                 $FGLTYPE

If this is incorrect, hit the INTERRUPT key.
If this is correct,   hit the RETURN    key.

"

trap '
echo "Set: FGLBLDBIN to define the location of the public scripts"
echo "     FGLBLDDIR to define the directory for FGLBLD files"
echo "     FGLUSR    to define the owner"
echo "     FGLGRP    to define the group"
echo "     FGLTYPE   to RDS or C4GL as appropriate"
exit 1' 2 3

read x
echo

trap 2 3
if grep "^$FGLUSR:" /etc/passwd >/dev/null
then	: OK
else	echo "User $FGLUSR does not exist in /etc/passwd" >&2
	exit 1
fi

if grep "^$FGLGRP:" /etc/group >/dev/null
then	: OK
else	echo "Group $FGLGRP does not exist in /etc/group" >&2
	exit 1
fi

# Check existence of installation tools
for file in instfile mkscript mkpath
do
	if [ -f $file ]
	then
		eval $file=$file
	elif [ -f ./etc/$file ]
	then
		eval $file=./etc/$file
	elif [ -f $FGLBLDDIR/etc/$file ]
	then
		eval $file=$FGLBLDDIR/etc/$file
	else
		echo "$0: $file missing" >&2
		exit 1
	fi
done
chmod +x $instfile $mkscript

if [ ! -d $FGLBLDDIR ]
then
	echo "Creating $FGLBLDDIR"
	$mkpath        $FGLBLDDIR ||
	{ echo "$0: failed to create $FGLBLDDIR" >&2 ; exit 1 ; }
	chmod 755     $FGLBLDDIR
	chgrp $FGLGRP $FGLBLDDIR
	chown $FGLUSR $FGLBLDDIR
fi

if [ ! -d $FGLBLDBIN ]
then
	echo "Creating $FGLBLDBIN"
	$mkpath        $FGLBLDBIN ||
	{ echo "$0: failed to create $FGLBLDBIN" >&2 ; exit 1 ; }
	chmod 755     $FGLBLDBIN
	chgrp $FGLGRP $FGLBLDBIN
	chown $FGLUSR $FGLBLDBIN
fi

# Check existence of file list
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

PATH=.:$FGLBLDDIR/etc:$PATH

# Install programs and files
cat $objfile |
while read file source link owner group perms
do
	case "$file" in
	\#*)	: Comment
		continue;;
	"")	: Blank
		continue;;
	esac
	if [ $owner = - ] ; then owner=$FGLUSR ; fi
	if [ $group = - ] ; then group=$FGLGRP ; fi
	if [ $source = directory ]
	then
		echo "Installing directory $FGLBLDDIR/$file"
		if [ ! -d $FGLBLDDIR/$file ]
		then
			mkdir $FGLBLDDIR/$file
		fi
		chmod $perms $FGLBLDDIR/$file
		chgrp $group $FGLBLDDIR/$file
		chown $owner $FGLBLDDIR/$file
	elif [ $source = deleted ]
	then
		rm -f $FGLBLDDIR/$file
	elif [ $source = link ]
	then
		if [ ! -f $FGLBLDDIR/$link ]
		then
			echo "$0: missing link file $FGLBLDDIR/$link" >&2
			echo "$0: please report this to your supplier" >&2
			exit 1
		fi
		rm -f $FGLBLDDIR/$file
		ln $FGLBLDDIR/$link $FGLBLDDIR/$file
	elif [ $source = configure ]
	then
		$mkscript $file >tmp.$$
		mv tmp.$$ $link
		#echo "installing to $FGLBLDBIN $instfile $link"
		$instfile $link $FGLBLDBIN $owner $group $perms
	else
		$instfile $file $FGLBLDDIR $owner $group $perms
	fi
done
