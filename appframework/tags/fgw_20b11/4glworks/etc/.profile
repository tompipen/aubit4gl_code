# 	Generalized 4glWorks application start-up script
#
#	Author:	Marco Greco (marco@4glworks.com), Catania, Italy
#
#	Initial release: Oct 92
#	Current release: Nov 97
#
#	No warranty expressed or implied.  All risks connected to the use of
#	this file remain solely on you. This file is being made available on
#	an "AS IS" basis, and the author or any party anyhow connected to him
#	are not liable for any damage or loss arising from the use of this file.
#
#	Permission is hereby granted to use and modify, with the exception
#	of this notice, this file, but not to reproduce, sell, distribute,
#	publish, circulate it or any portion thereof, and in any format it can
#	be devised (including but not limited to library files, object code or
#	pcode) without the written consent of the author.
#
#	Permission for any use other than personal or time limited evaluation is
#	subject to payment of applicable license fees to the author.
#
#	Title, ownership rights and intellectual property remain in the author.
#
#	Use of this file constitutes agreement with the above terms and
#	conditions.

#
#  setup informix env vars / make your own adjustments
#
INFORMIXDIR=${INFORMIXDIR:-/usr/informix}
PATH=$PATH:$INFORMIXDIR/bin
#
DBPATH=${DBPATH:-`dirname $0`}
if [ $DBPATH = "." ]
then
    DBPATH=`pwd`
fi
modname=`basename $DBPATH`
export INFORMIXDIR PATH DBPATH

if [ -n "$1" -a -f "$DBPATH/$modname.$1" ]
then
    ext=$1
else
    for i in 4ge 4gi
    do
	if [ -f "$DBPATH/$modname.$i" ]
	then
	    ext=$i
	    break
	fi
    done
fi
case "$ext" in
  4ge)
    exec $DBPATH/$modname.4ge
    ;;
  4gi)
    exec fgwgo $DBPATH/$modname.4gi
    ;;
  *)
    echo 'No application found'
    ;;
esac
