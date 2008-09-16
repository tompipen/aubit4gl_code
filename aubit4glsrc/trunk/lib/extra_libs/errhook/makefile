PLUGINDIR=`aubit-config DEFAULT_PLUGINDIR`
OUTPUT=$(PLUGINDIR)/liberrhook_sample.so
$(OUTPUT): sample.4gl
	4glc --as-dll -o $(OUTPUT) sample.4gl
