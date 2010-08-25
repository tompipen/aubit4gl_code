#!/bin/ksh

#########################################################################
#                         rd4gl.sh
#########################################################################

if [ x$1x = 'xx' ]
then
    echo -$1-$2-
    echo "rd4gl.sh Area .Aborting.."
    exit
fi

. /etc/profile > /dev/null
#echo "HOME is $HOME before exec of .profile"
#. /home/users/andrejf/.profile >  /dev/null
#HOME is /home/users/andrejf before exec of .profile
. $HOME/.profile >  /dev/null
sw -q $1 > /dev/null
FFCONAME="$FFCONAME ($1)"
export FFCONAME
#cd $HOME/d4gl
#./fglrun d4gl.42r &

echo D4GL_EDITOR is $D4GL_EDITOR

DBPATH=$DBPATH:$HOME/d4gl
export DBPATH
$HOME/d4gl/fglrun $HOME/d4gl/d4gl.42r &
#fglrun: Cannot open the file 'd4gl.42m' for reading or writing.


############################# end of rd4gl.sh ########################
