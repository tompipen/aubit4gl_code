#!/bin/ksh
#########################################################################
###function Params
#########################################################################

if [ $# -lt 2 ]
then
    echo -$1-$2-
    echo "rgrep.sh \"search string\" AREA [SYS] [filetype]. Aborting.."
    exit
fi

SEARCH_STRING=$1
AREA=$2
PROGSYSTEM=$3
FILETYPE=$4
EXT1="*gl"
EXT2="*.per"

    . /etc/profile > /dev/null
    . $HOME/.profile  > /dev/null
    sw -q $AREA > /dev/null

    if
        [ x"$PROGSYSTEM"x == "xx" ]
    then
        #sys NOT specified
        ADD_PATH="*/src/"
    else
        ADD_PATH=$PROGSYSTEM/src/
    fi

    rm /tmp/rgrep.out > /dev/null

    if
        [ x"$FILETYPE"x == "xx" ]
    then
        # user did NOT specify filetypes, search *gl (5gl&4gl) and per...
        #echo 2a -i "$SEARCH_STRING" $ADD_PATH
        #echo 2b -i "$SEARCH_STRING" $ADD_PATH"buildA"/
        grep -i "$SEARCH_STRING" $ADD_PATH$EXT1 > /tmp/rgrep.out
        grep -i "$SEARCH_STRING" $ADD_PATH$EXT2 >> /tmp/rgrep.out
        grep -i "$SEARCH_STRING" $ADD_PATH"buildA"/$EXT1 >> /tmp/rgrep.out
        grep -i "$SEARCH_STRING" $ADD_PATH"buildA"/$EXT2 >> /tmp/rgrep.out
    else
        #echo FILETYPE is -$FILETYPE-
        FILETYPE="*$FILETYPE"
        #echo FILETYPE is -$FILETYPE-
        grep -i "$SEARCH_STRING" $ADD_PATH$FILETYPE >> /tmp/rgrep.out
        grep -i "$SEARCH_STRING" $ADD_PATH"buildA"/$FILETYPE >> /tmp/rgrep.out
    fi

    if [ -s /tmp/rgrep.out ]
	then
        echo "SET RGREP_RESULT=YES"
        echo "SET RGREP_OUT=/tmp/rgrep.out"
	else
        echo "SET RGREP_RESULT=NO"
        echo "SET RGREP_OUT="
    fi

####
exit
####

############################# end of rgrep.sh ############################
