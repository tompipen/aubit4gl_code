/********************************************************************
                         rMake
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

#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80
#define MAX_FILE_NAME      80
#define MAX_SOURCE_FILES   20   // num of sourcefiles to be compiled and checked for errors
#define MAX_SOURCE_TYPES   3    // num of sourcefile types to be compiled checked for errors

// global variables
char g_szSysName[MAX_CMDLEN];
char g_szArea[MAX_CMDLEN];
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
char g_szMessage[100];
char *psz;
int  g_n4glVer;
char g_szDebug[MAX_FILE_LOCATION];
char szFileExt[16];
char g_szTransport[16];
char g_szSite[MAX_FILE_NAME];
char g_pszOutputFile[FILENAME_MAX];
char g_szGWDdir[FILENAME_MAX];

// function prototypes
void ScriptMain(HDOC);
void Compile(HDOC);
void RemoveCompilerErrorLines(HDOC hDoc);
void UnixPathToDosPath(char *);
void DosPathToUnixPath(char *);
void Make4glWin(HDOC);
void BaseName(char** ppsz);
HDOC GetHandleForFileName(const char *pszFileName);


//#######################################################
int main(int argc, char *argv[])
//#######################################################
{
   HDOC hDoc;


   hDoc = Gte_GetActiveDocument();
   if(hDoc == NULL)
   {
      MsgBox("Cannot get handle of active document!", MB_OK);
      return 1;
   }


   // check file extension
   // This is important because if we do not have a handle for correct
   // document (the one that is the most probable to cause compile error)
   // we will not be able to close it before opening .err file, so we will
   // have the "Another app have modified ... reload?" question.
   // This is not realy what I want, but GWD cannot make a handle from
   // filename, or close a document based on filename.

   {
      Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));
      // if document does not have file ext, empty string will be returned
      if(szFileExt[0] != 0)
      {
         if(stricmp(szFileExt, "4gl") == 0 || stricmp(szFileExt, "per") == 0  ||
            stricmp(szFileExt, "42r") == 0 || stricmp(szFileExt, "m") == 0    ||
            stricmp(szFileExt, "toc") == 0 || stricmp(szFileExt, "5gl") == 0)
         {
                // ok
         }
         else
         {
            strcpy (g_szMessage, "Error: Donno how to Make this mess: ");
            strcat (g_szMessage, szFileExt);
            strcat (g_szMessage," Make it yourself !");
            MsgBox(g_szMessage, MB_OK);
            return;
         }
      }
   }


   // call main script function
   ScriptMain(hDoc);

   // warning: document may be closed in the Compile function
   return 0;
}


//############################################################
void ScriptMain(HDOC hDoc)
//############################################################
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

   // get 4gl type
   g_n4glVer = GetPrivateProfileInt("Remote","4GLVersion",0,"remote.ini");

    if(g_n4glVer == 0)
        {
            MsgBox("4GLVersion in remote.ini is not defined", MB_OK);
            return;
		};


	  switch(g_n4glVer)
      {
         case 1:    // local 4GL for DOS
                    MsgBox("Make for DOS not implemented", MB_OK);
					return;

		 case 2:    // local Informix 4gl for Windows
		            Make4glWin(hDoc);
					return;

		 case 3:    // remote Informix 4GL
                    MsgBox("Make for remote Informix 4GL not implemented", MB_OK);
					return;

		 case 4:    // remote 4Js/Informix D4GL GUI
                    break;

		 case 5:    // remote 4Js/Informix D4GL CUI
                    break;

		 case 6: 	//local 4Js/Informix D4GL GUI
                    Make4glWin(hDoc);
					return;


       };

   // read configuration from ini file
   GetPrivateProfileString("Remote", "MakeCmd", "",     g_szMakeCmd, sizeof(g_szMakeCmd), "remote.ini");
   GetPrivateProfileString("Remote", "ClientInitDir", "", g_szClientInitDir, sizeof(g_szClientInitDir), "remote.ini");
   GetPrivateProfileString("Remote", "ServerName", "", g_szServerName, sizeof(g_szServerName), "remote.ini");
   GetPrivateProfileString("Remote", "UserName",   "", g_szUserName, sizeof(g_szUserName), "remote.ini");
   GetPrivateProfileString("Remote", "Password",   "", g_szPassword, sizeof(g_szPassword), "remote.ini");
   GetPrivateProfileString("Remote", "Transport",   "", g_szTransport, sizeof(g_szTransport), "remote.ini");
   // Get site specific location of bat files
   GetPrivateProfileString("Remote", "Site", "", g_szSite, sizeof(g_szSite), "remote.ini");
   Gte_GetTextEditorDir(g_szGWDdir, 80);

   // check configuration parameters and ask for them is necessary
   if(strlen(g_szMakeCmd) == 0) {
      if(Gte_GetStringDlg("Make command", "&Make command:",
         g_szMakeCmd, sizeof(g_szMakeCmd)) == FALSE)
      {
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


   if(stricmp(g_szTransport, "RCP") == 0)
   // from the filename and takeout.ini determine default filename and location
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

       GetPrivateProfileString("InitialPath", szDocFileName, g_szServerInitDir, g_szServerInitDir, sizeof(g_szServerInitDir), "takeout.ini");


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
       char** ppsz;
       char* psz;

       Gte_GetFileName(hDoc, g_szFileName, sizeof(g_szFileName));

	   {
    	   ppsz = &psz;
    	   *ppsz = g_szFileName;
           BaseName(ppsz);
    	   strcpy(g_szFileName,*ppsz);
       }
       //BaseName(g_szFileName);

       strcpy (g_szClientInitDir,g_szTransport);    // "samba"
       strcpy (g_szFileLocation,"x");               // dummy placeholder
   }


   // Compile file
   Compile(hDoc);

   return;
}


//  Warning: This function may close hDoc document
//######################################################
void Compile(HDOC hDoc)
//######################################################
{
   char szCmdLine[1024];
   char pszActionDisplay[100];
   char szCmdLine_param[1024];
   char szDocFileName[FILENAME_MAX];
   
   Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));


   if((strcmpi(g_szSite, "Fujitsu")) == 0)
   {
	  // Ask for filename/progname, user may want to make something other
      // then currently open doccument
      if(Gte_GetStringDlg("File or program to Make", "&Name (4gl/5gl/per/m/toc/42r):", g_szFileName,
         sizeof(g_szFileName)) == FALSE)
      {
         // user click Cancel
         return;
      }
   }

   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   strcat(szCmdLine, g_szFileName);
   UnixPathToDosPath(szCmdLine);


   strcpy(g_szServerInitDirNoSys,"/home/users/");

   if((strcmpi(g_szServerInitDir, g_szServerInitDirNoSys)) != 0 ) //|| strcmpi(g_szSite, "CSI") == 0   )
   //if the file is under /home/users/,it does not belong to any program system, otherwise
   // ask for Area name to do environment switching
   {
    	  // read previous Area name form ini file
          GetPrivateProfileString("Remote", "LastArea", "", g_szArea, sizeof(g_szArea), "remote.ini");

          if(Gte_GetStringDlg("Area name", "&Area name:", g_szArea,
             sizeof(g_szArea)) == FALSE)
          {
             // user click Cancel
             return;
          }

          // write last Area name to ini file
          WritePrivateProfileString("Remote", "LastArea", g_szArea, "remote.ini");

          // ask for system name: needed to set environment for compiler, like DBPATH
          // depending on program system

          // read previous system name form ini file
          GetPrivateProfileString("Remote", "LastSysRun", "", g_szSysName, sizeof(g_szSysName), "remote.ini");

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
          strcpy(g_szSysName, "dummy");
    }

   //------------------------------- Change current dir to GWD editor dir

   chdir(g_szGWDdir);

   //------------------------------- Batch file name

   strcpy(szCmdLine, "\""); // this is a first write to szCmdLine
   strcat(szCmdLine, g_szGWDdir);
   strcat(szCmdLine, "bat");
   strcat(szCmdLine, "\\");
   strcat(szCmdLine, g_szSite);
   strcat(szCmdLine, "\\rmake.bat");
   strcat(szCmdLine, "\" ");

   //------------------------------- System name

   strcpy(szCmdLine_param, "");//this is a first write to szCmdLine_param

   if(strchr(g_szSysName, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szSysName);
   if(strchr(g_szSysName, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");


    //-------------------------------- Program area name

/*
   if(strchr(g_szServerInitDir, ' '))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szServerInitDir);
   if(strchr(g_szServerInitDir, ' '))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");

    send Area name instead of ServerInitDir witch is irrelevant if we
    use environment generated by sw command and Jmk for Make

*/

   if(strchr(g_szArea, ' '))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szArea);
   if(strchr(g_szArea, ' '))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");


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

   if(strchr(TMPg_szClientInitDir, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, TMPg_szClientInitDir);
   if(strchr(TMPg_szClientInitDir, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");

   if(strchr(g_szServerName, '"'))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szServerName);
   if(strchr(g_szServerName, '"'))
      strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");

   if(strchr(g_szUserName, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szUserName);
   if(strchr(g_szUserName, ' '))
     strcat(szCmdLine_param, "\"");

   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");
   strcat(szCmdLine_param, g_szPassword);
   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, " ");

   // UNIX FileLocation
   {
       char szUnixFileLoc[MAX_FILE_LOCATION];

       strcpy(szUnixFileLoc, g_szFileLocation);
       DosPathToUnixPath(szUnixFileLoc);

       if(strchr(szUnixFileLoc, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, szUnixFileLoc);
       if(strchr(szUnixFileLoc, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");
   }

   // NT FileLocation
   {
       char szWinFileLoc[MAX_FILE_LOCATION];

       strcpy(szWinFileLoc, g_szFileLocation);
       UnixPathToDosPath(szWinFileLoc);

       if(strchr(szWinFileLoc, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, szWinFileLoc);
       if(strchr(szWinFileLoc, ' '))
         strcat(szCmdLine_param, "\"");
       strcat(szCmdLine_param, " ");
   }

   if(strchr(g_szFileName, ' '))
     strcat(szCmdLine_param, "\"");
   strcat(szCmdLine_param, g_szFileName);
   if(strchr(g_szFileName, ' '))
     strcat(szCmdLine_param, "\"");

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

     //---------------------------- message on Execute Tool Window

     strcpy (pszActionDisplay,"Making ");
     // strcat (pszActionDisplay, szDocFileName);
     strcat (pszActionDisplay, g_szSysName);
     strcat (pszActionDisplay,", please wait...");

    strcat (szCmdLine,szCmdLine_param);

/*
   if (MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION) == IDNO)
     {
         return;
     };
*/


   /* this shows at the status bar for a moment, and disapears. Vedran, why?
	  {
         char szMsg[180];
            strcpy (szMsg, "Running ");
            strcat (szMsg, szCmdLine);
            strcat (szMsg, ", Please wait...");
         Gte_StatusBarMsg(szMsg);
      }

   */

   // Show wait mouse cursor (hourglass)
   WaitCursor();


   //system(szCmdLine);
   Gte_ExecuteTool(szCmdLine, g_pszOutputFile, pszActionDisplay, szCmdLine_param);

   RestoreCursor();

   // Check for errors

   if(stricmp(g_szTransport, "RCP") == 0)
   {
      // with RCP transport, all error checking and opening of .err
      // files is done in .bat file
      char szErrorFile[50];

	  strcpy (szErrorFile, "make_err.flg");

      if(access(szErrorFile, 0) != 0)
      {
         MsgBox("Program Make successful!", MB_OK | MB_ICONINFORMATION);
         return;
      }
      else
      {
         MsgBox("Program make NOT successful!", MB_OK | MB_ICONINFORMATION);
          // position to the first error line of last opened document

          hDoc = Gte_GetActiveDocument();
          Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE);

          // delete error detection flag file
          remove(szErrorFile);

      }

   }
   else
   {
      // NFS mounted drives, including Samba behave exactly the same as
      // local drives, so we can check errors from here
      /*

        char *szEnv;
        char szMakeErr[50];
        char szPathBase[50];
        char szMakePrg[50];
        char szMakeOutput[50];
        char szErrFile1[50];
        char szErrExt1[50];

		MsgBox("a", MB_OK);

        {
            //szEnv = getenv("MAKE_ERR");
            szEnv = getenv("COMSPEC");
            if (szEnv != 0)
            {strcpy (szMakeErr, szEnv);}
            else
            {strcpy (szMakeErr, "");}
        }

		MsgBox("b", MB_OK);

		MsgBox(szMakeErr, MB_OK);

	   if(strlen(szMakeErr) == 0)
	   {
             MsgBox("Cannot read from environment", MB_OK);
             return;
       }

		MsgBox("c", MB_OK);

            strcpy (g_szDebug, "MAKE_ERR is -");
            strcat (g_szDebug, szMakeErr);
			strcat (g_szDebug, "-");

		MsgBox("d", MB_OK);

		// MsgBox(szMakeErr, MB_OK);
        MsgBox(g_szDebug, MB_OK);

        return;

       if(stricmp(szMakeErr, "ERROR") == 0)
       {

        szMakeOutput = getenv("MAKE_OUTPUT");
		szPathBase = getenv("PATH_BASE");
        szMakePrg = getenv("MAKEPRG");
        szErrFile1 = getenv("ERR_FILE1");
        szErrExt1 = getenv("ERR_EXT1");

	    MsgBox(szErrFile1, MB_OK);


           if(stricmp(szErrFile1, "LINK_ERROR") == 0)
           {
                // This was the link error, no .err files, open
                // make log file

           }
           else
           {
                // This was compile error, we have .err files, open them


           }

        }
        else
        {
             MsgBox("Make successful!", MB_OK | MB_ICONINFORMATION);
             return;
        }

       */

      {
        char szPath[FILENAME_MAX];
        char szFile[FILENAME_MAX];
        char szMakeErr[FILENAME_MAX];
        char szNowOpen[FILENAME_MAX];
        char szExt[5];
       	char szIniEntry[8];
        int i;
        char szErrFile[FILENAME_MAX];
        char szDocFileName[FILENAME_MAX];
        char szBackupFile[FILENAME_MAX];
        HDOC hDocToClose;


        // strcpy (szMakeErr, "c:\\progra~1\\GWD\\bat\\CSI\\MakeErr.ini");
       strcpy(szMakeErr, g_szGWDdir);
//       strcat(szMakeErr, "bat");
//       strcat(szMakeErr, "\\");
//       strcat(szMakeErr, g_szSite);
//       strcat(szMakeErr, "\\MakeErr.ini");
       strcat(szMakeErr, "MakeErr.ini");


        if(access(szMakeErr, 0) != 0)
        {
             MsgBox("Make successful!", MB_OK | MB_ICONINFORMATION); //Cannot locate MakeErr.ini file
             return;
        }

        //Get the full name of current active doc.
		Gte_GetFileName(hDoc, szNowOpen, sizeof(szNowOpen));


		//####################
		for(i = 0; i < 5; i++)
        //####################
       	{
          sprintf(szIniEntry, "%d", i+1);
          GetPrivateProfileString(szIniEntry, "Path", "", szPath, FILENAME_MAX, szMakeErr);
    	  if(szPath[0] == 0)
       	      break;
		  GetPrivateProfileString(szIniEntry, "File", "", szFile, FILENAME_MAX, szMakeErr);
          GetPrivateProfileString(szIniEntry, "Ext", "", szExt, FILENAME_MAX, szMakeErr);

              UnixPathToDosPath(szPath);
              strcpy (szErrFile, "\\");
              strcat (szErrFile, "\\");
              strcat (szErrFile, g_szServerName);    //CHAIX
              strcat (szErrFile, szPath);
              strcat (szErrFile, "\\");
			  strcat (szErrFile, szFile);
              strcat (szErrFile, ".err");

        	  strcpy(szBackupFile, szErrFile);
              strcpy(szDocFileName, szErrFile);

        	  psz = strrchr(szDocFileName, '\\');
              if(psz == NULL)
                 psz = szDocFileName;
              psz = strrchr(psz, '.');
              if(psz == NULL) {
                 MsgBox("ERROR: This file does not have file extension! Unable to continue", MB_OK);
                 return;
              }
              strcpy(psz+1, szExt);
              strcpy(szBackupFile + (psz - szDocFileName) + 1, "bak");

              if(access(szErrFile, 0) != 0)
              {
                     strcpy (g_szDebug,"Cannot locate error file ");
                     strcat (g_szDebug,szErrFile);
                     strcat (g_szDebug,". Open MakeErr.ini?");
                     MsgBox(g_szDebug, MB_OK | MB_ICONINFORMATION); //Cannot locate MakeErr.ini file

                     if (MsgBox(g_szDebug, MB_YESNO | MB_ICONQUESTION) == IDYES)
					 {
                          hDoc = Gte_OpenDocument(szMakeErr);
					 };

                     strcpy (g_szDebug,"Open GWD rMake output file?");
                     if (MsgBox(g_szDebug, MB_YESNO | MB_ICONQUESTION) == IDYES)
					 {
                          hDoc = Gte_OpenDocument(g_pszOutputFile);
					 };
                     return;
			  }

              /*
              strcpy (g_szDebug,szNowOpen);
              strcat (g_szDebug,"-");
              strcat (g_szDebug,szDocFileName);
              MsgBox(g_szDebug, MB_OK);
              */

              // If that is the current active doccument, close it
			  /*
			  if(stricmp(szNowOpen,szDocFileName ) == 0)
              {
                 Gte_CloseDocument(hDoc);
              }
              */

              hDocToClose = GetHandleForFileName(szDocFileName);

			  if(hDocToClose != NULL) // Doc szDocFileName is open already in GWD
              {
                 Gte_CloseDocument(hDocToClose);
              };


              // remove filename.bak
              remove(szBackupFile);

              // rename this file to bak
			  rename(szDocFileName, szBackupFile);

              // rename err file to this file
              rename(szErrFile, szDocFileName);

              // open it
              hDoc = Gte_OpenDocument(szDocFileName);

        	  // position to the first error line
              if(stricmp(szExt, "4gl") == 0)
              {
               // 4, 4 in Gte_find is to skip over first 3 lines inserted only by Windows 4GL compiler
               // position to the first error line
               Gte_Find(hDoc, "^\\|", 4, 4, FALSE, FALSE, TRUE, TRUE);

              }

              if(stricmp(szExt, "per") == 0)
              {
            	  if ((g_n4glVer == 4) || (g_n4glVer == 5))       //remote 4Js/Informix D4GL GUI  //remote 4Js/Informix D4GL CHUI
                  {
                       Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE);
    			  }
    			  else
                  {
            		  Gte_Find(hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE);
                  }
              }

        }       // for loop end
      }


   }
}

/*-------------------------------------------------------------------
                      RemoveCompilerErrorLines
-------------------------------------------------------------------*/
/* old ver
void RemoveCompilerErrorLines(HDOC hDoc)
{
   // first check if we have compiler error lines
   // compiler error lines in 4gl begins with | character
   if(Gte_Find(hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
   {
//      if(MsgBox("File contains compiler error lines. Remove them?", MB_YESNO) == IDYES)
//      {
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
//      }
   }
}
*/

//#####################################################################
void RemoveCompilerErrorLines(HDOC hDoc)
//#####################################################################
{

    // remember cursor position (this is not necessary, but it is user friendly)
    GM_SaveCursorPos(hDoc);

    // to speed up macro disable screen update
//    Gte_LockUpdate(hDoc);


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
             }
       }
     }

    if(stricmp(szFileExt, "per") == 0)
     {
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
     }

	  // Unlock screen update
//      Gte_UnlockUpdate(hDoc);
      // restore cursor position from stack
      GM_RestoreCursorPos(hDoc);
      // scroll window if necessary to make cursor visible
      Gte_FixWindowPos(hDoc);

}



//#####################################################################
void UnixPathToDosPath(char *psz)
//#####################################################################
{
   while(*psz)
   {
      if(*psz == '/')
         *psz = '\\';
      psz++;
   }
}

//#####################################################################
void DosPathToUnixPath(char *psz)
//#####################################################################
{
   while(*psz)
   {
      if(*psz == '\\')
         *psz = '/';
      psz++;
   }
}

//#####################################################################
void BaseName(char** ppsz)
//#####################################################################
{
// Yes, it is a mess, but this works
   char* pszslash;

   for (pszslash = *ppsz; *pszslash; pszslash++)
      if (*pszslash == '\\')
      {
    	 *ppsz = pszslash + 1;
      }
}

//#####################################################################
void Make4glWin(HDOC hDoc)
//#####################################################################
{
   char szCmdLine[1024];
   char szErrorFile[FILENAME_MAX];
   char szTargetName[FILENAME_MAX];
   char szBackupTarget[FILENAME_MAX];
   char szWorkPath[FILENAME_MAX];
   char szProject[FILENAME_MAX];
   char szTOC[FILENAME_MAX];
   char szSourceFile[FILENAME_MAX];
   char szFileName[FILENAME_MAX];
   char szBackupFile[FILENAME_MAX];
   char pszOutputFile[FILENAME_MAX];
   char pszActionDisplay[FILENAME_MAX];
   char szCompCommand[FILENAME_MAX];
   char szSourcePath[FILENAME_MAX];
   char szFormsPath[FILENAME_MAX];
   char szExecPath[FILENAME_MAX];
   char szSuccess[2];
   char szExt[4];
   char szMakeType[8];
   char szMakeCommand[10];
   char szFindErr[10];
   char szDescr[10];


   // determine if we are using some form of make and makefile,
   // or we are going file by file with .TOC ini file
   // can be MAKE or TOC
   strcpy(szMakeType,"MAKE");

   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	{
	   strcpy(szMakeCommand,"make");
    }
    else
    {
	   strcpy(szMakeCommand,"nmake /f");
    }


    {
	   // ex: strcpy(szWorkPath, "c:\\prg\\job_post");

		Gte_GetFileName(hDoc, szWorkPath, sizeof(szWorkPath)); //returns with full path

	  	psz = strrchr(szWorkPath, '\\');
	      if(psz == NULL)
    	     psz = szWorkPath;
	      if(psz == NULL) 
		  {
    	     MsgBox("ERROR: Cannnot find backslash", MB_OK);
        	 return;
	      }
		 //strcpy(psz+1, ""); // This will leave trailing backslash at the end
		 strcpy(psz, ""); // This will NOT leave trailing backslash at the end
	     // MsgBox(szWorkPath, MB_OK);

	 }

	// actually, name of expected executable after make,
	// and the name of the TOC file
	//   strcpy(szProject, "job_post");
       strcpy(szProject, "perorg");

   strcpy(szTargetName,szWorkPath);
   strcat(szTargetName, "\\");
   strcat(szTargetName, szProject);

   strcpy(szTOC, szTargetName);
   strcat(szTOC, ".TOC");

  // Paths for source, forms and resulting executables can be different then current:
  // WARNING ! THIS IS NOT USSED AT PRESENT, and should be used !
  GetPrivateProfileString("Project", "SourcePath", "", szSourcePath, FILENAME_MAX, szTOC);
  GetPrivateProfileString("Project", "FormsPath", "", szFormsPath, FILENAME_MAX, szTOC);
  GetPrivateProfileString("Project", "ExecPath", "", szExecPath, FILENAME_MAX, szTOC);



   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	{
	   strcat(szTargetName, ".42r");
    }
    else
	{
	   strcat(szTargetName, ".4gi");
    }


   strcpy(szBackupTarget,szTargetName);
   strcat(szBackupTarget,".bak");

   // rename target if exists
   if(access(szTargetName, 0) == 0)
   {
       if(access(szBackupTarget, 0) == 0)
       {
    	  // remove old target backup
          remove(szBackupTarget);
       }
	   rename(szTargetName, szBackupTarget);
   };


    /*
    gtecap32

	start /m /w

	nmake /f%1\%2.mkf %2.%3 %2 >>%2.%4

    nmake /fc:\prg\job_post\job_post.mkf job_post.4gi job_post


    Usage:  NMAKE @commandfile
            NMAKE [options] [/f makefile] [/x stderrfile] [macrodefs] [targets]

    Options:

    /A Build all evaluated targets
    /B Build if time stamps are equal
    /C Suppress output messages
    /D Display build information
    /E Override env-var macros
    /HELP Display brief usage message
    /I Ignore exit codes from commands
    /K Build unrelated targets on error
    /N Display commands but do not execute
    /NOLOGO Suppress copyright message
    /P Display NMAKE information
    /Q Check time stamps but do not build
    /R Ignore predefined rules/macros
    /S Suppress executed-commands display
    /T Change time stamps but do not build
    /U Dump inline files
    /Y Disable batch-mode
    /? Display brief usage message




	1= path to program files
    2= program name
    3= 4gi
    4= pre for prewiew or bld for build
	*/

   chdir(szWorkPath);

   strcpy (pszOutputFile, szProject);
   strcat (pszOutputFile, ".bld ");

   strcpy (pszActionDisplay,"Making program ");
   strcat (pszActionDisplay, szProject);
   strcat (pszActionDisplay,", please wait...");

	/*
   strcpy (szCmdLine, "c:\\progra~1\\gwd\\");
   strcat (szCmdLine, "gtecap32.exe ");
   strcat (szCmdLine, pszOutputFile);
    */

   strcpy (szCmdLine, szMakeCommand);

   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
	{
        // just 'make' will do in the current dir, with default makefile
    }
    else
    {
	   strcat (szCmdLine, " ");
	   strcat (szCmdLine, szWorkPath);
	   strcat (szCmdLine, "\\");
	   strcat (szCmdLine, szProject);
	   strcat (szCmdLine, ".mkf ");
	//   strcat (szCmdLine, szTargetName);
	   strcat (szCmdLine, szProject);
	   strcat (szCmdLine, ".4gi ");

	   strcat (szCmdLine, szProject);

	   /*
	   strcpy (szCmdLine, "pembld ");
	   strcat (szCmdLine, szWorkPath);
	   strcat (szCmdLine, " ");
	   strcat (szCmdLine, szProject);
	   strcat (szCmdLine, " 4gi bld");
	   */

	}


   if(strcmpi(szMakeType,"MAKE"))
   {
       // If we are NOT using MAKE...will step file-by-file
   }
   else
   {
     // If using MAKE, run it now
	 WaitCursor();

//   if(MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES)
//   {
       // system(szCmdLine);

       // int Gte_ExecuteTool(const char * pszCmdLine,
	   // const char * pszOutputFile, const char * pszPrgName, const char * pszArg)

       Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine); //" Args...");
//   }
     RestoreCursor();
   }

   strcpy(szSuccess,"Y");

    {
	// ###############################################
	// Compile file by file and/or Check error files
	// ###############################################
      int i;
      int e;
	  char szIniEntry[8];
      char szWarnFile[FILENAME_MAX];

      for(e = 0; e < MAX_SOURCE_TYPES; e++)
      {
    	  switch(e+1)
          {
             case 1:
			 	strcpy (szExt, "4gl"); strcpy(szFindErr,"^\\|");
			    if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
				{
					strcpy (szCompCommand,"fglcomp ");
                }
                else
                {
					strcpy (szCompCommand,"ix w4glcomp -n -pcode ");       //must use ix if not using WinExec
                }

				strcpy (szDescr," source ");break;

    		 case 2:
			 	strcpy (szExt, "per");
			    if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
				{
					strcpy(szFindErr,"^\\|");
				    strcpy (szCompCommand,"fglform ");              //ix
				}
                else
                {
					strcpy(szFindErr,"^#");
				    strcpy (szCompCommand,"ix wform4gl -n ");              //ix
                }
				strcpy (szDescr," form ");break;

             case 3:
			 	strcpy (szExt, "xxx"); break;   // end of sourcefile types list
           };

           /*
           sprintf(g_szDebug, "%d", e+0);
		   strcat (g_szDebug,"-");
		   strcat (g_szDebug,szExt);
		   strcat (g_szDebug,"-");


             if(MsgBox(g_szDebug,
                MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
             {
                return;
             }
           */

		   if(strcmpi(szExt, "xxx"))
           {
                //###################################
				for(i = 0; i < MAX_SOURCE_FILES; i++)
                //###################################
				{
                  sprintf(szIniEntry, "%d", i+1);

            	  GetPrivateProfileString(szExt, szIniEntry, "", szSourceFile, FILENAME_MAX, szTOC);

				  if(szSourceFile[0] == 0)
            	      break;

                  // WARNING ! should use szSourcePath, szFormsPath and szExecPath
                  // retrived from .toc before !

				  strcpy(szErrorFile,szWorkPath);
                  strcat(szErrorFile,"\\");
                  strcat(szErrorFile,szSourceFile);

        		  strcpy(szFileName,szErrorFile);
        		  strcat(szFileName,".");

				  strcpy(szWarnFile,szErrorFile);
        		  strcat(szWarnFile,".wrn");

				  strcat(szFileName,szExt);           //".4gl"
        		  strcat(szErrorFile,".err");


        		  strcpy(szBackupFile,szFileName);
				  strcat(szBackupFile,szExt);         // .4gl
				  strcat(szBackupFile,".bak");

                  strcpy(szCmdLine,szCompCommand);
				  strcat(szCmdLine,szSourceFile);
                  strcat(szCmdLine,".");
                  strcat(szCmdLine,szExt);

                  if(strcmpi(szMakeType,"MAKE"))
                  {
                   // NOT using MAKE, compile file-by-file first...
					   strcpy (pszActionDisplay,"Compiling");
                       strcat (pszActionDisplay,szDescr);
                       strcat (pszActionDisplay,"file ");
    				   strcat (pszActionDisplay, szSourceFile);
                       strcat (pszActionDisplay,", please wait...");

                      //  WinExec(szCmdLine, 1); // Does not wait for app to finnish...no can do!
    				  // (otherwise works, without "ix" )
                      Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine); //" Args...");
                      //	c:\informix\bin\errchkr c:\prg\job_post\job_post.4gl
                  }

                  // make or file-by-file, we will check for errors now:
        		  if(access(szErrorFile, 0) == 0)  // Error file exist
                  {
                        strcpy(szSuccess,"N");  // set success flag to N

               		    // MsgBox(szErrorFile, MB_OK | MB_ICONINFORMATION);


						// close source file that was active at the moment
                        // of make start, and HOPE that this is the one
                        // that caused compile error. This is to prevent
                        // mesage "Another app have changed...reload?"
                        // from poping up, because we cannot close a
                        // document based on filename...Vedran?
						// Gte_CloseDocument(hDoc);

                        // sollution for above

				        // Gte_GetFileName(hDoc, szDocFileName, sizeof(szDocFileName));
						{
                         HDOC hDocToClose;

						hDocToClose = GetHandleForFileName(szFileName);  // full source file name

					    if(hDocToClose != NULL) // Doc szDocFileName is open already in GWD
			              {
			                 Gte_CloseDocument(hDocToClose);
			              };
                        }

						// remove filename.bak - old backup
               		    // MsgBox(szBackupFile, MB_OK | MB_ICONINFORMATION);
						remove(szBackupFile);

						// rename this source file to bak
                        /*
                        strcpy (g_szDebug,szFileName);
                        strcat (g_szDebug,"-");
                        strcat (g_szDebug,szBackupFile);
					    MsgBox(g_szDebug, MB_OK | MB_ICONINFORMATION);
                        */
						rename(szFileName, szBackupFile);


                        // rename err file to this file
                        /*
						strcpy (g_szDebug,szErrorFile);
                        strcat (g_szDebug,"-");
                        strcat (g_szDebug,szFileName);
					    MsgBox(g_szDebug, MB_OK | MB_ICONINFORMATION);
                        */
						rename(szErrorFile,szFileName);


                  // how can I check if this file is already opened in GWD,
                  // to prevent message "Another app has updated .... reload?"

               		    //MsgBox(szFileName, MB_OK | MB_ICONINFORMATION);

						// open it
                        hDoc = Gte_OpenDocument(szFileName);
                        //Gte_SetActiveDocument(hDoc);


                        // 4, 4 in Gte_find is to skip over first 3 lines:
                        // |
                        // |	Source File : c:\prg\job_post\job_post.4gl
                        // |
                        // position to the first error line
                        Gte_Find(hDoc, szFindErr, 4, 4, FALSE, FALSE, TRUE, TRUE);
				  }

				  if(strcmpi(szExt, "per"))
				  // check also for wrn warning files for per sourcefiles in 4gl for windows only!!
                  {
    			    if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
                    {
                    }
                    else
                    {
					  if(access(szWarnFile, 0) == 0)  // Warning file exist
                      {
                            //strcpy(szSuccess,"N");  // set success flag to N
    						// open it
                            hDoc = Gte_OpenDocument(szFileName);
                      }
                    }
                  }
		   }
           else //szExt = "xxx", sourcefiles types list exspusted
           {
            break;
           }
       }
	}


   if(strcmpi(szSuccess, "Y"))  // No error files
   {
         // MsgBox("Err file(s) found!", MB_OK | MB_ICONINFORMATION);
   }
   else
   {
      if(strcmpi(szMakeType,"MAKE"))
      {
	                // Link object file

	   if(g_n4glVer == 6) //local 4Js/Informix D4GL GUI
        {
            // fgllink -o target.42r 1.42m 2.42m ... etc.
        }
        else
        {
            // 4gl for Windows: I must step one-by-one because dos command line
            // length is limmited
	      int i;
	      int e;
		  char szIniEntry[8];
	      char szCopyCmd[10];
	      char szObjectFile[FILENAME_MAX];

	      strcpy (szCopyCmd,"cach copy /b ");

	  	  GetPrivateProfileString("4gl", "1", "", szSourceFile, FILENAME_MAX, szTOC);

		  strcpy(szObjectFile,szWorkPath);
	      strcat(szObjectFile,"\\");
	      strcat(szObjectFile,szSourceFile);
		  strcat(szObjectFile,".4go");

		  strcpy (szCmdLine,szCopyCmd);
		  strcat (szCmdLine,szObjectFile);
		  strcat (szCmdLine," ");
		  strcat (szCmdLine,szTargetName);            //job_post.4gi

	      strcpy (pszActionDisplay,"Linking object ");
	      strcat (pszActionDisplay, szSourceFile);
	      strcat (pszActionDisplay,", please wait...");

		  // 	copy /b c:\prg\job_post\job_glob.4go job_post.4gi
	      //      Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);
	        system(szCmdLine);
	        MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
	                for(i = 1; i < MAX_SOURCE_FILES; i++)
	            	{
	                  sprintf(szIniEntry, "%d", i+1);

	            	  GetPrivateProfileString("4gl", szIniEntry, "", szSourceFile, FILENAME_MAX, szTOC);

	               	  if(szSourceFile[0] == 0)
	            	      break;

	                  strcpy(szObjectFile,szWorkPath);
	                  strcat(szObjectFile,"\\");
	                  strcat(szObjectFile,szSourceFile);
	        		  strcat(szObjectFile,".4go");

	            	  strcpy (szCmdLine,szCopyCmd);
	            	  strcat (szCmdLine,szObjectFile);
	            	  strcat (szCmdLine,"+");
	            	  strcat (szCmdLine,szTargetName);            //job_post.4gi
	            	  strcat (szCmdLine," ");
	            	  strcat (szCmdLine,szTargetName);            //job_post.4gi

	                   strcpy (pszActionDisplay,"Linking object ");
					   strcat (pszActionDisplay, szSourceFile);
	                   strcat (pszActionDisplay,", please wait...");


	                  // Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);
	                  // copy /b job_post.4gi+c:\prg\job_post\job_main.4go job_post.4gi
	                    system(szCmdLine);
	                    MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);

				   }
        }
       }   // if not MAKE - link objects

       if(access(szTargetName, 0) != 0)  // No target
       {
            // MsgBox("Linking failed, Target not generated!", MB_OK | MB_ICONINFORMATION);
           if(MsgBox("Linking failed, Target not generated! Do you want to examine build log?",
    	            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES)
           {
        		strcpy (szCmdLine,szWorkPath);
    			strcat (szCmdLine,"\\");
    			strcat (szCmdLine, szProject);
                strcat (szCmdLine, ".bld");
                hDoc = Gte_OpenDocument(szCmdLine);
           }
           else
           {
    		 return;
           }
       }
       else
       {
		 MsgBox("Program Make successful!", MB_OK | MB_ICONINFORMATION);
         return;
       }
   }

   return;
 }                 // end Compile and/or Check error files

}   // End function


//#################################################
HDOC GetHandleForFileName(const char *pszFileName)
//#################################################
// This function will return hDoc for filename or null if that doc is not
// open at all.
// Function Gte_GetFileName returns file name if we know its hDoc
// Gte_GetActiveDocument returns hDoc of active document
// Macro GM_NextWindow(hDoc) sets nex doc to be active

{
   HDOC hDocFirst;
   HDOC hDoc;
   char szActiveFileName[FILENAME_MAX];

   hDocFirst = Gte_GetActiveDocument();
   if(hDocFirst == NULL)
      return NULL;

// MsgBox("1", MB_OK);

// Gte_GetFileName(hDoc, szActiveFileName, FILENAME_MAX); // hang

 //MsgBox("1x", MB_OK);

   if(Gte_GetFileName(hDocFirst, szActiveFileName, FILENAME_MAX) > 0)
   {
// MsgBox("1a", MB_OK);

      if(strcmpi(pszFileName, szActiveFileName) == 0)
// MsgBox("1b", MB_OK);
         return hDocFirst;
   }

// MsgBox("2", MB_OK);

   GM_NextWindow(hDocFirst);
   hDoc = Gte_GetActiveDocument();


   //######################################
   while(hDoc != NULL && hDoc != hDocFirst)
// original  while(hDoc !+ NULL && hDoc != hDocFirst)
//  while(hDoc !+ NULL)  //  && hDoc != hDocFirst
//    while(hDoc != NULL)  //  && hDoc != hDocFirst OK
//  while(TRUE) OK
//   while( (hDoc !+ NULL) && (hDoc != hDocFirst) )
//   while( (hDoc != hDocFirst) ) OK

   //######################################


   {

// MsgBox("x", MB_OK);

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


   }  // end while


   return NULL;
}

//////////////////////////////////////////////////////////////// EOF
