*
* API specs for FORM library interface - used by dlmagic script
* to create API_form.c (try "make API_form.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY FORM
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_FORMTYPE
*
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*



//
// ------------ Function calls from lib/libform/form_xdr/readforms.c
//

//char * find_attribute (struct s_form_dets *f, int field_no)
*find_attribute s_form_dets *f,int field_no -> char*

//static char * ret_string (char *str)

//struct s_form_dets * read_form (char *fname, char *formname)
read_form char* fname,char* formname -> void*

//void set_default_form (struct s_form_attr *form)
*set_default_form struct s_form_attr *form -> void

//read_attributes (struct s_form_dets *f)

//comments (struct struct_scr_field * fprop)

//dump_srec (struct s_form_dets * fd)

//struct struct_screen_record * get_srec (char *name)

//int check_field_for_include (char *s, char *inc, int dtype)

//include_range_check (char *ss, char *ptr, int dtype)

//has_bool_attribute (struct struct_scr_field *f, int bool)
has_bool_attribute void* f,int bool -> void

//set_bool_attribute (struct struct_scr_field * f, int bool, int value)

//do_translate_form(struct_form *the_form)

//int chk_iskey (char *keys)


//
// ----------- from formwrite2.c
//



/**
 * Alocate memory to a new attribute structure and initializes the values
 * of each properties
 */
//static new_attribute(void)

/**
 * Initialize the default values of the last element from the field(s)
 * array of the current form (the one that is being compiled).
 *
 * It leaves the global field description pointer pointing to the new array
 * element.
 */
//void init_fld (void)
init_fld -> void

/**
 * Check if the alias allready exists in the tables array
 *
 * @param s Alias name
 * @return The table found name or the alias name
 */
//static char *chk_alias (char *s)

/**
 * Find a tag name from the fields array of the form
 *
 * @param s field tag name
 * @return -1 if not found, the index in the array otherwise
 */
//int find_field (char *s)
find_field char* s -> int

/**
 * Display a compilation error and exists
 *
 * @param s Formated string message to pass to printf
 * @param a First parameter of formated string
 * @param b Second parameter of formated string
 */
//static error_with (char *s, char *a, char *b)

/**
 * Alocate memory to a struct of structs_creen_record type and start to
 * insert as new record of the record array.
 */
//static new_records(void)

/**
 * Add / Initialize a new screen array
 */
//void add_srec(void)
add_srec -> void

/**
 *  Assigns a new name and size to de current screen array
 *
 *  @param s The screen array name
 *  @param a The array size
 */
//void set_dim_srec (char *s, int a)
set_dim_srec char* s,int a -> void

/**
 * Lower all the caracters of a string
 *
 * @param s The string to be lowered
 */
//void make_downshift(char *s)
make_downshift char* s -> void

/**
 *
 * @param tab The table name
 * @param a The position in the attributes array where to add
 */
//static add_srec_direct (char *tab, int a)

/**
 * Makes some validations and assigns default values on a new field description
 * found at attributes section.
 *
 * @param s Field tag name ( the one that is before '=' and in the scren
 * section )
 * @param f The field attributes filled in a struct (struct_scr_field)
 */
//void set_field (char *s, struct struct_scr_field *f)
set_field char* s,void* f -> void

/**
 * It takes the first and last character from a string (normaly "") and
 * convert the tabs to spaces.
 *
 *  @param s The origin string
 *  @return A pointer to a static transformated string
 */
//char *char_val (char *s)

/**
 * Allocate memory space to a metric structure and insert it in the
 * metrics array.
 *
 * @todo Define what is a metric
 *
 * @param x The column where the screen element found
 * @param y The line where the screen element was found
 * @param wid The width of the screen element in columns
 * @param scr The screen name
 * @param delim
 * @param label The label (if the element is a field) of the element
 * @return The index of metrics array
 */
//static int new_metric(int x, int y, int wid, int scr, int delim,char *label)


/**
 * Alocate space to a new field (struct_form_field) and insert it in the fields
 * array
 *
 * @return The fields array index
 */
//static add_new_field(void)

/**
 * Alocate space for a new form metric and insert it in the position
 * wanted or at the end of the array
 *
 * @todo Define what is a form metric
 * @param cnt The position of the array where to insert the form metric
 * @return The new index of form meetric array
 */
//static int new_form_metric(int cnt)

/**
 * Add(s) a new field found inside the screen section to the fields array
 * It validates if the label allready existes (there can be no duplicated
 * labels).
 *
 * Some screen text element is also added
 *
 * @param s
 * @param x Column number where the field starts
 * @param y Line number from starting from the beggining of screen scetion
 * @param wid Width of the screen form block
 * @param scr Screen sequential id
 * @param delim
 * @param label The screen label
 */
//add_field(char *s, int x, int y, int wid, int scr, int delim,char *label)
add_field char* s,int x,int y,int wid,int scr,int delim,char* label -> void

/**
 * Adds a new table to the form tables array
 *
 * @param s table name
 * @param a table alias
 */
//void add_table (char *s, char *a)
add_table char* s,char* a -> void

/**
 * Find the attribute for table and column name
 *
 * @param ptr An array pointer where the field will be putted
 * @param tab The table name
 * @param colname The column name
 * @return The index of the attribute in the array
 */
//static int find_attribs (int **ptr, char *tab, char *colname)

/**
 * Process the through of fields in the screen record
 * Expands the field attributes of a through in the screen record
 */
//static proc_thru (void)

/**
 * Adds a new attribute / field, field pattern to the current screen record
 *
 * @param tab The table name or FORMONLY
 * @param col The column name or '*'
 * @param thru
 */
//void add_srec_attribute (char *tab, char *col, char *thru)
add_srec_attribute char* tab,char* col,char* thru -> void

/**
 * Find the field in the attriutes array by field number
 *
 * @param fno The field number wanted
 * @return The index of the array of field number wanted
 */
//static int find_field_attr(int fno)

/**
 * Find the fields that are wordwrap for big strings input.
 *
 * It seems not used
 * @todo Understand if its or not used and if so remove it
 */
//static void chk_for_wordwrap(void)

/**
 * Write the frm file with the information parsed from the .per to memory
 */
//void write_form (void)
write_form -> void


/**
 * Gets the datatype of the column from the database
 *
 * @col The column name
 * @tab The table name
 */
//int getdatatype(char *col,char *tab)
getdatatype char* col,char* tab -> int

/**
 * Intialize the memory needed to compile a 4gl screen form in order to
 * the lexical and sintatic parser to load the information found
 */
//void init_form(void)
init_form -> void

/**
 * It seems that its not used
 * @toto Confirm if its used and if not remove it
 */
//static void new_field_bool_attribute(void)

/**
 * It seems that its not used
 *
 * @todo Confirm if its used and if not remove it
 */
//static new_field_str_attribute(void)

/**
 * If necessary locate memory to field attributes and insert it to the
 * attribute array of the screen field pointer.
 *
 * Adds only one of the screen attributes.
 *
 * @param f A screen field structure pointer
 * @param type The attribute type
 * @param str The attribute to add
 */
//void add_str_attr(struct struct_scr_field *f,int type,char *str)
add_str_attr void* f,int type,char* str -> void

/**
 * Try to find the attribute and if not alocate memory and insert it in
 * the attributes array.
 *
 * @param f Pointer to field description
 * @param type The type of the boolean attribute:
 *
 */
//void add_bool_attr(struct struct_scr_field *f,int type)
add_bool_attr void* f,int type -> void

//void translate_form()



// ------------- for decompile.c

//int isolated_xdr_struct_form( XDR xdrp, struct struct_form the_form)
isolated_xdr_struct_form void* xdrp,void* the_form -> int



// ----------------------------- EOF ----------------------------




