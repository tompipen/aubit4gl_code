main

define s record
       a int
     end record,
     c int

let c = 1
case c  # line 9
   when 1
      display s.a  # line 11
end case
end main
