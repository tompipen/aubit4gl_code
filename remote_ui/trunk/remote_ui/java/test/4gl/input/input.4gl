
{**
 * 4gl program to test the input command for the aubit4gl User Interface
 *}

main
  define first_field char(30)
  define second_field char(20)
  define var_one char(30)
  define var_two char(20)

  open form form_name FROM "my_form"
  INPUT var_one, var_two FROM first_field, second_field 
  --INPUT BY NAME first_field, second_field WITHOUT DEFAULTS
end main

