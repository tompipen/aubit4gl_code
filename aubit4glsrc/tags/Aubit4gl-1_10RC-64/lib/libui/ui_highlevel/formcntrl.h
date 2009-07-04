/* formcntrl.h */
#define FLAG_MOVED_IN_FIELD  1
#define FLAG_FIELD_TOUCHED   2
#define FLAG_MOVING_TO_FIELD 4
int A4GL_fprop_flag_get(void *f, int flag) ;
int A4GL_fprop_flag_set(void *f,int flag) ;
int A4GL_fprop_flag_clear(void *f,int flag) ;


