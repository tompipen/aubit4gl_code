#!/bin/ksh
#
#	@(#)$Id: mknmd.sh,v 1.1 2002-11-28 06:40:47 afalout Exp $
#
#	@(#)SQLFMT Version 14 (1998-11-04)
#
#	Create a Non-Modifiable Source Distribution
#	KSH-only: uses test operator -ot (older than)

arg0=`basename $0 .sh`

usage(){
	echo "Usage: $arg0 [-f] source object nmd-file [mkversion]" >&2
	exit 1
}

remove="no"
case "$1" in
-f)	remove=yes
	shift;;
-*) usage;;
esac

if [ $# -ne 4 -a $# -ne 3 ]
then
	usage
fi

: ${ADMIN:="admin"}		# SCCS
: ${GET:="get"}			# SCCS
: ${GFLAGS:="-s"}		# SCCS
: ${CO:="co"}			# RCS
: ${COFLAGS:="-q"}		# RCS
: ${CP:="cp -p"}		# POSIX.2
: ${MKPATH:="mkdir -p"}	# POSIX.2
: ${RM:="rm -f"}		# POSIX.2

SOURCEDIR=${1}
OBJECTDIR=${2}
CNTRLFILE=${3}
MKVERSION=${4:-./mkversion}

if [ ! -x $MKVERSION ]
then
	echo "$arg0: cannot locate executable file $MKVERSION" >&2
	exit 1
fi

sed -e 's/[     ]*#.*//' -e '/^[    ]*$/d' \
	-e 's/$Revision':' \(.*\) \$$/\1/' \
	$CNTRLFILE |
{
while read gfile sfile version notes
do

	case $gfile in	# Handle variable setting lines
	*=*)	eval $gfile $sfile $version
			continue;;
	esac

	eval target=$OBJECTDIR/$gfile
	if [ ! -f $target ]
	then
		tgtdir=`dirname $target`
		[ -d $tgtdir ] || ${MKPATH} $tgtdir
	fi

	eval sfile=$sfile
	case $sfile in
	/*) # Absolute
		source=$sfile;;
	*)  # Relative
		eval source=$SOURCEDIR/$sfile
		;;
	esac

	if [ $remove = yes ]
	then
		: File will be removed anyway
	elif [ -f $target -a ! $target -ot $source ]
	then
		# Time stamp on target is newer than (or the same as) $source.
		# Condition was [... $target -nt $source ] but this doesn't work
		# well with "cp -p".
		continue
	fi

	if [ ! -f $source ]
	then
		echo "$0: cannot find $source" >&2
		continue
	fi

	if [ "x$version" = "x-" ]
	then
		# Distributing non-SCCS file (e.g. FLEX-generated C source)
		$RM $target
		echo "$target $version"
		$CP $source $target
		chmod 444 $target
	elif val -r$version $source >/dev/null 2>&1
	then
		case `basename $target` in
		s.*)
			# Distributing SCCS s-file
			if [ $source != $target ]
			then
				echo "$target $version"
				$RM $target
				$CP $source $target
			fi
			;;
		*)
			# Distributing extracted file
			echo "$target $version"
			$RM $target
			if [ "$notes" = "binary" ]
			then
				${GET} -r$version ${GFLAGS} -p $source >$target
			else
				${GET} -r$version ${GFLAGS} -p $source |
				$MKVERSION >$target
			fi
			;;
		esac
		chmod 444 $target
	elif ${CO} -p -r$version $source >/dev/null 2>&1
	then
		case `basename $target` in
		*,v)
			# Distributing RCS file
			if [ $source != $target ]
			then
				echo "$target $version"
				$RM $target
				$CP $source $target
			fi
			;;
		*)
			# Distributing extracted file
			echo "$target $version"
			$RM $target
			if [ "$notes" = "binary" ]
			then
				${CO} -r$version ${COFLAGS} -p $source >$target
			else
				${CO} -r$version ${COFLAGS} -p $source |
				$MKVERSION >$target
			fi
			;;
		esac
		chmod 444 $target
	else
		echo "$0: invalid SCCS/RCS file $source (version $version)" >&2
	fi

done
} | awk '{ printf("%-40s %s\n", $1, $2); }'
