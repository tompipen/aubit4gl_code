/* display_array.h */

static void A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp, int blank,int attr, int arr_line, int first_only,...);
static void draw_arr (struct s_disp_arr *disp, int type, int no);
static void draw_arr_all (struct s_disp_arr *disp);
static void redisplay_arr (struct s_disp_arr *arr, int redisp);
void A4GL_set_array_mode (int type);
static int disp_loop (struct s_disp_arr *arr);
int UILIB_A4GL_disp_arr_ap (void *dispv, void *ptr, char *srecname, int attrib,va_list * ap);
static int set_scrline_da (int np);
static int set_arrline_da (int np);
static int aclfgl_set_arrline(int np);
static int aclfgl_set_scrline(int np);
static void A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp, int blank, int attr,int arr_line, int first_only, ...);

extern void *UILIB_A4GL_get_curr_form (int warn_if_no_form);
extern void A4GL_screen_update(void) ;
extern int A4GL_LL_getch_win() ;
extern void A4GL_LL_screen_refresh(void) ;
extern int A4GL_LL_field_opts (void *field) ;
extern void *A4GL_LL_get_field_userptr (void *field) ;
extern char *A4GL_LL_field_buffer(void *field,int n) ;
extern void A4GL_LL_set_current_field(void *form,void *field) ;
extern void A4GL_LL_set_carat(void *form) ;
extern int A4GL_LL_set_field_opts (void *field, int oopt) ;

