database test1
main
define a_date date
define a_dt datetime year to day
create temp table aa (aa integer)

insert into aa values(1)

select '' into a_date from aa
display a_date

select '01/01/2003' into a_date from aa
display a_date

select '' into a_dt from aa
display a_dt

select '2003-01-01' into a_dt from aa
display a_dt


end main
