

libSQL_mysql.so : mysql.c
	gcc -L$(AUBITDIR)/lib -g -fPIC -shared -o libSQL_mysql.so mysql.c -I../../../incl -I/usr/include/mysql -lmysqlclient -laubit4gl-`../../../bin/aubit-config A4GL_VERSION_STRING`
	cp libSQL_mysql.so $(AUBITDIR)/plugins-`../../../bin/aubit-config A4GL_VERSION_STRING`
clean:
	rm -f libSQL_mysql.so *.o $(AUBITDIR)/plugins-`../../../bin/aubit-config A4GL_VERSION_STRING`/libSQL_mysql.so
