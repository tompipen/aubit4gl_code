FGLC=4glpc -V1 -g --make-compile 

runforms: globals.4gl dbi.4gl runform.4gl   list.4gl
	$(FGLC) $^ -o $@

irunforms: globals.4gl dbi.4gl runform.4gl  list_arr.4gl 
	$(FGLC) $^ -o $@

clean:
	rm *.ao *.c *.glb *.h runforms *.cpc *.err *.ec *.sc
