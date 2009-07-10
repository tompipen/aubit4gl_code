database syspgm4gl

main

define lv_path like global.gpath,
       lv_name like global.globname,
       lv_progname like global.progname,
       lv_file char(80),
       lv_buff varchar(255),
       lv_cant int

if num_args() <> 1 then
    display "usage: to_make.sh <program>"
    display "   type to_make.sh -help for a description"
    exit program 1
end if
let lv_progname = arg_val(1)
if lv_progname = "-h" or lv_progname = "-help" or lv_progname = "--help" then
    display "This utility allows you to migrate the module dependency for a "
    display "program stored in the $db database to a .mk suitable for being"
    display "used for make."
    display ""
    display "This information is normally stored by the utility r4gl in the"
    display "'Program' -> 'Modify' -> '4GL' menu option."
    exit program 1
end if
let lv_file=lv_progname clipped, ".mk"
select count(*) into lv_cant from source4gl where progname = lv_progname
if lv_cant = 0 then
    display "Program ", lv_progname clipped, " not found in database"
    exit program 2
end if
start report repo to lv_file
let lv_buff = "all : ", lv_progname clipped, ".4ae"
output to report repo(lv_buff)
output to report repo(" ")
declare c_cursor cursor for
    select distinct nvl(gpath,"."),globname from global
         where progname = lv_progname
              union 
    select distinct nvl(spath,"."),fglsourcename from source4gl
         where progname = lv_progname
        order by 1, 2
foreach c_cursor into lv_path, lv_name
    if lv_path = "." then
        let lv_buff = lv_name clipped, ".ao : ", lv_name clipped, ".4gl"
        output to report repo(lv_buff)
        let lv_buff = ascii 9, "4glc -c ", 
                      lv_name clipped, ".4gl -o ", lv_name clipped, ".ao"
        output to report repo(lv_buff)
    else
        let lv_buff = lv_path clipped, "/", lv_name clipped, ".ao : ",
                      lv_path clipped, "/", lv_name clipped, ".4gl"
        output to report repo(lv_buff)
        let lv_buff = ascii 9, "(cd ", lv_path clipped, "; 4glc -c ", 
                      lv_name clipped, ".4gl -o ", lv_name clipped, ".ao)"
        output to report repo(lv_buff)
    end if
    output to report repo(" ")
end foreach
output to report repo(" ")
let lv_buff = lv_progname clipped, ".4ae: \\"
output to report repo(lv_buff)
foreach c_cursor into lv_path, lv_name
    if lv_path = "." then
        let lv_buff = ascii 9, lv_name clipped, ".ao \\"
    else
        let lv_buff = ascii 9, lv_path clipped, "/", lv_name clipped, ".ao \\"
    end if
    output to report repo(lv_buff)
end foreach
output to report repo(" ")
let lv_buff = ascii 9, "4glc -o $@ $^" 
output to report repo(lv_buff)
finish report repo
display lv_file clipped, " generated"
end main

report repo(lv_buff)
define lv_buff varchar(255)

output
   left margin 0 top margin 0 bottom margin 0 page length 1

format
   on every row
       print lv_buff clipped
end report
