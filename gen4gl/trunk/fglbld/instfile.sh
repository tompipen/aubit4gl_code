:	"@(#)instfile.sh	6.1 89/08/08"
#
#	Target: Proposal Tracking System
#	Install file 
#	Put in directory belonging to owner, group and with permissions set

case $# in
5)	if [ ! -f $1 ]
	then
		#we may not have debugger allways present:
		if [ "$1" != "bin/fgldb" ]
        then
			echo "$0: $1 not found"
        fi
        exit 1
	fi
	if [ ! -d $2 ]
	then
		echo "$0: $2 is not a directory"
		exit 1
	fi
	mv $1 tmp.$$	# Save new file (just in case it is in correct place)
	rm -f $2/$1	# Remove existing destination file
	mv tmp.$$ $2/$1	# Store new file in correct place
	set -e
	chmod $5 $2/$1
	chgrp $4 $2/$1
	chown $3 $2/$1
	;;
*)	echo "Usage: $0 file dir owner group perms" >&2
	exit 1;;
esac
