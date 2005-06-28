database patern
main
  define
  tclInterpID int,
  tclResult  char(60)

  call Tcl4gl_CreateInterp() returning tclInterpID
  call Tcl4gl_Startup(tclInterpID, "foo") returning tclResult
  call Tcl4gl_DeleteInterp(tclInterpID)
end main
