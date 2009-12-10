#!/bin/ksh

HOSTNAME=`hostname`
RGWDFILE=$1
SUFFIX=${RGWDFILE##*.}
FILEPATH=`pwd`

	if [ x$SUFFIXx = 'xx' ]
	then
        echo "Filetype is $SUFFIX"
    else
        echo "No filename suffix...adding .4gl"
		RGWDFILE=$1.4gl
	fi


	if [ -f $FILEPATH/$RGWDFILE ]
	then
		echo "file is $FILEPATH/$RGWDFILE"

        #if that file already have loacation info, we must first
        #remove it:




        #now, insert location info, so that GWD c script can
        #extract it and pass it to the rcp to return file:
		echo "#orig_location:$FILEPATH" > /tmp/$RGWDFILE
		echo "#orig_filename:$RGWDFILE" >> /tmp/$RGWDFILE
		echo "#orig_hostname:$HOSTNAME" >> /tmp/$RGWDFILE
		echo "#orig_username:$LOGIN" >> /tmp/$RGWDFILE
		cat $FILEPATH/$RGWDFILE >> /tmp/$RGWDFILE

		#copy generated file to client PC
		rcp /tmp/$RGWDFILE $FGLSERVER:c:/temp

		#we can use winexec() from d4gl but this works fine
		rsh $FGLSERVER shellexec c:/temp/$RGWDFILE

	else
        echo $FILEPATH/$RGWDFILE does NOT exists.
	fi

