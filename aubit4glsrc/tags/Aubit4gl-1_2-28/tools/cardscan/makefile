all: test_mag something.afr.dat test_mag_so magreader.so

test_mag: testmag.4gl mag.4gl  a4gl_fcard.afr.c a4gl_fcard2.afr.c
	4glpc testmag.4gl mag.4gl a4gl_fcard.afr.c a4gl_fcard2.afr.c -o test_mag

magreader.so:  mag.4gl  a4gl_fcard.afr.c a4gl_fcard2.afr.c
	4glpc -as-dll -o $@ mag.4gl a4gl_fcard.afr.c a4gl_fcard2.afr.c

test_mag_so: testmag_so.4gl 
	4glpc testmag_so.4gl -o test_mag_so

a4gl_fcard.afr.c: a4gl_fcard.per
	fcompile -c a4gl_fcard.per
a4gl_fcard2.afr.c: a4gl_fcard2.per
	fcompile -c a4gl_fcard2.per

%.afr.dat: %.per
	fcompile $^


clean:
	rm a4gl_fcard.afr.* a4gl_fcard2.afr.* mag.ao mag.c something.afr.dat test_mag testmag.ao testmag.c magreader.so test_mag_so testmag_so.c
