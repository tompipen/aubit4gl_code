#!bin/sh
I4GLLIST=
II4GLLIST=
if [ -n "$DEBUG" ];then
	DDEBUG="-DDEBUG"
	echo "`basename $0`: WARNING - preprocessor define DEBUG is set." >&2
else
	DDEBUG=
fi

if [ -n "$XACTIONS" ];then
	DXACTIONS="-DXACTIONS"
	echo "`basename $0`: WARNING - preprocessor define XACTIONS is set." >&2
else
	DXACTIONS=
fi

for a in $*
do
	case $a in
	*.4gl)
		I4GLLIST=$I4GLLIST" "$a
		;;
	*)
		ARGLIST=$ARGLIST" "$a
		;;
	esac
done

for fn in $I4GLLIST
do
	if [ -r "$fn" ];then
		TMPFN=pp${fn}
		cc -E $DDEBUG $DXACTIONS -I$BASEDIR/include $fn > $TMPFN
		if [ $? -ne 0 ];then
			echo "`basename $0`: file \"$fn\" preprocessor error" >&2
			exit 2
		else
			II4GLLIST=$II4GLLIST" "$TMPFN
		fi
	else
		echo "`basename $0`: file \"$fn\" not found/readable" >&2
	fi 
done

CMDSTR="c4gl $ARGLIST $II4GLLIST"
#echo $CMDSTR
eval $CMDSTR
RETVAL=$?
BASEII4GLLIST=`echo $I4GLLIST | sed -e "s/\.4gl//g"`
for bfn in $BASEII4GLLIST
do
	if [ -s "pp${bfn}.o" ];then
		mv pp${bfn}.o ${bfn}.o
	fi
	if [ -s "pp${bfn}.c" ];then
		mv pp${bfn}.c ${bfn}.c
	fi
	if [ -s "pp${bfn}.ec" ];then
		mv pp${bfn}.ec ${bfn}.ec
	fi
	if [ -s "pp${bfn}.err" ];then
		mv pp${bfn}.err ${bfn}.err
	fi
done

exit $RETVAL
