CFLAGS=-g `pkg-config libglade-2.0 --cflags`
../../libUI_GLADE.so: glade.o dialog.o obj.o list.o
	gcc -g -shared glade.o dialog.o obj.o list.o -o ../../libUI_GLADE.so  `pkg-config libglade-2.0 --libs --cflags`
