@echo off

set AUBITDIR=../..
set PATH=../../bin;../../lib;%PATH%

echo fcompile form.per
fcompile form.per

echo mkmess helpfile
mkmess helpfile

echo 4glc -o hello.exe hello.4gl
4glc -o hello.exe hello.4gl

echo 4glc -o hello2.exe hello2.4gl
4glc -o hello2.exe hello2.4gl

echo 4glc -o hello_db.exe hello_db.4gl
4glc -o hello_db.exe hello_db.4gl

echo.
echo Finished compiling Example 4gl programs
echo.


