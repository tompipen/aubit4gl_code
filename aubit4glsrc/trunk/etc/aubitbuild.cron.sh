##########################################################################
#
# This script performs Aubit related tasks on a daily (or nightly) basis,
# like make and upload automatic nightly builds, run regression tests,
# and create code documentation.
#
# It invokes aubitbuild.sh script to perform most tasks.
# You can use 'make install.cron' to install it
#
##########################################################################

#!/usr/bin/bash
#/usr/bin/run-parts: /etc/cron.daily/aubitbuild: bad interpreter: No such file or directory
#on Linux /bin/sh on CygWin /usr/bin/bash
#!/bin/sh

############################
#Stamp the cron log with date
date >> /tmp/cron_run.log

############################## Settings ##################################

############################
#Read global Bash profile
if test -f "/etc/bashrc"; then 
	. /etc/bashrc > /dev/null
fi

############################
#Read global shell profile
if test -f "/etc/profile"; then
	. /etc/profile >> /dev/null
fi

############################
#Read global aubitrc
if test -f "/etc/opt/aubit4gl/aubitrc" ; then
	. /etc/opt/aubit4gl/aubitrc > /dev/null
fi

############################
#Platform dependent settings
if test "$COMSPEC" = ""; then
	#UNIX
	DO_BUILD=1
	DO_DOXY=1
	DO_TESTS=1
	MAILADDR=andrej@falout.org
	MAILADDR_CC=root@falout.org
	#MAIL_SUBJECT="Aubit Linux nightly build"
	MAIL_SUBJECT="Aubit_Linux_nightly_build"
	if test "$AUBITDIR" = ""; then 
		#we should have got that by reading aubitrc ?!
		AUBITDIR="/opt/aubit/aubit4glsrc"
	fi
	SH=/bin/bash
	#Quote problem - works from cmd line but not from cron:
	#MAILCMD="mail -s \"$MAIL_SUBJECT\" -c $MAILADDR_CC $MAILADDR"
	MAILCMD="mail -s '$MAIL_SUBJECT' -c $MAILADDR_CC $MAILADDR"
	MAILCMD_TEST="mail -s 'Aubit_Linux_Test_Results' -c $MAILADDR_CC $MAILADDR"
	FGLC="4glc"
else
	#Windows
	DO_BUILD=1
	DO_DOXY=0
	DO_TESTS=0
	MAILADDR=andrej@aptiva
	MAILADDR_CC=root@aptiva
	MAIL_SUBJECT="Aubit Windows nightly build"
	if test "$AUBITDIR" = ""; then 
		#we should have got that by reading aubitrc ?!
		AUBITDIR="/usr/src/aubit/aubit4glsrc"
	fi
	SH=/usr/bin/bash	
	MAILCMD="ssmtp -FCronDaemonIstation $MAILADDR"
	MAILCMD_TEST="ssmtp -FCronDaemonIstation $MAILADDR"
	FGLC="4glc.exe"	
fi

############################
#Contains output of running this cron script
LOGFILE=/tmp/aubitbuild-cron.log

############################
#Contain output of running aubitbuild.sh
MAILFILE=/tmp/aubitbuild.mail

############################
#Contatins email we compose out of LOGFILE and MAKEFILE and then send
TMPMAIL=/tmp/aubitbuild-tmp.mail

############################
#command to execute to build Aubit
BUILD_CMD="$AUBITDIR/bin/aubitbuild.sh"

############################
#Parameters to pass to BUILD_CMD
PARAMS="-anyday"

############################
#Debugging of this script
DEBUG=1

############################
#Need database ID/password for test scripts (run_tests)
#Should be read by run_tests using aubit-config
#if test "$SQLUID" = "" ; then
#	SQLUID=username
#	SQLPWD=password
#fi
#export SQLUID SQLPWD

#####################
#Initialize log files
	echo "-------------------------------------" > $LOGFILE
	date >> $LOGFILE

	echo "-------------------------------------" > $MAILFILE
	date >> $MAILFILE

############################## begin ##################################

if test "$DO_BUILD" = "1"; then 

	#######################################################
	#Check for aubitbuild.sh script, recreate it if missing
	
	#Make sure we are using th latest aubitbuild.sh
	cd $AUBITDIR; ./config.status --file bin/aubitbuild.sh
	
	if [ ! -f $BUILD_CMD ]; then
		if test "$DEBUG" = "1"; then
			echo "$BUILD_CMD missing...running autoconf/configure"
		fi
		echo "$BUILD_CMD missing...running autoconf/configure"  >> $LOGFILE
		cd $AUBITDIR
		if [ ! -f $AUBITDIR/configure ]; then
			autoconf > /tmp/autoconf.log  2>&1
		fi
	
		./configure > /tmp/configure.log 2>&1
	
		if [ ! -f $BUILD_CMD ]; then
			echo 'Failed to run configure. Stop.' >> $LOGFILE
			echo 'See /tmp/autoconf.log and /tmp/configure.log' >> $LOGFILE
			if test "$DEBUG" = "1"; then 
				echo "$BUILD_CMD still missing...autoconf/configure failed"
			fi
		fi
	else
		if test "$DEBUG" = "1"; then 
			echo "OK (1): $BUILD_CMD"
		fi
		echo "OK (1): $BUILD_CMD"  >> $LOGFILE		
	fi
	
	######################
	#Run the build script
	if [ -f $BUILD_CMD ]; then
		if test "$DEBUG" = "1"; then 
			echo "About to invoke '$SH $BUILD_CMD $PARAMS'"
		fi
		echo "About to invoke '$SH $BUILD_CMD $PARAMS'"  >> $LOGFILE
		###############################
		$SH $BUILD_CMD $PARAMS >> $MAILFILE 2>&1
		#$SH $BUILD_CMD
		###############################
		RET=$?
		if test "$RET" != "0"; then
			if test "$DEBUG" = "1"; then
				echo "Command returned code $RET"		
			fi
			echo "Command returned code $RET" >> $LOGFILE
			BUILD_FAILED=1
		else
			if test "$DEBUG" = "1"; then
				echo "Completed succesfully, see $MAILFILE for details"		
			fi
			echo "Completed succesfully, see $MAILFILE for details" >> $LOGFILE	
		fi
	else
		echo "ERROR: $BUILD_CMD is missing" >> $LOGFILE
	fi
	
	##################
	#Finalize log file
	date >> $LOGFILE
	echo "-------------------------------------" >> $LOGFILE
	echo >> $LOGFILE
	
	##################
	#Prepare the email
	if test "$DEBUG" = "1"; then
		echo "Preparing email..."
	fi
	if test "$COMSPEC" != ""; then
		#On Windows we cannot specify subject on command line
		echo "subject: \"$MAIL_SUBJECT\"" > $TMPMAIL
	else
		rm -f $TMPMAIL
	fi
	if test -f "$LOGFILE"; then 
		cat $LOGFILE >> $TMPMAIL
	else
		echo "$LOGFILE file was missing" >> $TMPMAIL
	fi
	if test -f $MAILFILE; then
		cat $MAILFILE >> $TMPMAIL
	else
		echo "$MAILFILE file was missing" >> $TMPMAIL
	fi
	echo "Download: http://aubit4gl.sourceforge.net/files/aubitdownload.htm" >> $TMPMAIL
	echo "EOF" >> $TMPMAIL
	
	##################
	#Send the email
	echo "Sending mail with cmd: cat $TMPMAIL -pipe- $MAILCMD" >> $TMPMAIL
	cat $TMPMAIL | $MAILCMD > /tmp/mailcmd.log 2>&1
	if test "$DEBUG" = "1"; then
		echo "Email sent."
	fi
	
	if test "$BUILD_FAILED" = "1"; then
		#No point of trying to rebuild when first one failed
		#cant run tests on failed build
		#no point in running Doxy on failed build
		if test "$DEBUG" = "1"; then
			echo "Exiting after failed buid."
		fi
		exit
	fi
fi
############################### testing ################################

if test "$DO_TESTS" = "1"; then 
	cd $AUBITDIR
	#re-build local Aubit source code, if needed
	if test ! -f "$FGLC"; then 
		if test "$DEBUG" = "1"; then
			echo "Re-building Aubit source code tree."
		fi
		
		if [ ! -f $AUBITDIR/Makefile ]; then
			echo "$AUBITDIR/Makefile missing, running config.status..."
			cd $AUBITDIR; ./config.status
		fi
		
		#We are NOT invoking nightly build here!!!! Just re-build compiler
		#$SH $BUILD_CMD $PARAMS > /tmp/postbuild.log 2>&1
		cd $AUBITDIR; make > /tmp/postbuild.log 2>&1
		RET=$?
		echo "Finished postbuild at `date`" >> /tmp/postbuild.log 2>&1
		if test $RET != "0"; then
			echo "Command returned code $RET, see /tmp/postbuild.log" >> $LOGFILE
			if test "$DEBUG" = "1"; then
				echo "Command returned code $RET, see /tmp/postbuild.log"
			fi
			exit $RET
		else
			if test "$DEBUG" = "1"; then
				echo "Re-build successful."
			fi
		fi
	fi

	#Make sure compiler is installed for tests
	cd $AUBITDIR; make install > /tmp/postinstall.log 2>&1	
	RET=$?
	if test $RET != "0"; then
		echo "Install failed"
	fi
	
	#run tests
	if test "$DEBUG" = "1"; then
		echo "Running tests..."
	fi
	make test.build > /tmp/aubittest.log 2>&1 
	##################
	#Send the email
	if test "$DEBUG" = "1"; then
		echo "Sending test results email...."
	fi
	cat /tmp/aubittest.log | $MAILCMD_TEST  > /tmp/mailTestcmd.log 2>&1
	if test "$DEBUG" = "1"; then
		echo "Test results email sent."
	fi
fi

############################### Doxy ###################################

if test "$DO_DOXY" = "1"; then 
	if test "$DEBUG" = "1"; then
		echo "Creating Doxy documentation..."
	fi
	cd $AUBITDIR 
	make doxy > /tmp/aubitdoxy.log 2>&1
	RET=$?
	if test "$RET" != "0"; then 
		echo "ERROR: make doxy failed - see /tmp/aubitdoxy.log"
	else
		echo "Created Aubit Doxy documentation (make doxy) See /tmp/aubitdoxy.log for details"
	fi
fi

#Create separate cron script for OneMaxx - rebuild, test, Doc4GL

####################################### EOF ############################


