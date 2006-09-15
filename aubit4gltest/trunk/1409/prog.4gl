main
 start report r1 to "out"
 
 menu " Options"
    before menu
        hide option "Modify"
        show option "Find", "Add" ,"Merge", "Exit"
 
    command "Find" " Find a record "
	output to report r1 ("find");
	
    command "Add" " Add a record "
	output to report r1 ("add");
    command "Modify" " Modify a record "
	output to report r1 ("modify");
    command "Merge" " Merge record"
	output to report r1 ("merge");
    command "Display" " Display detail "
	output to report r1 ("display");
    command "Exit" " Exit menu"
       exit menu
 end menu
 finish report r1
end main


report r1(lv_a)
define lv_a char(10)
output
top margin 0
bottom margin 0
left margin 0
format
on every row
print lv_a
end report
