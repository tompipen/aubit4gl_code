main
define w_file char(25)
let w_file = "prinnull.out.expected"
{! let w_file = "prinnull.out" }
start report prinnull_repo to w_file
output to report prinnull_repo()
finish report prinnull_repo
end main

report prinnull_repo()
define w_c1, w_c2, w_c3 char(10),
       w_v1, w_v2, w_v3 varchar(10),
       w_i1, w_i2, w_i3 int
output
top margin 0 bottom margin 0 page length 1 left margin 0
format
    on every row
        let w_c1 = "c1"
        let w_c2 = "  "
        let w_c3 = NULL
        print "c|", w_c1, "|", w_c2, "|", w_c3, "|", w_c1, "|"
        print "cs|", w_c1[1,4], "|", w_c2[1,4], "|", w_c3[1,4], " |", w_c1[1,4], "|"
        let w_v1 = "v1"
        let w_v2 = "  "
        let w_v3 = NULL
        print "v|", w_v1, "|", w_v2, "|", w_v3, "|", w_v1, "|"
        let w_i1 = 1
        let w_i2 = 0
        let w_i3 = NULL
        print "i|", w_i1, "|", w_i2, "|", w_i3, "|", w_i1, 
"|"
end report

