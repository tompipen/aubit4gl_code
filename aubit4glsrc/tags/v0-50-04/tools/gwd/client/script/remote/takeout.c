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
#define MAX_FAVORITE_FILES 10	// number of favorite files
  
// global variables
char g_WindowTitle[MAX_FILE_NAME];










































			 // or PREV and NEW

// function prototypes:
void UnixPathToDosPath (char *);	// Common
void DosPathToUnixPath (char *);	// Common
void ReplaceNonDOSchar (char *);	// Common
BOOL MakeDir (const char *pszDir);	// Common

// TakeOut functions (+ main)
void TakeOut (void);


// test functions:
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
  
/*
{
    int argc;
    char *argv[];
    int i;
    char szFileNameFav[FILENAME_MAX];
    char szRemoteTakeOutLocationFav[MAX_FILE_LOCATION];
    char szRemoteInitDirFav[MAX_INIT_DIR];
	char szIniEntry[8];
    char FavoriteRemoteList[200];

   strcpy (FavoriteRemoteList, "Favorite Takeout Files: \r\n");


   for(i = 0; i < MAX_FAVORITE_FILES; i++)
	{
      sprintf(szIniEntry, "%d", i+1);
      GetPrivateProfileString("FavoriteRemoteFiles", szIniEntry, "", szFileNameFav, FILENAME_MAX, "gte.ini");
      if(szFileNameFav[0] == 0)
	      break;
//	   Gte_OpenDocument(szFileName);

      GetPrivateProfileString("FavoriteRemoteInitDir", szIniEntry, "", szRemoteInitDirFav, MAX_INIT_DIR, "gte.ini");
      GetPrivateProfileString("FavoriteRemoteTakeOutLocation", szIniEntry, "", szRemoteTakeOutLocationFav, MAX_FILE_LOCATION, "gte.ini");

      strcat(FavoriteRemoteList, szIniEntry);
      strcat(FavoriteRemoteList, ": ");
      strcat(FavoriteRemoteList, szRemoteInitDirFav);
      strcat(FavoriteRemoteList, szRemoteTakeOutLocationFav);
      strcat(FavoriteRemoteList, szFileNameFav);
      strcat(FavoriteRemoteList, "\r\n");
    }

//      MsgBox(FavoriteRemoteList, MB_OK);
}

*/ 
    
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
    
//         MsgBox(szDefaultExt, MB_OK);
    
//         MsgBox(PromptFor, MB_OK);
    
  
//          MsgBox(PromptFor, MB_OK);     //ok
    
  
//          MsgBox(PromptFor, MB_OK);
    
  
//      MsgBox(PromptFor, MB_OK);
    
    
    {
      
//      if(Gte_GetStringDlg("File Name", "&File name:", g_szFileName,
	if (Gte_GetStringDlg (PromptFor, "&File name:", g_szFileName, 
//      if(Gte_GetStringDlg( PromptFor, FavoriteRemoteList , g_szFileName,
			      
	
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
	    strcpy (psz + 1, szDefaultExt);
	  
	  
	
      
	
	{
	  
	
      
      else
	
    
  
    // ask for location
    // we will propose last takeout location as default takeout location
    GetPrivateProfileString ("Remote", "LastTakeOutLocation", "",
			     g_szFileLocation, sizeof (g_szFileLocation),
			     "gte.ini");
  
    
    {
      
      
//      MsgBox(g_FavNum, MB_OK);
	
	
	{
	
      
      else
	
	{
	  
	
      
	
	{
	  
	    
	    {
	      
		// User want to use path stored by number g_FavNum
		// We have this in g_Init1 and g_Location1...but...
		GetPrivateProfileString ("FavoriteRemoteInitDir", g_FavNum,
					 "", g_szServerInitDir, MAX_INIT_DIR,
					 "gte.ini");
	      
					g_FavNum, "", g_szFileLocation,
					MAX_FILE_LOCATION, "gte.ini");
	    
	  
	  else
	    
	    {
	      
		// ask for NEW location input:
		
	      
	      
		    (g_WindowTitle, g_szServerName, g_szServerInitDir,
		     
		
		{
		  
		    // user click Cancel
		    return;
		
	      
	      
	      
		    (g_WindowTitle, g_szServerInitDir, g_szFileLocation, 
		     //if(Gte_GetStringDlg(g_WindowTitle, "&File location:", g_szFileLocation,
		     //if(Gte_GetStringDlg("File Location", "&File location:", g_szFileLocation,
		     sizeof (g_szFileLocation)) == FALSE)
		
		{
		  
		    // user click Cancel
		    //  return 0;
		    return;
		
	    
	
      
      else
	
	{
	  
	    // we already have PREVIOUS location in g_szServerInitDir and g_szFileLocation
	    //MsgBox(g_szServerInitDir, MB_OK);
	    //MsgBox(g_szFileLocation, MB_OK);
	}
      
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
      
    
  
/*
        strcpy (g_szDebug, "Selected file: ");
        strcat (g_szDebug, g_szServerInitDir);
        strcat (g_szDebug, g_szFileLocation);
        strcat (g_szDebug, g_szFileName);

        MsgBox(g_szDebug, MB_OK);
*/ 
    // we have all informations needed for take out file
    // g_szServerInitDir, g_szClientInitDir and g_szFileLocation ends with '/'
    // even if user didn't specify them
    
  
  
  UnixPathToDosPath (szCmdLine);
  
    /* TEMP
       rem out: MakeDir sometimes hangs GWD, and newer creates directories.
       see debbuging info inside function
       
       - Last time this bastard created 12877 directiories without a glich
       using 280 MB on Windows 95
       
       - Arrrrrghhh ! Again! Vedran, it looks like memory leak?
       
       if(MakeDir(szCmdLine) == FALSE)
       {
       char szMsg[512];
       
       sprintf(szMsg, "Cannot create %s directory", szCmdLine);
       
       MsgBox(szMsg, MB_OK | MB_ICONSTOP);
       return;
       }
       
     */ 
    
    // check not to owerwrite possibly existing file with same name and
    // location already on local disk:
    
  
  
  
  
    
    {
      
      
      
	       " already exists on local disk. Overwrite with remote file?");
      
	
	{
	  
	  
	  
	  
	    
	    {
	      
	    
	  
	  else
	    
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
	strcat (g_szExecCmd, "takeout.bat");
      
	
      
	{
	  
	
      
      else
	
	{
	  
	
      
	
      
    }
  
  else
    
    {
      
	// --------------- original -------------------//
	
    
  
    // 1
    if (strrchr (g_szTakeOutCmd, ' '))
    
  
  
    
  
  
    //2
    //   MsgBox(g_szServerInitDir, MB_OK);
    if (strchr (g_szServerInitDir, ' '))
    
  
  
    
  
  
    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    //3
    // MsgBox(g_szClientInitDir, MB_OK);
    
  
  
    {
      
	{
	  
	  
	
    
  
    
  
  
    
  
  
    //4
    if (strchr (g_szServerName, ' '))
    
  
  
    
  
  
    //5
    if (strchr (g_szUserName, ' '))
    
  
  
    
  
    //6
    if (strchr (g_szPassword, ' '))
    
  
  
  
    
  
  
    // UNIX FileLocation
    // 7
  {
    
    
    
    
      
    
    
      
    
  
  
    // NT FileLocation
    //8
  {
    
    
    
    
      
    
    
      
    
  
  
    //9
    if (strchr (g_szFileName, ' '))
    
  
  
    
  
/*
   if (MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION) == IDNO)
     {
         return;
     };
*/ 
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
  
    // Check for error.$$$ file in the local directory after calling bat
    strcpy (szCmdLine, g_szClientInitDir);
  
  
  UnixPathToDosPath (szCmdLine);
  
    {
      
	       "Error message generated by TakeOut.bat. Do you want to examine TakeOut.log file ?");
      
	
	{
	  
	  
	  
	  
	  
	
      
    }
  
/* I test for existance of of file on local disk BEFORE takeout and prompt
    user, so he already know if this is what happened...

   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   strcat(szCmdLine, "errexist.$$$");  //File already existed localy error
   UnixPathToDosPath(szCmdLine);

   if(access(szCmdLine, 0) == 0)    // test for existance of generated .$$$ file
   {
      strcpy(g_szDebug, "Warning ! Requested file was already on local disk. Previous copy renamed to xxx_filename.ext, current file from REMOTE system will be opened in editor.");
//      strcat(g_szDebug,g_szClientInitDir);
//      strcat(g_szDebug, g_szFileLocation);
//      strcat(g_szDebug, "TakeOut.log");
//      UnixPathToDosPath(g_szDebug);

      MsgBox(g_szDebug, MB_OK);
      remove(szCmdLine);
//      return; //Try to open file anyway
   }

*/ 
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
	  
	    // SUCCESS:
	    
	    // write last TakeOut location and file name to ini file
	    WritePrivateProfileString ("Remote", "LastTakeOutLocation",
				       g_szFileLocation, "gte.ini");
	  
				      g_szFileName, "gte.ini");
	  
				      "gte.ini");
	  
				      g_szServerInitDir, "gte.ini");
	  
	    // add TakeOut location and file name to takeout.ini file
	    WritePrivateProfileString ("TakeOutLocation", szCmdLine,
				       g_szFileLocation, "takeout.ini");
	  
				      g_szFileName, "takeout.ini");
	  
				      "takeout.ini");
	  
				      g_szServerInitDir, "takeout.ini");
	  
	    // Write to FavoriteRemoteFiles section if this is new location:
	    
	  {
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	      //MsgBox(IsNewLocation, MB_OK);
	      
	      
	      {
		
		
					  "", szFileNameFav, FILENAME_MAX,
					  "gte.ini");
		
		  
		
					   szIniEntry, "", szRemoteInitDirFav,
					   MAX_INIT_DIR, "gte.ini");
		
					  szIniEntry, "",
					  szRemoteTakeOutLocationFav,
					  MAX_FILE_LOCATION, "gte.ini");
		
		  
		  {
		    
		      // ServerInitDir ini entry no. szIniEntry is different, so continue searching
		  }
		
		else
		  
		  {
		    
		      // InitDir is same as recorded..
		      if (strcmpi
			  (szRemoteTakeOutLocationFav, g_szFileLocation))
		      
		      {
			
			  // ...but location is different so continue searching
		      
		    
		    else
		      
		      {
			
			  // ... and location is already recorded, so stop searching
			  strcpy (IsNewLocation, "NO");
			
		      
		  
	      
	    
	      //MsgBox(IsNewLocation, MB_OK);
	      
	      
	      {
		
		  // that path is already recorded in favorites section
	      }
	    
	    else
	      
	      {
		
		  // That is new path, record it...at possition 1, move all
		  // previous records one possition back...but for now just
		  // record it
		  // *Vedran*, is there any easy way to renumerate entries
		  // to insrt entry at location 1 and move all previous
		  // one lace back? entryes
		  sprintf (szIniEntry, "%d", i + 1);	//add one as next free location
		
		  //MsgBox(szIniEntry, MB_OK);
		  
					      szIniEntry, g_szFileName,
					      "gte.ini");
		
					    szIniEntry, g_szServerInitDir,
					    "gte.ini");
		
					    szIniEntry, g_szFileLocation,
					    "gte.ini");
	      
	  
	  
	    //Check for read-only status; it will mean that opened sourcefile
	    //was not properly taken out ot source controll, or tha somebody
	    //else have it for edit
	    hdoc = Gte_GetActiveDocument ();
	  
	    {
	      
	      
	    
	  
	    // check if document is read only
	    if (Gte_IsReadOnly (hdoc))
	    {
	      
		("Document is read only! Check file ownership and status in version controll system!",
		 MB_OK);
	    
	
    
  
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
    // AF: Except when is "C:\DATA\VJ\src\(*#&_$&"
    szMkDir[0] = 0;
  
  
//This is C:\DATA   MsgBox(szSubdirList, MB_OK);
    
    
    {
      
      
	// if dir does not exist create it
	if (chdir (szMkDir) != 0)
	{
	  
	    
	    {			// Fail point
	      
	      
	      
	      
	      
	      
		// It looks that if there is no slash/backslahs on
		// the end of path string, szSubdirList dos not receive
		// last null terminator, and WHILE stmt goes on...
		
		// Some times it hangs GWD, some times it dont...
		
		// Some times it works fine (but it does not create
		// directories), some times it does not
		
		//This is always first dir under root, because of null terminators
//                    strcpy(g_szDebug,"szSubdirList --");
//                    strcat(g_szDebug, szSubdirList);
//                    MsgBox(g_szDebug, MB_OK);       //  C:\Data
		
	      
	      
	      
	      //  C:\Data\VJ\src\#||
	      
	      
	      
	    
	
      
      
    
  
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
      
	
      
    



/*-------------------------------------------------------------------
                    ReplaceNonDOSchar
-------------------------------------------------------------------*/ 
  
ReplaceNonDOSchar (char *psz) 
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


//*********************************************************************
  void
NextToDoFile2 (HDOC hdoc) 
//*********************************************************************
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
  
  



//###################################################################
  void
LocationMenu (void) 
//###################################################################
{
  
  
  
/*
   Vedran, how to put NULL into g_Menu1-20?

   g_Menu1 = 0;
   g_Menu2 = 0;
   g_Menu3 = 0;
   g_Menu4 = 0;
   g_Menu5 = 0;
*/ 
    
  
//    strcpy(g_Menu5,psz);
  
  {
    
    
    
    
    
    
    
    
    
      
      {
	
	
				  szFileNameFav, FILENAME_MAX, "gte.ini");
	
	  
	
//         Gte_OpenDocument(szFileName);
	  
				    szRemoteInitDirFav, MAX_INIT_DIR,
				    "gte.ini");
	
				  "", szRemoteTakeOutLocationFav,
				  MAX_FILE_LOCATION, "gte.ini");
	
	
/*
      strcpy(g_szDebug, "--");
      strcat(g_szDebug, Counter);
      strcat(g_szDebug, "--");
      strcat(g_szDebug, Num1);
      strcat(g_szDebug, "--");

      MsgBox(g_szDebug, MB_OK);
*/ 
	  if (strcmpi (Counter, "1"))
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
	
	  
	  {
	  
	
	else
	  
	  {
	    
	    
	    
	    
	  
      
  
  
			     g_szFileLocation, sizeof (g_szFileLocation),
			     "gte.ini");
  
			    sizeof (g_szServerInitDir), "gte.ini");
  
  
  
  
    // List box used as a menu
    //   while(TRUE)
  {
    
      { 

    };
    
    
    
      
      {
	
	
      }
    
      
      {
      
	strcpy (g_FavNum, "PREV");
	return;			//break;         //Previous location
      case 2:
	strcpy (g_FavNum, "NEW");
	return;			//break;          //New location
      case 3:
	strcpy (g_FavNum, "1");
	return;			//break;
      case 4:
	strcpy (g_FavNum, "2");
	return;			//break;
      case 5:
	strcpy (g_FavNum, "3");
	return;			//break;
      case 6:
	strcpy (g_FavNum, "4");
	return;			//break;
      case 7:
	strcpy (g_FavNum, "5");
	return;			//break;
      case 8:
	strcpy (g_FavNum, "6");
	return;			//break;
      case 9:
	strcpy (g_FavNum, "7");
	return;			//break;
      case 10:
	strcpy (g_FavNum, "8");
	return;			//break;
      case 11:
	strcpy (g_FavNum, "9");
	return;			//break;
      case 12:
	strcpy (g_FavNum, "10");
	return;			//break;
      }
  
  
//     MsgBox(g_FavNum, MB_OK);



//###################################################### LocationMenu()
  
//############################################################### EOF
  