/* <FLUSH_STATEMENT> */

/**
 * Bison rules for the FLUSH statement of a cursor.
 * FLUSH is used with insert cursors to insert the data in a buffer into
 * the database where the cursor is opened.
 */

/**
 * Flushing of an insert cursor into the database.
 * 4gl code examples:
 *    FLUSH crXpto
 *    USE SESSION connName FLUSH crXpto
 */
flush_cmd 
  : opt_use FLUSH fetch_cursor_name  
  ;

/* </FLUSH_STATEMENT> */
