@echo off
rem Manupulating shortcut files (.lnk) on Windows is close to impossible.
rem Windows is not treating them as files, so we are forced to rename them before
rem we pack them in zip file, and when they are in place, rename them back.

copy "Aubit 4gl GUI app mouse test.lnk.hide" "Aubit 4gl GUI app mouse test.lnk"
copy "Aubit 4gl app with GUI widget in console.lnk.hide" "Aubit 4gl app with GUI widget in console.lnk"
copy "Aubit 4gl app with GUI widget.lnk.hide" "Aubit 4gl app with GUI widget.lnk"
copy "Aubit 4gl multithread test.lnk.hide" "Aubit 4gl multithread test.lnk"
copy "Aubit 4gl simple app.lnk.hide" "Aubit 4gl simple app.lnk"
copy "Aubit4gl ODBC access test.lnk.hide" "Aubit4gl ODBC access test.lnk"
echo Done.