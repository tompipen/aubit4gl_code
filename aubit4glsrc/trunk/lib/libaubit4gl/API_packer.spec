*===============================================
LIBRARY PACKER
VARIABLE A4GL_PACKER
#include "../../incl/a4gl_API_packer.h"
*===============================================
*-- Packer definitions
output_int char* name,int val,int ptr,int isarr -> int
output_long char* name,long val,int ptr,int isarr -> int
output_bool char* name,int val,int ptr,int isarr -> int
output_string char* name,char* val,int ptr,int isarr -> int
output_double char* name,double val,int ptr,int isarr -> int
output_start_struct char* s,char* n,int ptr,int isarr -> int
output_end_struct char* s,char* n -> int
output_start_union char* s,char* n,int ptr,int isarr -> int
output_nullptr char* s -> int
output_okptr char* s -> int
output_end_union char* s,char* n -> int
output_enum char* name,char* s,int d,int ptr,int isarr -> int
output_start_array char* s,int type,int len -> int
output_end_array char* s,int type -> int
input_int char* name,int* val,int ptr,int isarr -> int
input_long char* name,long* val,int ptr,int isarr -> int
input_bool char* name,int* val,int ptr,int isarr -> int
input_string char* name,void* val,int ptr,int isarr -> int
input_double char* name,double* val,int ptr,int isarr -> int
input_start_struct char* s,char* n,int ptr,int isarr -> int
input_end_struct char* s,char* n -> int
input_start_union char* s,char* n,int ptr,int isarr -> int
input_ptr_ok -> int
input_end_union char* s,char* n -> int
input_enum char* name,int* d -> int
input_start_array char* s,int type,int* len -> int
input_end_array char* s,int type -> int
open_packer char* basename,char dir -> int
close_packer char dir -> int
can_pack_all char* name -> int
pack_all char* name,void* ptr,char* fname -> int
unpack_all char* name,void* ptr,char* fname -> int
