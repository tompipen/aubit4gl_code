

../../../libLOGREP_CSV.so : layout_csv.c ../common/csv_io.c
	cc -Wall -rdynamic -shared -g $^ -o $@ -I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl `pkg-config --libs --cflags gtk+-2.0` -laubit4gl

