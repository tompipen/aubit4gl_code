/********************************************************************
                         CONFIG
********************************************************************/  
  
#include <dir.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <editor/app.h>
#include <editor/dlg.h>
#include <editor/doc.h>
#include <editor/macros.h>
#include <sys\stat.h>		// for stat - test_time()
#include <time.h>		// for stat - test_time()
#include <io.h>			//needed for access function
  
#define MAX_FILE_LOCATION  80	// max file location string
#define MAX_FILE_NAME      80
  
#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
  
// global variables
char g_szTakeOutCmd[MAX_CMDLEN];
char g_szPutBackCmd[MAX_CMDLEN];
char g_szMakeCmd[MAX_CMDLEN];
char g_szServerInitDir[MAX_INIT_DIR];
char g_szClientInitDir[MAX_INIT_DIR];
char g_szServerName[MAX_SERVER_NAME];
char g_szUserName[MAX_USER_NAME];
char g_szPassword[MAX_PASSWORD];
char g_szArea[MAX_CMDLEN];
char g_szSysName[MAX_CMDLEN];
char g_szFileLocation[MAX_FILE_LOCATION];
char g_szFileName[MAX_FILE_NAME];
char TMPg_szClientInitDir[MAX_INIT_DIR];
char g_szDebug[MAX_FILE_NAME];
char *psz;

// function prototypes
void UnixPathToDosPath (char *);	// Common
void DosPathToUnixPath (char *);	// Common
void ReplaceNonDOSchar (char *);	// Common
BOOL MakeDir (const char *pszDir);	// Common
void OpenTOC (void);		// Menu 1
//void OpenMakefile(void);              // Menu 2
//void GrepToc(void);                   // Menu 3
//void GrepMakefile(void);              // Menu 4
void RemoteOptionsConfig (void);	// Menu 5
void MkDirFromFile (void);	// Menu 6
void TerminalIniFile (void);	// Menu 7
//void ReadFile(HDOC);                    //
//void ReadFileTest(HDOC hdoc)            //
//void ReadLine(HDOC hdoc)                //
void test_4gl_version (void);
void select_4gl_version (void);
void test_env_read (void);
void test_time (void);

/*-------------------------------------------------------------------
            main function - menu
-------------------------------------------------------------------*/ 
  int
main (int argc, char *argv[]) 
{
  
    // List box used as a menu
//   while(TRUE)
//   {
  char *pMenu[] = { "Open TOC for active document",	// 1
    "Open Makefile for active document",	// 2
    "Search all files in TOC for active document",	// 3
    "Search all files in Makefile for active document",	// 4
    "Configure options and defaults for all remote functions",	// 5
    "Make directory structure based on file remote server",	// 6
    "Test reading and writing from plwin ini file",	// 7
    "Display 4GL version configuration info",	// 8
    "Test reading environment",	// 9
    "Test compare file time", NULL 
  };
  int nIdx;
  nIdx = Gte_ListBoxDlg ("Choose Command", pMenu);
  if (nIdx == 0)
    return (0);
  switch (nIdx)
    
    {
    case 1:
      OpenTOC ();
      return (0);		// break;
    case 2:
      return (0);		// break;
    case 3:
      return (0);		// break;
    case 4:
      return (0);		// break;
    case 5:
      RemoteOptionsConfig ();
      return (0);		// break;
    case 6:
      MkDirFromFile ();
      return (0);		// break;
    case 7:
      TerminalIniFile ();
      return (0);
    case 8:
      test_4gl_version ();
      return (0);
    case 9:
      test_env_read ();
      return (0);
    case 10:
      test_time ();
      return (0);
      
	//       ReadFile(HDOC);
//                ReadFileTest(HDOC hdoc)
    }
  
//   }
    return 0;
}


/*-------------------------------------------------------------------
        RemoteOptionsConfig - Configure options and defaults for
        all Remote functions
-------------------------------------------------------------------*/ 
  void
RemoteOptionsConfig (void) 
{
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "TakeOutCmd", "", g_szTakeOutCmd,
			     sizeof (g_szTakeOutCmd), "remote.ini");
  GetPrivateProfileString ("Remote", "PutBackCmd", "", g_szPutBackCmd,
			    sizeof (g_szPutBackCmd), "remote.ini");
  GetPrivateProfileString ("Remote", "MakeCmd", "", g_szMakeCmd,
			    sizeof (g_szMakeCmd), "remote.ini");
  GetPrivateProfileString ("Remote", "ServerInitDir", "", g_szServerInitDir,
			    sizeof (g_szServerInitDir), "remote.ini");
  GetPrivateProfileString ("Remote", "ClientInitDir", "", g_szClientInitDir,
			    sizeof (g_szClientInitDir), "remote.ini");
  GetPrivateProfileString ("Remote", "ServerName", "", g_szServerName,
			    sizeof (g_szServerName), "remote.ini");
  GetPrivateProfileString ("Remote", "UserName", "", g_szUserName,
			    sizeof (g_szUserName), "remote.ini");
  GetPrivateProfileString ("Remote", "Password", "", g_szPassword,
			    sizeof (g_szPassword), "remote.ini");
  select_4gl_version ();
  if (Gte_GetStringDlg
	("TakeOut command", "&TakeOut command:", g_szTakeOutCmd,
	 sizeof (g_szTakeOutCmd)) != FALSE)
    
    {
      WritePrivateProfileString ("Remote", "TakeOutCmd", g_szTakeOutCmd,
				  "remote.ini");
    }
  if (Gte_GetStringDlg
	("PutBack command", "&PutBack command:", g_szPutBackCmd,
	 sizeof (g_szPutBackCmd)) != FALSE)
    
    {
      WritePrivateProfileString ("Remote", "PutBackCmd", g_szPutBackCmd,
				  "remote.ini");
    }
  if (Gte_GetStringDlg ("Make command", "&Make command:", 
//      g_szPutBackCmd, sizeof(g_szMakeCmd)) != FALSE)
			  g_szMakeCmd, sizeof (g_szMakeCmd)) != FALSE)
    
    {
      WritePrivateProfileString ("Remote", "MakeCmd", g_szMakeCmd,
				  "remote.ini");
    }
  if (Gte_GetStringDlg
	("Server Initial Directory", "&Server initial dir:",
	 g_szServerInitDir, sizeof (g_szServerInitDir)) != FALSE)
    
    {
      WritePrivateProfileString ("Remote", "ServerInitDir",
				  g_szServerInitDir, "remote.ini");
    }
  MsgBox ("Select client (WinNT) initial directory", MB_OK);
  if (Gte_BrowseForDirDlg
       (g_szClientInitDir, sizeof (g_szClientInitDir), FALSE) != FALSE)
    WritePrivateProfileString ("Remote", "ClientInitDir", g_szClientInitDir,
				"remote.ini");
  if (Gte_GetStringDlg
	("Server Name", "&Server name:", g_szServerName,
	 sizeof (g_szServerName)) != FALSE)
    WritePrivateProfileString ("Remote", "ServerName", g_szServerName,
				"remote.ini");
  if (Gte_GetStringDlg
	("User Name", "&User name:", g_szUserName,
	 sizeof (g_szUserName)) != FALSE)
    WritePrivateProfileString ("Remote", "UserName", g_szUserName,
				"remote.ini");
  if (MsgBox
	("Do you want to specify password? If you specify password here, it will not be "
	  "encripted and everyone will be able to see it",
	 MB_YESNO) == IDYES)
    
    {
      if (Gte_GetStringDlg
	   ("Password", "&Password:", g_szPassword,
	    sizeof (g_szPassword)) != FALSE)
	
//         return 
	  WritePrivateProfileString ("Remote", "Password", g_szPassword,
				     "remote.ini");
    }
  
//   return 0;
    return;
}


//-------------------------------------------------- RemoteOptionsConfig()
  
/*-------------------------------------------------------------------
         Get_TOC - open TOC file for active document
-------------------------------------------------------------------*/ 
  void
OpenTOC (void) 
{
  HDOC hDoc;
  char szCmdLine[1024];
  hDoc = Gte_GetActiveDocument ();
  if (hDoc == NULL)
    {
      MsgBox ("Document must be open in editor, to find TOC file for it !",
	       MB_OK);
      return 1;
    }
  
    // save cursor position
    GM_SaveCursorPos (hDoc);
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    GM_SaveFile (hDoc);
  
    // read configuration from ini file
//   GetPrivateProfileString("Remote", "PutBackCmd", "", g_szPutBackCmd, sizeof(g_szPutBackCmd), "remote.ini");
    GetPrivateProfileString ("Remote", "ServerInitDir", "", g_szServerInitDir,
			     sizeof (g_szServerInitDir), "remote.ini");
  GetPrivateProfileString ("Remote", "ClientInitDir", "", g_szClientInitDir,
			    sizeof (g_szClientInitDir), "remote.ini");
  GetPrivateProfileString ("Remote", "ServerName", "", g_szServerName,
			    sizeof (g_szServerName), "remote.ini");
  GetPrivateProfileString ("Remote", "UserName", "", g_szUserName,
			    sizeof (g_szUserName), "remote.ini");
  GetPrivateProfileString ("Remote", "Password", "", g_szPassword,
			    sizeof (g_szPassword), "remote.ini");
  
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
      if (Gte_GetStringDlg
	   ("Server Initial Directory", "&Server initial dir:",
	    g_szServerInitDir, sizeof (g_szServerInitDir)) == FALSE)
	
	{
	  return;
	}
      if (strlen (g_szServerInitDir) == 0)
	{
	  MsgBox ("Invalid initial dir", MB_OK);
	  return;
	}
    }
  if (strlen (g_szClientInitDir) == 0)
    {
      MsgBox ("Select client initial directory", MB_OK);
      if (Gte_BrowseForDirDlg
	   (g_szClientInitDir, sizeof (g_szClientInitDir), FALSE) == FALSE)
	return;
      if (strlen (g_szClientInitDir) == 0)
	{
	  MsgBox ("Invalid client initial dir", MB_OK);
	  return;
	}
    }
  if (strlen (g_szServerName) == 0)
    {
      if (Gte_GetStringDlg
	   ("Server Name", "&Server name:", g_szServerName,
	    sizeof (g_szServerName)) == FALSE)
	return;
      if (strlen (g_szServerName) == 0)
	{
	  MsgBox ("Invalid server name", MB_OK);
	  return;
	}
    }
  if (strlen (g_szUserName) == 0)
    {
      if (Gte_GetStringDlg
	   ("User Name", "&User name:", g_szUserName,
	    sizeof (g_szUserName)) == FALSE)
	return;
      if (strlen (g_szUserName) == 0)
	{
	  MsgBox ("Invalid user name", MB_OK);
	  return;
	}
    }
  if (strlen (g_szPassword) == 0)
    {
      if (Gte_GetStringDlg
	   ("Password", "&Password:", g_szPassword,
	    sizeof (g_szPassword)) == FALSE)
	return;
      if (strlen (g_szPassword) == 0)
	{
	  MsgBox ("Invalid password", MB_OK);
	  return;
	}
    }
  
    // from the filename and takeout.ini determine default filename and location
  {
    char szDocFileName[FILENAME_MAX];
    char szTakeOutFile[FILENAME_MAX];
    szDocFileName[0] = 0;
    Gte_GetFileName (hDoc, szDocFileName, sizeof (szDocFileName));
    UnixPathToDosPath (szDocFileName);
    GetPrivateProfileString ("Remote", "LastTakeOutLocation", "",
			       g_szFileLocation, sizeof (g_szFileLocation),
			       "remote.ini");
    if (szDocFileName)
      GetPrivateProfileString ("TakeOutLocation", szDocFileName,
				g_szFileLocation, g_szFileLocation,
				sizeof (g_szFileLocation), "takeout.ini");
    GetPrivateProfileString ("Remote", "LastTakeOutFileName", "",
			      g_szFileName, sizeof (g_szFileName),
			      "remote.ini");
    if (szDocFileName)
      GetPrivateProfileString ("TakeOutFileName", szDocFileName,
				g_szFileName, g_szFileName,
				sizeof (g_szFileName), "takeout.ini");
    
      // Check if this is the right file
      strcpy (szTakeOutFile, g_szClientInitDir);
    strcat (szTakeOutFile, g_szFileLocation);
    strcat (szTakeOutFile, g_szFileName);
    UnixPathToDosPath (szTakeOutFile);
    
/*-------------------------------------------------------------------
//  out because of removed "C:" from local path (rcp don't like disk label
//  in local path) this is never same:
//  SzTakeOutFile =   \dataLI\src\ldg_qbf.5gl
//  szDocFileName = c:\data\LI\src\ldg_qbf.5gl

//af debug:
//MsgBox(szTakeOutFile, MB_OK);
//MsgBox(szDocFileName, MB_OK);
//af debug end

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
	  MsgBox ("Invalid file location", MB_OK);
	}
      
      else
	break;
    }
  
    // ask for file name
    while (TRUE)
    
    {
      if (Gte_GetStringDlg
	    ("File Name", "&File name:", g_szFileName,
	     sizeof (g_szFileName)) == FALSE)
	
	{
	  
	    // user click Cancel
	    return;
	}
      if (strpbrk (g_szFileName, "\\/:*?"))
	
	{
	  MsgBox ("Invalid file name", MB_OK);
	}
      
      else
	break;
    }			//xxxxxx
  
    // ask for system name
//   while(TRUE)
//   {
    
    // read previous system name form ini file
    GetPrivateProfileString ("Remote", "LastSysRun", "", g_szSysName,
			     sizeof (g_szSysName), "remote.ini");
  if (Gte_GetStringDlg
	("System name", "&System name:", g_szSysName,
	 sizeof (g_szSysName)) == FALSE)
    
    {
      
	// user click Cancel
	return;
    }
  
    // Ask for Area name to do sw (Fujitsu NZ special)
    
    // read previous Area name form ini file
    GetPrivateProfileString ("Remote", "LastArea", "", g_szArea,
			     sizeof (g_szArea), "remote.ini");
  if (Gte_GetStringDlg
	("Area name", "&Area name:", g_szArea, sizeof (g_szArea)) == FALSE)
    
    {
      
	// user click Cancel
	return;
    }
  
    //   }
    // write last Area name to ini file
    WritePrivateProfileString ("Remote", "LastArea", g_szArea, "remote.ini");
  
    // write last system name to ini file
    WritePrivateProfileString ("Remote", "LastSysRun", g_szSysName,
			       "remote.ini");
  
//   }
    
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
/*
Switches for start command:
START [options] program [arg...]
START [options] document.ext
/m[inimized] Run the new program minimized (in the background).
/max[imized] Run the new program maximized (in the foreground).
/r[estored]  Run the new program restored (in the foreground). [default]
/w[ait]      Does not return until the other program exits.
*/ 
//   strcpy(szCmdLine, "start /m GetTOC.bat ");
    strcpy (szCmdLine, "bat\\GetTOC.bat ");
  if (strchr (g_szSysName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szSysName);
  if (strchr (g_szSysName, ' '))
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
  if (strchr (g_szServerName, '"'))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szServerName);
  if (strchr (g_szServerName, '"'))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  if (strchr (g_szUserName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szUserName);
  if (strchr (g_szUserName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, " ");
  
/*
   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");
   strcat(szCmdLine, g_szPassword);
   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");


    send Area name instead of ServerInitDir witch is irrelevant if we
    use environment generated by sw command and Jmk for Make

*/ 
    if (strchr (g_szArea, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szArea);
  if (strchr (g_szArea, ' '))
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
  
//    MsgBox(szCmdLine, MB_OK);
    system (szCmdLine);
  
    // restore cursor position
    GM_RestoreCursorPos (hDoc);
  Gte_FixWindowPos (hDoc);
  
//   return 0;
    return;
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


//----------------------------------------------------------------EOF
  
//###################################################################
  void
MkDirFromFile (void) 
//###################################################################
{
  int nWordWrapCol;
  char *pszLine;
  long lLine;
  char szCmdLine[1024];
  char szMessage[1024];
  char pszMakeDir[1024];
  char pszInitialPath[1024];
  char szFileName[FILENAME_MAX];
  HDOC hdoc;
  szFileName[0] = 0;
  if (Gte_BrowseForFileDlg
       (szFileName, sizeof (szFileName),
	"DirStr file (dirstr.txt)|dirstr.txt|Txt files (*.txt)|*.txt|",
	"Select file with directory structure to be created", FALSE, FALSE,
	NULL))
    
    {
      if (access (szFileName, 0) == 0)
	
	{
	  Gte_OpenDocument (szFileName);
	  hdoc = Gte_GetActiveDocument ();
	}
      
      else
	
	{
	  strcpy (szMessage, szFileName);
	  strcat (szMessage, " does not exist");
	  MsgBox (szMessage, MB_OK);
	  return;
	}
    }
  
  else
    
    {
      return;
    }
  strcpy (pszInitialPath, "/Program files/GDWedit/remote/nezsdc");
  strcpy (szMessage,
	    "Are youre shure you want to create directory structure based on this file, starting from ");
  strcat (szMessage, pszInitialPath);
  strcat (szMessage, " ?");
  if (MsgBox (szMessage, MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) ==
	IDNO)
    
    {
      Gte_CloseDocument (hdoc);
      return;
    }
  
    // reserve memory for line
    pszLine = (char *) malloc (Gte_GetMaxLineLen () + 1);
  if (pszLine == NULL)
    {
      MsgBox ("Not enought memory", MB_OK);
      return;
    }
  
    // Show wait mouse cursor (hourglass)
    WaitCursor ();
  
    // for each line in the document (be careful we must always call
    // Gte_GetNumOfLines because number of lines in the document will
    // be probably increased in the loop)
    
// First line will be root (/) so start from second line...
//   for(lLine = 0; lLine <= Gte_GetNumberOfLines(hdoc); lLine++)
    for (lLine = 1; lLine <= Gte_GetNumberOfLines (hdoc); lLine++)
    
    {
      
//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
	
      {
	
//         char *psz;
	  Gte_GetLine (hdoc, lLine + 1, pszLine, Gte_GetMaxLineLen () + 1);
	
/*
         if(MsgBox(pszLine,
            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDNO)
         {
              break;
         }
*/ 
	  
	  // Add Path to remote directory
	  strcpy (pszMakeDir, pszInitialPath);
	strcat (pszMakeDir, pszLine);
	
//      MsgBox(pszMakeDir, MB_OK);
	  UnixPathToDosPath (pszMakeDir);
	
//      MsgBox(pszMakeDir, MB_OK);
	  if (strpbrk (pszMakeDir, ":*?\"<>|"))
	  
	  {
	    ReplaceNonDOSchar (pszMakeDir);
	  }
	if (strpbrk (pszMakeDir, ":*?\"<>|"))
	  
	  {
	    strcpy (szMessage, "Invalid dir name: ");
	    strcat (szMessage, pszMakeDir);
	    MsgBox (szMessage, MB_OK);
	    return;
	  }
	if (MakeDir (pszMakeDir) == FALSE)
	  
	  {
	    char szMsg[512];
	    sprintf (szMsg, "Cannot create %s directory", pszMakeDir);
	    MsgBox (szMsg, MB_OK | MB_ICONSTOP);
	    Gte_CloseDocument (hdoc);
	    RestoreCursor ();
	    return;
	    
//                break;
	  }
      }
      
	// Display progress on status bar after every 10 lines
	if (lLine % 10 == 0)
	
	{
	  char szMsg[80];
	  sprintf (szMsg,
		     "Press Ctrl-Break to cancel operation: %0d%% completed",
		     (int) (lLine * 100 / Gte_GetNumberOfLines (hdoc)));
	  Gte_StatusBarMsg (szMsg);
	}
    }
  Gte_CloseDocument (hdoc);
  RestoreCursor ();
  free (pszLine);
}


//###################################################################
  void
TerminalIniFile (void) 
//###################################################################
{
  
    // Test reading and writing from plwin ini file:
    
    //  ...
    //  macro hdr 1=login
    //  macro key 1 line 1=WAIT("Login:")
    //  macro key 1 line 2=SEND("andrejf")
    //  macro key 1 line 3=RETURN
    //  macro key 1 line 4=WAIT("Password:")
    //  macro key 1 line 5=SEND("11sajonara")
    //  macro key 1 line 6=RETURN
    //  macro key 1 line 7=
    //  ...
    GetPrivateProfileString ("doc18-8-c", "macro key 1 line 2", "",
			      g_szDebug, FILENAME_MAX,
			      "c:\\plwin\\plwin.ini");
  MsgBox (g_szDebug, MB_OK);
  WritePrivateProfileString ("doc18-8-c", "macro key 1 line 2",
			       "SEND ahaha", "c:\\plwin\\plwin.ini");
  GetPrivateProfileString ("doc18-8-c", "macro key 1 line 2", "", g_szDebug,
			     FILENAME_MAX, "c:\\plwin\\plwin.ini");
  MsgBox (g_szDebug, MB_OK);
}


//###################################################################
  void
ReadFileTest (HDOC hdoc) 
//###################################################################
{
  int nWordWrapCol;
  char *pszLine;
  long lLine;
  char szCmdLine[1024];
  char szMessage[1024];
  
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
    
//   strcpy(szCmdLine, "VJ_todo.log");
    strcpy (szCmdLine, hdoc);
  if (access (szCmdLine, 0) == 0)
    
    {
      
//        hdoc = szCmdLine;
	Gte_OpenDocument (szCmdLine);
      hdoc = Gte_GetActiveDocument ();
      
//       MsgBox(szCmdLine, MB_OK);
//          Gte_GetLine( hdoc, lLine+1, pszLine, 10);
	
//        Gte_GetLine(hdoc, ypos, pszLine, Gte_GetMaxLineLen() + 1);
	
//          MsgBox(pszLine, MB_OK);
//          Gte_CloseDocument(hdoc);
	
//          return;
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
    for (lLine = 0; lLine <= Gte_GetNumberOfLines (hdoc); lLine++)
    
    {
      
//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
//        Gte_SetCursorPos("VJ_todo.log",1, lLine, FALSE);
	
//      if(Gte_GetLineLen(hdoc, lLine, FALSE) > nWordWrapCol)
//        if ( 1 == 1 )
      {
	char *psz;
	
//         int  nWrapAtCol = 0; // insert new line at this column pos
	  
//         MsgBox("before getline...", MB_OK);
//         Gte_GetLine(hdoc, lLine, pszLine, Gte_GetMaxLineLen()+1);
//OKOKOK     Gte_GetLine("c:\\progra~1\\GDWedit\\VJ_todo.log", lLine+1, pszLine, Gte_GetMaxLineLen()+1);
	  
//ok     Gte_GetLine("VJ_todo.log", lLine+1, pszLine, 10);
//last          Gte_GetLine( szCmdLine, lLine+1, pszLine, 10);
	  Gte_GetLine (hdoc, lLine + 1, pszLine, Gte_GetMaxLineLen () + 1);
	if (MsgBox (pszLine, MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2)
	       != IDNO)
	  
	  {
	    
//            return;
	      break;
	  }
	
//         Gte_GetLine(hdoc, lLine+1, pszLine, sizeof(pszLine));
//         Gte_GetLine(hdoc, 1, pszLine, 5);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
//         MsgBox("after getline...", MB_OK);
//         psz = pszLine;
	  
//
	  
//         MsgBox(psz, MB_OK);
//         MsgBox(pszLine, MB_OK);
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
  Gte_CloseDocument (hdoc);
  RestoreCursor ();
  free (pszLine);
}


//###################################################################
  
//###################################################################
  void
ReadFile (HDOC hdoc) 
//###################################################################
{
  int nWordWrapCol;
  char *pszLine;
  long lLine;
  char szCmdLine[1024];
  char szMessage[1024];
  
    // reserve memory for line
    pszLine = (char *) malloc (Gte_GetMaxLineLen () + 1);
  if (pszLine == NULL)
    {
      MsgBox ("Not enought memory", MB_OK);
      return;
    }
  strcpy (szCmdLine, hdoc);
  if (access (szCmdLine, 0) == 0)
    
    {
      Gte_OpenDocument (szCmdLine);
      hdoc = Gte_GetActiveDocument ();
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
    for (lLine = 0; lLine <= Gte_GetNumberOfLines (hdoc); lLine++)
    
    {
      
//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
	
      {
	char *psz;
	Gte_GetLine (hdoc, lLine + 1, pszLine, Gte_GetMaxLineLen () + 1);
	
/*
         if(MsgBox(pszLine,
            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDNO)
         {
              break;
         }
*/ 
      }
      
	// Display progress on status bar after every 10 lines
	if (lLine % 10 == 0)
	
	{
	  char szMsg[80];
	  sprintf (szMsg,
		     "Press Ctrl-Break to cancel operation: %0d%% completed",
		     (int) (lLine * 100 / Gte_GetNumberOfLines (hdoc)));
	  Gte_StatusBarMsg (szMsg);
	}
    }
  Gte_CloseDocument (hdoc);
  RestoreCursor ();
  free (pszLine);
}


//###################################################################
  
//###################################################################
  void
ReadLine (HDOC hdoc) 
//###################################################################
{
  int nWordWrapCol;
  char *pszLine;
  long lLine;
  char szCmdLine[1024];
  char szMessage[1024];
  
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
    
//   strcpy(szCmdLine, "VJ_todo.log");
    strcpy (szCmdLine, hdoc);
  if (access (szCmdLine, 0) == 0)
    
    {
      
//        hdoc = szCmdLine;
	Gte_OpenDocument (szCmdLine);
      hdoc = Gte_GetActiveDocument ();
      
//       MsgBox(szCmdLine, MB_OK);
//          Gte_GetLine( hdoc, lLine+1, pszLine, 10);
	Gte_GetLine (hdoc, 1, pszLine, Gte_GetMaxLineLen () + 1);
      
//        Gte_GetLine(hdoc, ypos, pszLine, Gte_GetMaxLineLen() + 1);
	MsgBox (pszLine, MB_OK);
      Gte_CloseDocument (hdoc);
      return;
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
//        if ( 1 == 1 )
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


//################################################### void ReadLine()
  
/*-------------------------------------------------------------------
                    ReplaceNonDOSchar
-------------------------------------------------------------------*/ 
  void
ReplaceNonDOSchar (char *psz) 
{
  while (*psz)
    
    {
      if (*psz == '?')
	*psz = '-';
      if (*psz == ':')
	*psz = '-';
      if (*psz == '*')
	*psz = '-';
      if (*psz == '\"')
	*psz = '-';
      if (*psz == '<')
	*psz = '-';
      if (*psz == '>')
	*psz = '-';
      if (*psz == '|')
	*psz = '-';
      psz++;
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
  char szDirReceived[FILENAME_MAX + 1];
  char szMkDir[FILENAME_MAX + 1];
  char *psz;
  if (pszDir == NULL || *pszDir == 0)
    {
      return FALSE;
    }
  
//   MsgBox("1", MB_OK);
    getcwd (szOldDir, FILENAME_MAX);
  
    // copy pszDir into szSubdirList and replace \ and / with null
    // terminator. At the end we will have list of directory components
    // terminated with two null terimator characters
    strcpy (szSubdirList, pszDir);
  strcpy (szDirReceived, pszDir);
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
    // AF: Except when is "C:\DATA\VJ\src\(*#&_$&"
    szMkDir[0] = 0;
  psz = szSubdirList;
  
//This is C:\DATA   MsgBox(szSubdirList, MB_OK);
    while (*psz != 0)
    
    {
      strcat (szMkDir, psz);
      
	// if dir does not exist create it
	if (chdir (szMkDir) != 0)
	{
	  if (mkdir (szMkDir) != 0)
	    
	    {			// Fail point
	      MsgBox (szDirReceived, MB_OK);
	      strcpy (g_szDebug, "Last psz cat to szMkDir -->");
	      strcat (g_szDebug, psz);
	      strcat (g_szDebug, "<--");
	      MsgBox (g_szDebug, MB_OK);	//  --#||  (psz gets garbage!!!)
	      
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
		strcpy (g_szDebug, "Error Trying to MD -->");
	      strcat (g_szDebug, szMkDir);
	      strcat (g_szDebug, "<--");
	      MsgBox (g_szDebug, MB_OK);	//  C:\Data\VJ\src...and then full screen of garbage....
	      //  C:\Data\VJ\src\#||
	      MsgBox (szOldDir, MB_OK);
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


//###################################################################
  void
test_4gl_version (void) 
//###################################################################
{
  int n4glVer;
  
/*
char n4glVerASCII[2];
GetPrivateProfileString("Remote", "4GLVersion","", n4glVerASCII, sizeof(n4glVerASCII), "remote.ini");
MsgBox(n4glVerASCII, MB_OK);
*/ 
    n4glVer = GetPrivateProfileInt ("Remote", "4GLVersion", 0, "remote.ini");
  if (n4glVer == 0)
    
    {
      MsgBox ("4GLVersion in remote.ini is not defined", MB_OK);
    }
  
  else
    
    {
      switch (n4glVer)
	
	{
	case 1:
	  strcpy (g_szDebug, "Type 1 is local 4GL for DOS");
	  MsgBox (g_szDebug, MB_OK);
	  return;
	case 2:
	  strcpy (g_szDebug, "Type 2 is local 4GL for Windows");
	  MsgBox (g_szDebug, MB_OK);
	  return;
	case 3:
	  strcpy (g_szDebug, "Type 3 is remote Informix 4GL");
	  MsgBox (g_szDebug, MB_OK);
	  return;
	case 4:
	  strcpy (g_szDebug, "Type 4 is remote 4Js/Informix D4GL GUI");
	  MsgBox (g_szDebug, MB_OK);
	  return;
	case 5:
	  strcpy (g_szDebug, "Type 5 is remote 4Js/Informix D4GL CHUI");
	  MsgBox (g_szDebug, MB_OK);
	  return;
	}
    }
}


//###################################################################
  void
select_4gl_version (void) 
//###################################################################
{
  int n4glVer;
  int nIdx;
  char *pMenu[] = { "Keep current selection",	// 1
    "1: local 4GL for DOS",	// 2
    "2: local 4GL for Windows",	// 3
    "3: remote Informix 4GL",	// 4
    "4: remote 4Js/Informix D4GL GUI",	// 5
    "5: remote 4Js/Informix D4GL CUI",	// 6
    NULL 
  };
  n4glVer = GetPrivateProfileInt ("Remote", "4GLVersion", 0, "remote.ini");
  strcpy (g_szDebug, "Select 4GL type (Current selection: ");
  if (n4glVer == 0)
    
    {
      strcat (g_szDebug, "Not set)");
    }
  
  else
    
    {
      switch (n4glVer)
	
	{
	case 1:
	  strcat (g_szDebug, "local 4GL for DOS)");
	  break;
	case 2:
	  strcat (g_szDebug, "local 4GL for Windows)");
	  break;
	case 3:
	  strcat (g_szDebug, "remote Informix 4GL)");
	  break;
	case 4:
	  strcat (g_szDebug, "remote 4Js/Informix D4GL GUI)");
	  break;
	case 5:
	  strcat (g_szDebug, "remote 4Js/Informix D4GL CHUI)");
	  break;
	}
    }
  nIdx = Gte_ListBoxDlg (g_szDebug, pMenu);
  if (nIdx == 0)
    return;
  switch (nIdx)
    
    {
    case 1:			// keep current
      return;
    case 2:
      WritePrivateProfileString ("Remote", "4GLVersion", "1", "remote.ini");
      return;
    case 3:
      WritePrivateProfileString ("Remote", "4GLVersion", "2", "remote.ini");
      return;
    case 4:
      WritePrivateProfileString ("Remote", "4GLVersion", "3", "remote.ini");
      return;
    case 5:
      WritePrivateProfileString ("Remote", "4GLVersion", "4", "remote.ini");
      return;
    case 6:
      WritePrivateProfileString ("Remote", "4GLVersion", "5", "remote.ini");
      return;
    }
}


//###################################################################
  void
test_env_read (void) 
//###################################################################
{
  char szEnvVar[50];
  char *szChar;
  char szEnvName[20];
  
//   strcpy(szEnvName,"COMSPEC");
//   strcpy(szEnvName,"TEST");
    strcpy (szEnvName, "BLASTER");
  szChar = getenv (szEnvName);
  strcpy (szEnvVar, szEnvName);
  strcat (szEnvVar, " is set to -");
  if (szChar != 0)
    
    {
      strcat (szEnvVar, szChar);
    }
  
  else
    
    {
      strcat (szEnvVar, "");
    }
  strcat (szEnvVar, "-");
  MsgBox (szEnvVar, MB_OK);
}


  // test reading parameters passed from macro calling this c code:
  
  /*
     strcpy (g_szFileName,argv[0]);  // This gives full path to this source
     strcpy (g_szFileName,argv[1]); // This gives GPF
     MsgBox(g_szFileName, MB_OK);
     return 1;
   */ 
  
//###################################################################
  void
test_time (void) 
//###################################################################
{
  
/*
 char * asctime(const struct tm * timeptr)
 The asctime function converts a tm structure to a 26-character string in
 the following format: "Sat Feb 14 16:52:00 1998\n\0"

 char * ctime(const time_t * timer)
 The ctime function converts a time_t to a 26-character string in the
 following format: "Sat Feb 14 16:52:00 1998\n\0"

#include <time.h>
double difftime(time_t time1, time_t time0)
The difftime function returns difference between two times in seconds.
Parameters
time1
Ending time.
time0
Beginning time.


#include <sys\stat.h>
int stat(cons char * filename, stat_t * statbuf)
The stat function returns file information.
Parameters
filename - Path of existing file.
statbuf - Pointer to structure that stores results.
Return Value - On success returns 0. On error returns -1 and sets the global variable errno to error code.

The stat_t structure contains the following fields:
st_mode	Bit mask giving information about the file's mode. The S_IFCHR bit is set if handle refers to a device. The S_IFREG bit is set if handle refers to an ordinary file. S_WRITE bit is set if user has permission mode. to write to file. S_READ bit is set if user has permission mode. to read file.
st_dev	Drive number of disk containing the file or file handle if the file is on a device.
st_rdev	Same as st_dev.
st_nlink	Set to the integer constant 1.
st_size	Size of the file in bytes.
st_atime	Time of last file access.
st_mtime	Time of last file modification.
st_ctime	Time of creation of file.

typedef struct {
    short st_dev;
	short st_ino;
	short st_mode;
	short st_nlink;
	int st_uid;
	int st_gid;
	short st_rdev;
	long st_size;
	long st_atime;
	long st_mtime;
	long st_ctime;
} stat_t;

*/ 
  char szFileName1[FILENAME_MAX];
  char szFileName2[FILENAME_MAX];
  char szTime1[50];
  char szTime2[50];
  stat_t statbuf1;
  stat_t statbuf2;
  int nIdx;
  strcpy (szFileName1, "c:\\autoexec.bat");
  strcpy (szFileName2, "c:\\config.sys");
  nIdx = stat (szFileName1, &statbuf1);
  nIdx = stat (szFileName2, &statbuf2);
  sprintf (szTime1, " %0d ", (int) (statbuf1.st_mtime));
  sprintf (szTime2, " %0d ", (int) (statbuf2.st_mtime));
  if (statbuf1.st_mtime > statbuf2.st_mtime)
    
    {
      
	// first is bigger
	strcpy (g_szDebug, szFileName1);
      strcat (g_szDebug, " is newer than ");
      strcat (g_szDebug, szFileName2);
      strcat (g_szDebug, " (");
      strcat (g_szDebug, szTime1);
      strcat (g_szDebug, ">");
      strcat (g_szDebug, szTime2);
      strcat (g_szDebug, ")");
    }
  
  else
    
    {
      
	// second is bigger, or they are equal
	strcpy (g_szDebug, szFileName2);
      strcat (g_szDebug, " is newer or equal than ");
      strcat (g_szDebug, szFileName1);
      strcat (g_szDebug, " (");
      strcat (g_szDebug, szTime2);
      strcat (g_szDebug, ">");
      strcat (g_szDebug, szTime1);
      strcat (g_szDebug, ")");
    }
  MsgBox (g_szDebug, MB_OK);
}


/*

Otvoren u GWD Text Editoru kao text file ili u GWD C Scriptu funkcijom fopen?
Ako se misli na dokument iz text editora, onda je to moguce.

Funkcija Gte_GetFileName vraca ime file-a, ako je poznat njegov hDoc, a
funkcija Gte_GetActiveDocument vraca hDoc aktivnog dokumenta, a makro
GM_NextWindow(hDoc) postavlja slijedeci dokument za aktivni.

Evo npr funkcije koja ce vratiti hDoc za ime datoteke ili NULL ako taj doc
nije otvoren. Kasnije samo treba pozvati Gte_CloseDocument:

HDOC GetHandleForFileName(const char *pszFileName)
{
   HDOC hDocFirst;
   HDOC hDoc;
   char szActiveFileName[FILENAME_MAX];

   hDocFirst = Gte_GetActiveDocument();
   if(hDocFirst == NULL)
      return NULL;

   if(Gte_GetFileName(hDoc, szActiveFileName, FILENAME_MAX) > 0)
   {
      if(strcmpi(pszFileName, szActiveFileName) == 0)
         return hDocFirst;
   }
   GM_NextWindow(hDocFirst);
   hDoc = Gte_GetActiveDocument();
   while(hDoc !+ NULL && hDoc != hDocFirst)
   {
      hDoc = Gte_GetActiveDocument();
      if(hDoc == NULL)
         return NULL; // nemoguce

      if(Gte_GetFileName(hDoc, szActiveFileName, FILENAME_MAX) > 0)
      {
         if(strcmpi(pszFileName, szActiveFileName) == 0)
            return hDoc;
      }
      GM_NextWindow(hDoc);
      hDoc = Gte_GetActiveDocument();
   }
   return NULL;
}

*/ 
  
// ############################################################## EOF
