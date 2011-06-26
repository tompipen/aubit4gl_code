@echo off
rem set DEBUG=yes
set DEBUG=no
rem --------------------------------------------------------------------
rem ------------------ TAKEOUT.Bat -------------------------------------
rem --------------------------------------------------------------------
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
rem DO NOT FORGET + OR * IN .RHOST FILE ON REMOTE HOST !!!!!!!!!!!!!!!!!
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
goto :start
rem ---------------------------------------------------------------------
rem desc. Of problems when using path wit spaces and more than 8 chars
rem long (with disk label removed)
rem ---------------------------------------------------------------------

rem command:        if not exist "%dsk%%3%8%9" goto :Rcopy
rem evaluates to:   "c:"\My Documents\"LI\src\r_outbal.par"
rem problem:        "" around \My Documents\

rem Command:
rem Result:         Invalid parameter - Documents\LI\src\r_outbal.par

rem command:        rcp -a nezsdc.andrejf:/property1/release/gui/src/LI/src/r_outbal.par ""\My Documents\"LI\src\r_outbal.par"
rem result:         rcp: Documents"LI\src\r_outbal.par: Not a directory.

Rem Command:
Rem Result:         Bad command or file name

rem command:        start "c:"\My Documents\"LI\src\TakeOut.Log"
rem result:         No application is associated with the specified file. Create
rem                 an association by using the Explorer.
rem ---------------------------------------------------------------------

:start

del "%dsk%%3%8error.$$$"
del "%dsk%%3%8errexist.$$$"

set warn=0
rem because of problem with rcp.Exe and disk label in local path,
rem var dsk inserted in front of local paths. BE carefull to manualy
rem delete disk label from GTE.INI ClientInitDir.
Rem When this problem is solved, just set dsk to nothing (null)
set dsk=c:
goto :ChkParams

rem -------------------------------------------------------------------
:Debug
rem -------------------------------------------------------------------
rem -----------------------------------------------------
rem SCCS takeout command     edit
echo 1%1-
rem -----------------------------------------------------
rem UNIX initial path   /property1/release/gui/src
echo 2%2-
rem -----------------------------------------------------
rem LOCAl initial path  c:\data\
echo 3%3-
rem -----------------------------------------------------
rem UNIX server name    nezsdc
echo 4%4-
rem -----------------------------------------------------
rem username            andrejf
echo 5%5-
rem -----------------------------------------------------
rem password            xxxzzzyyy
echo 6%6-
rem -----------------------------------------------------
rem UNIX path relative to initial path       fileloc/
echo 7%7-
rem -----------------------------------------------------
rem LOCAL path relative to initial path      filelc\
echo 8%8-
rem -----------------------------------------------------
rem filename            file.ext
echo 9%9-
rem -----------------------------------------------------
pause


rem -------------------------------------------------------------------
:ChkParams
rem -------------------------------------------------------------------
rem if %1!==! Goto :Perr1
if %2!==! Goto :Perr2
if %3!==! Goto :Perr3
if %4!==! Goto :Perr4
if %5!==! Goto :Perr5
rem if %6!==! Goto :Perr6
if %7!==! Goto :Perr7
if %8!==! Goto :Perr8
if %9!==! Goto :Perr9

Goto :ContPar

:Perr1
echo Parameter No1 to takeout.Bat is NULL!
Set warn=a
goto :ContPar
:Perr2
echo Parameter No2 to takeout.Bat is NULL!
Set warn=b
goto :ContPar
:Perr3
echo Parameter No3 to takeout.Bat is NULL!
Set warn=c
goto :ContPar
:Perr4
echo Parameter No4 to takeout.Bat is NULL!
Set warn=d
goto :ContPar
:Perr5
echo Parameter No5 to takeout.Bat is NULL!
Set warn=e
goto :ContPar
:Perr6
echo Parameter No6 to takeout.Bat is NULL!
Set warn=f
goto :ContPar
:Perr7
echo Parameter No7 to takeout.Bat is NULL!
Set warn=g
goto :ContPar
:Perr8
echo Parameter No8 to takeout.Bat is NULL!
Set warn=h
goto :ContPar
:Perr9
echo Parameter No9 to takeout.Bat is NULL!
Set warn=i
goto :ContPar

:ContPar


rem -------------------------------------------------------------------
:ExecOut
rem -------------------------------------------------------------------
rem TEMP DISABLED FOR FUJITSU IGET SYSTEM
goto :CheckExist
rem Execute TakeOut command of Version control system on UNIX
rem via REXECd or RSHd services. REXEC autenticates user, RSH does not(?)
rem rexec/rsh host -l username command...
rem -n redirects input of rexec to NULL
rem THIS WILL PROMPT FOR PASSWORD: rexec %4 -l %5 %1 %2%7%9
REM SAME, BUT WITHOUT USERNAME, SO NO PROMPT FOR PASSWORD...
rsh %4 %1 %2%7%9
if %DEBUG%==yes pause
rem

rem -------------------------------------------------------------------
:CheckExist
rem -------------------------------------------------------------------
rem if requested file is not on local path...
if not exist "%dsk%%3%8%9" goto :Rcopy
rem if requested file IS in local path, it means that it was teaken out
rem before, and possibly modified, and must not be overwriten
echo ********************************************************
echo                          WARNING !
echo     Local file %dsk%%3%8%9
echo                     already exists !
echo ********************************************************
set warn=AlreadyExists
rem file will still be opened in editor, this is just to prevent
rem overwriting local file with file from UNIX

                  if not exist "%dsk%%3%8001_%9" set sav_file=001_%9
if %sav_file%!==! if not exist "%dsk%%3%8002_%9" set sav_file=002_%9
if %sav_file%!==! if not exist "%dsk%%3%8003_%9" set sav_file=003_%9
if %sav_file%!==! if not exist "%dsk%%3%8004_%9" set sav_file=004_%9
if %sav_file%!==! if not exist "%dsk%%3%8005_%9" set sav_file=005_%9
if %sav_file%!==! if not exist "%dsk%%3%8006_%9" set sav_file=006_%9
if %sav_file%!==! if not exist "%dsk%%3%8007_%9" set sav_file=007_%9
if %sav_file%!==! if not exist "%dsk%%3%8008_%9" set sav_file=008_%9
if %sav_file%!==! if not exist "%dsk%%3%8009_%9" set sav_file=009_%9

if not sav_file!==! ren "%dsk%%3%8%9" "%sav_file%"

rem -------------------------------------------------------------------
:Rcopy
rem -------------------------------------------------------------------
rem verify that local path exists (directory)
if exist "%dsk%%3%8nul" goto :cont11
set warn=LocalPathInvalid
echo Local Directory "%dsk%%3%8" does not exist. Create it first.
pause

:cont11
rem rcp -a nezsdc.andrejf:/property1/release/gui/src/LI/src/bulk_fee.4gl %dsk%\data\LI\src\bulk_fee.4gl
rem OK rcp -a nezsdc.andrejf:/property1/release/gui/src/LI/src/bulk_fee.4gl .
rem local disc must not be specified

rem opens window: start /m /w rcp -a %4.%5:%2%7%9 %3%8%9
rem opens window: command nul /c rcp -a %4.%5:%2%7%9 %3%8%9
rem rcp.lnk -a %4.%5:%2%7%9 %3%8%9 > nul
rem -a ACSCII mode - translate CR/LF from/to DOS/UNIX fromats (-b = Binary)
rem -h transfers hiden files
rem -r copies all subdirs
rem TRY REPLACING C:\DIR\SUBDIR\PATH WITH UNC PATH LIKE
rem netPCname//SharedDiskName/path/filename OR
rem netPCname//SharedDiskName\path\filename, for example:
REM retail05pc//c/data/LI/src/filename.ext
rem this may be the reason why rcp don't like disk label (C:)
rem do not use -a (ascii transfer with CR/LF conversion - default mode)
rem     use -b (binary) instead because if you later transfer file by another
rem     means (like FTP) that does not do the translataion, you will end up
rem     with ^M on the end of each line.
rcp -b %4.%5:%2%7%9 "%3%8%9"
if errolevel==9 goto :err9
if errolevel==8 goto :err8
if errolevel==7 goto :err7
if errolevel==6 goto :err6
if errolevel==5 goto :err5
if errolevel==4 goto :err4
if errolevel==3 goto :err3
if errolevel==2 goto :err2
if errolevel==1 goto :err1

goto :ChkSucc

rem -------------------------------------------------------------------
rem Check for errors in RCP
rem -------------------------------------------------------------------
:err9
echo error no. 9
set warn=9
goto :EndRcp
:err8
echo error no. 8
set warn=8
goto :EndRcp
:err7
echo error no. 7
set warn=7
goto :EndRcp
:err6
echo error no. 6
set warn=6
goto :EndRcp
:err5
echo error no. 5
set warn=5
goto :EndRcp
:err4
echo error no. 4
set warn=4
goto :EndRcp
:err3
echo error no. 3
set warn=3
goto :EndRcp
:err2
echo error no. 2
set warn=2
goto :EndRcp
:err1
echo error no. 1
set warn=1
goto :EndRcp


:EndRcp

rem -------------------------------------------------------------------
:ChkSucc
rem -------------------------------------------------------------------
rem File is now in local path...
if exist "%dsk%%3%8%9" goto :Prompt
rem Or is NOT, RCP was not successfull
set warn=NotExists


rem -------------------------------------------------------------------
:Prompt
rem -------------------------------------------------------------------
rem If there was no warnings/errors, goto End
if %warn%==0 Goto :End
if %warn%==AlreadyExists echo !!! File was already in local path !!!  >> "%dsk%%3%8TakeOut.Log"
if not %warn%==AlreadyExists echo Warning! Cannot find File  >> "%dsk%%3%8TakeOut.Log"
echo %2%7%9 >> "%dsk%%3%8TakeOut.Log"
echo on_server: %4 as_user: %5  >> "%dsk%%3%8TakeOut.Log"
echo Error message: %warn%  >> "%dsk%%3%8TakeOut.Log"
echo ----------------------------------------------------------- >> "%dsk%%3%8TakeOut.Log"

rem Open Error messages in editor
rem no need to open log. TakeOut.c tests for existance of file
rem error.$$$ in g_szClientInitDir\g_szFileLocation
rem but it also tests for existance of requested file, whitch can be
rem same file coppied before, not now, so generate error.$$$ anyway
if not %warn%==AlreadyExists echo "Error encountered while executing TakeOut.bat" > "%dsk%%3%8error.$$$"
if %warn%==AlreadyExists echo "Same fielname exists-previous copy renamed to xxx_filename.ext" > "%dsk%%3%8errexist.$$$"
rem if not %warn%==AlreadyExists start "%dsk%%3%8TakeOut.Log"

rem -------------------------------------------------------------------
:End
rem -------------------------------------------------------------------
set sav_file=
set warn=
set dsk=
