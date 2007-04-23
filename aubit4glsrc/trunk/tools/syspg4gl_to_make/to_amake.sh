#!/bin/bash
#generate the .mk file from the info stored in syspgm4gl database.
#Written by Fernando Ortiz [fortiz (AT) lacorona (DOT) com (DOT) mx]
# Apr 20, 2007  Check if the program exist in database

db=syspgm4gl
if [ a$1 = a ]
then
    echo "usage: $0 <program>"
    exit 1
fi
if [ "$1" = "-h" -o "$1" = "-help" -o "$1" = "--help" ]
then
    echo "This utility allows you to migrate the module dependency for a "
    echo "program stored in the $db database to a .mk suitable for being"
    echo "used for the amake utility"
    exit -1
fi
work=$1.tmp
file=$1.mk
qty=`dbaccess $db - <<EOD 2>/dev/null | grep [0-9] | sed 's/ *//g'
select count(*) from source4gl where progname = "$1"
EOD
`
if [ $qty = 0 ]
then
    echo "Program $1 not found in $db database"
    exit 2
fi
echo "PROG\\t= $1" >$work
echo " " >>$work
echo "GLOBALS.4gl\\t=\\t\\" >>$work
dbaccess $db - <<EOD 2>&1 | grep "/"  >>$work 
select distinct "\\t"||trim(nvl(gpath,"."))||"/"||trim(globname)||".4gl\\t\\"
from global
where progname = "$1"
order by 1
EOD
echo " " >>$work
echo " " >>$work
echo "FILES.4gl\\t=\\t\${GLOBALS.4gl} \\" >>$work 
dbaccess $db - <<EOD 2>&1 | grep "/" >>$work 
select distinct "\\t"||trim(nvl(spath,"."))||"/"||trim(fglsourcename)||".4gl\\t\\"
from source4gl
where progname = "$1"
order by 1
EOD
echo " " >>$work
echo " " >>$work
sed -e 's/\\t/	/g;s/ *$//' $work >$file
rm $work
echo "$file created"
