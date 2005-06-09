/********************************************************************
                         PutBack
********************************************************************/  
  
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <editor/app.h>
#include <editor/dlg.h>
#include <editor/doc.h>
#include <editor/macros.h>
  
#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80	// max file location string
#define MAX_FILE_NAME      80
  
// global variables
char g_WindowTitle[MAX_FILE_NAME];
















// function prototypes
void ScriptMain (HDOC);






/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/ 
  
main (int argc, char *argv[]) 
{
  
  
  
    {
      
	("Document must be open in editor, to return it to version controll !",
	 MB_OK);
      
    
  
    // save cursor position
    GM_SaveCursorPos (hDoc);
  
    // call main script function
    ScriptMain (hDoc);
  
    // restore cursor position
    GM_RestoreCursorPos (hDoc);
  
  
  
  
  
  
    
    {
      
    
  
/*
      if
         (
            MsgBox("TakeOut another file ?",MB_YESNO | MB_ICONQUESTION)
         == IDYES
         )
            {
                Param1 "takeout"
                ExecScript
             }


*/ 
    



/*-------------------------------------------------------------------
                         ScriptMain

  Main script function.

  PARAMETERS

     hDoc - Handle of active document.
-------------------------------------------------------------------*/ 
  
ScriptMain (HDOC hDoc) 
{
  
    // Check for compiler error lines
    RemoveCompilerErrorLines (hDoc);
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "PutBackCmd", "", g_szPutBackCmd,
			     sizeof (g_szPutBackCmd), "gte.ini");
  
			    sizeof (g_szClientInitDir), "gte.ini");
  
			    sizeof (g_szServerName), "gte.ini");
  
			    sizeof (g_szUserName), "gte.ini");
  
			    sizeof (g_szPassword), "gte.ini");
  
    /*  This is now doccument dependent
       GetPrivateProfileString("Remote", "ServerInitDir", "", g_szServerInitDir, sizeof(g_szServerInitDir), "gte.ini");
       
       if(strlen(g_szServerInitDir) == 0) {
       if(Gte_GetStringDlg("Server Initial Directory", "&Server initial dir:",
       g_szServerInitDir, sizeof(g_szServerInitDir)) == FALSE)
       {
       return;
       }
       if(strlen(g_szServerInitDir) == 0) {
       MsgBox("Invalid initial dir", MB_OK);
       return;
       }
       
     */ 
    // check configuration parameters and ask for them is necessary
    if (strlen (g_szPutBackCmd) == 0)
    {
      
	   ("PutBack command", "&PutBack command:", 
	    sizeof (g_szPutBackCmd)) == FALSE)
	
	{
	  
	
    
  
    {
      
      
	   (g_szClientInitDir, sizeof (g_szClientInitDir), FALSE) == FALSE)
	
      
	{
	  
	  
	
    
  
    {
      
	   ("Server Name", "&Server name:", g_szServerName,
	    sizeof (g_szServerName)) == FALSE)
	
      
	{
	  
	  
	
    
  
    {
      
	   ("User Name", "&User name:", g_szUserName,
	    sizeof (g_szUserName)) == FALSE)
	
      
	{
	  
	  
	
    
  
    {
      
	   ("Password", "&Password:", g_szPassword,
	    sizeof (g_szPassword)) == FALSE)
	
      
	{
	  
	  
	
    
  
    // from the filename and takeout.ini determine default filename and location
  {
    
    
    
    
    
    
			       
			       "gte.ini");
    
      
				g_szFileLocation, 
				sizeof (g_szFileLocation), "takeout.ini");
    
//LastTakeOutFileName=prof_main.4gl
      GetPrivateProfileString ("Remote", "LastTakeOutFileName", "",
			       
			       "gte.ini");
    
      
				g_szFileName, 
				sizeof (g_szFileName), "takeout.ini");
    
			       g_szServerInitDir, 
			       "takeout.ini");
    
//   GetPrivateProfileString("Remote", "ServerInitDir", "", g_szServerInitDir, sizeof(g_szServerInitDir), "gte.ini");
      
      // Check if this is the right file
      strcpy (szTakeOutFile, g_szClientInitDir);
    
    strcat (szTakeOutFile, g_szFileLocation);
    
    
    
/*-------------------------------------------------------------------
//  out because of removed "C:" from local path (rcp don't like disk label
//  in local path) this is never same:
//  SzTakeOutFile =   \dataLI\src\ldg_qbf.5gl
//  szDocFileName = c:\data\LI\src\ldg_qbf.5gl
//
// returned to code after addition of DiskLabel&semicolon stripping
// function into PutBack.c prior to calling PutBack.bat, and re-anabling
// of disklabel in gte.ini param ClientInitDir=


//af debug:
MsgBox(szTakeOutFile, MB_OK);
MsgBox(szDocFileName, MB_OK);
//af A4GL_debug end
*/ 
      
      
      {
	
	     ("Cannot determine if this file is checked out. Continue?",
	      
	  
	  {
	    
	  
	
	     ("Are you sure? AFAIK this file is not in the source control or it is not in the project.",
	      
	  
	  {
	    
	  
      
    
/*-------------------------------------------------------------------*/ 
  }
  
    // ask for location
    while (TRUE)
    
    {
      
/* Whole point of returning file to version contoll on UNIX is to return
    it to same place with same filename. Prompt removed:

      if(Gte_GetStringDlg("File Location", "&File location:", g_szFileLocation,
         sizeof(g_szFileLocation)) == FALSE)
      {
         // user click Cancel
         return;
      }
*/ 
	if (strpbrk (g_szFileLocation, ":*?") || g_szFileLocation[0] == '/'
	    || g_szFileLocation[0] == '\\')
	
	{
	  
	
      
      else
	
    
  
    // ask for file name
    while (TRUE)
    
    {
      
/* Whole point of returning file to version contoll on UNIX is to return
    it to same place with same filename. Prompt removed:

      if(Gte_GetStringDlg("File Name", "&File name:", g_szFileName,
         sizeof(g_szFileName)) == FALSE)
      {
         // user click Cancel
         return;
      }
*/ 
	if (strpbrk (g_szFileName, "\\/:*?"))
	
	{
	  
	
      
      else
	
    
  
    // add "/" at the end of directory strings if necessary
    if (g_szServerInitDir[0] != 0
	&& g_szServerInitDir[strlen (g_szServerInitDir) - 1] != '\\'
	&& 
    
    {
      
      
    
  
       && g_szClientInitDir[strlen (g_szClientInitDir) - 1] != '\\'
       && 
    
    {
      
      
    
  
       && g_szFileLocation[strlen (g_szFileLocation) - 1] != '\\'
       && 
    
    {
      
    
  
    // TakeOut file
    PutBack ();
  



/*-------------------------------------------------------------------
                         PutBack
-------------------------------------------------------------------*/ 
  
PutBack (void) 
{
  
  
    // Check if this file is already PutBack
  {
    
    
    
    
    
    
      GetPrivateProfileInt ("PutBack", szCmdLine, 0, "takeout.ini");
    
      
      {
	
	     ("File is already in the source control. Are you want to put back file again?",
	      
	  
	  {
	    
	  
      
  
  
    // we have all informations needed for put back file
    // g_szServerInitDir, g_szClientInitDir and g_szFileLocation ends with '/' or '\'
    // even if user didn't specify them
    //
    // We will now call bat program and send them following parameters:
    //
    // command
    // server_initdir
    // client_initdir
    // server_name
    // user_name
    // password
    // UNIX_file_loc
    // NT_file_loc
    // file_name
    
    //get gwd.exe location from gwd.ini
    GetPrivateProfileString ("GWD Applications", "Text Editor", "",
			     g_GWDlocation, sizeof (g_GWDlocation),
			     "gwd.ini");
  
// MsgBox(g_GWDlocation, MB_OK);
    
    //now A4GL_strip gwd.exe ad replace it with putback.bat
    
    // Call to BAT program to witch we will pass all the parameters
    strcpy (szCmdLine, "bat\\putback.bat ");
  
    
  
  
    
  
  
    
  
  
    
  
  
    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    strcpy (TMPg_szClientInitDir, g_szClientInitDir);
  
  
    {
      
	{
	  
	  
	
    
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
    
  
  
  
    
  
  
    // UNIX FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    // NT FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    
  
  
    
  
//debug:
/*
         strcpy(g_DebugString, "Command = ");
         strcat(g_DebugString, szCmdLine);
         strcat(g_DebugString, "-");

         if(MsgBox(g_DebugString,
            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
         {
            return;
         }
*/ 
    system (szCmdLine);
  
    // Write to ini file that file is now in the source control
/*
Do not see any point in asking. In 99,99 % it will be corectly returned
to SCCS. If not, (not) marking it as returned in INI file will not have
any benefits (tahat I can see)
*/ 
//AF out:   if(MsgBox("Mark file as returned to the source control?", MB_YESNO | MB_ICONQUESTION) == IDYES)
  {
    
      // add location and file name to takeout.ini file
      strcpy (szCmdLine, g_szClientInitDir);
    
    
    
    
  



/*-------------------------------------------------------------------
                      RemoveCompilerErrorLines
-------------------------------------------------------------------*/ 
  
RemoveCompilerErrorLines (HDOC hDoc) 
{
  
    // first check if we have compiler error lines
    // compiler error lines in 4gl begins with | character
    if (Gte_Find (hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
    
    {
      
	   ("File contains compiler error lines. Remove them?",
	    MB_YESNO) == IDYES)
	
	{
	  
	  
	    
	    {
	      
		   0)
		
		{
		  
		  
		
	      
	      
	    
	
    



/*-------------------------------------------------------------------
                    UnixPathToDosPath
-------------------------------------------------------------------*/ 
  
UnixPathToDosPath (char *psz) 
{
  
    
    {
      
	
      
    



/*-------------------------------------------------------------------
                    DosPathToUnixPath
-------------------------------------------------------------------*/ 
  
DosPathToUnixPath (char *psz) 
{
  
    
    {
      
	
      
    



/*-------------------------------------------------------------------
                    RemoveDiskLabel and semicolon
-------------------------------------------------------------------*/ 
  
RemoveDiskLabel (char *psz) 
{
  
    
      
      {
	
	
	
	
      }


