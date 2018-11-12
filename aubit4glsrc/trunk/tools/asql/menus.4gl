DEFINE mv_info_name char(64)
 
FUNCTION set_info_text(lv_s)
DEFINE lv_s CHAR(64)
LET mv_info_name=lv_s
END FUNCTION
 
FUNCTION main_menu()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "q" LET lv_option=0
      WHEN "c" LET lv_option=1
      WHEN "d" LET lv_option=2
      WHEN "t" LET lv_option=3
      WHEN "s" LET lv_option=4
      WHEN "u" LET lv_option=5
      WHEN "e" LET lv_option=6
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "ADBACCESS"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Query-language"
          WHEN 1 NEXT OPTION "Connection"
          WHEN 2 NEXT OPTION "Database"
          WHEN 3 NEXT OPTION "Table"
          WHEN 4 NEXT OPTION "Session"
          WHEN 5 NEXT OPTION "Utilities"
          WHEN 6 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "q" "Query-language" "Use SQL query language"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "c" "Connection" "Connect or disconnect from a database environment."
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "d" "Database" "Select, Create, Info, Drop or Close a database."
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "t" "Table" "Create, Alter, or Drop a database table."
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "s" "Session" "Retrieve information about the current DB-Access session."
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "u" "Utilities" "Forms, Reports, User Menus etc."
        LET lv_option=5
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit ADBACCESS."
        LET lv_option=6
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL query_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL connection_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 CALL database_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 3 CALL table_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 4 CALL session_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 5 CALL tools_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 6 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION connection_menu()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "d" LET lv_option=1
      WHEN "e" LET lv_option=2
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "CONNECTION"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Connect"
          WHEN 1 NEXT OPTION "Disconnect"
          WHEN 2 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Connect" "Connect to a database environment."
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "d" "Disconnect" "Disconnect from the current database environment."
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "e" "Exit" "Returns to the DB-Access Menu."
        LET lv_option=2
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL connection_connect()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL connection_disconnect()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION connection_disconnect()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "y" LET lv_option=0
      WHEN "n" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "DISCONNECT"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Yes"
          WHEN 1 NEXT OPTION "No"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "y" "Yes" "Disconnect from current database environment."
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "n" "No" "Do not disconnect from current database environment."
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL do_disconnect()
        LET lv_run=FALSE
      WHEN 1 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION table_menu_int()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "a" LET lv_option=1
      WHEN "i" LET lv_option=2
      WHEN "d" LET lv_option=3
      WHEN "e" LET lv_option=4
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "TABLE"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Create"
          WHEN 1 NEXT OPTION "Alter"
          WHEN 2 NEXT OPTION "Info"
          WHEN 3 NEXT OPTION "Drop"
          WHEN 4 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Create" "Create a new Table (not implemented)"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "a" "Alter" "Alter a table (not implemented)"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "i" "Info" "Info for a table"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "d" "Drop" "Drop a table"
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to ADBACCESS Menu"
        LET lv_option=4
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL niy()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL niy()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 CALL table_info()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 3 CALL table_drop()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 4 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION database_menu()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "s" LET lv_option=0
      WHEN "c" LET lv_option=1
      WHEN "i" LET lv_option=2
      WHEN "d" LET lv_option=3
      WHEN "l" LET lv_option=4
      WHEN "e" LET lv_option=5
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "DATABASE"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Select"
          WHEN 1 NEXT OPTION "Create"
          WHEN 2 NEXT OPTION "Info"
          WHEN 3 NEXT OPTION "Drop"
          WHEN 4 NEXT OPTION "cLose"
          WHEN 5 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "s" "Select" "Select a database to work with."
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "c" "Create" "Create a new database."
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "i" "Info" "Retrieve information about a database."
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "d" "Drop" "Drop a database."
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "l" "cLose" "Close the current database."
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to the ADBACCESS menu."
        LET lv_option=5
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL select_db()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL create_db()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 CALL niy()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 3 CALL drop_db()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 4 CALL do_disconnect()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 5 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION confirm_drop()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "n" LET lv_option=0
      WHEN "y" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "CONFIRM"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "No"
          WHEN 1 NEXT OPTION "Yes"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "n" "No" "Don't drop the table"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "y" "Yes" "Yes - really drop the table"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Yes"
      WHEN 1 RETURN "No"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION tools_menu()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "f" LET lv_option=0
      WHEN "r" LET lv_option=1
      WHEN "u" LET lv_option=2
      WHEN "e" LET lv_option=3
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "Utilities"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Form"
          WHEN 1 NEXT OPTION "Report"
          WHEN 2 NEXT OPTION "User-Menus"
          WHEN 3 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "f" "Form" "Form maintenance"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "r" "Report" "Reports maintenance"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "u" "User-Menus" "User menus maintenance"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to main menu"
        LET lv_option=3
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL form_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL report_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 CALL user_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 3 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION user_menu_int()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "r" LET lv_option=0
      WHEN "m" LET lv_option=1
      WHEN "e" LET lv_option=2
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "User Menu"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Run"
          WHEN 1 NEXT OPTION "Modify"
          WHEN 2 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "r" "Run" "Run a user menu"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "m" "Modify" "Modify a user menu"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit"
        LET lv_option=2
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 CALL run_user_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 1 CALL modify_user_menu()
             IF lv_hadmenu THEN EXIT PROGRAM END IF
      WHEN 2 LET lv_run=FALSE
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION cr_db_menu()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "d" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "EXIT"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Create-new-database"
          WHEN 1 NEXT OPTION "Discard-new-database"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Create-new-database" "Create-new-database"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "d" "Discard-new-database" "Discard-new-database"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Create"
      WHEN 1 RETURN "Discard"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION cr_db_menu_options()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "d" LET lv_option=0
      WHEN "l" LET lv_option=1
      WHEN "e" LET lv_option=2
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "EXIT"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Dbspace"
          WHEN 1 NEXT OPTION "Log"
          WHEN 2 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "d" "Dbspace" "Select a dbspace for storing the databases's data."
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "l" "Log" "Specify the type of transaction logging."
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to the Database Menu."
        LET lv_option=2
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "DBSpace"
      WHEN 1 RETURN "Log"
      WHEN 2 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION get_log()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "n" LET lv_option=0
      WHEN "n" LET lv_option=1
      WHEN "b" LET lv_option=2
      WHEN "m" LET lv_option=3
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "LOG"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "None"
          WHEN 1 NEXT OPTION "Log"
          WHEN 2 NEXT OPTION "Buffered_log"
          WHEN 3 NEXT OPTION "log_Mode_ansi"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "n" "None" "None"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "n" "Log" "LOG"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "b" "Buffered_log" "Buffered Log"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "m" "log_Mode_ansi" "Ansi Log"
        LET lv_option=3
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN ""
      WHEN 1 RETURN "WITH LOG"
      WHEN 2 RETURN "WITH BUFFERED LOG"
      WHEN 3 RETURN "LOG MODE ANSI"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION ask_commit_rollback()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "r" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "COMMIT ?"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Commit"
          WHEN 1 NEXT OPTION "Rollback"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Commit" "Commit Work"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "r" "Rollback" "Rollback Work"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Commit"
      WHEN 1 RETURN "Rollback"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION confirm_yn()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "y" LET lv_option=0
      WHEN "n" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "Confirm"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Yes"
          WHEN 1 NEXT OPTION "No"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "y" "Yes" "Really do it"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "n" "No" "Don't do it"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Yes"
      WHEN 1 RETURN "No"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION confirm_drop_db()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "y" LET lv_option=0
      WHEN "n" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "CONFIRM >>"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "YES"
          WHEN 1 NEXT OPTION "NO"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "y" "YES" "Really Drop the database"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "n" "NO" "Don't drop it"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Yes"
      WHEN 1 RETURN "No"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION info_menu(lv_lastoption)
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "i" LET lv_option=1
      WHEN "p" LET lv_option=2
      WHEN "r" LET lv_option=3
      WHEN "s" LET lv_option=4
      WHEN "o" LET lv_option=5
      WHEN "g" LET lv_option=6
      WHEN "t" LET lv_option=7
      WHEN "f" LET lv_option=8
      WHEN "e" LET lv_option=9
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU mv_info_name
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Columns"
          WHEN 1 NEXT OPTION "Indexes"
          WHEN 2 NEXT OPTION "Privileges"
          WHEN 3 NEXT OPTION "References"
          WHEN 4 NEXT OPTION "Status"
          WHEN 5 NEXT OPTION "cOnstraints"
          WHEN 6 NEXT OPTION "triGgers"
          WHEN 7 NEXT OPTION "Table"
          WHEN 8 NEXT OPTION "Fragments"
          WHEN 9 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Columns" "List columns for the table"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "i" "Indexes" "List indexes for the table"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "p" "Privileges" "List privileges for the table"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "r" "References" "List references for the table"
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "s" "Status" "Display status for the table"
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "o" "cOnstraints" "List constraints for the table"
        LET lv_option=5
        EXIT MENU
      COMMAND KEY "g" "triGgers" "List triggers for the table"
        LET lv_option=6
        EXIT MENU
      COMMAND KEY "t" "Table" "Change table"
        LET lv_option=7
        EXIT MENU
      COMMAND KEY "f" "Fragments" "List fragments for the table"
        LET lv_option=8
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit"
        LET lv_option=9
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Columns"
      WHEN 1 RETURN "Indexes"
      WHEN 2 RETURN "Privileges"
      WHEN 3 RETURN "References"
      WHEN 4 RETURN "Status"
      WHEN 5 RETURN "cOnstraints"
      WHEN 6 RETURN "triGgers"
      WHEN 7 RETURN "Table"
      WHEN 8 RETURN "Fragments"
      WHEN 9 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION form_menu_int(lv_lastoption)
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "r" LET lv_option=0
      WHEN "m" LET lv_option=1
      WHEN "g" LET lv_option=2
      WHEN "n" LET lv_option=3
      WHEN "c" LET lv_option=4
      WHEN "d" LET lv_option=5
      WHEN "e" LET lv_option=6
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "FORM"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Run"
          WHEN 1 NEXT OPTION "Modify"
          WHEN 2 NEXT OPTION "Generate"
          WHEN 3 NEXT OPTION "New"
          WHEN 4 NEXT OPTION "Compile"
          WHEN 5 NEXT OPTION "Drop"
          WHEN 6 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "r" "Run" "Run a form"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "m" "Modify" "Modify a form"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "g" "Generate" "Generate a form"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "n" "New" "Create a new form"
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "c" "Compile" "Compile a form"
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "d" "Drop" "Drop a form"
        LET lv_option=5
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit Menu"
        LET lv_option=6
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Run"
      WHEN 1 RETURN "Modify"
      WHEN 2 RETURN "Generate"
      WHEN 3 RETURN "New"
      WHEN 4 RETURN "Compile"
      WHEN 5 RETURN "Drop"
      WHEN 6 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION modify_compile()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "s" LET lv_option=1
      WHEN "d" LET lv_option=2
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "Modify Form"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Compile"
          WHEN 1 NEXT OPTION "Save-and-exit"
          WHEN 2 NEXT OPTION "Discard-and-exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Compile" "Compile the form"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "s" "Save-and-exit" "Save the form"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "d" "Discard-and-exit" "Discard the form"
        LET lv_option=2
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Compile"
      WHEN 1 RETURN "Save-and-exit"
      WHEN 2 RETURN "Discard-and-exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION correct_compile_form()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "c" LET lv_option=0
      WHEN "e" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "COMPILE FORM"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Correct"
          WHEN 1 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "c" "Correct" "Correct the errors in the form"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit the compilation"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Correct"
      WHEN 1 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION confirm_drop_form()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "n" LET lv_option=0
      WHEN "y" LET lv_option=1
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "CONFIRM"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "No"
          WHEN 1 NEXT OPTION "Yes"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "n" "No" "No - I don't want to drop it"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "y" "Yes" "Yes - I do want to drop it"
        LET lv_option=1
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "No"
      WHEN 1 RETURN "Yes"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION form_table_selection()
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_lastoption=-1
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "t" LET lv_option=0
      WHEN "s" LET lv_option=1
      WHEN "e" LET lv_option=2
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "Generate"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "Table selection complete"
          WHEN 1 NEXT OPTION "Select more"
          WHEN 2 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "t" "Table selection complete" "Table selection complete"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "s" "Select more" "Select more"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "e" "Exit" "Exit"
        LET lv_option=2
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "Table selection complete"
      WHEN 1 RETURN "Select more"
      WHEN 2 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION query_menu_translate_int(lv_lastoption)
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "n" LET lv_option=0
      WHEN "r" LET lv_option=1
      WHEN "m" LET lv_option=2
      WHEN "u" LET lv_option=3
      WHEN "o" LET lv_option=4
      WHEN "c" LET lv_option=5
      WHEN "s" LET lv_option=6
      WHEN "i" LET lv_option=7
      WHEN "d" LET lv_option=8
      WHEN "t" LET lv_option=9
      WHEN "e" LET lv_option=10
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "SQL"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "New"
          WHEN 1 NEXT OPTION "Run"
          WHEN 2 NEXT OPTION "Modify"
          WHEN 3 NEXT OPTION "Use-editor"
          WHEN 4 NEXT OPTION "Output"
          WHEN 5 NEXT OPTION "Choose"
          WHEN 6 NEXT OPTION "Save"
          WHEN 7 NEXT OPTION "Info"
          WHEN 8 NEXT OPTION "Drop"
          WHEN 9 NEXT OPTION "Translate"
          WHEN 10 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "n" "New" "Type in new SQL commands"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "r" "Run" "Run the SQL commands"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "m" "Modify" "Modify the SQL commands"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "u" "Use-editor" "Use the editor to modify SQL"
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "o" "Output" "Output the results of the SQL"
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "c" "Choose" "Choose an SQL file"
        LET lv_option=5
        EXIT MENU
      COMMAND KEY "s" "Save" "Save an SQL file"
        LET lv_option=6
        EXIT MENU
      COMMAND KEY "i" "Info" "Info for tables"
        LET lv_option=7
        EXIT MENU
      COMMAND KEY "d" "Drop" "Drop an SQL file"
        LET lv_option=8
        EXIT MENU
      COMMAND KEY "t" "Translate" "Translate SQL into a different dialect"
        LET lv_option=9
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to ADBACCESS menu"
        LET lv_option=10
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "New"
      WHEN 1 RETURN "Run"
      WHEN 2 RETURN "Modify"
      WHEN 3 RETURN "Use-editor"
      WHEN 4 RETURN "Output"
      WHEN 5 RETURN "Choose"
      WHEN 6 RETURN "Save"
      WHEN 7 RETURN "Info"
      WHEN 8 RETURN "Drop"
      WHEN 9 RETURN "Translate"
      WHEN 10 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
FUNCTION query_menu_int(lv_lastoption)
DEFINE lv_option INTEGER
DEFINE lv_lastoption INTEGER
DEFINE lv_run INTEGER
DEFINE lv_menukey CHAR(1)
DEFINE lv_hadmenu INTEGER

LET lv_hadmenu=has_menu_action()
LET lv_run=TRUE
 
WHILE lv_run
  IF has_menu_action() THEN
    LET lv_menukey=get_menu_action()

    CASE lv_menukey
      WHEN "n" LET lv_option=0
      WHEN "r" LET lv_option=1
      WHEN "m" LET lv_option=2
      WHEN "u" LET lv_option=3
      WHEN "o" LET lv_option=4
      WHEN "c" LET lv_option=5
      WHEN "s" LET lv_option=6
      WHEN "i" LET lv_option=7
      WHEN "d" LET lv_option=8
      WHEN "e" LET lv_option=9
    END CASE
    CALL display_banner()

  ELSE
    LET lv_menukey="-"
    MENU "SQL"
      BEFORE MENU
        SET PAUSE MODE ON
        CALL display_banner()
        CASE lv_lastoption
          WHEN 0 NEXT OPTION "New"
          WHEN 1 NEXT OPTION "Run"
          WHEN 2 NEXT OPTION "Modify"
          WHEN 3 NEXT OPTION "Use-editor"
          WHEN 4 NEXT OPTION "Output"
          WHEN 5 NEXT OPTION "Choose"
          WHEN 6 NEXT OPTION "Save"
          WHEN 7 NEXT OPTION "Info"
          WHEN 8 NEXT OPTION "Drop"
          WHEN 9 NEXT OPTION "Exit"
        END CASE
        SET PAUSE MODE OFF
 
      COMMAND KEY "n" "New" "Type in new SQL commands"
        LET lv_option=0
        EXIT MENU
      COMMAND KEY "r" "Run" "Run the SQL commands"
        LET lv_option=1
        EXIT MENU
      COMMAND KEY "m" "Modify" "Modify the SQL commands"
        LET lv_option=2
        EXIT MENU
      COMMAND KEY "u" "Use-editor" "Use the editor to modify SQL"
        LET lv_option=3
        EXIT MENU
      COMMAND KEY "o" "Output" "Output the results of the SQL"
        LET lv_option=4
        EXIT MENU
      COMMAND KEY "c" "Choose" "Choose an SQL file"
        LET lv_option=5
        EXIT MENU
      COMMAND KEY "s" "Save" "Save an SQL file"
        LET lv_option=6
        EXIT MENU
      COMMAND KEY "i" "Info" "Info for tables"
        LET lv_option=7
        EXIT MENU
      COMMAND KEY "d" "Drop" "Drop an SQL file"
        LET lv_option=8
        EXIT MENU
      COMMAND KEY "e" "Exit" "Return to ADBACCESS menu"
        LET lv_option=9
        EXIT MENU
    END MENU
 
  END IF
  LET lv_lastoption=lv_option
 
  CASE lv_option
      WHEN 0 RETURN "New"
      WHEN 1 RETURN "Run"
      WHEN 2 RETURN "Modify"
      WHEN 3 RETURN "Use-editor"
      WHEN 4 RETURN "Output"
      WHEN 5 RETURN "Choose"
      WHEN 6 RETURN "Save"
      WHEN 7 RETURN "Info"
      WHEN 8 RETURN "Drop"
      WHEN 9 RETURN "Exit"
  END CASE
END WHILE
END FUNCTION
 
 
 
 
