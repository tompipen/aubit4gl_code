#	CONFIGURE.sh  -  framework configuration tool
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Nov 99
#	Current release: Jan 02
#
#	This library is free software; you can redistribute it and/or
#	modify it under the terms of the GNU Lesser General Public
#	License as published by the Free Software Foundation; either
#	version 2.1 of the License, or (at your option) any later version.
#
#	This library is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#	Lesser General Public License for more details.
#
#	You should have received a copy of the GNU Lesser General Public
#	License along with this library; if not, write to the Free Software
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

AWK=${AWK:-/usr/bin/awk}
framepath=`dirname $0`

#
# get parms
#
while [ $# -gt 0 ]
do
    case $1 in
    -clean)
	clean=1
	;;
    -f)
        shift
        framepath=$1
        ;;
    *)
        echo 'invalid parms...'
        exit 1
        ;;
    esac
    shift
done
tool=c4gl
ver=`$tool -V 2>&-`
if [ -z "$tool" ]
then
    tool=fglpc
    ver=`$tool -V 2>&-`
fi
ver=`echo "$ver" | $AWK '/Version/ { print substr($NF, 1, 1); exit }'`
case "$ver" in
  6|7)
	echo 'Adjusting code for 4gl 6.00 & above'
	sed -e 's/--free/free/g' $framepath/source/idefl.4gh > ch$$
	mv ch$$ $framepath/source/idefl.4gh
	;;
  4)
	echo 'Adjusting code for 4gl 4.1x & 4.20'
	sed -e 's/SQ_freecurs.*free/SQ_freecurs	--free/g'\
	    $framepath/source/idefl.4gh > ch$$
	mv ch$$ $framepath/source/idefl.4gh
	;;
  *)
	echo 'Cannot identify 4gl version - leaving code untouched'
	;;
esac
#
#  adjust sql interpreter source
#
rm $framepath/source/csqd* 2>&-
rm $framepath/objcode/csq*.o $framepath/pcode/csq*.o 2>&-
if [ x"$clean" != x ]
then
    exit
elif [ "$tool" = "fglpc" -o "$1" = "-force" ]
then
    echo 'Adjusting sql interpreter for rds'
    dir=rds
elif [ "$ver" = 4 ]
then
    echo 'Adjusting sql interpreter for c4gl 4.1x & 4.20'
    dir=4gl4
else
    echo 'Adjusting sql interpreter for c4gl 6.00 & above'
    dir=4gl6
fi
for file in $framepath/source/$dir/*
do
    ln $file $framepath/source
done
