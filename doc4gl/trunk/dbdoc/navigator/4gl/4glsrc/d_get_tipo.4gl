

function 	 d_get_tipo(coltype_num,col_length)
   define
		coltype_num  smallint,
		col_length   smallint,
		PrNomesTipos      record
			DecimalName char(15)
		end record
	
	let PrNomesTipos.DecimalName = "Decimal"
	return DGetTipoColuna(coltype_num,col_length,PrNomesTipos.*)
end function

#  Esta para ja funciona apenas para o Oracle.
#  Futuramente devera ir a tabela d_env
function 	 DGetTipo(coltype_num,col_length)
   define
		coltype_num  smallint,
		col_length   smallint,
		PrNomesTipos      record
			DecimalName char(15)
		end record
	
	let PrNomesTipos.DecimalName = "Number"
	return DGetTipoColuna(coltype_num,col_length,PrNomesTipos.*)
end function

function 	 DGetTipoColuna(coltype_num,col_length,PrNomesTipos)
{}
   define
		coltype_num  smallint,
		col_length   smallint,
		PrNomesTipos      record
			DecimalName char(15)
		end record,
		coltype_name char(64),
		msize, nsize smallint,
		dt_length    char(20),
		max_length   smallint,
		intv_length  char(20),
		min_length   smallint

  if coltype_num >= 256 then
	  let coltype_num = coltype_num - 256
	end if
  CASE coltype_num
    WHEN 0	-- CHAR(x)
      LET coltype_name = "Char(",
			   col_length USING "<<<<<<<<<<<", ")"
    WHEN 1	-- SMALLINT
      LET coltype_name = "Smallint"

    WHEN 2	-- INTEGER
      LET coltype_name = "Integer"

    WHEN 3	-- FLOAT
      LET coltype_name = "Float"

    WHEN 4	-- SMALLFLOAT
      LET coltype_name = "Smallfloat"

    WHEN 5	-- DECIMAL(m,n)
      LET msize = col_length / 256
      LET nsize = col_length MOD 256
		if nsize <= 0 or nsize is null or nsize = 255 then
         LET coltype_name = PrNomesTipos.DecimalName,
			"(", msize USING "<<<<<", ")"
		else
         LET coltype_name = PrNomesTipos.DecimalName clipped, 
			 "(", msize USING "<<<<<",
			 ",", nsize USING "<<<<<", ")"
		end if

    WHEN 6  -- in the SERIAL field: no account has been made of serials
	    --   with starting values
      LET coltype_name = "Serial"

    WHEN 7	-- DATE
      LET coltype_name = "Date"

    WHEN 8	-- MONEY(m,n)
--* The collength value specifies the precision of the MONEY column 
      LET msize = col_length / 256
      LET nsize = col_length MOD 256
      LET coltype_name = "Money(", msize USING "<<<<<"
      IF nsize <> 2 THEN -- scale not default 2, show it
        LET coltype_name = coltype_name CLIPPED,
			   ",", nsize USING "<<<<<"
      END IF
      LET coltype_name = coltype_name CLIPPED, ")"

    WHEN 9 -- should not occur
      LET coltype_name = "PLAN 9"

    WHEN 10 	-- DATETIME first TO last (handle in subroutine)
--* The collength value specifies the qualifiers of the DATETIME
--*   column. 
------------------------
      CALL cnvrt_dt(col_length) RETURNING dt_length
      LET coltype_name = "Datetime ", dt_length CLIPPED

    WHEN 11	-- BYTE (OnLine only)
      LET coltype_name = "Byte"

    WHEN 12	-- TEXT (OnLine only)
      LET coltype_name = "Text"

    WHEN 13 	-- VARCHAR(max,min) (handle in subroutine)
--* The collength value specifies the minimum and maximum lengths of
--*   the VARCHAR column.
------------------------
      CALL cnvrt_varch(col_length) RETURNING max_length, min_length
      LET coltype_name = "Varchar(", max_length CLIPPED
      IF min_length > 0 THEN -- min not default of zero, show it
        LET coltype_name = coltype_name CLIPPED, ",", min_length CLIPPED
      END IF
      LET coltype_name = coltype_name CLIPPED, ")"

    WHEN 14 	-- INTERVAL first TO last (handle in subroutine)
--* The collength value specifies the qualifiers of the INTERVAL
--*   column. 
------------------------
      CALL cnvrt_intvl(col_length) RETURNING intv_length
      LET coltype_name = "Interval ", intv_length CLIPPED

    OTHERWISE 	-- unexplained value
      LET coltype_name = "UNDEFINED: ", coltype_num
	end case
	return coltype_name
end function



function 	 d_aceita_nulos(tipo)
{}
   define
		tipo smallint
	
	if tipo >= 255 then
		return "Não"
	else
		return "Sim"
	end if
end function



------------------------------------------------------------
FUNCTION cnvrt_varch(clngth)
------------------------------------------------------------
--* Purpose: Converts the internal database representation of a
--*            VARCHAR column's length to the minimum and maximum 
--*            values for the column.
--* Argument(s): clngth - the syscolumns.collength value for the
--*                        VARCHAR column
--* Return Value(s): VARCHAR column's maximum and minimum length
---------------------------------------
  DEFINE 	clngth		SMALLINT,

       		hex_length	CHAR(4),
		min_length	SMALLINT,
		max_length	SMALLINT


--* Convert collength to hexadecimal. Since database uses masking of bits to
--*   quickly determine column size,  need to convert decimal number to one
--*   that more readily yields "bit" values.
------------------------
  LET hex_length = to_hex(clngth, 4)
    
--* Minimum length is 2 left-most "bits" so get decimal equivalent
  LET min_length = dec_digit(hex_length[1]) * 16 
		     + dec_digit(hex_length[2])
   
--* Minimum length is 2 right-most "bits" so get decimal equivalent
  LET max_length = dec_digit(hex_length[3]) * 16 
		     + dec_digit(hex_length[4])
    
  RETURN max_length, min_length 

END FUNCTION  -- cnvrt_varch --

------------------------------------------------------------
FUNCTION dec_digit(hex_char)
------------------------------------------------------------
--* Purpose: Converts a hexadecimal digit (0-F) to its decimal 
--*            number (0-15). The inverse operation is performed 
--*            by the hex_digit() function.
--* Argument(s): hex_char - the hex digit to convert
--* Return Value(s): the decimal number that represents hex_char
---------------------------------------
  DEFINE	hex_char	CHAR(1),

		dec_num		SMALLINT
	
--* If the hex number is A - F, then it must be converted
--*   to its decimal equivalent (10 - 15). Hex digits 0-9 do 
--*   not need to be converted.
------------------------
  IF hex_char MATCHES "[ABCDEF]" THEN
    CASE hex_char
      WHEN "A"
	LET dec_num = 10
      WHEN "B"
	LET dec_num = 11
      WHEN "C"
	LET dec_num = 12
      WHEN "D"
	LET dec_num = 13
      WHEN "E"
	LET dec_num = 14
      WHEN "F"
	LET dec_num = 15
    END CASE
  ELSE
    LET dec_num = hex_char
  END IF

  RETURN dec_num

END FUNCTION  -- dec_digit --

