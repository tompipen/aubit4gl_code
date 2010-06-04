GLOBALS
	DEFINE CONSTANT gv_max_fields	=	1000
	DEFINE CONSTANT gv_max_tables 	=	30

	DEFINE gv_fields 	INTEGER
	DEFINE gv_prepared 	ARRAY[gv_max_tables] OF INTEGER
	DEFINE gv_field_data 	ARRAY[gv_max_fields] OF INTEGER     # This is to hold a pointer to the data itself...
	DEFINE gv_dtypes     	ARRAY[gv_max_fields] OF INTEGER     # This is to hold the datatypes of our fields
	DEFINE gv_dtypesize  	ARRAY[gv_max_fields] OF INTEGER     # This is to hold the datatype sizes of our fields
	DEFINE gv_edtype     	ARRAY[gv_max_fields] OF INTEGER     # This is to hold the encoded datatypes of our fields

END GLOBALS

