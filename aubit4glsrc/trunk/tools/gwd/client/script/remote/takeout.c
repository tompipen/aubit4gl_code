/********************************************************************
                         TakeOut
********************************************************************/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <io.h>  //needed for access function
#include <editor/app.h>
#include <editor/dlg.h>
#include <editor/doc.h>

#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80  // max file location string
#define MAX_FILE_NAME      80
#define MAX_FAVORITE_FILES 10  // number of favorite files

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

char g_Menu1[MAX_FILE_NAME];
char g_Menu2[MAX_FILE_NAME];
char g_Menu3[MAX_FILE_NAME];
char g_Menu4[MAX_FILE_NAME];
char g_Menu5[MAX_FILE_NAME];
char g_Menu6[MAX_FILE_NAME];
char g_Menu7[MAX_FILE_NAME];
char g_Menu8[MAX_FILE_NAME];
char g_Menu9[MAX_FILE_NAME];
char g_Menu10[MAX_FILE_NAME];

char g_Init1[MAX_FILE_NAME];
char g_Init2[MAX_FILE_NAME];
char g_Init3[MAX_FILE_NAME];
char g_Init4[MAX_FILE_NAME];
char g_Init5[MAX_FILE_NAME];
char g_Init6[MAX_FILE_NAME];
char g_Init7[MAX_FILE_NAME];
char g_Init8[MAX_FILE_NAME];
char g_Init9[MAX_FILE_NAME];
char g_Init10[MAX_FILE_NAME];

char g_Location1[MAX_FILE_NAME];
char g_Location2[MAX_FILE_NAME];
char g_Location3[MAX_FILE_NAME];
char g_Location4[MAX_FILE_NAME];
char g_Location5[MAX_FILE_NAME];
char g_Location6[MAX_FILE_NAME];
char g_Location7[MAX_FILE_NAME];
char g_Location8[MAX_FILE_NAME];
char g_Location9[MAX_FILE_NAME];
char g_Location10[MAX_FILE_NAME];


char g_FavNum[4];        //Number of Favorite Remote file location in ini file
                         // or PREV and NEW

// function prototypes:
void UnixPathToDosPath(char *);         // Common
void DosPathToUnixPath(char *);         // Common
void ReplaceNonDOSchar(char *);         // Common
BOOL MakeDir(const char *pszDir);       // Common

// TakeOut functions (+ main)
void TakeOut(void);
void LocationMenu(void);

// test functions:
void NextTodoFile(char *pszFile);
void NextToDoFile2(HDOC);


/*-------------------------------------------------------------------
                    main function
-------------------------------------------------------------------*/

int main(int argc, char *argv[])
{

   // read configuration from ini file
   GetPrivateProfileString("Remote", "TakeOutCmd", "", g_szTakeOutCmd, sizeof(g_szTakeOutCmd), "gte.ini");
   GetPrivateProfileString("Remote", "ServerInitDir", "", g_szServerInitDir, sizeof(g_szServerInitDir), "gte.ini");
   GetPrivateProfileString("Remote", "ClientInitDir", "", g_szClientInitDir, sizeof(g_szClientInitDir), "gte.ini");
   GetPrivateProfileString("Remote", "ServerName", "", g_szServerName, sizeof(g_szServerName), "gte.ini");
   GetPrivateProfileString("Remote", "UserName",   "", g_szUserName, sizeof(g_szUserName), "gte.ini");
   GetPrivateProfileString("Remote", "Password",   "", g_szPassword, sizeof(g_szPassword), "gte.ini");

   // check configuration parameters and ask for them is necessary
   if(strlen(g_szTakeOutCmd) == 0) {
      if(Gte_GetStringDlg("TakeOut command", "&TakeOut command:",
         g_szTakeOutCmd, sizeof(g_szTakeOutCmd)) == FALSE)
      {
         return 0;
      }
   }
   if(strlen(g_szServerInitDir) == 0) {
      if(Gte_GetStringDlg("Server Initial Directory", "&Server initial dir:",
         g_szServerInitDir, sizeof(g_szServerInitDir)) == FALSE)
      {
         return 0;
      }
      if(strlen(g_szServerInitDir) == 0) {
         MsgBox("Invalid initial dir", MB_OK);
         return 0;
      }
   }
   if(strlen(g_szClientInitDir) == 0) {
      MsgBox("Select client initial directory", MB_OK);
      if(Gte_BrowseForDirDlg(g_szClientInitDir, sizeof(g_szClientInitDir), FALSE) == FALSE)
         return 0;
      if(strlen(g_szClientInitDir) == 0) {
         MsgBox("Invalid client initial dir", MB_OK);
         return 0;
      }
   }
   if(strlen(g_szServerName) == 0) {
      if(Gte_GetStringDlg("Server Name", "&Server name:", g_szServerName, sizeof(g_szServerName)) == FALSE)
         return 0;
      if(strlen(g_szServerName) == 0) {
         MsgBox("Invalid server name", MB_OK);
         return 0;
      }
   }
   if(strlen(g_szUserName) == 0) {
      if(Gte_GetStringDlg("User Name", "&User name:", g_szUserName, sizeof(g_szUserName)) == FALSE)
         return 0;
      if(strlen(g_szUserName) == 0) {
         MsgBox("Invalid user name", MB_OK);
         return 0;
      }
   }
   if(strlen(g_szPassword) == 0) {
      if(Gte_GetStringDlg("Password", "&Password:", g_szPassword, sizeof(g_szPassword)) == FALSE)
         return 0;
      if(strlen(g_szPassword) == 0) {
         MsgBox("Invalid password", MB_OK);
         return 0;
      }
   }

   // TakeOut file
   TakeOut();

   return 0;
}

/*-------------------------------------------------------------------
                         TakeOut
-------------------------------------------------------------------*/

void TakeOut(void)
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
      strcpy(szDefaultExt, "4gl");
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
   GetPrivateProfileString("Remote", "LastBADTakeOutFileName", "", g_szFileName, sizeof(g_szFileName), "gte.ini");

   // Try to find next unprocessed file listed in xxtodo.log file, and
   // offer that as default filename
   //xx

//   g_szFileName = NextTodoFile("VJ_todo.log");
//   NextTodoFile("VJ_todo.log");


//   hdoc = Gte_GetActiveDocument();


//  hdoc = "c:\\progra~1\\GDWedit\\VJ_todo.log";

//         MsgBox(szDefaultExt, MB_OK);

//         MsgBox(PromptFor, MB_OK);

      strcpy(PromptFor, "File name (default=.");

//          MsgBox(PromptFor, MB_OK);     //ok

      strcat(PromptFor, szDefaultExt);

//          MsgBox(PromptFor, MB_OK);

      strcat(PromptFor, ")");
//      MsgBox(PromptFor, MB_OK);


   while(TRUE)
   {
//      if(Gte_GetStringDlg("File Name", "&File name:", g_szFileName,
      if(Gte_GetStringDlg( PromptFor, "&File name:" , g_szFileName,
//      if(Gte_GetStringDlg( PromptFor, FavoriteRemoteList , g_szFileName,

         sizeof(g_szFileName)) == FALSE)
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
      strcpy(szBackupFile, g_szFileName);
      strcpy(szErrorFile, g_szFileName);
      psz = strrchr(szErrorFile, '\\');
      if(psz == NULL)
         psz = szErrorFile;
      psz = strrchr(psz, '.');
      if(psz == NULL) {   //This file does not have file extension

          //one more time...
          strcpy(szBackupFile, g_szFileName);
          strcat(szBackupFile, ".xxx");
          strcpy(szErrorFile, g_szFileName);
          strcat(szErrorFile, ".xxx");
          psz = strrchr(szErrorFile, '\\');
          if(psz == NULL)
             psz = szErrorFile;
          psz = strrchr(psz, '.');
          if(psz == NULL) {
             MsgBox("ERROR: This file STILL does not have file extension!", MB_OK);
             return;
          }

          //add default extension
          strcpy(psz+1, szDefaultExt);
          strcpy(szBackupFile + (psz - szErrorFile) + 1, "bak");
          strcpy(g_szFileName, szErrorFile);
      }

      if(strpbrk(g_szFileName, "\\/:*?"))
      {
         MsgBox("Invalid file name", MB_OK);
      }
      else
         break;
   }


   // ask for location
   // we will propose last takeout location as default takeout location
   GetPrivateProfileString("Remote", "LastTakeOutLocation", "", g_szFileLocation, sizeof(g_szFileLocation), "gte.ini");
   while(TRUE)
   {

      LocationMenu();

//      MsgBox(g_FavNum, MB_OK);

      if(strcmpi(g_FavNum, "EXIT"))
      {
      }
      else
      {
        return;
      }

      if(strcmpi(g_FavNum, "PREV"))
      {
          if(strcmpi(g_FavNum, "NEW"))
          {
              // User want to use path stored by number g_FavNum
              // We have this in g_Init1 and g_Location1...but...
              GetPrivateProfileString("FavoriteRemoteInitDir", g_FavNum, "", g_szServerInitDir, MAX_INIT_DIR, "gte.ini");
              GetPrivateProfileString("FavoriteRemoteTakeOutLocation", g_FavNum, "", g_szFileLocation, MAX_FILE_LOCATION, "gte.ini");
          }
          else
          {
              // ask for NEW location input:

              strcpy(g_WindowTitle, "Initial server path for ");
              strcat(g_WindowTitle, g_szFileName);

                if(Gte_GetStringDlg(g_WindowTitle, g_szServerName, g_szServerInitDir,
                 sizeof(g_szServerInitDir)) == FALSE)
              {
                 // user click Cancel
                    return;
              }

              strcpy(g_WindowTitle, "Location of ");
              strcat(g_WindowTitle, g_szFileName);

                if(Gte_GetStringDlg(g_WindowTitle, g_szServerInitDir, g_szFileLocation,
              //if(Gte_GetStringDlg(g_WindowTitle, "&File location:", g_szFileLocation,
              //if(Gte_GetStringDlg("File Location", "&File location:", g_szFileLocation,
                 sizeof(g_szFileLocation)) == FALSE)
              {
                 // user click Cancel
                 //  return 0;
                    return;
              }
          }
      }
      else
      {
             // we already have PREVIOUS location in g_szServerInitDir and g_szFileLocation
             //MsgBox(g_szServerInitDir, MB_OK);
             //MsgBox(g_szFileLocation, MB_OK);
      }

      if(strpbrk(g_szFileLocation, ":*?") || g_szFileLocation[0] == '/' || g_szFileLocation[0] == '\\')
        {
           MsgBox("Invalid file location", MB_OK);
        }
         else
            break;
  }


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

   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   szCmdLine[strlen(szCmdLine)-1] = 0;   // remove "/" from the end
   UnixPathToDosPath(szCmdLine);

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

   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   strcat(szCmdLine, g_szFileName);
   UnixPathToDosPath(szCmdLine);

      if(access(szCmdLine, 0) == 0)
   {

       strcpy(g_szDebug, "File ");
       strcat(g_szDebug, szCmdLine);
       strcat(g_szDebug, " already exists on local disk. Overwrite with remote file?");

      if (MsgBox(g_szDebug ,MB_YESNO | MB_ICONQUESTION) == IDNO)
      {
           strcpy(g_szDebug, "Open Local File ");
           strcat(g_szDebug, szCmdLine);
           strcat(g_szDebug, " ?");
          if (MsgBox(g_szDebug ,MB_YESNO | MB_ICONQUESTION) == IDNO)
          {
               return;
          }
          else
          {
              RestoreCursor();
              Gte_OpenDocument(szCmdLine);
              return;
          }
      }

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


   if (1==2) {
           //--------------------- version with patth to .bat file -------------//
           Gte_GetTextEditorDir(szBatPath,FILENAME_MAX);
           // MsgBox(szBatPath , MB_OK);
           strcpy(g_szExecCmd, szBatPath);

           // strcpy(szCmdLine, "takeout.bat ");
           strcat(g_szExecCmd,"takeout.bat" );

           if(strrchr(g_szExecCmd, ' '))
             strcpy(szCmdLine, "start /w \"");  // w is to prevent command returning before finninhed

           if(strrchr(g_szExecCmd, ' ')) {
             strcat(szCmdLine, g_szExecCmd);
             }
             else
             {
             strcpy(szCmdLine, g_szExecCmd);
             }
           if(strchr(g_szExecCmd, ' '))
             strcat(szCmdLine, "\"");

           strcat(szCmdLine, " ");        // add one space
    }
    else
    {
            // --------------- original -------------------//

           strcpy(szCmdLine,"bat\\takeout.bat " );

    }

    // 1
   if(strrchr(g_szTakeOutCmd, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, g_szTakeOutCmd);
   if(strchr(g_szTakeOutCmd, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");


    //2
    //   MsgBox(g_szServerInitDir, MB_OK);
   if(strchr(g_szServerInitDir, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, g_szServerInitDir);
   if(strchr(g_szServerInitDir, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");

    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    //3
    // MsgBox(g_szClientInitDir, MB_OK);

    strcpy(TMPg_szClientInitDir, g_szClientInitDir);
    psz = TMPg_szClientInitDir;
    if(*psz == 'C'||*psz == 'c') {
             if(*(psz+1) == ':') {
                psz = psz + 2;
                strcpy(TMPg_szClientInitDir,psz);
            }
    }

   if(strchr(TMPg_szClientInitDir, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, TMPg_szClientInitDir);
   if(strchr(TMPg_szClientInitDir, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");

   //4
   if(strchr(g_szServerName, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, g_szServerName);
   if(strchr(g_szServerName, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");

   //5
   if(strchr(g_szUserName, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, g_szUserName);
   if(strchr(g_szUserName, ' '))
     strcat(szCmdLine, "\"");

     //6
   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");
   strcat(szCmdLine, g_szPassword);
   if(strchr(g_szPassword, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, " ");

   // UNIX FileLocation
   // 7
   {
       char szUnixFileLoc[MAX_FILE_LOCATION];

       strcpy(szUnixFileLoc, g_szFileLocation);
       DosPathToUnixPath(szUnixFileLoc);

       if(strchr(szUnixFileLoc, ' '))
         strcat(szCmdLine, "\"");
       strcat(szCmdLine, szUnixFileLoc);
       if(strchr(szUnixFileLoc, ' '))
         strcat(szCmdLine, "\"");
       strcat(szCmdLine, " ");
   }
   // NT FileLocation
   //8
   {
       char szWinFileLoc[MAX_FILE_LOCATION];

       strcpy(szWinFileLoc, g_szFileLocation);
       UnixPathToDosPath(szWinFileLoc);

       if(strchr(szWinFileLoc, ' '))
         strcat(szCmdLine, "\"");
       strcat(szCmdLine, szWinFileLoc);
       if(strchr(szWinFileLoc, ' '))
         strcat(szCmdLine, "\"");
       strcat(szCmdLine, " ");
   }

   //9
   if(strchr(g_szFileName, ' '))
     strcat(szCmdLine, "\"");
   strcat(szCmdLine, g_szFileName);
   if(strchr(g_szFileName, ' '))
     strcat(szCmdLine, "\"");
/*
   if (MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION) == IDNO)
     {
         return;
     };
*/
   // Show wait mouse cursor (hourglass)
   WaitCursor();

   system(szCmdLine);

   // Check for error.$$$ file in the local directory after calling bat
   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   strcat(szCmdLine, "error.$$$");          //general error
   UnixPathToDosPath(szCmdLine);

   if(access(szCmdLine, 0) == 0)    // test for existance of generated .$$$ file
   {
      strcpy(g_szDebug, "Error message generated by TakeOut.bat. Do you want to examine TakeOut.log file ?");

      if (MsgBox(g_szDebug ,MB_YESNO | MB_ICONQUESTION) == IDYES)
      {
          strcpy(g_szDebug,g_szClientInitDir);
          strcat(g_szDebug, g_szFileLocation);
          strcat(g_szDebug, "TakeOut.log");
          UnixPathToDosPath(g_szDebug);

          Gte_OpenDocument(g_szDebug);
      }
      remove(szCmdLine);    // delete error.$$$ file
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
   strcpy(szCmdLine, g_szClientInitDir);
   strcat(szCmdLine, g_szFileLocation);
   strcat(szCmdLine, g_szFileName);
   UnixPathToDosPath(szCmdLine);

   RestoreCursor();

    if(access(szCmdLine, 0) == 0)    // first test for existance of requested file
                                     // this is to prevent unseccsessfull Gte_OpenDocument
                                     // from messing up windows in GWD
                                     // Vedran suggested to use this:
                                     //   if(Gte_OpenDocument(szCmdLine) == NULL)
                                	 // {
                                	 //   FullScreen
                                	 // }

   {
       if(Gte_OpenDocument(szCmdLine) != NULL)
       {
          // SUCCESS:

          // write last TakeOut location and file name to ini file
          WritePrivateProfileString("Remote", "LastTakeOutLocation", g_szFileLocation, "gte.ini");
          WritePrivateProfileString("Remote", "LastTakeOutFileName", g_szFileName, "gte.ini");
          WritePrivateProfileString("Remote", "LastBADTakeOutFileName", "", "gte.ini");
          WritePrivateProfileString("Remote", "ServerInitDir", g_szServerInitDir, "gte.ini");

          // add TakeOut location and file name to takeout.ini file
          WritePrivateProfileString("TakeOutLocation", szCmdLine, g_szFileLocation, "takeout.ini");
          WritePrivateProfileString("TakeOutFileName", szCmdLine, g_szFileName, "takeout.ini");
          WritePrivateProfileString("PutBack", szCmdLine, "0", "takeout.ini");
          WritePrivateProfileString("InitialPath", szCmdLine, g_szServerInitDir, "takeout.ini");

          // Write to FavoriteRemoteFiles section if this is new location:

            {
                int argc;
                char *argv[];
                int i;
                char szFileNameFav[FILENAME_MAX];
                char IsNewLocation[5];
                char szRemoteTakeOutLocationFav[MAX_FILE_LOCATION];
                char szRemoteInitDirFav[MAX_INIT_DIR];
            	char szIniEntry[8];

               strcpy (IsNewLocation, "YES");

               //MsgBox(IsNewLocation, MB_OK);

               for(i = 0; i < MAX_FAVORITE_FILES; i++)
            	{
                  sprintf(szIniEntry, "%d", i+1);
                  GetPrivateProfileString("FavoriteRemoteFiles", szIniEntry, "", szFileNameFav, FILENAME_MAX, "gte.ini");
                  if(szFileNameFav[0] == 0)
            	      break;

                  GetPrivateProfileString("FavoriteRemoteInitDir", szIniEntry, "", szRemoteInitDirFav, MAX_INIT_DIR, "gte.ini");
                  GetPrivateProfileString("FavoriteRemoteTakeOutLocation", szIniEntry, "", szRemoteTakeOutLocationFav, MAX_FILE_LOCATION, "gte.ini");

                  if(strcmpi(szRemoteInitDirFav, g_szServerInitDir))
                  {
                        // ServerInitDir ini entry no. szIniEntry is different, so continue searching
                  }
                  else
                  {
                      // InitDir is same as recorded..
                      if(strcmpi(szRemoteTakeOutLocationFav, g_szFileLocation))
                      {
                        // ...but location is different so continue searching

                      }
                      else
                      {
                        // ... and location is already recorded, so stop searching
                        strcpy (IsNewLocation, "NO");
                        break;
                      }

                  }
                }           // for loop end


              //MsgBox(IsNewLocation, MB_OK);

              if(strcmpi(IsNewLocation, "YES"))
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
                    sprintf(szIniEntry, "%d", i+1); //add one as next free location

                    //MsgBox(szIniEntry, MB_OK);

                    WritePrivateProfileString("FavoriteRemoteFiles", szIniEntry, g_szFileName, "gte.ini");
                    WritePrivateProfileString("FavoriteRemoteInitDir",szIniEntry ,g_szServerInitDir, "gte.ini");
                    WritePrivateProfileString("FavoriteRemoteTakeOutLocation",szIniEntry , g_szFileLocation, "gte.ini");
                }
            }

          //Check for read-only status; it will mean that opened sourcefile
          //was not properly taken out ot source controll, or tha somebody
          //else have it for edit
           hdoc = Gte_GetActiveDocument();
           if(hdoc == NULL) {
              MsgBox("Cannot get handle of the active document!", MB_OK);
              return 1;
           }
           // check if document is read only
           if(Gte_IsReadOnly(hdoc)) {
              MsgBox("Document is read only! Check file ownership and status in version controll system!", MB_OK);
           }

       }
   }
    else // requested file is not accessible on local disk
   {

      WritePrivateProfileString("Remote", "LastBADTakeOutFileName", g_szFileName, "gte.ini");
      //
      // TakeOut file again: calling this function aggain
      // Is this thing re-entrant? Can a function call itself?

      // MsgBox("TakeOut Error: Cannot access requested file", MB_OK);

      strcpy(g_szDebug, "TakeOut Error: Cannot access ");
      strcat(g_szDebug, szCmdLine);
      strcat(g_szDebug, " Try again?");

      if (MsgBox(g_szDebug ,MB_YESNO | MB_ICONQUESTION) == IDYES)
      {
       TakeOut();
      }

   }
}

/*-------------------------------------------------------------------
                         MakeDir

  The MakeDir function creates a new directory. Directory can end in
  / or \ and if some subdir does not exist it will be created

  Returns TRUE on success, FALSE on error.
-------------------------------------------------------------------*/

BOOL MakeDir(const char *pszDir)
{
   char szOldDir[FILENAME_MAX];
   char szSubdirList[FILENAME_MAX+1];
   char szDirReceived[FILENAME_MAX+1];
   char szMkDir[FILENAME_MAX+1];
   char *psz;

   if(pszDir == NULL || *pszDir == 0) {
      return FALSE;
   }

   getcwd(szOldDir, FILENAME_MAX);

   // copy pszDir into szSubdirList and replace \ and / with null
   // terminator. At the end we will have list of directory components
   // terminated with two null terimator characters
   strcpy(szSubdirList, pszDir);
   strcpy(szDirReceived, pszDir);

   psz = szSubdirList;
   while(*psz)
   {
      if(*psz == '/' || *psz == '\\')
      {
         // do not remove \, /, \\ and // from begin of string (network disk)
         if(psz == szSubdirList)
         {
            if(*(psz+1) == '\\' || *(psz+1) == '/')
               psz++;
         }
         else
         {
            if(psz == szSubdirList+2 && *(psz-1) == ':')
            {
               // do not remove \ in 'c:\'
            }
            else
              *psz = 0;
         }
      }
      psz++;
   }
   *psz = 0; // second null terminator

   // Contact directory components and try to make dir
   // During while loop szMkDir will be "c:\dir1", "c:\dir1\dir2", "c:\dir1\dir2\dir3"
   // AF: Except when is "C:\DATA\VJ\src\(*#&_$&"
   szMkDir[0] = 0;
   psz = szSubdirList;

//This is C:\DATA   MsgBox(szSubdirList, MB_OK);

   while(*psz != 0)
   {
      strcat(szMkDir, psz);
      // if dir does not exist create it
      if(chdir(szMkDir) != 0) {
         if(mkdir(szMkDir) != 0)
         {                                        // Fail point

                    MsgBox(szDirReceived, MB_OK);

                    strcpy(g_szDebug,"Last psz cat to szMkDir -->");
                    strcat(g_szDebug, psz);
                    strcat(g_szDebug, "<--");
                    MsgBox(g_szDebug, MB_OK);       //  --#||  (psz gets garbage!!!)

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


                    strcpy(g_szDebug,"Error Trying to MD -->");
                    strcat(g_szDebug, szMkDir);
                    strcat(g_szDebug, "<--");
                    MsgBox(g_szDebug, MB_OK);       //  C:\Data\VJ\src...and then full screen of garbage....
                                                    //  C:\Data\VJ\src\#||


                    MsgBox(szOldDir, MB_OK);


            chdir(szOldDir);
            return FALSE;
         }
      }
      strcat(szMkDir, "\\");

      psz += strlen(psz) + 1;
   }

   // return original directory
   chdir(szOldDir);

   return TRUE;
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
                    ReplaceNonDOSchar
-------------------------------------------------------------------*/

void ReplaceNonDOSchar(char *psz)
{
   while(*psz)
   {
      if(*psz == '?')
         *psz = '-';
      if(*psz == ':')
         *psz = '-';
      if(*psz == '*')
         *psz = '-';
      if(*psz == '\"')
         *psz = '-';
      if(*psz == '<')
         *psz = '-';
      if(*psz == '>')
         *psz = '-';
      if(*psz == '|')
         *psz = '-';

      psz++;
   }
}


//*********************************************************************
void NextTodoFile(char *pszFile)
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

   MsgBox(pszFile, MB_OK);
   hDoc = pszFile;

   if(hDoc == NULL) {
      MsgBox("Filename passed to NexToDo is NULL", MB_OK);
      return;
   };

    NumOfLines = Gte_GetNumberOfLines(pszFile);

    if (NumOfLines == 0){
      MsgBox("NumOfLines is empty!!!!!", MB_OK);
      return;
    };

    if (NumOfLines < 1){
      MsgBox("NumOfLines in file is less then 1. File is empty", MB_OK);

    };


    if (NumOfLines > 0){
      MsgBox("NumOfLines is more than 0.", MB_OK);

    };


//    strcpy(g_szDebug, NumOfLine);

//      MsgBox(NumOfLines, MB_OK);

// Const arg to non cont pointer:
//     Gte_GetLine(hDoc, NumOfLines, szLine, sizeof(szLine));
//     Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));
//     MsgBox(szLine, MB_OK);

        lLineNumber = 1;
        MsgBox(szLine, MB_OK);

      //read one line from file into szLine
// int Gte_GetLine(HDOC hDoc, long lLineNumber, char * pszBuf, unsigned nBufSize)
//    Gte_GetLine(hDoc, 1, szLine, sizeof(szLine));

      Gte_GetLine(hDoc, lLineNumber+1, * szLine, sizeof(szLine));
//*      Gte_GetLine(hDoc, lLineNumber+1, pszFile, sizeof(pszFile));
//      Gte_GetLine(hDoc, i+1, szLine, sizeof(szLine));


    MsgBox(szLine, MB_OK);

   return;


//    for(i = 0; i < Gte_GetNumberOfLines(hDoc); i++)
    for(i = 0; i < NumOfLines; i++)
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
void NextToDoFile2(HDOC hdoc)
//*********************************************************************
{
   int  nWordWrapCol;
   char *pszLine;
   long lLine;
   char szCmdLine[1024];

  return;

//   nWordWrapCol = Gte_GetWordWrapCol();

   // reserve memory for line
   pszLine = (char *)malloc(Gte_GetMaxLineLen()+1);
   if(pszLine == NULL) {
      MsgBox("Not enought memory", MB_OK);
      return;
   }


//   strcpy(szCmdLine, "c:\\progra~1\\GDWedit\\");
//   strcat(szCmdLine, "VJ_todo.log");

   strcpy(szCmdLine, "VJ_todo.log");

   if(access(szCmdLine, 0) == 0)
   {
        hdoc = szCmdLine;
   }
   else
   {
      strcat(szCmdLine, " does not exist");

      MsgBox(szCmdLine, MB_OK);
      return;
   }



   // Show wait mouse cursor (hourglass)
   WaitCursor();

   // for each line in the document (be careful we must always call
   // Gte_GetNumOfLines because number of lines in the document will
   // be probably increased in the loop)
   for(lLine = 1; lLine <= Gte_GetNumberOfLines(hdoc); lLine++)
   {

         if(MsgBox("in for ...",
            MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
         {
            return;
         }


//        Gte_SetCursorPos(hdoc, 1, lLine, FALSE);
//        Gte_SetCursorPos(hdoc, 1, lLine+1, FALSE);
//        Gte_SetCursorPos("VJ_todo.log",1, lLine, FALSE);

//      if(Gte_GetLineLen(hdoc, lLine, FALSE) > nWordWrapCol)
        if ( 1 == 1 )
      {
         char *psz;
//         int  nWrapAtCol = 0; // insert new line at this column pos


         MsgBox("before getline...", MB_OK);
//         Gte_GetLine(hdoc, lLine, pszLine, Gte_GetMaxLineLen()+1);
//OKOKOK     Gte_GetLine("c:\\progra~1\\GDWedit\\VJ_todo.log", lLine+1, pszLine, Gte_GetMaxLineLen()+1);

//ok     Gte_GetLine("VJ_todo.log", lLine+1, pszLine, 10);
          Gte_GetLine( szCmdLine, lLine+1, pszLine, 10);
//         Gte_GetLine(hdoc, lLine+1, pszLine, sizeof(pszLine));
//         Gte_GetLine(hdoc, 1, pszLine, 5);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
//         Gte_GetLine(hdoc, 1, pszLine, Gte_GetMaxLineLen()+1);
         MsgBox("after getline...", MB_OK);
         psz = pszLine;


//

         MsgBox(psz, MB_OK);
         MsgBox(pszLine, MB_OK);
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

   RestoreCursor();

   free(pszLine);
}


//###################################################################
void LocationMenu(void)
//###################################################################
{

    char Counter[2];
    char *psz;

/*
   Vedran, how to put NULL into g_Menu1-20?

   g_Menu1 = 0;
   g_Menu2 = 0;
   g_Menu3 = 0;
   g_Menu4 = 0;
   g_Menu5 = 0;
*/

   psz = g_Menu4;
   *psz = 0; // second null terminator
//    strcpy(g_Menu5,psz);

{
    int argc;
    char *argv[];
    int i;
    char szFileNameFav[FILENAME_MAX];
    char FavoriteRemoteList[200];
    char szRemoteTakeOutLocationFav[MAX_FILE_LOCATION];
    char szRemoteInitDirFav[MAX_INIT_DIR];
	char szIniEntry[8];


   for(i = 0; i < MAX_FAVORITE_FILES; i++)
	{
      sprintf(szIniEntry, "%d", i+1);
      GetPrivateProfileString("FavoriteRemoteFiles", szIniEntry, "", szFileNameFav, FILENAME_MAX, "gte.ini");
      if(szFileNameFav[0] == 0)
	      break;
//	   Gte_OpenDocument(szFileName);

      GetPrivateProfileString("FavoriteRemoteInitDir", szIniEntry, "", szRemoteInitDirFav, MAX_INIT_DIR, "gte.ini");
      GetPrivateProfileString("FavoriteRemoteTakeOutLocation", szIniEntry, "", szRemoteTakeOutLocationFav, MAX_FILE_LOCATION, "gte.ini");

      strcpy(Counter, szIniEntry);
/*
      strcpy(g_szDebug, "--");
      strcat(g_szDebug, Counter);
      strcat(g_szDebug, "--");
      strcat(g_szDebug, Num1);
      strcat(g_szDebug, "--");

      MsgBox(g_szDebug, MB_OK);
*/
      if(strcmpi(Counter, "1"))
      {
      }
      else
      {
        strcpy (g_Menu1,szRemoteInitDirFav);
        strcat (g_Menu1,szRemoteTakeOutLocationFav);

        strcpy (g_Init1,szRemoteInitDirFav);
        strcpy (g_Location1,szRemoteTakeOutLocationFav);

      }

      if(strcmpi(Counter, "2"))
      {
      }
      else
      {
        strcpy (g_Menu2,szRemoteInitDirFav);
        strcat (g_Menu2,szRemoteTakeOutLocationFav);
        strcpy (g_Init2,szRemoteInitDirFav);
        strcpy (g_Location2,szRemoteTakeOutLocationFav);

      }


      if(strcmpi(Counter, "3"))
      {
      }
      else
      {
        strcpy (g_Menu3,szRemoteInitDirFav);
        strcat (g_Menu3,szRemoteTakeOutLocationFav);
        strcpy (g_Init3,szRemoteInitDirFav);
        strcpy (g_Location3,szRemoteTakeOutLocationFav);

      }


      if(strcmpi(Counter, "4"))
      {
      }
      else
      {
        strcpy (g_Menu4,szRemoteInitDirFav);
        strcat (g_Menu4,szRemoteTakeOutLocationFav);
        strcpy (g_Init4,szRemoteInitDirFav);
        strcpy (g_Location4,szRemoteTakeOutLocationFav);

      }

      if(strcmpi(Counter, "5"))
      {
      }
      else
      {
        strcpy (g_Menu5,szRemoteInitDirFav);
        strcat (g_Menu5,szRemoteTakeOutLocationFav);
        strcpy (g_Init5,szRemoteInitDirFav);
        strcpy (g_Location5,szRemoteTakeOutLocationFav);

      }

      if(strcmpi(Counter, "6"))
      {
      }
      else
      {
        strcpy (g_Menu6,szRemoteInitDirFav);
        strcat (g_Menu6,szRemoteTakeOutLocationFav);
        strcpy (g_Init6,szRemoteInitDirFav);
        strcpy (g_Location6,szRemoteTakeOutLocationFav);

      }
      if(strcmpi(Counter, "7"))
      {
      }
      else
      {
        strcpy (g_Menu7,szRemoteInitDirFav);
        strcat (g_Menu7,szRemoteTakeOutLocationFav);
        strcpy (g_Init7,szRemoteInitDirFav);
        strcpy (g_Location7,szRemoteTakeOutLocationFav);

      }
      if(strcmpi(Counter, "8"))
      {
      }
      else
      {
        strcpy (g_Menu8,szRemoteInitDirFav);
        strcat (g_Menu8,szRemoteTakeOutLocationFav);
        strcpy (g_Init8,szRemoteInitDirFav);
        strcpy (g_Location8,szRemoteTakeOutLocationFav);

      }
      if(strcmpi(Counter, "9"))
      {
      }
      else
      {
        strcpy (g_Menu9,szRemoteInitDirFav);
        strcat (g_Menu9,szRemoteTakeOutLocationFav);
        strcpy (g_Init9,szRemoteInitDirFav);
        strcpy (g_Location9,szRemoteTakeOutLocationFav);

      }
      if(strcmpi(Counter, "10"))
      {
      }
      else
      {
        strcpy (g_Menu10,szRemoteInitDirFav);
        strcat (g_Menu10,szRemoteTakeOutLocationFav);
        strcpy (g_Init10,szRemoteInitDirFav);
        strcpy (g_Location10,szRemoteTakeOutLocationFav);

      }

    }

}

   GetPrivateProfileString("Remote", "LastTakeOutLocation", "", g_szFileLocation, sizeof(g_szFileLocation), "gte.ini");
   GetPrivateProfileString("Remote", "ServerInitDir", "", g_szServerInitDir, sizeof(g_szServerInitDir), "gte.ini");

    strcpy (g_szDebug,"Previous location: ");
    strcat (g_szDebug,g_szServerInitDir);
    strcat (g_szDebug,g_szFileLocation);

   // List box used as a menu
   //   while(TRUE)
   {
      char *pMenu[] =
    {
            g_szDebug,
            "New location",
            g_Menu1,
            g_Menu2,
            g_Menu3,
            g_Menu4,
            g_Menu5,
            g_Menu6,
            g_Menu7,
            g_Menu8,
            g_Menu9,
            g_Menu10,

         NULL
      };
      int  nIdx;

      nIdx = Gte_ListBoxDlg("Choose Location", pMenu);
      if(nIdx == 0)
        {
        strcpy(g_FavNum,"EXIT");
        return; //         break;
        }

      switch(nIdx)
      {
         case 1: strcpy(g_FavNum,"PREV"); return; //break;         //Previous location
         case 2: strcpy(g_FavNum,"NEW"); return; //break;          //New location
         case 3: strcpy(g_FavNum,"1"); return;//break;
         case 4: strcpy(g_FavNum,"2"); return;//break;
         case 5: strcpy(g_FavNum,"3"); return;//break;
         case 6: strcpy(g_FavNum,"4"); return;//break;
         case 7: strcpy(g_FavNum,"5"); return;//break;
         case 8: strcpy(g_FavNum,"6"); return;//break;
         case 9: strcpy(g_FavNum,"7"); return;//break;
         case 10: strcpy(g_FavNum,"8"); return;//break;
         case 11: strcpy(g_FavNum,"9"); return;//break;
         case 12: strcpy(g_FavNum,"10"); return;//break;
      }
   }

//     MsgBox(g_FavNum, MB_OK);


}
//###################################################### LocationMenu()

//############################################################### EOF



