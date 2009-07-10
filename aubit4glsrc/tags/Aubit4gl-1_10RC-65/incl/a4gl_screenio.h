#ifndef DEF_S_SCREENIO
#define DEF_S_SCREENIO


/* 
 * IF YOU CHANGE THIS - PLEASE REMEMBER  TO EDIT THE 'shadow' structure in  data_if.c 
 *
 */
  struct s_screenio
  {
    int mode;
    struct s_form_dets *currform;
    void *currentfield;
    int curr_attrib;
    struct s_metrics *currentmetrics;
    int novars;
    struct BINDING *vars;
    struct s_constr_list *constr;
    int nfields;
    void **field_list;
    int field_changed;
    int help_no;
    int fcntrl_cnt;
    int attrib;
    int processed_onkey;
    void *callback_function;
    struct s_formcontrol fcntrl[CONTROL_STACK_LENGTH];
  };

#endif
