
HLP_FILES=help_aubit.iem help_ecpg.iem

all: ${HLP_FILES}
	@echo "Help files compiled."

%.iem: %.hlp
	../bin/amkmessage $< $@

clean:
	rm -f ${HLP_FILES} *.bak

