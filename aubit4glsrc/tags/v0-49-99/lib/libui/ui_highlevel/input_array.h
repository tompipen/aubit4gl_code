/* input_array.h */

void A4GL_idraw_arr_all (struct s_inp_arr *inpa);

/*

static void A4GL_add_to_control_stack (struct s_inp_arr *sio, int op,void *f, char *parameter, int extent);
static void insert_line_in_array (struct s_inp_arr *inpa);
static void delete_line_in_array (struct s_inp_arr *inpa);
static void A4GL_idraw_arr (struct s_inp_arr *inpa, int type, int no);
static void iclear_srec (struct struct_screen_record *srec, struct s_inp_arr *inpa);
static void A4GL_idraw_arr_all (struct s_inp_arr *inpa);
static void ireinpalay_arr (struct s_inp_arr *arr, int reinpa);
static char *proc_zero(char *s);
static int pop_iarr_var (struct s_form_dets *form, int x, int y, int elem,struct BINDING *b);
static int iarr_loop (struct s_inp_arr *arr,struct aclfgl_event_list *evt);
static void process_key_press (struct s_inp_arr *arr, int a);
static int gen_field_list_vals (void *a, void *b, int nv, ...);
static void ***gen_srec_field_list (char *s, struct s_form_dets *form, int a, int d);
int UILIB_A4GL_inp_arr (void *vinpa, int defs, char *srecname, int attrib,int init);
int set_scrline_ia (int np);
int set_arrline_ia (int np);
static int A4GL_set_fields_inp_arr (void *vsio, int n);
static void init_arr_line (struct s_inp_arr *sio, int n);
static int A4GL_has_something_on_control_stack (struct s_inp_arr *sio);
static void A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data);
void *memdup(void *ptr,int size) ;
static void A4GL_newMovement (struct s_inp_arr *arr, int scr_line, int arr_line,int attrib);
static intprocess_control_stack (struct s_inp_arr *arr);
void A4GL_iarr_arr_fields (struct s_inp_arr *arr, int dattr, int arr_line,int scr_line, int blank);
int UILIB_A4GL_req_field_input_array (void *arrv, char type, va_list * ap);
void debug_print_flags (void *sv, char *txt);
int A4GL_field_name_match (void *f, char *s);
int A4GL_copy_field_data (struct s_form_dets *form);
void A4GL_set_arr_fields (int n, int attr, ...);
int A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m);
void A4GL_turn_field_on2 (void *f, int a);
void A4GL_set_field_attr_with_attr_already_determined (void *field, int attr,int cmd_type);

extern void *UILIB_A4GL_get_curr_form (int warn_if_no_form);
extern char *A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data);
extern int A4GL_LL_get_carat(void *form) ;
extern void *A4GL_LL_current_field (void *form) ;
extern int A4GL_LL_int_form_driver (void *mform, int mode) ;
extern void A4GL_screen_update(void) ;
extern char *A4GL_LL_field_buffer(void *field,int n) ;
extern void *A4GL_LL_get_field_userptr (void *field) ;
extern void A4GL_LL_set_carat(void *form) ;
extern int A4GL_LL_getch_win() ;
extern void A4GL_LL_screen_refresh(void) ;
extern void A4GL_LL_set_current_field(void *form,void *field) ;
extern int A4GL_LL_field_status(void *field) ;
extern void A4GL_LL_set_field_attr ( void *field) ;

*/
