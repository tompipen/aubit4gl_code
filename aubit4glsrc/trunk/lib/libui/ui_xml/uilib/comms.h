int get_ui_id(char c);
int connect_ui(void);
void send_to_ui(char *s, ...);
int get_event_from_ui(void);
void flush_ui(void);

