@echo off
rem set DBG=yes
set DBG=no
rem --------------------------------------------------------------------
rem --------------------- rmake.bat -------------------------------------
rem --------------------------------------------------------------------
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
rem DO NOT FORGET + OR * IN .RHOST FILE ON REMOTE HOST !!!!!!!!!!!!!!!!!
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
:start
set site=CSI
set warn=0
rem because of problem with rcp.Exe and disk label in local path,
rem var dsk inserted in front of local paths. BE carefull to manualy
rem delete disk label from GTE.INI ClientInitDir.
Rem When this problem is solved, just set dsk to nothing (null)
set dsk=c:
if not %DBG%==yes goto :ChkParams

rem -------------------------------------------------------------------
:Debug
rem -------------------------------------------------------------------
rem -----------------------------------------------------
rem Program system name to set environment (Like RG - Fujitsu)
echo 1-%1-
rem -----------------------------------------------------
rem Replaced by Area name (Fujitsu) UNIX initial path   /home/users/
echo 2-%2-
rem -----------------------------------------------------
rem LOCAl initial path  c:\data\ or \DATA\  OR "samba" if using samba mounted drive
rem instead of RCP
echo 3-%3-
rem -----------------------------------------------------
rem UNIX server name    nezsdc
echo 4-%4-
rem -----------------------------------------------------
rem username            andrejf
echo 5-%5-
rem -----------------------------------------------------
rem password            xxxzzzyyy
echo 6-%6-
rem -----------------------------------------------------
rem UNIX path relative to initial path       andrejf/job_post/
echo 7-%7-
rem -----------------------------------------------------
rem LOCAL path relative to initial path      andrejf\job_post\
echo 8-%8-
rem -----------------------------------------------------
rem filename            file.ext
echo 9-%9-


rem -----------------------------------------------------
pause

rem -------------------------------------------------------------------
:ChkParams
rem -------------------------------------------------------------------
if %1!==! Goto :Perr1
if %2!==! Goto :Perr2
if %3!==! Goto :Perr3
rem if %4!==! Goto :Perr4
rem if %5!==! Goto :Perr5
rem if %6!==! Goto :Perr6
rem if %7!==! Goto :Perr7
rem if %8!==! Goto :Perr8
rem if %9!==! Goto :Perr9

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


if %3!==samba! goto :RunMake
rem -------------------------------------------------------------------
:ExecOut
rem -------------------------------------------------------------------
rem 1: copy file to unix:
rem rcp -a %3%8%9 %4.%5:%2%7rcompile.4gl
rem do RCP only if filemane is 4gl/5gl/per open in editor at the moment
rem rcp -a %3%8%9 %4.%5:/home/users/andrejf/cmpl/%9
rem echo Done: rcp -a %3%8%9 %4.%5:/home/users/andrejf/cmpl/%9
rem pause
if errolevel==9 goto :err9
if errolevel==8 goto :err8
if errolevel==7 goto :err7
if errolevel==6 goto :err6
if errolevel==5 goto :err5
if errolevel==4 goto :err4
if errolevel==3 goto :err3
if errolevel==2 goto :err2
if errolevel==1 goto :err1


:RunMake
rem if %DBG%==yes echo Running rexec -a -l %5 -p mypass  %4 rmake.sh %9 %1 %2
rem if %DBG%==yes rexec -a -l %5 -p mypass  %4 rmake.sh %9 %1 %2
rem if %DBG%==yes pause

rem if %DBG%==yes echo Now same thing into file...
rem 2: call rcompile.sh script to perform compile, and check for errors
rem start /w /m rexec -a -l %5 -p mypass  %4 rmake.sh %9 %1 %2 > rmkerr.bat
rem rmkerr.bat
if %DBG%==yes if %site%==CSI echo rexec -a -l %5 -p mypass %4 rmake.sh %9 %1 %2

if %site%==Fujitsu rexec -a -l %5 -p mypass %4 rmake.sh %9 %1 %2  > rmkerr.bat
if %site%==CSI rexec -a -l %5 -p %6 %4 GWDagents/rmake.sh %9 %1 %2 > rmkerr.bat

if %DBG%==yes echo -------------------------------------------------- START rmkerr.bat
if %DBG%==yes type rmkerr.bat
if %DBG%==yes echo -------------------------------------------------- END rmkerr.bat
rem echo Done: rmake.sh %9 %1 %2
if %DBG%==yes pause
rem 3: call created bat file to set variables inedtifyng errors
SET MAKE_ERR=
SET PATH_BASE=
SET MAKEPRG=

SET ERR_FILE1=
SET ERR_EXT1=
SET ERR_FILE2=
SET ERR_EXT2=
SET ERR_FILE3=
SET ERR_EXT3=
SET ERR_FILE4=
SET ERR_EXT4=
SET ERR_FILE5=
SET ERR_EXT5=
SET ERR_FILE6=
SET ERR_EXT6=
SET ERR_FILE7=
SET ERR_EXT7=
SET ERR_FILE8=
SET ERR_EXT8=
SET ERR_FILE9=
SET ERR_EXT9=
SET ERR_FILE10=
SET ERR_EXT10=

rem if %DBG%==yes dir rmkerr.bat
rem if %DBG%==yes pause
call rmkerr.bat > nul

if %DBG%==yes echo MAKEPRG  is %MAKEPRG%
if %DBG%==yes echo MAKE_ERR  is %MAKE_ERR%
if %DBG%==yes echo PATH_BASE  is %PATH_BASE%
if %DBG%==yes echo ERR_FILE1 is %ERR_FILE1%
if %DBG%==yes echo ERR_EXT1 is %ERR_EXT1%
if %DBG%==yes echo ERR_FILE2 is %ERR_FILE2%
if %DBG%==yes echo ERR_EXT2 is %ERR_EXT2%

if %DBG%==yes pause
if %MAKE_ERR%==ERROR goto :cmplerr
del makeErr.ini
goto :ChkSucc


rem --------------------------------------------------------------------
:cmplerr
rem --------------------------------------------------------------------
rem create flag file so we can detect that shit happened from GWD
echo "error" > make_err.flg

if %3!==samba! goto :OpenErrNFS

rem 4: get created err file from unix
rem -----------------------------------------------------
rem   4      5        3        8         1
rem server user LOCALinitial LOCALrelat SYS
rem cd
rem call geterfil to rcopy err file to local hd and rename it to original
rem extension:
rem call geterfil.bat nezsdc andrejf \DATA\ RT\src\ RT in_param per
rem echo if not !%ERR_FILE1%=! call geterfil.bat %4 %5 %3 %8 %1 %ERR_FILE1% %ERR_EXT1%
if not !%ERR_FILE1%==! call geterfil.bat %4 %5 %3 %8 %1 %ERR_FILE1% %ERR_EXT1%
if not !%ERR_FILE2%==! call geterfil.bat %4 %5 %3 %8 %1 %ERR_FILE2% %ERR_EXT2%
if not !%ERR_FILE3%==! call geterfil.bat %4 %5 %3 %8 %1 %ERR_FILE3% %ERR_EXT3%
if not !%ERR_FILE4%==! call geterfil.bat %4 %5 %3 %8 %1 %ERR_FILE4% %ERR_EXT4%
if %DBG%==yes pause

:OpenErrRCP
rem 5: open err file renamed to real extension in editor...
if not !%ERR_FILE1%==! start "%3%8%ERR_FILE1%.%ERR_EXT1%"
if not !%ERR_FILE2%==! start "%3%8%ERR_FILE2%.%ERR_EXT2%"
if not !%ERR_FILE3%==! start "%3%8%ERR_FILE3%.%ERR_EXT3%"
if not !%ERR_FILE4%==! start "%3%8%ERR_FILE4%.%ERR_EXT4%"
goto :ChkSucc


:OpenErrNFS
rem 5: open err file renamed to real extension in editor...
rem echo %PATH_BASE%
rem if not !%ERR_FILE1%==! echo start "\\%4%PATH_BASE%\%ERR_FILE1%.%ERR_EXT1%"
rem if not !%ERR_FILE1%==! start "\\%4%PATH_BASE%\%ERR_FILE1%.%ERR_EXT1%"
rem if not !%ERR_FILE2%==! start "%3%8%ERR_FILE2%.%ERR_EXT2%"
rem if not !%ERR_FILE3%==! start "%3%8%ERR_FILE3%.%ERR_EXT3%"
rem if not !%ERR_FILE4%==! start "%3%8%ERR_FILE4%.%ERR_EXT4%"


del makeErr.ini
if !%ERR_FILE1%==! goto :ChkSucc
echo [1] > makeErr.ini
echo Path=%PATH_BASE% >> makeErr.ini
echo File=%ERR_FILE1% >> makeErr.ini
echo Ext=%ERR_EXT1% >> makeErr.ini

if !%ERR_FILE2%==! goto :ChkSucc
echo [2] > makeErr.ini
echo Path=%PATH_BASE% >> makeErr.ini
echo File=%ERR_FILE2% >> makeErr.ini
echo Ext=%ERR_EXT2% >> makeErr.ini

if !%ERR_FILE3%==! goto :ChkSucc
echo [3] > makeErr.ini
echo Path=%PATH_BASE% >> makeErr.ini
echo File=%ERR_FILE3% >> makeErr.ini
echo Ext=%ERR_EXT3% >> makeErr.ini

if !%ERR_FILE4%==! goto :ChkSucc
echo [4] > makeErr.ini
echo Path=%PATH_BASE% >> makeErr.ini
echo File=%ERR_FILE4% >> makeErr.ini
echo Ext=%ERR_EXT4% >> makeErr.ini

if !%ERR_FILE5%==! goto :ChkSucc
echo [5] > makeErr.ini
echo Path=%PATH_BASE% >> makeErr.ini
echo File=%ERR_FILE5% >> makeErr.ini
echo Ext=%ERR_EXT5% >> makeErr.ini

rem :EndRcp

rem -------------------------------------------------------------------
:ChkSucc
rem -------------------------------------------------------------------

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
rem if not %warn%==AlreadyExists start "%dsk%%3%8TakeOut.Log"

rem -------------------------------------------------------------------
:End
rem -------------------------------------------------------------------
set warn=
set dsk=
rem echo end...
rem pause
