# WHATSTR
# @(#)Built by: FGLBLDSTR
# @(#)Help messages
.1

The "Query" option allows you to select one or more rows and to display
their data on the screen by using query-by-example input.

Use the RETURN or arrow keys to move through the form.  Enter the criteria you
want the program to use in searching for rows.  Your options include:

	o literal values
	o a range of values (separated by :)
	o relational operators (for example "> 105")
	o to choose a null field, use =
	o wild cards like * to match any number of characters
	o a selection of values (separated by |)
	o etc.

.2

The "Next" option allows you to display the next row of the current list.

.3

The "Previous" option allows you to display the previous row of the current
list.

.4

The "Add" option enables you to enter new rows into the table.

You may get assistance on what input is appropriate for each field by pressing
the control-w key when the cursor is in the field.  When you have entered
all the data you want for a given row, press ESC to enter the row in the
table.  If you want to abort a given row and not write it to the table,
press the INTERRUPT key (usually DEL or CTRL-C).

.5

The "Delete" option enables you to remove rows from the table.

You must first select a current row to delete by using the "Query" option.
For your protection, you will be asked to confirm that the row should be
deleted.  Once deleted, it cannot be restored.

.6

The "Update" option enables you to alter data on existing rows in the table.

You must first select a current row to update by using the "Query" option.
You may get assistance on what input is appropriate for each field by pressing
the CONTROL-F key when the cursor is in the field.  When you have altered
all the data you want for a given row, press ESC to enter the data in the
table.  If you want to abort the changes and not write them to the table, press
the INTERRUPT key (usually DEL or CTRL-C).

.7

The "Report" option enables you to produce a report to the screen.

.8

The "Exit" option leaves the program and returns you to the operating system.

.10

No, I don't really want to delete this row.

.11

Yes, I really want this row to be deleted.

.20

Use control-F to obtain detailed help information for each field.

Enter the data appropriate to the new row of data, or edit what
is already there.  You will probably not be able to edit the
primary key column of this table.


.30

The "Curent-List" option will produce a report which will contain 
just the rows in the current list -- i.e. those you could see by 
using Next and Previous repeatedly.

This does not affect the current list.

.31

The "Same-Query" option will produce a report which will contain
just the rows you would be able to see if you re-executed the last
enquiry you specified on the data now in the database.

This does not affect the current list.

.32

The "New-Query" option allows you to specify a new enquiry 
(completely unrelated to the main enquiry) which specifies the rows 
you wish to have included in the report.

This does not affect the current list.

.33

The "Reuse-Query" option is only avaliable if you have previously 
executed a "New-Query" report; it will produce the report by 
re-executing the same query as last time on the data now in the 
database.

This does not affect the current list.

.34

The "All" option prints all the data from the database.

This does not affect the current list.

.35

The "Exit" option takes you back to the main menu.

