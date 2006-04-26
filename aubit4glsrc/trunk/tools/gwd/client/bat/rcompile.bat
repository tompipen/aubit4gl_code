@echo off
rem --------------------------------------------------------------------
rem --------------------- rcompile.Bat -------------------------------------
rem --------------------------------------------------------------------
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
rem DO NOT FORGET + OR * IN .RHOSTS FILE ON REMOTE HOST !!!!!!!!!!!!!!!!!
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
:start

set site=CSI
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
rem NOT! Name of program on remote system thet will execute compile (rcompile.sh)
rem Program system name to set environment
echo 1%1-
rem -----------------------------------------------------
rem UNIX initial path   /home/users/
rem or full NT path to the sourcefile FROM CLIENT for samba,
rem including drive letter or computer name if URL
echo 2%2-
rem -----------------------------------------------------
rem LOCAl initial path  c:\data\ or \DATA\  OR "samba" if using samba mounted drive
rem instead of RCP
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
rem UNIX path relative to initial path       andrejf/job_post/
rem or full UNIX path for sabma
echo 7%7-
rem -----------------------------------------------------
rem LOCAL path relative to initial path      andrejf\job_post\
echo 8%8-
rem -----------------------------------------------------
rem filename            file.ext
echo 9%9-


rem -----------------------------------------------------
pause


rem -------------------------------------------------------------------
:ChkParams
rem -------------------------------------------------------------------
if %1!==! Goto :Perr1
if %2!==! Goto :Perr2
rem if %3!==! Goto :Perr3
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
goto :end
rem goto :ContPar
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
if %3!==samba! goto :RunCmpl


rem -------------------------------------------------------------------
:ExecOut
rem -------------------------------------------------------------------
rem 1: copy file to unix:
rem rcp -a %3%8%9 %4.%5:%2%7rcompile.4gl
rcp -a %3%8%9 %4.%5:/home/users/andrejf/cmpl/%9
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

rem -------------------------------------------------------------------
:RunCmpl
rem -------------------------------------------------------------------
rem 2: call rcompile.sh script to perform compile, and check for errors
if %site%==Fujitsu start /w /m rexec -a -l %5 -p mypass  %4 rcompile.sh %2%7%9 %1 %2%7 > rcmplerr.bat
rem CSI: rexec -l afalout -p aaa chaix GWDagents/rcompile.sh /apps/max_4.00/repw/csi_p.4gl dummy /apps/max_4.00/repw samba
rem if %site%==CSI rexec -a -l %5 -p %6 %4 GWDagents/rcompile.sh %2%9 dummy %2 %3 > rcmplerr.bat
if %site%==CSI rexec -a -l %5 -p %6 %4 GWDagents/rcompile.sh %7/%9 dummy %7 %3 > rcmplerr.bat

rem echo -------------------------------------------------- START rcmplerr.bat
rem type rcmplerr.bat
rem echo -------------------------------------------------- END rcmplerr.bat
rem echo Done: rexec -a -l %5 -p mypass  %4 rcompile.sh %2%7%9 %1 %2%7
rem pause
rem 3: call created bat file to set variables inedtifyng errors
SET COMP_EXT=
SET COMP_FILE=
SET COMPILE=
call rcmplerr.bat > nul

rem echo COMPILE   is %COMPILE%
rem echo COMP_FILE is %COMP_FILE%
rem echo COMP_EXT  is %COMP_EXT%

rem pause
if %COMPILE%==ERROR goto :cmplerr
goto :ChkSucc


rem --------------------------------------------------------------------
:cmplerr
rem --------------------------------------------------------------------
if %3==samba goto :ChkSucc
rem 4: get created err file from unix
rem echo rcp command will be:
rem rcp -b %4.%5:%2%7%COMP_FILE%.err "%3%8rcompile.err"
rcp -b %4.%5:/home/users/andrejf/cmpl/%COMP_FILE%.err "%3%8%COMP_FILE%.err"
rem echo Done: rcp -b %4.%5:/home/users/andrejf/cmpl/%COMP_FILE%.err "%3%8%COMP_FILE%.err"
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

rem 5: open document in editor...
rem rcompile.c will do that:
rem start "%3%8%COMP_FILE%.err"


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
if not %warn%==AlreadyExists start "%dsk%%3%8TakeOut.Log"

rem -------------------------------------------------------------------
:End
rem -------------------------------------------------------------------
set warn=
set dsk=
