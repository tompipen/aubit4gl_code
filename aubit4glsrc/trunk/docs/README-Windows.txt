            README for Aubit 4GL compiler native Windows port


Limitations:
------------

1) Tested only on W2K

2) Needs Administrator privilege (to write to HCLM)

3) Must reboot to refresh PATH, did not find a way to send SendMessage() to
update running programs without it (Install program uses Pascal scripting -
it has a call, but I know nothing about Pascal and failed to assigne
parameters - any help appreciated). Actally, you can instead go to
Start->Settings->Control Panel->System->Advanced->Environment Varibales->OK
and this will update it too (If you have DOS window open, you will have
to restart it).

4) On Windows 9x, autoexec.bat must be edited to add path to (<install_dir>/bin)

6) Installing outside default path of c:\aubit4gl was not tested. It will
probably work if path don't have spaces it it.

7) There is no TUI support on native Windows - Is there native version od
ncurses libraries for Windows available at all? So you can choose between
GTK (default) and CONSOLE _ONLY_

Note: MinGW package includes make, renamed to mingw32-make.exe


Procedure:
----------

a) Install MinGW (www.mingw.org) first. Only reason for this is that Aubit 
installer will add MinGW to path for you, if it finds it. MinGW installer 
will NOT do this.
b) Install Aubit compiler.
c) Restart or refresh your PATH as described (W2K/NT) or edit your 
autoexec.bat to add path to Aubit and MinGW to PATH variable, and
restart (Windows 9x)
d) Open DOS prompt window; cd to C:\aubit4gl\tools\test; type "make" + enter
e) type "hello" + enter; you should see GUI window of "hello.4gl" demo program


All comments appreciated!


Yours, Andrej Falout, http://www.falout.com/disclaimer.html
Project manager, Aubit project: http://aubit4gl.sourceforge.net
Software architect, MakeTXT.com
PLEASE NOTE: All HTML email sent to me WILL BE DELETED AUTOMATICALLY WITHOUT READING.
