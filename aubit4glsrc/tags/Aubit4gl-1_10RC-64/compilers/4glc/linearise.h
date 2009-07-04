void linearise_commands_from_events(struct commands *master_list, struct on_events *evt_list);
struct commands *linearise_commands(struct commands *master_list, struct commands *cmds);
struct commands *linearise_report(struct commands *all_cmds, report_format_section *report_format_section);
void linearise_module(struct commands *all_cmds, module_definition *d);

