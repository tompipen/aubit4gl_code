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
* Add prefix for created API punctions:
*API_PREFIX FORMAPI_
* Add prefix for existing library functions:
*LIB_PREFIX FORMLIB_
* Name of the header file to be referenced with #include
*HEADER_FILE API_form.h


*========================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*

/*  ------ Function calls from lib/libform/form_xdr/readforms.c ------ */

/* this should be probably removed, together with function in readforms.c: */
/* dump_srec (struct s_form_dets * fd) */
dump_srec void* fd -> void

/* void comments (struct struct_scr_field *fprop); */
comments void* fprop -> void

/* void set_default_form (struct s_form_attr *form) */
set_default_form void* form -> void

/* struct s_form_dets * read_form (char *fname, char *formname) */
read_form char* fname,char* formname -> void*

/* int has_bool_attribute (struct struct_scr_field *f, int bool) */
has_bool_attribute void* f,int boolval -> int

/* int check_field_for_include (char *s, char *inc, int dtype) */
check_field_for_include char* s,char* inc,int dtype -> int

/*  -------- Function calls from formwrite2.c ------------------------ */

/**
 * Initialize the default values of the last element from the field(s)
 * array of the current form (the one that is being compiled).
 *
 * It leaves the global field description pointer pointing to the new array
 * element.
 */
/* void init_fld (void) */
init_fld -> void

/**
 * Find a tag name from the fields array of the form
 *
 * @param s field tag name
 * @return -1 if not found, the index in the array otherwise
 */
/* int find_field (char *s) */
find_field char* s -> int

/**
 * Add / Initialize a new screen array
 */
/* void add_srec(void) */
add_srec -> void

/**
 *  Assigns a new name and size to de current screen array
 *
 *  @param s The screen array name
 *  @param a The array size
 */
/* void set_dim_srec (char *s, int a) */
set_dim_srec char* s,int a -> void

/**
 * Lower all the caracters of a string
 *
 * @param s The string to be lowered
 */
/* void make_downshift(char *s) */
make_downshift char* s -> void

/**
 * Makes some validations and assigns default values on a new field description
 * found at attributes section.
 *
 * @param s Field tag name ( the one that is before '=' and in the scren
 * section )
 * @param f The field attributes filled in a struct (struct_scr_field)
 */
/* void set_field (char *s, struct struct_scr_field *f) */
set_field char* s,void* f -> void

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
/* int add_field(char *s, int x, int y, int wid, int scr, int delim,char *label) */
add_field char* s,int x,int y,int wid,int scr,int delim,char* label -> int

/**
 * Adds a new table to the form tables array
 *
 * @param s table name
 * @param a table alias
 */
/* void add_table (char *s, char *a) */
add_table char* s,char* a -> void

/**
 * Adds a new attribute / field, field pattern to the current screen record
 *
 * @param tab The table name or FORMONLY
 * @param col The column name or '*'
 * @param thru
 */
/* void add_srec_attribute (char *tab, char *col, char *thru) */
add_srec_attribute char* tab,char* col,char* thru -> void

/**
 * Write the frm file with the information parsed from the .per to memory
 */
/* void write_form (void) */
write_form -> void

/**
 * Gets the datatype of the column from the database
 *
 * @col The column name
 * @tab The table name
 */
/* int getdatatype(char *col,char *tab) */
getdatatype char* col,char* tab -> int

/**
 * Intialize the memory needed to compile a 4gl screen form in order to
 * the lexical and sintatic parser to load the information found
 */
/* void init_form(void) */
init_form -> void

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
/* void add_str_attr(struct struct_scr_field *f,int type,char *str) */
add_str_attr void* f,int type,char* str -> void

/**
 * Try to find the attribute and if not alocate memory and insert it in
 * the attributes array.
 *
 * @param f Pointer to field description
 * @param type The type of the boolean attribute:
 *
 */
/* void add_bool_attr(struct struct_scr_field *f,int type) */
add_bool_attr void* f,int type -> void

/* no longer required... */
* chk_iskey char* keys -> int


/*  ============================== EOF ================================= */




