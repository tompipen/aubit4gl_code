#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"



void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) {
int a;

A4GL_assertion(master_list==0, "Master list not set");

if (evt_list==0) return;

for (a=0;a<evt_list->event.event_len;a++) {
        linearise_commands(master_list, evt_list->event.event_val[a]->on_event_commands);
}

}

struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) {
int a;
int cnt;
struct on_events* evt_list;

        if (master_list==0) {
                master_list=malloc(sizeof(struct commands));
                master_list->cmds.cmds_val=0;
                master_list->cmds.cmds_len=0;
        }
        if (cmds==0) return master_list;

        for (a=0;a<cmds->cmds.cmds_len;a++) {

                master_list->cmds.cmds_len++;
                master_list->cmds.cmds_val=realloc(master_list->cmds.cmds_val, sizeof(struct command)* master_list->cmds.cmds_len);
                master_list->cmds.cmds_val[master_list->cmds.cmds_len-1]=cmds->cmds.cmds_val[a];

                switch ( cmds->cmds.cmds_val[a]->cmd_data.type) {
                        case E_CMD_FOR_CMD:
                                linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands);
                                break;

                        case E_CMD_IF_CMD:
                                for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len;cnt++) {
                                        linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[cnt].whentrue);
                                }
                                linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse);
                                break;

                        case E_CMD_FOREACH_CMD:
                                linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands);
                                break;

                        case E_CMD_WHILE_CMD:
                                linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands);
                                break;


                        case E_CMD_CASE_CMD:
                                for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len ;cnt++) {
                                        linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->when_commands);
                                }
                                linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise);
                                break;


                        case E_CMD_MENU_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;
                        case E_CMD_PROMPT_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;

                        case E_CMD_DISPLAY_ARRAY_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;

                        case E_CMD_INPUT_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;

                        case E_CMD_INPUT_ARRAY_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;
                        case E_CMD_CONSTRUCT_CMD:
                                evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
                                linearise_commands_from_events(master_list, evt_list);
                                break;

                        default :
                                // dont need to do anything - these don't embed Commands..
                                break;
                }

        }

return master_list;
}


struct commands *linearise_report(struct commands *all_cmds, report_format_section *report_format_section) {
int b;
        if (all_cmds==0) {
          all_cmds = linearise_commands (0, 0);
        }
          for (b = 0; b < report_format_section->entries.entries_len; b++)
            {
              linearise_commands (all_cmds, report_format_section->entries.  entries_val[b]->rep_sec_commands);
            }
        return all_cmds;
}

void linearise_module(struct commands *all_cmds, module_definition *d) {
int a;
//int b;
   for (a=0;a<d->module_entries.module_entries_len;a++) {
                //struct s_function_definition *f;


        switch (d->module_entries.module_entries_val[a]->met_type) {

                case E_MET_MAIN_DEFINITION:
                case E_MET_FUNCTION_DEFINITION:
                        linearise_commands(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.function_definition.func_commands);
                        break;

                case E_MET_REPORT_DEFINITION:
                        linearise_report(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.  report_definition.report_format_section);
                        break;

                case E_MET_PDF_REPORT_DEFINITION:
                        linearise_report(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.  pdf_report_definition.report_format_section);
                        break;

                // We dont need to worry about these commands....
                case E_MET_CMD:
                case E_MET_IMPORT_FUNCTION_DEFINITION:
                case E_MET_CLASS_DEFINITION:
                case E_MET_IMPORT_LEGACY_DEFINITION: break;

        }
   }

}


