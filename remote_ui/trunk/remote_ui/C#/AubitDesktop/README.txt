Implemented items : 

CALL aclfgl_getclientfile("filename on client", "filename on server" ) returning ok



CALL fgl_settitle ("...") 
		sets the label on the tabpage for the application



fgl_dialog_setkeylabel("Key","Label")
	sets the text on the toolbar key labels.
	
aclfgl_sendfile_to_ui("filename")
	sends the file to the frontend (if it exists) - returns true/false
	
aclfgl_sendfile_to_ui("BLAH","blah.txt") 
	sends the local file "BLAH" and calls it "blah.txt" on the client

	
aclfgl_send_to_ui("text");
	sends the text to the ui in a <UIDIRECT> packet..
		
aclfgl_client_execute("cmd")
	executes the command 'cmd' on the client. You can 'execute' a pdf or txt file - that opens the associated application (acroread/notepad for example)
	




Buttons etc can be added to the forms with 'Actions'
If the actions are used in the input/construct etc - then these buttons will be enabled on the form.

