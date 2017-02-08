#ifndef _A4GL_CONTEXTS_H
#define _A4GL_CONTEXTS_H
enum ui_state
{
  UI_NOT_INITIALIZED,
  UI_WANT_BEFORE_MENU,
  UI_WANT_BEFORE_INPUT,
  UI_INITIALIZED,
  UI_FREE,
  UI_AFTER_BEFORE_MENU
};


struct uiinput
{
  int nfields;
  int *changed;
  char **variable_data;
  char *setfield;
  int num_field_data;
  char **field_data;
  char *infield;
  int *touched;
};


struct uiconstruct
{
  char *constr_clause;
  char *setfield;
  int num_field_data;
  char **field_data;
  char **field_content_data;
  char *infield;
  int *touched;
};

struct uimenu
{
  char *menutitle;

};

struct uidisplayarray
{
  int count;
  int scr_line;
  int arr_line;
};


struct uiinputarray
{
  int count;
  int scr_line;
  int arr_line;
  int maxarrsize;
  int nvals;
  char *setfield;
  char ***variable_data;
  int *changed_rows;
  int num_field_data;
  char **field_data;
  char *infield;
  int **touched;
};

struct uiprompt
{
  char *promptresult;
};

enum uitype
{
  UIFREE,
  UIMENU,
  UIINPUT,
  UIPROMPT,
  UICONSTRUCT,
  UIDISPLAYARRAY,
  UIINPUTARRAY
};

struct ui_context
{
  enum uitype type;
  enum ui_state state;
  char *modulename;
  int lineno;
  char *pendingTriggereds[1000];
  int nPendingTriggereds;

  union
  {
    struct uimenu menu;
    struct uiinput input;
    struct uiprompt prompt;
    struct uiconstruct construct;
    struct uidisplayarray displayarray;
    struct uiinputarray inputarray;
  } ui;
};

#endif
