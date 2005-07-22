#!/bin/sh
#############################################################################
# Script to perform automatic backup of TikiWiki web site.
# - Creates backup database dump file using choosen method
# - Creates backup of all files in Tiki dir that changed since installation
# - Then downloads both to local machine
# $Id: tiki_backup.sh,v 1.5 2005-07-22 06:16:20 afalout Exp $
# See --help and --man for instructions
# Please report bugs to andrej@dontspam.falout.org
#############################################################################

######################## Read Global Settings ###############################

MY_DOMAIN=`hostname -d`
#Read global configuration file (system wide)
GLOBAL_CONF="/etc/custom/tiki_backup-$MY_DOMAIN.conf"
if test -f "$GLOBAL_CONF"; then
	. "$GLOBAL_CONF"
else
	GLOBAL_CONF="/etc/tiki_backup-$MY_DOMAIN.conf"
	if test -f "$GLOBAL_CONF"; then
		. "$GLOBAL_CONF"
	else
		GLOBAL_CONF="none"
	fi
fi

#Read global configuration file (user private)
#NOTE: all settings defined in user private configuration file will
#OVERRIDE settings from system-wide configuration file
USER_GLOBAL_CONF="~/.tiki_backup-$MY_DOMAIN.conf"
if test -f "$USER_GLOBAL_CONF"; then
	. "$USER_GLOBAL_CONF"
	if test "$GLOBAL_CONF" = "none"; then
		GLOBAL_CONF="$USER_GLOBAL_CONF"
	fi
fi

#################################
function site_list () {
#################################
#Define a list of recognised sites

	SITE_CONF_LIST="`ls /etc/custom/tiki_backup-site-*.conf 2> /dev/null`"
	SITE_CONF_LIST="`ls /etc/tiki_backup-site-*.conf 2> /dev/null` $SITE_CONF_LIST"
	SITE_CONF_LIST="`ls ~/.tiki_backup-site-*.conf 2> /dev/null` $SITE_CONF_LIST"
	ALL_SITES=""
	for conf in $SITE_CONF_LIST; do
		AN_SITE=`echo "$conf" | sed -e 's/\/etc/\//' -e 's/custom\///'`
		THE_SITE=`echo $AN_SITE | cut --field=3 --delimiter="-" | cut --field=1 --delimiter="."`
		ALL_SITES="$ALL_SITES $THE_SITE"
	done
	
	if test "$ALL_SITES" = ""; then
		message "WARNING: no site configuration files found"
	else
		debug "ALL_SITES=$ALL_SITES"
	fi
	
}

#################################
function site_settings () {
#################################
#read configuration that is site dependent. 

	CONF_PATHS="/etc/custom /etc ~/."
	
	site_list
	HAVE_CONF=0
	for an_site in $ALL_SITES; do
		if test "$TIKI_SITE" = "$an_site"; then
			for an_path in $CONF_PATHS; do
				if test -f "$an_path/tiki_backup-site-$TIKI_SITE.conf"; then
					. "$an_path/tiki_backup-site-$TIKI_SITE.conf"
					HAVE_CONF=1
					break
				fi
			done
		fi
	done

	
	if test "$HAVE_CONF" = "0"; then
		message "Site $TIKI_SITE not recognised"
		read -p "Would you like to create a default demonstration config file for this site? (N/y)"
		if test "$REPLY" = "y"; then 
			make_default_site_conf "$TIKI_SITE"
		else
			error "You ned to crate a configuration file for $TIKI_SITE site first."
			exit 4
		fi
	fi
	
}

#########################################
function make_default_site_conf () {
#########################################
#Create default (demonstration) site configuration file

	THIS_CONF="/etc/tiki_backup-site-$1.conf"
	touch $THIS_CONF
	if test ! -f "$THIS_CONF" ; then
		THIS_CONF="$HOME/.tiki_backup-site-$1.conf"
	fi
	
	echo "#Tiki_backup configuration file for site $1" > "$THIS_CONF"
	echo "#This is a demonstration configuration, automatically generated, for" >> "$THIS_CONF" 
	echo "#a Tiki site of Aubit project; use it as a starting point, change" >> "$THIS_CONF"
	echo "#settings to suit your web site" >> "$THIS_CONF"
	echo "PROJECT="aubit4gl"" >> "$THIS_CONF"
	echo "DOMAIN="sourceforge.net"" >> "$THIS_CONF"
	echo "SITE="\$PROJECT.\$DOMAIN"" >> "$THIS_CONF"
	echo "TIKI_PATH="/tiki" 	#Path to root of tiki installation, relative to Apache htdocs root" >> "$THIS_CONF"
	echo "SITE_URL="http://\$SITE\$TIKI_PATH"" >> "$THIS_CONF"
	echo "SITE_PATH="/home/groups/a/au/\$PROJECT/htdocs\$TIKI_PATH"" >> "$THIS_CONF"
	echo "DB_NAME="\$PROJECT"" >> "$THIS_CONF"
	echo "DB_USER="\$PROJECT"" >> "$THIS_CONF"
	echo "DB_HOST="mysql-a.\$DOMAIN"" >> "$THIS_CONF"
	echo "" >> "$THIS_CONF"
	
	echo "=============================================================="
	echo "Default demonstration configuration file for site $1 created as:"
	echo "$THIS_CONF"
	echo "It contains settings for a Tiki web site of Aubit project"
	echo "You MUST edit it to reflect YOUR site settings before you can use it"
	echo "=============================================================="
	exit 0
	
	#PROJECT="apps4gl"
	#TIKI_PATH=""
	#SITE_PATH="/home/groups/a/ap/$PROJECT/htdocs$TIKI_PATH"
	
}

################################################
function man_page () {
################################################
#Show instructions to the user (man page)
	
echo " Script to perform automatic backup of TikiWiki web site."
echo " - Creates backup database dump file using choosen method"
echo " - Creates backup of all files in Tiki dir that changed since installation"
echo " - Then downloads both to local machine"
echo " $Id: tiki_backup.sh,v 1.5 2005-07-22 06:16:20 afalout Exp $"
echo " Please report bugs to andrej@dontspam.falout.org"
echo "-----------------------------------------------------------------------------"
echo " Prerequisites:"
echo "---------------"
echo "  - scp (to retrive backup files from remote server)"
echo "  - expect (To run commands that need password at run-time)"
echo "  - bzip2 (To compress backup file)"
echo "  - Script to perform scp automatically, suplying username/password (SCP_SCRIPT)"
echo "    use --make-scp option to create it"
echo "  - ssh login on the TikiWiki server"
echo ""
echo "  Only for 'tiki' method:"
echo "    - lynx (To trigger TikiWiki to create a backup)"
echo "    - Lynx pre-recorded command keys script (LYNX_SCRIPT) (use --record option" 
echo "      to create it)"
echo ""
echo "  Only for 'mysql' method (DEFAULT)"
echo "    - ssh (to remotely execute mysqldump)"
echo "    - Script to perform ssh automatically, suplying username/password (SSH_SCRIPT)"
echo "      use --make-ssh option to create it"
echo "    - mysqldump on TikiWiki server"
echo "    - login information for mysql database"
echo ""
echo "Configuration:"
echo "---------------"
echo " Global configuration files:" 
echo "   - tiki_backup-`hostname -d`.conf in /etc/custom or /etc "
echo "   - .tiki_backup-`hostname -d`.conf in your home directory ($HOME)"
echo "	   NOTE: If global config is found in user's home directory, it will"
echo "           overwrite system-wide settings"
echo "     If none is found, default one will be automatically crated"
echo ""
echo " Site specific configuration files:"
echo "   - tiki_backup-site-SITENAME.conf in  /etc or /etc/custom"
echo "   - .tiki_backup-site-$1.conf in your home directory ($HOME)"
echo "	   NOTE: If site config is found in user's home directory, it will"
echo "           overwrite system-wide settings"
echo "     If none is found, you will be offered to automatically crate it"
echo "     and populate it with demonstration settings"
echo "     SITENAME is taken from name supplied using --tiki-site flag"
echo ""
echo "Installation:"
echo "-------------"
echo "  1: Check that all listed prerequisites exist on your system"
echo "  2: Make this script executable (chmod +x ...)"
echo "  3: Check that scipts required for choosen method are created. Use"
echo "     --record | --make-scp | --make-ssh options to create them"
echo "  4: run this script from command line, to verify it works on your system"
echo "     Example: ./tiki_backup.sh --tiki-site=aubit --db-pass=MyPass"
echo "  5: To create script in /etc/cron.daily directory to invoke it with"
echo "     same flags as tested in step 4, add --cron flags to flags used in"
echo "     step 4"
echo ""
echo "Methods for performing database backup:"
echo "---------------------------------------"
echo "  1. Mysql (DEFAULT)"
echo "      Uses SSH to run mysqldump on remote system, then downloads created"
echo "      backup file using SCP"
echo "  2. Tiki" 
echo "      Uses lynx web browser to trigger a TikiWiki web page that creates"
echo "      backup file, then downloads created file using SCP, or wget if user"
echo "      does not have a SSH account on the Tiki server"
echo ""
echo "Features:"
echo "----------"
echo "  - can use scp or wget to download created backups"
echo "  - cleans old backups automatically on each run, depending on settings"
echo "  - separate configuration files for system-wide and user specific"
echo "  - separate configuration for each site to backup"
echo "  - automatically creates needed scripts, based on user input"
echo "  - automatically creates default configuration files"
echo "  - can use mysqldump or TikiWiki functionality to create db backups"
echo "    NOTE: do not use Tiki functionality with TikiWiki version 1.8.5"
echo "  - back ups both database and files changed/added since installation in Tiki directory"
echo "  - can backup multiple sites in one invocation (if db passwords are different, and" 
echo "    when mysql methos is used, DB password has to be specified in site config file)"
echo "  - can backup database on server with no SSH access (but not files)"
echo "  - once configured, runs fully automatic with no user input needed"
echo "  - can install itself as daily cron script"
echo "  - ..."
echo ""


}

##############################################
function make_default_global_conf () {
##############################################
#Create default global configuration file
	
	GLOBAL_CONF="/etc/tiki_backup-$MY_DOMAIN.conf"

	echo "#Defaults that should work for most Linux installations" > $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Directory to put created Lynx script:" >> $GLOBAL_CONF
	echo "#Default: "/usr/local/bin"" >> $GLOBAL_CONF
	echo "#LYNX_SCRIPT_DIR="/usr/local/bin"" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Directory to put SCP and SSH expect scripts" >> $GLOBAL_CONF
	echo "#Default: "/usr/local/share"" >> $GLOBAL_CONF
	echo "#SCP_BASE="/usr/local/share"" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Location to put created backup files in; if it does not" >> $GLOBAL_CONF
	echo "#exist, it will be created" >> $GLOBAL_CONF
	echo "#Default: "/var/spool/backups/TikiWiki"" >> $GLOBAL_CONF
	echo "#BACKUP_BASE="/var/spool/backups/TikiWiki"" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#How many days to keep backups" >> $GLOBAL_CONF
	echo "#Default: 30" >> $GLOBAL_CONF
	echo "#KEEP_DAYS=30" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Are the backups older then KEEP_DAYS to be deleted or not (yes|no)" >> $GLOBAL_CONF
	echo "#Default: yes" >> $GLOBAL_CONF
	echo "#REMOVE_OLD="yes"" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Minimum number of backups to ALLWAYS keep, regardles of how old they are" >> $GLOBAL_CONF
	echo "#This is to prevent an system clock error from deleting all backups we have" >> $GLOBAL_CONF
	echo "#Default: 12" >> $GLOBAL_CONF
	echo "#ALLWAYS_KEEP=12" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Do we have a SSH login on TikiWiki server; if no, we must use 'tiki'" >> $GLOBAL_CONF
	echo "#method of creating database backup, and use wget to download it." >> $GLOBAL_CONF
	echo "#Note that without SSH login, we cant backup Tiki files" >> $GLOBAL_CONF
	echo "#Default: yes" >> $GLOBAL_CONF
	echo "#HAVE_SSH_ACCOUNT=yes" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
	echo "#Which metod to use for downloading files from web server" >> $GLOBAL_CONF
	echo "#Options are: scp | wget (NOT IMPLEMENTED)" >> $GLOBAL_CONF
	echo "#Default: scp" >> $GLOBAL_CONF
	echo "#DL_METHOD=scp" >> $GLOBAL_CONF
	echo "" >> $GLOBAL_CONF
		
	if test -f "$GLOBAL_CONF"; then
		echo "-------------------------------------------------------------------"
		echo "NOTE: Default global configuration file for tiki_backup was created:"
		echo "$GLOBAL_CONF"
		echo " You can edit it to adjust preferences"
		echo "-------------------------------------------------------------------"
	else
		echo "-------------------------------------------------------------------"
		echo "NOTE: Attempt to create default configuration file:"
		echo "$GLOBAL_CONF"
		echo "FAILED"
		echo "-------------------------------------------------------------------"
	fi
}	

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

	if test "$DL_METHOD" = "wget"; then
		error "DL_METHOD $DL_METHOD not implemented. STOP"
		exit 1
	else
		#use scp method to dl files
		if test "$METHOD" = "tiki"; then
			$SCP_SCRIPT $SITE_PATH/tiki/backups/$CREATED_BACKUP*.sql > /tmp/tiki_scp.log 2>&1
			THE_RESULT=`ls ./$CREATED_BACKUP*.sql`
		else
			$SCP_SCRIPT $SITE_PATH/$CREATED_BACKUP > /tmp/tiki_scp.log 2>&1
			THE_RESULT=`ls ./$CREATED_BACKUP`
		fi
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
	get_username
	if test "$LOGIN_USERNAME" = ""; then
		error "LOGIN_USERNAME is empty; STOP"
		exit 4
	fi
	
	CREATED_BACKUP="$LOGIN_USERNAME-DBbackup.sql.bz2"
	
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
function get_username () {
#######################################
#Get use name that is used to log-in into remote system. Used to make
#distinc file names between multiple users performing backups, since we
#cant rely on file permissions or users belonging to same group, and 
#we certanly cant leave world writable files on web server

	TMP_STR=`cat "$SCP_SCRIPT" | grep "$SITE" | cut --field=1 --delimiter="@"`
	#last field befoore cut (@) will have username
	for field in $TMP_STR; do
		LOGIN_USERNAME="$field"
	done
	#echo $LOGIN_USERNAME

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
		./backup.sql.bz2 './*-tikiBackup.tar.bz2'"
		
	#File (or directory) that has a timestamp of installation date:
	REF_FILE="./modules"
	get_username
	if test "$LOGIN_USERNAME" = ""; then
		error "LOGIN_USERNAME is empty; STOP"
		exit 4
	fi
	
	#Name of tar file to create
	if test "$LOCAL_DEBUG" = "1"; then	
		NEW_TAR="/tmp/test/$LOGIN_USERNAME-tikiBackup.tar.bz2"
	else
		NEW_TAR="./$LOGIN_USERNAME-tikiBackup.tar.bz2"
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
		tar -xjf $NEW_TAR
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
	if test "$GET_USERNAME"; then
		get_username
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
		#method is mysql
		get_username
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

if test "$GLOBAL_CONF" = "none"; then
	make_default_global_conf
fi


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
if test "$DL_METHOD" = ""; then 
	DL_METHOD="scp"
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

		#--get-username)
		#	GET_USERNAME=1
		#	;;
			
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

		--man)
			man_page
			exit 0
			;;
			
		--help)
			SH_DEBUG=0
			site_list
			echo " "
			echo "Script to perform automatic backup of TikiWiki web site. Options:"
			echo " "
			echo "General options:"
			echo "----------------"
			echo "--help       This page"
			echo "--debug      Output additional debugging info (verbose)"
			echo "--silent     Report only errors"
			echo "--tiki-site=[$ALL_SITES all] Tiki site to backup. If settings"
			echo "             for supplied site name do not exist, default will be created"
			echo "--method=[tiki|mysql] Use Tiki backup functionality, or Use mysqldump"
			echo "--make-scp   Generate script to download created backup file"
			echo "--cron       Create daily cron invocation using specified flags"
			echo "--files-only Backup only static files, not database"
			echo "--clean-tiki Remove old backups from Tiki web site, according to settings"
			echo "--clean-local Remove old backups from local machine, according to settings"
			echo "--man        Show man page" 
			echo " "			
			echo "Method=mysql only options:"
			echo "--------------------------"
			echo "--db-pass=password Specify database password to use for mysqldump command"
			echo "--make-ssh         Generate script to execute mysqldump command remotely"
			echo " "			
			echo "Method=tiki options:"
			echo "--------------------"
			echo "--record      Run lynx, record keystrokes to file"
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

