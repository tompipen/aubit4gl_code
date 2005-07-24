-- @(#)File:            $RCSfile: locale.sql,v $
-- @(#)Version:         $Revision: 1.2 $
-- @(#)Last changed:    $Date: 2002-06-14 09:23:16 $
-- @(#)Purpose:         SQL table definition for LOCALE table (Informix)
-- @(#)Author:          J Leffler

-- Designed after the ANSI C header <locale.h>
CREATE TABLE Locale
(
    Locale_name         CHAR(18) NOT NULL,  -- Name for format specification
    Currency_symbol     CHAR(4),            -- Local currency symbol
    Int_curr_symbol     CHAR(4),            -- International currency symbol
    Mon_decimal_point   CHAR(1),            -- Monetary decimal point
    Mon_grouping        CHAR(10),           -- Monetary group sizes
    Mon_thousands_sep   CHAR(1),            -- Monetary group separators
    Negative_sign       CHAR(4),            -- Monetary negative sign
    Positive_sign       CHAR(4),            -- Monetary positive sign
    Frac_digits         CHAR(1),            -- Monetary fractional digits
    Int_frac_digits     CHAR(1),            -- International fractional digits
    N_cs_precedes       CHAR(1),            -- CS precedes/follows amount (neg)
    N_sep_by_space      CHAR(1),            -- CS separated by space (neg)
    N_sign_posn         CHAR(1),            -- Sign position (neg)
    P_cs_precedes       CHAR(1),            -- CS precedes/follows amount (pos)
    P_sep_by_space      CHAR(1),            -- CS separated by space (pos)
    P_sign_posn         CHAR(1),            -- Sign position (pos)
    Decimal_point       CHAR(1),            -- Numeric decimal point
    Grouping            CHAR(10),           -- Numeric grouping
    Thousands_sep       CHAR(1)             -- Numeric grouping separator
);

{
    PRIMARY KEY Locale(Locale_name)
    DOMAIN Mon_grouping   IS REGEXPR("[0-9.]*")
    DOMAIN Frac_digits    IS REGEXPR("[0-9]")
    DOMAIN N_cs_precedes  IS REGEXPR("[0-1]")
    DOMAIN N_sep_by_space IS REGEXPR("[0-1]")
    DOMAIN N_sign_posn    IS REGEXPR("[0-4]")
    DOMAIN P_cs_precedes  IS REGEXPR("[0-1]")
    DOMAIN P_sep_by_space IS REGEXPR("[0-1]")
    DOMAIN P_sign_posn    IS REGEXPR("[0-4]")
    DOMAIN Grouping       IS REGEXPR("[0-9.]*")
}

CREATE UNIQUE INDEX Pk_locale ON Locale(Locale_name);

-- Semantics:
--
-- Locale_name identifies the particular locale.
--
-- Numeric formatting is controlled by:
-- Decimal_point:       the decimal point character.
-- Thousands_sep:       the character used to separate groups of digits before
--                      the decimal point.
-- Grouping:            string whose elements determine the size of each group
--                      of digits before the decimal point.  (See GROUPING).
--
-- Monetary formatting is controlled by:
-- Int_curr_symbol:     the international currency symbol.  The first 3
--                      characters contain the alphabetic international
--                      currency symbol in accordance with those specified in
--                      ISO 4217:1987.  The fourth character is the character
--                      used to separate the international currency symbol from
--                      the monetary quantity.
-- Currency_symbol:     the local currency symbol.
-- Mon_decimal_point:   the decimal point character.
-- Mon_thousands_sep:   the character used to separate groups of digits before
--                       the decimal point.
-- Mon_grouping:        string whose elements determine the size of each group
--                      of digits before the decimal point.  (See GROUPING).
-- Positive_sign:       the string used to indicate a non-negative formatted
--                      monetary quantity.
-- Negative_sign:       the string used to indicate a negative formatted
--                      monetary quantity.
-- Int_frac_digits:     number of fractional digits (after decimal point) in
--                      an internationally formatted monetary quantity.
-- Frac_digits:         number of fractional digits (after decimal point) in
--                      a formatted monetary quantity.
-- N_cs_precedes:       1 => currency symbol (CS) precedes negative value
--                      0 => currency symbol (CS) succeeds negative value
-- N_sep_by_space:      1 => space separates CS and negative value
--                      0 => no space separates CS and negative value
-- N_sign_posn:         Position of negative sign (see SIGN POSITION).
-- P_cs_precedes:       1 => currency symbol (CS) precedes non-negative value
--                      0 => currency symbol (CS) succeeds non-negative value
-- P_sep_by_space:      1 => space separates CS and non-negative value
--                      0 => no space separates CS and non-negative value
-- P_sign_posn:         Position of positive sign (see SIGN POSITION).
--
-- SIGN POSITION:
-- 0 => parentheses surround quantity and CS
-- 1 => sign string precedes quantity and CS
-- 2 => sign string succeeds quantity and CS
-- 3 => sign string immediately precedes CS
-- 4 => sign string immediately succeeds CS
--
-- GROUPING:
-- .	 =>	No further grouping is to be performed.
-- 0	 =>	The previous element is to be used repeatedly for the remainder of
--			the digits.
-- [1-9] => The number of digits which comprise the current group.  The next
--			character is examined to determine the size of the the next group
--			of digits before the current group.
-- Which, being interpreted, means that the first character specifies the
-- group of digits closest to the decimal point, the second character specifies
-- next closest group, and so on.
-- A standard value for this field is "30", which means group in thousands, and
-- millions, and thousands of millions, and millions of millions, and ...
