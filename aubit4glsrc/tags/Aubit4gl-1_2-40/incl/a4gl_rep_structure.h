#ifndef REP_STRUCTURE
#define REP_STRUCTURE

struct rb_blocks
{
    int     lineno;
    char    where;
    char    why[100];
};

// emulated parameters in haru
struct pdf_parameter_s
{
    int     overline;
    int     strikeout;
    int     underline;
};

// emulated values in haru
struct pdf_value_s
{
    double  horizscaling;
    double  strokewidth;
    int     textrendering;
    double  textrise;
    double  underlineposition;
    double  underlinewidth;
};

// used to keep a track of fonts already loaded for haru
struct fonts_loaded_s
{
    char   *font_name;
    char   *font_file;
};

// used to keep a track of pages suspended for haru
struct pages_suspended_s
{
    void   *page_handle;
    struct  pdf_parameter_s parameter;
    struct  pdf_value_s     value;
};

struct rep_structure
{
    int     top_margin, bottom_margin, left_margin, right_margin;
    int     page_length;
    int     has_first_page;
    char   *next_page;
    char   *rep_table;		/* database table for aggregate values */
    struct  BINDING *group_data;
    char    output_mode;
    struct  expr_str *output_loc; 
    char    output_loc_str[1024];
    char    top_of_page[256];
    FILE   *output;
    long    page_no;
    int     printed_page_no;
    int     printed_left_margin;
    long    line_no;
    int     col_no;
    /* was      int (*report)(); */
    int     (*report) (int a, int b);
    int     lines_in_header;
    int     lines_in_first_header;
    int     lines_in_trailer;
    int     print_section;
    char   *header;
    int     finishing;
    char   *repName;
    char   *modName;
    int     convertable;
    struct  rb_blocks *blocks;
    int     nblocks;
    int     curr_rb;

    /* The rb stack is used to track the push/pop_sections */
    int     rb_stack[8];
    int     rb_stack_level;

    char    emailAddress[1024];
};

struct pdf_rep_structure
{
    double  top_margin, bottom_margin, left_margin, right_margin;
    double  page_length;
    double  page_width;
    int     has_first_page;
    char   *next_page;
    char   *rep_table;		/* database table for aggregate values */
    struct  BINDING *group_data;
    char    output_mode;
    struct  expr_str *output_loc;
    char    output_loc_str[1024];
    FILE   *output;
    int     page_no;
    int     current_page_no;
    int     printed_page_no;
    double  line_no;
    double  col_no;
    /* was      int (*report)(); */
    int     (*report) (int a, int b);
    char    font_name[256];
    double  font_size;

    // used to keep track of fonts loaded in haru
    struct  fonts_loaded_s **fonts_loaded_array;
    int     fonts_loaded_count;

    int     paper_size;
    void   *pdf_ptr;

    // font index in pdflib
    int     font;

    int     lines_in_header;
    int     lines_in_first_header;
    int     lines_in_trailer;
    int     print_section;
    char   *header;
    int     finishing;
    char   *repName;
    char   *modName;
    int     convertable;
    struct  rb_blocks *blocks;
    int     nblocks;
    int     curr_rb;
    double  bluebar_r;
    double  bluebar_g;
    double  bluebar_b;
    int     bluebar_style;
    double  fill_color_r;
    double  fill_color_g;
    double  fill_color_b;
    double  stroke_color_r;
    double  stroke_color_g;
    double  stroke_color_b;

    // font pointer in haru
    void   *fontptr;

    // flagged to 1 if the openmode parameter is used in haru
    int     openmode_used;

    // emulated parameters in haru
    struct  pdf_parameter_s parameter;

    // emulated values in haru
    struct  pdf_value_s value;

    // used to keep track of allocated bookmarks in haru
    void  **bookmarks;
    int     bookmarks_count;

    // used to keep page details in haru for suspend/resume emulation
    struct  pages_suspended_s **pages_suspended_array;
    int     pages_suspended_count;

    /* The rb stack is used to track the push/pop_sections */
    int     rb_stack[8];
    int     rb_stack_level;

    char    emailAddress[1024];
};

#endif
