main
define v varchar(10)
define c char(10)
define r integer

  let v="1"
  let c="1"
  
  display "v=",v
  display "c=",c
  let v=v, "2"          # v should now be "12"
  let c=c clipped, "2"  # c should now be "12        "

  display "v=",v
  display "c=",c
  if v = c then         # should be true if VARCHAR is handled right (OK with i4gl and 4js)
    exit program 0
  else
    exit program 1
  end if
end main
