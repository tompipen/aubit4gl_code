#!/bin/sh
#####################################################
#This script is used to update Aubit 4gl web site
#and on-line doccumentation from Aubit CVS on
#SourceForge.
#
#Note: this script is INTERACTIVE, and will prompt you for
#your SourceForge CVS password: use expect if you need to
#make it non-interactive
#####################################################
cd $HOME
cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4glwww
rm -rf $WWW/*
cd aubit4glwww
cp * $WWW
cd $WWW
cvs -dafalout@cvs1:/cvsroot/aubit4gl co aubit4gldoc
echo "Aubit web site refreshed from CVS"