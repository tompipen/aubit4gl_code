{**
 * Test the conversion from char to interval works.
 * @process DATA_TYPE_CONVERSION
 *}

MAIN
	DEFINE lv_char CHAR(19)
  DEFINE lv_iv_defyy INTERVAL YEAR TO YEAR
  DEFINE lv_iv_oneyy INTERVAL YEAR(1) TO YEAR
  DEFINE lv_iv_nineyy INTERVAL YEAR(9) TO YEAR

  DEFINE lv_iv_ymo INTERVAL YEAR TO MONTH

  DEFINE lv_iv_defmomo INTERVAL MONTH TO MONTH
  DEFINE lv_iv_onemomo INTERVAL MONTH(1) TO MONTH
  DEFINE lv_iv_ninemomo INTERVAL MONTH(9) TO MONTH

  DEFINE lv_iv_defdd INTERVAL DAY TO DAY
  DEFINE lv_iv_onedd INTERVAL DAY(1) TO DAY
  DEFINE lv_iv_ninedd INTERVAL DAY(9) TO DAY
  DEFINE lv_iv_dh INTERVAL DAY TO HOUR
  DEFINE lv_iv_dm INTERVAL DAY TO MINUTE
  DEFINE lv_iv_ds INTERVAL DAY TO SECOND
  DEFINE lv_iv_df INTERVAL DAY TO FRACTION

  DEFINE lv_iv_defhh INTERVAL HOUR TO HOUR
  DEFINE lv_iv_onehh INTERVAL HOUR(1) TO HOUR
  DEFINE lv_iv_ninehh INTERVAL HOUR(9) TO HOUR
  DEFINE lv_iv_hm INTERVAL HOUR TO MINUTE
  DEFINE lv_iv_hs INTERVAL HOUR TO SECOND
  DEFINE lv_iv_hf INTERVAL HOUR TO FRACTION

  DEFINE lv_iv_defmm INTERVAL MINUTE TO MINUTE
  DEFINE lv_iv_onemm INTERVAL MINUTE(1) TO MINUTE
  DEFINE lv_iv_ninemm INTERVAL MINUTE(9) TO MINUTE
  DEFINE lv_iv_ms INTERVAL MINUTE TO SECOND
  DEFINE lv_iv_mf INTERVAL MINUTE TO FRACTION

  DEFINE lv_iv_defss INTERVAL SECOND TO SECOND
  DEFINE lv_iv_oness INTERVAL SECOND(1) TO SECOND
  DEFINE lv_iv_niness INTERVAL SECOND(9) TO SECOND
  DEFINE lv_iv_sf INTERVAL SECOND TO FRACTION

  DEFINE lv_iv_defff INTERVAL FRACTION TO FRACTION
  DEFINE lv_iv_oneff INTERVAL FRACTION TO FRACTION(1)
  DEFINE lv_iv_nineff INTERVAL FRACTION TO FRACTION(5)

	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  -- INTERVAL YEAR TO YEAR
	LET lv_char = "0000"
	LET lv_iv_defyy = lv_char
	IF lv_iv_defyy != INTERVAL(0000) YEAR TO YEAR THEN
		DISPLAY "Error INTERVAL 0000"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9999"
	LET lv_iv_defyy = lv_char
	IF lv_iv_defyy != INTERVAL(9999) YEAR TO YEAR THEN
		DISPLAY "Error INTERVAL 9999"
	  LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_iv_oneyy = lv_char
	IF lv_iv_oneyy != INTERVAL(0) YEAR(1) TO YEAR THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9"
	LET lv_iv_oneyy = lv_char
	IF lv_iv_oneyy != INTERVAL(9) YEAR(1) TO YEAR THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

	LET lv_char = "000000000"
	LET lv_iv_nineyy = lv_char
	IF lv_iv_nineyy != INTERVAL(000000000) YEAR(9) TO YEAR THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

	LET lv_char = "999999999"
	LET lv_iv_nineyy = lv_char
	IF lv_iv_nineyy != INTERVAL(999999999) YEAR(9) TO YEAR THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

	-- YEAR TO MONTH
	LET lv_char = "0000-00"
	LET lv_iv_ymo = lv_char
	IF lv_iv_ymo != INTERVAL(0000-00) YEAR TO MONTH THEN
		DISPLAY "Error INTERVAL 0000-00"
	  LET exitStatus = 1
	END IF

  -- INTERVAL MONTH TO MONTH
	LET lv_char = "00"
	LET lv_iv_defmomo = lv_char
	IF lv_iv_defmomo != INTERVAL(00) MONTH TO MONTH THEN
		DISPLAY "Error INTERVAL 00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "99"
	LET lv_iv_defmomo = lv_char
	IF lv_iv_defmomo != INTERVAL(99) MONTH TO MONTH THEN
		DISPLAY "Error INTERVAL 99"
	  LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_iv_onemomo = lv_char
	IF lv_iv_onemomo != INTERVAL(0) MONTH(1) TO MONTH THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9"
	LET lv_iv_onemomo = lv_char
	IF lv_iv_onemomo != INTERVAL(9) MONTH(1) TO MONTH THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

	LET lv_char = "000000000"
	LET lv_iv_ninemomo = lv_char
	IF lv_iv_ninemomo != INTERVAL(000000000) MONTH(9) TO MONTH THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

	LET lv_char = "999999999"
	LET lv_iv_ninemomo = lv_char
	IF lv_iv_ninemomo != INTERVAL(999999999) MONTH(9) TO MONTH THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

	-- YEAR TO DAY
	--LET lv_char = "0000-00-00"
	--LET lv_iv_yd = lv_char
	--IF lv_iv_yd != INTERVAL(0000-00-00) YEAR TO DAY THEN
		--DISPLAY "Error INTERVAL 0000-00-00"
	  --LET exitStatus = 1
	--END IF

	-- MONTH TO DAY
	--LET lv_char = "00-00"
	--LET lv_iv_mod = lv_char
	--IF lv_iv_mod != INTERVAL(00-00) MONTH TO DAY THEN
		--DISPLAY "Error INTERVAL 00-00"
	  --LET exitStatus = 1
	--END IF

	-- DAY TO DAY
	LET lv_char = "00"
	LET lv_iv_defdd = lv_char
	IF lv_iv_defdd != INTERVAL(00) DAY TO DAY THEN
		DISPLAY "Error INTERVAL 00"
	  LET exitStatus = 1
	END IF

	LET lv_char = "99"
	LET lv_iv_defdd = lv_char
	IF lv_iv_defdd != INTERVAL(99) DAY TO DAY THEN
		DISPLAY "Error INTERVAL 99"
	  LET exitStatus = 1
	END IF

	LET lv_char = "0"
	LET lv_iv_onedd = lv_char
	IF lv_iv_onedd != INTERVAL(0) DAY(1) TO DAY THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

	LET lv_char = "9"
	LET lv_iv_onedd = lv_char
	IF lv_iv_onedd != INTERVAL(9) DAY(1) TO DAY THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

	LET lv_char = "000000000"
	LET lv_iv_ninedd = lv_char
	IF lv_iv_ninedd != INTERVAL(000000000) DAY(9) TO DAY THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

	LET lv_char = "999999999"
	LET lv_iv_ninedd = lv_char
	IF lv_iv_ninedd != INTERVAL(999999999) DAY(9) TO DAY THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

	-- DAY TO HOUR 
  LET lv_char = "00 00"
  LET lv_iv_dh = lv_char
  IF lv_iv_dh != INTERVAL(00 00) DAY TO HOUR THEN
		DISPLAY "Error INTERVAL 00 00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99 23"
  LET lv_iv_dh = lv_char
  IF lv_iv_dh != INTERVAL(99 23) DAY TO HOUR THEN
		DISPLAY "Error INTERVAL 99 99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00 00:00"
  LET lv_iv_dm = lv_char
  IF lv_iv_dm != INTERVAL(00 00:00) DAY TO MINUTE THEN
		DISPLAY "Error INTERVAL 00 00:00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99 23:59"
  LET lv_iv_dm = lv_char
  IF lv_iv_dm != INTERVAL(99 23:59) DAY TO MINUTE THEN
		DISPLAY "Error INTERVAL 99 99:99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00 00:00:00"
  LET lv_iv_ds = lv_char
  IF lv_iv_ds != INTERVAL(00 00:00:00) DAY TO SECOND THEN
		DISPLAY "Error INTERVAL 00 00:00:00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99 23:59:59"
  LET lv_iv_ds = lv_char
  IF lv_iv_ds != INTERVAL(99 23:59:59) DAY TO SECOND THEN
		DISPLAY "Error INTERVAL 99 99:99:99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00 00:00:00.000"
  LET lv_iv_df = lv_char
  IF lv_iv_df != INTERVAL(00 00:00:00.000) DAY TO FRACTION THEN
		DISPLAY "Error INTERVAL 00 00:00:00.000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99 23:59:59.999"
  LET lv_iv_df = lv_char
  IF lv_iv_df != INTERVAL(99 23:59:59.999) DAY TO FRACTION THEN
		DISPLAY "Error INTERVAL 99 23:59:59.999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00"
  LET lv_iv_defhh = lv_char
  IF lv_iv_defhh != INTERVAL(00) HOUR TO HOUR THEN
		DISPLAY "Error INTERVAL 00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99"
  LET lv_iv_defhh = lv_char
  IF lv_iv_defhh != INTERVAL(99) HOUR TO HOUR THEN
		DISPLAY "Error INTERVAL 99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "0"
  LET lv_iv_onehh = lv_char
  IF lv_iv_onehh != INTERVAL(0) HOUR(1) TO HOUR THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

  LET lv_char = "9"
  LET lv_iv_onehh = lv_char
  IF lv_iv_onehh != INTERVAL(9) HOUR(1) TO HOUR THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

  LET lv_char = "000000000"
  LET lv_iv_ninehh = lv_char
  IF lv_iv_ninehh != INTERVAL(000000000) HOUR(9) TO HOUR THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "999999999"
  LET lv_iv_ninehh = lv_char
  IF lv_iv_ninehh != INTERVAL(999999999) HOUR(9) TO HOUR THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00:00"
  LET lv_iv_hm = lv_char
  IF lv_iv_hm != INTERVAL(00:00) HOUR TO MINUTE THEN
		DISPLAY "Error INTERVAL 00:00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99:59"
  LET lv_iv_hm = lv_char
  IF lv_iv_hm != INTERVAL(99:59) HOUR TO MINUTE THEN
		DISPLAY "Error INTERVAL 99:59"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00:00:00"
  LET lv_iv_hs = lv_char
  IF lv_iv_hs != INTERVAL(00:00:00) HOUR TO SECOND THEN
		DISPLAY "Error INTERVAL 00:00:00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99:59:59"
  LET lv_iv_hs = lv_char
  IF lv_iv_hs != INTERVAL(99:59:59) HOUR TO SECOND THEN
		DISPLAY "Error INTERVAL 99:99:99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00:00:00.000"
  LET lv_iv_hf = lv_char
  IF lv_iv_hf != INTERVAL(00:00:00.000) HOUR TO FRACTION THEN
		DISPLAY "Error INTERVAL 00:00:00.000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99:59:59.999"
  LET lv_iv_hf = lv_char
  IF lv_iv_hf != INTERVAL(99:59:59.999) HOUR TO FRACTION THEN
		DISPLAY "Error INTERVAL 99:99:99.999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00"
  LET lv_iv_defmm = lv_char
  IF lv_iv_defmm != INTERVAL(00) MINUTE TO MINUTE THEN
		DISPLAY "Error INTERVAL 00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99"
  LET lv_iv_defmm = lv_char
  IF lv_iv_defmm != INTERVAL(99) MINUTE TO MINUTE THEN
		DISPLAY "Error INTERVAL 99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "0"
  LET lv_iv_onemm = lv_char
  IF lv_iv_onemm != INTERVAL(0) MINUTE(1) TO MINUTE THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

  LET lv_char = "9"
  LET lv_iv_onemm = lv_char
  IF lv_iv_onemm != INTERVAL(9) MINUTE(1) TO MINUTE THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

  LET lv_char = "000000000"
  LET lv_iv_ninemm = lv_char
  IF lv_iv_ninemm != INTERVAL(000000000) MINUTE(9) TO MINUTE THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "999999999"
  LET lv_iv_ninemm = lv_char
  IF lv_iv_ninemm != INTERVAL(999999999) MINUTE(9) TO MINUTE THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00:00"
  LET lv_iv_ms = lv_char
  IF lv_iv_ms != INTERVAL(00:00) MINUTE TO SECOND THEN
		DISPLAY "Error INTERVAL 00:00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99:59"
  LET lv_iv_ms = lv_char
  IF lv_iv_ms != INTERVAL(99:59) MINUTE TO SECOND THEN
		DISPLAY "Error INTERVAL 99:99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00:00.000"
  LET lv_iv_mf = lv_char
  IF lv_iv_mf != INTERVAL(00:00.000) MINUTE TO FRACTION THEN
		DISPLAY "Error INTERVAL 00:00.000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99:59.999"
  LET lv_iv_mf = lv_char
  IF lv_iv_mf != INTERVAL(99:59.999) MINUTE TO FRACTION THEN
		DISPLAY "Error INTERVAL 99:99.999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00"
  LET lv_iv_defss = lv_char
  IF lv_iv_defss != INTERVAL(00) SECOND TO SECOND THEN
		DISPLAY "Error INTERVAL 00"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99"
  LET lv_iv_defss = lv_char
  IF lv_iv_defss != INTERVAL(99) SECOND TO SECOND THEN
		DISPLAY "Error INTERVAL 99"
	  LET exitStatus = 1
	END IF

  LET lv_char = "0"
  LET lv_iv_oness = lv_char
  IF lv_iv_oness != INTERVAL(0) SECOND(1) TO SECOND THEN
		DISPLAY "Error INTERVAL 0"
	  LET exitStatus = 1
	END IF

  LET lv_char = "9"
  LET lv_iv_oness = lv_char
  IF lv_iv_oness != INTERVAL(9) SECOND(1) TO SECOND THEN
		DISPLAY "Error INTERVAL 9"
	  LET exitStatus = 1
	END IF

  LET lv_char = "000000000"
  LET lv_iv_niness = lv_char
  IF lv_iv_niness != INTERVAL(000000000) SECOND(9) TO SECOND THEN
		DISPLAY "Error INTERVAL 000000000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "999999999"
  LET lv_iv_niness = lv_char
  IF lv_iv_niness != INTERVAL(999999999) SECOND(9) TO SECOND THEN
		DISPLAY "Error INTERVAL 999999999"
	  LET exitStatus = 1
	END IF

  LET lv_char = "00.000"
  LET lv_iv_sf = lv_char
  IF lv_iv_sf != INTERVAL(00.000) SECOND TO FRACTION THEN
		DISPLAY "Error INTERVAL 00.000"
	  LET exitStatus = 1
	END IF

  LET lv_char = "99.999"
  LET lv_iv_sf = lv_char
  IF lv_iv_sf != INTERVAL(99.999) SECOND TO FRACTION THEN
		DISPLAY "Error INTERVAL 99.999"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".000"
  LET lv_iv_defff = lv_char
  IF lv_iv_defff != INTERVAL(.000) FRACTION TO FRACTION THEN
		DISPLAY "Error INTERVAL .000"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".999"
  LET lv_iv_defff = lv_char
  IF lv_iv_defff != INTERVAL(.999) FRACTION TO FRACTION THEN
		DISPLAY "Error INTERVAL .999"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".0"
  LET lv_iv_oneff = lv_char
  IF lv_iv_oneff != INTERVAL(.0) FRACTION TO FRACTION(1) THEN
		DISPLAY "Error INTERVAL .0"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".9"
  LET lv_iv_oneff = lv_char
  IF lv_iv_oneff != INTERVAL(.9) FRACTION TO FRACTION(1) THEN
		DISPLAY "Error INTERVAL .9"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".00000"
  LET lv_iv_nineff = lv_char
  IF lv_iv_nineff != INTERVAL(.00000) FRACTION TO FRACTION(5) THEN
		DISPLAY "Error INTERVAL .00000"
	  LET exitStatus = 1
	END IF

  LET lv_char = ".99999"
  LET lv_iv_nineff = lv_char
  IF lv_iv_nineff != INTERVAL(.99999) FRACTION TO FRACTION(5) THEN
		DISPLAY "Error INTERVAL .99999"
	  LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus
END MAIN

