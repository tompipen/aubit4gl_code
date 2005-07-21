#!/bin/sh
#############################################################################
# Script to perform automatic backup of TikiWiki web site.
# - Creates backup database dump file using choosen method
# - Creates backup of all files in Tiki dir that changed since installation
# - Then downloads both to local machine
# $Id: tiki_backup.sh,v 1.4 2005-07-21 11:20:50 afalout Exp $
# Please report bugs to andrej@dontspam.falout.org
#-----------------------------------------------------------------------------
# Prerequisites:
#
#	- scp (to retrive backup files from remote server)
#	- expect (To run commands that need password at run-time)
#	- bzip2 (To compress backup file)
#	- Script to perform scp automatically, suplying username/password (SCP_SCRIPT)
#		use --make-scp option to create it
#	- ssh login on the TikiWiki server
#
#	Only for 'tiki' method:
#	- lynx (To trigger TikiWiki to create a backup)
#   - Lynx pre-recorded command keys script (LYNX_SCRIPT) (use --record option 
#		to create it)
#
#	Only for 'mysql' method (DEFAULT)
#   - ssh (to remotely execute mysqldump)
#	- Script to perform ssh automatically, suplying username/password (SSH_SCRIPT)
#		use --make-ssh option to create it
#   - mysqldump on TikiWiki server
#	- login information for mysql database
#
# Installation:
#	1: Check that all listed prerequisites exist on your system
#	2: Make this script executable (chmod +x ...)
#	3: Check that scipts required for choosen method are created. Use
#		--record | --make-scp | --make-ssh options to create them
#	4: run this script from command line, to verify it works on your system
#		Example: ./tiki_backup.sh --tiki-site=aubit --db-pass=MyPass
#	5: To create script in /etc/cron.daily directory to invoke it with
#		same flags as tested in step 4, add --cron flags to flags used in
#		step 4
#
# Methods for performing backup:
#	1. Mysql (DEFAULT)
#		Uses SSH to run mysqldump on remote system, then downloads created
#		backup file using SCP
#	2. Tiki 
#		Uses lynx web browser to trigger a TikiWiki web page that creates
#		backup file, then downloads created file using SCP
#
#
# Todo:
# - silent does not work with Tiki method (lynx hangs when redirected to file)
# - remove backups older then x days from web site, created by Tiki method
# - Find a way to kill lynx if it does not exit in X seconds (no response)
# - Enable wget as alternative to scp, for use on sites where user does not
#	have a ssh loging (tiki method only)
#
#############################################################################

############################# Global Settings ###############################

DOMAIN=`hostname -d`
if test -f "/etc/custom/tiki_backup-$DOMAIN.conf"; then
	. "/etc/custom/tiki_backup-$DOMAIN.conf"
else
	if test -f "/etc/tiki_backup-$DOMAIN.conf"; then
		. "/etc/tiki_backup-$DOMAIN.conf"
	else
		#Defaults that should work for most Linux installations, used in 
		#absense of .conf files tested for above. To override, preferably create 
		#one of configuration files as tested for above. If you instead choose
		#to modify this script, be aware that all changes will be lost on 
		#next update of this script.
		
		#Directory to put created Lynx script:
		#Default: "/usr/local/bin"
		#LYNX_SCRIPT_DIR="/usr/local/bin"
		
		#Directory to put SCP and SSH expect scripts"
		#Default: "/usr/local/share"
		#SCP_BASE="/usr/local/share"
		
		#Location to put created backup files in; if it does not
		#exist, it will be created
		#Default: "/var/spool/backups/TikiWiki"
		#BACKUP_BASE="/var/spool/backups/TikiWiki"
		
		#How many days to keep backups
		#Default: 30
		#KEEP_DAYS=30
		
		#Are the backups older then KEEP_DAYS to be deleted or not (yes|no)
		#Default: yes
		#REMOVE_OLD="yes"
		
		#Minimum number of backups to ALLWAYS keep, regardles of how old they are
		#This is to prevent an system clock error from deleting all backups we have
		#Default: 12
		#ALLWAYS_KEEP=12
		
		#Do we have a SSH login on TikiWiki server; if no, we must use 'tiki'
		#method of creating database backup, and use wget to download it.
		#Note that without SSH login, we cant backup Tiki files
		#Default: yes
		#HAVE_SSH_ACCOUNT=yes
		
		if test "$SH_DEBUG" = "1"; then
			echo "NOTE: using default settings"
		fi
	fi
fi

#################################
function site_list () {
#################################
#Define a list of recognised sites

	#all sites we know about. When adding sites, add it both here and in 'case'
	#statement below
	ALL_SITES="aubit apps"
}

#################################
function site_settings () {
#################################
#Set configuration that is site dependent. To add more sites to backup,
#modify this function ONLY

	case $TIKI_SITE in
		aubit) 
			PROJECT="aubit4gl"
			DOMAIN="sourceforge.net"
			SITE="$PROJECT.$DOMAIN"
			TIKI_PATH="/tiki" 	#Path to root of tiki installation, relative to Apache htdocs root
			SITE_URL="http://$SITE$TIKI_PATH"
			SITE_PATH="/home/groups/a/au/$PROJECT/htdocs$TIKI_PATH"
			DB_NAME="$PROJECT"
			DB_USER="$PROJECT"
			DB_HOST="mysql-a.$DOMAIN"
			;;
		apps)
			PROJECT="apps4gl"
			DOMAIN="sourceforge.net"
			SITE="$PROJECT.$DOMAIN"
			TIKI_PATH=""
			SITE_URL="http://$SITE"
			SITE_PATH="/home/groups/a/ap/$PROJECT/htdocs$TIKI_PATH"
			DB_NAME="$PROJECT"
			DB_USER="$PROJECT"
			DB_HOST="mysql-a.$DOMAIN"
			;;
		*) error "Site $TIKI_SITE not recognised"
			exit 4
	esac

}

##############################################################################
#
#								FUNCTIONS
#          User should not need to change anything below this line
#
##############################################################################

#########################################
function remove_old_tiki_backups () {
#########################################
# - remove backups older then 7 days from web site, created by Tiki method

	debug "TODO: remove backups older then 7 days from web site, created by Tiki method"

}

#########################################
function remove_old_local_backups () {
#########################################
# - remove backups older then 30 days from local machine

	BACKUPS_PATH="$BACKUP_BASE/$SITE"
	cd "$BACKUPS_PATH"
	
	ALL_CNT=`ls $SITE-*.*.bz2 | wc -l`
	ALL_LIST=`ls $SITE-*.*.bz2`
	
	JOIN="-a"
	TIME_TEST="-ctime"

	FIND_OLD="find . -type f $JOIN -name \"$SITE-*.*.bz2\" $JOIN $TIME_TEST $KEEP_DAYS -print"
	#echo "FIND CMD=$FIND_OLD"
	
	OLD_CNT=`eval $FIND_OLD | wc -l`
	OLD_LIST=`eval $FIND_OLD`
	
	if test "$SH_DEBUG" = "1"; then
		echo "All: $ALL_CNT Older then $KEEP_DAYS days: $OLD_CNT" 
		echo "--------------------- All -----------------------------"
		ls -al $SITE-*.*.bz2
		echo "-------------------- Older ----------------------------"
	fi
	
	let AFTER_DELETE=ALL_CNT-OLD_CNT
	
	if test "$AFTER_DELETE" -lt "$ALLWAYS_KEEP" ; then
		echo "WARNING:"
		echo "There are $OLD_CNT backups older then $KEEP_DAYS days, but I can't delete them"
		echo "because then there would be only $AFTER_DELETE left, which is less then"
		echo "a configured value of backups to allways keep, which is $ALLWAYS_KEEP"
		return
	fi
	
	if test "$OLD_CNT" != "0"; then
		if test "$REMOVE_OLD" != "yes"; then
			message "There are $OLD_CNT backups older then $KEEP_DAYS days, but REMOVE_OLD is set to '$REMOVE_OLD'"
		else
			echo "---------- REMOVING BACKUPS OLDER THEN $KEEP_DAYS days: ---------"
			for file in $OLD_LIST ; do
				if test "$file" != "." ; then
					ls -al $file
					rm $file
				fi
			done
		fi
	else
		debug "No backup older then $KEEP_DAYS"
	fi
}

##############################
function create_backup () {
##############################
#loop untill backup is created, usiing Tiki method

	RETRY_CNT=0
	while true ; do
		let RETRY_CNT=RETRY_CNT+1
		RESULT=0
		rm -f $PAGE_OLD
		rm -f $PAGE_NEW 
		replay_script
		if test "$RESULT" = "1"; then
			break
		else
			if test "$RETRY_CNT" = "$MAX_RETRY"; then
				error "Reached maximum number of retries ($MAX_RETRY). STOP"
				exit 1
			else
				message "Failed; retry # $RETRY_CNT ..."
			fi
		fi
	done
}

##############################
function make_scp () {
##############################
#Create expect scrip to run SCP

	read -p "Enter user name to use for scp command:"
	SCP_USER="$REPLY"
	read -p "Enter password to use for scp command:"
	SCP_PASS="$REPLY"

	echo "#!/usr/bin/expect -f" > $SCP_SCRIPT
	echo "set timeout 900" >> $SCP_SCRIPT
	echo "spawn scp -q $SCP_USER@$SITE:\$argv ." >> $SCP_SCRIPT
	echo "expect \" password:\"" >> $SCP_SCRIPT
	echo "send \"$SCP_PASS\r\"" >> $SCP_SCRIPT
	echo "expect eof" >> $SCP_SCRIPT

	chmod +x $SCP_SCRIPT
	echo "Script $SCP_SCRIPT created:"
	cat $SCP_SCRIPT
	
}

##############################
function make_ssh () {
##############################
#Create expect script to run SSH

	read -p "Enter user name to use for SSH command:"
	SSH_USER="$REPLY"
	read -p "Enter password to use for SSH command:"
	SSH_PASS="$REPLY"

	echo "#!/usr/bin/expect -f" > $SSH_SCRIPT
	echo "set timeout 900" >> $SSH_SCRIPT
	echo "spawn ssh $SSH_USER@$SITE \"\$argv\"" >> $SSH_SCRIPT
	echo "expect \" password:\"" >> $SSH_SCRIPT
	echo "send \"$SSH_PASS\r\"" >> $SSH_SCRIPT
	echo "expect eof" >> $SSH_SCRIPT

	chmod +x $SSH_SCRIPT
	echo "Script $SSH_SCRIPT created:"
	cat $SSH_SCRIPT
	
}

##############################
function replay_script () {
##############################
#Replay keystrokes using lynx browser (for Tiki method)

	debug "Running script..."
	if test "$SILENT" = "1"; then
		#WARNING: seems that lynx does not work correctly when its output is 
		#redirected to file	
		lynx "$LYNX_FLAGS" -accept_all_cookies -cmd_script=$LYNX_SCRIPT $SITE_URL $LOGCMD > /tmp/lynx_transcript.log 2>&1
	else
		lynx "$LYNX_FLAGS" -accept_all_cookies -cmd_script=$LYNX_SCRIPT $SITE_URL $LOGCMD
	fi
	 
	if ! test -f $PAGE_OLD ; then
		message "Failed to create $PAGE_OLD"
		RESULT=0
		return
	fi
	if ! test -f $PAGE_NEW ; then
		message "Failed to create $PAGE_NEW"
		RESULT=0
		return
	fi
	debug "Successfully created both pages"
	RESULT=1
	
}

#######################################
function get_new_backup_name () {
#######################################
#Determine file name of Tiki created backup file

	if test "$SH_DEBUG" = "1"; then
		echo "-------------------------------------------------------------"
		grep "remove restore" $PAGE_OLD | cut --fields=1 --delimiter="."
		echo "-------------------------------------------------------------"
		grep "remove restore" $PAGE_NEW | cut --fields=1 --delimiter="."
		echo "-------------------------------------------------------------"
	fi
	
	OLD_LIST=`grep "remove restore" $PAGE_OLD | cut --fields=1 --delimiter="."`
	NEW_LIST=`grep "remove restore" $PAGE_NEW | cut --fields=1 --delimiter="."`
	
	if test " $NEW_LIST" = "" ; then
		error "NEW_LIST is empty. STOP."
		exit 6
	fi
	
	if test "$OLD_LIST" != ""; then
		for new_backup in $NEW_LIST; do
			for old_backup in $OLD_LIST; do
				GOTIT=0
				if test "$old_backup" = "$new_backup"; then
					GOTIT=1
				fi
				if test "$GOTIT" = "0"; then
					CREATED_BACKUP="$new_backup"
					break
				fi
			done
		done
	else
		CREATED_BACKUP="$NEW_LIST"
	fi
	
	if test "$CREATED_BACKUP" != ""; then
		X=`grep "$CREATED_BACKUP" "$PAGE_NEW"`
		if test "$X" = ""; then
			error "Cannot find string $CREATED_BACKUP in $PAGE_NEW file. STOP"
			exit 4
		else
			debug "new backup is $CREATED_BACKUP"
		fi
	else
		error "Cannot determine name of just created backup. STOP"
		exit 4
	fi
}	

##################################
function debug () {
##################################
#Display handler for debug messages

	if test "$SH_DEBUG" = "1"; then
		echo "DEBUG: $1"
	fi
}

##################################
function message () {
##################################
#Display handler for normal messages

	if test "$SILENT" != "1"; then
		echo "$1"
	fi
}

##################################
function error () {
##################################
#Display handler for error messages

	echo "ERROR: $1"
}


##################################
function dl_new_backup () {
##################################
#Download created db backup file to local machine (both methods)

	if ! test -d "$BACKUPS_PATH" ; then
		mkdir -p "$BACKUPS_PATH"
	fi
	
	if test "$METHOD" = "tiki"; then
		$SCP_SCRIPT $SITE_PATH/tiki/backups/$CREATED_BACKUP*.sql > /tmp/tiki_scp.log 2>&1
		THE_RESULT=`ls ./$CREATED_BACKUP*.sql`
	else
		$SCP_SCRIPT $SITE_PATH/$CREATED_BACKUP > /tmp/tiki_scp.log 2>&1
		THE_RESULT=`ls ./$CREATED_BACKUP`
	fi

	if test "$THE_RESULT" != ""; then
		debug "Downloaded backup file: $THE_RESULT ; moving to $BACKUPS_PATH"
		mv "$THE_RESULT" "$BACKUPS_PATH"
		if test "$METHOD" = "tiki"; then
			FINAL_RESULT=`ls $BACKUPS_PATH/$CREATED_BACKUP*.sql`
		else
			FINAL_RESULT=`ls $BACKUPS_PATH/$CREATED_BACKUP`
		fi
		if test "$FINAL_RESULT" != ""; then
			debug "Success: $FINAL_RESULT"
			date_stamp=`date +%d-%m-%Y_%H-%M-%S`
			if test "$METHOD" = "tiki"; then
				mv $FINAL_RESULT $BACKUPS_PATH/$SITE-$date_stamp.sql
				bzip2 $BACKUPS_PATH/$SITE-$date_stamp.sql
			else
				mv $FINAL_RESULT $BACKUPS_PATH/$SITE-$date_stamp.sql.bz2
			fi
			ENDFILE=`ls $BACKUPS_PATH/$SITE-$date_stamp.sql.bz2`
			if test "$SILENT" != "1"; then
				message "Success: created backup file is:"
				ls -al $ENDFILE
			fi
		else
			error "Moving $THE_RESULT to $BACKUPS_PATH FAILED"
			exit 2
		fi
	else
		error "Download failed"
		exit 3
	fi
	
	if test "$SH_DEBUG" = "1"; then
		bunzip2 -c "$ENDFILE" | head
	fi
	
}


################################
function record_scrip () {
################################
#Record keystrokes needed to run lynx automatically (Tiki method only)

	lynx -accept_all_cookies -cmd_log=$LYNX_SCRIPT $SITE_URL
	echo "Finished recording to $LYNX_SCRIPT"
	
}

####################################
function ssh_mysqldump () {
####################################
#Run mysqldump remotely using ssh (mysql method)

	if test "$DB_PASS" = "" ; then
		error "--db-pass= was not specified. STOP"
		exit 3
	fi

	CREATED_BACKUP="backup.sql.bz2"
	
	CMD="mysqldump --opt --user="$DB_USER" --password="$DB_PASS" --host="$DB_HOST" $DB_NAME | bzip2 > $SITE_PATH/$CREATED_BACKUP "

	if test "$SH_DEBUG" = "1"; then	
		echo "SSH command is : "
		echo "$CMD"
	fi
	
	if test "$SH_DEBUG" = "1"; then
		$SSH_SCRIPT $CMD
	else
		$SSH_SCRIPT $CMD > /dev/null 2>&1
	fi
	
	TMPSTAT="$?"
	if test "$TMPSTAT" != "0"; then
		error "$SSH_SCRIPT returned $TMPSTAT STOP"
		exit 5
	fi
	
}

###################################
function make_cron () {
###################################
#Make scrip in daily cron using supplied flags
	CRON_DIR="/etc/cron.daily"

	if ! test -d "$CRON_DIR"; then
		error "Directory $CRON_DIR does not exit on your system. STOP"
		exit 4
	fi
	
	CMD_FLAGS=`echo $ALL_FLAGS | sed -e 's/--cron//'`
	THIS_SCRIPT=`pwd`/`basename $0`
	CMD="bash $THIS_SCRIPT $CMD_FLAGS"
	CRON_SCRIPT="$CRON_DIR/backup-$SITE.sh"
	echo $CMD > $CRON_SCRIPT
	chmod a+x $CRON_SCRIPT
	echo "Created $CRON_SCRIPT as:"
	cat $CRON_SCRIPT
	
}

#######################################
function tar_changed_files () {
#######################################
#pack all files in TikiWiki installation directory that changed after a 
#reference file into a tar file, compress, and download to local machine

LOCAL_DEBUG=0

	#List of directories that contain temporary or irrelevant files, that
	#are not needed in the case of restoreing the installation
	EXCLUDE="./templates_c ./temp ./mods/Cache ./backups ./modules/cache \
		./mods/avatars ./img/avatars './tikiwiki-*.tar.bz2' './tikiwiki-*.tar' \
		./backup.sql.bz2"
		
	#File (or directory) that has a timestamp of installation date:
	REF_FILE="./modules"

	#Name of tar file to create
	if test "$LOCAL_DEBUG" = "1"; then	
		NEW_TAR="/tmp/test/new.tar.bz2"
	else
		NEW_TAR="./new.tar.bz2"
	fi

	if test "$LOCAL_DEBUG" = "1"; then
		cd /srv/www/htdocs/tiki
	fi
	
	for skip in $EXCLUDE ; do
		#cant use -wholename since it was introduced only recently - use -path
		EX_STRING="$EX_STRING -path '$skip' -prune -o"
	done
	
	FIND_CMD="find . $EX_STRING -newer $REF_FILE -type f -print"
	
	if test "$LOCAL_DEBUG" = "1"; then	
		NEW_FILES=`eval $FIND_CMD`
	else
		#SSH_CMD="NEW_FILES=\`eval $FIND_CMD\`"
		SSH_CMD=""
	fi
	
	if test "$LOCAL_DEBUG" = "1"; then
		echo "----------------------------------------------------------------"
		echo "$NEW_FILES"
		echo "----------------------------------------------------------------"
	fi
	
	if test "$LOCAL_DEBUG" = "1"; then	
		rm -rf /tmp/test/*
	fi
	
	if test "$LOCAL_DEBUG" = "1"; then	
		tar -cjf $NEW_TAR $NEW_FILES
	else
		#SSH_CMD="$SSH_CMD; tar -cjf $NEW_TAR \$NEW_FILES"
		SSH_CMD="cd $SITE_PATH && rm -f $NEW_TAR && tar -cjf $NEW_TAR \`$FIND_CMD\`"
		
		debug "Creating archive..."
		if test "$SH_DEBUG" = "1"; then
			$SSH_SCRIPT $SSH_CMD
		else
			$SSH_SCRIPT $SSH_CMD > /dev/null 2>&1
		fi
		
		TMPSTAT="$?"
		if test "$TMPSTAT" != "0"; then
			error "$SSH_SCRIPT returned $TMPSTAT STOP"
			exit 5
		fi
	fi
	
	debug "Downloading archive..."
	$SCP_SCRIPT $SITE_PATH/$NEW_TAR >> /tmp/tiki_scp.log 2>&1
	THE_RESULT=`ls ./$NEW_TAR`

	if test "$THE_RESULT" != ""; then
		mv "$THE_RESULT" "$BACKUPS_PATH"
		FINAL_RESULT=`ls $BACKUPS_PATH/$NEW_TAR`
		if test "$FINAL_RESULT" != ""; then
			debug "Success: $FINAL_RESULT"
			date_stamp=`date +%d-%m-%Y_%H-%M-%S`
			mv $FINAL_RESULT $BACKUPS_PATH/$SITE-$date_stamp.tar.bz2
			ENDFILE=`ls $BACKUPS_PATH/$SITE-$date_stamp.tar.bz2`
			if test "$SILENT" != "1"; then
				message "Success: created backup file is:"
				ls -al $ENDFILE
			fi
		else
			error "Moving $THE_RESULT to $BACKUPS_PATH failed. STOP"
			exit 5
		fi
	else
		error "Download of $NEW_TAR failed. STOP"
		exit 9
	fi

	if test "$LOCAL_DEBUG" = "1"; then
		cd /tmp/test
		tar -xjf new.tar.bz2
		echo "----------------------------------------------------------------"
		find . -type f -print
		echo "----------------------------------------------------------------"
	else
		if test "$SH_DEBUG" = "1"; then
			mkdir -p /tmp/test
			cd /tmp/test
			rm -rf *
			tar -xjf $ENDFILE
			echo "Backed up files:"
			echo "----------------------------------------------------------------"
			find . -type f -print
			echo "----------------------------------------------------------------"
		fi
	fi
	
}

##################################
function check_ssh () {
##################################
	if ! test -f $SSH_SCRIPT ; then
		error "Missing SSH_SCRIPT:$SSH_SCRIPT STOP"
		echo "Use --make-ssh to create it."
		exit 5
	fi
}

##################################
function check_scp () {
##################################
	
	if ! test -f $SCP_SCRIPT ; then
		error "Missing SCP_SCRIPT:$SCP_SCRIPT STOP"
		echo "Use --make-scp to create it."	
		exit 5
	fi
}

##################################
function check_lynx () {
##################################
	
	if ! test -f $LYNX_SCRIPT ; then
		error "Missing LYNX_SCRIPT:$LYNX_SCRIPT STOP"
		echo "Use --record to create it."
		exit 5
	fi
}

##################################
function do_backup () {
##################################
#Perform selected actions for one site

	site_settings

	if test "$SITE" = ""; then
		error "SITE is undefined. Use --tiki-site= to select one. STOP"
		exit 5
	fi

	if test "$HAVE_SSH_ACCOUNT" != "yes" -a "$METHOD" = 'mysql'; then
		error "Cannot use 'mysql' method without SSH login to server. STOP"
		exit 4
	fi
	
	BACKUPS_PATH="$BACKUP_BASE/$SITE"
	LYNX_SCRIPT="$LYNX_SCRIPT_DIR/$SITE.cmd"
	SCP_SCRIPT="$SCP_BASE/scp-$SITE.sh"
	SSH_SCRIPT="$SCP_BASE/ssh-$SITE.sh"

	if test "$RECORD" = "1"; then
		record_script
		exit 0
	fi
	if test "$MAKE_SCP" = "1"; then
		make_scp
		exit 0
	fi
	if test "$MAKE_SSH" = "1"; then
		make_ssh
		exit 0
	fi
	if test "$MAKE_CRON" = "1"; then
		make_cron
		exit 0
	fi
	if test "$CLEAN_LOCAL" = "1"; then
		remove_old_local_backups
		exit 0
	fi
	if test "$CLEAN_TIKI" = "1"; then
		remove_old_tiki_backups
		exit 0
	fi
	
	if test "$METHOD" = 'mysql'; then
		check_scp
		check_ssh
		tar_changed_files
	fi
	if test "$FILES_ONLY" = "1"; then
		exit 0
	fi
	if test "$METHOD" = "tiki"; then
		check_lynx
		create_backup
		get_new_backup_name
		dl_new_backup
		remove_old_tiki_backups
	else
		ssh_mysqldump
		dl_new_backup
		remove_old_local_backups
	fi
}

################################### MAIN ##################################

#Built-in defaults:
PAGE_OLD="./tiki-backup1.txt"
PAGE_NEW="./tiki-backup2.txt"
ALL_FLAGS="$@"
METHOD="mysql"
MAX_RETRY=4
LYNX_FLAGS="-connect_timeout=60"

#Make sure we have values for all user configurable settings:
if test "$LYNX_SCRIPT_DIR" = ""; then
	LYNX_SCRIPT_DIR="/usr/local/bin"
fi
if test "$SCP_BASE" = ""; then
	SCP_BASE="/usr/local/share"
fi
if test "$BACKUP_BASE" = ""; then
	BACKUP_BASE="/var/spool/backups/TikiWiki"
fi
if test "$KEEP_DAYS" = ""; then
	KEEP_DAYS=30
fi
if test "$REMOVE_OLD" = ""; then
	REMOVE_OLD="yes"
fi
if test "$ALLWAYS_KEEP" = ""; then
	ALLWAYS_KEEP=12
fi
if test "$HAVE_SSH_ACCOUNT" = ""; then
	HAVE_SSH_ACCOUNT=yes
fi

START_TIME=`date +%s`

for flag in $ALL_FLAGS ; do
	case $flag in 
		--record) #record lynx keystrokes:
			RECORD=1
			;;

		--debug) #debug mode 
			SH_DEBUG=1
			;;

		--tiki-site=*) #select TikiWiki site to backup
			BACKUP_SITE=`echo $flag | cut --field=2 --delimiter="="`
			;;
		
		--silent)
			SILENT=1
			;;

		--db-pass=*)
			DB_PASS=`echo $flag | cut --field=2 --delimiter="="`
			;;

		--method=*)
			METHOD=`echo $flag | cut --field=2 --delimiter="="`
			case $METHOD in
				mysql) ;;
				tiki) ;;
				*) error "Method $METHOD not recognised"
					exit 4
			esac
			;;
			
		--make-scp)
			MAKE_SCP=1
			;;

		--clean-local)
			CLEAN_LOCAL=1
			;;

		--clean-tiki)
			CLEAN_TIKI=1
			;;
			
		--make-ssh)
			MAKE_SSH=1
			;;
			
		--cron)
			MAKE_CRON=1
			;;
			
		--files-only)
			FILES_ONLY=1
			;;
			
		--help)
			echo "Script to perform automatic backup of TikiWiki web site. Options:"
			echo " "			
			echo "--help    This page"
			echo "--debug	Output additional debugging info (verbose)"
			echo "--silent  Report only errors"
			echo "--tiki-site=[$ALL_SITES] Tiki site to backup"
			echo "--method=[tiki|mysql] Use Tiki backup functionality or Use mysqldump"
			echo "--make-scp Generate script to download created backup file"
			echo "--cron Create daily cron invocation using specified flags"
			echo "--files-only Backup only static files, not database"
			echo " "			
			echo "Method=mysql options:"
			echo "--db-pass=password Specify database password to use for mysqldump command"
			echo "--make-ssh Generate script to execute mysqldump command remotely"
			echo " "			
			echo "Method=tiki options:"
			echo "--record  Run lynx, record keystrokes to file"
			echo " "			
			echo "See also: prerequisites and installation instructions at the top"
			echo "of file $0"
			echo " "
			exit 0
			;;
		*)
			error "Unknown option $flag. Try --help"
			exit 4
			;;
	esac
done

	if test "$BACKUP_SITE" = "all"; then
		site_list
		for AN_SITE in $ALL_SITES ; do
			TIKI_SITE="$AN_SITE"
			do_backup
		done
	else
		TIKI_SITE="$BACKUP_SITE"
		do_backup
	fi

	EXIT_TIME=`date +%s`
	let TOOK_TIME=EXIT_TIME-START_TIME
	debug "This script was running for $TOOK_TIME secconds"
	exit 0

################################ EOF ######################################

