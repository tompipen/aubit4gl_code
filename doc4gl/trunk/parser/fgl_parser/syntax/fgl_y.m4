changecom(`XXXXXXX',`YYYYYYYYY')

/**  
 * This m4 file is used to build a bison gramar based on a set of rules
 * and a generated token table.
 *
 * @todo : Change the format macro so it is not changed in .y
 **/

/* <preamble.y> */
include(preamble.y)
/* </preamble.y> */

/* <../generated/kw.yh> */
include(../generated/kw.yh)
/* </../generated/kw.yh> */

%%

include(FglDefinition.y)
include(CompilerDirectives.y) 
include(StorageManipulation.y)
include(ScreenInteraction.y)
include(ReportExecution.y)
include(Sql.y)

/* <all_rules.y> */

include(all_rules.y)

/* </all_rules.y> */

