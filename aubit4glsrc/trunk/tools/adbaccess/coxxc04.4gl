# $Id: coxxc04.4gl,v 1.2 2002-02-25 18:27:26 mikeaubury Exp $
{******************************************************************************
*    Filename: coxxc04.4gl                                                    *
*    System  : Eunice 4GL - Library Module                                    *
*    Purpose : round() a value. Get the abs()olute value                      *
*    Returns :                                                                *
*    Author  : Unknown                                                        *
*                                                                             *
* 14/09/94 Kerry S  - Added "is_blank". Dunno if this is the right place tho' *
* 14/09/94 Kerry S  - Added "updated". I guess I've just made this file a bit *
*                     of a dumping ground for little aimless functions        *
* 05/10/94 Kerry S  - And "is_number".                                        *
* 02/12/94 Kerry S  - Added "max" and "min"                                   *
* 07/12/94 Kerry S  - nvl now handles money fields                            *
* 27/01/95 Kerry S  - "round" only rounded accurately to 2dp!                 *
* 08/02/95 Kerry S  - Use Jack Parker's is_number 'cause it copes with an     *
*                     unusual Informix bug                                    *
* 10/02/95 Kerry S  - Added "bwz" - blank when zero. Nice for reports         *
* 25/08/95 Julia R  - Added "is_numeric" this also checks for symbols passed  *
* 29/08/95 Kerry S  - Added "!" to the "is_numeric" symbol list               *
* 29/11/95 Eric H   - didn't allow more than 4 decimals precision             *
* 17/01/95 GBA      - 'is_numeric' allowed a '!' but should check for '!='    *
* 22/01/96 EJD      - Added 'calc_percent' to calculate a percentage and store*
*                     the result in a variable of a given size.               *
*                                                                             *
******************************************************************************}

#! round(amount, precision) RETURNs rounded amount
#!               - Rounds "amount" to "precision" decimal places
#!
#! abs(amount) RETURNs absolute value
#!               - eg: if amount = -35 abs will return 35.
#!
#! is_blank(variable) RETURNS TRUE/FALSE
#!               - if variable is NULL or = " " then returns TRUE
#!
#! is_number(variable) RETURNs TRUE/FALSE
#!               - if variable is numeric then returns TRUE
#!
#! updated() RETURNS number of rows updated
#!               - Returns the number of rows updated by the preceeding
#!                 UPDATE (ie: SQLCA.SQLERRD[3])
#!
#! maxval(value1, value2)     RETURNs the larger of the two parameters
#!
#! minval(value1, value2)     RETURNs the smaller of the two parameters
#!
#! nvl(oldvalue, newvalue) RETURNs newvalue if oldvalue is null
#!               - oldvalue - The value that is to be compared to null.
#!               - newvalue - The value to return if value is null.
#!
#!               - Returns newvalue if oldvalue is null, otherwise
#!                 returns oldvalue
#!
#! bwz(value)              RETURNs a blank when value is zero
#!                         (this is ideal for reporting)
#!
#! is_numeric(l_string) RETURNs True or False if a numeric field, handles
#!                       passed symbols eg. < > = |   etc.   
#!
#! trunc(value, precision) RETURNs value truncated to precision decimal places
#!               - value - The value to truncate
#!               - precision - The number of decimal place to truncate to.
#!                             If you want to truncate to figures before the
#!                             decimal place, use negative numbers.
#! calc_percent(numerator, demoninator, size) RETURNs percentage 
#!         to a maximum size required



FUNCTION nvl(l_original, l_if_null)
DEFINE  l_original                     CHAR(80),
        l_if_null                      CHAR(80)
#error "in nvl"
    IF LENGTH(l_original) = 0 THEN
#error "in nvl1"
		RETURN l_if_null
    ELSE
#error "in nvl2"
		IF l_original[1]="$" THEN   # Cope with money fields
           LET l_original[1]=" "
        END IF
#error "in nvl3"
        RETURN l_original
    END IF

END FUNCTION


FUNCTION round(amount,precsn)
DEFINE amount		MONEY(32,16),
       factor           INTEGER, 
       precsn		SMALLINT,
       spare		DECIMAL(32,0)

   LET factor = 10 ** precsn
   LET spare = amount * factor
   LET amount = spare / factor

   RETURN amount
END FUNCTION


#FUNCTION abs(l_amount)
#DEFINE   l_amount  DECIMAL(20,5) 
#
   #IF l_amount < 0 THEN 
      #LET l_amount = - l_amount
   #END IF
   #RETURN l_amount
#END FUNCTION
 

FUNCTION is_blank(l_str)
DEFINE   l_str       CHAR(50)

   IF LENGTH(l_str) = 0 THEN
      RETURN TRUE
   END IF
   RETURN FALSE
END FUNCTION

FUNCTION trunc(l_value, l_precision)

   DEFINE
      l_value                          DECIMAL(32, 16),
      l_precision                      SMALLINT

   DEFINE
      l_factor                         DECIMAL(32, 16),
      l_valstr                         CHAR(34)

   LET l_factor = 10 ** l_precision
   LET l_value = l_value * l_factor
   LET l_valstr = l_value USING "----------------&.&&&&&&&&&&&&&&&&"
   LET l_value = l_valstr[1, 17]
   LET l_value = l_value / l_factor

   RETURN l_value

END FUNCTION


FUNCTION is_number_dummy_function_stupid_informix_bug_wank()
   WHENEVER ANY ERROR CONTINUE
END FUNCTION


FUNCTION is_number(l_text)
DEFINE   l_text   INTEGER   

   IF status != 0 THEN
      RETURN FALSE
   ELSE
      RETURN TRUE
   END IF

END FUNCTION


FUNCTION updated()
   RETURN SQLCA.SQLERRD[3]
END FUNCTION


-- bwz = BLANK WHEN ZERO

FUNCTION bwz(l_number)
DEFINE   l_number    DECIMAL(32,16)

   IF l_number = 0 THEN
      RETURN ""
   END IF
   RETURN l_number
END FUNCTION

FUNCTION is_numeric(l_string)
DEFINE 
       l_string    CHAR(80),
       l_ok,
       i           SMALLINT

   LET l_ok = TRUE                 #Default to TRUE

   FOR i = 1 TO LENGTH(l_string)
      IF l_string[i] < "0" OR      #Set FALSE for invalid char
         l_string[i] > "9"   THEN
         IF l_string[i] = ">" OR
            l_string[i] = "<" OR
            l_string[i] = "[" OR
            l_string[i] = "]" OR
            l_string[i] = ":" OR
            l_string[i] = "|" OR
            l_string[i,i+1] = "!=" OR
            l_string[i] = "="   THEN
         ELSE 
              LET l_ok = FALSE
              EXIT FOR
         END IF
      END IF
   END FOR

   RETURN l_ok

END FUNCTION 
  
FUNCTION calc_percent(l_numerator, l_denominator, l_size)
DEFINE
    l_numerator        DECIMAL(32,5),
    l_denominator      DECIMAL(32,5),
    l_size             SMALLINT,
    l_maxval           DECIMAL(12,2),
    l_minval           DECIMAL(12,2),
    l_percent          DECIMAL(12,2)

    LET l_numerator = nvl(l_numerator, 0)
    LET l_denominator = nvl(l_denominator, 0)
    LET l_size = nvl(l_size, 3)
    CASE 
        WHEN l_size = 1
            LET l_maxval = 9.99
        WHEN l_size = 2
            LET l_maxval = 99.99
        WHEN l_size = 3
            LET l_maxval = 999.99
        WHEN l_size = 4
            LET l_maxval = 9999.99
        WHEN l_size = 5
            LET l_maxval = 99999.99
        WHEN l_size = 6
            LET l_maxval = 999999.99
        WHEN l_size = 7
            LET l_maxval = 9999999.99
        WHEN l_size = 8
            LET l_maxval = 99999999.99
        WHEN l_size = 9
            LET l_maxval = 999999999.99
        WHEN l_size = 10
            LET l_maxval = 9999999999.99
        OTHERWISE
            LET l_maxval = 999.99
    END CASE

    LET l_minval = -1 * l_maxval

    IF l_denominator = 0 THEN
         CASE 
             WHEN l_numerator > 0 AND l_size > 2
                 LET l_percent = 100
             WHEN l_numerator < 0 AND l_size > 2
                 LET l_percent = -100
             OTHERWISE
                 LET l_percent = 0
         END CASE
    ELSE
         CASE 
             WHEN (l_numerator / l_denominator) * 100 > l_maxval
                 LET l_percent = l_maxval
             WHEN (l_numerator / l_denominator) * 100 < l_minval
                 LET l_percent = l_minval
             OTHERWISE
                 LET l_percent = (l_numerator / l_denominator) * 100 
         END CASE
    END IF

    RETURN l_percent
  
END FUNCTION 
  
FUNCTION centre(l_text, l_fieldsize)
DEFINE   l_text          CHAR(150),
         l_fieldsize     SMALLINT,
         l_lth           SMALLINT,
         l_centre        SMALLINT,
         l_centered      CHAR(150)

   LET l_lth = LENGTH(l_text)

   LET l_centre = l_fieldsize / 2 - l_lth / 2
   IF l_centre < 1 THEN
      LET l_centre = 1
   END IF
   IF l_fieldsize < l_centre + l_lth THEN
      LET l_lth = l_fieldsize - l_centre
   END IF
   LET l_centered = 150 SPACES
   LET l_centered[l_centre, l_centre+l_lth]=l_text CLIPPED
   RETURN l_centered
END FUNCTION


FUNCTION check_del(str)
   DEFINE str CHAR(80)
	
   IF int_flag <> 0 OR quit_flag <> 0 THEN
      MESSAGE str CLIPPED
      LET int_flag = 0
      LET quit_flag = 0
      RETURN TRUE
   END IF
   RETURN FALSE

END FUNCTION


FUNCTION coxxc04_id()
DEFINE    l_id    CHAR(80)
LET l_id = '$Id: coxxc04.4gl,v 1.2 2002-02-25 18:27:26 mikeaubury Exp $'
END FUNCTION
