#!/bin/sh

# Svcript for executint the test programs for aubit remote user interface

LOG=/tmp/test_aubit_ui.log

echo "$0 : Executed at `date`" >> $LOG

. bin/aubit-env
AFGLSERVER=`echo $SSH_CONNECTION | cut -d " " -f1`
export AFGLSERVER
echo "AFGLSERVER : $AFGLSERVER" >> $LOG 2>&1

DBPATH=`dirname $1`
export DBPATH

echo "DBPATH=$DBPATH " >> $LOG
echo "Executing $1 " >> $LOG

$1 >> $LOG 2>&1
