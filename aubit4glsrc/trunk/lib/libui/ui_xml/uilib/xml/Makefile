# Programs.
HASFLEXML:=$(shell type flexml 2> /dev/null)

FLEXML = flexml -v  -s ./skel 
FLEXMLOPTS=-v  -s ./skel
FLEX=flex -Cfer


%.dtd: skel
#
#     # Generate linkable XML processor with header for application.
%.l %.h: %.dtd
	$(FLEXML) $<

# Generate C source from flex scanner.
%.c:    %.l
	$(FLEX) -Pxml_yy -B -o"$@" "$<"

# Generate XML application C source to link with processor.
# Note: The dependency must be of the form "appl.c: appl.act proc.dtd".
%.c:    %.act
	$(FLEXML) $(FLEXMLOPTS) -D -a $^ 

# Direct generation of stand-alone XML processor+application.
# Note: The dependency must be of the form "appl.l: appl.act proc.dtd".
%.l:    %.act
	$(FLEXML) $(FLEXMLOPTS) -A -a $^ 
	


all: parser 

triggers.l: triggers_act.act triggers.dtd
triggers.c: triggers_act.act triggers.dtd
triggers_act.c: triggers_act.act triggers.dtd

parser : refresh.pregenerated
	
	#gcc triggers_act.c  triggers.c attr.c -o x1

refresh.pregenerated:  triggers_act.c  triggers.c attr.c
	cp triggers.c triggers_act.c triggers.h  pregenerated

clean : 
	rm triggers.l triggers.c triggers_act.c triggers.h
