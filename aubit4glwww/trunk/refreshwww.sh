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
#
#
#####################################################

export CVS_RSH=
#export CVSROOT=':pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
export CVSROOT=':pserver:anonymous@cvs1.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
#autosfcvsanonpasswd

cd $HOME

#this needs password:
#cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4glwww
cvs -z8 checkout aubit4glsrc

rm -rf $WWW/*
cd aubit4glwww
cp -r * $WWW
cd $WWW

#this needs password
#cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4gldoc
cvs -z8 checkout aubit4gldoc

echo "Aubit web site refreshed from CVS"
sh refresh_hy4gl.sh

