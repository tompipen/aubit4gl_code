#include "fgicfunc.h"
#include "uilib.h"

cfunc_t usrcfuncs[] = { 
{"uilib_start",uilib_start,-1},
{"uilib_program_exit",uilib_program_exit,-1},
{"uilib_clear_screen",uilib_clear_screen,-1},
{"uilib_clear_window",uilib_clear_window,-1},
{"uilib_set_field_list",uilib_set_field_list,-1},
{"uilib_display_values",uilib_display_values,-1},
{"uilib_clear_fields",uilib_clear_fields,-1},
{"uilib_clear_form",uilib_clear_form,-1},
{"uilib_close_form",uilib_close_form,-1},
{"uilib_close_window",uilib_close_window,-1},
{"uilib_error",uilib_error,-1},
{"uilib_message",uilib_message,-1},
{"uilib_displayat",uilib_displayat,-1},
{"uilib_current_window",uilib_current_window,-1},
{"uilib_display",uilib_display,-1},
{"uilib_options",uilib_options,2},
{"uilib_open_form",uilib_open_form,-1},
{"uilib_display_form",uilib_display_form,-1},
{"uilib_sleep",uilib_sleep,-1},
{"uilib_open_window_with_form",uilib_open_window_with_form,5},
{"uilib_prompt_start",uilib_prompt_start,-1},
{"uilib_prompt_initialised",uilib_prompt_initialised,-1},
{"uilib_prompt_loop",uilib_prompt_loop,-1},
{"uilib_get_prompt_result",uilib_get_prompt_result,-1},
{"uilib_free_prompt",uilib_free_prompt,-1},
{"uilib_event",uilib_event,3},
{"uilib_start_events",uilib_start_events,0},
{"uilib_end_events",uilib_end_events,0},
{"uilib_hide_option",uilib_hide_option,2},
{"uilib_show_option",uilib_show_option,2},
{"uilib_next_option",uilib_next_option,2},
{"uilib_menu_add",uilib_menu_add,6},
{"uilib_free_menu",uilib_free_menu,-1},
{"uilib_menu_loop",uilib_menu_loop,-1},
{"uilib_menu_start",uilib_menu_start,3},
{"uilib_menu_initialised",uilib_menu_initialised,-1},
{"uilib_free_input",uilib_free_input,-1},
{"uilib_input_get_values",uilib_input_get_values,-1},
{"uilib_input_loop",uilib_input_loop,-100},
{"uilib_input_start",uilib_input_start,4},
{"uilib_input_initialised",uilib_input_initialised,-1},
{"uilib_next_field",uilib_next_field,-1},
{"uilib_construct_start",uilib_construct_start,-1},
{"uilib_construct_loop",uilib_construct_loop,-1},
{"uilib_construct_query",uilib_construct_query,-1},
{"uilib_free_construct",uilib_free_construct,-1},
{"uilib_construct_initialised",uilib_construct_initialised,-1},
{"uilib_get_context",uilib_get_context,2},
{"uilib_clear",uilib_clear,0},
{"uilib_clear_to_defaults",uilib_clear_to_defaults,0},


{"uilib_set_count", uilib_set_count,1},
{"uilib_arr_count", uilib_arr_count,0},
{"uilib_scr_line", uilib_scr_line,0},
{"uilib_arr_curr", uilib_arr_curr,0},
{"uilib_display_array_line", uilib_display_array_line,-100},
{"uilib_display_array_initialised", uilib_display_array_initialised,0},
{"uilib_array_lines_end", uilib_array_lines_end,0},
{"uilib_array_lines_start", uilib_array_lines_start,0},
{"uilib_display_array_loop", uilib_display_array_loop,1},
{"uilib_display_array_start", uilib_display_array_start,3},

{"uilib_input_array_start", uilib_input_array_start,6},
{"uilib_input_array_sync", uilib_input_array_sync ,-100},
{"uilib_input_array_loop", uilib_input_array_loop,1},
{"uilib_has_array_values", uilib_has_array_values,1},
{"uilib_input_get_array_values", uilib_input_get_array_values,2},
{"uilib_input_array_initialised", uilib_input_array_initialised,0},
{"uilib_free_input_array", uilib_free_input_array,1},



{0, 0, 0} 
};

#ifndef PLATFORM_HP_UX
int popstring(char *x, int y) {
                    return ibm_lib4gl_popString(x, y);
}


int pushquote(char *x, int y) {
                    return ibm_lib4gl_pushQuotedStr(x, y);
}

int pushint(int *x){
                         return ibm_lib4gl_pushMInt(x);
}

int popint(int *x) {
                          return ibm_lib4gl_popMInt(x);
}
#endif


void
trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
        break;
      p[a] = 0;
    }
}

