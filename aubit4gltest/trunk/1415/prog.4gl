database test1
main
# This way compiles OK
select * from systables where tabname[1,1] = "s" and tabid=1

# This way fails
select * from systables where @tabname[1] = "s" and tabid=1

select * from systables where @tabname[1,1] = "s" and tabid=1

end main

