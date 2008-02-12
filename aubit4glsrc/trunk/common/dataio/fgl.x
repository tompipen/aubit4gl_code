typedef string funcname<>;
typedef string str<>;
typedef string sql_ident<>;


enum dt_display_type {
        DT_DISPLAY_TYPE_LINE,
        DT_DISPLAY_TYPE_AT,
        DT_DISPLAY_TYPE_MENUITEM,
        DT_DISPLAY_TYPE_MAIN_CAPTION,
        DT_DISPLAY_TYPE_FIELD_LIST,
        DT_DISPLAY_TYPE_FORM_FIELD,
        DT_DISPLAY_TYPE_FORM_CAPTION,
        DT_DISPLAY_TYPE_STATUSBOX
};

struct form_field {
                        str form;
                        struct fh_field_list *field_list;
} 
;

struct x_y {
          struct expr_str* y;
          struct expr_str* x;
};

struct s_full_col {
        str tab;
        str col;
};



union dt_display switch ( enum dt_display_type dttype) {
		case DT_DISPLAY_TYPE_LINE: void;
		case DT_DISPLAY_TYPE_AT: x_y x_y;
                case DT_DISPLAY_TYPE_FORM_CAPTION: str caption;
                case DT_DISPLAY_TYPE_FIELD_LIST: struct fh_field_list *field_list;
		case DT_DISPLAY_TYPE_FORM_FIELD: form_field fldform_field;
		case DT_DISPLAY_TYPE_MAIN_CAPTION: void;
        	case DT_DISPLAY_TYPE_MENUITEM: void;
        	case DT_DISPLAY_TYPE_STATUSBOX: void;
};



enum cmd_type {
	E_CMD_ALLOC_ARR_CMD,
	E_CMD_AT_TERM_CMD,
	E_CMD_CALL_CMD,
	E_CMD_CANCEL_CMD,
	E_CMD_CASE_CMD,
	E_CMD_CHECK_MENU_CMD,
	E_CMD_CLEAR_CMD,
	E_CMD_CLOSE_CMD,
	E_CMD_CLOSE_SQL_CMD,
	E_CMD_CODE_CMD,
	E_CMD_CONNECT_CMD,
	E_CMD_CONSTRUCT_CMD,
	E_CMD_CONTINUE_CMD,
	E_CMD_CONVERT_CMD,
	E_CMD_CURRENT_WIN_CMD,
	E_CMD_DEALLOC_ARR_CMD,
	E_CMD_DECLARE_CMD,
	E_CMD_DEFER_CMD,
	E_CMD_DISABLE_MENU_CMD,
	E_CMD_DISPLAY_ARRAY_CMD,
	E_CMD_DISPLAY_B_N_CMD,
	E_CMD_DISPLAY_CMD,
	E_CMD_DISPLAY_FORM_CMD,
	E_CMD_ENABLE_MENU_CMD,
	E_CMD_ERROR_CMD,
	E_CMD_EXECUTE_CMD,
	E_CMD_EXECUTE_IMMEDIATE_CMD,
	E_CMD_EXIT_PROG_CMD,
	E_CMD_EXT_CMD,
	E_CMD_FINISH_CMD,
	E_CMD_FLUSH_CMD,
	E_CMD_FOREACH_CMD,
	E_CMD_FOR_CMD,
	E_CMD_FREE_CMD,
	E_CMD_FREE_REP_CMD,
	E_CMD_GOTO_CMD,
	E_CMD_HIDE_CMD,
	E_CMD_HIDE_OPTION_CMD,
	E_CMD_IF_CMD,
	E_CMD_INIT_CMD,
	E_CMD_INPUT_ARRAY_CMD,
	E_CMD_INPUT_CMD,
	E_CMD_LABEL_CMD,
	E_CMD_LET_CMD,
	E_CMD_LOAD_CMD,
	E_CMD_LOCATE_CMD,
	E_CMD_MENU_CMD,
	E_CMD_MESSAGE_CMD,
	E_CMD_MOVE_CMD,
	E_CMD_MSG_BOX_CMD,
	E_CMD_NEED_CMD,
	E_CMD_NEXT_FIELD_CMD,
	E_CMD_NEXT_FORM_CMD,
	E_CMD_NEXT_OPTION_CMD,
	E_CMD_OPEN_CURSOR_CMD,
	E_CMD_OPEN_FORM_CMD,
	E_CMD_OPEN_FORM_GUI_CMD,
	E_CMD_OPEN_STATUSBOX_CMD,
	E_CMD_OPEN_WINDOW_CMD,
	E_CMD_OPTIONS_CMD,
	E_CMD_OUTPUT_CMD,
	E_CMD_PAUSE_CMD,
	E_CMD_PAUSE_SCREEN_OFF_CMD,
	E_CMD_PAUSE_SCREEN_ON_CMD,
	E_CMD_PREPARE_CMD,
	E_CMD_PRINT_CMD,
	E_CMD_PRINT_FILE_CMD,
	E_CMD_PRINT_IMG_CMD,
	E_CMD_PROMPT_CMD,
	E_CMD_PUT_CMD,
	E_CMD_RESIZE_ARR_CMD,
	E_CMD_RETURN_CMD,
	E_CMD_RUN_CMD,
	E_CMD_SCROLL_CMD,
	E_CMD_SET_DATABASE_CMD,
	E_CMD_SHOW_CMD,
	E_CMD_SHOW_OPTION_CMD,
	E_CMD_SKIP_BY_CMD,
	E_CMD_SKIP_CMD,
	E_CMD_SKIP_TO_CMD,
	E_CMD_SKIP_TO_TOP_CMD,
	E_CMD_SLEEP_CMD,
	E_CMD_SELECT_CMD,
	E_CMD_SQL_BLOCK_CMD,
	/* E_CMD_SQL_BOUND_CMD, */
	E_CMD_SQL_CMD,
	E_CMD_SQL_TRANSACT_CMD,
	E_CMD_START_CMD,
	E_CMD_START_RPC_CMD,
	E_CMD_STOP_RPC_CMD,
	E_CMD_TERM_REP_CMD,
	E_CMD_UNCHECK_MENU_CMD,
	E_CMD_UNLOAD_CMD,
	E_CMD_VALIDATE_CMD,
	E_CMD_WHENEVER_CMD,
	E_CMD_SHOW_MENU_CMD, 
	E_CMD_WHILE_CMD,

	E_CMD_ENABLE_CMD,
	E_CMD_ENABLE_FORM_CMD,
	E_CMD_DISABLE_CMD,
	E_CMD_DISABLE_FORM_CMD,
	E_CMD_FETCH_CMD, 
	E_CMD_PDF_CALL_CMD,
	/* E_CMD_CALL_SHARED_CMD, */
	E_CMD_SET_SESSION_CMD,
        E_CMD_UPDATE_CMD,
        E_CMD_INSERT_CMD,
        E_CMD_DELETE_CMD,
E_CMD_LAST
};




struct str_list {
	str str_list_entry<>;
};

/*
enum e_variable_literal {
		E_V_OR_LIT_NOVALUE,
		E_V_OR_LIT_VAR,
		E_V_OR_LIT_INT,
		E_V_OR_LIT_STRING,
		E_V_OR_LIT_VAR_AS_STRING,
		E_V_OR_LIT_IDENT,
		E_V_OR_LIT_NULL
};

union variable_or_literal switch (enum e_variable_literal vttype) {
		case E_V_OR_LIT_NOVALUE:		void;
		case E_V_OR_LIT_VAR: 			struct expr_str *var;
		case E_V_OR_LIT_INT: 			int i;
		case E_V_OR_LIT_STRING: 		str s;
		case E_V_OR_LIT_VAR_AS_STRING: 		str sv;
		case E_V_OR_LIT_IDENT: 			str si;
	
};
*/

enum e_boolean {
	EB_FALSE,
	EB_TRUE,
	EB_NOTSET
};


struct field {
	str fieldname;
	str subscript;
};


struct attrib {
	int color;
	enum e_boolean nonewlines;
	enum e_boolean bold;
	enum e_boolean blink;
	enum e_boolean reverse;
	enum e_boolean dim;
	enum e_boolean invisible;
	enum e_boolean underline;
	enum e_boolean normal;
	str style;
	struct expr_str *variable_str;

/* INPUT/DISPLAY Array.... */
	str currentrowdisplay;
	struct expr_str *count;
	struct expr_str *maxcount;
	enum e_boolean allow_insert;
	enum e_boolean allow_delete;
	enum e_boolean no_new_lines;


/* Attributes that only apply to a WINDOW */
	enum e_boolean border;
	str text;
	str pad;
	struct expr_str *comment_line;
	struct expr_str *form_line;
	struct expr_str *error_line;
	struct expr_str *menu_line;
	struct expr_str *message_line;
	struct expr_str *prompt_line;
	struct expr_str *var_attrib;
	
};




struct funcname_list {
	funcname name<>;
	str namespaces<>;
};


/* ***************************************************** */
struct struct_start_rpc_cmd  {
	struct expr_str *valid_port;
	funcname_list remote_func_list;
};
	
/* ***************************************************** */

enum cancel_type { CT_INSERT, CT_DELETE };

struct struct_cancel_cmd {
	enum cancel_type c;
};

/* ***************************************************** */

struct struct_update_cmd {
	struct expr_str *connid;
	str table;
	str_list *column_list;
	struct s_select_list_item_list *value_list;
	struct expr_str *where_clause;
};


struct s_update_pair {
		str column_name;
	        struct s_select_list_item *value;
};

struct struct_insert_cmd {
	struct expr_str *connid;
	str table;
	str_list *column_list;
	struct s_select_list_item_list *value_list;
	struct s_select *subselect;
};

struct struct_delete_cmd {
	struct expr_str *connid;
	str table;
	struct expr_str *where_clause;
};


/* ***************************************************** */

enum e_close_type_nosql {
	E_CT_WINDOW,
	E_CT_FORM,
	E_CT_STATUSBOX
};

enum e_close_type_withsql {
	E_CT_DATABASE,
	E_CT_SESSION,
	E_CT_CURS_OR_PREP
};


/* ***************************************************** */
struct struct_close_cmd {
	enum e_close_type_nosql cl_type;
	struct expr_str * ident;
};

struct struct_close_sql_cmd {
	enum e_close_type_withsql cl_type;
	struct expr_str * ident;
};


struct struct_free_cmd {
	struct expr_str *connid;
	struct expr_str *cursorname;
};

/* ***************************************************** */
enum e_block_cmd {
	EBC_WHILE, EBC_FOR, EBC_INPUT, EBC_FOREACH, EBC_CONSTRUCT, EBC_DISPLAY, EBC_MENU,EBC_PROMPT, EBC_CASE
};

struct struct_continue_cmd {
	enum e_block_cmd what;
	int block_id;
	int sio_id;
};

struct struct_ext_cmd {
	enum e_block_cmd what;
	int block_id;
};


/* ***************************************************** */
enum e_defer {EDEFER_QUIT, EDEFER_INTERRUPT};

struct struct_defer_cmd  {
	enum e_defer what;
};


struct struct_code_cmd {
	str contents;
};


struct struct_disable_menu_cmd {
	str_list*  strlist;
};

struct struct_enable_menu_cmd {
	str_list* strlist;
};

struct struct_check_menu_cmd {
	str_list* strlist;
};

struct struct_uncheck_menu_cmd {
	str_list* strlist;
};

struct struct_goto_cmd {
	str label;
};

struct struct_label_cmd {
	str label;
};


struct struct_error_cmd {
	struct expr_str_list* expr_list;
	enum e_boolean wait_for_key;
	attrib *attributes;
};

struct struct_execute_cmd {
	struct expr_str *connid;
	struct expr_str_list* inbind;
	struct expr_str_list* outbind;
	struct expr_str *sql_stmtid;
};



struct struct_execute_immediate_cmd {
	struct expr_str * connid;
	struct expr_str *sql_stmt;
};

struct struct_flush_cmd {
	struct expr_str * connid;
	struct expr_str * cursorname;
};


struct struct_sleep_cmd {
	struct expr_str* sleep_expr;
};

struct struct_move_cmd {
	struct expr_str * windowname;
	struct expr_str* x;
	struct expr_str* y;
	enum e_boolean relative;
};

struct struct_show_menu_cmd {
	str menuname;
	str menuhandler;
	struct expr_str* mn_file;
};

struct struct_show_cmd {
	struct expr_str * windowname;
};

struct struct_hide_cmd {
	struct expr_str * windowname;
};

enum run_mode {
	ERM_NOT_SET,
	ERM_LINE_MODE,
	ERM_FORM_MODE
};

struct struct_run_cmd {
	struct expr_str* run_string;
	enum e_boolean wait;
	enum run_mode run_mode;
	struct expr_str *returning; /* Can only return a single variable */
};

enum e_direction {
	E_UP,
	E_DOWN
};

struct struct_scroll_cmd {
	struct fh_field_list *srec;
	struct expr_str* val;
};
	
struct struct_exit_prog_cmd {
	struct expr_str* exit_val;
};


typedef struct command * command_ptr;

struct commands {
	command_ptr cmds<>;
};

struct struct_return_cmd {
	struct expr_str_list* retvals;
};


struct struct_prepare_cmd {
	struct expr_str *connid;
	struct expr_str *stmtid;
	struct expr_str *sql;
	
};


enum e_location {
	E_LOC_FILE,
	E_LOC_MEMORY
};

union locate_pos switch (enum e_location where) {
	case E_LOC_FILE: 	struct expr_str *filename;
	case E_LOC_MEMORY : 	void;
};

struct struct_locate_cmd {
	struct expr_str_list* variables;
	locate_pos where;
};


struct struct_message_cmd {
	struct expr_str_list* message_expr;
	attrib *attributes;
	enum e_boolean wait;
};

struct struct_init_cmd {
	struct expr_str_list* varlist;
	/* struct expr_str_list* expanded_varlist; */
	str_list* tablist;
	struct expr_str_list *init_like_exprlist;
};


struct struct_next_field_cmd {
	int rel;
	struct fh_field_entry* nextfield;
	int sio;
};


struct struct_at_term_cmd {
	str funcname;
};


struct struct_next_option_cmd {
	struct expr_str *menuoption;
};

struct struct_show_option_cmd {
	struct expr_str_list*  menuoptions;
};

struct struct_hide_option_cmd {
	struct expr_str_list* menuoptions;
};


struct struct_for_cmd {
	struct expr_str* var;
	struct expr_str* start;
	struct expr_str* end;
	struct expr_str* step;
	commands *for_commands;
	int block_id;
};

struct struct_display_form_cmd {
	struct expr_str *formname;
	attrib *attributes;
};

typedef struct expr_str * expr_str_ptr; 

struct call_list {
	command_ptr calls_by_call<>;
	expr_str_ptr calls_by_expr<>;
};

struct struct_call_cmd {
	struct expr_str* fcall;
	struct expr_str_list* returning;
};

struct struct_pdf_call_cmd {
	struct expr_str* fcall;
	struct expr_str_list* returning;
};

struct if_cond {
	int lineno;
	struct expr_str* test_expr;
	commands *whentrue;
};

struct if_conds {
	if_cond conditions<>;
};

struct struct_if_cmd {
	if_conds truths;
	int lineno;
	int else_lineno;
	commands *whenfalse;
};

struct struct_foreach_cmd {
	struct expr_str *connid;
	struct expr_str * cursorname;
	struct expr_str_list* inputvals;
	struct expr_str_list* outputvals;
	commands *foreach_commands;
	int block_id;
};

struct single_option {
	str option;
	str value;
	struct expr_str *expr;
	int isKey;
};

typedef struct single_option * single_option_ptr;

struct manyoptions {
	single_option_ptr options<>;
};

struct struct_options_cmd {
	manyoptions* options;
};

struct startrep {
	char towhat;
	struct expr_str* s1;
        int with_page_length;
        int with_left_margin;
        int with_right_margin;
        int with_top_margin;
        int with_bottom_margin;
        str with_top_of_page;
};


struct pdf_startrep {
	char towhat;
	struct expr_str* s1;
        double with_page_length;
        double with_page_width;
        double with_left_margin;
        double with_right_margin;
        double with_top_margin;
        double with_bottom_margin;
	str fontname;
	double fontsize;
	int papersize;
	double pageheadersize;
	double firstpageheadersize;
	double pagetrailersize;
	enum e_boolean isdefault;
	enum e_boolean ascii_height;
	enum e_boolean ascii_width;
}
;





struct convert {
	char towhat;
	struct expr_str *s1;
	struct expr_str *conv_type;
	struct expr_str *filter;
};

struct struct_convert_cmd {
	str repname;
	str namespace;
	struct convert *conv_c;
};

struct struct_finish_cmd {
	str repname;
	str namespace;
	struct convert *conv_c;
};

struct struct_start_cmd {
	str repname;
	str namespace;
	struct startrep *sc_c;
};

struct struct_let_cmd {
	struct expr_str_list* vars;
	struct expr_str_list* vals;
};

struct rowscols  {
	struct expr_str* rows;
	struct expr_str* columns;
};

enum e_wintype {
	EWT_FORM,
	EWT_ROWSCOLS
};

union windowtype switch (enum e_wintype wintype) {
	case EWT_FORM: struct expr_str* formfilename;
	case EWT_ROWSCOLS: struct rowscols rowscols;
};

	
struct struct_open_window_cmd {
	struct expr_str * windowname;
	struct expr_str* x;
	struct expr_str* y;
	windowtype wt;
	struct attrib *attributes;
};




struct s_fetch_place {
        long ab_rel;
        struct expr_str* fetch_expr;
};

struct s_fetch {
        struct expr_str *cname;
        struct s_fetch_place *fp;
};

struct struct_fetch_cmd {
	        struct expr_str * connid;
	struct s_fetch* fetch;
	 struct expr_str_list* outbind;
};


struct struct_open_form_cmd {
	struct expr_str* formname;
	struct expr_str* form_filename;
};

struct struct_open_form_gui_cmd {
	struct expr_str *form;
	struct expr_str *y; 
	struct expr_str *x; 
	struct expr_str *like; 
	int disable;
	str formhandler;
};


struct struct_unload_cmd {
	struct expr_str * connid;
	struct expr_str * sql;
	struct expr_str* filename;
	struct expr_str* delimiter;
};


struct struct_load_cmd {
	struct expr_str * connid;
	struct expr_str* filename;
	struct expr_str* delimiter;
	struct expr_str *sqlvar; /* We'll use either sqlvar or tabname/collist */
	str tabname;
	str_list*  collist;
};

struct struct_connect_cmd {
	struct expr_str *conn_dbname;
	struct expr_str *conn_name;
	struct expr_str *username;
	struct expr_str *password;
};
	
enum report_blocks {
	RB_FIRST_PAGE_HEADER,
	RB_PAGE_HEADER,
	RB_PAGE_TRAILER,
	RB_ON_EVERY_ROW,
	RB_ON_LAST_ROW,
	RB_BEFORE_GROUP_OF,
	RB_AFTER_GROUP_OF,
	RB_FORMAT_EVERY_ROW
};

union report_block_data switch (enum report_blocks rb) {
	case RB_FIRST_PAGE_HEADER: 	void;
	case RB_PAGE_HEADER: 		void;
	case RB_PAGE_TRAILER: 		void;
	case RB_ON_EVERY_ROW: 		void;
	case RB_ON_LAST_ROW: 		void;

	case RB_FORMAT_EVERY_ROW: 	struct expr_str_list *variables;

	case RB_BEFORE_GROUP_OF: 	struct expr_str *bf_variable;
	case RB_AFTER_GROUP_OF:  	struct expr_str *af_variable;

};

struct report_format_section_entry {
	report_block_data rb_block;
	commands* rep_sec_commands;
        int lineno;
	int orderby_var_no;
};

typedef struct report_format_section_entry* report_format_section_entry_ptr;
struct report_format_section {
	report_format_section_entry_ptr entries<>;
        int lines_in_header ;
        int lines_in_first_header ;
        int lines_in_trailer;
};

enum e_report_orderby {
	REPORT_ORDERBY_IMPLICIT,
	REPORT_ORDERBY_EXTERNAL,
	REPORT_ORDERBY
};

struct report_orderby_section  {
	enum e_report_orderby rord_type;
	struct expr_str_list* variables;
	/* str asc_desc; */
};

struct struct_display_cmd {
	struct expr_str_list* exprs;
	dt_display* where;
	enum e_boolean by_name;
	attrib *attributes;
};



struct struct_display_b_n_cmd { /* Gets converted to a display_cmd ? */
	struct expr_str_list* vars;
	attrib *attributes;
};



struct struct_open_cursor_cmd {
	char cursor_type;
	struct expr_str *connid;
	struct expr_str *cursorname;
	struct expr_str_list* using_bind;
};



struct struct_put_cmd {
	struct expr_str * connid;
	struct expr_str * cursorname;
	struct expr_str_list *values;
};


struct s_cur_def {
        /* struct expr_str_list *inbind; */
        /* struct expr_str_list *outbind; */
        str forUpdate;
        struct struct_insert_cmd *insert_cmd;
        struct expr_str *ident;
        struct s_select *select;
} ;

struct struct_declare_cmd {
	struct expr_str *connid;
	struct expr_str *cursorname;
	struct s_cur_def *declare_dets;
	e_boolean with_hold;
	e_boolean scroll;
	e_boolean isstmt;
	char cursor_type;
};




struct  struct_validate_cmd {
	struct expr_str_list*  list;
	struct expr_str_list*  validate_list;
	str_list* tablist;
	
};

struct struct_while_cmd {
	struct expr_str* while_expr;
	commands *while_commands;
	int block_id;
};


struct struct_current_win_cmd {
	struct expr_str * windowname;
};


struct when {
	int lineno;
	int colno;
	struct expr_str* when_expr;
	commands *when_commands;
	
};


typedef struct when* when_ptr;

struct whens {
	when_ptr whens<>;
};

struct struct_case_cmd  {
	struct expr_str* case_expr;
	struct whens *whens;
	commands *otherwise;
};

struct struct_output_cmd {
	str repname;
	str namespace;
	struct expr_str_list* expressions;
};



struct struct_term_rep_cmd {
	str repname;
	str namespace;
};


enum e_clear {
	E_CLR_SCREEN,
	E_CLR_WINDOW,
	E_CLR_STATUS,
	E_CLR_FORM,
	E_CLR_FORM_DEFAULTS,
	E_CLR_FIELDS,
	E_CLR_FIELDS_TO_DEFAULT
	
};


union clear_data switch (enum e_clear clr_type) 
{
	case E_CLR_SCREEN: void;
	case E_CLR_FORM_DEFAULTS: void;
	case E_CLR_FORM: void;

	case E_CLR_WINDOW: struct expr_str * window;
	case E_CLR_STATUS: struct expr_str * statwindow;

	case E_CLR_FIELDS: struct fh_field_list *fields;
	case E_CLR_FIELDS_TO_DEFAULT: struct fh_field_list *deffields;
};

struct struct_clear_cmd {
	clear_data clr_data;
	enum e_boolean todefaults;
};


struct struct_sql_cmd {
	struct expr_str * connid;
	str sql;
};

/*
struct struct_sql_bound_cmd {
	struct expr_str * connid;
	str sql;
	struct expr_str_list* inbind;
};
*/

struct struct_select_cmd {
	struct expr_str * connid;
	struct s_select *sql;
	str forupdate;
};

struct struct_skip_cmd {
	int lines;
};

struct struct_skip_by_cmd {
	double lines;
};

struct struct_skip_to_cmd {
	double lines;
};

struct struct_sql_transact_cmd {
	struct expr_str * connid;
	int trans;
};

struct struct_set_database_cmd {
	struct expr_str* set_dbname;
	enum e_boolean exclusive_mode;
};

struct struct_whenever_cmd {
	int whencode;
	str whento;
};


struct struct_sql_block_cmd {
	struct expr_str *connid;
	struct expr_str_list* list;
};



struct struct_need_cmd {
	struct expr_str* expr;
};


struct struct_print_cmd {
	struct expr_str_list* print_expr;
	enum e_boolean semi;
};


struct struct_print_file_cmd {
	struct expr_str *filename;
	enum e_boolean semi;
};


struct struct_print_img_cmd {
	struct expr_str *var;
	struct expr_str* scale_x;
	struct expr_str* scale_y;
	str img_type;
	enum e_boolean semi;	
};


struct struct_pause_cmd {
	struct expr_str *pause_msg;
};


enum e_event {
	EVENT_BEF_ROW,
	EVENT_AFT_ROW,
	EVENT_BEFORE_DELETE,
	EVENT_AFTER_DELETE,
	EVENT_BEFORE_INSERT,
	EVENT_AFTER_INSERT,
	EVENT_BEFORE_INSERT_DELETE,
	EVENT_AFTER_INSERT_DELETE,
	EVENT_ON_IDLE,
	EVENT_ON_INTERVAL,
	EVENT_ON_TIME,
	EVENT_KEY_PRESS,
	EVENT_ANYKEY_PRESS,
	EVENT_ON_ACTION,
	EVENT_AFTER_INPUT,
	EVENT_BEFORE_INPUT,
	EVENT_BEFORE_FIELD,
	EVENT_AFTER_DISPLAY,
	EVENT_BEFORE_DISPLAY,
	EVENT_AFTER_CONSTRUCT,
	EVENT_BEFORE_CONSTRUCT,
	EVENT_BEFORE_MENU,
	EVENT_AFTER_FIELD,
	EVENT_MENU_COMMAND,

/* formhandler events */
	EVENT_BEFORE_OPEN_FORM,
	EVENT_AFTER_EVENT,
	EVENT_BEFORE_CLOSE_FORM,
	EVENT_BEFORE_ANY,
	EVENT_AFTER_ANY,
	EVENT_BEFORE,
	EVENT_AFTER,
	EVENT_BEFORE_EVENT,
	EVENT_ON,
	EVENT_AFTER_INP_CLEAN
};


struct menuoption {
	str_list *keys;
	int helpno;
	struct expr_str*  shortname;
	struct expr_str* longname;
};

union event_data switch (enum e_event event_type) {
	case EVENT_BEF_ROW: void;
	case EVENT_AFT_ROW: void;
	case EVENT_BEFORE_DELETE: void;
	case EVENT_AFTER_DELETE: void;
	case EVENT_BEFORE_INSERT: void;
	case EVENT_AFTER_INSERT: void;
	case EVENT_BEFORE_OPEN_FORM: void;
	case EVENT_BEFORE_INSERT_DELETE: void;
	case EVENT_AFTER_INSERT_DELETE: void;
	case EVENT_AFTER_INP_CLEAN: void;
	case EVENT_ANYKEY_PRESS: void;
	case EVENT_ON_IDLE: int idle_n;
	case EVENT_ON_INTERVAL: int interval_n;
	case EVENT_ON_TIME: int time_n;
	case EVENT_KEY_PRESS: str_list *key;
	case EVENT_ON_ACTION: str on_action;
	case EVENT_ON: str_list *on;

	case EVENT_AFTER_INPUT: void;
	case EVENT_BEFORE_INPUT:  void;

	case EVENT_AFTER_DISPLAY: void;
	case EVENT_BEFORE_DISPLAY:  void;
	case EVENT_AFTER_CONSTRUCT: void;
	case EVENT_BEFORE_CONSTRUCT:  void;
	case EVENT_BEFORE_MENU:  void;

	case EVENT_BEFORE_EVENT: void;
	case EVENT_BEFORE_FIELD: struct fh_field_list *before_field;
	case EVENT_AFTER_FIELD: struct fh_field_list *after_field;
	case EVENT_MENU_COMMAND : menuoption *mnoption;
	case EVENT_AFTER_EVENT: void;
	case EVENT_BEFORE_CLOSE_FORM: void;
	case EVENT_BEFORE_ANY: void;
	case EVENT_AFTER_ANY: void;
	case EVENT_BEFORE: str_list *before;
	case EVENT_AFTER: str_list *after;
};


struct on_event {
	event_data evt_data;
	commands *on_event_commands;
	int lineno;
	int colno;
};


typedef struct on_event* on_event_ptr;

struct on_events {
	on_event_ptr event<>;
};

struct struct_menu_cmd {
	struct expr_str *menu_title;
	struct attrib *menu_attrib;
	struct on_events* events;
	int sio;
	int blockid;
	struct expr_str *menu_attrib_comment;
	struct expr_str *menu_attrib_style;
	struct expr_str *menu_attrib_image;
};


struct struct_prompt_cmd {
	struct expr_str_list*prompt_str;
	struct attrib *prompt_str_attrib;
	struct attrib *prompt_fld_attrib;
	enum e_boolean for_char;
	struct expr_str* promptvar;
	int helpno;
	struct on_events* events;
	int sio;
	int blockid;
};

struct struct_display_array_cmd {
	struct expr_str * srec;
	struct expr_str * arrayname;
	struct attrib *attributes;
        struct on_events* events;
	struct fh_field_entry* scroll_using;
	int helpno;
	int sio;
	int blockid;
	str slice;
	int slice_start;
	int slice_end;
};


struct struct_input_cmd {
	struct expr_str_list* variables;
	struct fh_field_list* field_list;
        struct on_events* events;
	struct attrib *attributes;
	enum e_boolean by_name;
	enum e_boolean without_defaults;
	int helpno;
	int sio;
	int blockid;
};

struct cons_list_entry {
	str tabname;
	str colname;
};


typedef struct cons_list_entry* cons_list_entry_ptr;
struct cons_list {
	cons_list_entry_ptr list<>;
};




struct struct_input_array_cmd {
	struct expr_str *srec;
	struct expr_str *arrayname;
	struct attrib *attributes;
	struct on_events *events;
	e_boolean without_defaults;
	int helpno;
	int sio;
	int blockid;
	str slice;
	int slice_start;
	int slice_end;
};


struct struct_construct_cmd {
	enum e_boolean by_name;
	struct expr_str* constr_var;
	cons_list* con_columns;
	struct fh_field_list* list;
        struct on_events* events;
	struct attrib *attributes;
	enum e_boolean without_defaults;
	int helpno;
	int sio;
	int blockid;
};

/* *********************************** */


struct user_details {
	struct expr_str *username;
	struct expr_str *password;
};

struct struct_free_rep_cmd {
	str repname;
	str namespace;
};

/*
struct struct_open_session_cmd {
	struct expr_str * connid;
	struct expr_str* db;
	user_details* userdets;
};
*/



struct struct_alloc_arr_cmd {
	struct expr_str *variable;
};

struct struct_dealloc_arr_cmd {
	struct expr_str *variable;
};

struct struct_resize_arr_cmd {
	struct expr_str *variable;
};

struct struct_enable_cmd {
	struct fh_field_list *srec;
};

struct struct_enable_form_cmd {
	struct expr_str* formname;
	struct fh_field_list *srec;
};

struct struct_disable_cmd {
	struct fh_field_list *srec;
};

struct struct_disable_form_cmd {
	struct expr_str* formname;
	struct fh_field_list *srec;
};

struct struct_msg_box_cmd {
	struct expr_str_list *msg;
	struct expr_str_list *caption;
	int icon;
	int buttons;
	int default_button;
	int disable;
	struct expr_str *returning;
};

struct struct_next_form_cmd {
	str form;
	str field;
};

struct struct_call_shared_cmd {
	str niy;
};


/*
struct struct_gui_prompt_cmd {
	str niy;
};
*/

struct struct_open_statusbox_cmd {
	str name;
	struct expr_str *at_x;
	struct expr_str *at_y;
	struct expr_str *sz_width;
	struct expr_str *sz_height;
};




struct struct_set_session_cmd {
	str session_type;
	struct expr_str *s1;
	struct expr_str *s2;
	struct expr_str *s3;
};
	



union command_data switch (enum cmd_type type) {
	case E_CMD_STOP_RPC_CMD: void;
	case E_CMD_PAUSE_SCREEN_ON_CMD: void;
	case E_CMD_PAUSE_SCREEN_OFF_CMD: void;
	case E_CMD_SKIP_TO_TOP_CMD: void;
	case E_CMD_LAST: void;
	
	case E_CMD_START_RPC_CMD: struct_start_rpc_cmd start_rpc_cmd;
	case E_CMD_CALL_CMD: struct_call_cmd call_cmd;
	case E_CMD_CANCEL_CMD: struct_cancel_cmd cancel_cmd;
	case E_CMD_CASE_CMD: struct_case_cmd case_cmd;
	case E_CMD_CLOSE_CMD: struct_close_cmd close_cmd;
	case E_CMD_CLOSE_SQL_CMD: struct_close_sql_cmd close_sql_cmd;
	case E_CMD_CODE_CMD: struct_code_cmd code_cmd;
	case E_CMD_CONSTRUCT_CMD: struct_construct_cmd construct_cmd;
	case E_CMD_DEFER_CMD: struct_defer_cmd defer_cmd;
	case E_CMD_DISPLAY_B_N_CMD: struct_display_b_n_cmd display_b_n_cmd;
	case E_CMD_DISPLAY_CMD: struct_display_cmd display_cmd;
	case E_CMD_DISPLAY_FORM_CMD: struct_display_form_cmd display_form_cmd;
	case E_CMD_DISPLAY_ARRAY_CMD: struct_display_array_cmd display_array_cmd;
	case E_CMD_ALLOC_ARR_CMD: struct_alloc_arr_cmd alloc_arr_cmd;
	case E_CMD_DEALLOC_ARR_CMD: struct_dealloc_arr_cmd dealloc_arr_cmd;
	case E_CMD_RESIZE_ARR_CMD: struct_resize_arr_cmd resize_arr_cmd;
	case E_CMD_ERROR_CMD: struct_error_cmd error_cmd;
	case E_CMD_EXT_CMD: struct_ext_cmd ext_cmd;
	case E_CMD_CONTINUE_CMD: struct_continue_cmd continue_cmd;
	case E_CMD_EXIT_PROG_CMD: struct_exit_prog_cmd exit_prog_cmd;
	case E_CMD_FOR_CMD: struct_for_cmd for_cmd;
	case E_CMD_FOREACH_CMD: struct_foreach_cmd foreach_cmd;
	case E_CMD_FREE_CMD: struct_free_cmd free_cmd;
	case E_CMD_GOTO_CMD: struct_goto_cmd goto_cmd;
	case E_CMD_CHECK_MENU_CMD: struct_check_menu_cmd check_menu_cmd;
	case E_CMD_UNCHECK_MENU_CMD: struct_uncheck_menu_cmd uncheck_menu_cmd;
	case E_CMD_DISABLE_MENU_CMD: struct_disable_menu_cmd disable_menu_cmd;
	case E_CMD_ENABLE_MENU_CMD: struct_enable_menu_cmd enable_menu_cmd;
	case E_CMD_MSG_BOX_CMD: struct_msg_box_cmd msg_box_cmd;
	case E_CMD_IF_CMD: struct_if_cmd if_cmd;
	case E_CMD_INIT_CMD: struct_init_cmd init_cmd;
	case E_CMD_NEXT_FIELD_CMD: struct_next_field_cmd next_field_cmd;
	case E_CMD_NEXT_FORM_CMD: struct_next_form_cmd next_form_cmd;
	case E_CMD_INPUT_CMD: struct_input_cmd input_cmd;
	case E_CMD_INPUT_ARRAY_CMD: struct_input_array_cmd input_array_cmd;
	case E_CMD_SCROLL_CMD: struct_scroll_cmd scroll_cmd;
	case E_CMD_LABEL_CMD: struct_label_cmd label_cmd;
	case E_CMD_LET_CMD: struct_let_cmd let_cmd;
	case E_CMD_LOCATE_CMD: struct_locate_cmd locate_cmd;
	case E_CMD_AT_TERM_CMD: struct_at_term_cmd at_term_cmd;
	case E_CMD_RETURN_CMD: struct_return_cmd return_cmd;
	case E_CMD_MENU_CMD: struct_menu_cmd menu_cmd;
	case E_CMD_NEXT_OPTION_CMD: struct_next_option_cmd next_option_cmd;
	case E_CMD_SHOW_OPTION_CMD: struct_show_option_cmd show_option_cmd;
	case E_CMD_HIDE_OPTION_CMD: struct_hide_option_cmd hide_option_cmd;
	case E_CMD_MESSAGE_CMD: struct_message_cmd message_cmd;
	case E_CMD_OPEN_WINDOW_CMD: struct_open_window_cmd open_window_cmd;
	case E_CMD_OPEN_STATUSBOX_CMD: struct_open_statusbox_cmd open_statusbox_cmd;
	case E_CMD_OPEN_FORM_CMD: struct_open_form_cmd open_form_cmd;
	case E_CMD_OPEN_FORM_GUI_CMD: struct_open_form_gui_cmd open_form_gui_cmd;
	case E_CMD_OPEN_CURSOR_CMD: struct_open_cursor_cmd open_cursor_cmd;
	case E_CMD_CONNECT_CMD: struct_connect_cmd connect_cmd;
	case E_CMD_OPTIONS_CMD: struct_options_cmd options_cmd;
	case E_CMD_PREPARE_CMD: struct_prepare_cmd prepare_cmd;
	case E_CMD_EXECUTE_CMD: struct_execute_cmd execute_cmd;
	case E_CMD_EXECUTE_IMMEDIATE_CMD: struct_execute_immediate_cmd execute_immediate_cmd;
	case E_CMD_PROMPT_CMD: struct_prompt_cmd prompt_cmd;
	case E_CMD_START_CMD: struct_start_cmd start_cmd;
	case E_CMD_CONVERT_CMD: struct_convert_cmd convert_cmd;
	case E_CMD_FREE_REP_CMD: struct_free_rep_cmd free_rep_cmd;
	case E_CMD_OUTPUT_CMD: struct_output_cmd output_cmd;
	case E_CMD_FINISH_CMD: struct_finish_cmd finish_cmd;
	case E_CMD_TERM_REP_CMD: struct_term_rep_cmd term_rep_cmd;
	case E_CMD_NEED_CMD: struct_need_cmd need_cmd;
	case E_CMD_SKIP_CMD: struct_skip_cmd skip_cmd;
	case E_CMD_SKIP_BY_CMD: struct_skip_by_cmd skip_by_cmd;
	case E_CMD_SKIP_TO_CMD: struct_skip_to_cmd skip_to_cmd;
	case E_CMD_PRINT_CMD: struct_print_cmd print_cmd;
	case E_CMD_PRINT_FILE_CMD: struct_print_file_cmd print_file_cmd;
	case E_CMD_PRINT_IMG_CMD: struct_print_img_cmd print_img_cmd;
	case E_CMD_PAUSE_CMD: struct_pause_cmd pause_cmd;
	case E_CMD_RUN_CMD: struct_run_cmd run_cmd;
	case E_CMD_SLEEP_CMD: struct_sleep_cmd sleep_cmd;
	case E_CMD_SQL_BLOCK_CMD: struct_sql_block_cmd sql_block_cmd;
	case E_CMD_VALIDATE_CMD: struct_validate_cmd validate_cmd;
	case E_CMD_WHENEVER_CMD: struct_whenever_cmd whenever_cmd;
	case E_CMD_WHILE_CMD: struct_while_cmd while_cmd;
	case E_CMD_CLEAR_CMD: struct_clear_cmd clear_cmd;
	case E_CMD_CURRENT_WIN_CMD: struct_current_win_cmd current_win_cmd;
	case E_CMD_SHOW_CMD: struct_show_cmd show_cmd;
	case E_CMD_HIDE_CMD: struct_hide_cmd hide_cmd;
	case E_CMD_MOVE_CMD: struct_move_cmd move_cmd;
	case E_CMD_PUT_CMD: struct_put_cmd put_cmd;
	case E_CMD_UNLOAD_CMD: struct_unload_cmd unload_cmd;
	case E_CMD_LOAD_CMD: struct_load_cmd load_cmd;
	case E_CMD_SQL_CMD: struct_sql_cmd sql_cmd;
	/* case E_CMD_SQL_BOUND_CMD: struct_sql_bound_cmd sql_bound_cmd; */
	case E_CMD_SQL_TRANSACT_CMD: struct_sql_transact_cmd sql_transact_cmd;
	case E_CMD_SELECT_CMD: struct_select_cmd select_cmd;
	case E_CMD_FLUSH_CMD: struct_flush_cmd flush_cmd;
	case E_CMD_DECLARE_CMD: struct_declare_cmd declare_cmd;
	case E_CMD_SET_DATABASE_CMD: struct_set_database_cmd set_database_cmd;
	case E_CMD_FETCH_CMD: struct_fetch_cmd fetch_cmd;
	case E_CMD_SHOW_MENU_CMD : struct_show_menu_cmd show_menu_cmd;
	case E_CMD_ENABLE_CMD: struct_enable_cmd enable_cmd;

	case E_CMD_UPDATE_CMD: struct_update_cmd update_cmd;
	case E_CMD_INSERT_CMD: struct_insert_cmd insert_cmd;
	case E_CMD_DELETE_CMD: struct_delete_cmd delete_cmd;

	case E_CMD_ENABLE_FORM_CMD: struct_enable_form_cmd enable_form_cmd;
	case E_CMD_DISABLE_CMD: struct_disable_cmd disable_cmd;
	case E_CMD_DISABLE_FORM_CMD: struct_disable_form_cmd disable_form_cmd;
	case E_CMD_PDF_CALL_CMD: struct_pdf_call_cmd pdf_call_cmd;
	/*case E_CMD_CALL_SHARED_CMD: struct_call_shared_cmd call_shared_cmd; */
	case E_CMD_SET_SESSION_CMD: struct_set_session_cmd set_session_cmd;
	
};


struct comment {
	int lineno;
	int colno;
	int printed;
	str comment;
	char type;
};

struct command {
	command_data cmd_data; /* defined later */
	str comment;
	int lineno;
	int colno;
	str module;
};


struct vname {
	str name;
	str alias;
};

struct vname_name_list { /* NAMELIST */
	vname names<>;
};

enum e_constant_type {
		CONST_TYPE_CHAR  ,
		CONST_TYPE_FLOAT ,
		CONST_TYPE_INTEGER,
		CONST_TYPE_IDENT
};

union constant_data switch (enum e_constant_type consttype) {
	case CONST_TYPE_CHAR: 	str data_c;
	case CONST_TYPE_IDENT: 	str data_ident;
	case CONST_TYPE_INTEGER: int data_i;
	case CONST_TYPE_FLOAT: double data_f;
};

struct linked_variable
{
  str tabname;
  struct vname_name_list col_list;
};


typedef struct variable* variable_ptr;

struct assoc_array_variable
{
  variable_ptr variables<>;
  int size;
  int char_size;
};



struct simple_variable
 {
  int datatype;                 /* Integer data type */
  int dimensions[2];            /* Size - eg char(5), or decimal(16,2) */
};


struct record_variable
{
  variable_ptr variables<>;  		/* List of pointers to the variables */
  int record_alloc;             		/* Number of slots allocated */
  struct linked_variable *linked;       	/* Link to any table + pk or 0 */
  str object_type; 				/* Used for OBJECTS and RECORDs - for a record this will be 0 */
  str user_ptr;
};




struct assoc_subscript {
	str subscript_string;	
	struct expr_str *subscript_value;
};


enum e_variable_type {
        VARIABLE_TYPE_SIMPLE   ,
        VARIABLE_TYPE_RECORD    ,
        VARIABLE_TYPE_ASSOC     ,
        VARIABLE_TYPE_CONSTANT  ,
        VARIABLE_TYPE_FUNCTION_DECLARE  ,
        VARIABLE_TYPE_OBJECT    ,
        VARIABLE_TYPE_LINKED    
};

union variable_data switch ( enum e_variable_type variable_type) {
        case VARIABLE_TYPE_SIMPLE   		: struct simple_variable v_simple;
	/* The following is a fake comment so xgen_new can process it - DO NOT REMOVE THAT COMMENT! */
        case VARIABLE_TYPE_OBJECT 		: /*! struct record_variable v_record; !*/
        case VARIABLE_TYPE_RECORD    		: struct record_variable v_record;
        case VARIABLE_TYPE_ASSOC     		: struct assoc_array_variable v_assoc;
        case VARIABLE_TYPE_CONSTANT  		: constant_data v_const;
        case VARIABLE_TYPE_LINKED 		: struct linked_variable v_linked;
        case VARIABLE_TYPE_FUNCTION_DECLARE  	: void;

};

struct variable
{
  struct vname_name_list names;
  str defsrc;
  char user_system;
  char scope;
  int is_static;
  int is_extern;
  int arr_subscripts<>;
  variable_data var_data;
  str src_module;
  int usage;
  int assigned;
  int flags;
  int lineno;
};


struct lint_warning {
	int lineno;
	str warning;
};


struct variable_list {
	variable_ptr variables<>;
};
enum flist_type {
        FLIST_NORMAL,
        FLIST_SPECIAL
};


struct flist {
        str name;
        enum flist_type type;
        str special;
};


struct file_description {
        str name;
        struct flist list<>;
};



typedef struct module_entry* module_entry_ptr;


struct globals_definition {
	str mod_dbname;
	str external_datatypes<>;
	enum e_boolean schema_only;
	long compiled_time;
	variable_list exported_global_variables;
};

struct module_definition {
	str mod_dbname;
	str namespace;
	str force_ui;
	str debug_filename;
	str external_datatypes<>;
	struct comment comment_list<>;
	struct file_description imported_files<>;
	enum e_boolean schema_only;
	enum e_boolean genStackInfo;
	str module_name;
	long compiled_time;
	struct str_list *global_files;
	variable_list module_variables;
	variable_list exported_global_variables;
	variable_list imported_global_variables;
	module_entry_ptr module_entries<>;
};



	/*
struct expr_str {
  struct variable_usage *decoded_variable_usage;
  		//str varname_as_string;
  		//int dtype;
  		//str start_char_subscript_s;
  		//str end_char_subscript_s;
  		//char scope;
};



struct expr_str_list {
        struct expr_str bindings<>;
        long abind;
        int type;
        str data;
};


*/

struct expr_str_list {
          expr_str_ptr list<>;
};


/*
struct s_expr_push_variable {
        str variable_as_string; 
  	struct variable_usage *variable_usage;
        /long var_dtype;
	//char scope;
};
*/

struct s_expr_op {
        struct expr_str *left;
        struct expr_str *right;
        struct expr_str *escape;
};

struct s_expr_function_call {
        str fname;
	str namespace;
        struct expr_str_list *parameters;
        str module;
        int line;
};

struct s_expr_pdf_function_call {
        str fname;
	str namespace;
        struct expr_str_list *parameters;
        str module;
        int line;
};

struct s_expr_shared_function_call {
        str lib;
        str fname;
	str namespace;
        struct expr_str_list *parameters;
        str module;
        int line;
};


struct s_expr_infield {
                long sio_id;
                struct fh_field_list *field_list;
                str module;
                int line;
};


struct s_expr_get_fldbuf {
        long sio_id;
        struct fh_field_list *field_list;
        str module;
        int line;
};

struct s_expr_form_is_compiled {
	struct expr_str *formname;
	struct expr_str_list *params;
        str module;
        int line;
};

struct s_expr_field_touched {
        long sio_id;
        struct fh_field_list *field_list;
        str module;
        int line;
};

struct s_expr_wordwrap {
        struct expr_str *expr;
        struct expr_str * wrap_at;
};


struct s_expr_member_function_call {
	struct expr_str *var_usage_ptr;
	str namespace;
        expr_str_list *parameters;
        str module;
        int line;
};


struct s_expr_extend {
        struct expr_str *expr;
        int to;
};


struct s_expr_external_call {
        str host;
        str func;
        struct expr_str * port;
        str namespace;

        struct expr_str_list *parameters;
        int without_waiting;
        str module;
        int line;
};

/*
struct s_expr_substring {
         str str_as_string; 
  	struct variable_usage *var;
        long len;
        struct expr_str *substring_start;
        struct expr_str *substring_end;
        int type;
};
*/


struct s_expr_current {
        short from;
        short to;
};


struct s_expr_in {
        struct expr_str *expr;
        struct expr_str_list *elist;
};


struct s_expr_datetime {
        str dtval;
        int extend;
};

struct s_expr_tmp {
        str str;
        int dtype;
};

struct s_expr_interval {
        str intval;
        int extend;
};

struct s_expr_exists_sq {
        /* str subquery; */
        /* int nibind; */
        /* struct expr_str_list *ibind; */
	struct s_select *subquery;
};

struct s_expr_in_sq {
        struct expr_str *expr;
        /* str subquery; */
        /* int nibind; */
        /* struct expr_str_list *ibind; */
	struct s_select *subquery;
};

struct s_expr_cast {
                struct expr_str *expr;
                int target_dtype;
                int src_dtype;
                int notnull;
                int force;
};

struct s_expr_bound_fcall {
        str lib;
	str namespace;
        str fname;
        str module;
        int line;
	struct expr_str *channel;
	struct expr_str_list *values;
};

struct s_expr_agg {
        char agg_type;
        int expr_num;
        int in_group;
	struct expr_str *agg_expr;
	struct expr_str *expr_where;
	int blockid;
};

struct s_expr_dynarr_extent {
        struct expr_str *var;
        int n;
};

enum e_expr_type {
                ET_EXPR_EXPR_LIST,
                ET_EXPR_STRING,
                /* ET_EXPR_PUSH_VARIABLE, */
                ET_EXPR_TODAY,
                ET_EXPR_TIME,
                ET_EXPR_LINENO,
                ET_EXPR_PAGENO,
                ET_EXPR_TIME_EXPR,
                ET_EXPR_DATE_EXPR,
                ET_EXPR_NULL,
                ET_EXPR_TRUE,
                ET_EXPR_FALSE,
                ET_EXPR_NOT,
                ET_EXPR_UPSHIFT,
                ET_EXPR_DOWNSHIFT,
                ET_EXPR_EXTEND,
                ET_EXPR_ASCII,
                ET_EXPR_MM,
                ET_EXPR_POINTS,
                ET_EXPR_INCHES,
                ET_EXPR_CURRENT,
                ET_EXPR_OP_MULT,
                ET_EXPR_OP_DIV,
                ET_EXPR_OP_POWER,
                ET_EXPR_OP_ADD,
                ET_EXPR_OP_SUB,
                ET_EXPR_OP_EQUAL,
                ET_EXPR_OP_NOT_EQUAL,
                ET_EXPR_OP_MOD,
                ET_EXPR_OP_USING,
                ET_EXPR_OP_LIKE,
                ET_EXPR_OP_NOT_LIKE,
                ET_EXPR_OP_IN,
                ET_EXPR_OP_NOT_IN,
                ET_EXPR_OP_CONCAT,
                ET_EXPR_OP_MATCHES,
                ET_EXPR_OP_NOT_MATCHES,
                ET_EXPR_OP_CLIP,
                ET_EXPR_OP_LESS_THAN,
                ET_EXPR_OP_LESS_THAN_EQ,
                ET_EXPR_OP_GREATER_THAN,
                ET_EXPR_OP_GREATER_THAN_EQ,
                ET_EXPR_OP_YEAR,
                ET_EXPR_OP_MONTH,
                ET_EXPR_OP_DAY,
                ET_EXPR_OP_HOUR,
                ET_EXPR_OP_MINUTE,
                ET_EXPR_OP_SECOND,
                ET_EXPR_OP_ISNULL,
                ET_EXPR_OP_ISNOTNULL,
                ET_EXPR_OP_SPACES,
                ET_EXPR_OP_AND,
                ET_EXPR_OP_OR,
                ET_EXPR_NEG,
                ET_EXPR_FCALL,
                ET_EXPR_PDF_FCALL,
                ET_EXPR_SHARED_FCALL,
                ET_EXPR_MEMBER_FCALL,
                ET_EXPR_COLUMN,
                ET_EXPR_REPORT_EMAIL,
                ET_EXPR_REPORT_PRINTER,
                ET_EXPR_QUOTED_STRING,
                ET_EXPR_TRANSLATED_STRING,
                ET_EXPR_LITERAL_DOUBLE_STR,
                ET_EXPR_LITERAL_LONG,
                ET_EXPR_LITERAL_STRING, /* original is already quoted.... */
                ET_EXPR_LITERAL_EMPTY_STRING, /* original is already quoted.... */

                ET_EXPR_REDUCED,
                ET_EXPR_EXTERNAL,
                ET_EXPR_GET_FLDBUF,
                ET_EXPR_FORM_IS_COMPILED,
                ET_EXPR_WORDWRAP,
                /* ET_EXPR_SUBSTRING, */
                ET_EXPR_NOT_EXISTS_SUBQUERY,
                ET_EXPR_EXISTS_SUBQUERY,
                ET_EXPR_OP_IN_SUBQUERY,
                ET_EXPR_OP_NOTIN_SUBQUERY,

                ET_EXPR_CAST,
                ET_EXPR_CONCAT_LIST,
                ET_EXPR_YEAR_FUNC,
                ET_EXPR_MONTH_FUNC,
                ET_EXPR_DAY_FUNC,
                ET_EXPR_DATE_FUNC,
                ET_EXPR_TIME_FUNC,
                ET_EXPR_DTVAL,
                ET_EXPR_INFIELD,
                ET_EXPR_FIELD_TOUCHED,
                ET_EXPR_NOT_FIELD_TOUCHED,
                ET_EXPR_IVAL_VAL,
                /* ET_EXPR_FCALL_SINGLE, */
                ET_EXPR_TEMP,
                ET_EXPR_BOUND_FCALL,
                ET_EXPR_AGGREGATE,
                ET_EXPR_FGL_SIZEOF,
                ET_EXPR_FGL_ADDRESSOF,
                ET_EXPR_FGL_ISDYNARR_ALLOCATED,
                ET_EXPR_FGL_DYNARR_EXTENTSIZE,
                ET_EXPR_FIELDTOWIDGET,
                ET_EXPR_ID_TO_INT,
		ET_EXPR_FIELDNAME, 
                /*ET_EXPR_PROMPT_RESULT, */
                ET_EXPR_MODULE_FUNC,
		ET_EXPR_IDENTIFIER,
		ET_EXPR_PARAMETER,
		ET_EXPR_VARIABLE_IDENTIFIER,
		ET_EXPR_CACHED, 
		ET_EXPR_MENU_ALL,
		ET_EXPR_VARIABLE_USAGE,
		ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC,

		ET_EXPR_SQLBLOCK,
		ET_EXPR_SQLBLOCK_TEXT,
		ET_EXPR_SQLBLOCK_INTO,
		ET_EXPR_SELECT_LIST_ITEM,
		ET_EXPR_BRACKET,

	ET_E_V_OR_LIT_VAR,
	ET_E_V_OR_LIT_INT,
	ET_E_V_OR_LIT_STRING,
	ET_E_V_OR_LIT_VAR_AS_STRING,
	ET_E_V_OR_LIT_IDENT,
	ET_E_V_OR_LIT_NOVALUE,
                ET_EXPR_THROUGH,
		ET_EXPR_WHERE_CURRENT_OF, 
		ET_EXPR_ASSOC,

                ET_EXPR_LAST /* NOT USED - just there so the above can all have a trailing ',' !!! (and possibly checking later...) */
};




union expr_str switch ( enum e_expr_type expr_type) {
/* ET_EXPR_FCALL_SINGLE
ET_EXPR_PROMPT_RESULT  */

	case ET_EXPR_TODAY: /*! void; !*/
	case ET_EXPR_TIME: /*! void; !*/
	case ET_EXPR_LINENO: /*! void; !*/
	case ET_EXPR_PAGENO: /*! void; !*/
	case ET_EXPR_NULL: /*! void; !*/
	case ET_EXPR_TRUE: /*! void; !*/
	case ET_EXPR_FALSE: /*! void; !*/
	case ET_EXPR_REDUCED: /*! void; !*/
	case ET_EXPR_REPORT_PRINTER: /*! void; !*/
	case ET_EXPR_STRING: /*! void; !*/
	case ET_EXPR_LITERAL_EMPTY_STRING: /*! void; !*/
	case ET_EXPR_DATE_EXPR: /*! void; !*/
	case ET_EXPR_TIME_EXPR: /*! void; !*/
	case ET_EXPR_MENU_ALL: /*! void; !*/
	case ET_E_V_OR_LIT_NOVALUE: /*!		void; !*/
	case ET_EXPR_MODULE_FUNC: /*!         void; !*/
	case ET_EXPR_LAST:
		void;

	case ET_EXPR_TRANSLATED_STRING:
                /*! str                                    expr_string; !*/
	case ET_EXPR_LITERAL_DOUBLE_STR:
                /*! str                                    expr_string; !*/
	case ET_EXPR_QUOTED_STRING:
                /*! str                                    expr_string; !*/
	case ET_EXPR_LITERAL_STRING:
                /*! str                                    expr_string; !*/
	case ET_EXPR_FGL_ADDRESSOF:
                /*! str                                    expr_string; !*/
	case ET_EXPR_FGL_SIZEOF:
                /*! str                                    expr_string; !*/
	case ET_EXPR_REPORT_EMAIL:
                /*! str                                    expr_string; !*/
	case ET_EXPR_IDENTIFIER:
                /*! str                                    expr_string; !*/
	case ET_EXPR_PARAMETER:
                /*! str                                    expr_string; !*/
	case ET_EXPR_SQLBLOCK_TEXT: 	
               str                                    expr_string; 

	case ET_EXPR_CACHED:
                /*! long                                    expr_long; !*/
	case ET_EXPR_LITERAL_LONG:
                long                                    expr_long;

	case ET_EXPR_EXTEND:
                struct s_expr_extend                      *expr_extend;


	case ET_EXPR_SQLBLOCK:		
                /*! struct expr_str_list                    *expr_list; !*/

	case ET_EXPR_SQLBLOCK_INTO:		
                /*! struct expr_str_list                    *expr_list; !*/
	case ET_EXPR_THROUGH:
                /*! struct expr_str_list                    *expr_list; !*/
	case ET_EXPR_EXPR_LIST:
                /*! struct expr_str_list                    *expr_list; !*/
	case ET_EXPR_CONCAT_LIST:
                struct expr_str_list                    *expr_list;

	case ET_EXPR_FCALL:
                struct s_expr_function_call               *expr_function_call;
	case ET_EXPR_PDF_FCALL:
                struct s_expr_pdf_function_call           *expr_pdf_function_call;
	case ET_EXPR_SHARED_FCALL:
                struct s_expr_shared_function_call        *expr_shared_function_call;
	case ET_EXPR_MEMBER_FCALL:
                struct s_expr_member_function_call        *expr_member_function_call;
	case ET_EXPR_EXTERNAL:
                struct s_expr_external_call               *expr_external_call;

	case ET_EXPR_OP_ADD:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_AND:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_CONCAT:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_DIV:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_EQUAL:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_GREATER_THAN:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_GREATER_THAN_EQ:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_LESS_THAN:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_LESS_THAN_EQ:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_LIKE:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_MATCHES:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_MOD:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_MULT:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_NOT_EQUAL:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_NOT_LIKE:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_NOT_MATCHES:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_OR:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_POWER:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_SUB:
                /*! struct s_expr_op                          *expr_op; !*/
	case ET_EXPR_OP_USING:
                struct s_expr_op                          *expr_op;

	case ET_EXPR_CURRENT:
                struct s_expr_current                     *expr_current;

	case ET_EXPR_GET_FLDBUF:
                struct s_expr_get_fldbuf                  *expr_get_fldbuf;
	case ET_EXPR_FORM_IS_COMPILED:
                struct s_expr_form_is_compiled                  *expr_form_is_compiled;
	case ET_EXPR_INFIELD:
                struct s_expr_infield                     *expr_infield;
	case ET_EXPR_WORDWRAP:
                struct s_expr_wordwrap                    *expr_wordwrap;
/*
	case ET_EXPR_SUBSTRING:
                struct s_expr_substring                   *expr_substring;
*/

	case ET_EXPR_OP_IN:
                /*! struct s_expr_in                          *expr_in; !*/
	case ET_EXPR_OP_NOT_IN:
                struct s_expr_in                          *expr_in;

	case ET_EXPR_NOT_EXISTS_SUBQUERY:
                /*! struct s_expr_exists_sq                   *expr_exists_sq; !*/
	case ET_EXPR_EXISTS_SUBQUERY:
                struct s_expr_exists_sq                   *expr_exists_sq;

	case ET_EXPR_OP_IN_SUBQUERY:
                /*! struct s_expr_in_sq                       *expr_in_sq; !*/
	case ET_EXPR_OP_NOTIN_SUBQUERY:
                struct s_expr_in_sq                       *expr_in_sq;
	case ET_EXPR_CAST:
                struct s_expr_cast                        *expr_cast;
	case ET_EXPR_DTVAL:
                struct s_expr_datetime                    *expr_datetime;
	case ET_EXPR_IVAL_VAL:
                struct s_expr_interval                    *expr_interval;

	case ET_EXPR_FIELD_TOUCHED:
                /*! struct s_expr_field_touched               *expr_field_touched; !*/
	case ET_EXPR_NOT_FIELD_TOUCHED:
                struct s_expr_field_touched               *expr_field_touched;

	case ET_EXPR_TEMP:
                struct s_expr_tmp                         *expr_tmp;

	case ET_EXPR_BOUND_FCALL: 
		struct s_expr_bound_fcall                 *expr_bound_fcall;

	case ET_EXPR_AGGREGATE:
                struct s_expr_agg                         *expr_agg;

	case ET_EXPR_FGL_DYNARR_EXTENTSIZE:
                struct s_expr_dynarr_extent               *expr_dynarr_extent;


	case ET_EXPR_ID_TO_INT:
                /*! struct fh_field_entry                   *expr_field_entry; !*/
	case ET_EXPR_FIELDNAME:
                /*! struct fh_field_entry                   *expr_field_entry; !*/
	case ET_EXPR_FIELDTOWIDGET:
                struct fh_field_entry                   *expr_field_entry;

	case ET_EXPR_ASSOC:
		struct assoc_subscript *expr_assoc_subscript;
	case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_BRACKET:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_TIME_FUNC:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_MONTH_FUNC:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_DAY_FUNC:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_YEAR_FUNC:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_UPSHIFT:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_DOWNSHIFT:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_ASCII:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_POINTS:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_MM:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_INCHES:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_DATE_FUNC:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_COLUMN:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_SPACES:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_ISNULL:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_ISNOTNULL:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_NOT:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_CLIP:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_YEAR:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_MONTH:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_DAY:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_HOUR:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_MINUTE:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_VARIABLE_IDENTIFIER:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_OP_SECOND:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_WHERE_CURRENT_OF:
                /*! struct expr_str                         *expr_expr; !*/
	case ET_EXPR_NEG:
                struct expr_str                         *expr_expr;
	case ET_EXPR_VARIABLE_USAGE:
		struct variable_usage 			*expr_variable_usage;
	case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		struct variable_usage_with_asc_desc 			*expr_variable_usage_with_asc_desc;
	case ET_EXPR_SELECT_LIST_ITEM: 
		struct s_select_list_item *sl_item;


	case ET_E_V_OR_LIT_VAR: 		struct expr_str *var;
	case ET_E_V_OR_LIT_INT: 		int i;
	case ET_E_V_OR_LIT_STRING: 		str s;
	case ET_E_V_OR_LIT_VAR_AS_STRING: 	str sv;
	case ET_E_V_OR_LIT_IDENT: 		str si;
};










struct fh_field_entry {
        struct expr_str *field;
	struct expr_str *fieldsub;
};

struct fh_field_list {
        struct fh_field_entry field_list_entries<>;
};


struct variable_usage_with_asc_desc {
	struct variable_usage *var_usage;
	char asc_desc;
};

struct variable_usage {
        str variable_name;
        expr_str_ptr subscripts<>;
        expr_str *substrings_start;
        expr_str *substrings_end;
        int variable_id;
	int datatype;
	int datatype_length;
        int scope;
        struct variable_usage *next;
};


enum subtype {
        ST_INT,
        ST_EXPR,
        ST_VAR
};



/*
struct vardets {
        str name;
        struct subscript *subscript<>;
        struct vardets *sub_element;
};



union subscript switch (enum subtype subtype)  {
        case ST_INT:    int intval;
        case ST_VAR:    struct vardets *top_level_variable_name;
        case ST_EXPR:   struct sub_expr *substr;
};

struct sub_expr {
        subscript *sub_expr_left;
        subscript *sub_expr_right;
        str optype;
};
*/




enum e_sli {
        E_SLI_CHAR,
        E_SLI_COLUMN,
        E_SLI_SUBQUERY_EXPRESSION,
        E_SLI_BUILTIN_CONST_TRUE,
        E_SLI_BUILTIN_CONST_FALSE,
        E_SLI_BUILTIN_CONST_USER,
        E_SLI_BUILTIN_CONST_TODAY,
        E_SLI_BUILTIN_CONST_STAR,
        E_SLI_BUILTIN_CONST_COUNT_STAR,
        E_SLI_BUILTIN_CONST_CURRENT,
        E_SLI_BUILTIN_CONST_ROWID,
        E_SLI_BUILTIN_FUNC_YEAR,
        E_SLI_BUILTIN_FUNC_MONTH,
        E_SLI_BUILTIN_FUNC_DAY,
        E_SLI_BUILTIN_FUNC_MDY,
        E_SLI_BUILTIN_FUNC_WEEKDAY,
        E_SLI_BUILTIN_FUNC_DOW,
        E_SLI_BUILTIN_FUNC_DATE,
        E_SLI_BUILTIN_AGG_AVG,
        E_SLI_BUILTIN_AGG_MAX,
        E_SLI_BUILTIN_AGG_MIN,
        E_SLI_BUILTIN_AGG_SUM,
        E_SLI_BUILTIN_AGG_COUNT,
        E_SLI_BRACKET_EXPR,
        E_SLI_UNITS_YEAR,
        E_SLI_UNITS_MONTH,
        E_SLI_UNITS_DAY,
        E_SLI_UNITS_HOUR,
        E_SLI_UNITS_MINUTE,
        E_SLI_UNITS_SECOND,
        E_SLI_OP,
        E_SLI_BETWEEN,
        E_SLI_NOT_BETWEEN,
        E_SLI_DATETIME,
        E_SLI_INTERVAL,
        E_SLI_EXTEND,
        E_SLI_LITERAL,
        E_SLI_IN_VALUES,
        E_SLI_IN_SELECT,
        E_SLI_NOT_IN_VALUES,
        E_SLI_NOT_IN_SELECT,
        E_SLI_ISNULL,
        E_SLI_ISNOTNULL,
        E_SLI_NOT,
        E_SLI_REGEX_LIKE,
        E_SLI_REGEX_NOT_LIKE,
        E_SLI_REGEX_MATCHES,
        E_SLI_REGEX_NOT_MATCHES,
        E_SLI_REGEX_ILIKE,
        E_SLI_REGEX_NOT_ILIKE,
        E_SLI_FCALL,
        E_SLI_ASC,
        E_SLI_DESC,
        E_SLI_IBIND,
        E_SLI_COLUMN_NOT_TRANSFORMED,
        E_SLI_VARIABLE,
        E_SLI_QUERY,
        E_SLI_SUBQUERY,
        E_SLI_QUERY_PLACEHOLDER,
        E_SLI_JOIN,
        E_SLI_CASE,
        E_SLI_CASE_ELEMENT,
        E_SLI_COLUMN_ORDERBY,
        E_SLI_VAR_REPLACE,
        E_SLI_BUILTIN_CONST_TIME,
        E_SLI_BUILTIN_CONST_NULL,
	E_SLI_VARIABLE_USAGE,
	E_SLI_VARIABLE_USAGE_IN_SELECT_LIST,
	E_SLI_VARIABLE_USAGE_LIST

};

enum sq_expression_type {
        E_SQE_DONT_CARE,
        E_SQE_ALL,
        E_SQE_ANY,
        E_SQE_SOME,
        E_SQE_EXISTS,
        E_SQE_NOT_EXISTS

};


typedef struct s_select_list_item *elements_ptr;


struct s_select_list_item_list  {
                elements_ptr list<>;
};

struct s_sli_case {
	elements_ptr elements<>;
};

struct s_sli_case_element  {
        struct s_select_list_item *condition;
        struct s_select_list_item *response;
};

struct sql_statement {
        int stmt_type;
        str sql_string;
        struct expr_str_list *ibind;
        struct expr_str_list *obind;
        int nibind;
        int nobind;
};

struct s_table_list_element {
        str tabname;
        str alias;
        /* int ncolumns; */
        str columns<>;
};


typedef struct s_table_list_element *s_table_list_element_ptr;
struct s_table_list {
	struct s_table_list_element tables<>;
};

struct s_table {
                str tabname;
                str alias;
                struct s_table *next;
                struct s_table *outer_next;
};



struct s_select_finish {
                struct s_select_list_item_list *order_by;
                str into_temp;
                str insert_into;
                int nolog;
};

struct sq_subquery {
        char aud[20];
        struct s_select_list_item_list *list;
        /* struct tab_expression *te; */
};

struct s_limit {
        long start;
        long end;
        long offset;
};


struct list_of_integers {
        int list<>;
};


struct ilist {
                int i0;
                int i1;
                int i2;
                int i3;
                int i4;
                int i5;
} ;


struct s_select {
                str modifier; /* ALL/DISTINCT/UNIQUE */
		struct s_limit limit;
                int ncolumns;

                /* Our select list itself */
                struct s_select_list_item_list *select_list;
                struct s_select_list_item_list list_of_items;


                /* Pointer to first table */
                struct s_table *first;

                /* A flat list of tables (generated from the previous structure) */
                struct s_table_list table_elements;

                /* The group by clause */
                struct s_select_list_item       *where_clause;
                struct s_select_list_item_list  *group_by;
                struct s_select_list_item       *having;

                struct s_select                 *next;
                struct s_select_finish          *sf;
                struct expr_str_list *into;
                str union_op;
		str extra_statement;

};



struct s_select_list_item_column {
                        str tabname;
                        str colname;
                        struct ilist subscript;
};

struct s_select_list_item_sq_expression {
                        enum sq_expression_type type;
                        struct s_select_list_item *sq;

};

struct s_select_list_item_complex_expr {
                        struct s_select_list_item *left;
                        struct s_select_list_item *right;
                        char op[10];
};

struct s_select_list_item_between_expr {
                        struct s_select_list_item *val;
                        struct s_select_list_item *from;
                        struct s_select_list_item *to;

};
struct s_select_list_item_sli_expr {
                        struct s_select_list_item *left;
                        struct s_select_list_item *right;
};
struct s_select_list_item_slil_expr {
                       struct s_select_list_item *left;
                        struct s_select_list_item_list *right_list;
};
struct s_select_list_item_agg_expr {
                        char  aud[20]; /* All/unique/distinct */
                        struct s_select_list_item *expr;
};
struct s_select_list_item_builtin_fcall {
                        char fname[128];
                        struct s_select_list_item_list *params;
};

struct s_select_list_item_fcall {
                        char fname[128];
                        struct s_select_list_item_list *params;
};

struct s_select_list_item_extend {
                struct s_select_list_item *expr;
                char from[20];
                char to[20];
};

struct s_select_list_item_regex {
                       struct s_select_list_item *val;
                        struct s_select_list_item *regex;
                        char escape[20];
};





union s_select_list_item_data switch (enum e_sli type) {

        case E_SLI_IBIND:
                /*! str expression; !*/
        case E_SLI_VARIABLE:
                /*! str expression; !*/
        case E_SLI_DATETIME:
                /*! str expression; !*/
        case E_SLI_INTERVAL:
                /*! str expression; !*/
        case E_SLI_COLUMN_NOT_TRANSFORMED:
                /*! str expression; !*/
	case E_SLI_LITERAL:
                /*! str expression; !*/
        case E_SLI_CHAR: /* USED ? */
                /*! str expression; !*/
        case E_SLI_VAR_REPLACE:
                str expression;

        case E_SLI_BUILTIN_CONST_COUNT_STAR:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_CURRENT:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_FALSE:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_ROWID:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_STAR:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_TIME:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_TODAY:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_TRUE:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_USER:
		/*! void; !*/
        case E_SLI_BUILTIN_CONST_NULL:
		/*! void; !*/
        case E_SLI_QUERY_PLACEHOLDER:
		void;


        case E_SLI_ASC:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_DESC:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_NOT:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_BRACKET_EXPR:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_YEAR:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_DAY:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_HOUR:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_MINUTE:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_MONTH:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_UNITS_SECOND:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_ISNOTNULL:
		/*! struct s_select_list_item *expr; !*/
        case E_SLI_ISNULL:
		struct s_select_list_item *expr;

        case E_SLI_BUILTIN_FUNC_DATE:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_DAY:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_DOW:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_MDY:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_MONTH:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_WEEKDAY:
		/*! struct s_select_list_item_builtin_fcall builtin_fcall; !*/
        case E_SLI_BUILTIN_FUNC_YEAR:
		struct s_select_list_item_builtin_fcall builtin_fcall;


        case E_SLI_BUILTIN_AGG_AVG:
		/*!  struct s_select_list_item_agg_expr agg_expr; !*/
        case E_SLI_BUILTIN_AGG_COUNT:
		/*!  struct s_select_list_item_agg_expr agg_expr; !*/
        case E_SLI_BUILTIN_AGG_MAX:
		/*!  struct s_select_list_item_agg_expr agg_expr; !*/
        case E_SLI_BUILTIN_AGG_MIN:
		/*!  struct s_select_list_item_agg_expr agg_expr; !*/
        case E_SLI_BUILTIN_AGG_SUM:
		struct s_select_list_item_agg_expr agg_expr;

        case E_SLI_COLUMN:
		/*! struct s_select_list_item_column column; !*/
        case E_SLI_COLUMN_ORDERBY:
		struct s_select_list_item_column column;
        case E_SLI_EXTEND:
		struct s_select_list_item_extend extend;


        case E_SLI_FCALL:
		struct s_select_list_item_fcall fcall;

        case E_SLI_CASE:
		struct s_sli_case sqlcase;

        case E_SLI_REGEX_ILIKE:
		/*! struct s_select_list_item_regex regex; !*/
        case E_SLI_REGEX_LIKE:
		/*! struct s_select_list_item_regex regex; !*/
        case E_SLI_REGEX_MATCHES:
		/*! struct s_select_list_item_regex regex; !*/
        case E_SLI_REGEX_NOT_ILIKE:
		/*! struct s_select_list_item_regex regex; !*/
        case E_SLI_REGEX_NOT_LIKE:
		/*! struct s_select_list_item_regex regex; !*/
        case E_SLI_REGEX_NOT_MATCHES:
		struct s_select_list_item_regex regex;


        case E_SLI_BETWEEN:
		/*! struct s_select_list_item_between_expr  between_expr; !*/
        case E_SLI_NOT_BETWEEN:
		struct s_select_list_item_between_expr  between_expr;

        case E_SLI_CASE_ELEMENT:
                struct s_sli_case_element sqlcaseelement;
		
        case E_SLI_JOIN:
		/*! struct s_select_list_item_complex_expr complex_expr; !*/
        case E_SLI_OP: 
		struct s_select_list_item_complex_expr complex_expr;


        case E_SLI_IN_SELECT:
		/*! struct s_select_list_item_sli_expr sli_expr; !*/
        case E_SLI_NOT_IN_SELECT:
		struct s_select_list_item_sli_expr sli_expr;



        case E_SLI_IN_VALUES:
		/*! struct s_select_list_item_slil_expr slil_expr; !*/
        case E_SLI_NOT_IN_VALUES:
		struct s_select_list_item_slil_expr slil_expr;

        case E_SLI_QUERY:
		/*! struct s_select *subquery; !*/
        case E_SLI_SUBQUERY:
		struct s_select *subquery;

        case E_SLI_SUBQUERY_EXPRESSION:
		struct s_select_list_item_sq_expression sq_expression;

	case E_SLI_VARIABLE_USAGE_IN_SELECT_LIST : 
		/*! struct variable_usage *var_usage; !*/

	case E_SLI_VARIABLE_USAGE : 
		struct variable_usage *var_usage;

	case E_SLI_VARIABLE_USAGE_LIST: 
		/* used for record.* */
		struct s_select_list_item_list *var_usage_list; 

};

struct s_select_list_item {
	struct s_select_list_item_data data;
	str alias;
        int sign;
};

struct s_function_definition {
	str funcname;
	str namespace;
	enum e_boolean isstatic;
	struct expr_str_list expression_list;
	struct expr_str_list* parameters;
	str module;
	int lineno;
	int lastlineno;
	call_list call_list;
	variable_list variables;
	commands* func_commands;
	lint_warning extra_warnings<>;
};



struct s_report_definition {
	str funcname;
	str namespace;
	enum e_boolean isstatic;
	struct expr_str_list expression_list;
	variable_list variables;
	struct expr_str_list* parameters;
	startrep *report_output_section;
	report_orderby_section *report_orderby_section;
	report_format_section *report_format_section;
	struct expr_str_list aggregates;
	str module;
	int lineno;
	int colno;
	int lastlineno;
	call_list call_list;

	lint_warning extra_warnings<>;
};


struct s_pdf_report_definition {
	str funcname;
	str namespace;
	enum e_boolean isstatic;
	struct expr_str_list expression_list;
	variable_list variables;
	struct expr_str_list* parameters;
	pdf_startrep *report_output_section;
	report_orderby_section *report_orderby_section;
	report_format_section *report_format_section;
	struct expr_str_list aggregates;
	str module;
	int lineno;
	int colno;
	int lastlineno;
	call_list call_list;
	lint_warning extra_warnings<>;
};

enum module_entry_type {
	E_MET_FUNCTION_DEFINITION,
	E_MET_MAIN_DEFINITION,
	E_MET_REPORT_DEFINITION,
	E_MET_PDF_REPORT_DEFINITION,
	E_MET_CMD,
	E_MET_IMPORT_FUNCTION_DEFINITION,
	E_MET_IMPORT_LEGACY_DEFINITION,
	E_MET_FORMHANDLER_DEFINITION,
	E_MET_CLASS_DEFINITION
};


struct s_class_definition {
	str classname; 
	str parentname; 

	struct expr_str_list expression_list;
	variable_list public_variables;
	variable_list private_variables;
	module_entry_ptr class_entries<>;
};


struct s_import_function_definition {
	str funcname;
	int nparam;
	str module;
	int lineno;
	int colno;
};

struct s_import_legacy_definition {
	str funcname;
	str module;
	int lineno;
	int colno;
};

struct s_formhandler_definition {
	str formhandler_name;
	struct on_events *before_events;
	struct on_events *after_events;
	struct on_events *field_op_events;
	variable_list variables;
	struct expr_str_list* input_vars;
	str_list  *fields;
	lint_warning extra_warnings<>;
};

union module_entry switch (enum module_entry_type met_type)  {

	case E_MET_IMPORT_FUNCTION_DEFINITION: 	struct s_import_function_definition import_function_definition;
	case E_MET_IMPORT_LEGACY_DEFINITION: 	struct s_import_legacy_definition  	import_legacy_definition;

	/* The following is a fake comment so xgen_new can process it - DO NOT REMOVE THAT COMMENT! */
	case E_MET_MAIN_DEFINITION:   	/*! struct s_function_definition    function_definition; !*/
	case E_MET_FUNCTION_DEFINITION:   	struct s_function_definition 	function_definition;

	case E_MET_FORMHANDLER_DEFINITION:   	struct s_formhandler_definition 	formhandler_definition;

	case E_MET_REPORT_DEFINITION:		struct s_report_definition 	report_definition;
	case E_MET_PDF_REPORT_DEFINITION: 	struct s_pdf_report_definition 	pdf_report_definition;
	case E_MET_CLASS_DEFINITION: 		struct s_class_definition 	class_definition;
	
	case E_MET_CMD: 	struct command *cmd;

};


struct program_definition {
	struct module_definition  modules<>;
};



