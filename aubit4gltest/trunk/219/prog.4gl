main
define a integer

display "Hello World" at 1,1

#{!set pause mode on !}
for a=1 to 10
	run "ls -ltr /dev > /dev/null"
#code
	#Mike, what's wrong with 4Gl's SLEEP? if you don't like it, please remember 
	#that there is no
	#usleep() on Windows - please use a4gl_usleep()
	#a4gl_usleep (500000);
#endcode
	
end for
#{!set pause mode off !}
display "Hello World" at 1,1
sleep 3

end main
