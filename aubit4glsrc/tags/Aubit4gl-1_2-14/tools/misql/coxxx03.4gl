# $Id: coxxx03.4gl,v 1.1 2007-12-05 15:39:41 mikeaubury Exp $
{******************************************************************************
*    Filename     :   coxxx03.4gl                                             *
*    System       :   Eunice 4GL - Common Module                              *
*    Purpose      :   Display text in a box and let user choose an option     *
*    Returns      :   Option user chose                                       *
*    Author       :   Kerry S                                                 *
*    Date Written :   04/10/93                                                *
*    Last Change  :                                                           *
*                                                                             *
* 07/10/93 Kerry S  - Made code far more re-usable by splitting into          *
*                     setup_wwrap and next_wwrap functions.                   *
* 29/10/93 Kerry S  - Hard returns were not working since above mod           *
* 10/11/93 Kerry S  - If only option is "Exit", don't return a value          *
* 24/03/94 Kerry S  - next_wwrap sucks string space too much!                 *
* 27/05/94 Kerry S  - Never try to open a window bigger than the screen       *
* 21/07/94 Kerry S  - Cludgey little mod to let you specify window width      *
* 30/03/95 Kerry S  - Cope with running in the background                     *
* 31/05/95 Kerry S  - Added message_prompt_fussy() function                   *
* 12/10/95 Kerry S  - Cope with running in the background via "in_background" *
*                                                                             *
******************************************************************************}

#! message_prompt(l_text, l_menu_commands) RETURNING l_choice
#!   - Displays "l_text" in a window on-screen, and prompts the user
#!     to make a choice from a ring menu list passed as a comma-delimted
#!     string. The function returns the user's selection.
#!
#!     l_text     - Text to display in window.
#!                - The "<" character is interpreted as a hard-return.
#!                - l_text is currently limited to 800 characters
#!     l_commands - Commands to place in ring menu, delimited by commas
#!                  eg: "Yes,No" gives the user two options
#!                - A null "l_command" generates an "Exit" option
#!                - Only 5 options of 10 characters may be placed in
#!                  the l_command string.
#!     l_choice   - The full text of the ring menu choice the user chose
#!
#! message_prompt_fussy(l_row, l_col, l_width)
#!  - Allows fussy programmers the ability to place the message box
#!    window at a particular row and col, and a particular width
#!    (Passing 0 or NULL values indicates a default value will be used)
#!
#! setup_wwrap(l_text, l_width) RETURNING l_depth
#!  - Sets up a long text string for word-wrapping within l_width
#!    characters.
#!
#! next_wwrap() RETURNING l_formated_text
#!  - Returns formatted text line, being l_width characters of the
#!    l_text string passed to setup_wwrap().
#!
#!
#! eg: LET l_depth = setup_wwrap(l_long_text_string, 40)
#!     FOR i = 1 TO l_depth
#!        LET l_formated_to_40_characters_string = next_wwrap()
#!        PRINT l_formatted_to_40_characters_string
#!     END FOR
#!

DEFINE   m_text           CHAR(800),
         m_internalwidth  SMALLINT,
         m_width          SMALLINT,
         m_col            SMALLINT,
         m_row            SMALLINT,
         m_spos           SMALLINT,
         m_line_text      CHAR(132)

FUNCTION message_prompt_fussy(l_row, l_col, l_width)
DEFINE   l_col            SMALLINT,
         l_row            SMALLINT,
         l_width          SMALLINT

   LET m_col = l_col
   LET m_row = l_row
   LET m_width = l_width
END FUNCTION


FUNCTION message_prompt(l_text, l_commands)
DEFINE   l_text       CHAR(800),
         l_commands   CHAR(50),
         l_choice     CHAR(10),
         l_width      SMALLINT,
         l_depth      SMALLINT,
         l_col        SMALLINT,
         l_row        SMALLINT,
         i            SMALLINT
#error "message_prompt"
   IF l_commands IS NULL THEN
      LET l_commands = "Exit"
   END IF
#error "message_prompt1a"
#   let i = nvl(m_width, 0)
#error i
#error m_width
   IF nvl(m_width, 0) = 0 THEN   -- If particular width not specified
#error "message_prompt1b"
	  LET l_width = 50           -- just default to 50 characters
   ELSE
#error "message_prompt1c"
	  LET l_width = m_width      -- otherwise use specified width
   END IF
#error "message_prompt2"
   IF l_text[1,6]="WIDTH=" THEN     -- Ugly cludge kept for backwards
      WHENEVER ANY ERROR CONTINUE   -- compatability only. Should use
      LET l_width = l_text[7,8]     -- message_prompt_fussy instead
      IF status !=0 THEN
         LET l_width = 50
      END IF
      WHENEVER ANY ERROR STOP
      LET l_text = l_text[9, 800]
   END IF
#error "message_prompt3"
# Calculate depth of box...

   LET l_depth = setup_wwrap(l_text, l_width)
   LET l_depth = l_depth + 3

   IF nvl(m_row, 0) = 0 THEN
      LET l_row = (20 - l_depth) / 2
   ELSE
      LET l_row = m_row
   END IF

   IF nvl(m_col, 0) = 0 THEN
      LET l_col = (80 - l_width) / 2
   ELSE
      LET l_col = m_col
   END IF
#error "message_prompt4"
   CALL message_prompt_fussy(0, 0, 0)  -- Reset fussy stuff for the next
                                       -- time this routine is called

   IF l_row < 2 THEN LET l_row = 2 END IF
   IF l_col < 2 THEN LET l_col = 2 END IF
   IF l_depth > 19 THEN LET l_depth = 19 END IF
error "message_prompt5"
   OPEN WINDOW msgbox AT l_row, l_col
   WITH l_depth ROWS, l_width COLUMNS
   ATTRIBUTE(BORDER, YELLOW)
error "message_prompt6"
# Display message text...

   LET l_depth = l_depth - 3
   LET l_row = 3
   FOR i = 1 TO l_depth
      CALL coxxx03_study_text()
      DISPLAY m_line_text AT l_row, 1 ATTRIBUTE(NORMAL)
      LET l_row = l_row + 1
   END FOR
error "message_prompt7"

# Let user select choice from ring menu...
   LET l_choice = coxxx03_varimenu(l_commands)
error "message_prompt8"
   CLOSE WINDOW msgbox
error "message_prompt9"
   IF l_commands != "Exit" THEN
      RETURN l_choice
   END IF
END FUNCTION


FUNCTION setup_wwrap(l_text, l_width)
DEFINE   l_text       CHAR(800),   # Text string to be formatted
         l_width      SMALLINT,    # Width of the box
         l_depth      SMALLINT,    # Depth of the box
         l_lth        SMALLINT     # Length of entire text string

   LET m_internalwidth = l_width
   LET m_text  = l_text
   LET l_depth = 0

   LET l_lth = length(m_text)
   LET m_spos = 1
   WHILE m_spos <= l_lth 
      CALL coxxx03_study_text()
      LET l_depth = l_depth + 1
   END WHILE
   LET m_spos = 1
   LET m_text  = l_text
   RETURN l_depth
END FUNCTION


FUNCTION next_wwrap()
DEFINE   l_text       CHAR(132)

   CALL coxxx03_study_text()
   LET l_text = m_line_text
   RETURN l_text
END FUNCTION

FUNCTION coxxx03_study_text()
DEFINE  
         l_epos       SMALLINT,    # End position in text string
         l_hp         SMALLINT     # Hard-return position ("<")

# First look for a white-space to end the line on...
      FOR l_epos = m_spos + m_internalwidth TO m_spos STEP -1
         IF m_text[l_epos]=" " THEN
            EXIT FOR  
         END IF
      END FOR
      IF m_spos >= l_epos THEN           # Could not find a white-space, so
         LET l_epos = m_spos + m_internalwidth   # just chop off end of word
      END IF
      FOR l_hp = m_spos TO l_epos        # Have a look for hard-return code...
         IF m_text[l_hp]="<" THEN        # Found it...
            LET l_epos = l_hp 
            LET m_text[l_hp]=" "
            EXIT FOR
         END IF
      END FOR
      LET m_line_text = m_text[m_spos, l_epos] # This is our text to output
   
      LET m_spos = l_epos + 1
END FUNCTION


FUNCTION coxxx03_varimenu(l_commands)
DEFINE  i                  SMALLINT,
        l_lth              SMALLINT,
        l_cnt              SMALLINT,
        l_s                SMALLINT,
        l_commands         CHAR(50),
        la_opt ARRAY[5] OF CHAR(10),
        l_choice           CHAR(10),
        l_menu_name        CHAR(10)

# First determine which options are required...
#error "varimenu1"
   LET l_cnt = 1
   LET l_s   = 1
   LET l_lth = LENGTH(l_commands)
#error "varimenu2"
   FOR i = 1 TO l_lth
      IF l_commands[i,i]="," THEN
         LET la_opt[l_cnt] = l_commands[l_s, i-1]
         LET l_s = i + 1
         LET l_cnt = l_cnt + 1
      END IF
   END FOR
   LET la_opt[l_cnt] = l_commands[l_s, l_lth]
#error "varimenu3"
   IF l_cnt = 1 THEN
      LET l_menu_name = "MESSAGE"
   ELSE
      LET l_menu_name = "SELECT"
   END IF

# The following code is something that I find very embarrassing, but it's
# necessary if this routine is going to perform well for the user...
error "varimenu4"
error l_cnt
   CASE
   WHEN l_cnt = 1
      MENU l_menu_name
      COMMAND la_opt[1]
         LET l_choice = la_opt[1]
         EXIT MENU
      END MENU

   WHEN l_cnt = 2
      MENU l_menu_name
      COMMAND la_opt[1] 
         LET l_choice = la_opt[1]
         EXIT MENU
      COMMAND la_opt[2] 
         LET l_choice = la_opt[2]
         EXIT MENU
      END MENU
   
   WHEN l_cnt = 3
      MENU l_menu_name
      COMMAND la_opt[1]
         LET l_choice = la_opt[1]
         EXIT MENU
      COMMAND la_opt[2] 
         LET l_choice = la_opt[2]
         EXIT MENU
      COMMAND la_opt[3] 
         LET l_choice = la_opt[3]
         EXIT MENU
      END MENU
   
   WHEN l_cnt = 4
      MENU l_menu_name
      COMMAND la_opt[1] 
         LET l_choice = la_opt[1]
         EXIT MENU
      COMMAND la_opt[2] 
         LET l_choice = la_opt[2]
         EXIT MENU
      COMMAND la_opt[3] 
         LET l_choice = la_opt[3]
         EXIT MENU
      COMMAND la_opt[4] 
         LET l_choice = la_opt[4]
         EXIT MENU
      END MENU

   WHEN l_cnt = 5
      MENU l_menu_name
      COMMAND la_opt[1] 
         LET l_choice = la_opt[1]
         EXIT MENU
      COMMAND la_opt[2] 
         LET l_choice = la_opt[2]
         EXIT MENU
      COMMAND la_opt[3] 
         LET l_choice = la_opt[3]
         EXIT MENU
      COMMAND la_opt[4] 
         LET l_choice = la_opt[4]
         EXIT MENU
      COMMAND la_opt[5] 
         LET l_choice = la_opt[5]
         EXIT MENU
      END MENU
   END CASE
error "varimenu end"
   RETURN l_choice
END FUNCTION


 
FUNCTION coxxx03_id()
DEFINE    l_id    CHAR(80)
LET l_id = '$Id: coxxx03.4gl,v 1.1 2007-12-05 15:39:41 mikeaubury Exp $'
END FUNCTION
