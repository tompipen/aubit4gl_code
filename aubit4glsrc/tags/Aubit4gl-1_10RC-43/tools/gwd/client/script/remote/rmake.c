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
#define MAX_SOURCE_FILES   20	// num of sourcefiles to be compiled and checked for errors
#define MAX_SOURCE_TYPES   3	// num of sourcefile types to be compiled checked for errors
  
// global variables
char g_szSysName[MAX_CMDLEN];





















// function prototypes
void ScriptMain (HDOC);








//#######################################################
  int
main (int argc, char *argv[]) 
//#######################################################
{
  
  
  
    
    {
      
      
    
  
    // check file extension
    // This is important because if we do not have a handle for correct
    // document (the one that is the most probable to cause compile error)
    // we will not be able to close it before opening .err file, so we will
    // have the "Another app have modified ... reload?" question.
    // This is not realy what I want, but GWD cannot make a handle from
    // filename, or close a document based on filename.
    
  {
    
    
      // if document does not have file ext, empty string will be returned
      if (szFileExt[0] != 0)
      
      {
	
	     || stricmp (szFileExt, "per") == 0
	     || 
	     || stricmp (szFileExt, "m") == 0
	     || 
	     || stricmp (szFileExt, "5gl") == 0)
	  
	  {
	    
	      // ok
	  }
	
	else
	  
	  {
	    
	    
	    
	    
	    
	  
      
  
  
    // call main script function
    ScriptMain (hDoc);
  
    // warning: document may be closed in the Compile function
    return 0;



//############################################################
  void
ScriptMain (HDOC hDoc) 
//############################################################
{
  
    // Check for compiler error lines
    RemoveCompilerErrorLines (hDoc);
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    
  
    
    {
      
      
    
  
    // get 4gl type
    g_n4glVer =
    GetPrivateProfileInt ("Remote", "4GLVersion", 0, "remote.ini");
  
    
    {
      
      
    
  
    
    {
    
      MsgBox ("Make for DOS not implemented", MB_OK);
      
    
      Make4glWin (hDoc);
      
    
      MsgBox ("Make for remote Informix 4GL not implemented", MB_OK);
      
    
      break;
    
      break;
    
      Make4glWin (hDoc);
      
    
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "MakeCmd", "", g_szMakeCmd,
			     sizeof (g_szMakeCmd), "remote.ini");
  
			    sizeof (g_szClientInitDir), "remote.ini");
  
			    sizeof (g_szServerName), "remote.ini");
  
			    sizeof (g_szUserName), "remote.ini");
  
			    sizeof (g_szPassword), "remote.ini");
  
			    sizeof (g_szTransport), "remote.ini");
  
    // Get site specific location of bat files
    GetPrivateProfileString ("Remote", "Site", "", g_szSite,
			     sizeof (g_szSite), "remote.ini");
  
  
    // check configuration parameters and ask for them is necessary
    if (strlen (g_szMakeCmd) == 0)
    {
      
	   ("Make command", "&Make command:", 
	    sizeof (g_szMakeCmd)) == FALSE)
	
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
				 "remote.ini");
      
	
				  g_szFileLocation, g_szFileLocation,
				  sizeof (g_szFileLocation), "takeout.ini");
      
				 g_szFileName, sizeof (g_szFileName),
				 "remote.ini");
      
	
				  g_szFileName, g_szFileName,
				  sizeof (g_szFileName), "takeout.ini");
      
				 g_szServerInitDir, g_szServerInitDir,
				 sizeof (g_szServerInitDir), "takeout.ini");
      
	// Check if this is the right file
	strcpy (szTakeOutFile, g_szClientInitDir);
      
      strcat (szTakeOutFile, g_szFileLocation);
      
      
      
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
	  
	
    
  
  else
    
    {
      
      
      
      
      {
	
	
	
	
      
      
	//BaseName(g_szFileName);
	
      strcpy (g_szFileLocation, "x");	// dummy placeholder
    }
  
    // Compile file
    Compile (hDoc);
  



//  Warning: This function may close hDoc document
//######################################################
  void
Compile (HDOC hDoc) 
//######################################################
{
  
  
  
  
  
  
    
    {
      
	// Ask for filename/progname, user may want to make something other
	// then currently open doccument
	if (Gte_GetStringDlg
	    ("File or program to Make", "&Name (4gl/5gl/per/m/toc/42r):",
	     g_szFileName, 
	
	{
	  
	    // user click Cancel
	    return;
	
    
  
  
  
  
  
  
    //if the file is under /home/users/,it does not belong to any program system, otherwise
    // ask for Area name to do environment switching
    {
      
	// read previous Area name form ini file
	GetPrivateProfileString ("Remote", "LastArea", "", g_szArea,
				 sizeof (g_szArea), "remote.ini");
      
	    ("Area name", "&Area name:", g_szArea,
	     
	
	{
	  
	    // user click Cancel
	    return;
	
      
	// write last Area name to ini file
	WritePrivateProfileString ("Remote", "LastArea", g_szArea,
				   "remote.ini");
      
	// ask for system name: needed to set environment for compiler, like DBPATH
	// depending on program system
	
	// read previous system name form ini file
	GetPrivateProfileString ("Remote", "LastSysRun", "", g_szSysName,
				 sizeof (g_szSysName), "remote.ini");
      
	    ("System name", "&System name:", g_szSysName,
	     
	
	{
	  
	    // user click Cancel
	    return;
	
      
	// write last system name to ini file
	WritePrivateProfileString ("Remote", "LastSysRun", g_szSysName,
				   "remote.ini");
    
  
  else
    
    {
      
    
  
    //------------------------------- Change current dir to GWD editor dir
    
  
    //------------------------------- Batch file name
    
  strcat (szCmdLine, g_szGWDdir);
  
  
  
  
  
  
    //------------------------------- System name
    
  
    
  
  
    
  
  
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
    
    
  
  
    
  
  
    // Remove Disk label an semiclolon from clinets path
    // because of problems with Microsoft rcp.exe
    strcpy (TMPg_szClientInitDir, g_szClientInitDir);
  
  
    {
      
	{
	  
	  
	
    
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
  
    
  
    
  
  
  
    
  
  
    // UNIX FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    // NT FileLocation
  {
    
    
    
    
      
    
    
      
    
  
  
    
  
  
    
  
    //--------------------------- output file
    strcpy (g_pszOutputFile, szDocFileName);
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
    //---------------------------- message on Execute Tool Window
    
  
    // strcat (pszActionDisplay, szDocFileName);
    strcat (pszActionDisplay, g_szSysName);
  
  
  
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
    WaitCursor ();
  
    //system(szCmdLine);
    Gte_ExecuteTool (szCmdLine, g_pszOutputFile, pszActionDisplay,
		     szCmdLine_param);
  
  
    // Check for errors
    
    
    {
      
	// with RCP transport, all error checking and opening of .err
	// files is done in .bat file
      char szErrorFile[50];
      
      
	
	{
	  
	  
	
      
      else
	
	{
	  
		   MB_OK | MB_ICONINFORMATION);
	  
	    // position to the first error line of last opened document
	    
	  
	  
	    // delete error detection flag file
	    remove (szErrorFile);
	
    
  
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
	
	
	
	
	
	
	
	
	
	
	
	
	  // strcpy (szMakeErr, "c:\\progra~1\\GWD\\bat\\CSI\\MakeErr.ini");
	  strcpy (szMakeErr, g_szGWDdir);
	
//       strcat(szMakeErr, "bat");
//       strcat(szMakeErr, "\\");
//       strcat(szMakeErr, g_szSite);
//       strcat(szMakeErr, "\\MakeErr.ini");
	  strcat (szMakeErr, "MakeErr.ini");
	
	  
	  {
	    
	    return;
	  
	
	  //Get the full name of current active doc.
	  Gte_GetFileName (hDoc, szNowOpen, sizeof (szNowOpen));
	
	  //####################
	  for (i = 0; i < 5; i++)
	  
	    //####################
	  {
	    
	    
				      FILENAME_MAX, szMakeErr);
	    
	      
	    
				      FILENAME_MAX, szMakeErr);
	    
				      FILENAME_MAX, szMakeErr);
	    
	    
	    
	    
	    strcat (szErrFile, szPath);
	    
	    
	    
	    
	    
	    
	    
	      
	    
	    
	      {
		
		  ("ERROR: This file does not have file extension! Unable to continue",
		   MB_OK);
		
	      
	    
	    
	    
	      
	      {
		
		
		
		
		
		  
		  {
		    
		  
		
		
		  
		  {
		    
		  
		
	      
	    
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
	      
	    
	      {
		
	      
	    
	      // remove filename.bak
	      remove (szBackupFile);
	    
	      // rename this file to bak
	      rename (szDocFileName, szBackupFile);
	    
	      // rename err file to this file
	      rename (szErrFile, szDocFileName);
	    
	      // open it
	      hDoc = Gte_OpenDocument (szDocFileName);
	    
	      // position to the first error line
	      if (stricmp (szExt, "4gl") == 0)
	      
	      {
		
		  // 4, 4 in Gte_find is to skip over first 3 lines inserted only by Windows 4GL compiler
		  // position to the first error line
		  Gte_Find (hDoc, "^\\|", 4, 4, FALSE, FALSE, TRUE, TRUE);
	      
	    
	      
	      {
		
		  {
		    
		  
		
		else
		  
		  {
		    
		  
	      
	  
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
  void
RemoveCompilerErrorLines (HDOC hDoc) 
//#####################################################################
{
  
    // remember cursor position (this is not necessary, but it is user friendly)
    GM_SaveCursorPos (hDoc);
  
    // to speed up macro disable screen update
//    Gte_LockUpdate(hDoc);
    
    
    {
      
	// first check if we have compiler error lines
	// compiler error lines in 4gl begins with | character
	if (Gte_Find (hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
	
	{
	  
	  
	    
	    {
	      
		   0)
		
		{
		  
		  
		
	      
	      
	    
	
    
  
    
    {
      
	// first check if we have compiler error lines
	// compiler error lines in per(DOS) begins with # character
	if (Gte_Find (hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
	
	{
	  
	  
	    
	    {
	      
		
		{
		  
		  
		
	      
	      
	    
	
    
  
    // Unlock screen update
//      Gte_UnlockUpdate(hDoc);
    // restore cursor position from stack
    GM_RestoreCursorPos (hDoc);
  
    // scroll window if necessary to make cursor visible
    Gte_FixWindowPos (hDoc);



//#####################################################################
  void
UnixPathToDosPath (char *psz) 
//#####################################################################
{
  
    
    {
      
	
      
    



//#####################################################################
  void
DosPathToUnixPath (char *psz) 
//#####################################################################
{
  
    
    {
      
	
      
    



//#####################################################################
  void
BaseName (char **ppsz) 
//#####################################################################
{
  
// Yes, it is a mess, but this works
  char *pszslash;
  
    
      
      {
	
      



//#####################################################################
  void
Make4glWin (HDOC hDoc) 
//#####################################################################
{
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    // determine if we are using some form of make and makefile,
    // or we are going file by file with .TOC ini file
    // can be MAKE or TOC
    strcpy (szMakeType, "MAKE");
  
    {
      
    
  
  else
    
    {
      
    
  
  {
    
      // ex: strcpy(szWorkPath, "c:\\prg\\job_post");
      
    
    
      
    
      
      {
	
	
      
    
      //strcpy(psz+1, ""); // This will leave trailing backslash at the end
      strcpy (psz, "");		// This will NOT leave trailing backslash at the end
    // MsgBox(szWorkPath, MB_OK);
  
  
    // actually, name of expected executable after make,
    // and the name of the TOC file
    //   strcpy(szProject, "job_post");
    strcpy (szProject, "perorg");
  
  
  
  
  
  
    // Paths for source, forms and resulting executables can be different then current:
    // WARNING ! THIS IS NOT USSED AT PRESENT, and should be used !
    GetPrivateProfileString ("Project", "SourcePath", "", szSourcePath,
			     FILENAME_MAX, szTOC);
  
			    FILENAME_MAX, szTOC);
  
			    FILENAME_MAX, szTOC);
  
    {
      
    
  
  else
    
    {
      
    
  
  
  
    // rename target if exists
    if (access (szTargetName, 0) == 0)
    
    {
      
	
	{
	  
	    // remove old target backup
	    remove (szBackupTarget);
	
      
    
  
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
    
  
  
  
  
  
  
    /*
       strcpy (szCmdLine, "c:\\progra~1\\gwd\\");
       strcat (szCmdLine, "gtecap32.exe ");
       strcat (szCmdLine, pszOutputFile);
     */ 
    
  
    {
      
	// just 'make' will do in the current dir, with default makefile
    }
  
  else
    
    {
      
      
      
      
      
      
	//   strcat (szCmdLine, szTargetName);
	strcat (szCmdLine, szProject);
      
      
      
	/*
	   strcpy (szCmdLine, "pembld ");
	   strcat (szCmdLine, szWorkPath);
	   strcat (szCmdLine, " ");
	   strcat (szCmdLine, szProject);
	   strcat (szCmdLine, " 4gi bld");
	 */ 
    
  
    
    {
      
	// If we are NOT using MAKE...will step file-by-file
    }
  
  else
    
    {
      
	// If using MAKE, run it now
	WaitCursor ();
      
//   if(MsgBox(szCmdLine, MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON1) == IDYES)
//   {
	// system(szCmdLine);
	
	// int Gte_ExecuteTool(const char * pszCmdLine,
	// const char * pszOutputFile, const char * pszPrgName, const char * pszArg)
	
//   }
      RestoreCursor ();
    
  
  
  {
    
      // ###############################################
      // Compile file by file and/or Check error files
      // ###############################################
    int i;
    
    
    
    
      
      {
	
	  
	  {
	  
	    
	    strcpy (szFindErr, "^\\|");
	    
	      {
		
	      
	    
	    else
	      
	      {
		
	      }
	    
	    break;
	  
	    
	    
	      {
		
		
	      }
	    
	    else
	      
	      {
		
		
	      }
	    
	    break;
	  
	    
	    break;		// end of sourcefile types list
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
	  
	  
	  {
	    
	      //###################################
	      for (i = 0; i < MAX_SOURCE_FILES; i++)
	      
		//###################################
	      {
		
		
					   szSourceFile, FILENAME_MAX, szTOC);
		
		  
		
		  // WARNING ! should use szSourcePath, szFormsPath and szExecPath
		  // retrived from .toc before !
		  
		
		
		
		
		
		
		
		strcat (szErrorFile, ".err");
		
		
		strcat (szBackupFile, ".bak");
		
		
		
		
		
		  
		  {
		    
		      // NOT using MAKE, compile file-by-file first...
		      strcpy (pszActionDisplay, "Compiling");
		    
		    
		    
		    
		    
		      //  WinExec(szCmdLine, 1); // Does not wait for app to finnish...no can do!
		      // (otherwise works, without "ix" )
		      Gte_ExecuteTool (szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);	//" Args...");
		    //        c:\informix\bin\errchkr c:\prg\job_post\job_post.4gl
		  }
		
		  // make or file-by-file, we will check for errors now:
		  if (access (szErrorFile, 0) == 0)	// Error file exist
		  {
		    
		    
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
		      
		      
		      
			{
			  
			
		    
		    
		      // remove filename.bak - old backup
		      // MsgBox(szBackupFile, MB_OK | MB_ICONINFORMATION);
		      remove (szBackupFile);
		    
		      // rename this source file to bak
		      /*
		         strcpy (g_szDebug,szFileName);
		         strcat (g_szDebug,"-");
		         strcat (g_szDebug,szBackupFile);
		         MsgBox(g_szDebug, MB_OK | MB_ICONINFORMATION);
		       */ 
		      rename (szFileName, szBackupFile);
		    
		      // rename err file to this file
		      /*
		         strcpy (g_szDebug,szErrorFile);
		         strcat (g_szDebug,"-");
		         strcat (g_szDebug,szFileName);
		         MsgBox(g_szDebug, MB_OK | MB_ICONINFORMATION);
		       */ 
		      rename (szErrorFile, szFileName);
		    
		      // how can I check if this file is already opened in GWD,
		      // to prevent message "Another app has updated .... reload?"
		      
		      //MsgBox(szFileName, MB_OK | MB_ICONINFORMATION);
		      
		      // open it
		      hDoc = Gte_OpenDocument (szFileName);
		    
		      //Gte_SetActiveDocument(hDoc);
		      
		      // 4, 4 in Gte_find is to skip over first 3 lines:
		      // |
		      // |    Source File : c:\prg\job_post\job_post.4gl
		      // |
		      // position to the first error line
		      Gte_Find (hDoc, szFindErr, 4, 4, FALSE, FALSE, TRUE,
				TRUE);
		  
		
		  
		    // check also for wrn warning files for per sourcefiles in 4gl for windows only!!
		  {
		    
		      {
		      
		    
		    else
		      
		      {
			
			  {
			    
			      //strcpy(szSuccess,"N");  // set success flag to N
			      // open it
			      hDoc = Gte_OpenDocument (szFileName);
			  
		      
		  
	      
	    
	    else		//szExt = "xxx", sourcefiles types list exspusted
	    {
	      
	    
	  
      
    
      {
	
	  // MsgBox("Err file(s) found!", MB_OK | MB_ICONINFORMATION);
      }
    
    else
      
      {
	
	  
	  {
	    
	      // Link object file
	      
	      {
		
		  // fgllink -o target.42r 1.42m 2.42m ... etc.
	      }
	    
	    else
	      
	      {
		
		  // 4gl for Windows: I must step one-by-one because dos command line
		  // length is limmited
		int i;
		
		
		
		
		
		
					   FILENAME_MAX, szTOC);
		
		
		
		
		
		
		
		
		
		
		
		
		  //    copy /b c:\prg\job_post\job_glob.4go job_post.4gi
		  //      Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);
		  system (szCmdLine);
		
		
		  
		  {
		    
		    
					       szSourceFile, FILENAME_MAX,
					       szTOC);
		    
		      
		    
		    
		    
		    
		    
		    
		    
		    
		    strcat (szCmdLine, " ");
		    
		    
		    
		    
		    
		      // Gte_ExecuteTool(szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);
		      // copy /b job_post.4gi+c:\prg\job_post\job_main.4go job_post.4gi
		      system (szCmdLine);
		    
		  
	      
	  
	
	  {
	    
	      // MsgBox("Linking failed, Target not generated!", MB_OK | MB_ICONINFORMATION);
	      if (MsgBox
		  ("Linking failed, Target not generated! Do you want to examine build log?",
		   
	      
	      {
		
		
		
		
		
	      
	    
	    else
	      
	      {
		
	      
	  
	
	else
	  
	  {
	    
	    
	  
      
    
  



//#################################################
  HDOC GetHandleForFileName (const char *pszFileName) 
//#################################################
// This function will return hDoc for filename or null if that doc is not
// open at all.
// Function Gte_GetFileName returns file name if we know its hDoc
// Gte_GetActiveDocument returns hDoc of active document
// Macro GM_NextWindow(hDoc) sets nex doc to be active
  
{
  
  
  
  
  
    
  
// MsgBox("1", MB_OK);
    
// Gte_GetFileName(hDoc, szActiveFileName, FILENAME_MAX); // hang
    
    //MsgBox("1x", MB_OK);
    
    
    {
      
// MsgBox("1a", MB_OK);
	
	
// MsgBox("1b", MB_OK);
	  return hDocFirst;
    
  
// MsgBox("2", MB_OK);
    
  
  
    //######################################
    while (hDoc != NULL && hDoc != hDocFirst)
    
// original  while(hDoc !+ NULL && hDoc != hDocFirst)
//  while(hDoc !+ NULL)  //  && hDoc != hDocFirst
//    while(hDoc != NULL)  //  && hDoc != hDocFirst OK
//  while(TRUE) OK
//   while( (hDoc !+ NULL) && (hDoc != hDocFirst) )
//   while( (hDoc != hDocFirst) ) OK
      
      //######################################
      
    {
      
// MsgBox("x", MB_OK);
	
      
	
      
	
	{
	  
	    
	
      
      
    
  



//////////////////////////////////////////////////////////////// EOF