#!/bin/sh
#############################################################################
# Script to perform automatic backup of TikiWiki web site.
# Creates backup dump file using choosen method, and then downloads it 
# to local machine
#-----------------------------------------------------------------------------
# Prerequisites:
#
#	- scp (to retrive backup file from remote server)
#	- expect (To run commands that need password at run-time)
#	- bzip2 (To compress backup file)
#	- Script to perform scp automatically, suplying username/password (SCP_SCRIPT)
#		use --make-scp option to create it
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
# - backup forum attachments, Image/File Galleries files, ... anything else?
# - backup tiki-custom_home.php and theme template file (only in V 1.8.5)
# - silent does not work (lynx hangs when redirected to file)
# - remove backups older then 7 days from web site
# - remove backups older then 30 days from local machine
# - Find a way to kill lynx if it does not exit in X seconds
#
#############################################################################

############################# Settings #####################################

DOMAIN=`hostname -d`
if test "$DOMAIN" = "falout.org"; then
	#Private settings for specified domain
	LYNX_SCRIPT_DIR="/etc/custom"
	SCP_BASE="/bin/custom"
	BACKUP_BASE="/data/backups/TikiWiki"
	echo "`date` $0" > /var/log/run.log
else
	#Settings for everyone else
	LYNX_SCRIPT_DIR="/usr/local/bin"
	SCP_BASE="/usr/local/share"
	BACKUP_BASE="/var/spool/backups/TikiWiki"
fi
MAX_RETRY=4
LYNX_FLAGS="-connect_timeout=60"

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
#Download created backiup file to local machine (both methods)

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
			message "Success: created backup file is:"
			ENDFILE=`ls $BACKUPS_PATH/$SITE-$date_stamp.sql.bz2`
			echo $ENDFILE
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

################################### MAIN ##################################

PAGE_OLD="./tiki-backup1.txt"
PAGE_NEW="./tiki-backup2.txt"
ALL_FLAGS="$@"
METHOD="mysql"

for flag in $ALL_FLAGS ; do
	case $flag in 
		--record) #record lynx keystrokes:
			RECORD=1
			;;

		--debug) #debug mode 
			SH_DEBUG=1
			;;

		--tiki-site=*) #select TikiWiki site to backup
			TIKI_SITE=`echo $flag | cut --field=2 --delimiter="="`
			case $TIKI_SITE in
				aubit) 
					PROJECT="aubit4gl"
					DOMAIN="sourceforge.net"
					SITE="$PROJECT.$DOMAIN"
					SITE_URL="http://$SITE/tiki"
					SITE_PATH="/home/groups/a/au/$PROJECT/htdocs"
					DB_NAME="$PROJECT"
					DB_USER="$PROJECT"
					DB_HOST="mysql-a.$DOMAIN"
					;;
				apps)
					PROJECT="apps4gl"
					DOMAIN="sourceforge.net"
					SITE="$PROJECT.$DOMAIN"
					SITE_URL="http://$SITE"
					SITE_PATH="/home/groups/a/ap/$PROJECT/htdocs"
					DB_NAME="$PROJECT"
					DB_USER="$PROJECT"
					DB_HOST="mysql-a.$DOMAIN"
					;;
				*) error "Site $TIKI_SITE not recognised"
					exit 4
			esac
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
			
		--make-ssh)
			MAKE_SSH=1
			;;
			
		--cron)
			MAKE_CRON=1
			;;
			
		--help)
			echo "Script to perform automatic backup of TikiWiki web site. Options:"
			echo " "			
			echo "--help    This page"
			echo "--debug	Output additional debugging info (verbose)"
			echo "--silent  Report only errors"
			echo "--tiki-site=[aubit|apps] Tiki site to backup"
			echo "--method=[tiki|mysql] Use Tiki backup functionality or Use mysqldump"
			echo "--make-scp Generate script to download created backup file"
			echo "--cron Create daily cron invocation using specified flags"
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

	if test "$SITE" = ""; then
		error "SITE is undefined. Use --tiki-site= to select one. STOP"
		exit 5
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
	

	if ! test -f $SCP_SCRIPT ; then
		error "Missing SCP_SCRIPT:$SCP_SCRIPT STOP"
		echo "Use --make-scp to create it."	
		exit 5
	fi
	
	if test "$METHOD" = "tiki"; then
		if ! test -f $LYNX_SCRIPT ; then
			error "Missing LYNX_SCRIPT:$LYNX_SCRIPT STOP"
			echo "Use --record to create it."
			exit 5
		fi
		create_backup
		get_new_backup_name
		dl_new_backup
	else
		if ! test -f $SSH_SCRIPT ; then
			error "Missing SSH_SCRIPT:$SSH_SCRIPT STOP"
			echo "Use --make-ssh to create it."
			exit 5
		fi
		ssh_mysqldump
		dl_new_backup
	fi
	exit 0

################################ EOF ######################################

