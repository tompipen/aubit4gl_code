enum e_scrmodes {
        SCRMODE_GRID,
        SCRMODE_SCREEN
};

/* formxml.c */
int initialize_xmlpacker(void);
int hasPrintedAttribute(int n);
void addPrintedAttribute(int n);
int getNumberOfScreens(struct_form *f);
void get_screen_size_dims(struct_form *f, int scr, int *width, int *height);
int isline(char *s);
char *conv_to_xml_include(char *s);
int is_metric(struct_form *f, int field_no, int metric_no);
void get_attribs(struct_form *f, int attr_no, char *buff, int mode,int metric_no);
int isLabel(struct_form *f, int attr_no);
void print_widget(struct_form *f, int metric_no, int attr_no, char *why);
void print_entry(struct_form *f, int metric_no, int attr_no, char *why);
void print_buttonedit_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_button_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_browser_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_combobox_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_progressbar_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_image_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_unknown_widget_attr(struct_form *f, char *widget, int metric_no, int attr_no, int oldstyle, char *why);
void print_dateedit_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_textedit_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
void print_label_attr(struct_form *f, int metric_no, int attr_no, int oldstyle, char *why);
int isInScreenArray(struct_form *f, int attr_no, int *dim, char *scrname);
void printRecordView(struct_form *f);
int fieldOccursMultipleTimes(struct_form *f, int attr_no, int *dim);
int fieldOccursHowManyTimes(struct_form *f, int attr_no, int *dim);
void print_field_attribute(struct_form *f, int metric_no, int attr_no);
int get_attrno_for_metric(struct_form *f, int metric_no);
void print_field(struct_form *f, int metric_no);
void get_layout_attribs(struct s_layout *layout, char *buff);
void dump_group(struct_form *f, struct s_layout *layout);
void dump_folder(struct_form *f, struct s_layout *layout);
void dump_page(struct_form *f, struct s_layout *layout);
void dump_vbox(struct_form *f, struct s_layout *layout);
void dump_hbox(struct_form *f, struct s_layout *layout);
void dump_grid(struct_form *f, struct s_layout *layout);
void dump_table(struct_form *f, struct s_layout *layout);
void dump_layout(struct_form *f, struct s_layout *layout);
void dump_form_layout(struct_form *f);
void new_field(int y, int x, int w, char because_of, int fstart);
int has_label(int x, int y, int w, int set, int fy);
void make_screen(struct_form *f, int scr);
int merge_labels(struct_form *f, int scr);
int dump_xml_labels(void);
void dump_screen(struct_form *f, int scr, enum e_scrmodes scrmode, char *extra);
void dump_form_screen(struct_form *f);
void write_json_form(FILE *wofile, char *fname, struct_form *f);


int get_num_labels(void) ;
int get_label(int n, char **label, int *x,int *y) ;

void convertMatrix(struct_form *f);
