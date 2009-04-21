{**
 * @file
 * Comparing against null values OR another value
 * @process TEST_GENERAL
 *}
 
define m_fech date
main
define w_a date
let w_a = NULL
let m_fech = mdy(4,21,2009)
display "a=", w_a, "<<<"
if w_a is null then display "a is nulL" end if
if w_a = m_fech then display "a = m_fech " end if
if w_a is null or w_a = m_fech then display "a is nulL or = m_fech" end if
let w_a = m_fech
display "a=", w_a, "<<<"
if w_a is null then display "a is nulL" end if
if w_a = m_fech then display "a = m_fech " end if
if w_a is null or w_a = m_fech then display "a is nulL or = m_fech" end if
end main
