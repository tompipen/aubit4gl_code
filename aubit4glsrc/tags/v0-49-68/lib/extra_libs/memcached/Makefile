all: memcache.so test1

memcache.so: memcache.c mem.4gl
	4glpc -g --as-dll   -I. mem.4gl memcache.c -o memcache.so

test1: test1.4gl
	4glpc -g test1.4gl -o test1

