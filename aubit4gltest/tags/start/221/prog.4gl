
main
define a array[20] of record
	a char(10),
	b char(10)
end record
define c integer
for c=1 to 20
	let a[c].a="A",c using "&&&&&"
	let a[c].b="B",c using "&&&&&"
end for

open window w1 at 2,2 with form "f"

call set_count(20)
display array a to srec1.* attribute(red)
	on key(control-v) scroll srec1.* down by 1
	on key(control-b) scroll srec1.* up by 1
end display


end main
