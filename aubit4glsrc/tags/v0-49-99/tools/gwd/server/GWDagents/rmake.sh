#!/bin/ksh
#########################################################################
###function Params
#########################################################################

if [ $# -lt 3 ]
then
    echo -$1-$2-
    echo "rmake.sh [sourcefile.ext | prgname.toc/m] SYS AREA .Aborting.."
    exit
fi

FILE=$1
PROGSYSTEM=$2
AREA=$3

SUFFIX=${FILE##*.}
FILEBASE=${FILE%.*}
FILEBASE=${FILEBASE##*/}


#########################################################################
function EnvLog
#########################################################################
{
echo === this is output from set command in the moment of rmake execution ======= > $HOME/rshell.set
echo =========================================================================== >> $HOME/rshell.set
set >> $HOME/rshell.set
whoami >> $HOME/rshell.set
echo ==================================== END ================================== >> $HOME/rshell.set

}

#########################################################################
function EnvSetScripts
#########################################################################
{

. /etc/profile > /dev/null
. $HOME/.profile  > /dev/null
sw -q $AREA > /dev/null
sys $PROGSYSTEM > /dev/null

}


#########################################################################
function RunIt
#########################################################################
{
	    CheckMakefile

        #example: OBJBASE=/property1/release/gui/obj
        #example: OBJDIR=/property1/release/gui/obj/AN/src
        # Jmk shuld do this (cd), but is does not...
        cd $OBJDIR

        echo "Running Jmk -f $MAKENAME "

        rm $HOME/all_err.err
                #to prevent listing irrelevant error files:
        #rm $BASEDIR/$PROGSYSTEM/src/*.err

        Jmk -f $MAKENAME

        ls -1 $OBJDIR/*.err > $HOME/all_err.err

    if [ -s $HOME/all_err.err ]
	then
        #if make was unsuccsessfull ,offer to open
        # (example: /property1/release/gui/obj/AN/src/r_profinv.log)
        # log file with complete output of make proccess
        # OBJDIR=/property1/release/gui/obj/COM/src

        echo "set MAKE_OUTPUT=$OBJDIR/$MAKEBASE.log"
        echo "set MAKE_ERR=ERROR"
        echo "set PATH_BASE=$OBJDIR"

        let i=1
        for file in $OBJDIR/src/*.err
        do
                XX=`basename $file`

                #SUFFIX=${FILE##*.}
                filebase=${file%.*}
                filebase=${filebase##*/}

                echo "SET ERR_FILE$i=$filebase"
                SETERREXT="SET ERR_EXT$i=xxx"


                if [ -s $BASEDIR/$PROGSYSTEM/src/$filebase.4gl ]
            	then
                    SETERREXT="SET ERR_EXT$i=4gl"
                fi

                if [ -s $BASEDIR/$PROGSYSTEM/src/$filebase.per ]
            	then
                    SETERREXT="SET ERR_EXT$i=per"
                fi

                if [ -s $BASEDIR/$PROGSYSTEM/src/$filebase.5gl ]
            	then
                    SETERREXT="SET ERR_EXT$i=5gl"
                fi

                echo $SETERREXT

                let i=i+1
        done
    else
        # there was no err files, but
        #also check for existance of $MAKEBASE.42r in
        #BINDIR=/property1/release/gui/drs6000/COM/bin
        # if make fail at link time, there will be no err files,
        # but the 42r will not be created

        if [ -s $BINDIR/$MAKEBASE.42r ]
        then
            # ok: 42r was genetated, link was ok
        else
            #cat $OBJDIR/$MAKEBASE.log > $HOME/all_err.err
            echo "set MAKE_OUTPUT=$OBJDIR/$MAKEBASE.log"
            echo "set MAKE_ERR=ERROR"
            echo "set PATH_BASE=$OBJDIR"
            echo "SET ERR_FILE1=LINK_ERROR"
        fi
    fi

}

#########################################################################
function FindMakefile
#########################################################################
{
    grep -il $FILE $BASEDIR/$PROGSYSTEM/src/makedir/*.toc > /tmp/rmake.tmp

    if [ -s /tmp/rmake.tmp ]
	then
		FILEBASE=`head -1 /tmp/rmake.tmp|sed 's/\.toc//g'`
		FILEBASE=${FILEBASE##*/}
        MAKEBASE=$FILEBASE
        MAKENAME=$BASEDIR/$PROGSYSTEM/src/makedir/$FILEBASE.m
        echo Source file $1 belongs to $FILEBASE.42r / .toc /.m
        echo "SET MAKEPRG=$FILEBASE.42r"
	else
		echo $1 "Not Found in any .toc file of system $2"
		rm /tmp/rmake.tmp
		exit
	fi
}


#########################################################################
function CheckMakefile
#########################################################################
{

	if [ -f $MAKENAME ]
	then
            echo "$MAKENAME exists..."
    else
            echo "ERROR ! MAKEFILE $MAKENAME NOT FOUND !"
            exit
    fi

}

#################################### MAIN ###############################

#     Params          #Check and assign paramiters passed to the script
     EnvSetScripts   #Call ususual scripts that are used to set environment
#    EnvSetManual    #Set Environment Variables lost because of remote execution
#    . /home/users/andrejf/simenv.sh #Load environment variables from file
     EnvLog          #Dump current environment into file for debbuging


if [ x$VG_DIRx = 'xx' ]
then
    echo PD_DIR still not set !! Aborting..
    exit
fi

if [ $SUFFIX = '42r' ] ||  [ $SUFFIX = 'm' ] || [ $SUFFIX = 'toc' ]
then
#BASEDIR=/property1/release/gui/src
#        /property1/release/gui/src/RT/RT/src/makedir/paramiter.m NOT FOUND !
    MAKENAME=$BASEDIR/$PROGSYSTEM/src/makedir/$FILEBASE.m
    RunIt
fi

### for 4gl and per we need to find toc first :

if [ $SUFFIX = '4gl' ] || [ $SUFFIX = '5gl' || [ $SUFFIX = 'per' ] ]
then
    echo SUFFIX is $SUFFIX
    FindMakefile
    RunIt
fi

####
exit
####

############################# end of rrun.sh ############################
