:	"@(#)$Id: mkpath.sh,v 1.1.1.1 2002-06-15 05:07:06 afalout Exp $"
#
#	@(#):PRODUCT:
#
#	Make all directories down to named directory

arg0=`basename $0 .sh`
usage(){
echo "Usage: $arg0 [-o owner] [-g group] [-p perms] directory [...]" >&2
exit 1
}

set -- `getopt o:g:p: "$@"`

while [ $# -gt 0 ]
do
	case $1 in
	--)	shift; break;;
	-o) owner=$2;;
	-g) group=$2;;
	-p) perms=$2;;
	-*) usage;;
	*)	break;;
	esac
	shift 2
done

case $# in
0)	usage;;
esac

for directory in $*
do
	echo $directory
done |
awk -F/ ' { string=""
			pad=""
			for (i = 1; i <= NF; i++) {
				string=string pad $i
				if (string != "") print string
				pad="/"
			}
		  }' |
sort -u |
while read directory
do
	if [ ! -d $directory ]
	then
		mkdir $directory
		[ -z "$perms" ] || chmod $perms $directory
		[ -z "$group" ] || chgrp $group $directory
		[ -z "$owner" ] || chown $owner $directory
	fi
done
