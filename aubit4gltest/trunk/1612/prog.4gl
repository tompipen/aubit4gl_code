{**
 * @file
 * Mantis bug 917
 *
 * In input without defaults, previous content is not erased after typing new
 * text, after input of a smallint field.
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))
DEFINE m_i1, m_i2 INT,
       m_s1, m_s2 SMALLINT,
       m_d1, m_d2 DATE

DEFER INTERRUPT
LET m_d1 = 0  LET m_d2 = 0
OPEN FORM v_pru FROM "inp"
DISPLAY FORM v_pru
INPUT BY NAME m_d1, m_i1, m_s1, m_d2, m_i2, m_s2 WITHOUT DEFAULTS

#Use 	
{! call aclfgl_dump_screen("out") }
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

CLOSE FORM v_pru
end main
