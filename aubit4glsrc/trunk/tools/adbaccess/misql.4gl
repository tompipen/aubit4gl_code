# $Id: misql.4gl,v 1.7 2003-03-10 09:09:45 mikeaubury Exp $
# MISQL - Kerry's alternative to Informix-ISQL
{
MISQL is the result of work done on behalf of QUANTA SYSTEMS LTD,
AUCKLAND, NEW ZEALAND, and has been placed in the public domain with
their consent. There are no restrictions on how you can use it, but
please always include a reference to QUANTA SYSTEMS LTD and myself
in any derivative of this work.

Cheers,
Kerry Sainsbury (kerry@kcbbs.gen.nz, kerry@quanta.co.nz)

PS: Here's the obligatory disclaimer:

QUANTA SYSTEMS LTD DISCLAIMS ALL WARRANTIES RELATING TO THIS SOFTWARE,
WHETHER EXPRSSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, AND ALL
SUCH WARRANTIES ARE EXPRESSLY AND SPECIFICALLY DISCLAIMED.  NEITHER QUANTA
SYSTEMS LTD NOR ANYONE INVOLVED IN THE CREATION, PRODUCTION, OR
DELIVERY OF THIS SOFTWARE SHALL BE LIABLE FOR ANY INDIRECT, CONSEQUENTIAL,
OR INCIDENTAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE SUCH
SOFTWARE EVEN IF QUANTA SYSTEMS LTD HAS BEEN ADVISED OF THE POSSIBILITY
OF SUCH DAMAGES OR CLAIMS.  IN NO EVENT SHALL QUANTA SYSTEMS LTD
LIABILITY FOR ANY DAMAGES EVER EXCEED THE PRICE PAID FOR THE LICENSE TO
USE THE SOFTWARE, REGARDLESS OF THE FORM OF CLAIM.  THE PERSON USING THE
SOFTWARE BEARS ALL RISK AS TO THE QUALITY AND PERFORMANCE OF THE SOFTWARE.
}
# 30/03/94 Kerry S  - Ready for beta testing...
# 06/04/94 Kerry S  - Add "!" shell function
# 06/04/94 Kerry S  - Add second parameter to automatically run a given form
# 18/04/94 Kerry S  - Say if Insert/Update/Delete succeeded
#                   - Display SQL statements in correct order!
#                   - Display number of rows found after a Query
# 20/04/94 Kerry S  - Tidy up shell function
# 21/04/94 Kerry S  - Add "Searching..." message
# 27/04/94 Kerry S  - Fix nasty loop if enter character in numeric field
#                     when doing the Query-by-Example
# 25/05/94 Kerry S  - Could not set a column to null
# 31/05/94 Kerry S  - Internal screen count did not reset when choose Query
# 07/06/94 Kerry S  - Add "Output" option for forms
# 09/06/94 Kerry S  - When leave "Query-Language", go to "Forms" and return to
#                     "Query-Language" your query was destroyed.
# 30/06/94 Kerry S  - Make backward compatible with Informix 4.0
#                     (per Kingsley's notes)
# 18/07/94 Kerry S  - Sort tables by tablename
# 16/08/94 Kerry S  - Cope with !=
#                   - <DEL> in QBE now cancels Query
#                   - Say "0 rows found" if can't find any at all
# 17/08/94 Kerry S  - Add an "Info" option
# 17/08/94 Kerry S  - Cope with | in QBE
# 18/08/94 Kerry S  - Bug with | code
# 18/08/94 Kerry S  - Bug with | code (part 2)
#                   - Added -v version display
# 26/08/94 Kerry S  - Would not INSERT if enter lots of columns
# 25/11/94 Kerry S  - Display blank page where deleted records used to be
# 05/01/95 Kerry S  - "=" now checks for ='' OR IS NULL (not just IS NULL)
# 02/05/95 Kerry S  - Removed stupid wanky *slow* "x rows found" message
# 10/05/95 Kerry S  - Added an "OUTPUT" to Query menu
# 18/06/95 Kerry S  - Now clever enough to figure out if they have dbaccess
#                     or isql, and use whichever is appropriate for SQL
#                     commands
# 02/07/95 Kerry S  - Added "View" to forms menu to re-load current record
#                   - When no database name passed as argument 2 assume they
#                     want to use $E4GLDBNAME rather than "eunice"
# 22/11/95 Greg A   - Modified to test arg_val 1 to see if it's a database
#                     and if its not assumes it its a table in $E4GLDBNAME
# 01/04/96 Kerry S  - Fixed strange Network errors
# 25/06/96 Kerry S  - Was complaining about database not being closed before
#                     opening a new one
# 05/07/96 Kerry S  - "=" now checks for IS NULL only. Was also checking for
#                     ="" which, for some reason, returns rows for numeric
#                     columns that contain a zero.
# 25/07/96 Kerry S  - Removed dependancy on having a "eunice" database

DEFINE m_tabname            CHAR(18),
       m_database           CHAR(50),
       m_realname           CHAR(100),   # Holds original .sql filename
       m_viname             CHAR(100),   # Holds filename of current .sql file
       m_rowid              INTEGER,
       ma_col               ARRAY[300] OF RECORD
          colname           CHAR(18),
          val               CHAR(100)
       END RECORD,
       ma_diff              ARRAY[300] OF INTEGER,
       m_text               CHAR(3000),
       m_depth              INTEGER,
       m_isql_or_dbaccess   CHAR(9)

MAIN
define
    have_args integer

  #There is no function called serious_error
  #WHENEVER ANY ERROR CALL serious_error

  #There is no function called init_prog
  #CALL init_prog("misql")

   DEFER INTERRUPT
   DEFER QUIT
   OPTIONS MESSAGE LINE LAST
   LET have_args = false

   IF arg_val(1) = "-v"
   OR arg_val(1) = "-V"
   THEN
      CALL message_prompt("$Id: misql.4gl,v 1.7 2003-03-10 09:09:45 mikeaubury Exp $","")
      EXIT PROGRAM
   END IF


   initialize
		m_database, m_tabname
            to null


    if num_args() > 0 then
	   LET have_args = true
	   LET m_database = arg_val(1)
       if num_args() > 1 then
		   LET m_tabname = arg_val(2)
       end if
    end if

   if not have_args then
		LET m_database = fgl_getenv("E4GLDBNAME")
        if length(m_database) < 1 then
			display "No database name"
			call show_usage()
			exit program
        end if
   end if

	   WHENEVER ANY ERROR CONTINUE            -- GPA added following test to figure

   #LET m_text = "DATABASE ",m_database    -- out with to use argval(1) as dbase
   #PREPARE test_database FROM m_text      -- or as table for $E4GLDBNAME
   #EXECUTE test_database

	database m_database


	   WHENEVER ANY ERROR STOP
	   IF status!=0 THEN
		 #maybe the only parameter was not db name, but table name?
		 LET m_tabname = m_database
		 LET m_database = fgl_getenv("E4GLDBNAME")
         if length (m_database) < 1 then
			#can't be, we don't have db name
			display "Cannot connect to database ",m_tabname clipped
			call show_usage()
			exit program
         end if
	   END IF

   
#LET m_text = "database ",m_database
#PREPARE oo_p FROM m_text
#EXECUTE oo_p

	database m_database
    whenever error continue
	database m_database

--!  #This is Aubit only comment - but it's not working
{! #This is also Aubit only comment, and it is working !}

#This is supported by all 4gl compilers, and allow us to use db server name,
#user name and password, not only database name:
#	connect to m_database user "postgres" using "pg"

#This is Aubit specific way to open database connection:
#    OPEN SESSION s_id1 TO DATABASE ptest as user "postgres" password "pg"

	   IF status!=0 THEN
            display "ERROR: cannot connect to the database ", m_database clipped
            sleep 3
            exit program
       end if
    whenever error stop


   IF m_tabname IS NULL OR m_tabname = " " THEN
      LET m_tabname = NULL
   END IF

   WHENEVER ERROR CALL local_error
   LET m_depth = 17
   OPEN FORM misql FROM "misql"
   CREATE TEMP TABLE picklist
      (textt   char(80),
       linee   serial) WITH NO LOG

   IF m_tabname IS NOT NULL THEN
	  CALL form_maint(m_tabname)
   END IF


   MENU "MI-SQL"
   COMMAND "Form" "Run a form"
      CALL form_maint("")
   COMMAND "Query-Language" "Use Informix Structured Query Language"
      CALL query_maint()
   COMMAND "Database" "Change current database"
      CALL new_database()
   COMMAND "Exit" "Exit MI-SQL"
      EXIT MENU
   COMMAND KEY ("!")
      CALL shell()
   #Functions not implemented:
   #COMMAND KEY(F12)
   #   CALL user_menu()
   #COMMAND KEY(CONTROL-W)
   #   CALL show_help("")
   END MENU

   LET m_text = "rm -f /tmp/m????????.tmp"  # Cleanup temp .sql files
   RUN m_text
END MAIN

function show_usage()

	display "usage: misql [database] [table]"
	display "You can specify database name in environemtn variable E4GLDBNAME"
	display "When table naem is specified, ..."

end function


FUNCTION clear_stuff()
DEFINE   i     INTEGER
   FOR i = 1 TO 300
      LET ma_col[i].val = ""
      LET ma_diff[i] = FALSE
   END FOR
END FUNCTION


FUNCTION do_query()
DEFINE   i, j       INTEGER,
         l_where    CHAR(1000),
         l_cnt      INTEGER,
         l_first    INTEGER,
         l_wc       INTEGER,
         l_word     CHAR(80),
         l_val      CHAR(100)

   CALL set_count(300)
   OPTIONS INSERT KEY f35,
           DELETE KEY f35

   CALL clear_stuff()

   INPUT ARRAY ma_col WITHOUT DEFAULTS
   FROM scr.*

   IF check_del("") THEN
      RETURN
   END IF

   LET l_where = "select rowid, * from ",m_tabname CLIPPED, " where  1=1 "
   FOR i = 1 TO 300
      IF ma_col[i].val IS NOT NULL THEN
         CASE
         WHEN string_in("*", ma_col[i].val)
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                         " matches '",ma_col[i].val CLIPPED,"'"
         WHEN ma_col[i].val = "<<"
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                  " = (select min(",ma_col[i].colname CLIPPED,") from ",
                      m_tabname CLIPPED,")"
         WHEN ma_col[i].val = ">>"
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                  " = (select max(",ma_col[i].colname CLIPPED,") from ",
                      m_tabname CLIPPED,")"
         WHEN ma_col[i].val[1] = "<" OR ma_col[i].val[1] = ">"
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                          ma_col[i].val CLIPPED
         WHEN ma_col[i].val = "="
            LET l_where = l_where CLIPPED, " and ",
                          ma_col[i].colname CLIPPED, " IS NULL"
{
        WHEN ma_col[i].val = "=''"
           LET l_where = l_where CLIPPED, " and ",
                         ma_col[i].colname CLIPPED, " = ''"
                         ma_col[i].colname CLIPPED, " IS NULL OR ",
                         ma_col[i].colname CLIPPED, " = '')"
}
         WHEN ma_col[i].val = "!="
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                          " IS NOT NULL"
         WHEN ma_col[i].val[1,2] = "!="
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                          ma_col[i].val CLIPPED
         OTHERWISE   # Assume "="
            LET l_where = l_where CLIPPED, " and ",ma_col[i].colname CLIPPED,
                         " IN ("
            LET l_first = TRUE
            LET l_val = ma_col[i].val
            LET l_word = ""
            LET l_wc = 0
            FOR j = 1 TO LENGTH(l_val)     # Scan thru looking for pipes (|)
               IF l_val[j] = "|" THEN      # so can build multiple selection
                  IF NOT l_first THEN      # criteria...
                     LET l_where = l_where CLIPPED, ","
                  END IF
                  LET l_where = l_where CLIPPED,"'", l_word CLIPPED,"' "
                  LET l_first = FALSE
                  LET l_word = ""
                  LET l_wc = 0
               ELSE
                  LET l_wc = l_wc + 1
                  LET l_word[l_wc] = l_val[j]
               END IF
            END FOR
            IF NOT l_first THEN
               LET l_where = l_where CLIPPED, ","
            END IF
            LET l_where = l_where CLIPPED,"'", l_word CLIPPED,"')"
         END CASE
      END IF
   END FOR

   MESSAGE "Searching..."
#  PREPARE cntpre FROM l_where
#  IF STATUS !=0 THEN
#     RETURN
#  END IF
#  DECLARE cnt_curs CURSOR FOR cntpre
#  IF STATUS !=0 THEN
#     RETURN
#  END IF
#  LET l_cnt = 0
#  FOREACH cnt_curs
#     IF STATUS !=0 THEN
#        RETURN
#     END IF
#     LET l_cnt = l_cnt + 1
#  END FOREACH
#  MESSAGE l_cnt USING "<<<<&"," row(s) found"
#  CLOSE cnt_curs
#  IF STATUS !=0 THEN
#     RETURN
#  END IF
#  IF l_cnt = 0 THEN
#     RETURN
#  END IF

   PREPARE pre FROM l_where
   IF STATUS !=0 THEN
      RETURN
   END IF
   DECLARE qcurs SCROLL CURSOR WITH HOLD FOR pre

   IF STATUS !=0 THEN
      RETURN
   END IF
   OPEN qcurs
   IF STATUS !=0 THEN
      RETURN
   END IF

   MESSAGE "Searching... Complete"

   CALL show_next(1)
END FUNCTION


FUNCTION show_next(l_page)
DEFINE l_page             INTEGER
   FETCH NEXT qcurs INTO m_rowid
   IF STATUS != 0 THEN
      ERROR "No more rows in that direction"
   ELSE
      CALL load_stuff()
   END IF
   LET l_page = disp_page(l_page)
END FUNCTION

FUNCTION load_stuff()
DEFINE   i    INTEGER

   LET m_text = "select * from ",m_tabname CLIPPED," where rowid = ",m_rowid
   PREPARE ls FROM m_text
   IF STATUS !=0 THEN
      RETURN
   END IF
   DECLARE lsc CURSOR FOR ls
   IF STATUS !=0 THEN
      RETURN
   END IF
   OPEN lsc
   IF STATUS !=0 THEN
      RETURN
   END IF
   FETCH lsc INTO
ma_col[1].val,ma_col[2].val,ma_col[3].val,ma_col[4].val,ma_col[5].val,
ma_col[6].val,ma_col[7].val,ma_col[8].val,ma_col[9].val,
ma_col[10].val,ma_col[11].val,ma_col[12].val,ma_col[13].val,ma_col[14].val,
ma_col[15].val,ma_col[16].val,ma_col[17].val,ma_col[18].val,ma_col[19].val,
ma_col[20].val,ma_col[21].val,ma_col[22].val,ma_col[23].val,ma_col[24].val,
ma_col[25].val,ma_col[26].val,ma_col[27].val,ma_col[28].val,ma_col[29].val,
ma_col[30].val,ma_col[31].val,ma_col[32].val,ma_col[33].val,ma_col[34].val,
ma_col[35].val,ma_col[36].val,ma_col[37].val,ma_col[38].val,ma_col[39].val,
ma_col[40].val,ma_col[41].val,ma_col[42].val,ma_col[43].val,ma_col[44].val,
ma_col[45].val,ma_col[46].val,ma_col[47].val,ma_col[48].val,ma_col[49].val,
ma_col[50].val,ma_col[51].val,ma_col[52].val,ma_col[53].val,ma_col[54].val,
ma_col[55].val,ma_col[56].val,ma_col[57].val,ma_col[58].val,ma_col[59].val,
ma_col[60].val,ma_col[61].val,ma_col[62].val,ma_col[63].val,ma_col[64].val,
ma_col[65].val,ma_col[66].val,ma_col[67].val,ma_col[68].val,ma_col[69].val,
ma_col[70].val,ma_col[71].val,ma_col[72].val,ma_col[73].val,ma_col[74].val,
ma_col[75].val,ma_col[76].val,ma_col[77].val,ma_col[78].val,ma_col[79].val,
ma_col[80].val,ma_col[81].val,ma_col[82].val,ma_col[83].val,ma_col[84].val,
ma_col[85].val,ma_col[86].val,ma_col[87].val,ma_col[88].val,ma_col[89].val,
ma_col[90].val,ma_col[91].val,ma_col[92].val,ma_col[93].val,ma_col[94].val,
ma_col[95].val,ma_col[96].val,ma_col[97].val,ma_col[98].val,ma_col[99].val,
ma_col[100].val,ma_col[101].val,ma_col[102].val,ma_col[103].val,ma_col[104].val,
ma_col[105].val,ma_col[106].val,ma_col[107].val,ma_col[108].val,ma_col[109].val,
ma_col[110].val,ma_col[111].val,ma_col[112].val,ma_col[113].val,ma_col[114].val,
ma_col[115].val,ma_col[116].val,ma_col[117].val,ma_col[118].val,ma_col[119].val,
ma_col[120].val,ma_col[121].val,ma_col[122].val,ma_col[123].val,ma_col[124].val,
ma_col[125].val,ma_col[126].val,ma_col[127].val,ma_col[128].val,ma_col[129].val,
ma_col[130].val,ma_col[131].val,ma_col[132].val,ma_col[133].val,ma_col[134].val,
ma_col[135].val,ma_col[136].val,ma_col[137].val,ma_col[138].val,ma_col[139].val,
ma_col[140].val,ma_col[141].val,ma_col[142].val,ma_col[143].val,ma_col[144].val,
ma_col[145].val,ma_col[146].val,ma_col[147].val,ma_col[148].val,ma_col[149].val,
ma_col[150].val,ma_col[151].val,ma_col[152].val,ma_col[153].val,ma_col[154].val,
ma_col[155].val,ma_col[156].val,ma_col[157].val,ma_col[158].val,ma_col[159].val,
ma_col[160].val,ma_col[161].val,ma_col[162].val,ma_col[163].val,ma_col[164].val,
ma_col[165].val,ma_col[166].val,ma_col[167].val,ma_col[168].val,ma_col[169].val,
ma_col[170].val,ma_col[171].val,ma_col[172].val,ma_col[173].val,ma_col[174].val,
ma_col[175].val,ma_col[176].val,ma_col[177].val,ma_col[178].val,ma_col[179].val,
ma_col[180].val,ma_col[181].val,ma_col[182].val,ma_col[183].val,ma_col[184].val,
ma_col[185].val,ma_col[186].val,ma_col[187].val,ma_col[188].val,ma_col[189].val,
ma_col[190].val,ma_col[191].val,ma_col[192].val,ma_col[193].val,ma_col[194].val,
ma_col[195].val,ma_col[196].val,ma_col[197].val,ma_col[198].val,ma_col[199].val,
ma_col[200].val,ma_col[201].val,ma_col[202].val,ma_col[203].val,ma_col[204].val,
ma_col[205].val,ma_col[206].val,ma_col[207].val,ma_col[208].val,ma_col[209].val,
ma_col[210].val,ma_col[211].val,ma_col[212].val,ma_col[213].val,ma_col[214].val,
ma_col[215].val,ma_col[216].val,ma_col[217].val,ma_col[218].val,ma_col[219].val,
ma_col[220].val,ma_col[221].val,ma_col[222].val,ma_col[223].val,ma_col[224].val,
ma_col[225].val,ma_col[226].val,ma_col[227].val,ma_col[228].val,ma_col[229].val,
ma_col[230].val,ma_col[231].val,ma_col[232].val,ma_col[233].val,ma_col[234].val,
ma_col[235].val,ma_col[236].val,ma_col[237].val,ma_col[238].val,ma_col[239].val,
ma_col[240].val,ma_col[241].val,ma_col[242].val,ma_col[243].val,ma_col[244].val,
ma_col[245].val,ma_col[246].val,ma_col[247].val,ma_col[248].val,ma_col[249].val,
ma_col[250].val,ma_col[251].val,ma_col[252].val,ma_col[253].val,ma_col[254].val,
ma_col[255].val,ma_col[256].val,ma_col[257].val,ma_col[258].val,ma_col[259].val,
ma_col[260].val,ma_col[261].val,ma_col[262].val,ma_col[263].val,ma_col[264].val,
ma_col[265].val,ma_col[266].val,ma_col[267].val,ma_col[268].val,ma_col[269].val,
ma_col[270].val,ma_col[271].val,ma_col[272].val,ma_col[273].val,ma_col[274].val,
ma_col[275].val,ma_col[276].val,ma_col[277].val,ma_col[278].val,ma_col[279].val,
ma_col[280].val,ma_col[281].val,ma_col[282].val,ma_col[283].val,ma_col[284].val,
ma_col[285].val,ma_col[286].val,ma_col[287].val,ma_col[288].val,ma_col[289].val,
ma_col[290].val,ma_col[291].val,ma_col[292].val,ma_col[293].val,ma_col[294].val,
ma_col[295].val,ma_col[296].val,ma_col[297].val,ma_col[298].val,ma_col[299].val

   IF status !=0 THEN
      FOR i = 1 TO 299
         LET ma_col[i].val = ""
      END FOR
   END IF
END FUNCTION


FUNCTION show_prev(l_page)
DEFINE l_page   INTEGER
   FETCH PREVIOUS qcurs INTO m_rowid
   IF STATUS != 0 THEN
      ERROR "No more rows in that direction"
   ELSE
      CALL load_stuff()
   END IF
   LET l_page = disp_page(l_page)
END FUNCTION


FUNCTION form_maint(l_tabname)
DEFINE l_tabname  CHAR(18)

DEFINE l_tabid    INTEGER,
       i          INTEGER,
       l_page     INTEGER

error "form_maint"

   IF l_tabname IS NOT NULL THEN
      LET m_tabname = l_tabname
   ELSE
      LET m_tabname = select_table()
   END IF

error "f1"

   SELECT tabid
     INTO l_tabid
     FROM SYSTABLES WHERE tabname = m_tabname

error "f2"

   IF STATUS !=0 THEN
error "f3"
	  ERROR "Could not find the tablename in systables"
      RETURN
   END IF

   DISPLAY FORM misql
   CALL disp_dbtable()

   DECLARE isql_curs CURSOR FOR
    SELECT colname, colno
      FROM syscolumns
     WHERE syscolumns.tabid = l_tabid
     ORDER BY colno

   LET i = 0
   FOREACH isql_curs INTO ma_col[i+1].colname
      LET i = i + 1
      LET ma_col[i].val = NULL
   END FOREACH

   CALL set_count(i)

   FOR i = i + 1 TO 300
      INITIALIZE ma_col[i].* TO NULL
   END FOR

   LET l_page = disp_page(1)

   MENU "PERFORM"
   COMMAND "Query" "Searches the active database table"
      MESSAGE ""
      CALL do_query()
      LET l_page = 1
   COMMAND "Next" "Shows the next row in the Current List"
      MESSAGE ""
      CALL show_next(l_page)
   COMMAND "Previous" "Shows the previous row in the Current List"
      MESSAGE ""
      CALL show_prev(l_page)
   COMMAND "Add" "Add a row to the active database table"
      MESSAGE ""
      CALL clear_stuff()
      CALL input_stuff()
      IF NOT check_del("") THEN
         CALL insert_table()
      END IF
   COMMAND "Update" "Changes a row in the active database table"
      MESSAGE ""
      IF got_record() THEN
         CALL input_stuff()
         IF NOT check_del("") THEN
            CALL update_table()
         END IF
      END IF
   COMMAND "Remove" "Deletes a row from the active database table"
      MESSAGE ""
      IF got_record() THEN
         MENU "SURE"
         COMMAND "Yes" "Delete this row"
            CALL delete_table()
            CALL clear_stuff()
            LET l_page = disp_page(l_page)
            EXIT MENU
         COMMAND "No" "Do not delete this row"
            EXIT MENU
         #Functions not implemented:
		 #COMMAND KEY(F12) 
		 #	CALL user_menu()
         #COMMAND KEY(CONTROL-W) 
		 #   CALL show_help("")
         END MENU
      END IF

   COMMAND "Forward" "Shows the next page of the form"
      MESSAGE ""
      LET l_page = disp_page(l_page+1)

   COMMAND "Back" "Shows the previous page of the form"
      MESSAGE ""
      IF l_page > 1 THEN
         LET l_page = disp_page(l_page-1)
      ELSE
         ERROR "Already on first page"
      END IF

   COMMAND "View" "View record again with latest data"
      MESSAGE ""
      IF got_record() THEN
         CALL load_stuff()
         LET l_page = disp_page(l_page)
      END IF

   COMMAND "Info" "Show column definitions"
      CALL load_info()
      LET l_page = disp_page(l_page)

      MENU "TABLE INFO"
      COMMAND "Forward" "Shows the next page of the form"
         MESSAGE ""
         LET l_page = disp_page(l_page+1)

      COMMAND "Back" "Shows the previous page of the form"
         MESSAGE ""
         IF l_page > 1 THEN
            LET l_page = disp_page(l_page-1)
         ELSE
            ERROR "Already on first page"
         END IF

      COMMAND "Exit" "Back to main forms menu"
         EXIT MENU
#     COMMAND KEY(F12) CALL user_menu()
         -- COMMAND KEY(CONTROL-W) CALL show_help("")
      END MENU
      CALL load_stuff()
      LET l_page = disp_page(l_page)

   COMMAND "Output" "Print this row's details to the printer"
      MESSAGE ""
      CALL output_row()

   COMMAND "Exit" "Exits to the MI-SQL Menu"
      MESSAGE ""
      EXIT MENU

   COMMAND KEY ("!")
      MESSAGE ""
      CALL shell()
#  COMMAND KEY(F12) CALL user_menu()
         -- COMMAND KEY(CONTROL-W) CALL show_help("")
   END MENU
   CLOSE isql_curs
   IF STATUS !=0 THEN
      RETURN
   END IF
   CLEAR SCREEN
END FUNCTION


FUNCTION got_record()
   IF m_rowid IS NULL THEN
      ERROR "No item selected!"
      RETURN FALSE
   END IF
   RETURN TRUE
END FUNCTION


FUNCTION input_stuff()
DEFINE   i       INTEGER,
         l_curr  INTEGER,
         l_old   CHAR(100)

   INPUT ARRAY ma_col WITHOUT DEFAULTS FROM scr.*
   BEFORE ROW
      LET l_curr = arr_curr()
      LET l_old = ma_col[l_curr].val
   AFTER ROW
      IF (l_old != ma_col[l_curr].val) OR
         (l_old IS NULL AND ma_col[l_curr].val IS NOT NULL) OR
         (l_old IS NOT NULL AND ma_col[l_curr].val IS NULL)
      THEN
         LET ma_diff[l_curr] = TRUE
      END IF
#  ON KEY(F12) CALL user_menu()
         -- ON KEY(CONTROL-W) CALL show_help("")
   END INPUT
END FUNCTION


FUNCTION output_row()
DEFINE i          INTEGER

   START REPORT output_report

   FOR i = 1 TO 300
      IF ma_col[i].colname IS NOT NULL THEN
         OUTPUT TO REPORT output_report(i)
      ELSE
         EXIT FOR
      END IF
   END FOR
   FINISH REPORT output_report
END FUNCTION


REPORT output_report(i)
DEFINE i          INTEGER

#aubit
#   OUTPUT REPORT TO PRINTER
#|________________________^
#| Error at line 606, character 26
#| parse error ()

	OUTPUT report to "xxx.rpt"

   FORMAT
   ON EVERY ROW
      PRINT ma_col[i].colname, ma_col[i].val CLIPPED
   ON LAST ROW
      SKIP TO TOP OF PAGE

END REPORT


FUNCTION query_maint()
DEFINE   i            INTEGER,
         l_outfile    CHAR(100)

#  LET l_viname = get_tmpname()
#  LET l_realname = NULL

   MENU "QUERY"
   COMMAND "New" "Enter new SQL statements"
      LET m_viname = get_tmpname()
      LET m_text = "vi ",m_viname
      RUN m_text
      CALL show_sql(m_viname)
      NEXT OPTION "Run"
   COMMAND "Run" "Run the current SQL commands"
      IF m_viname IS NOT NULL THEN
         LET m_text = isql(),m_database CLIPPED, " < ",m_viname," | pg"
         RUN m_text
#        CALL execute_sql(m_viname)
         NEXT OPTION "Modify"
      ELSE
         ERROR "No command file is active!"
         NEXT OPTION "New"
      END IF
   COMMAND "Modify" "Modify the current SQL commands"
      IF m_viname IS NOT NULL THEN
         LET m_text = "vi ",m_viname
         RUN m_text
         CALL show_sql(m_viname)
         NEXT OPTION "Run"
      ELSE
         ERROR "Null command filename. Select New"
         NEXT OPTION "New"
      END IF
   COMMAND "Choose" "Choose a command file for the current SQL statement"
      LET m_text = pick_sql()
      IF m_text IS NOT NULL THEN
         LET m_realname = m_text
         IF m_viname IS NULL THEN
            LET m_viname = get_tmpname()
         END IF
         LET m_text = "cp ",m_realname clipped," ",m_viname
         RUN m_text
         CALL show_sql(m_realname)
      END IF
      NEXT OPTION "Run"
   COMMAND "Save" "Save the current SQL command file"
      IF m_realname IS NULL THEN
         ERROR "No command file is current. Use Save As"
         NEXT OPTION "As"
      ELSE
         LET m_text = "cp ",m_viname clipped," ",m_realname
         RUN m_text
         NEXT OPTION "Run"
      END IF
   COMMAND "As" "Save the current SQL command statement in a new command file"
      PROMPT "Save As: " FOR m_text
      IF m_text IS NOT NULL THEN
         LET i = LENGTH(m_text)
         IF m_text[i-3,i] != ".sql" THEN
            LET m_text = m_text CLIPPED,".sql"
         END IF
         LET m_realname = m_text
         LET m_text = "cp ",m_viname CLIPPED," ",m_text CLIPPED
         RUN m_text
      END IF
      NEXT OPTION "Run"
   COMMAND "Drop" "Drop an SQL command file"
      LET m_text = pick_sql()
      IF m_text IS NOT NULL THEN
         LET m_text = "rm -f ",m_text CLIPPED
         RUN m_text
      END IF
      NEXT OPTION "Exit"
   COMMAND "Output" "Run the current SQL commands and redirect output to a file"
      IF m_viname IS NOT NULL THEN
         PROMPT "Enter a output filename " FOR l_outfile
         IF NOT is_blank(l_outfile) THEN
            MESSAGE "Running..."
            LET m_text = isql(), m_database CLIPPED, " < ",m_viname," > ",
                          l_outfile
            RUN m_text
            MESSAGE "Running... Complete"
         END IF
#        CALL execute_sql(m_viname)
         NEXT OPTION "Modify"
      ELSE
         ERROR "No command file is active!"
         NEXT OPTION "New"
      END IF
   COMMAND "Exit" "Exit to MI-SQL Menu"
      EXIT MENU
   COMMAND KEY ("!")
      CALL shell()
#  COMMAND KEY(F12) CALL user_menu()
         -- COMMAND KEY(CONTROL-W) CALL show_help("")
   END MENU
END FUNCTION


FUNCTION show_sql(l_sqlfile)
DEFINE   l_sqlfile   CHAR(30),
         l_tmp       CHAR(30),
         i           INTEGER

   DELETE FROM picklist

   LET l_tmp = get_tmpname()
   LET l_tmp[14]="S"
   LET m_text = "cat ",l_sqlfile CLIPPED," | sed -e 's/$/~0~/' > ",l_tmp
   RUN m_text
   LOAD FROM l_tmp DELIMITER "~"
   INSERT INTO picklist

   DECLARE kcufs CURSOR FOR
    SELECT textt, linee FROM picklist
     ORDER BY linee

   LET l_sqlfile = l_sqlfile CLIPPED,":"
   DISPLAY l_sqlfile AT 4,1 ATTRIBUTE(NORMAL)
   OPEN kcufs
   FOR i = 5 TO 20
      FETCH kcufs INTO m_text
      IF status !=0 THEN
         LET m_text = ""
      END IF
      LET m_text = m_text[1,80]
      DISPLAY m_text,"" AT i, 1 ATTRIBUTE(DIM)
   END FOR
END FUNCTION


# This routine needs to understand ; as end-of-command...

FUNCTION execute_sql(l_sqlfile)
DEFINE   l_sqlfile   CHAR(30),
         l_tmp       CHAR(30),
         l_text      CHAR(200),
         i           INTEGER

   DELETE FROM picklist

   LET l_tmp = get_tmpname()
   LET m_text = "cat ",l_sqlfile CLIPPED," | sed -e 's/$/~0~/' > ",l_tmp
   RUN m_text
   LOAD FROM l_tmp DELIMITER "~"
   INSERT INTO picklist

   DECLARE ecufs CURSOR FOR
    SELECT textt, linee FROM picklist
     ORDER BY linee

   FOREACH ecufs INTO l_text
      LET m_text = m_text CLIPPED," ",l_text
   END FOREACH
   PREPARE exprep FROM m_text
   IF status != 0 THEN
#     ERROR "Error near character position ",SQLCA.SQLERRD[5] USING "<<<<<"
      RETURN
   END IF
   EXECUTE exprep
   IF status = 0 THEN
      MESSAGE SQLCA.SQLERRD[3] USING "<<<<<"," rows processed"
   END IF
END FUNCTION


FUNCTION pick_sql()
DEFINE   l_tmp      CHAR(20),
         l_sqlfile  CHAR(20)

   DELETE FROM picklist

   LET l_tmp = get_tmpname()
   LET m_text = "ls *sql | sed -e 's/$/+0+/' > ",l_tmp
   RUN m_text
   LOAD FROM l_tmp DELIMITER "+"
   INSERT INTO picklist

   LET m_text = "SELECT textt{k30} FROM picklist WHERE 1=1"
   LET l_sqlfile = query_window(m_text, "SQL file",1, "")

   RETURN l_sqlfile
END FUNCTION


FUNCTION get_tmpname()
DEFINE   l_tmp   CHAR(30)

   LET l_tmp = "/tmp/m",TIME,".tmp"
   RETURN l_tmp
END FUNCTION

FUNCTION new_database()
   PROMPT "Database: " FOR m_text
   IF m_text IS NOT NULL THEN
      LET m_database = m_text
      #LET m_text = "database ",m_database
      #PREPARE f_pr FROM m_text
      #EXECUTE f_pr

	DATABASE m_database

      CALL disp_dbtable()
   END IF
END FUNCTION


FUNCTION disp_dbtable()
DEFINE i       INTEGER

   LET m_text = m_database CLIPPED,":",m_tabname
   LET i = 80 - LENGTH(m_text)

   DISPLAY "" AT 2, 1
   DISPLAY m_text CLIPPED AT 3, i
END FUNCTION


FUNCTION select_table()
DEFINE   l_tabname     CHAR(18)

   LET m_text = "select tabname{k20} from systables WHERE 1=1 ORDER BY tabname"
   LET l_tabname =  query_window(m_text, "Table", 1, "FQ|AS")
   RETURN l_tabname
END FUNCTION


FUNCTION disp_page(l_page)
DEFINE l_page    INTEGER,
       l_start   INTEGER,
       i         INTEGER

   LET l_start = ((l_page-1) * m_depth) + 1

   IF ma_col[l_start].colname IS NULL THEN
      LET l_start = 1
      LET l_page = 1
   END IF

   FOR i = l_start TO l_start +  m_depth -1
      DISPLAY ma_col[i].colname, ma_col[i].val TO scr[i - l_start + 1].*
   END FOR
   RETURN l_page
END FUNCTION


FUNCTION insert_table()
DEFINE   i           INTEGER,
         l_value     CHAR(2000),
         l_first     INTEGER

   LET l_first = TRUE

   LET m_text = "insert into ",m_tabname CLIPPED,"("
   LET l_value= " values("

   FOR i = 1 TO 300
      IF ma_col[i].colname IS NULL THEN
         EXIT FOR
      END IF
      IF ma_diff[i] THEN
         IF NOT l_first THEN
            LET m_text = m_text CLIPPED,","
            LET l_value = l_value CLIPPED,","
         ELSE
            LET l_first = FALSE
         END IF
         LET m_text = m_text CLIPPED,ma_col[i].colname
         LET l_value = l_value CLIPPED,"'",ma_col[i].val CLIPPED,"'"
      END IF
   END FOR

   IF l_first THEN
      ERROR "MI-SQL Cannot insert a null record"
   ELSE
      LET m_text = m_text CLIPPED,") ",l_value CLIPPED,")"

      PREPARE pp2 FROM m_text
      EXECUTE pp2
      IF status = 0 THEN
         MESSAGE "Row inserted"
      END IF
   END IF
END FUNCTION

FUNCTION delete_table()
  LET m_text = "delete from ",m_tabname CLIPPED," where rowid = ",m_rowid
  PREPARE DO FROM m_text
  EXECUTE DO
  IF status = 0 THEN
     MESSAGE "Row deleted"
  END IF
  LET m_rowid = NULL
END FUNCTION


FUNCTION update_table()
DEFINE i INTEGER

   BEGIN WORK
   FOR i = 1 TO 300
      IF ma_col[i].colname IS NULL THEN
         EXIT FOR
      END IF
      IF ma_diff[i] THEN
         LET m_text = "update ",m_tabname CLIPPED,
                        " set ",ma_col[i].colname CLIPPED,
                       " = '", ma_col[i].val CLIPPED,
                    "' where rowid = ",m_rowid
         PREPARE pp FROM m_text
         IF STATUS !=0 THEN
            EXIT FOR
         END IF
         EXECUTE pp
         IF STATUS !=0 THEN
            EXIT FOR
         END IF
      END IF
   END FOR
   IF STATUS !=0 THEN
      ROLLBACK WORK
   ELSE
      MESSAGE "Row updated"
      COMMIT WORK
   END IF
END FUNCTION

FUNCTION string_in(word, l_where_part)
DEFINE
      word            CHAR(20),
      where_length    INTEGER,
      lngth,
      i	              INTEGER,
      l_where_part    CHAR(500)

      # Scan where_part for the first occurrence of word,
      # and return the position found.
      LET lngth = LENGTH(word)
      LET where_length = LENGTH(l_where_part)

      FOR i = 1 TO where_length
          IF l_where_part[i] = word[1] THEN
             IF l_where_part[i,i+lngth-1] = word THEN
	        RETURN i
	     END IF
          END IF
      END FOR

      RETURN 0

END FUNCTION

FUNCTION local_error()
DEFINE l_status   INTEGER

   LET l_status = STATUS
   LET m_text = err_get(STATUS)
   ERROR m_text CLIPPED
   LET STATUS = l_status
END FUNCTION


FUNCTION shell()
   PROMPT "Command: !" FOR m_text
   IF m_text IS NOT NULL THEN
      RUN m_text
      PROMPT "Press <Enter> to continue" FOR m_text
   END IF
END FUNCTION


FUNCTION load_info()
DEFINE   i            INTEGER,
         l_tabid      INTEGER,
         l_coltype    INTEGER,
         l_collength  INTEGER

   MESSAGE "Loading column definitions..."
   SELECT tabid
     INTO l_tabid
     FROM systables
    WHERE tabname = m_tabname

   IF status !=0 THEN
      CALL message_prompt("Information not found!", "")
      RETURN
   END IF

   DECLARE info_curs CURSOR FOR
    SELECT coltype, collength, colno
      FROM syscolumns
     WHERE syscolumns.tabid = l_tabid
     ORDER BY colno

   LET i = 0
   FOREACH info_curs INTO l_coltype, l_collength
      LET i = i + 1
      IF i = 301 THEN
         CALL message_prompt("More than 300 columns in table!", "")
         EXIT FOREACH
      END IF
      LET ma_col[i].val = get_type(l_coltype, l_collength)
   END FOREACH
   MESSAGE ""
END FUNCTION


-- Identify if client uses dbacess or isql...

FUNCTION isql()
DEFINE   l_return_code    INTEGER

   IF is_blank(m_isql_or_dbaccess) THEN
      RUN "dbaccess mja11a lkz99a 2>/dev/null" RETURNING l_return_code
      IF l_return_code / 256 = 1 THEN   -- There's no dbaccess, so assume isql
         LET m_isql_or_dbaccess = "isql"
      ELSE
         LET m_isql_or_dbaccess = "dbaccess"
      END IF
   END IF

   RETURN m_isql_or_dbaccess
END FUNCTION



FUNCTION get_type(l_coltype, l_collength)
DEFINE l_coltype     INTEGER,
       l_collength   INTEGER,
       type_text CHAR(41)

CASE
WHEN l_coltype=0 OR l_coltype=256
    LET type_text="CHAR(", l_collength USING "<<<", ")"
WHEN l_coltype=1 OR l_coltype=257
    LET type_text="SMALLINT"
WHEN l_coltype=2 OR l_coltype=258
    LET type_text="INTEGER"
WHEN l_coltype=3 OR l_coltype=259
    LET type_text="FLOAT"
WHEN l_coltype=4 OR l_coltype=260
    LET type_text="SMALLFLOAT"
WHEN l_coltype=5 OR l_coltype=261
    LET type_text="DECIMAL"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=6 OR l_coltype=262
    IF l_collength > 1 THEN
        LET type_text="SERIAL(",
            l_collength USING "<<<<<<<<<&", ")"
    ELSE
        LET type_text="SERIAL"
    END IF
WHEN l_coltype=7 OR l_coltype=263
    LET type_text="DATE"
WHEN l_coltype=8 OR l_coltype=264
    LET type_text="MONEY"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=10 OR l_coltype=266
    LET type_text="DATETIME"
    LET type_text = dt_length(l_collength, type_text)
WHEN l_coltype=11 OR l_coltype=267
    LET type_text="BYTE"
WHEN l_coltype=12 OR l_coltype=268
    LET type_text="TEXT"
WHEN l_coltype=13 OR l_coltype=269
    LET type_text="VARCHAR"
    LET type_text = varc_length(l_collength, type_text)
WHEN l_coltype=14 OR l_coltype=270
    LET type_text="INTERVAL"
    LET type_text = dt_length(l_collength, type_text)
OTHERWISE
    LET type_text="????"
END CASE

## Now the not nulls
IF l_coltype > 255 THEN
    LET type_text=type_text CLIPPED, " NOT NULL"
END IF

RETURN type_text

END FUNCTION

FUNCTION dec_length(l_collength, type_text)
# calculate length & precision for DECIMAL & MONEY data types
DEFINE type_text CHAR(41)
DEFINE len, prec INTEGER   # Length & Precision
DEFINE l_collength   INTEGER

LET len = l_collength / 256
LET prec = l_collength mod 256
IF prec > len THEN
    IF type_text = "DECIMAL" THEN
        # floating precision
        INITIALIZE prec TO NULL
    ELSE
        # 0 precision
        LET prec = 0
    END IF
END IF

IF prec IS NULL THEN
    LET type_text = type_text CLIPPED, "(", len USING "<<<<&", ")"
ELSE
    LET type_text = type_text CLIPPED, "(", len USING "<<<<&", ",",
        prec USING "<<<<&", ")"
END IF

RETURN type_text

END FUNCTION

FUNCTION varc_length(l_collength, type_text)
# calculate max & min length for VARCHAR data types
DEFINE l_collength   INTEGER
DEFINE type_text CHAR(41)
DEFINE minl, maxl INTEGER  # Length & Precision

LET maxl = l_collength mod 256
LET minl = l_collength / 256

IF minl < 2 THEN
    LET type_text = type_text CLIPPED, "(", maxl USING "<<<<&", ")"
ELSE
    LET type_text = type_text CLIPPED, "(", maxl USING "<<<<&", ",",
        minl USING "<<<<&", ")"
END IF

RETURN type_text

END FUNCTION

FUNCTION dt_length(l_collength, type_text)
# calculate range for DATETIME & INTERVAL
DEFINE l_collength   INTEGER
DEFINE type_text CHAR(41)

CASE
WHEN l_collength = 459
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(1)"
WHEN l_collength = 546
    LET type_text = type_text CLIPPED, " MONTH TO MONTH"
WHEN l_collength = 580
    LET type_text = type_text CLIPPED, " DAY TO DAY"
WHEN l_collength = 614
    LET type_text = type_text CLIPPED, " HOUR TO HOUR"
WHEN l_collength = 648
    LET type_text = type_text CLIPPED, " MINUTE TO MINUTE"
WHEN l_collength = 682
    LET type_text = type_text CLIPPED, " SECOND TO SECOND"
WHEN l_collength = 716
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(2)"
WHEN l_collength = 939
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(1)"
WHEN l_collength = 973
    # default fraction is 3, so no need for ()
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION"
WHEN l_collength = 1024
    LET type_text = type_text CLIPPED, " YEAR TO YEAR"
WHEN l_collength = 1060
    LET type_text = type_text CLIPPED, " MONTH TO DAY"
WHEN l_collength = 1094
    LET type_text = type_text CLIPPED, " DAY TO HOUR"
WHEN l_collength = 1128
    LET type_text = type_text CLIPPED, " HOUR TO MINUTE"
WHEN l_collength = 1162
    LET type_text = type_text CLIPPED, " MINUTE TO SECOND"
WHEN l_collength = 1196
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(2)"
WHEN l_collength = 1230
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(4)"
WHEN l_collength = 1419
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(1)"
WHEN l_collength = 1453
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION"
WHEN l_collength = 1487
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(5)"
WHEN l_collength = 1538
    LET type_text = type_text CLIPPED, " YEAR TO MONTH"
WHEN l_collength = 1574
    LET type_text = type_text CLIPPED, " MONTH TO HOUR"
WHEN l_collength = 1608
    LET type_text = type_text CLIPPED, " DAY TO MINUTE"
WHEN l_collength = 1642
    LET type_text = type_text CLIPPED, " HOUR TO SECOND"
WHEN l_collength = 1676
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(2)"
WHEN l_collength = 1710
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(4)"
WHEN l_collength = 1899
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(1)"
WHEN l_collength = 1933
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION"
WHEN l_collength = 1967
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(5)"
WHEN l_collength = 2052
    LET type_text = type_text CLIPPED, " YEAR TO DAY"
WHEN l_collength = 2088
    LET type_text = type_text CLIPPED, " MONTH TO MINUTE"
WHEN l_collength = 2122
    LET type_text = type_text CLIPPED, " DAY TO SECOND"
WHEN l_collength = 2156
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(2)"
WHEN l_collength = 2190
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(4)"
WHEN l_collength = 2379
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(1)"
WHEN l_collength = 2413
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION"
WHEN l_collength = 2447
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(5)"
WHEN l_collength = 2566
    LET type_text = type_text CLIPPED, " YEAR TO HOUR"
WHEN l_collength = 2602
    LET type_text = type_text CLIPPED, " MONTH TO SECOND"
WHEN l_collength = 2636
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(2)"
WHEN l_collength = 2670
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(4)"
WHEN l_collength = 2859
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(1)"
WHEN l_collength = 2893
    LET type_text = type_text CLIPPED, " DAY TO FRACTION"
WHEN l_collength = 2927
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(5)"
WHEN l_collength = 3080
    LET type_text = type_text CLIPPED, " YEAR TO MINUTE"
WHEN l_collength = 3116
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(2)"
WHEN l_collength = 3150
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(4)"
WHEN l_collength = 3373
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION"
WHEN l_collength = 3407
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(5)"
WHEN l_collength = 3594
    LET type_text = type_text CLIPPED, " YEAR TO SECOND"
WHEN l_collength = 3630
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(4)"
WHEN l_collength = 3851
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(1)"
WHEN l_collength = 3887
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(5)"
WHEN l_collength = 4108
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(2)"
WHEN l_collength = 4365
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION"
WHEN l_collength = 4622
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(4)"
WHEN l_collength = 4879
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(5)"
OTHERWISE
    LET type_text = type_text CLIPPED, " ????"
END CASE

RETURN type_text

END FUNCTION
