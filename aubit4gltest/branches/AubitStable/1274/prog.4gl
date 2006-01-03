database test1

main
define dt_0_0 DATETIME YEAR TO YEAR
define dt_0_1 DATETIME YEAR TO MONTH
define dt_0_2 DATETIME YEAR TO DAY
define dt_0_3 DATETIME YEAR TO HOUR
define dt_0_4 DATETIME YEAR TO MINUTE
define dt_0_5 DATETIME YEAR TO SECOND
define dt_0_6 datetime year to fraction(1)
define dt_0_7 datetime year to fraction(2)
define dt_0_8 datetime year to fraction(3)
define dt_0_9 datetime year to fraction(4)
define dt_0_10 datetime year to fraction(5)
define dt_0_11 datetime year to fraction
define dt_1_1 DATETIME MONTH TO MONTH
define dt_1_2 DATETIME MONTH TO DAY
define dt_1_3 DATETIME MONTH TO HOUR
define dt_1_4 DATETIME MONTH TO MINUTE
define dt_1_5 DATETIME MONTH TO SECOND
define dt_2_2 DATETIME DAY TO DAY
define dt_2_3 DATETIME DAY TO HOUR
define dt_2_4 DATETIME DAY TO MINUTE
define dt_2_5 DATETIME DAY TO SECOND
define dt_3_3 DATETIME HOUR TO HOUR
define dt_3_4 DATETIME HOUR TO MINUTE
define dt_3_5 DATETIME HOUR TO SECOND
define dt_4_4 DATETIME MINUTE TO MINUTE
define dt_4_5 DATETIME MINUTE TO SECOND
define dt_5_5 DATETIME SECOND TO SECOND
define dt_5_6 datetime second to fraction(1)
define dt_5_7 datetime second to fraction(2)
define dt_5_8 datetime second to fraction(3)
define dt_5_9 datetime second to fraction(4)
define dt_5_10 datetime second to fraction(5)
define dt_5_11 datetime second to fraction

create temp table t_dt (
	dt_0_0 DATETIME YEAR TO YEAR,
	dt_0_1 DATETIME YEAR TO MONTH,
	dt_0_2 DATETIME YEAR TO DAY,
	dt_0_3 DATETIME YEAR TO HOUR,
	dt_0_4 DATETIME YEAR TO MINUTE,
	dt_0_5 DATETIME YEAR TO SECOND,
	dt_0_6 datetime year to fraction(1),
	dt_0_7 datetime year to fraction(2),
	dt_0_8 datetime year to fraction(3),
	dt_0_9 datetime year to fraction(4),
	dt_0_10 datetime year to fraction(5),
	dt_0_11 datetime year to fraction,
	dt_1_1 DATETIME MONTH TO MONTH,
	dt_1_2 DATETIME MONTH TO DAY,
	dt_1_3 DATETIME MONTH TO HOUR,
	dt_1_4 DATETIME MONTH TO MINUTE,
	dt_1_5 DATETIME MONTH TO SECOND,
	dt_2_2 DATETIME DAY TO DAY,
	dt_2_3 DATETIME DAY TO HOUR,
	dt_2_4 DATETIME DAY TO MINUTE,
	dt_2_5 DATETIME DAY TO SECOND,
	dt_3_3 DATETIME HOUR TO HOUR,
	dt_3_4 DATETIME HOUR TO MINUTE,
	dt_3_5 DATETIME HOUR TO SECOND,
	dt_4_4 DATETIME MINUTE TO MINUTE,
	dt_4_5 DATETIME MINUTE TO SECOND,
	dt_5_5 DATETIME SECOND TO SECOND,
	dt_5_6 datetime second to fraction(1),
	dt_5_7 datetime second to fraction(2),
	dt_5_8 datetime second to fraction(3),
	dt_5_9 datetime second to fraction(4),
	dt_5_10 datetime second to fraction(5),
	dt_5_11 datetime second to fraction
)


insert into t_dt values (
	current YEAR TO YEAR,
	current YEAR TO MONTH,
	current YEAR TO DAY,
	current YEAR TO HOUR,
	current YEAR TO MINUTE,
	current YEAR TO SECOND,
	current year to fraction(1),
	current year to fraction(2),
	current year to fraction(3),
	current year to fraction(4),
	current year to fraction(5),
	current year to fraction,
	current MONTH TO MONTH,
	current MONTH TO DAY,
	current MONTH TO HOUR,
	current MONTH TO MINUTE,
	current MONTH TO SECOND,
	current DAY TO DAY,
	current DAY TO HOUR,
	current DAY TO MINUTE,
	current DAY TO SECOND,
	current HOUR TO HOUR,
	current HOUR TO MINUTE,
	current HOUR TO SECOND,
	current MINUTE TO MINUTE,
	current MINUTE TO SECOND,
	current SECOND TO SECOND,
	current second to fraction(1),
	current second to fraction(2),
	current second to fraction(3),
	current second to fraction(4),
	current second to fraction(5),
	current second to fraction
)




select * 
into
dt_0_0,
dt_0_1,
dt_0_2,
dt_0_3,
dt_0_4,
dt_0_5,
dt_0_6,
dt_0_7,
dt_0_8,
dt_0_9,
dt_0_10,
dt_0_11,
dt_1_1,
dt_1_2,
dt_1_3,
dt_1_4,
dt_1_5,
dt_2_2,
dt_2_3,
dt_2_4,
dt_2_5,
dt_3_3,
dt_3_4,
dt_3_5,
dt_4_4,
dt_4_5,
dt_5_5,
dt_5_6,
dt_5_7,
dt_5_8,
dt_5_9,
dt_5_10,
dt_5_11
from t_dt 


display dt_0_0
display dt_0_1
display dt_0_2
display dt_0_3
display dt_0_4
display dt_0_5
display dt_0_6
display dt_0_7
display dt_0_8
display dt_0_9
display dt_0_10
display dt_0_11
display dt_1_1
display dt_1_2
display dt_1_3
display dt_1_4
display dt_1_5
display dt_2_2
display dt_2_3
display dt_2_4
display dt_2_5
display dt_3_3
display dt_3_4
display dt_3_5
display dt_4_4
display dt_4_5
display dt_5_5
display dt_5_6
display dt_5_7
display dt_5_8
display dt_5_9
display dt_5_10
display dt_5_11
end main
