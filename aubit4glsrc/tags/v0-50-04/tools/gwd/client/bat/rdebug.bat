@echo off
AGENTDIR=./GWDagents
rem --------------------------------------------------------------------
rem --------------------- RRUN.Bat -------------------------------------
rem --------------------------------------------------------------------
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
rem DO NOT FORGET + OR * IN .RHOST FILE ON REMOTE HOST !!!!!!!!!!!!!!!!!
REM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
goto :start

:start

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
rem System code to wich source file belongs
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
rem Execute TakeOut command of Version control system on UNIX
rem via REXECd or RSHd services. REXEC autenticates user, RSH does not(?)
rem rexec/rsh host -l username command...
rem -n redirects input of rexec to NULL
rem THIS WILL PROMPT FOR PASSWORD: rexec %4 -l %5 %1 %2%7%9
REM SAME, BUT WITHOUT USERNAME, SO NO PROMPT FOR PASSWORD...
rem rsh %ServerName% %ScriptName% %sourceFileName.Ext% %SysName%
rem rsh nezsdc rrun.sh action_qbf.5gl AN
rem without specifing user:
rem rsh %4 rrun.sh %9 %1
rem with specified user:
start /m rsh -l %5 %4 %AGENTDIR%/rrun.sh %9 %1
rem WORKS !!!! rsh -l andrejf nezsdc $HOME/rrun.sh pc_calc.4gl VJ
rem ***echo command was: rsh -l %5 %4 rrun.sh %9 %1
rem rexec -l %5 -p 11sajonara  %4 rrun.sh %9 %1
echo command was: rexec -l %5 -p 11sajonara  %4 rrun.sh %9 %1
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
