/**
 *
 * This file should be used only with native Windows port/compiler (VC++)
 * and not with CygWin.
 *
 * Defines DLL main entry point
 *
 * @file
 *
 * @todo Does this file belong in lib/ directory, or...?
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */
#include <windows.h>

int sys_errlist;
int sys_nerr;


int WINAPI
dllMain (HANDLE h, DWORD reason, void *foo)
{
  return 1;
}


/*
Following two examples of opening and using dll, are quivalent
frist one using UNIX style dlopen (CygWin) and the other one
native Windows method for use wtih Windows native compilers like MSVC
*/

/*
#include <stdio.h>
#include <dlfcn.h>
#include <windows.h>

extern __declspec(dllexport) void foo(void)
{
    printf("hello\n");
}

int main(int argc, char *argv[])
{
    void* dl    = NULL;
    void* A4GL_func = NULL;

    dl = dlopen(0 , RTLD_LAZY);
    if (dl == NULL) {
        printf("dlopen() failed\n");
        exit(0);
    }

    A4GL_func = dlsym(dl, "foo");
    if (A4GL_func == NULL) {
        printf("dlsym() failed\n");
        exit(0);
    }

    printf("do something meaningful\n");

    A4GL_dlclose(dl);
    return 0;
}
*/

/*
#include <stdio.h>
#include <windows.h>

extern __declspec(dllexport) void foo(void)
{
    printf("hello\n");
}

int main(int argc, char *argv[])
{
    void* dl   = NULL;
    void* A4GL_func = NULL;

    dl = (void *) GetModuleHandle (NULL);
    if (dl == NULL) {
        printf("GetModuleHandle() failed\n");
        exit(0);
    }

    A4GL_func = (void*)GetProcAddress((HMODULE)dl, "foo");
    if (A4GL_func == NULL) {
        printf("GetProcAddress() failed (code %u)\n", GetLastError());
        exit(0);
    }

    printf("do something meaningful\n");

    return 0;
}

*/
