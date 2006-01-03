#!/bin/sh

#
# A script executed with a file name returning variables in that file.
#

if [ $# -lt 1 ]; then
  echo "File name needed"
	exit 1
fi
file_name=$1

first_var=25666
second_var="Hello world"
third_var=2
echo "$first_var|$second_var|$third_var" > $file_name
