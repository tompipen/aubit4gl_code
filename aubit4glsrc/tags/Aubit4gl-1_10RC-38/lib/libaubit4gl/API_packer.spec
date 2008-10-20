*===============================================
LIBRARY PACKER
VARIABLE A4GL_PACKER
LIB_PREFIX A4GLPacker_
*#include "../../incl/a4gl_API_packer.hxxx"
*===============================================
*-- Packer definitions
output_int char* name,int val,int ptr,int isarr -> int
output_long char* name,long val,int ptr,int isarr -> int
output_char char* name,char val,int ptr,int isarr -> int
output_short char* name,short val,int ptr,int isarr -> int
output_bool char* name,int val,int ptr,int isarr -> int
output_string char* name,char* val,int ptr,int isarr -> int
output_double char* name,double val,int ptr,int isarr -> int
output_start_struct char* s,char* n,int ptr,int isarr -> int
output_end_struct char* s,char* n -> int
output_start_union char* s char* enumname int enum_val char* n,int ptr,int isarr void* enumcallback -> int
* output_start_union_data char* s char* enumname int enum_val char* n,int ptr,int isarr -> int
output_nullptr char* s char* structname int isunion -> int
output_okptr char* s -> int
output_end_union char* s,char* en,int e,char* n -> int
output_enum char* rn char* name,char* s,int d -> int
output_start_array char* s,int type,int len -> int
output_end_array char* s,int type int len -> int
input_int char* name,int* val,int ptr,int isarr -> int
input_long char* name,long* val,int ptr,int isarr -> int
input_short char* name,short* val,int ptr,int isarr -> int
input_char char* name,char* val,int ptr,int isarr -> int
input_bool char* name,int* val,int ptr,int isarr -> int
input_string char* name,char** val,int ptr,int isarr -> int
input_double char* name,double* val,int ptr,int isarr -> int
input_start_struct char* s,char* n,int ptr,int isarr -> int
input_end_struct char* s,char* n -> int
input_start_union char* s,char* enumname, int* enum_val,char* n,int ptr,int isarr -> int
input_ptr_ok -> int
input_end_union char* s,char* en,int e char* n -> int
input_enum char* rn char* name,int* d -> int
input_start_array char* s,int type,int* len -> int
input_end_array char* s,int type -> int
A4GL_open_packer char* basename,char dir char* struct_to_pack -> int
A4GL_close_packer char dir -> void
A4GL_can_pack_all char* name -> int
A4GL_pack_all char* name,void* ptr,char* fname -> int
A4GL_unpack_all char* name,void* ptr,char* fname -> int
A4GL_pack_remove_file char* fname -> int
