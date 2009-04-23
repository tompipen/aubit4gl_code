#!/bin/ksh

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
. /etc/profile > nul
#echo "Calling sw.set..."
#. /u1/cm/bin/sw.set > nul
#echo ...sw.set end...Calling .profile...
. /home/users/andrejf/.profile
#echo ...profile end...Calling sw -q xxxx_relJ.gui...
#sw -q prop_relJ.gui
sw -q vip_relJ.gui > nul
#echo ...end of sw -q xxx_relJ.gui...Calling sys $PROGSYSTEM...
# to nul to prevent display of DBPATH
sys $PROGSYSTEM > nul
#echo ...end of sys $PROGSYSTEM...
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

#########################################################################
function RunIt
#########################################################################
{
	if [ -f $PPATH/$PROGSYSTEM/src/$FILEBASE.par ]
	then
#        echo $FILEBASE.par existes...executing pi..
#		cd $PD_DIR
        cd $VG_DIR
#        echo Running command: $FGLRUN pi -O $PROGSYSTEM/bin/$FILEBASE.42r
#        echo ...

        $FGLRUN pi -O $PROGSYSTEM/bin/$FILEBASE.42r
	else
#        echo $FILEBASE.par does NOT exists..
#		cd $PD_DIR
        cd $VG_DIR
#        echo Running command: $FGLRUN $PD_DIR/$PROGSYSTEM/bin/$FILEBASE.42r
#        echo Running command: $FGLRUN $VG_DIR/$PROGSYSTEM/bin/$FILEBASE.42r
#        echo ...

        $FGLRUN $VG_DIR/$PROGSYSTEM/bin/$FILEBASE.42r
    fi

    echo ...run command executed, returning...
}

#################################### MAIN ###############################
#    echo "Main..."

#     Params          #Check and assign paramiters passed to the script
     EnvSetScripts   #Call ususual scripts that are used to set environment
#    EnvSetManual    #Set Environment Variables lost because of remote execution
#    . /home/users/andrejf/simenv.sh #Load environment variables from file
     EnvLog          #Dump current environment into file for debbuging


if [ x$VG_DIRx = 'xx' ]
#if [$PD_DIR -z]
then
    echo PD_DIR still not set !! Aborting..
    exit
fi


if [ $SUFFIX = '42r' ]
then
    echo File suffix is 42r...
	ParCheck
else
#	echo $PROGSYSTEM
    grep -il $FILE $PPATH/$PROGSYSTEM/src/makedir/*.toc >/tmp/rrun.tmp

    if [ -s /tmp/rrun.tmp ]
	then
		FILEBASE=`head -1 /tmp/rrun.tmp|sed 's/\.toc//g'`
		FILEBASE=${FILEBASE##*/}
        echo Source file $1 belongs to $FILEBASE.42r / .toc
		RunIt        ##execute the $FGLRUN $FILEBASE.42r
	else
		echo $1 "Not Found in any .toc file of system "$2
		rm /tmp/rrun.tmp
		exit
	fi
fi

rm /tmp/rrun.tmp

####
exit
####

############################# end of rrun.sh ############################