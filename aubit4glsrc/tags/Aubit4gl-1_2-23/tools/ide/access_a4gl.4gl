#Aubit 4gl replacement for access.c

code
#include <unistd.h>
endcode

####################################
FUNCTION file_access(filename,fmode)
####################################

DEFINE filename CHAR(512)
DEFINE fmode INTEGER
DEFINE rval INTEGER

code
trim(filename); /* remove any trailing spaces.. */
rval=access(filename, fmode);
endcode

RETURN rval

END FUNCTION

