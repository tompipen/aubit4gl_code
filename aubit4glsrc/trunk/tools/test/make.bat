rem @echo off
fcompile form.per
mkmess helpfile
4glc -o hello.exe hello.4gl
4glc -o hello2.exe hello2.4gl
4glc -o hello_db.exe hello_db.4gl
echo.
echo Example 4gl programs compiled
echo.


