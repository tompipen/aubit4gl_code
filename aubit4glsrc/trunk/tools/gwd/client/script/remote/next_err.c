
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
#define MAX_FILE_LOCATION  80  // max file location string
#define MAX_FILE_NAME      80
#define MAX_SOURCE_FILES   20    // num of sourcefiles to be compiled and checked for errors
#define MAX_SOURCE_TYPES   3    // num of sourcefile types to be compiled checked for errors



int main(int argc, char *argv[])
{
   HDOC hDoc;
   char szFileExt[16];
   long lStartLine;

//   MsgBox("Next error line function enter", MB_OK);


   hDoc = Gte_GetActiveDocument();
   if(hDoc == NULL) {
      MsgBox("Cannot get handle of active document!", MB_OK);
      return;
   }


    Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));

	Gte_GetCursorPos(hDoc, NULL, &lStartLine);


    // remember cursor position (this is not necessary, but it is user friendly)
    // GM_SaveCursorPos(hDoc);


    if(stricmp(szFileExt, "4gl") == 0)
     {

          Gte_Find(hDoc, "^\\|", 2, lStartLine+2, FALSE, FALSE, TRUE, TRUE);
          return;
     }

    if(stricmp(szFileExt, "err") == 0)
     {

          Gte_Find(hDoc, "^\\|", 2, lStartLine+2, FALSE, FALSE, TRUE, TRUE);
          return;
     }


    if(stricmp(szFileExt, "per") == 0)
    {
		  Gte_Find(hDoc, "^#", 1, 1, FALSE, FALSE, TRUE, TRUE);
          return;

     }

   MsgBox("Next_err.c: This is not 4gl, per or err file !", MB_OK);


      // restore cursor position from stack
      // GM_RestoreCursorPos(hDoc);
      // scroll window if necessary to make cursor visible
      // Gte_FixWindowPos(hDoc);

}
