define fld_a record
             a1       char(30),
             a2       char(30),
             a3       char(30),
             a4       char(30)
       end record,

       fld_b record
             b1       char(30),
             b2       char(30)
       end record


main
  open window w01 at 3,12
       with 17 rows, 54 columns
       attribute (normal, form line 1, message line last, prompt line last)
  open form f02 from "m1"
  display form f02

  input fld_a.* without defaults from a_section.*
        before input
                display "Before input" sleep 1
        after input
                display "after input" sleep 1
  end input


  input fld_b.* without defaults from b_section.*
    on key (f1)
      exit input
  end input


  close form f02
  clear window w01
  close window w01
	if fld_b.b1="1" then
		exit program 0
	else
		exit program 1
	end if
end main

