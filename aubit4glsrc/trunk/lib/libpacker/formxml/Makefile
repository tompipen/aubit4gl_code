libPACKER_FORMXML.so: formxml.c wrapper.c
	$(CC) $(CFLAGS) -Wall -g -shared -fPIC -I../../../incl formxml.c wrapper.c -o libPACKER_FORMXML.so
	cp *.so `aubit-config DEFAULT_PLUGINDIR`
clean:
	rm -f libPACKER_FORMXML.so  `aubit-config DEFAULT_PLUGINDIR`/libPACKER_FORMXML.so
