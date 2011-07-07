#!/bin/sh
for f in *.per
do
    if [ $f != "*.per" ] 
    then
	b=`basename $f .per`.err
	fcompile $f 2>&1 >/dev/null
	if [ -e $b ]
        then
            echo form $f ... ERROR
        else
            echo form $f ... ok
        fi
    fi
done
