#!/bin/sh

export HOME=/home/users/a/af/afalout
export WWW=/home/groups/a/au/aubit4gl/htdocs


cd $WWW

if [ "$1" = "-anon" ]
then
	export CVS_RSH=
	export CVSROOT=':pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
	cvs -z8 checkout hy4gl/doc
else
	#this needs password:
	cvs -dafalout@cvs1:/cvsroot/aubit4gl co hy4gl/doc
fi


echo "Hy4gl doccuments refreshed from CVS"

