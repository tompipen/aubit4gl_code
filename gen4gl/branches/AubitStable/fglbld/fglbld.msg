#	@(#)fglbld.msg	6.6 89/11/14
#	@(#)FGLBLD Version 6.12 (04/04/1990)
#	@(#)Help Messages

.0
@(#)fglbld.msg	6.6 89/11/14
@(#)FGLBLD Version 6.12 (04/04/1990)

###########################################################################
# Main Menu
###########################################################################
.20

Create a Simplified Perform Interface program.

This is similar to what PERFORM would provide, but can quickly be extended
beyond what PERFRM can handle.

It will generate something of the order of 1500 lines of Informix-4GL code
for a table of normal size -- say 5-15 columns.

It also generates a message file, a screen form, and a makefile automatically.
Obviously, both the form and the message files will need editing.

Sometimes the form file needs editing before it can be used at all.
This occurs when a field in the table is too big for FORMBUILD to fit
on one line, which means that the field length is greater than about
40 characters.

.21

Create a pop-up function, possibly for use in an SPI generated previously.

The name of the function will be ch_tablename.

A pop-up function pops up a window and gives the user a list of
objects from which to choose (in a DISPLAY ARRAY).

There are two sub-types of pop-up:

	Conditional   -- the user can specify which data is to be shown
	Unconditional -- the user always gets given the complete set of data
					 from the table to choose from.

.22

Modify code.

This option allows you to edit just about any file you want.

.23

Build the program.

This runs make to re-build the current program.

.24

Run the program.

This runs the current program.

.25

Exit from the FGLBLD program.

.26

If there is already a program name, this allows you to change it.
If there is no program name yet, it allows you to set it.

.29

Create a fetch function.

The name of the function will be sel_tablename.

This function will be given the primary key value and will fetch and return
the complete row of data corresponding to that value.

It carefully caches the last row fetched so that it can avoid going back to the
database if it already has the data.  Beware: if the user can change the data,
you should call the routine inv_tablename to invalidate the cached data,
AND YOU MUST USE IT!

.30

Choose a new database.

This allows you to change the database you are working with.

I'm sorry, but I cannot offer you a list of available databases.

.32

Choose a new database.

Enter the name of the new database.

If it cannot be opened, you will be told.
If you leave the database name blank, the old database will be used.

I'm sorry, but I cannot offer you a list of available databases.

.33

Enter the name of the database.

You cannot specify a path name (unless it is very short).
Do not include the `.dbs' extension.

.35

Change the name of the files.

This changes the basename of the files.  When you edit files, this value
will be used to determine the file that is edited.  When you run a program,
it will be a program with this name.


###########################################################################
# Generic help for INPUT statements
###########################################################################
# SPI
###########################################################################
.40

Use CONTROL-F to obtain help about a specific field.

You are defining the control parameters for a
	Simplified Perform Interface or SPI.

This input statement expects you to define:
	1.	the table within the database,
	2.	the column which is the primary key,
	3.	the title for the SPI menu and the
	4.	basename of the files to be generated.
If these are not defined, FGLBLD will not generate an SPI.

Additionally, you can exercise some control over the code which is generated
by specifying which options which should be included.  If you do not specify
either Add or Update (or both), no input code will be generated.

###########################################################################
# Conditional Popup
###########################################################################
.50

Use CONTROL-F to obtain help about a specific field.

You are defining the control parameters for a
	Conditional Popup or CPOPUP.

This input statement expects you to define:
	1.	the table within the database,
	2.	the column which is the primary key,
	3.	basename of the files to be generated,
	4.	the name of the type of object the user is choosing.
If these are not defined, FGLBLD will not generate a CPOPUP.

NB: the function will return the primary key corresponding to the item selected
by the user.

###########################################################################
# Unconditional Popup
###########################################################################
.60

Use CONTROL-F to obtain help about a specific field.

You are defining the control parameters for an
	Unconditional Popup or UPOPUP.

This input statement expects you to define:
	1.	the table within the database,
	2.	the column which is the primary key,
	3.	basename of the files to be generated,
	4.	the name of the type of object the user is choosing.
If these are not defined, FGLBLD will not generate a UPOPUP.

NB: the function will return the primary key corresponding to the item selected
by the user.

###########################################################################
# Fetch
###########################################################################
.70

Use CONTROL-F to obtain help about a specific field.

You are defining the control parameters for a
	Fetch Function or FETCH.

This input statement expects you to define:
	1.	the table within the database,
	2.	the column which is the primary key,
	3.	basename of the files to be generated,
If these are not defined, FGLBLD will not generate a FETCH.

###########################################################################
# Help for the SPI input function
###########################################################################
.100

Specify the name of the table which the user should work on.

If you cannot remember the name of the table, you can use the F5 key
(or CONTROL-B) to choose from a list.  If you do that, you get the
opportunity to do a query-by-example on the tables you want choose from.

.101

Specify the name of the column in the table which is the primary key for
this table.  

If you cannot remember the name of the column, you can use the F5 key
(or CONTROL-B) to choose from a list.  

If the table has a composite primary key, you should specify that ROWID
is the primary key.  This can be typed in (in upper case) or chosen from
the list.

.102

This is the name of the menu which will be used.

In general, it should be kept to less than 14 characters; if it is 
longer, the menu will have several pages denoted by `...' at the edges.

.103

This is the basename for the files which will be generated.

All the generated files will start with this name; they will either have
an extension such as `.msg' (for the message file), or they will be
followed by a letter and the extension `.4gl' (for the source files).
If you enter the name `base', the generated files will be:

	base.4pr
	base.mk
	base.msg

	basec.4gl
	baseg.4gl
	basei.4gl
	basem.4gl
	baser.4gl

Certain other files will be copied into the directory; these are library files
and should not need to be changed.

.104

If you want the code to include an `Add' option to allow users to add data to
this table, specify `Y' in this field.

NB: if both the `Add' option and the `Update' option are set to `N',
no input code will be generated.

.105

If you want the input code to include `AFTER FIELD' clauses (which should
normally be the case), specify `Y' in this field.

.106

If you want the input code to include `BEFORE FIELD' clauses (which should
normally be the case), specify `Y' in this field.

.107

If you want the input code to include `ON KEY(F5, CONTROL-B)' clauses
(which will be the case if you intend to provide the user with any pop-up
choices), specify `Y' in this field.

.108

If you want the input code to include `ON KEY(F6, CONTROL-P)' clauses
(which is normally the case since it allows the user to copy the value
previously entered into this field again), specify `Y' in this field.

.109

If you want the code to include an `Delete' option to allow users to
delete  data from this table, specify `Y' in this field.

.110

If you want the code to include an `Update' option to allow users to
update data in this table, specify `Y' in this field.

NB: if both the `Add' option and the `Update' option are set to `N',
no input code will be generated.

.111

If you want the code to include an `Report' option to allow users to
produce a report on the data in this table, specify `Y' in this field.

.112

If you want the code to include a hidden `Shell Escape' option to allow
users to run any Unix command they wish, specify `Y' in this field.

The command will be activated by typing `!'.

###########################################################################
# Help for the Popup menu
###########################################################################
.151

Conditional Pop-up or CPOPUP.

Create a pop-up function, possibly for use in an SPI generated previously.

The name of the function will be ch_tablename.

A pop-up function pops up a window and gives the user a list of
objects from which to choose (in a DISPLAY ARRAY).

With a conditional pop-up, the user can specify which data is to be shown

.152

Unconditional Pop-up or UPOPUP.

Create a pop-up function, possibly for use in an SPI generated previously.

The name of the function will be ch_tablename.

A pop-up function pops up a window and gives the user a list of
objects from which to choose (in a DISPLAY ARRAY).

With an unconditional pop-up, the user always gets given the same
set of data from the table to choose from.  Normally, this will be
all the data, unless there are more rows than can be stored in the
arrays in the generated function.

.153

Exit from the POP-UP TYPE menu.

This will take you back to the main FGLBLD menu.

###########################################################################
# Help for the Conditional Popup input function
###########################################################################
.200

Specify the name of the table which the user should work on.

If you cannot remember the name of the table, you can use the F5 key
(or CONTROL-B) to choose from a list.  If you do that, you get the
opportunity to do a query-by-example on the tables you want choose from.

.201

Specify the name of the column in the table which is the primary key for
this table.  

If you cannot remember the name of the column, you can use the F5 key
(or CONTROL-B) to choose from a list.  

If the table has a composite primary key, you should specify that ROWID
is the primary key.  This can be typed in (in upper case) or chosen from
the list.

.202

This is the name of the menu which will be used.

.203

This is the basename for the files which will be generated.

All the generated files will start with this name.
If you enter the name `base', the generated files will be:

	base.4gl
	base.4pr

.204

This is the name of the type of thing which is selected.

This text should be entered in the singular; it is used in two messages
which can be displayed under certain error conditions.  If the noun is
not made into a plural by adding an `s', you will need to modify the
generated source appropriately.

###########################################################################
# Help for the Unconditional Popup input function
###########################################################################
.300

Specify the name of the table which the user should work on.

If you cannot remember the name of the table, you can use the F5 key
(or CONTROL-B) to choose from a list.  If you do that, you get the
opportunity to do a query-by-example on the tables you want choose from.

.301

Specify the name of the column in the table which is the primary key for
this table.  

If you cannot remember the name of the column, you can use the F5 key
(or CONTROL-B) to choose from a list.  

If the table has a composite primary key, you should specify that ROWID
is the primary key.  This can be typed in (in upper case) or chosen from
the list.

.302

This is the basename for the files which will be generated.

All the generated files will start with this name.
If you enter the name `base', the generated files will be:

	base.4gl
	base.4pr

.303

This is the name of the type of thing which is selected.

This text should be entered in the singular; it is used in two messages
which can be displayed under certain error conditions.  If the noun is
not made into a plural by adding an `s', you will need to modify the
generated source appropriately.

###########################################################################
# Help for the Fetch input function
###########################################################################
.401

Specify the name of the table which the user should work on.

If you cannot remember the name of the table, you can use the F5 key
(or CONTROL-B) to choose from a list.  If you do that, you get the
opportunity to do a query-by-example on the tables you want choose from.

.402

Specify the name of the column in the table which is the primary key for
this table.  

If you cannot remember the name of the column, you can use the F5 key
(or CONTROL-B) to choose from a list.  

If the table has a composite primary key, you should specify that ROWID
is the primary key.  This can be typed in (in upper case) or chosen from
the list.

.403

This is the basename for the file which will be generated.

If you enter the name `base', the generated file will be:

	base.4gl

###########################################################################
# Help messages for Edit option
###########################################################################
.530

Edit source code.

This will run the program indicated by DBEDIT (defaulting to vi without asking
questions) to edit one of the source files indicated by choosing from a
sub-menu.

.531

Edit the form file.

This will run the program indicated by DBEDIT (defaulting to vi without asking
questions) to edit the form file for the current program.

If the current basename is `base', the edited file will be:

	base.4pr

.532

Edit the help message file.

This will run the program indicated by DBEDIT (defaulting to vi without asking
questions) to edit the help message file for the current program.

If the current basename is `base', the edited file will be:

	base.msg

.533

Edit the makefile.

This will run the program indicated by DBEDIT (defaulting to vi without asking
questions) to edit the help message file for the current program.

If the current basename is `base', the edited file will be:

	base.mk

.534

Build the program.

This runs make to re-build the current program.

If the current basename is `base', the command executed will be:

	make -f base.mk

.535

Run the program.

This runs the current program.

If the current basename is `base', the program run will be:

	base.4ge
or
	fglgo base.4gi

.536

Change the name of the files.

This changes the basename of the files.  When you edit files, this value
will be used to determine the file that is edited.  When you run a program,
it will be a program with this name.

.537

Exit from the EDITING menu.

This will take you back to the main FGLBLD menu.

.540

Edit the input source file.

If the current basename is `base', the edited file will be:

	basei.4gl

.541

Edit the report source file.

If the current basename is `base', the edited file will be:

	baser.4gl

.542

Edit the cursor source file.

If the current basename is `base', the edited file will be:

	basec.4gl

.543

Edit the main source file.

If the current basename is `base', the edited file will be:

	basem.4gl

.544

Edit the globals source file.

If the current basename is `base', the edited file will be:

	baseg.4gl

.545

Edit a source file with any suffix.

This could be a popup function or a fetch function generated by FGLBLD
or any other I4GL source file.

If the current basename is `base', the edited file will be:

	base.4gl

.546

Exit from the SOURCE menu.

Does not edit any file and returns you to the EDITING menu.

