#!/bin/sh
#############################################################################
# Script to perform aubomatic backup of TikiWiki web site.
# Creates backup dump file using TikiWiki functionality, and then downloads it 
# to local machine
#-----------------------------------------------------------------------------
# Prerequisites:
#	- lynx
#   - ssh
#	- scp
#	- expect
#	- bzip2
#   - Lynx pre-recorded command keys script (LYNX_SCRIPT) (or use -record to 
#		create yours)
#	- Script to perform scp automatically, suplying username/password (SCP_SCRIPT)
#		Example:
#
#		#!/usr/bin/expect -f
#		set timeout 900
#		spawn scp -q yourUserName@aubit4gl.sourceforge.net:$argv .
#		expect " password:"
#		send "yourPassword\r"
#		expect eof
#
# Installation:
#	1: Enshure all listed prerequisites exist on your system
#	2: Enshure LYNX_SCRIPT and SCP_SCRIPT exist and are valid
#	3: Make this script executable (chmod +x ...)
#	4: run this script from command line, to verify it works on your system
#	5: move this script to /etc/cron.daily directory
#
#
# Todo:
# - backup forum attachments, Image/File Galleries files, ... anything else?
# - backup tiki-custom_home.php and theme template file (only in V 1.8.5)
# - silent does not work (lynx hangs when redirected to file)
# - remove backups older then 7 days from web site
# - remove backups older then 30 days from local machine
# - Add to Aubit CVS
#
#############################################################################

############################# Settings #####################################

SITE="aubit4gl.sourceforge.net"
SITE_URL="http://$SITE/tiki"
SITE_PATH="/home/groups/a/au/aubit4gl/htdocs"
BACKUPS_PATH="/data/backups/TikiWiki/$SITE"
LYNX_SCRIPT="/etc/custom/aubitTiki.cmd"
PAGE_OLD="./tiki-backup1.txt"
PAGE_NEW="./tiki-backup2.txt"
MAX_RETRY=4
SCP_SCRIPT="/bin/custom/auto_sf_scp_get"

##############################
function create_backup () {
##############################
	
	RETRY_CNT=0
	while true ; do
		let RETRY_CNT=RETRY_CNT+1
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
function replay_script () {
##############################
#Replay keystrokes

	debug "Running script..."
	if test "$SILENT" = "1"; then
		#WARNING: seems that lynx does not work correctly when its output is 
		#redirected to file	
		lynx -accept_all_cookies -cmd_script=$LYNX_SCRIPT $SITE_URL $LOGCMD > /tmp/lynx_transcript.log 2>&1
	else
		lynx -accept_all_cookies -cmd_script=$LYNX_SCRIPT $SITE_URL $LOGCMD
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

	if test "$SH_DEBUG" = "1"; then
		echo "-------------------------------------------------------------"
		grep "remove restore" $PAGE_OLD | cut --fields=1 --delimiter="."
		echo "-------------------------------------------------------------"
		grep "remove restore" $PAGE_NEW | cut --fields=1 --delimiter="."
		echo "-------------------------------------------------------------"
	fi
	
	OLD_LIST=`grep "remove restore" $PAGE_OLD | cut --fields=1 --delimiter="."`
	NEW_LIST=`grep "remove restore" $PAGE_NEW | cut --fields=1 --delimiter="."`
	
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
	
	if test "$CREATED_BACKUP" != ""; then
		debug "new backup is $CREATED_BACKUP"
	else
		error "Cannot determine just created backup. STOP"
		exit 4
	fi
}	

##################################
function debug () {
##################################

	if test "$SH_DEBUG" = "1"; then
		echo "DEBUG: $1"
	fi
}

##################################
function message () {
##################################

	if test "$SILENT" != "1"; then
		echo "$1"
	fi
}

##################################
function error () {
##################################

	echo "ERROR: $1"
}


##################################
function dl_new_backup () {
##################################

	if ! test -d "$BACKUPS_PATH" ; then
		mkdir -p "$BACKUPS_PATH"
	fi
	
	$SCP_SCRIPT $SITE_PATH/tiki/backups/$CREATED_BACKUP*.sql > /tmp/tiki_scp.log 2>&1
	
	THE_RESULT=`ls ./$CREATED_BACKUP*.sql`
	if test "$THE_RESULT" != ""; then
		debug "Downloaded backup file: $THE_RESULT ; moving to $BACKUPS_PATH"
		mv "$THE_RESULT" "$BACKUPS_PATH"
		FINAL_RESULT=`ls $BACKUPS_PATH/$CREATED_BACKUP*.sql`
		if test "$FINAL_RESULT" != ""; then
			debug "Success: $FINAL_RESULT"
			date_stamp=`date +%d-%m-%Y_%H-%M-%S`
			mv $FINAL_RESULT $BACKUPS_PATH/$SITE-$date_stamp.sql
			bzip2 $BACKUPS_PATH/$SITE-$date_stamp.sql
			message "Success: created backup file is:"
			ls $BACKUPS_PATH/$SITE-$date_stamp.sql.bz2
			
		else
			error "Moving $THE_RESULT to $BACKUPS_PATH FAILED"
			exit 2
		fi
	else
		error "Download failed"
		exit 3
	fi
}

#################################
function sane () {
#################################
	
	if ! test -f $LYNX_SCRIPT ; then
		error "Missing LYNX_SCRIPT:$LYNX_SCRIPT STOP"
		exit 5
	fi
	
	if ! test -f $SCP_SCRIPT ; then
		error "Missing SCP_SCRIPT:$SCP_SCRIPT STOP"
		exit 5
	fi
	
}	

################################### MAIN ##################################

ALL_FLAGS="$@"

for flag in $ALL_FLAGS ; do
	case $flag in 
		--record)
			#record keystrokes:
			lynx -accept_all_cookies -cmd_log=$LYNX_SCRIPT $SITE_URL 
			exit 0
			;;

		--debug)
			SH_DEBUG=1
			;;

		--silent)
			SILENT=1
			;;

		--help)
			echo "Script to perform aubomatic backup of TikiWiki web site. Options:"
			echo " "			
			echo "--record  Run lynx, record keystrokes to file"
			echo "--help    This page"
			echo "--debug	Outout additional debugging info (verbose)"
			echo "--silent  Report only errors"
			echo " "			
			;;
		*)
			error "Unknown option $flag"
			exit 4
			;;
	esac
done

	sane
	create_backup
	get_new_backup_name
	dl_new_backup
	exit 0

################################ EOF ######################################

