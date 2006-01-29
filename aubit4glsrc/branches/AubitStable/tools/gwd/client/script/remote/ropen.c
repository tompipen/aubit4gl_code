/********************************************************************
                         TakeOut
********************************************************************/  
  
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <io.h>			//needed for access function
#include <editor/app.h>
#include <editor/dlg.h>
#include <editor/doc.h>
  
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
void TakeOut (void);




//void NextTodoFile(const char *pszFile);
void NextTodoFile (char *pszFile);


/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/ 
  
main (int argc, char *argv[]) 
{
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "TakeOutCmd", "", g_szTakeOutCmd,
			     sizeof (g_szTakeOutCmd), "gte.ini");
  
			    sizeof (g_szServerInitDir), "gte.ini");
  
			    sizeof (g_szClientInitDir), "gte.ini");
  
			    sizeof (g_szServerName), "gte.ini");
  
			    sizeof (g_szUserName), "gte.ini");
  
			    sizeof (g_szPassword), "gte.ini");
  
    // check configuration parameters and ask for them is necessary
    if (strlen (g_szTakeOutCmd) == 0)
    {
      
	   ("TakeOut command", "&TakeOut command:", 
	    sizeof (g_szTakeOutCmd)) == FALSE)
	
	{
	  
	
    
  
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
	  
	  
	
    
  
    // TakeOut file
    TakeOut ();
  



/*-------------------------------------------------------------------
                         TakeOut
-------------------------------------------------------------------*/ 
  
TakeOut (void) 
{
  
  
  
  
  
  
  
  
  
  
    // put default extension to gwd.ini
    strcpy (szDefaultExt, "4gl");
  
    // ask for file name
    //offer default filename only if the last attempt was unsuccsessful
    //because after successful takeout LastBADTakeOutFileName is set to null
    GetPrivateProfileString ("Remote", "LastBADTakeOutFileName", "",
			     g_szFileName, sizeof (g_szFileName), "gte.ini");
  
    // Try to find next unprocessed file listed in xxtodo.log file, and
    // offer that as default filename
    //xx
    
//   g_szFileName = NextTodoFile("VJ_todo.log");
//   NextTodoFile("VJ_todo.log");
    
//   hdoc = Gte_GetActiveDocument();
    
//  hdoc = "c:\\progra~1\\GDWedit\\VJ_todo.log";
    
  
    {
      
      
//      return 1;
    }
  
  else
    
    {
      
    
  
//         MsgBox(szDefaultExt, MB_OK);
    
//         MsgBox(PromptFor, MB_OK);
    
  
//          MsgBox(PromptFor, MB_OK);     //ok
    
  
//          MsgBox(PromptFor, MB_OK);
    
  
//      MsgBox(PromptFor, MB_OK);
    
    
    {
      
//      if(Gte_GetStringDlg("File Name", "&File name:", g_szFileName,
	if (Gte_GetStringDlg
	    (PromptFor, "&File name:", g_szFileName,
	     
	
	{
	  
	    // user click Cancel
	    return;
	
      
	/*
	   // this is vedran's version of adding default extension to filename:
	   
	   psz = max(strrchr(filename, '/'), strrchr(filename, '\'))
	   if(psz == NULL)
	   psz = filename;
	   if(strchr(psz, '.'))
	   strcat(filename, ".Ext")
	   
	 */ 
	
	// Test if entered filename have extension
	strcpy (szBackupFile, g_szFileName);
      
      
      
	
      
      
	{			//This file does not have file extension
	  
	    //one more time...
	    strcpy (szBackupFile, g_szFileName);
	  
	  
	  
	  
	  
	    
	  
	  
	    {
	      
		       MB_OK);
	      
	    
	  
	    //add default extension
//          strcpy(psz+1, "4gl");
	    strcpy (psz + 1, szDefaultExt);
	  
	  
	    //          MsgBox(szErrorFile , MB_OK);
	    //          MsgBox(szBackupFile , MB_OK);
	    
	  
//          MsgBox(g_szFileName , MB_OK);
	
      
	
	{
	  
	
      
      else
	
    
  
    // ask for location
    // we will propose last takeout location as default takeout location
    GetPrivateProfileString ("Remote", "LastTakeOutLocation", "",
			     g_szFileLocation, sizeof (g_szFileLocation),
			     "gte.ini");
  
    
    {
      
      
      
	    (g_WindowTitle, g_szServerInitDir, g_szFileLocation, 
//      if(Gte_GetStringDlg(g_WindowTitle, "&File location:", g_szFileLocation,
//      if(Gte_GetStringDlg("File Location", "&File location:", g_szFileLocation,
	     sizeof (g_szFileLocation)) == FALSE)
	
	{
	  
	    // user click Cancel
//         return 0;
	    return;
	
      
	   || g_szFileLocation[0] == '\\')
	
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
      
    
  
    // we have all informations needed for take out file
    // g_szServerInitDir, g_szClientInitDir and g_szFileLocation ends with '/'
    // even if user didn't specify them
    
  
  
  UnixPathToDosPath (szCmdLine);
  
    /* TEMP
       rem out: Makedir fails because I have to remove disk label (C:)
       from GTE.INI ClientInitDir entry, rcp.Ece does not except disk labels
       SOLVED!
     */ 
    
    
    {
      
      
      
      
    
  
    /*
       // Remove error.$$$ file from the local directory before calling bat
       
       strcpy(szCmdLine, g_szClientInitDir);
       strcat(szCmdLine, g_szFileLocation);
       strcat(szCmdLine, "error.$$$");
       UnixPathToDosPath(szCmdLine);
       remove(szCmdLine);
     */ 
    
    // ********************************************************************
    // We now have all parameters for TakeOut. We will now call bat program
    // and send them following parameters:
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
    
    // Call to BAT script to witch we will pass all paramiters
    // this opens a window because of .BAT extension? strcpy(szCmdLine, "takeout.bat ");
    
    {
      
	//--------------------- version with patth to .bat file -------------//
	Gte_GetTextEditorDir (szBatPath, FILENAME_MAX);
      
	// MsgBox(szBatPath , MB_OK);
	strcpy (g_szExecCmd, szBatPath);
      
	// strcpy(szCmdLine, "takeout.bat ");
	strcat (g_szExecCmd, "bat\\takeout.bat");
      
	
      
	{
	  
	
      
      else
	
	{
	  
	
      
	
      
    }
  
  else
    
    {
      
	// --------------- original -------------------//
	
    
  
    
  
  
    
  
  
    
  
  
    
  
  
    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    strcpy (TMPg_szClientInitDir, g_szClientInitDir);
  
  
    {
      
	{
	  
	  
	
    
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
    
  
  
  
    
  
  
    // UNIX FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    // NT FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    
  
  
    
  
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
//   MsgBox(szCmdLine , MB_OK);
    
  
    // AF out- for debugging paramiters sent to Bat - MsgBox(szCmdLine, 0);
    
    // Check for error.$$$ file in the local directory after calling bat
    
  
  
  UnixPathToDosPath (szCmdLine);
  
    {
      
	       "Error message generated by TakeOut.bat. Do you want to examine TakeOut.log file ?");
      
//      strcpy(g_szDebug, "TakeOut Error message generated by TakeOut.bat. For details, examine file ");
//      strcat(g_szDebug,g_szClientInitDir);
//      strcat(g_szDebug, g_szFileLocation);
//      strcat(g_szDebug, "TakeOut.log");
//      UnixPathToDosPath(g_szDebug);
	
//      MsgBox(g_szDebug, MB_OK);
	if (MsgBox (g_szDebug, MB_YESNO | MB_ICONQUESTION) == IDYES)
	
	{
	  
	  
	  
	  
	  
	
      
      
//      return; //Try to open file anyway
    }
  
  
  
  UnixPathToDosPath (szCmdLine);
  
    {
      
	       "Warning ! Requested file was already on local disk. Previous copy renamed to xxx_filename.ext, current file from REMOTE system will be opened in editor.");
      
//      strcat(g_szDebug,g_szClientInitDir);
//      strcat(g_szDebug, g_szFileLocation);
//      strcat(g_szDebug, "TakeOut.log");
//      UnixPathToDosPath(g_szDebug);
	
      
      
//      return; //Try to open file anyway
    }
  
    // Open file
    strcpy (szCmdLine, g_szClientInitDir);
  
  
  
  
  
    // this is to prevent unseccsessfull Gte_OpenDocument
    // from messing up windows in GWD
    // Vedran suggested to use this:
    //   if(Gte_OpenDocument(szCmdLine) == NULL)
    // {
    //   FullScreen
    // }
    
    {
      
	
	{
	  
	    // write last TakeOut location and file name to ini file
	    WritePrivateProfileString ("Remote", "LastTakeOutLocation",
				       g_szFileLocation, "gte.ini");
	  
				      g_szFileName, "gte.ini");
	  
				      "gte.ini");
	  
	    // add TakeOut location and file name to takeout.ini file
	    WritePrivateProfileString ("TakeOutLocation", szCmdLine,
				       g_szFileLocation, "takeout.ini");
	  
				      g_szFileName, "takeout.ini");
	  
				      "takeout.ini");
	
    
  
  else				// requested file is not accessible on local disk
    {
      
				   g_szFileName, "gte.ini");
      
	//
	// TakeOut file again: calling this function aggain
	// Is this thing re-entrant? Can a function call itself?
	
	// MsgBox("TakeOut Error: Cannot access requested file", MB_OK);
	
      
      
      
	
	{
	  
	
    



/*-------------------------------------------------------------------
                         MakeDir

  The MakeDir function creates a new directory. Directory can end in
  / or \ and if some subdir does not exist it will be created

  Returns TRUE on success, FALSE on error.
-------------------------------------------------------------------*/ 
  
{
  
  
  
  
  
    {
      
    
  
  
    // copy pszDir into szSubdirList and replace \ and / with null
    // terminator. At the end we will have list of directory components
    // terminated with two null terimator characters
    strcpy (szSubdirList, pszDir);
  
  
    
    {
      
	
	{
	  
	    // do not remove \, /, \\ and // from begin of string (network disk)
	    if (psz == szSubdirList)
	    
	    {
	      
		
	    
	  
	  else
	    
	    {
	      
		
		{
		  
		    // do not remove \ in 'c:\'
		}
	      
	      else
		
	    
	
      
    
  
  
    // Contact directory components and try to make dir
    // During while loop szMkDir will be "c:\dir1", "c:\dir1\dir2", "c:\dir1\dir2\dir3"
    szMkDir[0] = 0;
  
  
    
    {
      
      
	// if dir does not exist create it
	if (chdir (szMkDir) != 0)
	{
	  
	    
	    {
	      
	      
	    
	
      
      
    
  
    // return original directory
    chdir (szOldDir);
  



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
      
	
      
    



//*********************************************************************
  void
NextTodoFile (char *pszFile) 
//*********************************************************************
{
  
  
  
//   char *szLine[80];
  char szLine[80];
  
//NO!   char *szLine;
  int i;
  
  
  
//   hDoc = Gte_GetActiveDocument();
//     hDoc = "RGtodo.log";
    
  
  
  
    {
      
      
    
  
  
    {
      
      
    
  
    {
      
    
  
    {
      
    
  
//    strcpy(g_szDebug, NumOfLine);
    
//      MsgBox(NumOfLines, MB_OK);
    
// Const arg to non cont pointer:
//     Gte_GetLine(hDoc, NumOfLines, szLine, sizeof(szLine));
//     Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));
//     MsgBox(szLine, MB_OK);
    
  
  
    //read one line from file into szLine
// int Gte_GetLine(HDOC hDoc, long lLineNumber, char * pszBuf, unsigned nBufSize)
//    Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));
    
  
//*      Gte_GetLine(hDoc, lLineNumber+1, pszFile, sizeof(pszFile));
//      Gte_GetLine(hDoc, i+1, szLine, sizeof(szLine));
    
  
  
//    for(i = 0; i < Gte_GetNumberOfLines(hDoc); i++)
    for (i = 0; i < NumOfLines; i++)
    
    {
      
	//read one line from file into szLine
	//    Gte_GetLine(hDoc, i+1, szLine, sizeof(szLine));
	
//       MsgBox(szLine, MB_OK);
	
/*
      //read value assigned to that filename in Proccesed section
//      bProcessed = GetPrivateProfileInt("Processed", szLine, 0, "RGtodo.log");
        bProcessed = GetPrivateProfileInt("Processed", szLine, 0, pszFile);
      //check if that file was already processed
      if(bProcessed)
      {

      }
      else
      {
//         WritePrivateProfileString("Processed", szLine, "1", "RGtodo.log");
           WritePrivateProfileString("Processed", szLine, "1", pszFile);
         //         break;
//         return szLine;
        return;
       g_szFileName = szLine;
      }
*/ 
    }
  
    //all filenames listed in that files are marked as processed
//    return;
}

NextToDoFile2 (HDOC hdoc) 
{
  
  
  
  
  
  
//   nWordWrapCol = Gte_GetWordWrapCol();
    
    // reserve memory for line
    pszLine = (char *) malloc (Gte_GetMaxLineLen () + 1);
  
    {
      
      
    
  
//   strcpy(szCmdLine, "c:\\progra~1\\GDWedit\\");
//   strcat(szCmdLine, "VJ_todo.log");
    
  
    
    {
      
    
  
  else
    
    {
      
      
      
    
  
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
    // for each line in the document (be careful we must always call
    // Gte_GetNumOfLines because number of lines in the document will
    // be probably increased in the loop)
    for (lLine = 1; lLine <= Gte_GetNumberOfLines (hdoc); lLine++)
    
    {
      
	    != IDYES)
	
	{
	  
	
      
//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
//        Gte_SetCursorPos("VJ_todo.log",1, lLine, FALSE);
	
//      if(Gte_GetLineLen(hdoc, lLine, FALSE) > nWordWrapCol)
	if (1 == 1)
	
	{
	  
	  
//         int  nWrapAtCol = 0; // insert new line at this column pos
	    
	  
//         Gte_GetLine(hdoc, lLine, pszLine, Gte_GetMaxLineLen()+1);
//OKOKOK     Gte_GetLine("c:\\progra~1\\GDWedit\\VJ_todo.log", lLine+1, pszLine, Gte_GetMaxLineLen()+1);
	    
//ok     Gte_GetLine("VJ_todo.log", lLine+1, pszLine, 10);
	    Gte_GetLine (szCmdLine, lLine + 1, pszLine, 10);
	  
//         Gte_GetLine(hdoc, lLine+1, pszLine, sizeof(pszLine));
//         Gte_GetLine(hdoc, 1, pszLine, 5);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
	    MsgBox ("after getline...", MB_OK);
	  
	  
//
	    
	  
	  
/*
         while(*psz == ' ' || *psz == '\t')
            psz++;
         while(*psz)
         {
            while(*psz && (*psz != ' ' && *psz != '\t'))
               psz++;
            if(Gte_GetCharColumnPos(pszLine, psz) > nWordWrapCol && nWrapAtCol > 4)
            {
               // word wrap
               Gte_SetCursorPos(hdoc, nWrapAtCol, lLine, FALSE);
               GM_NewLine(hdoc);
               //Gte_InsertText(hdoc, "\r\n"); // Autoident will not work
               break;
            }
            while(*psz == ' ' || *psz == '\t')
               psz++;
            nWrapAtCol = Gte_GetCharColumnPos(pszLine, psz);
         }
*/ 
	}
      
/*
      // Display progress on status bar after every 10 lines
      if(lLine % 10 == 0)
      {
         char szMsg[80];

         sprintf(szMsg, "Press Ctrl-Break to cancel operation: %0d%% completed", (int)(lLine * 100 / Gte_GetNumberOfLines(hdoc)));
         Gte_StatusBarMsg(szMsg);
      }
*/ 
    }
  
  



//************************************************************* eof
  