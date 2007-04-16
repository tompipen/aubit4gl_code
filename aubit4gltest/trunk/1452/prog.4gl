database sysmaster

main
define
   q_txt      char(200)

open window win1 at 2, 2 with form "test14" attribute (border)

construct q_txt on systables.tabname, systables.version
   from formonly.tabname, formonly.version

close window win1

display q_txt

end main
