/* <MENU_STATEMENT> */

/**
 * Bison rules for the MENU statement.
 */

/**
 * The MENU statement.
 * 4gl code example:
 *   MENU "Options"
 *      COMMAND "Op 1" "First option"
 *        ... 4gl statements ...
 *   END MENU
 */
menu_cmd	
  :	MENU menu_title menu_commands end_menu_command 
  ;

/**
 * The end menu
 * @todo : Understand why this is a separated RULE.
 */
end_menu_command  
  : END_MENU 
  ;

/**
 * The possible menu declarative subsections.
 * 4gl code examples:
 *   BEFORE MENU 
 *      ... 4gl statements ...
 *   COMMAND "Op 1" 
 *      ... 4gl statements ...
 *   COMMAND KEY "X" "Op 1" "First option" HELP 100
 *      ... 4gl statements ...
 */
menu_block_command 
  : BEFORE_MENU commands 
  | COMMAND opt_key menu_opt_name menu_optional_desc opt_help_no commands 
  | COMMAND opt_key opt_help_no commands 
  ;

/**
 * The list of possible menu commands
 */
menu_commands 
  : menu_block_command 
	| menu_commands menu_block_command
	;

/**
 * Optional key to use in the COMMAND of the MENU statement.
 */
opt_key	
  :	
	| key_val 

/**
 * Name for a COMMAND substatement in the MENU statement.
 * @todo : This should change name because it is not optional and 
 *         is part of COMMAND. maybe "command_option_name"
 */
menu_opt_name	
  :	CHAR_VALUE 
  | variable 
  ;

/**
 * Optional description of the COMMAND substatement in the MENU statement.
 * @todo : Change to opt_menu_description.
 */
menu_optional_desc	
  :
  | variable 
  | CHAR_VALUE 
	;

/**
 * A NEXT option command to be used in the MENU events. The
 * next option continue the menu execution in a specific 
 * option.
 * 4gl code example:
 *    NEXT OPTION "Xpto"
 */
next_option_cmd 
  : NEXT_OPTION opt_name 
  ;

/**
 * The SHOW OPTION command of the MENU statement. This statement
 * turns visible one option.
 * 4gl code examples:
 *   SHOW OPTION "Xpto"
 *   SHOW OPTION "Xpto", "Xpta"
 */
show_option_cmd 
  : SHOW_OPTION opt_name_list 
  ;

/**
 * The HIDE OPTION command of the MENU statement. This statement
 * turns invisible one option.
 * 4gl code example:
 *   HIDE OPTION "Xpto"
 *   HIDE OPTION "Xpto", "Xpta"
 */
hide_option_cmd 
  : HIDE_OPTION opt_name_list 
  ;

/**
 * Name of a menu option.
 * @todo : Change the rule name because it is not optional
 */
opt_name	
  :	ALL 
  | CHAR_VALUE 
  | variable 
  ;

/**
 * A comma separated menu option name.
 */
opt_name_list	
  :	opt_name
	|	opt_name_list COMMA opt_name 
	;

/** 
 * The title of the menu.
 */
menu_title 	
  :	variable 
  | CHAR_VALUE
  ;

/* </MENU_STATEMENT> */
