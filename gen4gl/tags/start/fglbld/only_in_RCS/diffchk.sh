:	"@(#)$Id: diffchk.sh,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $"
#
#	Test code under Test for differences with current directory

for file in $*
do
	if [ ! -f $file ]
	then
		echo $0: cannot locate $file in "\`.'" >&2
		continue
	fi
	if [ ! -f Test/$file ]
	then
		if [ ! -f Test/*/$file ]
		then
			echo $0: cannot locate $file under Test >&2
			continue
		else
			tfile=Test/*/$file
		fi
	else
		tfile=Test/$file
	fi
	echo $file
	diff $file $tfile
done

