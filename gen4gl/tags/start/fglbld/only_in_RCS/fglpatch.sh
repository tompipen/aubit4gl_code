:	"@(#)$Id: fglpatch.sh,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $"
#
#	Apply fix to gtu_xxxxx code

for file in $*
do
	echo $file
	if [ ! -w $file ]
	then	
		echo	$file not writable >&2
		continue
	fi
	ed - $file <<!
/^	OPEN c_update USING/;i
	WHENEVER ERROR CONTINUE
.
/^	FETCH c_update INTO/;a
	WHENEVER ERROR STOP
.
/^	OPEN c_current USING/;i
	WHENEVER ERROR CONTINUE
.
/^	END IF/;a
	WHENEVER ERROR STOP
.
w
!
done
