# $Id: coxxq01.4gl,v 1.1 2001-09-24 04:18:53 afalout Exp $
{******************************************************************************
*    Filename     :   coxxq01.4gl                                             *
*    System       :   Eunice 4GL - Common Module                              *
*    Purpose      :   Quick and dirty QBE selection window                    *
*    Returns      :   key value                                               *
*    Author       :   Kerry Sainsbury                                         *
*    Date Written :   12 August 1993                                          *
*    Last Change  :                                                           *
*                                                                             *
* 21/10/93 Kerry S  - Major changes to the front end                          *
*                   - Cleaning up Temp String Storage bug.                    *
* 22/10/93 Kerry S  - Cope with cancelling from QBE window if keycnt > 1      *
* 28/10/93 Kerry S  - Fields in "Query" QBE window now right-justified        *
* 29/10/93 Kerry S  - AS flag was not working                                 *
*                   - Null flag meant "Line" prompt did not display           *
* 12/11/93 Kerry S  - Large headings causing routine to fall over             *
* 12/11/93 Kerry S  - Stick "Nothing to list" message in a window             *
* 16/11/93 Kerry S  - If > 5 keys would not open correct form                 *
* 01/12/93 Kerry S  - Problems with numeric columns, and their headings       *
* 07/12/93 Kerry S  - Catch user's attempts to use wildcards in numeric fields*
* 07/12/93 Kerry S  - Cope with any error with QDsystem_error                 *
* 13/12/93 Kerry S  - Cope with headings of up to 80 characters (but only     *
*                     display first 30 characters)                            *
* 26/04/94 Kerry S  - Found the -4518 (Temp String Space) bug. Informix bug!  *
* 14/06/94 Kerry S  - Add tagging                                             *
* 14/06/94 Kerry S  - Disable subsequent QBEs if tagging is enabled           *
* 16/06/94 Kerry S  - Was crashing for non-tagging selections!                *
* 11/07/94 Kerry S  - Just CREATE temporary tagging table once per program    *
* 12/08/94 Kerry S  - Cope with longer titles than can fit in 80 columns      *
*                   - When window is oversize, use all 80 columns (was 76)    *
* 24/08/94 Kerry S  - Cope with column list not padded with spaces            *
* 01/09/94 Kerry S  - Add the "More..." indicator per: a Fox & Gun good idea  *
* 07/10/94 Kerry S  - Drop QBE box down a line so that it doesn't obscure     *
*                     line 3 (The heading line)                               *
* 18/10/94 EJD      - Cope with more than one occurance of text to change in  *
*                     QDchange_text                                           *
* 20/10/94 Kerry S  - New parameter CDE to allow a cheap data-entry screen    *
* 25/10/94 Kerry S  - If a multiple-return-value QBE failed, it was returning *
*                     data from previous windows as 2nd thru 10th values      *
* 28/10/94 Kerry S  - New parameter "NA" to not insist on a * to QBE everythng*
* 29/12/94 Kerry S  - Cope with BIG SELECTs (like used in cocmq01)            *
*                   - Add F12 "I'm sorry" message                             *
* 06/04/95 Kerry S  - Finally fix headings with embedded spaces               *
* 07/04/95 Kerry S  - Let this routine die if it needs to                     *
* 07/04/95 Kerry S  - Now add ability to put a title inside query_windows     *
* 13/04/95 Kerry S  - Now handle empty headings                               *
* 26/04/95 Kerry S  - Maximum heading per column is 30 characters             *
* 02/05/95 Kerry S  - Cope with headings of "Something,"                      *
* 15/06/95 Greg  A  - Cope with multi-line titles and also lets you have      *
*                     uncentred titles and fixed NS flag so that it works     *
* 15/06/95 Kerry S  - Wildcard matching cannot be used with non-character     *
*                     datatypes (an old bug I recently reintroduced)          *
* 15/06/95 Eric H   - Have key columns that dont show in select - only in qbe *
* 19/07/95 Eric H   - Add new STn start column flag - see below               *
* 24/07/91 Eric H   - Problems with status field                              *
* 17/08/95 Eric H   - program aborting on OPEN cursor if non-numeric data in  *
*                     a numeric field. Let QDsystem_error handle it.          *
* 29/09/95 Greg A   - Add tag all and untag all options to the ring menu for  *
*                     list when tagging is on                                 *
* 12/10/95 Kerry S  - Added in_background test, and a GOTO (for clarity!)     *
*                                                                             *
*******************************************************************************}

#! query_window(select_statement, headings, keycnt, flags)
#!    - select_statement : display columns need {[k]size} parameter
#!        eg: SELECT pmprodno{k15}, pmdesc{40}, smohdqty{8.2} etc
#!            would specify that pmprodno is 15 characters wide,
#!            pmdesc is 40 characters wide, and smohdqty is a numeric
#!            field 8 characters wide with 2 figures after the
#!            decimal points.
#!           - A "k" after the "{" indicates the field can be queryed
#!             under the "Query" menu option
#!    - headings : headings for the SELECTed columns 
#!                    (eg:Code, Description)
#!    - keycnt   : this number of columns which are keys
#!                    (the first <keycnt> columns are returned
#!                     to the calling function)
#!    - flags. User selection options, delimited by pipes (|).
#!      "AS" - Automatically select if only one option to choose.
#!      "CDE"- Cheap Data Entry. FQ & AS plus it skips the the 
#!            "No details to display" window and returns immediately
#!             to the calling program. A cheap data entry routine :-)
#!      "FQ" - Force QBE before bringing up selection window
#!      "NA" - No asterisk required to QBE everything
#!      "NBE"- No Back End. Just pops up QBE window and returns
#!             WHERE clause
#!      "NS" - No line selection available.
#!      "NQ" - No "Query" option on ring menu
#!      "TAG"- Allow tagging of multiple items (requires subsequent
#!             calls to "next_tag()")
#!      "STn"- Start RETURN of parameters in column "n" of SELECT list
#!             ie RETURN column n thru n + keycnt - 1
#!
#! next_tag() RETURNs next tagged item, or NULL on last item
#!
#! query_title(l_title) RETURNs nothing
#!      - Places l_title as a title at the top of the query_window
#!        selection screen
#!
#! query_centre_off(l_centre_lines) RETURNs nothing
#!      - l_centre_lines - Numbers of the lines that you want centred or null
#!                         for all uncentred
#!      - Places l_centre_lines as centre title and all others a uncentred 
#!        If passed null then all lines are uncentred

# Note: I'm not passing huge strings around the place any more simply because
#       Informix is slow at it, and I'm concerned about running out of
#       Temporary String Storage space. Hence more globals in this version.
#

DEFINE   m_lpp           SMALLINT,  # Number of lines per page
         m_bell          CHAR(1),   # For ASCII(7)
         ma_desclen      ARRAY[10] OF DECIMAL(3,1), # Length of display field
         ma_number       ARRAY[10] OF SMALLINT,     # Is field a number ?
         ma_key          ARRAY[10] OF SMALLINT,     # Is field a key for QBE?
         ma_head         ARRAY[10] OF CHAR(30),     # Heading text
         ma_desc         ARRAY[10] OF CHAR(80),     # Data from current row
         ma_column       ARRAY[10] OF CHAR(20),     # Columns name
         m_select        CHAR(1000),                # Hold SQL SELECT string 
         m_change_text   CHAR(1000),
         m_eighty_spaces CHAR(80),
         m_tagkeycnt     INTEGER,
         m_tagstartcol   INTEGER,
         m_built_tagtable  SMALLINT,   # Has the tagtable been built?
         m_using         CHAR(20),     # For formatting numerics
         m_width         SMALLINT,
         m_offset        SMALLINT,  -- Row at which data starts displaying
         m_title         CHAR(250), -- 78 * 3 :-o
         m_centrelines   CHAR(15)   -- No's of lines to centre

FUNCTION query_any(l_table, l_keycolumn, l_desccolumn, # Easy frontend
                   l_keyname, l_heading,l_where, l_old)
DEFINE   l_table        CHAR(18),  # LIKE systables.tabname,
         l_keycolumn    CHAR(18),  # LIKE syscolumns.colname,
         l_desccolumn   CHAR(18),  # LIKE syscolumns.colname,
         l_keyname      CHAR(18),  # LIKE syscolumns.colname,
         l_heading      CHAR(18),  # LIKE syscolumns.colname,
         l_where        CHAR(100),
         l_old          CHAR(80),
         l_flags        CHAR(20),
         l_key          CHAR(80),
         l_keylen       SMALLINT,
         l_desclen      SMALLINT,
         l_text         CHAR(200),
         l_head         CHAR(80),
         l_nrows        SMALLINT

--   WHENEVER ANY ERROR CALL QDsystem_error

   IF l_where IS NULL THEN
      LET l_where = "1=1"
   END IF
   LET l_keylen  = QDgetcollen(l_table, l_keycolumn) # Get size of columns
   LET l_desclen = QDgetcollen(l_table, l_desccolumn)

   LET l_text =  # Build a SELECT string
 "SELECT ",l_keycolumn CLIPPED,"{k",l_keylen,"}, ", # in a format suitable
          l_desccolumn CLIPPED,"{",l_desclen,"}", # for query_window()
  " FROM ",l_table CLIPPED,
 " WHERE ",l_where CLIPPED,
" ORDER BY ",l_keycolumn CLIPPED

   LET l_head = l_keyname CLIPPED,",",l_heading CLIPPED

# Force QBE box if more than 50 rows in the table...

   SELECT nrows
     INTO l_nrows
     FROM systables
    WHERE tabname = l_table

   IF l_nrows > 50 THEN              # If more than 50 rows in table
      LET l_flags = "FQ"
   ELSE
      LET l_flags = ""
   END IF

   LET l_key = query_window(l_text, l_head, 1, l_flags) # Do it!

   IF l_key IS NULL THEN
      LET l_key = l_old
   END IF
   RETURN l_key
END FUNCTION

FUNCTION query_title(l_title)
DEFINE   l_title                    CHAR(800)
   LET m_title = l_title
END FUNCTION
 
FUNCTION query_centre_off(l_centrelines)
DEFINE   l_centrelines                    CHAR(15)
   LET m_centrelines = l_centrelines
   IF m_centrelines IS NULL THEN 
      LET m_centrelines = "ZZ"
   ELSE
      LET m_centrelines = "[",m_centrelines CLIPPED,"]"
   END IF
END FUNCTION
 

FUNCTION query_window(l_select, l_heading, l_keycnt, l_flags)
DEFINE   l_select                   CHAR(1000),
         l_heading                  CHAR(100),
         l_titlearr ARRAY[3]  OF    CHAR(78),
         l_keycnt                   SMALLINT,
         l_flags                    CHAR(30),

         l_desccolumn               CHAR(20),

         l_text                     CHAR(600),
         l_fixwhere                 CHAR(600),
         l_desc                     CHAR(80),
         l_desclen                  SMALLINT,
         l_wcol                     SMALLINT,
         l_depth                    SMALLINT,         
         l_page                     SMALLINT,
         l_tagging                  SMALLINT,
         l_headlineno               SMALLINT,
         l_headmatch                CHAR(3),
         l_noofheadlines            SMALLINT,
         l_want_selection_window    SMALLINT,
         l_menuline                 SMALLINT,
         l_startcol                 SMALLINT,
         i                          SMALLINT,
         la_desc     ARRAY[10] OF   CHAR(80)

--   WHENEVER ANY ERROR CALL QDsystem_error

# Setup global variables...

   LET m_select = l_select
   LET m_lpp = 9       # There are 9 lines per page...
   LET m_bell = ASCII(7)
   LET m_using = "--------------------"
   LET m_eighty_spaces =  # Do not replace with "80 SPACES"
"                                                                                "

    LET l_flags = "|",l_flags CLIPPED, "|"
    IF l_flags MATCHES "*|CDE|*" THEN    # Cheap data entry turned on?
       LET l_flags = l_flags CLIPPED,"FQ|AS|"
    END IF
    IF l_flags MATCHES "*|NBE|*" THEN    # No Back End turned on?
       LET l_flags = l_flags CLIPPED,"FQ|"
    END IF

    LET l_startcol = 1
    IF l_flags MATCHES "*|ST*" THEN
       FOR i = 1 TO 26
           IF l_flags[i,i+2] = "|ST" THEN
               IF l_flags[i+4] = "|" THEN
                   LET l_startcol = l_flags[i+3]
               ELSE
                   LET l_startcol = l_flags[i+3,i+4]
               END IF
               EXIT FOR
           END IF
       END FOR
    END IF
    IF l_flags MATCHES "*|TAG|*" THEN
       LET l_tagging = TRUE
       LET m_tagkeycnt = l_keycnt
       LET m_tagstartcol = l_startcol
       LET l_keycnt = FALSE

       IF NOT m_built_tagtable THEN
          PREPARE create_tagtable FROM
                 "CREATE TEMP TABLE tagtable (line SMALLINT) WITH NO LOG"

          EXECUTE create_tagtable
          LET m_built_tagtable = TRUE
       ELSE
          DELETE FROM tagtable
       END IF
    ELSE
       LET l_tagging = FALSE
    END IF

# Extract options from l_desccolumn, and work out how wide the
# description field will be...

   LET l_desclen = QDget_desc_sizes()
   LET l_select = m_select      # Store our cleaned up SQL string for later
   LET l_heading = QDformat_heading(l_heading)

# Force QBE box ?

   IF l_flags MATCHES "*|FQ|*"          # If Force-Query flag turned on...
   THEN
      LET l_text = QDqbewindow(l_flags)
      IF check_del("Query cancelled") THEN
         LET m_title = ""
         IF l_flags MATCHES "*|NBE|*" THEN    # No Back End turned on?
            RETURN ""                       # return empty where clause
         END IF

         GOTO RETURN_CHOICE -- At the end of this function
      END IF

      IF l_flags MATCHES "*|NBE|*" THEN    # No Back End turned on?
         LET m_title = ""
         RETURN l_text                   # return where clause
      END IF
   ELSE 
      LET l_text = "1=1"
   END IF

   LET l_fixwhere = " WHERE ",l_text CLIPPED," AND "
   LET m_change_text = l_select
   CALL QDchange_text("WHERE", l_fixwhere, "g")
   LET m_select = m_change_text

   IF m_change_text = l_select THEN      # Check for WHERE clause
      LET m_select = 
      "SYSTEM ERROR!<",
      "SELECT string passed to query_window() did not contain a WHERE clause. ",
      "Advise your support company of this error!"
      CALL message_prompt(m_select, "")
      LET m_title = ""

      GOTO RETURN_CHOICE -- At the end of this function
   END IF

   CALL QDbuild_cursor()

# If there's only one record, then don't bother with the selection window...
   
   LET l_want_selection_window = TRUE

   IF l_flags MATCHES "*|AS|*" THEN          # If Auto-Select flag is on, then
      CALL QDchoice(1, 2,FALSE, FALSE, 0)  # check if more than one record.
      IF ma_desc[1] IS NULL THEN           # There is no second record,
         CALL QDchoice(1, 1,FALSE, l_tagging, 0)  # So look for a first one
         IF ma_desc[1] IS NOT NULL THEN           # There is a first record
            LET l_want_selection_window = FALSE   # so don't need window
         END IF
      ELSE
         CALL QDclear_desc()
      END IF
   ELSE
      CALL QDclear_desc()
   END IF

   IF l_flags MATCHES "*|CDE|*" THEN         # If cheap data entry then
      CALL QDchoice(1, 1,FALSE, FALSE, 0)  # read the first record, and if
      IF ma_desc[1] IS NULL THEN           # blank return to calling program
         LET l_want_selection_window = FALSE
      END IF
   END IF

   IF l_want_selection_window THEN
      IF l_desclen + 2 > 78 THEN     # Truncate long descriptive fields
         LET l_desclen = 78 - 2
      END IF

      LET m_width = l_desclen + 2

      IF m_width < 42 THEN    # This stops an "invalid opcode" error in
         LET m_width = 42     # Informix 4.1 if the Menu list does not
      END IF                  # all fit inside the window.

      IF m_width > 78 THEN    # This keeps the window small enough to
         LET m_width = 78     # fit on the screen!
      END IF
      LET l_depth = 6 + m_lpp
      LET m_offset = 4
      LET l_menuline = 1

      IF NOT is_blank(m_title) THEN
         LET l_noofheadlines = setup_wwrap(m_title,m_width)
         IF l_noofheadlines > 3 THEN
            CALL message_prompt("coxxq01: Can only handle 3 title lines",
                                 "")
            LET l_noofheadlines = setup_wwrap(m_title,m_width)
            LET l_noofheadlines = 3
         END IF
         
         FOR l_headlineno = 1 TO l_noofheadlines
             LET l_titlearr[l_headlineno]=next_wwrap()
         END FOR
         LET l_depth = l_depth + 1 + l_noofheadlines
         LET m_offset = m_offset + 1 + l_noofheadlines
         LET l_menuline = l_menuline + 1 + l_noofheadlines
      END IF

# Open scrolly selection window...

      LET l_wcol = (80 - m_width) / 2
      IF l_wcol < 2 THEN LET l_wcol = 2 END IF
      OPEN WINDOW qdwin AT 6, l_wcol
      WITH l_depth ROWS, m_width COLUMNS
	  ATTRIBUTE(BORDER, CYAN, MESSAGE LINE LAST)
#aubit
#	  ATTRIBUTE(BORDER, CYAN, MESSAGE LINE LAST, MENU LINE l_menuline)
#|___________________________________________________________________^
#| Error at line 393, character 69
#| parse error ()

      IF NOT is_blank(m_title) THEN
         FOR l_headlineno = 1 TO l_noofheadlines
           LET l_headmatch = l_headlineno
           IF m_centrelines IS NOT NULL THEN
              IF l_headmatch MATCHES m_centrelines THEN
                 LET l_titlearr[l_headlineno]=
                                        centre(l_titlearr[l_headlineno],m_width)
              END IF
           ELSE 
              LET l_titlearr[l_headlineno]=
                                        centre(l_titlearr[l_headlineno],m_width)
              
           END IF
           DISPLAY l_titlearr[l_headlineno] AT l_headlineno,1 ATTRIBUTE(REVERSE)
         END FOR
         LET m_title = ""
         LET m_centrelines = ""
      END IF

      LET l_wcol = 3
      IF l_desclen THEN
         DISPLAY l_heading AT m_offset, l_wcol ATTRIBUTE(DIM)
      END IF

      IF l_flags NOT MATCHES "*|NS|*" THEN
         MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
      END IF

      IF QDshow_page(1, l_desclen, l_tagging) THEN
         LET l_page = 1

         MENU "SELECT"

         BEFORE MENU
            HIDE OPTION "Tag All"
            HIDE OPTION "Untag All"
            IF l_flags MATCHES "*|NQ|*" THEN  # If No Query flag is on
               HIDE OPTION "Query"            # then turn off "Query" option
            END IF
            IF l_flags MATCHES "*|TAG|*" THEN   # or tagging is enabled 
               HIDE OPTION "Query"              # then turn off "Query" option
               SHOW OPTION "Tag All"
               SHOW OPTION "Untag All"
            END IF

         COMMAND "Query" "Find a match based on partial information"
            IF l_flags NOT MATCHES "*|NS|*" THEN
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF
            LET l_text = QDqbewindow(l_flags)
            IF NOT check_del("Query cancelled") THEN
               LET l_fixwhere = " WHERE ",l_text CLIPPED," AND "
               LET m_change_text = l_select
               CALL QDchange_text("WHERE", l_fixwhere, "g")
               LET m_select = m_change_text
               CALL QDbuild_cursor()
               LET l_page = 1
               IF NOT QDshow_page(l_page, l_desclen, l_tagging) THEN
                  CALL QDblank_window(1)
                  CALL message_prompt("No details to display","")
               END IF
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF

         COMMAND "Next" "Display next page"
            IF l_flags NOT MATCHES "*|NS|*" THEN
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF
            CALL QDnext_page(l_page, l_desclen, l_tagging) 
            RETURNING l_page

         COMMAND "Previous" "Display previous page"
            IF l_flags NOT MATCHES "*|NS|*" THEN
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF
            CALL QDprev_page(l_page, l_desclen, l_tagging) 
            RETURNING l_page

         COMMAND "Tag All" "Tags All lines in the selection window"
            CALL QDtagallctrl(l_page,l_desclen,l_tagging,"T")
         
         COMMAND "Untag All" "Untag All lines in the selection window"
            CALL QDtagallctrl(l_page,l_desclen,l_tagging,"U")
         
         COMMAND "Exit" "Exit selection window"
            CALL QDclear_desc()
            EXIT MENU


         COMMAND KEY (F3)     # Next Page
            IF l_flags NOT MATCHES "*|NS|*" THEN
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF
            CALL QDnext_page(l_page, l_desclen, l_tagging) 
            RETURNING l_page

         COMMAND KEY (F4)     # Prev Page
            IF l_flags NOT MATCHES "*|NS|*" THEN
               MESSAGE "Enter Line No." ATTRIBUTE (REVERSE)
            END IF
            CALL QDprev_page(l_page, l_desclen, l_tagging) 
            RETURNING l_page

         COMMAND KEY ("1")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 1, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("2")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 2, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("3")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 3, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("4")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 4, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("5")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 5, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("6")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 6, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("7")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 7, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("8")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 8, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         COMMAND KEY ("9")
            IF l_flags MATCHES "*|NS|*" THEN CONTINUE MENU END IF
            CALL QDchoice(l_page, 9, TRUE, l_tagging, l_desclen)
            IF NOT l_tagging AND ma_desc[1] IS NOT NULL THEN EXIT MENU END IF

         END MENU
      ELSE
         CALL message_prompt("No details to display","")
      END IF
      
      CLOSE WINDOW qdwin
      OPTIONS MENU LINE 1
   END IF

   IF check_del("") THEN
      MESSAGE m_bell,"Query cancelled" ATTRIBUTE(REVERSE)
   END IF

   IF l_tagging THEN
      CALL QDsetup_tags()
   END IF

   LET m_title = ""

   FOR i = 1 TO l_keycnt
       IF i + l_startcol > 10 THEN
           LET la_desc[i] = ""
       ELSE
           LET la_desc[i] = ma_desc[i + l_startcol - 1]
       END IF
   END FOR

LABEL RETURN_CHOICE:

   CASE
   WHEN l_keycnt = 0
      RETURN
   WHEN l_keycnt = 1 
      RETURN la_desc[1]
   WHEN l_keycnt = 2 
      RETURN la_desc[1], la_desc[2]
   WHEN l_keycnt = 3 
      RETURN la_desc[1], la_desc[2], la_desc[3]
   WHEN l_keycnt = 4 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4]
   WHEN l_keycnt = 5 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5]
   WHEN l_keycnt = 6 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6]
   WHEN l_keycnt = 7 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7]
   WHEN l_keycnt = 8 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8]
   WHEN l_keycnt = 9 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8], la_desc[9]
   WHEN l_keycnt = 10 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8], la_desc[9], la_desc[10]
   OTHERWISE
      CALL message_prompt("Can't return more than 10 values from query_window",
                          "")
   END CASE
END FUNCTION


FUNCTION QDbuild_cursor() # Builds the cursor, based on m_select string

   MESSAGE "Building list..."

   WHENEVER ANY ERROR CALL QDsystem_error

   PREPARE qdprep FROM m_select


   DECLARE qdcurs SCROLL CURSOR FOR qdprep
   OPEN qdcurs
   WHENEVER ANY ERROR STOP

   MESSAGE ""
END FUNCTION


# This function scans thru the SELECT string looking for directives (ie {k5})
# and throws the various bits of information into misc arrays for later use.
#
# Also strips the directive text out of the SELECT string so that it makes
# sense to Informix-SQL
FUNCTION QDget_desc_sizes() 
DEFINE   l_thiscol       CHAR(18), # LIKE syscolumns.colname,
         l_desclen       SMALLINT,
         l_lth           SMALLINT,
         l_nstart        SMALLINT,
         l_cnt           SMALLINT,  # Count of descriptions
         i, j            SMALLINT

   FOR i = 1 TO 10              # Clean out description length array
      LET ma_desclen[i]=0
      LET ma_number[i]=0
      LET ma_key[i]=0
   END FOR

   LET l_cnt = 1
   LET l_lth = LENGTH(m_select)
   FOR i = 1 TO l_lth          # Scan through desccolumn string  
      CASE
      WHEN m_select[i]="{" # Hit a definition
         FOR j = i-1 TO 1 STEP -1      # Try to work out the name of the column
            IF m_select[j]=" "
            OR m_select[j]=","
            THEN
               LET j = j + 1
               EXIT FOR
            END IF
         END FOR

         LET ma_column[l_cnt]=m_select[j, i-1]
         FOR l_nstart = j - 1 TO 1 STEP -1 # look for a comma
            IF m_select[l_nstart] = "," THEN
               EXIT FOR
            END IF
            IF m_select[l_nstart] <> " " THEN
               LET l_nstart = l_nstart + 1
               EXIT FOR
            END IF
         END FOR          

         FOR j = i+1 TO l_lth # Look for column sizes
            CASE
            WHEN m_select[j]="k"      # It's a QBE key column
               LET ma_key[l_cnt]=TRUE # so remember to display it in the
               LET m_select[j]=" "    # "Query" ring menu
            WHEN m_select[j]="K"      # It's a QBE key column
               LET ma_key[l_cnt]=TRUE # but we don't want it in the select
               LET m_select[l_nstart,j]=" "    # 
            WHEN m_select[j]="}"      # End of column size definition
               LET ma_desclen[l_cnt] = m_select[i+1,j-1]
               FOR i = i TO j
                  IF m_select[i]="." THEN        # Look for a decimal point
                     LET ma_number[l_cnt] = TRUE # Hey - it's a number
                  END IF
                  LET m_select[i]=" "
               END FOR
               LET i = j
               LET l_cnt = l_cnt + 1
               EXIT FOR
            OTHERWISE
            END CASE
         END FOR  
      OTHERWISE
      END CASE
   END FOR 

# Work out total size of all descriptions bolted together...

   LET l_desclen = 0
   FOR i = 1 TO l_cnt
      LET l_desclen = l_desclen+ma_desclen[i]
      LET l_lth = ma_desclen[i]         # Check for numeric with decimal places
      IF l_lth != ma_desclen[i] THEN    # If found, then add one to account
         LET l_desclen = l_desclen + 1  # for the decimal place marker
      END IF
      IF l_desclen > 76 THEN
         LET ma_desclen[i] = ma_desclen[i] - (l_desclen - 76)
         LET l_desclen = 76
      END IF      
   END FOR
   LET l_desclen = l_desclen + l_cnt - 1

   RETURN l_desclen
END FUNCTION


FUNCTION QDformat_heading(l_heading)
DEFINE   l_heading            CHAR(100),
         l_desc               CHAR(80),
         l_cnt                SMALLINT,
         l_lth                SMALLINT,
         i                    SMALLINT,
         l_s                  SMALLINT,
         l_e                  SMALLINT,
         l_rounded_desclen    SMALLINT

# First work out what headings we've got...

   LET l_desc = m_eighty_spaces
   LET l_cnt = 1
   LET l_s = 1
   LET l_lth = LENGTH(l_heading)
   FOR i = 1 TO l_lth 
      IF l_heading[i] = "," THEN
         IF i-1 >= l_s THEN    -- Cope with an empty heading
            LET ma_head[l_cnt] = l_heading[l_s, i-1]
         END IF
         LET l_cnt = l_cnt + 1
         LET l_s = i + 1
         IF l_cnt > 30 THEN         -- Max column heading size is 30 characters
            LET l_heading[i+1]=","  -- so force our way onto the next heading
         END IF
      END IF
   END FOR
   IF l_s <= l_lth THEN
      LET ma_head[l_cnt] = l_heading[l_s, l_lth] CLIPPED
   ELSE
      LET ma_head[l_cnt] = ""
   END IF

# Build up description line...
   LET l_e = -1
   FOR i = 1 TO l_cnt
      IF ma_desclen[i] THEN
         LET l_s = l_e + 2
         LET l_e = l_s + ma_desclen[i] -1
         IF ma_number[i] THEN
            LET l_lth = LENGTH(ma_head[i])    # Right justify numbers
            IF l_lth > ma_desclen[i] THEN
               LET l_lth = ma_desclen[i] 
            END IF
            LET l_s = l_e - l_lth + 1
#           LET l_rounded_desclen = ma_desclen[i]
#           IF ma_desclen[i] != l_rounded_desclen THEN
#              LET l_s = l_s + 1
#           END IF
         END IF
         IF ma_head[i] IS NOT NULL AND l_s <=80 THEN
            IF l_e > 80 THEN
               LET l_e = 80
            END IF
            LET l_desc[l_s, l_e] = ma_head[i]
         END IF
      END IF
   END FOR
   RETURN l_desc
END FUNCTION


FUNCTION QDnext_page(l_page, l_desclen, l_tagging)  # Next page of list
DEFINE   l_page     SMALLINT,
         l_desclen  SMALLINT,
         l_tagging  SMALLINT

   IF QDshow_page(l_page+1, l_desclen, l_tagging) THEN 
      LET l_page = l_page + 1
   ELSE
      MESSAGE m_bell,"No more pages to display" ATTRIBUTE(REVERSE)
   END IF
   RETURN l_page
END FUNCTION


FUNCTION QDprev_page(l_page, l_desclen, l_tagging)  # Previous page of list
DEFINE   l_page     SMALLINT,
         l_desclen  SMALLINT,
         l_tagging  SMALLINT

   IF l_page !=1 THEN
      IF QDshow_page(l_page-1, l_desclen, l_tagging) THEN
         LET l_page = l_page -1
      END IF
   ELSE
      MESSAGE m_bell,"No previous page to display" ATTRIBUTE(REVERSE)
   END IF
   RETURN l_page
END FUNCTION


FUNCTION QDchoice(l_page, l_selline, l_errflag, l_tagging, l_desclen)
DEFINE   l_page     SMALLINT,
         l_selline  SMALLINT,
         l_errflag  SMALLINT,
         l_tagging  SMALLINT,
         l_desclen  SMALLINT,
         l_rec      INTEGER,
         i          SMALLINT
         
   LET l_rec = ((l_page-1) * m_lpp) + l_selline
   FETCH ABSOLUTE l_rec qdcurs
    INTO ma_desc[1], ma_desc[2], ma_desc[3], ma_desc[4], ma_desc[5],
         ma_desc[6], ma_desc[7], ma_desc[8], ma_desc[9], ma_desc[10]
   IF status !=0 THEN
      FOR i = 1 TO 10
         LET ma_desc[i]= NULL
      END FOR
      IF l_errflag THEN
         MESSAGE m_bell,"Invalid line number"  ATTRIBUTE(REVERSE)
      END IF
   ELSE
      IF l_tagging THEN                            # If tagging then
         DELETE FROM tagtable WHERE line = l_rec   # toggle tag table
         IF SQLCA.SQLERRD[3]=0 THEN
            INSERT INTO tagtable (line) VALUES (l_rec)
         END IF
         IF l_desclen THEN    # Do not try to display anything if autoselecting
            IF QDshow_line(l_page, l_desclen, l_rec, l_selline, l_tagging) THEN
            END IF
         END IF
      END IF
   END IF
END FUNCTION

FUNCTION QDtagallctrl(l_page, l_desclen, l_tagging, l_tagctrl)
DEFINE   l_page     SMALLINT,
         l_desclen  SMALLINT,
         l_tagging  SMALLINT,
         l_tagctrl  CHAR(1),
         l_row_cnt  SMALLINT,
         l_ok       SMALLINT
         
  
   IF l_tagctrl = "U" THEN
      DELETE FROM tagtable
      LET l_ok=QDshow_page(l_page,l_desclen,l_tagging)
   ELSE
      DELETE FROM tagtable
      LET l_row_cnt = 1
      FOREACH qdcurs
         INSERT INTO tagtable VALUES(l_row_cnt)
         LET l_row_cnt = l_row_cnt + 1
      END FOREACH
      OPEN qdcurs
      LET l_ok=QDshow_page(l_page,l_desclen,l_tagging)
   END IF
END FUNCTION
      

FUNCTION QDshow_page(l_page, l_desclen, l_tagging)# Display a page full of lines
DEFINE   l_page     SMALLINT,
         l_desclen  SMALLINT,
         l_tagging  SMALLINT,
         l_rec      INTEGER,
         i          SMALLINT,
         l_last_ok  SMALLINT,
         l_col      SMALLINT,
         l_row      SMALLINT

   LET l_rec = (l_page-1) * m_lpp + 1

   FOR i = 1 TO m_lpp
      LET l_last_ok = i - 1
      IF NOT QDshow_line(l_page, l_desclen, l_rec+i-1, i, l_tagging) THEN
         IF i > 1 THEN
            CALL QDblank_window(i)  # Blank reset of window
         END IF
         EXIT FOR
      END IF
   END FOR
   LET i = l_rec + l_last_ok
   LET l_row = m_offset + m_lpp + 2
   LET l_col = m_width - 7

   FETCH ABSOLUTE i qdcurs 
   IF status = 0 THEN
      DISPLAY "More... " AT l_row, l_col
   ELSE
      DISPLAY "        " AT l_row, l_col
   END IF

   RETURN l_last_ok
END FUNCTION


# Display a single line

FUNCTION QDshow_line(l_page, l_desclen, l_curr, l_row, l_tagging)
DEFINE   l_page     SMALLINT,
         l_desclen  SMALLINT,
         l_curr     INTEGER,
         l_row      SMALLINT,
         l_tagging  SMALLINT,

         l_s        SMALLINT,
         l_e        SMALLINT,
         i          SMALLINT,
         l_rec      INTEGER,
         l_desc     CHAR(80),
         l_text     CHAR(80),
         l_using    CHAR(30),
         l_lth      SMALLINT,
         l_decimals SMALLINT,
         l_num      CHAR(1),
         l_temp     CHAR(80),
         l_templen  SMALLINT

   LET l_desc = m_eighty_spaces
   FETCH ABSOLUTE l_curr qdcurs 
    INTO ma_desc[1], ma_desc[2], ma_desc[3], ma_desc[4], ma_desc[5],
         ma_desc[6], ma_desc[7], ma_desc[8], ma_desc[9], ma_desc[10]
   IF status = NOTFOUND THEN
      CALL QDclear_desc()
      RETURN FALSE
   END IF
   IF ma_desc[1] IS NULL THEN
      LET l_num = " "
   ELSE
      LET l_num = l_row 
   END IF

# Build up description line...

   LET l_e = -1
   FOR i = 1 TO 10
      IF ma_desclen[i] THEN
         LET l_using = ""
         IF ma_number[i] THEN               # If this is a numeric column
            LET l_lth = ma_desclen[i]       # then build a "USING" string
            LET l_decimals = (ma_desclen[i]-l_lth) *10 # How many after dpoint?
# Build up left hand side of the using string
            IF l_decimals THEN
               LET l_lth = l_lth - l_decimals - 1
            END IF 
            IF l_lth > 1 THEN 
               LET l_using = m_using[1,l_lth-1],"&"
            ELSE
               LET l_using = "&"
            END IF
# And tack on the right hand side if there are any decimal places
            IF l_decimals THEN
               LET l_using = l_using CLIPPED,".", m_using[1,l_decimals]
            END IF
         END IF
      
         LET l_s = l_e + 2
         LET l_e = l_s + ma_desclen[i] -1
         IF ma_number[i] THEN
            LET l_temp = ma_desc[i]
            IF l_temp[1] = "$" THEN
               LET l_templen = LENGTH(l_temp)
               LET ma_desc[i] = l_temp[2, l_templen]
            END IF
            LET l_desc[l_s, l_e] = ma_desc[i] USING l_using
         ELSE
            IF ma_desc[i] IS NOT NULL AND l_s <=80 THEN # This test stops
               IF l_e > 80 THEN
                  LET l_e = 80
               END IF
               LET l_desc[l_s, l_e] = ma_desc[i]  # Informix -4518ing later on
            END IF
         END IF
      END IF
   END FOR

   LET l_text = l_num, " ",l_desc[1,l_desclen]

# And plonk it on the screen...

   LET l_row = l_row + m_offset

   IF l_tagging THEN
      SELECT line FROM tagtable WHERE line = l_curr
      IF status = 0 THEN
         DISPLAY l_text AT l_row, 1 ATTRIBUTE(REVERSE)   
      ELSE
         DISPLAY l_text AT l_row, 1 ATTRIBUTE(NORMAL)   
      END IF
   ELSE
      DISPLAY l_text AT l_row, 1 ATTRIBUTE(NORMAL)   
   END IF
   RETURN TRUE

END FUNCTION


FUNCTION QDblank_window(l_start_row) # Blank out the rest of the page
DEFINE   i             SMALLINT,
         l_start_row   SMALLINT, 
         l_row         SMALLINT

    FOR i = l_start_row TO m_lpp
       LET l_row = i + m_offset
       DISPLAY "" AT l_row, 1 ATTRIBUTE(NORMAL)
    END FOR
END FUNCTION


FUNCTION QDqbewindow(l_flags) # Do the CONSTRUCT...
DEFINE  l_flags          CHAR(30)
DEFINE  l_text           CHAR(200),
        l_cnt            SMALLINT,
        l_lth            SMALLINT,
        l_strcnt         CHAR(1),
        l_qdkey          CHAR(10),
        l_form           CHAR(15),
        l_pad            CHAR(15),
        l_finished       SMALLINT,
        i                SMALLINT 

# Find out how many key columns there are, so we know which form to open...

   LET l_cnt = 0
   FOR i = 1 TO 10
      IF ma_key[i] THEN
         LET l_cnt = l_cnt + 1
      END IF
   END FOR

# Open the appropriate form...

   CASE
   WHEN l_cnt = 0
      RETURN " 1=1"
   WHEN l_cnt = 1
      LET l_form = "coxxq01a"
   WHEN l_cnt = 2
      LET l_form = "coxxq01b"
   WHEN l_cnt = 3
      LET l_form = "coxxq01c"
   WHEN l_cnt = 4
      LET l_form = "coxxq01d"
   WHEN l_cnt = 5
      LET l_form = "coxxq01e"
   WHEN l_cnt = 6
      LET l_form = "coxxq01f"
   WHEN l_cnt = 7
      LET l_form = "coxxq01g"
   WHEN l_cnt = 8
      LET l_form = "coxxq01h"
   WHEN l_cnt = 9
      LET l_form = "coxxq01i"
   WHEN l_cnt = 10
      LET l_form = "coxxq01j"
   OTHERWISE
   END CASE

   OPEN WINDOW qbewind at 5, 8
   WITH FORM l_form
   ATTRIBUTE (CYAN, BORDER, MESSAGE LINE LAST, COMMENT LINE LAST-1)

   DISPLAY "Enter data for QBE"         AT 1, 2 ATTRIBUTE(DIM)
   DISPLAY "Esc to accept. Del to exit" AT 2, 2 ATTRIBUTE(DIM)

# Display the column descriptions...

   LET l_cnt = 0
   FOR i = 1 TO 10
      IF ma_key[i] THEN
         LET l_cnt = l_cnt + 1
         LET l_pad = "              :"
         LET l_lth = LENGTH(ma_head[i])
         IF l_lth > 14 THEN 
            LET l_lth = 13
         END IF
         IF ma_head[i] IS NOT NULL THEN 
            LET l_pad[15-l_lth, 14] = ma_head[i]
         END IF
         DISPLAY l_pad TO anyqbe[l_cnt].keyname ATTRIBUTE(DIM)
      END IF
   END FOR

# Do the CONSTRUCT... (If you know a better way to do this, feel free..)

   LET l_finished = FALSE
   WHILE NOT l_finished
      CASE
      WHEN l_cnt = 1
         CONSTRUCT l_text ON qdkey1
         FROM keyqbe1
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 2
         CONSTRUCT l_text ON qdkey1, qdkey2
         FROM keyqbe1, keyqbe2
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 3
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3
         FROM keyqbe1, keyqbe2, keyqbe3
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 4
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 5
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 6
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5,
                             qdkey6
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5,
              keyqbe6
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 7
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5,
                             qdkey6, qdkey7
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5,
              keyqbe6, keyqbe7
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 8
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5,
                             qdkey6, qdkey7, qdkey8
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5,
              keyqbe6, keyqbe7, keyqbe8
         ATTRIBUTE(NORMAL)
      WHEN l_cnt = 9
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5,
                             qdkey6, qdkey7, qdkey8, qdkey9
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5,
              keyqbe6, keyqbe7, keyqbe8, keyqbe9
         ATTRIBUTE(NORMAL)
      OTHERWISE
         CONSTRUCT l_text ON qdkey1, qdkey2, qdkey3, qdkey4, qdkey5,
                             qdkey6, qdkey7, qdkey8, qdkey9, qdkey10
         FROM keyqbe1, keyqbe2, keyqbe3, keyqbe4, keyqbe5,
              keyqbe6, keyqbe7, keyqbe8, keyqbe9, keyqbe10
         ATTRIBUTE(NORMAL)
      END CASE

# Check everything is OK...
      IF int_flag THEN
         LET l_text = "!CANCEL!"
         LET l_finished = TRUE
      END IF
      IF l_text = " 1=1" AND NOT (l_flags MATCHES "*|NA|*") THEN
         MESSAGE m_bell,"Cannot search for all records" ATTRIBUTE(REVERSE)
      ELSE
# Yep - Then change the select string so it reflects real column names...
         LET l_cnt = 0
         FOR i = 1 TO 10
            IF ma_key[i] THEN
               LET l_cnt = l_cnt + 1
               LET l_strcnt = l_cnt
               LET l_qdkey = "qdkey", l_strcnt
               LET m_change_text = l_text
               CALL QDchange_text(l_qdkey, ma_column[i], "1")
               LET l_text = m_change_text
            END IF
         END FOR
         LET l_finished = TRUE
      END IF
   END WHILE

   CLOSE WINDOW qbewind
   RETURN l_text
END FUNCTION


#  Replace l_old with l_new in m_change_text
FUNCTION QDchange_text(l_old, l_new, l_global)
DEFINE   l_old            CHAR(600),
         l_new            CHAR(600),
         l_global         CHAR(1),
         l_cnt            SMALLINT,
         l_oldlth         SMALLINT,
         l_difflth        SMALLINT,
         l_for            SMALLINT,
         i                SMALLINT

   LET l_cnt = LENGTH(m_change_text)
   LET l_oldlth = LENGTH(l_old)
   LET l_difflth = l_old - LENGTH(l_new)
   LET l_for = l_cnt - l_oldlth
   FOR i = 1 TO l_for
      IF m_change_text[i, i+l_oldlth-1]=l_old CLIPPED THEN
         IF i > 1 THEN
            LET m_change_text = m_change_text[1,i-1],l_new CLIPPED,
                m_change_text[i+l_oldlth,l_cnt] CLIPPED
         ELSE
            LET m_change_text = l_new CLIPPED,
                m_change_text[i+l_oldlth,l_cnt] CLIPPED
         END IF
# 18/10/94 EJD
# If a 'global' replace (l_global = "g") then don't EXIT FOR here but adjust
# lengths, counts, etc and continue until all l_olds are found
         IF l_global != "g" THEN
             EXIT FOR
         ELSE
             LET l_for = l_for - l_difflth
             LET l_cnt = l_cnt - l_difflth
             LET i = i - l_difflth
         END IF
      END IF
   END FOR
END FUNCTION


FUNCTION QDclear_desc() # Clear out current row details
DEFINE   i      SMALLINT

   FOR i = 1 TO 10
      LET ma_desc[i] = NULL
   END FOR
END FUNCTION


FUNCTION QDgetcollen(l_table, l_column) # Get size of column (from syscolumns)
DEFINE   l_table     CHAR(18), # LIKE systables.tabname,
         l_column    CHAR(18), # LIKE syscolumns.colname,
         l_desclen   SMALLINT

   SELECT collength 
     INTO l_desclen
     FROM syscolumns, systables
    WHERE systables.tabname  = l_table
      AND syscolumns.tabid   = systables.tabid
      AND syscolumns.colname = l_column
   IF status = NOTFOUND THEN
      LET l_desclen = 0
   END IF
   RETURN l_desclen
END FUNCTION


FUNCTION QDsystem_error()
DEFINE   l_status    INTEGER 

   LET l_status = status
   LET m_select = err_get(l_status)
   IF l_status != -219 AND 
      l_status != -1213 THEN
      LET m_select = "ERROR in coxxq01.4gl!<",m_select CLIPPED ,"<",
                     "Please quote the above error message to your ",
                     "support company"
   END IF
   CALL message_prompt(m_select, "")
   LET m_select = 
  "SELECT ROWID FROM syscolumns WHERE ROWID = -6"
   CALL QDbuild_cursor()
END FUNCTION
 

FUNCTION QDsetup_tags()

   DECLARE smeg CURSOR FOR
    SELECT line FROM tagtable
     ORDER BY line
   OPEN smeg
END FUNCTION


FUNCTION next_tag()
DEFINE   l_rec     INTEGER,
         i         SMALLINT,
         la_desc   ARRAY[10] OF CHAR(80)

   WHENEVER ANY ERROR CONTINUE     # Cope with unopen cursors
   FETCH smeg INTO l_rec

   FETCH ABSOLUTE l_rec qdcurs
    INTO ma_desc[1], ma_desc[2], ma_desc[3], ma_desc[4], ma_desc[5],
         ma_desc[6], ma_desc[7], ma_desc[8], ma_desc[9], ma_desc[10]
-- WHENEVER ANY ERROR CALL QDsystem_error
   WHENEVER ANY ERROR STOP
   IF status !=0 THEN
      LET la_desc[1]= NULL
   ELSE  
       IF m_tagkeycnt > 0 THEN
           FOR i = 1 TO m_tagkeycnt 
               IF i + m_tagstartcol > 10 THEN
                   LET la_desc[i] = ""
               ELSE
                   LET la_desc[i] = ma_desc[i + m_tagstartcol - 1]
               END IF
           END FOR
       END IF
   END IF
    
   CASE
   WHEN m_tagkeycnt = 0
      RETURN
   WHEN m_tagkeycnt = 1 
      RETURN la_desc[1]
   WHEN m_tagkeycnt = 2 
      RETURN la_desc[1], la_desc[2]
   WHEN m_tagkeycnt = 3 
      RETURN la_desc[1], la_desc[2], la_desc[3]
   WHEN m_tagkeycnt = 4 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4]
   WHEN m_tagkeycnt = 5 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5]
   WHEN m_tagkeycnt = 6 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6]
   WHEN m_tagkeycnt = 7 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7]
   WHEN m_tagkeycnt = 8 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8]
   WHEN m_tagkeycnt = 9 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8], la_desc[9]
   WHEN m_tagkeycnt = 10 
      RETURN la_desc[1], la_desc[2], la_desc[3], la_desc[4], la_desc[5],
             la_desc[6], la_desc[7], la_desc[8], la_desc[9], la_desc[10]
   END CASE

END FUNCTION
   

FUNCTION coxxq01_id()
DEFINE    l_id    CHAR(80)
LET l_id = '$Id: coxxq01.4gl,v 1.1 2001-09-24 04:18:53 afalout Exp $'
END FUNCTION
