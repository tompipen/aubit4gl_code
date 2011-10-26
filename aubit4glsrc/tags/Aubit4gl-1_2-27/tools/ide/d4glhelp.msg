# @(#)$Id: d4glhelp.msg,v 1.1.1.1 2001-08-20 02:37:07 afalout Exp $
# @(#)D4GL: Alternative D4GL compiling front-end
# @(#)Help messages for D4GL
# ---------------------------------------------------------------
# Messages formatted with left-justified text and right margin
# set to 65 (fill -l65).
# ---------------------------------------------------------------
# Help messages for d4glmain.4gl
.2
MAIN MENU/Module

Use this option to modify or compile D4GL source code.

It leads to the D4GL COMPILER menu, which allows you to specify
the compiler and compilation options, to edit or compile a source
file, and build a program.

You can also use this option to edit help files or makefiles.

.3
MAIN MENU/Form

Use the option to modify of compile D4GL form files.

It leads to the FORM COMPILER menu, which allows you to specify
the form compiler and options, to edit of compile a form file,
and to build a complete program.

.4
MAIN MENU/Program

Use this option to change the name of the program which is
run when the Run option is chosen.

.5
MAIN MENU/Build

Use this option to build a complete program.

It will run the MAKE program as specified by the options on display.

.6
MAIN MENU/Run

Use this option to run the program specified.

.7
MAIN MENU/Exit

Use this option to exit from the MAIN MENU (thereby terminating D4GL).

# Help message for INPUT function
.10
You are being requested to enter some data, which is described by
the prompt string.  Enter the relevant string, and hit the ESCAPE
key or the RETURN key to enter the data.

Use the arrow keys to move the data.  The CONTROL-X key deletes
the character under the cursor.  The CONTROL-D key deletes from
the character under the cursor to the end of the field.  The
CONTROL-R key redraws the screen.  The CONTROL-A toggles between
insert mode (the default) and overwrite mode.

# ---------------------------------------------------------------
# Help messages for d4glfile.4gl
.20
MAIN MENU/Module/Compile

Use this option to compile the current source file.

If the compilation succeeds, you will be given the options to
save or discard the changes.  If the compilation fails, you will
be given the options to edit the file (ready for recompilation),
or to save the file as it is, errors and all, or to discard the
changes made since the file was last saved.

.21
MAIN MENU/Module/Modify

Use this option to edit the current source file.

When you quit the editor, you will be given the option of
compiling the file, or of saving the changes you have made, or of
discarding the changes you have made.  If you have not already
specified the name of a file, you will be prompted to do so.

.22
MAIN MENU/Module/File

Use this option to change the name of the source file you are
editing and compiling.

The file need not exist; you can create a file by specifying a
new file name.

You can also use this option to edit makefiles and help message
files.

.23
MAIN MENU/Module/Build

Use this option to run MAKE to build the complete program.

.24
MAIN MENU/Module/Run

Use this option to run the current program.

If you have not already specified the name of the program, you
will be prompted to do so.

.25
MAIN MENU/Module/Options

Use this option to change the D4GL compiler or its options, or
the MAKE options or the editor you are using.

.26
MAIN MENU/Module/Program

Use this option to specify the name of the program to be run.

If you are using the p-code compiler, you would type the name of
the p-code interpreter (or the p-code debugger) and the name of
the p-code program.  If the program takes command line arguments,
you can add them to the program command line.

.27
MAIN MENU/Module/Exit

Exit from the D4GL COMPILER menu.

This normally returns you back to the MAIN MENU, but if you
specified a number of file names on the D4GL command line, it
will move you on to the next file name, which may put you in the
FORM COMPILER or the D4GL COMPILER menus, depending on the file
name.

.30
MAIN MENU/Module/Options/Compiler

Use this option to specify the name of the D4GL source compiler.

The default value is `c4gl', the standard c-code compiler.  You
might want to change it to the p-code compiler, `fglpc', or
specify an absolute pathname.

You can set the compiler on the command line using the `-c'
option followed by the name of the compiler.

.31
MAIN MENU/Module/Options/Options"

Specify extra options for the D4GL source compiler.

The default option is empty.  If the compiler is `c4gl', then the
`-c' option needed to produce an object file will be added
automatically.  If the compiler is not `c4gl' but needs an
equivalent option, you should specify it here.

.32
MAIN MENU/Module/Options/Build"

Use this option to specify the name of the MAKE program.

You would use this if you are using something other than the
standard MAKE program, such as GNU Make.  You may use any MAKE
program which will accept the other options you specify and do
the compilation you want done using the rules in the makefile you
specify.

.33
MAIN MENU/Module/Options/Target"

Use this option to specify the target to be made by MAKE.

If no value is specified, the default target in the makefile will
be made.

.34
MAIN MENU/Module/Options/Flags"

Use this option to specify any special flags for the MAKE
program.

Typical uses might be to add `-k' to try to compile as much as
possible, or a MACRO=value setting to alter the compilation in
some way.

.35
MAIN MENU/Module/Options/Makefile"

Use this option to specify the name of the makefile.

If no name is specified, then MAKE will determine which makefile
it uses.  The name specified here will be prefixed with the `-f'
option.

.36
MAIN MENU/Module/Options/Visual"

Use this option to specify the name of the editor.

If you do not use vi, the editor will not be invoked in such a
way as to find the first error in an error report file.

.37
MAIN MENU/Module/Options/Exit"

Use this option to leave the D4GL OPTIONS menu without making any
changes ot the options.

You will be returned to the D4GL COMPILER menu.  Selecting any of
the other options allows you to change an option value but then
returns you to the D4GL COMPILER menu.

.40
MAIN MENU/Module/Compile/Failed/Correct

Use this option to edit the error file, fixing any mistakes.

You should save the file direct to the error file.  You do not
need to remove the error messages; D4GL automatically does that
as it renames the error file to the source file name.

.41
MAIN MENU/Module/Compile/Failed/Save

Use this option to save the edited version of the file, despite
the fact that it failed to compile.

You would typically use this option when the trouble is actually
not in the file but somewhere else.  A typical example would be
that the database is not accessible, either because the system is
down or because the environment is not correct.

.42
MAIN MENU/Module/Compile/Failed/Discard

Use this option to discard the edited version of the file and
reinstate the previous version of the file.

.50
MAIN MENU/Module/Compile/Succeeded/Save

Use this option to save the edited version of the file after the
successful compilation.

.51
MAIN MENU/Module/Compile/Succeeded/Discard

Use this option to discard the edited version of the file and
reinstate the previous version of the file, despite the fact that
the compilation succeeded.

.60
MAIN MENU/Module/Compile/Failed/Correct/Compile

Use this option to recompile the source file after editing it to
correct the errors.

.61
MAIN MENU/Module/Compile/Failed/Correct/Save

Use this option to save the corrected source file without
compiling it to ensure that the errors were corrected.

.62
MAIN MENU/Module/Compile/Failed/Correct/Discard

Use this option to discard the corrected source file without
compiling it to ensure that the errors were corrected.  The
previous saved version of the file will be reinstated.

.70
MAIN MENU/Module/Modify/Compile/Compile

Use this option to compile the edited version of the source file.

.71
MAIN MENU/Module/Modify/Compile/Save

Use this option to save the edited version of the source file
without compiling it to ensure there are no errors in it.

.72
MAIN MENU/Module/Modify/Compile/Discard

Use this option to discard the edited version of the source file
and reinstate the previous version.

# ---------------------------------------------------------------
# Help messages for d4glform.4gl
.80
MAIN MENU/Form/Compile

Use this option to compile the current form.

If the compilation succeeds, you will be given the options to
save or discard the changes.  If the compilation fails, you will
be given the options to edit the form (ready for recompilation),
or to save the form as it is, errors and all, or to discard the
changes made since the form was last saved.

.81
MAIN MENU/Form/Modify

Use this option to edit the current form.

When you quit the editor, you will be given the option of
compiling the form, or of saving the changes you have made, or of
discarding the changes you have made.  If you have not already
specified the name of a form, you will be prompted to do so.

.82
MAIN MENU/Form/Form

Use this option to change the name of the form you are editing
and compiling.

The form need not exist; you can create a form by specifying a
new form name.

.83
MAIN MENU/Form/Build

Use this option to run MAKE to build the complete program.

.84
MAIN MENU/Form/Run

Use this option to run the current program.

If you have not already specified the name of the program, you
will be prompted to do so.

.85
MAIN MENU/Form/Options

Use this option to change the form compiler or its options, or
the MAKE options or the editor you are using.

.86
MAIN MENU/Form/Program

Use this option to specify the name of the program to be run.

If you are using the p-code compiler, you would type the name of
the p-code interpreter (or the p-code debugger) and the name of
the p-code program.  If the program takes command line arguments,
you can add them to the program command line.

.87
MAIN MENU/Form/Exit

Exit from the FORM COMPILER menu.

This normally returns you back to the MAIN MENU, but if you specified
a number of file names on the D4GL command line, it will move you on
to the next file name, which may put you in the FORM COMPILER or the
D4GL COMPILER menus, depending on the file name.

.90
MAIN MENU/Form/Options/Compiler

Use this option to specify the name of the form compiler.

The default value is `form4gl', the standard compiler.  You might
want to set it to an absolute path name, or to some other form
compiler altogether (eg `sformbld').

.91
MAIN MENU/Form/Options/Options

Specify extra options for the form compiler.

The default option is `-q' which avoids printing version
information on the screen.  Other options can be added, or the
field can be left blank, as required.

.92
MAIN MENU/Form/Options/Build

Use this option to specify the name of the MAKE program.

You would use this if you are using something other than the
standard MAKE program, such as GNU Make.  You may use any MAKE
program which will accept the other options you specify and do
the compilation you want done using the rules in the makefile you
specify.

.93
MAIN MENU/Form/Options/Target

Use this option to specify the target to be made by MAKE.

If no value is specified, the default target in the makefile will
be made.

.94
MAIN MENU/Form/Options/Flags

Use this option to specify any special flags for the MAKE
program.

Typical uses might be to add `-k' to try to compile as much as
possible, or a MACRO=value setting to alter the compilation in
some way.

.95
MAIN MENU/Form/Options/Makefile

Use this option to specify the name of the makefile.

If no name is specified, then MAKE will determine which makefile
it uses.  The name specified here will be prefixed with the `-f'
option.

.96
MAIN MENU/Form/Options/Visual

Use this option to specify the name of the editor.

If you do not use vi, the editor will not be invoked in such a
way as to find the first error in an error report file.

.97
MAIN MENU/Form/Options/Exit

Use this option to leave the FORM OPTIONS menu without making any
changes ot the options.

You will be returned to the FORM COMPILER menu.  Selecting any of
the other options allows you to change an option value but then
returns you to the FORM COMPILER menu.


.100
MAIN MENU/Form/Compile/Failed/Correct

Use this option to edit the error file, fixing any mistakes.

You should save the file direct to the error file.  You do not
need to remove the error messages; D4GL automatically does that
as it renames the error file to the form file name.

.101
MAIN MENU/Form/Compile/Failed/Save

Use this option to save the edited version of the file, despite
the fact that it failed to compile.

You would typically use this option when the trouble is actually
not in the file but somewhere else.  A typical example would be
that the database is not accessible, either because the system is
down or because the environment is not correct.

.102
MAIN MENU/Form/Compile/Failed/Discard

Use this option to discard the edited version of the file and
reinstate the previous version of the file.

.110
MAIN MENU/Form/Compile/Succeeded/Save

Use this option to save the edited version of the file after the
successful compilation.

.111
MAIN MENU/Form/Compile/Succeeded/Discard

Use this option to discard the edited version of the file and
reinstate the previous version of the file, despite the fact that
the compilation succeeded.

.120
MAIN MENU/Form/Compile/Failed/Correct/Compile

Use this option to recompile the form file after editing it to
correct the errors.

.121
MAIN MENU/Form/Compile/Failed/Correct/Save

Use this option to save the corrected form file without
compiling it to ensure that the errors were corrected.

.122
MAIN MENU/Form/Compile/Failed/Correct/Discard

Use this option to discard the corrected form file without
compiling it to ensure that the errors were corrected.  The
previous saved version of the file will be reinstated.

.130
MAIN MENU/Form/Modify/Compile/Compile

Use this option to compile the edited version of the form file.

.131
MAIN MENU/Form/Modify/Compile/Save

Use this option to save the edited version of the form file
without compiling it to ensure there are no errors in it.

.132
MAIN MENU/Form/Modify/Compile/Discard

Use this option to discard the edited version of the form file
and reinstate the previous version.

# EOF for $RCSfile: d4glhelp.msg,v $

