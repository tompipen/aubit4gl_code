database test1

define m_t1, m_t2 text

main

define w_t1, w_t2 text,
       w_op int
create temp table twotext (t1 text, t2 text)
locate w_t1 in file "twotext1.txt"
locate w_t2 in file "twotext2.txt"
insert into twotext values (w_t1, w_t2)

locate m_t1 in memory
locate m_t2 in memory
display "one select at the time .... 1"
display "both select at once ....... 2"
display "Run together .............. 3"
#prompt "option ? " for w_op
let w_op=2
if w_op = 1 or w_op = 3 then
    display "one select at the time"
    select t1 into m_t1 from twotext
    display "m_t1=", m_t1
    select t2 into m_t2 from twotext
    display "m_t2=", m_t2
end if
if w_op = 2 or w_op = 3 then
    display "both selects at once"
    select t1, t2 into m_t2, m_t1 from twotext
    display "m_t1 (sw t2)=", m_t1, ",m_t2 (sw t1)=", m_t2,":"
end if
end main
