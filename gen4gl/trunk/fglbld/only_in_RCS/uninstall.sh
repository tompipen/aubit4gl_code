:   "@(#)$Id: uninstall.sh,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $"
#
#   @(#):FGLBLDVER:
#   @(#)De-installation script

uid=`id | sed 's/uid=\e([0-9][0-9]*\e)[^0-9].*/\e1/'`
case $uid in
0)  : OK;;
*)  echo "You must be root to de-install this software" >&2
    exit 1;;
esac

:   ${FGLBLDDIR:=/usr/fglbld}
:   ${FGLBLDBIN:=${INFORMIXDIR:-/usr/informix}/bin}
:   ${FGLTYPE:=RDS}

export FGLBLDDIR FGLBLDBIN FGLUSR FGLGRP FGLTYPE

echo "

De-installing FGLBLD Informix-4GL Code Generator Software

Version: :FGLBLDVER:

The software will be removed from:

    Public Directory:     $FGLBLDBIN
    Private Directory:    $FGLBLDDIR
    Type:                 $FGLTYPE

If this is incorrect, hit the INTERRUPT key.
If this is correct,   hit the RETURN    key.

"

trap '
echo "Set: FGLBLDBIN to define the location of the public scripts"
echo "     FGLBLDDIR to define the directory for FGLBLD files"
echo "     FGLTYPE   to RDS or C4GL as appropriate"
exit 1' 2 3

read x
echo

trap 2 3

if [ ! -d $FGLBLDDIR ]
then
	echo "$FBLBLDDIR is not a directory!" >&2
	exit 1
fi

if [ ! -d $FGLBLDBIN ]
then
	echo "$FBLBLDBIN is not a directory!" >&2
	exit 1
fi

# Check existence of file list
case $FGLTYPE in
RDS)    ext=RDS;;
C4GL)   ext=4GL;;
*)      echo "$arg0: unknown type $FGLTYPE -- should be RDS or C4GL" >&2
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

# Install programs and files
sed -e 's/#.*//' -e '/^[ 	]*$/d' $objfile |
while read file source link owner group perms
do
    case "$file" in
    \e#*)   : Comment
        continue;;
    "") : Blank
        continue;;
    esac
    if [ $source = directory ]
    then
		echo "De-installing $file" >&2
		echo "$file"
    elif [ $source = deleted ]
    then
        rm -f $FGLBLDDIR/$file
    elif [ $source = link ]
    then
        rm -f $FGLBLDDIR/$file
    elif [ $source = configure ]
    then
		rm -f $FGLBLDBIN/$link
    else
        rm -f $FGLBLDDIR/$file
    fi
done |
sort -r |
xargs rmdir 2>/dev/null

echo "De-installation complete"
