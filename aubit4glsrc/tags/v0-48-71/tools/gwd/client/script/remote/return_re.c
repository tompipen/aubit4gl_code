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
#define MAX_FILE_LOCATION  80	// max file location string
#define MAX_FILE_NAME      80
#define MAX_SOURCE_FILES   20	// num of sourcefiles to be compiled and checked for errors
#define MAX_SOURCE_TYPES   3	// num of sourcefile types to be compiled checked for errors


/*
  1: menu option 'Macro' --> create new macro
  In Macro definition enter:

  	Param1 "return_re"
	ExecScript

    in shortcut key, enter ctrl+s

*/


int
main (int argc, char *argv[])
{
  HDOC hDoc;
  char *psz;
  char szFileExt[16];
  long lStartLine;
  char szMessage[250];
  char szExec[250];
  char szSaveOrigLocation[50];
  char szSaveOrigFilename[50];
  char szSaveOrigHostname[50];
  char szSaveOrigUsername[50];
  char szOrigLocation[50];
  char szOrigFilename[50];
  char szOrigHostname[50];
  char szOrigUsername[50];


  hDoc = Gte_GetActiveDocument ();
  if (hDoc == NULL)
    {
      MsgBox ("Cannot get handle of active document!", MB_OK);
      return;
    }

  // remember cursor position
  GM_SaveCursorPos (hDoc);

  // to speed up macro disable screen update
  Gte_LockUpdate (hDoc);

/*
information is stored in the first 4 lines of document, like this
*/

  //------------------------------------------------------------
  if (Gte_Find (hDoc, "#orig_location:", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
    {
      Gte_GetCursorPos (hDoc, NULL, &lStartLine);
      Gte_GetLine (hDoc, lStartLine, szSaveOrigLocation,
		   sizeof (szOrigLocation));
      strcpy (szOrigLocation, szSaveOrigLocation);
      psz = szOrigLocation;
      while (*psz)
	{
	  if (*psz == ':')
	    {
	      psz = psz + 1;
	      strcpy (szOrigLocation, psz);
	      break;
	    }
	  psz++;
	}

      GM_DeleteLine (hDoc);
    }
  else
    {
      // MsgBox("Cannot find #orig_location: string in active doccument", MB_OK);
      // This is not a doccument that came from server via rcp,
      // so we will just save it, in the case that user mapped
      // this program to the CTRL-S key
      GM_SaveFile (hDoc);

      // Unlock screen update
      Gte_UnlockUpdate (hDoc);
      return;
    }

  //------------------------------------------------------------
  if (Gte_Find (hDoc, "#orig_filename:", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
    {
      Gte_GetCursorPos (hDoc, NULL, &lStartLine);
      Gte_GetLine (hDoc, lStartLine, szSaveOrigFilename,
		   sizeof (szOrigFilename));
      strcpy (szOrigFilename, szSaveOrigFilename);
      psz = szOrigFilename;
      while (*psz)
	{
	  if (*psz == ':')
	    {
	      psz = psz + 1;
	      strcpy (szOrigFilename, psz);
	      break;
	    }
	  psz++;
	}
      GM_DeleteLine (hDoc);
    }
  else
    {
      Gte_UnlockUpdate (hDoc);
      MsgBox ("Cannot find #orig_filename: string in active doccument",
	      MB_OK);
      return;

    }

  //------------------------------------------------------------
  if (Gte_Find (hDoc, "#orig_hostname:", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
    {
      Gte_GetCursorPos (hDoc, NULL, &lStartLine);
      Gte_GetLine (hDoc, lStartLine, szSaveOrigHostname,
		   sizeof (szOrigHostname));
      strcpy (szOrigHostname, szSaveOrigHostname);
      psz = szOrigHostname;
      while (*psz)
	{
	  if (*psz == ':')
	    {
	      psz = psz + 1;
	      strcpy (szOrigHostname, psz);
	      break;
	    }
	  psz++;
	}
      GM_DeleteLine (hDoc);

    }
  else
    {
      Gte_UnlockUpdate (hDoc);
      MsgBox ("Cannot find #orig_hostname: string in active doccument",
	      MB_OK);
      return;
    }

  //------------------------------------------------------------
  if (Gte_Find (hDoc, "#orig_username:", 1, 1, FALSE, FALSE, TRUE, TRUE) == 0)
    {
      Gte_GetCursorPos (hDoc, NULL, &lStartLine);
      Gte_GetLine (hDoc, lStartLine, szSaveOrigUsername,
		   sizeof (szOrigUsername));
      strcpy (szOrigUsername, szSaveOrigUsername);
      psz = szOrigUsername;
      while (*psz)
	{
	  if (*psz == ':')
	    {
	      psz = psz + 1;
	      strcpy (szOrigUsername, psz);
	      break;
	    }
	  psz++;
	}
      GM_DeleteLine (hDoc);
    }
  else
    {
      Gte_UnlockUpdate (hDoc);
      MsgBox ("Cannot find #orig_username: string in active doccument",
	      MB_OK);
      return;
    }


  // save curent file
  GM_SaveFile (hDoc);

  // execute rcp
  strcpy (szExec, "rcp -a ");
  strcat (szExec, "\\temp\\");
  strcat (szExec, szOrigFilename);
  strcat (szExec, " ");
  strcat (szExec, szOrigHostname);
  strcat (szExec, ".");
  strcat (szExec, szOrigUsername);
  strcat (szExec, ":");
  strcat (szExec, szOrigLocation);
  strcat (szExec, "/");
  strcat (szExec, szOrigFilename);

//    MsgBox(szExec, MB_OK);
//    Gte_UnlockUpdate(hDoc);
//    return;
//    example: rcp -a \temp\PB1.4gl chaix.afalout:/apps/max_4.00/ap/PB1.4gl

  WaitCursor ();

  Gte_ExecuteTool (szExec, "c:\\temp\\rcp.log",
		   "Returning file, please wait...", szExec);


  // re-insert kication info:
  strcat (szSaveOrigLocation, "\n");
  strcat (szSaveOrigFilename, "\n");
  strcat (szSaveOrigHostname, "\n");
  strcat (szSaveOrigUsername, "\n");


  Gte_SetCursorPos (hDoc, 1, 1, 0);
  if (Gte_InsertText (hDoc, szSaveOrigLocation) != 0)
    {
      if (Gte_InsertText (hDoc, szSaveOrigFilename) != 0)
	{
	  if (Gte_InsertText (hDoc, szSaveOrigHostname) != 0)
	    {
	      if (Gte_InsertText (hDoc, szSaveOrigUsername) != 0)
		{
		  //MsgBox("ok", MB_OK);
		}
	      else
		{
		  MsgBox ("Error re-inserting location data", MB_OK);
		}
	    }
	  else
	    {
	      MsgBox ("Error re-inserting location data", MB_OK);
	    }
	}
      else
	{
	  MsgBox ("Error re-inserting location data", MB_OK);
	}
    }
  else
    {
      MsgBox ("Error re-inserting location data", MB_OK);
    }

  // Reacticare screen update
  Gte_UnlockUpdate (hDoc);
  // Save file with re-inserted location info
  GM_SaveFile (hDoc);
  // Restore mouse pointer from hourglass
  RestoreCursor ();
  // restore cursor position in the doccument from stack
  GM_RestoreCursorPos (hDoc);
  // scroll window if necessary to make cursor visible
  Gte_FixWindowPos (hDoc);

}
