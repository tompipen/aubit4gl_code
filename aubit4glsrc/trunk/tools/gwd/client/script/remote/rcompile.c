/********************************************************************
                         Compile
********************************************************************/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <io.h>
#include <editor/app.h>
#include <editor/dlg.h>
#include <editor/doc.h>
#include <editor/macros.h>
#include <time.h>               // for GWD open patch



#define WM_COMMAND      0x0111 // for _GWD_CloseDoccument

#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80
#define MAX_FILE_NAME      80

// global variables
char g_szSysName[MAX_CMDLEN];
char g_szMakeCmd[MAX_CMDLEN];
char g_szServerInitDir[MAX_INIT_DIR];
char g_szServerInitDirNoSys[MAX_INIT_DIR];
char g_szClientInitDir[MAX_INIT_DIR];
char TMPg_szClientInitDir[MAX_INIT_DIR];
char g_szServerName[MAX_SERVER_NAME];
char g_szUserName[MAX_USER_NAME];
char g_szPassword[MAX_PASSWORD];
char g_szFileLocation[MAX_FILE_LOCATION];
char g_szFileName[MAX_FILE_NAME];
char g_szDebug[MAX_FILE_LOCATION];
char szFileExt[16];
char g_szTransport[16];
int  g_n4glVer;
char g_pszOutputFile[FILENAME_MAX];
char *psz;
char g_szSite[MAX_FILE_NAME];
char g_szGWDdir[FILENAME_MAX];

// function prototypes
void ScriptMain(HDOC);
void Compile(HDOC);
void CompileDOS(HDOC);
void CompileWin(HDOC);
void RemoveCompilerErrorLines(HDOC hDoc);
void UnixPathToDosPath(char *);
void DosPathToUnixPath(char *);
// void BaseName(char *);
void BaseName(char** ppsz);
void ChkErr(HDOC);
BOOL _Gte_CloseDocument(HDOC);

//##################################################################
int main(int argc, char *argv[])
//##################################################################
{
   HDOC hDoc;

   hDoc = Gte_GetActiveDocument();
   if(hDoc == NULL) {
      MsgBox("Cannot get handle of active document!", MB_OK);
      return 1;
   }

   // check file extension
   {
      Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));
      // if document does not have file ext, empty string will be returned
      if(szFileExt[0] != 0)
      {
         if(stricmp(szFileExt, "4gl") == 0 || stricmp(szFileExt, "per") == 0)//  ||
         {
             // call main script function
             ScriptMain(hDoc);
         }
         else
         {
              MsgBox("Error: To compile, activate doccument window of 4GL or PER file", MB_OK);
              return 1;
         }
      }
   }

   // warning document may be closed in the Compile function
   return 0;
}

//##################################################################
void ScriptMain(HDOC hDoc)
//##################################################################
{
   // Check for compiler error lines
   RemoveCompilerErrorLines(hDoc);

   // Save file if is modified
   if(Gte_IsModified(hDoc))
      GM_SaveFile(hDoc);
   if(Gte_IsModified(hDoc))
   {
      MsgBox("Error: Cannot save file", MB_OK);
      return;
   }

   // read configuration from ini file
   GetPrivateProfileString("Remote", "MakeCmd", "",     g_szMakeCmd, sizeof(g_szMakeCmd), "remote.ini");
   GetPrivateProfileString("Remote", "ServerInitDir", "", g_szServerInitDir, sizeof(g_szServerInitDir), "remote.ini");
   GetPrivateProfileString("Remote", "ClientInitDir", "", g_szClientInitDir, sizeof(g_szClientInitDir), "remote.ini");
   GetPrivateProfileString("Remote", "ServerName", "", g_szServerName, sizeof(g_szServerName), "remote.ini");
   GetPrivateProfileString("Remote", "UserName",   "", g_szUserName, sizeof(g_szUserName), "remote.ini");
   GetPrivateProfileString("Remote", "Password",   "", g_szPassword, sizeof(g_szPassword), "remote.ini");
   GetPrivateProfileString("Remote", "Transport",   "", g_szTransport, sizeof(g_szTransport), "remote.ini");
   // Get site specific location of bat files
   GetPrivateProfileString("Remote", "Site", "", g_szSite, sizeof(g_szSite), "remote.ini");
   Gte_GetTextEditorDir(g_szGWDdir, 80);


   g_n4glVer = GetPrivateProfileInt("Remote","4GLVersion",0,"remote.ini");

   // check configuration parameters and ask for them is necessary
    if(g_n4glVer == 0)
        {
            MsgBox("4GLVersion in remote.ini is not defined", MB_OK);
            return;
		}

   if(strlen(g_szMakeCmd) == 0) {
      if(Gte_GetStringDlg("Make command", "&Make command:",
         g_szMakeCmd, sizeof(g_szMakeCmd)) == FALSE)
      {
         return;
      }
   }
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
   }
   if(strlen(g_szClientInitDir) == 0) {
      MsgBox("Select client initial directory", MB_OK);
      if(Gte_BrowseForDirDlg(g_szClientInitDir, sizeof(g_szClientInitDir), FALSE) == FALSE)
         return;
      if(strlen(g_szClientInitDir) == 0) {
         MsgBox("Invalid client initial dir", MB_OK);
         return;
      }
   }
   if(strlen(g_szServerName) == 0) {
      if(Gte_GetStringDlg("Server Name", "&Server name:", g_szServerName, sizeof(g_szServerName)) == FALSE)
         return;
      if(strlen(g_szServerName) == 0) {
         MsgBox("Invalid server name", MB_OK);
         return;
      }
   }
   if(strlen(g_szUserName) == 0) {
      if(Gte_GetStringDlg("User Name", "&User name:", g_szUserName, sizeof(g_szUserName)) == FALSE)
         return;
      if(strlen(g_szUserName) == 0) {
         MsgBox("Invalid user name", MB_OK);
         return;
      }
   }
   if(strlen(g_szPassword) == 0) {
      if(Gte_GetStringDlg("Password", "&Password:", g_szPassword, sizeof(g_szPassword)) == FALSE)
         return;
      if(strlen(g_szPassword) == 0) {
         MsgBox("Invalid password", MB_OK);
         return;
      }
   }

	  switch(g_n4glVer)
      {
         case 1: //local 4GL for DOS
      			    CompileDOS(hDoc);
                    return;

		 case 2: //local 4GL for Windows
                    CompileWin(hDoc);
    	            return;

		 case 3: //remote Informix 4GL
                    break;

		 case 4: //remote 4Js/Informix D4GL GUI
                    break;

		 case 5: //remote 4Js/Informix D4GL CUI
		            break;

		 case 6: //local 4Js/Informix D4GL GUI
                    CompileWin(hDoc);
					return;

       }

   if(stricmp(g_szTransport, "RCP") == 0)
   // from the filename and takeout.ini determine default filename and location for RCP transport
   {
      char szDocFileName[FILENAME_MAX];
      char szTakeOutFile[FILENAME_MAX];

      szDocFileName[0] = 0;
      Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));
      UnixPathToDosPath(szDocFileName);

      GetPrivateProfileString("Remote", "LastTakeOutLocation", "", g_szFileLocation, sizeof(g_szFileLocation), "remote.ini");
      if(szDocFileName)
         GetPrivateProfileString("TakeOutLocation", szDocFileName, g_szFileLocation, g_szFileLocation, sizeof(g_szFileLocation), "takeout.ini");
      GetPrivateProfileString("Remote", "LastTakeOutFileName", "", g_szFileName, sizeof(g_szFileName), "remote.ini");
      if(szDocFileName)
         GetPrivateProfileString("TakeOutFileName", szDocFileName, g_szFileName, g_szFileName, sizeof(g_szFileName), "takeout.ini");

      // Check if this is the right file
      strcpy(szTakeOutFile, g_szClientInitDir);
      strcat(szTakeOutFile, "\\");              //af added
      strcat(szTakeOutFile, g_szFileLocation);
      strcat(szTakeOutFile, g_szFileName);
      UnixPathToDosPath(szTakeOutFile);

       // add "/" at the end of directory strings if necessary
       if(g_szServerInitDir[0] != 0 && g_szServerInitDir[strlen(g_szServerInitDir)-1] != '\\' &&
          g_szServerInitDir[strlen(g_szServerInitDir)-1] != '/')
       {
          strcat(g_szServerInitDir, "/");
          DosPathToUnixPath(g_szServerInitDir);
       }
       if(g_szClientInitDir[0] != 0 && g_szClientInitDir[strlen(g_szClientInitDir)-1] != '\\' &&
          g_szClientInitDir[strlen(g_szClientInitDir)-1] != '/')
       {
          strcat(g_szClientInitDir, "/");
          UnixPathToDosPath(g_szClientInitDir);
       }
       if(g_szFileLocation[0] != 0 && g_szFileLocation[strlen(g_szFileLocation)-1] != '\\' &&
          g_szFileLocation[strlen(g_szFileLocation)-1] != '/')
       {
          strcat(g_szFileLocation, "/");
       }

   }
   else
   {

       Gte_GetFileName(hDoc, g_szFileName, sizeof(g_szFileName));

	   {
       char** ppsz;
       char* psz;


		   ppsz = &psz;
    	   *ppsz = g_szFileName;
           BaseName(ppsz);
    	   strcpy(g_szFileName,*ppsz);
       }
       //BaseName(g_szFileName);

   }

   // Compile file
   Compile(hDoc);

   return;
}

/*-------------------------------------------------------------------
                         Compile

  Warning: This function may close hDoc document
-------------------------------------------------------------------*/

void Compile(HDOC hDoc)
{
   char szCmdLine[1024];
   char szCmdLine_param[1024];
   char szSite[MAX_FILE_NAME];
   char pszActionDisplay[100];
   char szDocFileName[FILENAME_MAX];

   Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));


   // determine progSYS name
   if(stricmp(g_szTransport, "RCP") == 0)
   {
        strcpy(g_szServerInitDirNoSys,"/home/users/"); // this shoud be in .ini file

        //if the file is under /home/users/, it does not belong to any program system
        if(strcmpi(g_szServerInitDir, g_szServerInitDirNoSys))
        {
          // read previous system name form ini file
          GetPrivateProfileString("Remote", "LastSysRun", "", g_szSysName, sizeof(g_szSysName), "remote.ini");

          // ask for system name: needed to set envirnment for compiler, like DBPATH
          // depending on program system
          if(Gte_GetStringDlg("System name", "&System name:", g_szSysName,
             sizeof(g_szSysName)) == FALSE)
          {
             // user click Cancel
             return;
          }

          // write last system name to ini file
          WritePrivateProfileString("Remote", "LastSysRun", g_szSysName, "remote.ini");

        }
         else
        {
          // this shoud be the name of the UNIX script that sets up the environment
          // for program system that this file came from, like
          // . maxdev4js /apps/max_4.00 or "40" alias for CSI for example
          strcpy(g_szSysName, "dummy");
        }
   }
   else // samba transport
   {
        strcpy(g_szSysName, "dummy");
   }

   if(stricmp(g_szTransport, "samba") == 0)
   {
	  strcpy (TMPg_szClientInitDir, g_szTransport);

      //------------------------------------ path to the source

	  //strcpy (g_szServerInitDir,"/apps/max_4.00/repw/");
      strcpy (g_szServerInitDir, szDocFileName);
	  psz = strrchr(g_szServerInitDir, '\\');
      if(psz == NULL)
         psz = g_szServerInitDir;
      if(psz == NULL) {
         MsgBox("ERROR: Cannnot find backslash", MB_OK);
         return;
      }
	  //strcpy(psz+1, ""); // this leaves a slash at the end
  	  strcpy(psz, ""); // this does NOT leave a slash at the end


      strcpy (g_szFileLocation, g_szServerInitDir);
   }

   //------------------------------- Change current dir to GWD editor dir

   chdir(g_szGWDdir);

   //------------------------------- Batch file name

   strcpy(szCmdLine, "\""); // this is a first write to szCmdLine
   strcat(szCmdLine, g_szGWDdir);
   strcat(szCmdLine, "bat");
   strcat(szCmdLine, "\\");
   strcat(szCmdLine, g_szSite);
   strcat(szCmdLine, "\\rcompile.bat");
   strcat(szCmdLine, "\" ");

   //----------------------- System name or dummy

       strcpy(szCmdLine_param, "");//this is a first write to szCmdLine_param

	   if(strchr(g_szSysName, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, g_szSysName);
       if(strchr(g_szSysName, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");

   //------------------------ UNIX initial path, or full path to file if samba transport

       if(strchr(g_szServerInitDir, ' '))
          strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, g_szServerInitDir);
       if(strchr(g_szServerInitDir, ' '))
          strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");

    //------------------------ Local initial Path or "samba"


       if(stricmp(g_szTransport, "RCP") == 0)
       {
    		// Remove Disk label an semiclolon from clinets path
            // because of problems with Microsoft rcp.exe
            strcpy(TMPg_szClientInitDir, g_szClientInitDir);
            psz = TMPg_szClientInitDir;
            if(*psz == 'C'||*psz == 'c') {
                     if(*(psz+1) == ':') {
                        psz = psz + 2;
                        strcpy(TMPg_szClientInitDir,psz);
                    }
            }
        }

       if(strchr(TMPg_szClientInitDir, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, TMPg_szClientInitDir);
       if(strchr(TMPg_szClientInitDir, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");

       //-------------------------- server name

       if(strchr(g_szServerName, '"'))
          strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, g_szServerName);
       if(strchr(g_szServerName, '"'))
          strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");

       //--------------------------- user name

       if(strchr(g_szUserName, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, g_szUserName);
       if(strchr(g_szUserName, ' '))
         strcat(szCmdLine_param, "\"");

       //---------------------------- password

       if(strchr(g_szPassword, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");
       strcat(szCmdLine_param, g_szPassword);
       if(strchr(g_szPassword, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");

       // UNIX FileLocation relative to UNIX initial path
	   // or
	   // for samba, UNIX path to the source file

	   {
           char szUnixFileLoc[MAX_FILE_LOCATION];

           strcpy(szUnixFileLoc, g_szFileLocation);
           // this can contain a drive letter, or a network drive URL,
           // and we need to remove that:
            psz = szUnixFileLoc;
            if(*psz == 'C'||*psz == 'c') {
                     if(*(psz+1) == ':') {
                        psz = psz + 2;
                        strcpy(szUnixFileLoc,psz);
                    }
            }

            psz = szUnixFileLoc;
            if(*psz == '\\')
			{
                    if(*(psz+1) == '\\')
					{
                        psz = psz + 2;
                        // we have removed leading two backslash-es,
						// now, remove everithing to first next backslash,
                        // that is actualy computer name:

                        while(*psz)
                        {
                          if(*psz == '\\')
                            {
							 //*psz = '\\';
                             break;
                            }
						  psz++;

                        }

                        strcpy(szUnixFileLoc,psz);
                    }
            }

           DosPathToUnixPath(szUnixFileLoc);

           if(strchr(szUnixFileLoc, ' '))
             strcat(szCmdLine_param, "\"");
           strcat(szCmdLine_param, szUnixFileLoc);
           if(strchr(szUnixFileLoc, ' '))
             strcat(szCmdLine_param, "\"");
           strcat(szCmdLine_param, " ");
       }

       // NT FileLocation relative to initial client path or dummy for samba

	   {
           char szWinFileLoc[MAX_FILE_LOCATION];

           if(stricmp(g_szTransport, "samba") == 0)
    	   {
               strcpy(szWinFileLoc, "x"); // just a placeholder
    	   }
		   else
           {
               strcpy(szWinFileLoc, g_szFileLocation);
		   }

           UnixPathToDosPath(szWinFileLoc);

           if(strchr(szWinFileLoc, ' '))
             strcat(szCmdLine_param, "\"");
           strcat(szCmdLine_param, szWinFileLoc);
           if(strchr(szWinFileLoc, ' '))
             strcat(szCmdLine_param, "\"");
           strcat(szCmdLine_param, " ");
       }

       //---------------------------- filename.ext



       if(strchr(g_szFileName, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, g_szFileName);
       if(strchr(g_szFileName, ' '))
         strcat(szCmdLine_param, "\"");


       //---------------------------- message

     strcpy (pszActionDisplay,"Compiling ");
     strcat (pszActionDisplay, szDocFileName);
     strcat (pszActionDisplay,", please wait...");


        //--------------------------- output file
      strcpy (g_pszOutputFile, szDocFileName);

	  psz = strrchr(g_pszOutputFile, '\\');
      if(psz == NULL)
         psz = g_pszOutputFile;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }
	  strcpy(psz+1, "cmp");

// the call looks like this:
// C:\Program Files\GWD\bat\CSI>rcompile dummy /apps/max_4.00/repw/ samba chaix afalout aaa bla bla csi_p.4gl


    strcat (szCmdLine,szCmdLine_param);

//*
   if (MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION) == IDNO)
     {
         return;
     };
//*/
   WaitCursor();

//   system(szCmdLine_param);
   Gte_ExecuteTool(szCmdLine, g_pszOutputFile, pszActionDisplay, szCmdLine_param);

   // Check for errors
   ChkErr(hDoc);

   RestoreCursor();

}

/*-------------------------------------------------------------------
                      RemoveCompilerErrorLines
-------------------------------------------------------------------*/

void RemoveCompilerErrorLines(HDOC hDoc)
{

    // remember cursor position (this is not necessary, but it is user friendly)
    GM_SaveCursorPos(hDoc);

    WaitCursor();

    // to speed up macro disable screen update
    Gte_LockUpdate(hDoc);


    if(stricmp(szFileExt, "4gl") == 0)
     {
       // first check if we have compiler error lines
       // compiler error lines in 4gl begins with | character
       if(Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
       {
             long lStartLine = 1;
             while(TRUE)
             {
                if(Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) != 0)
                {
                   GM_SaveFile(hDoc);
                   return;
                }
                GM_DeleteLine(hDoc);
                Gte_GetCursorPos(hDoc, NULL, &lStartLine);

				// Display progress on status bar after every 10 lines
                {
                  char szMsg[80];

                  sprintf(szMsg, "Removeing compiler error messages - Press Ctrl-Break to cancel: %0d%% completed", (int)(lStartLine * 100 / Gte_GetNumberOfLines(hDoc)));
                  Gte_StatusBarMsg(szMsg);
                }

             }
       }
     }

    if(stricmp(szFileExt, "per") == 0)
     {
// MsgBox("per", MB_OK);
	  if ((g_n4glVer == 4) || (g_n4glVer == 5))       //remote 4Js/Informix D4GL GUI  //remote 4Js/Informix D4GL CHUI
      {
//  MsgBox("dos", MB_OK);
           // first check if we have compiler error lines
           // compiler error lines in per(DOS) begins with # character
    	   if(Gte_Find(hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
           {
                 long lStartLine = 1;
                 while(TRUE)
                 {
                    if(Gte_Find(hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE) != 0)
                    {
                       GM_SaveFile(hDoc);
                       return;
                    }
                    GM_DeleteLine(hDoc);
                    Gte_GetCursorPos(hDoc, NULL, &lStartLine);
                 }
           }
       }    // if compiler DOS/D4gl

	  else
	  {
// MsgBox("D4gl", MB_OK);
           // first check if we have compiler error lines
           // compiler error lines in per(D4GL) begins with | character
           if(Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
           {
                 long lStartLine = 1;
                 while(TRUE)
                 {
                    if(Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) != 0)
                    {
                       GM_SaveFile(hDoc);
                       return;
                    }
                    GM_DeleteLine(hDoc);
                    Gte_GetCursorPos(hDoc, NULL, &lStartLine);
                 }
           }

	  }
	 }      // if PER

	  // Unlock screen update
      Gte_UnlockUpdate(hDoc);

      RestoreCursor();

      // restore cursor position from stack
      GM_RestoreCursorPos(hDoc);
      // scroll window if necessary to make cursor visible
      Gte_FixWindowPos(hDoc);


}

/*-------------------------------------------------------------------
                    UnixPathToDosPath
-------------------------------------------------------------------*/

void UnixPathToDosPath(char *psz)
{
   while(*psz)
   {
      if(*psz == '/')
         *psz = '\\';
      psz++;
   }
}

/*-------------------------------------------------------------------
                    DosPathToUnixPath
-------------------------------------------------------------------*/

void DosPathToUnixPath(char *psz)
{
   while(*psz)
   {
      if(*psz == '\\')
         *psz = '/';
      psz++;
   }
}

/*-------------------------------------------------------------------
                    BaseName
-------------------------------------------------------------------*/

void BaseName(char** ppsz)
{
// Yes, it is a mess, but this works
   char* pszslash;

   for (pszslash = *ppsz; *pszslash; pszslash++)
      if (*pszslash == '\\')
      {
    	 *ppsz = pszslash + 1;
      }
}

/* this does nothing ?????!!!! Vedran?
void BaseName(char* psz)
{
   char* psztemp;
   char* pszslash;

   psztemp = psz;
   for (pszslash = psztemp; *pszslash; pszslash++)
      if (*pszslash == '/')
    	 psztemp = pszslash + 1;
   strcpy(psz, psztemp);
}
*/

//#######################################################################
void CompileDOS(HDOC hDoc)
//#######################################################################
{
   char szCmdLine[1024];
   char szTargetDir[FILENAME_MAX];
   char szDocFileName[FILENAME_MAX];
   char szDocFileNameNoExt[FILENAME_MAX];
   char szTargetObject[FILENAME_MAX];
   char szProgram[FILENAME_MAX];
   char szCompler[30];

   MsgBox("WARNING: Close all apps that access database engine !\n DOS is a single user system!", MB_OK);

   WaitCursor();

   if(stricmp(szFileExt, "4gl") == 0)
         {
               strcpy (szCompler,"fglpc -p ");

		 }

   if(stricmp(szFileExt, "per") == 0)
         {
               strcpy (szCompler,"form4gl -p ");

		 }


    szDocFileName[0] = 0;
	Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));

	strcpy (szTargetObject, szDocFileName);
    strcpy (szProgram, szDocFileName);
    strcpy (szTargetDir, szDocFileName);
    strcpy (szDocFileNameNoExt, szDocFileName);

	  psz = strrchr(szTargetDir, '\\');
      if(psz == NULL)
         psz = szTargetDir;
      if(psz == NULL) {
         MsgBox("ERROR: Cannnot find backslash", MB_OK);
         return;
      }
	 strcpy(psz+1, "");

	  psz = strrchr(szDocFileNameNoExt, '\\');
      if(psz == NULL)
         psz = szDocFileNameNoExt;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }
	  strcpy(psz, "");

	  psz = strrchr(szTargetObject, '\\');
      if(psz == NULL)
         psz = szTargetObject;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }
	  strcpy(psz+1, "4go");
      strcpy(szProgram + (psz - szTargetObject) + 1, "4gi");


	strcpy (szCmdLine, szCompler);
    if(stricmp(szFileExt, "4gl") == 0)
        {
    	strcat (szCmdLine, szTargetDir);
        strcat (szCmdLine, " ");
    	strcat (szCmdLine, szDocFileName);
		}
        else
        {
    	strcat (szCmdLine, szDocFileNameNoExt);
        }


//   MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION); return;

    system(szCmdLine);

   // Check for errors
   ChkErr(hDoc);


   if(stricmp(szFileExt, "4gl") == 0)
   {
      // rename object file to executable file
      if(access(szTargetObject, 0) == 0)
      {
         remove(szProgram);
		 rename(szTargetObject,szProgram);
      }
   }

   RestoreCursor();

}

//#######################################################################
void ChkErr(HDOC hDoc)
//#######################################################################
{
      char szDocFileName[FILENAME_MAX];
      char szBackupFile[FILENAME_MAX];
      char szErrorFile[FILENAME_MAX];
      char szTargetFile[FILENAME_MAX];
      char *psz;

      szDocFileName[0] = 0;
      Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));
      UnixPathToDosPath(szDocFileName);

	  strcpy(szBackupFile, szDocFileName);
	  strcpy(szErrorFile, szDocFileName);
      strcpy(szTargetFile, szDocFileName);

	  psz = strrchr(szErrorFile, '\\');
      if(psz == NULL)
         psz = szErrorFile;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }
      strcpy(psz+1, "err");
      strcpy(szBackupFile + (psz - szErrorFile) + 1, "bak");
//      Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));


	  switch(g_n4glVer)
      {
         case 1: //local 4GL for DOS
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "4go");
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "frm");
             }

					break;
		 case 2: //local 4GL for Windows
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "4go");
					break;
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "frm");
             }


		 case 3: //remote Informix 4GL
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "4go");
                    break;
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "frm");
             }


		 case 4: //remote 4Js/Informix D4GL GUI
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42m");
            		break;
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42f");
             }


		 case 5: //remote 4Js/Informix D4GL CHUI
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42m");
					break;
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42f");
             }

		 case 6: //local 4Js/Informix D4GL CUI
            if(stricmp(szFileExt, "4gl") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42m");
					break;
             }
            if(stricmp(szFileExt, "per") == 0)
             {
					strcpy(szTargetFile + (psz - szErrorFile) + 1, "42f");
             }
       }

	  if(access(szErrorFile, 0) != 0)
      {

    	  if(access(szTargetFile, 0) != 0)
          {
             if (MsgBox("Object not generated! Open compile log file?", MB_YESNO | MB_ICONQUESTION) == IDNO)
             {
                 return;
             };

             hDoc = Gte_OpenDocument(g_pszOutputFile);

             return;
          }
          else
          {
			 MsgBox("Compilation successful!", MB_OK | MB_ICONINFORMATION);
             return;
		  }
      }

//MsgBox("Before close", MB_OK | MB_ICONINFORMATION);

	  // close this file
      // Gte_CloseDocument(hDoc);
	  _Gte_CloseDocument(hDoc);

/*
Da li je prozor stvarno zatvoren ili ne i nije tako tesko provijeriti. Naime
nakon Gte_Close(hDoc), bilo koji poziv Gte_ funkcije sa hDoc parametrom bi
trebao srusiti editor. Do rusenja mozda nece odmah doci ali nakon:
*/

/*
Gte_OpenDocument("c:\\informix\\agent_ol_armada.log");			//("neki veliki file");
Gte_CloseDocument(hDoc);    // <- ovo mora izazvat rusenje programa
MsgBox("Shit, it did not crash!", MB_OK | MB_ICONINFORMATION);

        return;

*/
	  // remove filename.bak
      remove(szBackupFile);


      // rename this file to bak
      rename(szDocFileName, szBackupFile);


	  // rename err file to this file
      rename(szErrorFile, szDocFileName);
// umjesto rename(szErroeFile, szDocFileName):
//**CallDLLFunc(NULL, "kernel32.dll", "DeleteFileA", "p", szDocFileName);
//MsgBox("After delete .4gl", MB_OK | MB_ICONINFORMATION);

//orig CallDLLFunc(NULL, "kernel32.dll", "MoveFileA", "pp", szDocFileName,szErrorFile);
//**CallDLLFunc(NULL, "kernel32.dll", "MoveFileA", "pp",szErrorFile, szDocFileName);
//MsgBox("After move err to 4gl", MB_OK | MB_ICONINFORMATION);


// -------------   PATCH --------------

/*
Kao da se rename izvrsava u drugom thread-u? Mozda do cache-a, ili neceg slicnog.
Probao sam na FAT-u i NTFS-u (WinNT) i kod mene je uvijek radilo, medjutim ovaj
kod bi mogao zaobici gresku:

Ovim se skript vrti u petlji dok datoteka szDocFile ne dobije read premmission ili
dok ne prodju 4 sekunde.
*/

/*
   {
      time_t lStartTime = time(NULL);
      while(access(szDocFileName, 4) != 0 && time(NULL) - lStartTime < 4)
      {
      }
   }

*/

/*
   {
      time_t lStartTime = time(NULL);
      while(access(szDocFileName, 4) != 0 && time(NULL) - lStartTime < 4)
      {
         CallDLLFunc(NULL, "kernel32.dll", "Sleep", "4", 250);
      }
   }

*/
MsgBox(szDocFileName, MB_OK | MB_ICONINFORMATION);


// -------------- end patch ------------------------


	  // open it
      hDoc = Gte_OpenDocument(szDocFileName);
//MsgBox(szDocFileName, MB_OK | MB_ICONINFORMATION);

// return;


	  // position to the first error line
        if(stricmp(szFileExt, "4gl") == 0)
         {
        	  if ((g_n4glVer == 4) || (g_n4glVer == 5) || (g_n4glVer == 6))       //4Js/Informix D4GL
               {
		           Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE);
			   }
                   else
               {
				   // 4, 4 in Gte_find is to skip over first 3 lines
				   // inserted only by Windows 4GL compiler
        		   // position to the first error line
		           Gte_Find(hDoc, "^\\|", 4, 4, FALSE, FALSE, TRUE, TRUE);
               }
         }

		if(stricmp(szFileExt, "per") == 0)
         {
        	  if ((g_n4glVer == 4) || (g_n4glVer == 5) || (g_n4glVer == 6))       //4Js/Informix D4GL
              {
                   Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE);
			  }
			  else
              {
        		  Gte_Find(hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE);
              }
         }

}


//#######################################################################
void CompileWin(HDOC hDoc)
//#######################################################################
{
   char szCmdLine[1024];
   char szLogEnvCmdLine[1024];
   char szTargetDir[FILENAME_MAX];
   char szDocFileName[FILENAME_MAX];
   char szDocFileNameNoExt[FILENAME_MAX];
   char szTargetObject[FILENAME_MAX];
   char szProgram[FILENAME_MAX];
   char pszActionDisplay[FILENAME_MAX];
   char pszOutputFile[FILENAME_MAX];
   char szBaseName[FILENAME_MAX];
   char szCompler[30];

   WaitCursor();

   if(stricmp(szFileExt, "4gl") == 0)
         {

		   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	        {
               // -V : Display version informations
			   // -h : Display this help
			   // -S : Dump SQL
			   // -R : Ignore number of returned values
			   // -C : C-code generation (default is P-code)
			   // -g : Implement globals in this file (internal use only)
  			   // hmmm? strcpy (szCompler,"fglcomp ");
/*
Usage: fgl2p source.4gl ...

        -o            Next argument is program name
        -V            Display version of fgl2p only
        -E            Display configuration
        -S            Dump SQL
        -W optwarm    Warning messages. optwarm can be unused, return or all
        -M            Error output on terminal
        -n opterror
                      1 Continue when an error occurs
                      2 Continue when an error occurs but display all .err
                      3 Stop a the first error and display the error (default)

                      Example: fgl2p -n2 -o file.42r file.4gl

        -t flageditor
                      1 If an error occurs the file .4gl and .err are displayed
                      2 If an error occurs only the file .err is displayed.
                      3 If an error occurs only the file .4gl is displayed.

                      Example: fgl2p -t2 -o file.42r file.4gl

***** BUT, FGL2P WILL CRASH IF YOU SPECIFY FULL PATH !!! ********


*/

			   strcpy (szCompler,"fgl2p ");
			}
            else
            {
 			   //strcpy (szExt, "4gl"); strcpy(szFindErr,"^\\|");
			   strcpy (szCompler,"ix w4glcomp -n -pcode ");       //must use ix if not using WinExec
			   //strcpy (szDescr," source ");
            }
		 }

   if(stricmp(szFileExt, "per") == 0)
        {
		   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	         {

				// Usage : fglform [options] filename
				//    -V : Display version information.
				//    -h : Display this help.
				//    -s : Silent mode (no messages are displayed).

				 strcpy (szCompler,"fglform ");
             }
             else
			 {
    			 //strcpy (szExt, "per"); strcpy(szFindErr,"^#");
				 strcpy (szCompler,"ix wform4gl -n ");              //ix
				 //strcpy (szDescr," form ");
             }
		 }


    szDocFileName[0] = 0;
	Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName)); //returns with full path

    // We should check filename for length of 8.3 for 4gl for Windows,
    // How to do that?

	strcpy (szTargetObject, szDocFileName);
    strcpy (szProgram, szDocFileName);
    strcpy (szTargetDir, szDocFileName);
    strcpy (szDocFileNameNoExt, szDocFileName);
    strcpy (pszOutputFile, szDocFileName);

	  psz = strrchr(szTargetDir, '\\');
      if(psz == NULL)
         psz = szTargetDir;
      if(psz == NULL) {
         MsgBox("ERROR: Cannnot find backslash", MB_OK);
         return;
      }
	 strcpy(psz+1, "");

	  psz = strrchr(szDocFileNameNoExt, '\\');
      if(psz == NULL)
         psz = szDocFileNameNoExt;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }
	  strcpy(psz, "");

	  psz = strrchr(szTargetObject, '\\');
      if(psz == NULL)
         psz = szTargetObject;
      psz = strrchr(psz, '.');
      if(psz == NULL) {
         MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
         return;
      }

     if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	  {
		  strcpy(psz+1, "42m");
    	  strcpy(szProgram + (psz - szTargetObject) + 1, "42r");

	  }
      else
      {
		  strcpy(psz+1, "4go");
    	  strcpy(szProgram + (psz - szTargetObject) + 1, "4gi");
      }

	  strcpy(pszOutputFile + (psz - szTargetObject) + 1, "cmp");

//   strcpy (pszOutputFile, szProject);
//   strcat (pszOutputFile, ".bld ");

	strcpy (szCmdLine, szCompler);

	if(stricmp(szFileExt, "4gl") == 0)
        {
    	//strcat (szCmdLine, szTargetDir);
        //strcat (szCmdLine, " ");

	        if(strcmpi(szCompler,"fgl2p "))
            // FGL2P WILL CRASH IF YOU SPECIFY FULL PATH !!!
	        {
				strcat (szCmdLine, szDocFileName);
	        }
            else
            {
			   {
		       char** ppsz;
		       char* psz;

				   ppsz = &psz;
		    	   *ppsz = szDocFileName;
		           BaseName(ppsz);
		    	   strcpy(szBaseName,*ppsz);
		       }
		       //BaseName(g_szFileName);

				strcat (szCmdLine, szBaseName);
            }

		}
        else
        {

	     if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
		  {
			   // The form 'C:\PRG\CSI\wax_3.71.per' cannot be opened.
			   // for 4js form compiler, long paths cannot be used!!!

			  {
               char** ppsz;
			   char* psz;


		    	   ppsz = &psz;
		    	   *ppsz = szDocFileNameNoExt;
		           BaseName(ppsz);
		    	   strcpy(szDocFileNameNoExt,*ppsz);
		       }

           }

			strcat (szCmdLine, szDocFileNameNoExt);

        }


//   MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
	// return;

//    system(szCmdLine);



				   strcpy (pszActionDisplay,"Compiling ");
                   /*

				   strcat (pszActionDisplay,szDescr);
                   strcat (pszActionDisplay,"file ");
                   */
				   strcat (pszActionDisplay, szDocFileName);

                   strcat (pszActionDisplay,", please wait...");

                  //  WinExec(szCmdLine, 1); // Does not wait for app to finnish...no can do!
                  // Vedran, is there something like WinExecWait????
				  // (otherwise works, without "ix" )


                  //MsgBox(szTargetDir, MB_OK | MB_ICONINFORMATION);
                  chdir(szTargetDir);

                  //MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
                  //MsgBox(pszOutputFile, MB_OK | MB_ICONINFORMATION);
                  Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine); //" Args...");
                  //	c:\informix\bin\errchkr c:\prg\job_post\job_post.4gl


/*
	Log the current envirinment to .cmp file for diag
	strcpy (szLogEnvCmdLine, "set >> ");
    strcat (szLogEnvCmdLine, pszOutputFile);
	system(szLogEnvCmdLine);
*/

                 //MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);

   // Check for errors
   ChkErr(hDoc);

/*
   if(stricmp(szFileExt, "4gl") == 0)
   {
      // rename object file to executable file
      if(access(szTargetObject, 0) == 0)
      {
         remove(szProgram);
		 rename(szTargetObject,szProgram);
      }
   }
*/
   RestoreCursor();

}


BOOL _Gte_CloseDocument(HDOC hDoc)
{


   Gte_SetActiveDocument(hDoc);
   if(Gte_GetActiveDocument() == hDoc)
   {
#ifdef __32BIT__
      CallDLLFunc(NULL, "user32.dll", "PostMessageA", "iiil",
	  	GetMainWndHandle(),WM_COMMAND, 110, 0);
#else
      CallDLLFunc(NULL, "user.exe", "PostMessage", "iiil",
	  	GetMainWndHandle(), WM_COMMAND,110, 0);
#endif
      if(Gte_GetActiveDocument() == hDoc)
         return FALSE;
      return TRUE;
   }
   return FALSE;


}


 // ============================================================ EOF
