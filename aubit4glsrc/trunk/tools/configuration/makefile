all: configurator

config.4gl: descriptions mk_config config.4gl.head
	sh mk_config > config.4gl

config.o: config.4gl
	4glpc config.4gl -c -o config.o

rest.o: rest.4gl
	4glpc -c rest.4gl -o rest.o 

configurator: config.o rest.o
	4glpc config.o rest.o -o configurator

	
