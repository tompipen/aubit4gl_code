#!/bin/sh

export CVS_RSH=
#export CVSROOT=':pserver:anonymous@cvs.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'
export CVSROOT=':pserver:anonymous@cvs1.aubit4gl.sourceforge.net:/cvsroot/aubit4gl'


cd $WWW

#this needs password:
#cvs -dafalout@cvs1:/cvsroot/aubit4gl co hy4gl/doc
cvs -z8 checkout hy4gl/doc


echo "Hy4gl doccuments refreshed from CVS"

