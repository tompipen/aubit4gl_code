
database test1
main
define rec1 array[20] of record  a integer end record
define rec2 array[20,20] of record  a integer end record
define c integer
define d1 integer
define d2 integer

let rec1[c].*=rec2[d1,d2].*

end main

