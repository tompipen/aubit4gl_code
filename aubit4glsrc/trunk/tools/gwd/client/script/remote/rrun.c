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
#include <io.h>			// for access
  
#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80	// max file location string
#define MAX_FILE_NAME      80
  
// global variables
char g_szSysName[MAX_CMDLEN];
char g_szServerInitDir[MAX_INIT_DIR];
char g_szClientInitDir[MAX_INIT_DIR];
char g_szServerName[MAX_SERVER_NAME];
char g_szUserName[MAX_USER_NAME];
char g_szPassword[MAX_PASSWORD];
char g_szFileLocation[MAX_FILE_LOCATION];
char g_szFileName[MAX_FILE_NAME];
char g_szDebug[MAX_FILE_LOCATION];
int g_n4glVer;

// function prototypes
void ScriptMain (HDOC);
void Run4glWin (HDOC);
void PutBack (void);
void UnixPathToDosPath (char *);
void DosPathToUnixPath (char *);

/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/ 
  int
main (int argc, char *argv[]) 
//int main(char Param[20])
{
  HDOC hDoc;
  hDoc = Gte_GetActiveDocument ();
  if (hDoc == NULL)
    {
      MsgBox ("Document must be open in editor, to run it !", MB_OK);
      return 1;
    }
  
    // save cursor position
    GM_SaveCursorPos (hDoc);
  
    // call main script function
    ScriptMain (hDoc);
  
    // restore cursor position
    GM_RestoreCursorPos (hDoc);
  Gte_FixWindowPos (hDoc);
  return 0;
}


/*-------------------------------------------------------------------
                         ScriptMain

  Main script function.

  PARAMETERS

     hDoc - Handle of active document.
-------------------------------------------------------------------*/ 
  void
ScriptMain (HDOC hDoc) 
{
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    GM_SaveFile (hDoc);
  
    // get 4gl type
    g_n4glVer =
    GetPrivateProfileInt ("Remote", "4GLVersion", 0, "remote.ini");
  if (g_n4glVer == 0)
    
    {
      MsgBox ("4GLVersion in remote.ini is not defined", MB_OK);
      return;
    };
  switch (g_n4glVer)
    
    {
    case 1:			// local 4GL for DOS
      MsgBox ("Run for DOS not implemented", MB_OK);
      return;
    case 2:			// local Informix 4gl for Windows
      Run4glWin (hDoc);
      return;
    case 3:			// remote Informix 4GL - run in Plwin terminal
      break;
    case 4:			// remote 4Js/Informix D4GL GUI
      break;
    case 5:			// remote 4Js/Informix D4GL CUI - run in Plwin terminal
      break;
    case 6:			// local 4Js/Informix D4GL GUI
      Run4glWin (hDoc);
      return;
    };
  
    // read configuration from ini file
//   GetPrivateProfileString("Remote", "PutBackCmd", "", g_szPutBackCmd, sizeof(g_szPutBackCmd), "gte.ini");
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
			       "gte.ini");
    if (szDocFileName)
      GetPrivateProfileString ("TakeOutLocation", szDocFileName,
				g_szFileLocation, g_szFileLocation,
				sizeof (g_szFileLocation), "takeout.ini");
    GetPrivateProfileString ("Remote", "LastTakeOutFileName", "",
			      g_szFileName, sizeof (g_szFileName), "gte.ini");
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
			     sizeof (g_szSysName), "gte.ini");
  if (Gte_GetStringDlg
	("System name", "&System name:", g_szSysName,
	 sizeof (g_szSysName)) == FALSE)
    
    {
      
	// user click Cancel
	return;
    }
  
    // write last system name to ini file
    WritePrivateProfileString ("Remote", "LastSysRun", g_szSysName,
			       "gte.ini");
  
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
  
    // TakeOut file
    PutBack ();
  return;
}


/*-------------------------------------------------------------------
                         PutBack
-------------------------------------------------------------------*/ 
  void
PutBack (void) 
{
  char szCmdLine[1024];
  
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
    strcpy (szCmdLine, "bat\\rrun.bat ");
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
  if (strchr (g_szClientInitDir, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szClientInitDir);
  if (strchr (g_szClientInitDir, ' '))
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
    strcat (szCmdLine, " 3");
  }
  if (strchr (g_szFileName, ' '))
    strcat (szCmdLine, "\"");
  strcat (szCmdLine, g_szFileName);
  if (strchr (g_szFileName, ' '))
    strcat (szCmdLine, "\"");
  system (szCmdLine);
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


//#####################################################################
  void
Run4glWin (HDOC hDoc) 
//#####################################################################
{
  char szWorkPath[FILENAME_MAX];
  char szRunner[FILENAME_MAX];
  char szProject[FILENAME_MAX];
  char szWindowTitle[FILENAME_MAX];
  char szExecutable[FILENAME_MAX];
  char szProgramTOC[FILENAME_MAX];
  char szProjectTOC[FILENAME_MAX];
  char szCmdLine[1024];
  char szWindowSize[12];
  char szFontName[12];
  char szFontSize[2];
  char szExt[5];
  strcpy (szWorkPath, "c:\\prg\\csi\\wax_3.71.61\\cm\\source");
  strcpy (szProjectTOC, szWorkPath);
  strcat (szProjectTOC, "\\project.toc");
  
//   strcpy(szProject, "job_post");
    GetPrivateProfileString ("Project", "1", "", szProject,
			     sizeof (szProject), szProjectTOC);
  
    //strcpy(szRunner, "C:\\Informix\\BIN\\FGLGX.EXE");
    strcpy (szProgramTOC, szWorkPath);
  strcat (szProgramTOC, "\\");
  strcat (szProgramTOC, szProject);
  strcat (szProgramTOC, ".toc");
  GetPrivateProfileString ("Project", "Runner", "", szRunner,
			     sizeof (szRunner), szProgramTOC);
  strcpy (szFontSize, "8");
  strcpy (szFontName, "Accumon");
  strcpy (szWindowTitle, "Job post replyer");
  
    //  " -WS80X15 ");        // standardno siroki, kratki
    //  " -WS40X15 ");        // isto kao i 80X15
    //  " -WS60x15 ");        // isto kao i 80X15
    //  " -WS107X23 ");       // siroki, 1 red kraci od defaulta
    //  " -WS100X28 ");       // 35 = maksimalna visina na 600*800
    //  " -WS107X30 ");
    //  " -WS90X30 ");
    //  " -WS1000X30 ");      // full screen on 600*800
    strcpy (szWindowSize, "100X30");
  
    //################################################################
    // -FSsize            font size default = 10
    // -FTtype            font type (defaupt = Accumon.fnt)
    // Accumon.fnt: 8 = smanjena visina ista shirina
    //             12 = povecana i visina i sirina
    // -MBBOTTOM          mouse bar on the bottom
    // -MBOFF             no mouse bar
    // -MBRIGHT           mouse bar on the right
    // -WSwidthXheight    window size height lines by width coloumns
    //                Default = 80 x 24
    // "-WTtitle"         window title
    //################################################################
    
    // cmd /K C:\usr\Env.bat & FGLRUN.EXE %1 & exit
    strcpy (szCmdLine, szRunner);
  strcat (szCmdLine, " ");
  
//    strcpy (szCmdLine,""); No go
    if (g_n4glVer != 6)	//local 4Js/Informix D4GL GUI
    {
      
      {
	strcat (szCmdLine, " -FS");
	strcat (szCmdLine, szFontSize);
	strcat (szCmdLine, " ");
      }
      
      {
	strcat (szCmdLine, " -FT");
	strcat (szCmdLine, szFontName);
	strcat (szCmdLine, " ");
      }
      
      {
	strcat (szCmdLine, "-WS");
	strcat (szCmdLine, szWindowSize);
	strcat (szCmdLine, " ");
      }
      
      {
	strcat (szCmdLine, "\"-WT");
	strcat (szCmdLine, szWindowTitle);
	strcat (szCmdLine, "\" ");
      }
      strcpy (szExt, ".4gi");
    }
  
  else
    
    {
      strcpy (szExt, ".42r");
    }
  
  {
    strcpy (szExecutable, szWorkPath);
    strcat (szExecutable, "\\");
    strcat (szExecutable, szProject);
    strcat (szExecutable, szExt);
    strcat (szCmdLine, szExecutable);
    strcat (szCmdLine, " & exit");
  }
  chdir (szWorkPath);
  
//   if(MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES)
//   {
    // UINT WinExec(LPCSTR lpszCmdLine, UINT fuCmdShow)
    // How application will be shown. This parameter can be SW_HIDE,
    // SW_SHOWNORMAL, SW_NORMAL, SW_SHOWMINIMIZED, SW_SHOWMAXIMIZED
    // SW_MAXIMIZE, SW_SHOWNOACTIVATE, SW_SHOW SW_MINIMIZE,
    // SW_SHOWMINNOACTIVE, SW_SHOWNA or SW_RESTORE.
    if (access (szExecutable, 0) != 0)
    
    {
      strcpy (g_szDebug, "Cannot find ");
      strcat (g_szDebug, szExecutable);
      MsgBox (g_szDebug, MB_OK | MB_ICONINFORMATION);
      return;
    }
  
  else
    
    {
      
//         MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
	WinExec (szCmdLine, 1);
    }
  
//   }
}


//############################################################# EOF
  
