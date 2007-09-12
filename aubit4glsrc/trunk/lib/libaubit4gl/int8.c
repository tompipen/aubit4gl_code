#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
=====================================================================
                    Functions definitions
=====================================================================

*/

#ifdef NOINT8SUPPORT
void add_int8_support(void) { 
	A4GL_debug("No int8_support");
}
#else


int8 vNull=0x8000000000000LL;

static char *A4GL_display_int8 (void *ptr, int size, int size_c,
                  struct struct_scr_field *field_details, int display_type)
{
  int8 a;
  int8 value_in_ptr=0;
  static char buff_16[256];
  A4GL_debug ("A4GL_display_int..");

  value_in_ptr=*(int8 *)ptr;

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_INT8, ptr))
        {
          strcpy (buff_16, "           ");
        }
      else
        {
          a = value_in_ptr;
          SPRINTF1 (buff_16, "%20lld", a);
        }
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT8, ptr))
        {
          strcpy (buff_16, "");
        }
      else
        {
          a =value_in_ptr;
          SPRINTF1 (buff_16, "%lld", a);
        }
    }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
        {
          A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : %d", *(int *) ptr);
        }

      if (ptr == 0 || A4GL_isnull (DTYPE_INT8, ptr))
        {
          A4GL_debug ("Int value is null");
          strcpy (buff_16, "");
          return buff_16;
        }

      a = value_in_ptr;

      if (A4GL_isnull (DTYPE_INT8, (void *) &a))
        {
          A4GL_debug ("Int value is null");
          strcpy (buff_16, "");
          return buff_16;
        }

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
        {
          strcpy (using_buff,
                  (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
        }
      else
        {
          memset (using_buff, '-', 255);
          using_buff[size_c] = 0;
          using_buff[size_c - 1] = '&';
        }

      A4GL_push_long (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_16, size_c);
      A4GL_debug ("display_int Got '%s'", buff_16);
      return buff_16;
    }

  A4GL_debug ("Returning '%s'", buff_16);

  return buff_16;
}


static void A4GL_null_int8(void *p) {
	//*(int8*)p = vNull;
}

static void A4GL_zero_int8(void *p) {
	A4GL_assertion(p==0,"Pointer not set");
 	exit(30);
	*(int8*)p = 0;
}

static int A4GL_isnull_int8(void *p) {
	if ((*(int8*)p) == vNull) return 1;
	return 0;
}

static int A4GL_tostring_int8(void *p) {
	
	return 0;
}


static void *A4GL_copy_int8(void *p) {
	int8 *ptr;
	ptr=(int8*)malloc(sizeof(int8));
	*ptr=*(int8*)p;
	return ptr;
}
	
	

static int A4GL_conv_int8(int d1, void *p1, int d2, void *p2, int size ) {
int8 l;

A4GL_debug("A4GL_conv_int8 %d %d\n",d1,d2);
if (d1==DTYPE_INT8) {
	// Convert FROM int8..
	switch (d2) {
		case DTYPE_FLOAT: 	*(double *)p2=*(int8*) p1; return 1;
		case DTYPE_SMFLOAT: 	*(float *)p2=*(int8*) p1; return 1;
		case DTYPE_INT: 	*(int *)p2=*(int8*) p1; return 1;
		case DTYPE_SMINT: 	*(short *)p2=*(int8*) p1; return 1;
		case DTYPE_DECIMAL: 	{
				char buff[2000];
				sprintf(buff,"%lld",*(int8*)p1);
				A4GL_push_char(buff);
				A4GL_pop_param(p2,d2,size);
				return 1;
			}
		case DTYPE_CHAR: 	{
				char buff[2000];
				sprintf(buff,"%lld",*(int8*)p1);
				A4GL_push_char(buff);
				A4GL_pop_param(p2,d2,size);
				return 1;
		}
	}
	return 0;
} else {
	// Convert TO int8..
	switch (d1) {
		case DTYPE_FLOAT: *(int8*) p2=*(double *)p1; return 1;
		case DTYPE_SMFLOAT: *(int8*) p2=*(float *)p1; return 1;
		case DTYPE_INT: *(int8*) p2=*(int *)p1; return 1;
		case DTYPE_SMINT: *(int8*) p2=*(short *)p1; return 1;
		case DTYPE_DECIMAL: 
				{
				char buff[2000];
				strcpy(buff,A4GL_dec_to_str(p1,0,0));
				sscanf(buff,"%lld",(int8*)p2);
				}
				return 1;
		case DTYPE_CHAR: 
				sscanf(p1,"%lld",(int8*)p2);
				return 1;


		}
	}
return 0;


}

void add_int8_support(void) {
	A4GL_debug("Has int8_support");
	A4GL_add_datatype_function_i (DTYPE_INT8, "INIT", (void *)A4GL_null_int8);
	A4GL_add_datatype_function_i (DTYPE_INT8, "ISNULL", (void *)A4GL_isnull_int8); //
	A4GL_add_datatype_function_i (DTYPE_INT8, "SETDTYPE", (void *)A4GL_zero_int8); // Invalid conversion set it to 0
	A4GL_add_datatype_function_i (DTYPE_INT8, "DISPLAY", (void *)A4GL_display_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT8, "COPY", (void *)A4GL_copy_int8); 

	A4GL_add_datatype_function_i (DTYPE_FLOAT, "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_DECIMAL,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_INT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_SMINT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_SMFLOAT,  "CONVTO_17", (void *)A4GL_conv_int8); 
	A4GL_add_datatype_function_i (DTYPE_CHAR,  "CONVTO_17", (void *)A4GL_conv_int8); 


	//A4GL_add_op_function (DTYPE_SMINT, 	DTYPE_INT8, OP_MATH, A4GL_smint_int8_ops);
	//A4GL_add_op_function (DTYPE_INT, 	DTYPE_INT8, OP_MATH, A4GL_int_int8_ops);
	//A4GL_add_op_function (DTYPE_FLOAT, 	DTYPE_INT8, OP_MATH, A4GL_float_int8_ops);
	//A4GL_add_op_function (DTYPE_SMFLOAT, 	DTYPE_INT8, OP_MATH, A4GL_smfloat_int8_ops);
	//A4GL_add_op_function (DTYPE_DECIMAL, 	DTYPE_INT8, OP_MATH, A4GL_decimal_int8_ops);

}

#endif
