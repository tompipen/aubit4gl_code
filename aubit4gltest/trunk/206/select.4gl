database test1
main
 define
 p_co_name char(20)

create temp table stxcntrc (
	co_name char(20)
)

# Don't insert anything...

 select co_name into p_co_name from stxcntrc
 display "=",p_co_name

 #sleep 10
end main



