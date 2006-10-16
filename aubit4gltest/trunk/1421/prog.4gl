database test1
 
 main
 define w record
      s smallint,
      i1, i2 int
     end record,
     i int
 
 start report repoint_repo to "repoint.out"
 for i = 1 to 5
    let w.s = i
    let w.i1 = i * 10
    let w.i2 = i * 100
    output to report repoint_repo(w.*)
 end for
 finish report repoint_repo
 end main
 
 report repoint_repo(s)
 define s record
      s smallint,
      i1, i2 int
     end record
 
 output
 left margin 0 bottom margin 0 top margin 0 page length 1
 
 order by s.s, s.i1, s.i2
 
 format
    on every row
        print s.s, s.i1, s.i2
 end report
