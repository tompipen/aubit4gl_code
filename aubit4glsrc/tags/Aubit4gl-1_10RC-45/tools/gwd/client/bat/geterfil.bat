@echo off
rem nezsdc andrejf \DATA\       RT\src\    RT  in_param      per
rem   1      2        3            4       5      6           7
rem server user   LOCALinitial LOCALrelat SYS  %ERR_FILE1%  %ERR_EXT1%
if exist "%3%5\src\%6.ba1" del "%3%5\src\%6.ba1"
if exist "%3%5\src\%6.%7" ren "%3%5\src\%6.%7" %6.ba1
rcp -b %1.%2:%PATH_BASE%/%5/src/%6.err "%3%5\src\%6.%7"
rem echo Done:rcp -b %1.%2:%PATH_BASE%/%5/src/%6.err "%3%5\src\%6.%7"
rem Done:rcp -b nezsdc.andrejf:/property1/release/gui/src/RT/src/in_param.err "\DATA\RT\src\in_param.per"
rem Done:rcp -b nezsdc.andrejf:/property1/release/gui/src/RT/src/parameter.err "\DATA\RT\src\parameter.4gl"
rem pause

