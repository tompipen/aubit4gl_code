Implemented items : 

Add stuff to toolbars :


        call aclfgl_add_to_toolbar("mnQuit","Quit","Quit","Quit the program","DIE",1)
        Where the parameters are :
        1 - a 'tag'
        2 - the text to use
        3 - The image to use (comes from the images directory IIRC)
        4 - Tooltip
        5 - Keyvalue/action to use if clicked.
        6 - 'Always show' - 1 = Yes, 0 - no - only show if it can be used...



Set background Image :
        CALL aclfgl_client_set("WORKSPACEBACKGROUND","background.jpg")


Set the application tree :

        CALL aclfgl_client_set("SHOWAPPLICATIONTREE","menu.xml")
        You can also send a file with a ".4sm" extension and it will be loaded automatically:
                call aclfgl_sendfile_to_ui("filename.4sm")
                
		See "StartMenuXMLParser.cs" for the reader for this file format - which should be in XML...
		
		A sample would be : 
			<StartMenu text ="Aubit Computing Ltd">
				<StartMenuGroup text ="Demo Menu">
					<StartMenuGroup text ="Set1">
						<StartMenuCommand text ="Prog1" exec ="prog1" />
						<StartMenuCommand text ="Prog2" exec ="prog2" />
					</StartMenuGroup>
					<StartMenuGroup text ="Set2">
						<StartMenuCommand text ="Prog3" exec ="prog3" />
					</StartMenuGroup>
				</StartMenuGroup>
			</StartMenu>


Play with which panels are visible :
        call aclfgl_client_set("MENUBAR","NEVER")
        call aclfgl_client_set("TOOLBAR","NEVER")
        call aclfgl_client_set("APPLICATIONLAUNCHER","ALWAYS")



Send a file to the UI :
        if not aclfgl_sendfile_to_ui("menu.xml") then
                error "Unable to send XML menu file to front end"
        end if

		


Builtin functions :
        CALL aclfgl_send_to_ui("string") - does nothing in this UI
        CALL aclfgl_flushinp() - does nothing in this UI

        CALL aclfgl_flush_ui() - flushes the buffer (rather than waiting for user interaction)

        CALL aclfgl_getclientfile("filename")                    gets a file from the client machine

        CALL aclfgl_client_execute("Program")
                executes the command 'cmd' on the client. You can 'execute' a pdf or txt file - that opens the associated application (acroread/notepad for example)

        CALL fgl_keysetlabel ("tag","text")
        CALL fgl_setkeylabel("tag","text")
        CALL fgl_dialog_setkeylabel("tag","text")

        CALL fgl_dialog_setcursor(n)     - sets the current cursor line (not implemented yet ?)
        CALL fgl_dialog_getcursor           - gets the current cursor line



        CALL fgl_settitle ("...")
                sets the label on the tabpage for the application

        aclfgl_sendfile_to_ui("filename")
                sends the file to the frontend (if it exists) - returns true/false

        aclfgl_sendfile_to_ui("BLAH","blah.txt")
                sends the local file "BLAH" and calls it "blah.txt" on the client

Buttons etc can be added to the forms with 'Actions'
If the actions are used in the input/construct etc - then these buttons will be enabled on the form.

