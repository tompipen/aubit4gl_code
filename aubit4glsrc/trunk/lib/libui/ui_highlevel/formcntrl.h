/* formcntrl.h */

static void A4GL_add_to_control_stack (struct s_screenio *sio, int op,void *f, char *parameter, int extent);
static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);
static void A4GL_newMovement (struct s_screenio *sio, int attrib);
static int process_control_stack (struct s_screenio *sio);
int UILIB_A4GL_req_field_input (void *sv, char type, va_list * ap);
int UILIB_A4GL_form_loop (void *vs, int init);
static void do_key_move (char lr, struct s_screenio *s, int a, int has_picture,char *picture);
static int A4GL_proc_key_input (int a, void *mform, struct s_screenio *s);
void A4GL_set_init_value (void *f, void *ptr, int dtype);
void A4GL_mja_set_current_field (void *form, void *field);
void A4GL_comments (struct struct_scr_field *fprop);
void A4GL_set_curr_infield (long a);
int A4GL_get_curr_infield (void);
void UILIB_A4GL_set_infield_from_stack (void);
int A4GL_get_curr_metric (struct s_form_dets *form);

extern void *UILIB_A4GL_get_curr_form (int warn_if_no_form);
extern void *A4GL_LL_get_field_userptr (void *field) ;
extern int A4GL_LL_int_form_driver (void *mform, int mode) ;
extern int A4GL_LL_get_carat(void *form) ;
extern void *A4GL_LL_current_field (void *form) ;
extern void A4GL_LL_set_current_field(void *form,void *field) ;
extern void A4GL_LL_set_carat(void *form) ;
extern char *A4GL_LL_field_buffer(void *field,int n) ;
extern void A4GL_screen_update(void) ;
extern void A4GL_LL_set_form_page(void *form,int page) ;
extern int A4GL_LL_getch_win() ;
extern void *A4GL_LL_get_form_userptr(void *form) ;
extern void A4GL_LL_screen_refresh(void) ;
extern void *memdup(void *ptr,int size) ;

