main
start report r1 to "out"
menu "Select"
	command "Yes"
		output to report r1 ("yes")
		hide option "yes"
		show option "no"
		message "Yes"

	command "No"
		output to report r1 ("no")
		show option "yes"
		hide option "no"
		message "No"

	command "Go"
		output to report r1("go")
		next option "Always"

	command "Always"
		output to report r1 ("always")

	command "Exit"
		output to report r1 ("exit")
		exit menu
end menu
finish report r1
end main



report r1 (a )
define a char(20)
format
on every row
print a
end report
