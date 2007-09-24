
libUI_XML.so: xml.c libuilib.a
	gcc -g -Wall -I$(AUBITDIR)/incl -I/home/aubit4gl/cm/proxy/uilib -shared -o libUI_XML.so xml.c -Bstatic  -Luilib -luilib
	cp *.so `aubit-config DEFAULT_PLUGINDIR`

libuilib.a: 
	cd uilib && make -f Makefile.libaubit4gl libuilib.a


update : 
	cp /home/aubitv2/aubit4glsrc/proxy/debug.[ch] .
	cp /home/aubitv2/aubit4glsrc/proxy/pipe.[ch] .
	cp -r /home/aubitv2/aubit4glsrc/proxy/uilib .

clean: 
	rm libUI_XML.so `aubit-config DEFAULT_PLUGINDIR`/libUI_XML.so 
	cd uilib && make clean
	cd uilib/xml && make clean
