
{**
 * 4gl program to test the input command for the aubit4gl User Interface
 *}

main
  define record_array ARRAY[20] OF RECORD
    var_one CHAR(20),
    var_two CHAR(30)
  END RECORD

  open form form_name FROM "my_form"
  DISPLAY ARRAY record_array TO screen_array.*
end main

