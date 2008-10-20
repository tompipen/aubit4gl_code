#ifndef DEF_S_SCREENIO
#define DEF_S_SCREENIO

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
    struct s_formcontrol *fcntrl;
    int fcntrl_cnt;
    int attrib;
    int processed_onkey;
  };

#endif
