
struct struct_metrics
  {
    	int x;
	int  y;
	int  w;
	int  scr;
	int  delim_code;
    	string label<>;
	int pos_code;
	int dlm1;
	int dlm2;
	int field;
  };


struct struct_form_field
  {
    string tag<>;
    int metric<>;
  };


enum FIELD_ATTRIBUTES_BOOL {
	FA_B_AUTONEXT,
	FA_B_REVERSE,
	FA_B_INVISIBLE,
	FA_B_NOENTRY,
	FA_B_VERIFY,
	FA_B_WORDWRAP,
	FA_B_COMPRESS,
	FA_B_UPSHIFT,
	FA_B_DOWNSHIFT,
	FA_B_REQUIRED
	
};

enum FA_COLOUR {
	FA_C_BLACK,
	FA_C_RED,
	FA_C_GREEN,
	FA_C_YELLOW,
	FA_C_BLUE,
	FA_C_MAGENTA,
	FA_C_CYAN,
	FA_C_WHITE
};


enum FA_ATTRIBUTES_STRING {
	FA_S_INCLUDE,
	FA_S_PICTURE,
	FA_S_FORMAT,
	FA_S_DEFAULT,
	FA_S_PROGRAM,
	FA_S_WIDGET,
	FA_S_CONFIG,
	FA_S_COMMENTS
};

struct struct_field_attr_string {
	enum FA_ATTRIBUTES_STRING type;
	string value<>;
};

struct struct_scr_field
  {
    int field_no;
    string colname<>;
    string tabname<>;
    int subscripts[3];
    int datatype;
    int dynamic;
    int do_reverse;
    struct struct_field_attr_string str_attribs<>;
    enum FIELD_ATTRIBUTES_BOOL bool_attribs<>;
    enum FA_COLOUR colour;
  };

struct struct_tables
  {
    string tabname<>;
    string alias<>;
  };

struct screen_name {
	string name<>;
};
	

struct struct_screen_record
  {
    string name<>;
    int dim;
    int attribs<>;
  };

struct struct_labels
  {
    	string label_content<>;
    	int x;
	int  y;
	int  w;
	int  scr;
  };

struct struct_form
	{
	string magic1<>;
	string dbname<>;
	string delim<>;
	int maxcol;
	int maxline;
    	struct screen_name snames<>;
	struct struct_scr_field attributes<>;
	struct struct_metrics metrics<>;
	struct struct_form_field fields<>;
	struct struct_screen_record records<>;
	struct struct_tables tables<>;
	string magic2<>;
};






