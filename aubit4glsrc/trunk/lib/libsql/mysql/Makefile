

libSQL_mysql.so : mysql.c
	gcc -L$(AUBITDIR)/lib -g -fPIC -shared -o libSQL_mysql.so mysql.c -I../../../incl -I/usr/include/mysql -lmysqlclient -laubit4gl-`aubit-config A4GL_VERSION_STRING`
	cp libSQL_mysql.so $(AUBITDIR)/plugins-`aubit-config A4GL_VERSION_STRING`
clean:
	rm -f libSQL_mysql.so *.o $(AUBITDIR)/plugins-`aubit-config A4GL_VERSION_STRING`
