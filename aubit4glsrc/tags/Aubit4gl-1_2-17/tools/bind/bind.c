#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <imagehlp.h>

/**
 * Uses BindImageEx in the ImageHlp library to bind Windows
 * executables.
 * See the MSDN documentation for this function for more details.
 * <p>
 * This can potentially speed up the loading times of the executable.
 * Note that such an executable cannot then be reliably redistributed
 * due to the very nature of this operation.
 * <p>
 * To compile using the GCC in MinGW, use:
 * <br/>
 * <tt>gcc -Wall bind.c -o bind.exe -limagehlp</tt>
 *
 * @author Ranjit Mathew <rmathew AT hotmail DOT com>
 *
 * @version 0.1
 */
int main( int argc, char *argv[])
{
  OSVERSIONINFO osInfo;
  DWORD bindFlags;

  if (argc != 2)
  {
    fprintf (stderr, "USAGE: bind <executable file>\n");
    return 1;
  }


  ZeroMemory (&osInfo, sizeof (osInfo));
  osInfo.dwOSVersionInfoSize = sizeof (osInfo);
  GetVersionEx (&osInfo);

  if ((osInfo.dwMajorVersion == 4)
      && ((osInfo.dwMinorVersion == 0)
         || (osInfo.dwMinorVersion == 10)
         || (osInfo.dwMinorVersion == 90)))
  {
    printf ("INFO: Windows 9x/ME detected - using BIND_NO_BOUND_IMPORTS.\n");
    bindFlags = BIND_NO_BOUND_IMPORTS;
  }
  else
  {
    bindFlags = 0;
  }


  if (BindImageEx (bindFlags, argv[1], NULL, NULL, NULL) == TRUE)

  {
    printf ("INFO: \"%s\" has been successfully bound!\n", argv[1]);
  }
  else
  {
    char *bufPtr;

    DWORD err = GetLastError ();

    fprintf (stderr, "\nERROR: Could not bind \"%s\"!\n\n", argv[1]);

    if (FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER
                       | FORMAT_MESSAGE_FROM_SYSTEM
                       | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL,
                       err,
                       MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                       (LPTSTR) &bufPtr,
                       0,
                       NULL) != 0)
    {
      fprintf (stderr, "REASON: %s\n", bufPtr);
      LocalFree (bufPtr);
    }
    else
    {
      fprintf (stderr, "REASON: System error code: %lu\n", err);
    }

    return 1;
  }

  return 0;
}
