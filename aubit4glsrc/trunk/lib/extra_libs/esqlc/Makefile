all: libesqlhelper_funcs.so


helper_funcs.o: helper_funcs.ec
	esql -g -c -o helper_funcs.o helper_funcs.ec -I../../../incl 

libesqlhelper_funcs.so: helper_funcs.o
	esql -g --shared helper_funcs.o -o libesqlhelper_funcs.so -L../../../lib -laubit4gl 
	cp *.so ../..
