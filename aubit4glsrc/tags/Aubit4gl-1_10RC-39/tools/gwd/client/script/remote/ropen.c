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
char g_szTakeOutCmd[MAX_CMDLEN];
char g_szServerInitDir[MAX_INIT_DIR];
char g_szClientInitDir[MAX_INIT_DIR];
char TMPg_szClientInitDir[MAX_INIT_DIR];
char g_szServerName[MAX_SERVER_NAME];
char g_szUserName[MAX_USER_NAME];
char g_szPassword[MAX_PASSWORD];
char g_szFileLocation[MAX_FILE_LOCATION];
char g_szFileName[MAX_FILE_NAME];
char g_szDebug[MAX_FILE_NAME];
char *psz;

// function prototypes
void TakeOut (void);
BOOL MakeDir (const char *pszDir);
void UnixPathToDosPath (char *);
void DosPathToUnixPath (char *);

//void NextTodoFile(const char *pszFile);
void NextTodoFile (char *pszFile);
void NextToDoFile2 (HDOC);

/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/ 
  int
main (int argc, char *argv[]) 
{
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "TakeOutCmd", "", g_szTakeOutCmd,
			     sizeof (g_szTakeOutCmd), "gte.ini");
  GetPrivateProfileString ("Remote", "ServerInitDir", "", g_szServerInitDir,
			    sizeof (g_szServerInitDir), "gte.ini");
  GetPrivateProfileString ("Remote", "ClientInitDir", "", g_szClientInitDir,
			    sizeof (g_szClientInitDir), "gte.ini");
  GetPrivateProfileString ("Remote", "ServerName", "", g_szServerName,
			    sizeof (g_szServerName), "gte.ini");
  GetPrivateProfileString ("Remote", "UserName", "", g_szUserName,
			    sizeof (g_szUserName), "gte.ini");
  GetPrivateProfileString ("Remote", "Password", "", g_szPassword,
			    sizeof (g_szPassword), "gte.ini");
  
    // check configuration parameters and ask for them is necessary
    if (strlen (g_szTakeOutCmd) == 0)
    {
      if (Gte_GetStringDlg
	   ("TakeOut command", "&TakeOut command:", g_szTakeOutCmd,
	    sizeof (g_szTakeOutCmd)) == FALSE)
	
	{
	  return 0;
	}
    }
  if (strlen (g_szServerInitDir) == 0)
    {
      if (Gte_GetStringDlg
	   ("Server Initial Directory", "&Server initial dir:",
	    g_szServerInitDir, sizeof (g_szServerInitDir)) == FALSE)
	
	{
	  return 0;
	}
      if (strlen (g_szServerInitDir) == 0)
	{
	  MsgBox ("Invalid initial dir", MB_OK);
	  return 0;
	}
    }
  if (strlen (g_szClientInitDir) == 0)
    {
      MsgBox ("Select client initial directory", MB_OK);
      if (Gte_BrowseForDirDlg
	   (g_szClientInitDir, sizeof (g_szClientInitDir), FALSE) == FALSE)
	return 0;
      if (strlen (g_szClientInitDir) == 0)
	{
	  MsgBox ("Invalid client initial dir", MB_OK);
	  return 0;
	}
    }
  if (strlen (g_szServerName) == 0)
    {
      if (Gte_GetStringDlg
	   ("Server Name", "&Server name:", g_szServerName,
	    sizeof (g_szServerName)) == FALSE)
	return 0;
      if (strlen (g_szServerName) == 0)
	{
	  MsgBox ("Invalid server name", MB_OK);
	  return 0;
	}
    }
  if (strlen (g_szUserName) == 0)
    {
      if (Gte_GetStringDlg
	   ("User Name", "&User name:", g_szUserName,
	    sizeof (g_szUserName)) == FALSE)
	return 0;
      if (strlen (g_szUserName) == 0)
	{
	  MsgBox ("Invalid user name", MB_OK);
	  return 0;
	}
    }
  if (strlen (g_szPassword) == 0)
    {
      if (Gte_GetStringDlg
	   ("Password", "&Password:", g_szPassword,
	    sizeof (g_szPassword)) == FALSE)
	return 0;
      if (strlen (g_szPassword) == 0)
	{
	  MsgBox ("Invalid password", MB_OK);
	  return 0;
	}
    }
  
    // TakeOut file
    TakeOut ();
  return 0;
}


/*-------------------------------------------------------------------
                         TakeOut
-------------------------------------------------------------------*/ 
  void
TakeOut (void) 
{
  char szCmdLine[1024];
  HDOC hdoc;
  char szBackupFile[FILENAME_MAX];
  char szErrorFile[FILENAME_MAX];
  char *psz;
  char szBatPath[FILENAME_MAX];
  char g_szExecCmd[FILENAME_MAX];
  char szDefaultExt[4];
  char PromptFor[30];
  
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
    hdoc = "VJ_todo.log";
  if (hdoc == NULL)
    {
      MsgBox ("Cannot get handle of the document!", MB_OK);
      
//      return 1;
    }
  
  else
    
    {
      NextToDoFile2 (hdoc);
    }
  
//         MsgBox(szDefaultExt, MB_OK);
    
//         MsgBox(PromptFor, MB_OK);
    strcpy (PromptFor, "File name (default=.");
  
//          MsgBox(PromptFor, MB_OK);     //ok
    strcat (PromptFor, szDefaultExt);
  
//          MsgBox(PromptFor, MB_OK);
    strcat (PromptFor, ")");
  
//      MsgBox(PromptFor, MB_OK);
    while (TRUE)
    
    {
      
//      if(Gte_GetStringDlg("File Name", "&File name:", g_szFileName,
	if (Gte_GetStringDlg
	    (PromptFor, "&File name:", g_szFileName,
	     sizeof (g_szFileName)) == FALSE)
	
	{
	  
	    // user click Cancel
	    return;
	}
      
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
      strcpy (szErrorFile, g_szFileName);
      psz = strrchr (szErrorFile, '\\');
      if (psz == NULL)
	psz = szErrorFile;
      psz = strrchr (psz, '.');
      if (psz == NULL)
	{			//This file does not have file extension
	  
	    //one more time...
	    strcpy (szBackupFile, g_szFileName);
	  strcat (szBackupFile, ".xxx");
	  strcpy (szErrorFile, g_szFileName);
	  strcat (szErrorFile, ".xxx");
	  psz = strrchr (szErrorFile, '\\');
	  if (psz == NULL)
	    psz = szErrorFile;
	  psz = strrchr (psz, '.');
	  if (psz == NULL)
	    {
	      MsgBox ("ERROR: This file STILL does not have file extension!",
		       MB_OK);
	      return;
	    }
	  
	    //add default extension
//          strcpy(psz+1, "4gl");
	    strcpy (psz + 1, szDefaultExt);
	  strcpy (szBackupFile + (psz - szErrorFile) + 1, "bak");
	  
	    //          MsgBox(szErrorFile , MB_OK);
	    //          MsgBox(szBackupFile , MB_OK);
	    strcpy (g_szFileName, szErrorFile);
	  
//          MsgBox(g_szFileName , MB_OK);
	}
      if (strpbrk (g_szFileName, "\\/:*?"))
	
	{
	  MsgBox ("Invalid file name", MB_OK);
	}
      
      else
	break;
    }
  
    // ask for location
    // we will propose last takeout location as default takeout location
    GetPrivateProfileString ("Remote", "LastTakeOutLocation", "",
			     g_szFileLocation, sizeof (g_szFileLocation),
			     "gte.ini");
  while (TRUE)
    
    {
      strcpy (g_WindowTitle, "Location of ");
      strcat (g_WindowTitle, g_szFileName);
      if (Gte_GetStringDlg
	    (g_WindowTitle, g_szServerInitDir, g_szFileLocation, 
//      if(Gte_GetStringDlg(g_WindowTitle, "&File location:", g_szFileLocation,
//      if(Gte_GetStringDlg("File Location", "&File location:", g_szFileLocation,
	     sizeof (g_szFileLocation)) == FALSE)
	
	{
	  
	    // user click Cancel
//         return 0;
	    return;
	}
      if (strpbrk (g_szFileLocation, ":*?") || g_szFileLocation[0] == '/'
	   || g_szFileLocation[0] == '\\')
	
	{
	  MsgBox ("Invalid file location", MB_OK);
	}
      
      else
	break;
    }
  
    // add "/" at the end of directory strings if necessary
    if (g_szServerInitDir[0] != 0
	&& g_szServerInitDir[strlen (g_szServerInitDir) - 1] != '\\'
	&& g_szServerInitDir[strlen (g_szServerInitDir) - 1] != '/')
    
    {
      strcat (g_szServerInitDir, "/");
      DosPathToUnixPath (g_szServerInitDir);
    }
  if (g_szClientInitDir[0] != 0
       && g_szClientInitDir[strlen (g_szClientInitDir) - 1] != '\\'
       && g_szClientInitDir[strlen (g_szClientInitDir) - 1] != '/')
    
    {
      strcat (g_szClientInitDir, "/");
      UnixPathToDosPath (g_szClientInitDir);
    }
  if (g_szFileLocation[0] != 0
       && g_szFileLocation[strlen (g_szFileLocation) - 1] != '\\'
       && g_szFileLocation[strlen (g_szFileLocation) - 1] != '/')
    
    {
      strcat (g_szFileLocation, "/");
    }
  
    // we have all informations needed for take out file
    // g_szServerInitDir, g_szClientInitDir and g_szFileLocation ends with '/'
    // even if user didn't specify them
    strcpy (szCmdLine, g_szClientInitDir);
  strcat (szCmdLine, g_szFileLocation);
  szCmdLine[strlen (szCmdLine) - 1] = 0;	// uklonimo "/" sa kraja
  UnixPathToDosPath (szCmdLine);
  
    /* TEMP
       rem out: Makedir fails because I have to remove disk label (C:)
       from GTE.INI ClientInitDir entry, rcp.Ece does not except disk labels
       SOLVED!
     */ 
    if (MakeDir (szCmdLine) == FALSE)
    
    {
      char szMsg[512];
      sprintf (szMsg, "Cannot create %s directory", szCmdLine);
      MsgBox (szMsg, MB_OK | MB_ICONSTOP);
      return;
    }
  
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
    if (1 == 2)
    {
      
	//--------------------- version with patth to .bat file -------------//
	Gte_GetTextEditorDir (szBatPath, FILENAME_MAX);
      
	// MsgBox(szBatPath , MB_OK);
	strcpy (g_szExecCmd, szBatPath);
      
	// strcpy(szCmdLine, "takeout.bat ");
	strcat (g_szExecCmd, "bat\\takeout.bat");
      if (strrchr (g_szExecCmd, ' '))
	strcpy (szCmdLine, "start /w \"");	// w is to prevent command returning before finninhed
      if (strrchr (g_szExecCmd, ' '))
	{
	  strcat (szCmdLine, g_szExecCmd);
	}
      
      else
	
	{
	  strcpy (szCmdLine, g_szExecCmd);
	}
      if (strchr (g_szExecCmd, ' '))
	strcat (szCmdLine, "\"");
      strcat (szCmdLine, " ");	// add one space
    }
  
  else
    
    {
      
	// --------------- original -------------------//
	strcpy (szCmdLine, "bat\\takeout.bat ");
    }
  if (strrchr (g_szTakeOutCmd, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szTakeOutCmd);
  if (strchr (g_szTakeOutCmd, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  if (strchr (g_szServerInitDir, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szServerInitDir);
  if (strchr (g_szServerInitDir, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  
    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    strcpy (TMPg_szClientInitDir, g_szClientInitDir);
  psz = TMPg_szClientInitDir;
  if (*psz == 'C' || *psz == 'c')
    {
      if (*(psz + 1) == ':')
	{
	  psz = psz + 2;
	  strcpy (TMPg_szClientInitDir, psz);
	}
    }
  if (strchr (TMPg_szClientInitDir, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, TMPg_szClientInitDir);
  if (strchr (TMPg_szClientInitDir, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  if (strchr (g_szServerName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szServerName);
  if (strchr (g_szServerName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  if (strchr (g_szUserName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szUserName);
  if (strchr (g_szUserName, ' '))
    strcat (szCmdLine, "\"");
  if (strchr (g_szPassword, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  strcat (szCmdLine, g_szPassword);
  if (strchr (g_szPassword, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  
    // UNIX FileLocation
  {
    char szUnixFileLoc[MAX_FILE_LOCATION];
    strcpy (szUnixFileLoc, g_szFileLocation);
    DosPathToUnixPath (szUnixFileLoc);
    if (strchr (szUnixFileLoc, ' '))
      strcat (szCmdLine, "\"");
    strcat (szCmdLine, szUnixFileLoc);
    if (strchr (szUnixFileLoc, ' '))
      strcat (szCmdLine, "\"");
    strcat (szCmdLine, " ");
  }
  
    // NT FileLocation
  {
    char szWinFileLoc[MAX_FILE_LOCATION];
    strcpy (szWinFileLoc, g_szFileLocation);
    UnixPathToDosPath (szWinFileLoc);
    if (strchr (szWinFileLoc, ' '))
      strcat (szCmdLine, "\"");
    strcat (szCmdLine, szWinFileLoc);
    if (strchr (szWinFileLoc, ' '))
      strcat (szCmdLine, "\"");
    strcat (szCmdLine, " ");
  }
  if (strchr (g_szFileName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szFileName);
  if (strchr (g_szFileName, ' '))
    strcat (szCmdLine, "\"");
  
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
//   MsgBox(szCmdLine , MB_OK);
    system (szCmdLine);
  
    // AF out- for debugging paramiters sent to Bat - MsgBox(szCmdLine, 0);
    
    // Check for error.$$$ file in the local directory after calling bat
    strcpy (szCmdLine, g_szClientInitDir);
  strcat (szCmdLine, g_szFileLocation);
  strcat (szCmdLine, "error.$$$");	//general error
  UnixPathToDosPath (szCmdLine);
  if (access (szCmdLine, 0) == 0)	// test for existance of generated .$$$ file
    {
      strcpy (g_szDebug,
	       "Error message generated by TakeOut.bat. Do you want to examine TakeOut.log file ?");
      
//      strcpy(g_szDebug, "TakeOut Error message generated by TakeOut.bat. For details, examine file ");
//      strcat(g_szDebug,g_szClientInitDir);
//      strcat(g_szDebug, g_szFileLocation);
//      strcat(g_szDebug, "TakeOut.log");
//      UnixPathToDosPath(g_szDebug);
	
//      MsgBox(g_szDebug, MB_OK);
	if (MsgBox (g_szDebug, MB_YESNO | MB_ICONQUESTION) == IDYES)
	
	{
	  strcpy (g_szDebug, g_szClientInitDir);
	  strcat (g_szDebug, g_szFileLocation);
	  strcat (g_szDebug, "TakeOut.log");
	  UnixPathToDosPath (g_szDebug);
	  Gte_OpenDocument (g_szDebug);
	}
      remove (szCmdLine);
      
//      return; //Try to open file anyway
    }
  strcpy (szCmdLine, g_szClientInitDir);
  strcat (szCmdLine, g_szFileLocation);
  strcat (szCmdLine, "errexist.$$$");	//File already existed localy error
  UnixPathToDosPath (szCmdLine);
  if (access (szCmdLine, 0) == 0)	// test for existance of generated .$$$ file
    {
      strcpy (g_szDebug,
	       "Warning ! Requested file was already on local disk. Previous copy renamed to xxx_filename.ext, current file from REMOTE system will be opened in editor.");
      
//      strcat(g_szDebug,g_szClientInitDir);
//      strcat(g_szDebug, g_szFileLocation);
//      strcat(g_szDebug, "TakeOut.log");
//      UnixPathToDosPath(g_szDebug);
	MsgBox (g_szDebug, MB_OK);
      remove (szCmdLine);
      
//      return; //Try to open file anyway
    }
  
    // Open file
    strcpy (szCmdLine, g_szClientInitDir);
  strcat (szCmdLine, g_szFileLocation);
  strcat (szCmdLine, g_szFileName);
  UnixPathToDosPath (szCmdLine);
  RestoreCursor ();
  if (access (szCmdLine, 0) == 0)	// first test for existance of requested file
    // this is to prevent unseccsessfull Gte_OpenDocument
    // from messing up windows in GWD
    // Vedran suggested to use this:
    //   if(Gte_OpenDocument(szCmdLine) == NULL)
    // {
    //   FullScreen
    // }
    
    {
      if (Gte_OpenDocument (szCmdLine) != NULL)
	
	{
	  
	    // write last TakeOut location and file name to ini file
	    WritePrivateProfileString ("Remote", "LastTakeOutLocation",
				       g_szFileLocation, "gte.ini");
	  WritePrivateProfileString ("Remote", "LastTakeOutFileName",
				      g_szFileName, "gte.ini");
	  WritePrivateProfileString ("Remote", "LastBADTakeOutFileName", "",
				      "gte.ini");
	  
	    // add TakeOut location and file name to takeout.ini file
	    WritePrivateProfileString ("TakeOutLocation", szCmdLine,
				       g_szFileLocation, "takeout.ini");
	  WritePrivateProfileString ("TakeOutFileName", szCmdLine,
				      g_szFileName, "takeout.ini");
	  WritePrivateProfileString ("PutBack", szCmdLine, "0",
				      "takeout.ini");
	}
    }
  
  else				// requested file is not accessible on local disk
    {
      WritePrivateProfileString ("Remote", "LastBADTakeOutFileName",
				   g_szFileName, "gte.ini");
      
	//
	// TakeOut file again: calling this function aggain
	// Is this thing re-entrant? Can a function call itself?
	
	// MsgBox("TakeOut Error: Cannot access requested file", MB_OK);
	strcpy (g_szDebug, "TakeOut Error: Cannot access ");
      strcat (g_szDebug, szCmdLine);
      strcat (g_szDebug, " Try again?");
      if (MsgBox (g_szDebug, MB_YESNO | MB_ICONQUESTION) == IDYES)
	
	{
	  TakeOut ();
	}
    }
}


/*-------------------------------------------------------------------
                         MakeDir

  The MakeDir function creates a new directory. Directory can end in
  / or \ and if some subdir does not exist it will be created

  Returns TRUE on success, FALSE on error.
-------------------------------------------------------------------*/ 
  BOOL MakeDir (const char *pszDir) 
{
  char szOldDir[FILENAME_MAX];
  char szSubdirList[FILENAME_MAX + 1];
  char szMkDir[FILENAME_MAX + 1];
  char *psz;
  if (pszDir == NULL || *pszDir == 0)
    {
      return FALSE;
    }
  getcwd (szOldDir, FILENAME_MAX);
  
    // copy pszDir into szSubdirList and replace \ and / with null
    // terminator. At the end we will have list of directory components
    // terminated with two null terimator characters
    strcpy (szSubdirList, pszDir);
  psz = szSubdirList;
  while (*psz)
    
    {
      if (*psz == '/' || *psz == '\\')
	
	{
	  
	    // do not remove \, /, \\ and // from begin of string (network disk)
	    if (psz == szSubdirList)
	    
	    {
	      if (*(psz + 1) == '\\' || *(psz + 1) == '/')
		psz++;
	    }
	  
	  else
	    
	    {
	      if (psz == szSubdirList + 2 && *(psz - 1) == ':')
		
		{
		  
		    // do not remove \ in 'c:\'
		}
	      
	      else
		*psz = 0;
	    }
	}
      psz++;
    }
  *psz = 0;			// second null terminator
  
    // Contact directory components and try to make dir
    // During while loop szMkDir will be "c:\dir1", "c:\dir1\dir2", "c:\dir1\dir2\dir3"
    szMkDir[0] = 0;
  psz = szSubdirList;
  while (*psz != 0)
    
    {
      strcat (szMkDir, psz);
      
	// if dir does not exist create it
	if (chdir (szMkDir) != 0)
	{
	  if (mkdir (szMkDir) != 0)
	    
	    {
	      chdir (szOldDir);
	      return FALSE;
	    }
	}
      strcat (szMkDir, "\\");
      psz += strlen (psz) + 1;
    }
  
    // return original directory
    chdir (szOldDir);
  return TRUE;
}


/*-------------------------------------------------------------------
                    UnixPathToDosPath
-------------------------------------------------------------------*/ 
  void
UnixPathToDosPath (char *psz) 
{
  while (*psz)
    
    {
      if (*psz == '/')
	*psz = '\\';
      psz++;
    }
}


/*-------------------------------------------------------------------
                    DosPathToUnixPath
-------------------------------------------------------------------*/ 
  void
DosPathToUnixPath (char *psz) 
{
  while (*psz)
    
    {
      if (*psz == '\\')
	*psz = '/';
      psz++;
    }
}


//*********************************************************************
  void
NextTodoFile (char *pszFile) 
//*********************************************************************
{
  HDOC hDoc;
  BOOL bProcessed;
  
//   char *szLine[80];
  char szLine[80];
  
//NO!   char *szLine;
  int i;
  long NumOfLines;
  long lLineNumber;
  
//   hDoc = Gte_GetActiveDocument();
//     hDoc = "RGtodo.log";
    return;
  MsgBox (pszFile, MB_OK);
  hDoc = pszFile;
  if (hDoc == NULL)
    {
      MsgBox ("Filename passed to NexToDo is NULL", MB_OK);
      return;
    };
  NumOfLines = Gte_GetNumberOfLines (pszFile);
  if (NumOfLines == 0)
    {
      MsgBox ("NumOfLines is empty!!!!!", MB_OK);
      return;
    };
  if (NumOfLines < 1)
    {
      MsgBox ("NumOfLines in file is less then 1. File is empty", MB_OK);
    };
  if (NumOfLines > 0)
    {
      MsgBox ("NumOfLines is more than 0.", MB_OK);
    };
  
//    strcpy(g_szDebug, NumOfLine);
    
//      MsgBox(NumOfLines, MB_OK);
    
// Const arg to non cont pointer:
//     Gte_GetLine(hDoc, NumOfLines, szLine, sizeof(szLine));
//     Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));
//     MsgBox(szLine, MB_OK);
    lLineNumber = 1;
  MsgBox (szLine, MB_OK);
  
    //read one line from file into szLine
// int Gte_GetLine(HDOC hDoc, long lLineNumber, char * pszBuf, unsigned nBufSize)
//    Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));
    Gte_GetLine (hDoc, lLineNumber + 1, *szLine, sizeof (szLine));
  
//*      Gte_GetLine(hDoc, lLineNumber+1, pszFile, sizeof(pszFile));
//      Gte_GetLine(hDoc, i+1, szLine, sizeof(szLine));
    MsgBox (szLine, MB_OK);
  return;
  
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
void
NextToDoFile2 (HDOC hdoc) 
{
  int nWordWrapCol;
  char *pszLine;
  long lLine;
  char szCmdLine[1024];
  return;
  
//   nWordWrapCol = Gte_GetWordWrapCol();
    
    // reserve memory for line
    pszLine = (char *) malloc (Gte_GetMaxLineLen () + 1);
  if (pszLine == NULL)
    {
      MsgBox ("Not enought memory", MB_OK);
      return;
    }
  
//   strcpy(szCmdLine, "c:\\progra~1\\GDWedit\\");
//   strcat(szCmdLine, "VJ_todo.log");
    strcpy (szCmdLine, "VJ_todo.log");
  if (access (szCmdLine, 0) == 0)
    
    {
      hdoc = szCmdLine;
    }
  
  else
    
    {
      strcat (szCmdLine, " does not exist");
      MsgBox (szCmdLine, MB_OK);
      return;
    }
  
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
    // for each line in the document (be careful we must always call
    // Gte_GetNumOfLines because number of lines in the document will
    // be probably increased in the loop)
    for (lLine = 1; lLine <= Gte_GetNumberOfLines (hdoc); lLine++)
    
    {
      if (MsgBox ("in for ...", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2)
	    != IDYES)
	
	{
	  return;
	}
      
//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
//        Gte_SetCursorPos("VJ_todo.log",1, lLine, FALSE);
	
//      if(Gte_GetLineLen(hdoc, lLine, FALSE) > nWordWrapCol)
	if (1 == 1)
	
	{
	  char *psz;
	  
//         int  nWrapAtCol = 0; // insert new line at this column pos
	    MsgBox ("before getline...", MB_OK);
	  
//         Gte_GetLine(hdoc, lLine, pszLine, Gte_GetMaxLineLen()+1);
//OKOKOK     Gte_GetLine("c:\\progra~1\\GDWedit\\VJ_todo.log", lLine+1, pszLine, Gte_GetMaxLineLen()+1);
	    
//ok     Gte_GetLine("VJ_todo.log", lLine+1, pszLine, 10);
	    Gte_GetLine (szCmdLine, lLine + 1, pszLine, 10);
	  
//         Gte_GetLine(hdoc, lLine+1, pszLine, sizeof(pszLine));
//         Gte_GetLine(hdoc, 1, pszLine, 5);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
	    MsgBox ("after getline...", MB_OK);
	  psz = pszLine;
	  
//
	    MsgBox (psz, MB_OK);
	  MsgBox (pszLine, MB_OK);
	  
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
  RestoreCursor ();
  free (pszLine);
}


//************************************************************* eof
  
