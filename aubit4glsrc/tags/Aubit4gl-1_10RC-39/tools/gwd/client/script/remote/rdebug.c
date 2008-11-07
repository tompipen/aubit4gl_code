/********************************************************************
                         rRun
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
char g_szSysName[MAX_CMDLEN];








// function prototypes
void ScriptMain (HDOC);




/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/ 
  
main (int argc, char *argv[]) 
//int main(char Param[20])
{
  
  
  strcpy (g_szFileName, argv[1]);
  
  
  
  
    {
      
      
    
  
    // save cursor position
    GM_SaveCursorPos (hDoc);
  
    // call main script function
    ScriptMain (hDoc);
  
    // restore cursor position
    GM_RestoreCursorPos (hDoc);
  
  



/*-------------------------------------------------------------------
                         ScriptMain

  Main script function.

  PARAMETERS

     hDoc - Handle of active document.
-------------------------------------------------------------------*/ 
  
ScriptMain (HDOC hDoc) 
{
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    
  
    // read configuration from ini file
//   GetPrivateProfileString("Remote", "PutBackCmd", "", g_szPutBackCmd, sizeof(g_szPutBackCmd), "gte.ini");
    GetPrivateProfileString ("Remote", "ServerInitDir", "", g_szServerInitDir,
			     sizeof (g_szServerInitDir), "gte.ini");
  
			    sizeof (g_szClientInitDir), "gte.ini");
  
			    sizeof (g_szServerName), "gte.ini");
  
			    sizeof (g_szUserName), "gte.ini");
  
			    sizeof (g_szPassword), "gte.ini");
  
    // check configuration parameters and ask for them is necessary
/*
   if(strlen(g_szPutBackCmd) == 0) {
      if(Gte_GetStringDlg("PutBack command", "&PutBack command:",
         g_szPutBackCmd, sizeof(g_szPutBackCmd)) == FALSE)
      {
         return;
      }
   }
*/ 
    if (strlen (g_szServerInitDir) == 0)
    {
      
	   ("Server Initial Directory", "&Server initial dir:",
	    
	
	{
	  
	
      
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
    
    
    
    
    
    
			       g_szFileLocation, sizeof (g_szFileLocation),
			       "gte.ini");
    
      
				g_szFileLocation, g_szFileLocation,
				sizeof (g_szFileLocation), "takeout.ini");
    
			      g_szFileName, sizeof (g_szFileName), "gte.ini");
    
      
				g_szFileName, g_szFileName,
				sizeof (g_szFileName), "takeout.ini");
    
      // Check if this is the right file
      strcpy (szTakeOutFile, g_szClientInitDir);
    
    
    
    
/*-------------------------------------------------------------------
//  out because of removed "C:" from local path (rcp don't like disk label
//  in local path) this is never same:
//  SzTakeOutFile =   \dataLI\src\ldg_qbf.5gl
//  szDocFileName = c:\data\LI\src\ldg_qbf.5gl

//af debug:
//MsgBox(szTakeOutFile, MB_OK);
//MsgBox(szDocFileName, MB_OK);
//af A4GL_debug end

      if(strcmpi(szDocFileName, szTakeOutFile))
      {
         if(MsgBox("Cannot determine if this file is checked out. Continue?",
                  MB_YESNO | MB_ICONQUESTION) != IDYES)
         {
            return;
         }
         if(MsgBox("Are you sure? AFAIK this file is not in the source control or it is not in the project.",
                  MB_YESNO | MB_ICONQUESTION) != IDYES)
         {
            return;
         }
      }

-------------------------------------------------------------------*/ 
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
      
	    ("File Name", "&File name:", g_szFileName,
	     
	
	{
	  
	    // user click Cancel
	    return;
	
      
	
	{
	  
	
      
      else
	
    
  
    // ask for system name
//   while(TRUE)
//   {
    
    // read previous system name form ini file
    GetPrivateProfileString ("Remote", "LastSysRun", "", g_szSysName,
			     sizeof (g_szSysName), "gte.ini");
  
	("System name", "&System name:", g_szSysName,
	 
    
    {
      
	// user click Cancel
	return;
    
  
    // write last system name to ini file
    WritePrivateProfileString ("Remote", "LastSysRun", g_szSysName,
			       "gte.ini");
  
//   }
    
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
    
    // Call to BAT program to witch we will pass all the parameters
// With start keywors, in both c script and bat (before rexrc), it
// starts two dos sessions and doe not close automaticaly
//   strcpy(szCmdLine, "start /m rrun.bat ");
    
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
    
  
  
  
    
  
  
    // UNIX FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    // NT FileLocation
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
      
	
      
    


