database test1
main
    create temp table atable (acol char(20))
	insert into atable values("arow")

    unload to "out"
        select * from atable
      union all
        select * from atable
end main
