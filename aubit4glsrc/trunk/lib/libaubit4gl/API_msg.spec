*
* API specs for MSG library interface - used by dlmagic script
* to create API_msg.c (try "make API_msg.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY MSG
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_MSGTYPE
* Name of the header file to be referenced with #include
*HEADER_FILE API_msg.h


*
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*
// Only one function here for now, from lib/libmsg/msg_native/readmsg.c
// TODO: extract function that creates compiled message file from mkmess
// executable, and crate lib/libmsg/msg_native/writemsg.c
//
//int read_help_f (int no,int *maxwidth)
read_help_f int no,int *maxwidth -> int

// ------------------------ EOF ------------------------


