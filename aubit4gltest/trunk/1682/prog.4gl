{**
 * @file
 * unlad varchar, content is not truncated to new size
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE w_file CHAR(50)

create temp table testunl (a int, b varchar(100))
insert into testunl values (1,"aaa")
insert into testunl values (2,"bbbbbb")
insert into testunl values (3,"cccccccccc")
insert into testunl values (4,"dddddddd")
insert into testunl values (5,"eeee")
insert into testunl values (6,"f")
unload to "out" select * from testunl order by a
END MAIN
