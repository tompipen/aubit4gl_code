#ifndef REP_STRUCTURE
#define REP_STRUCTURE
  struct rep_structure
  {
    int top_margin, bottom_margin, left_margin, right_margin;
    int page_length;
    int has_first_page;
    char *next_page;
    char *rep_table;		/* database table for aggregate values */
    struct BINDING *group_data;
    char output_mode;
    char output_loc[256];
    char top_of_page[256];
    FILE *output;
    long page_no;
    int printed_page_no;
    long line_no;
    int col_no;
    /* was      int (*report)(); */
    int (*report) (int a, int b);
    int lines_in_header;
    int lines_in_first_header;
    int lines_in_trailer;
    int print_section;
    char *header;
	int finishing;
	char *repName;
	char *modName;
    int convertable;
  };
  struct pdf_rep_structure
  {
    double top_margin, bottom_margin, left_margin, right_margin;
    double page_length;
    double page_width;
    int has_first_page;
    char *next_page;
    char *rep_table;		/* database table for aggregate values */
    struct BINDING *group_data;
    char output_mode;
    char output_loc[256];
    FILE *output;
    int page_no;
    int printed_page_no;
    double line_no;
    double col_no;
    /* was      int (*report)(); */
    int (*report) (int a, int b);
    char font_name[256];
    double font_size;
    int paper_size;
    void *pdf_ptr;
    int font;
    int lines_in_header;
    int lines_in_first_header;
    int lines_in_trailer;
    int print_section;
    char *header;
    int finishing;
	char *repName;
	char *modName;
    int convertable;
  };

#endif