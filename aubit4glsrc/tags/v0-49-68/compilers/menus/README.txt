This README describes the format of the menus file and their usage.


GUI Menus
---------

There are two ways to use menus in GUI mode. The first is the traditional 4GL menu command in 4GL :

MENU  ...
	COMMAND ...
	COMMAND ...
END MENU

This should work as before - but does not look very GUI. There is no support 
for drop down menus for example.

A GUI specific alternative is to use menu files.

Menu files have a couple of benefits :
	1) They are the only way to get GUI looking drop down menus

	2) You can distribute different files, eg. in different languages (Only a very small benefit!)

Menu are loaded from this file using the 'SHOW MENU' 4GL command.

eg. SHOW MENU my_menu USING my_menuhandler

You should then have a MENUHANDLER function to deal with clicks on menu items:


--------------------------------------------------------------------------------
MENUHANDLER my_menuhandler
DEFINE somevariables...

BEFORE SHOW MENU
	ENABLE MENUITEM mn_1 # You can use MENUITEM or MENUITEMS here
	ENABLE MENUITEMS mn_2,mn_3
	DISABLE MENUITEM mn_1,mn_3
	DISABLE MENUITEMS mn_1

ON mn_2
	DISPLAY "Hello World"
ON mn_3
	EXIT PROGRAM

END MENUHANDLER
--------------------------------------------------------------------------------


By default menus are loaded from a file called "menu.mnu", you can specify an
alternate filename by using  a FROM clause :

	eg. SHOW MENU my_menu USING my_menuhandler FROM "myfile"

The .mnu will be automatically appended.





Menu File Format
----------------

Source menu files have the extension '.menu', which will be compiled to '.mnu' by the mcompile command.

	$ mcompile filename

If no extension is specified .menu is assumed.

mcompile can also compile the menu file into C code which can be included in the
application directly (this means you don't need to distrubute the .mnu file) using the -c option.

	$ mcompile -c filename


This will generated a .c which can be linked into the application.

	$ mcompile -c mymenu

		will compile mymenu.menu into mymenu.c

	$ mcompile mymenu

		will compile mymenu.menu into mymenu.mnu




.menu files
-----------

A menu file contains one or more MENUs. Each menu has an associated ID :


MENU file
	....
END MENU


Within the menu you can place OPTIONs, these are specified as follows :

		OPTION id     "Caption"

You can also specify an image for an option in addition to the caption :
		OPTION id  Image="filename"   "Caption"

Note : At present all images must be in .xpm format


Although not fully implemented yet, you can also specify attributes for an
option. Currently the only option allowed is 'RIGHT' [not implemented] 
which will right align the menu item (Often used for Help), although there may be
others later...


		OPTION id     "Caption" ATTRIBUTES(RIGHT)

Simple example
--------------


A Typical file menu may look like this:

--------------------------------------------------------------------------------
MENU file
		OPTION mn_new   Image="New.xpm" "New" 
		OPTION mn_open  Image="Open.xpm" "Open"
		OPTION mn_save   "Save"
		OPTION mn_saveas "Save As"
		OPTION mn_exit   "Exit"
END MENU
--------------------------------------------------------------------------------



The above example will probably not appear as you'd imagine, the menu is 
displayed across the screen, what you'd normally have is a File menu, with 
the options listed as a drop down menu.

This is done using SUBMENUs. These have the same parameters as options :

Eg.

	SUBMENU mn_file "_File" Image="file.xpm" .. ATTRIBUTE(RIGHT)

Options to submenus are listed between the SUBMENU and an END SUBMENU :

--------------------------------------------------------------------------------
		SUBMENU mn_zoom "Zoom"
			OPTION mn_in "In"
			OPTION mn_out "In"
			OPTION mn_fit "To Fit"
		END SUBMENU
--------------------------------------------------------------------------------

Additionally, because these may be reused, you can specify the ID of the SUBMENU:

	SUBMENU mn_file "_File" USE file


In which case the compiler will substitute the options associated with a MENU 
with the specified ID.

Eg.

--------------------------------------------------------------------------------
MENU file
                OPTION mn_new    "New"
                OPTION mn_open   "Open"
                OPTION mn_save   "Save"
                OPTION mn_saveas "Save As"
                OPTION mn_exit   "Exit"
END MENU

MENU mymenu

	SUBMENU mn_file "_File" USE file

END MENU
--------------------------------------------------------------------------------

Is the same as :


--------------------------------------------------------------------------------
MENU mymenu
	SUBMENU mn_file "_File" 
                OPTION mn_new    "New"
                OPTION mn_open   "Open"
                OPTION mn_save   "Save"
                OPTION mn_saveas "Save As"
                OPTION mn_exit   "Exit"
	END SUBMENU
END MENU
--------------------------------------------------------------------------------

You can also nest SUBMENUs


--------------------------------------------------------------------------------
	SUBMENU mn_edit "_Edit"
		OPTION mn_cut  IMAGE="m1.xpm"  "Cut"  
		OPTION mn_copy Image="Copy.xpm" "Copy"
		OPTION mn_paste "Pastxxxxxxxxxxxxxxxxxxxxxxxxe"
		SUBMENU mn_zoom "Zoom"
			OPTION mn_in "In"
			OPTION mn_out "In"
			OPTION mn_fit "To Fit"
		END SUBMENU
	END SUBMENU
--------------------------------------------------------------------------------

Again - these can be either direct (as in the above example) or SUBMENU .. USE.


A complete example :


--------------------------------------------------------------------------------
MENU file
		OPTION mn_new    "New"
		OPTION mn_open   "Open"
		OPTION mn_save   "Save"
		OPTION mn_saveas "Save As"
		OPTION mn_exit   "Exit"
END MENU

MENU mymenu

	SUBMENU mn_file "_File" USE file


	SUBMENU mn_edit "_Edit"
		OPTION mn_cut  IMAGE="m1.xpm"  "Cut"
		OPTION mn_copy Image="Copy.xpm" "Copy"
		OPTION mn_paste "Pastxxxxxxxxxxxxxxxxxxxxxxxxe"
		SUBMENU mn_zoom "Zoom"
			OPTION mn_in "In"
			OPTION mn_out "In"
			OPTION mn_fit "To Fit"
		END SUBMENU
	END SUBMENU

	SUBMENU mn_useful "Useful Stuff"
		OPTION mn_form "Open Window & Form"
		OPTION mn_sform "Open small Window & Form"
		OPTION mn_screen "Open Form on Screen"
		OPTION mn_lots "Open lots of windows"
		OPTION mn_loop "Loop windows"
		OPTION mn_closewin "Close windows"
	END SUBMENU

	OPTION mn_help "Help" ATTRIBUTES(RIGHT)

END MENU
--------------------------------------------------------------------------------

In this example - your program could 'SHOW MENU' mymenu or file.



Handling menu options
In code, options can be enabled or disabled using
	ENABLE MENUITEM id
or
	DISABLE MENUITEM id

Note :
You can't use the 'SHOW OPTION "caption"' AND 'HIDE OPTION "caption"' !
These are for the traditional menu command.






