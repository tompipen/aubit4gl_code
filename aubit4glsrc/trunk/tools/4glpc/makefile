all: 4glpc_new ../../etc/4glpc.iem


../../etc/4glpc.iem: helpfile.hlp
	amkmessage helpfile.hlp ../../etc/4glpc.iem

4glpc_new: 4glpc.4gl times.4gl readsettings.4gl
	4glpc 4glpc.4gl times.4gl readsettings.4gl -o 4glpc_new
