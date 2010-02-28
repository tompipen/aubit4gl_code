//void linearise_commands_from_events(struct commands *master_list, struct on_events *evt_list);
struct s_commands *linearise_commands(struct s_commands *master_list, struct s_commands *cmds);
struct s_commands *linearise_report(struct s_commands *all_cmds, s_report_format_section *report_format_section);
void linearise_module(struct s_commands *all_cmds, module_definition *d);

