#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"
#include "cmd_funcs.h"
#include "fgl_enums.h"

char *decode_dt_display_type(enum dt_display_type value) {
 switch (value) {
 case DT_DISPLAY_TYPE_LINE: return "DT_DISPLAY_TYPE_LINE";
 case DT_DISPLAY_TYPE_AT  : return "DT_DISPLAY_TYPE_AT";
 case DT_DISPLAY_TYPE_MENUITEM: return "DT_DISPLAY_TYPE_MENUITEM";
 case DT_DISPLAY_TYPE_MAIN_CAPTION: return "DT_DISPLAY_TYPE_MAIN_CAPTION";
 case DT_DISPLAY_TYPE_FIELD_LIST: return "DT_DISPLAY_TYPE_FIELD_LIST";
 case DT_DISPLAY_TYPE_FORM_FIELD: return "DT_DISPLAY_TYPE_FORM_FIELD";
 case DT_DISPLAY_TYPE_FORM_CAPTION: return "DT_DISPLAY_TYPE_FORM_CAPTION";
 case DT_DISPLAY_TYPE_STATUSBOX: return "DT_DISPLAY_TYPE_STATUSBOX";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_cmd_type(enum cmd_type value) {
 switch (value) {
 case E_CMD_ALLOC_ARR_CMD : return "E_CMD_ALLOC_ARR_CMD";
 case E_CMD_AT_TERM_CMD   : return "E_CMD_AT_TERM_CMD";
 case E_CMD_CALL_CMD      : return "E_CMD_CALL_CMD";
 case E_CMD_CANCEL_CMD    : return "E_CMD_CANCEL_CMD";
 case E_CMD_CASE_CMD      : return "E_CMD_CASE_CMD";
 case E_CMD_CHECK_MENU_CMD: return "E_CMD_CHECK_MENU_CMD";
 case E_CMD_CLEAR_CMD     : return "E_CMD_CLEAR_CMD";
 case E_CMD_CLOSE_CMD     : return "E_CMD_CLOSE_CMD";
 case E_CMD_CLOSE_SQL_CMD : return "E_CMD_CLOSE_SQL_CMD";
 case E_CMD_CODE_CMD      : return "E_CMD_CODE_CMD";
 case E_CMD_CONNECT_CMD   : return "E_CMD_CONNECT_CMD";
 case E_CMD_CONSTRUCT_CMD : return "E_CMD_CONSTRUCT_CMD";
 case E_CMD_CONTINUE_CMD  : return "E_CMD_CONTINUE_CMD";
 case E_CMD_CONVERT_CMD   : return "E_CMD_CONVERT_CMD";
 case E_CMD_CURRENT_WIN_CMD: return "E_CMD_CURRENT_WIN_CMD";
 case E_CMD_DEALLOC_ARR_CMD: return "E_CMD_DEALLOC_ARR_CMD";
 case E_CMD_DECLARE_CMD   : return "E_CMD_DECLARE_CMD";
 case E_CMD_DEFER_CMD     : return "E_CMD_DEFER_CMD";
 case E_CMD_DISABLE_MENU_CMD: return "E_CMD_DISABLE_MENU_CMD";
 case E_CMD_DISPLAY_ARRAY_CMD: return "E_CMD_DISPLAY_ARRAY_CMD";
 case E_CMD_DISPLAY_B_N_CMD: return "E_CMD_DISPLAY_B_N_CMD";
 case E_CMD_DISPLAY_CMD   : return "E_CMD_DISPLAY_CMD";
 case E_CMD_DISPLAY_FORM_CMD: return "E_CMD_DISPLAY_FORM_CMD";
 case E_CMD_ENABLE_MENU_CMD: return "E_CMD_ENABLE_MENU_CMD";
 case E_CMD_ERROR_CMD     : return "E_CMD_ERROR_CMD";
 case E_CMD_EXECUTE_CMD   : return "E_CMD_EXECUTE_CMD";
 case E_CMD_EXECUTE_IMMEDIATE_CMD: return "E_CMD_EXECUTE_IMMEDIATE_CMD";
 case E_CMD_EXIT_PROG_CMD : return "E_CMD_EXIT_PROG_CMD";
 case E_CMD_EXT_CMD       : return "E_CMD_EXT_CMD";
 case E_CMD_FINISH_CMD    : return "E_CMD_FINISH_CMD";
 case E_CMD_FLUSH_CMD     : return "E_CMD_FLUSH_CMD";
 case E_CMD_FOREACH_CMD   : return "E_CMD_FOREACH_CMD";
 case E_CMD_FOR_CMD       : return "E_CMD_FOR_CMD";
 case E_CMD_FREE_CMD      : return "E_CMD_FREE_CMD";
 case E_CMD_FREE_REP_CMD  : return "E_CMD_FREE_REP_CMD";
 case E_CMD_GOTO_CMD      : return "E_CMD_GOTO_CMD";
 case E_CMD_HIDE_CMD      : return "E_CMD_HIDE_CMD";
 case E_CMD_HIDE_OPTION_CMD: return "E_CMD_HIDE_OPTION_CMD";
 case E_CMD_IF_CMD        : return "E_CMD_IF_CMD";
 case E_CMD_INIT_CMD      : return "E_CMD_INIT_CMD";
 case E_CMD_INPUT_ARRAY_CMD: return "E_CMD_INPUT_ARRAY_CMD";
 case E_CMD_INPUT_CMD     : return "E_CMD_INPUT_CMD";
 case E_CMD_LABEL_CMD     : return "E_CMD_LABEL_CMD";
 case E_CMD_LET_CMD       : return "E_CMD_LET_CMD";
 case E_CMD_LOAD_CMD      : return "E_CMD_LOAD_CMD";
 case E_CMD_LOCATE_CMD    : return "E_CMD_LOCATE_CMD";
 case E_CMD_MENU_CMD      : return "E_CMD_MENU_CMD";
 case E_CMD_MESSAGE_CMD   : return "E_CMD_MESSAGE_CMD";
 case E_CMD_MOVE_CMD      : return "E_CMD_MOVE_CMD";
 case E_CMD_MSG_BOX_CMD   : return "E_CMD_MSG_BOX_CMD";
 case E_CMD_NEED_CMD      : return "E_CMD_NEED_CMD";
 case E_CMD_NEXT_FIELD_CMD: return "E_CMD_NEXT_FIELD_CMD";
 case E_CMD_NEXT_FORM_CMD : return "E_CMD_NEXT_FORM_CMD";
 case E_CMD_NEXT_OPTION_CMD: return "E_CMD_NEXT_OPTION_CMD";
 case E_CMD_OPEN_CURSOR_CMD: return "E_CMD_OPEN_CURSOR_CMD";
 case E_CMD_OPEN_FORM_CMD : return "E_CMD_OPEN_FORM_CMD";
 case E_CMD_OPEN_FORM_GUI_CMD: return "E_CMD_OPEN_FORM_GUI_CMD";
 case E_CMD_OPEN_STATUSBOX_CMD: return "E_CMD_OPEN_STATUSBOX_CMD";
 case E_CMD_OPEN_WINDOW_CMD: return "E_CMD_OPEN_WINDOW_CMD";
 case E_CMD_OPTIONS_CMD   : return "E_CMD_OPTIONS_CMD";
 case E_CMD_OUTPUT_CMD    : return "E_CMD_OUTPUT_CMD";
 case E_CMD_PAUSE_CMD     : return "E_CMD_PAUSE_CMD";
 case E_CMD_PAUSE_SCREEN_OFF_CMD: return "E_CMD_PAUSE_SCREEN_OFF_CMD";
 case E_CMD_PAUSE_SCREEN_ON_CMD: return "E_CMD_PAUSE_SCREEN_ON_CMD";
 case E_CMD_PREPARE_CMD   : return "E_CMD_PREPARE_CMD";
 case E_CMD_PRINT_CMD     : return "E_CMD_PRINT_CMD";
 case E_CMD_PRINT_FILE_CMD: return "E_CMD_PRINT_FILE_CMD";
 case E_CMD_PRINT_IMG_CMD : return "E_CMD_PRINT_IMG_CMD";
 case E_CMD_PROMPT_CMD    : return "E_CMD_PROMPT_CMD";
 case E_CMD_PUT_CMD       : return "E_CMD_PUT_CMD";
 case E_CMD_RESIZE_ARR_CMD: return "E_CMD_RESIZE_ARR_CMD";
 case E_CMD_RETURN_CMD    : return "E_CMD_RETURN_CMD";
 case E_CMD_RUN_CMD       : return "E_CMD_RUN_CMD";
 case E_CMD_SCROLL_CMD    : return "E_CMD_SCROLL_CMD";
 case E_CMD_SET_DATABASE_CMD: return "E_CMD_SET_DATABASE_CMD";
 case E_CMD_SHOW_CMD      : return "E_CMD_SHOW_CMD";
 case E_CMD_SHOW_OPTION_CMD: return "E_CMD_SHOW_OPTION_CMD";
 case E_CMD_SKIP_BY_CMD   : return "E_CMD_SKIP_BY_CMD";
 case E_CMD_SKIP_CMD      : return "E_CMD_SKIP_CMD";
 case E_CMD_SKIP_TO_CMD   : return "E_CMD_SKIP_TO_CMD";
 case E_CMD_SKIP_TO_TOP_CMD: return "E_CMD_SKIP_TO_TOP_CMD";
 case E_CMD_SLEEP_CMD     : return "E_CMD_SLEEP_CMD";
 case E_CMD_SELECT_CMD    : return "E_CMD_SELECT_CMD";
 case E_CMD_SQL_BLOCK_CMD : return "E_CMD_SQL_BLOCK_CMD";
 case E_CMD_SQL_CMD       : return "E_CMD_SQL_CMD";
 case E_CMD_SQL_TRANSACT_CMD: return "E_CMD_SQL_TRANSACT_CMD";
 case E_CMD_START_CMD     : return "E_CMD_START_CMD";
 case E_CMD_START_RPC_CMD : return "E_CMD_START_RPC_CMD";
 case E_CMD_STOP_RPC_CMD  : return "E_CMD_STOP_RPC_CMD";
 case E_CMD_TERM_REP_CMD  : return "E_CMD_TERM_REP_CMD";
 case E_CMD_UNCHECK_MENU_CMD: return "E_CMD_UNCHECK_MENU_CMD";
 case E_CMD_UNLOAD_CMD    : return "E_CMD_UNLOAD_CMD";
 case E_CMD_VALIDATE_CMD  : return "E_CMD_VALIDATE_CMD";
 case E_CMD_WHENEVER_CMD  : return "E_CMD_WHENEVER_CMD";
 case E_CMD_SHOW_MENU_CMD : return "E_CMD_SHOW_MENU_CMD";
 case E_CMD_WHILE_CMD     : return "E_CMD_WHILE_CMD";
 case E_CMD_ENABLE_CMD    : return "E_CMD_ENABLE_CMD";
 case E_CMD_ENABLE_FORM_CMD: return "E_CMD_ENABLE_FORM_CMD";
 case E_CMD_DISABLE_CMD   : return "E_CMD_DISABLE_CMD";
 case E_CMD_DISABLE_FORM_CMD: return "E_CMD_DISABLE_FORM_CMD";
 case E_CMD_FETCH_CMD     : return "E_CMD_FETCH_CMD";
 case E_CMD_PDF_CALL_CMD  : return "E_CMD_PDF_CALL_CMD";
 case E_CMD_SET_SESSION_CMD: return "E_CMD_SET_SESSION_CMD";
 case E_CMD_UPDATE_CMD    : return "E_CMD_UPDATE_CMD";
 case E_CMD_INSERT_CMD    : return "E_CMD_INSERT_CMD";
 case E_CMD_DELETE_CMD    : return "E_CMD_DELETE_CMD";
 case E_CMD_LAST          : return "E_CMD_LAST";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_boolean(enum e_boolean value) {
 switch (value) {
 case EB_FALSE            : return "EB_FALSE";
 case EB_TRUE             : return "EB_TRUE";
 case EB_NOTSET           : return "EB_NOTSET";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_cancel_type(enum cancel_type value) {
 switch (value) {
 case CT_INSERT           : return "CT_INSERT";
 case CT_DELETE           : return "CT_DELETE";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_close_type_nosql(enum e_close_type_nosql value) {
 switch (value) {
 case E_CT_WINDOW         : return "E_CT_WINDOW";
 case E_CT_FORM           : return "E_CT_FORM";
 case E_CT_STATUSBOX      : return "E_CT_STATUSBOX";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_close_type_withsql(enum e_close_type_withsql value) {
 switch (value) {
 case E_CT_DATABASE       : return "E_CT_DATABASE";
 case E_CT_SESSION        : return "E_CT_SESSION";
 case E_CT_CURS_OR_PREP   : return "E_CT_CURS_OR_PREP";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_block_cmd(enum e_block_cmd value) {
 switch (value) {
 case EBC_WHILE           : return "EBC_WHILE";
 case EBC_FOR             : return "EBC_FOR";
 case EBC_INPUT           : return "EBC_INPUT";
 case EBC_FOREACH         : return "EBC_FOREACH";
 case EBC_CONSTRUCT       : return "EBC_CONSTRUCT";
 case EBC_DISPLAY         : return "EBC_DISPLAY";
 case EBC_MENU            : return "EBC_MENU";
 case EBC_PROMPT          : return "EBC_PROMPT";
 case EBC_CASE            : return "EBC_CASE";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_defer(enum e_defer value) {
 switch (value) {
 case EDEFER_QUIT         : return "EDEFER_QUIT";
 case EDEFER_INTERRUPT    : return "EDEFER_INTERRUPT";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_run_mode(enum run_mode value) {
 switch (value) {
 case ERM_NOT_SET         : return "ERM_NOT_SET";
 case ERM_LINE_MODE       : return "ERM_LINE_MODE";
 case ERM_FORM_MODE       : return "ERM_FORM_MODE";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_direction(enum e_direction value) {
 switch (value) {
 case E_UP                : return "E_UP";
 case E_DOWN              : return "E_DOWN";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_location(enum e_location value) {
 switch (value) {
 case E_LOC_FILE          : return "E_LOC_FILE";
 case E_LOC_MEMORY        : return "E_LOC_MEMORY";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_wintype(enum e_wintype value) {
 switch (value) {
 case EWT_FORM            : return "EWT_FORM";
 case EWT_ROWSCOLS        : return "EWT_ROWSCOLS";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_report_blocks(enum report_blocks value) {
 switch (value) {
 case RB_FIRST_PAGE_HEADER: return "RB_FIRST_PAGE_HEADER";
 case RB_PAGE_HEADER      : return "RB_PAGE_HEADER";
 case RB_PAGE_TRAILER     : return "RB_PAGE_TRAILER";
 case RB_ON_EVERY_ROW     : return "RB_ON_EVERY_ROW";
 case RB_ON_LAST_ROW      : return "RB_ON_LAST_ROW";
 case RB_BEFORE_GROUP_OF  : return "RB_BEFORE_GROUP_OF";
 case RB_AFTER_GROUP_OF   : return "RB_AFTER_GROUP_OF";
 case RB_FORMAT_EVERY_ROW : return "RB_FORMAT_EVERY_ROW";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_report_orderby(enum e_report_orderby value) {
 switch (value) {
 case REPORT_ORDERBY_IMPLICIT: return "REPORT_ORDERBY_IMPLICIT";
 case REPORT_ORDERBY_EXTERNAL: return "REPORT_ORDERBY_EXTERNAL";
 case REPORT_ORDERBY      : return "REPORT_ORDERBY";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_clear(enum e_clear value) {
 switch (value) {
 case E_CLR_SCREEN        : return "E_CLR_SCREEN";
 case E_CLR_WINDOW        : return "E_CLR_WINDOW";
 case E_CLR_STATUS        : return "E_CLR_STATUS";
 case E_CLR_FORM          : return "E_CLR_FORM";
 case E_CLR_FORM_DEFAULTS : return "E_CLR_FORM_DEFAULTS";
 case E_CLR_FIELDS        : return "E_CLR_FIELDS";
 case E_CLR_FIELDS_TO_DEFAULT: return "E_CLR_FIELDS_TO_DEFAULT";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_event(enum e_event value) {
 switch (value) {
 case EVENT_BEF_ROW       : return "EVENT_BEF_ROW";
 case EVENT_AFT_ROW       : return "EVENT_AFT_ROW";
 case EVENT_BEFORE_DELETE : return "EVENT_BEFORE_DELETE";
 case EVENT_AFTER_DELETE  : return "EVENT_AFTER_DELETE";
 case EVENT_BEFORE_INSERT : return "EVENT_BEFORE_INSERT";
 case EVENT_AFTER_INSERT  : return "EVENT_AFTER_INSERT";
 case EVENT_BEFORE_INSERT_DELETE: return "EVENT_BEFORE_INSERT_DELETE";
 case EVENT_AFTER_INSERT_DELETE: return "EVENT_AFTER_INSERT_DELETE";
 case EVENT_ON_IDLE       : return "EVENT_ON_IDLE";
 case EVENT_ON_INTERVAL   : return "EVENT_ON_INTERVAL";
 case EVENT_ON_TIME       : return "EVENT_ON_TIME";
 case EVENT_KEY_PRESS     : return "EVENT_KEY_PRESS";
 case EVENT_ANYKEY_PRESS  : return "EVENT_ANYKEY_PRESS";
 case EVENT_ON_ACTION     : return "EVENT_ON_ACTION";
 case EVENT_AFTER_INPUT   : return "EVENT_AFTER_INPUT";
 case EVENT_BEFORE_INPUT  : return "EVENT_BEFORE_INPUT";
 case EVENT_BEFORE_FIELD  : return "EVENT_BEFORE_FIELD";
 case EVENT_AFTER_DISPLAY : return "EVENT_AFTER_DISPLAY";
 case EVENT_BEFORE_DISPLAY: return "EVENT_BEFORE_DISPLAY";
 case EVENT_AFTER_CONSTRUCT: return "EVENT_AFTER_CONSTRUCT";
 case EVENT_BEFORE_CONSTRUCT: return "EVENT_BEFORE_CONSTRUCT";
 case EVENT_BEFORE_MENU   : return "EVENT_BEFORE_MENU";
 case EVENT_AFTER_FIELD   : return "EVENT_AFTER_FIELD";
 case EVENT_MENU_COMMAND  : return "EVENT_MENU_COMMAND";
 case EVENT_BEFORE_OPEN_FORM: return "EVENT_BEFORE_OPEN_FORM";
 case EVENT_AFTER_EVENT   : return "EVENT_AFTER_EVENT";
 case EVENT_BEFORE_CLOSE_FORM: return "EVENT_BEFORE_CLOSE_FORM";
 case EVENT_BEFORE_ANY    : return "EVENT_BEFORE_ANY";
 case EVENT_AFTER_ANY     : return "EVENT_AFTER_ANY";
 case EVENT_BEFORE        : return "EVENT_BEFORE";
 case EVENT_AFTER         : return "EVENT_AFTER";
 case EVENT_BEFORE_EVENT  : return "EVENT_BEFORE_EVENT";
 case EVENT_ON            : return "EVENT_ON";
 case EVENT_AFTER_INP_CLEAN: return "EVENT_AFTER_INP_CLEAN";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_constant_type(enum e_constant_type value) {
 switch (value) {
 case CONST_TYPE_CHAR     : return "CONST_TYPE_CHAR";
 case CONST_TYPE_FLOAT    : return "CONST_TYPE_FLOAT";
 case CONST_TYPE_INTEGER  : return "CONST_TYPE_INTEGER";
 case CONST_TYPE_IDENT    : return "CONST_TYPE_IDENT";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_variable_type(enum e_variable_type value) {
 switch (value) {
 case VARIABLE_TYPE_SIMPLE: return "VARIABLE_TYPE_SIMPLE";
 case VARIABLE_TYPE_RECORD: return "VARIABLE_TYPE_RECORD";
 case VARIABLE_TYPE_ASSOC : return "VARIABLE_TYPE_ASSOC";
 case VARIABLE_TYPE_CONSTANT: return "VARIABLE_TYPE_CONSTANT";
 case VARIABLE_TYPE_FUNCTION_DECLARE: return "VARIABLE_TYPE_FUNCTION_DECLARE";
 case VARIABLE_TYPE_OBJECT: return "VARIABLE_TYPE_OBJECT";
 case VARIABLE_TYPE_LINKED: return "VARIABLE_TYPE_LINKED";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_flist_type(enum flist_type value) {
 switch (value) {
 case FLIST_NORMAL        : return "FLIST_NORMAL";
 case FLIST_SPECIAL       : return "FLIST_SPECIAL";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_expr_type(enum e_expr_type value) {
 switch (value) {
 case ET_EXPR_EXPR_LIST   : return "ET_EXPR_EXPR_LIST";
 case ET_EXPR_STRING      : return "ET_EXPR_STRING";
 case ET_EXPR_TODAY       : return "ET_EXPR_TODAY";
 case ET_EXPR_TIME        : return "ET_EXPR_TIME";
 case ET_EXPR_LINENO      : return "ET_EXPR_LINENO";
 case ET_EXPR_PAGENO      : return "ET_EXPR_PAGENO";
 case ET_EXPR_TIME_EXPR   : return "ET_EXPR_TIME_EXPR";
 case ET_EXPR_DATE_EXPR   : return "ET_EXPR_DATE_EXPR";
 case ET_EXPR_NULL        : return "ET_EXPR_NULL";
 case ET_EXPR_TRUE        : return "ET_EXPR_TRUE";
 case ET_EXPR_FALSE       : return "ET_EXPR_FALSE";
 case ET_EXPR_NOT         : return "ET_EXPR_NOT";
 case ET_EXPR_UPSHIFT     : return "ET_EXPR_UPSHIFT";
 case ET_EXPR_DOWNSHIFT   : return "ET_EXPR_DOWNSHIFT";
 case ET_EXPR_EXTEND      : return "ET_EXPR_EXTEND";
 case ET_EXPR_ASCII       : return "ET_EXPR_ASCII";
 case ET_EXPR_MM          : return "ET_EXPR_MM";
 case ET_EXPR_POINTS      : return "ET_EXPR_POINTS";
 case ET_EXPR_INCHES      : return "ET_EXPR_INCHES";
 case ET_EXPR_CURRENT     : return "ET_EXPR_CURRENT";
 case ET_EXPR_OP_MULT     : return "ET_EXPR_OP_MULT";
 case ET_EXPR_OP_DIV      : return "ET_EXPR_OP_DIV";
 case ET_EXPR_OP_POWER    : return "ET_EXPR_OP_POWER";
 case ET_EXPR_OP_ADD      : return "ET_EXPR_OP_ADD";
 case ET_EXPR_OP_SUB      : return "ET_EXPR_OP_SUB";
 case ET_EXPR_OP_EQUAL    : return "ET_EXPR_OP_EQUAL";
 case ET_EXPR_OP_NOT_EQUAL: return "ET_EXPR_OP_NOT_EQUAL";
 case ET_EXPR_OP_MOD      : return "ET_EXPR_OP_MOD";
 case ET_EXPR_OP_USING    : return "ET_EXPR_OP_USING";
 case ET_EXPR_OP_LIKE     : return "ET_EXPR_OP_LIKE";
 case ET_EXPR_OP_NOT_LIKE : return "ET_EXPR_OP_NOT_LIKE";
 case ET_EXPR_OP_IN       : return "ET_EXPR_OP_IN";
 case ET_EXPR_OP_NOT_IN   : return "ET_EXPR_OP_NOT_IN";
 case ET_EXPR_OP_CONCAT   : return "ET_EXPR_OP_CONCAT";
 case ET_EXPR_OP_MATCHES  : return "ET_EXPR_OP_MATCHES";
 case ET_EXPR_OP_NOT_MATCHES: return "ET_EXPR_OP_NOT_MATCHES";
 case ET_EXPR_OP_CLIP     : return "ET_EXPR_OP_CLIP";
 case ET_EXPR_OP_LESS_THAN: return "ET_EXPR_OP_LESS_THAN";
 case ET_EXPR_OP_LESS_THAN_EQ: return "ET_EXPR_OP_LESS_THAN_EQ";
 case ET_EXPR_OP_GREATER_THAN: return "ET_EXPR_OP_GREATER_THAN";
 case ET_EXPR_OP_GREATER_THAN_EQ: return "ET_EXPR_OP_GREATER_THAN_EQ";
 case ET_EXPR_OP_YEAR     : return "ET_EXPR_OP_YEAR";
 case ET_EXPR_OP_MONTH    : return "ET_EXPR_OP_MONTH";
 case ET_EXPR_OP_DAY      : return "ET_EXPR_OP_DAY";
 case ET_EXPR_OP_HOUR     : return "ET_EXPR_OP_HOUR";
 case ET_EXPR_OP_MINUTE   : return "ET_EXPR_OP_MINUTE";
 case ET_EXPR_OP_SECOND   : return "ET_EXPR_OP_SECOND";
 case ET_EXPR_OP_ISNULL   : return "ET_EXPR_OP_ISNULL";
 case ET_EXPR_OP_ISNOTNULL: return "ET_EXPR_OP_ISNOTNULL";
 case ET_EXPR_OP_SPACES   : return "ET_EXPR_OP_SPACES";
 case ET_EXPR_OP_AND      : return "ET_EXPR_OP_AND";
 case ET_EXPR_OP_OR       : return "ET_EXPR_OP_OR";
 case ET_EXPR_NEG         : return "ET_EXPR_NEG";
 case ET_EXPR_FCALL       : return "ET_EXPR_FCALL";
 case ET_EXPR_PDF_FCALL   : return "ET_EXPR_PDF_FCALL";
 case ET_EXPR_SHARED_FCALL: return "ET_EXPR_SHARED_FCALL";
 case ET_EXPR_MEMBER_FCALL: return "ET_EXPR_MEMBER_FCALL";
 case ET_EXPR_COLUMN      : return "ET_EXPR_COLUMN";
 case ET_EXPR_REPORT_EMAIL: return "ET_EXPR_REPORT_EMAIL";
 case ET_EXPR_REPORT_PRINTER: return "ET_EXPR_REPORT_PRINTER";
 case ET_EXPR_QUOTED_STRING: return "ET_EXPR_QUOTED_STRING";
 case ET_EXPR_TRANSLATED_STRING: return "ET_EXPR_TRANSLATED_STRING";
 case ET_EXPR_LITERAL_DOUBLE_STR: return "ET_EXPR_LITERAL_DOUBLE_STR";
 case ET_EXPR_LITERAL_LONG: return "ET_EXPR_LITERAL_LONG";
 case ET_EXPR_LITERAL_STRING: return "ET_EXPR_LITERAL_STRING";
 case ET_EXPR_LITERAL_EMPTY_STRING: return "ET_EXPR_LITERAL_EMPTY_STRING";
 case ET_EXPR_REDUCED     : return "ET_EXPR_REDUCED";
 case ET_EXPR_EXTERNAL    : return "ET_EXPR_EXTERNAL";
 case ET_EXPR_GET_FLDBUF  : return "ET_EXPR_GET_FLDBUF";
 case ET_EXPR_WORDWRAP    : return "ET_EXPR_WORDWRAP";
 case ET_EXPR_NOT_EXISTS_SUBQUERY: return "ET_EXPR_NOT_EXISTS_SUBQUERY";
 case ET_EXPR_EXISTS_SUBQUERY: return "ET_EXPR_EXISTS_SUBQUERY";
 case ET_EXPR_OP_IN_SUBQUERY: return "ET_EXPR_OP_IN_SUBQUERY";
 case ET_EXPR_OP_NOTIN_SUBQUERY: return "ET_EXPR_OP_NOTIN_SUBQUERY";
 case ET_EXPR_CAST        : return "ET_EXPR_CAST";
 case ET_EXPR_CONCAT_LIST : return "ET_EXPR_CONCAT_LIST";
 case ET_EXPR_YEAR_FUNC   : return "ET_EXPR_YEAR_FUNC";
 case ET_EXPR_MONTH_FUNC  : return "ET_EXPR_MONTH_FUNC";
 case ET_EXPR_DAY_FUNC    : return "ET_EXPR_DAY_FUNC";
 case ET_EXPR_DATE_FUNC   : return "ET_EXPR_DATE_FUNC";
 case ET_EXPR_TIME_FUNC   : return "ET_EXPR_TIME_FUNC";
 case ET_EXPR_DTVAL       : return "ET_EXPR_DTVAL";
 case ET_EXPR_INFIELD     : return "ET_EXPR_INFIELD";
 case ET_EXPR_FIELD_TOUCHED: return "ET_EXPR_FIELD_TOUCHED";
 case ET_EXPR_NOT_FIELD_TOUCHED: return "ET_EXPR_NOT_FIELD_TOUCHED";
 case ET_EXPR_IVAL_VAL    : return "ET_EXPR_IVAL_VAL";
 case ET_EXPR_TEMP        : return "ET_EXPR_TEMP";
 case ET_EXPR_BOUND_FCALL : return "ET_EXPR_BOUND_FCALL";
 case ET_EXPR_AGGREGATE   : return "ET_EXPR_AGGREGATE";
 case ET_EXPR_FGL_SIZEOF  : return "ET_EXPR_FGL_SIZEOF";
 case ET_EXPR_FGL_ADDRESSOF: return "ET_EXPR_FGL_ADDRESSOF";
 case ET_EXPR_FGL_ISDYNARR_ALLOCATED: return "ET_EXPR_FGL_ISDYNARR_ALLOCATED";
 case ET_EXPR_FGL_DYNARR_EXTENTSIZE: return "ET_EXPR_FGL_DYNARR_EXTENTSIZE";
 case ET_EXPR_FIELDTOWIDGET: return "ET_EXPR_FIELDTOWIDGET";
 case ET_EXPR_ID_TO_INT   : return "ET_EXPR_ID_TO_INT";
 case ET_EXPR_FIELDNAME   : return "ET_EXPR_FIELDNAME";
 case ET_EXPR_MODULE_FUNC : return "ET_EXPR_MODULE_FUNC";
 case ET_EXPR_IDENTIFIER  : return "ET_EXPR_IDENTIFIER";
 case ET_EXPR_PARAMETER   : return "ET_EXPR_PARAMETER";
 case ET_EXPR_VARIABLE_IDENTIFIER: return "ET_EXPR_VARIABLE_IDENTIFIER";
 case ET_EXPR_CACHED      : return "ET_EXPR_CACHED";
 case ET_EXPR_MENU_ALL    : return "ET_EXPR_MENU_ALL";
 case ET_EXPR_VARIABLE_USAGE: return "ET_EXPR_VARIABLE_USAGE";
 case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC: return "ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC";
 case ET_EXPR_SQLBLOCK    : return "ET_EXPR_SQLBLOCK";
 case ET_EXPR_SQLBLOCK_TEXT: return "ET_EXPR_SQLBLOCK_TEXT";
 case ET_EXPR_SQLBLOCK_INTO: return "ET_EXPR_SQLBLOCK_INTO";
 case ET_EXPR_SELECT_LIST_ITEM: return "ET_EXPR_SELECT_LIST_ITEM";
 case ET_EXPR_BRACKET     : return "ET_EXPR_BRACKET";
 case ET_E_V_OR_LIT_VAR   : return "ET_E_V_OR_LIT_VAR";
 case ET_E_V_OR_LIT_INT   : return "ET_E_V_OR_LIT_INT";
 case ET_E_V_OR_LIT_STRING: return "ET_E_V_OR_LIT_STRING";
 case ET_E_V_OR_LIT_VAR_AS_STRING: return "ET_E_V_OR_LIT_VAR_AS_STRING";
 case ET_E_V_OR_LIT_IDENT : return "ET_E_V_OR_LIT_IDENT";
 case ET_E_V_OR_LIT_NOVALUE: return "ET_E_V_OR_LIT_NOVALUE";
 case ET_EXPR_THROUGH     : return "ET_EXPR_THROUGH";
 case ET_EXPR_WHERE_CURRENT_OF: return "ET_EXPR_WHERE_CURRENT_OF";
 case ET_EXPR_LAST        : return "ET_EXPR_LAST";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_subtype(enum subtype value) {
 switch (value) {
 case ST_INT              : return "ST_INT";
 case ST_EXPR             : return "ST_EXPR";
 case ST_VAR              : return "ST_VAR";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_e_sli(enum e_sli value) {
 switch (value) {
 case E_SLI_CHAR          : return "E_SLI_CHAR";
 case E_SLI_COLUMN        : return "E_SLI_COLUMN";
 case E_SLI_SUBQUERY_EXPRESSION: return "E_SLI_SUBQUERY_EXPRESSION";
 case E_SLI_BUILTIN_CONST_TRUE: return "E_SLI_BUILTIN_CONST_TRUE";
 case E_SLI_BUILTIN_CONST_FALSE: return "E_SLI_BUILTIN_CONST_FALSE";
 case E_SLI_BUILTIN_CONST_USER: return "E_SLI_BUILTIN_CONST_USER";
 case E_SLI_BUILTIN_CONST_TODAY: return "E_SLI_BUILTIN_CONST_TODAY";
 case E_SLI_BUILTIN_CONST_STAR: return "E_SLI_BUILTIN_CONST_STAR";
 case E_SLI_BUILTIN_CONST_COUNT_STAR: return "E_SLI_BUILTIN_CONST_COUNT_STAR";
 case E_SLI_BUILTIN_CONST_CURRENT: return "E_SLI_BUILTIN_CONST_CURRENT";
 case E_SLI_BUILTIN_CONST_ROWID: return "E_SLI_BUILTIN_CONST_ROWID";
 case E_SLI_BUILTIN_FUNC_YEAR: return "E_SLI_BUILTIN_FUNC_YEAR";
 case E_SLI_BUILTIN_FUNC_MONTH: return "E_SLI_BUILTIN_FUNC_MONTH";
 case E_SLI_BUILTIN_FUNC_DAY: return "E_SLI_BUILTIN_FUNC_DAY";
 case E_SLI_BUILTIN_FUNC_MDY: return "E_SLI_BUILTIN_FUNC_MDY";
 case E_SLI_BUILTIN_FUNC_WEEKDAY: return "E_SLI_BUILTIN_FUNC_WEEKDAY";
 case E_SLI_BUILTIN_FUNC_DOW: return "E_SLI_BUILTIN_FUNC_DOW";
 case E_SLI_BUILTIN_FUNC_DATE: return "E_SLI_BUILTIN_FUNC_DATE";
 case E_SLI_BUILTIN_AGG_AVG: return "E_SLI_BUILTIN_AGG_AVG";
 case E_SLI_BUILTIN_AGG_MAX: return "E_SLI_BUILTIN_AGG_MAX";
 case E_SLI_BUILTIN_AGG_MIN: return "E_SLI_BUILTIN_AGG_MIN";
 case E_SLI_BUILTIN_AGG_SUM: return "E_SLI_BUILTIN_AGG_SUM";
 case E_SLI_BUILTIN_AGG_COUNT: return "E_SLI_BUILTIN_AGG_COUNT";
 case E_SLI_BRACKET_EXPR  : return "E_SLI_BRACKET_EXPR";
 case E_SLI_UNITS_YEAR    : return "E_SLI_UNITS_YEAR";
 case E_SLI_UNITS_MONTH   : return "E_SLI_UNITS_MONTH";
 case E_SLI_UNITS_DAY     : return "E_SLI_UNITS_DAY";
 case E_SLI_UNITS_HOUR    : return "E_SLI_UNITS_HOUR";
 case E_SLI_UNITS_MINUTE  : return "E_SLI_UNITS_MINUTE";
 case E_SLI_UNITS_SECOND  : return "E_SLI_UNITS_SECOND";
 case E_SLI_OP            : return "E_SLI_OP";
 case E_SLI_BETWEEN       : return "E_SLI_BETWEEN";
 case E_SLI_NOT_BETWEEN   : return "E_SLI_NOT_BETWEEN";
 case E_SLI_DATETIME      : return "E_SLI_DATETIME";
 case E_SLI_INTERVAL      : return "E_SLI_INTERVAL";
 case E_SLI_EXTEND        : return "E_SLI_EXTEND";
 case E_SLI_LITERAL       : return "E_SLI_LITERAL";
 case E_SLI_IN_VALUES     : return "E_SLI_IN_VALUES";
 case E_SLI_IN_SELECT     : return "E_SLI_IN_SELECT";
 case E_SLI_NOT_IN_VALUES : return "E_SLI_NOT_IN_VALUES";
 case E_SLI_NOT_IN_SELECT : return "E_SLI_NOT_IN_SELECT";
 case E_SLI_ISNULL        : return "E_SLI_ISNULL";
 case E_SLI_ISNOTNULL     : return "E_SLI_ISNOTNULL";
 case E_SLI_NOT           : return "E_SLI_NOT";
 case E_SLI_REGEX_LIKE    : return "E_SLI_REGEX_LIKE";
 case E_SLI_REGEX_NOT_LIKE: return "E_SLI_REGEX_NOT_LIKE";
 case E_SLI_REGEX_MATCHES : return "E_SLI_REGEX_MATCHES";
 case E_SLI_REGEX_NOT_MATCHES: return "E_SLI_REGEX_NOT_MATCHES";
 case E_SLI_REGEX_ILIKE   : return "E_SLI_REGEX_ILIKE";
 case E_SLI_REGEX_NOT_ILIKE: return "E_SLI_REGEX_NOT_ILIKE";
 case E_SLI_FCALL         : return "E_SLI_FCALL";
 case E_SLI_ASC           : return "E_SLI_ASC";
 case E_SLI_DESC          : return "E_SLI_DESC";
 case E_SLI_IBIND         : return "E_SLI_IBIND";
 case E_SLI_COLUMN_NOT_TRANSFORMED: return "E_SLI_COLUMN_NOT_TRANSFORMED";
 case E_SLI_VARIABLE      : return "E_SLI_VARIABLE";
 case E_SLI_QUERY         : return "E_SLI_QUERY";
 case E_SLI_SUBQUERY      : return "E_SLI_SUBQUERY";
 case E_SLI_QUERY_PLACEHOLDER: return "E_SLI_QUERY_PLACEHOLDER";
 case E_SLI_JOIN          : return "E_SLI_JOIN";
 case E_SLI_CASE          : return "E_SLI_CASE";
 case E_SLI_CASE_ELEMENT  : return "E_SLI_CASE_ELEMENT";
 case E_SLI_COLUMN_ORDERBY: return "E_SLI_COLUMN_ORDERBY";
 case E_SLI_VAR_REPLACE   : return "E_SLI_VAR_REPLACE";
 case E_SLI_BUILTIN_CONST_TIME: return "E_SLI_BUILTIN_CONST_TIME";
 case E_SLI_BUILTIN_CONST_NULL: return "E_SLI_BUILTIN_CONST_NULL";
 case E_SLI_VARIABLE_USAGE: return "E_SLI_VARIABLE_USAGE";
 case E_SLI_VARIABLE_USAGE_IN_SELECT_LIST: return "E_SLI_VARIABLE_USAGE_IN_SELECT_LIST";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_sq_expression_type(enum sq_expression_type value) {
 switch (value) {
 case E_SQE_DONT_CARE     : return "E_SQE_DONT_CARE";
 case E_SQE_ALL           : return "E_SQE_ALL";
 case E_SQE_ANY           : return "E_SQE_ANY";
 case E_SQE_SOME          : return "E_SQE_SOME";
 case E_SQE_EXISTS        : return "E_SQE_EXISTS";
 case E_SQE_NOT_EXISTS    : return "E_SQE_NOT_EXISTS";
 default: return "Unhandled";
 } /* end of switch */
}
char *decode_module_entry_type(enum module_entry_type value) {
 switch (value) {
 case E_MET_FUNCTION_DEFINITION: return "E_MET_FUNCTION_DEFINITION";
 case E_MET_MAIN_DEFINITION: return "E_MET_MAIN_DEFINITION";
 case E_MET_REPORT_DEFINITION: return "E_MET_REPORT_DEFINITION";
 case E_MET_PDF_REPORT_DEFINITION: return "E_MET_PDF_REPORT_DEFINITION";
 case E_MET_CMD           : return "E_MET_CMD";
 case E_MET_IMPORT_FUNCTION_DEFINITION: return "E_MET_IMPORT_FUNCTION_DEFINITION";
 case E_MET_IMPORT_LEGACY_DEFINITION: return "E_MET_IMPORT_LEGACY_DEFINITION";
 case E_MET_FORMHANDLER_DEFINITION: return "E_MET_FORMHANDLER_DEFINITION";
 case E_MET_CLASS_DEFINITION: return "E_MET_CLASS_DEFINITION";
 default: return "Unhandled";
 } /* end of switch */
}
