
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


   hDoc = Gte_GetActiveDocument();
   if(hDoc == NULL) {
      MsgBox("Cannot get handle of active document!", MB_OK);
      return;
   }


   // check file extension
   // This is important because if we do not have a handle for correct
   // document (the one that is the most probable to cause compile error)
   // we will not be able to close it before opening .err file, so we will
   // have the "Another app have modified ... reload?" question.
   // This is not realy what I want, but GWD cannot make a handle from
   // filename, or close a document based on filename.

   {
      //Gte_GetFileExtension(g_szFileName, szFileExt, sizeof(szFileExt));
      Gte_GetFileExtension(hDoc, szFileExt, sizeof(szFileExt));


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



}
