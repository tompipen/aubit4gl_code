{**
 * @file
 * Mantis bug 917
 *
 * In input without defaults, previous content is not erased after typing new
 * text, after input of a smallint field.
 * @process TEST_GENERAL
 *}
 
main
DEFINE m_i1, m_i2 INT,
       m_s1, m_s2 SMALLINT,
       m_d1, m_d2 DATE

DEFER INTERRUPT
LET m_d1 = 0  LET m_d2 = 0
OPEN FORM v_pru FROM "inp"
DISPLAY FORM v_pru
INPUT BY NAME m_d1, m_i1, m_s1, m_d2, m_i2, m_s2 WITHOUT DEFAULTS
{! call aclfgl_dump_screen("out") }
CLOSE FORM v_pru
end main
