{**
 * @file
 * begin/commit work inside a report using temporary table due to 'order by'
 * the report loop is stopped before processing all the rows
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_i, w_sum, w_count int
create temp table tempwork (i int)
start report repowork_repo to "out"
begin work
for w_i = 1 to 100
    output to report repowork_repo(w_i)
end for
finish report repowork_repo
commit work
select sum(i), count(*) into w_sum, w_count from tempwork
display "sum=", w_sum, ", count=", w_count
end main

report repowork_repo(s_i)
define s_i, i int
output left margin 0 bottom margin 0 top margin 0 page length 1
# need and order by to fail
#   with no order or with order EXTERNAL the program runs ok
order by s_i
format   
   on every row 
       let i = i + 1
       if i > 10 then
           commit work
           begin work
           let i = 0
       end if
       insert into tempwork values (s_i)
end report
