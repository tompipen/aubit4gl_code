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
#include <time.h>		// for GWD open patch
  
#define WM_COMMAND      0x0111	// for _GWD_CloseDoccument
  
#define MAX_CMDLEN         20
#define MAX_INIT_DIR       80
#define MAX_SERVER_NAME    80
#define MAX_USER_NAME      80
#define MAX_PASSWORD       80
#define MAX_FILE_LOCATION  80
#define MAX_FILE_NAME      80
  
// global variables
char g_szSysName[MAX_CMDLEN];



















// function prototypes
void ScriptMain (HDOC);







// void BaseName(char *);
void BaseName (char **ppsz);



//##################################################################
  int
main (int argc, char *argv[]) 
//##################################################################
{
  
  
  
    {
      
      
    
  
    // check file extension
  {
    
    
      // if document does not have file ext, empty string will be returned
      if (szFileExt[0] != 0)
      
      {
	
	  {
	    
	      // call main script function
	      ScriptMain (hDoc);
	  
	
	else
	  
	  {
	    
	      ("Error: To compile, activate doccument window of 4GL or PER file",
	       MB_OK);
	    
	  
      
  
  
    // warning document may be closed in the Compile function
    return 0;



//##################################################################
  void
ScriptMain (HDOC hDoc) 
//##################################################################
{
  
    // Check for compiler error lines
    RemoveCompilerErrorLines (hDoc);
  
    // Save file if is modified
    if (Gte_IsModified (hDoc))
    
  
    
    {
      
      
    
  
    // read configuration from ini file
    GetPrivateProfileString ("Remote", "MakeCmd", "", g_szMakeCmd,
			     sizeof (g_szMakeCmd), "remote.ini");
  
			    sizeof (g_szServerInitDir), "remote.ini");
  
			    sizeof (g_szClientInitDir), "remote.ini");
  
			    sizeof (g_szServerName), "remote.ini");
  
			    sizeof (g_szUserName), "remote.ini");
  
			    sizeof (g_szPassword), "remote.ini");
  
			    sizeof (g_szTransport), "remote.ini");
  
    // Get site specific location of bat files
    GetPrivateProfileString ("Remote", "Site", "", g_szSite,
			     sizeof (g_szSite), "remote.ini");
  
  
    GetPrivateProfileInt ("Remote", "4GLVersion", 0, "remote.ini");
  
    // check configuration parameters and ask for them is necessary
    if (g_n4glVer == 0)
    
    {
      
      
    
  
    {
      
	   ("Make command", "&Make command:", 
	    sizeof (g_szMakeCmd)) == FALSE)
	
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
	  
	  
	
    
  
    
    {
    
      CompileDOS (hDoc);
      
    
      CompileWin (hDoc);
      
    
      break;
    
      break;
    
      break;
    
      CompileWin (hDoc);
      
    
  
    
      // from the filename and takeout.ini determine default filename and location for RCP transport
    {
      
      
      
      
      
      
				 g_szFileLocation, sizeof (g_szFileLocation),
				 "remote.ini");
      
	
				  g_szFileLocation, g_szFileLocation,
				  sizeof (g_szFileLocation), "takeout.ini");
      
				g_szFileName, sizeof (g_szFileName),
				"remote.ini");
      
	
				  g_szFileName, g_szFileName,
				  sizeof (g_szFileName), "takeout.ini");
      
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
    
  
    // Compile file
    Compile (hDoc);
  



/*-------------------------------------------------------------------
                         Compile

  Warning: This function may close hDoc document
-------------------------------------------------------------------*/ 
  
Compile (HDOC hDoc) 
{
  
  
  
  
  
  
  
    // determine progSYS name
    if (stricmp (g_szTransport, "RCP") == 0)
    
    {
      
      
	//if the file is under /home/users/, it does not belong to any program system
	if (strcmpi (g_szServerInitDir, g_szServerInitDirNoSys))
	
	{
	  
	    // read previous system name form ini file
	    GetPrivateProfileString ("Remote", "LastSysRun", "", g_szSysName,
				     sizeof (g_szSysName), "remote.ini");
	  
	    // ask for system name: needed to set envirnment for compiler, like DBPATH
	    // depending on program system
	    if (Gte_GetStringDlg
		("System name", "&System name:", g_szSysName,
		 
	    
	    {
	      
		// user click Cancel
		return;
	    
	  
	    // write last system name to ini file
	    WritePrivateProfileString ("Remote", "LastSysRun", g_szSysName,
				       "remote.ini");
	
      
      else
	
	{
	  
	    // this shoud be the name of the UNIX script that sets up the environment
	    // for program system that this file came from, like
	    // . maxdev4js /apps/max_4.00 or "40" alias for CSI for example
	    strcpy (g_szSysName, "dummy");
	
    
  
  else				// samba transport
    {
      
    
  
    
    {
      
      
	//------------------------------------ path to the source
	
	//strcpy (g_szServerInitDir,"/apps/max_4.00/repw/");
	strcpy (g_szServerInitDir, szDocFileName);
      
      
	
      
	{
	  
	  
	
      
	//strcpy(psz+1, ""); // this leaves a slash at the end
	strcpy (psz, "");	// this does NOT leave a slash at the end
      
    
  
    //------------------------------- Change current dir to GWD editor dir
    
  
    //------------------------------- Batch file name
    
  strcat (szCmdLine, g_szGWDdir);
  
  
  
  
  
  
    //----------------------- System name or dummy
    
  
    
  
  
    
  
  
    //------------------------ UNIX initial path, or full path to file if samba transport
    
    
  
  
    
  
  
    //------------------------ Local initial Path or "samba"
    
    
    {
      
	// Remove Disk label an semiclolon from clinets path
	// because of problems with Microsoft rcp.exe
	strcpy (TMPg_szClientInitDir, g_szClientInitDir);
      
      
	{
	  
	    {
	      
	      
	    
	
    
  
    
  
  
    
  
  
    //-------------------------- server name
    
    
  
  
    
  
  
    //--------------------------- user name
    
    
  
  
    
  
    //---------------------------- password
    
    
  
  
  
    
  
  
    // UNIX FileLocation relative to UNIX initial path
    // or
    // for samba, UNIX path to the source file
    
  {
    
    
    
      // this can contain a drive letter, or a network drive URL,
      // and we need to remove that:
      psz = szUnixFileLoc;
    
      {
	
	  {
	    
	    
	  
      
    
    
      
      {
	
	  
	  {
	    
	    
	      // we have removed leading two backslash-es,
	      // now, remove everithing to first next backslash,
	      // that is actualy computer name:
	      
	      
	      {
		
		  
		  {
		    
		      //*psz = '\\';
		      break;
		  
		
	      
	    
	  
      
    
    
      
    
    
      
    
  
  
    // NT FileLocation relative to initial client path or dummy for samba
    
  {
    
    
      
      {
	
      }
    
    else
      
      {
	
      
    
    
      
    
    
      
    
  
  
    //---------------------------- filename.ext
    
    
  
  
    
  
    //---------------------------- message
    
  
  
  
    //--------------------------- output file
    strcpy (g_pszOutputFile, szDocFileName);
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
// the call looks like this:
// C:\Program Files\GWD\bat\CSI>rcompile dummy /apps/max_4.00/repw/ samba chaix afalout aaa bla bla csi_p.4gl
    
  
//*
    if (MsgBox (szCmdLine, MB_YESNO | MB_ICONQUESTION) == IDNO)
    
    {
      
    
  
//*/
    WaitCursor ();
  
//   system(szCmdLine_param);
    Gte_ExecuteTool (szCmdLine, g_pszOutputFile, pszActionDisplay,
		     szCmdLine_param);
  
    // Check for errors
    ChkErr (hDoc);
  



/*-------------------------------------------------------------------
                      RemoveCompilerErrorLines
-------------------------------------------------------------------*/ 
  
RemoveCompilerErrorLines (HDOC hDoc) 
{
  
    // remember cursor position (this is not necessary, but it is user friendly)
    GM_SaveCursorPos (hDoc);
  
  
    // to speed up macro disable screen update
    Gte_LockUpdate (hDoc);
  
    
    {
      
	// first check if we have compiler error lines
	// compiler error lines in 4gl begins with | character
	if (Gte_Find (hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
	
	{
	  
	  
	    
	    {
	      
		   0)
		
		{
		  
		  
		
	      
	      
	      
		// Display progress on status bar after every 10 lines
	      {
		
		
			   "Removeing compiler error messages - Press Ctrl-Break to cancel: %0d%% completed",
			   (int) (lStartLine * 100 /
				  Gte_GetNumberOfLines (hDoc)));
		
	      
	    
	
    
  
    
    {
      
// MsgBox("per", MB_OK);
	if ((g_n4glVer == 4) || (g_n4glVer == 5))	//remote 4Js/Informix D4GL GUI  //remote 4Js/Informix D4GL CHUI
	{
	  
//  MsgBox("dos", MB_OK);
	    // first check if we have compiler error lines
	    // compiler error lines in per(DOS) begins with # character
	    if (Gte_Find (hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
	    
	    {
	      
	      
		
		{
		  
		       != 0)
		    
		    {
		      
		      
		    
		  
		  
		
	    
	
      
      else
	
	{
	  
// MsgBox("D4gl", MB_OK);
	    // first check if we have compiler error lines
	    // compiler error lines in per(D4GL) begins with | character
	    if (Gte_Find (hDoc, "^\\|", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
	    
	    {
	      
	      
		
		{
		  
		       != 0)
		    
		    {
		      
		      
		    
		  
		  
		
	    
	
    
  
    // Unlock screen update
    Gte_UnlockUpdate (hDoc);
  
  
    // restore cursor position from stack
    GM_RestoreCursorPos (hDoc);
  
    // scroll window if necessary to make cursor visible
    Gte_FixWindowPos (hDoc);



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
                    BaseName
-------------------------------------------------------------------*/ 
  
BaseName (char **ppsz) 
{
  
// Yes, it is a mess, but this works
  char *pszslash;
  
    
      
      {
	
      



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
  void
CompileDOS (HDOC hDoc) 
//#######################################################################
{
  
  
  
  
  
  
  
  
    ("WARNING: Close all apps that access database engine !\n DOS is a single user system!",
     MB_OK);
  
  
    
    {
      
    
  
    
    {
      
    
  
  
  
  
  
  
  
  
    
  
    {
      
      
    
  
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
  
  
    
    {
      
      
      
    
  
  else
    
    {
      
    
  
//   MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION); return;
    
  
    // Check for errors
    ChkErr (hDoc);
  
    
    {
      
	// rename object file to executable file
	if (access (szTargetObject, 0) == 0)
	
	{
	  
	  
	
    
  



//#######################################################################
  void
ChkErr (HDOC hDoc) 
//#######################################################################
{
  
  
  
  
  
  
  
  
  
  
  
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
  
//      Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));
    
    
    {
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	
      
	
	{
	  
	
      
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	  
	
      
	
	{
	  
	
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	  
	
      
	
	{
	  
	
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	  
	
      
	
	{
	  
	
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	  
	
      
	
	{
	  
	
    
      if (stricmp (szFileExt, "4gl") == 0)
	
	{
	  
	  
	
      
	
	{
	  
	
    
  
    
    {
      
	
	{
	  
	       ("Object not generated! Open compile log file?",
		MB_YESNO | MB_ICONQUESTION) == IDNO)
	    
	    {
	      
	    
	  
	  
	
      
      else
	
	{
	  
	  
	
    
  
//MsgBox("Before close", MB_OK | MB_ICONINFORMATION);
    
    // close this file
    // Gte_CloseDocument(hDoc);
    _Gte_CloseDocument (hDoc);
  
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
    remove (szBackupFile);
  
    // rename this file to bak
    rename (szDocFileName, szBackupFile);
  
    // rename err file to this file
    rename (szErrorFile, szDocFileName);
  
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
    MsgBox (szDocFileName, MB_OK | MB_ICONINFORMATION);
  
// -------------- end patch ------------------------
    
    // open it
    hDoc = Gte_OpenDocument (szDocFileName);
  
//MsgBox(szDocFileName, MB_OK | MB_ICONINFORMATION);
    
// return;
    
    // position to the first error line
    if (stricmp (szFileExt, "4gl") == 0)
    
    {
      
	{
	  
	
      
      else
	
	{
	  
	    // 4, 4 in Gte_find is to skip over first 3 lines
	    // inserted only by Windows 4GL compiler
	    // position to the first error line
	    Gte_Find (hDoc, "^\\|", 4, 4, FALSE, FALSE, TRUE, TRUE);
	
    
  
    
    {
      
	{
	  
	
      
      else
	
	{
	  
	
    



//#######################################################################
  void
CompileWin (HDOC hDoc) 
//#######################################################################
{
  
  
  
  
  
  
  
  
  
  
  
  
  
    
    {
      
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
	    
	
      
      else
	
	{
	  
	    //strcpy (szExt, "4gl"); strcpy(szFindErr,"^\\|");
	    strcpy (szCompler, "ix w4glcomp -n -pcode ");	//must use ix if not using WinExec
	  //strcpy (szDescr," source ");
	}
    
  
    
    {
      
	{
	  
	    // Usage : fglform [options] filename
	    //    -V : Display version information.
	    //    -h : Display this help.
	    //    -s : Silent mode (no messages are displayed).
	    
	
      
      else
	
	{
	  
	    //strcpy (szExt, "per"); strcpy(szFindErr,"^#");
	    strcpy (szCompler, "ix wform4gl -n ");	//ix
	  //strcpy (szDescr," form ");
	}
    
  
  
  
    // We should check filename for length of 8.3 for 4gl for Windows,
    // How to do that?
    
  
  
  
  
  
  
    
  
    {
      
      
    
  
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
  
  
    
  
  
    {
      
	("ERROR: This file does not have file extension! Unable to continue",
	 MB_OK);
      
    
  
    {
      
      
    
  
  else
    
    {
      
      
    
  
  
//   strcpy (pszOutputFile, szProject);
//   strcat (pszOutputFile, ".bld ");
    
  
    
    {
      
	//strcat (szCmdLine, szTargetDir);
	//strcat (szCmdLine, " ");
	
	
	  // FGL2P WILL CRASH IF YOU SPECIFY FULL PATH !!!
	{
	  
	
      
      else
	
	{
	  
	  {
	    
	    
	    
	    
	    
	    
	  
	  
	    //BaseName(g_szFileName);
	    
	
    
  
  else
    
    {
      
	{
	  
	    // The form 'C:\PRG\CSI\wax_3.71.per' cannot be opened.
	    // for 4js form compiler, long paths cannot be used!!!
	    
	  {
	    
	    
	    
	    
	    
	    
	  
	
      
    
  
//   MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
    // return;
    
//    system(szCmdLine);
    
  
    /*
       
       strcat (pszActionDisplay,szDescr);
       strcat (pszActionDisplay,"file ");
     */ 
    strcat (pszActionDisplay, szDocFileName);
  
  
    //  WinExec(szCmdLine, 1); // Does not wait for app to finnish...no can do!
    // Vedran, is there something like WinExecWait????
    // (otherwise works, without "ix" )
    
    //MsgBox(szTargetDir, MB_OK | MB_ICONINFORMATION);
    chdir (szTargetDir);
  
    //MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
    //MsgBox(pszOutputFile, MB_OK | MB_ICONINFORMATION);
    Gte_ExecuteTool (szCmdLine, pszOutputFile, pszActionDisplay, szCmdLine);	//" Args...");
  //    c:\informix\bin\errchkr c:\prg\job_post\job_post.4gl
  
/*
	Log the current envirinment to .cmp file for diag
	strcpy (szLogEnvCmdLine, "set >> ");
    strcat (szLogEnvCmdLine, pszOutputFile);
	system(szLogEnvCmdLine);
*/ 
    
    //MsgBox(szCmdLine, MB_OK | MB_ICONINFORMATION);
    
    // Check for errors
    ChkErr (hDoc);
  
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
    RestoreCursor ();



{
  
  
    
    {
      
#ifdef __32BIT__
	CallDLLFunc (NULL, "user32.dll", "PostMessageA", "iiil",
		     
      
#else	/* 
	CallDLLFunc (NULL, "user.exe", "PostMessage", "iiil",
		     
      
#endif	/* 
	if (Gte_GetActiveDocument () == hDoc)
	
      
    
  



  // ============================================================ EOF