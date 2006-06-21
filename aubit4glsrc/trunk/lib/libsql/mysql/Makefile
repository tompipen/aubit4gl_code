libSQL_mysql.so : mysql.c
	gcc -g -fPIC -shared -o libSQL_mysql.so mysql.c -I../../../incl -I/usr/include/mysql -lmysqlclient -laubit4gl
	cp libSQL_mysql.so ../..
