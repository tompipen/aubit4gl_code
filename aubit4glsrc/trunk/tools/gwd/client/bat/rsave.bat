@echo off
set warn=0
rem ------------------ PUTBACK.Bat ----------------------
goto :ChkParams

rem -----------------------------------------------------
rem SCCS putback command     delta
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
goto :End



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

goto :ContPar

:Perr1
echo Parameter No1 to PutBack.Bat is NULL!
Set warn=a
goto :ContPar
:Perr2
echo Parameter No2 to PutBack.Bat is NULL!
Set warn=b
goto :ContPar
:Perr3
echo Parameter No3 to PutBack.Bat is NULL!
Set warn=c
goto :ContPar
:Perr4
echo Parameter No4 to PutBack.Bat is NULL!
Set warn=d
goto :ContPar
:Perr5
echo Parameter No5 to PutBack.Bat is NULL!
Set warn=e
goto :ContPar
:Perr6
echo Parameter No6 to PutBack.Bat is NULL!
Set warn=f
goto :ContPar
:Perr7
echo Parameter No7 to PutBack.Bat is NULL!
Set warn=g
goto :ContPar
:Perr8
echo Parameter No8 to PutBack.Bat is NULL!
Set warn=h
goto :ContPar
:Perr9
echo Parameter No9 to PutBack.Bat is NULL!
Set warn=i
goto :ContPar

:ContPar


:Rcopy
rem echo rcp -a %3%8%9 %4.%5:%2%7xxx.test
rem pause
rem rcp -a %3%8%9 %4.%5:%2%7xxx.test
rem do not use -a (ascii transfer with CR/LF conversion - default mode)
rem     use -b (binary) instead because if you later transfer file by another
rem     means (like FTP) that does not do the translataion, you will end up
rem     with ^M on the end of each line. BUT, when you return files, why not
rem     let rcp try to do conversion - if there are no CR/LFs, no damage
rem     will be done, and if there are, they will be stripped
rem echo rcp -a %3%8%9 %4.%5:%2%7%9
rcp -a %3%8%9 %4.%5:%2%7%9
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

goto :EndRcp

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
if %warn%==0 goto :End
echo Warning! Returning of file %3%8%9 >> c:%3%8TakeOut.log
echo to server %4 with username %5 >> c:%3%8TakeOut.log
echo to location %2%7%9  >> c:%3%8TakeOut.log
echo was NOT succesful !!!! >> c:%3%8TakeOut.log
echo Error returned from RCP.EXE: %warn%  >> c:%3%8TakeOut.log
echo ----------------------------------------------------------- >> c:%3%8TakeOut.log
start c:%3%8TakeOut.log

:End
set warn=


