#!/bin/bash

#generate the .mk file from the info stored in syspgm4gl database.
#Written by Fernando Ortiz [fortiz (AT) lacorona (DOT) com (DOT) mx]

if [ a$1 = a ]
then
    echo "usage: $0 module"
    exit 1
fi
work=$1.tmp
file=$1.mk
db=syspgm4gl
echo "PROG\\t= $1" >$work
echo " " >>$work
echo "GLOBALS.4gl\\t=\\t\\" >>$work
dbaccess $db - <<EOD 2>&1 | grep "/"  >>$work select distinct "\\t"||trim(nvl(gpath,"."))||"/"||trim(globname)||".4gl\\t\\"
from global
where progname = "$1"
order by 1
EOD
echo " " >>$work
echo " " >>$work
echo "FILES.4gl\\t=\\t\${GLOBALS.4gl} \\" >>$work dbaccess $db - <<EOD 2>&1 | grep "/" >>$work select distinct "\\t"||trim(nvl(spath,"."))||"/"||trim(fglsourcename)||".4gl\\t\\"
from source4gl
where progname = "$1"
order by 1
EOD
echo " " >>$work
echo " " >>$work
sed -e 's/\\t/	/g;s/ *$//' $work >$file
rm $work
