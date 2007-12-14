Installing AUBIT on MS Windows
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The following notes assume that a database such as SQLServer or Postgres is set up and running, and that ODBC connections have been set up via Administrative Tools.  (In writing 4GL scripts, the database name will be that given in the ODBC settings, which may differ from the name given to the database server.)


1
A DEVELOPER will need to install minGW in order to get the GNU C compiler (gcc).

Installation is straightforward.  Go to www.mingw.org, follow the links to the download section, and download the current Automated MinGW Installer.  Run this, select Minimal, with MinGW base tools, and install.  (Downloading more is fine, but this is all that is needed.)

You will need to get this on your PATH.  Go to System Properties, Advanced, Environment Variables;  and either edit the machine PATH, if you are the Administrator, or set/edit the User Path.   If, for example, MinGW was installed in c:\mingw (the default), then PATH will need to include c:\mingw\bin.

Test by opening a new command window and entering 
gcc -v
which should then output the version details.


2
Download the current AUBIT win32 build and unzip to a convenient directory (eg c:\aubit).  

You will need to set a few variables.  This can be done either through System Properties or by using a batch file (see 5 below).
- AUBITDIR is where you installed AUBIT (eg c:\aubit)
- PATH will need to include %AUBITDIR%\bin;%AUBITDIR%\lib
- A4GL_SQLTYPE needs to be set as "odbc32" - but without the quotation marks
- A4GL_DBDATE may need to be set.  The MS system will tend to output dates in the American format, mm/dd/yyyy.  If you want a European format (dd/mm/yyyy), then set A4GL_DBDATE as "DMY4/" (again, without the quotation marks)

Test in a new command window, by entering
4glc -v
which should then list the version and build details.


3
You should now be able to compile and run the test programs, hello.4gl and helloFORM.per
I use a simple 
4glc hello.4gl -o hello		to compile the 4gl, which outputs to hello.exe
fcompile helloFORM.per		to compile the form, which outputs to helloFORM.afr.dat

Entering
hello
should then execute the program.


4
A developer who wants to use the VI editor might want to download and install Msys, from the same stable as MinGW.  In an Msys shell, the basic *nix commands are available, and "vi" in particular.


5
RUN-TIME settings:

On an example network, all database users have access to the database server with a common drive letter, "y:"
The same AUBIT zip file as used by the developer is unzipped to y:\a4gl, and all the developed EXE files are copied to y:\a4gl\local-bin

A batch file (eg aubit.bat) is created in y:\a4gl\local-bin, as

@echo off
set AUBITDIR=y:\a4gl
set PATH="%AUBITDIR%\bin;%AUBITDIR%\lib;%AUBITDIR%\local-bin;%PATH%
set A4GL_SQLTYPE=odbc32
set A4GL_DBDATE=DMY4/
%AUBITDIR%\local-bin\MAINPROGRAM.exe
exit

where MAINPROGRAM.exe is the 4gl program that calls all the rest - a central menu.
Shortcuts are created to this batch file, on all the users' desktops;  and that's it.  There's probably a lot more in the AUBIT directories than the run-time users need, but its not worth the hassle of minimising them (the AUBIT programs, not the users).
In the above example, the drive letter "y:" could be replaced by the server name, eg "\\DATABASE_SERVER_NAME".



Bernard Moreton
December 2007