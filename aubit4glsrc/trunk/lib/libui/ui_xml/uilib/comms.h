#include "contexts.h"

int get_ui_id(char c);
int connect_ui(void);
void send_to_ui(char *s, ...);
void send_to_ui_no_nl(char *s, ...);
int get_event_from_ui(struct ui_context *context);
void flush_ui(void);
void cleanup(void);
int connect_ui_noproxy (void);
int connect_ui_proxy (void);
int getMyId(void);
int havePendingTriggers(struct ui_context *context);

#define ID_FRONTCALLRETURN -123




