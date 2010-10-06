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

static struct s_pass_reference vNull = { 0, 0 };

static void
A4GL_null_reference (void *p)
{
  struct s_pass_reference *ptr;
  ptr = p;
  memcpy (ptr, &vNull, sizeof (vNull));
}


static int
A4GL_isnull_reference (void *p)
{
  int isnull;
  if (memcmp (p, &vNull, sizeof (vNull)) == 0)
    {
      isnull = 1;
    }
  else
    {
      isnull = 0;
    }

  return isnull;
}

static void
A4GL_zero_reference (void *p)
{
  struct s_pass_reference *ptr;
  A4GL_assertion (p == 0, "Pointer not set");
  ptr = p;
  ptr->bytes = 0;
  ptr->nbytes = 0;
}




static char *
A4GL_display_reference (void *vptr, int size, int size_c, struct struct_scr_field *field_details, int display_type)
{
  static char buff_16[256];
  struct s_pass_reference *ptr;
  ptr = vptr;
  memset (buff_16, 0, sizeof (buff_16));
  if (ptr == 0)
    {				// Assume its null
      strcpy (buff_16, "                    ");
      return buff_16;

    }

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_REFERENCE, vptr))
	{
	  strcpy (buff_16, "                    ");
	}
      else
	{
	  SPRINTF1 (buff_16, "%20lld", ptr->bytes);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_REFERENCE, vptr))
	{
	  strcpy (buff_16, "");
	}
      else
	{
	  SPRINTF1 (buff_16, "%lld", ptr->bytes);
	}
    }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr == 0 || A4GL_isnull (DTYPE_REFERENCE, vptr))
	{
#ifdef DEBUG
	  A4GL_debug ("Int value is null");
#endif
	  strcpy (buff_16, "");
	  return buff_16;
	}


      if (A4GL_isnull (DTYPE_REFERENCE, vptr))
	{
#ifdef DEBUG
	  A4GL_debug ("Int value is null");
#endif
	  strcpy (buff_16, "");
	  return buff_16;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[size_c] = 0;
	  using_buff[size_c - 1] = '&';
	}

      A4GL_push_long ((long) ptr->bytes);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_16, size_c);
#ifdef DEBUG
      A4GL_debug ("display_int Got '%s'", buff_16);
#endif
      return buff_16;
    }

#ifdef DEBUG
  A4GL_debug ("Returning '%s'", buff_16);
#endif

  return buff_16;
}



static void *
A4GL_conv_reference (void *p)
{
  printf ("conv_ref1\n");
  return NULL;
}

static int
A4GL_convto_reference (int d1, void *p1, int d2, void *p2, int size)
{
  struct s_pass_reference *ppr1;
  if (d1 == DTYPE_REFERENCE && (d2 == DTYPE_CHAR || d2 == DTYPE_NCHAR || d2 == DTYPE_VCHAR || d2 == DTYPE_NVCHAR))
    {
      SPRINTF0 (p2, "(REF)");
      return 1;
    }

  if (d1 != DTYPE_REFERENCE || d2 != DTYPE_REFERENCE)
    {
      return 0;
    }
  ppr1 = p1;
  if (size != ppr1->nbytes)
    {
      A4GL_exitwith ("Incompatible storage size");
      return 1;
    }


  memcpy (p2, ppr1->bytes, size);

  return 1;

}

void
add_reference_support (void)
{
#ifdef DEBUG
  A4GL_debug ("Has reference_support");
#endif
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "INIT", (void *) A4GL_null_reference);
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "ISNULL", (void *) A4GL_isnull_reference);	//
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "SETDTYPE", (void *) A4GL_zero_reference);	// Invalid conversion set it to 0
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "DISPLAY", (void *) A4GL_display_reference);
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "COPY", (void *) A4GL_conv_reference);
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "CONVTO_97", (void *) A4GL_convto_reference);
  A4GL_add_datatype_function_i (DTYPE_REFERENCE, "CONVTO_0", (void *) A4GL_convto_reference);
}
