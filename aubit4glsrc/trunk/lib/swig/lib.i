%module aubit4gl_pl
%include typemaps.i
%apply int *BOTH {int *in_out}; 
%apply double *REFERENCE {double *in_out}; 

%apply double *REFERENCE {double *byref}; 
%apply int *REFERENCE    {int *byref}; 
%apply float *REFERENCE  {float *byref}; 
%apply long *REFERENCE   {long *byref}; 
%apply char *REFERENCE   {char *byref}; 



%{
typedef struct {
	int sqlcode;
	char sqlerrm[73];
	char sqlerrp[9];
	int sqlerrd[6];
	char sqlawarn[9];
	char sqlstate[10];
} sqlca_struct;

struct BINDING {
        void *ptr;
        int dtype;
        long size;
};
%}

typedef struct {
	int sqlcode;
	char sqlerrm[73];
	char sqlerrp[9];
	int sqlerrd[6];
	char sqlawarn[9];
	char sqlstate[10];
} sqlca_struct;

struct BINDING {
        void *ptr;
        int dtype;
        long size;
};







%typemap(perl5,in) char ** {
        AV *tempav;
        I32 len;
        int i;
        SV  **tv;
        if (!SvROK($source))
            croak("$source is not a reference.");
        if (SvTYPE(SvRV($source)) != SVt_PVAV)
            croak("$source is not an array.");
       tempav = (AV*)SvRV($source);
        len = av_len(tempav);
        $target = (char **) malloc((len+2)*sizeof(char *));
        for (i = 0; i <= len; i++) {
            tv = av_fetch(tempav, i, 0);        
            $target[i] = (char *) SvPV(*tv,na);
        }
        $target[i] = 0;
};

// This cleans up our char ** array after the function call
%typemap(perl5,freearg) char ** {
        free($source);
}

// Creates a new Perl array and places a char ** into it
%typemap(perl5,out) char ** {
        AV *myav;
        SV **svs;
        int i = 0,len = 0;
        /* Figure out how many elements we have */
        while ($source[len])
           len++;
        svs = (SV **) malloc(len*sizeof(SV *));
        for (i = 0; i < len ; i++) {
            svs[i] = sv_newmortal();
            sv_setpv((SV*)svs[i],$source[i]);
        };
        myav =  av_make(len,svs);
        free(svs);
       $target = newRV((SV*)myav);
       sv_2mortal($target);
}


extern sqlca_struct sqlca;
extern int status;

void fgl_start(int nargs,char *argv[]) ;
void push_char(char *s);
void push_int(int n);
void push_long(long n);
void display_at (int n, int a) ;
void *
cr_window (char *s, int iswindow, int form_line, int error_line,
           int prompt_line, int menu_line, int border, int comment_line,
           int message_line, int attrib);
void sleep_i ();
void remove_window (char *win_name);
void chk_err(int lineno,char *fname) ;
int cr_window_form (char *name, int iswindow, int form_line, int error_line, int prompt_line, int menu_line, int border, int comment_line, int message_line, int attrib);
void finish_create_menu(void *menu) ;
void add_menu_option(void *menu,char *txt,char *keys,char *desc,int helpno,int attr) ;
void *new_menu_create(char *title, int x, int y, int mn_type, int help_no);
int menu_loop (void * menu);
int free_menu (void * menu);
char *disp_h_menu (void * menu);
void fgl_end();
void push_variable(void *ptr,int dtype);
void xset_status (int a);  
void pop_args (int a) ;
void pop_params (struct BINDING b[], int n);
void *dif_start_bind();


void dif_add_bind_date(void *list,     int val) ;
void dif_add_bind_smint(void *list,    int val);
void dif_add_bind_int(void *list,      long val) ;
void dif_add_bind_float(void *list,    double val) ;
void dif_add_bind_smfloat(void *list,  float val);
void dif_add_bind_char(void *list,     char *val) ;


void dif_add_bind(struct bound_list *list,int *dptr,int dtype,int size);
void dif_free_bind(void *ptr);
long dif_get_bind(void *ptr);
void dif_print_bind(void *ptr);
void dif_add_bind_smint_ptr(void *list, int *in_out);
void dif_add_bind_dbl_ptr(void *list, double *in_out);
long dif_pop_bind_int(void *list) ;
char *dif_pop_bind_char(void *list) ;
int dif_pop_bind_smint(void *list) ;
int dif_pop_bind_float(void *list) ;
int dif_pop_bind_smfloat(void *list) ;
int dif_pop_bind_dec(void *list) ;
int dif_pop_bind_money(void *list) ;

