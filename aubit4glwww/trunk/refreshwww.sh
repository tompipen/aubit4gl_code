#!/bin/sh

#####################################################
#This script is used to update Aubit 4gl web site
#and on-line doccumentation from Aubit CVS on
#SourceForge.
#
#All changes to Aubit web site should be done like this:
#1) check out "aubit4glwww" and/or "aubit4gldoc" branch from SF CVS
#2) make your changes on that checked out code/pages/pictures
#3) commit your local copy to SF CVS
#4) log in to SF shell account
#5) execute this script
#
#Note: this script is INTERACTIVE, and will prompt you for
#your (mine, if you don't change my login name - "afalout") SourceForge 
#CVS password: use "expect" if you need to
#make it non-interactive
#
#You must run this script when logged in SF shell account.
#
#Aubit web site on SF shell account is loccated at:
#/home/groups/a/au/aubit4gl/htdocs
#
#Andrej Falout's HOME at SF shell account is located at:
#/home/users/a/af/afalout
#
#TODO: make it non-interactive
#TODO: create PHP page that will execute non-interactive version
#   of this script when user click on the link; protect
#   this page with username/password, using .htaccess file
#
##!/bin/sh
#export CVS_RSH=
#export CVSROOT=':pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
#cvs -z8 checkout aubit4glsrc
#
#
#####################################################


echo "just type 'cvs update -d' instead"
exit

#ANONCVS=$1
#UPDATE=$2

ANONCVS=-anon
UPDATE=-upd


export HOME=/home/users/a/af/afalout
export WWW=/home/groups/a/au/aubit4gl/htdocs

if [ "$ANONCVS" = "-anon" ]
then
	export CVS_RSH=
	export CVSROOT=':pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
else
	autosfcvsanonpasswd
fi

if [ "$UPDATE" = "-upd" ]
then
	cvs update -d 2>&1
	RET=$?
	if test "$RET" != "0"
	then
    	echo "Error on cvs update"
	    exit $RET
    fi

	echo "Aubit web site updated from CVS"

    #FIXME: what about aubit4gldoc and hy4gl ?


    exit
fi

exit

###################################################################
# Stuff below this line should no longer be used
###################################################################



#We don't have the right to cd out of $WWW when running from PHP
cd $HOME
RET=$?
if test "$RET" != "0"
then
    echo "Error on cd HOME ($HOME)"
    exit $RET
fi

if [ "$ANONCVS" = "-anon" ]
then
	cvs -z8 checkout aubit4glwww
else
	#this needs password:
	cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4glwww
fi

RET=$?
if test "$RET" != "0"
then
    echo "Error on checkout aubit4glwww"
    exit $RET
fi



rm -rf $WWW/*
RET=$?
if test "$RET" != "0"
then
    echo "Error on rm -rf $WWW/*"
    exit $RET
fi

cd aubit4glwww
RET=$?
if test "$RET" != "0"
then
    echo "Error on cd aubit4glwww"
    exit $RET
fi

cp -r * $WWW
RET=$?
if test "$RET" != "0"
then
    echo "Error on cp -r * $WWW"
    exit $RET
fi

echo "Aubit web site pages (aubit4glwww) refreshed from CVS"

cd $WWW
RET=$?
if test "$RET" != "0"
then
    echo "Error on cd WWW ($WWW)"
    exit $RET
fi

if [ "$ANONCVS" = "-anon" ]
then
	cvs -z8 checkout aubit4gldoc
else
	#this needs password
	cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4gldoc
fi
RET=$?
if test "$RET" != "0"
then
    echo "Error on 	checkout aubit4gldoc"
    exit $RET
fi

echo "Aubit web site doccumentation (aubit4gldoc) refreshed from CVS"

sh refresh_hy4gl.sh $ANONCVS
RET=$?
if test "$RET" != "0"
then
    echo "Error on 	sh refresh_hy4gl.sh $ANONCVS"
    exit $RET
fi

