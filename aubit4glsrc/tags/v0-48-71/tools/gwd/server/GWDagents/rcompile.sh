#!/bin/ksh
########################### rcompile.sh #################################

#########################################################################
###function Params
#########################################################################
###{
#echo "Params..."

if [ x$1x = 'xx' ]
then
    echo -$1-$2-
    echo "rrun.sh sourcefile.ext SYS .Aborting.."
    exit
fi
if [ x$2x = 'xx' ]
then
    echo -$1-$2-
    echo "rrun.sh sourcefile.ext SYS .Aborting.."
    exit
fi

FILE=$1
PROGSYSTEM=$2
PATHTOSRC=$3

#set local variables:
#AREA=property1
AREA=vip2
PPATH=/$AREA/release/gui/src
SUFFIX=${FILE##*.}
FILEBASE=${FILE%.*}
FILEBASE=${FILEBASE##*/}
###}

#########################################################################
function EnvLog
#########################################################################
{
echo === this is output from set command in the moment of rrun execution ======= > $HOME/rshell.set
echo =========================================================================== >> $HOME/rshell.set
set >> $HOME/rshell.set
whoami >> $HOME/rshell.set
echo ==================================== END ================================== >> $HOME/rshell.set

}

#########################################################################
function EnvSetScripts
#########################################################################
{
# to nul to prevent display of UX:stty: ERROR: Invalid argument
. /etc/profile > /dev/null
#echo "Calling sw.set..."
#. /u1/cm/bin/sw.set > nul
#echo ...sw.set end...Calling .profile...
. /home/users/andrejf/.profile  > /dev/null
#echo ...profile end...Calling sw -q xxxx_relJ.gui...



if [ $PROGSYSTEM = 'dummy' ]
then
    #skip system switching and environment, file is in users homedir
    #and does not belong to any program system
    XYX=dummy
else
    #sw -q prop_relJ.gui
    sw -q vip_relJ.gui > /dev/null  > /dev/null
    #echo ...end of sw -q xxx_relJ.gui...Calling sys $PROGSYSTEM...
    # to nul to prevent display of DBPATH
    sys $PROGSYSTEM > /dev/null  > /dev/null
    #echo ...end of sys $PROGSYSTEM...
fi

}

#########################################################################
function EnvSetManual
#########################################################################
{
#echo "PATH is" $PATH

#Display needed environment after attempt to set them with scripts
#echo PD_DIR is -$PD_DIR-
#echo FGLRUN is -$FGLRUN-
#echo DBPATH is -$DBPATH-

#Manualy set environment that is not already set

PD_DIR=/$AREA/release/gui/drs6000 export PD_DIR
#for financial apps use VG_DIR instead of PD_DIR
VG_DIR=/vip2/release/gui/drs6000

FGLRUN=/$AREA/release/gui/drs6000/RUN/bin/vip_run export FGLRUN
FGLDIR=/u1/2.02.1e6l6  export FGLDIR
PATH=$FGLDIR/bin:$PATH export PATH
INFORMIXDIR=/u3/informix/4.14-5.02 export INFORMIXDIR
DBPATH=/$AREA/release/gui.db:/vip1/base.db:/vip1/base.db:/vip1/base/sql:/property1/base.db:/property1/releaSe/gui/drs6000:/property1/base/sql:/crap export DBPATH

#echo DBPATH is -$DBPATH-

}

#################################### MAIN ###############################
#    echo "Main..."

#     Params          #Check and assign paramiters passed to the script
     EnvSetScripts   #Call ususual scripts that are used to set environment
#    EnvSetManual    #Set Environment Variables lost because of remote execution
#    . /home/users/andrejf/simenv.sh #Load environment variables from file


#     PATH=$PATH:$HOME/bin:$HOME       #add path if needed

     DBPATH=$DBPATH:$PATHTOSRC         #add Dbpath to original location
                                       #of sourcefile for globals files

     DBPATH=$DBPATH:$HOME/job_post     #add additional DBpath if needed

     EnvLog          #Dump current environment into file for debbuging

if [ x$VG_DIRx = 'xx' ]
#if [$PD_DIR -z]
then
    echo PD_DIR still not set !! Aborting..
    exit
fi

#    cd ~
#    cd cmpl

    rm $HOME/cmpl/$FILEBASE.err

    cd $PATHTOSRC #execute cmpl in original sorcefile dir because globals
                  #files thai might be in that dir

    if [ $SUFFIX = '4gl' ]
    then
            #Informix P-code
            #fglpc -p $HOME/cmpl $HOME/cmpl/$FILEBASE

            #Informix Dinamic4gl/4Js P-code
            fgl2p $HOME/cmpl/$FILEBASE.$SUFFIX

    fi

    if [ $SUFFIX = 'per' ]
    then
            #Informix form compiler
            #form4gl -p $HOME/cmpl/$FILEBASE $HOME/cmpl

            #Informix Dinamic4gl/4Js form compiler
            fglform $HOME/cmpl/$FILEBASE
    fi

    echo "SET COMP_EXT=$SUFFIX"
    echo "SET COMP_FILE=$FILEBASE"

	if [ -f $HOME/cmpl/$FILEBASE.err ]

    then
        echo "SET COMPILE=ERROR"
    else
        echo "SET COMPILE=OK"
    fi



####
exit
####

############################# end of rcompile.sh ############################
