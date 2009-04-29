#include <stdlib.h>
#include <sys/types.h>

#if (defined(WIN32) && ! defined(__CYGWIN__))
#include <windows.h>
#include "winsock2.h"
#define USE_WINSOCK
#endif

#if defined(WIN32) || defined (__MINGW32__)
         #ifndef _NO_WINDOWS_H_
            #define __UCHAR_DEFINED__
         #endif
#else                                           /* UNIX */
                #include <sys/socket.h>
                #include <netinet/in.h>
                #include <netdb.h>
		#include <netinet/in.h>
		#include <netdb.h>
       		#include <arpa/inet.h>
		#include <sys/un.h>

#endif

#if (defined(WIN32) && ! defined(__CYGWIN__))
 #ifndef USE_WINSOCK
  #define SOCKET int
 #endif
 #ifdef USE_WINSOCK
  #ifndef EINTR
   #define EINTR WSAEINTR
  #endif
 #endif
#endif




