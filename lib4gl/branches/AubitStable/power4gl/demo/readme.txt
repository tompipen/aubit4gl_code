Welcome to the Power-4gl Demo program:

The following guidelines should help you to get started. It is assumed that you
are currently in the Power-4gl directory. Also assumed is that you have
environment variables set, including the Informix directory and the database
server, which will allow you to create a database and compile programs.

1. Run the script file "setup.sh". The demo database will be imported and
   the programs will be compiled. If you wish to use the c-compiler version of
   4gl then you must run "comp.sh" to compile the programs after "setup.sh".

2. Make sure the terminal is correctly set up. Included is a "termcap" file
   which contains a typical termcap entry for the Reflection terminal emulator
   and for the DEC vt220. If you are using Reflection or a similar emulator,
   you should map the keyboard to work best with the demo program, as in the
   Reflection script "pow4gl.rcl".

3. Run the script file "demo.sh" to start the demo program. If there are
   problems with the keyboard or display, adjust the termcap file or your
   terminal settings (the escape character can be used to exit). For the
   c-compiler version, run "demo.4ge".

The source modules "func.4gl", "menu.4gl", "list.4gl" and "report.4gl", along
with the c modules contain a subset of the Power-4gl toolkit. All other 4gl
modules are part of the demo program and can be viewed to get an idea of how
things work.

Please contact me at john@rl.is if there are any problems.

Have fun!

John H. Frantz
