main

if "TEST" like "TES%" then
	display "True"
else
	display "False"
end if

if "TEST" MATCHES "TES*" then
	display "True"
else
	display "False"
end if


if "TEST" like "tES%" then
	display "True"
else
	display "False"
end if

if "TEST" MATCHES "tES*" then
	display "True"
else
	display "False"
end if

end main

