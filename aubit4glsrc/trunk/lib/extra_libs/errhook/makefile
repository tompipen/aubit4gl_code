
ROOT    =../../..
4GLC	=${ROOT}/bin/4glc

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

OUTPUT=$(PLUGINDIR)/liberrhook_sample${SO_EXT}
$(OUTPUT): sample.4gl
	4glc --as-dll -o $(OUTPUT) sample.4gl

clean: 
	rm *.o $(OUTPUT)
	
